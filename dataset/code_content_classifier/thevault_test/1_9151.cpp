bool isValidUtf8(const std::string &s) {
      // cannot replace for std::string_view for security reasons
      //std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>
      //---------- fixed by ruymaster --- need to check on ubuntu --- //
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>
          utf16conv;
      try {
        auto utf16 = utf16conv.from_bytes(s.data());
      } catch (...) {
        return false;
      }
      return true;
    }