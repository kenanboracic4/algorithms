#include <iostream>
#include <vector>

// cirkularna lista
// dvostruko linkovanje, da bude i glava i kraj, brisanje prvog i cupanje te vrijednosti (pop front i pop back)
using namespace std;

template<typename T>
class Lista {

    class CvorLista{

        public:

        T m_vrijednost;
        CvorLista* m_sljedeci;

        CvorLista(T vrijednost):m_vrijednost(vrijednost), m_sljedeci(nullptr){}


    };

    CvorLista* m_glava;

public:

    Lista():m_glava(nullptr){};

    ~Lista(){
        auto  pocetak = m_glava;

        while ( pocetak != nullptr){
            auto temp = pocetak -> m_sljedeci;
            delete pocetak;
            pocetak = temp;
        }
    }

    void dodaj(const T vrijednost){
        auto cvor = new CvorLista(vrijednost);
        cvor -> m_sljedeci = m_glava;
        m_glava = cvor;
    }
    
    void dodajNaKraj(const T vrijednost){
        auto noviCvor = new CvorLista(vrijednost);

        if(m_glava == nullptr){
            m_glava = noviCvor;
        }else {
            auto tekuci = m_glava;
            while (tekuci -> m_sljedeci != nullptr){
                tekuci = tekuci -> m_sljedeci;
            }
            // ovdje tekuci pokazuje na posljednji cvor liste
        }
    }

    void dodajNaKraj2(const T vrijednost){

        auto noviCvor = new CvorLista(vrijednost);
        auto pokazivacNaTekuci = &m_glava;
        auto tekuci = m_glava;

        while (tekuci != nullptr){
            pokazivacNaTekuci = &tekuci->m_sljedeci;
            tekuci = tekuci -> m_sljedeci;
        }

        *pokazivacNaTekuci = noviCvor;

    }

    void obrisi(const T vrijednost){
        auto tekuci = m_glava;
        auto pokazivacNaPrethodni = &m_glava;

        while (tekuci != nullptr){
            if (tekuci -> m_vrijednost == vrijednost){
                // nasli smo element
                *pokazivacNaPrethodni = tekuci -> sljedeci ;
                delete tekuci;
                return;
            }

            pokazivacNaPrethodni = &tekuci -> m_sljedeci;

            tekuci = tekuci -> m_sljedeci;

        }
        throw invalid_argument("NE postoji takav element");
    }

    void test(){
        auto pocetak = m_glava;
        while ( pocetak != nullptr){
            cout<<pocetak -> m_vrijednost << " ";
            pocetak = pocetak -> m_sljedeci;
        }
        cout<<endl;
    }

    class IteratorListe{
        
        CvorLista* m_cvor;

        public:
        IteratorListe(CvorLista* cvor){
            m_cvor(cvor);
        }
        IteratorListe& operator++(){
            if(m_cvor != nullptr){
                m_cvor = m_cvor -> m_sljedeci;

            }
            return *this;

        }
        T& operator*(){
            return m_cvor -> m_vrijednost;

        }
        bool operator !=(IteratorListe& desni){
            // lijeva strana je this
            return m_cvor != desni -> m_cvor;
        }
    };

    IteratorListe begin(){return IteratorListe(m_glava); }
    IteratorListe end(){return IteratorListe(nullptr); }


};

int main(){

    Lista<int> l;
    l.dodaj(10);
    l.dodaj(20);
    l.dodaj(30);

    l.dodajNaKraj(5);
    l.dodajNaKraj(15);


    
    l.test();

    for(auto x: l){
        cout<<x<<" ";
    }


    return 0;
}