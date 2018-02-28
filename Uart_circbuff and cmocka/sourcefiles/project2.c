/*
 * project2.c
 *
 *  Created on: Oct 29, 2017
 *  Author: Gautham
 */

#include "project2.h"

statistics dump_sta;
cb_t Rx_Buff;
cb_t Tx_Buff;
extern uint8_t RxData;
extern uint8_t TxData;

state Tx_Status;
state Rx_Status;


char table[] = "\r\n Statistics\t";
char alpha[] = "\r\n Number of Alphabets\t";
char num[]= "\r\n Number of numerics\t\t";
char punct[]= "\r\n Number of punctuations\t";
char others[]= "\r\n Number of Miscellaneous char\t";


uint8_t itoa_cbalpha[itoa_len];

uint8_t itoa_cbnum[itoa_len];

uint8_t itoa_cbpunct[itoa_len];

uint8_t itoa_cbothers[itoa_len];



void project2()
{
	uint8_t data;
	SystemInit();
	uart_init();
	CB_init(&Rx_Buff, rx_cbuf_size );
	CB_init(&Tx_Buff, tx_cbuf_size );


while(1)
{

	Rx_Status = CB_buffer_remove_item(&Rx_Buff, &data);

	if(Rx_Status == success)
	{
		if((data>=48)&&(data<=57))
		{
			(dump_sta.Num)++;
			data=0;
		}
		else if(((data>=65)&&(data<=90))||((data>=97)&&(data<=122)))
		{
			(dump_sta.Alpha)++;
			data=0;
		}
		else if(data==61)
		{
			dump(&dump_sta);
			data=0;
		}
		else if((data==33)||(data=34)||((data==39)&&(data==47)))
		{
			(dump_sta.punct)++;
			data=0;
		}
		else
		{
			(dump_sta.others)++;
			data=0;
		}
	}



}

}

void dump(statistics* stat)
{
	uint32_t a =0;
	uint32_t b =0;
	uint32_t c =0;

	for (a=0; a<sizeof(table); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(table+a));
}
for(b=0; b<sizeof(alpha); (b)++)
{
	CB_buffer_add_item(&Tx_Buff, *(alpha+b));
}

my_itoa((dump_sta.Alpha), itoa_cbalpha, 10);

for (c=0; c<sizeof(itoa_cbalpha); c++)
{
	CB_buffer_add_item(&Tx_Buff, *(itoa_cbalpha+c));
}

for (a=0; a<sizeof(num); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(num+a));
}
my_itoa((dump_sta.num), itoa_cbnum, 10);
for(a=0; a<sizeof(itoa_cbnum); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(itoa_cbnum+a));
}

for(a=0; a<sizeof(punct); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(punct+a));
}
my_itoa((dump_sta.punct), itoa_bufpunct, 10);

for(a=0; a<sizeof(itoa_cbpunct); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(itoa_cbpunct+a));
}

for(a=0; a<sizeof(others);a++)
{
	CB_buffer_add_item(&Tx_Buff, *(others+a));
}
my_itoa(dump_sta.others), itoa_cbothers, 10);
for(a=0; a<sizeof(itoa_cbothers); a++)
{
	CB_buffer_add_item(&Tx_Buff, *(itoa_cbothers+a));
}


dump_sta.Num =0;
dump_sta.Alpha=0;
dump_sta.punct = 0;
dump_sta.others =0;

UART0->C2 |= UART_C2_TIE_MASK;
}

