void ThinLensCamera::setStopNumber(const float newStopNumber) {
    ap.scaleAbs((focalDist / newStopNumber) * 0.5f);
    stopNumber = newStopNumber;
    updateSampler();
}