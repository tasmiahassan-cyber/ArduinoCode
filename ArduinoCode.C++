
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

void loop(){
    int IRsensorState = digitalRead(IRsensor);
    if(IRsensorState == LOW){
        RPM = RPM + 1;
        println(RPM);
    } else if(IRsensorState == HIGH){
        println("Detected nothing");
    }
}

// TODO for Tasmnia:
// Implement the seconds variable functionality for it must:
//1. Represent the real world seconds once the arduino starts/
//count the seconds from when the arduino starts
//2. Once the seconds reach 60 seconds, the RPM variable stops counting upwards,
//since it is the RPM measurement in the minute