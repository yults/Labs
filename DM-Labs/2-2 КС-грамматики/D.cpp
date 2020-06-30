#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<char, string> >  jumps;
vector<pair<char, string> >  nottjumps;
vector<vector<vector<long long> > > path;
set<char> nott;

int main()
{
    ifstream cin ("nfc.in");
    ofstream cout ("nfc.out");
    long long n;
    char s;
    cin >> n >> s;
    path.resize(101, vector<vector<long long> >(101, vector<long long> (101, 0)));
    for (long long i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        char st = s1[0];
        nott.insert(st);
        if (s3.length() > 1)
        {
            nott.insert(s3[0]);
            nott.insert(s3[1]);
            nottjumps.push_back(make_pair(s1[0], s3));
        }
        else
            jumps.push_back(make_pair(s1[0], s3));
    }
    string m;
    cin >> m;
    for (long long i = 0; i < m.length(); i++)
        for (auto jump : jumps)
            if (jump.second.length() < 2 && jump.second[0] == m[i])
                path[jump.first][i][i] = 1;
    for (long long i = 0; i < m.length() - 1; i++)
        for (long long j = 0; j < m.length(); j++)
            if (m.length() > i + j + 1)
                for(long long z = j; z < i + j + 1; z++)
                    for (auto x : nottjumps)
                        path[x.first][j][i + j + 1]
                                            = (path[x.second[0]][j][z]
                                            * path[x.second[1]][z + 1][i + j + 1]
                                            + path[x.first][j][i + j + 1])
                                            % 1000000007;
    cout << path[s][0][m.length() - 1];
}

