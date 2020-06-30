#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > p(n, vector<int> (log(n)/log(2) + 1, -1));
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        p[i][0] = c - 1;
    }
    int i = 1;
    while((1 << (i - 1)) < n)
    {
        for (int j = 0; j < n; j++)
            if (p[j][i - 1] != -1)
                p[j][i] = (p[p[j][i - 1]][i - 1]);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        int j = 0;
        while((1 << (j - 1) < n) && (p[i][j] != -1))
        {
            cout << p[i][j] + 1 << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}
