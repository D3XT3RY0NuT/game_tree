#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"
#include "rezolvare_cerinte.h"
#include "utilitare.h"

//Functia de citire a tablei initiale pentru cerintele 1 si 2
void citire_tabla(char *fisier_intrare, char *jucator, Nod *radacina){
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

//Generarea arborelui de joc pentru prima cerinta
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

//Afiseaza arborele de joc pentru prima cerinta
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

//Rezolvarea primei cerinte
void rezolvare_cerinta1(char *fisier_intrare, char *fisier_iesire){
    Nod *radacina = (Nod *) malloc(sizeof(Nod));
    radacina->tata = NULL;
    radacina->nr_fii = 0;
    radacina->statut_tabla = 0;
    char jucator;
    citire_tabla(fisier_intrare, &jucator, radacina);
    verificare_tabla(radacina);
    generare_arbore_joc(radacina, jucator);

    FILE *f_out = fopen(fisier_iesire, "w");
    if (!f_out){
        printf("Eroare la crearea fisierului de iesire.\n");
        return;
    }
    afisare_arbore_joc(f_out, radacina, 0);
    stergere_arbore(radacina);
    fclose(f_out);
}

//Generarea arborelui SI/SAU
void generare_arbore_SI_SAU(Nod *radacina, char jucator, int nivel){
    for (int i = 0; i < radacina->nr_fii; i++)
        generare_arbore_SI_SAU(radacina->fii[i], jucator, nivel + 1);
    if (radacina->nr_fii){
        int aux = radacina->fii[0]->val;
        if (nivel % 2){
            for (int i = 1; i < radacina->nr_fii; i++)
                aux = aux && radacina->fii[i]->val;
        }
        else{
            for (int i = 1; i < radacina->nr_fii; i++)
                aux = aux || radacina->fii[i]->val;
        }
        radacina->val = aux;
    }
    else{
        if (jucator == 'X' && radacina->statut_tabla == 1)
            radacina->val = 1;
        else if (jucator == 'O' && radacina->statut_tabla == -1)
            radacina->val = 1;
        else
            radacina->val = 0;
    }
}

//Afisarea arborelui SI/SAU
void afisare_arbore_SI_SAU(FILE *f_out, Nod *radacina, int nivel){
    for (int i = 0; i < nivel; i++)
        fprintf(f_out, "\t");
    if (radacina->val == 1)
        fprintf(f_out, "T\n");
    else
        fprintf(f_out, "F\n");
    for (int i = 0; i < radacina->nr_fii; i++)
        afisare_arbore_SI_SAU(f_out, radacina->fii[i], nivel + 1);
}

//Rezolvarea celei de a doua cerinte
void rezolvare_cerinta2(char *fisier_intrare, char *fisier_iesire){
    Nod *radacina = (Nod *) malloc(sizeof(Nod));
    radacina->tata = NULL;
    radacina->nr_fii = 0;
    radacina->statut_tabla = 0;
    char jucator;
    citire_tabla(fisier_intrare, &jucator, radacina);
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

void citire_nod(FILE *f_in, Nod *nod, Coada *coada){
    char s[L_MAX];
    int l = 0; //Lungimea lui s
    char c = fgetc(f_in);
    while(c != ' ' && c != '\n'){
        s[l++] = c;
        c = fgetc(f_in);
    }
    s[l++] = '\0';
    int x = convertire_sir_numar(s, l);
    printf("%s %d\n", s, x);
    if (s[0] == '('){
        nod->nr_fii = x;
        for (int i = 0; i < nod->nr_fii; i++){
            nod->fii[i] = creare_nod(nod);
            inserare_coada(coada, nod->fii[i]);
        }
    }
    else
        nod->val = x;
}

void generare_arbore_min_max(Nod *radacina, int nivel){
    for (int i = 0; i < radacina->nr_fii; i++)
        generare_arbore_min_max(radacina->fii[i], nivel + 1);
    if (radacina->nr_fii){
        radacina->val = radacina->fii[0]->val;
        if (nivel % 2){
            for (int i = 1; i < radacina->nr_fii; i++)
                radacina->val = minim(radacina->val, radacina->fii[i]->val);
        }
        else{
            for (int i = 1; i < radacina->nr_fii; i++)
                radacina->val = maxim(radacina->val, radacina->fii[i]->val);
        }
    }
}

void afisare_arbore_min_max(FILE *f_out, Nod *radacina, int nivel){
    for (int i = 0; i < nivel; i++)
        fprintf(f_out, "\t");
    fprintf(f_out, "%d\n", radacina->val);
    for (int i = 0; i < radacina->nr_fii; i++)
        afisare_arbore_min_max(f_out, radacina->fii[i], nivel + 1);
}

void rezolvare_cerinta3(char *fisier_intrare, char *fisier_iesire){
    FILE *f_in = fopen(fisier_intrare, "r");
    if (!f_in){
        printf("Fisierul de intrare nu a putut fi deschis.\n");
        return;
    }
    int N;
    fscanf(f_in, "%d", &N);
    fgetc(f_in);
    Nod *radacina = (Nod *) malloc(sizeof(Nod));
    Coada *coada = initializare_coada();
    inserare_coada(coada, radacina);
    Nod *aux;
    while(coada->inceput){
        aux = extragere_coada(coada);
        citire_nod(f_in, aux, coada);
    }
    fclose(f_in);

    generare_arbore_min_max(radacina, 0);
    FILE *f_out = fopen(fisier_iesire, "w");
    if (!f_out){
        printf("Fisierul de iesire nu a putut fi creat.\n");
        return;
    }
    afisare_arbore_min_max(f_out, radacina, 0);
    stergere_arbore(radacina);
    fclose(f_out);
}
