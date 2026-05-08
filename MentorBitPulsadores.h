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

#ifndef MentorBitPulsadores_h
#define MentorBitPulsadores_h

#include <Arduino.h>
#include <MentorPort.h>

class MentorBitPulsadores : public MentorPort
{
    public:

        enum Pulsador { BOTON_1, BOTON_2 };

        MentorBitPulsadores(uint8_t pin_pulsador1 = 0, uint8_t pin_pulsador2 = 0);

        void configPort(const Port& port) override;

        bool obtenerLectura(Pulsador boton) const;
        bool estaPulsado1() const;
        bool estaPulsado2() const;
        bool estanAmbosPulsados() const;

    private:

        Port _port;

};

#endif