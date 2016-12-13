// uloha-6-1.c -- Tyzden 6 - Uloha 1
// Peter Ocelik, 24.10.2016 13:00:33

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lowbit(X) (X & -X)

int T[100000];

void inc(int i ,int k){
  while(i < 100000){  
    T[i] += k;
    i += lowbit(i);
  }
}

void dec(int i, int k){
  while(i < 100000){  
    T[i] -= k;
    i += lowbit(i);
  }
}

int sum(int k) 	// od prvej po k-tu
{
  int value = 0;
  while(k > 0){  
    value += T[k];
    k -= lowbit(k);
  }
  return value;
}

int get(int i, int k)
{
  if(i > 1)
    return sum(i+k) - sum(i-1);
  else
    return sum(i+k);
}

int main()
{
  char buf[10];
  int i, k;
  
   while (scanf("%s", buf) > 0)
  {
     scanf("%d %d", &i, &k);
     if (!strcmp(buf, "inc")){
       inc(i,k);
     }
    else if(!strcmp(buf, "dec") )
      dec(i,k);
      else
        printf("%d\n",get(i,k));
   }   
     
  return 0;
}
