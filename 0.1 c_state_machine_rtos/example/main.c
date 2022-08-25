/*
 * @Filename: main.c
 * @Author: c
 * @Date: 2022-08-18
 * @LastEditors: c
 * @LastEditDate: 2022-08-18
 * @Change: 
 *        : 
 * @Description: 使用于rtos的状态机或延时历程
 * Copyright (c) c, All Rights Reserved. 
 */

#include <stdio.h>
#include <Windows.h>
#include "../c_state_machine_rtos.h"



int contactor_check_n_flg = 0;
int contactor_check_flg = 0;

void contactor_check_p(const unsigned int sn);
void contactor_check_n(const unsigned int sn);

void contactor_check_n(const unsigned int sn)
{
    printf("contactor_check_n\r\n");
    if(contactor_check_n_flg > 0)
    {
        csmr_next(0, 3000, contactor_check_p);
    }
    else
    {
        csmr_next(0, 200, contactor_check_n);
    }
}

void contactor_check_p(const unsigned int sn)
{
    printf("contactor_check_p\r\n");
    if(contactor_check_flg > 0)
    {
        csmr_next(sn, 3000, contactor_check_n);
    }
    else
    {
        csmr_next(sn, 200, contactor_check_p);
    }
}

void contactor_init(void)
{
    csmr_next(csmr_sn0, 0, contactor_check_p);
}

int main(void)
{
    int temp = 0;
    contactor_init();
    while(1)
    {
        temp = temp + 1;
        if(temp++ > 1000)
            contactor_check_flg = 1;
        Sleep(10);
        csmr_process(csmr_sn0, 10);

        printf("run-%d", contactor_check_flg);
    }
}

/************************ (C) COPYRIGHT c *****END OF FILE main.c ****/
