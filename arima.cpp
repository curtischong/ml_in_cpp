#include <bits/stdc++.h>
#define VI vector<int>
#define US (unsigned)
using namespace std;
//https://medium.com/skyshidigital/arima-price-forecasting-by-using-parseltongue-uhmm-i-mean-python-6a40b36c6565
//"Month","International airline passengers: monthly totals in thousands. Jan 49 ? Dec 60"
int main(){
  ifstream infile("datasets/international-airline-passengers.csv");
  string a;
  infile>>a; // ignore first row
  while (infile >> a){
    int year = atoi(a.substr(1,5).c_str());
    int month = atoi(a.substr(6,8).c_str());
    int passengers = atoi(a.substr(10,13).c_str());
    cout<<passengers<<endl;
  }
}
