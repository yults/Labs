#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
    public:
    long long x, y, size, flag;
    Node * left, * right , * parent;
    Node(long long x1, Node * par) : left(nullptr), right(nullptr), parent(par), x(x1), size(1), flag(false), y(rand() + rand()) {}
	Node(long long x1) : left(nullptr), right(nullptr), parent(nullptr), x(x1), size(1), flag(false), y(rand() + rand()) {}
};

vector<long long> ans;
Node* root = nullptr;

long long size(Node * v)
{
    if (v == nullptr) return 0;
	return v -> size;
}

void update(Node * v)
{
	if (v != nullptr) {
		v -> size = 1 + size(v -> left) + size(v -> right);
	}
}

void prop (Node * node)
{
    if (node && node -> flag) {
        swap(node -> left, node -> right);
        if (node -> left) node -> left -> flag ^= 1;
        if (node -> right) node -> right -> flag ^= 1;
        node -> flag = false;
    }

}

Node * merge(Node * fir, Node * sec)
{
    prop(fir);
    prop(sec);
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

pair <Node *, Node *> split(Node * v, long long k, long long z)
{
    prop(v);
	if (v == nullptr) return make_pair(nullptr, nullptr);
	long long cnt = z + size(v -> left);
	if (k > cnt)
        {
		pair <Node*, Node*> t = split(v -> right, k - cnt - 1, 0);
		v -> right = t.first;
		update(v);
		return make_pair(v, t.second);
	} else
	{
		pair <Node *, Node *> t = split(v -> left, k, 0);
		v -> left = t.second;
		update(v);
		return make_pair(t.first, v);
	}
}


void anss(Node * v)
{
	if (v != nullptr)
        {
        prop(v);
		anss(v -> left);
		ans.push_back(v -> x);
		anss(v -> right);
        }
}

void insert(int k){
    auto t = split(root, k, 0);
    Node * t1 = new Node(k);
    root = merge(t.first, merge(t1, t.second));
}

void reversee (int left, int right) {
    auto t1 = split(root, right, 0);
    auto t2 = split(t1.first, left, 0);
    if (t2.second) t2.second -> flag ^= 1;
    root = merge(t2.first, merge(t2.second, t1.second));
}

int main()
{
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
		insert(i + 1);
	long long left, right;
	for (long long i = 0; i < m; i++)
    {
		cin >> left >> right;
		reversee(left - 1, right);
	}
	anss(root);
	for (long long i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
	return 0;
}
