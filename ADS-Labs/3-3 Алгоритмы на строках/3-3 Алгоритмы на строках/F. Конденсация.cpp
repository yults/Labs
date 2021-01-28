#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> p, rp, lcp, c;
    int sn = s.length(), n = sn + 2 + t.length();
    s = s + '$' + t + '#';
    vector<vector<int>> cc(95);
    c.resize(n), rp.resize(n); lcp.resize(n);;
    for (int i = 0; i < n; i++)
        cc[s[i] - 32].push_back(i);
    int k = 0;
    for (int i = 0; i < cc.size(); i++)
    {
        for (int j : cc[i]) {
            c[j] = k;
            p.push_back(j);
        }
        if (!cc[i].empty()) k++;
    }
    for (int i = 0; (1 << i) < n; i++)
    {
        vector<int> sor(n), nec(n);
        for (int j = 0; j < n; j++)
            sor[j] = int((p[j] - (1 << i) + n) % n);
        vector<vector<int>> cc(k);
        for (int j : sor)
            cc[c[j]].push_back(j);
        p.clear();
        for (int j = 0; j < k; j++)
            for (int z : cc[j])
                p.push_back(z);
        int nk = 0, pf = c[p[0]], ps = c[(p[0] + (1 << i)) % n];
        c[p[0]] = nk;
        for (int z = 1; z < p.size(); z++)
        {
            int iz = p[z], f = c[iz], s = c[(iz + (1 << i)) % n];
            if (f != pf || s != ps)
                nk++;
            nec[iz] = nk;
            pf = f;
            ps = s;
        }
        c = nec;
        k = ++nk;
    }
    for (int i = 0; i < n; i++)
        rp[p[i]] = i;
    k = 0;
    for (int i = 0; i < n; i++)
    {
        k--;
        if (k < 0) k = 0;
        if (rp[i] == n - 1)
        {
            lcp[rp[i]] = 0;
            k = 0;
            continue;
        }
        while (i + k < n && p[rp[i] + 1] + k < n && s[i + k] == s[p[rp[i] + 1] + k]) k++;
        lcp[rp[i]] = k;
    }
    int j = -1;
    for (int i = 2; i < n; i++)
    {
        if ((p[i] < sn) == (p[i + 1] < sn)) continue;
        if (j == -1 || lcp[i] > lcp[j]) j = i;
    }
    for (int i = p[j]; i < p[j] + lcp[j]; i++)
        cout << s[i];
    return 0;
}
