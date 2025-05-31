#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char Nombre[30];
    int edad;
    FILE *p_archivo;
    p_archivo = fopen("Texto1.txt", "w");
    fprintf(stdout,"Ingrese su nombre:\n");
    fgets(Nombre, sizeof(Nombre), stdin);
    Nombre[strlen(Nombre) - 1] = '\0';
    fprintf(stdout, "cuantos años tienes:\n");
    scanf("%d", &edad);
    if (p_archivo != NULL){
        printf("se crea el erchivo.\n");
// Escribir una cadena de caracteres
        fprintf(p_archivo,"Este es el texto de prueba del archivo Texto1.txt\n");
// Escribir texto y variables
        fprintf(p_archivo,"Hola %s bienvenido al curso\n", Nombre);
// Escribir variable tipo int
        fprintf(p_archivo,"Edad = %d\n", edad);
    }

    fclose(p_archivo);
return 0;
}
