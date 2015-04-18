int colors[100];
int possition = 0;
int photo1 = 0;
int photo2 = 1;
int photo3 = 2;
int photo4 = 3;
int count = 1;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
boolean run = true;

void setup(){
  Serial.begin(9600);
  for(int i = 10; i < 14; i ++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  while(run){
    for(int i = 0; i<count; i++){
      record(possition);
      delay(1000);
      possition++;
    }
    for(int i = 0; i<count; i++){
      if (colors[i]==1){
        digitalWrite(led1, HIGH);
        delay(1000);
        digitalWrite(led1, LOW);
      }
      if (colors[i]==2){
        digitalWrite(led2, HIGH);
        delay(1000);
        digitalWrite(led2, LOW);
      }
      if (colors[i]==3){
        digitalWrite(led3, HIGH);
        delay(1000);
        digitalWrite(led3, LOW);
      }
      if (colors[i]==4){
        digitalWrite(led4, HIGH);
        delay(1000);
        digitalWrite(led4, LOW);
      }
    }
    possition = 0;
    count++;
    /*if(count > 4){
     run = false;
     }*/
  }

}

void record(int poss){
  boolean run = true;
  while(true){
    Serial.print("1: ");
    Serial.println(analogRead(photo1));
    if (analogRead(photo1) >= ave(photo2, photo3, photo4)){
      colors[poss] = 1;
      break;
    }
    Serial.print("2: ");
    Serial.println(analogRead(photo2));    
    if (analogRead(photo2) >= ave(photo1, photo3, photo4)){
      colors[poss] = 2;
      break;
    }
    Serial.print("3: ");
    Serial.println(analogRead(photo3));
    if (analogRead(photo3) >= ave(photo1, photo2, photo4)){
      colors[poss] = 3;
      break;
    }
    Serial.print("4: ");
    Serial.println(analogRead(photo4));
    if (analogRead(photo4) >= ave(photo1, photo2, photo3)){
      colors[poss] = 4;
      break;
    }
  }
};

int ave(int a, int b, int c){
  int sum = analogRead(a) + analogRead(b) + analogRead(c);
  return (sum/3)+150;
};

