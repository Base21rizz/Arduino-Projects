#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(10, 11); // RX, TX

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

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Engine ON");
  delay(1000);
  lcd.clear();

  Serial.println("Engine Started!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Engine Started?");
}

void loop() { // run over and over
  if (mySerial.available()) {
    char direction = mySerial.read();

Serial.write(direction);
lcd.setCursor(0, 0);        // always print on line 2
lcd.print("Input: ");      // fixed label
lcd.print(direction);
lcd.print("   ");          // clears leftover characters

    if(direction == '1')
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
    }
    else if(direction == '2')
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
