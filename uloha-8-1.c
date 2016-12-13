// uloha-8-1.c -- Tyzden 8 - Uloha 1
// Peter Ocelik, 7.11.2016 11:39:07

#include <stdio.h>
#include <string.h>

char *data[10000];
int stlpec, riadok;

int maze(int x, int y)
{
  if(x == riadok && y == stlpec-2) {
    return 0;
  }
 
  if((x >= 0) && (x < riadok) && (y >= 0) && (y < stlpec) && (data[x][y] == '.')) {
    data[x][y]='*';

    if (maze(x, y-1) == 0)
      return 0;
    
    if (maze(x-1, y) == 0)
      return 0;
      
    if (maze(x, y+1) == 0)
      return 0;
    
    if (maze(x+1, y) == 0)
      return 0;

    data[x][y]='.';
    return 1;
  }   
  return 1;
}

int main()
{
  int i = 0;
  char s[10000];
  
  while (scanf("%s", s) > 0){
    data[i] = strdup(s);
    stlpec = strlen(s);
    i++;
  }
  riadok = i;

  if (maze(0, 1) == 1)
    printf("Bez riesenia\n");
  
  for(i = 0; i < riadok; i++){
    printf("%s\n",data[i]);
  }
  
  return 0;
}
