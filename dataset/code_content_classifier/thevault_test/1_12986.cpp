void Main_api::init() {
  for (const auto &it : Pass_plugin::get_registry()) {
    // fmt::print("function:{}\n", it.first);
    it.second();
  }

  //setup_inou_liveparse();
  setup_inou_pyrope();
  setup_inou_yosys();
  //setup_pass_fplan();
  //setup_pass_lnast_tolg();
  //setup_inou_json();
  /* setup_inou_verific(); */
  /* setup_cops_live(); */

  // FIXME beyond this point (to delete some of them)

  Top_api::setup(Pass::eprp);  // *

  Meta_api::setup(Pass::eprp);   // lgraph.*
  Cloud_api::setup(Pass::eprp);  // cloud.*

  main_path = Eprp_utils::get_exe_path();
}