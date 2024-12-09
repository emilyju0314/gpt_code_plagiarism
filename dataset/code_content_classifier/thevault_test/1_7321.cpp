int glutStrokeWidth( void* fontID, int character )
{
  const Fl_Glut_StrokeChar *schar;
  Fl_Glut_StrokeFont* font = (Fl_Glut_StrokeFont *)fontID;
  if (character < 0 || character >= font->Quantity) return 0;
  schar = font->Characters[ character ];

  return schar ? (int)(schar->Right + 0.5) : 0;
}