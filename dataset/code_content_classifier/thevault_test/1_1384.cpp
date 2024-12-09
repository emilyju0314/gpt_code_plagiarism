void SpiderStage::add(InsectSprite *p_insect) {
	ERR_FAIL_NULL(root);

	p_insect->set_tilt_factor(_factor_y);
	root->add_child(p_insect);
	insects.push_back(p_insect);
}