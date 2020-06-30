#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <long long> a;
void pop()
{
  a.pop_back();
}

void begin_pop()
{
  a.erase(a.begin() + 0);
}

//a.insert(a.begin() + ..)
void push(long long x)
{
  a.push_back(x);
}

long long top()
{
    return a.back();
}

long long head()
{
    return a[0];
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
        switch(x)
        {
            case 1:
            {
                int y;
                cin >> y;
                push(y);
                break;
            }
            case 2:
            {
                begin_pop();
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            case 4:
            {
                int y;
                cin >> y;
                for (int i = 0; i < a.size(); i++)
                    if (a[i] == y) cout << i << endl;
                    break;
            }
            case 5:
            {
                cout << head() << endl;
                break;
            }
        }
    }
    return 0;
}
