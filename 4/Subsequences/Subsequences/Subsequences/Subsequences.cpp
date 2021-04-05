
#include <iostream>
#include "LCS.h"
#include "LCH.h"    
#include <ctime>
int main()
{
    clock_t t1 = 0;
    clock_t t2 = 0;
    clock_t	t3 = 0;
    clock_t t4 = 0;

    setlocale(LC_ALL, "rus");
    char X[] = "MIOPLKJ", Y[] = "GUIOLW";
    std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
    std::cout << std::endl << "-- последовательность X: " << X;
    std::cout << std::endl << "-- последовательность Y: " << Y;

    t1 = clock();
    int s = lcs(
        sizeof(X) - 1,  // длина   последовательности  X   
        "MIOPLKJ",       // последовательность X
        sizeof(Y) - 1,  // длина   последовательности  Y
        "GUIOLW"       // последовательность Y
    );
    t2 = clock();

    std::cout << std::endl << "-- длина LCS: " << s << std::endl;
    std::cout << std::endl << "затраченное время(сек):  " << ((double)(t2 - t1)) / ((double)(clock_t)1000) << std::endl;

    char z[100] = "";

    t3 = clock();
    int l = lcsd(X, Y, z);
    t4 = clock();

    std::cout << std::endl
        << "-- наибольшая общая подпоследовательость - LCS(динамическое"
        << "программирование)" << std::endl;
    std::cout << std::endl << "последовательость X: " << X;
    std::cout << std::endl << "последовательость Y: " << Y;
    std::cout << std::endl << "                LCS: " << z;
    std::cout << std::endl << "          длина LCS: " << l;
    std::cout << std::endl;
    std::cout << std::endl << "затраченное время(сек):  " << ((double)(t4 - t3)) / ((double)(clock_t)1000) << std::endl;

    system("pause");
    return 0;
}
