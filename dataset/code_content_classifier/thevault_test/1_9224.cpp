void BoundedNumberInfo::write(ostream & os){
    os<<wts::getOnOffType(jitter)<<tb;
    os<<lower<<tb;
    os<<upper<<tb;
    NumberInfo::write(os);//finish writing
}