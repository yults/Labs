#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<int> > g;
vector<bool> used;
vector<int> du, t, comp;
map<pair<int, int>, int> E;
set <pair<int, int> > ex;
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
    }
}

void fcomp (int v, int c)
{
    comp[v] = c;
    for (int i = 0; i < g[v].size(); i++)
    {
        int x = g[v][i];
        if (comp[x] == 0)
            if (ex.count(make_pair(x, v)) == 0 && t[v] < du[x])
            {
               cnt++;
               fcomp(x, cnt);
            }
            else fcomp(x, c);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    comp.resize(n, 0);
    used.resize(n);
    du.resize(n);
    t.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (E.count(make_pair(u, v)) == 1)
        {
            ex.insert(make_pair(u, v));
            ex.insert(make_pair(v, u));
        }
        g[u].push_back(v);
        g[v].push_back(u);
        E[make_pair(u, v)] = i;
        E[make_pair(v, u)] = i;
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs(i, -1);
    for (int i = 0; i < n; i++)
    {
        if (comp[i] == 0)
        {
            cnt++;
            fcomp(i, cnt);
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
        cout << comp[i] << " ";
    return 0;
}

