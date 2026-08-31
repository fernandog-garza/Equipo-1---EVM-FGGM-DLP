int led1=13;
int led2=12;
int led3=11;
int boton1=6;
int boton2=3;
int boton3=2;
int lednow=random(1,4);


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
}

void loop()
{
  if(lednow==1)
  {
    digitalWrite(led1,HIGH);
    if (digitalRead(boton1)==LOW)
    {
      digitalWrite(led1,LOW);
      lednow=random(1,4);
      delay(100);
    }
    
  }
  else if(lednow==2)
  {
    digitalWrite(led2,HIGH);
    if (digitalRead(boton2)==LOW)
    {
      digitalWrite(led2,LOW);
      lednow=random(1,4);
      delay(100);
    }  
  }
  else if(lednow==3)
  {
    digitalWrite(led3,HIGH);
    if (digitalRead(boton3)==LOW)
    {
      digitalWrite(led3,LOW);
      lednow=random(1,4);
      delay(100);
    }  
  }
}