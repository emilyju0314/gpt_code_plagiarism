void DS1337::setTime(String time) {
	time.trim();
	if (time.length()==5)
	setTime(time.substring(0, 2).toInt(), time.substring(3, 5).toInt());
	else if (time.length()==8)
		setTime(time.substring(0, 2).toInt(), time.substring(3, 5).toInt(), time.substring(6, 8).toInt());
}