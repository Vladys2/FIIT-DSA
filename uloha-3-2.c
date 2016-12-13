// uloha-3-2.c -- Tyzden 3 - Uloha 2
// Peter Ocelik, 4.10.2016 23:58:15

#include <stdio.h>
double pocet(int n)
{
  int i, j;
  double stromy[n+1];

  stromy[0] = stromy[1] = 1;
  for(i=2; i<=n; i++){
    stromy[i] = 0;
    for(j=0; j<i; j++)
      stromy[i] += stromy[j] * stromy[i-j-1];
    }
    return stromy[n];
}

int main()
{
  int n;
  
  while(scanf("%d", &n) != EOF){
    printf("%.f\n",pocet(n));
  }
  
  
  return 0;
}
