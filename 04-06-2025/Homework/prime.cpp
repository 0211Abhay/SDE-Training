#include<iostream>
using namespace std;
bool isPrime(int n) {
        // code here
        if(n<2){
            return false;
        }
        if(n<4){
            return true;
        }
        if(n%2==0 || n%3==0){
            return false;
        }
        for(int i=5; i<=(n/i);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
        
    }
    int main(){
        int n;
        cin >> n;
        cout << isPrime(n);
    }