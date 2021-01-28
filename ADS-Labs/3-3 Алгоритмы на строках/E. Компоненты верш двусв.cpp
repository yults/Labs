#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length() + 1;
    vector<int> p(n);
    p[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while(true)
        {
            if (j == -1 || s[j] == s[i - 1])
            {
                p[i] = j + 1;
                break;
            }
            j = p[j];
        }
    }
    n--;
    if (n % (n - p[n])) cout << n;
    else cout << n - p[n];
    return 0;
}
