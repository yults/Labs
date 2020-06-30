#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main() {
	ifstream cin ("telemetry.in");
	ofstream cout("telemetry.out");
	long long n, k;
	cin >> n >> k;
	long long siz = pow(k, n);
	vector<vector<long long> > ans(siz, vector<long long>(n));
	long long cur = 1;
	for (int i = 0; i < n; i++) 
	{
 		if (i > 0) cur = cur * k;
		long long idx = 0;
		while (idx < siz)
	    {
			long long p = 0;
			while (idx < siz && p < k) 
			{
				for (long long j = 0; j < cur; j++)
			    {
					ans[idx][i] = p;
					idx++;
				}
				p++;
			}
			p--;
			while (idx < siz && p > -1)
		    {
				for (int j = 0; j < cur; j++)
			    {
					ans[idx][i] = p;
					idx++;
				}
				p--;
			}
		}
	}

	for (long long i = 0; i < siz; i++)
	{
		for (long long j = 0; j < n; j++) 
			cout << ans[i][j];
		cout << endl;
	}

}
