WERD::WERD(C_BLOB_LIST *blob_list, ///< In word order
           WERD *clone)            ///< Source of flags
    : flags(clone->flags), script_id_(clone->script_id_), correct(clone->correct) {
  C_BLOB_IT start_it = blob_list; // iterator
  C_BLOB_IT end_it = blob_list;   // another

  while (!end_it.at_last()) {
    end_it.forward(); // move to last
  }
  cblobs.assign_to_sublist(&start_it, &end_it);
  // move to our list
  blanks = clone->blanks;
  //      fprintf(stderr,"Wrong constructor!!!!\n");
}