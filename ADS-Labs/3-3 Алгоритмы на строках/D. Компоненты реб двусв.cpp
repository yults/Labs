#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string sp, t;
    cin >> sp >> t;
    string pt = sp + '#' + t;
    int n = pt.length() + 1;
    vector<int> p(n), a;
    p[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while(true)
        {
            if (j == -1 || pt[j] == pt[i - 1])
            {
                p[i] = j + 1;
                break;
            }
            j = p[j];
        }
        if (p[i] == sp.length()) a.push_back((int)(i - 2 * sp.length()));
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    return 0;
}
