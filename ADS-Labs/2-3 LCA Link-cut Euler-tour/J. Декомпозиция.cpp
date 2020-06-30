#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int siz;
vector<set<int> > DT;
vector<int> T, sizes;

int find_cen(int tree, int parent_tree)
{
    for (int sub_tree : DT[tree])
        if (sizes[sub_tree] * 2 > siz && sub_tree != parent_tree)
            return find_cen(sub_tree, tree);
    return tree;
}

int upd(int new_tree, int parent_tree)
{
    sizes[new_tree] = 1;
    for (int tree : DT[new_tree])
        if (tree != parent_tree)
            sizes[new_tree] = sizes[new_tree] + upd(tree, new_tree);
    return sizes[new_tree];
}

void update(int new_tree, int parent_tree)
{
    sizes[new_tree] = 1;
    for (int tree : DT[new_tree])
        if (tree != parent_tree)
            sizes[new_tree] = sizes[new_tree] + upd(tree, new_tree);
}


void build_decomp(int new_tree, int centroid)
{
    update(new_tree, -1);
    siz = sizes[new_tree];
    int cen = find_cen(new_tree, -1);
    T[cen] = centroid;
    for (auto trees : DT[cen])
    {
        DT[trees].erase(cen);
        build_decomp(trees, cen);
    }
    DT[cen].clear();
}

int main()
{
    int n;
    cin >> n;
    DT.resize(n);
    for(int i = 1; i < n; i++)
    {
        int v, u;
        cin >> u >> v;
        v--; u--;
        DT[u].insert(v);
        DT[v].insert(u);
    }
    T.resize(n);
    sizes.resize(n);
    build_decomp(0, -1);
    for (int i = 0; i < n; i++)
        cout << T[i] + 1 << ' ';
}

