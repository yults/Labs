#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > g;
map<pair<int, int>, int> E;
vector<bool> brige, used;
vector<int> du, t;
int cnt = 0, tr = 0;

void dfs(int v, int p) 
{
    t[v] = du[v] = tr++;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int node = g[v][i];
        if (node == p) continue;
        if (used[node])
        {
            du[v] = min(du[v], t[node]);
            continue;
        }
        dfs(node, v);
        du[v] = min(du[v], du[node]);
        if (du[node] > t[v])
        {
            int x = E[make_pair(v, node)];
            brige[x] = true;
            cnt++;
        }
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    brige.resize(m);
    used.resize(n);
    du.resize(n);
    t.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        E[make_pair(u, v)] = i;
        E[make_pair(v, u)] = i;

    }
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs(i, -1);
    cout << cnt << endl;
    for (int i = 0; i < m; i++)
        if (brige[i]) cout << i + 1 << " ";
    return 0;
}
