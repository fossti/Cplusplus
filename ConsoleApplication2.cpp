#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x, y;
    cin >> x;
    cin >> y;
    double R = 1 / cos(pow(y, 2) / x);
    double S = pow(x + log(1 / x), 1 / 3);
    cout << "R = " << R << endl;
    cout << "S = " << S << endl;
    double C = max(R, S);
    cout << C;
    return 0;
}