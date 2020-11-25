#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "round_buffer.h"

RBUF_t *rbuf_init(void *data_buf, uint32_t buf_len, uint8_t item_size)
{
    RBUF_t * prbuf = malloc(sizeof(RBUF_t));

    if(prbuf != NULL)
    {
        prbuf->buf_total_len = buf_len;
        prbuf->head = prbuf->tail = 0;
        prbuf->data_buf = data_buf;
    }

    return prbuf;
}

void rbuf_delete(RBUF_t *prbuf)
{
    if(prbuf != NULL)
    {
        free(prbuf);
    }
}

RBUF_ERR_t rbuf_put(RBUF_t *prbuf, void *item)
{
    if(prbuf->head == prbuf->tail)
    {
        return RBUF_ERR_FULL;
    }

    memcpy(prbuf->data_buf + prbuf->head*prbuf->item_size, item, prbuf->item_size);

    prbuf->head++;

    if(prbuf->head == prbuf->buf_total_len)
    {
        prbuf->head = 0;
    }

    return RBUF_ERR_OK;
}

RBUF_ERR_t rbuf_get(RBUF_t *prbuf, void * dest)
{
    if(prbuf->tail == prbuf->head)
    {
        return RBUF_ERR_EMPTY;
    }

    memcpy(dest, prbuf->data_buf + prbuf->tail*prbuf->item_size, prbuf->item_size);

    prbuf->tail++;

    if(prbuf->tail == prbuf->buf_total_len)
    {
        prbuf->tail = 0;
    }

    return RBUF_ERR_OK;

}
