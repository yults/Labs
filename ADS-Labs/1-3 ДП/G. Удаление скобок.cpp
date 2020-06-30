#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int> > dp;
vector<vector<int> > ep;

void cout_ans (string s, int l, int r)
{
    if (dp[l][r] == r - l + 1)
    return;
    if (dp[l][r] == 0)
        {
        cout << s.substr(l, r - l + 1);
        return;
        }
    if (ep[l][r] == -1)
    {
        cout << s[l];
        cout_ans(s, l + 1, r - 1);
        cout << s[r];
        return;
    }
    cout_ans(s, l, ep[l][r]);
    cout_ans(s, ep[l][r] + 1, r);
}


int main()
{
    string s;
    cin >> s;
    dp.resize(s.length());
    ep.resize(s.length());
    for (int i = 0; i < s.length(); i++)
    {
    	dp[i].resize(s.length() + 1);
    	ep[i].resize(s.length() + 1);
	}
	for (int i = 0; i < s.length(); i++)
		for (int j = 0; j < s.length(); j++)
			if (i > j) dp[i][j] = 0;
		 	else dp[i][j] = 1000;
    for (int r = 0; r < s.length(); r++)
        for (int l = r; l >= 0; l--)
            {
                if (l == r)
                dp[l][r] = 1;
                else
                {
                    int ans = 1000;
                    int pos = -1;
                    if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']' || s[l] == '{' && s[r] == '}')
                        ans = dp[l + 1][r - 1];
                    for (int k = l; k < r; k++)
                        if (dp[l][k] + dp[k + 1][r] < ans)
                        {
                            ans = dp[l][k] + dp[k + 1][r];
                            pos = k;
                        }
                    dp[l][r] = ans;
                    ep[l][r] = pos;
                }
            }
    cout_ans(s, 0, s.length() - 1);
    return 0;
}
