#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    vector<vector<int> > g(n, vector<int> (n, -1));
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            char x;
            cin >> x;
            g[i][j] = (int)x - 48;
            g[j][i] = (g[i][j] + 1) % 2;
        }
    vector<int> que(1, 0), ans;
    for (int i = 0; i < n - 1; i++)
    {
        k = 0;
        while (k < que.size() && g[que[k]][i + 1] == 1)
            k++;
        que.insert(que.begin() + k, i + 1);
    }
    int i = 0, j1;
    n--;
    while (n > 1 && g[que[n]][que[0]] == 0)
        n--;
    n++;
    ans.insert(ans.begin(), que.begin(), que.begin() + n);
    que.erase(que.begin(), que.begin() + n);
    while (que.size() != 0)
    {
        j1 = -1;
        for (int j = 0; j < ans.size(); j++)
            if (g[que[i]][ans[j]])
            {
                j1 = j;
                break;
            }
        if (j1 < 0) i++;
        else
        {
            for (int j = 0; j <= i; j++)
                ans.insert(ans.begin() + j1 + j, que[j]);
            que.erase(que.begin(), que.begin() + i + 1);
            i = 0;
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';
    return 0;
}
