
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"

int PILE_initialiser(pile p){ /* p[0] = nombre d'élément dans la pile */

  int i, j;

  srand(time(NULL));

  p[0] = (rand() % (15 - 0 + 1)) + 0;

  for(i=1; i<=p[0]; i++){
    p[i] = (rand() % (100 - 0 + 1)) + 0;
    for(j=1; j<i; j++){
      if(p[i] == p[j]){
        i--;
      }
    }
  }
  
  return 1;

}

int PILE_empiler(int elem, pile p){

	p[p[0]+1] = elem;

	p[0] = p[0] + 1;

	return 1;

}

int PILE_estvide(pile p){

	if(p[0] == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int PILE_depiler(pile p){

	int sommet;

	sommet = p[p[0]];

	p[p[0]] = 0;

	p[0] = p[0] - 1;

	return sommet;
}

int PILE_afficher(pile p){
	int i;

	for(i=p[0]; i>=1; i--){
		printf("[%d]\n", p[i]);
	}

	return 1;
}
