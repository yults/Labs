#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct e
{
    int u, v, z;
};

int main()
{
    int n, ans, v, p, siz;
    cin >> n;
    vector<e> E;
    vector<int> d(n, 0), par(n, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int u;
            cin >> u;
            if (u != 100000) E.push_back({i, j, u});
        }
    for (int i = 0; i < n; i++)
    {
        ans = -1;
        for (int j = 0; j < E.size(); j++)
        {
            if (d[E[j].v] - E[j].z > d[E[j].u])
            {
                d[E[j].v] = d[E[j].u] + E[j].z;
                par[E[j].v] = E[j].u;
                ans = E[j].v;
            }
        }
    }
    if (ans == -1)
    {
        cout << "NO";
        return 0;
    }
    v = ans;
    cout << "YES" << endl;
    stack<int> s;
    for (int i = 0; i < n; i++)
        v = par[v];
    p = v;
    siz = 0;
    while (p != v || s.empty())
    {
        s.push(p);
        p = par[p];
        siz++;
    }
    cout << siz << endl;
    while(!s.empty())
    {
        int f = s.top() + 1;
        s.pop();
        cout << f << ' ';
    }
    return 0;
}
