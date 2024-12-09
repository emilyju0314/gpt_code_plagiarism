bool Monte_carlo::try_move(double max_step) {

  int random_index = rand() % nr_atoms;
  std::uniform_real_distribution<double> accept_move_dist(0, 1);

  if (!list_cache_set){
  cache_list = atom_list;
  list_cache_set=true;
  }
  
  std::mt19937 rng2;
  double old_energy = total_energy();
  double new_energy = old_energy - energy_from_atom((size_t)random_index);

  std::uniform_real_distribution<double> dist(-(max_step/2), (max_step/2));
  energy_cache_set = false;

  atom_list[random_index].x += dist(rng);
  if (atom_list[random_index].x < 0) atom_list[random_index].x = box_length - atom_list[random_index].x;
  atom_list[random_index].y += dist(rng);
  if (atom_list[random_index].y < 0) atom_list[random_index].y = box_length - atom_list[random_index].y;
  atom_list[random_index].z += dist(rng);
  if (atom_list[random_index].z < 0) atom_list[random_index].z = box_length-atom_list[random_index].z;

  new_energy += energy_from_atom((size_t)random_index);

  if(new_energy <= old_energy) {
    list_cache_set = false;
    energy_cache = new_energy;
    energy_cache_set = true;
    return true;
  }
  else {
    double accept_probability = exp((-new_energy + old_energy)/(boltzmann)); //acceptance probability

    if (accept_move_dist(rng) <= accept_probability) {
      list_cache_set = false;
      energy_cache = new_energy;
      energy_cache_set = true;
      return true;
    }
    else {
      atom_list = cache_list;
      energy_cache = old_energy;
      energy_cache_set = true;
      return false;
    }
  }
}