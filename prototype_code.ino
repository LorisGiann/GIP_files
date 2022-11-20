#include <LiquidCrystal.h>
volatile int stato = LOW;
volatile int stato_interruttore = LOW;
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);	
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(0, up, RISING); //interrupt per rilevare urto
  //da cambiarre con FALLING
  attachInterrupt(1, open, RISING); //interrupt per rilevare interruzione circuito 
}
void loop() {
  Serial.println(stato);
  lcd.setCursor(0, 0);
  if (stato == HIGH){
    lcd.clear();
    lcd.print("rilevato urto");
  } else {
    //da cambiare con LOW
    if (stato_interruttore == HIGH){
      lcd.clear();
      lcd.print("circuito");
      lcd.setCursor(0, 1);
      lcd.print("interrotto");
    } else {
      lcd.clear();
      lcd.print("ok");
    } 
  }
  delay(500);
}

void up(){
  stato = HIGH;
}

void open(){
  //da cambiare con LOW
  stato_interruttore = HIGH;
}