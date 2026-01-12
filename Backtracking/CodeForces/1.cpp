#include <iostream>
#include <vector>
using namespace std;
bool labirinto_bt(vector<vector<int>> &labirinto, int l, int c){
    int linha = labirinto.size();
    int coluna = labirinto[0].size();

    if(l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] != 0){
        return false;
    }
    if(l == linha - 1 && c == coluna - 1){
        return true;
    }
    labirinto[l][c] = 2;
    bool ans = 
        labirinto_bt(labirinto,l+1,c) ||
        labirinto_bt(labirinto,l,c+1) ||
        labirinto_bt(labirinto,l,c-1) ||
        labirinto_bt(labirinto,l-1,c);
    
    labirinto[l][c] = 0;
    return ans;
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
    if(labirinto_bt(labirinto,0,0)){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}