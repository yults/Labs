#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    vector<pair<double, double> > g;
    int n;
    cin >> n;
    double cnt = 0;
    vector<int> ee(n, -1);
    vector<double> me(n, 1000000000);
    vector<bool> used(n);
    me[0] = 0;
    for (int i = 0; i < n; i++)
    {
        double u, v;
        cin >> u >> v;
        g.push_back(make_pair(u, v));
    }
    for (int i = 0; i < n; i++)
    {
        int x = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (me[x] > me[j] || x == -1)) x = j;
        used[x] = true;
        if (x != 0)
            cnt += sqrt(pow(g[x].first - g[ee[x]].first, 2) + pow(g[x].second - g[ee[x]].second, 2));
        for (int j = 0; j < n; j++)
        {
            double y = sqrt(pow(g[x].first - g[j].first, 2) + pow(g[x].second - g[j].second, 2));
            if (me[j] > y)
            {
                me[j] = y;
                ee[j] = x;
            }
        }
    }
    cout << fixed << setprecision(15) << cnt;
    return 0;
}
