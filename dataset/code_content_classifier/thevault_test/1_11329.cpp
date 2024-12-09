void variant_deep_save(const variant_type& v, oarchive& oarc) {
  oarc << v.which();
  switch(v.which()) {
   case 0:
     oarc << boost::get<flexible_type>(v);
     break;
   case 1:
     {
       std::shared_ptr<unity_sgraph> g = 
           std::static_pointer_cast<unity_sgraph>(variant_get_ref<std::shared_ptr<unity_sgraph_base>>(v));
       oarc << *g;
       break;
     }
   case 2:
     oarc << boost::get<dataframe_t>(v);
     break;
   case 3:
     log_and_throw(std::string("Unable to serialize unity model pointer"));
     break;
   case 4:
     {
       std::shared_ptr<unity_sframe> s = 
           std::static_pointer_cast<unity_sframe>(variant_get_ref<std::shared_ptr<unity_sframe_base>>(v));
       oarc << *s;
       break;
     }
     break;
   case 5:
     {
       std::shared_ptr<unity_sarray> s = 
           std::static_pointer_cast<unity_sarray>(variant_get_ref<std::shared_ptr<unity_sarray_base>>(v));
       oarc << *s;
       break;
     }
     break;
   case 6:
     {
       const variant_map_type& varmap = variant_get_ref<variant_map_type>(v);
       oarc << (size_t)varmap.size();
       for(const auto& elem : varmap) {
         oarc << elem.first;
         variant_deep_save(elem.second, oarc);
       }
       break; 
     }
   case 7:
     {
       const variant_vector_type& varvec = variant_get_ref<variant_vector_type>(v);
       oarc << (size_t)varvec.size();
       for(const auto& elem : varvec) {
         variant_deep_save(elem, oarc);
       }
       break; 
     }
   default:
     break;
  };
}