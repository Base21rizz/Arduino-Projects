
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int direction{1};
int outputVar{1};
int five = 5;
int six = 6;


void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Engine Started!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() { // run over and over
  if (mySerial.available()) {
    int direction = mySerial.read();
    direction = direction -'0';
Serial.write(direction);

    if(direction == 1)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
    }
    else if(direction == 2)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
    }
    else 
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
  }
  delay(10);
}
