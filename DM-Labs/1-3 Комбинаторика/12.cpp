#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
 	int n, k;
 	cin >> n >> k;
	int siz = pow(k, n);
	vector<vector<int> > a(siz, vector<int> (n + 1));	
    int h = 1;
    for (int i = n - 1; i >= 0; i--)
	{
        if (i != n - 1) h = h * k;
        int h1 = 0;
        for (int j = 0; j < siz; j++) 
		{
            if (j == 0) a[j][i] = h1; 
			else
			{
                if (j % h == 0)
				{
				a[j][i] = h1;
                h1 = (h1 + 1) % k;
		 	    } 
				else 
                    a[j][i] = h1;
            }
        }

    }
    for (int i = 0; i < siz; i++)
	{
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
