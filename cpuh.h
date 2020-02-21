#pragma once

#define ZERO_FLAG (1 << 7);
#define SUB_FLAG (1 << 6);
#define HALF_CARRY_FLAG (1 << 5);
#define CARRY_FLAG (1 << 4);
//D = data (ex. LD_BC_D is same as LD BC, d16)
//A = address (ex. LD_AAP_SP is the same as LD (a16), SP)
void NOP(void); //0x00
void LD_BC_DD(unsigned short operand);  //0x01
void LD_BCP_A(void);                    //0x02
void INC_BC(void);                      //0x03
void INC_B(void);                       //0x04
void DEC_B(void);                       //0x05
void LD_B_D(unsigned char operand);     //0x06
void RLCA(void);                        //0x07
void LD_AAP_SP(unsigned short operand); //0x08
void ADD_HL_BC(void);                   //0x09
void LD_A_BCP(void);                    //0x0A
void DEC_BC(void)                       //0x0B
void INC_C(void);                       //0x0C
void DEC_C(void);                       //0x0D
void LD_C_D(unsigned char operand);     //0x0E
void RRCA(void);                        //0x0F
void STOP(void);                        //0x10
void LD_DE_DD(unsigned short operand);  //0x11
void LD_DEP_A(void);                    //0x12
void INC_DE(void);                      //0x13
void INC_D(void);                       //0x14
void DEC_D(void);                       //0x15
void LD_D_D(void);                      //0x16