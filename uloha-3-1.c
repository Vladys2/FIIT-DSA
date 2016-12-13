// uloha-3-1.c -- Tyzden 3 - Uloha 1
// Peter Ocelik, 4.10.2016 13:55:59

#include<stdlib.h>
#include<stdio.h>

struct bin_strom{
  int data;
  struct bin_strom *pravy, *lavy;
};
typedef struct bin_strom uzol;

void vloz(uzol ** strom, int x)
{
  uzol *temp = NULL;
  if(!(*strom)){
    temp = (uzol *)malloc(sizeof(uzol));
    temp->lavy = temp->pravy = NULL;
    temp->data = x;
    *strom = temp;
    return;
  }

  if(x < (*strom)->data){
    vloz(&(*strom)->lavy, x);
  }
  else if(x > (*strom)->data){
    vloz(&(*strom)->pravy, x);
  }
}

int hladaj(uzol *uzol, int data, int level)
{
  int nizsie;
  if (uzol == NULL)
    return 0;
 
  if(uzol->data == data)
    return level;
 
  nizsie = hladaj(uzol->lavy, data, level+1);
  if (nizsie != 0)
    return nizsie;
 
  nizsie = hladaj(uzol->pravy, data, level+1);
  return nizsie;
}
 
int getHlbka(uzol *uzol, int data)
{
    return hladaj(uzol, data, 1);
}

int main()
{
  uzol *root;
  int x, hlbka;
  root = NULL;
  
  while(scanf("%d", &x) != EOF){
    hlbka = getHlbka(root, x);
    if(hlbka)
      printf("%d\n",getHlbka(root, x)-1);
    else{
      vloz(&root, x);
      printf("%d\n",getHlbka(root, x)-1);
    }
  }
  
  return 0;
}