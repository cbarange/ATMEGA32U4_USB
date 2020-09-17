#include <KeyboardAzertyFr.h>
#include <HID.h>

// Utility function
void typeKey(int key){
  KeyboardAzertyFr.press(key);
  delay(50);
  KeyboardAzertyFr.release(key);
}

void setup()
{
  // Start KeyboardAzertyFr and Mouse
  KeyboardAzertyFr.begin();

  // Start Payload
  delay(500);

  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_RIGHT_ARROW);
  KeyboardAzertyFr.releaseAll();

  delay(500);

  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_DOWN_ARROW);
  KeyboardAzertyFr.releaseAll();

  delay(500);

  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_LEFT_ARROW);
  KeyboardAzertyFr.releaseAll();

  delay(500);

  KeyboardAzertyFr.press(KEY_LEFT_CTRL);
  KeyboardAzertyFr.press(KEY_LEFT_ALT);
  KeyboardAzertyFr.press(KEY_UP_ARROW);
  KeyboardAzertyFr.releaseAll();

  // End Payload

  // Stop KeyboardAzertyFr and Mouse
  KeyboardAzertyFr.end();

}

// Unused
void loop() {}
