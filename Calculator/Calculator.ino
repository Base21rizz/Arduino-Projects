#include<Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);
  
long first = 0;
long second = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {17,16,15,14};
  
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins,ROWS, COLS);
  
  
void setup()
{
	Serial.begin(9600);
  
  	//LCD part of the code
  	lcd.begin(16, 2); 
  	lcd.setCursor(0,0);
  	lcd.print("Calculator On");
  	delay(1000);
  	lcd.clear();
}
void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey)
  {
	case '0' ... '9':
    	lcd.setCursor(0,0);
		first = first * 10 + (customKey - '0');
    	lcd.print(first);
    	break;
    case '+':
    	first = (total != 0 ? total:first);
    	lcd.print("+");
    	second = SecondNumber();
    	total = first + second;
    	
    	lcd.setCursor(0,1);
    	lcd.print("= ");
    	lcd.print(total);          
    
    	first = 0, second = 0;
    	break;
    case '-':
    	first = (total != 0 ? total:first);
    	lcd.print("-");
    	second = SecondNumber();
    	total = first - second;
    
    	lcd.setCursor(0,1);
    	lcd.print("= ");
    	lcd.print(total);
    
    	first = 0, second = 0;
    	break;
    case '*':
    	first = (total != 0 ? total:first);
    	lcd.print("*");
    	second = SecondNumber();
    	total = first * second;
    	
    	lcd.setCursor(0,1);
    	lcd.print("= ");
    	lcd.print(total);
    
    	first = 0, second = 0;
    	break;
    case '/':
    	first = (total != 0 ? total:first);
    	lcd.print("/");
    	second = SecondNumber();
    	
    	lcd.setCursor(0,1);
    	if(second == 0) lcd.print("Error");
    	else
        {
          total = (float)first/ second;
          lcd.print("= ");
          lcd.print(total);
        }
    	first = 0, second = 0;
    	break;
    case 'C':
    	total = 0;
    	first = 0;
    	second = 0;
    	lcd.clear();
    	break;
  }
}
long SecondNumber()
{
  while(1)
  {
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
      lcd.print(customKey);
    }
    if(customKey == '=') break;
  }
    return second;
}