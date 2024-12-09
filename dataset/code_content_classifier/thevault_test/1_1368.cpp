Label::WordCache Label::calculate_word_cache(const Ref<Font> &font, const String &label_text) const {
	WordCache cache;
	cache.line_count = 1;
	cache.total_char_cache = 0;
	cache.cache_text = label_text;

	if (autowrap) {
		Ref<StyleBox> style = get_stylebox("normal");
		cache.width = MAX(get_size().width, get_custom_minimum_size().width) - style->get_minimum_size().width;
	} else {
		cache.width = get_longest_line_width(label_text);
	}

	real_t current_word_size = 0;
	int word_pos = 0;
	int line_pos = 0;
	real_t line_width = 0;
	int space_count = 0;
	real_t space_width = font->get_char_size(' ').width + horizontal_spacing;

	WordList *root = nullptr, *last = nullptr;

	for (int i = 0; i <= label_text.length(); i++) {
		CharType current = i < label_text.length() ? label_text[i] : L' '; //always a space at the end, so the algo. works

		if (uppercase) {
			current = String::char_uppercase(current);
		}

		// ranges taken from https://en.wikipedia.org/wiki/Plane_(Unicode)
		// if your language is not well supported, consider helping improve
		// the unicode support in Godot.
		bool separatable = (current >= 0x2E08 && current <= 0x9FFF) || // CJK scripts and symbols.
				(current >= 0xAC00 && current <= 0xD7FF) || // Hangul Syllables and Hangul Jamo Extended-B.
				(current >= 0xF900 && current <= 0xFAFF) || // CJK Compatibility Ideographs.
				(current >= 0xFE30 && current <= 0xFE4F) || // CJK Compatibility Forms.
				(current >= 0xFF65 && current <= 0xFF9F) || // Halfwidth forms of katakana
				(current >= 0xFFA0 && current <= 0xFFDC) || // Halfwidth forms of compatibility jamo characters for Hangul
				(current >= 0x20000 && current <= 0x2FA1F) || // CJK Unified Ideographs Extension B ~ F and CJK Compatibility Ideographs Supplement.
				(current >= 0x30000 && current <= 0x3134F); // CJK Unified Ideographs Extension G.
		bool insert_newline = false;
		real_t char_width = 0;

		if (current < 33) {
			if (current_word_size > 0) {
				WordList *wc = memnew(WordList);
				if (root) {
					last->next = wc;
				} else {
					root = wc;
				}
				last = wc;

				wc->pixel_width = current_word_size - horizontal_spacing; // remove last horizontal_spacing
				wc->char_pos = word_pos;
				wc->word_len = i - word_pos;
				wc->line = cache.line_count - 1;
				wc->line_pos = line_pos - wc->word_len;
				wc->space_count = space_count;
				current_word_size = 0;
				space_count = 0;
			} else if ((i == xl_text.length() || current == '\n') && last != nullptr && space_count != 0) {
				//in case there are trailing white spaces we add a placeholder word cache with just the spaces
				WordList *wc = memnew(WordList);
				if (root) {
					last->next = wc;
				} else {
					root = wc;
				}
				last = wc;

				wc->pixel_width = 0;
				wc->char_pos = 0;
				wc->word_len = 0;
				wc->space_count = space_count;
				current_word_size = 0;
				space_count = 0;
			}

			if (current == '\n') {
				insert_newline = true;
			} else if (current != ' ') {
				cache.total_char_cache++;
			}

			line_pos++;

			if (i < label_text.length() && label_text[i] == ' ') {
				if (line_width > 0 || last == nullptr || last->char_pos != WordList::CHAR_WRAPLINE) {
					space_count++;
					line_width += space_width;
				} else {
					space_count = 0;
				}
			}

		} else {
			// latin characters
			if (current_word_size == 0) {
				word_pos = i;
			}
			char_width = font->get_char_size(current, label_text[i + 1]).width + horizontal_spacing;
			current_word_size += char_width;
			line_width += char_width;
			line_pos++;
			cache.total_char_cache++;

			// allow autowrap to cut words when they exceed line width
			if (autowrap && (current_word_size > word_cache.width)) {
				separatable = true;
			}
		}

		if ((autowrap && (line_width - horizontal_spacing >= word_cache.width) && ((last && last->char_pos >= 0) || separatable)) || insert_newline) {
			if (separatable) {
				if (current_word_size > 0) {
					WordList *wc = memnew(WordList);
					if (root) {
						last->next = wc;
					} else {
						root = wc;
					}
					last = wc;

					wc->pixel_width = current_word_size - char_width - horizontal_spacing;
					wc->char_pos = word_pos;
					wc->word_len = i - word_pos;
					wc->line = cache.line_count - 1;
					wc->line_pos = line_pos - wc->word_len;
					wc->space_count = space_count;
					current_word_size = char_width;
					word_pos = i;
				}
			}

			WordList *wc = memnew(WordList);
			if (root) {
				last->next = wc;
			} else {
				root = wc;
			}
			last = wc;

			wc->pixel_width = 0;
			wc->char_pos = insert_newline ? WordList::CHAR_NEWLINE : WordList::CHAR_WRAPLINE;
			wc->line = cache.line_count - 1;

			cache.line_count++;

			line_width = current_word_size;
			line_pos = 0;
			space_count = 0;
		}
	}
	cache.words = root;

	return cache;
}