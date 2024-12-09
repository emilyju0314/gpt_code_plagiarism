inline void TurnOffClauses(const Formula* f, uint* begin, uint* end, State* s, VariableQueue* v)
{
	uint vars = f->num_variables;
	int *a, *b;
	uint *c;
	while(begin != end)
	{
		if (s->info[1+vars+(*begin)] == INACTIVE)// is the clause active? is watched literal 1 nonzero?
		{
			begin++;
			continue; 
		}
		s->var_pos_neg_count[0]--;
		s->info[1+vars+(*begin)] = INACTIVE; //deactivate clause
		// a, b : pointers to the literals
		a = f->clauses_variables + f->clauses_variables_index[*begin];
		b = f->clauses_variables + f->clauses_variables_index[*begin +1];
		while(a != b)
		{
			if(s->info[abs(*a)] == Undef)
			{
				if(*a > 0)
				{
					c = &(s->var_pos_neg_count[*a]);
					(*c)--;
					if(*c == 0) // no more positive occurences
					{
						s->info[*a] = False;
						v->queue[v->top_index] = *a;
						v->top_index++;
					}
				}
				else
				{
					c = &(s->var_pos_neg_count[vars-*a]); //[vars + abs(a)]
					(*c)--;
					if(*c == 0) // no more negative occurences
					{
						s->info[-*a] = True;
						v->queue[v->top_index] = -(*a);
						v->top_index++;
					}
				}
			}
			a++;
		}
		begin++;
	}
}