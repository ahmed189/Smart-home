/*Notes
 * Don't forget to make mosi & c/k as outputs
 */

#include "../MCAL/SPI/SPI_CONF.h"
#include "../libraries_/Typedefs.h"
#include "../libraries_/BIT_Manepulation.h"



void SPI_Init(void)
{
        /*Enable or disable SPI*/
        if(SPI_Group.Enable == SPI_Enable_ON)
            SET_BIT(SPCR,SPE);
        else if(SPI_Group.Enable == SPI_Enable_OFF)
            CLEAR_BIT(SPCR,SPE);

        /*SPI Master or slave*/
        if(SPI_Group.Type == SPI_Master)
            SET_BIT(SPCR,MSTR);
        else if(SPI_Group.Type == SPI_Slave)
            CLEAR_BIT(SPCR,MSTR);

		/*Enable or disable SPI interrupt*/
		if(SPI_Group.Enable_Interrupt == SPI_INTERRUPT_ON)
			SET_BIT(SPCR,SPIE);
		else if(SPI_Group.Enable_Interrupt == SPI_INTERRUPT_OFF)
			CLEAR_BIT(SPCR,SPIE);
		
		
        /*SPI Mode CPOL -> Rising or Falling clock polarity
                CPHA -> Rising or Falling clock edge    */
        if(SPI_Group.Mode == SPI_Mode0)
        {
                CLEAR_BIT(SPCR,CPHA);
                CLEAR_BIT(SPCR,CPOL);
        }
        else if(SPI_Group.Mode == SPI_Mode1)
        {
                SET_BIT(SPCR,CPHA);
                CLEAR_BIT(SPCR,CPOL);
        }
        else if(SPI_Group.Mode == SPI_Mode2)
        {
                SET_BIT(SPCR,CPOL);
                CLEAR_BIT(SPCR,CPHA);
        }
        else if(SPI_Group.Mode == SPI_Mode3)
        {
                SET_BIT(SPCR,CPOL);
                SET_BIT(SPCR,CPHA);
        }

        /*SPI Prescalar*/
        if(SPI_Group.Double_Speed == SPI_Double_Speed_OFF)
        {
            if(SPI_Group.Prescalar == SPI_Fosc4 || SPI_Group.Prescalar == SPI_Fosc16 || SPI_Group.Prescalar == SPI_Fosc64 || SPI_Group.Prescalar == SPI_Fosc128)
            {
                    SPCR |= (SPI_Group.Prescalar & 0x03);
            }
            else;
        }
        else if(SPI_Group.Double_Speed == SPI_Double_Speed_ON)
        {
            if(SPI_Group.Prescalar == SPI_Fosc4 || SPI_Group.Prescalar == SPI_Fosc16 || SPI_Group.Prescalar == SPI_Fosc64)
            {
                    SET_BIT(SPSR,SPI2X);
                    SPCR |= (SPI_Group.Prescalar & 0x03);
            }
            else;
        }

		/*SPI Data order*/
        if(SPI_Group.Data_Order == SPI_MSB)
            CLEAR_BIT(SPCR,DORD);
        else if(SPI_Group.Data_Order == SPI_LSB)
            SET_BIT(SPCR,DORD);
			

}

void SPI_Data_Write(u8 Data)
{
	SPDR = Data;
	while(!(SPSR & (1<<SPIF)));
}
u8 SPI_Data_Read(void)
{
	SPDR = 0x00;
	while( !(SPSR & (1<<SPIF)) );
	return SPDR;
}