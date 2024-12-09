void ts::SpliceInformationTable::adjustPTS()
{
    // Only splice_insert() commands need adjustment.
    if (splice_command_type == SPLICE_INSERT) {
        splice_insert.adjustPTS(pts_adjustment);
    }

    // Adjustment applied, don't do it again.
    pts_adjustment = 0;
}