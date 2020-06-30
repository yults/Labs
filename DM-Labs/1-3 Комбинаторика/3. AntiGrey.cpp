#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int n;
int blocksiz = 0;
vector<string> ans;
void genObj(int i, string s)
{
    if(s.length() < n)
    {
		if (i == n)
	    {
	        ans.push_back(s);
	        return;
	    }
	    genObj(i + 1, s + "0");
	    genObj(i + 1, s + "1");
	    genObj(i + 1, s + "2");
	    cout << "LOL" << s << endl;
   }	
   else 
   {
   if (blocksiz < pow(3, n - 1))
           {
  
  		   ans.push_back(s);
            blocksiz++;
            string s1 = "";
            for (int i = 0; i < s.length(); i++)
                s1 += (char)(((int)s[i] + 1) % 3);
				ans.push_back(s);
            for (int i = 0; i < s.length(); i++)
                s1 = (char)(((int)s[i] + 2) % 3);
                ans.push_back(s1);
                cout << "BAN" << s << ' ' << s1 << endl;
   	
   }
}
}


int main()
{
   //ifstream cin("antigray.in");
   //ofstream cout("antigray.out");
    cin >> n;
    string s = "";
    genObj(0, s);
    for (int i = 0; i < ans.size()/n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i * n + j];
        }
        cout << endl;
    }
}
