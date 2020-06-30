#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<char> ans, ned, nep, p, d;
vector<vector<string> > jumps, jumps2;
vector<bool> vis;

int main()
{
    ifstream cin ("useless.in");
    ofstream cout ("useless.out");
    int n;
    char s;
    string g;
    getline(cin, g);
    string n1 = "";
    int i = 0;
    vis.resize(101, false);
    while (g[i] >= '0' && g[i] <= '9')
        {
            n1 = n1 + g[i];
            i++;
        }
    i++;
    n = std::stoi(n1);
    s = g[i];
    vis[s] = true;
    jumps.resize(101);
    jumps2.resize(101);
    for (int i = 0; i < n; i++)
    {
        string s1, s2 = "";
        getline(cin, s1);
        char st = s1[0];
        vis[st] = true;
        if (s1.length() > 5)
                for (int i = 5; i < s1.length(); i++)
                {
                    s2 = s2 + s1[i];
                    vis[s1[i]] = true;
                }
        else s2 = "ep";
        jumps[st - 'A'].push_back(s2);
    }
    for (char i = 0; i < jumps.size(); i++)
        for (string j : jumps[i])
        {
            bool f = true;
            for (int z = 0; z < j.length(); z++)
                if (!islower(j[z])) f = false;
            if (f) p.insert(i + 'A');
        }
    bool eps = true;
    while(eps)
    {
        eps = false;
        for (char i = 0; i < jumps.size(); i++)
            for (auto j : jumps[i])
            {
                bool ad = true;
                for (int k = 0; k < j.length(); k++)
                    if (!islower(j[k]) && p.count(j[k]) == 0) ad = false;
                if (ad)
                {
                    int sz = p.size();
                    p.insert(i + 'A');
                    if (sz < p.size()) eps = true;
                }
            }
    }
    for (char i = 0; i < jumps.size(); i++)
    {
        bool f = true;
        if (vis[i] && p.count(i) == 0 && !islower(i)) continue;
        for (auto jump : jumps[i])
        {
            f = true;
            for (int j = 0; j < jump.length(); j++)
                if (!islower(jump[j]) && p.count(jump[j]) == 0)
                    f = false;
            if (!f) continue;
            jumps2[i].push_back(jump);
        }
    }
    for (char i = 40; i < 101; i++)
        if (vis[i] && p.count(i) == 0 && !islower(i))
            nep.insert(i);
    if (p.count(s) == 0)
        {
            for (char i = 65; i < 100; i++)
                if (vis[i]) nep.insert(i);
        }
    else
    {
        d.insert(s);
        eps = true;
        while(eps)
        {
            eps = false;
            for (char i = 0; i < jumps2.size(); i++)
                for (auto j : jumps2[i])
                    if (d.count(i + 'A') != 0)
                        for (int k = 0; k < j.length(); k++)
                            if (!islower(j[k]))
                                {
                                    int sz = d.size();
                                    d.insert(j[k]);
                                    if (sz < d.size()) eps = true;
                                }
        }
        for (char i = 40; i < 100; i++)
        {
            if (vis[i] && d.count(i) == 0 && !islower(i))
            nep.insert(i);
        }
    }
    vector<char> usles;
    for (auto c : nep)
        usles.push_back(c);
    sort(usles.begin(), usles.end());
    for (int i = 0; i < usles.size(); i++)
        if (!islower(usles[i]))cout << usles[i] << " ";
}

