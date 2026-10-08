
const int IRsensor = 7;

unsigned long seconds = 0;
int RPM = 0;

int previousState = HIGH;
bool finished = false;

void setup() {
  pinMode(IRsensor, INPUT);
  Serial.begin(9600);

  previousState = digitalRead(IRsensor);
}

void loop() {

  // Count seconds from Arduino startup
  seconds = millis() / 1000;

  int IRsensorState = digitalRead(IRsensor);

  // Count rotations during the first minute
  if (seconds < 60) {

    if (IRsensorState == LOW &&
        previousState == HIGH) {

      RPM = RPM + 1;
      Serial.println(RPM);
    }
  }

  previousState = IRsensorState;

  // Display final RPM after 60 seconds
  if (seconds >= 60 && !finished) {

    Serial.print("Final RPM: ");
    Serial.println(RPM);

    finished = true;
  }
}
