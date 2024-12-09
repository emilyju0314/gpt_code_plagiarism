static void register_counter_types()
{
     naming::get_agas_client().register_counter_types();
     LBT_(info) << "(2nd stage) pre_main: registered AGAS client-side "
                   "performance counter types";

     get_runtime().register_counter_types();
     LBT_(info) << "(2nd stage) pre_main: registered runtime performance "
                   "counter types";

     threads::get_thread_manager().register_counter_types();
     LBT_(info) << "(2nd stage) pre_main: registered thread-manager performance "
                   "counter types";

     applier::get_applier().get_parcel_handler().register_counter_types();
     LBT_(info) << "(2nd stage) pre_main: registered parcelset performance "
                   "counter types";
}