#include "KeyboardES_ES_Beetle.h"

KeyboardES_ES_Beetle kbd;

void setup() {
  delay(4000); 
  kbd.begin();

  // 1. Open RUN dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  delay(200);
  Keyboard.releaseAll();
  delay(600);

  // 2. Open PowerShell
  kbd.printES("powershell -NoP"); 
  kbd.tap(40); 
  delay(2500); 

  // 3. Define the VBScript messages in English
  // You can customize these messages as you like
  kbd.printES("$v = @'");
  kbd.printES("MsgBox \"System threat detected!\", 48, \"Alert\"");
  kbd.printES("MsgBox \"Scanning components...\", 64, \"Analysis\"");
  kbd.printES("MsgBox \"Scan complete. No real threats found.\", 64, \"Result\"");
  kbd.printES("MsgBox \"Beetle BadUSB test successful!\", 0, \"Success\"");
  kbd.printES("'@");
  kbd.tap(40);

  // 4. Create the temporary VBS file, execute it, and then delete it
  kbd.printES("$p = \"$env:temp\\alert.vbs\"; $v | Out-File $p -Encoding ascii; cscript.exe $p; rm $p; exit");
  kbd.tap(40);

  kbd.end();
}

void loop() {}
