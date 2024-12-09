std::size_t resource_manager::reserve_at_higher_use_count(
            std::size_t desired,
            std::vector<punit_status>& available_punits)
    {
        std::size_t use_count = 1;
        std::size_t available = 0;

        while (available < desired)
        {
            available += reserve_processing_units(
                    use_count++, desired - available, available_punits);
        }

        return available;
    }