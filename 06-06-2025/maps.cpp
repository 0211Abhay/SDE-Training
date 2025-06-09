#include<bits/stdc++.h>
using namespace std;
void populate_map(map<int,int> &m){
    m[1] = 2;
    m[0] = 1;
}

void print_map(map<int,int> &m){
    map<int,int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++){
        //itr->first  same as (*itr).second;        
        cout << itr->first << ":" << itr->second << "\n";
    }


    cout << "Way 2" << "\n";

    for(pair<int,int> p : m){
        cout << p.first << ":" << p.second << "\n";
    }


    // cout << "Way 3" << "\n";

    // for(auto [key,value]  : m){
    //     cout << key << ":" << value << "\n";
    // }
}
int main(){
    map<int,int> m;
    populate_map(m);
    print_map(m);
}