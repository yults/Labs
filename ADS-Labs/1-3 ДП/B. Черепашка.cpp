#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int> > c(n, vector<int>(m, -1e9));
    vector<vector<char> > pred(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    vector<vector<int> > F(n, vector<int> (m, -1e9));
    F[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && F[i - 1][j] > F[i][j])
            {
                F[i][j] = F[i - 1][j];
                pred[i][j] = 'D';
            }
            if (j > 0 && F[i][j - 1] > F[i][j])
            {
                F[i][j] = F[i][j - 1];
                pred[i][j] = 'R';
            }
            F[i][j] += c[i][j];
        }
    }
    int i = n - 1;
    int j = m - 1;
    string s;
    while (i > 0 || j > 0)
    {
      s += pred[i][j];
      if (pred[i][j] == 'R') j--; else i--;
    }
    cout << F[n - 1][m - 1] << endl;
    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}
