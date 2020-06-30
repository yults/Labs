#include <iostream>
#include <vector>

using namespace std;
vector<long long> pref;

long long sum_do(long long l, long long r) {
    if (l > 0) {
        return pref[r] - pref[l - 1];
    } else {
        return pref[r];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long cons1 = (1 << 16) - 1;
    long long cons2 = (1 << 30) - 1 ;
    long long n, x, y;
    cin >> n >> x >> y;
    pref.resize(n);
    long long preda;
    cin >> preda;
    pref[0] = preda;
    for (long long i = 1; i < n; i++)
    {
         preda = (x * preda + y) & cons1;
         pref[i] = pref[i - 1] + preda;
    }

    long long sum = 0;

    long long m, z, t1;
    cin >> m >> z >> t1;

    long long predb;
    cin >> predb;
    long long c1, c2;
    c1 = predb % n;
    predb = (z * predb + t1) & cons2;
    c2 = predb % n;
    long long l = min(c1, c2);
    long long r = max(c1, c2);
    sum +=  sum_do(l, r);
    if (m == 0) {cout << 0; return 0;}
    for (long long i = 1; i < m; i++)
    {
        predb = (z * predb + t1) & cons2;
        c1 = predb % n;
        predb = (z * predb + t1) & cons2;
        c2 = predb % n;

        long long l = min(c1, c2);
        long long r = max(c1, c2);
        sum +=  sum_do(l, r);
    }
    cout << sum;
    return 0;
}
