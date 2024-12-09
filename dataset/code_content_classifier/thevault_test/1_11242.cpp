bool consumes_inputs_at_same_rates(const query_operator_attributes& attributes) {
  return (attributes.num_inputs == 1
          || (attributes.attribute_bitfield & query_operator_attributes::LINEAR)
          || (attributes.attribute_bitfield & query_operator_attributes::SUB_LINEAR));
}