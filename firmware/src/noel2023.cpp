#include <Arduino.h>

#define LED_A PIN_PA1
#define LED_B PIN_PA2
#define LED_C PIN_PA3

int randomSign(void);
int randomValue(void);
const int signs[2] = {-1, 1};

void setup() {
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);
}

void loop() {
    analogWrite(LED_A, randomValue());
    analogWrite(LED_B, randomValue());
    analogWrite(LED_C, randomValue());
    delay(random(300, 600));
}

int randomValue() {
    return 127 + randomSign() * random(80, 127);
}

int randomSign() {
    return signs[random(2)];
}
