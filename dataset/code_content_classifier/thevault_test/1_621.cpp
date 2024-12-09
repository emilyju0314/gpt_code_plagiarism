void
sort_p( species_t * sp )
{
  if ( ! sp )
  {
    ERROR( ( "Bad args." ) );
  }

  // Conditionally execute this when more abstractions are available.
  sort_p_pipeline( sp );
}