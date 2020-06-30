#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<vector<int> > w;
 
int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    vector<vector<long long> > dp(m, vector<long long> (1 << n));
    for (int mask = 0; mask < (1 << n); mask++) {
        dp[0][mask] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int maski = 0; maski < (1 << n); maski++) {
            for (int maskj = 0; maskj < (1 << n); maskj++) {
                long long flag = 1;
                for (int k = 0; k < n - 1; k++) {
                    if ((bool)(maski & (1 << k)) == (bool)(maskj & (1 << k))
                        && (bool)(maski & (1 << k + 1)) == (bool)(maskj & (1 << k + 1))
                        && (bool)(maski & (1 << k)) == (bool)(maskj & (1 << k + 1))) {
                        flag = 0;
                    }
                }
                dp[i][maski] += dp[i - 1][maskj] * flag;
            }
        }
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
        ans += dp.back()[mask];
    cout << ans;
    return 0;
}
