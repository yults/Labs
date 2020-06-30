#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("bwt.in");
    ofstream cout("bwt.out");
    string s1;
    cin >> s1;
    vector<string> a;
    a.push_back(s1);
    for (int i = 1; i < s1.length(); i++)
    {
        string s = s1;
        char temp;
        for (int j = 0; j < i; j++)
            {
            temp = s[s.length() - 1];
            for (int j = s.length(); j >= 1; j--)
                s[j] = s[j - 1];
            s[0] = temp;
            }
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        cout << a[i][s1.length() - 1];
    return 0;
}
