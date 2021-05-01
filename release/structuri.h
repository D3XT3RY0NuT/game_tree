#ifndef __STRUCTURI__
#define __STRUCTURI__
#define NR_MAX_FII 100 //Numarul maxim de fii ai unui nod
#define L_MAX 20 //Lungimea maxima a unei celule cu informatii din cadrul celei de a treia cerinte

//Structura de arbore pentru primele doua cerinte
typedef struct Nod{
    char tabla[3][3]; //Tabla de X si O
    int nr_fii; //Numarul de noduri fii
    int statut_tabla; //Ia valoarea 1 daca X castiga, -1 daca O castiga sau 0 in toate celalte cazuri
    int val; //Ia valoarea 1(T) sau 0(F) pentru cerinta a doua sau orice valoarea intreaga pentru a treia
    struct Nod *fii[NR_MAX_FII], *tata;
}Nod;

typedef struct ElemCoada{
    Nod *nod;
    struct Coada *urm, *prec;
}ElemCoada;

typedef struct Coada{
    ElemCoada *inceput, *sfarsit;
}Coada;

#endif // __STRUCTURI__
