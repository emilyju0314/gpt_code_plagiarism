bool check_stop_search(unsigned depth, UCIOptions& options, SearchState& search_state) {
        if (search_state.height < MIN_DEPTH && depth < MIN_DEPTH) {
            return false;
        }

        /// If the depth we've reached exceeds the max depth, then stop the search
        if (depth > MAX_DEPTH) {
            search_state.time_exit = true;
            return true;
        }

        /// If the user has asked us to stop, then stop
#ifndef WIND32
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(fileno(stdin), &readfds);
        struct timeval tv{};
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        select(16, &readfds, nullptr, nullptr, &tv);

        bool ret = (FD_ISSET(fileno(stdin), &readfds));
        int bytes;
        char input[256] = "", *endc;

        if (ret) {
            do {
                bytes = read(fileno(stdin), input, 256);
            } while (bytes < 0);
            endc = strchr(input, '\n');
            if (endc) {
                *endc = 0;
            }
            if (strlen(input)> 0) {
                if (!strncmp(input, "stop", 4)) {
                    options.infinite = false;
                    search_state.time_exit = true;
                    return true;
                }
            }
        }
#endif // NOT WINDOWS

        /// If the engine is pondering or in an infinite search, then don't stop the search
        if (options.infinite || options.ponder) {
            return false;
        }

        /// If it's sudden death, and we've run outta time, then stop the search
        if (options.sudden_death && search_state.clock.has_exceeded_time()) {
            search_state.time_exit = true;
            return true;
        }

        /// If we're supposed to search to a specific depth, and we've reached that depth, then stop the search
        if (options.search_to_depth_x == (int)depth) {
            search_state.time_exit = true;
            return true;
        }

        /// If the amount of time that's transpired exceeds the amount of time for the search, then stop
        if (options.move_time != -1) {
            search_state.clock.stop();
            bool should_exit = search_state.clock.duration() / 1000000 > options.move_time;
            search_state.time_exit = should_exit;
            return should_exit;
        }

        return false;

    }