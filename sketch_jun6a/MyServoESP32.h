#ifndef MYSERVOESP32_H
#define MYSERVOEPS32_H

#include <Arduino.h>

class MyServoESP32{
  // _pin and _channel -> menyimpan informasi servo yang sedang
  // dikendalikan oleh objek tersebut
  private:
    int _pin;
    int _channel;
  public:
    MyServoESP32();
    void attach(int pin, int channel = 0);
    void write(int angle);
};

#endif