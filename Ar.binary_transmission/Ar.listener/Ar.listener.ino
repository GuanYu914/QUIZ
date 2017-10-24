#include <stdio.h>
#include <string.h>
#define START_BYTE '@'
#define DATA_LENGTH 11

char data[DATA_LENGTH] = {};
unsigned int v_int = 0; 
float v_float = 0.0; 
char v_char = ' ';  

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
    if(Serial.available() > 0)
    {   
        //wait to read start byte...
        Serial.println("wait to receive start byte...");
        while((char)Serial.read() == START_BYTE)
        {
            data[0] = START_BYTE;
            for(int i = 1; i < DATA_LENGTH ; i++)
            {
                  if(Serial.available() > 0)
                  {
                      data[i] = Serial.read();
                  }  
            }
          
            memcpy(&v_int, &data[1], sizeof(unsigned int));
            memcpy(&v_float, &data[5], sizeof(float));
            memcpy(&v_char, &data[9], sizeof(char));
          
            if(data[10] == checksum(data))
            {
                Serial.println("check checksum successfully.");
                char buff[100] = {};
                char v_float_char[15] = {};
                dtostrf(v_float, 7, 3, v_float_char);
                sprintf(buff, "%u, %s, %c", v_int, v_float_char, v_char);
                Serial.println(buff);
            }
        }
    }
    delay(500);
}

char checksum(char data[])
{
    char checksum = ' ';
    for(int i = 0; i < DATA_LENGTH - 1; i++)
    {
          checksum ^= data[i];
    }
    return checksum;
}
