#include <iostream>
using namespace std;

int sublista_bt(int *a,int tam,int soma){
    if(soma == 0){return 1;}
    if(soma < 0 || tam == 0){return 0;}

    int result = sublista_bt(a,tam - 1,soma- a[tam - 1]); /*colocando o numero atual*/
    int result2 =sublista_bt(a,tam - 1, soma); /*não colocando o numero atual*/
    return result + result2;
}
int main(){
    int *a,n,s;
    cin >> n >> s;
    a = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << sublista_bt(a,n,s);
    delete a;
    return 0;
}