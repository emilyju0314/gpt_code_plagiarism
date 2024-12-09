void DS1337::snooze(int minutes) {
	clearAlarm();
	if (minutes>0 && minutes<=60) {
		Date _currentAlarm = getAlarm();
		_currentAlarm.setMinutes(_currentAlarm.getMinutes()+minutes);
		if (_currentAlarm.getMinutes()>60) {
			_currentAlarm.setMinutes(_currentAlarm.getMinutes()-60);
			_currentAlarm.setHour(_currentAlarm.getHour()+1);
			if (_currentAlarm.getHour()>23) {
				_currentAlarm.setHour(0);
				_currentAlarm.setDay(_currentAlarm.getDay()+1);
			}
		}
		setAlarm(_currentAlarm);
	}
}