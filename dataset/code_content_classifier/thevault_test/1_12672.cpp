std::string Grammar::printExpansionType(Expansion * e) {
	switch(e->getType()) {
		case UNPARSED_SECTION:
			return "UNPARSED_SECTION";
			break;
		case KLEENE_STAR:
			return "KLEENE_STAR";
			break;
		case PLUS_OPERATOR:
			return "PLUS_OPERATOR";
			break;
		case REQUIRED_GROUPING:
			return "REQUIRED_GROUPING";
			break;
		case OPTIONAL_GROUPING:
			return "OPTIONAL_GROUPING";
			break;
		case SEQUENCE:
			return "SEQUENCE";
			break;
		case TOKEN:
			return "TOKEN";
			break;
		case ALTERNATE_SET:
			return "ALTERNATIVE_SET";
			break;
		case TAG:
			return "TAG";
			break;
		default:
			return "UNKNOWN TYPE";
			break;
	}
	return "ERROR";
}