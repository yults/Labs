#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > jumps, jumps2;
vector<bool> terminal, terminal2;
vector<vector<bool> > visited;
queue<int> q;

bool checker()
{
    q.push(0);
    q.push(0);
	while(!q.empty())
	{
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();
        if (terminal[a] != terminal2[b]) return false;
        visited[a][b] = true;
        for (int i = 0; i < 26; i++)
        	if (!visited[jumps[a][i]][jumps2[b][i]])
			   {
			   	q.push(jumps[a][i]);
			   	q.push(jumps2[b][i]);
			   }
    }
    return true;
}

int main()
{
	ifstream cin ("equivalence.in");
	ofstream cout ("equivalence.out");
	int n, m, k;
    cin >> n >> m >> k;
    terminal.resize(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal[pos - 1] = true;
    }
    vector<int> fil(26);
    for(int i = 0; i < 26; i++)
    	fil[i] = n;
    for (int i = 0; i < n + 1; i++)
        jumps.push_back(fil);
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps[a - 1][(int)c - (int)'a'] = b - 1;
	}
	int n2;
 	cin >> n2 >> m >> k;
    terminal2.resize(n2 + 1, false);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal2[pos - 1] = true;
    }
    for(int i = 0; i < 26; i++)
    	fil[i] = n2;
    for (int i = 0; i < n2 + 1; i++)
        jumps2.push_back(fil);
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps2[a - 1][(int)c - (int)'a'] = b - 1;
	}
	vector<bool> fill(n2 + 1, false);
	for(int i = 0; i < n + 1; i++)
	visited.push_back(fill);
	visited[0][0] = true;
	if (checker()) cout << "YES";
	else cout << "NO";
}
