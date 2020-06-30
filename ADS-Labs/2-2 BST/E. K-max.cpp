#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    long long x, y, kid;
    Node * left, * right;
    Node(long long x1) {
        x = x1;
        y = RAND_MAX * rand() + rand();
        left = nullptr;
        right = left;
        kid = 1;
    }
};

Node * root;

long long upd (Node * v)
{
    if (v == nullptr) return 0;
    else return v -> kid;
}

void update (Node * v)
{
    v -> kid = 1 + upd(v -> left) + upd(v -> right);
}

Node * mergee(Node * fir, Node * sec)
{
    if (fir == nullptr) return sec;
    if (sec == nullptr) return fir;
    if (fir -> y > sec -> y)
    {
        fir -> right = mergee(fir -> right, sec);
        update(fir);
        return fir;
    }
    else
    {
        sec -> left = mergee(fir, sec -> left);
        update(sec);
        return sec;
    }
}

pair<Node *, Node *> split(Node * v, long long z)
{
    if (v == nullptr) return pair<Node *, Node *>(nullptr, nullptr);
    if (z > v -> x)
    {
        pair<Node *, Node *> t = split(v -> right, z);
        v -> right = t.first;
        update(v);
        return make_pair(v, t.second);
    }
    pair<Node *, Node *> t = split(v -> left, z);
    v -> left = t.second;
    update(v);
    return make_pair(t.first, v);
}

Node * insertt(Node * v, Node * v2)
{
    pair<Node *, Node *> t = split(v, v2 -> x);
    t.first = mergee(t.first, v2);
    return mergee(t.first, t.second);
}

Node * deletee(int z)
{
    pair<Node *, Node *> t1 = split(root, z);
    pair<Node *, Node *> t2 = split(t1.second, z + 1);
    return mergee(t1.first, t2.second);
}

Node * findd(Node * v, long long z)
{
    if (v == nullptr) return v;
    if (z == v -> x) return v;
    if (z > v -> x) return findd(v -> right, z);
    else return findd(v -> left, z);
}

bool exists(long long z)
{
    if (findd(root, z) == nullptr) return false;
    return true;
}

Node * next(Node * v, long long z)
{
    if (v == nullptr) return v;
    if (z < v -> x)
    {
        if (next(v -> left, z)) return next(v -> left, z);
        else return v;
    }
    return next(v -> right, z);
}

Node * prev(Node * v, long long z)
{
    if (v == nullptr) return v;
    if (z > v -> x)
    {
        if (prev(v -> right, z)) return prev(v -> right, z);
        else return v;
    }
    return prev(v -> left, z);
}

long long k_max(Node * v, long long z)
{
    if (upd(v -> right) + 1 == z)
        return v -> x;
    if (v -> right == nullptr)
        return k_max(v -> left, z - 1);
    if (v -> right -> kid >= z)
        return k_max(v -> right, z);
    return k_max(v -> left, z - v -> right -> kid - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    root = nullptr;
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        long long k;
        cin >> c >> k;
        if (c == 1)
            if (!exists(k)) root = insertt(root, new Node(k));
        if (c == 0)
            cout << k_max(root, k) << endl;
        if (c == -1)
            root = deletee(k);
    }
    return 0;
}

