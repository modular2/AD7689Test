#include "mbed.h"
class AD7689 {
    public:
    AD7689(PinName mosi,PinName miso,PinName clk,PinName cnv);
    uint16_t ReadData();
     void config(uint16_t option);
    private:
        SPI _spi;
       DigitalOut _cnv; 
};
     