#include <iostream>
#include <vector>
using namespace std;



void bucketSort_aco(vector<int> &v){

    vector<int> brojac(10,0);

    for (auto x : v){
        brojac[x] ++;
    }

    int index = 0;
    for(int i = 0; i<brojac.size(); i++){
        for(int j = 0;j < brojac[i]; j++){
  
            v[index++] = i;
        
        }
     
    }
}


int main(){
    vector<int> v{1,3,2,6,6,2,4,8,1,2};

    bucketSort_aco(v);

    for(int x : v){
        cout << x << " ";
    }

    return 0;
}
