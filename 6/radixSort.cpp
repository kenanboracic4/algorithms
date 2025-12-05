#include <iostream>
#include <vector>


using namespace std;

int nadjiCifru(int x, int pozicija){

    //pozicija == 0 tada su jedinice
    // pozicija == 1 tada su desetice
    // pozicija == 2 tada su stotice

    while(pozicija != 0){
        x /= 10;
        pozicija--;

    }
    return x % 10;

}

void radixSort(vector<int> &v){

    vector<vector<int>> korpe(10);

    for(int pozicija = 0; pozicija <= 1; pozicija++){

    

    for(auto x:v){
        auto brojKorpe = nadjiCifru(x,0);
        korpe[brojKorpe].push_back(x);
    }

    auto p = 0;
    for(int i = 0; i< korpe.size(); i++){
        for(auto x:korpe[i]){
            v[p++] = x;
        }
        korpe[i].clear();
    }


    }

}

int nadji_cifru_hex(int x, int pozicija){
    return (x>>(pozicija*4) & 0x0F);
}

int main(){

    cout<<nadjiCifru(123,0) <<endl;
    vector<int> v{10,50,32,56,44,34,71,12,62};

    radixSort(v);
    for(auto x:v){
        cout<<x<< "  ";
    }



    return 0;
}