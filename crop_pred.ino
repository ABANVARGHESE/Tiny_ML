#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include "RandomForestRegressor.h"
#include "DHT.h"
#define DHTPIN 25     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
Eloquent::ML::Port::RandomForest regressor;

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] =  {27, 23, 4, 16};
byte colPins[COLS] = {17, 5, 18, 19}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int count = 0;
char entered_array[16];
char arr0[10];
char arr1[10];
char arr2[10];
char arr3[10];
char arr4[10];
char arr5[10];
char arr6[10];

int parameter=0;
float X[7];


int cursorColumn = 0;
int cursorRow = 0;
int h,t; //temp,humi
int counter=0; //humi

void setup() {
  Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();
  dht.begin();
  delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature(); 
}

void loop() {
  
  
   char key = keypad.getKey();
  


    switch(parameter){
      
      case 0:
         
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Nitrogen : "); 
         if (key) 
   {if (key=='A') 
    {sasi0();
    }
   else  
   {
    lcd.setCursor(cursorRow,1 );
    cursorRow++;
    Serial.println(key);
    lcd.print(key);
    arr0[count]=key;
    count++;
    }
}
         break;

      case 1:
         
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Phosphorus : "); 
         if (key) 
  {if (key=='A') 
    {sasi1();
    }
   else  
   {
    lcd.setCursor(cursorRow,1 );
    cursorRow++;
    Serial.println(key);
    lcd.print(key);
    arr1[count]=key;
    count++;
    }
}
         break;

      case 2:
         
         //.clear();
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Potassium : "); 
         if (key) 
  {if (key=='A') 
    {sasi2();
    }
   else  
   {
    lcd.setCursor(cursorRow,1 );
    cursorRow++;
    Serial.println(key);
    lcd.print(key);
    arr2[count]=key;
    count++;
    }
}
         
         break;
         
      case 3:
         
         //lcd.clear();
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Temperature : "); 
         lcd.setCursor(0,1);
         lcd.print(t);
         if (key) 
          {if (key=='A') 
            {sasi3();
              }
           else  
            {
             lcd.setCursor(cursorRow,1 );
             cursorRow++;
             Serial.println(key);
             lcd.print(key);
             arr3[count]=key;
             count++;
            }
          }
        
         break;

      case 4:
         
         //lcd.clear();
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Humidity : "); 
         lcd.setCursor(0,1);
         lcd.print(h);
         if (key) 
           {if (key=='A') 
            {sasi4();
             }
           else  
           {
         lcd.setCursor(cursorRow,1 );
         cursorRow++;
         Serial.println(key);
         lcd.print(key);
         arr4[count]=key;
         count++;
           }
          }
         
         break;

      case 5:
         
         //lcd.clear();
         lcd.setCursor(cursorColumn, 0);
         lcd.print("pH : "); 
         if (key) 
  {if (key=='A') 
    {sasi5();
    }
   else  
   {
    lcd.setCursor(cursorRow,1 );
    cursorRow++;
    Serial.println(key);
    lcd.print(key);
    arr5[count]=key;
    count++;
    }
}
         
         break;
         
      case 6:
         
        // lcd.clear();
         lcd.setCursor(cursorColumn, 0);
         lcd.print("Rainfall : "); 
         if (key) 
          {if (key=='A') 
            {sasi6();
            }
   else  
   {
    lcd.setCursor(cursorRow,1 );
    cursorRow++;
    Serial.println(key);
    lcd.print(key);
    arr6[count]=key;
    count++;
    }
}
         break;   

      default:
         //lcd.clear();
         int y_pred = regressor.predict(X);
         lcd.setCursor(cursorColumn, 0);
         if( X[0]>150 || X[1]>150 || X[2]>210 || X[3]>46 || X[4]>100 || X[5]>14 || X[6]>300){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Invalid Input...");
          while(1){
            lcd.setCursor(0,1);
            lcd.print("Press B to reset");
            char key1 = keypad.getKey();
            if(key1){
              if(key1=='B'){
                ESP.restart();
                }
              }
            }
          }
       
             switch(y_pred){
      
      case 0:
         lcd.print("Apple");
         break;

      case 1:
         lcd.print("Banana");
         break;

      case 2:
         lcd.print("Blackgram");
         break;
         
      case 3:
         lcd.print("Chickpea");
         break;

      case 4:
         lcd.print("Coconut");
         break;

      case 5:
         lcd.print("Coffee");
         break;
         
      case 6:
         lcd.print("Cotton");
         break;   
         
      case 7:
         lcd.print("Grapes");
         break;

      case 8:
         lcd.print("Jute");
         break;

      case 9:
         lcd.print("KidneyBeans");
         break;
      case 10:
         lcd.print("Lentil");
         break;

      case 11:
         lcd.print("Maize");
         break;

      case 12:
         lcd.print("Mango");
         break;
         
      case 13:
         lcd.print("Mothbeans");
         break;

      case 14:
         lcd.print("Mungbean");
         break;

      case 15:
         lcd.print("Muskmelon");
         break;
         
      case 16:
         lcd.print("Orange");
         break;

      case 17:
         lcd.print("Papaya");
         break;

      case 18:
         lcd.print("Pigeonpeas");
         break;
         
      case 19:
         lcd.print("Pomegranate");
         break;

      case 20:
         lcd.print("Rice");
         break;

      case 21:
         lcd.print("Watermelon");
         break;
         
      default:
         lcd.print("Invalid");
         break;
   }
       
          
         //lcd.print(y_pred);
         Serial.println("---------------------------------");
         for(int p=0;p<7;p++)
         {Serial.println(X[p]);
          } 
         while(1){ 
          lcd.setCursor(0,1);
          lcd.print("Press B to reset");
          char key2 = keypad.getKey();
            if(key2){
              if(key2=='B'){
                ESP.restart();
                }
              }
             } 
         break;
  
  
  

}
}
void sasi0()
{  int N=0;
    for (int i = 0; i < strlen(arr0); i++) 
    {
        N *= 10;
        N += (arr0[i] - '0');
    }
    
    Serial.println(N);
    X[parameter]=N;
    count=0;
    parameter=1;
    lcd.clear();
    
  }

  void sasi1()
{  int N=0;
    for (int i = 0; i < strlen(arr1); i++) 
    {
        N *= 10;
        N += (arr1[i] - '0');
    }
    
    Serial.println(N);
    X[parameter]=N;
    count=0;
    parameter=2;
    lcd.clear();
    
  }

  void sasi2()
{  int N=0;
    for (int i = 0; i < strlen(arr2); i++) 
    {
        N *= 10;
        N += (arr2[i] - '0');
    }
    
    Serial.println(N);
    X[parameter]=N;
    count=0;
    parameter=3;
    lcd.clear();
    
  }

  void sasi3()
{  int N=0;
    for (int i = 0; i < strlen(arr3); i++) 
    {
        N *= 10;
        N += (arr3[i] - '0');
    }
    
    Serial.println(t);
    X[parameter]=t;
    count=0;
    parameter=4;
    lcd.clear();
    
  }


  void sasi4()
{  int N=0;
    for (int i = 0; i < strlen(arr4); i++) 
    {
        N *= 10;
        N += (arr4[i] - '0');
    }
    
    Serial.println(h);
    X[parameter]=h;
    count=0;
    parameter=5;
    lcd.clear();
    
  }

  void sasi5()
{  int N=0;
    for (int i = 0; i < strlen(arr5); i++) 
    {
        N *= 10;
        N += (arr5[i] - '0');
    }
    
    Serial.println(N);
    X[parameter]=N;
    count=0;
    parameter=6;
    lcd.clear();
    
  }


   void sasi6()
{  int N=0;
    for (int i = 0; i < strlen(arr6); i++) 
    {
        N *= 10;
        N += (arr6[i] - '0');
    }
    
    Serial.println(N);
    X[parameter]=N;
    count=0;
    parameter=7;
    lcd.clear();
    
  }

  
