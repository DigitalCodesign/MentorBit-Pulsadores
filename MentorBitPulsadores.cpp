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

MentorBitPulsadores::MentorBitPulsadores(uint8_t pin_pulsador1 = 0, uint8_t pin_pulsador2 = 0){
    _port.gpios[0] = pin_pulsador1;
    _port.gpios[1] = pin_pulsador2;
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
       value = digitalRead(_port.gpios[0]);
    }
    else{
        value = digitalRead(_port.gpios[1]);
    }
    return value;
}

void MentorBitPulsadores::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

}