# Proyecto Tienda Online C++ — Plan de trabajo EJ-007

Rama de trabajo: `ejercicio7/tablas-dispersion`  
Base: implementación previa de `main`  
Directorio del proyecto: `proyecto/`

Este plan está ordenado por prioridad descendente y dependencias: primero definir y conseguir una implementación correcta; después mejorar su eficiencia, documentar y entregar.

## Objetivo y requisitos

Implementar `palabras PALABRA` mediante una tabla de dispersión que asocie cada palabra con los productos que la contienen en su nombre o descripción.

- Las consultas son de una sola palabra.
- Normalizar las claves y las consultas con `minusculas` del ejercicio 003.
- Conservar el texto original de los productos y del encabezado de consulta.
- Mostrar cada producto una sola vez y por identificador ascendente.
- Los identificadores insertados son distintos.
- La entrada de este ejercicio solo contiene `insertar` y `palabras`.
- No se establece un máximo de productos ni de palabras.
- Mantener exactamente el formato de salida del enunciado.

Arquitectura prevista:

```text
Interprete
    └── DiccionarioProductos
            ├── Almacenamiento de productos
            └── TablaHash
                    └── palabra → colección de Producto*
```

Los productos se almacenan una sola vez; el índice guarda referencias, no copias completas.

## Prioridad 1 — Definir el diseño y las interfaces

Antes de escribir la implementación completa:

- [ ] Elegir dispersión abierta o cerrada.
- [ ] Elegir una función de dispersión para cadenas.
- [ ] Si se usa dispersión cerrada, elegir la estrategia de redispersión.
- [ ] Definir el tamaño inicial de la tabla.
- [ ] Prever cómo crecerá y qué condición activará la reestructuración.
- [ ] Decidir dónde se almacenan los productos y quién es propietario de su memoria.
- [ ] Distinguir el número de productos, el de palabras distintas y el de asociaciones palabra-producto.
- [ ] Definir las responsabilidades de consulta e impresión: quién muestra los productos y quién devuelve o imprime el total.
- [ ] Resolver de forma coherente las operaciones anteriores (`eliminar`, `producto`, `precios`) y las llamadas que todavía realiza el intérprete.

### Restricciones

- No usar como hash la simple suma de códigos ASCII, su producto o únicamente la primera letra.
- No almacenar punteros a parámetros locales, como `&nuevo` en una inserción por valor.
- Mantener la lógica de indexación en el diccionario y en la tabla, no en el intérprete.
- Si se mantienen operaciones de borrado, deberán conservar la coherencia del índice; no basta con eliminar el producto y dejar punteros colgantes.

### Archivos afectados

- [ ] `TablaHash.h`: definir la representación y las operaciones públicas y privadas.
- [ ] `DiccionarioProductos.h`: incluir `TablaHash.h`, completar `numElem()` y concretar `palabras`.
- [ ] Revisar que las declaraciones acordadas permiten mantener coherente el resto del proyecto.

## Prioridad 2 — Preparar el acceso a los datos y la normalización

### `Producto.h`

- [ ] Añadir un getter para el nombre.
- [ ] Añadir un getter para la descripción.
- [ ] Conservar el formato actual de `mostrar()`.
- [ ] No convertir a minúsculas permanentemente los campos originales del producto.

### Función `minusculas`

- [ ] Reutilizar la función de `src/EJ_003.cpp`.
- [ ] Integrarla en el proyecto sin incorporar el `main` de ese ejercicio.
- [ ] Situarla en un archivo o módulo reutilizable, si procede.
- [ ] Usarla tanto en la indexación como en las consultas.
- [ ] Comprobar mayúsculas ASCII y caracteres españoles: tildes, `Ñ` y `Ü`.
- [ ] Incorporar al `Makefile` los nuevos archivos, si se crean.

## Prioridad 3 — Implementar una primera tabla hash funcional

Puede comenzarse con una tabla de tamaño fijo para validar el comportamiento; la versión final deberá gestionar adecuadamente el crecimiento y la eficiencia.

### `TablaHash.h`

- [ ] Definir la asociación palabra → colección de `Producto*`.
- [ ] Declarar constructor y destructor según la representación elegida.
- [ ] Declarar inserción y consulta.
- [ ] Declarar la función hash y los métodos auxiliares.
- [ ] Documentar el significado de los contadores y los resultados de las operaciones.

### `TablaHash.cpp`: inserción

- [ ] Calcular la posición de la palabra.
- [ ] Resolver las colisiones.
- [ ] Crear una entrada si la palabra no existe.
- [ ] Reutilizar la entrada si ya existe.
- [ ] Añadir el puntero al producto en orden por identificador.
- [ ] Impedir asociaciones duplicadas entre una palabra y un mismo producto.
- [ ] Actualizar los contadores adecuados.

### `TablaHash.cpp`: consulta

- [ ] Localizar la palabra y resolver las colisiones durante la búsqueda.
- [ ] Gestionar la tabla vacía y las palabras inexistentes.
- [ ] Recorrer únicamente los productos asociados a la palabra encontrada.
- [ ] Facilitar la presentación numerada y el recuento según la interfaz acordada.
- [ ] No crear entradas al consultar palabras inexistentes.

## Prioridad 4 — Adaptar el diccionario e indexar los productos

### `DiccionarioProductos.h`

- [ ] Revisar las inclusiones necesarias.
- [ ] Mantener el atributo `TablaHash tabla`.
- [ ] Definir el almacenamiento persistente de productos.
- [ ] Completar la declaración y definición de `numElem()`.
- [ ] Mantener las declaraciones coherentes con el intérprete.

### Constructor

- [ ] Inicializar los contadores propios.
- [ ] Comprobar que la construcción de `TablaHash` deja una tabla vacía utilizable.

### `DiccionarioProductos::insertar`

- [ ] Almacenar el producto de forma persistente.
- [ ] Obtener el puntero al producto realmente almacenado, nunca al parámetro local.
- [ ] Separar los tokens del nombre.
- [ ] Separar los tokens de la descripción.
- [ ] Normalizar cada token con `minusculas`.
- [ ] Registrar cada asociación en la tabla.
- [ ] Actualizar el número de productos.

Si se conserva `list<Producto>` como almacén, el PDF propone que no esté ordenada y que se inserte al principio o al final en O(1). El orden exigido para la consulta se mantiene en las asociaciones de cada palabra.

### `DiccionarioProductos::palabras`

- [ ] Normalizar la palabra consultada.
- [ ] Delegar la búsqueda en la tabla.
- [ ] Mostrar o entregar los resultados según la interfaz acordada.
- [ ] Garantizar un recuento correcto, también cuando no hay resultados.

## Prioridad 5 — Conectar el comando y conseguir una compilación completa

### `Interprete.h` e `Interprete.cpp`

- [ ] Añadir la declaración y definición del procesamiento de `palabras`.
- [ ] Leer la palabra consultada.
- [ ] Mostrar el encabezado conservando la escritura original.
- [ ] Invocar la consulta del diccionario.
- [ ] Mostrar `Total: X productos` una única vez.
- [ ] Añadir el despacho de `palabras` en `ejecutar`.
- [ ] Resolver las llamadas a métodos antiguos que ya no estén declarados.
- [ ] No introducir lógica hash ni extracción de palabras en el intérprete.

Nota de alcance: el PDF pide no modificar el intérprete, pero la versión revisada del repositorio no reconoce `palabras`. Es necesario añadir el soporte mínimo del comando, salvo que se utilice otra versión del intérprete que ya lo incluya.

### `Makefile`

- [ ] Verificar la compilación y el enlazado de `TablaHash.cpp`.
- [ ] Revisar las dependencias de las cabeceras.
- [ ] Incorporar utilidades nuevas, si existen.
- [ ] Compilar desde cero para no depender de objetos antiguos.
- [ ] Como mejora opcional, añadir `clean` y advertencias del compilador.

## Prioridad 6 — Validar la corrección funcional

- [ ] Consultar antes de insertar productos.
- [ ] Consultar una palabra inexistente.
- [ ] Consultar palabras presentes solo en el nombre.
- [ ] Consultar palabras presentes solo en la descripción.
- [ ] Repetir una palabra en el nombre y en la descripción y verificar que el producto aparece una sola vez.
- [ ] Insertar identificadores desordenados y comprobar el orden ascendente de salida.
- [ ] Consultar variantes de mayúsculas y minúsculas.
- [ ] Probar caracteres españoles.
- [ ] Consultar tokens de puntuación como `.`.
- [ ] Forzar colisiones entre palabras diferentes.
- [ ] Repetir consultas y comprobar que no modifican la tabla.
- [ ] Verificar el contador tras cada inserción.
- [ ] Comparar encabezados, numeración, espacios, precios y totales con el formato exigido.

### Detalles del enunciado

- El punto `.` es consultable: no eliminar automáticamente toda la puntuación.
- El ejemplo de salida incluye `palabras a`, pero ese comando no aparece en la entrada mostrada. Tratarlo como una inconsistencia del ejemplo, no como salida adicional que deba generarse.

## Prioridad 7 — Implementar y verificar el crecimiento y la memoria

- [ ] Implementar la condición de reestructuración elegida.
- [ ] Reservar una tabla mayor.
- [ ] Recalcular la posición de cada palabra para el nuevo tamaño.
- [ ] Trasladar todas las asociaciones sin perder productos ni introducir duplicados.
- [ ] Mantener el orden de los productos asociados a cada palabra.
- [ ] Mantener válidos los punteros a los productos.
- [ ] Liberar la tabla antigua.
- [ ] Revisar los destructores y la propiedad de cada reserva.
- [ ] No liberar desde la tabla productos cuya propiedad pertenece al diccionario.
- [ ] Si una clase posee memoria dinámica, controlar su copia: implementarla correctamente o impedirla si no se necesita.
- [ ] Provocar varias reestructuraciones y repetir las pruebas funcionales.
- [ ] Comprobar fugas, accesos fuera de rango y punteros colgantes.
- [ ] Revisar el tratamiento de bytes UTF-8 en el hash para evitar índices negativos.

## Prioridad 8 — Medir, comparar y justificar la eficiencia

- [ ] Preparar entradas grandes y reproducibles.
- [ ] Comparar distintas funciones de dispersión.
- [ ] Comparar tamaños iniciales.
- [ ] Comparar umbrales y estrategias de crecimiento.
- [ ] Medir tiempos de ejecución.
- [ ] Distinguir el coste de encontrar la palabra del coste de recorrer e imprimir sus resultados.
- [ ] Revisar si la inserción ordenada de referencias se convierte en un cuello de botella.
- [ ] Registrar las configuraciones y las mediciones.
- [ ] Elegir la configuración final basándose en las pruebas.

Ejemplo de medición propuesto en la práctica:

```bash
time ./a.out < 201a.in > salida
```

El ejemplo requiere disponer de ese archivo de entrada; no implica que esté incluido en el repositorio.

## Prioridad 9 — Redactar la memoria

- [ ] Explicar la arquitectura y las responsabilidades de cada clase.
- [ ] Justificar el almacenamiento de productos y el uso de punteros.
- [ ] Justificar dispersión abierta o cerrada.
- [ ] Explicar la función hash y la resolución de colisiones.
- [ ] Explicar el tamaño inicial, el umbral y la reestructuración.
- [ ] Documentar cómo se evitan duplicados y se mantiene el orden.
- [ ] Explicar la gestión de memoria.
- [ ] Incluir pruebas funcionales y mediciones de rendimiento.
- [ ] Presentar las alternativas comparadas y las conclusiones.

## Prioridad 10 — Preparar y comprobar la entrega

- [ ] Realizar una compilación limpia.
- [ ] Ejecutar las pruebas finales.
- [ ] Eliminar mensajes de depuración de la salida del programa.
- [ ] Verificar que todos los archivos necesarios están incluidos.
- [ ] Generar el archivo de entrega desde `proyecto/`:

```bash
tar -cf archivo.tar *.cpp *.h Makefile
```

- [ ] Comprobar el contenido del archivo generado.
- [ ] Verificar que el proyecto puede compilarse con los archivos entregados.

## Criterio de finalización

El ejercicio estará listo cuando compile desde cero, procese correctamente `insertar` y `palabras`, respete el formato, devuelva productos sin duplicados y ordenados, gestione el crecimiento y la memoria, y disponga de pruebas y justificación de diseño.

## Documentación utilizada

- README de la rama `ejercicio7/tablas-dispersion`.
- Código revisado de `main` y de la rama de trabajo.
- `AED1.SesionPract4.pdf`: arquitectura, restricciones y decisiones de implementación.
- `enunciado4.txt`: comportamiento y formato de entrada/salida.
- `tema2.pptx`: fundamentos de dispersión, colisiones, reestructuración y eficiencia.

Las mejoras opcionales se señalan como tales; las decisiones de diseño no representan una única solución obligatoria.
