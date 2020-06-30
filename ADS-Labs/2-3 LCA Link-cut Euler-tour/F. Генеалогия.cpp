#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node * left = nullptr, * right = nullptr, * parent = nullptr;
    int size = 1;
};
vector<int> g;
vector<Node *> t;

void update (Node * x)
{
    if (!x) return;
    x -> size = 1;
    if (x -> left) x -> size += x -> left -> size;
    if (x -> right) x -> size += x -> right -> size;
}

void zig (Node * x)
{
    Node * p = x -> parent, * grandp = p -> parent;
    if (!(p && (!grandp || (grandp -> left != p && grandp -> right != p))))
        if (grandp -> left == p) grandp -> left = x;
            else grandp -> right = x;
    if (p -> left == x)
    {
        p -> left = x -> right;
        x -> right = p;
    } else {
        p -> right = x -> left;
        x -> left = p;
    }
    if (x -> left) x -> left -> parent = x;
    if (x -> right) x -> right -> parent = x;
    if (p -> left) p -> left -> parent = p;
    if (p -> right) p -> right -> parent = p;
    if (x) x -> parent = grandp;
    update(p); update(x); update(grandp);
}

Node * splay (Node * x)
{
    Node * p = x -> parent;
    if (x && (!(p) || (p -> left != x && p -> right != x)))
    {
        update(x);
        return x;
    }
    p = x -> parent;
    Node * grandp = p -> parent;
    if (p && (!(grandp) || (grandp -> left != p && grandp -> right != p)))
    {
        zig(x);
        return x;
    }
    if ((grandp -> left == p) == (p -> left == x)) zig(p);
    else zig(x);
    zig(x);
    return splay(x);
}

Node * expose (Node * x)
{
    Node * ex = nullptr;
    for (Node * i = x; i; i = i -> parent)
    {
        splay(i);
        i -> left = ex;
        update(i);
        ex = i;
    }
    splay(x);
    return ex;
}

Node * root (Node * x)
{
    while (x && x -> parent && (x -> parent -> left == x || x -> parent -> right == x))
        x = x -> parent;
    return x;
}

int idx (Node * x)
{
    if (!x) return 0;
    int a = 0;
    if (x -> left) a = x -> left -> size;
    while (!( x && (! x -> parent || (x -> parent -> left != x && x -> parent -> right != x))))
    {
        if (x == x -> parent -> right)
        {
           if (x -> parent -> left)
                a += x -> parent -> left -> size;
            a++;
        }
        x = x -> parent;
    }
    return a;
}



int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++)
        t[i] = new Node();
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (u != -1)
        {
            expose(t[i]);
            t[i] -> parent = t[u - 1];
        }
    }
    cin >> m;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int y;
            cin >> y;
            y--;
            g[j] = y;
        }
        int anss = 0;
        for (int j = 0; j < k; j++)
            expose(t[g[j]]);
        for (int j = 0; j < k; j++)
        {
            int h = idx(t[g[j]]);
            if (h == 0)
                anss += root(t[g[j]]) -> size;
        }
        cout << anss << endl;
        g.clear();
    }
    cin >> n;
    return 0;
}
