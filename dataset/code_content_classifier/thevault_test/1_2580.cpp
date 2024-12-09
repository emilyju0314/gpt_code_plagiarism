void
CChangeSetProcessor::process()
{
	// Load whole source file into memory for further operation,
	// suppose files just opened and we do not need to rewind pointer

	CHashedString str;

	while (readString(mFile1, str))
	{
		mData.push_back(str);
	}

	// OK, first line of changeset must be [BEGIN]

	THROW_IF_WINFO(readCommandPart() != kBegin, XBadDiff, "No [BEGIN] at file start");

	short cmd = readCommandPart();

	for (;;)
	{
		size_t pos;

		switch (cmd)
		{
		case kEnd:

			// This is the end, my only friend -- the end

			outputResult();
			return;

		case kInsert:

			cmd = readCommandPart(&mWhat);
			THROW_IF_NOT_WINFO(cmd == kBetween, XBadDiff, "[BETWEEN] expected");

			cmd = readCommandPart(&mBefore);
			THROW_IF_NOT_WINFO(cmd == kAnd, XBadDiff, "[AND] expected");

			// Command stored for next iteration

			cmd = readCommandPart(&mAfter);

			// Fill pattern

			mPattern.clear();

			addPattern(mBefore);
			addPattern(mAfter);

			pos = checkPattern();

			// Update output file content

			insertContext(pos + mBefore.size(), mWhat);

			break;

		case kDelete:

			cmd = readCommandPart(&mWhat);
			THROW_IF_NOT_WINFO(cmd == kBetween, XBadDiff, "[BETWEEN] expected");

			cmd = readCommandPart(&mBefore);
			THROW_IF_NOT_WINFO(cmd == kAnd, XBadDiff, "[AND] expected");

			// Command stored for next iteration

			cmd = readCommandPart(&mAfter);

			// Fill pattern

			mPattern.clear();

			addPattern(mBefore);
			addPattern(mWhat);
			addPattern(mAfter);

			pos = checkPattern();

			// Update output file content

			deleteContext(pos + mBefore.size(), mWhat.size());

			break;

		case kReplace:

			cmd = readCommandPart(&mWhat);
			THROW_IF_NOT_WINFO(cmd == kWith, XBadDiff, "[WITH] expected");

			// Command stored for next iteration

			cmd = readCommandPart(&mBefore);

			// Fill pattern

			mPattern.clear();

			addPattern(mWhat);

			pos = checkPattern();

			// Update output file content
			// mBefore keeps 'WITH' part

			deleteContext(pos, mWhat.size());
			insertContext(pos, mBefore);

			break;
		}
	}
}