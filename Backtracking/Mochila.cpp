#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct item
{
    int peso;
    double valor;

};
double mochila(vector<item> &itens, int q, int peso){
    double ans = 0;
    if(q < 0 || peso <= 0){
        return 0;
    }
    if(itens[q].peso > peso){
        return mochila(itens,q-1,peso);
    }
    double nao_colocar = mochila(itens,q-1,peso);
    double colocar = itens[q].valor + mochila(itens,q - 1, peso - itens[q].peso);
    ans = max(colocar,nao_colocar);
    return ans;
}
int main(){
    int n, peso_maximo; std::cin >> n >> peso_maximo;
    std::vector<item> itens(n);
    for (item & i: itens){
        std::cin >> i.peso >> i.valor;
    }
    double valor = mochila(itens, n-1, peso_maximo);
    cout << "Valor final: " << valor << endl;
    return 0;
}

