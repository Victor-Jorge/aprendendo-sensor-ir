#include <IRremote.h>

#define receptor 7

float valor;

IRrecv recIR(receptor);
decode_results resultado;


void Setup() {
  Serial.begin(9600);
  recIR.enableIRIn();
}

void Loop(){
  if(recIR.decode(&resultado)){
    valor=(resultado.value);
    Serial.print("valor: "); Serial.println(valor, HEX);
    recIR.resume();
  }

}