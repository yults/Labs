#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

set<long long> q0;
map<set<long long>, vector<set<long long> > > msi;
map<set<long long>, bool> vis;
map<set<long long>, long long> sett;
queue<set<long long> > que;

int main()
{
	ifstream cin ("problem5.in");
	ofstream cout ("problem5.out");
	long long n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<vector<vector<long long> > > jumps;
	vector<vector<long long> > filling(26);
	for (long long i = 0; i < n; i++)
        jumps.push_back(filling);
	vector<bool> jterminal(n, false);
	for (long long i = 0; i < k; i++)
    {
        long long pos;
		cin >> pos;
		jterminal[pos - 1] = true;
	}
	for (long long i = 0; i < m; i++)
    {
        char c;
        long long a, b;
		cin >> a >> b >> c;
		jumps[a - 1][c - 'a'].push_back(b - 1);
	}
	long long anss = 0;
	bool flag;
	que.push({0});
	vis[{0}] = true;
	sett[{0}] = 1;
	while (!que.empty())
    {
		q0 = que.front();
		msi[q0].resize(26);
		que.pop();
		for (long long i = 0; i < 26; i++)
		{
			set<long long> s;
			for (auto j : q0)
				for (auto z : jumps[j][i])
					s.insert(z);
			if (!vis[s])
			{
				vis[s] = true;
				que.push(s);
			}
			msi[q0][i] = s;
		}
	}
	for (long long i = 0; i < l; i++)
	{
		map<set<long long>, long long> sett2;
		for (auto j : sett)
			for (auto s : msi[j.first])
			sett2[s] = (sett2[s] + j.second)  % 1000000007;
		sett = sett2;
	}
	for (auto i : sett)
	{
		flag = false;
		for (auto j : i.first) if (jterminal[j]) flag = true;
		if (flag) anss += i.second;
	}
    cout << anss % 1000000007;
	return 0;
}
