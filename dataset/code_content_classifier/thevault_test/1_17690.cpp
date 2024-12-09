bool is_breaking_asian_glyph(wchar_t ch)
        {
            return (ch >= 0x3040 && ch <= 0x3096) || // Hiragana
                   (ch >= 0x30a0 && ch <= 0x30fa) || // Katakana
                   (ch >= 0x4e00 && ch <= 0x9fff) || // CJK Unfied Ideographs
                   (ch >= 0x3400 && ch <= 0x4db5);   // CJK Unified Ideographs Extension A
        }