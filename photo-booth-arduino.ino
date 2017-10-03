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

void fade(int from, int to) {
  fill(from, from, from);
  
  if(to > from) {
    for(int l = from; l < to; l++) {
      fill(l, l, l);
      pixels.show();
      delay(1);
    }
  } else {
    for(int l = from; l > to; l--) {
      fill(l, l, l);
      pixels.show();
      delay(1);
    }
  }
}

void fill(int r, int g, int b) {
    for(int i = 0; i < 60; i++) {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
    }
}

void count_up(float duration, int brightness) {
  clear();

  for(int i = 0; i < 60; i++) {
    pixels.setPixelColor(i, pixels.Color(brightness, brightness, brightness));
    pixels.show();
    delay(duration / 60);
  }

  fade(0, 60);
  fade(60, 0);
  fade(0, 60);
  fade(60, 0);
  fade(0, 60);
}

void count_down(float duration) {
  for(int i = 0; i < 60; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(duration / 60);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.read() - 48;
    if(command == 0) {
      count_up(10000, 32);
    } else if(command == 1) {
      delay(1000);
      count_down(3000);
    } else if(command == 2) {
      fade(0, 60);
      delay(1000);
      count_down(3000);
    }
  }
}
