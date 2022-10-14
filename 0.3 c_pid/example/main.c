#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../c_pid_p.h"
#include "../c_pid_i.h"
// #pragma comment (lib,"glib.lib")

st_c_pid_p_typedef st_pidp = {
    .tv = 100,
    .kp = 0.4,
    .ki = 0.4,
    .kd = 0.1,
};

st_c_pid_i_typedef st_pidi = {
    .tv = 100,
    .kp = 0.4,
    .ki = 0.4,
    .kd = 0.1,
    .err = 0,
    .errl = 0,
    .errll = 0,
};

int main(void)
{
    float m = 0;
    float ma = 0;

    while(1)
    {
        Sleep(100);
        printf("value: %f; err: %f; inter: %f, ma:%f \r\n", m, st_pidi.err, st_pidi.out, ma);
        m += c_pid_i(&st_pidi, m);
    }

    while(1)
    {
        Sleep(100);
        printf("value: %f; err: %f; inter: %f \r\n", m, st_pidp.err, st_pidp.integral);
        m = c_pid_p(&st_pidp, m);
    }

    return 0;
}





