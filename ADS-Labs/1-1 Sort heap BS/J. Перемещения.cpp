#include <iostream>
#include <cmath>

using namespace std;
long long const1 = 10000;

int main()
{
    long long vl, vp;
    cin >> vp >> vl;
    vl = vl * const1;
    vp = vp * const1;
    long long a;
    cin >> a;
    a = a * const1;
    float mint = 1000000000;
    long long mi = 0;
    for (long long i = 0; i < const1; i++)
    {
    float time = (sqrt((const1 - a)^2 + i^2) / vp + sqrt(a^2 + (const1 - i) ^2) / vl)/10000;
    if (time < mint) {mint = time; mi = i;}
    }
    cout << mi/const1;
    return 0;
}
