# MentorBitPulsadores

Librería para el uso de módulos de dos pulsadores en placas compatibles con MentorBit.

## Descripción

La librería `MentorBitPulsadores` facilita la lectura de dos pulsadores conectados a pines digitales en módulos compatibles con MentorBit. Permite obtener el estado de cada pulsador individualmente.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitPulsadores" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitPulsadores.h>

    MentorBitPulsadores pulsadores(2, 3); // Pulsador 1 en pin 2, pulsador 2 en pin 3

    void setup() {
      Serial.begin(9600);
      Serial.println("Módulo de pulsadores inicializado.");
    }

    void loop() {
      if (pulsadores.obtenerLectura(pulsadores.PULSADOR_1)) {
        Serial.println("Pulsador 1 presionado");
      }
      if (pulsadores.obtenerLectura(pulsadores.PULSADOR_2)) {
        Serial.println("Pulsador 2 presionado");
      }
      delay(100);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitPulsadores(uint8_t pin_pulsador1, uint8_t pin_pulsador2)`: Crea un objeto `MentorBitPulsadores`.
    * `pin_pulsador1`: Pin digital al que está conectado el primer pulsador.
    * `pin_pulsador2`: Pin digital al que está conectado el segundo pulsador.

### Métodos

* `bool obtenerLectura(bool pulsador)`: Obtiene el estado de un pulsador.
    * `pulsador`: `PULSADOR_1` para leer el primer pulsador, `PULSADOR_2` para leer el segundo pulsador.

## Constantes Públicas

* `PULSADOR_1`, `PULSADOR_2`: Constantes para seleccionar el pulsador a leer.
