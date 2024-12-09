void apply_eos_newaccount(apply_context& context) {
   auto create = context.msg.as<types::newaccount>();
   context.require_authorization(create.creator);

   EOS_ASSERT( validate(create.owner), message_validate_exception, "Invalid owner authority");
   EOS_ASSERT( validate(create.active), message_validate_exception, "Invalid active authority");
   EOS_ASSERT( validate(create.recovery), message_validate_exception, "Invalid recovery authority");

   auto& db = context.mutable_db;

   auto existing_account = db.find<account_object, by_name>(create.name);
   EOS_ASSERT(existing_account == nullptr, account_name_exists_exception,
              "Cannot create account named ${name}, as that name is already taken",
              ("name", create.name));

   for( const auto& auth : { create.owner, create.active, create.recovery } ){
      validate_authority_precondition( context, auth );
   }

   const auto& new_account = db.create<account_object>([&create, &db](account_object& a) {
      a.name = create.name;
      a.creation_date = db.get(dynamic_global_property_object::id_type()).time;
   });
   if (context.controller.is_applying_block()) {
      const auto& owner_permission = db.create<permission_object>([&create, &new_account](permission_object& p) {
         p.name = "owner";
         p.parent = 0;
         p.owner = new_account.name;
         p.auth = std::move(create.owner);
      });
      db.create<permission_object>([&create, &owner_permission](permission_object& p) {
         p.name = "active";
         p.parent = owner_permission.id;
         p.owner = owner_permission.owner;
         p.auth = std::move(create.active);
      });
   }

   const auto& creatorBalance = context.mutable_db.get<balance_object, by_owner_name>(create.creator);

   EOS_ASSERT(creatorBalance.balance >= create.deposit.amount, message_validate_exception,
              "Creator '${c}' has insufficient funds to make account creation deposit of ${a}",
              ("c", create.creator)("a", create.deposit));

   context.mutable_db.modify(creatorBalance, [&create](balance_object& b) {
      b.balance -= create.deposit.amount;
   });

   context.mutable_db.create<balance_object>([&create](balance_object& b) {
      b.owner_name = create.name;
      b.balance = 0; //create.deposit.amount; TODO: make sure we credit this in @staked
   });

   context.mutable_db.create<staked_balance_object>([&create](staked_balance_object& sbo) {
      sbo.ownerName = create.name;
      sbo.staked_balance = create.deposit.amount;
   });
}