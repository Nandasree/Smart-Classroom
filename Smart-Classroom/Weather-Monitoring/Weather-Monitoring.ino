#include <SimpleDHT.h>

#include <LiquidCrystal_I2C.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
    lcd.init();
}

void loop() {
  // start working...
  Serial.println("=================================");
  
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    /*Serial.print("Read DHT11 failed, err="); Serial.println(err);*/delay(1000);
    return;
  }
  

  

  // Turn on the blacklight and print a message.
 lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("temperature  "); lcd.print((int)temperature);
 lcd.setCursor(0, 1);
  lcd.print("humidity  ");
  lcd.print((int)humidity);
  
  delay(10);
 if(temperature>=37){
   Serial.println("AC is reduced to 16deg");
    delay(10000);
  }
  else if(temperature<37 && temperature>=32){
    Serial.println("Ac is reduced to 18deg");
    delay(10000);
  }
  else if(temperature<32 && temperature>=29){
    Serial.println("Ac is reduced to 21deg");
    delay(10000);
  }
 else if(temperature<29){
    Serial.println("AC is at noraml temp");
    delay(10000);
 }
  }
