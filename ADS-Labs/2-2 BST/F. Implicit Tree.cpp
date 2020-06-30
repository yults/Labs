#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y, size;
    Node * left, * right;
    Node(int x1)
    {
        x = x1;
        y = rand() + rand();
        size = 1;
        left = nullptr;
        right = left;
    }
};

int sizee(Node * v)
{
    if (v == nullptr) return 0;
    else return v -> size;
}

void update(Node * v)
{
    if (v == nullptr) return;
    v -> size = sizee(v -> left) + sizee(v -> right) + 1;
}

Node * merge(Node * fir, Node * sec)
{
    if (fir == nullptr) return sec;
    if (sec == nullptr) return fir;
    if (fir -> y > sec -> y)
    {
        fir -> right = merge(fir -> right, sec);
        update(fir);
        return fir;
    }
    else
    {
        sec -> left = merge(fir, sec -> left);
        update(sec);
        return sec;
    }
}

void split(Node * v, int k, Node *&t1, Node *&t2)
{
    if (v == nullptr)
    {
        t1 = t2 = nullptr;
        return;
    }
    int sz = sizee(v -> left);
    if (sz < k)
    {
        split(v -> right, k - 1 - sz, v -> right, t2);
        t1 = v;
    }
    else
    {
        split(v -> left, k, t1, v -> left);
        t2 = v;
    }
    update(v);
}

Node * add(Node * v, int inx, int num)
{
    Node * t1, * t2;
    split(v, inx + 1, t1, t2);
    return merge(merge(t1, new Node(num)), t2);
}

Node* deletee(Node * v, int inx)
{
    Node * t1, * t2, * t3, * t4;
    split(v, inx, t1, t2);
    split(t2, 1, t3, t4);
    v = merge(t1, t4);
    delete t3;
    return v;
}

Node * make_tree(const vector<int>& vec)
{
    Node * result = nullptr;
    for (int i = 0; i < vec.size(); ++i)
    {
        result = merge(result, new Node(vec[i]));
    }
    return result;
}

vector<int> ans;

void anss(Node * v)
{
    if (v == nullptr) return;
    anss(v -> left);
    ans.push_back(v -> x);
    anss(v -> right);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tr(n);
    for (int i = 0; i < n; i++)
        cin >> tr[i];
    Node * tree = make_tree(tr);
    string s;
    for(int i = 0; i < m; ++i)
    {
        cin >> s;
       if (s[0] == 'a')
        {
            int inx, num;
            cin >> inx >> num;
            tree = add(tree, inx - 1, num);
        }
        else
        {
            int num;
            cin >> num;
            tree = deletee(tree, num - 1);
        }
    }
    anss(tree);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
