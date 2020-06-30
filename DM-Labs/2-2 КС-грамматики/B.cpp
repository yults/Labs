#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<char> eps_prod;
vector<vector<string> > jumps;

int main()
{
    ifstream cin ("epsilon.in");
    ofstream cout ("epsilon.out");
    int n;
    char s;
    string g;
    getline(cin, g);
    string n1 = "";
    int i = 0;
    while (g[i] >= '0' && g[i] <= '9')
        {
            n1 = n1 + g[i];
            i++;
        }
    i++;
    n = std::stoi(n1);
    s = g[i];
    jumps.resize(26);
    for (int i = 0; i < n; i++)
    {
        string s1, s2 = "";
        getline(cin, s1);
        char st = s1[0];
        if (s1.length() > 5)
            for (int i = 5; i < s1.length(); i++)
                s2 = s2 + s1[i];
        else s2 = "*";
        jumps[st - 'A'].push_back(s2);
    }
    for (char i = 0; i < jumps.size(); i++)
        for (string j : jumps[i])
            if (j == "*") eps_prod.insert(i + 'A');
    bool eps = true;
    while(eps)
    {
        eps = false;
        for (char i = 0; i < jumps.size(); i++)
            for (auto j : jumps[i])
            {
                bool ad = true;
                for (int k = 0; k < j.length(); k++)
                    if (eps_prod.count(j[k]) == 0) ad = false;
                if (ad)
                {
                    int sz = eps_prod.size();
                    eps_prod.insert(i + 'A');
                    if (sz < eps_prod.size()) eps = true;
                }
            }
    }
    vector<char> ep;
    for (auto c : eps_prod)
        ep.push_back(c);
    sort(ep.begin(), ep.end());
    for (int i = 0; i < ep.size(); i++)
        cout << ep[i] << " ";
}

