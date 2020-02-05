int buttonPin = 2;
int relayPin = 3;
int relayState = HIGH;
int buttonState;              //REcord the Current button State
int lastButtonState = LOW;    //Record the Last button State
long lastDebounceTime = 0;   
long debounceDelay = 50;    //elliminate Debounce time

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, relayState); //Configure the initial State of the Relay
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);   //Obtain the button's state
  //Once it detects the change of state, records time
  if(reading != lastButtonState){
    lastDebounceTime = millis();  //Set the last Debounce Time to the instantaneous clock time
  }
  //wait for 50ms to evaluate if its the same state as the last state
  //if different, change the button state
  //if the state of button is high(pressed), change the state of relay
  if((millis()-lastDebounceTime)>debounceDelay){
    if(reading != buttonState){
      buttonState = reading;
      if(buttonState == HIGH){
        relayState = !relayState;
      }
    }
  }
  digitalWrite(relayPin, relayState);
  //Change the last state of button
  lastButtonState = reading;
} 
