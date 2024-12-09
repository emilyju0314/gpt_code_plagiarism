void BaseRuntimeInfo::SaveTimeAttribute(TiXmlElement* element,
                                    const char* name, time_t value) {
  if (value == -1) {  
    element->SetAttribute(name, "-1");
  } else {
    char value_str[256];
    strftime(value_str, sizeof(value_str), kTimeFormat, localtime(&value));
    element->SetAttribute(name, value_str);
  }
}