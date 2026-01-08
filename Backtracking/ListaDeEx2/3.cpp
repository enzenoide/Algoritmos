#include <iostream>
#include <vector>
using namespace std;

bool sublista_bt(vector<int> &lista ,int indice,int soma,vector<int> &resposta){
    if(soma == 0){
        return true;
    }
    if(soma < 0 || indice == lista.size()){
        return false;
    }

    resposta.push_back(lista[indice]);
    if(sublista_bt(lista,indice + 1, soma - lista[indice],resposta)){
        return true;
    }

    resposta.pop_back();
    if(sublista_bt(lista,indice+1,soma,resposta)){
        return true;
    }
    return false;
}
int main(){
    int n,soma,indice;
    cin >> n >> soma;
    vector<int> lista(n);
    for(int i = 0; i < n; ++i){
        cin >> lista[i];
    }
    vector<int> resultado;
    if(sublista_bt(lista,0,soma,resultado)){
        for(int i = 0; i < resultado.size();++i){
            cout << resultado[i] << " ";
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
