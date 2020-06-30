#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;
int n;

void swwap(int i)
{
	int l = i + 1;
    int r = n - 1;
    while (l < r)
	{
        swap(a[l], a[r]);
        l++;
        r--;
	}
}

bool next_perm()
{
    int i;
    for (i = n - 2; i > -1; i--)
	{
        if (a[i + 1] > a[i]) break;
    }
    if (i == -1) return false;
    int j;
    for (j = n - 1; j > -1; j--)
	{
        if (a[j] > a[i]) break;
    }
    swap(a[i], a[j]);
    swwap(i);
	return true;
}

int main()
{
ifstream cin ("permutations.in");
ofstream cout("permutations.out");
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) 
	{
            a[i] = i + 1;
            cout << a[i] << " ";
    }
    cout << endl;
    while(next_perm())
	{
        for (int i = 0; i < n; i++)
		{
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
