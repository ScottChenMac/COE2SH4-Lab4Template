
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix()
{

	rowsNum = 3;
	colsNum = 3;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = 0;

}

Matrix::~Matrix()
{
	for(int i = 0; i < rowsNum; i++)
	{
		delete[] matrixData[i];
	}

	delete[] matrixData;
}

Matrix::Matrix( int row, int col )
{

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/

	if(row <= 0)
	{
		row = 3;
	}
	
	if(col <= 0)
	{
		col = 3;
	}

	rowsNum = row;
	colsNum = col;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = 0;
	         

}


Matrix::Matrix(int row, int col, int** table)
{

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	rowsNum = row;
	colsNum = col;
	matrixData = new int*[rowsNum];

	for(int i = 0; i < rowsNum; i++)
	{
		matrixData[i] = new int[colsNum];
	}

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] = table[i][j];

}

int Matrix::getElement(int i, int j)
{
	if(i >= rowsNum || i < 0 || j >= colsNum || j < 0)
		throw std::out_of_range("Invalid indexes.");

	return matrixData[i][j];
}



bool Matrix::setElement(int x, int i, int j){

	if(i >= rowsNum || j >= colsNum) return false;

    matrixData[i][j] = x;
	
	return true;
}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */
	Matrix copy =  Matrix(rowsNum,colsNum);

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			copy.setElement(matrixData[i][j], i, j);

    return copy;
}


void Matrix::addTo( Matrix m ){

	if(m.getsizeofrows() != rowsNum || m.getsizeofcols() != colsNum)
		throw std::invalid_argument("Invalid operation.");

	for(int i = 0; i < rowsNum; i++)
		for(int j = 0; j < colsNum; j++)
			matrixData[i][j] += m.getElement(i, j);

}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/
	if(i >= rowsNum || j >= colsNum) 
		throw std::out_of_range("Submatrix not defined.");

	/* fix the code and write your implementation below */
	Matrix subM = Matrix (i + 1, j + 1);

    for(int a = 0; a <= i; a++)
		for(int b = 0; b <= j; b++)
			subM.setElement(matrixData[a][b], a, b);


    return  subM;
}


int Matrix::getsizeofrows(){

	/* update below return */
	return rowsNum;
}


int Matrix::getsizeofcols(){

	/* update below return */
    return colsNum;
}



string Matrix::toString(){

	string output;

	for(int i = 0; i < rowsNum; i++)
	{
		for(int j = 0; j < colsNum; j++)
			output += to_string(matrixData[i][j]) + " ";
		
		output += "\n";
	}
	
	cout << output << endl;

	return output;
}
