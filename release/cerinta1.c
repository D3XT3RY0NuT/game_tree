#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "cerinta1.h"
#include "utilitare.h"

void citire(char *fisier_intrare, char *jucator, Nod *radacina){
    FILE *f_in = fopen(fisier_intrare, "r");
    if (!f_in){
        printf("Fisierul de intrare nu a putut fi deschis!\n");
        return;
    }
    char c;
    *jucator = fgetc(f_in);
    c = fgetc(f_in);
    for (int i = 0; i < 9; i++){
        c = fgetc(f_in);
        radacina->tabla[i / 3][i % 3] = c;
        c = fgetc(f_in);
    }
    fclose(f_in);
}

void generare_arbore_joc(Nod *radacina, char jucator){
    if (radacina->statut_tabla)
        return;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (radacina->tabla[i][j] == '-'){
                radacina->fii[radacina->nr_fii] = creare_nod(radacina);
                radacina->fii[radacina->nr_fii]->tabla[i][j] = jucator;
                verificare_tabla(radacina->fii[radacina->nr_fii++]);
            }
        }
    }
    if (jucator == 'X')
        jucator = 'O';
    else
        jucator = 'X';
    for (int i = 0; i < radacina->nr_fii; i++)
        generare_arbore_joc(radacina->fii[i], jucator);
}

void afisare_arbore_joc(FILE *f_out, Nod *radacina, int nivel){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < nivel; j++)
            fprintf(f_out, "\t");
        for (int j = 0; j < 2; j++)
            fprintf(f_out, "%c ", radacina->tabla[i][j]);
        fprintf(f_out, "%c\n", radacina->tabla[i][2]);
    }
    fprintf(f_out, "\n");
    for (int i = 0; i < radacina->nr_fii; i++)
        afisare_arbore_joc(f_out, radacina->fii[i], nivel + 1);
}

void rezolvare_cerinta1(char *fisier_intrare, char *fisier_iesire){
    Nod *radacina = (Nod *) malloc(sizeof(Nod));
    radacina->tata = NULL;
    radacina->nr_fii = 0;
    radacina->statut_tabla = 0;
    char jucator;
    citire(fisier_intrare, &jucator, radacina);
    verificare_tabla(radacina);
    generare_arbore_joc(radacina, jucator);

    FILE *f_out = fopen(fisier_iesire, "w");
    if (!f_out){
        printf("Eroare la crearea fisierului de iesire.\n");
        return;
    }
    afisare_arbore_joc(f_out, radacina, 0);
    fclose(f_out);
}

void generare_arbore_SI_SAU(Nod *radacina, char jucator, int nivel){
    for (int i = 0; i < radacina->nr_fii; i++)
        generare_arbore_SI_SAU(radacina->fii[i], jucator, nivel + 1);
    if (radacina->nr_fii){
        if (nivel % 2){
            int aux = radacina->fii[0]->adevar;
            for (int i = 1; i < radacina->nr_fii; i++)
                aux = aux && radacina->fii[i]->adevar;
            radacina->adevar = aux;
        }
        else{
            int aux = radacina->fii[0]->adevar;
            for (int i = 1; i < radacina->nr_fii; i++)
                aux = aux || radacina->fii[i]->adevar;
            radacina->adevar = aux;
        }
    }
    else{
        if (jucator == 'X' && radacina->statut_tabla == 1)
            radacina->adevar = 1;
        else if (jucator == 'O' && radacina->statut_tabla == -1)
            radacina->adevar = 1;
        else
            radacina->adevar = 0;
    }
}

void afisare_arbore_SI_SAU(FILE *f_out, Nod *radacina, int nivel){
    for (int i = 0; i < nivel; i++)
        fprintf(f_out, "\t");
    if (radacina->adevar == 1)
        fprintf(f_out, "T\n");
    else
        fprintf(f_out, "F\n");
    for (int i = 0; i < radacina->nr_fii; i++)
        afisare_arbore_SI_SAU(f_out, radacina->fii[i], nivel + 1);
}

void rezolvare_cerinta2(char *fisier_intrare, char *fisier_iesire){
    Nod *radacina = (Nod *) malloc(sizeof(Nod));
    radacina->tata = NULL;
    radacina->nr_fii = 0;
    radacina->statut_tabla = 0;
    char jucator;
    citire(fisier_intrare, &jucator, radacina);
    verificare_tabla(radacina);
    generare_arbore_joc(radacina, jucator);
    generare_arbore_SI_SAU(radacina, jucator, 0);

    FILE *f_out = fopen(fisier_iesire, "w");
    if (!f_out){
        printf("Eroare la crearea fisierului de iesire.\n");
        return;
    }
    afisare_arbore_SI_SAU(f_out, radacina, 0);
    stergere_arbore(radacina);
    fclose(f_out);
}
