// uloha-4-2.c -- Tyzden 4 - Uloha 2
// Peter Ocelik, 10.10.2016 15:39:35

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_TO_INDEX(c) ((int)c - (int)'A')

typedef struct node{
  struct node *child[26];
}NODE;

NODE *getnode()
{
  NODE *node = (NODE *)malloc(sizeof(NODE));
  int i;
  
  for (i = 0; i < 26; i++)
    node->child[i] = NULL;
  return node;
}

void insert(NODE *root,char *key, int *prefix)
{
  NODE *t = root;
  int l = strlen(key);
  int index, i, pocet = 0;
  
  for (i = 0; i < l; i++){
    index = CHAR_TO_INDEX(key[i]);
    if (t->child[index] == NULL) {
      t->child[index] = getnode();
    }
    else{
      pocet++;
    }
    t = t->child[index];
  }
  if(pocet > *prefix){
    *prefix = pocet;
  }
  
}

int main()
{
  char x[20];
  int i;
  int prefix = 0;
  NODE *root = (NODE *)malloc(sizeof(NODE));
 
  for(i = 0; i < 26; i++){
    root->child[i] = NULL;
  }

  while (scanf("%s", x) > 0){
    insert(root, x, &prefix);
  }
  printf("%d\n", prefix);
  
  return 0;
}
