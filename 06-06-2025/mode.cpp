#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> number_list(n);

    for(int i = 0; i<n;i++){
        cin >> number_list[i];
    }
    
    unordered_map<int,int> freq_map;

    for(int i=0; i<n;i++){
        freq_map[number_list[i]]++;
    }
    cout << "FreqList : " << "\n";
    for(pair<int,int> p : freq_map){
        cout << p.first << ":" << p.second << "\n";
    }

    vector<int> modeList;
    unordered_map<int,int>::iterator itr;
    int max = 0;
    for(itr = freq_map.begin();itr!=freq_map.end();itr++){
        if(itr->second < max){
            continue;
        }
        if(itr->second > max){
            max = itr->second;
            modeList.clear();
        } 
        modeList.push_back(itr->first);
    }


    cout << "ModeList : " << "\n";
    for(int i:modeList){
        cout << i << " ";
    }
}