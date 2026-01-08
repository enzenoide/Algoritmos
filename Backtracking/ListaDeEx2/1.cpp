#include <iostream>
using namespace std;

bool sublista_bt(int *a,int tam,int soma){
    bool result;
    if(soma == 0){return true;}
    if(soma < 0 || tam == 0){return false;}

    result = sublista_bt(a,tam - 1,soma- a[tam - 1]); /*colocando o numero atual*/
    result = result || sublista_bt(a,tam - 1, soma); /*não colocando o numero atual*/
    return result;
}
int main(){
    int *a,n,s;
    cin >> n >> s;
    a = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    if(sublista_bt(a,n,s)){cout << 1 << endl;}
    else{cout << 0;}
    delete a;
    return 0;
}