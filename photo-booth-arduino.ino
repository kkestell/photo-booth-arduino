#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(60, 3, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

  pixels.begin();
  clear();
}

void clear() {
  for(int i = 0; i < 60; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }

  pixels.show();
}

void countdown_slow() {
  for(int b = 0; b < 64; b++) {
    for(int i = 0; i < 60; i++) {
      pixels.setPixelColor(i, pixels.Color(b, b, b));
    }
    pixels.show();
    delay(16);
  }

  for(int i = 0; i < 60; i++) {
    if(i - 1 >= 0)
      pixels.setPixelColor(i - 1, pixels.Color(32, 32, 32));

    if(i - 2 >= 0)
      pixels.setPixelColor(i - 2, pixels.Color(16, 16, 16));

    if(i - 3 >= 0)
      pixels.setPixelColor(i - 3, pixels.Color(4, 4, 4));

    if(i - 4 >= 0)
      pixels.setPixelColor(i - 4, pixels.Color(0, 0, 0));

    pixels.show();

    delay(180);
  }

  clear();
}

void countdown_fast() {
  for(int b = 0; b < 64; b++) {
    for(int i = 0; i < 60; i++) {
      pixels.setPixelColor(i, pixels.Color(b, b, b));
    }
    pixels.show();
    delay(16);
  }

  for(int i = 0; i < 60; i++) {
    if(i - 1 >= 0)
      pixels.setPixelColor(i - 1, pixels.Color(32, 32, 32));

    if(i - 2 >= 0)
      pixels.setPixelColor(i - 2, pixels.Color(16, 16, 16));

    if(i - 3 >= 0)
      pixels.setPixelColor(i - 3, pixels.Color(4, 4, 4));

    if(i - 4 >= 0)
      pixels.setPixelColor(i - 4, pixels.Color(0, 0, 0));

    pixels.show();

    delay(40);
  }

  clear();
}

void loop() {
  if (Serial.available() > 0) {  
    int command = Serial.read() - 48;
    if(command == 0)
      countdown_slow();
    else if(command == 1)
      countdown_fast();
  }
}
