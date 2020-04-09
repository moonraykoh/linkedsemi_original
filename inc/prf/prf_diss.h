#ifndef PRF_DISS_H_
#define PRF_DISS_H_
#include <stdint.h>

enum diss_evt_type
{
    DIS_SERVER_SET_VALUE_RSP,
    DIS_SERVER_GET_VALUE_IND,
};

struct diss_set_value_rsp_evt
{
    uint8_t value;
    uint8_t status;
};

struct diss_get_value_ind_evt
{
    uint8_t value;
};

union diss_evt_u
{
    struct diss_set_value_rsp_evt set_value_rsp;
    struct diss_get_value_ind_evt get_value_ind;
};

void prf_dis_server_callback_init(void (*cb)(enum diss_evt_type,union diss_evt_u *,uint8_t));

void dev_manager_prf_dis_server_add(uint8_t sec_lvl,uint16_t features);

void prf_diss_set_value_req(uint8_t con_idx,uint8_t value,uint8_t length,uint8_t *data);

void prf_diss_value_confirm(uint8_t con_idx,uint8_t value,uint8_t length,uint8_t *data);


#endif
