#include <stdio.h>
#include <stdlib.h>

typedef struct arbre
{
 char c;
 int N,code[100];
 struct arbre * FG,*FD;
}arbre;

arbre * racine = NULL;
int possible = 0;

arbre * prefixe()
{
 arbre * m;
 m=(arbre*)malloc(sizeof(arbre));
 m->FG = NULL;
 m->FD = NULL;  
 m->c = '*';
 m->N = 0; 
 return m;
}
      
arbre * valide(int N,int code[100])
{
 arbre * R = racine,*q;
 int i=1;
 //q = R; 
 while(i<=N)
 {        
  if(racine==NULL)
  {
   printf("\nRacine null");
   racine = prefixe();
   R = racine;
  }
  else
  { 
   q = R; 
   //-------------------------------
   if(code[i]==0)
   {
    printf("\nFils Gauche i = %d",i);                 
     
    if(R->FG == NULL)
     R->FG = prefixe();
    else
    {
     R = R->FG;
     if(R->c != '*')
      return NULL;
    }
   }
   //-------------------------------
   if(code[i]==1)
   {
    printf("\nFils Droit i = %d",i);  
    if(R->FD == NULL)
     R->FD = prefixe();
    else
    {
     R = R->FD;
     if(R->c != '*')
      return NULL;
    }
   }
   //-------------------------------
   i++; 
  }
 } 
 possible = 1;
 return q;   
}

void Ajouter()
{
 int i,j;
 arbre * p,*q;
 
 p=(arbre*)malloc(sizeof(arbre));
 p->FG = NULL;
 p->FD = NULL;
 printf("\nEntrer le Caracter :");
 scanf("%c",&p->c);
 scanf("%c",&p->c);
 
 printf("\nEntrer la longeur du code N :");
 scanf("%d",&p->N);
 
 printf("\nEntrer le code du Caracter :\n");
 for(i=1;i<=p->N;i++)
 {
  printf("code %d :",i);
  scanf("%d",&p->code[i]);
 }  
 
  q = valide(p->N,p->code);
  //if(q!=NULL && possible==1)
  if(q!=NULL)
  {
   printf("\n============= Insertion Possible =============\n");
   if(p->code[p->N]==0)
    q->FG = p;
   else
    q->FD = p;
  }
  else
   printf("\nInsertion Impossible !!");
}
void Affichage(arbre * racine)
{
 int i;
 //if(racine->c == '*')
 if(racine!=NULL) 
 { 
  printf("\nLe caractere est : %c\n",racine->c);
  if(racine->FG!=NULL)
   Affichage(racine->FG);
  if(racine->FD!=NULL)
   Affichage(racine->FD);
 }
 /*else
 {
  printf("\nLe caractere est : %c\n",racine->c);
  printf("Le code du Caracter est :");
  for(i=1;i<=racine->N;i++)
   printf("%d",racine->code[i]);
 }*/
 printf("\n");
}
 Supprimer_noeud(){}
 coder_chaine(){}
 decoder_chaine(){}
int main(int argc, char *argv[])
{
  int l=0;
  do
  {
   printf("     Tapper '1' pour Ajouter un noeud\n");
   printf("     Tapper '2' pour Afficher l'arbre\n");
   printf("     Tapper '3' pour Supprimer un noeud\n");
   printf("     Tapper '4' pour coder une chaine de caracteres\n");
   printf("     Tapper '5' pour décoder une chaine de caracteres\n");
   printf("     Tapper '6' pour Quiter le proggrame\n");
   scanf("%d",&l);
   switch(l) 
    {
        case 1: Ajouter();
                break;
        case 2: Affichage(racine);
                break; 
        case 3: Supprimer_noeud();
                break;
        case 4: coder_chaine();
                break;
        case 5: decoder_chaine();
                break;
        case 6: system("exit");       
        default:
                printf("Erreur de saisie\n");
    }
   system("pause");
   system("cls");
  }while(l<6&&l>0);
  return 0;
}
