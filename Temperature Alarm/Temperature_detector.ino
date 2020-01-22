float sinVal;
int toneVal;
unsigned long tepTimer;

void setup() {
	pinMode(8, OUTPUT);  //configuring buzzer pin as an OUTPUT
	Serial.begin(9600);     //configuring Baud rate to 9600 bps
}

void loop() {
	int val;
	double data;
	val analogRead(0);
	data = (double) val*(5/10.24)        //converting voltage value to Temperature value

	if (data > 27) {                        // if Temperature is highe than 27, the buzzer makes a sound
		for(int x=0; x<180; x++) {
			sinVal = (sin(x*(3.142/180)));        //converting the sin function to radians
			toneVal = 2000 + (int(sinVal*1000));      // using sin function to generate frequency of sound
			tone(8, toneVal);       //configuring the buzzer at pin 8
			delay(2);
		}
	}else {
		noTone(8);    //Turning off the buzzer
	}
	if (millis() - tepTimer > 50 ) {      // Every 500ms the Serial monitor outputs temperature value
		tepTimer = millis();
		Serial.print("Temperature: ");
		Serial.print(data);
		Serial.println("C");
	}
}
	
