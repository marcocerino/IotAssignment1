
#include <stdio.h>
#include <stdlib.h>


#include "xtimer.h"
#include "lpsxxx.h"
#include "lpsxxx_params.h"




int main(void)
{

    lpsxxx_t dev;
    printf("Test application for %s pressure sensor\n\n", LPSXXX_SAUL_NAME);
    printf("Initializing %s sensor\n", LPSXXX_SAUL_NAME);
    if (lpsxxx_init(&dev, &lpsxxx_params[0]) != LPSXXX_OK) {
        puts("Initialization failed");
        return 1;
    }
    
    int16_t temp;

    uint16_t pres;

    while (1) {
        lpsxxx_enable(&dev);
        xtimer_sleep(1); /* wait a bit for the measurements to complete */

        lpsxxx_read_temp(&dev, &temp);

        lpsxxx_read_pres(&dev, &pres);

        lpsxxx_disable(&dev);

        int temp_abs = temp / 100;
        temp -= temp_abs * 100;

         printf("Pressure value: %ihPa - Temperature: %2i.%02i°C\n",
               pres, temp_abs, temp);
    }

    return 0;
}