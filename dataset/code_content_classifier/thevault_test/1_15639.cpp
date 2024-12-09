void apply_eos_lock(apply_context& context) {
   auto lock = context.msg.as<types::lock>();

   EOS_ASSERT(lock.amount > 0, message_validate_exception, "Locked amount must be positive");

   context.require_scope(lock.to);
   context.require_scope(lock.from);
   context.require_scope(config::eos_contract_name);

   context.require_authorization(lock.from);

   context.require_recipient(lock.to);
   context.require_recipient(lock.from);

   const auto& locker = context.db.get<balance_object, by_owner_name>(lock.from);

   EOS_ASSERT( locker.balance >= lock.amount, message_precondition_exception, 
              "Account ${a} lacks sufficient funds to lock ${amt} EOS", ("a", lock.from)("amt", lock.amount)("available",locker.balance) );

   context.mutable_db.modify(locker, [&lock](balance_object& a) {
      a.balance -= lock.amount;
   });

   const auto& balance = context.db.get<staked_balance_object, by_owner_name>(lock.to);
   balance.stake_tokens(lock.amount, context.mutable_db);
}