#include <iostream>
#include "Functions.h"
int main()
{
	int AmountOfElement;
	std::cout << "Enter a mount of elements" << std::endl;
	std::cin >> AmountOfElement;
	double* mas = new double[AmountOfElement];
	input(mas, AmountOfElement);
	print(mas, AmountOfElement);
	merege(mas, 0, AmountOfElement - 1, AmountOfElement);
	std::cout << "sorted mas" << std::endl;
	print(mas, AmountOfElement);
	system("pause");
}