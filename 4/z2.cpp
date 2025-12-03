#include <iostream>
#include <vector>

using namespace std;

// ispitni zadatak lv 3 grupa a

int broj_a_s_rekurzivno (vector<int> &v,int pocetak,int kraj){

    if(kraj - pocetak < 2){
        return 0;
    }else if(kraj - pocetak == 2){

        if(2* v[pocetak+1]== v[pocetak] + v[kraj]){
            return 1;
        }
        return 0;
    }

    auto sredina = (pocetak + kraj) / 2;
    auto brojLijevo = broj_a_s_rekurzivno(v,pocetak,sredina);
    auto brojDesno = broj_a_s_rekurzivno(v,sredina+1,kraj);
    auto ukupanBroj = brojDesno + brojLijevo;

    // ostaje konsolidacija
    // treba provjeriti krajnji broj desno u lijevoj polovini
    // i krajnji broj lijevo u desnoj polovini

    if(2 * v[sredina] == v[sredina - 1]+ v[sredina+1])
        ukupanBroj++;

    if(2*v[sredina+1] == v[sredina] + v[sredina+2])
        ukupanBroj++;

    // npr 0 1 2 3 4
    // sredina = 2
    // 1. dio 0..2
    // 2. dio 3..4

    return ukupanBroj;

}



int broj_a_s(vector<int> &v){

    if(v.size()<3){
        return 0;
    }

    return broj_a_s_rekurzivno(v,0,v.size()-1);

}



int main(){

    vector<int> v{0,2,4,6,8,12,14};

    cout<<broj_a_s(v)<<endl;


    return 0;
}
