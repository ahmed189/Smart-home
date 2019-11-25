#ifndef BIT_MANEPULATION_H_
#define BIT_MANEPULATION_H_

#define SET_BIT(PORT,BIT)	((PORT)|= (1<<(BIT)))
#define CLEAR_BIT(PORT,BIT)	((PORT)&=~(1<<(BIT)))


#endif /* BIT_MANEPULATION_H_ */