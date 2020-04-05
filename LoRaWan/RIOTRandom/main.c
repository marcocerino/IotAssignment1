#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef MODULE_SEMTECH_LORAMAC_RX
#include "thread.h"
#include "msg.h"
#endif

#include "shell.h"
#include "semtech_loramac.h"

extern semtech_loramac_t loramac;

#ifdef MODULE_SEMTECH_LORAMAC_RX
#define LORAMAC_RECV_MSG_QUEUE                   (4U)
static msg_t _loramac_recv_queue[LORAMAC_RECV_MSG_QUEUE];
static char _recv_stack[THREAD_STACKSIZE_DEFAULT];

static void *_wait_recv(void *arg)
{
    msg_init_queue(_loramac_recv_queue, LORAMAC_RECV_MSG_QUEUE);

    (void)arg;
    while (1) {
        /* blocks until something is received */
        switch (semtech_loramac_recv(&loramac)) {
            case SEMTECH_LORAMAC_RX_DATA:
                loramac.rx_data.payload[loramac.rx_data.payload_len] = 0;
                printf("Data received: %s, port: %d\n",
                (char *)loramac.rx_data.payload, loramac.rx_data.port);
                break;

            case SEMTECH_LORAMAC_RX_LINK_CHECK:
                printf("Link check information:\n"
                   "  - Demodulation margin: %d\n"
                   "  - Number of gateways: %d\n",
                   loramac.link_chk.demod_margin,
                   loramac.link_chk.nb_gateways);
                break;

            case SEMTECH_LORAMAC_RX_CONFIRMED:
                puts("Received ACK from network");
                break;

            default:
                break;
        }
    }
    return NULL;
}
#endif


//this will generate random number in range l and r
int generate_random(int l, int r) { 
    int rand_num = (rand() % (r - l + 1)) + l;
    return rand_num;
}

//function called when asked to generate values
void gen_val(char* payoff){
    int temp = generate_random(-50,50);
    int hum = generate_random(0,100);
    int win_dir = generate_random(0,360);
    int win_int = generate_random(0,100);
    int rain = generate_random(0,50);

    sprintf(payoff,"{\"Temperature\":%d,\"Humidity\":%d,\"WindDirection\":%d,\"WindIntensity\":%d,\"RainHight\":%d}",temp,hum,win_dir,win_int,rain);

}

static int send(int argc, char**argv)
{
    while (1) {
        /* wait 20 secs */
        xtimer_sleep(20);

        char message[400];
        gen_val(message);

        /* send the LoRaWAN message */
        printf("Sending message: %s\n", message);
        uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message,
                                           strlen(message));
        if (ret != SEMTECH_LORAMAC_TX_DONE) {
            printf("Cannot send message '%s', ret code: %d\n", message, ret);
        }
    }

    (void) argc;
    (void) argv;

    /* this should never be reached */
    return 1;
}


/* loramac shell command handler is implemented in
   sys/shell/commands/sc_loramac.c */

static const shell_command_t shell_commands[] = {
    {"send","send randomly generated data to TTN", send},
    { NULL, NULL, NULL }
};

int main(void)
{
#ifdef MODULE_SEMTECH_LORAMAC_RX
    thread_create(_recv_stack, sizeof(_recv_stack),
                  THREAD_PRIORITY_MAIN - 1, 0, _wait_recv, NULL, "recv thread");
#endif

    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);
}
