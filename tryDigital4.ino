#include <Wire.h>
#include <SPI.h>
#include "animation.h"
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

#define Logo_width 128
#define Logo_height 64


//設定腳位
SSD1306Wire  display(0x3c, 21, 22);

const int buttonPin = 19; 
void setup() {
  pinMode(buttonPin, INPUT);
  display.init(); //初始化(init)
  display.setContrast(255); //數值介於0~255，調整對比
  display.clear();//清除螢幕和緩衝區(clear)
  display.drawXbm(0, 0,64, 128, walk_0_img);
  //印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
  display.display(); //顯示畫面(display)
}

void loop() { 
int i=0;
int buttonState;
while(1){
buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
      display.clear();
      display.drawXbm(i, 0,64, 128,*( walk+i));
      display.display(); 
      delay(200);
      i++;
      if(i==8){
      i=0;
      }
    }

else if(buttonState == LOW){
int x=0;
while(1){  
  display.clear();
      display.drawXbm(i, 0,64, 128,*( idle+x));
      x++;
      display.display(); 
      delay(200);
     
   if(x==2){
      x=0;
      }
      buttonState = digitalRead(buttonPin);

if(buttonState == HIGH){
    break;
      }
}
}
}    
}
  
 
