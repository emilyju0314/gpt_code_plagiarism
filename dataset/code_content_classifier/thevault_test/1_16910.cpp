static bool serialized_as_vector(TypeTag tag)
	{
	switch ( tag )
		{
		case TYPE_VECTOR:
		case TYPE_RECORD:
		case TYPE_FUNC:
		case TYPE_PATTERN:
		case TYPE_OPAQUE:
			return true;
		default:
			return false;
		}
	return false;
	}