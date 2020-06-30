#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length() + 1;
    int m = s2.length() + 1;
    s1 = "#" + s1;
    s2 = "#" + s2;
    vector<vector<int> > d(n, vector<int>(m));
    d[0][0] = 0;
    for (int j = 1; j < m; j++)
    {
        d[0][j] = d[0][j - 1] + 1;
    }
    for (int i = 1; i < n; i++)
    {
        d[i][0] = d[i - 1][0] + 1;
        for (int j = 1; j < m; j++)
        {
            if (s1[i] != s2[j])
            {
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
                d[i][j] = min(d[i][j], d[i - 1][j - 1] + 1);
            }
            else
                d[i][j] = d[i - 1][j - 1];
        }
    }
    cout << d[n - 1][m - 1];
    return 0;
}
