#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int piramide_bt(vector<vector<int>> &matriz,int l, int c,int N){
    if(c < 0 || (c + l - 1) >= N){
        return -1;
    }
    double pesoDaLinha = 0;
    for(int i = 0; i < l;++i){
        pesoDaLinha += matriz[l - 1][c + i];
    }

    if(l == N){
        return pesoDaLinha;
    }
    int menor_caminho = -1;
    double bDireita = piramide_bt(matriz,l + 1,c,N);
    double bEsquerda = piramide_bt(matriz,l + 1, c - 1,N);
    if(bDireita != -1 && bEsquerda != -1){
        menor_caminho = min({bDireita,bEsquerda});
    }
    else if(bDireita != -1){
        menor_caminho = bDireita;
    }
    else if(bEsquerda != -1){
        menor_caminho = bEsquerda;
    }

    if(menor_caminho == -1){
        return -1;
    }
    return pesoDaLinha + menor_caminho;
}
int main(){
  int N;
  cin >> N;
  vector<vector<int>> matriz(N,vector<int>(N));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      cin >> matriz[i][j];
    }
  }
  int melhor_resultado = INT_MAX;
  for(int i = 0; i < N; ++i){
    int res = piramide_bt(matriz,1,i,N);
    if(res != -1){
      melhor_resultado = min(melhor_resultado,res);
    }
  }
  cout << melhor_resultado << endl;
  return 0;

}
