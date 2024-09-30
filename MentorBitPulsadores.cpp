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

// Se incluye las librerias para el uso del modulo de pulsadores
#include <MentorBitPulsadores.h>

/*
    Constructor, se debe indicar los pines a los que esta conectado el modulo de pulsadores
*/

MentorBitPulsadores::MentorBitPulsadores(uint8_t pin_pulsador1, uint8_t pin_pulsador2){
    _pin_pulsador1 = pin_pulsador1;
    _pin_pulsador2 = pin_pulsador2;
    pinMode(_pin_pulsador1,INPUT);
    pinMode(_pin_pulsador2,INPUT);
}
/*
    Funcion que lee el estado digital de cada uno de los pulsadores. Para leer se le debe
    indicar el pulsador. 

    PULSADOR_1 -> pulsador 1
    PULSADOR_2 -> pulsador 2
*/
bool MentorBitPulsadores::obtenerLectura(bool pulsador){
    bool value;
    if(pulsador){
       value = digitalRead(_pin_pulsador1);
    }
    else{
        value = digitalRead(_pin_pulsador2);
    }
    return value;
}
