#define DATA_PIN 7
#define SH_PIN 5
#define ST_PIN 6

byte numbers[8] = {
  B00000001, 
  B00000010, 
  B00000100, 
  B00001000,
  B00010000, 
  B00100000, 
  B01000000, 
  B10000000
};

int pos = 0;
int dir = 1;

void setup() {
  Serial.begin(9600);

  pinMode(DATA_PIN, OUTPUT);
  pinMode(SH_PIN, OUTPUT);
  pinMode(ST_PIN, OUTPUT);

  digitalWrite(ST_PIN, LOW);
}

void loop() {
  pos += dir;
  send_data_74HC595(numbers[pos]);

  Serial.print("pos: "); Serial.print(pos);
  Serial.print("\tdir: "); Serial.print(dir);
  Serial.print("\tvalue: "); Serial.println(numbers[pos]);

  if(pos == 7) dir = -1;
  if(pos == 0) dir = 1;

  delay(25);
}

void send_data_74HC595(byte value) {
  for(int iter = 0; iter < 8; iter++) {
    digitalWrite(SH_PIN, LOW);
    digitalWrite(DATA_PIN, bitRead(value, iter));
    digitalWrite(SH_PIN, HIGH);
  }

  digitalWrite(ST_PIN, HIGH);
  digitalWrite(ST_PIN, LOW);
}
