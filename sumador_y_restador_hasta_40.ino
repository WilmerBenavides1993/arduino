/*UNIVERSIDAD TECNICA DEL NORTE 
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * Nombre: WILMER BENAVIDES 
 * Realizar un programa que medienta un pulsador se aumente el valor de un contador (1 al 40) 
 * y mediante otro pulsador se reste ese valor. El visualización del proceso se lo hace en displays.
*/
int A=4;//declaracion de variables para controlar el 7447
int B=3;//declaracion de variables para controlar el 7447
int C=2;//declaracion de variables para controlar el 7447
int D=1;//declaracion de variables para controlar el 7447
int mas=5;//declaracion de variable para sumar 
int menos=6; //declaracion de variables para restar 
int i=0;
int dec=8;
int unit=9;
int decenas;
int unidades;
 
void setup() {
  
  pinMode(A,OUTPUT);// asignamos si las salidas son de lectrura o escritura
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(mas,INPUT);
  pinMode(menos,INPUT);
   pinMode(dec,OUTPUT);
  pinMode(unit,OUTPUT);
  

}

void loop() {
  if(digitalRead(mas)==HIGH){// comparamos la entrada si esta en alto realiza la suma 
    delay(200);// esperamos 2s
    if(i<40){// controlamos hasta que numero va ir el contador
      i++;// designamos si el conteo va ascendente 
      decenas=i/10;// operacion para que las decenas 
      unidades=i-(decenas*10);// operacion para las unidades
    }else{ i=0;
      }
  }
  if(digitalRead(menos)==HIGH){// comparamos la entrada si esta en alto realiza la suma 
    delay(400);
    if(i<40){
      i--;//  asignamos que la cuenta va ha ser inversa 
      decenas=i/10;
      unidades=i-(decenas*10);
    }else{ i=0;
      }
  }// proceso para controlar la multiplexacion de los display
  digitalWrite(unit,HIGH);
  digitalWrite(dec,LOW);
  display(unidades);
  delay(100);
  digitalWrite(unit,LOW);
  digitalWrite(dec,HIGH);
  display(decenas);
  delay(100);
  }
  void display (int j){
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
}}
