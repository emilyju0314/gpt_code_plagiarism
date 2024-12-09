void Fl_Timer::suspended(char d) {
  if (!d) {
    if (on) return;
    on = (delay > 0.0);
    fl_gettime(&(lastsec), &(lastusec));
    if (on) Fl::add_timeout(FL_TIMER_BLINKRATE, stepcb, this);
  } else {
    if (!on) return;
    on = 0;
    Fl::remove_timeout(stepcb, this);
  }
}