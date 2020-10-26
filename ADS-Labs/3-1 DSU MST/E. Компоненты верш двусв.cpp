#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

vector<vector<int> > g;
vector<bool> used;
vector<int> du, t;
map<pair<int, int>, int> E;
vector<pair<int, int> > ans;
stack<pair<int, int> > stak;
int cnt = 1, tr = 0;

void dfs(int v, int p)
{
    t[v] = du[v] = tr++;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int node = g[v][i];
        if (node == p) continue;
        if (E.count(make_pair(v, node)) != 0 || E.count(make_pair(node, v)) != 0)
            continue;
        if (!used[node])
        {
            stak.push(make_pair(v, node));
            dfs(node, v);
            if (t[v] <= du[node])
            {
                int c = cnt++;
                while (stak.top() != make_pair(v, node))
                {
                    E[stak.top()] = c;
                    stak.pop();
                }
                    E[make_pair(v, node)] = c;
                    stak.pop();
            }
            if (du[v] > du[node]) du[v] = du[node];
        }
        else 
        {
            if (t[node] < t[v])
            {
                stak.push(make_pair(v, node));
                if (du[v] > t[node]) du[v] = t[node];
            }
            else if (t[node] < t[v]) du[v] = du[node];
        }
    }
}

int anss(int v, int u)
{
    if (E.count(make_pair(v, u)) == 0)
        return E[(make_pair(u, v))];
    return E[(make_pair(v, u))];
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    du.resize(n);
    t.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ans.push_back(make_pair(u, v));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs(i, -1);
    cnt--;
    cout << cnt << endl;
    for (int i = 0; i < m; i++)
        cout << anss(ans[i].first, ans[i].second) << " ";
    return 0;
}
