void start_pwm(float dutycycle)
{
  OCR0A   = static_cast<uint16_t>(PWM_16BIT_TOP * dutycycle);
  TCCR0B |= (1 << CS00); //set prescaler to 1 / start timer
}