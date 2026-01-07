#include <iostream>
#include <vector>
using namespace std;
bool labirinto_bt(vector<vector<int>> &labirinto,int l,int c){
    int linhas = labirinto.size();
    int colunas = labirinto[0].size();
    
    if(l < 0 || c < 0 || l >= linhas || c >= colunas || labirinto[l][c] != 0){
        return false;
    }
    if (l == linhas - 1 && c ==colunas - 1){
        return true;
    }

    labirinto[l][c] = 9;
    bool ans = 
    labirinto_bt(labirinto,l+1,c)||
    labirinto_bt(labirinto,l,c+1)||
    labirinto_bt(labirinto,l,c-1)||
    labirinto_bt(labirinto,l-1,c);
    
    return ans;
}
int main(){
    int L,C;
    cin >> L >> C;
    vector<vector<int>> labirinto(L,vector<int>(C));
    for(int i = 0; i < L; ++i){
        for(int j = 0; j < C; ++j){
            cin >> labirinto[i][j];
        }
    }
    if(labirinto_bt(labirinto,0,0)){ /* primeira chamada da funçao, que diz onde vc vai começar*/
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
