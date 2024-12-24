#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)  // ƒл€ компил€ции библиотеки
#else
#define MYLIBRARY_API __declspec(dllimport) // ƒл€ использовани€ библиотеки
#endif

extern "C" {
    MYLIBRARY_API double divide_vector(const double* I, double* O, size_t S, double D);
}