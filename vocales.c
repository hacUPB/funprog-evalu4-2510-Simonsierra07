#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (int argc, char const *argv[])
{
char frase [100];
int contador = 0;
char letra;
//Pedimos al usuario que ingrese una frase
printf("Ingrese una frase: \n");
fgets(frase, sizeof(frase), stdin);
printf ("%s\n", frase);
for (int i=0; i< strlen(frase;) i++)
{
    letra = tolower(frase[i]);
    if (letra == 'a' || letra == 'e' || letra 'i'|| letra 'o'|| letra 'u')
    {
        contador++;
    }
}
printf("En la frase hay %d vocales\n", contador);
return 0;
}