#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<bool> terminal, visited;
vector<int> a, b, builder;
vector<char> metka;
vector<vector<int> > jumps, path;
int n, m, k;

void dfs(int v)
{
	if (visited[v]) return;
	visited[v] = true;
	for (int i = 0; i < path[v].size(); i++)
		if (visited[path[v][i]] == false) dfs(path[v][i]);
}

bool is_uncountble(int v)
{
    metka[v] = 'v'; //viewed
    for (int i = 0; i < jumps[v].size(); i++)
    {
        int pos = jumps[v][i];
        if (metka[pos] == 'n' && is_uncountble(pos) || metka[pos] == 'v' && visited[pos]) return true;
    }
    metka[v] = 'i'; //inserted
    a.push_back(v);
    return false;
}

int build_ans()
{
    b.resize(a.size());
    for (int i = 0; i < a.size(); i++)
        b[a.size() - i - 1] = a[i];
    builder[0] = 1;
    for (int i = 0; i < b.size(); i++)
        for (int j = 0; j < path[b[i]].size(); j++)
            builder[b[i]] += builder[path[b[i]][j]];
    int anss = 0;
    for (int i = 0; i < terminal.size(); i++)
       if (terminal[i]) anss += builder[i];
    return anss;
}

int main()
{
	ifstream cin ("problem3.in");
	ofstream cout ("problem3.out");
    cin >> n >> m >> k;
    terminal.resize(n, false);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal[pos - 1] = true;
    }
    jumps.resize(n);
    path.resize(n);
    for (int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps[a - 1].push_back(b - 1);
        path[b - 1].push_back(a - 1);

	}
	visited.resize(n, false);
	metka.resize(n, 'n'); //not viewed
	builder.resize(n);
	for (int i = 0; i < n; i++)
            if(terminal[i]) dfs(i);
    if(is_uncountble(0)) cout << -1;
    else cout << build_ans();
}
