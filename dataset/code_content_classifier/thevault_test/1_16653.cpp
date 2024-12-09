static void insufficient_parameters(boost::string_ref directive, const LoadingContext& context)
    {
      DEBUG_RELEVANT << "Warning: insufficient parameters to '" << directive <<
        "' directive in " << context.file_name << " on line " << context.line_index << "." << debug::endl;
    }