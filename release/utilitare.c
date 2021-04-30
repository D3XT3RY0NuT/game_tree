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
