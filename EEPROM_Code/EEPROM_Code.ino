#include <EEPROM.h>

int addr = 50;

void setup(){
  Serial.begin(115200);
  EEPROM.begin(512);
  }

void loop(){
  if(Serial.available()>0){
    String dump = Serial.readString();

    eepWrite(dump);
    delay(2000);
    Serial.println(eepRead());
    }
  }

void eepWrite(String dump){
  int len = dump.length();
  if(len>0 and len<=9)  {dump = "00"+String(len)+dump;}
  if(len>9 and len<=99){dump = "0"+String(len)+dump;}
  if(len>99 and len<300){dump = String(len)+dump;}

  for (int i = 0; i < dump.length(); ++i)
  {
    EEPROM.write(addr + i, dump[i]);
  }

  if (EEPROM.commit()) {
//    Serial.println("Data successfully committed");
  } else {
//    Serial.println("ERROR! Data commit failed");
  }
}

String eepRead(){
  String readAdd,data;
  for (int k = 50; k < 50 + 3; ++k){readAdd += char(EEPROM.read(k));}
  int addInt = readAdd.toInt();
  
  for (int l = 53; l < 53 + addInt; ++l){data += char(EEPROM.read(l));}
  return data;
  }
