// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define MAX 10

int main()
{
	int data[MAX][MAX];
	int row, col;
	int pivotval;
	int pivotrowindex, pivotcolindex;
	bool rowflag = false;
	bool colflag = false;
	bool pivotflag = false;
	std::cout << "Please define the size of the matrix <row col> max is 10: ";
	std::cin >> row >> col;
	std::cout << "Input the matrix data: " << std::endl;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			std::cin >> data[r][c];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			
			//search row
			int tempmax = data[i][j];
			for (int k = 0; k < col; k++)
			{
				if (tempmax <= data[i][k])
					tempmax = data[i][k];
			}
			rowflag = (tempmax == data[i][j]);

			//search column
			int tempmin = data[i][j];
			for (int l = 0; l < row; l++)
			{
				if (tempmin >= data[l][j])
				{
					tempmin = data[l][j];
				}
			}
			colflag = (tempmin == data[i][j]);
			if (rowflag && colflag)
			{
				pivotflag = true;
				pivotval = data[i][j];
				pivotrowindex = i;
				pivotcolindex = j;
			}
		}
	}
	if (pivotflag)
	{
		std::cout << "Found pivot at row: " << pivotrowindex+1 << " col: " << pivotcolindex+1 << " with value " << pivotval;
	}
	else
	{
		std::cout << "Pivot not found." << std::endl;
	}
	system("pause");
	return 0;
}
