#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

string s;
vector<vector<set<int> > > jumps;
set<int> terminal;
set<int> states;

bool checker()
{
    for (auto i : states)
        if (0 != terminal.count(i)) return true;
    return false;
}

void jump()
{
    for (int i = 0; i < s.length(); i++)
    {
        set<int> new_states;
        for (auto j : states)
            for (auto k : jumps[j][(int)s[i] - (int)'a']) new_states.insert(k);
        states = new_states;
    }
}

int main()
{
	ifstream cin ("problem2.in");
	ofstream cout ("problem2.out");
	cin >> s;
	int n, m, k;
    cin >> n >> m >> k;
    jumps.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
        jumps[i].resize(26);
    states.insert(1);
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        terminal.insert(pos);
    }
    for(int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> a >> b >> c;
        jumps[a][(int)c - (int)'a'].insert(b);
	}
    jump();
	if (checker()) cout << "Accepts";
	else cout << "Rejects";
}
