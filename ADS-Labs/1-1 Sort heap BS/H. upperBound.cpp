#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[100000];

int up_bound(int x, int n)
{
    int L = -1;
    int R = n;
    while (R - L > 1){
        int M = L + (R - L)/2;
        if (a[M] <= x)
            L = M;
        else
            R = M;
    }
    if (R < n)
        return R;
    return L;

}

int main()
{
    long long n, m;
    cin >> n;
    cin >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (long long i = 0; i < m; i++)
    {
        long long va = up_bound(b[i], n);
        if  (va - 1 > -1)
        {
            if (va < n)
            {
                if (b[i] - a[va - 1] > a[va] - b[i])
                cout << a[va] << endl;
            else
                cout << a[va - 1] << endl;
            } else  cout << a[va - 1] << endl;
        }
        else
            cout << a[va] << endl;
    }
    return 0;
}
