void variant_deep_load(variant_type& v, iarchive& iarc) {
  int which;
  iarc >> which;
  switch(which) {
   case 0:
     {
       v = flexible_type();
       iarc >> boost::get<flexible_type>(v);
       break;
     }
   case 1:
     {
       std::shared_ptr<unity_sgraph> g(new unity_sgraph());
       iarc >> *g;
       variant_set_value<std::shared_ptr<unity_sgraph>>(v, g);
       break;
     }
   case 2:
     {
       v = dataframe_t();
       iarc >> boost::get<dataframe_t>(v);
       break;
     }
   case 3:
     log_and_throw(std::string("Unable to deseralize unity model pointer"));
     break;
   case 4:
     {
       std::shared_ptr<unity_sframe> s(new unity_sframe());
       iarc >> *s;
       variant_set_value<std::shared_ptr<unity_sframe>>(v, s);
       break;
     }
   case 5:
     {
       std::shared_ptr<unity_sarray> s(new unity_sarray());
       iarc >> *s;
       variant_set_value<std::shared_ptr<unity_sarray>>(v, s);
       break;
     }
   case 6:
     {
       size_t numvals;
       iarc >> numvals;
       variant_map_type varmap;
       for (size_t i = 0;i < numvals; ++i) {
         std::string key;
         variant_type value;
         iarc >> key;
         variant_deep_load(value, iarc);
         varmap[key] = std::move(value);
       }
       variant_set_value<variant_map_type>(v, varmap);
       break; 
     }
   case 7:
     {
       size_t numvals;
       iarc >> numvals;
       variant_vector_type varvec;
       varvec.resize(numvals);
       for (size_t i = 0;i < numvals; ++i) {
         variant_type value;
         variant_deep_load(value, iarc);
         varvec[i] = std::move(value);
       }
       variant_set_value<variant_vector_type>(v, varvec);
       break; 
     }
   default:
     break;
  }
}