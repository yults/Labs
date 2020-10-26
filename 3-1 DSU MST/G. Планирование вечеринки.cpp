#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;
map <string, vector<string> > g, kg;
vector<string> ns, x, out;
int cnt = 0;
map <string, int> cp;
map <string, bool> used;
stack<string> stak;

void dfs(string u)
{
     used[u] = true;
     for (int i = 0; i < g[u].size(); i++)
     {
         string node = g[u][i];
         if (!used[node]) dfs(node);
     }
     stak.push(u);
}

void dfsc(string u)
{
     cp[u] = cnt;
     for (int i = 0; i < kg[u].size(); i++)
     {
         string node = kg[u][i];
         if (cp[node] == 0) dfsc(node);
     }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string s1 = "+", s2 = "-";
        s1 += s;
        s2 += s;
        ns.push_back(s1);
        ns.push_back(s2);
        used[s1] = used[s2] = false;
        g[s1] = g[s2] = kg[s1] = kg[s2] = x;
        cp[s1] = cp[s2] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        string s1, s2, sym;
        cin >> s1 >> sym >> s2;
        string uns1 = s1.substr(1), uns2 = s2.substr(1);
        if (s1[0] == '+') uns1 = "-" + uns1; else uns1 = "+" + uns1;
        if (s2[0] == '+') uns2 = "-" + uns2; else uns2 = "+" + uns2;
        g[s1].push_back(s2);
        kg[s2].push_back(s1);
        g[uns2].push_back(uns1);
        kg[uns1].push_back(uns2);
    }
    for (int i = 0; i < n * 2; i++)
        if (!used[ns[i]]) dfs(ns[i]);
    cnt = 1;
    while (!stak.empty())
    {
        string v = stak.top();
        stak.pop();
        if (cp[v] == 0)
        {
            dfsc(v);
            cnt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cp[ns[i * 2]] == cp[ns[i * 2 + 1]])
        {
            cout << -1;
            return 0;
        }
        if (cp[ns[i * 2]] > cp[ns[i * 2 + 1]]) out.push_back(ns[i * 2].substr(1));
    }
    cout << out.size() << endl;
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << endl;
    return 0;
}
