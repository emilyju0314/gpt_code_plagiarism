String *Swig_method_decl(SwigType *rettype, SwigType *decl, const_String_or_char_ptr id, List *args, int strip, int values) {
  String *result;
  List *elements;
  String *element = 0, *nextelement;
  int is_const = 0;
  int nelements, i;
  int is_func = 0;
  int arg_idx = 0;

  if (id) {
    result = NewString(Char(id));
  } else {
    result = NewString("");
  }

  elements = SwigType_split(decl);
  nelements = Len(elements);
  if (nelements > 0) {
    element = Getitem(elements, 0);
  }
  for (i = 0; i < nelements; i++) {
    if (i < (nelements - 1)) {
      nextelement = Getitem(elements, i + 1);
    } else {
      nextelement = 0;
    }
    if (SwigType_isqualifier(element)) {
      int skip = 0;
      DOH *q = 0;
      if (!strip) {
	q = SwigType_parm(element);
	if (!Cmp(q, "const")) {
	  is_const = 1;
	  is_func = SwigType_isfunction(nextelement);
	  if (is_func)
	    skip = 1;
	  skip = 1;
	}
	if (!skip) {
	  Insert(result, 0, " ");
	  Insert(result, 0, q);
	}
	Delete(q);
      }
    } else if (SwigType_isfunction(element)) {
      Parm *parm;
      String *p;
      Append(result, "(");
      parm = args;
      while (parm != 0) {
	String *type = Getattr(parm, "type");
	String *name = Getattr(parm, "name");
	if (!name && Cmp(type, "void")) {
	  name = NewString("");
	  Printf(name, "arg%d", arg_idx++);
	  Setattr(parm, "name", name);
	}
	if (!name) {
	  name = NewString("");
	}
	p = SwigType_str(type, name);
	Append(result, p);
	String *value = Getattr(parm, "value");
	if (values && (value != 0)) {
	  Printf(result, " = %s", value);
	}
	parm = nextSibling(parm);
	if (parm != 0)
	  Append(result, ", ");
      }
      Append(result, ")");
    } else if (rettype) { // This check is intended for conversion operators to a pointer/reference which needs the pointer/reference ignoring in the declaration
      if (SwigType_ispointer(element)) {
	Insert(result, 0, "*");
	if ((nextelement) && ((SwigType_isfunction(nextelement) || (SwigType_isarray(nextelement))))) {
	  Insert(result, 0, "(");
	  Append(result, ")");
	}
      } else if (SwigType_ismemberpointer(element)) {
	String *q;
	q = SwigType_parm(element);
	Insert(result, 0, "::*");
	Insert(result, 0, q);
	if ((nextelement) && ((SwigType_isfunction(nextelement) || (SwigType_isarray(nextelement))))) {
	  Insert(result, 0, "(");
	  Append(result, ")");
	}
	Delete(q);
      } else if (SwigType_isreference(element)) {
	Insert(result, 0, "&");
      } else if (SwigType_isarray(element)) {
	DOH *size;
	Append(result, "[");
	size = SwigType_parm(element);
	Append(result, size);
	Append(result, "]");
	Delete(size);
      } else {
	if (Strcmp(element, "v(...)") == 0) {
	  Insert(result, 0, "...");
	} else {
	  String *bs = SwigType_namestr(element);
	  Insert(result, 0, " ");
	  Insert(result, 0, bs);
	  Delete(bs);
	}
      }
    }
    element = nextelement;
  }

  Delete(elements);

  if (is_const) {
    if (is_func) {
      Append(result, " ");
      Append(result, "const");
    } else {
      Insert(result, 0, "const ");
    }
  }

  Chop(result);

  if (rettype) {
    Insert(result, 0, " ");
    String *rtype = SwigType_str(rettype, 0);
    Insert(result, 0, rtype);
    Delete(rtype);
  }

  return result;
}