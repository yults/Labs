#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
int n;
vector<char> a;

bool next_sp(){
    int close = 0;
    int open = 0;
    for (int i = a.size() - 1; i > -1; i--)
	{
        if (a[i] == '(')
		{
                open++;
                if (close > open) break;
        } else close++;
    }
    for (int i = n * 2 -1 - open - close; i < n * 2 - 1; i++)
        a.pop_back();
    if (a.size() == 0)
        return false;
    	else
	    {
        a.push_back(')');
        close--;
        for (int j = 0; j < open; j++)
            a.push_back('(');
        for (int j = 0; j < close; j++){
            a.push_back(')');
        }
    }
    return true;
}


int main()
{
    ifstream cin ("brackets.in");
    ofstream cout ("brackets.out");
    cin >> n;
    a.resize(n * 2);
    for (int i = 0; i < n * 2; i++) if (i < n) a[i] = '('; else  a[i] = ')';
    do
	{
        for (int i = 0; i < n * 2; i++)
            cout << a[i];
        cout << endl;
    } while (next_sp());
}
