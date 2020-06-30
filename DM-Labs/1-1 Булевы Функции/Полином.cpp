#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    int neww = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        neww = neww * 2;
    n = neww;

    vector<pair<string,int>> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second = y;
        b[i] = y;
    }
    int k = n;
    int cnt = 1;
    while(k > 0)
    {
        for(int i = 0; i < k - 1; i++)
        {
            if (b[i + 1] == 0 && b[i] == 1 || b[i + 1] == 1 && b[i] == 0) b[i] = 1;
            else b[i] = 0;
            if (i == 0) a[cnt].second = b[i];
        }
        k--;
        cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << ' ' << a[i].second << endl;
    }
    return 0;
}
