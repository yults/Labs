#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("sparse.in");
    //ofstream cout("sparse.out");
    int n, m, u ,v;
    vector <vector<int> > table(20, vector<int> (200001));
    cin >> n >> m >> table[0][1] >> u >> v;

    vector <int> a(200001);
    a[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (i % (1 << a[i - 1]) == 0)
            a[i]++;
        table[0][i] = (23 * table[0][i - 1] + 21563) % 16714589;
    }

    for (int j = 1; j < table.size(); j++)
    {
        for (int i = 1; i <= (n - (1 << j) + 1); i++)
        {
            table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << j - 1)]);
        }
    }
    int ans;
    int u1 = max(u, v) + 1;
    int v1 = min(u, v);
    int dist = abs(u1 - v1);
    ans = min(table[a[dist]][v1], table[a[dist]][u1 - (1 << a[dist])]);
    for(int i = 1; i < m; i++)
    {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        u1 = max(u, v) + 1;
        v1 = min(u, v);
        dist = abs(u1 - v1);
        ans = min(table[a[dist]][v1], table[a[dist]][u1 - (1 << a[dist])]);
    }
        cout << u << " " << v << " " << ans;

}
