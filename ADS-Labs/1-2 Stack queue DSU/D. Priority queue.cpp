#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Deque
{
    vector<int> a  = vector<int>(500000);
    int l = 250000;
    int r = 250000;

    int sizze()
    {
        return r - l;
    }

    void r_pop()
    {
        a[--r] = 0;
    }

    void l_pop()
    {
        a[l++] = 0;
    }

    void l_push(long long x)
    {
        a[--l] = x;
    }

    void r_push(long long x)
    {
        a[r++] = x;
    }

    long long br()
    {
        return a[r - 1];
    }

    long long fl()
    {
        return a[l];
    }

    bool isEmpty()
    {
        return a.empty();
    }
};

void balance(Deque &x, Deque &y)
{
    while(x.sizze() - y.sizze() < 0)
    {
        x.r_push(y.fl());
        y.l_pop();
    }
    while (x.sizze() - y.sizze() > 1)
    {
        y.l_push(x.br());
        x.r_pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Deque x, y;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        switch(ch)
        {
        case '+':
        {
            int in;
            cin >> in;
            y.r_push(in);
            break;
        }
        case '-':
        {
            cout << x.fl() << endl;
            x.l_pop();
            break;
        }
        case '*':
        {
            int in;
            cin >> in;
            x.r_push(in);
            break;
        }
        }
        balance(x, y);
    }
    return 0;
}
