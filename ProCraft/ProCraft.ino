#define pinVRx A0
#define pinAccelerator A1
#define pinBrake A2
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_MULTI_AXIS, 10, 0,  // Alterado para 6 eixos
  true, true, true, true, true, true,
  true, true, true, true, true);

void setup() {
  pinMode(pinVRx, INPUT);
  pinMode(pinAccelerator, INPUT);
  pinMode(pinBrake, INPUT);
  Joystick.begin();
  Serial.begin(9600);
}

void loop() {
  int valorVRx = analogRead(pinVRx);
  int valorAccelerator = digitalRead(pinAccelerator); // Leitura do acelerador
  int valorBrake = digitalRead(pinBrake); // Leitura do freio
  // Envie os valores mapeados para os eixos do joystick
  Joystick.setXAxis(valorVRx);
  Joystick.setYAxis(512); // Manter o eixo Y fixo, se necessário ajuste conforme a necessidade
  Serial.println(valorBrake);
  //Joystick.setBrake(valorBrake); // Mapeia o acelerador
  //Joystick.setAccelerator(valorAccelerator); // Mapeia o freio

  Joystick.setButton(0, valorBrake);
  Joystick.setButton(1, valorAccelerator);

  // Aguarde um curto período antes de enviar novos dados
  delay(50);
}