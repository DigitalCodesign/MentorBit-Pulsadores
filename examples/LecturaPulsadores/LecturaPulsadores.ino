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
    Este sketch muestra un ejemplo de como evaluar el estado de los dos pulsadores, 
    mostrando un mensaje por el monitor serial cuando se ha presionado uno de estos
*/

// Se incluye la libreria necesaria para el uso del modulo de pulsadores
#include <MentorBitPulsadores.h>

#define PIN_PULSADOR_1 24
#define PIN_PULSADOR_2 A4

// Se crea el objeto modulo_pulsadores
MentorBitPulsadores modulo_pulsadores(PIN_PULSADOR_1,PIN_PULSADOR_2);    

void setup(){
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
}

void loop(){
    if(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_1)){
        Serial.println("Se ha pulsado el pulsador 1");
        while(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_1));
    }
    if(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_2)){
        Serial.println("Se ha pulsado el pulsador 2");
        while(!modulo_pulsadores.obtenerLectura(modulo_pulsadores.PULSADOR_2));
    }
}