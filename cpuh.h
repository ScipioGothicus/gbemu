#pragma once

#define ZERO_FLAG (1 << 7);
#define SUB_FLAG (1 << 6);
#define HALF_CARRY_FLAG (1 << 5);
#define CARRY_FLAG (1 << 4);
//D = data (ex. LD_BC_D is same as LD BC, d16)
void NOP(void);
void LD_BC_DD(unsigned short operand);
void LD_BCP_A(void);
void INC_BC(void);
void INC_B(void);
void DEC_B(void);
void LD_B_