foreach(objects_type::value_type& v, objects)
        {
          GD_FINFO_TRACE("    Scanning %s (%s)",  v.second->__name,
                         typeid(*v.second).name());
          if (typeid(*v.second) == ti && o != v.second)
          {
            GD_FINFO_TRACE("Found parent of %s: %s", o->__name,
                           v.second->__name);
            o->cloner = v.second->cloner;
            return;
          }
        }