# MentorBit-Pulsadores

Esta librería está diseñada para que puedas utilizarr fácilmente el módulo de pulsadore junto a tu placa MentorBit mediante un único conector JST de 4 pines.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo de dos pulsadores.](https://github.com/DigitalCodesign/MentorBit-Pulsadores/blob/main/assets/Modulo_Pulsadores.png)

Con esta librería, podrás detectar si se ha presionado alguno de los dos botones de forma independiente, ideal para entradas simples en tus proyectos interactivos.

---

## Descripción

### ¿Qué es el módulo MentorBit de dos pulsadores?

Este módulo cuenta con dos pulsadores independientes, cada uno con su propia salida digital. Se conectan a través de un único conector JST de 4 pines.

El módulo está diseñado para que puedas detectar fácilmente la interacción del usuario con el pulsador sin necesidad de configuraciones complejas.

---

### ¿Qué hace esta librería?

La librería **MentorBit-Pulsadores** te permite leer el estado de los dos pulsadores mediante funciones simples. Puedes saber en cualquier momento si el pulsador 1 o el pulsador 2 están siendo presionados.

---

### ¿Qué puedes construir con este módulo?

- Menús controlados por botones.
- Juegos simples de dos botones.
- Activadores manuales para encender luces o motores.
- Entradas digitales para proyectos de robótica o educación.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo de pulsadores a uno de los puertos digitales con conector JST de 4 pines que se encuentran en la sección "Puertos para Módulos" de la placa MentorBit. Ambos pulsadores usan líneas digitales independientes.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-Pulsadores*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-Pulsadores/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer pulsadores

Este ejemplo imprime por el monitor serie si se presiona alguno de los dos botones.

```cpp
// Se incluye la libreria necesaria para el uso del modulo de pulsadores
#include <MentorBitPulsadores.h>

#define PIN_PULSADOR_1 24
#define PIN_PULSADOR_2 A4

// Se crea el objeto modulo_pulsadores
MentorBitPulsadores modulo_pulsadores(PIN_PULSADOR_1,PIN_PULSADOR_2);  

void setup() {
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
}

void loop() {
    if(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_1)){
        Serial.println("Se ha pulsado el pulsador 1");
        while(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_1));
    }
    if(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_2)){
        Serial.println("Se ha pulsado el pulsador 2");
        while(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_2));
    }
}
```

---

## Funciones Principales

- `bool obtenerLectura(bool pulsador)`  
  Devuelve el estado lógico del pulsador indicado (para indicar el pulsador se disponen de dos atributos).

---

## Atributos Principales (clase pulsadores)

- `pulsadores.PULSADOR_1`  
  Selecciona el pulsador 1 en la función de `obtenerLectura()`.

- `pulsadores.PULSADOR_2`  
  Selecciona el pulsador 2 en la función de `obtenerLectura()`.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo de Pulsadores](https://canarias.digitalcodesign.com/shop/00038805-mentorbit-modulo-de-pulsadores-8111?category=226&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/19UKh8xvWa1s_IAWsS2bx1jMyJLhTn91o/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1NgnDGHyL2NPyO9IWciVHZKL5mXTEADZ3/view?usp=drive_link)
