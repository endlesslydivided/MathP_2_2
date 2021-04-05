#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	char abc[25]; // наш алфавит
	char s1[300];
	char s2[250];	

	// заполняем массив
	for (int i = 97, n = 0; i <= 122; ++i, ++n)
	{
		abc[n] = (char)i; 
	}
	std::cout << "S1 = ";
	for (int i = 0; i < 301; i++)
	{
		s1[i] = abc[_rand(0, 26)];
		if (i % 50 == 0)
			std::cout << std::endl;
		std::cout << s1[i];
	}
	std::cout << std::endl <<"S2 =";

	for (int i = 0; i < 251; i++)
	{
		s2[i] = abc[_rand(0, 25)];
		if (i% 50 == 0)
			std::cout << std::endl;
		std::cout << s2[i];
	}
	std::cout << std::endl;
	
	clock_t t1 = 0;
	clock_t t2 = 0;
	clock_t	t3 = 0;
	clock_t t4 = 0;
	int  lx = sizeof(s1) ;
	int ly = sizeof(s2) ;


	int S1_size[]{ 12, 15, 20, 30,60,150,300 };
	int S2_size[]{ 10,13,17,25,50,125,250 };

	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"<< std::endl;
	for (int i = 0; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(S1_size[i], s1 , S2_size[i], s2);
		t2 = clock();
		t3 = clock();
		levenshtein(S1_size[i], s1, S2_size[i], s2);
		t4 = clock();
		std::cout << std::right << std::setw(2) << S1_size[i] << "/" << std::setw(2) << S2_size[i]
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}
	system("pause");
	return 0;
}


