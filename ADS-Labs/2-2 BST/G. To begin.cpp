#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct Node
{
    int x, y, s;
    Node * left, * right;
    Node(int x1) {
        x = x1;
        y = RAND_MAX * rand();
        left = nullptr;
        right = left;
        s = 1;
    }
};
 
Node * root;
vector<int> ans;
 
int sizee(Node * v)
{
    if (v == nullptr) return 0;
    else return v -> s;
}
 
void update(Node * v)
{
    v -> s = 1 + sizee(v -> left) + sizee(v -> right);
}
 
pair<Node *, Node *> split(Node * v, int z)
{
    if (v == nullptr) return pair<Node *, Node *> (nullptr, nullptr);
    if (z > sizee(v -> left))
    {
        pair<Node *, Node *> t = split(v -> right, z - sizee(v -> left) - 1);
        v -> right = t.first;
        update(v);
        return make_pair(v, t.second);
    }
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
    for (int i = 0; i < n; i++)
        root = mergee(root, new Node(i + 1));
    for (int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;
        pair<Node *, Node *> t1 = split(root, left - 1);
        pair<Node *, Node *> t2 = split(t1.second, right - left + 1);
        root = mergee(mergee(t2.first, t1.first), t2.second);
    }
    anss(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}