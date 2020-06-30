#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node * left = nullptr, * right = nullptr, * parent = nullptr;
    int size = 1;
    bool upd = false, ussed = false;
};
vector<vector<int> > g;
vector<Node *> t;
vector<bool> used;

void push (Node * x)
{
    if (! x -> upd) return;
    x -> upd = false; x -> ussed = true;
    if (x -> left) x -> left -> upd = x -> left -> ussed = true;
    if (x -> right) x -> right -> upd = x -> right -> ussed = true;
}

void update (Node * x)
{
    if (!x) return;
    x -> size = 1; x -> upd = false;
    if (x -> left) x -> size += x -> left -> size;
    if (x -> right) x -> size += x -> right -> size;
}

void zig (Node * x)
{
    Node * p = x -> parent, * grandp = p -> parent;
    if (grandp) push(grandp);
    push(p); push(x);
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
        push(x); update(x);
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

void pushing (Node * u)
{
    if (!u || !u -> upd) return;
    push(u);
    pushing(u -> left);
    pushing(u -> right);
}

void dfs (int u)
{
    used[u] = true;
    for (int i : g[u])
        if (!used[i])
        {
            expose(t[i]);
            t[i] -> parent = t[u];
            dfs(i);
        }
}

void build (Node * x, Node * x1)
{
    expose(x);
    Node * lca = expose(x1);
    if (lca != x1 && lca != x)
    {
        splay(x);
        x -> upd = x -> ussed = true;
        splay(lca);
        lca -> left -> upd = lca -> left -> ussed = true;
        return;
    }
    Node * x2;
    if (x == lca)
        x2 = x1;
    else x2 = x;
    expose(x2);
    splay(lca);
    lca -> left -> upd = lca -> left -> ussed = true;
}

int main()
{
    int n, m, ans = 0;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++)
        t[i] = new Node();
    g.resize(n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used.resize(n, false);
    dfs(0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> u >> v;
        v--; u--;
        build(t[u], t[v]);
    }
    for (int i = 0; i < n; i++)
        pushing(t[i]);
    for (int i = 0; i < n - 1; i++)
        if (! t[i + 1] -> ussed) ans++;
    cout << ans << endl;
    return 0;
}
