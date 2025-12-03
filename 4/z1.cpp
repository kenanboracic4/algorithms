#include <iostream>
#include <vector>

using namespace std;
// proizvod brojeva u nizu tehnikom podijeli pa vladaj

int broj_ulazaka = 0; // varijabla koja broji broj ulaza u rekurzivnu fj

template <typename T>
T pomnoziRekurzivno(vector<T> &v, int pocetak, int kraj){

    broj_ulazaka++;

    T rezultat;

    if(pocetak == kraj){ // provjera da li vektor ima 1 element
        return v[pocetak];
    } else if(pocetak + 1 == kraj){ // provjera da li vektor ima 2 elementa
        return v[pocetak] * v[kraj];
    }else if(pocetak + 2  == kraj){ // provjera da li vektor ima 3 elementa
        return v[pocetak] * v[pocetak + 1] * v[kraj];
    }


    auto sredina = (pocetak+kraj)/2;

    // moglo je i
    // auto lijevi = pomnoziRekurzivno(v,pocetak,sredina)
    // auto desni = pomnoziRekurzivno(v,sredina+1,kraj)
    //return lijevi * desni
    return pomnoziRekurzivno(v,pocetak,sredina) * pomnoziRekurzivno(v,sredina+1,kraj);

}


template <typename T>
T pomnozi(vector<T> &v){

    if(v.size() == 0){
        return (T)0;
    }



    return pomnoziRekurzivno(v,0,v.size()-1);

}

// slozenost
// T(n) = 2T(n/2) + 1
// master teorem
// a = 2, b = 2, f(n) = 1
// 1° slucaj -> f(n) = O(n^1-Epsilon) => T(n) = Teta(n)


//slucaj za binarnu pretragu
// T(n) = T(n/2) + 1
// log n

int main(){

vector<int> v;//{1,2,3,4,5,6,7,8,9,10};

for(int i = 0; i<=20;i++)
    v.push_back(1);


cout<<pomnozi(v)<<endl;
cout<<"Broj ulazaka u rekurzivnu funkciju "<< broj_ulazaka <<endl;



return 0;
}
