/* Cherry MX Custom Keypad Example Program
 * By: Dan Watson 
 * syncchannel.blogspot.com
 * 5/29/2016
 * 
 * This example program has the following behavior for the keys:
 *  -- They send w, a, s, and d respectively
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

#define LED 1
#define BACKLIGHT 6

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
  pinMode(LED, OUTPUT);
  pinMode(BACKLIGHT, OUTPUT);
  
  Keyboard.begin();
}

void loop()
{
 if (digitalRead(SW0) == LOW)
  {
    delay(5);
    if (digitalRead(SW0) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.print('0');
      while(digitalRead(SW0) == LOW) { }
    }
  }

 
  // Check the first key. If it is pressed, wait 5ms
  if (digitalRead(SW1) == LOW)
  {
    delay(5);

    // Check again (debouncing). If still pressed, send key
    if (digitalRead(SW1) == LOW)
    {
      // Backlight to full brightness during press
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;

      // Send key
      Keyboard.print('1');

      // Sit here while key is still pressed, sending charatcer only once
      while(digitalRead(SW1) == LOW) { }
    }
  }


  // Check second key
  else if (digitalRead(SW2) == LOW)
  {
    delay(5);
    if (digitalRead(SW2) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.print('2');
      while(digitalRead(SW2) == LOW) { }
    }
  }

  // Check third key
  else if (digitalRead(SW3) == LOW)
  {
    delay(5);
    if (digitalRead(SW3) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.print('3');
      while(digitalRead(SW3) == LOW) { }
    }
  }

  // Check fourth key
  else if (digitalRead(SW4) == LOW)
  {
    delay(5);
    if (digitalRead(SW4) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.print('4');
      while(digitalRead(SW4) == LOW) { }
    }
  }

  // Check fourth key
  else if (digitalRead(SW5) == LOW)
  {
    delay(5);
    if (digitalRead(SW5) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.print('5');
      while(digitalRead(SW5) == LOW) { }
    }
  }

  // Check fourth key
  else if (digitalRead(SW6) == LOW)
  {
    delay(5);
    if (digitalRead(SW6) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.print('6');
      while(digitalRead(SW6) == LOW) { }
    }
  }

  // Check fourth key
  else if (digitalRead(SW7) == LOW)
  {
    delay(5);
    if (digitalRead(SW7) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.print('7');
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
