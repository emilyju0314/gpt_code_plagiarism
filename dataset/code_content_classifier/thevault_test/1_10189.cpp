void hasp_set_anti_burn(int32_t repeat_count, uint32_t period)
{
    lv_obj_t* layer = lv_disp_get_layer_sys(NULL);
    if(!layer) return;

    if(repeat_count != 0) {
        anti_burnin_task = lv_task_create(hasp_anti_burnin_cb, period, LV_TASK_PRIO_LOWEST, NULL);
        if(anti_burnin_task) {
            // hasp_set_wakeup_touch(true);
            lv_obj_set_event_cb(layer, first_touch_event_handler);
            lv_obj_set_click(layer, true);
            lv_task_set_repeat_count(anti_burnin_task, repeat_count);
            LOG_INFO(TAG_HASP, F("Antiburn %s"), D_SETTING_ENABLED);
        } else {
            LOG_INFO(TAG_HASP, F("Antiburn %s"), D_INFO_FAILED);
        }
    } else {
        if(anti_burnin_task) {
            lv_task_del(anti_burnin_task);
            hasp_stop_anti_burn(layer);
        }
    }
}