// uloha-2-3.c -- Tyzden 2 - Uloha 3
// Peter Ocelik, 26.9.2016 17:11:13

#include <stdio.h>
#include <stdlib.h>

long spajaj(int *a, int *x, int lavy, int stred, int pravy)
{
  int i = lavy, j = stred, k = lavy;
  int pocet = 0;

  while((i <= stred - 1) && (j <= pravy)){
    if(a[i] <= a[j]){
      x[k++] = a[i++];
    }
    else{
      x[k++] = a[j++];
      pocet += (stred - i);
    }
  }

  while (i <= stred - 1)
    x[k++] = a[i++];
 
  while (j <= pravy)
    x[k++] = a[j++];
 
  for (i = lavy; i <= pravy; i++)
    a[i] = x[i];
 
  return pocet;
}

long mergeSort(int *a, int *x, int lavy, int pravy)
{
  int stred, pocet = 0;
  if(pravy > lavy){
    stred = (pravy + lavy) / 2;

    pocet = mergeSort(a, x, lavy, stred);
    pocet += mergeSort(a, x, stred+1, pravy);
    pocet += spajaj(a, x, lavy, stred+1, pravy);
  }
  
  return pocet;
}

long pocet_neusporiadanych_dvojic(int *a, int n)
{
    int *x = (int *)malloc(n * sizeof(int));
    return mergeSort(a, x, 0, n - 1);
}

int main(void)
{
  int i, *x, n;

  scanf("%d", &n);
  x = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);

  printf("Pocet neusporiadanych dvojic: %ld\n", pocet_neusporiadanych_dvojic(x, n));
  
  return 0;
}