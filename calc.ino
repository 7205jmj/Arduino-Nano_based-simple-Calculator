//libary including
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//i2c address
LiquidCrystal_I2C lcd(0x27,16,2);

//defining keypad as 4x4
const byte ROWS=4;
const byte COLS=4;

//defining keypad layout

char keys[ROWS][COLS]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'c','0','/','='}
};

byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};

Keypad keypad =Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

long num1=0,num2=0;
char oper;
bool secnum= false;

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("NANO-382p calc");
  delay(2000);
  lcd.clear();

}
void loop()
{
  char key=keypad.getKey();
  if(key){
    if(key>='0' && key<='9'){
      lcd.print(key);
      if(!secnum)
        num1=num1*10+(key-'0');
      else
        num2=num2*10+(key-'0');
    }
  
  else if(key=='+'||key=='-'||key=='*'||key=='/'){
    oper=key;
    secnum=true;
    lcd.print(oper);
  }
  else if(key=='='){
    lcd.setCursor(0,1);
    long result=0;
  
  switch (oper){
    case '+':
    result=num1+num2;
    break;
    case '-':
    result=num1-num2;
    break;
    case '*':
    result =num1*num2;
    break;
    case '/':
    result=(num2!=0)?num1/num2:0;break;
  }
  lcd.print("= ");
  lcd.print(result);}

  else if(key =='c'){
    lcd.clear();
    num1=num2=0;
    secnum=false;
  }}



}