inline bool TestUnit(const Formula*f, uint* begin, const uint* end, State* s, VariableQueue* v, uint var)
{
	uint num_var = f->num_variables;
	uint pos, ai, aw1, aw2;
	int *w1,*w2; //the watched literals
	int* i;
	while(begin != end)
	{
		pos = 2*(*begin);
		w1 = g_watched_lits + pos; //ptr arithm.
		w2 = g_watched_lits + pos + 1;
		aw1 = abs(*w1);
		aw2 = abs(*w2);

		if(s->info[num_var+1+(*begin)] == INACTIVE) //continues if this clause is inactive
		{
			begin++;
			continue;
		}
		if(aw1 != var && aw2 != var)
		{
			g_comp_var = aw1;
			begin++;
			continue;
		}
		// watched literal down, find an undef variable in this clause
		i = &(f->clauses_variables[f->clauses_variables_index[*begin]]);
		while(i < &(f->clauses_variables[f->clauses_variables_index[1+*begin]]))
		{
			ai = abs(*i);
			if(s->info[ai] != Undef)
			{
				// this clause is already satisfied but has not been turned off yet.
				// without this the program could make bad implications
				// if ( (*i > 0 && s->data[*i] == True) || (*i < 0 && s->data[-(*i)] == False) )
				if (((*i) * (s->info[ai]-1)) > 0) //using: True = 2, False = 0
					goto endofwhile;
			}			
			// if(s->data[ai] == Undef && ai != aw1 && ai != aw2)
			else if (ai != aw1 && ai != aw2)
			{
				if(aw1 == var) // the first watched literal was var
					*w1 = *i;
				else			// the second watched literal was var
					*w2 = *i;
				g_comp_var = ai;
				goto endofwhile;
			}
			i++;
		}
		// we could not find a new watched literal -> this clause is unit
		s->info[num_var+1+(*begin)] = INACTIVE;
		s->var_pos_neg_count[0]--; ////////////////////////////////////////////////////////////////////////////////////////////
		if(aw1 != var)
			i = w1;
		else 
			i = w2;
		if(*i>0)
		{
			if(s->info[*i] == False) //contradiction
				return false;
			if(s->info[*i] == Undef)
			{
				v->queue[v->top_index] = *i;
				v->top_index++;
			}
			s->info[*i] = True;
		}
		else
		{
			if(s->info[-(*i)] == True) //contradiction
				return false;
			if(s->info[-(*i)] == Undef)
			{
				v->queue[v->top_index] = -(*i);
				v->top_index++;
			}
			s->info[-(*i)] = False;
		}

endofwhile:
		begin++;
	}
	return true;
}