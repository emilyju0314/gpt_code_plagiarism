int SpiderStage::sort_for_target(Node2D *p_source, Point2 p_location, InsectSprite *&p_target) {
	p_target = 0;
	if (!insects.empty()) {
		InsectCompByDist cp(p_location);
		stdx::sort(insects.begin(), insects.end(), cp);

		bool clean_rest = false;
		int i = 0;

		for (InsectSprite &insect : insects) {
			if (clean_rest) {
				if (insect.get_target() == p_source)
					insect.set_target(nullptr);
			} else if (insect.get_target() == p_source && i < SpidersMaxSpiders) {
				p_target = &insect; // selected insect
				clean_rest = true; // clean rest of the insects
			} else if (insects[i].get_target() == nullptr && !p_target) {
				p_target = &insect; // first free insect
			}
			i++;
		}
	}

	return insects.size();
}