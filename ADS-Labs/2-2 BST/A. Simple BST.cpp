#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node * left, * right;
    Node(int x) {
        key = x;
        left = nullptr;
        right = left;
    }
};

Node * root;

Node * insertt(Node * v, int x)
{
    if (v == nullptr) return new Node(x);
    if (v -> key == x) return v;
    if (v -> key < x) v -> right = insertt(v -> right, x);
    else v -> left = insertt(v -> left, x);
    return v;
}

Node * minim(Node * v)
{
    if (v -> left == nullptr) return v;
    return minim(v -> left);
}

Node * deletee(Node* v, int x)
{
    if (v == nullptr) return v;
    if (x < v -> key) v -> left = deletee(v -> left, x);
    else
        if (x > v -> key) v -> right = deletee(v -> right, x);
        else
        {
            if (v -> left && v -> right)
            {
                v -> key = minim(v -> right) -> key;
                v -> right = deletee(v -> right, v -> key);
            }
            else if (v -> left) v = v -> left;
                    else v = v -> right;
        }
    return v;
}

Node * findd(Node * v, int x)
{
    if (v == nullptr) return v;
    if (x == v -> key) return v;
    if (x > v -> key) {
        return findd(v -> right, x);
    } else {
        return findd(v -> left, x);
    }
}

bool exists(int x)
{
    if (findd(root, x) == nullptr) return false;
    return true;
}

Node * next(Node * v, int x)
{
    if (v == nullptr) return v;
    if (x < v -> key)
    {
        Node * nxtt = next(v -> left, x);
        if (nxtt) {
            return nxtt;
        } else {
            return v;
        }
    }
    return next(v -> right, x);
}

Node * prev(Node * v, int x)
{
    if (v == nullptr) return v;
    if (x > v -> key)
    {
        Node * prvv = prev(v -> right, x);
        if (prvv) {
            return prvv;
        } else {
            return v;
        }
    }
    return prev(v -> left, x);
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
                root = insertt(root, x);
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
                    cout << (next(root, x)) -> key << endl;
                else
                    cout << "none" << endl;
                break;
            case 'p':
                if (prev(root, x) != nullptr)
                    cout << (prev(root, x)) -> key << endl;
                else
                    cout << "none" << endl;
                break;
        }
    }
    return 0;
}
