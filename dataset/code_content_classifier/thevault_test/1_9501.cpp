string Option_register::getOption(void) {
	if (isModified()) {
		return getModified();
	} else {
		return getDefault();
	}
}