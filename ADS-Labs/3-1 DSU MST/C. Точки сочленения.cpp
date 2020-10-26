#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > g;
vector<bool> cp, used;
vector<int> du, t;
int cnt = 0, tr = 0;

void dfs(int v, int p)
{
    t[v] = du[v] = tr++;
    used[v] = true;
    int c = 0;
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
        if (t[v] <= du[node] && p != -1)
            if (!cp[v])
            {
                cnt++;
                cp[v] = true;
            }
        c++;
    }
    if (p == -1 && c > 1)
        if (!cp[v])
        {
            cnt++;
            cp[v] = true;
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    cp.resize(m);
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
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs(i, -1);
    cout << cnt << endl;
    for (int i = 0; i < m; i++)
        if (cp[i]) cout << i + 1 << " ";
    return 0;
}
