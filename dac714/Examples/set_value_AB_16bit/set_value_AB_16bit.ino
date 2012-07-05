#include <SPI.h>
#include "dac714.h"

#define AOUT_A0 10
#define AOUT_A1 9

DAC714 analogOut = DAC714(AOUT_A0,AOUT_A1);

void setup() {
    // Setup serial and SPI communications
    Serial.begin(115200);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    SPI.begin();
}


void loop() {
    static uint16_t cnt=0;
    analogOut.setValue_AB(cnt,-cnt);
    cnt += 1;
}
