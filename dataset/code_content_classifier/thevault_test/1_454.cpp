void DS1337::setAlarm(String time) {
  time.trim();
  if (time.length()==5)
	  setAlarm(time.substring(0, 2).toInt(), time.substring(3, 5).toInt(), 0);
  else if (time.length()==8)
	  setAlarm(time.substring(0, 2).toInt(), time.substring(3, 5).toInt(), time.substring(6, 8).toInt(), 0);
}