static void position_outline( // put in place
    C_OUTLINE *outline,       // thing to place
    C_OUTLINE_LIST *destlist  // desstination list
) {
  C_OUTLINE_IT it = destlist; // iterator
                              // iterator on children
  C_OUTLINE_IT child_it = outline->child();

  if (!it.empty()) {
    do {
      // outline from dest list
      C_OUTLINE *dest_outline = it.data(); // get destination
                                // encloses dest
      if (*dest_outline < *outline) {
        // take off list
        dest_outline = it.extract();
        // put this in place
        it.add_after_then_move(outline);
        // make it a child
        child_it.add_to_end(dest_outline);
        while (!it.at_last()) {
          it.forward(); // do rest of list
                        // check for other children
          dest_outline = it.data();
          if (*dest_outline < *outline) {
            // take off list
            dest_outline = it.extract();
            child_it.add_to_end(dest_outline);
            // make it a child
            if (it.empty()) {
              break;
            }
          }
        }
        return; // finished
      }
      // enclosed by dest
      else if (*outline < *dest_outline) {
        position_outline(outline, dest_outline->child());
        // place in child list
        return; // finished
      }
      it.forward();
    } while (!it.at_first());
  }
  it.add_to_end(outline); // at outer level
}