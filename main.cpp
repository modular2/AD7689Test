#include "mbed.h"
#include "AD7689.h"
#define SPI_MOSI PF_9
#define SPI_MISO PF_8
#define SPI_SCK  PF_7
#define CNV PF_4
AD7689 ad7689(SPI_MOSI, SPI_MISO, SPI_SCK,CNV);
DigitalOut myled(PC_6);
Serial pc(USBTX, USBRX);
int main() {
    uint32_t value;
    double ADCVoltage,ReadOut;
    int sel;// Select analog channel
    pc.baud(115200);
    sel=0;
    ad7689.config(0X3C51);//0x3c51|(sel<<6)
    while(1) {
       value= ad7689.ReadData();
       ADCVoltage=(double)(value*4.096)/65535;
       ReadOut=10-(ADCVoltage-0.05)*20/4;//voltage input to ADC =0.05 to 4.057V
       printf("%4.2f\n",ReadOut);
       // myled = 1; // LED is ON
       // wait(1); // 200 ms
       // myled = 0; // LED is OFF
       // wait(1.0); // 1 sec
    }
}
