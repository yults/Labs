#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int> > g(n, vector<int> (n));
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            char x;
            cin >> x;
            g[i][j] = (int)x - 48;
            g[j][i] = g[i][j];
        }
    vector<int> que(n);
    for (int i = 0; i < n; i++)
        que[i] = i;
    int beg = 0;
    for (int i = 0; i < n * (n - 1); i++)
    {
        if (!g[que[beg]][que[beg + 1]])
        {
            int j = beg + 2;
            while (!g[que[beg]][que[j]] || !g[que[beg + 1]][que[j + 1]]) j++;
            reverse(que.begin() + beg + 1, que.begin() + j + 1);
        }
        que.push_back(que[beg]);
        beg++;
    }
    for (int i = beg; i < que.size(); i++)
        cout << que[i] + 1 << ' ';
}

