#include "stdafx.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

struct IntMatrix
{
	int dimension;
	int matrix[3][3];
};
struct DoubleMatrix
{
	int dimension;
	double matrix[3][3];
};

bool GetStartMatrix(IntMatrix& matrix, int dimension, char* fileName)
{
	bool isPossibleToGetMatrix = false;
	ifstream ifs(fileName);

	if (ifs.is_open())
	{
		cout << "File is  not open" << endl;
		isPossibleToGetMatrix = true;
	}
	else
	{
		matrix.dimension = dimension;

		for (int i = 0; i < matrix.dimension; i++)
		{
			for (int j = 0; j < matrix.dimension; j++)
			{
				if (!ifs.eof()) //!
				{
					ifs >> matrix.matrix[i][j];
				}
			}
		}
	}

	//метод у потока
	//мог быть прочитан eof
	return isPossibleToGetMatrix;
}

double GetAlgebraicComplement(IntMatrix& matrix, int lineMatrix, int columnMatrix)
{
	double algebraicComplement;

	switch (lineMatrix)
	{
	case 0:
		switch (columnMatrix)
		{
		case 0:
			algebraicComplement = matrix.matrix[1][1] * matrix.matrix[2][2] - matrix.matrix[2][1] * matrix.matrix[1][2];
			break;
		case 1:
			algebraicComplement = matrix.matrix[0][1] * matrix.matrix[2][2] - matrix.matrix[0][2] * matrix.matrix[2][1];
			break;
		case 2:
			algebraicComplement = matrix.matrix[0][1] * matrix.matrix[1][2] - matrix.matrix[0][2] * matrix.matrix[1][1];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 1:
		switch (columnMatrix)
		{
		case 0:
			algebraicComplement = matrix.matrix[1][0] * matrix.matrix[2][2] - matrix.matrix[2][0] * matrix.matrix[1][2];
			break;
		case 1:
			algebraicComplement = matrix.matrix[0][0] * matrix.matrix[2][2] - matrix.matrix[2][0] * matrix.matrix[0][2];
			break;
		case 2:
			algebraicComplement = matrix.matrix[0][0] * matrix.matrix[1][2] - matrix.matrix[1][0] * matrix.matrix[0][2];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 2:
		switch (columnMatrix)
		{
		case 0:
			algebraicComplement = matrix.matrix[1][0] * matrix.matrix[2][1] - matrix.matrix[2][0] * matrix.matrix[1][1];
			break;
		case 1:
			algebraicComplement = matrix.matrix[0][0] * matrix.matrix[2][1] - matrix.matrix[0][1] * matrix.matrix[2][0];
			break;
		case 2:
			algebraicComplement = matrix.matrix[0][0] * matrix.matrix[1][1] - matrix.matrix[1][0] * matrix.matrix[0][1];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	default:
		cerr << "Error\n";
	}

	return algebraicComplement;
}

void GetTransposeMatrix(IntMatrix& matrix)
{
	for (int lineMatrix = 0; lineMatrix < matrix.dimension; lineMatrix++)
	{
		for (int columnMatrix = 0; columnMatrix < matrix.dimension; columnMatrix++)
		{
//без временной  переменной
			int matrixElement = matrix.matrix[lineMatrix][columnMatrix];
			matrix.matrix[lineMatrix][columnMatrix] = matrix.matrix[columnMatrix][lineMatrix];
			matrix.matrix[columnMatrix][lineMatrix] = matrixElement;
		}
	}
}

double GetElementForInvertMatrix(double algebraicComplement, int lineMatrix, int columnMatrix,
	const double& determinant)
{
	double coef = pow(-1, lineMatrix + columnMatrix) * (1 / determinant);

	algebraicComplement = algebraicComplement * coef;

	if (algebraicComplement == 0) 0 и -0 одно и то же
	{
		algebraicComplement = 0;
	}

	return algebraicComplement;
}

void CreateInvertMatrix(IntMatrix& matrix, DoubleMatrix& invertMatrix, const double& determinant)
{
	//найти транспонированную матрицу
	GetTransposeMatrix(matrix);

	for (int lineMatrix = 0; lineMatrix < matrix.dimension; lineMatrix++)
	{
		for (int columnMatrix = 0; columnMatrix < matrix.dimension; columnMatrix++)
		{
			//получить алгебраическое дополнение (переделать функцию)
			double algebraicComplement = GetAlgebraicComplement(matrix, lineMatrix, columnMatrix);

			invertMatrix.matrix[lineMatrix][columnMatrix] = GetElementForInvertMatrix(algebraicComplement, lineMatrix, columnMatrix, determinant);
		}
	}
}

void PrintMatrix(const DoubleMatrix& invertMatrix)
{

	for (int i = 0; i < invertMatrix.dimension; i++)
	{
		for (int j = 0; j < invertMatrix.dimension; j++)
		{
			cout << round(invertMatrix.matrix[i][j] * 1000) / 1000 << " ";

			//cout << fixed;  //математическое округление
			//cout.precision(1);
			//cout << invertMatrix[i][j] << endl;
		}
		cout << endl;
	}
};

double GetMatrixDeterminant(IntMatrix& matrix)
{
	int positivePartDeterminant = matrix.matrix[0][0] * matrix.matrix[1][1] * matrix.matrix[2][2] + matrix.matrix[1][0] * matrix.matrix[2][1] * matrix.matrix[0][2] + matrix.matrix[0][1] * matrix.matrix[1][2] * matrix.matrix[2][0];

	int negativePartDeterminant = matrix.matrix[2][0] * matrix.matrix[1][1] * matrix.matrix[0][2] + matrix.matrix[1][0] * matrix.matrix[0][1] * matrix.matrix[2][2] + matrix.matrix[0][0] * matrix.matrix[2][1] * matrix.matrix[1][2];

	double determinant = positivePartDeterminant - negativePartDeterminant;

	return determinant;
}

void GetInvertMatrix(IntMatrix& startMatrix, int dimension)
{
	double determinant = GetMatrixDeterminant(startMatrix);

	if (determinant != 0)
	{
		DoubleMatrix invertMatrix;
		invertMatrix.dimension = dimension;

		CreateInvertMatrix(startMatrix, invertMatrix, determinant);

		PrintMatrix(invertMatrix);
	}
	else
	{
		cout << "This matrix does not have an invert matrix: the determinant is zero" << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "This program need get a start matrix (file .txt)" << endl;
	}
	else
	{
		int dimension = 3; //размерность матрицы (задана по условию)
		IntMatrix startMatrix;

		bool isPossibleToGetMatrix = GetStartMatrix(startMatrix, dimension, argv[1]);

		if (isPossibleToGetMatrix)
		{
			GetInvertMatrix(startMatrix, dimension);
		}
	}

	return 0;
}
