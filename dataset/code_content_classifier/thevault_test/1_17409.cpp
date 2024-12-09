bool remove_crlf_in_clipboard() {
        auto hwnd = util::get_foreground_window() ;
        bind::SmartClipboard scb(hwnd) ;
        scb.open() ;

        std::string str ;
        scb.get_as_str(str) ;

        if(!str.empty()) {
            auto pos = str.find_last_not_of("\r\n") ;
            if(pos != std::string::npos) {
                str = str.substr(0, pos + 1) ;
                if(!str.empty()) {
                    scb.set(str) ;
                }
            }
        }

        return !str.empty() ;
    }