#include "BenimFonksiyonlarim.h"

int SecimKontrol(char input[], int a, int b){
    int temp;
    char* cp;
    temp = strtol(input, &cp, 10);
    while(1){
        if(temp >= a && temp <= b){
            if(*cp == '\0'){
                return temp;
                break;
            }
            else{
                printf("Boyle bir secenek bulunmamaktadir!Lutfen seciminizi tekrar yapiniz: ");
                scanf("%s",input);
                temp = strtol(input, &cp, 10);
            }
        }
        else{
            printf("Boyle bir secenek bulunmamaktadir!Lutfen seciminizi tekrar yapiniz: ");
            scanf("%s",input);
            temp = strtol(input, &cp, 10);
        }
    }
}
