#ifndef __RBUF_H__
#define __RBUF_H__

typedef struct
{
    uint32_t head;
    uint32_t tail;
    void * data_buf;
    uint32_t buf_total_len;
    uint8_t item_size;
}RBUF_t;

typedef enum
{
    RBUF_ERR_OK,
    RBUF_ERR_FULL,
    RBUF_ERR_EMPTY,
}RBUF_ERR_t;

RBUF_t *rbuf_init(void * data_buf, uint32_t buf_len, uint8_t item_size);

#endif
