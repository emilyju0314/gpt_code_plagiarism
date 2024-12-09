void xiRefCounter::Drop() const {
	--referenceCount;

	if( referenceCount == 0 ) {
		Delete();
	}
}