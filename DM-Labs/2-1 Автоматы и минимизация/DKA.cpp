#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Jumps
{
    int next;
    char c;
    Jumps(int next1, char c1)
    {
        next = next1;
        c = c1;
    }
};

int prev1;
string s;
vector<vector<Jumps> > jumps;

int jump(char c)
{
    for (int i = 0; i < jumps[prev1].size(); i++)
        if (jumps[prev1][i].c == c) return jumps[prev1][i].next;
    return -1;
}

int checker()
{
    prev1 = 1;
    for (int i = 0; i < s.length(); i++)
    {
        prev1 = jump(s[i]);
        if (prev1 == -1) return 0;
    }
    return prev1;
}

int main()
{
	ifstream cin ("problem1.in");
	ofstream cout ("problem1.out");
	cin >> s;
	int n, m, k;
    cin >> n >> m >> k;
    vector<bool> term(n + 1, false);
    jumps.resize(n + 1);
    jumps[0].push_back(Jumps(0, '0'));
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        term[pos] = true;

    }
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps[a].push_back(Jumps(b, c));
	}
	int last_pos = checker();
	if (term[last_pos]) cout << "Accepts";
	else cout << "Rejects";
}
