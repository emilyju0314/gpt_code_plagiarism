void CTrace::kflush()
{
   buffer << ss.rdbuf() << flush;
   ss.str("");
}