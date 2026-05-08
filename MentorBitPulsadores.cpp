/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


@author Digital Codesign
@version 1.1.0
@date Fecha de creación: Septiembre de 2024
@date Fecha de versión: Mayo de 2026
@see Repositorio: https://github.com/DigitalCodesign/MentorBit-Pulsadores
* @brief Descripción: 
    Esta librería está específicamente diseñada para ser utilizada junto con 
    el módulo de pulsadores dual de MentorBit. Se ha optimizado introduciendo 
    enumeradores para una mayor seguridad de tipos y métodos directos que 
    mejoran la legibilidad del código final del usuario.
* @details Métodos principales:
    - MentorBitPulsadores -> Constructor de la clase.
    - obtenerLectura      -> Obtiene el estado de un pulsador específico mediante el enumerador.
* Métodos extendidos (Quality of Life):
    - estaPulsado1        -> Comprueba directamente el estado del primer pulsador.
    - estaPulsado2        -> Comprueba directamente el estado del segundo pulsador.
    - estanAmbosPulsados  -> Verifica si ambos pulsadores están siendo presionados simultáneamente.

*/

#include "MentorBitPulsadores.h"

/**
 * @brief Constructor de la clase MentorBitPulsadores.
 * Asigna los pines por defecto a los que está conectado el módulo físico.
 * @param pin_pulsador1 Pin digital correspondiente al primer botón (por defecto 0).
 * @param pin_pulsador2 Pin digital correspondiente al segundo botón (por defecto 0).
 */
MentorBitPulsadores::MentorBitPulsadores(uint8_t pin_pulsador1, uint8_t pin_pulsador2) {

    _port.gpios[0] = pin_pulsador1;
    _port.gpios[1] = pin_pulsador2;

}

/**
 * @brief Configura el puerto de hardware asociado al módulo.
 * Define internamente los pines asignados como entradas (INPUT) para poder 
 * registrar correctamente las pulsaciones físicas.
 * @param port Estructura constante por referencia con la configuración del puerto.
 */
void MentorBitPulsadores::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    pinMode(_port.gpios[0], INPUT);
    pinMode(_port.gpios[1], INPUT);

}

/**
 * @brief Obtiene el estado lógico actual de uno de los pulsadores.
 * @param boton Etiqueta del pulsador a consultar (BOTON_1 o BOTON_2).
 * @return true si el botón está pulsado (HIGH), false si está en reposo (LOW).
 */
bool MentorBitPulsadores::obtenerLectura(Pulsador boton) const {

    if (boton == BOTON_1) return digitalRead(_port.gpios[0]);
    else return digitalRead(_port.gpios[1]);

}

/**
 * @brief Comprueba de forma directa si el primer pulsador está siendo presionado.
 * @return true si el BOTON_1 está activo, false en caso contrario.
 */
bool MentorBitPulsadores::estaPulsado1() const {

    return digitalRead(_port.gpios[0]);

}

/**
 * @brief Comprueba de forma directa si el segundo pulsador está siendo presionado.
 * @return true si el BOTON_2 está activo, false en caso contrario.
 */
bool MentorBitPulsadores::estaPulsado2() const {

    return digitalRead(_port.gpios[1]);

}

/**
 * @brief Verifica si ambos pulsadores están siendo presionados al mismo tiempo.
 * Útil para programar combinaciones de teclas (ej. reiniciar un sistema, acceder a un menú).
 * @return true solo si BOTON_1 y BOTON_2 están activos simultáneamente, false en caso contrario.
 */
bool MentorBitPulsadores::estanAmbosPulsados() const {

    return (estaPulsado1() && estaPulsado2());

}
