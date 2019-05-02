#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>
#ifndef __cplusplus
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#else
#ifndef __bool_true_false_are_defined
#define bool  int
#define true  1
#define false 0
#define __bool_true_false_are_defined 1
#endif /* __bool_true_false_are_defined */
#endif /* defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L */
#endif /* __cplusplus */

typedef struct {
	size_t size;
	size_t capacity;
	int *data;
} vector_t;

#ifdef __cplusplus
extern "C" {
#endif
bool   vector_init          (vector_t*, size_t)
size_t vector_size          (vector_t*)
size_t vector_capacity      (vector_t*)
bool   vector_empty         (vector_t*)
int*   vector_begin         (vector_t*)
int*   vector_end           (vector_t*)
int    vector_front         (vector_t*)
int    vector_back          (vector_t*)
int    vector_at            (vector_t*, ssize_t)
void   vector_clear         (vector_t*)
void   vector_swap          (vector_t*, vector_t*)
bool   vector_reserve       (vector_t*, size_t)
bool   vector_shrink_to_fit (vector_t*)
bool   vector_resize        (vector_t*, size_t)
bool   vector_push_back     (vector_t*, int)
int    vector_pop_back      (vector_t*)
bool   vector_assign        (vector_t*, size_t, int)
#ifdef __cplusplus
}
#endif

#endif /* __VECTOR_H__ */
