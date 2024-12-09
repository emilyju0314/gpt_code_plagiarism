int fl_add_symbol(const char *name, void (*drawit)(Fl_Color), int scalable)
{
  fl_init_symbols();
  int pos;
  if (symbnumb > MAXSYMBOL / 2) return 0;	// table is full
  pos = find(name);
  symbols[pos].name = name;
  symbols[pos].drawit = drawit;
  symbols[pos].notempty = 1;
  symbols[pos].scalable = scalable;
  symbnumb++;
  return 1;
}