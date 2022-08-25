/**
 * @Filename: c_state_machine_rtos_cfg.h
 * @Author: c
 * @Date: 2022-08-25
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-08-25
 * @Change: 
 *        : 
 * @Description: 状态机配置文件
 * Copyright (c) c, All Rights Reserved. 
 */


#ifndef __C_STATE_MACHINE_RTOS_CFG_H
#define __C_STATE_MACHINE_RTOS_CFG_H

#ifdef __cplusplus
extern "C" {
#endif


/// 需要用到状态线的数量
#define C_STATE_MACHINE_RTOS_COUNT          5

/// 状态机线程编号选择,每个只能使用一次, 切只能选择比数量(C_STATE_MACHINE_RTOS_COUNT)值小的数
typedef enum {
    csmr_sn0 = 0,
    csmr_sn1,
    csmr_sn2,
    csmr_sn3,
    csmr_sn4,
}csmr_sn;



#ifdef __cplusplus
}
#endif

#endif


/************************ (C) COPYRIGHT c *****END OF FILE c_state_machine_rtos_cfg.h ****/
