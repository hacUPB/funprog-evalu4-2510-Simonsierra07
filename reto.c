#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Estructura para guardar resultados
typedef struct {
    int totalCaracteres;
    int totalPalabras;
    int totalEspacios;
    int totalLineas;
    int frecuenciaVocales[5]; // a, e, i, o, u
} Estadisticas;

// Función para cargar archivo completo a memoria
char* cargarArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    rewind(archivo);

    char* contenido = (char*)malloc(tam + 1);
    if (!contenido) {
        perror("Error de memoria");
        fclose(archivo);
        return NULL;
    }

    fread(contenido, 1, tam, archivo);
    contenido[tam] = '\0';
    fclose(archivo);
    return contenido;
}

// Función para calcular estadísticas
Estadisticas calcularEstadisticas(const char* texto) {
    Estadisticas e = {0};
    int inPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') e.totalCaracteres++;
        if (isspace(c)) {
            if (c == ' ') e.totalEspacios++;
            if (c == '\n') e.totalLineas++;
            inPalabra = 0;
        } else {
            if (!inPalabra) {
                e.totalPalabras++;
                inPalabra = 1;
            }
        }

        switch (tolower(c)) {
            case 'a': e.frecuenciaVocales[0]++; break;
            case 'e': e.frecuenciaVocales[1]++; break;
            case 'i': e.frecuenciaVocales[2]++; break;
            case 'o': e.frecuenciaVocales[3]++; break;
            case 'u': e.frecuenciaVocales[4]++; break;
        }
    }

    e.totalLineas++; // Por la última línea sin \n
    return e;
}

// Función para reemplazar palabras
char* reemplazarPalabra(const char* texto, const char* buscar, const char* reemplazo) {
    char* resultado;
    int i, contador = 0;
    int tamBuscar = strlen(buscar);
    int tamReemplazo = strlen(reemplazo);

    // Contar ocurrencias
    for (i = 0; texto[i] != '\0'; i++) {
        if (strstr(&texto[i], buscar) == &texto[i]) {
            contador++;
            i += tamBuscar - 1;
        }
    }

    resultado = (char*)malloc(i + contador * (tamReemplazo - tamBuscar) + 1);
    if (!resultado) {
        perror("Error de memoria en reemplazo");
        return NULL;
    }

    i = 0;
    while (*texto) {
        if (strstr(texto, buscar) == texto) {
            strcpy(&resultado[i], reemplazo);
            i += tamReemplazo;
            texto += tamBuscar;
        } else {
            resultado[i++] = *texto++;
        }
    }
    resultado[i] = '\0';
    return resultado;
}

// Guardar resultados en archivo
void guardarResultados(const char* nombreArchivo, Estadisticas est, const char* texto) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (!archivo) {
        perror("Error al guardar archivo");
        return;
    }

    fprintf(archivo, "=== Estadísticas ===\n");
    fprintf(archivo, "Caracteres: %d\n", est.totalCaracteres);
    fprintf(archivo, "Palabras: %d\n", est.totalPalabras);
    fprintf(archivo, "Espacios: %d\n", est.totalEspacios);
    fprintf(archivo, "Líneas: %d\n", est.totalLineas);

    fprintf(archivo, "\n=== Frecuencia de Vocales ===\n");
    fprintf(archivo, "a: %d\n", est.frecuenciaVocales[0]);
    fprintf(archivo, "e: %d\n", est.frecuenciaVocales[1]);
    fprintf(archivo, "i: %d\n", est.frecuenciaVocales[2]);
    fprintf(archivo, "o: %d\n", est.frecuenciaVocales[3]);
    fprintf(archivo, "u: %d\n", est.frecuenciaVocales[4]);

    fprintf(archivo, "\n=== Texto Modificado ===\n");
    fprintf(archivo, "%s\n", texto);

    fclose(archivo);
    printf("Resultados guardados en '%s'.\n", nombreArchivo);
}

// Menú principal
int main() {
    char nombreArchivo[100];
    char* texto = NULL;
    Estadisticas est;
    int opcion;
    int textoModificado = 0;

    printf("Ingrese el nombre del archivo a analizar: ");
    scanf("%s", nombreArchivo);

    texto = cargarArchivo(nombreArchivo);
    if (!texto) return 1;

    char* textoOriginal = strdup(texto); // Copia de respaldo
    if (!textoOriginal) return 1;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Ver estadísticas del texto\n");
        printf("2. Ver frecuencia de vocales\n");
        printf("3. Reemplazar palabra\n");
        printf("4. Guardar resultados en archivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion) {
            case 1:
                est = calcularEstadisticas(texto);
                printf("\nCaracteres: %d\n", est.totalCaracteres);
                printf("Palabras: %d\n", est.totalPalabras);
                printf("Espacios: %d\n", est.totalEspacios);
                printf("Líneas: %d\n", est.totalLineas);
                break;
            case 2:
                est = calcularEstadisticas(texto);
                printf("\nFrecuencia de Vocales:\n");
                printf("a: %d\n", est.frecuenciaVocales[0]);
                printf("e: %d\n", est.frecuenciaVocales[1]);
                printf("i: %d\n", est.frecuenciaVocales[2]);
                printf("o: %d\n", est.frecuenciaVocales[3]);
                printf("u: %d\n", est.frecuenciaVocales[4]);
                break;
            case 3: {
                char buscar[50], reemplazo[50];
                printf("Palabra a buscar: ");
                scanf("%s", buscar);
                printf("Palabra para reemplazar: ");
                scanf("%s", reemplazo);

                char* nuevoTexto = reemplazarPalabra(texto, buscar, reemplazo);
                if (nuevoTexto) {
                    free(texto);
                    texto = nuevoTexto;
                    textoModificado = 1;
                    printf("Reemplazo realizado con éxito.\n");
                }
                break;
            }
            case 4: {
                char salida[100];
                printf("Nombre del archivo de salida: ");
                scanf("%s", salida);
                est = calcularEstadisticas(texto);
                guardarResultados(salida, est, texto);
                break;
            }
            case 5:
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != 5);

    free(texto);
    free(textoOriginal);
    return 0;
}

        