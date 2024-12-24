#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)  // ��� ���������� ����������
#else
#define MYLIBRARY_API __declspec(dllimport) // ��� ������������� ����������
#endif

extern "C" {
    MYLIBRARY_API double divide_vector(const double* I, double* O, size_t S, double D);
}