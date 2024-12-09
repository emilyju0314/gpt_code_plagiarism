mdILI9341_SPI::mdILI9341_SPI(int8_t cs, int8_t dc, int8_t mosi,
                               int8_t sclk, int8_t rst, int8_t miso)
                               : DisplayDriver(ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT)
    {
      _cs   = cs;
      _dc   = dc;
      _mosi = mosi;
      _miso = miso;
      _sclk = sclk;
      _rst  = rst;
      hwSPI = false;
    }