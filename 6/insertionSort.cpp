#include<iostream>
#include <vector>

using namespace std;


void insertionSort(vector<int> &v){

    for(int i= 1; i < v.size(); i++){

        int trenutni = v[i];
        int j = i -1;

        while(j >= 0 && v[j] > trenutni ){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = trenutni;
        
    }

}

int main(){


    vector<int> v{10,50,30,20,60,40};

    insertionSort(v);

    for(auto x:v){
        cout<<x<<" ";
    }

    return 0;
}