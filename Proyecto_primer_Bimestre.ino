/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * PROYECTO- BIMESTRE 1
 * Nombres: Benavides Wilmer - Chandi Brayan- Chicaiza Fredy 
 * La empresa XYZ le solicita que realice un sistema de seguridad y acceso para su edificio. Las indicaciones son las siguientes.
1. Debe tener un ingreso y salida de los empleados mediante una contraseña individual por ingreso de teclado matricial.
2.  Las contraseñas deben ser de 5 dígitos y hay que validar ese número.
3.  Son 4 trabajadores.
4.  Si alguno de los empleados se olvida la contraseña, es necesario que el personal administrativo digite su contraseña master y permita el cambio de la contraseña olvidada.
5.  Desea contabilizar el número de clientes por día que ingresan a las instalaciones. Al final de día, se puede observar el número final en displays.
6.  Al terminar la jornada del día, se ingresa una nueva contraseña por comunicación serial para activar la alarma. Si alguien ingresa y el sensor lo detecta se enciende una alarma hasta que se ingrese la misma contraseña.
7.  Se necesita interrupciones para dar un mejor funcionamiento al sistema.
  */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 4);
#include <Keypad.h>
int fun=0, num, r, cont=0,i=0;
char resp =' ';
char admin[5]={'1','2','3','4','5'};
char trabajador1[5]={'1','2','3','4','5'};
char trabajador2[5]={'1','2','3','4','5'};
char trabajador3[5]={'1','2','3','4','5'};
char trabajador4[5]={'1','2','3','4','5'};
char pass2[5];
const byte ROWS = 4;
const byte COLS = 4; 
char vector [2];
String dato;
boolean bandera=false;
boolean bandera1=false;
int A=13, B=12, C=11, D=10;
int b=0;
int dec=8;
int unit=9;
int decenas, unidades;
int mas=3;
unsigned long arranque;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; 
byte colPins[COLS] = {A3,A2,A1,A0}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
  Serial.begin(9600);
  pinMode(1,LOW);
  attachInterrupt(0,funciones,FALLING);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT); 
  pinMode(mas,INPUT);
  pinMode(dec,OUTPUT); //pin dec declarado como salida 
  pinMode(unit,OUTPUT); //pin unit declarado como salida 
 Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SISTEMA  DE");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("SEGURIDAD");
  delay(1000);
  digitalWrite(unit,LOW); 
  digitalWrite(dec,LOW);
}

void loop() {
mostrardigitos();
  //*****************************************************************************************
 char teclado = customKeypad.getKey();
 if(fun==0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SISTEMA APAGADO");
    (millis()-arranque)>100;
 }

 if(fun==1){
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("REGISTRO INGRESO");
    delay(2000);
    lcd.clear();
     lcd.setCursor(0,0);
       lcd.print("A:TRABAJADOR1");
       delay(500);
       lcd.setCursor(0,1);
       lcd.print("B:TRABAJADOR2");
       delay(500);
       lcd.setCursor(0,2);
       lcd.print("C:TRABAJADOR3");
       delay(500);
       lcd.setCursor(0,3);
       lcd.print("D:TRABAJADOR4");
       delay(500);
       lcd.clear();
      lcd.setCursor(0,2);
      for(int i=0;i<1;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        lcd.print(teclado);
        i++;
       if(teclado='A'){
        lcd.clear();
        validar_trab1();}
      else if(teclado='B'){
         lcd.clear();
        validar_trab2();}
      else if(teclado='C'){ lcd.clear();
        validar_trab3();}
      else if(teclado='D'){ lcd.clear();
       validar_trab4(); }
    
      }
      }
      
      (millis()-arranque)>100;
 }
 if(fun==2){
 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("REGISTRO SALIDA");
    delay(500);
    lcd.clear();
     lcd.setCursor(0,0);
       lcd.print("A:TRABAJADOR1");
       delay(500);
       lcd.setCursor(0,1);
       lcd.print("B:TRABAJADOR2");
       delay(500);
       lcd.setCursor(0,2);
       lcd.print("C:TRABAJADOR3");
       delay(500);
       lcd.setCursor(0,3);
       lcd.print("D:TRABAJADOR4");
       delay(500);
       lcd.clear();
      lcd.setCursor(0,2);
      for(int i=0;i<1;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        lcd.print(teclado);
        i++;
       if(teclado='A'){
        lcd.clear();
        validar_trab1();}
      else if(teclado='B'){
         lcd.clear();
        validar_trab2();}
      else if(teclado='C'){ lcd.clear();
        validar_trab3();}
      else if(teclado='D'){ lcd.clear();
       validar_trab4(); }
    
      }
      }
  
 (millis()-arranque)>100;
 }
  if(fun==3){
   
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MODIFICAR CLAVES");
    lcd.setCursor(0,1);
    delay(5000);
     lcd.clear();
      delay(1000);
    lcd.clear();
     lcd.setCursor(0,0);
       lcd.print("A:TRABAJADRI1");
       delay(2000);
       lcd.setCursor(0,1);
       lcd.print("B:TRABAJADOR2");
       delay(2000);
       lcd.setCursor(0,2);
       lcd.print("C:TRABAJADRI3");
       delay(2000);
       lcd.setCursor(0,3);
       lcd.print("D:TRABAJADOR4");
       delay(2000);
       lcd.clear();
       delay(2000);
       lcd.clear();
      lcd.setCursor(0,2);
      for(int i=0;i<1;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        
        lcd.print(teclado);
        i++;
       if(teclado='A'){
        lcd.clear();
      modificar1();}
      else if(teclado='B'){
         lcd.clear();
        modificar2();}
      else if(teclado='C'){ lcd.clear();
        modificar3();}
      else if(teclado='D'){ lcd.clear();
       modificar4(); }
      
      }
      }
      
      (millis()-arranque)>100;
  }
   if(fun==4){
   
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ACTIVAR ALARMA");
    lcd.setCursor(0,1);
    lcd.print("CLAVE POR SERIAL");
    delay(500);
    if(digitalRead(mas)==LOW){
    digitalWrite(1,HIGH);
    delay(200);
    }
    
  
  (millis()-arranque)>100;
}
}
void funciones(){
  delay(50);
  if(fun<5)
    fun++;
  else
    fun=0;
}
void validar_admin(){
    lcd.setCursor(0,0);
    lcd.print("INGRESE CLAVE");
    delay(200);
    lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
 
  delay(1000);
  if((admin[0]==pass2[0])&&(admin[1]==pass2[1])&&(admin[2]==pass2[2])&&(admin[3]==pass2[3])&&(admin[4]==pass2[4])){
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("CLAVE");
      lcd.setCursor(0,2);
      lcd.print("CORRECTA");
      delay(500);
      cont=0;
      fun==1;
  }else{
    cont++;
    if(cont<3){
      lcd.setCursor(0,0);
      lcd.print("CLAVE ERRONEA");
      lcd.setCursor(0,1);
      lcd.print("INTENTE OTRA VEZ");
      delay(1000);
    }else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SISTEMA");
            lcd.setCursor(0,1);
            lcd.print("BLOQUEADO");
            delay(5000);
            fun==3;
          }
        }
      }
  void mostrardigitos(){
  if(digitalRead(mas)==LOW){ //si es leido el pulsador mas 
  delay(400); //hay un tiempo de espera de 400 ms
  if(i<99){ //si el contador es menor a 40
      b++; //el contador se incrementa 
      decenas=b/10; //las decenas se obtienen dividiendo el contador para 10
      unidades=b-(decenas*10); //obtencion de las unidades que se mostraran en el display 
    }else{ b=0; //caso contrario en contador regresa a 0 
      }
  }
  digitalWrite(unit,HIGH); //encendido del display para mostrar digitos unidades
  digitalWrite(dec,LOW);
  display(unidades);
  delay(100); //tiempo de refrescamiento 
  digitalWrite(unit,LOW);
  digitalWrite(dec,HIGH); //encendido del display mara mostrar digitos decenas
  display(decenas);
  delay(100); //tiempo de refrescamiento 
    }
  void validar_trab1(){
    lcd.setCursor(0,0);
    lcd.print("INGRESE CLAVE");
    delay(200);
    lcd.setCursor(0,2);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
  delay(1000);
  if((trabajador1[0]==pass2[0])&&(trabajador1[1]==pass2[1])&&(trabajador1[2]==pass2[2])&&(trabajador1[3]==pass2[3])&&(trabajador1[4]==pass2[4])){
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("CLAVE");
      lcd.setCursor(0,1);
      lcd.print("CORRECTA");
      delay(500);
      cont=0;
      fun==1;
  }else{
    cont++;
    if(cont<3){
      lcd.setCursor(0,0);
      lcd.print("CLAVE ERRONEA");
      lcd.setCursor(0,1);
      lcd.print("INTENTE OTRA VEZ");
      delay(1000);
    }else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SISTEMA");
            lcd.setCursor(0,1);
            lcd.print("BLOQUEADO");
            delay(1000);
            fun==3;
          }
        }
      }
    void validar_trab2(){
        lcd.setCursor(0,0);
    lcd.print("INGRESE CLAVE");
    delay(2000);
    lcd.setCursor(0,2);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  
  delay(1000);
  if((trabajador2[0]==pass2[0])&&(trabajador2[1]==pass2[1])&&(trabajador2[2]==pass2[2])&&(trabajador2[3]==pass2[3])&&(trabajador2[4]==pass2[4])){
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("CLAVE");
      lcd.setCursor(0,1);
      lcd.print("CORRECTA");
      delay(5000);
      cont=0;
      fun==1;
  }else{
    cont++;
    if(cont<3){
      lcd.setCursor(0,0);
      lcd.print("CLAVE ERRONEA");
      lcd.setCursor(0,1);
      lcd.print("INTENTE OTRA VEZ");
      delay(500);
    }else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SISTEMA");
            lcd.setCursor(0,1);
            lcd.print("BLOQUEADO");
            delay(5000);
            fun==3;
          }
        }
      }
    void validar_trab3(){
        lcd.setCursor(0,0);
    lcd.print("INGRESE CLAVE");
    delay(500);
    lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  
  delay(1000);
  if((trabajador3[0]==pass2[0])&&(trabajador3[1]==pass2[1])&&(trabajador3[2]==pass2[2])&&(trabajador3[3]==pass2[3])&&(trabajador3[4]==pass2[4])){
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("CLAVE");
      lcd.setCursor(0,1);
      lcd.print("CORRECTA");
      delay(1000);
      cont=0;
      fun==1;
  }else{
    cont++;
    if(cont<3){
      lcd.setCursor(0,0);
      lcd.print("CLAVE ERRONEA");
      lcd.setCursor(0,1);
      lcd.print("INTENTE OTRA VEZ");
      delay(1000);
     
    }else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SISTEMAS");
            lcd.setCursor(0,1);
            lcd.print("BLOQUEADO");
            delay(1000);
            fun==3;
          }
        }
      }
    void validar_trab4(){
        lcd.setCursor(0,0);
    lcd.print("INGRESE CLAVE");
    delay(1000);
    lcd.setCursor(0,2);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
  delay(1000);
  if((trabajador4[0]==pass2[0])&&(trabajador4[1]==pass2[1])&&(trabajador4[2]==pass2[2])&&(trabajador4[3]==pass2[3])&&(trabajador4[4]==pass2[4])){
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
      lcd.print("CLAVE");
      lcd.setCursor(0,1);
      lcd.print("CORRECTA");
      delay(1000);
      cont=0;
      fun==2;
  }else{
    cont++;
    if(cont<3){
      lcd.setCursor(0,0);
      lcd.print("ClAVE INCORRECTA");
      lcd.setCursor(0,1);
      lcd.print("INTENTE OTRA VEZ");
      delay(1000);
    }else{
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SISTEMA");
            lcd.setCursor(0,1);
            lcd.print("BLOQUEADO");
            delay(5000);
            fun==3;
          }
        }
      }
void modificar1(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("clave admin");
  lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
  if((admin[0]==pass2[0])&&(admin[1]==pass2[1])&&(admin[2]==pass2[2])&&(admin[3]==pass2[3])&&(admin[4]==pass2[4])){
    lcd.setCursor(0,2);
    lcd.print("Nueva Clave");
    lcd.setCursor(0,3);
    for(int i=0;i<5;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        trabajador1[i]=teclado;
        lcd.print('*');
        i++;
      }
    }
    lcd.print(" ");
    delay(500);
   
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
       lcd.print("ACCION");
      lcd.setCursor(0,1);
       lcd.print("EXITOSO");
      delay(500);
    fun=1;
  }else{
    lcd.setCursor(0,2);
    lcd.print("Clave Incorrecta");
    delay(1000);
    lcd.clear();
    fun=1;
  }
}
void modificar2(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("clave trabajador2");
  lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
if((admin[0]==pass2[0])&&(admin[1]==pass2[1])&&(admin[2]==pass2[2])&&(admin[3]==pass2[3])&&(admin[4]==pass2[4])){
  lcd.setCursor(0,2);
    lcd.print("Nueva Clave");
    lcd.setCursor(0,3);
    for(int i=0;i<5;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        trabajador2[i]=teclado;
        lcd.print('*');
        i++;
      }
    }
    lcd.print(" ");
    delay(500);
   
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
       lcd.print("ACCION");
      lcd.setCursor(0,1);
       lcd.print("EXITOSO");
      delay(500);
    fun=1;
  }else{
    lcd.setCursor(0,2);
    lcd.print("Clave Incorrecta");
    delay(1000);
    lcd.clear();
    fun=1;
  }
}
void modificar3(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("clave trabajador3");
  lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      pass2[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
if((admin[0]==pass2[0])&&(admin[1]==pass2[1])&&(admin[2]==pass2[2])&&(admin[3]==pass2[3])&&(admin[4]==pass2[4])){
    lcd.setCursor(0,2);
    lcd.print("Nueva Clave");
    lcd.setCursor(0,3);
    for(int i=0;i<5;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        trabajador3[i]=teclado;
        lcd.print('*');
        i++;
      }
    }
    lcd.print(" ");
    delay(500);
   
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
       lcd.print("ACCION");
      lcd.setCursor(0,1);
       lcd.print("EXITOSO");
      delay(500);
    fun=1;
  }else{
    lcd.setCursor(0,2);
    lcd.print("Clave Incorrecta");
    delay(1000);
    lcd.clear();
    fun=1;
  }
}
void modificar4(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("clave admin");
  lcd.setCursor(0,1);
  for(int i=0;i<5;i){
    char teclado = customKeypad.getKey();
    if(teclado){
      trabajador4[i]=teclado;
      lcd.print('*');
      i++;
    }
  }
  lcd.println(" ");
if((admin[0]==pass2[0])&&(admin[1]==pass2[1])&&(admin[2]==pass2[2])&&(admin[3]==pass2[3])&&(admin[4]==pass2[4])){
    lcd.setCursor(0,2);
    lcd.print("Nueva Clave");
    lcd.setCursor(0,3);
    for(int i=0;i<5;i){
      char teclado = customKeypad.getKey();
      if(teclado){
        trabajador4[i]=teclado;
        lcd.print('*');
        i++;
      }
    }
    lcd.print(" ");
    delay(500);
   
      lcd.clear();
      delay(500);
      lcd.setCursor(0,0);
       lcd.print("ACCION");
      lcd.setCursor(0,1);
       lcd.print("EXITOSO");
      delay(500);
    fun=1;
  }else{
    lcd.setCursor(0,2);
    lcd.print("Clave Incorrecta");
    delay(1000);
    lcd.clear();
    fun=1;
  }
}

      

void display(int a){
  //0
  switch(a){
    case 0:
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,0);
      digitalWrite(D,0);
    break;
  //1
    case 1:
      digitalWrite(A,1);
      digitalWrite(B,0);
      digitalWrite(C,0);
      digitalWrite(D,0);
    break;
  //2
    case 2:
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,0);
      digitalWrite(D,0);
    break;
  //3
    case 3:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,0);
      digitalWrite(D,0);
    break;
  //4
    case 4:
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,1);
      digitalWrite(D,0);
    break;
  //5
    case 5:
      digitalWrite(A,1);
      digitalWrite(B,0);
      digitalWrite(C,1);
      digitalWrite(D,0);
    break;
  //6
    case 6:
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,0);
    break;
  //7
    case 7:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,0);
    break;
  //8
    case 8:
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,0);
      digitalWrite(D,1);
    break;
  //9
    case 9:
      digitalWrite(A,1);
      digitalWrite(B,0);
      digitalWrite(C,0);
      digitalWrite(D,1);
    break;
  }
}
