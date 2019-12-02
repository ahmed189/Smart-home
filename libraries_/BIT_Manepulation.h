#ifndef BIT_MANEPULATION_H_
#define BIT_MANEPULATION_H_

#define SET_BIT(PORT,BIT)	((PORT)|= (1<<(BIT)))
#define CLEAR_BIT(PORT,BIT)	((PORT)&=~(1<<(BIT)))
#define GET_BIT(PORT,BIT)	( ((PORT) >> (BIT)) & (0X01))


#endif /* BIT_MANEPULATION_H_ */