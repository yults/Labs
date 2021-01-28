#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length(), m;
    cin >> m;
    vector<int> p(n + 1), h(n + 1);
    p[0] = 1; h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i] * 11;
        h[i + 1] = h[i] * 11 + s[i];
    }
    for (int i = 0; i < m; i++)
    {
        int lf, rf, ls, rs;
        cin >> lf >> rf >> ls >> rs;
        lf--; ls--;
        if (h[rf] - h[lf] * p[rf - lf] == h[rs] - h[ls] * p[rs - ls]) cout << "Yes" << endl;
            else cout << "No" << endl;
    }
    return 0;
}
