void PathFinder::printTime(std::ostream& ostr, const double& timemin) const
    {
        double minpart, secpart;
        double time_min_024 = timemin;
        char   cross_day    = ' ';

        // this version is in [0,1440)
        if (time_min_024 < 0) {
            time_min_024 += 1440.0;
            cross_day    = '-';
        }
        if (time_min_024 >= 1440.0) {
            time_min_024 -= 1440.0;
            cross_day     = '+';
        }
        int    hour = static_cast<int>(time_min_024/60.0);

        secpart = modf(time_min_024, &minpart); // split into minutes and seconds
        minpart = minpart - hour*60.0;
        secpart = secpart*60.0;
        ostr << std::right;
        ostr << std::setw( 1) << cross_day;
        ostr << std::setw( 2) << std::setfill('0') << hour                       << ":"; // hour
        ostr << std::setw( 2) << std::setfill('0') << static_cast<int>(minpart)  << ":"; // minutes
        ostr << std::setw( 2) << std::setfill('0') << static_cast<int>(secpart);
    }