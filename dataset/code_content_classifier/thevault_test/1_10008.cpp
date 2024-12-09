void deepSleep() {
		/* Clear the register */
		_writeValueToRegister(AON, AON_CTRL_SUB, 0x00, LEN_AON_CTRL);
		/* Write 1 in SAVE_BIT */
		_writeValueToRegister(AON, AON_CTRL_SUB, 0x02, LEN_AON_CTRL);
	}