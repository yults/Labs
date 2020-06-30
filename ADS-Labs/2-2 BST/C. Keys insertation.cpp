#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int x, y, s, z;
    Node * left, * right;
    Node(int x1) {
        x = x1;
        y = RAND_MAX * rand() + rand();
        left = nullptr;
        right = left;
        s = 1;
        if (x1 == 0) z = 1;
        else z = 0;
    }
};

Node * root;
vector<int> ans;

int sizee(Node * v)
{
    if (v == nullptr) return 0;
    else return v -> s;
}

int zero(Node * v)
{
    if (v == nullptr) return 0;
    else return v -> z;
}

void update(Node * v)
{
    if (!v) return;
    else
    {
        v -> s = 1 + sizee(v -> left) + sizee(v -> right);
        v -> z = zero(v -> left) + zero(v -> right) + (v -> x ? 0 : 1);
    }
}

pair<Node *, Node *> split(Node * v, int z)
{
    if (z > sizee(v -> left) + 1)
    {
        pair<Node *, Node *> t = split(v -> right, z - sizee(v -> left) - 1);
        v -> right = t.first;
        update(v);
        return make_pair(v, t.second);
    }
    if (z == sizee(v -> left) + 1)
    {
        Node * t = v -> right;
        v -> right = nullptr;
        update(v);
        return make_pair(v, t);
    }
    if (z == 0)
        return make_pair(nullptr, v);
    pair<Node *, Node *> t = split(v -> left, z);
    v -> left = t.second;
    update(v);
    return make_pair(t.first, v);
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

Node * delete_zero(Node * v)
{
    if (v -> left && v -> left -> z)
        v -> left = delete_zero(v -> left);
    else if (v -> x == 0)
        v = mergee(v -> left, v -> right);
    else
        v -> right = delete_zero(v -> right);
    update(v);
    return v;
}

void anss(Node * v)
{
    if (v == nullptr) return;
    anss(v -> left);
    ans.push_back(v -> x);
    anss(v -> right);
}

int main()
{
    root = nullptr;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
        root = mergee(root, new Node(0));
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        pair<Node *, Node *> t = split(root, k - 1);
        t.first = mergee(t.first, new Node(i));
        t.second = delete_zero(t.second);
        root = mergee(t.first, t.second);
    }
    anss(root);
    while (ans[ans.size() - 1] == 0)
        ans.pop_back();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
