#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int> > jumps, jumps2;
vector<bool> terminal, terminal2, visited;

bool checker(int a, int b)
{
	bool ans = true;
    visited[a] = true;
    if(terminal[a] != terminal2[b]) return false;
    for (int i = 0; i < 26; i++)
    {
    	int A = jumps[a][i];
    	int B = jumps2[b][i];
    	if ((A < 0 || B < 0) && (A != B)) return false;
    	if (A > 0 && !visited[A]) ans = ans && checker(A, B);
	}
    return ans;
}

int main()
{
	ifstream cin ("isomorphism.in");
	ofstream cout ("isomorphism.out");
	int n, m, k;
    cin >> n >> m >> k;
    terminal.resize(n, false);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal[pos - 1] = true;
    }
    vector<int> fil(26, -1);
    for (int i = 0; i < n; i++)
        jumps.push_back(fil);
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps[a - 1][(int)c - (int)'a'] = b - 1;
	}
 	cin >> n >> m >> k;
    terminal2.resize(n, false);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal2[pos - 1] = true;
    }
    for (int i = 0; i < n; i++)
        jumps2.push_back(fil);
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps2[a - 1][(int)c - (int)'a'] = b - 1;
	}
	visited.resize(n, false);
	if (checker(0, 0)) cout << "YES";
	else cout << "NO";
}
