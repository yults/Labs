#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

struct G
{
    int w, u, v;
    G(int x, int y, int z) : w(x), u(y), v(z){}
};

vector<int> q, p;
vector<G> E;

int up(int v)
{
    while (p[v] != v) v = p[v];
    return v;
}

bool cmp(G x, G y)
{
    return x.w < y.w;
}

void unite(int u, int v)
{
    v = up(v);
    u = up(u);
    if (u == v) return;
    if (q[v] > q[u])
    {
        q[v] += q[u];
        p[u] = v;
        return;
    }
    q[u] += q[v];
    p[v] = u;
}

int main()
{
    int n, m;
    cin >> n >> m;
    q.resize(n, 1);
    for (int i = 0; i < n; i++)
        p.push_back(i);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        E.push_back(G(z, --x, --y));
    }
    long long ans = 0;
    sort(E.begin(), E.end(), cmp);
    for (auto e : E)
    {
        if (up(e.v) != up(e.u))
        {
            ans += e.w;
            unite(e.u, e.v);
        }
    }
    cout << ans;
    return 0;
}