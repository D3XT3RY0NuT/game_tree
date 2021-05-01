# Algoritmul MinMax pentru jocul de X și 0.
***
## Cuprins
1. [Informații generale](#informații-generale)
2. [Conținutul proiectului](#conținutul-proiectului)
3. [Tehnologii folosite](#tehnologii-folosite)
4. [Instalare și utilizare](#instalare-și-utilizare)
5. [Probleme](#probleme)

### Informații generale
***
În cadrul acestui proiect au fost implementate următoarele cerințe:
1. Generarea tuturor posibilităților de desfășurare a unei partide de X și 0 pornind de la o situație inițială dată.
2. Generarea arborelui ȘI/SAU pornind de la aceeași situație inițială dată.
3. Implementarea algoritmului MinMax pentru jocul X și 0.

### Conținutul proiectului
***
Acest proiect conține 6 fișiere sursă, un Makefile, licența de distribuire și fișierul curent README.
Fișierele sursă sunt următoarele:
1. **main.c**: fișierul ce decide ce sarcină va fi rezolvată în funcție de primul parametru dat.
2. **rezolvare_cerinte.c**: conține 3 funcții principale, pentru fiecare sarcină în parte, cât și 
alte funcții secundare ce conduc la o rezolvare corectă și completă a necesităților proiectului.
3. **rezolvare_cerinte.h**: în interiorul acestui fișier se află definițiile tuturor funcțiilor din **rezolvare_cerințe.c** care sunt apelate de alte module.
4. **utilitare.c**: un set de funcții cu utilitate ridicată și folosite de-a lungul proiectului
5. **utilitare.h**: definițiile funcțiilor din **utilitare.c**
6. **structuri.h**: fișier antet ce definește cele două structuri utilizate în proiect: arbori și cozi.

### Tehnologii folosite
***
Mediu integrat de dezvoltare: [CodeBlocks](https://www.codeblocks.org/), ver 20.03.    
Compilator: [gcc](https://gcc.gnu.org/), ver 9.3.0.    
Limbaj de programare: C.    
Sistem de versionare: [git](https://git-scm.com/), ver 2.25.1, împreună cu serviciul web de stocare [GitHub](https://github.com/)

### Instalare și utilizare
***
Pentru instalare, se descarcă dosarul **release**, iar din interiorul acestuia se rulează comanda **make** specifică fișierului **Makefile**. Se va genera un fișier binar cu denumirea de **minimax**.    
Pentru utilizare, se rulează executabilul **minimax** cu următoarele argumente:
1. Primul argument va fi **-c1**, **-c2** sau **-c3** în funcție de cerința de rezolvare dorită.
2. Al doilea argument reprezintă numele fișierului din care se vor citi datele.
3. Al treilea argument reprezintă numele fișierului în care se vor stoca rezultatele.
Pentru vizualizarea rezultatelor, este suficient să se deschidă fișierul de ieșire cu orice editor de text.

### Probleme
***
Versiunea curentă (ver 1.0) nu conține probleme cunoscute. Programul a fost testat pe Windows 10, 64 de biți și pe distribuția de Linux Ubuntu 20.04. Dacă observați orice comportament neașteptat, vă rog să-l semnalați prin intermediul acestui depozit https://github.com/D3XT3RY0NuT/game_tree.
***
Notă: Depozitul GitHub a fost publicat la data de 7 mai 2021.
