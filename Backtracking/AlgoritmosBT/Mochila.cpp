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
    double ans = 0; /* Variavel ans*/
    if(q < 0 || peso <= 0){ /* Se a quantidade for menor que 0 ou o peso for menor igual a zero*/
        return 0;
    }
    if(itens[q].peso > peso){ /* Se o peso do item atual for maior que o peso da mochila*/
        return mochila(itens,q-1,peso); /*Passa a funçao ignorando o item*/
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
    cout << "UHU!";
    return 0;
}

