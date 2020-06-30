#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ifstream cin ("problem4.in");
	ofstream cout ("problem4.out");
	long long n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<bool> terminal(n, false);
    for (long long i = 0; i < k; i++)
    {
        long long pos;
        cin >> pos;
        terminal[pos - 1] = true;
    }
    vector<vector<long long> > jumps(n);
    for (long long i = 0; i < m; i++)
    {
        char c;
        long long a, b;
        cin >> a >> b >> c;
        jumps[a - 1].push_back(b - 1);
	}
	vector<long long> builder(n);
	builder[0] = 1;
	set<long long> a;
	a.insert(0);
	for (long long i = 0; i < l; i++)
    {
        vector<long long> builder2(n);
        set<long long> b;
        for (auto j : a)
            for (long long z = 0; z < jumps[j].size(); z++)
                {
                    builder2[jumps[j][z]] += builder[j];
                    builder2[jumps[j][z]]%= 1000000007;
                    b.insert(jumps[j][z]);
                }
    a = b;
    builder = builder2;
    }
    long long anss = 0;
    for (long long i = 0; i < n; i++)
        if (terminal[i]) anss+= builder[i];
    cout << anss % 1000000007;
}
