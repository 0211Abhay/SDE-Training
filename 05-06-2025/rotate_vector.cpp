#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define forn(i,n) for(int i=0;i<n;i++)
vi input(){
    int n;
    cout << "Enter size of Vector" << "\n";
    cin >> n;
    vi vec(n);
    forn(i,vec.size()){
        cin>>vec[i];
    }
    return vec;
}
void print(vi &vec){
    cout << "Print : ";
    forn(i,vec.size()){
        cout  << vec[i] << "\t";
    }
}

void clockwise(vi &vec,int k){
    k%=vec.size();
    vi temp(k);
    for(int i=0;i<k;i++){
        temp[i] = vec[vec.size()-k+i];
    }
   
    for(int i=vec.size()-k;i>=0;i--){
        vec[vec.size()-k+i-1] = vec[i];
    }

    print(vec);
    print(temp);
    for(int i=0;i<k;i++){
        vec[i] = temp[i];
    }
}

int main(){
    vi vec = input();
    int k;
    cout << "Enter Value of k: \n";
    cin>>k;
    
    clockwise(vec,k);
    cout<<"rotate done";
    print(vec);
}