std::string locateDemoJavaScript()
{
   std::string  paths[3] = {
      "examples/Demo.js",
      "../examples/Demo.js",
      "../../examples/Demo.js"
   };
   
   for (int i = 0; i < 3; ++i)
   {
      std::ifstream file(paths[i].c_str());
      if (file.is_open())
         return paths[i];
   }
   
   return "";
}