#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int> > a;
void pop()
{
  a.pop_back();
}

void push(int x, int y)
{
  a.push_back({x, y});
}

pair<int,int> top()
{
    return a.back();
}

bool isEmpty()
{
    return a.empty();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
        cin >> x;
        if (isEmpty())
            push(x, x);
        else
            push(x, min(x, top().second));
        }
        else if (x == 2) pop();
        else cout  << top().second << endl;
    }
    return 0;
}
