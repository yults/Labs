#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector <int> > g;
vector<int> t, a;
bool f;

void dfs (int v)
{
    if (t[v] == 2) return;
    if (t[v] == 1)
    {
            f = true;
            return;
    }
    t[v] = 1;
    for (auto u : g[v]) dfs(u);
    t[v] = 2;
    a.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    t.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
    }
    for (int i = 0; i < n; i++) dfs(i);
    if (f) cout << -1; else
    {
        reverse(a.begin(), a.end());
        for (auto v : a) cout << ++v << ' ';
    }
    return 0;
}