implicit_paragraph_action(
            collector& out,
            collector& phrase,
            std::string const& pre,
            std::string const& post,
            quickbook::actions& actions)
        : out(out)
        , phrase(phrase)
        , pre(pre)
        , post(post)
        , actions(actions) {}