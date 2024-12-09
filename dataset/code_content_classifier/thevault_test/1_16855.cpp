int SlamMap::getPixelY() {

    if (mapInitData_) {

        double pos_tmp = (-getOriginPosX() - position_y);
        int pixel_y = (int) (pos_tmp / mapResolution_);
        return pixel_y;
    }
}