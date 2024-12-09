void Tool_gasparize::fixHangingTie(HTp first, HTp second) {
	string text = *second;
	text += "]";
	second->setText(text);
}