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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (isEmpty()) push(x, 1);
        else if (top().first == x) push(x, top().second + 1);
        else
        {
            int k = top().second;
            if (k >= 3)
            {
                ans += k;
                for (int j = 0; j < k; j++)
                    pop();
            }
        if (top().first == x) push(x, top().second + 1);
        else push(x, 1);
        }
    }
    if (top().second >= 3)
            {
                int k = top().second;
                ans += k;
                for (int j = 0; j < k; j++)
                    pop();
            }
    cout << ans;
    return 0;
}
