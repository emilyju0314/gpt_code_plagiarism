void SceneDemo::updateSnapshotContactPoints() {

    // Remove the previous contact points
    removeAllVisualContactPoints();

    // For each contact point
    std::vector<SceneContactPoint>::const_iterator it;
    for (it = mSnapshotsContactPoints.begin(); it != mSnapshotsContactPoints.end(); ++it) {

        // Create a visual contact point for rendering
        VisualContactPoint* point = new VisualContactPoint(it->point, it->point + it->normal, it->color);
        mVisualContactPoints.push_back(point);
    }
}