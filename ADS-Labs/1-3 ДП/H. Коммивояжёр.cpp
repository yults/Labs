#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
vector<vector<int> > w;
 
int main()
{
    int n;
    cin >> n;
    w.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }
    vector<vector<int> > dp(n + 1, vector<int> (1 << (n + 1), 1e9)), p(n + 1, vector<int>(1 << (n + 1)));
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << (n + 1)); mask++) {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i != j && (bool)(mask & (1 << j)) && dp[j][mask - (1 << j)] + w[i][j] < dp[i][mask]) {
                    dp[i][mask] = dp[j][mask - (1 << j)] + w[i][j];
                    p[i][mask] = j;
                }
            }
        }
    }
    cout << dp[0][(1 << (n + 1)) - 1] << endl;
    int k = 0, mask = (1 << (n + 1)) - 1;
    vector<int> ans;
    do {
        k = p[k][mask];
        mask -= 1 << k;
        ans.push_back(k);
    } while (k != 0);
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
