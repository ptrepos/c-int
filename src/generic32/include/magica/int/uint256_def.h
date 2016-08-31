/**
 * Copyright (C) Takuo Hada 2015-2016
 * @author t.hada 2016/07/09
 *
 * 256 bit integer implementation
 */
#pragma once

#include <stdint.h>

#define MG_UINT256_SIZE	(8)
#define MG_UINT256_WORD_BITS	(32)

/**
 * 256bit integer definition for 32bit.
 */
typedef struct mg_uint256
{
	uint32_t word[MG_UINT256_SIZE];
} mg_uint256;
