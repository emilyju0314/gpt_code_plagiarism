void Session::begin()
{
  Reply r(sql(L"START TRANSACTION", NULL));
  r.wait();
  if (r.entry_count() > 0)
    r.get_error().rethrow();
}