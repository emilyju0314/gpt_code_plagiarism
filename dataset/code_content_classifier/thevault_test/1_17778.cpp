void Transform::easeTo(const CameraOptions& camera, const AnimationOptions& animation) {
    Duration duration = animation.duration.value_or(Duration::zero());
    if (state.getLatLngBounds() == LatLngBounds() && !isGestureInProgress() && duration != Duration::zero()) {
        // reuse flyTo, without exaggerated animation, to achieve constant ground speed.
        return flyTo(camera, animation, true);
    }
    const EdgeInsets& padding = camera.padding.value_or(state.getEdgeInsets());
    LatLng startLatLng = getLatLng(LatLng::Unwrapped);
    const LatLng& unwrappedLatLng = camera.center.value_or(startLatLng);
    const LatLng& latLng = state.getLatLngBounds() != LatLngBounds() ? unwrappedLatLng : unwrappedLatLng.wrapped();
    double zoom = camera.zoom.value_or(getZoom());
    double bearing = camera.bearing ? -*camera.bearing * util::DEG2RAD : getBearing();
    double pitch = camera.pitch ? *camera.pitch * util::DEG2RAD : getPitch();

    if (std::isnan(zoom) || std::isnan(bearing) || std::isnan(pitch)) {
        if (animation.transitionFinishFn) {
            animation.transitionFinishFn();
        }
        return;
    }

    if (state.getLatLngBounds() == LatLngBounds()) {
        if (isGestureInProgress()) {
            // If gesture in progress, we transfer the wrap rounds from the end longitude into
            // start, so the "scroll effect" of rounding the world is the same while assuring the
            // end longitude remains wrapped.
            const double wrap = unwrappedLatLng.longitude() - latLng.longitude();
            startLatLng = LatLng(startLatLng.latitude(), startLatLng.longitude() - wrap);
        } else {
            // Find the shortest path otherwise.
            startLatLng.unwrapForShortestPath(latLng);
        }
    }

    const Point<double> startPoint = Projection::project(startLatLng, state.getScale());
    const Point<double> endPoint = Projection::project(latLng, state.getScale());

    // Constrain camera options.
    zoom = util::clamp(zoom, state.getMinZoom(), state.getMaxZoom());
    pitch = util::clamp(pitch, state.getMinPitch(), state.getMaxPitch());

    // Minimize rotation by taking the shorter path around the circle.
    bearing = _normalizeAngle(bearing, state.getBearing());
    state.setBearing(_normalizeAngle(state.getBearing(), bearing));

    const double startZoom = state.getZoom();
    const double startBearing = state.getBearing();
    const double startPitch = state.getPitch();
    state.setProperties(TransformStateProperties()
                            .withPanningInProgress(unwrappedLatLng != startLatLng)
                            .withScalingInProgress(zoom != startZoom)
                            .withRotatingInProgress(bearing != startBearing));
    const EdgeInsets startEdgeInsets = state.getEdgeInsets();

    startTransition(
        camera,
        animation,
        [=](double t) {
            Point<double> framePoint = util::interpolate(startPoint, endPoint, t);
            LatLng frameLatLng = Projection::unproject(framePoint, state.zoomScale(startZoom));
            double frameZoom = util::interpolate(startZoom, zoom, t);
            state.setLatLngZoom(frameLatLng, frameZoom);
            if (bearing != startBearing) {
                state.setBearing(util::wrap(util::interpolate(startBearing, bearing, t), -M_PI, M_PI));
            }
            if (padding != startEdgeInsets) {
                // Interpolate edge insets
                EdgeInsets edgeInsets;
                state.setEdgeInsets({util::interpolate(startEdgeInsets.top(), padding.top(), t),
                                     util::interpolate(startEdgeInsets.left(), padding.left(), t),
                                     util::interpolate(startEdgeInsets.bottom(), padding.bottom(), t),
                                     util::interpolate(startEdgeInsets.right(), padding.right(), t)});
            }
            double maxPitch = getMaxPitchForEdgeInsets(state.getEdgeInsets());
            if (pitch != startPitch || maxPitch < startPitch) {
                state.setPitch(std::min(maxPitch, util::interpolate(startPitch, pitch, t)));
            }
        },
        duration);
}