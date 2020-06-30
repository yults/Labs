#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
int n, k;
vector <int> a;

int next_choose()
{
    int i = -1;
    for (i = k - 1; i > -1; i--)
	{
        if (a[i] < n)
		{
            a[i]++;
            break;
        }
    }
    if (i == -1) return false;
    for (int j = i + 1; j < k; j++)
	{
        a[j] = a[j - 1] + 1;
    }
    return true;

}

int main()
{
    ifstream cin("choose.in");
    ofstream cout("choose.out");
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) 
	{
 	 	a[i] = i+1;
    	cout << a[i] << " ";
    }
    cout << endl;
    while (next_choose())
	{
        int flag = 0;
        for (int i = 0; i < k; i++)
		{
            if (a[i] > n) flag = 1;
        }
	 	if (flag == 0)
	    {
		    for (int i = 0 ; i < k; i++)
            	cout << a[i] << " ";
        cout << endl;
    	}
    }
}
