 const int trigPin = 6;//for PROTECTOR CIRCUIT
const int echoPin = 8;//for PROTECTOR CIRCUIT
const int buzzPin = 11;//for PROTECTOR CIRCUIT

float duration, distance;

const int triglPin = 12;//for LAMP CIRCUIT
const int echolPin = 10;//for LAMP CIRCUIT
const int buzzlPin = 04;//(led pin)for LAMP CIRCUIT

float duration1, distance1;

int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor


void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);

  pinMode(triglPin, OUTPUT);
  pinMode(echolPin, INPUT);
  pinMode(buzzlPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //CODING FOR PROTECTOR DEVICE
 digitalWrite(buzzPin, LOW);
  digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.println(duration);
  Serial.print("Distance for protector device: ");
  Serial.println(distance);
 
  if (distance>5){
      digitalWrite(buzzPin, HIGH);
    }
  
//CODING FOR LAMP
  digitalWrite(triglPin, LOW);
  delay(1000);
  digitalWrite(triglPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triglPin, LOW);

  duration1 = pulseIn(echolPin, HIGH);
  distance1 = (duration1*.0343)/2;
  Serial.print("dtance for lamp: ");
  Serial.println(distance1);

sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the scree


  if ((distance1<50) and (sensorValue>100)){
      digitalWrite(buzzlPin, HIGH);}
    else {digitalWrite(buzzlPin,LOW);}
      delay(1000);

}
