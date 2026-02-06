#include "ordenacao.hpp"

/* TODO: Implementar função */
bool ordenado(int a[],  unsigned int t){
    if (t <= 1) return true;

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

    for(unsigned int i = 0; i < t - 1; ++i){
        min = i;

        for(unsigned int j = i + 1; j < t; ++j){
            if(a[j] < a[min]){
                min = j;
            }
        }

        if(min != i){
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }

}/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
     for(int i = 1;i < t; ++i){
      int j =  i - 1;
      int num = a[i];/*pra salvar o numero q está na posicao i*/
      while(j >= 0 && num < a[j]){
        a[j + 1] = a[j];
        j--;
    }
      a[j + 1] = num;

  } 
}

/* TODO: Implementar função */
void merge(int a[],int i1, int j1, int i2, int j2){
    int * temp = new int[((j1 - i1) + (j2 - i2) + 2)];
    int i = i1;
    int j = i2;
    int k = 0;
    while( i <= j1 && j <= j2){
      if(a[i] < a[j]){
        temp[k++] = a[i++];
    }
      else{
        temp[k++] = a[j++];
    }
  }
    while(i <= j1){
      temp[k++] = a[i++];
  }
    while(j <= j2){
      temp[k++] = a[j++];
  }
    for(i = i1,j = 0; i <= j2; ++i,++j){
      a[i] = temp[j];
  }
    delete[] temp;
     
}
void merge_sort_rec(int a[], int primeiro, int ultimo){
    int meio;
    if(primeiro < ultimo){
      meio = (primeiro + ultimo) / 2;
      merge_sort_rec(a,primeiro,meio);
      merge_sort_rec(a,meio + 1, ultimo);
      merge(a,primeiro,meio,meio + 1, ultimo);
  }
}
void merge_sort(int a[],unsigned int t){
    if (t <= 1) return;
    merge_sort_rec(a,0,t-1);
}
