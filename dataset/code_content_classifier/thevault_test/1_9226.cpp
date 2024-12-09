void BoundedNumberInfo::writeToR1(ostream& os){
    os<<"scaleType='"<<tcsam::getScaleType(scaleType)<<qt<<cc;
    os<<"lower="<<lower<<cc;
    os<<"upper="<<upper<<cc;
    os<<"jitter="<<qt<<wts::getOnOffType(jitter)<<qt<<cc;
    NumberInfo::writeToR1(os);
}