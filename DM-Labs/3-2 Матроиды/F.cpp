#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

vector<int> t;
set<int> s;
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        m[i] = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        m[x]++;
        t.push_back(x);
    }
    for (auto m1 : m)
        if (m1.second == 0)
            s.insert(m1.first);
    for (int i = 0; i < n - 2; i++)
    {
        auto u = t[0];
        m[u]--;
        auto v = *s.begin();
        if (m[u] == 0)
            s.insert(u);
        cout << v << ' ' << u << endl;
        t.erase(t.begin());
        s.erase(v);
        m.erase(v);
    }
    for (auto m1 : m)
        cout << m1.first << " ";
    return 0;
}
