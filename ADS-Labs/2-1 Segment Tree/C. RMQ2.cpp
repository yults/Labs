#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const long long maxx = pow(10,18);

struct List
{
    long long flag = 0;
    long long set1;
    long long add2;
    long long minn;
};

vector<List> t;
vector<List> a;

void propagate(long long x)
{
    long long left = 2 * x + 1;
    long long right = 2 * x + 2;
	if (t[x].flag == 1 && t.size() > left)
        {
        t[left].flag = 1;
        t[right].flag = 1;

		t[left].set1 = t[x].set1;
        t[right].set1 = t[x].set1;

		t[left].minn = t[x].set1;
		t[right].minn = t[x].set1;

		t[x].flag = 0;
        }
    if (t[x].flag == 2 && t.size() > left)
        {
        t[left].minn += t[x].add2;
        t[right].minn += t[x].add2;

        propagate(left);
        t[left].add2 = t[x].add2;
        propagate(right);
        t[right].add2 = t[x].add2;

        t[left].flag = 2;
        t[right].flag = 2;
        t[x].flag = 0;
        }
}

long long cout_min (long long x, long long left, long long right, long long lx, long long rx)
{
    long long l = 2 * x + 1;
    long long r = 2 * x + 2;
    if (lx > rx) return maxx;
    if (lx == left && rx == right)
    {
        if (t[x].flag == 2 && t.size() > l)
            return t[x].minn;
        else
            return t[x].minn;
    }
    propagate(x);
    long long m = (left + right) / 2;
    return min(cout_min(l, left, m , lx, min(rx, m)), cout_min(r, m + 1, right, max(lx, m + 1), rx));
}

void upd_min(long long x)
{
    if (x == 0)
        return;
    long long ver = (x - 1) / 2;
    if (x == ver * 2 + 1)
    {
        t[ver].minn = min(t[x].minn, t[ver * 2 + 2].minn);
    } else {
        t[ver].minn = min(t[x].minn, t[ver * 2 + 1].minn);
    }
    upd_min(ver);
}

void upd_set(long long x, long long left, long long right, long long lx, long long rx, long long new_value)
{
    if (lx > rx)
		return;
	if (lx == left && right == rx)
    {
		t[x].minn = new_value;
		t[x].set1 = new_value;
		t[x].flag = 1;
		upd_min(x);
	}
	else
    {
		propagate(x);
		long long m = (left + right) / 2;
		upd_set (x * 2 + 1, left, m, lx, min(rx, m), new_value);
        upd_set (x * 2 + 2, m + 1, right, max(lx, m + 1), rx, new_value);
	}
}

void upd_add(long long x, long long left, long long right, long long lx, long long rx, long long new_value)
{
    if (lx > rx)
        return;
	if (lx == left && right == rx)
    {
        if (t[x].flag == 1)
            propagate(x);
        t[x].minn += new_value;
        upd_min(x);
        t[x].add2 += new_value;
        if (t[x].flag == 1 || t[x].flag == 0)
            t[x].add2 = new_value;
        t[x].flag = 2;
    } else
    {
        propagate(x);
        long long m = (left + right) / 2;
        upd_add (x * 2 + 1, left, m, lx, min(rx, m), new_value);
        upd_add (x * 2 + 2, m + 1, right, max(lx, m + 1), rx, new_value);
    }
}

void build()
{
    for (int i = 0; i < a.size(); i++)
        t[t.size() / 2 + i].minn = a[i].minn;
    for (int i = a.size() - 2; i >= 0; i--)
        t[i].minn = min(t[2 * i + 1].minn, t[2 * i + 2].minn);
}


int main()
{
    long long n;
    cin >> n;
    long long y = 1;
    while (y < n) y *= 2;
    y = y * 2;
    a.resize(y / 2);
    t.resize(y - 1);
    for (long long i = 0; i < a.size(); i++)
        {
        if (i >= n) a[i].minn = maxx;
        else cin >> a[i].minn;
        }
    build();
    string zapros;
    int k = 0;
    while (cin >> zapros)
    {
        long long i, j;
        cin >> i >> j;
        i--; j--;
        if (zapros == "min")
            cout << cout_min(0, 0 , a.size() - 1, i, j) << endl;
        else {
            long long x;
            cin >> x;
            if (zapros == "set")
                upd_set(0, 0, a.size() - 1, i, j, x);
            else if (zapros == "add")
                upd_add(0, 0 , a.size() - 1, i, j, x);
        }
    }
}

