/**
 * @Filename: c_pid_p.h
 * @Author: c
 * @Date: 2022-10-13
 * @LastEditors: carithers carithers@163.com
 * @LastEditDate: 2022-10-13
 * @Change: 
 *        : 
 * @Description: 位置pid(position pid)
 * Copyright (c) c, All Rights Reserved. 
 */

#ifndef __C_PID_P_H
#define __C_PID_P_H

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
    float integral;  /// 积分值
    float out;
}st_c_pid_p_typedef;


/**
 * @description: 位置式PID计算函数
 * @param {st_c_pid_p_typedef} *v: 位置式PID结构体
 * @param {float} measure: 测量值
 * @return {float} 控制值
 */
float c_pid_p(st_c_pid_p_typedef *v, float measure);

#ifdef __cplusplus
}
#endif

#endif


/************************ (C) COPYRIGHT c *****END OF FILE c_pid_p.h ****/
