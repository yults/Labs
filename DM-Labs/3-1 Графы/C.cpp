#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ar;
string str;
bool flag = true;

bool cmp (int a, int b)
{
    cout << "1 " << a <<  ' ' << b << endl;
    cout.flush();
    cin >> str;
    return (str == "YES");
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        ar.push_back(i);
    stable_sort(ar.begin(), ar.end(), cmp);
    cout << 0 << ' ';
    if (flag) for (int i = 0; i < n; i++) cout << ar[i] << ' ';
    else for (int i = 0; i < n; i++) cout << '0 ';
}

