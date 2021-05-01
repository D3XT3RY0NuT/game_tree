#ifndef __UTILITARE__
#define __UTILITARE__
#include "structuri.h"

//Creaza un nod ce contine o tabla identica cu a tatalui sau
Nod *creare_nod(Nod *tata);

//Determina daca pe tabla se afla un grup de X sau de O castigator
void verificare_tabla(Nod *);

//Elibereaza memoria ocupata de arbore
void stergere_arbore(Nod *);

//Converteste un sir de caracter incojurat de parenteze in numarul corespunzator
int convertire_sir_numar(char *, int);

//Initializeaza o coada vida
Coada *initializare_coada();

//Insereaza un nod de arbore in coada
void inserare_coada(Coada *, Nod *);

//Extrage nodul din varful cozii daca exista
Nod *extragere_coada(Coada *);

//Determina minimul dintre doua numere intregi
int minim(int, int);

//Determina maximul dintre doua numere intregi
int maxim(int, int);

#endif // __UTILITARE__
