#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct mochila{
    int peso;
    double preco;
};
double mochila_bt(vector<mochila> &lista,int itens,int peso){
    double ans = 0;
    if(itens < 0 || peso <= 0){
        return 0;
    }
    if(lista[itens].peso > peso){
        return mochila_bt(lista,itens-1,peso);
    }
    double nao_colocar = mochila_bt(lista,itens - 1 , peso);
    double colocar = lista[itens].preco + mochila_bt(lista,itens - 1,peso - lista[itens].peso);
    ans = max(colocar,nao_colocar);
    return ans;
}
int main(){
    int n, peso_maximo; cin >> n >> peso_maximo;
    vector<mochila> lista(n);
    for (mochila & i: lista){
        cin >> i.peso >> i.preco;
    }
    double valor = mochila_bt(lista, n-1, peso_maximo);
    cout << fixed << setprecision(2) << valor << endl;
    return 0;
}
