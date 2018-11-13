/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA-CIERCOM 
 * SISTEMAS MICROPROCESADOS 
 * Nombre: WILMER BENAVIDES
 * Estimados estudiantes como lo dialogamos en clase. Realizar un programa que permita ingresar el número de cédula con el guión y 
 * posteriormente validarlo. El dato se lo ingresa por comunicación serial
  */
#include<stdlib.h>

 char digito1 ;// variables char para almacenar los caracteres
  char digito2 ;// variables char para almacenar los caracteres
  char digito3 ;// variables char para almacenar los caracteres
  char digito10 ;// variables char para almacenar los caracteres
  int validador[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};// parametro para analisis de cedual 
  int valor;//variables 
  int total = 0;
  int i=0;
  int n1 ;
  int n2 ;
  int n10 ;
  int total2 = 0;

void setup() {
 
  Serial.begin(9600);// tiempo del la comunicacion serial
  Serial.println("Ingrese la cedula"); // texto de inicio


}
void loop() {
  if (Serial.available() > 0) {// se valida la comunicacion serial
    String cedula = Serial.readString();//lee los datos 
    validadorCedula(cedula);// se ingresa al metodo validadorcedula
  }
}

void validadorCedula(String cedula2) {// creacion de metodo validador

  digito1 = cedula2.charAt(0);//se asigna el valor al digito1 en la posicion 0
  digito2 = cedula2.charAt(1);//se asigna el valor al digito1 en la posicion 1
  digito3 = cedula2.charAt(2);//se asigna el valor al digito1 en la posicion 2
  digito10 = cedula2.charAt(9);//se asigna el valor al digito1 en la posicion 9

  n1 = digito1 - 48;// calculos validadores de para la cedula
   n2 = digito2 - 48;// calculos validadores de para la cedula
    n10 = digito10 - 48;// calculos validadores de para la cedula
     total2 = 0;



  if (cedula2.length() == 10) {// preguntamos si es igual a 10 sin es asi seguimos la validacion
    if (n1 >= 1 || n1 <= 2 && n2 >= 0 || n2 <= 4) {// preguntamos los parametros 
      
        for (; i < 9; i++) {//
          valor = validador[i] * (((cedula2.charAt(i) - 48)));// realiza calculos 
          if (valor >= 10) {// pregunta si el valor adquirido de calculo anterior
            valor = valor - 9;
          }
          total = total + valor;// se suma para optener los valores y se hace los calculos 
          total2 = 10 - (total % 10);
          if (total2 == 10) {
            total2 = 0;
          }

        }

        if (total2 == n10) {// validamos si es correcto
          Serial.println("");
          Serial.println("Cedula correcta");// mesaje
          delay(200);// tiempo espera

        } else {// si no es asi
          Serial.println("");
          Serial.println("Cedula Incorrecta");// mensaje
          delay(200);
          
    }
    
    }
  }
  else if (cedula2.length() < 10) {// si los digitos son menores a 10 digitos
    Serial.println("");
    Serial.println("la cedula tiene menos de 10 digitos");
    delay(200);

  }
  else if (cedula2.length() > 10) {// si los digitos son mayores a 10 digitos
    Serial.println("");    
    Serial.println("la cedula tiene mas de 10 digitos");
    delay(200);

  }

    }
     
    
