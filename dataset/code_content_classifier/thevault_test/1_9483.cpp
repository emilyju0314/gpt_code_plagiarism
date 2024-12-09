BoundingBox(list<Dreieck*> dreiecke, int unterteilung) {
		this->unterteilung = unterteilung;
		this->dreiecke = dreiecke;

		min.set(0, 0, 0);
		max.set(0, 0, 0);
		int count = 0;
		for (list<Dreieck *>::iterator it = dreiecke.begin(); it != dreiecke.end();
				 it++) {
			count++;
			double xMin = std::min(
		std::min(std::min(min.x, (*it)->p1.x), (*it)->p2.x), (*it)->p3.x);
			double yMin = std::min(
		std::min(std::min(min.y, (*it)->p1.y), (*it)->p2.y), (*it)->p3.y);
			double zMin = std::min(
		std::min(std::min(min.z, (*it)->p1.z), (*it)->p2.z), (*it)->p3.z);

			double xMax = std::max(
		std::max(std::max(max.x, (*it)->p1.x), (*it)->p2.x), (*it)->p3.x);
			double yMax = std::max(
		std::max(std::max(max.y, (*it)->p1.y), (*it)->p2.y), (*it)->p3.y);
			double zMax = std::max(
		std::max(std::max(max.z, (*it)->p1.z), (*it)->p2.z), (*it)->p3.z);
			min.set(xMin, yMin, zMin);
			max.set(xMax, yMax, zMax);
		}
		logVar("Neue Bounding Box erzeugt. Polygone enthalten: ", count);
	}