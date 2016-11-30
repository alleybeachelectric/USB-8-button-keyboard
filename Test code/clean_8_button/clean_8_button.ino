65// You need to include this in some versions of the IDE
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
#define SW8 13

#define led A0
#define BACKLIGHT 6

char ctrlKey = KEY_LEFT_CTRL;

// Counter for updating the backlight
uint16_t backlightCounter = 0;
int val = 0;     // variable for reading the pin status

// Variables will change:
byte buttonPresses = 0;                // how many times the button has been pressed
byte lastPressCount = 0;               // to keep track of last press count

void setup()
{
  pinMode(SW0, INPUT_PULLUP); // previous
  pinMode(SW1, INPUT_PULLUP); // next
  pinMode(SW2, INPUT_PULLUP); // mute
  pinMode(SW3, INPUT_PULLUP); // volume down
  pinMode(SW4, INPUT_PULLUP); // volume up
  pinMode(SW5, INPUT_PULLUP); // play/pause
  pinMode(SW6, INPUT_PULLUP); // stop
  pinMode(SW7, INPUT_PULLUP); // page select
  pinMode(SW8, INPUT_PULLUP); // desktop
  pinMode(BACKLIGHT, OUTPUT); 
  pinMode(led, OUTPUT);
  
  Keyboard.begin();
}

void loop()

{
  lastPressCount = buttonPresses;    // track last press count
  if (digitalRead(SW7) == LOW)
  {
    delay(5);
    if (digitalRead(SW7) == LOW)
    {
      buttonPresses++;
        while(digitalRead(SW7) == LOW) {}
    }
    if (buttonPresses == 2) buttonPresses = 0;
    if (lastPressCount != buttonPresses)
    {
      Serial.print ("Button Press Count = ");
      Serial.println (buttonPresses);
    }
  }
  if (buttonPresses == 0)
  {
    Volume_UP();
    Volume_DOWN();
    PREVIOUS();
    NEXT();
    PLAY_PAUSE();
    MUTE();
    STOP();
    DESKTOP();
  }
  if (buttonPresses == 1)
  {
    sw1();
    sw2();
    sw3();
    sw4();
    sw5();
    sw6();
    sw7();
    sw8();
  }
   {
   if (buttonPresses == 0)
   {
      digitalWrite(led, HIGH);    
   }
   else
   {
      digitalWrite(led,LOW);    
   }
  }
}








 void Volume_UP ()
 {
 if (digitalRead(SW4) == LOW)
  {
    delay(5);
    if (digitalRead(SW4) == LOW)
    {
      Keyboard.press(ctrlKey);
      Keyboard.press(211);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW4) == LOW) { }
    }
  }
 }
 
 void Volume_DOWN ()
 {
  if (digitalRead(SW3) == LOW)
  {
    delay(5);
    if (digitalRead(SW3) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 0;
      Keyboard.press(ctrlKey);
      Keyboard.press(214);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW3) == LOW) { }
    }
  }
 }
 
 void PREVIOUS ()
 {
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
      delay(10);
      // Sit here while key is still pressed, sending charatcer only once
      while(digitalRead(SW0) == LOW) { }
    }
  }
 }
 
 void NEXT ()
 {
  if (digitalRead(SW1) == LOW)
  {
    delay(5);
    if (digitalRead(SW1) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(210);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW1) == LOW) { }
    }
  }
 }
 
 void PLAY_PAUSE ()
 {
   if (digitalRead(SW5) == LOW)
  {
    delay(5);
    if (digitalRead(SW5) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(213);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW5) == LOW) { }
    }
  }
 }
 
 void MUTE ()
 {
   if (digitalRead(SW2) == LOW)
  {
    delay(5);
    if (digitalRead(SW2) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(205);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW2) == LOW) { }
    }
  }
 }
 
 void STOP ()
 {
  if (digitalRead(SW6) == LOW)
  {
    delay(5);
    if (digitalRead(SW6) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(ctrlKey);
      Keyboard.press(212);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW6) == LOW) { }
    }
  }
 }
  void DESKTOP ()
   {
  if (digitalRead(SW8) == LOW)
  {
    delay(5);
    if (digitalRead(SW8) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(0x83); //GUI button
      Keyboard.press('d');
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW8) == LOW) { }
    }
  }
 }
  
 void sw1()
 {
  if (digitalRead(SW0) == LOW)
  {
    delay(5);
    if (digitalRead(SW0) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(48); //numpad 0
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW0) == LOW) { }
    }
  }
 }
 void sw2()
 {
  if (digitalRead(SW1) == LOW)
  {
    delay(5);
    if (digitalRead(SW1) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(49);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW1) == LOW) { }
    }
  }
 }
 void sw3()
 {
  if (digitalRead(SW2) == LOW)
  {
    delay(5);
    if (digitalRead(SW2) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(50);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW2) == LOW) { }
    }
  }
 }
 void sw4()
 {
  if (digitalRead(SW3) == LOW)
  {
    delay(5);
    if (digitalRead(SW3) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(51);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW3) == LOW) { }
    }
  }
 }
 void sw5()
 {
  if (digitalRead(SW4) == LOW)
  {
    delay(5);
    if (digitalRead(SW4) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(52);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW4) == LOW) { }
    }
  }
 }
 void sw6()
 {
  if (digitalRead(SW5) == LOW)
  {
    delay(5);
    if (digitalRead(SW5) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(53);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW5) == LOW) { }
    }
  }
 }
 void sw7()
 {
  if (digitalRead(SW6) == LOW)
  {
    delay(5);
    if (digitalRead(SW6) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(54);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW6) == LOW) { }
    }
  }
 }
void sw8()
 {
  if (digitalRead(SW8) == LOW)
  {
    delay(5);
    if (digitalRead(SW8) == LOW)
    {
      analogWrite(BACKLIGHT,200);
      backlightCounter = 201;
      Keyboard.press(55);
      Keyboard.releaseAll();
      delay(10);
      while(digitalRead(SW8) == LOW) { }
    }
  }
 }
