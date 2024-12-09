mdILI9341_SPI::mdILI9341_SPI(int8_t cs, int8_t dc, int8_t rst, int16_t _W, int16_t _H)
                               : DisplayDriver(_W,_H)
    {
      _cs     = cs;
      _dc     = dc;
      _rst    = rst;
      hwSPI   = true;
      _mosi   = _sclk = 0;
    }