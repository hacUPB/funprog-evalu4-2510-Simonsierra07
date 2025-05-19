#include <stdio.h>
#include <stdlib.h>
 
int main(void){
/*
Preguntaral usuario cuantas letras tiene su nombre y apellido
Reservamos memoria para almacenar esos datos (malloc)
Le pedimos al usuario que ingrese su nombre y apellidos
 y lo imprimimos en pantalla con un saludo adicional
*/
int apellido_p, nombre_p;
char *nombre, *apellido;

printf("¿Cuántas letras tiene tu nombre? ");
scanf("%d", &nombre_p);

printf("¿Cuántas letras tiene tu apellido? ");
scanf("%d", &apellido_p);

nombre = (char *)malloc((nombre_p + 1) * sizeof(char));
apellido = (char *)malloc((apellido_p + 1) * sizeof(char));

printf("Ingresa tu nombre");
    scanf("%s", nombre);

    printf("Ingresa tu apellido");
    scanf("%s", apellido);

    printf("¡Hola, %s %s!\n", nombre, apellido);

    free(nombre);
    free(apellido);

    return 0;
}
 