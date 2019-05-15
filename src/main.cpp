#include <mbed.h>
#include <USBSerial.h>

int main() {
I2C dac(PB_9,PB_8);
USBSerial serial;
int address = 0x94;
char status1 = 0x01,chip1= 0x2E,status2 = 00000000,chip2 = 00000000;
while(1){
  dac.write(address,&status1,1);
  dac.read(address,&status2,1);
  dac.write(address,&chip1,1);
  dac.read(address,&chip2,1);
  serial.printf("Status: %c\nChip: %s\nAddress:0x%x\n",&status2,&chip2,address);
  wait(1);
  }
}