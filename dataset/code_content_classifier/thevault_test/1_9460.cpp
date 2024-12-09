string Format::ElapsedTime(long seconds) { 
  int hours = seconds /3600;
  int minutes = (seconds/60) - (hours*60);
  int only_seconds = seconds - (hours*3600) - (minutes*60);
  return  nice_string(hours) + ":" + nice_string(minutes) + ":" + nice_string(only_seconds); 
}