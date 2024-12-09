void logOpForSharding(OperationContext* txn,
                      const char* opstr,
                      const char* ns,
                      const BSONObj& obj,
                      BSONObj* patt,
                      bool notInActiveChunk) {
    ShardingState* shardingState = ShardingState::get(txn);
    if (shardingState->enabled())
        shardingState->migrationSourceManager()->logOp(txn, opstr, ns, obj, patt, notInActiveChunk);
}