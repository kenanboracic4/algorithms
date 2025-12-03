#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
// zadatak najblizi par tacaka -> closest pair

using namespace std;

class Tacka{

    double m_x, m_y;

public:
    Tacka(double x, double y){
        m_x = x;
        m_y = y;
    }
    Tacka(){
         m_x = 0.0;
        m_y = 0.0;
    }

    double getX(){ return m_x; }
    double getY(){ return m_y; }

};

double udaljenost(Tacka &x, Tacka &y){
    return sqrt(pow(x.getX()-y.getX(), 2)+ pow(x.getY()- y.getY(),2));
}

double najbliziParRekurzivno(vector<Tacka> &v, int odIndeksa, int doIndeksa,Tacka &prva, Tacka &druga){

    if (odIndeksa == doIndeksa){
        throw invalid_argument("Ovo se ne bi smjelo desiti !!!");
    }
    else if (odIndeksa + 1 == doIndeksa){
        prva = v[odIndeksa];
        druga = v[doIndeksa]; // v[odIndeksa +1]
        return udaljenost(prva,druga);
    }
    else if(odIndeksa +2 == doIndeksa){ // vektor ima 3 elementa, d1,d2,d3 udaljenost izmedju
        auto d1 = udaljenost(v[odIndeksa], v[odIndeksa +1 ]);  // 1 i 2 tacka
        auto d2 = udaljenost(v[odIndeksa], v[odIndeksa +2 ]); // 1 i 3 tacka
        auto d3 = udaljenost(v[odIndeksa+1], v[odIndeksa +2 ]); // 2 i 3 tacka

        if (d1 < d2 && d1< d3){ // provjerava najblizu udaljenost
            prva = v[odIndeksa];
            druga = v[odIndeksa+1];
            return d1;
        } else if( d2<d3){
            prva = v[odIndeksa];
            druga = v[odIndeksa + 2];
            return d2;
        }
        else{
            prva = v[odIndeksa+1];
            druga = v[odIndeksa+2];
            return d3;
        }
    }

    auto sredina = (odIndeksa + doIndeksa) / 2;

    Tacka l1,l2;
    Tacka r1,r2;

    auto dLijeva = najbliziParRekurzivno(v,odIndeksa,sredina, l1, l2);
    auto dDesna = najbliziParRekurzivno(v,sredina+1,doIndeksa, r1, r2);

    double daljina;
    if(dLijeva< dDesna){
        daljina = dLijeva;
        prva = l1;
        druga = l2;
    }else{
    daljina= dDesna;
    prva = r1;
    druga = r2;
    }

    auto srednjaTacka = v[sredina];
    vector<Tacka> pojas;

    for(auto t: v){
        if (abs(t.getX()- srednjaTacka.getX())< daljina){
            pojas.push_back(t);
        }
    }

    for(int i= odIndeksa;i < pojas.size() - 1; i++){
        for(int j = i +1; j<pojas.size(); j++){
                auto d = udaljenost(pojas[i],pojas[j]);
                if( d< daljina){
                    daljina = d;
                    prva = pojas[i];
                    druga = pojas[j];
                }

        }
    }

    return daljina;

}

double najbliziPar(vector<Tacka> &v, Tacka &prva, Tacka &druga){

    if(v.size()<= 1){
        throw invalid_argument ("Najblizi par zahtijeva barem dvije tacke ");
    }

    sort(v.begin(),v.end(),[](Tacka &a, Tacka &b){return a.getX()<b.getX(); }); // sortira  Tacke u vektoru po X kordinati

    return najbliziParRekurzivno(v,0,v.size()-1,prva,druga);
}

int main(){

vector<Tacka> v{
    Tacka(1,0),Tacka(2,2), Tacka(2,3),Tacka(2,3),Tacka(4,6),Tacka(8,9),Tacka(8.5,9)};


    Tacka a,b;

    cout<<najbliziPar(v,a,b);




    return 0;
}
