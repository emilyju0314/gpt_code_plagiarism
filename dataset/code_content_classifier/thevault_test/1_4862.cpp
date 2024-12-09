bool Scene::scrollingEvent(float /*xAxis*/, float yAxis, float scrollSensitivy) {
    zoom(yAxis * scrollSensitivy);

    return true;
}