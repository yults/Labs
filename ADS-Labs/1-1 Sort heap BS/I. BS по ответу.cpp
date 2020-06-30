#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

double f(double x, double c)
{
    return x * x + sqrt(x) - c;
}

double bs(double c)
{
    double l = 0;
    double r = 100000;
    while (r - l > 0.000000000001){
        double mid = l + (r - l)/2;
        if (f(mid, c) <= 0)
            l = mid;
        else
            r = mid;
    }
    return l;

}

int main()
{
    double c;
    cin >> c;
    printf("%.10f", bs(c));
    return 0;
}
