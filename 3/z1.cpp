#include <iostream>
#include <vector>
using namespace std;

//binary search

bool nadji_rekurzivno(vector<int> &v, int element, int odIndeksa, int doIndeksa){

        auto m = (odIndeksa + doIndeksa) / 2;
        // odIndeksa = 0, doIndeksa = 5, m = 2 lijeov 0 i 1, desno 3, 4, 5
        // odIndeksa = 0, doIndeksa = 4, m = 2, lijevo 0 i 1, desno 3 i 4

        cout<< "Od indeksa: "<< odIndeksa << ", do indeksa: "<< doIndeksa <<endl;


        if (v[m] == element){
            return true;
        }

        if(v[m] > element) { // idemo lijevo
            if(m > odIndeksa)
                return nadji_rekurzivno(v, element, odIndeksa, m - 1);
        }
        else { // v[m] < elem
            if(m < doIndeksa)
                return nadji_rekurzivno(v,element,m+1,doIndeksa);
        }

        return false;
}


bool nadji(vector<int> &v, int element){ // fj za provjeruu pronalaska elementa u vectoru

        return nadji_rekurzivno(v,element,0, v.size()-1);

}



int main(){
    vector<int> v{1,5,8,10,25,33,46,65,89};

    cout<<nadji(v,46);



    return 0;
}


// moguce varijacije
// da se vrati broj indeksa
// da se vrati ime prezime u vektoru stringova
