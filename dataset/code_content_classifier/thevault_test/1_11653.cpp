std::string formatDuration( double seconds ) {
            ReusableStringStream rss;
            rss << std::fixed << std::setprecision( 3 ) << seconds;
            return rss.str();
        }