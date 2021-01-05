
#ifndef AFN_H
#define AFN_H

#include "ensemble.h"

#define NB_ETATS_MAX 10
#define TAILLE_ALPHABET 2

typedef struct afn_t{
  ensemble final;
  ensemble initial;
  ensemble trans[NB_ETATS_MAX][TAILLE_ALPHABET];
}afn_t;
typedef struct afn_t* afn;


afn AFN_initialiser(void);

int AFN_rendre_final(int e, afn a);

int AFN_rendre_initial(int e, afn a);

int AFN_ajouter_transition(int p, char x, int r, afn a);

int AFN_afficher(afn a);

int AFN_analyser_mot(char *mot, afn a);

int AFN_determiniser(afn a, afn r);

#endif
