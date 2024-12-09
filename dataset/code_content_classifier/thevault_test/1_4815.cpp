IBencParser::PARSE_T  BencParserElement::ParseNext( const unsigned char **ppStart, size_t *pSize, bool isKey )
{
	const unsigned char* pElementStart = _p; // store the pointer to the start of the element before ParseNext moves it away
	PARSE_T parseReturn = BencParser::ParseNext( ppStart, pSize, isKey );

	// Skip this business if we think we have found the element
	if ( _elementStart && _elementEnd ) {
		return parseReturn;
	}

	// _lastString is expected to be the key we are interested in.
	switch ( parseReturn )
	{
		case INT:
			// This condition is repeated verbatim for each case below:
			// It means that we capture the result if we have matched every key in the key path so far, and there are no more
			// keys to match in depth.
			if( _lastString && _elementStart == NULL && _level && static_cast<size_t>((1 << _level) - 1) == _keyMatch && !*(_key + _keyLen + 1) ) {
				// +1 and -1 are to include the i-prefix and e-suffix
				_elementStart = const_cast<unsigned char*>((*ppStart)-1);
				_elementEnd = const_cast<unsigned char*>((*ppStart) + *pSize + 1);
			}
			break;
		case STRING :
			if (isKey && _level > 0) 
			{
				_lastString = *ppStart;
				// We mark a key match if we were parsing a key position, and the string matches in length and content
				if (_keyMatch == 0) {
					for (auto k : _keys) {
						size_t size = strlen(k);
						if (memcmp( (unsigned char *) _lastString, k, size) == 0 && size == *pSize) {
							_origKey = _key = k;
							_keyLen = size;
							_keyMatch |= 1 << (_level - 1);
							break;
						}
					}
				}
				else if (memcmp( (unsigned char *) _lastString, _key, _keyLen) == 0 && _keyLen == *pSize) {
					// _keyMatch is a bitstring whose i'th bit remembers whether the key leading here at level i matched
					// the desired key in the key path in _key.
					_keyMatch |= 1 << (_level - 1);
				}
			} else if( _lastString && _elementStart == NULL && _level && static_cast<size_t>((1 << _level) - 1) == _keyMatch && !*(_key + _keyLen + 1) ) {
				_elementStart = const_cast<unsigned char*>(pElementStart);
				_elementEnd = const_cast<unsigned char*>(*ppStart + *pSize);
			}
			break;
		case DICT :
		case LIST :
			// check for "element", record start
			if( _lastString && _elementStart == NULL && _level && static_cast<size_t>((1 << _level) - 1) == _keyMatch && !*(_key + _keyLen + 1) ) {
				_elementStart = const_cast<unsigned char*>(*ppStart - 1);
				_elementLevel = _level;
			}
			_lastString = 0;
			// _keyLen == 0 means that we've exceeded the length of our key path, but we're in a deeper structure
			// in bencoding.  We need to remember how far until we walk back into the key.
			if (_keyLen == 0) {
				_keyLevel++;
			} else if( _level != 0 ) {
				// Go past the \0 end of this key to the next key in the key path.
				_key += _keyLen + 1;
				_keyLen = strlen(_key);
			}
			_level++;
			break;
		case END_E :
			// Unset match for this level, because we're exiting the dictionary.  Note that we might have matches
			// and nonmatches mixed.  We only consider that we have the right element if the value is "all-1s"
			// and we're at the last key.
			_keyMatch &= ~(1 << (_level - 1));
			_level--;
			// _keyLevel remembers how many levels deep we are beyond the key path we were given
			if (_keyLevel > 0)
				_keyLevel--;
			else if ( _level != 0 ) {
				// scan in reverse to the beginning of the previous key in the key path.  Make sure not to
				// check a byte before the whole key path.
				do {
					_key--;
				} while (_key-1 >= _origKey && _key[-1]);
				// We could compute this while scanning but i'm lazy
				_keyLen = strlen(_key);
			}
			if( _elementLevel && _elementStart && _elementLevel == _level && _elementEnd == NULL ) {
				_elementEnd = const_cast<unsigned char*>(*ppStart);	// there, we're done
			}
			break;
		case BERROR:
		case DONE:
		case BPARSE_ABSOLUTE_MAX:
		default:
			// just to quiet some warnings about the switch not addressing these enum items
			break;
	}
	return parseReturn;
}