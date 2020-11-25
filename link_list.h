/* ---------------------------------------------------------------------------- */
/* Copyright 2020 NXP.                                                          */
/*                                                                              */
/* This software is owned or controlled by NXP and may only be used strictly    */
/* in accordance with the applicable license terms. By expressly accepting such */
/* terms or by downloading, installing, activating and/or otherwise using the   */
/* software, you are agreeing that you have read, and that you agree to comply  */
/* with and are bound by, such license terms. If you do not agree to be bound   */
/* by the applicable license terms, then you may not retain, install, activate  */
/* or otherwise use the software.                                               */
/* ---------------------------------------------------------------------------- */

#ifndef LL_H_
#define LL_H_

#include <stdbool.h>
#include <stdlib.h>

#include "error.h"

#define __UID2(__a, __b)  __a ## __b
#define __UID1(__a, __b)  __UID2(__a, __b)
#define __UID  __UID1(__it__, __LINE__)

#define ll_foreach_noit(__l, __lp)                                                                \
    __typeof__(__lp)UID;                                                                            \
    for (__lp = (__l)->next; UID = __lp ? __lp->next : NULL, __lp && (__lp != (__l)); __lp = UID)

#define ll_foreach(__l, __lp)                                                                     \
    __typeof__(__lp)UID;                                                                            \
    for (__lp = (__typeof__(__lp))((__l)->next);                                                    \
         UID = __lp ? (__typeof__(__lp))(((ll *)(__lp))->next) : NULL, __lp && ((ll *)__lp != (__l)); __lp = UID)

/**
 * Linked-list base structure.
 */
typedef struct _ll {
    struct _ll *next; /**< Next member. */
    struct _ll *prev; /**< Previous member. */
} ll;

static inline void ll_init(ll *l)
{
    l->next = l;
    l->prev = l;
}

static inline bool ll_is_empty(ll *l)
{
    return l->next == l;
}

ERROR_CODE_t ll_insert(ll *entry, ll *before, ll *after);

static inline ERROR_CODE_t ll_push_head(ll *l, ll *entry)
{
    return ll_insert(entry, l, l->next);
}

static inline ERROR_CODE_t ll_push_tail(ll *l, ll *entry)
{
    return ll_insert(entry, l->prev, l);
}

static inline bool ll_is_tail(ll *l, ll *entry)
{
    return(entry->next == l);
}

static inline ll *ll_get_head(ll *l)
{
    if (ll_is_empty(l)) {
        return NULL;
    }

    return l->next;
}

ERROR_CODE_t ll_delete(ll *entry);
int ll_count(ll *l);
bool ll_is_linked(ll *l, ll *entry);
void ll_deinit(ll *l);

#endif /* LL_H_ */
