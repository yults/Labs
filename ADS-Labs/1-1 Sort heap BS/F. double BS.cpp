#include <iostream>
#include <cmath>

using namespace std;

int low_bound(int x, int n)
{
    int L = -1;
    int R = n;
    while (R - L > 1)
    {
        int M = L + (R - L)/2;
        if (a[M] <= x)
            L = M;
        else
            R = M;
    }
    return L;
}

int main()
{
    lm = sqrt(x * x + (1 - a) * (1 - a));
    mr = sqrt((x - 1) * (x - 1) + a * a);
    double vl, vp;
    cin >> vp >> vl;
    vl = vl;
    vp = vp;
    double a;
    cin >> a;
    float time = (lm / vp + mr / vl);
    cout << mi;
    return 0;
}
