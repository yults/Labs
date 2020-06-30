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

bool isEmpty()
{
    return a.empty();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char x;
    long long ans = 0;
    while (cin >> x)
    {
        if (x >= '0' && x <= '9') push(x - '0');
        else
        {
                long long meow1 = top();
                pop();
                long long meow2 = top();
                pop();
                if (x == '+') ans = meow1 + meow2;
                if (x == '-') ans = - meow1 + meow2;
                if (x == '*') ans = meow1 * meow2;
                push(ans);
        }
    }
    cout << ans;
    return 0;
}
