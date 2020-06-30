#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<int> getmin;
vector<int> getmax;
vector<int> rankk;

int leader(int v)
{
    if (p[v] == v) return v;
    else return p[v] = leader(p[v]);
}

void uunion(int x, int y)
{
  x = leader(x);
  y = leader(y);
  if (x == y) return;
  if (rankk[x] > rankk[y]) swap(x, y);
  p[x] = y;
  rankk[y] += rankk[x];
  getmin[y] = min(getmin[y], getmin[x]);
  getmax[y] = max(getmax[y], getmax[x]);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string unorget;
    for(int i = 0; i < n; i++)
    {
        rankk.push_back(1);
        getmin.push_back(i);
        getmax.push_back(i);
        p.push_back(i);
    }
    while(cin >> unorget)
    {
        if (unorget == "union")
        {
            int x, y;
            cin >> x >> y;
            x--; y--;
            uunion(x, y);
        }
        else
        {
            int x;
            cin >> x;
            x--;
            x = leader(x);
            cout << getmin[x] + 1 << ' ' << getmax[x] + 1 << ' ' << rankk[x] << endl;
        }
    }
    return 0;
}
