/* Cherry MX Custom Keypad Example Program
 * By: Dan Watson 
 * syncchannel.blogspot.com
 * 5/29/2016
 * 
 * This example program has the following behavior for the keys:
 *  -- Software debouncing (5ms)
 *  -- Characters are only sent once when the key is depressed
 *  -- Only one key can be pressed at a time
 *  -- The backlight pulses, but goes to full brightness on a press
 *  
 *  All key behavior is completely customizable by modifying this program.
 *  
 *  See this reference to learn the various keyboard and mouse commands available:
 *  https://www.arduino.cc/en/Reference/MouseKeyboard
 */

// You need to include this in some versions of the IDE
#include <Keyboard.h>

// Define I/O connections on board
#define SW0 4
#define SW1 5
#define SW2 7
#define SW3 8
#define SW4 9
#define SW5 10
#define SW6 11
#define SW7 12

#define led 1
#define BACKLIGHT 6

char ctrlKey = KEY_LEFT_CTRL;

// Counter for updating the backlight
uint16_t backlightCounter = 0;

void setup()
{
  pinMode(SW0, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(SW6, INPUT_PULLUP);
  pinMode(SW7, INPUT_PULLUP);  
  pinMode(BACKLIGHT, OUTPUT);
  pinMode(led, OUTPUT);
  
  Keyboard.begin();
}

void loop()

{
 // digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);               // wait for a second
  //digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second




{
  // Check the first key (previous). If it is pressed, wait 5ms
  if (digitalRead(SW0) == LOW)
  {
    delay(5);

    // Check again (debouncing). If still pressed, send key
    if (digitalRead(SW0) == LOW)
    {
      // Backlight to full brightness during press
      analogWrite(led,200);
      backlightCounter = 201;

      // Send key
      Keyboard.press(ctrlKey);
      Keyboard.press(209);
      Keyboard.releaseAll();
      delay(100);
      // Sit here while key is still pressed, sending charatcer only once
      while(digitalRead(SW0) == LOW) { }
    }
  }


  // Check second key (next)
  else if (digitalRead(SW1) == LOW)
  {
    delay(5);
    if (digitalRead(SW1) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(210);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW1) == LOW) { }
    }
  }

  // Check third key (mute)
  else if (digitalRead(SW2) == LOW)
  {
    delay(5);
    if (digitalRead(SW2) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(205);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW2) == LOW) { }
    }
  }

  // Check fourth key (volume down)
  else if (digitalRead(SW3) == LOW)
  {
    delay(5);
    if (digitalRead(SW3) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.press(ctrlKey);
      Keyboard.press(214);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW3) == LOW) { }
    }
  }

 // Check fifth key (volume up)
  else if (digitalRead(SW4) == LOW)
  {
    delay(5);
    if (digitalRead(SW4) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(211);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW4) == LOW) { }
    }
  }

   // Check sixth key (play/pause)
  else if (digitalRead(SW5) == LOW)
  {
    delay(5);
    if (digitalRead(SW5) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(213);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW5) == LOW) { }
    }
  }
  
   // Check seventh key (stop)
  else if (digitalRead(SW6) == LOW)
  {
    delay(5);
    if (digitalRead(SW6) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(212);
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW6) == LOW) { }
    }
  }

  
   // Check eighth key (page select) does nothing.
  else if (digitalRead(SW7) == LOW)
  {
    delay(5);
    if (digitalRead(SW7) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
     //Keyboard.press();
      Keyboard.releaseAll();
      delay(100);
      while(digitalRead(SW7) == LOW) { }
    }
  }
  // If no keys were pressed, update the backlight
  else {
    backlightCounter++;

    // This if/else creates a pulsing effect instead of ramp from min to max
    if (backlightCounter < 32768)
      analogWrite(BACKLIGHT,map(backlightCounter,0,32767,0,175));
    else
      analogWrite(BACKLIGHT,map(backlightCounter,32768,65535,175,0));
  }
}
}
