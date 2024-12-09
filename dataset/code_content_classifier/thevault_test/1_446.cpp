void ctrlloop(ap_uint<32> iomem [IOMEM_SPACE_SIZE],
	ap_uint<32> regs[REG_SPACE_SIZE],
	const ap_uint<4> buttons,
	ap_uint<4>& leds){
/* Define a new AXI-Lite bus named CTRL for HLS Status/Control registers
   (return)*/
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
/* Define the argument reg as an AXI-Slave port, shared with the bundle
 * CTRL. Values read and written to reg will be accessible from this AXI-Slave
 * bus. The address of the registers is equal to REG_SPACE_SIZE (by default) */
#pragma HLS INTERFACE s_axilite port=regs   bundle=CTRL
/* Define a new AXI-Master bus named MEM represented by the argument
 * iomem. Writes and reads to iomem will be seen on this AXI port. This bus will
 * be used to talk to AXI peripherals such as UART, SPI, and I2C */ 
#pragma HLS INTERFACE m_axi port=iomem bundle=IOMEM
/* Define the port leds to be a port with no protocol. This will generate a
 * 4-bit output port for driving leds*/
#pragma HLS INTERFACE ap_none port=leds
/* Define the port buttons to be a port with no protocol. This will generate a
 * 4-bit output port for driving buttons*/
#pragma HLS INTERFACE ap_none port=buttons


	static ap_uint<4> led_state = 0;
/* Define that the static variable led_state should be driven to 0 (it's default
 * value) on reset*/
#pragma HLS reset variable=led_state
	led_state++;
	// Drive the LEDs to the current value of led_state
	leds = led_state;

	// Set the value of reg at index 0 to the value of buttons.
	regs[0] = buttons;

	// Make this function delay until 1000 milliseconds have passed *since
	// it started*. 
	delay_until_ms<1000>();	
	return;
}