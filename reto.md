
 1. **Explicación del análisis del problema**

El problema consiste en desarrollar un programa que analice un archivo de texto para obtener estadísticas relevantes, modificar su contenido mediante reemplazos de palabras, y guardar el resultado junto con las estadísticas en un archivo de salida.

**Decisiones tomadas:**

* Leer el archivo completo en memoria para facilitar el análisis y edición.
* Utilizar una estructura (`Estadisticas`) para encapsular los resultados del análisis.
* Implementar funciones independientes para tareas específicas: lectura de archivo, análisis estadístico, reemplazo de palabras, y escritura en archivo.
* Usar un menú interactivo para que el usuario ejecute las acciones deseadas de forma ordenada y sencilla.

Estas decisiones permiten modularidad, legibilidad y facilidad de mantenimiento del código.

---

 2. **Estrategia de solución**

## Estructura General:

El programa se divide en 5 componentes funcionales principales:

| Módulo / Función       | Propósito                                                                   |
| ---------------------- | --------------------------------------------------------------------------- |
| `cargarArchivo`        | Lee el archivo completo a memoria.                                          |
| `calcularEstadisticas` | Recorre el texto y cuenta caracteres, palabras, líneas, espacios y vocales. |
| `reemplazarPalabra`    | Busca y reemplaza todas las ocurrencias de una palabra por otra.            |
| `guardarResultados`    | Escribe en un archivo los resultados del análisis y el texto modificado.    |
| `main`                 | Controla el flujo del programa mediante un menú interactivo.                |

 ## Flujo General:

1. Se solicita al usuario el nombre de un archivo.
2. El contenido se carga a memoria.
3. El usuario puede:

   * Ver estadísticas generales.
   * Ver frecuencia de vocales.
   * Reemplazar palabras.
   * Guardar los resultados modificados.
4. El programa finaliza liberando la memoria.

---

 3. **Tabla de variables**

## Función: `cargarArchivo`

| Variable        | Tipo          | Rol                          |
| --------------- | ------------- | ---------------------------- |
| `nombreArchivo` | `const char*` | Entrada                      |
| `archivo`       | `FILE*`       | Interna (manejo del archivo) |
| `tam`           | `long`        | Interna (tamaño del archivo) |
| `contenido`     | `char*`       | Salida                       |

---

## Función: `calcularEstadisticas`

| Variable    | Tipo           | Rol                                      |
| ----------- | -------------- | ---------------------------------------- |
| `texto`     | `const char*`  | Entrada                                  |
| `e`         | `Estadisticas` | Salida                                   |
| `c`         | `char`         | Interna (carácter actual)                |
| `inPalabra` | `int`          | Interna (estado de detección de palabra) |
| `i`         | `int`          | Interna (índice del ciclo)               |

---

## Función: `reemplazarPalabra`

| Variable                    | Tipo          | Rol      |
| --------------------------- | ------------- | -------- |
| `texto`                     | `const char*` | Entrada  |
| `buscar`                    | `const char*` | Entrada  |
| `reemplazo`                 | `const char*` | Entrada  |
| `resultado`                 | `char*`       | Salida   |
| `i`, `contador`             | `int`         | Internas |
| `tamBuscar`, `tamReemplazo` | `int`         | Internas |

---

## Función: `guardarResultados`

| Variable        | Tipo           | Rol     |
| --------------- | -------------- | ------- |
| `nombreArchivo` | `const char*`  | Entrada |
| `est`           | `Estadisticas` | Entrada |
| `texto`         | `const char*`  | Entrada |
| `archivo`       | `FILE*`        | Interna |

---


4.  **Pseudocódigo** (para `calcularEstadisticas`)


Inicializar estructura de estadísticas
Recorrer cada carácter del texto:
    - Si no es salto de línea → contar como carácter
    - Si es espacio → contar espacio
    - Si es salto de línea → contar línea
    - Si comienza palabra → contar palabra
    - Si es vocal → incrementar contador correspondiente
Al finalizar → sumar 1 a líneas por última línea sin '\n'
Retornar estadísticas


---

 5. **Lenguaje**

El análisis se realizó utilizando terminología técnica adecuada, enfocándose en:

* **Modularidad**: separar funciones por responsabilidades.
* **Tipado de variables**: tipos estándar en C (`char*`, `int`, `FILE*`).
* **Estructuras de control**: ciclos, condicionales y estructuras (`struct`).
* **Manejo de memoria dinámica**: uso de `malloc`, `free`.
