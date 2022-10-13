/**
 * @Filename: c_kalman_filter.h
 * @Author: c
 * @Date: 2022-08-26
 * @LastEditors: c
 * @LastEditDate: 2022-08-26
 * @Change: 
 *        : 
 * @Description: 卡尔曼滤波
 * Copyright (c) c, All Rights Reserved. 
 */

#ifndef __C_KALMAN_FILTER_H
#define __C_KALMAN_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
    float r;        /// 系统测量噪声
    float q;        /// 系统过程噪声
    float out;      /// 系统当前预测值和测量值估计的最优状态值
    float kg;       /// 卡尔曼增益
    float p;        /// 这一刻对应的最优协方差
}st_c_kalman_filter_typedef;



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
void c_kalman_filter_init(st_c_kalman_filter_typedef *v, float r, float q, float out, float kg, float p);

/**
 * @description: 卡尔曼滤波计算
 * @param {st_c_kalman_filter_typedef} *v: 卡尔曼滤波变量结构体
 * @param {float} m: 滤波前的值
 * @return {float}: 滤波后的值
 */
float c_kalman_filter(st_c_kalman_filter_typedef *v, float m);


#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT c *****END OF FILE c_kalman_filter.h ****/
