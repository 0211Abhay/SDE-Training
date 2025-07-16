#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

class Stack
{
public:
    int _top;
    int size, capacity;
    vi v;
    // int a[3];
    Stack()
    {
        _top = -1;
        size = 0;
        capacity = 3;
        // v.reserve(capacity);
        forn(i, capacity)
        {
            v.push_back('\0');
        }
    }
    int top()
    {
        if (size < 1)
        {
            cout << "invalid command. nothing to top\n";
            return '\0';
        }
        return v[_top];
    }
    void pop()
    {
        if (size < 1)
        {
            cout << "Nothing to pop\n";
            return;
        }
        size--;
        v[_top--] = '\0';
    }
    void push(int val)
    {
        if (size == capacity)
        {
            cout << "Overflow\n";
            return;
        }
        size++;
        v[++_top] = val;
    }
    bool empty()
    {
        return (size == 0);
    }
};

void print_Stack(Stack s)
{
    while (!s.empty())
    {
        cout << (s.top()) << "\t";
        s.pop();
    }
    cout << "\n";
}

void solve()
{
    Stack s;
    // cout << s.capacity << "\t" << s._top << "\t" << s.size << "\t";
    // cout << s.v.size() << "\n";
    s.push(1);
    s.push(2);
    print_Stack(s); // 2 1
    s.push(3);
    s.push(4); // Overflow
    s.pop();
    s.pop();
    cout << (s.top()) << "\n"; // 1
    s.pop();
    s.pop();                   // Underflow
    cout << s.empty() << "\n"; // 1
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}