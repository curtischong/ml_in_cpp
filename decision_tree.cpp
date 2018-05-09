/*
  Things I need to do:

  constraints:
 - The first value of the masterArray always represents the  classes

*/

#include <bits/stdc++.h>
#define VI vector<int>
#define US (unsigned)
using namespace std;


double calc_gini(VI arr){
  int totSum = 0;
  int topSum = 0;
  for(int i = 0;US i<arr.size();i++){
    totSum +=arr[i];
  }

  for(int i = 0;US i<arr.size();i++){
    topSum += (2*i - arr.size() - 1)*arr[i];
  }
  return topSum/(arr.size() * totSum);
}

vector<VI> masterArray = {
  {0,0,1,1,0,1,1,1},
  {4,8,12,16,1,4,9,16},
  {1,4,9,16,4,8,12,3},
};
int main(){



}
