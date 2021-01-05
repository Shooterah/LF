
#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "pile.h"
#include "afn.h"


void test_ensemble(){

  int retour;
  ensemble e1, e2, e3, e4;

  retour = ENS_initialiser(e1);

  retour = ENS_ajouter(2, e1);

  retour = ENS_ajouter(4, e1);

  retour = ENS_ajouter(2, e1);

  retour = ENS_ajouter(6, e1);

  retour = ENS_ajouter(1, e1);

  printf("\n Initialiser e1 : %d\n\n", retour);

  retour = ENS_afficher(e1);

  printf("\n Afficher e1 : %d\n\n", retour);

  retour = ENS_ajouter(22, e1);

  printf("\n Ajouter 22 a e1 : %d\n\n", retour);

  retour = ENS_afficher(e1);

  retour = ENS_appartient(16, e1);

  printf("\n 16 Appartient a e1 : %d\n\n", retour);

  retour = ENS_estvide(e1);

  printf("\n e1 Est vide : %d\n\n", retour);

  retour = ENS_retirer_un_element(e1);

  printf("\n Retirer 2ème élément de e1 : %d\n\n", retour);

  retour = ENS_afficher(e1);

  retour = ENS_initialiser(e2);

  printf("\n e1 suivis de e2 :\n\n");

  retour = ENS_afficher(e1);

  printf("\n");

  retour = ENS_afficher(e2);

  retour = ENS_ajouter_les_elements_de(e1, e2);

  printf("\n Ajouter e a e2 : %d\n\n", retour);

  printf("\n Affichage de e2 : \n\n");

  retour = ENS_afficher(e2);

  retour = ENS_affecter(e1, e2);

  printf("\n Affectation de e1 dans e2 : %d\n\n", retour);

  printf("\n Affichage de e2 :\n\n");

  retour = ENS_afficher(e2);

  retour = ENS_initialiser(e3);

  printf("\n Initialiser e3 : %d\n\n", retour);

  printf("\n Affichage de e3 :\n\n");

  retour = ENS_afficher(e3);

  retour = ENS_intersection(e1, e3, e4);

  printf("\n e1 inter e3 : %d\n\n", retour);

  printf("\n Affichage de e4 (e1 inter e3) :\n\n");

  retour = ENS_afficher(e4);

  printf("\n");
}

void test_pile(){

  int retour;
  pile p1;

  retour = PILE_initialiser(p1);

  printf("\nInitialisation de la Pile : %d\n\n", retour);

  printf("\n Affichage de la pile p1 :\n\n");

  retour = PILE_afficher(p1);

  retour = PILE_depiler(p1);

  printf("\n On retire le sommet de p1 qui est : %d\n\n", retour);

  retour = PILE_afficher(p1);

  retour = PILE_estvide(p1);

  printf("\n La pile p1 est-elle vide ? (0 = non // 1 = oui) : %d\n\n", retour);

  retour = PILE_empiler(20, p1);

  printf("\n On empile 20 sur p1 :\n\n");

  printf("\n Affichage de la pile p1 :\n\n");

  retour = PILE_afficher(p1);

}


void test_afn(){

  afn hello;
  int retour;

  hello = AFN_initialiser();

  retour = AFN_rendre_initial(1, hello);

  retour = AFN_rendre_final(3, hello);

  retour = AFN_ajouter_transition(1, 'a', 1, hello);

  retour = AFN_ajouter_transition(1, 'b', 1, hello);

  retour = AFN_ajouter_transition(1, 'b', 2, hello);

  retour = AFN_ajouter_transition(2, 'a', 3, hello);

  retour = AFN_ajouter_transition(3, 'a', 3, hello);

  retour = AFN_ajouter_transition(3, 'b', 3, hello);

  printf("\n\n");

  AFN_afficher(hello);

  retour = AFN_analyser_mot("aba", hello);

  if(retour == 1){
    printf("\nOui le mot est reconnu\n");
  }
  else{
    printf("\nNon le mot n'est pas reconnu\n");
  }

}

int main(){

  /*test_ensemble();*/

  /*test_pile();*/

  test_afn();

  return 0;
  
}

