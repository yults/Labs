#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node
{
    Node * left = nullptr, * right = nullptr, * parent = nullptr;
    int size = 1; pair<int, int> g;
    Node(int u1, int v1)
    {
       g = {u1, v1};
    }
};
map<pair<int, int>, Node *> g;
vector<Node *> t;
Node * curu;
Node * curv;

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
    if (grandp)
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
    if (!p)
        return x;
    p = x -> parent;
    Node * grandp = p -> parent;
    if (!(grandp))
    {
        zig(x);
        return x;
    }
    if ((grandp -> left == p) == (p -> left == x)) zig(p);
    else zig(x);
    zig(x);
    return splay(x);
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

Node * root(Node * u)
{
    if (!u) return nullptr;
    while (u -> parent) u = u -> parent;
    return u;
}

Node * left(Node * u)
{
    if (!u) return nullptr;
    while (u -> left) u = u -> left;
    return u;
}

Node * right(Node * u)
{
    if (!u) return nullptr;
    while (u -> right) u = u -> right;
    return u;
}


void split(Node * tr, int x)
{
    if(!tr) {curu = nullptr; curv = nullptr; return;}
    int a = 0;
    if (tr -> left) a = tr -> left -> size;
    if (a >= x)
    {
        split(tr -> left, x);
        Node * f = curu, * s = curv;
        tr -> left = s;
        if (s) s -> parent = tr;
        if (f) f -> parent = nullptr;
        update(tr);
        curu = f; curv = tr; return;
    }
    else
    {
        split(tr -> right, x - a - 1);
        Node * f = curu, * s = curv;
        tr -> right = f;
        if (f) f -> parent = tr;
        if (s) s -> parent = nullptr;
        update(tr);
        curu = tr; curv = s; return;
    }
}

Node * mergee(Node * x, Node * y)
{
    if (!x) return y;
    if (!y) return x;
    splay(x);
    while (x -> right) x = x -> right;
    splay(x);
    x -> right = y;
    if (y) y -> parent = x;
    update(x);
    return x;
}

void cut(int u, int v)
{
    Node * p = g[{u, v}];
    Node * rp = g[{v, u}];
    g.erase({u, v});
    g.erase({v, u});
    if (idx(rp) < idx(p)) swap(rp, p);
    split(root(p), idx(p));
    Node * x1 = curu, * x23 = curv;
    Node * rx1 = right(x1);
    split(x23, 1);
    x23 = curv;
    split(x23, idx(rp));
    Node * x2 = curu, * x3 = curv;
    Node * lx2 = left(x2);
    Node * rlx2 = nullptr;
    if (lx2) rlx2 = g[{lx2 -> g.second, lx2 -> g.first}];
    Node * rx2 = right(x2);
    split(x3, 1);
    x3 = curv;
    Node * lx3 = left(x3);
    Node * rlx3 = nullptr;
    if (lx3) rlx3 = g[{lx3 -> g.second, lx3 -> g.first}];
    if (rx2) t[p -> g.second] = rx2;
        else t[p -> g.second] = rlx2;
    if (rx1) t[p -> g.first] = rx1;
        else t[p -> g.first] = rlx3;
    mergee(x1, x3);
}


void link(int u1, int v1)
{
    Node * u = t[u1], * v = t[v1];
    split(root(u), idx(u) + 1);
    Node * x1 = curu, * x4 = curv;
    split(root(v), idx(v) + 1);
    Node * x3 = curu, * x2 = curv;
    Node * p = new Node(u1, v1), * rp = new Node(v1, u1);
    if (!v) t[v1] = p; if (!u) t[u1] = rp;
    g.insert({{u1, v1}, p}); g.insert({{v1, u1}, rp});
    Node * x1p = mergee(x1, p), * rpx4 = mergee(rp, x4);
    Node * x1px2 = mergee(x1p, x2), * x3rpx4 = mergee(x3, rpx4);
    mergee(x1px2, x3rpx4);
}

int main()
{
    int n, m;
    cin >> n >> m;
    t.resize(n, nullptr);
    for (int i = 0; i < m; i++)
    {
        string op;
        int u, v;
        cin >> op;
        u--; v--;
        if (op == "size")
        {
            cin >> u;
            u--;
            int siz = 0;
            Node * uu = t[u], * ur = root(uu);
            if (ur) siz = ur -> size;
            cout << siz / 2 + 1 << endl;
        }
        if (op == "link")
        {
            cin >> u >> v;
            u--; v--;
           link(u, v);
        }
        if (op == "cut")
        {
            cin >> u >> v;
            u--; v--;
            cut(u, v);
        }
    }
}
