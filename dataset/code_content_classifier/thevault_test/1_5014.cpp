static void readStringField(char *field, std::FILE *file, int fieldSize) {
	char previous = ';';
	char current = std::fgetc(file);
	int index = 0;

	switch (current) {
	// Case in which the field has no characters: ;;
	case ';':
		break;
	
	// Case in which the last field has no characters, so there's only an LF line break
	case '\n':
		break;
	
	// Case in which the last field has no characters, but there's still a CRLF line break
	case '\r':
		std::fgetc(file); // '\n'
		break;
	
	// Case in which instead of a field there's only NULL
	case 'N':
		std::fgetc(file); // 'U'
		std::fgetc(file); // 'L'
		std::fgetc(file); // 'L'
		if (std::fgetc(file) == '\r') std::fgetc(file); // Skips the line break, be it LF or CRLF
		break;
	
	// Case in which there's a string in the field
	case '"':
		while (true) {
			previous = current;
			current = fgetc(file);
			
			if (previous == '"') {
				bool fieldEnded = false;
				
				// If the quotes are followed by either of these elements, then we've reached the end of the field
				switch (current) {
				case '\r':
					std::fgetc(file); // '\n'
				case ';':
				case '\n':
				case EOF:
					--index;
					fieldEnded = true;
					break;
				}
				
				if (fieldEnded) break;
			}
			
			if (current >= 0) {
				// Only insert the character in the buffer if there's still
				// space left (taking into account the '\0' end character).
				// We'll keep reading the file until the end of the column.
				if (index < fieldSize - 1) {
					field[index] = current;
				}

				++index;
			}
		}
		
		break;
	}
	
	if (index >= fieldSize) {
		index = fieldSize - 1;
	}
	
	field[index] = '\0';
}