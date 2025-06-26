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
void CountNoOf1s(){
    int n ;
    cin >> n;
    if(n<0){
       n =  ~n;
       n+=1; 
    }
    int count = 0;
    while(n!=0){
        if( (n & 1) == 1 ){
            count ++;
        }
        n = n>>1;
    }
    cout << count;
}
void TrackLeading1(){
    int n ;
    cin >> n;
    if(n<0){
        cout << 32;
        return;
    }
    int count = 0;
    while(n!=0){
  
            count ++;
        
        n = n>>1;
    }
    cout << count;
}
void count_set_bits(){
    int n;
    cin >> n;
    int count = 0;
    while(n!=0){
        //cout << n << "\n";
        n = n & (n-1);

        count ++;
    }
    cout << count;    
}

void TrackLeading1sO1(){
    int n;
    cin >> n;
    cout << floor(log2(n))+1;
}
void solve()
{   
    cout << floor(log2(43));
    
    TrackLeading1sO1();   
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