#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin("brackets2num.in");
    ofstream cout("brackets2num.out");

    string s;
    cin >> s;
    long long n = s.length() / 2;
    long long k = 0;

    vector<vector<long long> > d(n * 2 + 1, vector <long long> (n + 1));
    for (long long i = 0; i < d.size() - 1; i++)
        for (long long j = 0; j < d[i].size(); j++)
            d[i][j] = 0;
    d[0][0] = 1;
    for (long long i = 1; i < n * 2; i++)
        for (long long j = 0; j < n + 1; j++)
         {
            if (j > 0)
               d[i][j] += d[i - 1][j - 1];
            if (j < n)
               d[i][j] += d[i - 1][j + 1];
         }
    long long b = 0;
    for (long long i = 0; i < n * 2; i++)
        {
        if (s[i] == '(')
                b++;
        else
            {
                if (b < n)
                    k += d[2*n - i - 1][b + 1];
                b--;
            }
        }
    cout << k;
    return 0;
}
