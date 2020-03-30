
#include <stdio.h>
#include <stdlib.h>


#include "shell.h"
#include "xtimer.h"
#include "lpsxxx.h"
#include "lpsxxx_params.h"


int16_t temp;

uint16_t pres;

void get_val(char*payoff)
{
     sprintf(payoff,"{\"Temperature\":%2i.%02i,\"Humidity\":%i}",temp,pres);
}


int sens(int argc, char**argv)
{

    lpsxxx_t dev;
    printf("Test application for %s pressure sensor\n\n", LPSXXX_SAUL_NAME);
    printf("Initializing %s sensor\n", LPSXXX_SAUL_NAME);
    if (lpsxxx_init(&dev, &lpsxxx_params[0]) != LPSXXX_OK) {
        puts("Initialization failed");
        return 1;
    }
    

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

    (void)argc;
    (void)argv;

    return 0;
}

static const shell_command_t shell_commands[] = {
    {"sens","get values from sensors",sens},
    { NULL, NULL, NULL }
};

int main(void){

    /* start shell */
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    /* should be never reached */
    return 0;
}
