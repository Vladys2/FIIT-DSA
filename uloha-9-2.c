// uloha-9-2.c -- Tyzden 9 - Uloha 2
// Peter Ocelik, 15.11.2016 17:30:25

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct edge{
  int x;
  int y;
}EDGE;

EDGE *edges;
int n;

int minimum(double *value, int *visited)
{
  int i, index;
  double min = INT_MAX;
 
  for (i = 0; i < n; i++){
    if (visited[i] == 0 && value[i] < min){
      min = value[i];
      index = i;
    }
  } 
  return index;
}

void primov_alg(double **graph)
{
  int i, j, k;
  int kostra[n], visited[n];
  double value[n];
 
  for (i = 0; i < n; i++){
    value[i] = INT_MAX;
    visited[i] = 0;
  }
  
  value[0] = 0;
  kostra[0] = -1; 

  for (j = 0; j < n-1; j++) {
    int u = minimum(value, visited);		
    visited[u] = 1;	
 
    for (k = 0; k < n; k++){
      if ((graph[u][k] >= 0) && (visited[k] == 0) && graph[u][k] < value[k]){
        kostra[k] = u; 
        value[k] = graph[u][k];
      }
    }
  }
 
  double suma = 0;
  for (i = 1; i < n; i++)
    suma += graph[i][kostra[i]];
  printf("%.3lf\n", suma);
}

int main()
{
  int i, j, x, y, m;
  double **graph;
  
  scanf("%d", &n);
  edges = (EDGE *)malloc(n * sizeof(EDGE));
  graph = (double **)calloc(n, sizeof(double *));
  for(i = 0; i < n; i++)
    graph[i] = (double *)calloc(n, sizeof(double));
  
  //nacitanie suradnic
  for(i = 0; i < n; i++){
    scanf("%d %d", &x, &y);
    edges[i].x = x;
    edges[i].y = y;
  }
  
  //vypocet dlzky ciest
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      x = edges[i].x-edges[j].x;
      y = edges[i].y-edges[j].y;
      graph[i][j] = pow(((pow(x,2)) + (pow(y,2))),0.5);
      if(i==j) graph[i][j] = -1;
    }
  }
  
  scanf("%d", &m);
  for(i = 0; i < m; i++){
    scanf("%d %d", &x, &y);
    graph[x-1][y-1] = 0;
    graph[y-1][x-1] = 0;
  }
  /*
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%.3lf ", graph[i][j]);
    }
    putchar('\n');
  }*/
  
 primov_alg(graph);
  
  return 0;
}
