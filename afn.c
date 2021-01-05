
#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "afn.h"
#include <string.h>

afn AFN_initialiser(){
  int i, j;
  afn n;
  n = (afn)malloc(sizeof(afn_t));
  ENS_initialiser(n->final);
  ENS_initialiser(n->initial);
  for(i=0; i<NB_ETATS_MAX; i++){
    for(j=0; j<TAILLE_ALPHABET; j++){
      ENS_initialiser(n->trans[i][j]);
    }
  }
  return n;
}

int AFN_rendre_final(int e, afn a){

  int retour;
  

  retour = ENS_ajouter(e, a->final);

  return retour;
  
}


int AFN_rendre_initial(int e, afn a){

  int retour;
  

  retour = ENS_ajouter(e, a->initial);

  return retour;

}


int AFN_ajouter_transition(int p, char x, int r, afn a){

  if(x == 'a'){
    
    ENS_ajouter(r, a->trans[p][1]);

    return 1;

  }
  else if(x == 'b'){

    ENS_ajouter(r, a->trans[p][2]);

  }

  else{

    ENS_ajouter('%', a->trans[p][2]);
    ENS_ajouter('%', a->trans[p][2]);

  }

  return 1;

}


int AFN_afficher(afn a){

  int i, j;
  int ptf = 1;
  int k;

  printf("Etats initiaux : ");
  for(i=1; i<=a->initial[0]; i++){
    printf("[%d]", a->initial[i]);
  }
  printf("\n\n");

  printf("Etats finaux : ");
  for(i=1; i<=a->final[0]; i++){
    printf("[%d]", a->final[i]);
  }
  printf("\n\n");

  printf("Transition(s) :\n\n");


  printf("       a        b\n", ptf);

  i = 1;

  while(!ENS_estvide(a->trans[i][1])){

    i++;

  }

  for(k=1; k < i; k++){
    printf("{%d} ", ptf);
    for(j=1; j<=2; j++){
      ENS_afficher(a->trans[k][j]);
    }
    printf("\n", ptf);
    ptf++;
  }

  return 1;

}


int AFN_analyser_mot(char *mot, afn a){

  int lg = strlen(mot);
  int i = 0;
  int j;
  int lettre;

  int etat_courant;

  char symb_courant;

  etat_courant = a->initial[1];

  symb_courant = mot[i];

  if(symb_courant == 'a'){

    lettre = 1;

  }
  if(symb_courant == 'b'){

    lettre = 2;

  }

  do{

    if(i == lg && symb_courant == mot[i] && ENS_appartient(etat_courant, a->final)){

      return 1;

    }
    else if(i == lg && symb_courant != mot[i] || !ENS_appartient(etat_courant, a->final)){

      return 0;

    }

    for(j=0; j<MAX; j++){    

      if(ENS_appartient(j, a->trans[etat_courant][lettre])){

	etat_courant = j;

	i++;

	symb_courant = mot[i];   

      }
      else{

	return 0;

      }


    }


  }while(i > lg);

}

