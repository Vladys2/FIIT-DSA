// uloha-9-1.c -- Tyzden 9 - Uloha 1
// Peter Ocelik, 15.11.2016 17:21:36

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a, b) ((a > b) ? a : b)

int n, m;
int *dist;

int minDistance(int *dist, int *sptSet)
{
  int i;
  int min = INT_MAX, index;
  
   for (i = 0; i < n; i++)
     if (sptSet[i] == 0 && dist[i] <= min)
         min = dist[i], index = i;
  
   return index;
}
  
void dijkstra(int **graph, int src)
{
  int i, j, k;
  dist = (int *)malloc(n * sizeof(int));
  int sptSet[n];
  
  for (i = 0; i < n; i++){
    dist[i] = INT_MAX; 
    sptSet[i] = 0;
  }
  
  dist[src] = 0;

  for (j = 0; j < n-1; j++){
    int u = minDistance(dist, sptSet);
    sptSet[u] = 1;
  
    for (k = 0; k < n; k++)
      if (!sptSet[k] && graph[u][k] && dist[u] != INT_MAX && dist[u]+graph[u][k] < dist[k])
      dist[k] = dist[u] + graph[u][k];
  }
}

int division(int array[], int n)
{
  int i;
  int a = 0, b = 0;
  for(i = n-1; i >= 0; i--){
    if(a <= b){
      a += array[i];
      //printf("a %d\n", array[i]);
    }
    else {
      b+= array[i];
      //printf("b %d\n", array[i]);
    }
  }
  printf("%d %d\n", a, b);
  if(a >= b)
    return a;
  else return b;
}

void quick_sort (int *a, int n) 
{
  int i, j, p, t;
  if (n < 2)
    return;
  p = a[n / 2];
  for (i = 0, j = n-1;; i++, j--) {
    while (a[i] < p)
      i++;
    while (p < a[j])
      j--;
    if (i >= j)
      break;
    t = a[i]; a[i] = a[j]; a[j] = t;
    }
  quick_sort(a, i);
  quick_sort(a + i, n - i);
}

int knapSack(int W, int wt[], int val[], int n)
{
  int i, w;
  int K[n+1][W+1];
 
  for (i = 0; i <= n; i++) {
    for (w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i-1] <= w)
        K[i][w] = MAX(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
      else
        K[i][w] = K[i-1][w];
    }
  }
  return K[n][W];
}


int main()
{
  int i, k;
  int **graph;
  int *x, *val;
  int sum=0;
  
  scanf("%d %d\n",&n, &m);
  graph = (int **)calloc(n, sizeof(int *));
  for(i = 0; i < n; i++)
    graph[i] = (int *)calloc(n, sizeof(int));

  int a, b, d;
  for(i = 0; i < m; i++){
    scanf("%d %d %d\n", &a, &b, &d);
    graph[a-1][b-1] = d; 
    graph[b-1][a-1] = d; 
  }
  
  dijkstra(graph, 0);
  
  scanf("%d\n",&k);
  x = (int *)malloc(k * sizeof(int));
  val = (int *)malloc(k * sizeof(int));
  int house;
  for(i = 0; i < k; i++){
    scanf("%d\n", &house);
    x[i] = 2*dist[house-1];
    val[i] = house;
    sum+=x[i];
    //printf("%d %d\n", house, x[i]);
  }
  
  /*for(i = 0; i < k; i++){
    printf("%d\n", x[i]);
  }*/
  
  printf("%d\n", sum - knapSack(sum/2, x, x, k));
  

  return 0;
}
