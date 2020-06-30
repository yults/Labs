#include <iostream>
#include <vector>
using namespace std;

int main()
{
 int n;
 cin >> n;
 vector<int> a(n);
for (int i = 0; i < n; i++)
    cin >> a[i];
 int buff = 0;
 int i, j;
 for (i = 1; i < n; i++)
 {
 buff = a[i];
 for (j = i - 1; j >= 0 && a[j] > buff; j--)
 a[j + 1] = a[j];
 a[j + 1] = buff;
 }
 for (int i = 0; i < n; i++)
 cout << a[i] << ' ';
}
