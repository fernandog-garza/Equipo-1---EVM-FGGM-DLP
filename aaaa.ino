int led1=13;
int led2=12;
int led3=11;
int boton1=6;
int boton2=3;
int boton3=2;
int lednow=random(1,4);
int contador = 0;
float tiempo = 0;
bool end=false;
unsigned long inicio;
unsigned long transcurrido;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
  inicio = millis();
}

void loop()
{
  if (end==true){
    Serial.println("Juego terminado");
    delay(1000000000000);
  }
   else if (end==false){
    transcurrido = millis() - inicio;
    if(lednow==1)
  {
    digitalWrite(led1,HIGH);
    if (digitalRead(boton1)==LOW)
    {
      contador++;
      digitalWrite(led1,LOW);
      lednow=random(1,4);
  
    }
    
    
  }
  else if(lednow==2)
  {
    digitalWrite(led2,HIGH);
    if (digitalRead(boton2)==LOW)
    {
      contador++;
      digitalWrite(led2,LOW);
      lednow=random(1,4);
    }  
     
  }
  else if(lednow==3)
  {
    digitalWrite(led3,HIGH);
    if (digitalRead(boton3)==LOW)
    {
      contador++;
      digitalWrite(led3,LOW);
      lednow=random(1,4);
    
    }  
   
  }
  Serial.println("contador:");
  Serial.println(contador);

  tiempo++;
  Serial.println("tiempo:");
  Serial.println(tiempo);
  if (transcurrido >= 10*1000)
  {
    Serial.println("Acabo el timer");
  end=true;
  }
  } 
}

