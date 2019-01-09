
/*UNIVERSIDAD TECNICA DEL NORTE
   FICA-CIERCOM
   SISTEMAS MICROPROCESADOS
   DEBER:
   REALIZAR UN RELOJ DIGITAL USANDO TIMER

*/
#include <MsTimer2.h>
#include <LiquidCrystal.h>
int horero = 00; // variable para hora
int minutero = 00; // variable para minutos
int segundero = 00; // variable para segundos
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);// posiciones del lcd

int str ;// CONTROL de minutero
int str1 ;// control de horero
int num = 0;// bandera

int pinzumbador = 13;    // pin del BUZZER
int frecuencia = 220;      // frecuencia correspondiente
void setup() {

  attachInterrupt(0, alarma, LOW);
  lcd.begin(16, 2);// inicializa la lcd
  Serial.begin(9600);// inicializa la comunicacion serial
  MsTimer2::set(50, rutina); // parametros el timer
  MsTimer2::start();// inicializa el timer
}

void loop() {
  alarma(num);
  if ((str > 59) && (str1 > 25)) { // si la hora excede los limites sale el siguiente mesaje
    Serial.println("hora incorrecta");
  }
  if ((str == minutero) && (str == horero)) { // si la hora ingresada es igual al reloj sonara la alarma
    tono();
    Serial.print("ALARMA ACTIVADA");
  }
}

void rutina() { // metodo para el timer el cual contara y mostrara el reloj
  segundero++; // contador empieza a contar a cada segundo
  lcd.setCursor(14, 0);// posicion el la lcd para los segundos
  lcd.print(segundero); // muestra en la lcd
  lcd.setCursor(12, 0);
  lcd.print(":");
  lcd.setCursor(11, 0);
  lcd.print(minutero);
  lcd.setCursor(9, 0);
  lcd.print(":");
  lcd.setCursor(8, 0);
  lcd.print(horero);
  lcd.setCursor(1, 0);
  lcd.print("HORA");
  lcd.setCursor(1, 1);
  lcd.print("ALARMA");


  if ( segundero == 59) { // control para minutero cuando el segundero llegue a 59
    minutero++;// comienza a contar minutero
    lcd.setCursor(11, 0);
    lcd.print(minutero);// se imprime los minutos
    segundero = 0;
    // lcd.clear();

  }
  if ( minutero == 59) { // control del munutero
    horero++;// comienza el conteo para hora
    lcd.setCursor(6, 0);
    lcd.print(horero);// se imprime la hora
    minutero = 0;
    lcd.clear();


  }
  if ( horero == 23) { // control de hora cuando llega a 23:59:59 se imprime en 00:00:00
    horero = 0;
    minutero = 0;
    segundero = 0;

  }
}
void alarma(int num) {// metodo alarma
  if (Serial.available() > 0) {
    if (num == 0) {// si la bandera esta en 0 pide la hora y guarda el dato de la comunicacion serial
      Serial.println("ingrese hora");
      delay(500);
      String dato = Serial.readString();
      int str1 = String(dato).toInt();
      lcd.setCursor(8, 1);// se imprime en la lcd los resultados
      lcd.print(str1);
      lcd.setCursor(10, 1);
      lcd.print(":");
      delay(200);
      num = 1;// bandera en 1 para que ejecute la siguiente condicion


    } if (num == 1) {// si la bandera esta en 1 pide los minutos y guardar en la variable str
      Serial.println("");
      Serial.println("ingrese minutos");
      delay(500);
      String dato1 = Serial.readString();
      int str = String(dato1).toInt();
      lcd.setCursor(12, 1);// ubicacion en la lcd para los minutos de la alarma
      lcd.print(str);
      delay(200);
      num = 0;// bandera en cero para volver a pedir hora
    }


  }

}



void tono() {// metodo para el tono de alarma
  tone(pinzumbador, frecuencia);   // inicia el zumbido
  delay(2000);
  noTone(pinzumbador);               // lo detiene a los dos segundos
  delay(1000);
}
