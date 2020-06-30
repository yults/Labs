#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod = 1000000000;

long long func(vector<long long> f, long long a, long long b, long long c)
{
    return (f[a] % mod + f[b] % mod + f[c] % mod) % mod;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> F(10, 1);
    F[8] = 0;
    F[0] = 0;
    for (long long i = 1; i < n; i++)
    {
        vector<long long> f(11, 0);
        for (long long j = 0; j < 10; j++)
        {
            f[j] = F[j];
        }
        F[0] = func(f, 4, 6, 10);
        F[1] = func(f, 6, 8, 10);
        F[2] = func(f, 7, 9, 10);
        F[3] = func(f, 4, 8, 10);
        F[4] = func(f, 0, 3, 9);
        F[5] = 0;
        F[6] = func(f, 0, 1, 7);
        F[7] = func(f, 2, 6, 10);
        F[8] = func(f, 1, 3, 10);
        F[9] = func(f, 2, 4, 10);
    }
    long long ans = 0;
    for (long long i = 0; i < 10; i++)
        ans = (ans + F[i]) % mod;
    cout << ans;
    return 0;
}
