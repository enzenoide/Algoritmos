#include <iostream>
#include <vector>
using namespace std;
/*TESTE COM MEMOIZATION*/
double machu(vector<vector<int>> &matriz, vector<vector<int>> &memo,int l,int c, int M){
  if(l == 0){ /*se chegou no topo*/
    return matriz[l][c];
  }
  if(memo[l][c] != -1){ /*Se ja calculou aquela rota*/
    return memo[l][c];
  }
  double menor = machu(matriz,memo,l-1,c,M);/*tenta acima*/
  if(c > 0){/*tenta diagonal esquerda*/
    menor = min(menor,machu(matriz,memo,l-1,c-1,M));
  }
  if(c < M - 1){/*tenta diagonal direita*/
    menor = min(menor,machu(matriz,memo,l-1,c+1,M));
  }
  /*retorna o registro da rota atual + a melhor rota*/
  return memo[l][c] = matriz[l][c] + menor;
}
int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> matriz(N,vector<int> (M));
  vector<vector<int>> memo(N,vector<int> (M,-1));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M;++j){
      cin >> matriz[i][j];
    }
  }
  /*TESTAR TODAS OS PONTOS DE COMEÇO NA ULTIMA LINHA*/
  double res = machu(matriz,memo,N - 1,0,M);
  for(int j = 1; j < M; ++j){
    res = min(res,machu(matriz,memo,N - 1, j,M));

  }
  cout << res << endl;
  return 0;
}
