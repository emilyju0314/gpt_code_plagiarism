void GenomicsDBMultiDVectorField::run_operation(GenomicsDBMultiDVectorFieldOperator& multid_vector_field_operator,
    const std::vector<const uint8_t*>& data_ptr_vec) const
{
  if(m_field_info_ptr->get_genomicsdb_type().get_num_elements_in_tuple() != data_ptr_vec.size())
    throw GenomicsDBMultiDVectorFieldOperatorException("Data ptr vec and genomicsdb_type do not have the same number of elements");
  auto& length_descriptor = m_field_info_ptr->m_length_descriptor;
  //Stack replacing the recursive function
  std::vector<std::vector<GenomicsDBMultiDVectorIdx>> idx_stack_vec;
  for(auto i=0u;i<data_ptr_vec.size();++i)
    idx_stack_vec.emplace_back(std::vector<GenomicsDBMultiDVectorIdx>(
          1u, GenomicsDBMultiDVectorIdx(data_ptr_vec[i], m_field_info_ptr, 0u)));
  //current index vector e.g. A[5][0][3] will have 5,0,3
  //changes as stack is traversed
  //Don't bother with the last dimension
  std::vector<uint64_t> curr_index_vector(length_descriptor.get_num_dimensions()-1u);
  //Optimization - tracks the outermost dimension index which changed since the
  //last call to operate(). Initialized to N-2
  auto outermost_dim_idx_changed_since_last_call_to_operate = length_descriptor.get_num_dimensions()-2u;
  //Vector to hold pointers and sizes for calling the operator
  std::vector<const uint8_t*> op_ptr_vec(data_ptr_vec.size(), 0);
  std::vector<size_t> op_size_vec(data_ptr_vec.size(), 0u);
  while(!idx_stack_vec[0].empty())
  {
    auto& top_idx = idx_stack_vec[0].back();
    auto curr_dim_idx_in_curr_index_vector = top_idx.get_current_dim_index();
    assert(static_cast<size_t>(curr_dim_idx_in_curr_index_vector) < curr_index_vector.size());
    curr_index_vector[curr_dim_idx_in_curr_index_vector++] = top_idx.get_current_index_in_current_dimension();
    //At the end of this block, the stack must look like the following:
    //[  [top+1], [top][0] ]
    //This ensures that subsequent iterations expand on lower dimensions starting with [top][0]
    //first followed by [top+1]
    auto is_top_idx_valid = (top_idx.get_current_index_in_current_dimension()
        < top_idx.get_num_entries_in_current_dimension());
    if(is_top_idx_valid)
    {
      //First index in the next dimension is added to the top of the stack
      //Why +2u? dimension N-2 corresponds to a pointer to a contiguous segment of values
      if(top_idx.get_current_dim_index()+2u < length_descriptor.get_num_dimensions())
      {
        for(auto i=0u;i<data_ptr_vec.size();++i)
        {
          auto& curr_tuple_element_top_idx = idx_stack_vec[i].back();
          auto copy_idx = curr_tuple_element_top_idx; //copy
          assert(copy_idx.get_current_index_in_current_dimension()
              < copy_idx.get_num_entries_in_current_dimension()
              && copy_idx.get_current_dim_index()+2u
              < length_descriptor.get_num_dimensions());
          //index 0 in the next dimension
          copy_idx.advance_to_index_in_next_dimension(0u);
          //Cannot move this to outside the if-else block because idx_stack memory can be reallocated
          //by the emplace_back() statement
          curr_tuple_element_top_idx.advance_index_in_current_dimension();
          idx_stack_vec[i].emplace_back(copy_idx);
        }
      }
      else
      {
        for(auto i=0u;i<data_ptr_vec.size();++i)
        {
          auto& curr_tuple_element_top_idx = idx_stack_vec[i].back();
          assert(curr_tuple_element_top_idx.get_current_dim_index()+2u
              >= length_descriptor.get_num_dimensions());
          op_ptr_vec[i] = curr_tuple_element_top_idx.get_ptr<uint8_t>();
          op_size_vec[i] = curr_tuple_element_top_idx.get_size_of_current_index();
        }
        multid_vector_field_operator.operate(op_ptr_vec,
            op_size_vec, curr_index_vector,
            outermost_dim_idx_changed_since_last_call_to_operate);
        //reset outermost_dim_idx_changed_since_last_call_to_operate 
        outermost_dim_idx_changed_since_last_call_to_operate = length_descriptor.get_num_dimensions()-2u; 
        //Cannot move this to outside the if-else block because idx_stack memory can be reallocated (if block)
        for(auto i=0u;i<data_ptr_vec.size();++i)
          idx_stack_vec[i].back().advance_index_in_current_dimension();
      }
      //DO NOT USE top_idx in this if block after this - emplace_back() might have reallocated the vector
    }
    else
    {
      for(auto i=0u;i<idx_stack_vec.size();++i)
        idx_stack_vec[i].pop_back();
      --outermost_dim_idx_changed_since_last_call_to_operate;
    }
  }
}