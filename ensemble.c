
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ensemble.h"

int ENS_initialiser(ensemble e){ /* e[0] = Nombre d'élément */

  int i, j;

  srand(time(NULL));

  e[0] = 0;

  for(i=1; i<=MAX-1; i++){
    e[i] = 0;
  }
  
  return 1;

}

int ENS_ajouter(int elem, ensemble e){

  int taille = e[0];
  int present = 0;
  int i;

  for(i=1; i<=e[0]; i++){
    if(e[i] == elem){
      present = 1;
    }
  }

  if(!present){
    
  e[taille+1] = elem;

  e[0] = taille + 1;

  return 1;
  }
  
  else{
    return 0;
  }

}

int ENS_appartient(int elem, ensemble e){

  int i;

  for(i=1; i<e[0]; i++){
    if(e[i] == elem){
      return 1;
    }  
  }

  return 0;
}

int ENS_estvide(ensemble e){

  if(e[0] == 0){
    return 1;
  }
  else{
    return 0;
  }
}

int ENS_afficher(ensemble e){

  int i;

  printf("| {");

  for(i=1; i<=e[0]; i++){
    printf(" %d,", e[i]);
  }
  printf("} ");

  return 1;
}

int ENS_retirer_un_element(ensemble e){ /* Retire l'élément n°2 */

  int i, tmp, tmp2;

  tmp = e[e[0]];

  if(e[0] >= 2){

    tmp2 = e[2];

    for(i=2; i<e[0]-1; i++){
      e[i] = e[i+1];
    }

    e[0] = e[0] - 1;

    e[e[0]] = tmp;
    
    return tmp2;

  }
  else{
    return -1;
  }
}

int ENS_ajouter_les_elements_de(ensemble s, ensemble d){

  int i, j, nb, tmp, present;

  int tampon[d[0]+s[0]+1];

  nb = 0;

  for(i=1; i<=d[0]; i++){
    tampon[i] = d[i];
    nb++;
  }

  for(j=1; j<=s[0]; j++){
    for(i=0; i<=d[0]; i++){
      if(s[j] == d[i]){
	present = 1;
	j++;
      }

      if(s[j] != d[i]){
	present = 0;
	tmp = s[j];
      }
    }

    if(!present){
      nb++;
      tampon[nb] = tmp;
    }
  }

  tampon[0] = nb;

  for(i=0; i<=nb+1; i++){
    d[i] = tampon[i];
  }

  return 1;

}

int ENS_affecter(ensemble s, ensemble d){

  int i;

  for(i=0; i<d[0]-1; i++){

    s[i] = d[i];

  }

  return 1;

}

int ENS_intersection(ensemble a, ensemble b, ensemble r){

  int i, j, nbr;

  nbr = 0;

  for(i=1; i<=a[0]; i++){
    for(j=1; j<=b[0]; j++){
      if(a[i] == b[j]){
	     nbr++;
	     r[nbr] = a[i];
      }
    }
  }

  r[0] = nbr;

  return 1;

}

int ENS_union(ensemble a, ensemble b, ensemble r){

  int i, j, nbr;

  nbr = 0;

  for(i=1; i<=a[0]; i++){
    nbr++;
    r[nbr] = a[i];
  }

  for(i=1; i<=b[0]; i++){
    for(j=1; j<=nbr; j++){
      if(b[i] != r[j]){
	nbr++;
	r[nbr] = b[i];
      }
    }
  }

  r[0] = nbr;

  return 1;

}

int ENS_egal(ensemble a, ensemble b){

  int i, j, nbr;

  if(a[0] == b[0]){
    for(i=1; i<=a[0]; i++){
      for(j=1; j<=b[0]; j++){
	if(a[i] == b[i]){
	  nbr++;
	}
      }
    }
  }
  else{
    return 0;
  }

  if(nbr == a[0]){
    return 1;
  }
  else{
    return 0;
  }
}



				       
