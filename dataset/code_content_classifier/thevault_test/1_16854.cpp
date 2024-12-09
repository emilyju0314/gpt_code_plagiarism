int SlamMap::getPixelX() {

    if (mapInitData_) {

        double pos_tmp = (getOriginPosX() - position_x);
        int pixel_x = (int) (pos_tmp / mapResolution_);
        pixel_x = -pixel_x;
        return pixel_x;
    }
}