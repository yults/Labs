#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int siz = (1 << n);
    vector<vector<int>> x1xnf(siz);
    for (int i = 0; i < siz; i++)
    {
        int j = i;
        for(int cnt = 0; cnt < n; cnt++)
        {
            x1xnf[i].push_back(j % 2);
            j = j / 2;
        }
        x1xnf[i].push_back(1);
    }
    set <pair<int,int>> used;
    int cnt = 0;
    for (int i = 0; i < k; i++)
        {
        int a, b;
        cin >> a >> b;
        if (a - b > 0)
            swap(a, b);
        pair<int,int> newpair = make_pair(a, b);
        if (used.find(newpair) != used.end()) continue;
        used.insert(newpair);
        int z1 = abs(a) - 1;
        int z2 = abs(b) - 1;
        int a01, b01;
        if (a > 0) a01 = 0; else a01 = 1;
        if (b > 0) b01 = 0; else b01 = 1;
        for (int j = 0; j < siz; j++)
            {
            if (x1xnf[j][z1] == a01 && x1xnf[j][z2] == b01)
                {
                if (x1xnf[j][n] == 1) cnt++;
                x1xnf[j][n] = 0;
                }
            }
        }
    if (cnt == siz) cout << "YES";
        else cout << "NO";
}
