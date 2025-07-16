#include<bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
        if(n==0 || n==1 ) return 0;

        vector<int> prime(n+1,1);
        prime[0]=0;  prime[1]=0; 

        for(int i=2;i*i<=n;i++){
            if(prime[i] == 1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }

        int ans=0;
        for(int i=2;i<n;i++){
            if( prime[i] == 1 ) ans++;
        }
        return ans;
    }
    int main(){
        int n;
        cin >> n;

        int ans = countPrimes(n);

        cout << ans;
    }