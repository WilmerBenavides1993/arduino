
/*                           UNIVERSIDAD TECNICA DEL NORTE
                                     FICA-CIERCOM
                                SISTEMAS MICROPROCESADOS
    NOMBRE= WILMER BENAVIDES
    FECHA=22/ENERO/2019
    EXAMEN
    PROCESO:
    -> incluir librerias
    -> asignar puertos para botones
    -> asignar arrays para las claves
    -> iniciar comunicacion serial
    -> variables de control
    -> asignar si es entrada o salida los pines
    -> interrupcion para activar o desactivar
    -> comparar los digitos ingresados
    -> asignar una accion despues de los 2 intentos
    -> ingresar una nuerva contraseña
    -> mostrarla por serial
*/
#include <EEPROM.h>// librerias
#include <MsTimer2.h>
#include<avr/wdt.h>
int p1 = 5, p2 = 6, p3 = 7;// asignacion de pines para las entradas de los pulsadores
int sw = 0;// contador para la interrupcion
int num[4] ;// variable donde se guardaran los numeros aleatorios
int sec[4];// variable donde se tomara los datos de los pulsadores
int cont;// contador
int control = 0;// variable para controlar cuatas veces se repite la contraseña correcta
void setup() {
  Serial.begin(9600);// inicializa la comunicacion serial
  //MsTimer2::set(500, rutina); // parametros el timer
  //MsTimer2::start();// inicializa el timer
  pinMode(p1, INPUT);//pines de entrada
  pinMode(p2, INPUT);//pines de entrada
  pinMode(p3, INPUT);//pines de entrada
  attachInterrupt(0, activar, LOW);// interrupcion para controlar el sistema activo o desactivado
  //  for (int i = 0; i < 5; i++) {
  //    EEPROM.write(i, 0);
  //  }
  EEPROM.write(0, 1);// ingresa en EEPROM la contraseña
  EEPROM.write(1, 1);// ingresa en EEPROM la contraseña
  EEPROM.write(2, 1);// ingresa en EEPROM la contraseña
  EEPROM.write(3, 1);// ingresa en EEPROM la contraseña
  EEPROM.write(4, 1);// ingresa en EEPROM la contraseña
}

void loop() {
  // si el contador de la interrucion da un pulso se activa y empieza a comparar todos los digitos con los ingresados por los botones
  ingreso();
  if (sw == 1) {
    if ((EEPROM.read(0) == sec[0]) && (EEPROM.read(1) == sec[1]) && (EEPROM.read(2) == sec[2]) && (EEPROM.read(3) == sec[3]) && (EEPROM.read(4) == sec[4])) {
      Serial.println("clave correcta");// se imprime un mensaje
      delay(2000);// tiempo espera
    } else {// caso contrario
      Serial.println("clave incorrecta");// mensaje de aviso
      //      for (int i = 0; i < 5; i++) {
      //      Serial.println(sec[i]);
      //      Serial.println(EEPROM.read(i));
      delay(2000);// tiempo de espera
      control++;// contador si superera los 2 intentos se activa

    }
  }
  if (control >= 2) {// si excede en 2 actua
    for (int i = 0; i < 5; i++) {// imprime un mensaje 5 veces
      Serial.println("#####################");
      Serial.println("#####################");
      Serial.println("SISTEMA BLOQUEADO");
      Serial.println("#####################");
      Serial.println("#####################");
      delay(2000);// tiempo de espera
    }
    for (int i = 0; i < 5; i++) {// ciclo repetitivo para escribir en la EEPROM la nueva contraseña
      num[i] = random(1, 4);// numeros aleatorios entre 1 y 3
      EEPROM.write(i, num[i]);// se graba en la EEPROM
    }
    Serial.println("su nuev clave es:");// se muestra el mensaje con la neuva contraseña
    for (int i = 0; i < 5; i++) {
      Serial.println(EEPROM.read(i));
    }

    control = 0;// se estable en cero la variable de contros de contraseña incorrecta
  }
}

void activar() {// metodo de la interrupcion
  switch (sw) {
    case 0:// primer caso si da un pulso se activa
      Serial.println("ACTIVADO");// mensaje
      sw++;// contador se incrementa
      break;// termina primer caso
    case 1:// caso 2 se desactiva el sistema
      Serial.println("DESACTIVADO");// mensaje
      sw = 0;
      break;// termina el caso 2
  }
}
void ingreso() {// metodo para ingresar valores
  int A = digitalRead(p1);// se asigna la variable dependiendo de la entrada de los pines
  int B = digitalRead(p2);
  int C = digitalRead(p3);
  if (A) {// se se preciona A se guardar 1 en el arreglo
    Serial.println("A");
    cont++;// contador para incrementar la posicion del arreglo
    sec[cont] = 1;
    delay(2000);
  } if (B) {
    Serial.println("B");
    cont++;
    sec[cont] = 2;
    delay(2000);
  } if (C) {
    Serial.println("C");
    cont++;
    sec[cont] = 3;
    delay(2000);
  }
}
