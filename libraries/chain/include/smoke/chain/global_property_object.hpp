#pragma once
#include <fc/uint128.hpp>

#include <smoke/chain/steem_object_types.hpp>

#include <smoke/protocol/asset.hpp>

namespace smoke { namespace chain {

   using smoke::protocol::asset;
   using smoke::protocol::price;

   /**
    * @class dynamic_global_property_object
    * @brief Maintains global state information
    * @ingroup object
    * @ingroup implementation
    *
    * This is an implementation detail. The values here are calculated during normal chain operations and reflect the
    * current values of global blockchain properties.
    */
   class dynamic_global_property_object : public object< dynamic_global_property_object_type, dynamic_global_property_object>
   {
      public:
         template< typename Constructor, typename Allocator >
         dynamic_global_property_object( Constructor&& c, allocator< Allocator > a )
         {
            c( *this );
         }

         dynamic_global_property_object(){}

         id_type           id;

         uint32_t          head_block_number = 0;
         block_id_type     head_block_id;
         time_point_sec    time;
         account_name_type current_witness;

         asset       current_supply             = asset( 0, SMOKE_SYMBOL );
         asset       total_vesting_fund_steem   = asset( 0, SMOKE_SYMBOL );
         asset       total_vesting_shares       = asset( 0, VESTS_SYMBOL );
         asset       total_reward_fund_steem    = asset( 0, SMOKE_SYMBOL );
         fc::uint128 total_reward_shares2; ///< the running total of REWARD^2
         asset       pending_rewarded_vesting_shares = asset( 0, VESTS_SYMBOL );
         asset       pending_rewarded_vesting_steem = asset( 0, SMOKE_SYMBOL );

         price       get_vesting_share_price() const
         {
            if ( total_vesting_fund_steem.amount == 0 || total_vesting_shares.amount == 0 )
               return price ( asset( 1, SMOKE_SYMBOL ), asset( 1000000, VESTS_SYMBOL ) );

            return price( total_vesting_shares, total_vesting_fund_steem );
         }

         price get_reward_vesting_share_price() const
         {
            if ( pending_rewarded_vesting_shares.amount == 0 || pending_rewarded_vesting_steem.amount == 0 )
               return get_vesting_share_price();

            return price( total_vesting_shares + pending_rewarded_vesting_shares,
               total_vesting_fund_steem + pending_rewarded_vesting_steem );
         }

         /**
          *  Maximum block size is decided by the set of active witnesses which change every round.
          *  Each witness posts what they think the maximum size should be as part of their witness
          *  properties, the median size is chosen to be the maximum block size for the round.
          *
          *  @note the minimum value for maximum_block_size is defined by the protocol to prevent the
          *  network from getting stuck by witnesses attempting to set this too low.
          */
         uint32_t     maximum_block_size = 0;

         /**
          * The current absolute slot number.  Equal to the total
          * number of slots since genesis.  Also equal to the total
          * number of missed slots plus head_block_number.
          */
         uint64_t      current_aslot = 0;

         /**
          * used to compute witness participation.
          */
         fc::uint128_t recent_slots_filled;
         uint8_t       participation_count = 0; ///< Divide by 128 to compute participation percentage

         uint32_t last_irreversible_block_num = 0;

         /**
          * The number of votes regenerated per day.  Any user voting slower than this rate will be
          * "wasting" voting power through spillover; any user voting faster than this rate will have
          * their votes reduced.
          */
         uint32_t vote_power_reserve_rate = 40;
   };

   typedef multi_index_container<
      dynamic_global_property_object,
      indexed_by<
         ordered_unique< tag< by_id >,
            member< dynamic_global_property_object, dynamic_global_property_object::id_type, &dynamic_global_property_object::id > >
      >,
      allocator< dynamic_global_property_object >
   > dynamic_global_property_index;

} } // smoke::chain

FC_REFLECT( smoke::chain::dynamic_global_property_object,
             (id)
             (head_block_number)
             (head_block_id)
             (time)
             (current_witness)
             (current_supply)
             (total_vesting_fund_steem)
             (total_vesting_shares)
             (total_reward_fund_steem)
             (total_reward_shares2)
             (pending_rewarded_vesting_shares)
             (pending_rewarded_vesting_steem)
             (maximum_block_size)
             (current_aslot)
             (recent_slots_filled)
             (participation_count)
             (last_irreversible_block_num)
             (vote_power_reserve_rate)
          )
CHAINBASE_SET_INDEX_TYPE( smoke::chain::dynamic_global_property_object, smoke::chain::dynamic_global_property_index )
