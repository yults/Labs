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
	ifstream cin ("allvectors.in");
	ofstream cout ("allvectors.out");
    cin >> n;
    string s;
    genObj(0, s);
    for(int i = 0; i < ans.size(); i++)
    {
    	cout << ans[i] << endl;
	}
}
