bool isSchnitt(Vector3d l1, Vector3d l2, double distMin, double distMax) {
		Vector3d schnittPunkt;
		l1 = l1 + ((l2 - l1).normalized() * distMin);

		if (isBlatt())
		// Schnittpunkte berechnen und den nähesten zurückgeben wenn es einen gibt
		{

			for (list<Dreieck *>::iterator it = dreiecke.begin(); it != dreiecke.end(); it++) {
	if ((**it).intersectLine(l1, l2, schnittPunkt))
		return true;
			}

		} else {
			for (list<BoundingBox *>::iterator itBox = kindBoxen.begin();
					 itBox != kindBoxen.end(); itBox++) {
	if ((*itBox)->inside(l1, l2)) {

		if ((*itBox)->isSchnitt(l1, l2, distMin, distMax))
			return true;
	}
			}
		}
		return false;
	}