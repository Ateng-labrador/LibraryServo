#include "MyServoESP32.h"

MyServoESP32::MyServoESP32(){

}

// member function dari scope MyServoESP32
void MyServoESP32::attach(int pin, int channel){
  _pin = pin;
  _channel = channel;
  // Mengaktifkan PWM
  // Buat sinyal PWM pada GPIO pin dengan frekuensi 50 Hz dan resolusi 16 bit
  // ledcAttach(pin, frequency, resolution);
  ledcAttach(_pin, 50, 16);
}


// member function dari scope MyServoESP32
void MyServoESP32::write(int angle){
  // memastika nilai tidak keluar dari rentang
  angle = constrain(angle, 0, 180);
  // ubah sudut jadi lebar pulsa
  uint32_t pulseWidth = map(angle, 0, 180, 500, 2500);

  // mengubah pulse width menjadi nilai duty
  uint32_t duty = (pulseWidth * 65535) / 20000;
  // buat pulse sebanyak duty
  ledcWrite(_pin, duty);
}
