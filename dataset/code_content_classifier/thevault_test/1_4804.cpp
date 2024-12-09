void BencEntity::MoveFrom(BencEntity& be)
{
	assert(bencType == be.bencType || bencType == BENC_VOID || bencType == BENC_NULL);
	assert(this != &be);
	FreeMembers();
	switch (be.bencType) {
		case BENC_STR:
		case BENC_STR_INPLACE:
		case BENC_INT_LAZY:
			mem = be.mem;
			break;
		case BENC_VLIST:
			vlist = be.vlist;
			break;
		case BENC_LIST:
			list = be.list;
			break;
		case BENC_DICT:
			dict = be.dict;
			break;
		case BENC_INT:
		case BENC_BIGINT:
		case BENC_VOID:
		default:
			num = be.num;
			break;
	}
	bencType = be.bencType;
	be.ZeroOut();
}