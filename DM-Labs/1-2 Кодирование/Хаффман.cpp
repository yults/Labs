#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
using namespace std;
int main()
{
    ifstream cin("huffman.in");
    ofstream cout("huffman.out");
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n + 1; i++)
    {
        b[i]= 3e18;
    }
    long long ans = 0;
    int i = 0, j = 0;
    for (int k = 0; k < n - 1; k++)
    {
        if (a[i] + a[i + 1] <= a[i] + b[j] && a[i] + a[i + 1] <= b[j] + b[j + 1])
        {
            b[k] = a[i] + a[i + 1];
            ans += b[k];
            i += 2;
        }
        else if (a[i] + b[j] <= a[i] + a[i + 1] && a[i] + b[j] <= b[j] + b[j + 1])
        {
            b[k] = a[i] + b[j];
            ans += b[k];
            i++;
            j++;
        }
        else if (b[j] + b[j + 1] <= a[i] + a[i + 1] && b[j] + b[j + 1] <= a[i] + b[j])
        {
            b[k] = b[j] + b[j + 1];
            ans += b[k];
            j += 2;
        }
    }
    cout << ans;
}
