int SEARCHER::is_legal_fast(MOVE move) {
    
    int from = m_from(move), to = m_to(move),
                 pic = m_piece(move),
                 cap = m_capture(move),
                 prom = m_promote(move),
                 sq;

    if((from & 0x88) || (to & 0x88) || (from == to))
        return false;
    
    if(pic == blank || pic >= elephant)
        return false;

    if(cap >= elephant)
        return false;

    if(prom >= elephant)
        return false;

    if(player != PCOLOR(pic))
        return false;
    
    if(board[from] != pic)
        return false;
    
    if(cap) {
        if(PIECE(pic) == pawn) {
            if(to != from + pawn_dir[player] + RR &&
                to != from + pawn_dir[player] + LL)
                return false;
        }
        if(is_ep(move)) {
            sq = to - pawn_dir[player];
            if(epsquare == to && board[to] == blank && board[sq] == COMBINE(opponent,pawn)) 
                return true;
        } else {
            if(board[to] == cap) {
                if(PIECE(pic) != pawn) {
                    if(!(sqatt_pieces(to - from) & piece_mask[pic]))
                        return false;
                }
                if(piece_mask[pic] & QRBM) {
                    if(!blocked(from,to))
                        return true;
                }else
                    return true;
            }
        }
    }  else {
        if(board[to] != blank)
            return false;
        if(PIECE(pic) == pawn) {
            if(to == from + pawn_dir[player]) {
                if(board[from + pawn_dir[player]] == blank)
                    return true;
            } else if(to == from + 2 * pawn_dir[player]) {
                if(board[from + pawn_dir[player]] == blank &&
                    board[from + 2 * pawn_dir[player]] == blank)
                    return true;
            } else
                return false;
        } else if(is_castle(move)) {
            if(player == white) {
                if(castle & WSC_FLAG && to == G1 && can_castle(true))
                    return true;
                if(castle & WLC_FLAG && to == C1 && can_castle(false))
                    return true;
            } else if(player == black) {
                if(castle & BSC_FLAG && to == G8 && can_castle(true))
                    return true;
                if(castle & BLC_FLAG && to == C8 && can_castle(false))
                    return true;
            }
        } else {
            if(!(sqatt_pieces(to - from) & piece_mask[pic]))
                return false;
            if(piece_mask[pic] & QRBM) {
                if(!blocked(from,to))
                    return true;
            } else
                return true;
        }
    }
    return false;
}