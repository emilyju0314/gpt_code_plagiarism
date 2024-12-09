static void skip_until_end(LoadingContext& context)
    {
      const auto& lines = *context.lines;
      auto& line_index = context.line_index;

      for (std::string directive; line_index < lines.size() && directive != "end"; ++context.line_index)
      {
        boost::string_ref line = lines[line_index];
        boost::string_ref directive_view = extract_word(line);

        // Minor optimization: read 4 characters at most
        directive.assign(directive_view.begin(), std::min<std::size_t>(directive_view.size(), 4));

        primitive_tolower(directive);
      }
    }