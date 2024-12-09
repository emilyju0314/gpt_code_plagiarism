rObject
    uobject_new(rObject proto, bool forceName, bool instanciate, const std::string& fname)
    {
      rObject res = new object::Finalizable(proto->as<object::Finalizable>());

      // Get UObject name.
      rObject rcName = proto->slot_get_value(SYMBOL(__uobject_cname));
      const std::string& cname = rcName.cast<object::String>()->value_get();

      // Get the name we will pass to uobject.
      std::string name;
      if (forceName)
      {
        res->slot_set_value(SYMBOL(type), rcName);
        name = cname;
        where->slot_set_value(libport::Symbol(name), res);
      }
      else if (!fname.empty())
        name = fname;
      else
      {
        // boost::lexical_cast does not work on the way back, so dont
        // use it here.
        std::stringstream ss;
        ss << "uob_" << res.get();
        name = ss.str();
      }
      res->slot_set_value(SYMBOL(__uobjectName), object::to_urbi(name));
      {
        libport::BlockLock bl(object_links_lock);
        ObjectLinks::iterator i = object_links.find(name);
        if (i == object_links.end())
        {
          GD_FINFO_TRACE("pushing %s %s", name, res);
          object_links[name] = urbi::impl::Link(res.get(), false, 0);
          assert(get_base(name));
        }
        else
          i->second.set(res, false);
      }
      res->call(SYMBOL(uobjectInit));
      // Instanciate UObject.
      if (instanciate)
      {
        foreach (urbi::baseURBIStarter* i, urbi::baseURBIStarter::list())
        {
          if (i->name == cname)
          {
            bound_context.push_back(std::make_pair(name, name + ".new"));
            FINALLY(((std::string, name)), bound_context.pop_back());
            i->instanciate(urbi::impl::KernelUContextImpl::instance(),
                           forceName?name:("getUObject." + name));
            return res;
          }
        }
      }
      return res;
    }