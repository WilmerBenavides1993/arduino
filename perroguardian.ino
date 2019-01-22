/*                           UNIVERSIDAD TECNICA DEL NORTE
                                     FICA-CIERCOM
                                SISTEMAS MICROPROCESADOS
    NOMBRE= WILMER BENAVIDES
    FECHA=22/ENERO/2019
    DEBER
    Realizar un programa que permita que el conversor análogo digital
    configure al perro guardían a 10,20,30 y 40 segundos. Este proceso se visualiza en una lcd.
    PROCESO:
            -> asignar las librerias necesarias
            -> los puertos de salida de lcd
            -> declarar variables
            -> iniciar comunicacion serial
            -> activar el timer
            -> crear el metodo para timer
            -> tomar datos de la entrada AD y transformarlos a enteros
            -> comparar valores y activar el perro guardian

*/
#include <LiquidCrystal.h>// librerias
#include <MsTimer2.h>
#include<avr/wdt.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);// entradas a lcd pines
int dato;// variable para AD
int cont;// contador
void setup() {
  Serial.begin(9600);// iniciar comunicacion serial
  lcd.begin(16, 2);// iniciar lcd
  MsTimer2::set(1000, conteo);//asignar valores a timer 1000-> 1s de velocodad, conteo-> metodo de acciones del timer
  MsTimer2::start();// iniciar timer
  Serial.print("inicio");// imprimir mensaje para saber cada vez que se reinicie
  cont = 0;
  lcd.clear();// limpiar la lcd por cada reset
  delay(200);
}
void loop() {

}
void conteo() {//metodo donde el dato entero de guarda en dato y posterirmente se lo ira comparando 

  dato = ((analogRead(1) * 5) / 1023.0) * 100;// datos del AD
  lcd.setCursor(1, 0);// posicion del dato en lcd
  lcd.print(dato);
  if (dato == 100) {// se compara para ir asignando el tiempo de  reset
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("10 SEG");// mensaje de aviso
    cont++;// contador para el tiempo de reset
    delay(500);
    lcd.setCursor(1, 0);
    lcd.print(cont);
    if (cont == 10) {// cuando llege a 10 se reinicia 
      wdt_enable(WDTO_1S);
    }
  }
  if (dato == 200) {
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("20 SEG");
    cont++;
    delay(500);
    lcd.setCursor(1, 0);
    lcd.print(cont);
    if (cont == 20) {
      wdt_enable(WDTO_1S);
    }
  }
  if (dato == 300) {
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("30 SEG");
    cont++;
    delay(500);
    lcd.setCursor(1, 0);
    lcd.print(cont);
    if (cont == 30) {
      wdt_enable(WDTO_1S);
    }
  }
  if (dato == 400) {
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("40 SEG");
    cont++;
    delay(500);
    lcd.setCursor(1, 0);
    lcd.print(cont);
    if (cont == 40) {
      wdt_enable(WDTO_1S);
    }
  }
}
