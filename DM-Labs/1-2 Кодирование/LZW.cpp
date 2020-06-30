#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("lzw.in");
    ofstream cout("lzw.out");
    map<string, int> dic;
    int meow = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        string hru;
        hru += i;
        dic[hru] = meow++;
    }
    string gav;
    string krya;
    cin >> krya;
    for(int i = 0; i < krya.length(); i++)
    {
        string kok = gav;
        kok += krya[i];
        if (dic.count(kok))
            {
            gav += krya[i];
            }
            else
                {
                    cout << dic[gav] << " ";
                    dic[kok] = meow++;
                    gav = " ";
                    gav[0] = krya[i];
                }
    }
    cout << dic[gav];
}
