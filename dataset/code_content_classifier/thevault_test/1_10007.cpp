void _txpowertune() {
			byte txpower[LEN_TX_POWER];
			if(_channel == Channel::CHANNEL_1 || _channel == Channel::CHANNEL_2) {
				if(_pulseFrequency == PulseFrequency::FREQ_16MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x1B153555L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x15355575L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x55555555L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x75757575L, LEN_TX_POWER);
						#endif
					}
				} else if(_pulseFrequency == PulseFrequency::FREQ_64MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x0D072747L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x07274767L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x47474747L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x67676767L, LEN_TX_POWER);
						#endif
					}
				} else {
					// TODO proper error/warning handling
				}
			} else if(_channel == Channel::CHANNEL_3) {
				if(_pulseFrequency == PulseFrequency::FREQ_16MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x150F2F4FL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x0F2F4F6FL, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x4F4F4F4FL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x6F6F6F6FL, LEN_TX_POWER);
						#endif
					}
				} else if(_pulseFrequency == PulseFrequency::FREQ_64MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x0B2B4B6BL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x2B4B6B8BL, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x6B6B6B6BL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x8B8B8B8BL, LEN_TX_POWER);
						#endif
					}
				} else {
					// TODO proper error/warning handling
				}
			} else if(_channel == Channel::CHANNEL_4) {
				if(_pulseFrequency == PulseFrequency::FREQ_16MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x1F1F1F3FL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x1F1F3F5FL, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x3F3F3F3FL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x5F5F5F5FL, LEN_TX_POWER);
						#endif
					}
				} else if(_pulseFrequency == PulseFrequency::FREQ_64MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x1A3A5A7AL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x3A5A7A9AL, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x7A7A7A7AL, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x9A9A9A9AL, LEN_TX_POWER);
						#endif
					}
				} else {
					// TODO proper error/warning handling
				}
			} else if(_channel == Channel::CHANNEL_5) {
				if(_pulseFrequency == PulseFrequency::FREQ_16MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x140E0828L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x0E082848L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x28282828L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x48484848L, LEN_TX_POWER);
						#endif
					}
				} else if(_pulseFrequency == PulseFrequency::FREQ_64MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x05254565L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x25456585L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x65656565L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x85858585L, LEN_TX_POWER);
						#endif
					}
				} else {
					// TODO proper error/warning handling
				}
			} else if(_channel == Channel::CHANNEL_7) {
				if(_pulseFrequency == PulseFrequency::FREQ_16MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x12325272L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x32527292L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x72727272L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x92929292L, LEN_TX_POWER);
						#endif
					}
				} else if(_pulseFrequency == PulseFrequency::FREQ_64MHZ) {
					if(_smartPower) {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0x315191B1L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0x5171B1D1L, LEN_TX_POWER);
						#endif
					} else {
						#if DWM1000_OPTIMIZED
						DW1000NgUtils::writeValueToBytes(txpower, 0xB1B1B1B1L, LEN_TX_POWER);
						#else
						DW1000NgUtils::writeValueToBytes(txpower, 0xD1D1D1D1L, LEN_TX_POWER);
						#endif
					}
				} else {
					// TODO proper error/warning handling
				}
			} else {
				// TODO proper error/warning handling
			}
			_writeBytesToRegister(TX_POWER, NO_SUB, txpower, LEN_TX_POWER);
		}