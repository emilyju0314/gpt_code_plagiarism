bool BencEntity::SetParsed( IBencParser::PARSE_T parseResult, const unsigned char *pElement, size_t size, AllocRegime *regime )
{
	switch( parseResult ) {
		case IBencParser::INT : {
			if(! regime->LazyInt() ){
				BencEntity be(BENC_INT);
				MoveFrom(be);
				ParseNum(pElement);
			} else {
				BencEntityLazyInt beLazy(regime->NewMem((unsigned char *) pElement, (int)size));
				MoveFrom( (BencEntity &) beLazy );
			}
			break;
		}
		case IBencParser::STRING : {
			BencEntityMem beM(regime->NewStr((unsigned char *) pElement, (int)size));
			MoveFrom(beM);
			break;
		}
		case IBencParser::LIST : {
			BencodedList beL;
			MoveFrom(beL);
			break;
		}
		case IBencParser::DICT : {
			BencodedDict beD;
			MoveFrom(beD);
			break;
		}
		case IBencParser::BERROR :
		case IBencParser::END_E :
		case IBencParser::DONE :
		default:
			return false;
	}
	return true;
}