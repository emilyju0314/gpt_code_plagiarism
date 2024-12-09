std::string FunctionDumper::getOffsetType() {
    if(offsets_32bit) {
       return "uint";
    } else {
       return "long";
   }
}