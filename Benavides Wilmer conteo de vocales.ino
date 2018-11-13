/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA-CIERCOM 
 * SISTEMAS MICROPROCESADOS 
 * Nombre: WILMER BENAVIDES
 * realizar un sistema que permite determinar el número de vocales dentro de una palabra. Este dato es ingresado por comunicación serial 
 * y la respuesta del mismo de igual manera. Subir su link de github. Ejemplo 1: Ingreso: CIERCOM Retorna: 3 Ejemplo 2. Ingreso: DATOS Retorna: 
 */

#include<stdlib.h> //libreria
int i=0;//la variable i para el ciclo 
int cont=0; //la variable c es el contador 
String str; // variable string 
int tam; //variable donde se almacenara el vector palabra 
char palabra; // para guardar la cadena de letras
void setup() {
  Serial.begin(9600); //inicia la comunicacion serial
  Serial.println("Ingrese la palabra"); // texto de inicio
  for (i=0;i<50;i++){
    }
  i=0;
}

void loop() {
if(Serial.available()>0){ //se valida la comunicacion serial 
       str=Serial.readString(); // se lee el dato ingreado por serial
       tam=str.length(); //tamaño de la palabra y lo guarda en la variable tam
       char vector [tam];
       str.toCharArray(vector,tam+2); //conversion de string a char con el tamaño 
       palabra=vector[1]; // vector palabra 
       delay(500);// tiempo de espara
 for (i=0;i<20;i++){ //ciclo for  busca de vocales letra por letra
if (vector[i]=='a' || vector[i]=='e' || vector[i]=='i' || vector[i]=='o' || vector[i]== 'u' ||vector[i]=='A' || vector[i]=='E' || vector[i]=='I' || vector[i]=='O' || vector[i]== 'U' ){//conciones (o) de busqueda de letras  
cont++; // el contador  aumenta en uno
Serial.println("");//salto de linea para espaciar
}

  } 

Serial.println("numero de vocales: ");//texto referencia
Serial.println(cont); //se imprime el numero de vocales 
cont=0;//el contador de vocales vuelve a 0 para que se pueda analizar otra palabra 
 Serial.println("Ingrese la palabra"); // texto de inicio
}
}
 
