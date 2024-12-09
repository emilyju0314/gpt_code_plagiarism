void kitfox_proxy_t::add_kitfox_power_component(Comp_ID ComponentID)
{
    /* Check if there already exists the same component ID. */
    for(vector<pair<libKitFox::Comp_ID, libKitFox::counter_t*> >::iterator it =
            kitfox_power_component.begin();
        it != kitfox_power_component.end(); it++) {
        if(it->first == ComponentID) { return; }
    }

    kitfox_power_component.push_back(make_pair(ComponentID, (libKitFox::counter_t*)NULL));
}