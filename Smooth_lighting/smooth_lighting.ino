#define PIN_LED 3
#define PHOTO_RES A0

boolean statusLed = false;
int valuePhoto = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PHOTO_RES, INPUT);

  Serial.begin(9600);
}

void loop() {
    valuePhoto = analogRead(PHOTO_RES);
    Serial.print("value Photo: "); Serial.println(valuePhoto);  
    
    if(valuePhoto <= 60 && statusLed == false) {
      for(int iter = 0; iter < 255; iter++) {
        analogWrite(PIN_LED, iter);
        delay(10);
      }
      statusLed = !statusLed;
    } 
    if(valuePhoto >= 65 && statusLed == true){
      for(int iter = 254; iter != 0; iter--) {
        analogWrite(PIN_LED, iter);
        delay(10);
      }
      statusLed = !statusLed;
      digitalWrite(PIN_LED, LOW);
    } 
}
