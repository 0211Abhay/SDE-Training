#include<iostream>
using namespace std;
bool isPalindrome(int n) {
        int m=0;
        int x=n;
        while(x>0){
            int temp=x%10;
            m=m*10+temp;
            x=x/10;
        }
        if(n==m) return true;
        else return false;
    }
int main(){
    int n;
    cin >> n;
    cout<<isPalindrome(n);
}