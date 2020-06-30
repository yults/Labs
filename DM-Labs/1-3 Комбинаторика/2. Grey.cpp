#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int n;
vector<string> grayCode(2);

void buildCode(int n)
{
   	grayCode[0] = "0";
   	grayCode[1] = "1";    
   	int p = 2;
   	for (int i = 1; i < n; i++)
	{
	  	int t = p;
      	p = p * 2;
      	grayCode.resize(p);
      	for (int k = t; k < p; k++)
    	{
        	grayCode[k] = grayCode[t - 1];    
         	grayCode[t - 1] = "0" + grayCode[t - 1];
         	grayCode[k] = "1" + grayCode[k];   
         	t--;
		}
    }
}
int main()
{
	ifstream cin("gray.in");
	ofstream cout("gray.out");
	cin >> n;
	buildCode(n);
	for (int i = 0; i < (1 << n); i++) 
	{
		cout << grayCode[i] << endl;
	}
	return 0;
}


