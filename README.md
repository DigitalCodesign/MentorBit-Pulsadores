# MentorBit-Pulsadores
Esta librería está construida por Digital Codesign para utilizar el módulo de Pulsadores, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluir la librería con la siguiente línea:

```
#include <MentorBitPulsadores.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de pulsadores, y definimos los pines a los que están conectados los pulsadores:

```
MentorBitPulsadores pulsadores(PIN_PULSADOR_1, PIN_PULSADOR_2);
```

Siendo `PIN_PULSADOR_1` y `PIN_PULSADOR_2` los pines donde están conectados los pulsadores del módulo.

### Uso

Con los pulsadores ya definidos, podemos leer el estado de cada uno de los pulsadores utilizando la función `obtenerLectura()`. El parámetro que se pasa a la función determina cuál de los pulsadores queremos leer.

```
bool estado = pulsadores.obtenerLectura(PULSADOR_1);
```

- Si el valor de `PULSADOR_1` es `true`, se leerá el estado del pulsador 1.
- Si el valor de `PULSADOR_2` es `false`, se leerá el estado del pulsador 2.

Esta función devuelve un valor booleano (`true` o `false`), dependiendo del estado del pulsador, ya sea presionado o no.

### Atributos

- `PULSADOR_1`: Selecciona el pulsador 1 para su lectura.
- `PULSADOR_2`: Selecciona el pulsador 2 para su lectura.

