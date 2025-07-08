// #include <bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

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

int a = 1;

void fun2(int &a) {
    cout<<a++<<"\n";
}

void fun1(int &a) {
    // int a=2;
    cout<<a++<<"\n";
    fun2(a);
}

void solve()
{
    // int a=1;
    cout<<a++<<'\n';
    fun1(a);
    cout<<a<<"\n";
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