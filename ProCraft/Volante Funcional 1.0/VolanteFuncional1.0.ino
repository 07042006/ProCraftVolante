#define pinVRx A0
#define pinSW 2
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, 4, 0,
  true, true, true, true, true, true,
  true, true, true, true, true);

void setup() {
  pinMode(pinVRx, INPUT);
  pinMode(pinSW, INPUT_PULLUP);
  Joystick.begin();
  Serial.begin(9600);
}

void loop() {

  int valorVRx = analogRead(pinVRx);
  bool statusSW = digitalRead(pinSW);

  int mappedValue = map(valorVRx, 0, 1023, -512, 512);  // Mapeie para o intervalo de -512 a 512

  // Envie o valor mapeado para o eixo X do joystick
  Joystick.setXAxis(valorVRx);
  Joystick.setYAxis(512);

  // Defina o botão do volante
  Joystick.setButton(0, !statusSW);  // Configurando o botão 0 conforme o estado do switch

  // Aguarde um curto período antes de enviar novos dados
  delay(50);
}