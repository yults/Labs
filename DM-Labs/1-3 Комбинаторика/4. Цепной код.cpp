#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;
int n;
vector<int> a(n, 0);
vector<bool> use(pow(2, n), false);
vector<int> siz(n);
int i = 0;
int cur = 1;
vector<int> ans;

void func(int p)
{
    use[0] = true;
    if (p == 1) {i++;}
    cur = p;
        for (int j = 1; j < n; j++)
            cur += a[n-j] * siz[j];
        if (!use[cur])
        {

            for (int k = 1; k < n; k++)
            {
                ans.push_back(a[k]);
                a[k-1] = a[k];
            }
            a[n-1] = p;
            if (p == 0) ans.push_back(0); else ans.push_back(1);
            use[cur] = true;
        }
        else func(0);
        if (i == pow(2, n) - 1) return;
        func(1);
}

int main()
{
    ifstream cin ("chaincode.in");
    ofstream cout("chaincode.out");
    cin >> n;
    a.resize(n, 0);
    use.resize(pow(2, n), false);
    siz.resize(n);
    for (int i = 1; i < n; i++)
        siz[i] = pow(2, i);
    int cur;
    for (int i = 0; i < n; i++)
        cout << "0";
    cout << endl;
    func(1);
    for(int i = 0; i < pow(2, n) - 1; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i * n + j];
        cout << endl;
    }
}
