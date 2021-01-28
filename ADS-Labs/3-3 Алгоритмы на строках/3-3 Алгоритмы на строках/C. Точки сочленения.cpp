#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length(), l = 0, r = 1;
    vector<int> zf(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (i <= r) zf[i] = min(zf[i - l], r - i);
        while (s[zf[i]] == s[zf[i] + i]) zf[i]++;
        if (i + zf[i] > r) {
            l = i;
            r = zf[i] + i;
        }
        cout << zf[i] << ' ';
    }
    return 0;
}
