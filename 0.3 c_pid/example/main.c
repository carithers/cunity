#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../c_pid_p.h"
// #pragma comment (lib,"glib.lib")

st_c_pid_p_typedef st_pidp = {
    .tv = 100,
    .kp = 0.4,
    .ki = 0.4,
    .kd = 0.1,
};

int main(void)
{
    printf("%f, %f, %f, %f\r\n", st_pidp.tv, st_pidp.kp, st_pidp.ki, st_pidp.kd);
    float m = 0;
    while(1)
    {
        Sleep(100);
        printf("value: %f; err: %f; inter: %f \r\n", m, st_pidp.err, st_pidp.integral);
        m = c_pid_p(&st_pidp, m);
    }

    return 0;
}





