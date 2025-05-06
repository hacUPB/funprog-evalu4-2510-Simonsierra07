#include <stdio.h>


int main(int argc, char const *argv[])
{
   
    FILE *pfile;
    int letra = 1;
    char caracter;
    pfile = fopen("Texto2.txt", "a");
    if (pfile) // NULL es falso, cualquier valor diferente es verdadero
    {
        while(letra != '?')
        {
            caracter = fgetc(stdin);
            
           letra = fputc(caracter, pfile);
        }
    }

fclose (pfile);
    return 0;
}