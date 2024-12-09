jni::jboolean NativeMapView::removeLayer(JNIEnv&, jlong layerPtr) {
    assert(layerPtr != 0);

    mbgl::android::Layer *layer = reinterpret_cast<mbgl::android::Layer *>(layerPtr);
    std::unique_ptr<mbgl::style::Layer> coreLayer = map->getStyle().removeLayer(layer->get().getID());
    if (coreLayer) {
        layer->setLayer(std::move(coreLayer));
        return jni::jni_true;
    }
    return jni::jni_false;
}