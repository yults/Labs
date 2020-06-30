#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int parent;
	int minim;
};
int find_i;
Node dp[200001][21] = {};
vector<int> depth;

int find_minimum (int u, int v)
{
    int ans = 1000007;
    if (depth[v] > depth[u])
        swap(u, v);
    for (int i = find_i; i >= 0; i--)
    {
        if ((1 << i) <= depth[u] - depth[v])
        {
            ans = min(dp[u][i].minim, ans);
            u = dp[u][i].parent;
        }
    }
    if (v != u)
    {
        for (int i = find_i; i >= 0; i--)
        {
            if (dp[v][i].parent == dp[u][i].parent) continue;
            else
            {
                ans = min(min(dp[u][i].minim, dp[v][i].minim), ans);
                u = dp[u][i].parent;
                v = dp[v][i].parent;
            }
        }
        ans = min(min(dp[u][0].minim, dp[v][0].minim), ans);
    }
    return ans;
}

int main()
{
    ifstream cin ("minonpath.in");
	ofstream cout ("minonpath.out");
	int n;
	cin >> n;
	depth.resize(n);
	depth[0] = 0;
	dp[0][0].parent = 0;
	dp[0][0].minim = 1000007;
	for (int i = 1; i < n; i++)
    {
        int x, y;
		cin >> x >> y;
		x--;
		depth[i] = depth[x] + 1;
		dp[i][0].parent = x;
		dp[i][0].minim = y;
	}
	int m;
	cin >> m;
	int i = 1;
	while ((1 << (i - 1)) < n)
    {
        for (int j = 0; j < n; j++)
        {
			dp[j][i].parent = dp[dp[j][i - 1].parent][i - 1].parent;
			dp[j][i].minim = min(dp[dp[j][i - 1].parent][i - 1].minim, dp[j][i - 1].minim);
		}
		i++;
    }
    find_i = i - 1;
	for (int k = 0; k < m; k++)
    {
        int v, u;
		cin >> u >> v;
		u--; v--;
        cout << find_minimum(u, v) << endl;
	}
	return 0;
}
