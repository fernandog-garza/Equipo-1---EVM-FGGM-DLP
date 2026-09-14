const int boton = 2;
const int led = 13;

void setup() {
  pinMode(boton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(boton) == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("Encendido");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("Apagado");
  }

  delay(100);
}