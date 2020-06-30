#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ifstream cin ("subsets.in");
	ofstream cout("subsets.out");
	int n;
 	cin >> n;
 	vector<int> a;
 	vector<vector<int> > ans;
 	for (int i = 1; i <= n; i++)
 	{
 		a.push_back(i);
 	}
	for (int mask = 0; mask < (1 << n); mask++)
	{
		ans.push_back(vector<int>());
		for (int i = 0; i < n; i++)
		{
			if ((bool)(mask & (1 << i)))
			   ans.back().push_back(a[i]);
		}
	}
	sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
    	for (int j = 0; j < ans[i].size(); j++)
    		cout << ans[i][j] << ' ';
   		cout << endl;
	}
}
