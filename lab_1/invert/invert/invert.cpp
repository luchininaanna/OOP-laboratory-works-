#include "stdafx.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

struct IntMatrix
{
	int dimension;
	int matrix[3][3];
	double determinant;
};
struct DoubleMatrix
{
	int dimension;
	double matrix[3][3];
	double determinant;
};

bool FillArray(IntMatrix* startMatrix, char* fileName)
{
	bool isError = false;
	ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		cout << "File is  not open" << endl;
		isError = true;
	}
	else
	{
		int matrixElement;

		while (!ifs.eof())
		{
			for (int i = 0; i < startMatrix->dimension; i++)
			{
				for (int j = 0; j < startMatrix->dimension; j++)
				{
					ifs >> matrixElement;
					startMatrix->matrix[i][j] = matrixElement;
				}
			}
		}
	}

	return isError;
}

double CalculateMatrixDeterminant(IntMatrix* startMatrix, bool* isDeterminantIsZero_ptr)
{

	int positivePartDeterminant = startMatrix->matrix[0][0] * startMatrix->matrix[1][1] * startMatrix->matrix[2][2] + startMatrix->matrix[1][0] * startMatrix->matrix[2][1] * startMatrix->matrix[0][2] + startMatrix->matrix[0][1] * startMatrix->matrix[1][2] * startMatrix->matrix[2][0];

	int negativePartDeterminant = startMatrix->matrix[2][0] * startMatrix->matrix[1][1] * startMatrix->matrix[0][2] + startMatrix->matrix[1][0] * startMatrix->matrix[0][1] * startMatrix->matrix[2][2] + startMatrix->matrix[0][0] * startMatrix->matrix[2][1] * startMatrix->matrix[1][2];
	;

	double determinant = positivePartDeterminant - negativePartDeterminant;
	startMatrix->determinant = determinant;

	if (determinant == 0)
	{
		*isDeterminantIsZero_ptr = true;
	}

	return 0;
}

double GetNewElement(IntMatrix* startMatrix, int i, int j)
{

	double matrixElement;
	double coef = pow(-1, i + j) * (1 / startMatrix->determinant);

	switch (i)
	{
	case 0:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix->matrix[1][1] * startMatrix->matrix[2][2] - startMatrix->matrix[2][1] * startMatrix->matrix[1][2];
			break;
		case 1:
			matrixElement = startMatrix->matrix[0][1] * startMatrix->matrix[2][2] - startMatrix->matrix[0][2] * startMatrix->matrix[2][1];
			break;
		case 2:
			matrixElement = startMatrix->matrix[0][1] * startMatrix->matrix[1][2] - startMatrix->matrix[0][2] * startMatrix->matrix[1][1];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 1:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix->matrix[1][0] * startMatrix->matrix[2][2] - startMatrix->matrix[2][0] * startMatrix->matrix[1][2];
			break;
		case 1:
			matrixElement = startMatrix->matrix[0][0] * startMatrix->matrix[2][2] - startMatrix->matrix[2][0] * startMatrix->matrix[0][2];
			break;
		case 2:
			matrixElement = startMatrix->matrix[0][0] * startMatrix->matrix[1][2] - startMatrix->matrix[1][0] * startMatrix->matrix[0][2];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 2:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix->matrix[1][0] * startMatrix->matrix[2][1] - startMatrix->matrix[2][0] * startMatrix->matrix[1][1];
			break;
		case 1:
			matrixElement = startMatrix->matrix[0][0] * startMatrix->matrix[2][1] - startMatrix->matrix[0][1] * startMatrix->matrix[2][0];
			break;
		case 2:
			matrixElement = startMatrix->matrix[0][0] * startMatrix->matrix[1][1] - startMatrix->matrix[1][0] * startMatrix->matrix[0][1];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	default:
		cerr << "Error\n";
	}

	if (matrixElement != 0)
	{
		matrixElement = matrixElement * coef;
	}

	return matrixElement;
}

void GetinvertMatrix(IntMatrix* startMatrix, DoubleMatrix* invertMatrix)
{

	for (int i = 0; i < startMatrix->dimension; i++)
	{
		for (int j = 0; j < startMatrix->dimension; j++)
		{
			double matrixElement = GetNewElement(startMatrix, i, j);
			invertMatrix->matrix[i][j] = matrixElement;
		}
	}
}

int PrintMatrix(DoubleMatrix* invertMatrix)
{

	for (int i = 0; i < invertMatrix->dimension; i++)
	{
		for (int j = 0; j < invertMatrix->dimension; j++)
		{
			cout << round(invertMatrix->matrix[i][j] * 1000) / 1000 << " ";

			//cout << fixed;  //математическое округление
			//cout.precision(1);
			//cout << invertMatrix[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
};

int main(int argc, char* argv[])
{
	const int DIMENSION = 3; //размер матрицы (задан по условию)

	IntMatrix* startMatrix = new IntMatrix;
	startMatrix->dimension = DIMENSION;

	bool isError = FillArray(startMatrix, argv[1]);

	if (!isError)
	{
		bool isDeterminantIsZero = false;
		bool* isDeterminantIsZero_ptr = &isDeterminantIsZero;

		CalculateMatrixDeterminant(startMatrix, isDeterminantIsZero_ptr);

		if (!isDeterminantIsZero)
		{
			DoubleMatrix* invertMatrix = new DoubleMatrix;
			invertMatrix->dimension = DIMENSION;

			GetinvertMatrix(startMatrix, invertMatrix);
			PrintMatrix(invertMatrix);

			delete invertMatrix;
		}
		else
		{
			delete startMatrix;
			cout << "This matrix does not have an invert matrix: the determinant is zero" << endl;
		}
	}

	return 0;
}
