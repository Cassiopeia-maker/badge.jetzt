

#include "base/display.h"
#include "base/led.h"
#include "base/button.h"
#include "base/pins.h"

unsigned long countdownTime = 10 * 60 * 1000;  // 10 Minuten in Millisekunden
unsigned long startTime;




void setup() {
    Serial.begin(115200);
    Serial.println("badge.jetzt");

    button::init();
    led::init();
    display::init();

    display::clearDisplay();
    display::println("Countdown");
    display::display();

    startTime = millis();
}



void loop() {

    unsigned long elapsed = millis() - startTime;

    if (elasped >=countdownTime) {

        display::clearDisplay();
        display::println("Fertig"); 
        display::display(); 

        return; 
    } 

    unsigned long remaining = countdownTime - elapsed;
    int minutes = (remaining / 1000) / 60;
    int seconds = (remaining / 1000) % 60;


    //if (button::down(BTN1)) { led::set_l(255,0,0); msg_l = "BTN1: Left Red"; }
  


    // Update display::display
    display::clearDisplay();
    if (seconds < 10) {
    display::println("%d:0%d", minutes, seconds);
  } else {
    display::println("%d:%d", minutes, seconds);
  }
  display::display();

  delay(500);

}
