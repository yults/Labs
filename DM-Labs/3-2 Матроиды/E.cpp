#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

set<int> s;
map<int, set<int> > m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
     for (int i = 0; i < n; i++)
        m[i + 1] = s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        m[u].insert(v);
        m[v].insert(u);
    }
    for (auto m1 : m)
        if (m1.second.size() == 1)
            s.insert(m1.first);
    for (int i = 0; i < n - 2; i++)
    {
        auto beg = *s.begin();
        auto mbeg = *m[beg].begin();
        cout << mbeg << ' ';
        m[mbeg].erase(beg);
        if (m[mbeg].size() == 1)
            s.insert(mbeg);
        s.erase(beg);
        m.erase(beg);
    }
    return 0;
}
