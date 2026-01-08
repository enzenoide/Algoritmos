#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int const NUMERO_GRANDE = 100000000;
int labirinto_bt(vector<vector<int>> &labirinto,int li, int ci,int lf,int cf){
    int linha = labirinto.size();
    int coluna = labirinto[0].size();
    if(li < 0 || ci < 0 || li >= linha || ci >= coluna || labirinto[li][ci] == -1 || labirinto[li][ci] == -2){
        return NUMERO_GRANDE; /* porque não 0? Porque quando encontrar um caminho sem saída e retornar 0 o melhor caminho la embaixo vai retornar 0, mas 0 não é o melhor caminho, é um caminho sem saída*/
                             
    }
    if(li == lf && ci == cf){
        return labirinto[li][ci];
    }
    int dificuldade_atual = labirinto[li][ci];
    labirinto[li][ci] = -2;

    int baixo = labirinto_bt(labirinto,li+1,ci,lf,cf);
    int direita = labirinto_bt(labirinto,li,ci+1,lf,cf);
    int cima = labirinto_bt(labirinto,li-1,ci,lf,cf);
    int esquerda = labirinto_bt(labirinto,li,ci-1,lf,cf);

    labirinto[li][ci] = dificuldade_atual;

    int melhor_caminho = min({baixo,direita,cima,esquerda});

    if(melhor_caminho >= NUMERO_GRANDE){
        return NUMERO_GRANDE;
    }
    return dificuldade_atual + melhor_caminho;


    

}

int main(){
    int l,c,lf,cf,li,ci;
    cin >> l >> c;
    cin >> li >> ci;
    cin >> lf >> cf;
    vector<vector<int>> labirinto(l,vector<int>(c));
    for(int i = 0; i < l; ++i){
        for(int j = 0; j < c; ++j){
            cin >> labirinto[i][j];
        }
    }
    int melhor_caminho = labirinto_bt(labirinto,li,ci,lf,cf);

    if(melhor_caminho >= NUMERO_GRANDE){
        cout << -1 << endl;
    }
    else{
        cout << melhor_caminho << endl;
    }
    return 0;
}