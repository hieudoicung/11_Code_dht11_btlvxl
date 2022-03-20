#include <Wire.h>
#include <LiquidCrystal_I2C.h> //Gọi thư viện I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); //Khai báo loại LCD

#include "DHT.h"      //gọi thư viện DHT11
const int DHTPIN = 2;       //Khai báo chân đọc dữ liệu trên Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11
DHT dht(DHTPIN, DHTTYPE);

//Khởi động hệ thống
void setup() {
  Serial.begin(9600);
  dht.begin();         // Khởi động cảm biến
  lcd.init();         //Khởi động LCD
  lcd.backlight();     // Bật đèn nền LCD
}

//Hoạt động của hệ thống
void loop() {
  float humidity = dht.readHumidity();    //Đọc độ ẩm
  float temperature = dht.readTemperature(); //Đọc nhiệt độ

//In dữ liệu nhiệt độ, dộ ẩm trên màn hình LCD
  lcd.setCursor(0,0);
  lcd.print("Nhiet do:");
  lcd.setCursor(10, 0);
  lcd.print(temperature);
  lcd.setCursor(14, 0);
  lcd.print("oC");
  lcd.setCursor(0, 1);
  lcd.print("Do am:");
  lcd.setCursor(10, 1);
  lcd.print(humidity);
  lcd.setCursor(14, 1);
  lcd.print("%");
  delay(1000); //Độ trễ 1s
}
