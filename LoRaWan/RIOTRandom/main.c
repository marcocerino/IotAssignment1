
#include <string.h>

#include "xtimer.h"

#include "net/loramac.h"
#include "semtech_loramac.h"

#include "board.h"



//this will generate random number in range l and r
int generate_random(int l, int r) { 
    int rand_num = (rand() % (r - l + 1)) + l;
    return rand_num;
}

//function called when asked to generate values
void gen_val(char** payoff){
    int temp = generate_random(-50,50);
    int hum = generate_random(0,100);
    int win_dir = generate_random(0,360);
    int win_int = generate_random(0,100);
    int rain = generate_random(0,50);

    sprintf(payoff[0],"{\"Temperature\":%d}",temp);
    sprintf(payoff[1],"{\"Humidity\":%d}",hum);
    sprintf(payoff[2],"{\"WindDirection\":%d}",win_dir);
    sprintf(payoff[3],"{\"WindIntensity\":%d}",win_int);
    sprintf(payoff[4],"{\"RainHeight\":%d}",rain);

}

/* Declare globally the loramac descriptor */
semtech_loramac_t loramac;


//need to change the EUIs and the key to your TTN device's ones
/* Device and application informations required for OTAA activation */
static const uint8_t deveui[LORAMAC_DEVEUI_LEN] = { 0x00, 0x81, 0xF9, 0x8E, 0xA7, 0xF8, 0x22, 0x23 };
static const uint8_t appeui[LORAMAC_APPEUI_LEN] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x02, 0xD4, 0xC0 };
static const uint8_t appkey[LORAMAC_APPKEY_LEN] = { 0xB0, 0xEA, 0x13, 0xFC, 0x3F, 0xF2, 0x91, 0x5E, 0x67, 0xC1, 0x74, 0x3E, 0xDF, 0xFC, 0x50, 0x57 };


int main(void)
{
    /* The  message to send */
    char* message[5];
    for(int i=0; i<5; i++){
        message[i] = (char*) malloc(sizeof(char)*50);
    }


    /* initialize the loramac stack */
    semtech_loramac_init(&loramac);

    /* use a fast datarate so we don't use the physical layer too much */
    semtech_loramac_set_dr(&loramac, 5);

    /* set the LoRaWAN keys */
    semtech_loramac_set_deveui(&loramac, deveui);
    semtech_loramac_set_appeui(&loramac, appeui);
    semtech_loramac_set_appkey(&loramac, appkey);

    /* start the OTAA join procedure */
    puts("Starting join procedure");
    if (semtech_loramac_join(&loramac, LORAMAC_JOIN_OTAA) != SEMTECH_LORAMAC_JOIN_SUCCEEDED) {
        puts("Join procedure failed");
        return 1;
    }

    puts("Join procedure succeeded");

    
    
    while (1) {
        /* wait 20 secs */
        xtimer_sleep(5);

        gen_val(message);

        /* send the LoRaWAN messages */
        int j;
        
        for(j=0; j<2; j++){
            printf("Sending message: %s\n", message[j]);
            uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message[j],
                                                       strlen(message[j]));
            if (ret != SEMTECH_LORAMAC_TX_DONE) {
                    printf("Cannot send message '%s', ret code: %d\n", message[j], ret);
            }
        }

        //wait to avoid err code 13
        xtimer_sleep(5);

        for(j=2; j<4; j++){
            printf("Sending message: %s\n", message[j]);
            uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message[j],
                                               strlen(message[j]));
            if (ret != SEMTECH_LORAMAC_TX_DONE) {
                printf("Cannot send message '%s', ret code: %d\n", message[j], ret);
            }
        }


        //wait to avoid err code 13
        xtimer_sleep(5);

        //j==4
        printf("Sending message: %s\n", message[4]);
        uint8_t ret = semtech_loramac_send(&loramac, (uint8_t *)message[4],
                                               strlen(message[4]));
        if (ret != SEMTECH_LORAMAC_TX_DONE) {
            printf("Cannot send message '%s', ret code: %d\n", message[4], ret);
        }
            
    }

    return 0; /* should never be reached */
}