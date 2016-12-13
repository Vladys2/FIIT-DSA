// uloha-8-2.c -- Tyzden 8 - Uloha 2
// Peter Ocelik, 7.11.2016 11:40:16

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *data1[10000];
char *data2[10000];
int stlpec, riadok;
char *pathfinder[10000];

int mazeL(int x, int y)
{
  
  if(x == riadok && y == stlpec-2) 
    return 0;
  
  if((x >= 0) && (x < riadok) && (y >= 0) && (y < stlpec) && (data1[x][y] == '.')) {
    data1[x][y]='*';

    if (mazeL(x-1, y) == 0)		
      return 0;
    
    if (mazeL(x, y+1) == 0)		
      return 0;
      
    if (mazeL(x+1, y) == 0)		
      return 0;
    
    if (mazeL(x, y-1) == 0)		
      return 0;

    data1[x][y]='.';
    return 1;
  }   
  return 1;
}

int mazeR(int x, int y)
{
  
  if(x == riadok && y == stlpec-2) 
    return 0;
  
  if((x >= 0) && (x < riadok) && (y >= 0) && (y < stlpec) && (data2[x][y] == '.')) {
    data2[x][y]='*';
    
    if(data2[x][y] == data1[x][y])
      pathfinder[x][y] = '!';

   if (mazeR(x+1, y) == 0)	
      return 0;
    
    if (mazeR(x, y+1) == 0)
      return 0;
      
    if (mazeR(x-1, y) == 0)	
      return 0;
    
    if (mazeR(x, y-1) == 0)	
      return 0;
    
    data2[x][y]='.';
    return 1;
  }   
  return 1;
}

void scan()
{
  int i = 0;
  char s[10000];
  
  while (scanf("%s", s) > 0){
    data1[i] = strdup(s);
    data2[i] = strdup(s);
    pathfinder[i] = strdup(s);
    stlpec = strlen(s);
    i++;
  }
  riadok = i;
}

int main()
{
  int i = 0;
  
  scan();

  mazeL(0, 1);
  mazeR(0,1);
  
  for(i = 0; i < riadok; i++){
    printf("%s\n",pathfinder[i]);
  }
  
  return 0;
}
