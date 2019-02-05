/*             UNIVERSIDAD TECNICA DEL NORTE
                   FICA-CIERCOM
                SISTEMAS MICROPROCESADOS
                   WILMER BENAVIDES
     Realizar un reloj dentro del arduino con el menor coste computacional
     que se visualiza en una LCD (apagar los periféricos que no se usen).
*/
#include <avr/power.h>// libreria de control de energia
#include <avr/sleep.h>// libreria para dormir al arduino
#include <MsTimer2.h>// libreria del timer
#include <LiquidCrystal.h>// libreria para lcd
int horero = 00; // variable para hora
int minutero = 00; // variable para minutos
int segundero = 00; // variable para segundos
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);// posiciones del lcd

void setup() {
  lcd.begin(16, 2);// inicializa la lcd
  Serial.begin(9600);// inicializa la comunicacion serial
  MsTimer2::set(1000, rutina); // parametros el timer
  MsTimer2::start();// inicializa el timer
  set_sleep_mode(SLEEP_MODE_IDLE);// introducir modos sleep IDLE es muy recomendable que que nos ahorra 12mA
  sleep_enable();// iniciamos el modo sleep
  
}

void loop() {// se pone a dormir los componentes que no se usan para bajar el consumo de energia
 
sleep_mode();
power_adc_disable();
power_spi_disable();
power_timer0_disable();
power_twi_disable();
}
void rutina() { // metodo para el timer el cual contara y mostrara el reloj

  lcd.setCursor(1, 0);
  lcd.print("WILL BENAVIDES");
  segundero++; // contador empieza a contar a cada segundo
  lcd.setCursor(12, 1);// posicion el la lcd para los segundos
  lcd.print(segundero); // muestra en la lcd
  lcd.setCursor(10, 1);
  lcd.print(":");
  lcd.setCursor(8, 1);
  lcd.print(minutero);
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(4, 1);
  lcd.print(horero);


  if ( segundero == 59) { // control para minutero cuando el segundero llegue a 59
    minutero++;// comienza a contar minutero
    lcd.setCursor(8, 1);
    lcd.print(minutero);// se imprime los minutos
    segundero = 0;
  }
  if ( minutero == 59) { // control del munutero
    horero++;// comienza el conteo para hora
    lcd.setCursor(4, 1);
    lcd.print(horero);// se imprime la hora
    minutero = 0;
  }
  if ( horero == 23) { // control de hora cuando llega a 23:59:59 se imprime en 00:00:00
    horero = 0;
    minutero = 0;
    segundero = 0;
  }




}
