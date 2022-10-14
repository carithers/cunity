/**
 * @Filename: c_pid_i.h
 * @Author: c
 * @Date: 2022-10-13
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-10-13
 * @Change: 
 *        : 
 * @Description: 增量式PID(incremental pid)
 * Copyright (c) c, All Rights Reserved. 
 */
#ifndef __C_PID_I_H
#define __C_PID_I_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float tv; /// target value 目标值
    float kp;
    float ki;
    float kd;
    float err;
    float errl; /// error last上次误差值
    float errll; /// error last上次误差值
    float out;
}st_c_pid_i_typedef;


float c_pid_i(st_c_pid_i_typedef *v, float measure);

#ifdef __cplusplus
}
#endif

#endif



/************************ (C) COPYRIGHT c *****END OF FILE c_pid_i.h ****/
