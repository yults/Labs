#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int find_i, i1 = 1;
vector<vector<int> > p;
vector<int> depth, age;

int youngest(int v)
{
    if (age[v] != v) age[v] = youngest(age[v]);
    return age[v];
}

void remove1(int u1, int v1)
{
    int u = youngest(u1);
    int v = youngest(v1);
    if (v != u) age[u] = v;
}

int lca(int u, int v)
{
    if (depth[v] > depth[u])
        swap(u, v);
    for (int i = find_i; i >= 0; i--)
        if ((1 << i) <= depth[u] - depth[v]) u = p[u][i];
    if (v != u)
    {
        for (int i = find_i; i >= 0; i--)
        {
            if (p[v][i] == p[u][i]) continue;
            u = p[u][i];
            v = p[v][i];
        }
        return p[v][0];
    }
    return u;
}

void add(int v)
{
    age[i1] = i1;
    depth[i1] = depth[v] + 1;
    p[i1][0] = v;
    for (int j = 1; j <= find_i; j++)
        p[i1][j] = p[p[i1][j - 1]][j - 1];
    i1++;
}


int main()
{
	int m;
	cin >> m;
	depth.resize(m);
	age.resize(m);
	find_i = 0;
    for (int i = 1; (1 << (i - 1)) < m; i++)
        find_i++;
    p.resize(m, vector<int> (find_i + 1));
	for (int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        int v, u;
        if (c == '+')
        {
            cin >> v;
            v--;
            add(v);
        }
        else if (c == '-')
        {
            cin >> v;
            v--;
            remove1(v, p[v][0]);
        }
        else
        {
            cin >> u >> v;
            u--; v--;
            cout << youngest(lca(u, v)) + 1 << endl;
        }
	}
	return 0;
}
