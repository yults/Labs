#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> c(n);
    vector<int> pred(n, -1);
    for (int i = 1; i < n - 1; i++)
    {
        cin >> c[i];
    }
    vector<int> F(n, -1e9);
    F[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < k + 1 && i + j < n; j++)
        {
            if (F[i] + c[i + j] > F[i + j])
            {
                F[i + j] = F[i] + c[j + i];
                pred[i + j] = i;
            }
        }
    }
    k = n - 1;
    vector<int> ans;
    while (k != -1)
    {
      ans.push_back(k + 1);
      k = pred[k];
    }
    cout << F[n - 1] << endl << ans.size() - 1 << endl;
    for (int i = ans.size() - 1; i > -1; i--)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
