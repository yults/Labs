#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
