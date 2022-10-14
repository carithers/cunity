/**
 * @Filename: c_pid_p.c
 * @Author: c
 * @Date: 2022-10-13
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-10-13
 * @Change: 
 *        : 
 * @Description: 位置pid(position PID)
 * Copyright (c) c, All Rights Reserved. 
 */

#include "c_pid_p.h"

/**
 * @description: 位置式PID计算函数
 * @param {st_c_pid_p_typedef} *v: 位置式PID结构体
 * @param {float} measure: 测量值
 * @return {float} 控制值
 */
float c_pid_p(st_c_pid_p_typedef *v, float measure)
{
    v->err = v->tv - measure;
    v->integral += v->err;
    v->out = v->kp * v->err + \
             v->ki * v->integral + \
             v->kd * (v->err - v->errl);
    v->errl = v->err;
    return v->out;
}


/************************ (C) COPYRIGHT c *****END OF FILE c_pid_p.c ****/
