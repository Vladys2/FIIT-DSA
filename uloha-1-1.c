// uloha-1-1.c -- Tyzden 1 - Uloha 1
// Peter Ocelik, 20.9.2016 18:11:47

#include <stdio.h>
#include <string.h>

int main()
{
  long int n, i, lengthS;
  char s[1000];
  
  while (scanf("%s", s) != EOF) { 
    scanf("%li",&n);
    lengthS = strlen(s);
    n = n % lengthS;
    
    for(i=n; i<lengthS; i++){
      putchar(s[i]);
    }
    for(i=0; i<n; i++){
      putchar(s[i]);
    }
    putchar('\n');
  }
  
  return 0;
}
