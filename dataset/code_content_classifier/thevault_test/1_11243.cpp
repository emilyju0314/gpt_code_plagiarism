bool is_sublinear_transform(const query_operator_attributes& attributes) {
  return (consumes_inputs_at_same_rates(attributes)
          && !is_source_node(attributes)
          && (attributes.attribute_bitfield & query_operator_attributes::SUB_LINEAR));
}