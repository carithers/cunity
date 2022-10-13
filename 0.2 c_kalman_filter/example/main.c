#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../c_kalman_filter.h"
// #pragma comment (lib,"glib.lib")


int main()
{
    FILE *fp = NULL;
    FILE *fpb = NULL;
	char line[10];

    st_c_kalman_filter_typedef ka;
    c_kalman_filter_init(&ka, 1, 0.0001, 3.3, 0, 3.3);
    // ka.r = 1;
    // ka.q = 0.0001;
    // ka.kg = 0;
    // ka.out = 3.3;
    // ka.p = 3.3;

	if ((fp = fopen("a.csv", "r")) == NULL)
	{
        printf("file open error");
        exit(1);
    }

    if ((fpb = fopen("b.csv", "w+")) == NULL)
	{
        printf("file2 open error");
        exit(1);
    }

    int len = 0, len_cpy;
    while (fgets(line, 10, fp) != NULL)
    {
        len++;
        // printf("%s", line);
    }
    len_cpy = len;
    printf("lines:%d\r\n", len);

    float *df = malloc(sizeof(float) * len);
    float *dfk = malloc(sizeof(float) * len);

    rewind(fp);
    len = 0;
    while (fgets(line, 10, fp) != NULL)
    {

        df[len] = atof(line);
        dfk[len] = c_kalman_filter(&ka, atof(line));
        len++;
    }

    // len = 0;
    // while(len < len_cpy)
    // {
    //     printf("A:%dB:%f\r\n", len, df[len]);
    //     printf("X:%dY:%f\r\n", len, dfk[len]);
    //     len++;
    // }

    len = 0;
    char str[20];
    while(len < len_cpy)
    {
        sprintf(str, "%.3f,%.3f\n", df[len], dfk[len]);
        fwrite(str, 13, 1, fpb);
        len++;
    }




    free(df);
    free(dfk);

    fclose(fp);
    fclose(fpb);
    fp = NULL;
	fpb = NULL;



    return 0;
}





