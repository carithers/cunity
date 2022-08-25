/**
 * @Filename: c_state_machine_rtos.c
 * @Author: c
 * @Date: 2022-08-17
 * @LastEditors: carithers carithers@163.com
 * @LastEditTime: 2022-08-22 14:15:25
 * @Change:
 *        :
 * @Description: 状态机
 * Copyright (c) c, All Rights Reserved.
 */

#include "c_state_machine_rtos.h"

struct st_c_state_machine_rtos_process
{
    void (*fun)(const unsigned int sn);
    unsigned int rt;
    unsigned int rd;
};

typedef struct
{
    struct st_c_state_machine_rtos_process process[C_STATE_MACHINE_RTOS_COUNT];
} st_c_state_machine_rtos_typedef;

static st_c_state_machine_rtos_typedef st_csmr;

/**
 * @description: 初始化状态机数据
 * @return {void}
 */
void csmr_init(void)
{
    int i;
    for(i = 0; i < C_STATE_MACHINE_RTOS_COUNT; i++)
    {
        st_csmr.process[i].fun = 0;
        st_csmr.process[i].rd = 0;
        st_csmr.process[i].rt = 0;
    }
}

/**
 * @description: 跳转到下一下个状态函数
 * @param {unsigned int} sn: 状态机编号
 * @param {unsigned int} delay: 延长多长时间运行下一个状态
 * @param {function} fun: 下一个状态函数
 * @return {void}
 */
void csmr_next(csmr_sn sn, unsigned int delay, void (*fun)(const unsigned int sn))
{
    if(sn < C_STATE_MACHINE_RTOS_COUNT)
    {
        st_csmr.process[sn].fun = fun;
        st_csmr.process[sn].rd = delay;
        st_csmr.process[sn].rt = 0;
    }
}

/**
 * @description: 状态机处理函数, 需要周期性调用
 * @param {unsigned int} sn: 状态机编号
 * @param {unsigned int} ms: 每次运行间隔时间
 * @return {void}
 */
void csmr_process(csmr_sn sn, unsigned int ms)
{
    if(sn < C_STATE_MACHINE_RTOS_COUNT && st_csmr.process[sn].fun)
    {
        if(++st_csmr.process[sn].rt >= st_csmr.process[sn].rd / ms)
        {
            st_csmr.process[sn].rt = 0;
            st_csmr.process[sn].fun(sn);
        }
    }
}



