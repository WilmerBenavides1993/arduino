/*                                  UNIVERSIDAD TECNICA DEL NORTE
                                           FICA-CIERCOM
                                       SISTEMAS MICROPROCESADOS
                                            LABORATORIO
    NOMBRE:
                BENAVIDES WILMER
    EJERCICIO:
  Realice un sistema que guarde en una posición de la memoria EEPROM
  solo cuando su valor exceda a la anterior lectura.

*/
#include <EEPROM.h>  //Incluimos la librería EEPROM
char buffer_EEPROM[50]; //variable con el tamaño de la frase maximo a ingresar
String dato;// variable para guardar el string

void setup() {
  Serial.begin(9600);    //Iniciamos la comunicación serial
  attachInterrupt(0, borrar, LOW);// interrupcion para borrar memoria
  Serial.println("INGRESE FRASE");

}


void loop() {
  if (Serial.available() > 0) { // si se escrtito algo en el serial lee
    dato = Serial.readString(); // el serial lee el dato ingreado
    int tam = dato.length(); //determina la longitud del string y lo guarda en la variable tam
    char vector [tam];//el valor tam corresponde al vector (cadena char)
    dato.toCharArray(vector, tam + 1); //conversion de string a char con el tamaño
    if (tam > EEPROM.read(100)) {// si supera el tamaño del anterior se ingresa un nuevo
      EEPROM.write(100, tam);// guarda el tamaño
      Escribir_EEPROM(vector);// activar metodos de lectura y escritura
      Leer_EEPROM(buffer_EEPROM);                           
      Serial.println("");
      Serial.println("NUEVA FRASE GUARDADA EN EEPROM ES : ");
      Serial.print(buffer_EEPROM); //Leemos la frase
      delay(10000);
    }
    else {// si no supera se imprime la anterior
      Leer_EEPROM(buffer_EEPROM);                            //Leemos la frase
      Serial.println("");
      Serial.println("ANTIGUA FRASE EN EEPROM ES : ");
      Serial.print(buffer_EEPROM);                         // imprime la frase
      delay(10000);
    }
  }
}

//metodo para escribir en la EEPROM
void Escribir_EEPROM(char *fra) {
  for (int i = 0; i < strlen(fra); i++) {
    EEPROM.write(i, fra[i]);
  }
}

//metodo para leer de la EEPROM
void Leer_EEPROM(char *buff) {
  for (int i = 0; i < 50; i++) {
    buff[i] = EEPROM.read(i);
  }
}
//metodo de borrar EEPROM
void borrar() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  Serial.println("Memoria EEPROM borrada!");

}
