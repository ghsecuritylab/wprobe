/*
 * ustream-ssl - library for SSL over ustream
 *
 * Copyright (C) 2012 Felix Fietkau <nbd@openwrt.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
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

#ifndef __USTREAM_POLARSSL_H
#define __USTREAM_POLARSSL_H

#include <polarssl/net.h>
#include <polarssl/ssl.h>
#include <polarssl/certs.h>
#include <polarssl/x509.h>
#include <polarssl/rsa.h>
#include <polarssl/error.h>

struct ustream_polarssl_ctx {
	x509_cert cert;
	rsa_context key;
	bool server;
};

static inline char *__ustream_ssl_strerror(int error, char *buffer, int len)
{
	error_strerror(error, buffer, len);
	return buffer;
}

void __ustream_ssl_session_free(void *ssl);
void *__ustream_ssl_session_new(void *ctx);

#endif
