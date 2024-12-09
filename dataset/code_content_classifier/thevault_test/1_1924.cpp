void trace::X86TraceGenerator::writeInstToFile(ofstream &file, Inst_info *inst_info)
{
  file << "*** begin of the data strcture *** " <<endl;

  WRITE_INST_TO_FILE(file, inst_info);

  file << "*** end of the data strcture *** " << endl << endl;
}