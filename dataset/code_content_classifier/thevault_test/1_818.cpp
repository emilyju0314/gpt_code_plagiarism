bool find_policies(Tcl_Interp *interp, std::string const &cmdName,
     policies_interp_map::iterator &piti)
{
     policies_map::iterator pit = call_policies.find(interp);
     if (pit == call_policies.end())
     {
          return false;
     }
     
     piti = pit->second.find(cmdName);
     return piti != pit->second.end();
}