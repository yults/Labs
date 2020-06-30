#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("mtf.in");
    ofstream cout("mtf.out");
    string s;
    cin >> s;
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    string snew = "";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s1.find(s[i]) + 1 << " ";
        snew += s[i];
        for(int j = 0; j < s1.find(s[i]); j++)
            snew += s1[j];
        for(int j = s1.find(s[i]) + 1; j < s1.length(); j++)
            snew += s1[j];
        s1 = snew;
        snew = "";
    }
    return 0;
}
