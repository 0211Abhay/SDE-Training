#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

#define forn(i, n) for (int i = 0; i < n; i++)
#define pb push_back

int count_square_sum(int n){
    int temp = n;
    int ans =0;

    while(temp){
        ans += (temp %10) * (temp%10);
        temp/=10;
    }
    return ans;
}
bool isHappy(int n) {
        int temp = n;
        int ans = 0;
        int count = 10;
        
        while(count-- && temp){
            int ans = count_square_sum(temp);
            cout << temp << " " << ans << " " << count << endl;
            if(ans == 1){
                return true;
            }
            temp = ans;
            
        }
        return false;

    }
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

void solve()
{
    // vi v = input_vector();
    int n; 
    cin >>n;
    bool ans = isHappy(n);
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