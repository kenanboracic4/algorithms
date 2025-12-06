#include <iostream>
#include <vector>

//selekcija
// odabir k-tog najveceg elementa
using namespace std;
// k = 0 prvi element
// k= 1 drugi element

int selekcija_rek(vector<int> &v, int k){


    if(v.size() == 1){
            return v[0];
    }

    
    auto srednji = v.size() / 2;


    auto pivot = v[srednji];

    for(int i=0;i<v.size();i++){
        if(i != srednji){
            auto x = v[i];
            if(x<pivot ){
                lijevi.push_back(x);
            }else{
                desni.push_back(x);
            }
        }
    }

    
   if(lijevi.size() > k){
        return selekcija_rek(lijevi,k);
   }
    else if(lijevi.size() == k){
        return pivot;
    }
   else{
        return selekcija_rek(desni,k - lijevi.size()-1);
   }

}

int selekcija(vector<int> &v, int k){
    if(k >= v.size()){
        throw invalid_argument("k je vece od velicine vektora! ");
    }
    return selekcija_rek(v,k);
}


int main(){
    vector<int> v{10,30,50,20,40,60};

    cout<<selekcija(v,2);

    return 0;
}