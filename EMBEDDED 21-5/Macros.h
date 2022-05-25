#ifndef MACROS_H_
#define MACROS_H_


/* Set a bit to 1 in a register*/
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))

/*Clear a bit to 0 in a register*/
#define CLEAR_BIT(REG , BIT) (REG &=~(1<<BIT))

/*Toggle a bit in a register*/
#define TOGGLE_BIT(REG , BIT) (REG ^= (1<<BIT))

/* Write a logic value to a bit in a register*/
#define WRITE_BIT(REG , BIT , VALUE){\
	switch(VALUE) {\
	case 0 : CLEAR_BIT(REG , BIT); break; \
	case 1: SET_BIT(REG , BIT); } }

/*Check if a bit is set to 1 in a register, returns 1 in that case and 0 otherwise*/
#define BIT_IS_SET(REG ,BIT) (REG & (1<<BIT))

/*Checks if a bit is cleared to 0 in a register, returns 1 in that case and 0 otherwise*/
#define BIT_IS_CLEAR(REG ,BIT) !(BIT_IS_SET(REG , BIT))


 /*reads the value of the bit in a register and returns 1 or 0*/
#define READ_BIT(REG , BIT) (REG & (1<<BIT))

#endif
	