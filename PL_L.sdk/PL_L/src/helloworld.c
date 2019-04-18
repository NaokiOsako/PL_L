#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"

#define REG(address) *(volatile unsigned int*)(address)

#define GPIO_BASE (0x41200000)  /* XPAR_AXI_GPIO_0_BASEADDR */
#define GPIO_DATA (GPIO_BASE + 0x0000)
#define GPIO_TRI  (GPIO_BASE + 0x0004)

int main()
{
    init_platform();

    print("Hello World\n\r");
    int x = 0;

    /* Set all of 4 pins(LEDs) as output */
    REG(GPIO_TRI) = 0x00;
    while(1) {
        /* Set all of 4 pins(LEDs) as High */
        x++;
        /* Set all of 4 pins(LEDs) as Low */
        REG(GPIO_DATA) = x;
        sleep(1);
        if(x==16)
        	x=0;
    }

    cleanup_platform();
    return 0;
}
