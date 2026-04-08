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

  // 2. Request PowerShell with Administrator privileges
  // This uses the official 'RunAs' verb to trigger the UAC prompt
  kbd.printES("powershell Start-Process powershell -Verb RunAs");
  kbd.tap(40); // Enter
  
  // 3. Wait for the UAC (User Account Control) window to appear
  delay(3000); 
  
  // 4. Confirm UAC (Left Arrow + Enter)
  // This selects "Yes" in the Spanish/English UAC prompt
  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  kbd.tap(40); 
  
  delay(3000); // Wait for the elevated Admin console to load

  // 5. Execute Silent Installation via Winget
  // You can change '7zip.7zip' to any other package ID (e.g., 'VideoLAN.VLC')
  // The '-NoExit' flag is kept for debugging; remove it for stealth use
  kbd.printES("winget install --id 7zip.7zip --silent --accept-source-agreements --accept-package-agreements; exit");
  kbd.tap(40);

  kbd.end();
}

void loop() {}
