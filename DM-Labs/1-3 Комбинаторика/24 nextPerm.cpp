#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;
int n;
vector <int> a, b;
int flag_prev = 0;
int flag_next = 0;
void prev_perm() 
{
	int max_i;
	for (int i = n - 2; i >= 0; i--) 
	{
		max_i = i + 1;
		if (a[i] > a[i + 1]) 
		{
			flag_prev = 1;
			for (int j = i + 1; j < n; j++)
				if (a[j] > a[max_i] && a[j] < a[i])
					max_i = j;
			swap(a[i], a[max_i]);
			reverse(a.begin() + i + 1, a.begin() + n);
			return;
		}
	}
}
void next_perm() 
{
	int min_i;
	for (int i = n - 2; i >= 0; i--) 
	{
		if (b[i] < b[i + 1]) 
		{
		    min_i = i + 1;
			flag_next = 1;
			for (int j = i + 1; j < n; j++)
				if (b[j] < b[min_i] && b[j] > b[i])
					min_i = j;
			swap(b[i], b[min_i]);
			reverse(b.begin() + i + 1, b.begin() + n);
			return;
		}
	}
}



int main() {
	ifstream cin("nextperm.in");
	ofstream cout("nextperm.out");
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0 ; i < n; i++) 
	{
		cin >> a[i];
		b[i] = a[i];
	}

	next_perm();
	prev_perm();

	if (flag_prev == 0) 
	{
		for (int i = 0; i < n; i++) 
			cout << 0 << ' ';
		cout << endl;
	}
	else
	{
		for (int i = 0; i < a.size(); i++) 
			cout << a[i] << " ";
		cout << endl;
	}
	if (flag_next == 0) 
	{
		for (int i = 0; i < n; i++) 
			cout << 0 << ' ';
	}
	else
	{
		for (int i = 0; i < b.size(); i++) 
			cout << b[i] << " ";
	}
}
