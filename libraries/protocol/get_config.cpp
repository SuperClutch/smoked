#include <smoke/protocol/get_config.hpp>
#include <smoke/protocol/config.hpp>
#include <smoke/protocol/asset.hpp>
#include <smoke/protocol/types.hpp>
#include <smoke/protocol/version.hpp>

namespace smoke { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
#else
   result[ "IS_TEST_NET" ] = false;
#endif

   result["SMOKE_100_PERCENT"] = SMOKE_100_PERCENT;
   result["SMOKE_1_PERCENT"] = SMOKE_1_PERCENT;
   result["SMOKE_1_TENTH_PERCENT"] = SMOKE_1_TENTH_PERCENT;
   result["SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = SMOKE_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["SMOKE_ACTIVE_CHALLENGE_FEE"] = SMOKE_ACTIVE_CHALLENGE_FEE;
   result["SMOKE_ADDRESS_PREFIX"] = SMOKE_ADDRESS_PREFIX;
   result["SMOKE_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = SMOKE_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["SMOKE_BANDWIDTH_PRECISION"] = SMOKE_BANDWIDTH_PRECISION;
   result["SMOKE_BLOCKCHAIN_HARDFORK_VERSION"] = SMOKE_BLOCKCHAIN_HARDFORK_VERSION;
   result["SMOKE_BLOCKCHAIN_VERSION"] = SMOKE_BLOCKCHAIN_VERSION;
   result["SMOKE_BLOCK_INTERVAL"] = SMOKE_BLOCK_INTERVAL;
   result["SMOKE_BLOCKS_PER_DAY"] = SMOKE_BLOCKS_PER_DAY;
   result["SMOKE_BLOCKS_PER_HOUR"] = SMOKE_BLOCKS_PER_HOUR;
   result["SMOKE_BLOCKS_PER_YEAR"] = SMOKE_BLOCKS_PER_YEAR;
   result["SMOKE_CASHOUT_WINDOW_SECONDS"] = SMOKE_CASHOUT_WINDOW_SECONDS;
   result["SMOKE_CHAIN_ID"] = SMOKE_CHAIN_ID;
   result["SMOKE_CONTENT_CONSTANT"] = SMOKE_CONTENT_CONSTANT;
   result["SMOKE_CONTENT_REWARD_PERCENT"] = SMOKE_CONTENT_REWARD_PERCENT;
   result["SMOKE_CREATE_ACCOUNT_DELEGATION_RATIO"] = SMOKE_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["SMOKE_CREATE_ACCOUNT_DELEGATION_TIME"] = SMOKE_CREATE_ACCOUNT_DELEGATION_TIME;
   result["SMOKE_CREATE_ACCOUNT_WITH_STEEM_MODIFIER"] = SMOKE_CREATE_ACCOUNT_WITH_STEEM_MODIFIER;
   result["SMOKE_EQUIHASH_K"] = SMOKE_EQUIHASH_K;
   result["SMOKE_EQUIHASH_N"] = SMOKE_EQUIHASH_N;
   result["SMOKE_GENESIS_TIME"] = SMOKE_GENESIS_TIME;
   result["SMOKE_HARDFORK_REQUIRED_WITNESSES"] = SMOKE_HARDFORK_REQUIRED_WITNESSES;
   result["SMOKE_INFLATION_NARROWING_PERIOD"] = SMOKE_INFLATION_NARROWING_PERIOD;
   result["SMOKE_INFLATION_RATE_START_PERCENT"] = SMOKE_INFLATION_RATE_START_PERCENT;
   result["SMOKE_INFLATION_RATE_STOP_PERCENT"] = SMOKE_INFLATION_RATE_STOP_PERCENT;
   result["SMOKE_INIT_MINER_NAME"] = SMOKE_INIT_MINER_NAME;
   result["SMOKE_INIT_PUBLIC_KEY_STR"] = SMOKE_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["SMOKE_INIT_PRIVATE_KEY"] = SMOKE_INIT_PRIVATE_KEY;
#endif
   result["SMOKE_INIT_SUPPLY"] = SMOKE_INIT_SUPPLY;
   result["SMOKE_IRREVERSIBLE_THRESHOLD"] = SMOKE_IRREVERSIBLE_THRESHOLD;
   result["SMOKE_MAX_ACCOUNT_NAME_LENGTH"] = SMOKE_MAX_ACCOUNT_NAME_LENGTH;
   result["SMOKE_MAX_ACCOUNT_WITNESS_VOTES"] = SMOKE_MAX_ACCOUNT_WITNESS_VOTES;
   result["SMOKE_MAX_BLOCK_SIZE"] = SMOKE_MAX_BLOCK_SIZE;
   result["SMOKE_SOFT_MAX_BLOCK_SIZE"] = SMOKE_SOFT_MAX_BLOCK_SIZE;
   result["SMOKE_MAX_COMMENT_DEPTH"] = SMOKE_MAX_COMMENT_DEPTH;
   result["SMOKE_MAX_MEMO_SIZE"] = SMOKE_MAX_MEMO_SIZE;
   result["SMOKE_MAX_WITNESSES"] = SMOKE_MAX_WITNESSES;
   result["SMOKE_MAX_MINER_WITNESSES"] = SMOKE_MAX_MINER_WITNESSES;
   result["SMOKE_MAX_PERMLINK_LENGTH"] = SMOKE_MAX_PERMLINK_LENGTH;
   result["SMOKE_MAX_PROXY_RECURSION_DEPTH"] = SMOKE_MAX_PROXY_RECURSION_DEPTH;
   result["SMOKE_MAX_RESERVE_RATIO"] = SMOKE_MAX_RESERVE_RATIO;
   result["SMOKE_MAX_RUNNER_WITNESSES"] = SMOKE_MAX_RUNNER_WITNESSES;
   result["SMOKE_MAX_SHARE_SUPPLY"] = SMOKE_MAX_SHARE_SUPPLY;
   result["SMOKE_MAX_SIG_CHECK_DEPTH"] = SMOKE_MAX_SIG_CHECK_DEPTH;
   result["SMOKE_MAX_TIME_UNTIL_EXPIRATION"] = SMOKE_MAX_TIME_UNTIL_EXPIRATION;
   result["SMOKE_MAX_TRANSACTION_SIZE"] = SMOKE_MAX_TRANSACTION_SIZE;
   result["SMOKE_MAX_UNDO_HISTORY"] = SMOKE_MAX_UNDO_HISTORY;
   result["SMOKE_MAX_VOTE_CHANGES"] = SMOKE_MAX_VOTE_CHANGES;
   result["SMOKE_MAX_VOTED_WITNESSES"] = SMOKE_MAX_VOTED_WITNESSES;
   result["SMOKE_MAX_WITHDRAW_ROUTES"] = SMOKE_MAX_WITHDRAW_ROUTES;
   result["SMOKE_MAX_WITNESS_URL_LENGTH"] = SMOKE_MAX_WITNESS_URL_LENGTH;
   result["SMOKE_MIN_ACCOUNT_CREATION_FEE"] = SMOKE_MIN_ACCOUNT_CREATION_FEE;
   result["SMOKE_MIN_ACCOUNT_NAME_LENGTH"] = SMOKE_MIN_ACCOUNT_NAME_LENGTH;
   result["SMOKE_MIN_BLOCK_SIZE"] = SMOKE_MIN_BLOCK_SIZE;
   result["SMOKE_MIN_BLOCK_SIZE_LIMIT"] = SMOKE_MIN_BLOCK_SIZE_LIMIT;
   result["SMOKE_MIN_PERMLINK_LENGTH"] = SMOKE_MIN_PERMLINK_LENGTH;
   result["SMOKE_MIN_REPLY_INTERVAL"] = SMOKE_MIN_REPLY_INTERVAL;
   result["SMOKE_MIN_ROOT_COMMENT_INTERVAL"] = SMOKE_MIN_ROOT_COMMENT_INTERVAL;
   result["SMOKE_MIN_VOTE_INTERVAL_SEC"] = SMOKE_MIN_VOTE_INTERVAL_SEC;
   result["SMOKE_MINER_ACCOUNT"] = SMOKE_MINER_ACCOUNT;
   result["SMOKE_MIN_TRANSACTION_EXPIRATION_LIMIT"] = SMOKE_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["SMOKE_MIN_UNDO_HISTORY"] = SMOKE_MIN_UNDO_HISTORY;
   result["SMOKE_NULL_ACCOUNT"] = SMOKE_NULL_ACCOUNT;
   result["SMOKE_NUM_INIT_MINERS"] = SMOKE_NUM_INIT_MINERS;
   result["SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = SMOKE_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["SMOKE_OWNER_AUTH_RECOVERY_PERIOD"] = SMOKE_OWNER_AUTH_RECOVERY_PERIOD;
   result["SMOKE_OWNER_CHALLENGE_FEE"] = SMOKE_OWNER_CHALLENGE_FEE;
   result["SMOKE_OWNER_UPDATE_LIMIT"] = SMOKE_OWNER_UPDATE_LIMIT;
   result["SMOKE_POST_REWARD_FUND_NAME"] = SMOKE_POST_REWARD_FUND_NAME;
   result["SMOKE_PROXY_TO_SELF_ACCOUNT"] = SMOKE_PROXY_TO_SELF_ACCOUNT;
   result["SMOKE_SECONDS_PER_YEAR"] = SMOKE_SECONDS_PER_YEAR;
   result["SMOKE_RECENT_RSHARES_DECAY_RATE"] = SMOKE_RECENT_RSHARES_DECAY_RATE;
   result["SMOKE_REVERSE_AUCTION_WINDOW_SECONDS"] = SMOKE_REVERSE_AUCTION_WINDOW_SECONDS;
   result["SMOKE_ROOT_POST_PARENT"] = SMOKE_ROOT_POST_PARENT;
   result["SMOKE_SOFT_MAX_COMMENT_DEPTH"] = SMOKE_SOFT_MAX_COMMENT_DEPTH;
   result["SMOKE_START_MINER_VOTING_BLOCK"] = SMOKE_START_MINER_VOTING_BLOCK;
   result["SMOKE_SYMBOL_STR"] = SMOKE_SYMBOL_STR;
   result["SMOKE_TEMP_ACCOUNT"] = SMOKE_TEMP_ACCOUNT;
   result["SMOKE_UPVOTE_LOCKOUT"] = SMOKE_UPVOTE_LOCKOUT;
   result["SMOKE_VESTING_FUND_PERCENT"] = SMOKE_VESTING_FUND_PERCENT;
   result["SMOKE_VESTING_WITHDRAW_INTERVALS"] = SMOKE_VESTING_WITHDRAW_INTERVALS;
   result["SMOKE_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMOKE_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMOKE_VOTE_DUST_THRESHOLD"] = SMOKE_VOTE_DUST_THRESHOLD;
   result["SMOKE_VOTE_REGENERATION_SECONDS"] = SMOKE_VOTE_REGENERATION_SECONDS;
   result["SMOKE_SYMBOL"] = SMOKE_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["VIRTUAL_SCHEDULE_LAP_LENGTH"] = VIRTUAL_SCHEDULE_LAP_LENGTH;

   return result;
}

} } // smoke::protocol
