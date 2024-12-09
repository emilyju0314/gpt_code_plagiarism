void WritableCatalog::UpdateCounters() {
  SqlUpdateCounter sql_counter(database());
  bool retval;

  if (delta_counters_.d_self_regular != 0) {
    retval =
      sql_counter.BindCounter("self_regular") &&
      sql_counter.BindDelta(delta_counters_.d_self_regular) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_self_symlink != 0) {
    retval =
      sql_counter.BindCounter("self_symlink") &&
      sql_counter.BindDelta(delta_counters_.d_self_symlink) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_self_dir != 0) {
    retval =
      sql_counter.BindCounter("self_dir") &&
      sql_counter.BindDelta(delta_counters_.d_self_dir) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_self_nested != 0) {
    retval =
      sql_counter.BindCounter("self_nested") &&
      sql_counter.BindDelta(delta_counters_.d_self_nested) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_subtree_regular != 0) {
    retval =
      sql_counter.BindCounter("subtree_regular") &&
      sql_counter.BindDelta(delta_counters_.d_subtree_regular) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_subtree_symlink != 0) {
    retval =
      sql_counter.BindCounter("subtree_symlink") &&
      sql_counter.BindDelta(delta_counters_.d_subtree_symlink) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_subtree_dir != 0) {
    retval =
      sql_counter.BindCounter("subtree_dir") &&
      sql_counter.BindDelta(delta_counters_.d_subtree_dir) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }

  if (delta_counters_.d_subtree_nested != 0) {
    retval =
      sql_counter.BindCounter("subtree_nested") &&
      sql_counter.BindDelta(delta_counters_.d_subtree_nested) &&
      sql_counter.Execute();
    assert(retval);
    sql_counter.Reset();
  }
}