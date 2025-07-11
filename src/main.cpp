

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

    delay(1000);
    startTime = millis();
}



void loop() {

    

    unsigned long elapsed = millis() - startTime;

    if (elapsed >=countdownTime) {

        display::clearDisplay();
        display::println("Fertig"); 
        display::display(); 

        return; 
    } 

    unsigned long remaining = countdownTime - elapsed;
    int minutes = (remaining / 1000) / 60;
    int seconds = (remaining / 1000) % 60;


    //if (button::down(BTN1)) { led::set_l(255,0,0); msg_l = "BTN1: Left Red"; }
  
     String timeString = String(minutes) + ":" + String(seconds);

    // Update display::display
    //display::clearDisplay();
    
    //display::println(timeString);
 
  //display::display();

  delay(500);



}
