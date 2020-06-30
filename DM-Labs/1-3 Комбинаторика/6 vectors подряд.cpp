#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int n;
vector <string> ans;
void genObj(int i, string s)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    genObj(i + 1, s + "0");
    genObj(i + 1, s + "1");
}

int main()
{
ifstream cin ("vectors.in");
ofstream cout("vectors.out");
    cin >> n;
    string s;
    genObj(0, s);
    int ans_kol = 0;
   
    for(int i = 0; i < ans.size(); i++)
    {
    	int flag = 0;
    	for (int j = 1; j < ans[i].size(); j++)
    	{
    		if (ans[i][j - 1] == '1' && ans[i][j] == '1') flag = 1;
		}
		if (flag == 0) ans_kol++;
	}
	cout << ans_kol << endl;
	for(int i = 0; i < ans.size(); i++)
    {
    	int flag = 0;
    	for (int j = 1; j < ans[i].size(); j++)
    	{
    		if (ans[i][j - 1] == '1' && ans[i][j] == '1') flag = 1;
		}
		if (flag == 0) cout << ans[i] << endl;
	}
}


