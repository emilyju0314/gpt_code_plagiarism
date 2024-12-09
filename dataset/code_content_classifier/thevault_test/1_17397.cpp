uint32_t md_31855_ktype::spiread32(void)
      {
        uint32_t  val;
        uint8_t   buf[4];
        uint32_t* pbuf = (uint32_t*) &buf[0];

        _spi.read(buf, 4);        // MSB first
        val  = buf[0]; val <<= 8;
        val |= buf[1]; val <<= 8;
        val |= buf[2]; val <<= 8;
        val |= buf[3];
             //SOUT(" spi buf[0-3] "); SOUTHEX(*pbuf);
             //SOUT(" result "); SOUTHEXLN(val);
        return val;
      }