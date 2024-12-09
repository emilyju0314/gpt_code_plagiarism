Analytic_MultigroupOpacity::Analytic_MultigroupOpacity(const sf_char &packed)
    : group_boundaries(), reaction(), model() {
  // the packed size must be at least 4 integers (number of groups, reaction
  // type, model type, analytic model indicator)
  Require(packed.size() >= 4 * sizeof(int));

  // make an unpacker
  rtt_dsxx::Unpacker unpacker;

  // register the unpacker
  unpacker.set_buffer(packed.size(), &packed[0]);

  // unpack the number of group boundaries
  int ngrp_bounds = 0;
  unpacker >> ngrp_bounds;

  // make the group boundaries and model vectors
  group_boundaries.resize(ngrp_bounds);

  // unpack the group boundaries
  for (int i = 0; i < ngrp_bounds; i++)
    unpacker >> group_boundaries[i];

  // unpack the reaction and model type
  int reaction_int, model_int;
  unpacker >> reaction_int >> model_int;

  // assign the reaction and model type
  reaction = static_cast<rtt_cdi::Reaction>(reaction_int);
  model = static_cast<rtt_cdi::Model>(model_int);
  Check(reaction == rtt_cdi::ABSORPTION || reaction == rtt_cdi::SCATTERING ||
        reaction == rtt_cdi::TOTAL);
}