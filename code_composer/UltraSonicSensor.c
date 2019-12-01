#include "msp.h"
#include "delay.h"
#include <math.h>
#include "UltraSonicSensor.h"



/* P2.5 - output (trig)
 * P7.3 - input(TA0.CCI0A) (echo)
 * P2.4 - input(TA0.ccI1A) (echo)
 */
void init_ECHO(){
   // step 1 - init CCI0A
    P7->SEL0 |= BIT3;
    P7->SEL1 &= ~BIT3;
    // step 2 - init CCI1A
    P2->SEL0 |= BIT4;
    P2->SEL1 &= ~BIT4;
}
void init_TRIGGER(){
    // Step 1 - init gpio
    P2->SEL0 &= ~TRIG;
    P2->SEL1 &= ~TRIG;
    P2->DIR |= TRIG;
    P2->OUT &= TRIG; // init low
}
void init_UltraSonicSensor(){
     init_TA0();
     set_DCO(F_INPUT/pow(10, 6)); // 3mhz
     set_clk("SMCLK");
     init_ECHO();
     init_TRIGGER();
     overflows = 0;
     got_value = 0;
}

void send_trigger(){
    P2->OUT|= TRIG;
    delay_us(0);
    P2->OUT&=~ TRIG;
}


uint16_t get_time_high(){

    uint16_t diff = abs(rising_edge_counter - falling_edge_counter);

    return diff/(F_INPUT/pow(10,6));
}

double get_distance_cm()
{
    // Step 1 - keep sending till value is valid
    while(got_value == 0){
        send_trigger();
        delay_us(5000);
    }

  uint16_t time_high = get_time_high();
  float distance = time_high*.01751 -.207;
  reset_TimerA();

  return distance;

}
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void linearSort(float *arr, int size)
{
    int i, j;
    for(i = 0; i < size-1; i++)
        for(j = 0; j < size - 1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


double get_distance_cm_max(){
    const int SIZE = 10;
    int i;
    float arr[SIZE];
    for (i = 0; i<SIZE; i++)
    {
        arr[i] = get_distance_cm();
    }
    linearSort(arr, SIZE);
    for (i = 0; i < SIZE-1; i ++)
        if (arr[i] > 1 && abs(arr[i] - arr[i+1]) < 2)
            return arr[i];

    return get_max(arr, SIZE);
}



double get_max(float *arr, int size){
    if (size == 1){
        return arr[0];
    }
    return new_max(arr[0], get_max(arr+1, size-1));
}

void init_TA0(){

        TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK | // SMCLK, continuous mode
                        TIMER_A_CTL_MC__CONTINUOUS|
                        TIMER_A_CTL_TASSEL_2 | //SMCLK
                        TIMER_A_CTL_IE; // enable TAxR overflow

        TIMER_A0->CCTL[0] = TIMER_A_CCTLN_CM_1 | //Trigger on rising edge
                            TIMER_A_CCTLN_CCIS_0 | //select CCIxA
                            TIMER_A_CCTLN_CCIE | //enable interrupt
                            TIMER_A_CCTLN_CAP | // capture mode
                            TIMER_A_CCTLN_SCS; //synchronous

        TIMER_A0->CCTL[1] = TIMER_A_CCTLN_CM_2 | //Trigger on rising falling edge
                            TIMER_A_CCTLN_CCIS_0 | //select CCIxA
                            TIMER_A_CCTLN_CCIE | //enable interrupt
                            TIMER_A_CCTLN_CAP | // capture mode
                            TIMER_A_CCTLN_SCS; //synchronous


        NVIC->ISER[0] = 1 << ((TA0_N_IRQn) & 31);
        NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);
}

// Description: for ccr1 handler and r overflow
void TA0_N_IRQHandler(){
    // Step 1 - check to see the interrupt is from ccr
    if (TIMER_A0->CCTL[1] & TIMER_A_CCTLN_CCIFG){
        if (TIMER_A0->CCTL[0]& COV){
           reset_TimerA();
        }else{
            falling_edge_counter = TIMER_A0->CCR[1] + overflows*TIMER_A_MAX;
            got_value = 1;
            disable_ISR_TIMERA();
        }
    // Step 2 - else its from overflow
    }else{
        overflows++;
        TIMER_A0->CTL &= ~TIMER_A_CTL_IFG; // clear interrupt flag
    }
}
//description: for ccr0 handler and r overflow
void TA0_0_IRQHandler(){
    // Step 1 - check to see the interrupt is from ccr
    rising_edge_counter = TIMER_A0->CCR[0];
}

void enable_ISR_TIMERA(){
    TIMER_A0->CTL |=TIMER_A_CTL_IE; // enable TAxR overflow
    TIMER_A0->CCTL[0] |= TIMER_A_CCTLN_CCIE; //enable interrupt
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_CCIE; //enable interrupt
}
void disable_ISR_TIMERA(){
    TIMER_A0->CTL &=~TIMER_A_CTL_IE; // enable TAxR overflow
    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIE; //enable interrupt
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIE; //enable interrupt
}
void reset_TimerA(){
    overflows=0;
    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_COV;
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
    overflows=0;
    TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG;
    got_value = 0;
    enable_ISR_TIMERA();
}
