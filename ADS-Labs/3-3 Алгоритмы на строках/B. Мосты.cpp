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
    for (int i = 0; i < n - 1; i++) {
        int j = p[i];
        while(true)
        {
            if (j == -1 || s[j] == s[i])
            {
                p[i + 1] = j + 1;
                break;
            }
            j = p[j];
        }
        cout << p[i + 1] << ' ';
    }
    return 0;
}
