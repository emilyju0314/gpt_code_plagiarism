inline bool insert(char ch){
        S[slen++] = ch, cur = nextlink(cur);
        int c = ch - 'a', flag = trie[cur][c]; /// Change here if any non-lower case character can occur

        if (!flag){
            len[idx] = len[cur] + 2;
            link[idx] = trie[nextlink(link[cur])][c];
            trie[cur][c] = idx++;
        }

        cur = trie[cur][c];
        counter[cur]++; /// count of palindromic substring cur in the string
        lps = max(lps, len[cur]); /// Update the longest palindromic substring after adding this character
        return !flag;
    }