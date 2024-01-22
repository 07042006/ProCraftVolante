
const int volantePin = A0;
const int freioPin = 8;
const int aceleradorPin = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(volantePin, INPUT_PULLUP);
  pinMode(freioPin, INPUT_PULLUP);
  pinMode(aceleradorPin, INPUT_PULLUP);
}

void loop()
{
  int valueVolante = analogRead(volantePin);
  int freioPressionado = digitalRead(freioPin) == LOW;
  int aceleradorPressionado = digitalRead(aceleradorPin) == LOW;
  
  Serial.print(valueVolante);
  Serial.print(freioPressionado ? "Freio Pressionado" : " ");
  Serial.println(aceleradorPressionado ? "Acelerar Pressionado" : " ");
}