#include <iostream>
#include <vector>
using namespace std;

void sublista_bt(vector<int> &lista ,int indice,int soma,vector<int> &resposta,int &maior_sub,vector<int> &melhor_sub){
    if(soma == 0){
      if(resposta.size() > maior_sub){
          maior_sub = resposta.size();
          melhor_sub = resposta;
    }
    return;
    }
    if(soma < 0 || indice == lista.size()){
        return;
    }

    resposta.push_back(lista[indice]);
    sublista_bt(lista,indice + 1, soma - lista[indice],resposta,maior_sub,melhor_sub);
    resposta.pop_back();
    sublista_bt(lista,indice+1,soma,resposta,maior_sub,melhor_sub);
  
    return;
}
int main(){
    int n,soma,indice;
    cin >> n >> soma;
    vector<int> lista(n);
    for(int i = 0; i < n; ++i){
        cin >> lista[i];
    }
    vector<int> resultado;
    vector<int> melhor_sub;
    int maior_sub = 0;
    sublista_bt(lista,0,soma,resultado,maior_sub,melhor_sub);
    if(melhor_sub.size() == 0){
      cout << 0;        
    }
    else{
      for(int i = 0; i < melhor_sub.size();++i){
            cout << melhor_sub[i] << " ";
        }
    }
    return 0;
}


