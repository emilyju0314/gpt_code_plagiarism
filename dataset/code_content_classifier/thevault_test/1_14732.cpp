uint32_t kronos() {
	cli();
	uint32_t out = ((uint32_t) (timer_ovf_count << 8)) | TCNT0;
	sei();
	return out;
}