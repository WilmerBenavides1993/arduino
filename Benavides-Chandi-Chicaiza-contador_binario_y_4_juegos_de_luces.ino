/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * INTEGRANTES: WILMER BENAVIDES, FREDY CHICAIZA, ARMANDO CHANDI
 * pinMode(pin,modo) -> pin 0 ->13
 * modo imput u output
 * digitalRead(pin)
 * 
 */
int j=1;
int i=0;
int numero=0; //el contador inicia en 0
int leds[5]={2,3,4,5,6};// pin como salida para led
int sw=8;// pin para el switch
int sw2=10;// pin para el switch
int sw3=11;// pin para el switch
int sw1=9; // pin para el switch
int sw0=7; // pin para el pulsador

void setup() {
for(;i<6;i++){
     pinMode(leds[i],OUTPUT);// leds de salida
    }
    i=0;
    pinMode(sw1,INPUT);//sw como entrada
     pinMode(sw2,INPUT);//sw como entrada
      pinMode(sw3,INPUT);//sw como entrada
       pinMode(sw,INPUT);//sw como entrada
        pinMode(sw0,INPUT);//sw como entrada
}
void loop() {
  int k; // Declaro variable k
if (digitalRead(sw0)==HIGH){ // Si presiono el pulsador
numero++; // Aumento el contador
if (numero>32){ // El contador llega a 255, 8bits 8 leds
numero=0; // vuelve a 0
}
while (digitalRead(sw0)==HIGH){} // Al presionar no hace nada mas
}
k=numero; // El numero va a variable k
for(int i=2; i<=6; i++){ //Ciclo para ver que leds prendo
digitalWrite(i, k%2); // modulo de la division por 2 para ver si led prendido o apagado
k=k/2; // Se divide el cociente entre 2 por cada ciclo
}
 if(digitalRead(sw)==HIGH){// pregunta si switch esta en alto
    for(;i<6;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
       delay(200);  // tiempo de espera de 2s
        i=i+1;// incremento del contador
      }
     for(;i>=0;i--){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200);
        i=i+1;
     }
     }
     
 else if (digitalRead(sw1)==HIGH){// pregunta si switch esta en alto
  for(;i<6;i++){
    digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
     delay(200);                  //espero
      digitalWrite(leds[i],LOW);   // apago posicion i del vector
       delay(200);                   //espero
    }
    i=0;    // reset de variable de conteo
    
    for(;i<6;i++){
      digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
       delay(200);  
      }
     for(;i>=0;i--){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200); 
      }
      }
       else if (digitalRead(sw2)==HIGH){ // pregunta si switch esta en alto
         i=0;  // j=5 
      for(;i<3;i++){//contador del 0 al 3
        digitalWrite(leds[i],HIGH);// enciende el juego de luces
        digitalWrite(leds[5-i],HIGH);// enciende el juego de luces hasta la mitad y regresa
        delay(200);
        }
        i=2;
        for(;i>=0;i--){
          digitalWrite(leds[i],LOW);// apagamos los leds
           digitalWrite(leds[5-i],LOW);
          delay(200);
          }
     i=0;

       }
        else if (digitalRead(sw3)==HIGH){
         while(i>7);// mientras sea mayor a 7 sigue trabajando
          int num=random(0,7);//generacion de numeros randomicos 
           for(i=0;i<num;i++){ // ciclo repetevitivo 
             digitalWrite(leds[i],HIGH);  // encendiendo posicion i del vector
              delay(200);  
      
      }
     for(i=0;i<num;i++){
      digitalWrite(leds[i],LOW);  // encendiendo posicion i del vector
       delay(200);
       }
       }
       
      else
        digitalWrite(leds[i],LOW);// que todos los leds permanescan apagados
}
