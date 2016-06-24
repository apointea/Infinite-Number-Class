#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <InfNum.class.hpp>

void		test_values(InfNum *a, InfNum *b)
{
	std::cout << "A : " << a->toString() << " or " << a->toStringSigned() << std::endl;
	std::cout << "B : " << b->toString() << " or " << b->toStringSigned() << std::endl;
	if (*a > *b)
		std::cout << "A gt B" << std::endl;
	else
		std::cout << "A !gt B" << std::endl;
	if (*a < *b)
		std::cout << "A lt B" << std::endl;
	else
		std::cout << "A !lt B" << std::endl;
	if (*a >= *b)
		std::cout << "A gte B" << std::endl;
	else
		std::cout << "A !gte B" << std::endl;
	if (*a <= *b)
		std::cout << "A lte B" << std::endl;
	else
		std::cout << "A !lte B" << std::endl;
	if (*a == *b)
		std::cout << "A == B" << std::endl;
	else
		std::cout << "A != B" << std::endl;
}

int			main(void)
{
	char	buffer[300];
	InfNum	*a;

	InfNum	*b;
	while (1)
	{
		std::cout << "Please choose a value for (A) :" << std::endl;
		fgets(buffer, 300, stdin);
		a = new InfNum(buffer);
		std::cout << "Please choose a value for (B) :" << std::endl;
		fgets(buffer, 300, stdin);
		b = new InfNum(buffer);
		test_values(a, b);
		delete a;
		delete b;
	}
}
