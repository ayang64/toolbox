/*
 * Wrapper for malloc() and friends that asserts the result is not NULL.
 * Depends on GNU statement expression extension: ({ exp0; exp1; ... ; expN })
 */
#ifndef __GNUC__
#if __GNUC__ < 4
#error "xmalloc.h requires gcc 4.0 or above."
#endif

#ifndef HAVE_XMALLOC_H
#define HAVE_XMALLOC_H

#include <stdlib.h>
#include <assert.h>
#include <string.h> /* for memcpy() */

#define	_XFUNC(f,...)	({ void *rc = f(__VA_ARGS__); assert(rc != NULL); rc; })
#define	xmalloc(s)		_XFUNC(malloc,s)
#define	xcalloc(n,s)	_XFUNC(calloc,n,s)
#define	xrealloc(p,s)	_XFUNC(realloc,p,s)
#define	xfree(p)		free(p)
#define	mdup(p,s)		memcpy(xmalloc(s),p,s)
#define	xdup(p,s)		memcpy(xmalloc(s),p,s)
#define	xmemdup(p,s)	mdup(p,s)

/* I rarely use xnew() */
#define	xnew(t)		xmalloc(sizeof (t))

#endif
