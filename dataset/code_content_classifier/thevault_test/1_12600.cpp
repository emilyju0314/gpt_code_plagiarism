void kitfox_proxy_t::add_kitfox_thermal_component(Comp_ID ComponentID)
{
    /* Check if there already exists the same component ID. */
    for(vector<Comp_ID>::iterator it = kitfox_thermal_component.begin();
        it != kitfox_thermal_component.end(); it++) {
        if((*it) == ComponentID) { return; }
    }

    kitfox_thermal_component.push_back(ComponentID);
}