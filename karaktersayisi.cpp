#include <stdio.h>

int main ()
{
    int i = 0, karakter = 0;
    char cumle[200];
    printf("Bir cumle giriniz.\n");
    gets(cumle);

    for( i = 0; cumle[i]!='\0' ; i++)
    {

        if (cumle[i] != ' ') /*i bo�luk dan farkl� ise karakteri bir att�r */
            karakter++;
    }

    printf("Girilen Karakter Sayisi: %d", karakter);

    return 0;
}
