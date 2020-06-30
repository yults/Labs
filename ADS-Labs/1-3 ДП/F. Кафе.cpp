#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, INF)), used(n + 1, vector<int>(n + 1, 0)), p(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == INF)
                continue;
            if (j > 0 && dp[i + 1][j - 1] > dp[i][j])
            {
                dp[i + 1][j - 1] = dp[i][j];
                used[i + 1][j - 1] = used[i][j] + 1;
                p[i + 1][j - 1] = j;
            }
            if (c[i] > 100 && dp[i + 1][j + 1] > dp[i][j] + c[i])
            {
                dp[i + 1][j + 1] = dp[i][j] + c[i];
                used[i + 1][j + 1] = used[i][j];
                p[i + 1][j + 1] = j;
            }
            else if (c[i] <= 100 && dp[i + 1][j] > dp[i][j] + c[i])
            {
                dp[i + 1][j] = dp[i][j] + c[i];
                used[i + 1][j] = used[i][j];
                p[i + 1][j] = j;
            }
        }
    }
    int ans = INF, k = -1;
    for (int i = 0; i <= n; i++)
    {
        if (dp[n][i] <= ans)
        {
            ans = dp[n][i];
            k = i;
        }
    }
    cout << ans << endl << k << ' ' << used[n][k] << endl;
    vector<int> days;
    while (n > 0)
    {
        if (p[n][k] == k + 1)
            days.push_back(n);
        k = p[n][k];
        n--;
    }
    for (int i = days.size() - 1; i >= 0; i--)
        cout << days[i] << endl;
    return 0;
}
