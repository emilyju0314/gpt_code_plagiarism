void SpiderStage::eat(const InsectSprite *p_killed) {
	ERR_FAIL_NULL(root);
	ERR_FAIL_NULL(p_killed);

	auto f = std::find(insects.begin(), insects.end(), *p_killed);
	if (f != insects.end()) {
		insects.detach(f); // remove killed bug from insects list
		root->remove_child(const_cast<InsectSprite *>(p_killed)); // and free
		dirty_insects++;
		insects_eaten++;
	}
}