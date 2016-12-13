// uloha-11-1.c -- Tyzden 11 - Uloha 1
// Peter Ocelik, 28.11.2016 12:45:05

#include <stdio.h>
#include <stdlib.h>

typedef struct suradnice{
  double x;
  double y;
}SURADNICE;

int pnpoly(int vert, SURADNICE *ss, double xx, double yy)
{
  int i, j, c = 0;
  for (i = 0, j = vert-1; i < vert; j = i++) {
    if ( ((ss[i].y >= yy) != (ss[j].y >= yy)) &&
     (xx <= (ss[j].x-ss[i].x) * (yy-ss[i].y) / (ss[j].y-ss[i].y) + ss[i].x) )
       c = !c;
  }
  return c;
}


int main()
{
  int n, i;
  
  while (scanf("%d", &n) > 0){

    SURADNICE *s = (SURADNICE *)malloc(n*sizeof(SURADNICE));
    for(i=0; i<n; i++){
      scanf("%lf %lf", &s[i].x, &s[i].y);
    }

    double a = 0;
    int i1 = 1;
    for(i=0; i<n; i++){
      a += s[i].x*s[i1].y - s[i1].x*s[i].y;
      i1 = (i1 + 1) % n;
    }
    a *= 0.5;
  
    i1 = 1;
    double x = 0.0, y = 0.0, t;
    for (i=0; i<n; i++) {
      t = s[i].x*s[i1].y - s[i1].x*s[i].y;
      x += (s[i].x+s[i1].x) * t;
      y += (s[i].y+s[i1].y) * t;
      i1 = (i1 + 1) % n;
    }
    x = x / (6.0 * a);
    y = y / (6.0 * a);

    printf("%.3lf %.3lf ", x, y);

    if(pnpoly(n, s, x, y))
      printf("IN\n");
    else printf("OUT\n");
}
  return 0;
}
