#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;

int next_part(int k)
{
    a[k-1]--;
	a[k-2]++;
    if (a[k-2] > a[k-1])
	{
        a[k-2] += a[k-1];
        k--;
        a.pop_back();
    } else
	{
        while (a[k-2] * 2 <= a[k-1])
		{
            a.push_back(a[k-1] - a[k-2]);
            k = a.size();
            a[k-2] = a[k-3];
        }
    }
    return k;
}


int main()
{
	ifstream cin ("partition.in");
	ofstream cout("partition.out");
	int n;
 	cin >> n;
    a.resize(n, 1);
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << "+";
    cout << a[n - 1];
    cout << endl;

    while (a.size()!= 1)
	{
 	    n = next_part(n);
        for (int i = 0; i < a.size() - 1; i++)
 			cout << a[i] << "+";
  		cout << a[a.size() - 1];
        cout << endl;
    }
}

