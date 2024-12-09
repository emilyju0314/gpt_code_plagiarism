string Automaton::IsLastValidUtf8Str(const vector<uint8_t>& byteVec) {
    string s;
    uint32_t nByte;
    for (vector<uint8_t>::const_reverse_iterator rit = byteVec.rbegin();
         rit != byteVec.rend(); ++rit) {
        s.push_back(*rit);
        if (Utf8Util::IsUtf8Beginning(*rit,nByte)) {
            if (s.size() == nByte) {
                std::reverse(s.begin(), s.end());
                return s;
            }
            break;
        }
    }
    s.clear();
    return s;
}