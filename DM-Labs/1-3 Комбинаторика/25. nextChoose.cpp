#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

int n, k;
vector<int> a, b;

int next_choose() 
{
	for (int i = 0; i < k; i++)
		b[i] = a[i];
	b[k] = n + 1;
	int i = k - 1;
	while (i >= 0 && b[i + 1] - b[i] < 2)
		i--;
	if (i >= 0) 
	{
		b[i]++;
		for (int j = i + 1; j < k; j++)
			b[j] = b[j - 1] + 1;
		for (int z = 0; z < k; z++)
			a[z] = b[z];
		return 1;
	} else
		return -1;
}

int main() 
{
	ifstream cin("nextchoose.in");
	ofstream cout("nextchoose.out");
	cin >> n >> k;
	a.resize(k);
	b.resize(k + 1);
	for (int i = 0 ; i < k; i++) 
		cin >> a[i];

	int x = next_choose();

	if (x == -1) {
		cout << - 1;
		return 0;
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
}
