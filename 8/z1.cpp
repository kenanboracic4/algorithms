#include <iostream>
#include <vector>

using namespace std;
//klasa super vektor
// templejt, treba napraviti da indexnim pristupom automatski alocira novu velicinu vektora
// dodatna funckija prolazi kroz elemente vektora
// iteratori

template <typename T>
class superVektor {
private:
    int velicina;
    T* niz;

public:
    superVektor() : velicina(0), niz(nullptr) {}

    superVektor(int v) : velicina(v) {
        niz = new T[v];
        for (int i = 0; i < v; i++) niz[i] = 0;
    }

    ~superVektor() {
        delete[] niz;
    }

    
    T& operator[](int index) {
        if (index >= velicina) {
            
            T* noviNiz = new T[index + 1];

           
            for (int i = 0; i < velicina; i++)
                noviNiz[i] = niz[i];


            for (int i = velicina; i <= index; i++)
                noviNiz[i] = 0;

    
            delete[] niz;


            niz = noviNiz;
            velicina = index + 1;
        }

        return niz[index];
    }
    
template <typename F>
    void apply(F fun) {
        for (auto& x : *this) {
            fun(x);
        }
    }

    int size() const { return velicina; }

    
    T* begin() { return niz; }
    T* end()   { return niz + velicina; }
};

//aleksandrov nacin
template <typename T>
class super_vector; // deklaracija klase



template <typename T>
class sv_iterator {

    super_vector<T> *m_v;
    size_t m_index;

    public:
    sv_iterator(super_vector<T> *v, size_t index){
        m_v = v;
        m_index = index;
    }

    friend bool operator == (const sv_iterator<T> &lhs, const sv_iterator<T> &rhs){ // jednaki su kad su im vrijednosti jednake
        return lhs.m_v == rhs.m_v && lhs.m_index == rhs.m_index;
    }
    friend bool operator != (const sv_iterator<T> &lhs, const sv_iterator<T> &rhs){ // razliciti
        return !(lhs.m_v == rhs.m_v && lhs.m_index == rhs.m_index);
    }

    sv_iterator<T> operator++(){
        return sv_iterator(this->m_v, this-> m_index +1);
    }

};


template <typename T>
class super_vector{

    T * m_array;
    size_t m_size;

    public:
        super_vector():m_array(nullptr), m_size(0){} // default konstruktor

        super_vector(size_t size):m_array(nullptr), m_size = size{ // konstruktor sa duzinom i inicijalnim elementom
            m_array = new T[size];
            
        }

        super_vector(size_t size,T value){ // konstruktor sa duzinom i inicijalnim elementom
            m_array = new T[size];
            m_size = size;

            for(int i=0;i<size; i++){
                m_array[i] = value;
            }
        }
        ~super_vector(){
            delete[] m_array;
        }

        int size() {return m_size; } // metoda vraca duzinu

       T& operator[](int index) { // preklopljeni operator [] za vracanje elementa vektora
        if (index >= velicina) {
            
            T* noviNiz = new T[index + 1];

           
            for (int i = 0; i < velicina; i++)
                noviNiz[i] = niz[i];


            for (int i = velicina; i <= index; i++)
                noviNiz[i] = 0;

    
            delete[] niz;


            niz = noviNiz;
            velicina = index + 1;
        }

        return niz[index];
    }
    template <typename F>
    void apply(F f){
        for (int i = 0;i<m.size;i++){
            f(m_array[i]);
        }
    }
    void apply_old_style(void(*f)(T)){
        for(int i=0;i<m_size; i++){
            f(m_array[i]);
        }
    }

    sv_iterator<T> begin(){
        return sv_iterator<T>(this,0);
    }

      sv_iterator<T> end(){
        return sv_iterator<T>(end,0);
    }

    };


int main() {
    superVektor<int> v(5);

    auto it = v.begin();
    while(it != v.end()){
        it++;
    }
    

    for (auto x : v) {
        cout << x << " ";
    }
    cout<<endl;



      v.apply([](int &x){
        x += 10;
    });

    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}