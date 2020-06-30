#include <iostream>
#include <algorithm>
using namespace std;

int heap[1000000];
int n = 0;

int extract()
{
    return heap[0];
}
void add(int x)
{
    heap[n] = x;
    n++;
    int i = n - 1;
    while(i > 0 && heap[i] > heap[(i - 1)/2])
    {
        swap(heap[i], heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}
void remove_max()
{
    swap(heap[n - 1], heap[0]);
    n--;
    int i = 0;
    while(true)
    {
        int j = i;
        if (heap[j] < heap[2*i + 1] && 2 * i + 1 < n)
            j = 2 * i + 1;
        if (heap[j] < heap[2*i + 2] && 2 * i + 2 < n)
            j = 2 * i + 2;
        swap(heap[i], heap[j]);
        if (i == j)
            break;
        i = j;
    }
}
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int whtd;
        cin >> whtd;
        if (whtd == 0)
        {
            int newel;
            cin >> newel;
            add(newel);
        }
        else
        {
            cout << extract() << endl;
            remove_max();
        }
    }
}

