Iterator(Generator &generator) noexcept :
			generator_{ &generator },
			value_{} {
		if (generator_->done())
			generator_ = nullptr;
		else
			value_ = generator_->generate();
	}