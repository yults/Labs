#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    long long x, y, s;
    Node * left, * right;
    Node(long long x1) {
        x = x1;
        y = RAND_MAX * rand() + rand();
        left = nullptr;
        right = left;
        s = x1;
    }
};

const long long cnst = 1000000000;
Node * root;

long long upd (Node * v)
{
    if (v == nullptr) return 0;
    else return v -> s;
}

void update (Node * v)
{
    v -> s = upd(v -> left) + upd(v -> right) + v -> x;
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
    else
    {
        pair<Node *, Node *> t = split(v -> left, z);
        v -> left = t.second;
        update(v);
        return make_pair(t.first, v);
    }
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

Node * next(Node * v, long long k)
{
    if (v == nullptr) return v;
    if (k < v -> x)
    {
        Node * v1 = next(v -> left, k);
        if (v1 == nullptr) return v; else return v1;
    }
    return next(v -> right, k);
}

Node * prev(Node * v, long long k)
{
    if (v == nullptr) return v;
    if (k > v -> x)
    {
        Node * v1 = prev(v -> right, k);
        if (v1 == nullptr) return v; else return v1;
    }
    return prev(v -> left, k);
}

long long sum(long long left, long long right)
{
	Node * v1 = next(root, left - 1);
    Node * v2 = prev(root, right + 1);
    if (v1 == nullptr || v2 == nullptr || (v1 -> x > v2 -> x)) return 0;
    pair<Node *, Node *> t1 = split(root, v1 -> x);
    pair<Node *, Node *> t2 = split(t1.second, v2 -> x + 1);
    long long k = t2.first -> s;
    root = mergee(t1.first, mergee(t2.first, t2.second));
    return k;
}

Node * insertt(Node * v, Node * v1)
{
	pair<Node *, Node *> t = split(v, v1 -> x);
	t.first = mergee(t.first, v1);
    return mergee(t.first, t.second);
}

int main()
{
    root = nullptr;
    long long pr = 0;
    long long n;
    cin >> n;
    char ch;
    bool if_add = false;
    for (long long i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == '?')
        {
            long long left, right;
            cin >> left >> right;
            pr = sum(left, right);
            cout << pr << endl;
            if_add = true;
        }
        if (ch == '+')
        {
            long long x;
            cin >> x;
            if (if_add) x = (x + pr) % cnst;
            if (!exists(x)) root = insertt(root, new Node(x));
            if_add = false;
        }
    }
    return 0;
}
