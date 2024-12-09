EtherCatBus(std::unique_ptr<EtherCatBusOptions>&& options)
    : tcan::Bus<EtherCatDatagrams>(std::move(options)),
      wkcExpected_(0),
      wkc_(0) {
      // Initialize all SOEM context data pointers that are not used with null.
      ecatContext_.port->stack.sock = nullptr;
      ecatContext_.port->stack.txbuf = nullptr;
      ecatContext_.port->stack.txbuflength = nullptr;
      ecatContext_.port->stack.tempbuf = nullptr;
      ecatContext_.port->stack.rxbuf = nullptr;
      ecatContext_.port->stack.rxbufstat = nullptr;
      ecatContext_.port->stack.rxsa = nullptr;
      ecatContext_.port->redport = nullptr;
//      ecatContext_.idxstack->data = nullptr; // This does not compile since SOEM uses a fixed size array of void pointers.
      ecatContext_.FOEhook = nullptr;
    }