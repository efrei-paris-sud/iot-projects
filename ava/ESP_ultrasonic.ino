// defines pins numbers
#define TRIGGER 12
#define ECHO 14

// defines variables
long duration = 0;
long distance = 0;

void setup() {
  Serial.begin(115200); // Starts the serial communication
pinMode(TRIGGER, OUTPUT); // Sets the trigPin as an Output
pinMode(ECHO, INPUT); // Sets the echoPin as an Input
}

void loop() {
// Clears the trigPin
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO, HIGH);
// Calculating the distance
distance= (duration*0.034)/2;
Serial.println("");
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(500);
}
