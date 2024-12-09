ISR(TIMER4_CAPT_vect)
{
  TCNT4 = 0;
  speed_time_current = (time_counter * 0.024992f + TIMER_FREQUENCY * static_cast<float>(ICR4));
  speed_current      = (0.15*2*PI/speed_time_current);
  time_counter       = 0;
  flag  = 1;
}