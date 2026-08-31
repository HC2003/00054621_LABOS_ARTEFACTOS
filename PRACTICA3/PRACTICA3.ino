#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {

  Serial.begin(9600);

  Wire.begin();
  delay(250);

  if (!display.begin(i2c_Address, true)) {
    Serial.println("ERROR: OLED no encontrada");
    while (1);
  }

  Serial.println("OLED funcionando correctamente");

  //Conf inicial
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(2);
  display.setCursor(15, 10);
  display.println("HOLA!");

  display.setTextSize(1);
  display.setCursor(15, 40);
  display.println("OLED funcionando");

  display.display();

  delay(2000);
}

void loop() {

  //Leer el sensor
  int LecturaReal = analogRead(A3);

  //Conversion
  float temperatura = (LecturaReal * 5.0 / 1023.0) * 100;

  //Y... Mostrar datos en el Moni Serial
  Serial.print("Lectura: ");
  Serial.print(LecturaReal);

  Serial.print(" | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  
  display.clearDisplay();

  
  display.setTextSize(1);
  display.setCursor(20, 5);
  display.println("TEMPERATURA");

  //Mostrando datos
  display.setTextSize(2);
  display.setCursor(20, 25);
  display.print(temperatura, 1);
  display.println(" C");

  display.display();

  delay(1000);
}