#include "mbed.h"
#include "AD7689.h"
AD7689::AD7689(PinName mosi,PinName miso,PinName clk,PinName cnv)
:_spi(mosi,miso,clk),
_cnv(cnv){
      _spi.format(16,1);
    _spi.frequency(1500000);
    _cnv=1;
 
}
uint16_t AD7689::ReadData()
{uint16_t v;
   _cnv=0; 
  v=_spi.write(0xffff);
   _cnv=1;
  return v;
    }
void AD7689::config(uint16_t option)
 {  
 _spi.write(option);
     }
