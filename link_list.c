/**
* @file        link_list.c
* @brief       link list module implementation.
* @author      Cencong
* @date        2020/11/11
* @version     0.2046.1
* @Copyright(c):	hey@cencongs.com
*/

#include <stdlib.h>
#include "error.h"
#include "link_list.h"

ERROR_CODE_t ll_insert(ll *entry, ll *before, ll *after)
{
    if (!entry || !before || !after)
    {
        return ERROR_Fail;
    }

    before->next = entry;
    after->prev = entry;
    entry->next = after;
    entry->prev = before;

    return ERROR_Ok;
}

ERROR_CODE_t ll_delete(ll *entry)
{
    if (!entry)
    {
        return ERROR_Fail;
    }

    if (entry->next && entry->prev)
    {
        entry->next->prev = entry->prev;
        entry->prev->next = entry->next;
    }

    entry->prev = NULL;
    entry->next = NULL;

    return ERROR_Ok;
}

int ll_count(ll *l)
{
    if (!l)
    {
        return 0;
    }

    int count = 0;

    ll *lp = NULL;
    ll_foreach_noit(l, lp)
    {
        count++;
    }

    return count;
}

bool ll_is_linked(ll *l, ll *entry)
{
    ll *lp = NULL;
    ll_foreach_noit(l, lp)
    {
        if (lp == entry)
        {
            return true;
        }
    }

    return false;
}

void ll_deinit(ll *l)
{
    ll *lp = ll_get_head(l);

    while (lp) {
        ll_delete(lp);
        lp = ll_get_head(l);
    }

    l->next = NULL;
    l->prev = NULL;
}

void main()
{
}
