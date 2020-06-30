#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool ans;
vector<vector<pair<char, char> > > jumps;
void dfs(string ch, int not_term, char s)
{
    if (s == '0' && ch.length() == not_term) ans = true;
    if (ch.length() <= not_term || s == '0') return;
    char x = ch[not_term];
    for (int i = 0; i < jumps[s - 'A'].size(); i++)
        if (x == jumps[s - 'A'][i].second) dfs(ch, not_term + 1, jumps[s - 'A'][i].first);
}

int main()
{
    ifstream cin ("automaton.in");
    ofstream cout ("automaton.out");
    int n;
    char s;
    cin >> n >> s;
    jumps.resize(26);
    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        char st = s1[0], fjump = s3[0], sjump = '0';
        if (s3.length() > 1) sjump = s3[1];
        jumps[st - 'A'].push_back(make_pair(sjump, fjump));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string z;
        cin >> z;
        ans = false;
        dfs(z, 0, s);
        if (ans) cout << "yes"; else cout << "no";
        cout << endl;
    }
}

