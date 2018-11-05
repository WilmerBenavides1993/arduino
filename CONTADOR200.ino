
 /*UNIVERSIDAD TECNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: WILMER BENAVIDES 
 *  realizar un sistema que permita contar de forma automática 
 * (sin pulsador, el sistema inicia y empieza a contar sin necesidad de una actividad del usuario). 
 * Del 1 al 200 mediante la multiplexación de displays.
  */
int A=4;//variables para contros del 7447
int B=3;//variables para contros del 7447
int C=2;//variables para contros del 7447
int D=1;//variables para contros del 7447
int i=0;//variable para el contador en cero
int m=0;//variable para el contador en cero
int dec =8;// variable de salida y control de decimales
int uni =9;// variable de salida y control de unidades
int cent=10;// variable de salida y control de centenas
int unidades;// variables para operaciones
int decenas;
int centenas;

 void setup() {
  pinMode(A,OUTPUT);// declaramos si son salida o entrada de datos
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);  
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  pinMode(cent,OUTPUT);
}

void loop() {
 for(;m<200;m++){// iniciamos un ciclo repetitivo para que vaya de 0 a 200
    if( i<200){// pregunta si es menor de 200 procedemos a hacer los calculos de dec,uni,cent
      i++;// incrementamos por cada vuelta uno
      decenas=i/10-(centenas*10);// calculo para las decenas 
      unidades=i-(decenas*10)-(centenas*100);//calculo para unidades
      centenas=i/100;//calculo para centenos
  }
    else {// caso contrario se pone en cero 
      i=0;
    }
    
//control de los multiplexores con los display
   digitalWrite(uni,HIGH);
   digitalWrite(dec,LOW);
   digitalWrite(cent,LOW);
   display(unidades);
   delay(100);
    digitalWrite(uni,LOW);
    digitalWrite(dec,HIGH);
    digitalWrite(cent,LOW);
    display(decenas);
    delay(100);
     digitalWrite(uni,LOW);
     digitalWrite(dec,LOW);
     digitalWrite(cent,HIGH);
     display(centenas);
     delay(100);  
     }
       m=0;
     }
     
void display(int j ){
 switch(j){
  //0
  case 0:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;
  //1
  case 1:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;  
    //2
    case 2:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
 break;
  //3
  case 3:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break; 
  //4
  case 4:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
  //5
  case 5:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
  //6
  case 6:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
break;
  //7
  case 7:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
    //8
    case 8:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
  //9
  case 9:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
}
}
