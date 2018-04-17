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

bool FillMatrix(IntMatrix &startMatrix, int dimension, char* fileName)
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
		startMatrix.dimension = dimension;

		int matrixElement;

		while (!ifs.eof())
		{
			for (int i = 0; i < startMatrix.dimension; i++)
			{
				for (int j = 0; j < startMatrix.dimension; j++)
				{
					ifs >> matrixElement;
					startMatrix.matrix[i][j] = matrixElement;
				}
			}
		}
	}

	return isError;
}

double CalculateMatrixDeterminant(IntMatrix &startMatrix, bool* isDeterminantIsZeroPtr)
{

	int positivePartDeterminant = startMatrix.matrix[0][0] * startMatrix.matrix[1][1] * startMatrix.matrix[2][2] + 
		startMatrix.matrix[1][0] * startMatrix.matrix[2][1] * startMatrix.matrix[0][2] + 
		startMatrix.matrix[0][1] * startMatrix.matrix[1][2] * startMatrix.matrix[2][0];

	int negativePartDeterminant = startMatrix.matrix[2][0] * startMatrix.matrix[1][1] * startMatrix.matrix[0][2] + 
		startMatrix.matrix[1][0] * startMatrix.matrix[0][1] * startMatrix.matrix[2][2] + 
		startMatrix.matrix[0][0] * startMatrix.matrix[2][1] * startMatrix.matrix[1][2];

	double determinant = positivePartDeterminant - negativePartDeterminant;
	startMatrix.determinant = determinant;

	if (determinant == 0)
	{
		*isDeterminantIsZeroPtr = true;
	}

	return 0;
}

double GetNewElement(IntMatrix &startMatrix, int i, int j)
{

	double matrixElement;
	double coef = pow(-1, i + j) * (1 / startMatrix.determinant);

	switch (i)
	{
	case 0:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix.matrix[1][1] * startMatrix.matrix[2][2] - 
				startMatrix.matrix[2][1] * startMatrix.matrix[1][2];
			break;
		case 1:
			matrixElement = startMatrix.matrix[0][1] * startMatrix.matrix[2][2] - 
				startMatrix.matrix[0][2] * startMatrix.matrix[2][1];
			break;
		case 2:
			matrixElement = startMatrix.matrix[0][1] * startMatrix.matrix[1][2] - 
				startMatrix.matrix[0][2] * startMatrix.matrix[1][1];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 1:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix.matrix[1][0] * startMatrix.matrix[2][2] - 
				startMatrix.matrix[2][0] * startMatrix.matrix[1][2];
			break;
		case 1:
			matrixElement = startMatrix.matrix[0][0] * startMatrix.matrix[2][2] - 
				startMatrix.matrix[2][0] * startMatrix.matrix[0][2];
			break;
		case 2:
			matrixElement = startMatrix.matrix[0][0] * startMatrix.matrix[1][2] - 
				startMatrix.matrix[1][0] * startMatrix.matrix[0][2];
			break;
		default:
			cerr << "Error\n";
		}
		break;
	case 2:
		switch (j)
		{
		case 0:
			matrixElement = startMatrix.matrix[1][0] * startMatrix.matrix[2][1] - 
				startMatrix.matrix[2][0] * startMatrix.matrix[1][1];
			break;
		case 1:
			matrixElement = startMatrix.matrix[0][0] * startMatrix.matrix[2][1] - 
				startMatrix.matrix[0][1] * startMatrix.matrix[2][0];
			break;
		case 2:
			matrixElement = startMatrix.matrix[0][0] * startMatrix.matrix[1][1] - 
				startMatrix.matrix[1][0] * startMatrix.matrix[0][1];
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

void GetInvertMatrix(IntMatrix &startMatrix, DoubleMatrix &invertMatrix)
{

	for (int i = 0; i < startMatrix.dimension; i++)
	{
		for (int j = 0; j < startMatrix.dimension; j++)
		{
			double matrixElement = GetNewElement(startMatrix, i, j);
			invertMatrix.matrix[i][j] = matrixElement;
		}
	}
}

void PrintMatrix(const DoubleMatrix &invertMatrix)
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

void ProcessMatrix(IntMatrix &startMatrix, int dimension){
	bool isDeterminantIsZero = false;

	CalculateMatrixDeterminant(startMatrix, &isDeterminantIsZero);

	if (!isDeterminantIsZero)
	{
		DoubleMatrix invertMatrix;
		invertMatrix.dimension = dimension;

		GetInvertMatrix(startMatrix, invertMatrix);
		PrintMatrix(invertMatrix);
	}
	else
	{
		cout << "This matrix does not have an invert matrix: the determinant is zero" << endl;
	}
}

int main(int argc, char* argv[])
{
	int dimension = 3; //размерность матрицы (задан по условию)
	IntMatrix startMatrix;

	bool isError = FillMatrix(startMatrix, dimension, argv[1]);

	if (!isError)
	{
		ProcessMatrix(startMatrix, dimension);
	}

	return 0;
}
