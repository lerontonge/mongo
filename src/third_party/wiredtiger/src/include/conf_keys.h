/*-
 * Copyright (c) 2014-present MongoDB, Inc.
 * Copyright (c) 2008-2014 WiredTiger, Inc.
 *	All rights reserved.
 *
 * See the file LICENSE for redistribution information.
 */

#pragma once

/*******************************************
 * API configuration keys.
 *******************************************/
/*
 * DO NOT EDIT: automatically built by dist/api_config.py.
 * API configuration keys: BEGIN
 */
#define WT_CONF_ID_Assert 1ULL
#define WT_CONF_ID_Block_cache 182ULL
#define WT_CONF_ID_Checkpoint 197ULL
#define WT_CONF_ID_Checkpoint_cleanup 201ULL
#define WT_CONF_ID_Chunk_cache 204ULL
#define WT_CONF_ID_Compatibility 206ULL
#define WT_CONF_ID_Debug 118ULL
#define WT_CONF_ID_Debug_mode 208ULL
#define WT_CONF_ID_Disaggregated 20ULL
#define WT_CONF_ID_Dump_version 120ULL
#define WT_CONF_ID_Encryption 24ULL
#define WT_CONF_ID_Eviction 228ULL
#define WT_CONF_ID_File_manager 242ULL
#define WT_CONF_ID_Flush_tier 170ULL
#define WT_CONF_ID_Hash 305ULL
#define WT_CONF_ID_Heuristic_controls 247ULL
#define WT_CONF_ID_History_store 251ULL
#define WT_CONF_ID_Import 104ULL
#define WT_CONF_ID_Incremental 127ULL
#define WT_CONF_ID_Io_capacity 253ULL
#define WT_CONF_ID_Live_restore 66ULL
#define WT_CONF_ID_Log 42ULL
#define WT_CONF_ID_Operation_tracking 263ULL
#define WT_CONF_ID_Prefetch 285ULL
#define WT_CONF_ID_Rollback_to_stable 265ULL
#define WT_CONF_ID_Roundup_timestamps 161ULL
#define WT_CONF_ID_Shared_cache 267ULL
#define WT_CONF_ID_Statistics_log 271ULL
#define WT_CONF_ID_Tiered_storage 53ULL
#define WT_CONF_ID_Transaction_sync 324ULL
#define WT_CONF_ID_access_pattern_hint 12ULL
#define WT_CONF_ID_action 93ULL
#define WT_CONF_ID_allocation_size 13ULL
#define WT_CONF_ID_app_metadata 0ULL
#define WT_CONF_ID_append 90ULL
#define WT_CONF_ID_archive 257ULL
#define WT_CONF_ID_auth_token 54ULL
#define WT_CONF_ID_available 316ULL
#define WT_CONF_ID_background 97ULL
#define WT_CONF_ID_background_compact 209ULL
#define WT_CONF_ID_backup 174ULL
#define WT_CONF_ID_backup_restore_target 287ULL
#define WT_CONF_ID_bitmap 67ULL
#define WT_CONF_ID_blkcache_eviction_aggression 185ULL
#define WT_CONF_ID_block_allocation 14ULL
#define WT_CONF_ID_block_compressor 15ULL
#define WT_CONF_ID_block_manager 16ULL
#define WT_CONF_ID_bound 94ULL
#define WT_CONF_ID_bucket 55ULL
#define WT_CONF_ID_bucket_prefix 56ULL
#define WT_CONF_ID_buckets 306ULL
#define WT_CONF_ID_buffer_alignment 288ULL
#define WT_CONF_ID_builtin_extension_config 289ULL
#define WT_CONF_ID_bulk 116ULL
#define WT_CONF_ID_cache 175ULL
#define WT_CONF_ID_cache_cursors 281ULL
#define WT_CONF_ID_cache_directory 57ULL
#define WT_CONF_ID_cache_max_wait_ms 193ULL
#define WT_CONF_ID_cache_on_checkpoint 183ULL
#define WT_CONF_ID_cache_on_writes 184ULL
#define WT_CONF_ID_cache_overhead 194ULL
#define WT_CONF_ID_cache_resident 17ULL
#define WT_CONF_ID_cache_size 195ULL
#define WT_CONF_ID_cache_stuck_timeout_ms 196ULL
#define WT_CONF_ID_capacity 291ULL
#define WT_CONF_ID_checkpoint 62ULL
#define WT_CONF_ID_checkpoint_backup_info 63ULL
#define WT_CONF_ID_checkpoint_cleanup 167ULL
#define WT_CONF_ID_checkpoint_cleanup_obsolete_tw_pages_dirty_max 248ULL
#define WT_CONF_ID_checkpoint_crash_point 168ULL
#define WT_CONF_ID_checkpoint_fail_before_turtle_update 282ULL
#define WT_CONF_ID_checkpoint_id 75ULL
#define WT_CONF_ID_checkpoint_lsn 64ULL
#define WT_CONF_ID_checkpoint_meta 76ULL
#define WT_CONF_ID_checkpoint_read_timestamp 119ULL
#define WT_CONF_ID_checkpoint_retention 211ULL
#define WT_CONF_ID_checkpoint_sync 290ULL
#define WT_CONF_ID_checkpoint_use_history 117ULL
#define WT_CONF_ID_checkpoint_wait 110ULL
#define WT_CONF_ID_checksum 18ULL
#define WT_CONF_ID_chunk 268ULL
#define WT_CONF_ID_chunk_cache 255ULL
#define WT_CONF_ID_chunk_cache_evict_trigger 292ULL
#define WT_CONF_ID_chunk_size 293ULL
#define WT_CONF_ID_claim_prepared_id 155ULL
#define WT_CONF_ID_close_handle_minimum 243ULL
#define WT_CONF_ID_close_idle_time 244ULL
#define WT_CONF_ID_close_scan_interval 245ULL
#define WT_CONF_ID_colgroups 86ULL
#define WT_CONF_ID_collator 6ULL
#define WT_CONF_ID_columns 7ULL
#define WT_CONF_ID_commit_timestamp 2ULL
#define WT_CONF_ID_compare_timestamp 105ULL
#define WT_CONF_ID_compile_configuration_count 298ULL
#define WT_CONF_ID_compressor 310ULL
#define WT_CONF_ID_config 277ULL
#define WT_CONF_ID_config_base 299ULL
#define WT_CONF_ID_configuration 212ULL
#define WT_CONF_ID_consolidate 128ULL
#define WT_CONF_ID_corruption_abort 210ULL
#define WT_CONF_ID_create 300ULL
#define WT_CONF_ID_cursor_copy 213ULL
#define WT_CONF_ID_cursor_reposition 214ULL
#define WT_CONF_ID_cursors 176ULL
#define WT_CONF_ID_default 317ULL
#define WT_CONF_ID_delta_pct 22ULL
#define WT_CONF_ID_dhandle_buckets 307ULL
#define WT_CONF_ID_dictionary 19ULL
#define WT_CONF_ID_direct_io 301ULL
#define WT_CONF_ID_do_not_clear_txn_id 143ULL
#define WT_CONF_ID_drop 169ULL
#define WT_CONF_ID_dryrun 98ULL
#define WT_CONF_ID_dump 126ULL
#define WT_CONF_ID_dump_address 144ULL
#define WT_CONF_ID_dump_all_data 145ULL
#define WT_CONF_ID_dump_blocks 146ULL
#define WT_CONF_ID_dump_key_data 147ULL
#define WT_CONF_ID_dump_layout 148ULL
#define WT_CONF_ID_dump_offsets 149ULL
#define WT_CONF_ID_dump_pages 150ULL
#define WT_CONF_ID_dump_tree_shape 151ULL
#define WT_CONF_ID_durable_timestamp 3ULL
#define WT_CONF_ID_early_load 278ULL
#define WT_CONF_ID_enabled 43ULL
#define WT_CONF_ID_entry 279ULL
#define WT_CONF_ID_error_prefix 227ULL
#define WT_CONF_ID_evict_sample_inmem 231ULL
#define WT_CONF_ID_evict_use_softptr 232ULL
#define WT_CONF_ID_eviction 215ULL
#define WT_CONF_ID_eviction_checkpoint_target 234ULL
#define WT_CONF_ID_eviction_checkpoint_ts_ordering 226ULL
#define WT_CONF_ID_eviction_dirty_target 235ULL
#define WT_CONF_ID_eviction_dirty_trigger 236ULL
#define WT_CONF_ID_eviction_obsolete_tw_pages_dirty_max 249ULL
#define WT_CONF_ID_eviction_target 237ULL
#define WT_CONF_ID_eviction_trigger 238ULL
#define WT_CONF_ID_eviction_updates_target 239ULL
#define WT_CONF_ID_eviction_updates_trigger 240ULL
#define WT_CONF_ID_exclude 99ULL
#define WT_CONF_ID_exclusive 103ULL
#define WT_CONF_ID_exclusive_refreshed 96ULL
#define WT_CONF_ID_extensions 303ULL
#define WT_CONF_ID_extra_diagnostics 241ULL
#define WT_CONF_ID_file 129ULL
#define WT_CONF_ID_file_extend 304ULL
#define WT_CONF_ID_file_max 252ULL
#define WT_CONF_ID_file_metadata 106ULL
#define WT_CONF_ID_file_wait_ms 203ULL
#define WT_CONF_ID_final_flush 172ULL
#define WT_CONF_ID_flatten_leaf_page_delta 77ULL
#define WT_CONF_ID_flush_time 73ULL
#define WT_CONF_ID_flush_timestamp 74ULL
#define WT_CONF_ID_flushed_data_cache_insertion 295ULL
#define WT_CONF_ID_force 111ULL
#define WT_CONF_ID_force_stop 130ULL
#define WT_CONF_ID_force_write_wait 311ULL
#define WT_CONF_ID_format 27ULL
#define WT_CONF_ID_free_space_target 100ULL
#define WT_CONF_ID_full_target 186ULL
#define WT_CONF_ID_generation_drain_timeout_ms 246ULL
#define WT_CONF_ID_get 142ULL
#define WT_CONF_ID_granularity 131ULL
#define WT_CONF_ID_handles 177ULL
#define WT_CONF_ID_hashsize 188ULL
#define WT_CONF_ID_hazard_max 308ULL
#define WT_CONF_ID_huffman_key 28ULL
#define WT_CONF_ID_huffman_value 29ULL
#define WT_CONF_ID_id 65ULL
#define WT_CONF_ID_ignore_cache_size 284ULL
#define WT_CONF_ID_ignore_in_memory_cache_size 30ULL
#define WT_CONF_ID_ignore_prepare 156ULL
#define WT_CONF_ID_immutable 72ULL
#define WT_CONF_ID_in_memory 31ULL
#define WT_CONF_ID_inclusive 95ULL
#define WT_CONF_ID_ingest 84ULL
#define WT_CONF_ID_internal_item_max 32ULL
#define WT_CONF_ID_internal_key_max 33ULL
#define WT_CONF_ID_internal_key_truncate 34ULL
#define WT_CONF_ID_internal_page_delta 78ULL
#define WT_CONF_ID_internal_page_max 35ULL
#define WT_CONF_ID_interval 323ULL
#define WT_CONF_ID_isolation 157ULL
#define WT_CONF_ID_json 272ULL
#define WT_CONF_ID_json_output 256ULL
#define WT_CONF_ID_key_format 36ULL
#define WT_CONF_ID_key_gap 37ULL
#define WT_CONF_ID_keyid 26ULL
#define WT_CONF_ID_last 87ULL
#define WT_CONF_ID_last_materialized_lsn 79ULL
#define WT_CONF_ID_leaf_item_max 38ULL
#define WT_CONF_ID_leaf_key_max 39ULL
#define WT_CONF_ID_leaf_page_delta 80ULL
#define WT_CONF_ID_leaf_page_max 40ULL
#define WT_CONF_ID_leaf_value_max 41ULL
#define WT_CONF_ID_leak_memory 173ULL
#define WT_CONF_ID_legacy_page_visit_strategy 233ULL
#define WT_CONF_ID_local_retention 58ULL
#define WT_CONF_ID_lock_wait 112ULL
#define WT_CONF_ID_log 178ULL
#define WT_CONF_ID_log_retention 216ULL
#define WT_CONF_ID_log_size 198ULL
#define WT_CONF_ID_lose_all_my_data 81ULL
#define WT_CONF_ID_max_consecutive_delta 23ULL
#define WT_CONF_ID_max_percent_overhead 189ULL
#define WT_CONF_ID_memory_page_image_max 44ULL
#define WT_CONF_ID_memory_page_max 45ULL
#define WT_CONF_ID_metadata 179ULL
#define WT_CONF_ID_metadata_file 107ULL
#define WT_CONF_ID_method 202ULL
#define WT_CONF_ID_mmap 313ULL
#define WT_CONF_ID_mmap_all 314ULL
#define WT_CONF_ID_multiprocess 315ULL
#define WT_CONF_ID_name 25ULL
#define WT_CONF_ID_nbits 68ULL
#define WT_CONF_ID_next_checkpoint_id 82ULL
#define WT_CONF_ID_next_random 134ULL
#define WT_CONF_ID_next_random_sample_size 135ULL
#define WT_CONF_ID_next_random_seed 136ULL
#define WT_CONF_ID_no_timestamp 158ULL
#define WT_CONF_ID_nvram_path 190ULL
#define WT_CONF_ID_object_target_size 59ULL
#define WT_CONF_ID_obsolete_tw_btree_max 250ULL
#define WT_CONF_ID_oldest 88ULL
#define WT_CONF_ID_oldest_timestamp 286ULL
#define WT_CONF_ID_on_close 273ULL
#define WT_CONF_ID_operation_timeout_ms 159ULL
#define WT_CONF_ID_os_cache_dirty_max 46ULL
#define WT_CONF_ID_os_cache_dirty_pct 258ULL
#define WT_CONF_ID_os_cache_max 47ULL
#define WT_CONF_ID_overwrite 91ULL
#define WT_CONF_ID_page_history 217ULL
#define WT_CONF_ID_page_log 21ULL
#define WT_CONF_ID_panic_corrupt 108ULL
#define WT_CONF_ID_path 264ULL
#define WT_CONF_ID_percent_file_in_dram 191ULL
#define WT_CONF_ID_pinned 205ULL
#define WT_CONF_ID_prealloc 259ULL
#define WT_CONF_ID_prealloc_init_count 260ULL
#define WT_CONF_ID_precise 199ULL
#define WT_CONF_ID_prefix_compression 48ULL
#define WT_CONF_ID_prefix_compression_min 49ULL
#define WT_CONF_ID_prefix_search 92ULL
#define WT_CONF_ID_prepare_timestamp 164ULL
#define WT_CONF_ID_prepared 162ULL
#define WT_CONF_ID_prepared_id 165ULL
#define WT_CONF_ID_preserve_prepared 318ULL
#define WT_CONF_ID_priority 160ULL
#define WT_CONF_ID_quota 269ULL
#define WT_CONF_ID_raw 137ULL
#define WT_CONF_ID_raw_key_value 124ULL
#define WT_CONF_ID_read 163ULL
#define WT_CONF_ID_read_corrupt 152ULL
#define WT_CONF_ID_read_once 138ULL
#define WT_CONF_ID_read_size 309ULL
#define WT_CONF_ID_read_timestamp 4ULL
#define WT_CONF_ID_readonly 69ULL
#define WT_CONF_ID_realloc_exact 218ULL
#define WT_CONF_ID_realloc_malloc 219ULL
#define WT_CONF_ID_recover 312ULL
#define WT_CONF_ID_release 207ULL
#define WT_CONF_ID_release_evict 125ULL
#define WT_CONF_ID_release_evict_page 283ULL
#define WT_CONF_ID_remove 261ULL
#define WT_CONF_ID_remove_files 113ULL
#define WT_CONF_ID_remove_shared 114ULL
#define WT_CONF_ID_repair 109ULL
#define WT_CONF_ID_require_max 296ULL
#define WT_CONF_ID_require_min 297ULL
#define WT_CONF_ID_reserve 270ULL
#define WT_CONF_ID_role 83ULL
#define WT_CONF_ID_rollback_error 220ULL
#define WT_CONF_ID_rollback_timestamp 166ULL
#define WT_CONF_ID_run_once 101ULL
#define WT_CONF_ID_salvage 319ULL
#define WT_CONF_ID_secretkey 302ULL
#define WT_CONF_ID_session_max 320ULL
#define WT_CONF_ID_session_scratch_max 321ULL
#define WT_CONF_ID_session_table_cache 322ULL
#define WT_CONF_ID_sessions 180ULL
#define WT_CONF_ID_shared 60ULL
#define WT_CONF_ID_size 187ULL
#define WT_CONF_ID_skip_sort_check 139ULL
#define WT_CONF_ID_slow_checkpoint 221ULL
#define WT_CONF_ID_source 8ULL
#define WT_CONF_ID_sources 274ULL
#define WT_CONF_ID_split_deepen_min_child 50ULL
#define WT_CONF_ID_split_deepen_per_child 51ULL
#define WT_CONF_ID_split_pct 52ULL
#define WT_CONF_ID_src_id 132ULL
#define WT_CONF_ID_stable 85ULL
#define WT_CONF_ID_stable_timestamp 153ULL
#define WT_CONF_ID_start_timestamp 122ULL
#define WT_CONF_ID_statistics 140ULL
#define WT_CONF_ID_storage_path 294ULL
#define WT_CONF_ID_stress_skiplist 222ULL
#define WT_CONF_ID_strict 154ULL
#define WT_CONF_ID_sync 115ULL
#define WT_CONF_ID_system_ram 192ULL
#define WT_CONF_ID_table_logging 223ULL
#define WT_CONF_ID_target 141ULL
#define WT_CONF_ID_terminate 280ULL
#define WT_CONF_ID_this_id 133ULL
#define WT_CONF_ID_threads 266ULL
#define WT_CONF_ID_threads_max 229ULL
#define WT_CONF_ID_threads_min 230ULL
#define WT_CONF_ID_tiered_flush_error_continue 224ULL
#define WT_CONF_ID_tiered_object 70ULL
#define WT_CONF_ID_tiers 89ULL
#define WT_CONF_ID_timeout 102ULL
#define WT_CONF_ID_timestamp 275ULL
#define WT_CONF_ID_timestamp_order 123ULL
#define WT_CONF_ID_timing_stress_for_test 276ULL
#define WT_CONF_ID_total 254ULL
#define WT_CONF_ID_txn 181ULL
#define WT_CONF_ID_type 9ULL
#define WT_CONF_ID_update_restore_evict 225ULL
#define WT_CONF_ID_use_environment 325ULL
#define WT_CONF_ID_use_environment_priv 326ULL
#define WT_CONF_ID_use_timestamp 171ULL
#define WT_CONF_ID_value_format 61ULL
#define WT_CONF_ID_verbose 10ULL
#define WT_CONF_ID_verify_metadata 327ULL
#define WT_CONF_ID_version 71ULL
#define WT_CONF_ID_visible_only 121ULL
#define WT_CONF_ID_wait 200ULL
#define WT_CONF_ID_write_through 328ULL
#define WT_CONF_ID_write_timestamp 5ULL
#define WT_CONF_ID_write_timestamp_usage 11ULL
#define WT_CONF_ID_zero_fill 262ULL

#define WT_CONF_ID_COUNT 329
/*
 * API configuration keys: END
 */

/*******************************************
 * Configuration key structure.
 *******************************************/
/*
 * DO NOT EDIT: automatically built by dist/api_config.py.
 * Configuration key structure: BEGIN
 */
static const struct {
    struct {
        uint64_t commit_timestamp;
        uint64_t durable_timestamp;
        uint64_t read_timestamp;
        uint64_t write_timestamp;
    } Assert;
    struct {
        uint64_t blkcache_eviction_aggression;
        uint64_t cache_on_checkpoint;
        uint64_t cache_on_writes;
        uint64_t enabled;
        uint64_t full_target;
        uint64_t hashsize;
        uint64_t max_percent_overhead;
        uint64_t nvram_path;
        uint64_t percent_file_in_dram;
        uint64_t size;
        uint64_t system_ram;
        uint64_t type;
    } Block_cache;
    struct {
        uint64_t log_size;
        uint64_t precise;
        uint64_t wait;
    } Checkpoint;
    struct {
        uint64_t file_wait_ms;
        uint64_t method;
        uint64_t wait;
    } Checkpoint_cleanup;
    struct {
        uint64_t capacity;
        uint64_t chunk_cache_evict_trigger;
        uint64_t chunk_size;
        uint64_t enabled;
        uint64_t flushed_data_cache_insertion;
        uint64_t hashsize;
        uint64_t pinned;
        uint64_t storage_path;
        uint64_t type;
    } Chunk_cache;
    struct {
        uint64_t release;
        uint64_t require_max;
        uint64_t require_min;
    } Compatibility;
    struct {
        uint64_t checkpoint_fail_before_turtle_update;
        uint64_t release_evict_page;
    } Debug;
    struct {
        uint64_t background_compact;
        uint64_t checkpoint_retention;
        uint64_t configuration;
        uint64_t corruption_abort;
        uint64_t cursor_copy;
        uint64_t cursor_reposition;
        uint64_t eviction;
        uint64_t eviction_checkpoint_ts_ordering;
        uint64_t log_retention;
        uint64_t page_history;
        uint64_t realloc_exact;
        uint64_t realloc_malloc;
        uint64_t rollback_error;
        uint64_t slow_checkpoint;
        uint64_t stress_skiplist;
        uint64_t table_logging;
        uint64_t tiered_flush_error_continue;
        uint64_t update_restore_evict;
    } Debug_mode;
    struct {
        uint64_t checkpoint_id;
        uint64_t checkpoint_meta;
        uint64_t flatten_leaf_page_delta;
        uint64_t internal_page_delta;
        uint64_t last_materialized_lsn;
        uint64_t leaf_page_delta;
        uint64_t lose_all_my_data;
        uint64_t next_checkpoint_id;
        uint64_t page_log;
        uint64_t role;
    } Disaggregated;
    struct {
        uint64_t keyid;
        uint64_t name;
        uint64_t secretkey;
    } Encryption;
    struct {
        uint64_t evict_sample_inmem;
        uint64_t evict_use_softptr;
        uint64_t legacy_page_visit_strategy;
        uint64_t threads_max;
        uint64_t threads_min;
    } Eviction;
    struct {
        uint64_t close_handle_minimum;
        uint64_t close_idle_time;
        uint64_t close_scan_interval;
    } File_manager;
    struct {
        uint64_t enabled;
        uint64_t force;
        uint64_t sync;
        uint64_t timeout;
    } Flush_tier;
    struct {
        uint64_t buckets;
        uint64_t dhandle_buckets;
    } Hash;
    struct {
        uint64_t checkpoint_cleanup_obsolete_tw_pages_dirty_max;
        uint64_t eviction_obsolete_tw_pages_dirty_max;
        uint64_t obsolete_tw_btree_max;
    } Heuristic_controls;
    struct {
        uint64_t file_max;
    } History_store;
    struct {
        uint64_t compare_timestamp;
        uint64_t enabled;
        uint64_t file_metadata;
        uint64_t metadata_file;
        uint64_t panic_corrupt;
        uint64_t repair;
    } Import;
    struct {
        uint64_t consolidate;
        uint64_t enabled;
        uint64_t file;
        uint64_t force_stop;
        uint64_t granularity;
        uint64_t src_id;
        uint64_t this_id;
    } Incremental;
    struct {
        uint64_t chunk_cache;
        uint64_t total;
    } Io_capacity;
    struct {
        uint64_t enabled;
        uint64_t path;
        uint64_t read_size;
        uint64_t threads_max;
    } Live_restore;
    struct {
        uint64_t archive;
        uint64_t compressor;
        uint64_t enabled;
        uint64_t file_max;
        uint64_t force_write_wait;
        uint64_t os_cache_dirty_pct;
        uint64_t path;
        uint64_t prealloc;
        uint64_t prealloc_init_count;
        uint64_t recover;
        uint64_t remove;
        uint64_t zero_fill;
    } Log;
    struct {
        uint64_t enabled;
        uint64_t path;
    } Operation_tracking;
    struct {
        uint64_t available;
        uint64_t _default;
    } Prefetch;
    struct {
        uint64_t threads;
    } Rollback_to_stable;
    struct {
        uint64_t prepared;
        uint64_t read;
    } Roundup_timestamps;
    struct {
        uint64_t chunk;
        uint64_t name;
        uint64_t quota;
        uint64_t reserve;
        uint64_t size;
    } Shared_cache;
    struct {
        uint64_t json;
        uint64_t on_close;
        uint64_t path;
        uint64_t sources;
        uint64_t timestamp;
        uint64_t wait;
    } Statistics_log;
    struct {
        uint64_t auth_token;
        uint64_t bucket;
        uint64_t bucket_prefix;
        uint64_t cache_directory;
        uint64_t interval;
        uint64_t local_retention;
        uint64_t name;
        uint64_t shared;
    } Tiered_storage;
    struct {
        uint64_t enabled;
        uint64_t method;
    } Transaction_sync;
    uint64_t access_pattern_hint;
    uint64_t action;
    uint64_t allocation_size;
    uint64_t app_metadata;
    uint64_t append;
    uint64_t background;
    uint64_t backup;
    uint64_t backup_restore_target;
    uint64_t block_allocation;
    uint64_t block_compressor;
    uint64_t block_manager;
    uint64_t bound;
    uint64_t bucket;
    uint64_t bucket_prefix;
    uint64_t buffer_alignment;
    uint64_t builtin_extension_config;
    uint64_t bulk;
    uint64_t cache;
    uint64_t cache_cursors;
    uint64_t cache_directory;
    uint64_t cache_max_wait_ms;
    uint64_t cache_overhead;
    uint64_t cache_resident;
    uint64_t cache_size;
    uint64_t cache_stuck_timeout_ms;
    uint64_t checkpoint;
    uint64_t checkpoint_backup_info;
    uint64_t checkpoint_lsn;
    uint64_t checkpoint_sync;
    uint64_t checkpoint_use_history;
    uint64_t checkpoint_wait;
    uint64_t checksum;
    uint64_t claim_prepared_id;
    uint64_t colgroups;
    uint64_t collator;
    uint64_t columns;
    uint64_t commit_timestamp;
    uint64_t compile_configuration_count;
    uint64_t config;
    uint64_t config_base;
    uint64_t create;
    uint64_t cursors;
    uint64_t dictionary;
    uint64_t direct_io;
    uint64_t do_not_clear_txn_id;
    uint64_t drop;
    uint64_t dryrun;
    uint64_t dump;
    uint64_t dump_address;
    uint64_t dump_all_data;
    uint64_t dump_blocks;
    uint64_t dump_key_data;
    uint64_t dump_layout;
    uint64_t dump_offsets;
    uint64_t dump_pages;
    uint64_t dump_tree_shape;
    uint64_t durable_timestamp;
    uint64_t early_load;
    uint64_t entry;
    uint64_t error_prefix;
    uint64_t eviction_checkpoint_target;
    uint64_t eviction_dirty_target;
    uint64_t eviction_dirty_trigger;
    uint64_t eviction_target;
    uint64_t eviction_trigger;
    uint64_t eviction_updates_target;
    uint64_t eviction_updates_trigger;
    uint64_t exclude;
    uint64_t exclusive;
    uint64_t exclusive_refreshed;
    uint64_t extensions;
    uint64_t extra_diagnostics;
    uint64_t file_extend;
    uint64_t final_flush;
    uint64_t flush_time;
    uint64_t flush_timestamp;
    uint64_t force;
    uint64_t format;
    uint64_t free_space_target;
    uint64_t generation_drain_timeout_ms;
    uint64_t get;
    uint64_t handles;
    uint64_t hazard_max;
    uint64_t huffman_key;
    uint64_t huffman_value;
    uint64_t id;
    uint64_t ignore_cache_size;
    uint64_t ignore_in_memory_cache_size;
    uint64_t ignore_prepare;
    uint64_t immutable;
    uint64_t in_memory;
    uint64_t inclusive;
    uint64_t ingest;
    uint64_t internal_item_max;
    uint64_t internal_key_max;
    uint64_t internal_key_truncate;
    uint64_t internal_page_max;
    uint64_t isolation;
    uint64_t json_output;
    uint64_t key_format;
    uint64_t key_gap;
    uint64_t last;
    uint64_t leaf_item_max;
    uint64_t leaf_key_max;
    uint64_t leaf_page_max;
    uint64_t leaf_value_max;
    uint64_t leak_memory;
    uint64_t lock_wait;
    uint64_t log;
    uint64_t memory_page_image_max;
    uint64_t memory_page_max;
    uint64_t metadata;
    uint64_t mmap;
    uint64_t mmap_all;
    uint64_t multiprocess;
    uint64_t name;
    uint64_t next_random;
    uint64_t next_random_sample_size;
    uint64_t next_random_seed;
    uint64_t no_timestamp;
    uint64_t oldest;
    uint64_t oldest_timestamp;
    uint64_t operation_timeout_ms;
    uint64_t os_cache_dirty_max;
    uint64_t os_cache_max;
    uint64_t overwrite;
    uint64_t prefix_compression;
    uint64_t prefix_compression_min;
    uint64_t prefix_search;
    uint64_t prepare_timestamp;
    uint64_t prepared_id;
    uint64_t preserve_prepared;
    uint64_t priority;
    uint64_t raw;
    uint64_t read_corrupt;
    uint64_t read_once;
    uint64_t read_timestamp;
    uint64_t readonly;
    uint64_t remove_files;
    uint64_t remove_shared;
    uint64_t rollback_timestamp;
    uint64_t run_once;
    uint64_t salvage;
    uint64_t session_max;
    uint64_t session_scratch_max;
    uint64_t session_table_cache;
    uint64_t sessions;
    uint64_t skip_sort_check;
    uint64_t source;
    uint64_t split_deepen_min_child;
    uint64_t split_deepen_per_child;
    uint64_t split_pct;
    uint64_t stable;
    uint64_t stable_timestamp;
    uint64_t statistics;
    uint64_t strict;
    uint64_t sync;
    uint64_t target;
    uint64_t terminate;
    uint64_t threads;
    uint64_t tiered_object;
    uint64_t tiers;
    uint64_t timeout;
    uint64_t timing_stress_for_test;
    uint64_t txn;
    uint64_t type;
    uint64_t use_environment;
    uint64_t use_environment_priv;
    uint64_t use_timestamp;
    uint64_t value_format;
    uint64_t verbose;
    uint64_t verify_metadata;
    uint64_t version;
    uint64_t write_through;
    uint64_t write_timestamp_usage;
} WT_CONF_ID_STRUCTURE = {
  {
    WT_CONF_ID_Assert | (WT_CONF_ID_commit_timestamp << 16),
    WT_CONF_ID_Assert | (WT_CONF_ID_durable_timestamp << 16),
    WT_CONF_ID_Assert | (WT_CONF_ID_read_timestamp << 16),
    WT_CONF_ID_Assert | (WT_CONF_ID_write_timestamp << 16),
  },
  {
    WT_CONF_ID_Block_cache | (WT_CONF_ID_blkcache_eviction_aggression << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_cache_on_checkpoint << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_cache_on_writes << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_full_target << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_hashsize << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_max_percent_overhead << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_nvram_path << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_percent_file_in_dram << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_size << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_system_ram << 16),
    WT_CONF_ID_Block_cache | (WT_CONF_ID_type << 16),
  },
  {
    WT_CONF_ID_Checkpoint | (WT_CONF_ID_log_size << 16),
    WT_CONF_ID_Checkpoint | (WT_CONF_ID_precise << 16),
    WT_CONF_ID_Checkpoint | (WT_CONF_ID_wait << 16),
  },
  {
    WT_CONF_ID_Checkpoint_cleanup | (WT_CONF_ID_file_wait_ms << 16),
    WT_CONF_ID_Checkpoint_cleanup | (WT_CONF_ID_method << 16),
    WT_CONF_ID_Checkpoint_cleanup | (WT_CONF_ID_wait << 16),
  },
  {
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_capacity << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_chunk_cache_evict_trigger << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_chunk_size << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_flushed_data_cache_insertion << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_hashsize << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_pinned << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_storage_path << 16),
    WT_CONF_ID_Chunk_cache | (WT_CONF_ID_type << 16),
  },
  {
    WT_CONF_ID_Compatibility | (WT_CONF_ID_release << 16),
    WT_CONF_ID_Compatibility | (WT_CONF_ID_require_max << 16),
    WT_CONF_ID_Compatibility | (WT_CONF_ID_require_min << 16),
  },
  {
    WT_CONF_ID_Debug | (WT_CONF_ID_checkpoint_fail_before_turtle_update << 16),
    WT_CONF_ID_Debug | (WT_CONF_ID_release_evict_page << 16),
  },
  {
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_background_compact << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_checkpoint_retention << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_configuration << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_corruption_abort << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_cursor_copy << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_cursor_reposition << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_eviction << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_eviction_checkpoint_ts_ordering << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_log_retention << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_page_history << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_realloc_exact << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_realloc_malloc << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_rollback_error << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_slow_checkpoint << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_stress_skiplist << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_table_logging << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_tiered_flush_error_continue << 16),
    WT_CONF_ID_Debug_mode | (WT_CONF_ID_update_restore_evict << 16),
  },
  {
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_checkpoint_id << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_checkpoint_meta << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_flatten_leaf_page_delta << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_internal_page_delta << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_last_materialized_lsn << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_leaf_page_delta << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_lose_all_my_data << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_next_checkpoint_id << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_page_log << 16),
    WT_CONF_ID_Disaggregated | (WT_CONF_ID_role << 16),
  },
  {
    WT_CONF_ID_Encryption | (WT_CONF_ID_keyid << 16),
    WT_CONF_ID_Encryption | (WT_CONF_ID_name << 16),
    WT_CONF_ID_Encryption | (WT_CONF_ID_secretkey << 16),
  },
  {
    WT_CONF_ID_Eviction | (WT_CONF_ID_evict_sample_inmem << 16),
    WT_CONF_ID_Eviction | (WT_CONF_ID_evict_use_softptr << 16),
    WT_CONF_ID_Eviction | (WT_CONF_ID_legacy_page_visit_strategy << 16),
    WT_CONF_ID_Eviction | (WT_CONF_ID_threads_max << 16),
    WT_CONF_ID_Eviction | (WT_CONF_ID_threads_min << 16),
  },
  {
    WT_CONF_ID_File_manager | (WT_CONF_ID_close_handle_minimum << 16),
    WT_CONF_ID_File_manager | (WT_CONF_ID_close_idle_time << 16),
    WT_CONF_ID_File_manager | (WT_CONF_ID_close_scan_interval << 16),
  },
  {
    WT_CONF_ID_Flush_tier | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Flush_tier | (WT_CONF_ID_force << 16),
    WT_CONF_ID_Flush_tier | (WT_CONF_ID_sync << 16),
    WT_CONF_ID_Flush_tier | (WT_CONF_ID_timeout << 16),
  },
  {
    WT_CONF_ID_Hash | (WT_CONF_ID_buckets << 16),
    WT_CONF_ID_Hash | (WT_CONF_ID_dhandle_buckets << 16),
  },
  {
    WT_CONF_ID_Heuristic_controls |
      (WT_CONF_ID_checkpoint_cleanup_obsolete_tw_pages_dirty_max << 16),
    WT_CONF_ID_Heuristic_controls | (WT_CONF_ID_eviction_obsolete_tw_pages_dirty_max << 16),
    WT_CONF_ID_Heuristic_controls | (WT_CONF_ID_obsolete_tw_btree_max << 16),
  },
  {
    WT_CONF_ID_History_store | (WT_CONF_ID_file_max << 16),
  },
  {
    WT_CONF_ID_Import | (WT_CONF_ID_compare_timestamp << 16),
    WT_CONF_ID_Import | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Import | (WT_CONF_ID_file_metadata << 16),
    WT_CONF_ID_Import | (WT_CONF_ID_metadata_file << 16),
    WT_CONF_ID_Import | (WT_CONF_ID_panic_corrupt << 16),
    WT_CONF_ID_Import | (WT_CONF_ID_repair << 16),
  },
  {
    WT_CONF_ID_Incremental | (WT_CONF_ID_consolidate << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_file << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_force_stop << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_granularity << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_src_id << 16),
    WT_CONF_ID_Incremental | (WT_CONF_ID_this_id << 16),
  },
  {
    WT_CONF_ID_Io_capacity | (WT_CONF_ID_chunk_cache << 16),
    WT_CONF_ID_Io_capacity | (WT_CONF_ID_total << 16),
  },
  {
    WT_CONF_ID_Live_restore | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Live_restore | (WT_CONF_ID_path << 16),
    WT_CONF_ID_Live_restore | (WT_CONF_ID_read_size << 16),
    WT_CONF_ID_Live_restore | (WT_CONF_ID_threads_max << 16),
  },
  {
    WT_CONF_ID_Log | (WT_CONF_ID_archive << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_compressor << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_file_max << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_force_write_wait << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_os_cache_dirty_pct << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_path << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_prealloc << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_prealloc_init_count << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_recover << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_remove << 16),
    WT_CONF_ID_Log | (WT_CONF_ID_zero_fill << 16),
  },
  {
    WT_CONF_ID_Operation_tracking | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Operation_tracking | (WT_CONF_ID_path << 16),
  },
  {
    WT_CONF_ID_Prefetch | (WT_CONF_ID_available << 16),
    WT_CONF_ID_Prefetch | (WT_CONF_ID_default << 16),
  },
  {
    WT_CONF_ID_Rollback_to_stable | (WT_CONF_ID_threads << 16),
  },
  {
    WT_CONF_ID_Roundup_timestamps | (WT_CONF_ID_prepared << 16),
    WT_CONF_ID_Roundup_timestamps | (WT_CONF_ID_read << 16),
  },
  {
    WT_CONF_ID_Shared_cache | (WT_CONF_ID_chunk << 16),
    WT_CONF_ID_Shared_cache | (WT_CONF_ID_name << 16),
    WT_CONF_ID_Shared_cache | (WT_CONF_ID_quota << 16),
    WT_CONF_ID_Shared_cache | (WT_CONF_ID_reserve << 16),
    WT_CONF_ID_Shared_cache | (WT_CONF_ID_size << 16),
  },
  {
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_json << 16),
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_on_close << 16),
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_path << 16),
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_sources << 16),
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_timestamp << 16),
    WT_CONF_ID_Statistics_log | (WT_CONF_ID_wait << 16),
  },
  {
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_auth_token << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_bucket << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_bucket_prefix << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_cache_directory << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_interval << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_local_retention << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_name << 16),
    WT_CONF_ID_Tiered_storage | (WT_CONF_ID_shared << 16),
  },
  {
    WT_CONF_ID_Transaction_sync | (WT_CONF_ID_enabled << 16),
    WT_CONF_ID_Transaction_sync | (WT_CONF_ID_method << 16),
  },
  WT_CONF_ID_access_pattern_hint,
  WT_CONF_ID_action,
  WT_CONF_ID_allocation_size,
  WT_CONF_ID_app_metadata,
  WT_CONF_ID_append,
  WT_CONF_ID_background,
  WT_CONF_ID_backup,
  WT_CONF_ID_backup_restore_target,
  WT_CONF_ID_block_allocation,
  WT_CONF_ID_block_compressor,
  WT_CONF_ID_block_manager,
  WT_CONF_ID_bound,
  WT_CONF_ID_bucket,
  WT_CONF_ID_bucket_prefix,
  WT_CONF_ID_buffer_alignment,
  WT_CONF_ID_builtin_extension_config,
  WT_CONF_ID_bulk,
  WT_CONF_ID_cache,
  WT_CONF_ID_cache_cursors,
  WT_CONF_ID_cache_directory,
  WT_CONF_ID_cache_max_wait_ms,
  WT_CONF_ID_cache_overhead,
  WT_CONF_ID_cache_resident,
  WT_CONF_ID_cache_size,
  WT_CONF_ID_cache_stuck_timeout_ms,
  WT_CONF_ID_checkpoint,
  WT_CONF_ID_checkpoint_backup_info,
  WT_CONF_ID_checkpoint_lsn,
  WT_CONF_ID_checkpoint_sync,
  WT_CONF_ID_checkpoint_use_history,
  WT_CONF_ID_checkpoint_wait,
  WT_CONF_ID_checksum,
  WT_CONF_ID_claim_prepared_id,
  WT_CONF_ID_colgroups,
  WT_CONF_ID_collator,
  WT_CONF_ID_columns,
  WT_CONF_ID_commit_timestamp,
  WT_CONF_ID_compile_configuration_count,
  WT_CONF_ID_config,
  WT_CONF_ID_config_base,
  WT_CONF_ID_create,
  WT_CONF_ID_cursors,
  WT_CONF_ID_dictionary,
  WT_CONF_ID_direct_io,
  WT_CONF_ID_do_not_clear_txn_id,
  WT_CONF_ID_drop,
  WT_CONF_ID_dryrun,
  WT_CONF_ID_dump,
  WT_CONF_ID_dump_address,
  WT_CONF_ID_dump_all_data,
  WT_CONF_ID_dump_blocks,
  WT_CONF_ID_dump_key_data,
  WT_CONF_ID_dump_layout,
  WT_CONF_ID_dump_offsets,
  WT_CONF_ID_dump_pages,
  WT_CONF_ID_dump_tree_shape,
  WT_CONF_ID_durable_timestamp,
  WT_CONF_ID_early_load,
  WT_CONF_ID_entry,
  WT_CONF_ID_error_prefix,
  WT_CONF_ID_eviction_checkpoint_target,
  WT_CONF_ID_eviction_dirty_target,
  WT_CONF_ID_eviction_dirty_trigger,
  WT_CONF_ID_eviction_target,
  WT_CONF_ID_eviction_trigger,
  WT_CONF_ID_eviction_updates_target,
  WT_CONF_ID_eviction_updates_trigger,
  WT_CONF_ID_exclude,
  WT_CONF_ID_exclusive,
  WT_CONF_ID_exclusive_refreshed,
  WT_CONF_ID_extensions,
  WT_CONF_ID_extra_diagnostics,
  WT_CONF_ID_file_extend,
  WT_CONF_ID_final_flush,
  WT_CONF_ID_flush_time,
  WT_CONF_ID_flush_timestamp,
  WT_CONF_ID_force,
  WT_CONF_ID_format,
  WT_CONF_ID_free_space_target,
  WT_CONF_ID_generation_drain_timeout_ms,
  WT_CONF_ID_get,
  WT_CONF_ID_handles,
  WT_CONF_ID_hazard_max,
  WT_CONF_ID_huffman_key,
  WT_CONF_ID_huffman_value,
  WT_CONF_ID_id,
  WT_CONF_ID_ignore_cache_size,
  WT_CONF_ID_ignore_in_memory_cache_size,
  WT_CONF_ID_ignore_prepare,
  WT_CONF_ID_immutable,
  WT_CONF_ID_in_memory,
  WT_CONF_ID_inclusive,
  WT_CONF_ID_ingest,
  WT_CONF_ID_internal_item_max,
  WT_CONF_ID_internal_key_max,
  WT_CONF_ID_internal_key_truncate,
  WT_CONF_ID_internal_page_max,
  WT_CONF_ID_isolation,
  WT_CONF_ID_json_output,
  WT_CONF_ID_key_format,
  WT_CONF_ID_key_gap,
  WT_CONF_ID_last,
  WT_CONF_ID_leaf_item_max,
  WT_CONF_ID_leaf_key_max,
  WT_CONF_ID_leaf_page_max,
  WT_CONF_ID_leaf_value_max,
  WT_CONF_ID_leak_memory,
  WT_CONF_ID_lock_wait,
  WT_CONF_ID_log,
  WT_CONF_ID_memory_page_image_max,
  WT_CONF_ID_memory_page_max,
  WT_CONF_ID_metadata,
  WT_CONF_ID_mmap,
  WT_CONF_ID_mmap_all,
  WT_CONF_ID_multiprocess,
  WT_CONF_ID_name,
  WT_CONF_ID_next_random,
  WT_CONF_ID_next_random_sample_size,
  WT_CONF_ID_next_random_seed,
  WT_CONF_ID_no_timestamp,
  WT_CONF_ID_oldest,
  WT_CONF_ID_oldest_timestamp,
  WT_CONF_ID_operation_timeout_ms,
  WT_CONF_ID_os_cache_dirty_max,
  WT_CONF_ID_os_cache_max,
  WT_CONF_ID_overwrite,
  WT_CONF_ID_prefix_compression,
  WT_CONF_ID_prefix_compression_min,
  WT_CONF_ID_prefix_search,
  WT_CONF_ID_prepare_timestamp,
  WT_CONF_ID_prepared_id,
  WT_CONF_ID_preserve_prepared,
  WT_CONF_ID_priority,
  WT_CONF_ID_raw,
  WT_CONF_ID_read_corrupt,
  WT_CONF_ID_read_once,
  WT_CONF_ID_read_timestamp,
  WT_CONF_ID_readonly,
  WT_CONF_ID_remove_files,
  WT_CONF_ID_remove_shared,
  WT_CONF_ID_rollback_timestamp,
  WT_CONF_ID_run_once,
  WT_CONF_ID_salvage,
  WT_CONF_ID_session_max,
  WT_CONF_ID_session_scratch_max,
  WT_CONF_ID_session_table_cache,
  WT_CONF_ID_sessions,
  WT_CONF_ID_skip_sort_check,
  WT_CONF_ID_source,
  WT_CONF_ID_split_deepen_min_child,
  WT_CONF_ID_split_deepen_per_child,
  WT_CONF_ID_split_pct,
  WT_CONF_ID_stable,
  WT_CONF_ID_stable_timestamp,
  WT_CONF_ID_statistics,
  WT_CONF_ID_strict,
  WT_CONF_ID_sync,
  WT_CONF_ID_target,
  WT_CONF_ID_terminate,
  WT_CONF_ID_threads,
  WT_CONF_ID_tiered_object,
  WT_CONF_ID_tiers,
  WT_CONF_ID_timeout,
  WT_CONF_ID_timing_stress_for_test,
  WT_CONF_ID_txn,
  WT_CONF_ID_type,
  WT_CONF_ID_use_environment,
  WT_CONF_ID_use_environment_priv,
  WT_CONF_ID_use_timestamp,
  WT_CONF_ID_value_format,
  WT_CONF_ID_verbose,
  WT_CONF_ID_verify_metadata,
  WT_CONF_ID_version,
  WT_CONF_ID_write_through,
  WT_CONF_ID_write_timestamp_usage,
};
/*
 * Configuration key structure: END
 */
