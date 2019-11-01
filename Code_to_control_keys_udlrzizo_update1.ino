uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_up 2
#define PIN_down 3
#define PIN_left 4
#define PIN_right 5
#define PIN_zin 6
#define PIN_zout 7


int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_up, INPUT);
  pinMode(PIN_down, INPUT);
  pinMode(PIN_left, INPUT); 
  pinMode(PIN_right, INPUT);
  pinMode(PIN_zin, INPUT); 
  pinMode(PIN_zout, INPUT);
  // enable internal pull-ups
  digitalWrite(PIN_up, 1); 
  digitalWrite(PIN_down, 1); 
  digitalWrite(PIN_left, 1); 
  digitalWrite(PIN_right, 1);
  digitalWrite(PIN_zin, 1); 
  digitalWrite(PIN_zout, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_up);
  if (state != 1) {
    buf[2] = 82;   // up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 

  state = digitalRead(PIN_down);
  if (state != 1) {
    buf[2] = 81;   // down KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 

  state = digitalRead(PIN_left);
  if (state != 1) {
    buf[2] = 80;   // left KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 
  state = digitalRead(PIN_right);
  if (state != 1) {
    buf[2] = 79;   // right KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 
  state = digitalRead(PIN_zin);
  if (state != 1) {
    buf[2] = 87;   // zin KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 
  state = digitalRead(PIN_zout);
  if (state != 1) {
    buf[2] = 86;   // zout KEY
    Serial.write(buf, 8); // Send keypress
    releaseKey();
    delay(200);
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
