#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int a,b,c,d;
int b1=9,b2=10;

void fromECE(int inp)
{
  if(inp == 1)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    Serial.print("Walk for about 10m from ECE dept. towards North\n");
    Serial.print("The block to your Right is GJCB\n");
  }
  else if(inp == 2)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    Serial.print("Walk for about 12m from ECE dept. towards North\n");
    Serial.print("The block to your Left is Mech Dept.\n");
  }
  else
  {
  }
  return;
}

void fromGJCB(int inp)
{
  if(inp == 1)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    Serial.print("Walk for about 10m from GJCB towards South\n");
    Serial.print("The block infront of you is ECE Dept.\n");
    lcd.setCursor(0,0);
    lcd.print("10m to south");
    lcd.setCursor(0,1);
    lcd.print("Block is ECE");
    delay(5000);
    lcd.clear();  
  }
  else if(inp == 2)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    //Serial.print("Walk for about 12m from ECE dept. towards North\n");
    Serial.print("The block infront of GJCB is Mech Dept.\n");
    lcd.setCursor(0,0);
    lcd.print("1m to West");
    lcd.setCursor(0,1);
    lcd.print("Block is MECH");
    delay(5000);
    lcd.clear(); 
  }
  else
  {
  }
  return;
}


void fromMech(int inp)
{
  if(inp == 1)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    Serial.print("Walk for about 5m from Mech dept. towards South\n");
    Serial.print("The block infront of you is ECE dept.\n");
    lcd.setCursor(0,0);
    lcd.print("10m to south");
    lcd.setCursor(0,1);
    lcd.print("Block is ECE");
    delay(5000);
    lcd.clear(); 
  }
  else if(inp == 2)
  {
    Serial.print("\n\nYour Destination Path is:\n");
    //Serial.print("Walk for about 12m from ECE dept. towards North\n");
    Serial.print("The block infront of Mech Dept. is GJCB\n");
    lcd.setCursor(0,0);
    lcd.print("1m to East");
    lcd.setCursor(0,1);
    lcd.print("Block is GJCB");
    delay(5000);
    lcd.clear(); 
  }
  else
  {
  }
  return;
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  int val1 = analogRead(A1);
  int val3 = analogRead(A2);
  int val4 = analogRead(A3);
  int avg = (val+val1+val3+val4)/4;
  
  if(avg-val>150)
  {
    a=1;
  }
  else
  {
    a=0;
  }
  
  if(avg-val1>150)
  {
    b=1;
  }
  else
  {
    b=0;
  }
  
  if(avg-val3>150)
  {
    c=1;
  }
  else
  {
    c=0;
  }
  
  if(avg-val4>150)
  {
    d=1;
  }
  else
  {
    d=0;
  }
  //Serial.print(val);
  //Serial.print(' ');
  //Serial.print(b);
  //Serial.print(val1);
  //Serial.print(' ');
  //Serial.print(c);
  //Serial.print(val3);
  //Serial.print(' ');
  //Serial.print(d);
  //Serial.print(val4);
  //Serial.print('\n');
  //Serial.print(a);
  //Serial.print(b);
  //Serial.print(c);
  //Serial.print(d);

  if(a==0&&b==0&&c==0&&d==0 || a==1&&b==1&&c==1&&d==1)
  {
    Serial.print("Location updating - No nearby Transmitters");
    lcd.setCursor(0,0);
    lcd.print("No Location");
    lcd.setCursor(0,1);
    lcd.print("Detected...");
    delay(2000);
    lcd.clear();
  }
  else if(a==0&&b==0&&c==0&&d==1)
  {
    Serial.print("@ECE Block");
    Serial.print("\n1:GJCB\n2:Mech Block\n3:Cafe");
    Serial.print("\nEnter Input for Dest. - ");
    lcd.setCursor(0,0);
    lcd.print("You are at");
    lcd.setCursor(0,1);
    lcd.print("ECE Block...");
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Enter Destination");
    lcd.setCursor(0,1);
    lcd.print("Location");
    delay(2000);
    lcd.clear();
    
    int inp = 0;
    int s1=digitalRead(b1);
    int s2 = digitalRead(b2);
    if(s1==0 && s2==1){
      inp = 1;
    }
    else if(s1==1 && s2==0){
      inp = 2;
    }
    
    fromECE(inp);
  }
  else if(a==0&&b==0&&c==1&&d==0)
  {
    Serial.print("@GJCB Block");
    Serial.print("\n1:ECE Block\n2:Mech Block\n3:Cafe");
    Serial.print("\nEnter Input for Dest. - ");

    lcd.setCursor(0,0);
    lcd.print("You are at");
    lcd.setCursor(0,1);
    lcd.print("GJC Block...");
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Enter Destination");
    lcd.setCursor(0,1);
    lcd.print("Location");
    delay(2000);
    lcd.clear();
    
    int inp = 0;
    int s1=digitalRead(b1);
    int s2 = digitalRead(b2);
    if(s1==0 && s2==1){
      inp = 1;
    }
    else if(s1==1 && s2==0){
      inp = 2;
    }
    fromGJCB(inp);
  }
  else if(a==0&&b==1&&c==0&&d==0)
  {
    Serial.print("@Mech Block");
    Serial.print("\n1:ECE Block\n2:GJCB\n3:Cafe");
    Serial.print("\nEnter Input for Dest. - ");

    lcd.setCursor(0,0);
    lcd.print("You are at");
    lcd.setCursor(0,1);
    lcd.print("MECH Block...");
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Enter Destination");
    lcd.setCursor(0,1);
    lcd.print("Location");
    delay(2000);
    lcd.clear();

    int inp = 0;
    int s1=digitalRead(b1);
    int s2 = digitalRead(b2);
    if(s1==0 && s2==1){
      inp = 1;
    }
    else if(s1==1 && s2==0){
      inp = 2;
    }
    fromMech(inp);
  }

  Serial.print('\n');
  delay(1000);
}
