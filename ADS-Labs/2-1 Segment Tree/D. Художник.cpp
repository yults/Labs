#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Zapros
{
    int color;
    int l;
    int r;

};

struct Tree
{
    int sum;
    int cnt;
};
vector <Tree> t;


void build(vector <int> a)
{
	int n = a.size();
    for (int i = 0; i < n; i++)
	{
        t[t.size() / 2 + i].sum = a[i];
    }
    n--;
    for (int i = n - 1; i >= 0; i--)
	{
        t[i].sum = t[2 * i + 1].sum + t[2 * i + 2].sum;
        t[i].cnt = ???;
    }
}



int main()
{
    int n;
    cin >> n;
    char col;
    vector <Zapros> a(n);
    int leftel = 500001, rightel = -500001;

    for (int i = 0; i < n; i++)
	{
		Zapros z;
        cin >> col >> z.l >> z.r;
        z.r += z.l - 1;
        z.l--;
        if (col == 'B')
	 	{
            z.color = 1;
        } else
	    {
            z.color = 0;
        }
        a.push_back(z);
        leftel = min(z.l, leftel);
 		leftel = min(z.r, leftel);
 		rightel = max(z.l, rightel);
        rightel = max(z.r, rightel);
    }

    rightel++;
    leftel = min(0, leftel);
    leftel = abs(leftel);
    int n1 = rightel + leftel;

    long long y = 1;
    while (y < n1)
	   y *= 2;
    vector <int> p(y);
    t.resize(y * 2 - 1);

    for (int i = 0; i < n; i++)
	{
        for (int j = a[i].l; j < a[i].r; j++)
		{
            p[j] = a[i].color;
        }
        build(p);
    }
    for (int i = 0; i < t.size(); i++){
                cout << t[i].sum << " ";
            }
            cout << endl;
    return 0;
}
