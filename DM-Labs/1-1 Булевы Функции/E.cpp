#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > g(27);
vector<vector<int> > f(27);
vector<int> lt;
vector<int> val(27);
vector<int> pred;

/*int DFS(int v, int cnt) {
	if (g[v].size() == 0)
		return cnt;
	int maxi = cnt;
	for (int i = 0; i < g[v].size(); i++) {
		maxi = max(maxi, DFS(g[v][i], cnt + 1));
	}
	return  maxi;
}
*/

void make_f(int k)
{
	for (int i = lt.size() - 1; i >= 0; i--)
	{
		val[lt[i]] = k % 2;
		k = k / 2;
	}
}
int find_val(int v) {
	if (g[v].size() == 0) {
		return val[v];
	}
	int num = 0;
	int k = 1;
	for (int i = g[v].size() - 1; i >= 0; i--) {
		num += find_val(g[v][i]) * k;
		k = k * 2;
	}
	return f[v][num];

}
int main() {
	int n;
	cin >> n;
	int ans1 = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (m == 0)
		{
			lt.push_back(i);
			pred.push_back(0);
			continue;
		}
		int maxpred = 0;
		for (int j = 0; j < m; j++)
		{
			int cell;
			cin >> cell;
			g[i].push_back(--cell);
			if(maxpred < pred[cell]) maxpred = pred[cell];
		}
		pred.push_back(++maxpred);
		ans1 = max(ans1, maxpred);
		int siz_f = (1 << m);
		for (int j = 0; j < siz_f; j++)
		{
			int val_f;
			cin >> val_f;
			f[i].push_back(val_f);
		}
	}
	cout << ans1 << endl;
	int siz_f_lt = (1 << lt.size());
	for (int i = 0; i < siz_f_lt; i++)
	{
		make_f(i);
		cout << find_val(n - 1);
	}
}
