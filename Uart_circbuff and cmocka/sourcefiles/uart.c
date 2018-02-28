/*
 * uart.c
 *
 *  Created on: Oct 28, 2017
 *      Author: Gautham
 */





#include <MKL25Z4.h>                    // Device header
#include <uart.h>
#include <Circular_buffer.h>
#include <stdbool.h>
#include <project2.h>

uint8_t RxData;
uint8_t TxData;
extern state Tx_Status;
extern state Rx_Status;
extern cb_t Rx_Buff;
extern cb_t Tx_Buff;



//uint8_t* ptra = NULL;

void uart_init(void)
{

	uint16_t tmp;
	uart_status Status = 0;


		   SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
		   SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
		   UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
		   SIM->SOPT2 &= ~(SIM_SOPT2_PLLFLLSEL_MASK);
		   SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL(1);
		   SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1);
		   PORTA->PCR[1]= PORT_PCR_MUX(0x2);
		   PORTA->PCR[2]= PORT_PCR_MUX(0x2);
		   tmp = 48000000 / (115200*16);
		   UART0->BDH &= ~UARTLP_BDH_SBR_MASK;
		   UART0->BDH |= UARTLP_BDH_SBR((tmp>>8));
		   UART0->BDL &= ~UARTLP_BDL_SBR_MASK;
		   UART0->BDL |= UARTLP_BDL_SBR(tmp);
		   UART0->C4 = UART0_C4_OSR(15);
		   UART0->S2 = 0x00;
		   UART0->C1 = 0x00;
		   UART0->C3 = 0x00;
		   UART0->C5 = 0x00;
		   UART0->C2 = UART_C2_RIE_MASK;
		   NVIC_EnableIRQ(UART0_IRQn);
		   UART0->C2 |= UARTLP_C2_RE_MASK | UARTLP_C2_TE_MASK;
		   Status= UART_Success;
		   return Status;
		
 }


uart_status send(uint8_t *ch)
{
	uart_status stat;
 
    if(ch!=NULL)
    {
    UART0->D = *ch;
    stat = UART_Success;
    }
    else
    {
    	stat = UART_Null_Error;
    }
    return stat;
	                   
}


uart_status send_n(uint8_t *str,uint8_t length)    
{
	
	UART_Stat stat;
	uint8_t a = 0;
 if(str!=NULL)
 {
	for (a=0; a<length; a++)
	{
		UART0->D = *(str+a);

	}
	stat = UART_Success;
 }
 else
 {
	 stat = UART_Null_Error;
 }
 return stat;
		                   
}





uart_status receive(uint8_t *ptra)
{
	
	UART_Stat stat;
    if(ptra!=NULL)
    {
    *ptra = UART0->D;
    stat = UART_Success;
    }
    else
    {
    stat = UART_Null_Error;
    }
	return stat;

	
}




uart_status receive_n(uint8_t *str,uint8_t length)
{
	UART_Stat stat;
	uint8_t i;
	if(str!= NULL)
	{
	   for(i=0; i<length; i++)
	   {
		   *(str+i)= UART0->D;
	   }
	   stat = UART_Success;
	}
	else
	{
		stat = UART_Null_Error;
	}
	return stat;
}


void UART0_IRQHandler (void)
{
	if(((UART0->S1) & UART0_S1_RDRF_MASK)>>UART0_S1_RDRF_SHIFT == 0x01)
	{
	    receive(&RxData);
	    CB_buffer_add_item(&Rx_Buff, RxData);
	}
	else if( ( ((UART0->S1)&UART0_S1_TDRE_MASK)>>UART0_S1_TDRE_SHIFT) ==0x1)
	{
		Tx_Status = CB_buffer_remove_item(&Tx_Buff, &TxData);
		if(Tx_Status == Success)
	    {
	    	send(&TxData);
	    }
	else
	    {
		UART0->C2 &= ~UART_C2_TIE_MASK;
	    }
	}
	else
	{

	}
}
	

