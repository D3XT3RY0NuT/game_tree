#ifndef __STRUCTURI__
#define __STRUCTURI__
#define NR_MAX_FII 100

typedef struct Nod{
    char tabla[3][3];
    int nr_fii, statut_tabla;
    struct Nod *fii[NR_MAX_FII], *tata;
}Nod;

#endif // __STRUCTURI__
