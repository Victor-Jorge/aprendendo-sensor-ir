#include <IRremote.h>
#define IR_RECEIVE_PIN 3
#define PIN_LED 11

bool estadoLed = false;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  Serial.println("Aponte o controle e pressione um botão...");
}

void loop() {
  if (IrReceiver.decode()) {

    // ── Leitura dos dados ──────────────────────────────
    uint32_t codigoRaw     = IrReceiver.decodedIRData.decodedRawData; // código completo (ex: 0xFD00FF)
    uint8_t  comando       = IrReceiver.decodedIRData.command;         // apenas o byte de comando
    uint8_t  endereco      = IrReceiver.decodedIRData.address;         // endereço do dispositivo
    String   protocolo     = getProtocolString(IrReceiver.decodedIRData.protocol);

    // ── Ignora repetições automáticas ─────────────────
    bool ehRepeticao = IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT;

    if (!ehRepeticao) {
      // ── Imprime tudo no Serial ───────────────────────
      Serial.println("─────────────────────────");
      Serial.print("Protocolo : "); Serial.println(protocolo);
      Serial.print("Raw (HEX) : 0x"); Serial.println(codigoRaw, HEX);
      Serial.print("Endereço  : 0x"); Serial.println(endereco,  HEX);
      Serial.print("Comando   : 0x"); Serial.println(comando,   HEX);
    }

    IrReceiver.resume();
  }
}