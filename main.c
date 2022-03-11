//Program by cybulsky
#include "rome.h" 
#include <stdio.h>
#include <stdlib.h>

void write_usage() {
        printf("Program zamienia liczby rzymskie na dziesiętne i dziesiętne na rzymskie\n"
                "Wywołanie programu:\n"
                "<nazwa> <tryb> <liczba>\n"
                "Tryby:\n"
                "0 - dziesiętne na rzymskie\n"
                "1 - rzymskie na dziesiętne\n"
                "Należy pamiętać, że liczba rzymska liczba naturalna, która nie może być większa niż 3999\n");
}

int main (int argc, char **argv) {
        if(argc == 3) {
                int tryb = atoi(argv[1]);
                if(tryb == 1){
                        printf("%s: Pracuje w trybie rzymskie na dziesiętne\n", argv[0]);
                        printf("%d\n",ToDecimal(argv[2]));
                }
                else if (tryb == 0) {
                        if((atoi(argv[2]) > 3999) || ((atoi(argv[2] )< 0))) {
                                write_usage();
                                printf("%s: Liczba %s to liczba proza zakresu\n",argv[0], argv[2]);
                                return EXIT_FAILURE;     
                        }
                        else 
                        {
                                printf("%s: Pracuje w trybie dziesiętne na rzymskie\n", argv[0]);
                                printf("%s\n",ToRome(atoi(argv[2])));
                        }
                }
                else {
                        write_usage();
                        fprintf(stderr,"%s: Nieznany tryb.\nTryb: %d.\nDopuszczalne tryby: 0 i 1\n", argv[0], tryb);
                        return EXIT_FAILURE;
                }
        }       
        else {
                write_usage();
                fprintf(stderr,"%s: Zła ilość argumentów wywołania. Podano %d\n", argv[0], argc);
                return EXIT_FAILURE;
        }       
        return EXIT_SUCCESS;
}
