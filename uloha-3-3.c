// uloha-3-3.c -- Tyzden 3 - Uloha 3
// Peter Ocelik, 5.10.2016 00:59:25

#include <stdio.h>
#include <stdlib.h>
#define KLADNE(n) ((n) < 0 ? 0 - (n) : (n))

typedef struct uzol {
  int cislo;
  struct uzol *lavy, *pravy;
  int hlbka;
} UZOL;

UZOL *root = NULL;

int hlbka(UZOL *N)
{
  if (N == NULL)
    return 0;
  
  return N->hlbka;
}
 
int maximum(int a, int b)
{
  return (a > b) ? a : b;
}

int minimum(int a, int b)
{
  return (a < b) ? a : b;
}
 
UZOL *novy(int cislo) 
{
  UZOL *uzol = (UZOL *)malloc(sizeof(UZOL));
  
  uzol->cislo = cislo;
  uzol->lavy = NULL;
  uzol->pravy = NULL;
  uzol->hlbka = 1;

  return(uzol);
}

UZOL *pravaRotacia(UZOL *y)
{
  UZOL *x = y->lavy;
  UZOL *T2 = x->pravy;
 
  x->pravy = y;
  y->lavy = T2;
 
  y->hlbka = maximum(hlbka(y->lavy), hlbka(y->pravy))+1;
  x->hlbka = maximum(hlbka(x->lavy), hlbka(x->pravy))+1;
 
  return x;
}
 
UZOL *lavaRotacia(UZOL *x)
{
  UZOL *y = x->pravy;
  UZOL *T2 = y->lavy;
 
  y->lavy = x;
  x->pravy = T2;

  x->hlbka = maximum(hlbka(x->lavy), hlbka(x->pravy))+1;
  y->hlbka = maximum(hlbka(y->lavy), hlbka(y->pravy))+1;

  return y;
}

int getBalance(UZOL *N)
{
  if (N == NULL)
    return 0;
  
  return hlbka(N->lavy) - hlbka(N->pravy);
}
 
UZOL* insert(UZOL* uzol, int cislo)
{

  if (uzol == NULL) {
    return(novy(cislo));
  }
 
  if (cislo < uzol->cislo)
    uzol->lavy  = insert(uzol->lavy, cislo);
  else
    uzol->pravy = insert(uzol->pravy, cislo);

  uzol->hlbka = maximum(hlbka(uzol->lavy), hlbka(uzol->pravy)) + 1;

  int balance = getBalance(uzol);
 
    // Lavy Lavy
  if (balance > 1 && cislo < uzol->lavy->cislo)
    return pravaRotacia(uzol);
 
    // Pravy Pravy
  if (balance < -1 && cislo > uzol->pravy->cislo)
    return lavaRotacia(uzol);
 
    // Lavy Pravy
  if (balance > 1 && cislo > uzol->lavy->cislo) {
    uzol->lavy =  lavaRotacia(uzol->lavy);
    return pravaRotacia(uzol);
  }
 
    // Pravy Lavy
  if (balance < -1 && cislo < uzol->pravy->cislo) {
    uzol->pravy = pravaRotacia(uzol->pravy);
    return lavaRotacia(uzol);
  }
  return uzol;
}

UZOL *min(UZOL *koren){
	while(koren->lavy != NULL) 
      koren=koren->lavy;
	return koren;
}

UZOL *max(UZOL *koren){
	while(koren->pravy != NULL) 
      koren=koren->pravy;
	return koren;
}

void pred_succ(UZOL* koren, UZOL **pre, UZOL **suc, int cislo)
{
    if (koren == NULL)  
      return;
  
  if(koren->cislo == cislo){
    if(koren->lavy){
      *pre = max(koren->lavy);
    //printf("pre %d\n",pre->cislo);
    }
    if(koren->pravy){
      *suc = min(koren->pravy);
    //printf("suc %d\n",suc->cislo);
    }
    return;
  }
  
  if(koren->cislo > cislo){
    *suc = koren;
    pred_succ(koren->lavy,pre,suc,cislo);
  }
  else{
    *pre = koren;
    pred_succ(koren->pravy,pre,suc,cislo);
  }
  
 
}

UZOL* search(UZOL* p, int cislo)
{
  if (!p)
    return NULL;

  if (cislo < p->cislo)
    return search(p->lavy, cislo);
  else if (cislo > p->cislo)
    return search(p->pravy, cislo);
    else {
    return p; 
  }
}

int main()
{
  long int n;
  
  while(scanf("%li", &n) != EOF){
    if(search(root,n) == NULL){
      root = insert(root, n);
    }
    UZOL* pre = NULL, *suc = NULL;
      pred_succ(root, &pre, &suc, n);
    /*
    printf("cislo %d\n",n);
    if(pre!=NULL)
      printf("pre %d\n",pre->cislo);
    else
      printf("NO PREDECESSOR\n");
 
    if(suc!=NULL)
      printf("suc %d\n",suc->cislo);
    else
      printf("NO SUCCESSOR\n");
    */
    if(pre == NULL && suc == NULL)
      printf("-1\n");
    else if(pre != NULL && suc != NULL){
      if(KLADNE(pre->cislo - n) < KLADNE(suc->cislo - n))
        printf("%d\n",pre->cislo);
      else if(KLADNE(pre->cislo - n) > KLADNE(suc->cislo - n))
        printf("%d\n",suc->cislo);
        else
        printf("%d\n",minimum(pre->cislo,suc->cislo));
    }
      else if(pre!=NULL && suc == NULL)
        printf("%d\n",pre->cislo);
      else
        printf("%d\n",suc->cislo);
  }

  return 0;
}
