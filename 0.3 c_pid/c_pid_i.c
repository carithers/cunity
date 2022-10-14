/**
 * @Filename: c_pid_i.c
 * @Author: c
 * @Date: 2022-10-13
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-10-13
 * @Change: 
 *        : 
 * @Description: 增量式pid(incremental pid)
 * Copyright (c) c, All Rights Reserved. 
 */
#include "c_pid_i.h"

/**
 * @description: 增量式PID计算函数
 * @param {st_c_pid_i_typedef} *v: pid结构体
 * @param {float} measure: 测量值
 * @return {float} 增量值
 */
float c_pid_i(st_c_pid_i_typedef *v, float measure)
{
    v->err = v->tv - measure;
    v->out = v->kp * (v->err - v->errl) + \
             v->ki * v->err + \
             v->kd * (v->err - 2 * v->errl + v->errll);
    v->errll = v->errl;
    v->errl = v->err;

    return v->out;
}


/************************ (C) COPYRIGHT c *****END OF FILE c_pid_i.c ****/
