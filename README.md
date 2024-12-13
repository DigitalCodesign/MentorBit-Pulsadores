

# MentorBit-Pulsadores
Esta librería está construida por Digital Codesign para utilizar el módulo de pulsadores de MentorBit, principalmente diseñado para el kit educacional "MentorBit".

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

Siendo `PIN_PULSADOR_1` el pin al que está conectado el pulsador 1 y `PIN_PULSADOR_2` el pin al que está conectado el pulsador 2.

### Uso

Con el objeto `pulsadores` definido, podemos obtener la lectura de cada pulsador utilizando la función `obtenerLectura()`, que devuelve el estado digital de un pulsador:

```
bool estadoPulsador1 = pulsadores.obtenerLectura(pulsadores.PULSADOR_1);
bool estadoPulsador2 = pulsadores.obtenerLectura(pulsadores.PULSADOR_2);
```

El valor devuelto es `true` si el pulsador está presionado y `false` si no lo está.

### Atributos

- `PULSADOR_1`: Define el primer pulsador.
- `PULSADOR_2`: Define el segundo pulsador.

### Configuración de puertos

Si deseas configurar puertos personalizados, puedes usar la función `configPort()` para asignar los pines y configuraciones de puertos que necesitas:

```
pulsadores.configPort(port);
```

Donde `port` es un objeto de tipo `Port` que contiene las configuraciones necesarias.


