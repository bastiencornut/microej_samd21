/* 
 * Copyright 2008-2016 IS2T. All rights reserved.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
/* 
 * AUTOGENERATED by COMP-ICETEA-CGNU-ARM - 1.0.0 - DO NOT EDIT IT
 */
/**
 * General purpose bestfit allocator, 32 bits oriented,
 * Allowed to work in a continuous interval of ram [startAddress, endAddress[
 */
#ifndef _BESTFIT_ALLOCATOR
#define _BESTFIT_ALLOCATOR 
#include <intern/BESTFIT_ALLOCATOR.h>
#include <stdint.h>
#ifdef __cplusplus
	extern "C" {
#endif

/**
 * Default Constructor
 */
void BESTFIT_ALLOCATOR_new(BESTFIT_ALLOCATOR* env);

// --------------------------------------------------------------------------------
// -                      Functions provided by the platform                      -
// --------------------------------------------------------------------------------

/**
 * Initializes this allocator to work within the given memory space.
 * This function must be called once and prior to any other calls.
 * @param startAddress memory start address.
 * @param endAddress memory end address (excluded).
 */
void BESTFIT_ALLOCATOR_initialize(BESTFIT_ALLOCATOR* env, int32_t startAddress, int32_t endAddress);

/**
 * Allocates a new block. 
 * @param size the block size in bytes. If size is lower than of equals 0, returns an empty block.
 * @return the address of the allocated block or <code>null<code> if out of memory
 */
void* BESTFIT_ALLOCATOR_allocate(BESTFIT_ALLOCATOR* env, int32_t size);

/**
 * Releases a block that has been previously allocated using {@link BESTFIT_ALLOCATOR_allocate}.
 * @param the address of the block to release
 */
void BESTFIT_ALLOCATOR_free(BESTFIT_ALLOCATOR* env, void* block);

#ifdef __cplusplus
	}
#endif
#endif
