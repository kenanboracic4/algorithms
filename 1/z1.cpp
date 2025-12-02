#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mojmin(vector<int> &v)
{

    int m = INT_MAX;
    for(auto x:v)
    {
        if(x<m)
        {
            m=x;
        }
    }
    return m;
}

int mojmin2(vector<int>&v)
{
    if(v.size()==0)
    {
        throw invalid_argument("Funckija min ocekujen e preazan vektor");

    }
    int m=v[0];
    int i=1;

    while(i<v.size())
    {
        if(v[i]<m)
        {
            m=v[i];
        }
        ++i;
    }
    return m;
}

int mmcd2_interna(vector<int> &v, int pocetak, int kraj)
{

    if(pocetak == kraj)
    {
        return v[pocetak];
    }
    if(pocetak > kraj)
        throw invalid_argument("Problem!");

    auto mid = (kraj +pocetak)/2;

    auto m1= mmcd2_interna(v, pocetak, mid-1);
    auto m2= mmcd2_interna(v, mid, kraj);

    return min(m1,m2);
}


int mojmincd(vector<int> v)
{
    if(v.size()== 0)
    {
        throw invalid_argument("Prazan vektor");
    }

    if(v.size()== 1)
        return v[0]; // minimum je upravo prvi i jedini element

    auto mid = v.size()/2;

    auto v1 = vector<int>(mid);
    auto v2 = vector<int>(v.size()-mid);

    int i = 0;
    int p = 0;
    while(p<mid)
    {
        v1[p++] = v[i++];
    }
    p = 0;
    while (i<v.size())
        v2[p++] = v[i++];

//auto m1 = minimumdijela();
//auto m2 = minimumdijela();

    auto m1=mojmincd(v1);
    auto m2=mojmincd(v2);


    if(m1<m2)
        return m1;
    return m2;

}

int mojmincd2(vector<int> &v,int pocetak,int kraj)
{
    if(v.size()==0)
        throw invalid_argument("vektor je prazan! ");

    return mojmincd2(v,0,v.size()-1);

}

int main()
{

    vector<int> v {10,50,35,2,16,45,1};

    int m = mojmin(v);

    m = mojmin(v);

    cout<<m<<endl;


}



