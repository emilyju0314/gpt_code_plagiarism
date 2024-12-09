TEST(LogUploader, parse_logs_with_counter) {
  struct log_parse_params* params = create_log_parse_params(test_log_data,
      test_log_data_size);
  struct parser_progress* progress =
    (struct parser_progress*) params->user_data;

  params->last_log_counter = 103LL;
  char* res_buffer = parse_and_consume_log_data(params);

  // Make sure it actually read in the whole thing.
  EXPECT_EQ(2, progress->eos_count);
  EXPECT_EQ(progress->num_entries, progress->curr_entry);

  EXPECT_EQ(107LL, params->last_log_counter);
  EXPECT_EQ(1, params->last_line_valid);
  EXPECT_STREQ(new_marker_logged_str, params->line_buffer);

  verify_dev_kmsg_writes();

  // It should have skipped the first 4 entries, but wrote out the rest
  verify_log_data(test_log_data, res_buffer, params->total_read, 4, 4);

  free_log_parse_params(params);
}