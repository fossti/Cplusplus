#include <iostream>

using namespace std;

int countLessThan(int arr[], int size, int t) {// Функция получает на вход массив, его размер и значение t
    int count = 0;
    for (int i = 0; i < size; i++) {// сравнивает значение с индексом i со значением t
        if (arr[i] < t) {//если значение меньше t, то к счетчику прибавляется 1
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int size) {  //Функция получает сам массив и его размер.
    for (int i = 0; i < size; i++) { //С помощью цикла выводит значениe находящиеся под индексом i
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "russian");
    const int SIZE = 5;
    int A[SIZE];
    int B[SIZE];
    cout << "Введите 5 чисел для массива A: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> A[i];
    }

    cout << "Введите 5 чисел для массива B: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> B[i];
    }

    int t;
    cout << "Введите значение t: ";
    cin >> t;
    int countA = countLessThan(A, SIZE, t);
    int countB = countLessThan(B, SIZE, t);
    cout << "\nКоличество элементов, меньших " << t << ":" << endl;
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;

    cout << "\nМассив с наибольшим количеством элементов, меньших " << t << ":" << endl;
    if (countA >= countB) {
        cout << "A: ";
        printArray(A, SIZE);
    }
    else {
        cout << "B: ";
        printArray(B, SIZE);
    }
    int s;
    cin >> s;
    return 0;
}