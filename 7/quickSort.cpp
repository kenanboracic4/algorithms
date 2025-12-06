#include <iostream>
#include <vector>

using namespace std;

void quickSort_rek(vector<int> &v, int pocetak, int kraj){

    if (pocetak >= kraj){
        return;
    }
    if(pocetak + 1 == kraj){
        if(v[pocetak] > v[kraj]){
            swap(v[pocetak],v[kraj]);
        } 
        return;
    }

    auto sredina = (pocetak+kraj) /2;
    auto pivot = v[sredina];

    swap(v[sredina], v[kraj]);
    auto i = pocetak;
    auto j = kraj - 1;

    while (true){

        while(v[i] < pivot ){
            i++;
        }

        while (j>= pocetak && v[j] >= pivot)
        {
            j--;
        }
        

        if (i>=j){
            break;
        }
        swap(v[i],v[j]);
        i++;
        j--;
    }
    swap(v[kraj], v[i]);
    quickSort_rek(v,pocetak, i-1);
    quickSort_rek(v, i+1,kraj);

}

void quickSort(vector<int> &v){

    quickSort_rek(v,0,v.size()-1);
}

int main(){

    vector<int> v{10,30,15,25,40,5,35};

    quickSort(v);

    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;

}