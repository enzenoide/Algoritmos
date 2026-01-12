#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const NUMERO_GRANDE = 100000000;
int labirinto_bt(vector<vector<int>> &labirinto,int l, int c){
    int linha = labirinto.size();
    int coluna = labirinto[0].size();
    if(l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] != 0){
        return NUMERO_GRANDE; /* porque não 0? Porque quando encontrar um caminho sem saída e retornar 0 o melhor caminho la embaixo vai retornar 0, mas 0 não é o melhor caminho, é um caminho sem saída*/
                             
    }
    if(l == linha - 1 && c == coluna - 1){
        return 1;
    }
    labirinto[l][c] = 9;

    int baixo = labirinto_bt(labirinto,l+1,c);
    int direita = labirinto_bt(labirinto,l,c+1);
    int cima = labirinto_bt(labirinto,l-1,c);
    int esquerda = labirinto_bt(labirinto,l,c-1);

    labirinto[l][c] = 0;
    int melhor_caminho = min({baixo,direita,cima,esquerda});

    if(melhor_caminho >= NUMERO_GRANDE){
        return NUMERO_GRANDE;
    }
    return 1 + melhor_caminho;


    

}
int labirinto_otimizado(vector<vector<int>> &labirinto,int l, int c, int &melhor_ate_agora, int distancia_atual){ /* Passar o melhor_ate_agora por referencia para que todos os galhos da recursao compartilhem o mesmo valor*/
    int linha = labirinto.size();
    int coluna = labirinto[0].size();
    if(distancia_atual >= melhor_ate_agora){
        return NUMERO_GRANDE;
    }
    if(l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] != 0){
        return NUMERO_GRANDE; /* porque não 0? Porque quando encontrar um caminho sem saída e retornar 0 o melhor caminho la embaixo vai retornar 0, mas 0 não é o melhor caminho, é um caminho sem saída*/
                             
    }
    if(l == linha - 1 && c == coluna - 1){
        melhor_ate_agora = distancia_atual;
        return 1;
    }
    labirinto[l][c] = 9;
    int baixo = labirinto_otimizado(labirinto,l+1,c,melhor_ate_agora, distancia_atual + 1);
    int direita = labirinto_otimizado(labirinto,l,c+1,melhor_ate_agora,distancia_atual + 1);
    int cima = labirinto_otimizado(labirinto,l-1,c,melhor_ate_agora,distancia_atual + 1);
    int esquerda = labirinto_otimizado(labirinto,l,c-1,melhor_ate_agora,distancia_atual + 1);

    labirinto[l][c] = 0;
    int melhor_caminho = min({baixo,direita,cima,esquerda});

    if(melhor_caminho == NUMERO_GRANDE){
        return NUMERO_GRANDE;
    }
    return 1 + melhor_caminho;


    

}
int main(){
    int l,c;
    cin >> l >> c;
    vector<vector<int>> labirinto(l,vector<int>(c));
    for(int i = 0; i < l; ++i){
        for(int j = 0; j < c; ++j){
            cin >> labirinto[i][j];
        }
    }
    int melhor_caminho = labirinto_bt(labirinto,0,0);

    if(melhor_caminho >= NUMERO_GRANDE){
        cout << -1 << endl;
    }
    else{
        cout << melhor_caminho << endl;
    }
    return 0;
}