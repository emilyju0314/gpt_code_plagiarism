std::string vcard::format_tel(std::string tel)
{
  const std::string chars = " ()-\t.";

  tel.erase(std::remove_if(tel.begin(), tel.end(),
                           [&](unsigned char ch) { return chars.find(ch) != std::string::npos; }
              ), tel.end());

  if (tel.rfind("+33", 0) == 0) tel = '0' + tel.substr(3);  // This works only for french numbers

  return tel;
}