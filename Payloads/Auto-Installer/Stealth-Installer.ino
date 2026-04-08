#include "KeyboardES_ES_Beetle.h"

KeyboardES_ES_Beetle kbd;

void setup() {
  delay(4000); 
  kbd.begin();

  // 1. Open RUN dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  delay(250);
  Keyboard.releaseAll();
  delay(800);

  // 2. Launch Hidden PowerShell with Admin privileges
  // -W Hidden: Makes the window invisible
  // -C: Executes the command and then terminates
  kbd.printES("powershell Start-Process powershell -Verb RunAs -ArgumentList '-NoP -W Hidden -C \"winget install --id 7zip.7zip --silent --accept-source-agreements --accept-package-agreements\"'");
  kbd.tap(40); // Enter
  
  // 3. Wait for the UAC (User Account Control) prompt
  delay(3000); 
  
  // 4. Confirm UAC (Left Arrow + Enter)
  // Even in stealth mode, the UAC must be confirmed manually or via HID
  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  kbd.tap(40); 
  
  // From this point on, the installation happens completely in the background.
  // No further windows will be visible to the user.

  kbd.end();
}

void loop() {}
