#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long siz;
long long find_i;
vector<set<long long> > DT;
vector<long long> T, sizes, depth;
vector<vector<long long> > p;
long long n;
struct node
{
    long long c, ws, bs;
    long long wsc, wsn, bsc, bsn;
};
vector<node> wb;

long long lca (long long u, long long v)
{
    if (depth[v] > depth[u])
        swap(u, v);
    for (long long i = find_i; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v]) u = p[u][i];
    if (v != u)
    {
        for (long long i = find_i; i >= 0; i--)
        {
            if (p[v][i] == p[u][i]) continue;
            u = p[u][i];
            v = p[v][i];
        }
        return p[v][0];
    }
    return u;
}

long long find_cen(long long tree, long long parent_tree)
{
    for (long long sub_tree : DT[tree])
        if (sizes[sub_tree] * 2 > siz && sub_tree != parent_tree)
            return find_cen(sub_tree, tree);
    return tree;
}

long long upd(long long new_tree, long long parent_tree)
{
    sizes[new_tree] = 1;
    for (long long tree : DT[new_tree])
        if (tree != parent_tree)
            sizes[new_tree] = sizes[new_tree] + upd(tree, new_tree);
    return sizes[new_tree];
}

void update(long long new_tree, long long parent_tree)
{
    sizes[new_tree] = 1;
    for (long long tree : DT[new_tree])
        if (tree != parent_tree)
            sizes[new_tree] = sizes[new_tree] + upd(tree, new_tree);
}

void build_decomp(long long new_tree, long long centroid)
{
    update(new_tree, -1);
    siz = sizes[new_tree];
    long long cen = find_cen(new_tree, -1);
    T[cen] = centroid;
    for (auto trees : DT[cen])
    {
        DT[trees].erase(cen);
        build_decomp(trees, cen);
    }
    DT[cen].clear();
}


long long D(long long u, long long v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

long long ans(long long u)
{
    long long c = wb[u].c;
    long long a;
    if (c) a = wb[u].bsc;
        else a = wb[u].wsc;
    if (T[u] == -1) return a;
    long long prev = u;
    long long v = T[u];
    while (true)
    {
        if (c)
            a += wb[v].bsc - wb[prev].bsn + D(u, v) * (wb[v].bs - wb[prev].bs);
        else
            a += wb[v].wsc - wb[prev].wsn + D(u, v) * (wb[v].ws - wb[prev].ws);
        if (T[v] == -1) return a;
        prev = v;
        v = T[v];
    }
}

void fil(long long u, long long u1)
{
    p[u].push_back(u1);
    for (long long i : DT[u])
        if (i != u1)
        {
            depth[i] = depth[u] + 1;
            fil(i, u);
        }
}

void colored()
{
    for (long long i = 0; i < n; i++)
    {
        wb[i].c = 1;
        long long v = i;
        while (true)
        {
            wb[v].bs += 1;
            wb[v].bsc += D(i, v);
            if (T[v] == -1) break;
            wb[v].bsn += D(i, T[v]);
            v = T[v];
        }
    }
}

long long col, uu;

void chc(long long u)
{
    if (wb[u].c) col = 1; else col = -1;
    wb[u].c = 1 - wb[u].c;
    long long v = u;
    while (true)
    {
        wb[v].bs -= col;
        wb[v].bsc -= D(u, v) * col;
        wb[v].ws += col;
        wb[v].wsc += D(u, v) * col;
        if (T[v] == -1) return;
        wb[v].bsn -= D(u, T[v]) * col;
        wb[v].wsn += D(u, T[v]) * col;
        v = T[v];
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    long long m;
    cin >> n >> m;
    DT.resize(n);
    T.resize(n);
    sizes.resize(n);
    p.resize(n);
    depth.resize(n);
    wb.resize(n);
    for(long long i = 1; i < n; i++)
    {
        long long v, u;
        cin >> u >> v;
        v--; u--;
        DT[u].insert(v);
        DT[v].insert(u);
    }
    fil(0, 0);
    long long i = 1;
    find_i = 0;
    for (long long j = 1; 1 << (j - 1) < n; j++)
    {
        for (long long i = 0; i < n; i++)
            p[i].push_back(p[p[i][j - 1]][j - 1]);
        find_i++;
    }
    build_decomp(0, -1);
    colored();
    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        v--;
        if (u == 1) chc(v);
            else cout << ans(v) << endl;
    }
}

