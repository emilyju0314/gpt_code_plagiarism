int SEARCHER::checks(MOVE move,int& rev_check) const {
    int from = m_from(move),to = m_to(move),sq,step,mvstep;
    int pic = board[from];
    int ksq = plist[COMBINE(opponent,king)]->sq;
    int special,check = 0;
    
    rev_check = 0;
    
    if(m_promote(move))
        pic = m_promote(move);
    
    /*direct check*/
    if (pic == COMBINE(player,pawn)) {
        if(ksq - to == (pawn_dir[player] + RR) || ksq - to == (pawn_dir[player] + LL))
            check = 1;
    } else if(sqatt_pieces(ksq - to) & piece_mask[pic]) {
        if (pic == COMBINE(player,king) || pic == COMBINE(player,knight))
            check = 1;
        else {
            special = (m_promote(move) && (sqatt_step(to - from) == sqatt_step(to - ksq)));
            if(special) {
                if(blocked(ksq,from) == 0)
                    check = 1;
            } else {
                if(blocked(ksq,to) == 0)
                    check = 1;
            }
        }
    }
    /*revealed check*/
    step = sqatt_step(from - ksq);
    mvstep = sqatt_step(to - from);
    if(step && ABS(step) != ABS(mvstep)) {
        if(blocked(ksq,from) == 0) {
            sq = from + step;
            while(board[sq] == blank) sq += step;
            if(!(sq & 0x88)) {
                if(PCOLOR(board[sq]) == player 
                    && (sqatt_pieces(sq - ksq) & piece_mask[board[sq]])) {
                    check += 2;
                    rev_check = sq;
                }
            }
        }
    }
    
    /*castling*/
    if(is_castle(move)) {
        int cast = ((to == SQ(rank(from), FILEG)) ? (to + LL):(to + RR));
        if(sqatt_pieces(cast - ksq) & piece_mask[COMBINE(player,rook)]) {
            special = (rank(cast) == rank(ksq));
            if(special) {
                if(!blocked(from,ksq)) {
                    check += 2;
                    rev_check = cast;
                }
            }else{
                if(!blocked(cast,ksq)) {
                    check += 2;
                    rev_check = cast;
                }
            }
        }
    /*enpassant*/
    } else if(is_ep(move)) {
        int epsq = to + ((to > from) ? DD:UU);
        step = sqatt_step(epsq - ksq);
        if(step && ABS(step) != UU) {
            int nsq,fsq;
            if(ABS(step) == RR){
                if(distance(from,ksq) < distance(epsq,ksq)) {
                    nsq = from;
                    fsq = epsq;
                } else {
                    nsq = epsq;
                    fsq = from;
                }
            } else {
                nsq = epsq;
                fsq = epsq;
            }
            if(!blocked(nsq,ksq)){
                sq = fsq + step;
                while(board[sq] == blank) {sq += step;}
                if(!(sq & 0x88)) {
                    if(PCOLOR(board[sq]) == player 
                        && (sqatt_pieces(sq - ksq) & piece_mask[board[sq]])) {
                        check += 2;
                        rev_check = sq;
                    }
                }
            }
        }
    }
    
    return check;
}