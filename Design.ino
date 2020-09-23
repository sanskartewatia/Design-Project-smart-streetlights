const int trigPin = 2;
const int echoPin = 4;

void setup()
{
	pinMode(13, OUTPUT);
	Serial.begin(9600);
	while (!Serial);
	Serial.println("Input 1 to Turn LED on");
}

void loop() {
long duration, inches;
  int status;
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration);
if(inches<591)
  status=1;
 else
  status=0;
  

if (Serial.available())
	{
	int state = Serial.parseInt();
	if ((state == 1)||(status == 1))
	{
    	digitalWrite(13, HIGH);
		Serial.println("Command completed LED turned ON");
		delay(3500);
		digitalWrite(13, LOW);
        Serial.println("Command completed LED turned OFF");
	}
}
}

long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}