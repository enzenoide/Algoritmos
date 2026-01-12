#include <iostream>
#include <vector>
using namespace std;

bool sublista_bt(vector<int> &lista,int tam,int soma){
    if(soma == 0){ /*se achou a soma ja para de procurar*/
        return true;
    }
    if(soma < 0 || tam == 0){/*Se não achou a soma, verifica se a soma ja passou do limite ou se o tamanho acabou*/
        return false;
    }
    bool ans = sublista_bt(lista,tam - 1,soma - lista[tam - 1]) ||
    sublista_bt(lista,tam - 1, soma);
    
    return ans;
}
int main(){
    int n, soma;
    cin >> n >> soma;
    vector<int> lista(n);
    for(int i = 0; i < n; ++i){
        cin >> lista[i];
    }
    if(sublista_bt(lista,n,soma)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}