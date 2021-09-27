/**
 * Copyright (c) 2014 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 * @defgroup uart_example_main main.c
 * @{
 * @ingroup uart_example
 * @brief UART Example Application main file.
 *
 * This file contains the source code for a sample application using UART.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"
#include "nrf_uart.h"


#define  TX_BUFF_SIZE 128
#define RX_BUFF_SIZE  128

#define  UART_HWFC APP_UART_FLOW_CONTROL_DISABLED


void uart_err_handler(app_uart_evt_type_t *ptr)
{

}
int main(void)
{
uint32_t err_code;
/*err_code =
APP_ERROR_CHECK(err_code);
*/
bsp_board_init(BSP_INIT_LEDS);

uint8_t x ;
#if 0
typedef struct
{
    uint32_t                rx_pin_no;    /**< RX pin number. */
    uint32_t                tx_pin_no;    /**< TX pin number. */
    uint32_t                rts_pin_no;   /**< RTS pin number, only used if flow control is enabled. */
    uint32_t                cts_pin_no;   /**< CTS pin number, only used if flow control is enabled. */
    app_uart_flow_control_t flow_control; /**< Flow control setting, if flow control is used, the system will use low power UART mode, based on CTS signal. */
    bool                    use_parity;   /**< Even parity if TRUE, no parity if FALSE. */
    uint32_t                baud_rate;    /**< Baud rate configuration. */
} app_uart_comm_params_t;
#endif

const app_uart_comm_params_t com_params =
{
RX_PIN_NUMBER,
TX_PIN_NUMBER,
RTS_PIN_NUMBER,
CTS_PIN_NUMBER,
UART_HWFC,
false,
NRF_UART_BAUDRATE_115200
};

APP_UART_FIFO_INIT(&com_params,RX_BUFF_SIZE,TX_BUFF_SIZE,uart_err_handler,APP_IRQ_PRIORITY_LOWEST,err_code);
APP_ERROR_CHECK(err_code);
printf("hello Mohamed Nice job \r\n");

while (1)
{
while(app_uart_get(&x) != NRF_SUCCESS);
if (x == 'n'){
bsp_board_leds_on();
printf("LEDS TURNED ON\r\n");
}

if (x == 'f'){
bsp_board_leds_off();
printf("LEDS TURNED OFF\r\n");
}

}


}


/** @} */
