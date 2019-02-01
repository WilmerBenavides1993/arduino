/*           UNIVERSIDAD TÉCNICA DEL NORTE
                    FICA-CIERCOM
              SISTEMAS MICROPROCESADOS
   INTEGRANTES_ BENAVIDES WILMER
                CHICAIZA FREDDY
                MACAS CHRISTOFER

   En base a la  base de datos recopilada por su sensor ecg y realice el mismo proceso de la evaluación parcial.
*/

#define ARM_MATH_CM3 // libreria de calculos matematicos
#include <arm_math.h>
#define tam_Signal 194 // tamaño de los datos del sensor cardiaco
#define tam_impulse 29 // tamaño para del impulso_response

extern float32_t InputSignal[tam_Signal];// llamamos a los array de datos  de la señal cardiaca
extern float32_t Impulse_response[tam_impulse];// llamamos a los array de datos del impulso

float32_t signal_out[tam_Signal + tam_impulse];// variables para las señales de salida se suman los dos valores de las señales ya que el resultado seran las 2
float32_t OutputSignal1 [tam_Signal];

float32_t REX1[tam_Signal];// variables para la tdf
float32_t IDX1[tam_Signal];


void setup() {
  Serial.begin(9600);
}

void loop() {
  // mostrar impulso
  // plot_impulso_original();

  // mostrar señal del corazon
  // plot_sig_original();

  //convolucion

  //    arm_conv_f32(&InputSignal[0], tam_Signal, &Impulse_response[0], tam_impulse, &signal_out[0]);
  //     plot_sig(signal_out, tam_Signal + tam_impulse);


  //suma de la señal

  //  suma(&InputSignal[0], &OutputSignal1[0], tam_Signal);
  //   plot_sig1();

  // resta de la señal
  //  resta(&InputSignal[0], &OutputSignal1[0], tam_Signal);
  //   plot_sig1();



  //transformada de la primera señal

  cal_tdf(&InputSignal[0], &REX1[0], &IDX1[0], tam_Signal);
  get_tdf1();
  plot_signal2();

}
// metodo para mostrar el impulso_response
void plot_impulso_original() {
  uint32_t i;
  for (i = 0; i < tam_impulse ; i++) {
    Serial.println(Impulse_response[i]);
    delay(10);
  }
}

// metodo para mostrar la señal cardiaca
void plot_sig_original() {
  uint32_t i;
  for (i = 0; i < tam_Signal; i++) {
    Serial.println(InputSignal[i]);
    delay(10);
  }
}

// moetdo de mostrar la suma y resta de las señales 
void plot_sig1() {
  uint32_t i;
  for (i = 0; i < tam_Signal; i++) {
    Serial.println(OutputSignal1[i]);
    delay(10);
  }
}
// metodo para mostrar la convolucion de las 2 señales
void plot_sig(float32_t *sig_entrada, uint32_t tam_sig) {
  uint32_t i;
  for (i = 0; i < tam_sig; i++) {
    Serial.println(sig_entrada[i] * 100);
    delay(10);
  }
}



//metodo que suma las dos señales

void suma(float32_t *input, float32_t *output, uint32_t tam) {
  uint32_t i;
  for (i = 0; i < tam; i++) {
    output[i] = input[i] + output[i - 1];
  }
}
//metodo de resta de las dos señales
void resta(float32_t *input, float32_t *output, uint32_t tam) {
  uint32_t i;
  for (i = 0; i < tam; i++) {
    output[i] = input[i] - input[i - 1];
  }
}

//metodo para el calculo de la trasformada discreta de fourier
void cal_tdf(float32_t *input_sig, float32_t *sig_rex, float32_t *sig_idx, uint32_t tam) {

  uint32_t i, j, k;
  for (j = 0; j < tam; j++) {
    sig_rex[j] = 0;
    sig_idx[j] = 0;
  }

  for (k = 0; k < tam; k++) {
    for (i = 0; i < tam; i++) {
      sig_rex[k] = sig_rex[k] + input_sig[i] * cos(2 * PI * k * i / tam);
      sig_idx[k] = sig_idx[k] - input_sig[i] * sin(2 * PI * k * i / tam);
    }
  }
}

void get_tdf1(void) {
  uint32_t i;
  for (i = 0; i < tam_Signal; i++) {
    OutputSignal1[i] = sqrt(pow(REX1[i], 2) + pow(IDX1[i], 2));
  }
}

//metodo para la impresion de la transformada de la primera señal
void plot_signal2() {
  uint32_t i;
  for (i = 0; i < tam_Signal; i++) {
    Serial.println(OutputSignal1[i]);

  }
}
