

#define MAX 20

typedef int ensemble[MAX];

int ENS_initialiser(ensemble e);

int ENS_ajouter(int elem, ensemble e);

int ENS_appartient(int elem, ensemble e);

int ENS_estvide(ensemble e);

int ENS_afficher(ensemble e);

int ENS_retirer_un_element(ensemble e);

int ENS_ajouter_les_elements_de(ensemble s, ensemble d);

int ENS_affecter(ensemble s, ensemble d);

int ENS_intersection(ensemble a, ensemble b, ensemble r);

int ENS_union(ensemble a, ensemble b, ensemble r);

int ENS_egal(ensemble a, ensemble b);

