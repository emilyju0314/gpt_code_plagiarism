void State::setTimes(double mintime, double maxtime)
{
	double incr = (maxtime - mintime) / size_;
	double tim = mintime;
	for (int i = 0; i < size_; i++) {
		tim += incr;
		states[i].time = tim;
	}
}