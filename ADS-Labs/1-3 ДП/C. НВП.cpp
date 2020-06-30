#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n);
    vector<long long> prev(n, -1);
    for (int i = 0; i < n; i++)
       {
           cin >> a[i];
            d[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i])
                {
                    if (d[j] + 1 > d[i])
                    {    
						d[i] = d[j] + 1;
                        prev[i] = j;
                    }
                }
            }
       }
    int k = max_element(d.begin(), d.end()) - d.begin();
    vector<long long> ans;
    cout << d[k] << endl;
    while (k != -1)
    {
      ans.push_back(a[k]);
      k = prev[k];
    }
    for (int i = ans.size() - 1; i > -1; i--)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
