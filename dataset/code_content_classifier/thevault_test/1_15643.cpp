price( BaseToken base, QuoteToken quote ) {
      assert( base  >= BaseToken(1ul), "invalid price" );
      assert( quote >= QuoteToken(1ul), "invalid price" );

      base_per_quote = base.quantity;
      base_per_quote *= precision;
      base_per_quote /= quote.quantity;
    }