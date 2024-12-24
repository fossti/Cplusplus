#include <iostream>
#include "pch.h"
#include "Header.h"
#include <ctime>
#include <cmath>


using namespace std;

double divide_vector(const double* I, double* O, size_t S, double D) {
    
    clock_t start_time = clock();


    for (size_t i = 0; i < S; ++i) {
        O[i] = I[i] / D;
    }

    clock_t end_time = clock(); // Завершение таймера
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC; // Вычисление времени выполнения в секундах

    return time_taken;
}