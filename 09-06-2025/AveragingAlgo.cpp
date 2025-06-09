#include<bits/stdc++.h>
using namespace std;

double get_deviation(int n, double root){
    double est = root*root;
    double diff = abs(n-est);
    double perc_diff = diff / n* 100;
    return perc_diff;
}
double helper(int n, double guess){
    
    while(get_deviation(n,guess)>= 0.000001){
 
    double div = n / guess;
       cout << guess << "\t" << div << "\n";
    double avg = (guess + div )/ 2.0;
    guess = avg;
    }
    return guess;
}
double my_sqrt(int n){
    int guess = 69;
    return helper(n,guess);
}

int main(){
   double sqrt =  my_sqrt(898989);
   cout << sqrt;
}