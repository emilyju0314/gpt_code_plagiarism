void DS1337::setDateTime(unsigned long timestamp) {
    int y,m,d,h,mm,s;
	DS1337::getTime(timestamp, y, m, d, h, mm, s);
    setDateTime(y, m, d, h, mm, s);
}