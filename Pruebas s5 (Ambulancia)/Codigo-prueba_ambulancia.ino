const int trig = 12;
const int echopin = 11;
const int buzzer = 10;
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
unsigned long ultimoCambio = 0;
bool buzzerEncendido = false;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  Serial.begin(9600);
}
void detener() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
void adelante() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}
void reversa() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}
void girar() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  analogWrite(motor2pin2, 10);
}
int medirDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echopin, HIGH, 30000); 
  if (duration == 0) return -1;                         
  return duration * 0.0343 / 2;
}
void sensorbuzzer() {
  int cm = medirDistancia();
  Serial.println(cm);
  if (cm <= 0 || cm >= 60) {
    noTone(buzzer);
    buzzerEncendido = false;
    Serial.println("Objeto fuera de alcance");
    delay(50);
    return;
  }
  if (cm < 10) {
    tone(buzzer, 600);
    buzzerEncendido = true;
    delay(50);
    return;
  }
  unsigned long intervalo;
  if (cm < 20)      intervalo = 50;
  else if (cm < 30) intervalo = 100;
  else if (cm < 40) intervalo = 300;
  else if (cm < 50) intervalo = 500;
  else              intervalo = 1000;
  if (millis() - ultimoCambio >= intervalo) {
    ultimoCambio = millis();
    buzzerEncendido = !buzzerEncendido;
    if (buzzerEncendido) tone(buzzer, 600);
    else noTone(buzzer);
  }
  delay(50);
}
void esperar(unsigned long ms, bool sensorActivo) {
  unsigned long inicio = millis();
  while (millis() - inicio < ms) {
    if (sensorActivo) sensorbuzzer();
  }
  noTone(buzzer);
  buzzerEncendido = false;
}
void loop() {
  adelante();
  esperar(1000, false);
  detener();   
  esperar(1000, false);
  reversa();   
  esperar(10000, true);  
  detener();   
  esperar(1000, false);
  girar();     
  esperar(1000, false);
  detener();   
  esperar(1000, false);
}