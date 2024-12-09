inline bool flex_type_is_convertible(flex_type_enum from, flex_type_enum to) {
  static constexpr bool castable[9][9] =
        // int flt str vec rec dic dtime undef img
/*int*/  {{1,  1,  1,  0,  0,  0,  1,  0,  0},  // integer casts to self, float and string
/*flt*/   {1,  1,  1,  0,  0,  0,  1,  0,  0},  // float casts to integer, self, string
/*str*/   {0,  0,  1,  0,  0,  0,  0,  0,  0},  // string casts to string only
/*vec*/   {0,  0,  1,  1,  1,  0,  0,  0,  0},  // vector casts to string and self and recursive
/*rec*/   {0,  0,  1,  0,  1,  0,  0,  0,  0},  // recursive casts to string and self. 
                                                // technically a cast from rec to vec exists, but it could fail
                                                // and so is not a reliable test for castability
/*dic*/   {0,  0,  1,  0,  0,  1,  0,  0,  0},  // dict casts to self
/*dtime*/ {1,  1,  1,  0,  0,  0,  1,  0,  0},  // dtime casts to string and self
/*undef*/ {0,  0,  1,  0,  0,  0,  0,  1,  0},  //UNDEFINED casts to string and UNDEFINED 
/*img*/   {0,  0,  1,  1,  0,  0,  0,  0,  1}}; // img casts to string, vec, and self.
  return castable[static_cast<int>(from)][static_cast<int>(to)];
}