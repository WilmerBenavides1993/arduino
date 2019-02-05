/*             UNIVERSIDAD TECNICA DEL NORTE 
 *                 FICA-CIERCOM
 *              SISTEMAS MICROPROCESADOS 
 *                 WILMER BENAVIDES 
 *    Realizar un programa que permita poner al sistema 19 segundos 
 *    en modo sleep, se despierte, realice un lectura del conversor 
 *    análogo digital, lo imprima por comunicación serial y 
 *    vuelva a dormir 19 segundos.
 * 
 */

#include <LowPower.h>// librerias de control de energia
#include <MsTimer2.h>// libreria de reloj
int dato;

void setup() {
  Serial.begin(9600);// inicio comunicacion serial
  MsTimer2::set(100, rutina);// ingreso parametros el timer y su metodo
  MsTimer2::start();//inicio del timer
  Serial.println("ingrese tiempo <=8");
  Serial.print("inicio");// mensaje de inicio
  Serial.println(analogRead(0));// lectura del lector AD
 
}



void loop() {
if (Serial.available() > 0) { // si se escrtito algo en el serial lee
    dato = Serial.read(); // el serial lee el dato ingreado
    
  sleep(dato); // llamamar al metodo crado de control  
  }
}
void rutina() {// metodo del timer
 

 
}

void sleep(int sec) {
  while (sec >= 8) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    sec -= 8;
  }
  if (sec >= 4) {
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    sec -= 4;
  }
  if (sec >= 2) {
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
    sec -= 2;
  }
  if (sec >= 1) {
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    sec -= 1;
  }
  
}
