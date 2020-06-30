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
    int n;
    cin >> n;
    vector<int> meow(n);
    vector<int> s_meow;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> meow[i];
        while (!isEmpty() && top() < meow[i])
            {
                s_meow.push_back(top());
                pop();
                ans.push_back("pop");
            }
        push(meow[i]);
        ans.push_back("push");
    }
    while (!isEmpty())
    {
        s_meow.push_back(top());
        pop();
        ans.push_back("pop");
    }
    for(int i = 1; i < n; i++)
    {
        if (s_meow[i - 1] > s_meow[i])
            {
                cout << "impossible";
                return 0;
            }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
