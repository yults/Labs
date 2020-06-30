#include <iostream>
#include <stdio.h>
using namespace std;
long long cnt = 0;

void merge(int a[], int b, int e)
{
    int i = b;
    int mid = b + (e - b) / 2;
    int j = mid + 1;
    int k = 0;
    int *d;
    d = new int[e - b + 1];
    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            d[k] = a[i];
            i++;
        }
        else {
            d[k] = a[j];
            j++;
            cnt += mid + 1 - i;
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
            {
                swap(a[l], a[r]);
                cnt++;
            }
    }
    else {
        mergesort(a, l, l + (r - l) / 2);
        mergesort(a, l + (r - l) / 2 + 1, r);
        merge(a, l, r);
    }
}
int main()
{
    int N;
    cin >> N;
    int *a;
    a = new int[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    mergesort(a, 0, N - 1);
    cout << cnt;
    return 0;
}
