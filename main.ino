#include <Arduino.h>
#include <Keypad.h>
#include "HID-Project.h"

const byte COLS = 4; //4 Spalten
const byte ROWS = 4; //4 Zeilen

//Die Ziffern und Zeichen des Keypads werden eingegeben:
char hexaKeys[ROWS][COLS] = {
    {'D', 'C', 'B', 'A'},
    {'#', '9', '6', '3'},
    {'0', '8', '5', '2'},
    {'*', '7', '4', '1'}};

byte colPins[COLS] = {10, 16, 4, 5};                                            //Definition der Pins für die 4 Spalten
byte rowPins[ROWS] = {6, 7, 8, 9};                                              //Definition der Pins für die 4 Zeilen
char Taste;                                                                     //Taste ist die Variable für die jeweils gedrückte Taste.
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //Das Keypad kann absofort mit "Tastenfeld" angesprochen werden

void trigger()
{

  delay(10);             //Warten ob weitere Tasten gedrückt wurden
  Keyboard.releaseAll(); //Alle Tastenanschläge lösen/ausführen
  delay(100);            //Warten bis neuer Anschlag erfolgen kann
}

void setup()
{
  // Sends a clean report to the host. This is important on any Arduino type.
  BootKeyboard.begin();
  Serial.begin(9600);
}

void loop()
{

  Taste = Tastenfeld.getKey(); //Mit Unter der Variablen pressedKey entspricht der gedrückten Taste

  if (Taste)
  { //Wenn eine Taste gedrückt wurde

    Serial.print("Die Taste ");
    Serial.print(Taste);
    Serial.print(" wurde gedrueckt");
    Serial.println(); //Teile uns am Serial Monitor die gedrückte Taste mit

    switch (Taste)
    {

    case '1':
      break;

    case '2':
      break;

    case '3':
      break;

    case 'A':   //Ausschneiden
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('x');
      Keyboard.releaseAll();
      break;

    case '4':
      break;

    case '5':   //Text eingeben
      Keyboard.println("TEXT");
      break;
      
    case '6':
      break;

    case 'B':
      break;

    case '7':
      break;

    case '8':
      break;

    case '9':
      break;

    case 'C':   //Kopieren
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      Keyboard.releaseAll();
      break;

    case '*':
      break;

    case '0':
      break;

    case '#':

    case 'D':   //Einfügen
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      Keyboard.releaseAll();
      break;

    }
  }

  delay(100);
}
