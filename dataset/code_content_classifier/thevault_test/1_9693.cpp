void Tool_chantize::outputFile(HumdrumFile& infile) {
	vector<bool> terminalRest = getTerminalRestStates(infile);
	HTp token;
	bool restQ = false;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (infile[i].isInterpretation()) {
			token = infile.token(i, 0);
			if (token->isTimeSignature()) {
				// suppress time signatures
				continue;
			}
		} else if (infile[i].isCommentGlobal()) {
			// Convert line breaks into invisible barlines.
			token = infile.token(i, 0);
			if (token->find("original") != string::npos) {
				int cols = 2;
				for (int j=0; j<cols; j++) {
					m_humdrum_text << "=-";
					if (j < cols - 1) {
						m_humdrum_text << "\t";
					}
				}
				m_humdrum_text << "\n";
				continue;
			}
		} else if (infile[i].isBarline()) {
			// suppress barlines
			token = infile.token(i, 0);
			// but do not suppress double barlines
			if (token->find("||") == string::npos) {
				continue;
			}
		} else if (infile[i].isData()) {
			token = infile.token(i, 0);
			if (token->isRest()) {
				if (terminalRest[i]) {
					continue;
				}
				if (!restQ) {
					restQ = true;
					// convert rest into double barline
					// but suppress rests at end of music
					//or just suppress
					// for (int j=0; j<infile[i].getFieldCount(); j++) {
					// 	m_humdrum_text  << "=-";
					// 	if (j < infile[i].getFieldCount() - 1) {
					// 		m_humdrum_text << "\t";
					// 	}
					// }
					// m_humdrum_text << "\n";
				} 
				continue;
			} else {
				restQ = false;
			}
		}
		m_humdrum_text << infile[i] << "\n";
	}
	if (m_diamondQ) {
		m_humdrum_text << "!!!RDF**kern: j = diamond note, color=blue\n";
	}
	m_humdrum_text << "!!!RDF**kern: {} = ligature\n";
}