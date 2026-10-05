#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  while(BTSerial.available()>0){
    char receivedChar=BTSerial.read();
    Serial.print("Mensaje recibido: ");
    Serial.println(receivedChar);
    if(receivedChar=='1'){
      Serial.println("Se recibio comando de encendido");
      digitalWrite(13,HIGH);
    } else if (receivedChar=='0'){
         Serial.println("Se recibio comando de apagado");
         digitalWrite(13,LOW);
         BTSerial.println("Se apagó el LED");
    } else{
      Serial.println("Se recibió comando inválido");
      BTSerial.println("No hubo acción, comando inválido");
    }
  }
}
