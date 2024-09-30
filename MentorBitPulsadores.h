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


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: https://github.com/DigitalCodesign/MentorBit-Pulsadores
  Descripcion:
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo de pulsadores de MentorBit
  Metodos principales:
    MentorBitPulsadores -> constructor de la clase
    obtenerLectura -> devuelve el valor analogico del potenciometro
  Atributos:
    PULSADOR_1 -> selecciona el pulsador 1
    PULSADOR_2 -> selecciona el pulsador 2
*/

#ifndef MentorBitPulsadores_h
#define MentorBitPulsadores_h

// Se incluye las librerias para el uso del modulo de pulsadores
#include <arduino.h>

class MentorBitPulsadores
{
    public:

        MentorBitPulsadores(uint8_t pin_pulsador1, uint8_t pin_pulsador2);
        bool obtenerLectura(bool pulsador);

        const bool PULSADOR_1 = 1;
        const bool PULSADOR_2 = 0;

    private:

        uint8_t _pin_pulsador1;
        uint8_t _pin_pulsador2;
};

#endif