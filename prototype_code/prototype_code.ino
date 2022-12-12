#include <LiquidCrystal.h>
volatile int urto = LOW;
volatile int manomissione = LOW;
//const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);	
LiquidCrystal lcd(4,5,9,8,7,6);	
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  delay(10);
  attachInterrupt(digitalPinToInterrupt(2), up, CHANGE); //interrupt per rilevare urto
  attachInterrupt(digitalPinToInterrupt(3), open, CHANGE); //interrupt per rilevare interruzione circuito
  urto = LOW;
  manomissione = LOW;
}
void loop() {
  Serial.println(urto);
  lcd.setCursor(0, 0);
  if (urto == HIGH){
    lcd.clear();
      lcd.print("Rilevato");
      lcd.setCursor(0, 1);
      lcd.print("Urto");
      digitalWrite(13,HIGH);
  } else {
    //da cambiare con LOW
    if (manomissione == HIGH){
      lcd.clear();
      lcd.print("Rilevata");
      lcd.setCursor(0, 1);
      lcd.print("Manomissione");
      digitalWrite(13,HIGH);
    } else {
      lcd.clear();
      lcd.print("ok");
    } 
  }
  delay(500);
}

void up(){
  urto = HIGH;
}

void open(){
  //da cambiare con LOW
  manomissione = HIGH;
}