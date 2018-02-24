/* =============================================================================
 * Pure64 -- a 64-bit OS/software loader written in Assembly for x86-64 systems
 * Copyright (C) 2008-2017 Return Infinity -- see LICENSE.TXT
 * =============================================================================
 */

#ifndef PURE64_DAP_H
#define PURE64_DAP_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct pure64_stream;

/** This structure is used by the
 * boot sector to determine where
 * to load the 2nd and 3rd stage
 * boot loaders. The acronym DAP
 * stands for disk address packet.
 * */

struct pure64_dap {
	/** Reserved for use by the boot sector. */
	uint8_t reserved[2];
	/** The number of sectors occupied by the boot loader. */
	uint16_t sector_count;
	/** The address to load the boot loader at. */
	uint16_t address;
	/** The segment to load the boot loader at. */
	uint16_t segment;
	/** The sector that contains the boot loader. */
	uint64_t sector;
};

/** Read the disk address packet from a stream.
 * @param dap A disk address packet structure.
 * @param stream The stream to read the data from.
 * @returns Zero on success, an error code on failure.
 * */

int pure64_dap_read(struct pure64_dap *dap, struct pure64_stream *stream);

/** Write the disk address packet to a stream.
 * @param dap A disk address packet structure.
 * @param stream The stream to wrote the data to.
 * @returns Zero on success, an error code on failure.
 * */

int pure64_dap_write(const struct pure64_dap *dap, struct pure64_stream *stream);

#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* PURE64_DAP_H */
