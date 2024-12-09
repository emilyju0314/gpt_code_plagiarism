void CCalcDlg::calc_binary()
{
	if (op_ == binop_none) return;  // Handles case where state_ > CALCINTEXPR without changing state_

	CWaitCursor wc;   // show an hourglass just in case it takes a long time

	ASSERT(state_ != CALCERROR && state_ <= CALCINTEXPR);
	current_ = get_norm(current_);

	state_ = CALCINTRES;  // default to integer result - may be overridden due to error/overflow or for CALCINTBINARY
	switch (op_)
	{
	case binop_add:
		current_ += previous_;
		break;
	case binop_subtract:
		current_ = previous_ - current_;
		break;
	case binop_multiply:
		current_ *= previous_;
		break;
	case binop_divide:
		if (current_ == 0)
		{
			current_str_ = "Divide by zero";
			state_ = CALCERROR;
		}
		else
			current_ = previous_ / current_;
		break;
	case binop_mod:
		if (current_ == 0)
		{
			current_str_ = "Divide (modulus) by zero";
			state_ = CALCERROR;
		}
		else
			current_ = previous_ % current_;
		break;
	case binop_pow:
		if (current_ > mpz_class(ULONG_MAX))
		{
			current_ = 0;
			state_ = CALCOVERFLOW;
		}
		else
			mpz_pow_ui(current_.get_mpz_t(), previous_.get_mpz_t(), current_.get_si());
		break;
	case binop_gtr:
	case binop_gtr_old:
		if (current_ < previous_)
			current_ = previous_;
		break;
	case binop_less:
	case binop_less_old:
		if (current_ > previous_)
			current_ = previous_;
		break;
	case binop_rol:
		if (bits_ == 0)
		{
			current_str_ = "Can't rotate right if bit count is unlimited";
			state_ = CALCERROR;
		}
		else
		{
			mpz_class t1, t2;
			current_ %= bits_;
			mpz_mul_2exp(t1.get_mpz_t(), previous_.get_mpz_t(), current_.get_ui());
			mpz_fdiv_q_2exp(t2.get_mpz_t(), previous_.get_mpz_t(), bits_ - current_.get_ui());
			current_ = (t1 | t2) & mask_;
		}
		break;
	case binop_ror:
		if (bits_ == 0)
		{
			current_str_ = "Can't rotate left if bit count is unlimited";
			state_ = CALCERROR;
		}
		else
		{
			mpz_class t1, t2;
			current_ %= bits_;
			mpz_fdiv_q_2exp(t1.get_mpz_t(), previous_.get_mpz_t(), current_.get_ui());
			mpz_mul_2exp(t2.get_mpz_t(), previous_.get_mpz_t(), bits_ - current_.get_ui());
			current_ = (t1 | t2) & mask_;
		}
		break;
	case binop_lsl:
		mpz_mul_2exp(current_.get_mpz_t(), previous_.get_mpz_t(), current_.get_ui());
		break;
	case binop_lsr:
		mpz_fdiv_q_2exp(current_.get_mpz_t(), previous_.get_mpz_t(), current_.get_ui());
		break;
	case binop_asr:
		if (bits_ == 0)
			mpz_fdiv_q_2exp(current_.get_mpz_t(), previous_.get_mpz_t(), current_.get_ui());
		else
		{
			int shift = current_.get_si();
			int neg = mpz_tstbit(previous_.get_mpz_t(), bits_-1);
			if (shift > bits_)
			{
				// All bits shifted out
				if (neg)
					current_ = -1 & mask_;
				else
					current_ = 0;
			}
			else
			{
				current_ = previous_;
				for (int ii = 0; ii < shift; ++ii)
				{
					current_ >>= 1;
					if (neg) mpz_setbit(current_.get_mpz_t(), bits_-1);  // propagate high bit
				}
			}
		}
		break;

	case binop_and:
		current_ &= previous_;
		break;
	case binop_or:
		current_ |= previous_;
		break;
	case binop_xor:
		current_ ^= previous_;
		break;

	default:
		ASSERT(0);
		break;
	}
	right_ = get_expr(false);  // we need parentheses in case there are further operations

	op_ = binop_none;
	previous_unary_op_ = unary_none;
}