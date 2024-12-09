void crab_move(cup* current, cup_finder& finder, int max_label)
{
    auto picked_cups = cut_next_three(current);
    int destination_label = previous_label(current->label, max_label);
    while (is_label_in(picked_cups, destination_label))
        destination_label = previous_label(destination_label, max_label);
    auto destination_cup = finder.cup_by_value[destination_label];
    insert_after(destination_cup, picked_cups);
}