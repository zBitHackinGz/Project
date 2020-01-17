// arduino.robotics-club.com.ru

int pins[8] = { 11, 10, 9, 8, 7, 6, 5, 4 };
byte numbers[10] = {
  B11111100, B01100000, B11011010, B11110010, B01100110,
  B10110110, B10111110, B11100000, B11111110, B11100110
};

int number = 0;

void setup() {
  for(int iter = 0; iter < 8; iter++) {
    pinMode(pins[iter], OUTPUT);
    digitalWrite(pins[iter], LOW);
  }
}

void loop() {
  setNumber(number);
  delay(1000);

  number = (number + 1) % 10;
}

void setNumber(int num) {
  for(int iter = 0; iter < 7; iter++) {
    if(bitRead(numbers[num], 7-iter) == HIGH)
      digitalWrite(pins[iter], HIGH);
    else digitalWrite(pins[iter], LOW);
  }
}
