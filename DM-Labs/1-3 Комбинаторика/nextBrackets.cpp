#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
 
using namespace std;

int n;
string s;

bool next_sp()
{
    int open = 0, close = 0;
    for (int i = s.length() - 1; i > -1; i--)
	{
        if (s[i] == '(')
		{
  		    open++;
            if (close > open) break;
        } else 
            close++;
    }
    for (int i = n * 2 - 1 - (open + close); i < n * 2 - 1; i++)
        s.resize(s.length() - 1);
    if (s.length() == 0)
	{
        return false;
    } else 
	{
        s += ')';
        for (int j = 0; j < open; j++)
		{
            s += '(';
        }
        for (int j = 0; j < close - 1; j++)
		{
            s +=')';
        }
    }
    return true;
}

 
int main()
{
    ifstream cin("nextbrackets.in");
    ofstream cout("nextbrackets.out");
    cin >> s;
    if (next_sp())
	{
    for (int i = 0; i < s.length(); i++)
        cout << s[i];
    cout << endl;
	}
	else
        cout << "-";
}

