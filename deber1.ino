/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * NOMBRE:WILMERBENAVIDES
 * DEBER:
 * 1.- Realizar un juego de lueces que se prendan secuencialmente los leds impartes (1,3,5). 
 *  int leds[6]={0,1,2,3,4,5}; // defino vector para configurar leds
int i=1; // variable de recorrido del vector

void setup() {
  // configuracion de pines en forma impar con icrementos de 2
  for(;i<6;i++){
     pinMode(leds[i],OUTPUT);
    }
    i=1;  // reseteo la variable de conteo
   
}

void loop() {
  for(;i<6;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
      delay(200);  
      i=i+1;
      }
     for(;i>=0;i--){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200);
      i=i-1;
     }}
 * 2.- Realizar un programa que se enciendan uno por uno los leds pares (0,2,4). 
 *  int leds[6]={0,1,2,3,4,5}; // defino vector para configurar leds
int i=0; // variable de recorrido del vector

void setup() {
  // configuracion de pines en forma impar con icrementos de 2
  for(;i<6;i++){
     pinMode(leds[i],OUTPUT);
    }
    i=0;  // reseteo la variable de conteo
   
}

void loop() {
  for(;i<6;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
      delay(200);  
      i=i+1;
      }
     for(;i>=0;i--){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200);
       i=i-1;
     }}
 * 3.- Realizar un juego que se enciendan y apaguen los leds de forma aleatoria. (Consultar random)
 * 
 */
 
int leds[6]={0,1,2,3,4,5}; // defino vector para configurar leds
int i; // variable de recorrido del vector
int num;
void setup() {
  // configuracion de pines en forma impar con icrementos de 2
  for(i=0;i<6;i++){
     pinMode(leds[i],OUTPUT);
    }
    randomSeed(analogRead(0));
      
}

void loop() {
 
  while(i>7);
   num=random(0,7);
  for(i=0;i<num;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
      delay(200);  
      
      }
     for(i=0;i<num;i++){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200);
     
     }}
