void read_fasta_names_and_seqs(const std::string& filename,
                               std::vector<std::string>& seqs,
                               std::vector<std::string>& names,
                               std::map<std::string, size_t>& names_to_idxs)
{
  boost::shared_ptr<std::ifstream> ifs = open_or_throw(filename);
  deweylab::bio::formats::fasta::InputStream is(*ifs);
  deweylab::bio::formats::fasta::Record rec;
  size_t idx = 0;
  while (is >> rec) {
    assert(names_to_idxs.count(rec.id) == 0);
    names_to_idxs[rec.id] = idx;
    names.push_back(rec.id);
    seqs.push_back(rec.sequence);
    assert(names[names_to_idxs[rec.id]] == rec.id);
    ++idx;
  }
}