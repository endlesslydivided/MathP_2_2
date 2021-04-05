#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"
#include "Boat.h"
#define NN 31
#define MM 6
#define N 5
#define SPACE(n) std::setw(n)<<" "
#define NL 12
int main()
{
    setlocale(LC_ALL, "rus");
    // ПРИМЕР РЕШЕНИЯ ЗАДАЧИ КОММИВОЯЖЁРА
    int d[N][N] = {
                   {  INF,  30, 36,  INF,  15 },
                   { 15,   INF,  30,  53,  69},
                   { 17,  45,   INF,  86,   64},
                   { 32,  43,  60,   INF,   45},
                   { 78,  81,  52,  28,    INF} };

    int k[N];                     // результат 
    int m = salesman(
        N,                   // [in]  количество городов 
        (int*)d,             // [in]  массив [n*n] расстояний 
        k                   // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++) {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)
            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";
            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << k[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << m;
    std::cout << std::endl;
    //// ПРИМЕР РЕШЕНИЯ ОБ ОПТИМАЛЬНОЙ ЗАГРУЗКЕ СУДНА
    //srand(time(0));
    //int p[N][N], r[N];
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        if (i == j) { p[i][j] = INF; }
    //        else { p[i][j] = 10 +rand()% 300; }
    //    }
    //}
    //std::cout << std::endl << "-- Задача коммивояжера -- ";
    //std::cout << std::endl << "-- количество ------ продолжительность -- ";
    //std::cout << std::endl << "      городов           вычисления  ";
    //clock_t t1, t2;
    //for (int i = 6; i <= NL; i++) {
    //    t1 = clock();
    //    salesman(i, (int*)p, r);
    //    t2 = clock();
    //    std::cout << std::endl << SPACE(7) << std::setw(2) << i
    //        << SPACE(15) << std::setw(5) << (t2 - t1);
    //}
    //std::cout << std::endl;
    system("pause");
    return 0;

}

