Long spqrDebug_rhsize       // returns # of entries in R+H
(
    // input, not modified
    Long m,                 // # of rows in F
    Long n,                 // # of columns in F
    Long npiv,              // number of pivotal columns in F
    Long *Stair,            // size n; column j is dead if Stair [j] == 0.
                            // Only the first npiv columns can be dead.
    cholmod_common *cc
)
{
    Long k, h, t, rm, rhsize = 0 ;

    ASSERT (m >= 0 && n >= 0 && npiv <= n && npiv >= 0) ;

    if (cc == NULL) return (EMPTY) ;
    if (m <= 0 || n <= 0) return (0) ;                     // nothing to do

    PR (("Try RHSIZE: m %ld n %ld npiv %ld\n", m, n, npiv)) ;

    // -------------------------------------------------------------------------
    // count the squeezed part of R+H
    // -------------------------------------------------------------------------

    rm = 0 ;                            // number of rows in R (:,0:k)
    for (k = 0 ; k < npiv ; k++)
    {
        // get the staircase
        t = Stair [k] ;                 // F (0:t-1,k) contains R and H
        if (t == 0)
        {
            t = rm ;                    // dead col, R (0:rm-1,k) only, no H
        }
        else if (rm < m)
        {
            rm++ ;                      // col k not dead; one more row of R
        }
        PR (("  for RHSIZE, k %ld Stair %ld t %ld (piv)\n", k, Stair[k], t)) ;
        // pack R (0:rm-1,k) and H (rm:t-1,k)
        rhsize += t ;
    }

    // -------------------------------------------------------------------------
    // count the rectangular part of R and trapezoidal part of H
    // -------------------------------------------------------------------------

    h = rm ;                            // the column of H starts in row h
    for ( ; k < n ; k++)
    {
        // get the staircase
        t = Stair [k] ;
        // pack R (0:rm-1,k)
        rhsize += rm ;
        h = MIN (h+1, m) ;              // one more row of C to skip over
        // pack H (h:t-1,k)
        PR (("  for RHSIZE, k %ld Stair %ld t %ld\n", k, Stair[k], t)) ;
        rhsize += (t-h) ;
    }

    PR (("  RHSIZE: m %ld n %ld npiv %ld is %ld\n", m, n, npiv, rhsize)) ;
    return (rhsize) ;                   // return # of entries in R+H
}