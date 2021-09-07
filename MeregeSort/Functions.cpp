#include "Functions.h"
#include <iostream>


void print(double *mas, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << mas[i] << " ";
	std::cout << std::endl;
}

void input(double* mas, int n)
{
	std::cout << "Enter mas elements" << std::endl;
	for (int i = 0; i < n; ++i)
		std::cin >> mas[i];
}

void merege(double* mas, int LeftBound, int RightBound, int MasSize)
{
	if (RightBound == LeftBound)
		return;
	if (RightBound - LeftBound == 1)
	{
		if (mas[LeftBound] > mas[RightBound])
		{
			std::swap(mas[RightBound], mas[LeftBound]);
		}
		return;
	}

	int MasCenter = (RightBound + LeftBound) / 2;
	merege(mas, LeftBound, MasCenter, MasSize);
	merege(mas, MasCenter + 1, RightBound, MasSize);
	
	double* BufMas = new double[100];
	int RightIndex = MasCenter+1;
	int LeftIndex = LeftBound;
	int CurrentIndex = 0;
	while (RightBound - LeftBound+1 != CurrentIndex)
	{
		if (LeftIndex > MasCenter)
			BufMas[CurrentIndex++] = mas[RightIndex++];

		else if (RightIndex > RightBound)
			BufMas[CurrentIndex++] = mas[LeftIndex++];

		else if (mas[LeftIndex] > mas[RightIndex])
			BufMas[CurrentIndex++] = mas[RightIndex++];

		else BufMas[CurrentIndex++] = mas[LeftIndex++];
	}
	for (int i = 0; i < CurrentIndex; ++i)
		mas[i+LeftBound] = BufMas[i];
}





