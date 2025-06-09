#include<bits/stdc++.h>
using namespace std;
int print1toN(int start,int end){
    if(start==end){
        cout << start << "\n";
        return 0;
    }
    cout << start << " ";
    return print1toN(start-1,end);
}

int main(){
    int s,e;
    cin >> s >> e;

    print1toN(s,e);
}