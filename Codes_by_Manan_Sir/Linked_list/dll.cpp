#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

struct DLLNode
{
    int data;
    DLLNode *next, *prev;
    DLLNode()
    {
        this->data = '\0';
        this->next = this->prev = nullptr;
    }
    DLLNode(int data)
    {
        this->data = data;
        this->next = this->prev = nullptr;
    }
    DLLNode(int data, DLLNode *next, DLLNode *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class DLL
{
    //
};

void solve()
{
    // code here
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