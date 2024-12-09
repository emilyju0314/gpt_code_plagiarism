void speq::fm::generate_fm_index(
    speq::args::cmd_arguments & args,
    const std::filesystem::file_time_type & scaffold_file_time,
    const std::filesystem::file_time_type & group_file_time,
    const std::vector<std::string> & group_names,
    const std::vector<int> & group_scaffolds,
    const std::vector<int> & group_counts
)
{
    //################ Input the references for indexing ################
    // Pull all sequences from the reference lazily
    seqan3::sequence_file_input ref_recs{args.in_file_references};
    auto ref_seqs = ref_recs | std::views::transform([] (auto s) 
    { 
        return seqan3::get<seqan3::field::seq>(s);
    });
    // Get both the forward and reverse complements in the index file
    auto fnr_ref_seqs = ranges::view::for_each(ref_seqs,[](auto c) 
    {
        return ranges::yield_from(ranges::views::repeat_n(c,2));
    }) | ranges::to<std::vector>();

    for(auto it = std::begin(fnr_ref_seqs); it < std::end(fnr_ref_seqs); ++it)
    {
        *(++it) = seqan3::views::complement(std::views::reverse(*it)) | ranges::to<std::vector>();
    }
    //################ Indexing ##################
    // Generate the fm_index against the sequences
    seqan3::fm_index index{fnr_ref_seqs};
    
    // Output the index for scanning later
    {
        args.io_file_index.replace_extension(".idx");
        std::ofstream os{args.io_file_index, std::ios::binary};
        cereal::BinaryOutputArchive oarchive{os};
        oarchive(args.in_file_references.string());
        oarchive(scaffold_file_time);
        oarchive(group_file_time);
        oarchive(group_names);
        oarchive(group_scaffolds);
        oarchive(group_counts);
        oarchive(index);
    }
    return;
}