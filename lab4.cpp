#include <iostream>
#include <set>

using namespace std;

set<int> findElementsOnlyInB(const set<int>& A, const set<int>& B) {// Функция получает на вход 2 множества,
//если число < 0 и находится только в B, то оно записывается в множество result
    set<int> result;
    for (int b : B) {
        if (b < 0 && A.find(b) == A.end()) {
            result.insert(b);
        }
    }
    return result;
}

void printSet(const set<int>& s) {//Функция на вход принимает множество. Выводит элементы множества
    for (int elem : s) {
        cout << elem << " ";
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    int nA, nB;
    cout << "Введите количество элементов в множестве A: ";
    cin >> nA;
    set<int> A;
    cout << "Введите элементы множества A: " << endl;
    for (int i = 0; i < nA; i++) {
        int element;
        cin >> element;
        A.insert(element);
    }

    cout << "Введите количество элементов в множестве B: ";
    cin >> nB;
    set<int> B;
    cout << "Введите элементы множества B: " << endl;
    for (int i = 0; i < nB; i++) {
        int element;
        cin >> element;
        B.insert(element);
    }

    set<int> result = findElementsOnlyInB(A, B);

    cout << "\nМножество элементов, присутствующих только в B и меньших 0: " << endl;
    printSet(result);
    int s;
    cin >> s;
    return 0;
}
