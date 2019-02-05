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


void setup() {
  Serial.begin(9600);// inicio comunicacion serial
  MsTimer2::set(1000, rutina);// ingreso parametros el timer y su metodo
  MsTimer2::start();//inicio del timer
  Serial.print("inicio");// mensaje de inicio
  Serial.println(analogRead(0));// lectura del lector AD

}



void loop() {
  for(int i=0; i<3;i++){// ciclo de 3*8=24 segundos para que duerma el arduino
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);// parametros del lowpower
 
  }
}
void rutina() {// metodo del timer
 
 // llamamar al metodo crado de control

//void sleep(){// metetodo sleep 
//  
  
}
//void sleep() {
//  //for (int i=0;i<19;i++){
//    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
//  //}
//  }
