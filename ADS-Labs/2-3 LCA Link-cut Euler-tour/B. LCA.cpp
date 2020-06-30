#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int> > p;
int find_i;
vector<int> depth;

int lca (int u, int v)
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

int main()
{
    int n;
    cin >> n;
	depth.resize(n);
    p.resize(n, vector<int> (log(n)/log(2) + 10, -1));
	depth[0] = 0;
	p[0][0] = 0;
	for (int i = 1; i < n; i++)
    {
        int x;
		cin >> x;
		x--;
		depth[i] = depth[x] + 1;
		p[i][0] = x;
	}
	int m;
	cin >> m;
	int i = 1;
	while ((1 << (i - 1)) < n)
    {
        for (int j = 0; j < n; j++)
            if (p[j][i - 1] != -1)
                p[j][i] = p[p[j][i - 1]][i - 1];
		i++;
    }
    find_i = i - 1;
	for (int k = 0; k < m; k++)
    {
        int v, u;
		cin >> u >> v;
		u--; v--;
        cout << lca(u, v) + 1 << endl;
	}
	return 0;
}
