#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
    Node * left, * right;
    Node(int x1) {
        x = x1;
        y = RAND_MAX * rand();
        left = nullptr;
        right = left;
    }
};

Node * root;

Node * merge(Node * fir, Node * sec)
{
    if (fir == nullptr) return sec;
    if (sec == nullptr) return fir;
    if (fir -> y <= sec -> y)
    {
        sec -> left = merge(fir, sec -> left);
        return sec;
    }
    else
    {
        fir -> right = merge(fir -> right, sec);
        return fir;
    }
}

pair<Node *, Node *> split(Node * v, int z)
{
    if (v == nullptr) return pair<Node *, Node *>(nullptr, nullptr);
    if (z > v -> x)
    {
        pair<Node *, Node *> t = split(v -> right, z);
        v -> right = t.first;
        return make_pair(v, t.second);
    }
    pair<Node *, Node *> t = split(v -> left, z);
    v -> left = t.second;
    return make_pair(t.first, v);
}


Node * insertt(Node * v, Node * v2)
{
    pair<Node *, Node *> t = split(v, v2 -> x);
    t.first = merge(t.first, v2);
    return merge(t.first, t.second);
}

Node * deletee(Node* v, int x)
{
    pair<Node *, Node *>  fir = split(root, x);
    pair<Node *, Node *>  sec = split(fir.second, x + 1);
    return merge(fir.first, sec.second);
}

Node * findd(Node * v, int z)
{
    if (v == nullptr) return v;
    if (z == v -> x) return v;
    if (z > v -> x) return findd(v -> right, z);
    else return findd(v -> left, z);
}

bool exists(int x)
{
    if (findd(root, x) == nullptr) return false;
    return true;
}

Node * next(Node * v, int z)
{
    if (v == nullptr) return v;
    if (z < v -> x)
    {
        if (next(v -> left, z)) return next(v -> left, z);
        else return v;
    }
    return next(v -> right, z);
}

Node * prev(Node * v, int z)
{
    if (v == nullptr) return v;
    if (z > v -> x)
    {
        if (prev(v -> right, z)) return prev(v -> right, z);
        else return v;
    }
    return prev(v -> left, z);
}

int main()
{
    root = nullptr;
    string s;
    int x;
    while (cin >> s)
    {
        cin >> x;
        switch (s[0])
        {
            case 'i':
                root = insertt(root, new Node(x));
                break;
            case 'd':
                root = deletee(root, x);
                break;
            case 'e':
                if (exists(x))
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
                break;
            case 'n':
                if (next(root, x) != nullptr)
                    cout << (next(root, x)) -> x << endl;
                else
                    cout << "none" << endl;
                break;
            case 'p':
                if (prev(root, x) != nullptr)
                    cout << (prev(root, x)) -> x << endl;
                else
                    cout << "none" << endl;
                break;
        }
    }
    return 0;
}
