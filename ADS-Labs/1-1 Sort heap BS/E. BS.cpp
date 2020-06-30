#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[100000];
int low_bound(int x, int n)
{
    int L = -1;
    int R = n;
    while (R - L > 1)
    {
        int M = L + (R - L)/2;
        if (a[M] <= x)
            L = M;
        else
            R = M;
    }
    return L;
}
int up_bound(int x, int n)
{
    int L = -1;
    int R = n;
    while (R - L > 1)
    {
        int M = L + (R - L)/2;
        if (a[M] < x)
            L = M;
        else
            R = M;
    }
    return L;

}


void merge(int a[], int b, int e)
{
    int i = b;
    int mid = b + (e - b) / 2;
    int j = mid + 1;
    int k = 0;
    int *d;
    d = new int[e - b + 1];
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            d[k] = a[i];
            i++;
        }
        else
        {
            d[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        d[k] = a[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        d[k] = a[j];
        j++;
        k++;
    }
    for (int i = 0; i < k; i++)
        a[b + i] = d[i];
}

void mergesort(int *a, int l, int r)
{
    if (l < r)
        if (r - l == 1)
        {
            if (a[l] > a[r])
                swap(a[l], a[r]);
        }
        else
        {
            mergesort(a, l, l + (r - l) / 2);
            mergesort(a, l + (r - l) / 2 + 1, r);
            merge(a, l, r);
        }
}

int main()
{
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n - 1);
    int k;
    int l, r;
    cin >> k;
    for (long long i = 0; i < k; i++)
    {
        cin >> l >> r;
        cout << low_bound(r, n) - up_bound(l, n)<< ' ';
    }
}
