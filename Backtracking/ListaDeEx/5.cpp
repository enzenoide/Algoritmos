#include <iostream>
#include <vector>
using namespace std;
int labirinto_bt(vector<vector<int>> &labirinto, int l_inicial, int c_inicial,int l_final,int c_final,int &maior_d, int d_atual){
    int linha = labirinto.size();
    int coluna = labirinto[0].size();
    if(l_inicial < 0 || c_inicial < 0 || l_inicial >= linha ||c_inicial >= coluna || labirinto[l_inicial][c_inicial] != 0){
        return false;
    }
    if(l_inicial == l_final && c_inicial == c_final){
        return true;
    }
    labirinto[l_inicial][c_inicial] = 9;

    bool ans = 
    labirinto_bt(labirinto,l_inicial + 1,c_inicial,l_final,c_final)||
    labirinto_bt(labirinto,l_inicial,c_inicial + 1,l_final,c_final)||
    labirinto_bt(labirinto,l_inicial - 1,c_inicial,l_final,c_final)||
    labirinto_bt(labirinto,l_inicial,c_inicial - 1,l_final,c_final);

    return ans;
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
    bool result = labirinto_bt(labirinto,li,ci,lf,cf);
    cout << result << endl;
    return 0;
}