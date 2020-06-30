#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
long long  n;
vector <long long > t;
vector <long long > a;

void set_do (long long i, long long v)
{
    t[i] = v;
    while(i >  0)
    {
        i = (i - 1) / 2;
        t[i] = min(t[2 * i + 1], t[2 * i + 2]);
    }
}

long long  minn(long long  x, long long  left, long long  right, long long  lx, long long  rx)
{
    if (left == right && left >= lx && left <= rx)
        return t[x];
    if (left >= right || left > rx || right < lx)
        return n;
    long long  m = (left + right) / 2;
    return min(minn(2 * x + 1, left, m , lx, min(rx, m)), minn(2 * x + 2, m + 1, right, max(lx, m + 1), rx));
}

void update(long long  ver, long long  left, long long  right, long long  itemp, long long  x)
{
    if (left == right)
        t[ver] = x;
    else {
        long long  m = (left + right) / 2;
        if (itemp <= m)
            update(2 * ver + 1, left, m, itemp, x);
            else
            update(2 * ver + 2, m + 1, right, itemp, x);
        t[ver] = min(t[2 * ver + 1], t[2 * ver + 2]);
    }
}

int  main()
{
    ifstream cin("parking.in");
    ofstream cout("parking.out");
    long long  m;
    cin >> n >> m;
    long long  y = 1;
    while(y < n)
        y *= 2;
    y = y * 2;
    a.resize(y / 2);
    t.resize(y /2);
    long long  siz = a.size() - 1;
      for (long long i = 0; i < y / 2; i++)
    {
        t.push_back(0);
    }
    y = y / 2;
    for (long long i = 0; i < a.size(); i++)
    {
        if (i < n) a[i] = i;
        else a[i] = n;
        long long ii = i + y - 1;
        set_do(ii, a[i]);
    }
    for(int i = 0; i < t.size(); i++)
    cout << t[i] <<' ' ;
    cout << endl;
    for (long long  i = 0; i < m; i++)
    {
        string zapros;
        long long  x;
        cin >> zapros >> x;
        if (zapros == "exit")
            update(0, 0, siz, x - 1, x - 1);
        else {
            long long  ans = minn(0, 0, siz, x - 1, siz);
            if (ans >= n)
            ans = minn(0, 0, siz, 0, siz);
            cout << ans + 1 << endl;
            update(0, 0, siz, ans, n);
        }
    }
}
