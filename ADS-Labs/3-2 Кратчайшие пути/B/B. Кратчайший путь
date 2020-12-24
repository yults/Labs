#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n);
    vector<int> ans(n, 10000000);
    for (int i = 0; i < m; i++)
    {
        int u, v, z;
        cin >> u >> v >> z;
        u--; v--;
        g[u].push_back(make_pair(v, z));
        g[v].push_back(make_pair(u, z));
    }
    set<pair<int, int> > s;
    pair<int, int> a = make_pair(0, 0);
    s.insert(a);
    ans[0] = 0;
    while (!s.empty())
    {
        int dt = s.begin()->first;
        int v = s.begin()->second;
        s.erase(make_pair(dt, v));
        for (int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i].first;
            int z = g[v][i].second;
            if (ans[u] - z <= ans[v]) continue;
            if (ans[u] != 10000000) s.erase(make_pair(ans[u], u));
            ans[u] = ans[v] + z;
            s.insert(make_pair(ans[u], u));
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}
