#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

vector<vector<int> > g, kg;
vector<bool> used;
vector<int> du, t, cp;
stack<int> stak;
set<pair<int, int> > st, st2;
int cnt = 0;

void dfs(int u)
{
     used[u] = true;
     for (int i = 0; i < g[u].size(); i++)
     {
         int node = g[u][i];
         if (!used[node]) dfs(node);
     }
     stak.push(u);
}

void dfsc(int u)
{
     cp[u] = cnt;
     for (int i = 0; i < kg[u].size(); i++)
     {
         int node = kg[u][i];
         if (cp[node] == 0) dfsc(node);
     }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    du.resize(n);
    t.resize(n);
    cp.resize(n);
    kg.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        u--; v--;
        if (st.count(make_pair(u, v)) != 0) continue;
        st.insert(make_pair(u, v));
        g[u].push_back(v);
        kg[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs(i);
    cnt = 1;
    while (!stak.empty())
    {
        int v = stak.top();
        stak.pop();
        if (cp[v] == 0)
        {
            dfsc(v);
            cnt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            int x = g[i][j];
            if (cp[i] != cp[x]) st2.insert(make_pair(cp[i], cp[x]));
        }
    }
    cout << st2.size();
    return 0;
}
