#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node * left = nullptr, * right = nullptr, * parent = nullptr;
    long long size = 1; long long upd = 0, ussed = 0;
};
vector<vector<long long> > g;
vector<Node *> t;
vector<bool> used;

void add (Node * x, long long y)
{
    if (!x) return;
    x -> upd += y;
    x -> ussed += y;
}

void push (Node * x)
{
    if (!x -> upd) return;
    add(x -> left, x -> upd);
    add(x -> right, x -> upd);
    x -> upd = 0;
}

void update (Node * x)
{
    if (!x) return;
    x -> size = 1;
    if (x -> left) x -> size += x -> left -> size;
    if (x -> right) x -> size += x -> right -> size;
    x -> upd = 0;
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

void dfs (long long u)
{
    used[u] = true;
    for (long long i : g[u])
        if (!used[i])
        {
            expose(t[i]);
            t[i] -> parent = t[u];
            dfs(i);
        }
}

void build (Node * x, Node * x1, long long y)
{
    expose(x);
    Node * lca = expose(x1);
    if (lca != x1 && lca != x)
    {
        splay(x);
        add(x, y);
    }
    else
    {
     if (x == lca) expose(x1);
     else expose(x);
    }
    splay(lca);
    add(lca -> left, y);
    lca -> ussed += y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d\n", &n);
    t.resize(n);
    for (long long i = 0; i < n; i++)
        t[i] = new Node();
    g.resize(n);
    for (long long i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d %d\n", &v, &u);
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used.resize(n, false);
    dfs(0);
    scanf("%d\n", &m);
    for (long long i = 0; i < m; i++)
    {
        char ch;
        scanf("%c ", &ch);
        if (ch == '+')
        {
            int v, u, y;
            scanf("%d %d %d\n", &v, &u, &y); ;
            v--; u--;
            build(t[u], t[v], y);
        }
        if (ch == '?')
        {
            int u;
            scanf("%d\n", &u);
            u--;
            splay(t[u]);
            printf("%lld\n", t[u] -> ussed);
        }
    }
    return 0;
}
