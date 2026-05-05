#include <bits/stdc++.h>
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
int recursive(vi &vi, int n){
    if(n<2){
        return 0;
    }
    int onestep = recursive(vi, n-1) + abs(vi[n] - vi[n-1]);
    int twostep = INT_MAX;
    if(n>1)
    {
        twostep = recursive(vi, n-2) + abs(vi[n] - vi[n-2]);
    }
    return  min(onestep,twostep);
}
int memoize(vi &v, int n,vi &memo){
    if(n==0){
        return 0;
    }
    if(memo[n]!= -1 ){
        return memo[n];
    }
    int onestep = memoize(v, n-1,memo) + abs(v[n] - v[n-1]);
    int twostep = INT_MAX;
    if(n>1)
    {
        twostep = memoize(v, n-2,memo) + abs(v[n] - v[n-2]);
    }
    return  memo[n] = min(onestep,twostep);
}
void solve()
{
    // code here
    vi nrgList = input_vector();
    
    int n = nrgList.size();
    vi memo(n,-1);
    // int ans = recursive(nrgList,n-1);
    int ans = memoize(nrgList, n-1 , memo);
    cout << ans;
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