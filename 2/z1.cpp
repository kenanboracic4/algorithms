#include <iostream>
#include <vector>


using namespace std;

template<typename T>
T lokMax(vector<T> &v){
    if(v.size()< 3){
        throw invalid_argument("Velicina niza je manja od 3!!");

    }
    for(int i=1;i<v.size()-1;i++){
        if(v[i]> v[i-1] && v[i] > v[i+1]){
            return v[i];
        }
    }
    throw invalid_argument("Nema lokalnog maksimuma! ");

}
template<typename T>
bool lokMaxOdDo(vector<T> &v, int pocetak, int kraj, T& maksimum){
        cout<<"Pregledam od "<<pocetak<<" do "<<kraj<<endl;

     if(kraj-pocetak+1<3){
            return false;
    }
    if(kraj-pocetak+1 == 3){
        if(v[pocetak+1] > v[pocetak] && v[pocetak+1] > v[kraj]){
            maksimum = v[pocetak+1];
            return true;
        }
        return false;
    }

    auto srednji = (pocetak + kraj)/2;
    auto nasao = lokMaxOdDo(v,pocetak,srednji,maksimum);
    if (nasao) {
        return true;
    }
     nasao = lokMaxOdDo(v,srednji+1,kraj,maksimum);
     if (nasao) {
        return true;
    }

    if(v[srednji] > v[srednji-1] && v[srednji] > v[srednji+1]){
        maksimum = v[srednji];
    }

    if(v[srednji+1] > v[srednji] && v[srednji+1]>v[srednji+2]){
        maksimum = v[srednji+1];
        return true;
    }
}

template<typename T>
T lokMax2(vector<T> &v){
    T lm;
    auto nasao = lokMaxOdDo(v,0,v.size()-1,lm);
    if(nasao){
        return lm;
    }
    throw invalid_argument("Nema lokalnih maksimuma!!");

}


int main(){
    vector<int> v {5,16,2,4,1,0,-1,5,2};

    cout<<lokMax2(v);
    return 0;
}
