#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< Updated upstream
=======
#include "utilitare.h"
#include "rezolvare_cerinte.h"
>>>>>>> Stashed changes

int main(int argc, char *argv[])
{
    if (!strcmp("-c1", argv[1])){
        rezolvare_cerinta1(argv[2], argv[3]);
    }
    else if (!strcmp("-c2", argv[1])){
        //Rezolva cerinta 2
    }
    else if (!strcmp("-c3", argv[1])){
        rezolvare_cerinta3(argv[2], argv[3]);
    }
    else
        printf("Cerinta a fost incorect specificata!\n");

    return 0;
}
