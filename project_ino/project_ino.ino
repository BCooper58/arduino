int bluePin = 9;
int greenPin = 8;
int redPin = 7;
int trigPin = 5;
int echoPin = 6;
long duration, cm, inches;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int distance = 0;

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if(distance > 0 && distance <=20){
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    delayMicroseconds(5);
    digitalWrite(redPin, HIGH);
    delayMicroseconds(5);
  }
  
  else if(distance >20 && distance <=80){
    digitalWrite(redPin,LOW);
    digitalWrite(bluePin,LOW);
    delayMicroseconds(5);
    digitalWrite(greenPin,HIGH);
    delayMicroseconds(5);
  }
  
  else if(distance >80){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    delayMicroseconds(5);
    digitalWrite(bluePin,HIGH);
    delayMicroseconds(5);
  }
  
  Serial.print(distance);
  Serial.println();
  
  delay(250);
  
}
  
