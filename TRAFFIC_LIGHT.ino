short REDLIGHT_PIN = 12, YELLOWLIGHT_PIN = 11, GREENLIGHT_PIN = 10;

void redLightBlink();
void yellowLightBlink();
void greenLightBlink();

void setup() {

  Serial.begin(9600);
  pinMode(REDLIGHT_PIN, OUTPUT);
  pinMode(YELLOWLIGHT_PIN, OUTPUT);
  pinMode(GREENLIGHT_PIN, OUTPUT);

}

void loop() {
  
  redLightBlink();
  yellowLightBlink();
  greenLightBlink();
    
}

void redLightBlink() {

  digitalWrite(REDLIGHT_PIN, HIGH);
  digitalWrite(YELLOWLIGHT_PIN, LOW);
  digitalWrite(GREENLIGHT_PIN, LOW);
  delay(5000);

}

void yellowLightBlink() {

  digitalWrite(REDLIGHT_PIN, LOW);
  digitalWrite(YELLOWLIGHT_PIN, HIGH);
  digitalWrite(GREENLIGHT_PIN, LOW);
  delay(5000);

}

void greenLightBlink(){

  digitalWrite(REDLIGHT_PIN, LOW);
  digitalWrite(YELLOWLIGHT_PIN, LOW);
  digitalWrite(GREENLIGHT_PIN, HIGH);
  delay(5000);

}
