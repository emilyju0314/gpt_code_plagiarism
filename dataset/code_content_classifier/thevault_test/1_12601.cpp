void kitfox_proxy_t::add_kitfox_reliability_component(Comp_ID ComponentID)
{
    /* Check if there already exists the same component ID. */
    for(vector<Comp_ID>::iterator it = kitfox_reliability_component.begin();
        it != kitfox_reliability_component.end(); it++) {
        if((*it) == ComponentID) { return; }
    }

    kitfox_reliability_component.push_back(ComponentID);
}