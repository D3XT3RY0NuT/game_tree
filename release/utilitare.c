#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "utilitare.h"

//Creaza un nod ce contine o tabla identica cu a tatalui sau
Nod *creare_nod(Nod *tata){
    Nod *aux = (Nod *) malloc(sizeof(Nod));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            aux->tabla[i][j] = tata->tabla[i][j];
    }
    aux->nr_fii = 0;
    aux->statut_tabla = 0;
    aux->tata = tata;

    return aux;
}

//Determina daca pe tabla se afla un grup de X sau de O castigator
void verificare_tabla(Nod *nod){
    int ok;
    for (int i = 0; i < 3; i++){
        if (nod->tabla[i][0] != '-')
            ok = 1;
        else
            ok = 0;
        if (ok){
            for (int j = 1; j < 3; j++)
                ok = ok && nod->tabla[i][0] == nod->tabla[i][j];
            if (ok){
                if (nod->tabla[i][0] == 'X')
                    nod->statut_tabla = 1;
                else
                    nod->statut_tabla = -1;
            }
        }
        if (!ok && nod->tabla[0][i] != '-'){
            ok = 1;
            for (int j = 1; j < 3; j++)
                ok = ok && nod->tabla[0][i] == nod->tabla[j][i];
            if (ok){
                if (nod->tabla[0][i] == 'X')
                    nod->statut_tabla = 1;
                else
                    nod->statut_tabla = -1;
            }
        }
    }
    if (!nod->statut_tabla){
        if (nod->tabla[0][0] != '-')
            ok = 1;
        else
            ok = 0;
        if (ok){
            for (int j = 1; j < 3; j++)
                ok = ok && nod->tabla[0][0] == nod->tabla[j][j];
            if (ok){
                if (nod->tabla[0][0] == 'X')
                    nod->statut_tabla = 1;
                else
                    nod->statut_tabla = -1;
            }
        }
        if (!ok && nod->tabla[0][2] != '-'){
            ok = 1;
            for (int j = 1; j < 3; j++)
                ok = ok && nod->tabla[0][2] == nod->tabla[j][2 - j];
            if (ok){
                if (nod->tabla[0][2] == 'X')
                    nod->statut_tabla = 1;
                else
                    nod->statut_tabla = -1;
            }
        }
    }
}

<<<<<<< Updated upstream
=======
//Elibereaza memoria ocupata de arbore
>>>>>>> Stashed changes
void stergere_arbore(Nod *radacina){
    for (int i = 0; i < radacina->nr_fii; i++)
        stergere_arbore(radacina->fii[i]);
    free(radacina);
}
<<<<<<< Updated upstream
=======

//Converteste un sir de caracter incojurat de parenteze in numarul corespunzator
int convertire_sir_numar(char *s, int l){
    int rez = 0;
    int i = 1;
    if (s[1] == '-')
        i++;
    for (; i < l - 2; i++)
        rez = rez * 10 + s[i] - '0';
    if (s[1] == '-')
        return -rez;
    return rez;
}

//Initializeaza o coada vida
Coada *initializare_coada(){
    Coada *aux = (Coada *) malloc(sizeof(Coada));
    aux->inceput = NULL;
    aux->sfarsit = NULL;

    return aux;
}

//Insereaza un nod de arbore in coada
void inserare_coada(Coada *coada, Nod *nod){
    ElemCoada *aux = (ElemCoada *) malloc(sizeof(ElemCoada));
    aux->nod = nod;
    aux->prec = NULL;
    aux->urm = coada->sfarsit;
    if (coada->sfarsit)
        coada->sfarsit->prec = aux;
    coada->sfarsit = aux;
    if (!coada->inceput)
        coada->inceput = coada->sfarsit;
}

//Extrage nodul din varful cozii daca exista
Nod *extragere_coada(Coada *coada){
    if (coada->inceput){
        Nod *aux = coada->inceput->nod;
        ElemCoada *elem = coada->inceput;
        coada->inceput = coada->inceput->prec;
        free(elem);
        if (coada->inceput)
            coada->inceput->urm = NULL;
        else
            coada->sfarsit = NULL;
        return aux;
    }
}

//Determina minimul dintre doua numere intregi
int minim(int a, int b){
    if (a < b)
        return a;
    return b;
}

//Deetermina maximul dintre doua numere intregi
int maxim(int a, int b){
    if (a > b)
        return a;
    return b;
}
>>>>>>> Stashed changes
