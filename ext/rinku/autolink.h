/*
 * Copyright (c) 2016, GitHub, Inc
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef RINKU_AUTOLINK_H
#define RINKU_AUTOLINK_H

#include <stdbool.h>
#include <stdint.h>
#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
	AUTOLINK_SHORT_DOMAINS = (1 << 0),
};

struct autolink_pos {
	size_t start;
	size_t end;
};

struct autolink_ctx {
	unsigned int flags;
	const char **schemes;
};

bool
autolink_issafe(const uint8_t *link, size_t link_len, const char **schemes);

bool
autolink__www(struct autolink_pos *res,
	const uint8_t *data, size_t pos, size_t size, const struct autolink_ctx *ctx);

bool
autolink__email(struct autolink_pos *res,
	const uint8_t *data, size_t pos, size_t size, const struct autolink_ctx *ctx);

bool
autolink__url(struct autolink_pos *res,
	const uint8_t *data, size_t pos, size_t size, const struct autolink_ctx *ctx);

#ifdef __cplusplus
}
#endif

#endif

/* vim: set filetype=c: */
