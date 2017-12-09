#ifndef NVMOS_DL_META_H_
#define NVMOS_DL_META_H_

#define NVMOS_DL_META_FLAG_ISFILE 0x1 // Either file meta or process meta
#define NVMOS_DL_META_FLAG_ISDIR 0x2
#define NVMOS_DL_META_FLAG_FREE 0x4
#define NVMOS_DL_META_FLAG_LOCKED 0x8

#include <stdint.h>
#include <kernel/datalayer/datalayer.h>
#include <kernel/datalayer/file.h>
#include <kernel/datalayer/proc.h>



struct meta_freeMeta
{
	uint64_t nextFreeMeta;
};
typedef struct meta_freeMeta meta_freeMeta_t;

struct meta_meta
{
	uint64_t metaId;
	union {
		file_meta_t fileMeta;
		proc_meta_t processMeta;
		meta_freeMeta_t freeMeta;
	} metaContent;
	uint32_t flags;
};
typedef struct meta_meta meta_meta_t;

#endif