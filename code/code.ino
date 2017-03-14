const byte trigPin = 9;
const byte echoPin = 10;
const byte valvePin = 12;
const byte testPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(valvePin, OUTPUT);
}

void loop() {
  long duration=0, distance=0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);
  delay(1000);
  if (distance < 8) {
    digitalWrite(valvePin, LOW);
    digitalWrite(testPin, LOW);
  }
  else {
    digitalWrite(valvePin, HIGH);
    digitalWrite(testPin, HIGH);
  }
}
