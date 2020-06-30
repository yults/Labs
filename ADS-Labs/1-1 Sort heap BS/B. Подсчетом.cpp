#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int k = 101;
    vector<int> ap(k);
    string str;
    getline(cin, str);
    int num = 0;
    for (int i = 0; i < k; i++)
        ap[i] = 0;
    for (int i = 0; i < str.length() + 1; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int digit = str[i] - '0';
            num = num * 10 + digit;
        }
        else
        {
            ap[num]++;
            num = 0;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (ap[i] > 0)
            for (int j = 0; j < ap[i]; j++)
                cout << i << ' ';
    }
    return 0;
}
