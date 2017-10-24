#include <stdio.h>
#include <string.h>
#define START_BYTE '@'
#define DATA_LENGTH 11

void setup() 
{
    Serial.begin(9600);
    Serial.println("start transmit data...");
}

void loop() 
{
    send_data(65530, -314.256, 'm');
}

void send_data(unsigned int v_int, float v_float, char v_char)
{
    char data[DATA_LENGTH] = {};
    data[0] = START_BYTE; 
    memcpy(&data[1], &v_int, sizeof(unsigned int));
    memcpy(&data[5], &v_float, sizeof(float));
    memcpy(&data[9], &v_char, sizeof(char));
    data[10] = checksum(data);
    
    Serial.write(data, DATA_LENGTH);
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
