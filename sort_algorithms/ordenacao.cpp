#include "ordenacao.hpp"

/* TODO: Implementar função */
bool ordenado(int a[],  unsigned int t){
    if(t == 1){
      return true;
  }
    for(int i = 0; i <= t - 2; ++i){
      if(a[i] > a[i+1]){
        return false;
    }
  }
    return true;
}

/* TODO: Implementar função */
void selecao(int a[], unsigned int t){
    int min, aux;
    for(int i = 0; i < t - 1; ++i){
      min = i;
      for(int j = i + 1;j < t;++j){
          if(a[j] < a[min]){
          min = j;
      }
      if(a[i] != a[min]){
          aux = a[i];
          a[i] = a[min];
          a[min] = aux;
      }
    }
  }
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
  
}

/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t);
