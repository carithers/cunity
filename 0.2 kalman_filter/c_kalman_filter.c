/**
 * @Filename: c_kalman_filter.c
 * @Author: c
 * @Date: 2022-08-26
 * @LastEditors: c carithers@163.com
 * @LastEditDate: 2022-08-26
 * @Change: 
 *        : 
 * @Description: 卡尔曼滤波
 * Copyright (c) c, All Rights Reserved. 
 */

#include "c_kalman_filter.h"

/**
 * @description: 卡尔曼滤波参数初始化
 * @param {st_c_kalman_filter_typedef} *v: 卡尔曼滤波变量结构体
 * @param {float} r: 系统测量噪声
 * @param {float} q: 系统过程噪声
 * @param {float} out: 系统当前预测值和测量值估计的最优状态值
 * @param {float} kg: 卡尔曼增益
 * @param {float} p: 这一刻对应的最优协方差
 * @return {void}
 */
void c_kalman_filter_init(st_c_kalman_filter_typedef *v, float r, float q, float out, float kg, float p)
{
    v->r = r;
    v->q = q;
    v->out = out;
    v->kg = kg;
    v->p = p;
}

/**
 * @description: 卡尔曼滤波计算
 * @param {st_c_kalman_filter_typedef} *v: 卡尔曼滤波变量结构体
 * @param {float} m: 滤波前的值
 * @return {float}: 滤波后的值
 */
float c_kalman_filter(st_c_kalman_filter_typedef *v, float m)
{
    v->p = v->p + v->q;
    v->kg = v->p / (v->p + v->r);
    v->out += v->kg * (m - v->out);
    v->p *= (1 - v->kg);
    
    return v->out;
}


/************************ (C) COPYRIGHT c *****END OF FILE c_kalman_filter.c ****/
