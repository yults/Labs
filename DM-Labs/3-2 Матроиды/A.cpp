#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

struct s{
    long long d, w;
};

vector<vector <int> > vv;
vector<bool> b;
vector<int> a, l;
vector<s> vs;
int n, m;

bool operator<(const s& x, const s& y){
    if (x.d == y.d) return x.w > y.w;
    return x.d > y.d;
}

bool DFS(int x){
    if (b[x]) return false;
    b[x] = true;
    for (int vx : vv[x]){
        if (l[vx] == -1 || DFS(l[vx])){
            l[vx] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream cin ("matching.in");
    ofstream cout ("matching.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    l.resize(n, -1);
    a.resize(n, -1);
    vv.resize(n);
    vs.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vs[i] = {x, i};
    }
    sort(vs.begin(), vs.end());
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++){
            cin >> y;
            vv[i].push_back(--y);
        }
    }
    for (auto x : vs){
        b.assign(n, 0);
        DFS(x.w);
    }
    for (int i = 0; i < n; i++)
        if (l[i] != -1) a[l[i]] = i;
    for (auto x : a)
        cout << ++x << " ";
    return 0;
}

