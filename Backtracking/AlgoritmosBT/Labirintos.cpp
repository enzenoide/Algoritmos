#include <iostream>

bool labirinto_bt1(int labirinto[20][20], int linha, int coluna, int l , int c){
    if(l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] == 1){
        return false; /*Rejeita*/
    }
    if(l == linha - 1 && c == coluna - 1){
        return true; /* Aceita */
    }
    if(labirinto_bt1(labirinto, linha,coluna,l + 1,c)){ /* Caminho Abaixo */
        return true;
    }
    if(labirinto_bt1(labirinto,linha,coluna,l,c+1)){
        return true; /* Caminho a direita */
    }
    return false;
}

bool labirinto_bt2(int labirinto[20][20],int linha,int coluna,int l, int c){
    if(l == -1 || c == -1|| l == linha || c == coluna){
        return false; /* Rejeita*/
    }
    if(l == linha - 1 && c == coluna - 1){
        return true; /* Aceita */
    }
    bool ans = false;/* Retorno da célula */
    ans = labirinto_bt2(labirinto,linha,coluna,l + 1,c);
    if(ans == false){ /* Se não encontrou, tenta a direita*/
        ans = labirinto_bt2(labirinto,linha,coluna,l,c+1);
    }
    if(ans == false){/* Se não encontrou, tenta a esquerda*/
        ans = labirinto_bt2(labirinto,linha,coluna,l,c-1);
    }
    if(ans == false){/* Se não encontrou, tenta acima */
        ans = labirinto_bt2(labirinto,linha,coluna,l-1,c);
    }
    return ans; /* retorno do backtracking */
}
bool labirinto_bt2_sem_if(int labirinto[20][20], int linha, int coluna,int l, int c){
    if(l == -1 || c == -1 || l == linha || c == coluna || labirinto[l][c] != 0){
        return false;
    }
    if(l == linha - 1 && c == coluna - 1){
        return true;
    }

    labirinto[l][c] = 9;
    bool ans = 
        labirinto_bt2_sem_if(labirinto,linha,coluna,l+1,c) || 
        labirinto_bt2_sem_if(labirinto,linha,coluna,l,c+1) ||
        labirinto_bt2_sem_if(labirinto,linha,coluna,l,c-1) ||
        labirinto_bt2_sem_if(labirinto,linha,coluna,l+1,c);

        labirinto[l][c] = 0;
        return ans;
}
int labirinto_qtd_caminhos(int labirinto[20][20],int linha,int coluna, int l , int c){
    if(l == -1 || c == -1 || l == linha || c == coluna || labirinto[l][c] != 0){
        return false;
    }
    if(l == linha - 1 && c == coluna - 1){
        return true;
    }
    labirinto[l][c] = 9;
    int ans = 
        labirinto_qtd_caminhos(labirinto,linha,coluna,l+1,c) + 
        labirinto_qtd_caminhos(labirinto,linha,coluna,l,c+1) +
        labirinto_qtd_caminhos(labirinto,linha,coluna,l,c-1) +
        labirinto_qtd_caminhos(labirinto,linha,coluna,l+1,c); 
    labirinto[l][c] = 0;
    return ans;
}
int main(){
    int labirinto[20][20] = {
        {0,0,1,0,0},
        {1,0,1,1,0},
        {0,0,0,1,0},
        {0,1,0,0,0},
        {0,1,1,1,0}
    };
    int linha = 5;
    int coluna = 5;

    if(labirinto_bt1(labirinto,linha,coluna,0,0)){
        std::cout << "Caminho encontrado (bt1)!" << std::endl;
    } else {
        std::cout << "Caminho não encontrado (bt1)!" << std::endl;
    }

    if(labirinto_bt2(labirinto,linha,coluna,0,0)){
        std::cout << "Caminho encontrado (bt2)!" << std::endl;
    } else {
        std::cout << "Caminho não encontrado (bt2)!" << std::endl;
    }

    if(labirinto_bt2_sem_if(labirinto,linha,coluna,0,0)){
        std::cout << "Caminho encontrado (bt2 sem if)!" << std::endl;
    } else {
        std::cout << "Caminho não encontrado (bt2 sem if)!" << std::endl;
    }

    int qtd_caminhos = labirinto_qtd_caminhos(labirinto,linha,coluna,0,0);
    std::cout << "Quantidade de caminhos encontrados: " << qtd_caminhos << std::endl;
    cout << "UHU!";
    return 0;
}