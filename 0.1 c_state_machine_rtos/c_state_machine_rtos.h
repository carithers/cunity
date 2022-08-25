/**
 * @Filename: c_state_machine_rtos.h
 * @Author: c
 * @Date: 2022-08-19
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-08-19
 * @Change:
 *        :
 * @Description:
 * Copyright (c) c, All Rights Reserved.
 */

#ifndef __C_STATE_MACHINE_RTOS_H
#define __C_STATE_MACHINE_RTOS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "c_state_machine_rtos_cfg.h"


/**
 * @description: 跳转到下一下个状态函数
 * @param {unsigned int} sn: 状态机编号
 * @param {unsigned int} delay: 延长多长时间运行下一个状态
 * @param {function} fun: 下一个状态函数
 * @return {void}
 */
void csmr_next(csmr_sn sn, unsigned int delay, void (*fun)(const unsigned int sn));

/**
 * @description: 状态机处理函数, 需要周期性调用
 * @param {unsigned int} sn: 状态机编号
 * @param {unsigned int} ms: 每次运行间隔时间
 * @return {void}
 */
void csmr_process(csmr_sn sn, unsigned int ms);



#ifdef __cplusplus
}
#endif

#endif


/************************ (C) COPYRIGHT c *****END OF FILE c_state_machine_rtos.h ****/
