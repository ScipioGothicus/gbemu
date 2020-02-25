#pragma once

#define ZERO_FLAG (1 << 7)
#define SUB_FLAG (1 << 6)
#define HALF_CARRY_FLAG (1 << 5)
#define CARRY_FLAG (1 << 4)

#define ZERO_FLAG_CHK (registers.f & ZERO_FLAG)
#define SUB_FLAG_CHK (registers.f & SUB_FLAG)
#define HALF_CARRY_FLAG_CHK (registers.f & HALF_CARRY_FLAG)
#define CARRY_FLAG_CHK (registers.f & CARRY_FLAG)

#define SETFLAG_CHK(value) (registers.f & (value))
#define SETFLAG(value) (registers.f |= (value))
#define CLEARFLAG(value) (registers.f &= ~(value))


struct instruction {
    char *disassembly;
    unsigned char operandLength;
    void *execute;
} extern const instructionList[256];

extern const unsigned char instructionCycles[256];

extern unsigned long cycles;
extern unsigned long stopped;

void RESET(void);
void CPUSTEP(void);

void UNDEFINED(void);

//multiple lowercase letters signify bits (ex. 1 d is 8 bit, 2 b's is 16 bit)
//d = data (ex. LD_BC_D is same as LD BC, d16)
//a = address (ex. LD_AAP_SP is the same as LD (a16), SP)
//p = parenthesis
//i = increment
//s = decrement

void NOP(void);                         //0x00
void LD_BC_dd(unsigned short operand);  //0x01
void LD_BCP_A(void);                    //0x02
void INC_BC(void);                      //0x03
void INC_B(void);                       //0x04
void DEC_B(void);                       //0x05
void LD_B_d(unsigned char operand);     //0x06
void RLCA(void);                        //0x07
void LD_aap_SP(unsigned short operand); //0x08
void ADD_HL_BC(void);                   //0x09
void LD_A_BCP(void);                    //0x0A
void DEC_BC(void)                       //0x0B
void INC_C(void);                       //0x0C
void DEC_C(void);                       //0x0D
void LD_C_d(unsigned char operand);     //0x0E
void RRCA(void);                        //0x0F

void STOP(unsigned char operand);       //0x10
void LD_DE_dd(unsigned short operand);  //0x11
void LD_DEP_A(void);                    //0x12
void INC_DE(void);                      //0x13
void INC_D(void);                       //0x14
void DEC_D(void);                       //0x15
void LD_D_D(void);                      //0x16
void RLCA(void);                        //0x17
void LD_aa_SP(unsigned short operand);  //0x18
void ADD_HL_BC(void);                   //0x19
void LD_A_DEP(void);                    //0x1A
void DEC_DE(void);                      //0x1B
void INC_E(void);                       //0x1C
void DEC_E(void);                       //0x1D
void LD_E_d(unsigned char operand);     //0x1E
void RRA(void);                         //0x1F

void JR_NZ_d(unsigned char operand);    //0x20
void LD_HL_dd(unsigned short operand);  //0x21
void LD_HLpi_A(void)                    //0x22
void INC_HL(void);                      //0x23
void INC_H(void);                       //0x24
void DEC_H(void);                       //0x25
void LD_H_d(unsigned char operand);     //0x26
void DAA(void);                         //0x27
void JR_Z_d(unsigned char operand);     //0x28
void ADD_HL_HL(void);                   //0x29
void LD_A_HLpi(void);                   //0x2A
void DEC_HL(void);                      //0x2B
void INC_L(void);                       //0x2C
void DEC_L(void);                       //0x2D
void LD_L_d(unsigned char operand);     //0x2E
void CPL(void);                         //0x2F

void JR_NC_d(unsigned char operand);    //0x30
void LD_SP_dd(unsigned short operand);  //0x31
void LD_HLps_A(void);                   //0x32
void INC_SP(void);                      //0x33
void INC_HLp(void);                     //0x34
void DEC_HLp(void);                     //0x35
void LD_HLp_d(unsigned char operand);   //0x36
void SCF(void);                         //0x37
void JR_C_d(unsigned char operand);     //0x38
void ADD_HL_SP(void);                   //0x39
void LD_A_HLps(void);                   //0x3A
void DEC_SP(void);                      //0x3B
void INC_A(void);                       //0x3C
void DEC_A(void);                       //0x3D
void LD_A_d(unsigned char operand);     //0x3E
void CCF(void);                         //0x3F

void LD_B_B(void);                      //0x40
void LD_B_C(void);                      //0x41
void LD_B_D(void);                      //0x42
void LD_B_E(void);                      //0x43
void LD_B_H(void);                      //0x44
void LD_B_L(void);                      //0x45
void LD_B_HLp(void);                    //0x46
void LD_B_A(void);                      //0x47
void LD_C_B(void);                      //0x48
void LD_C_C(void);                      //0x49
void LD_C_D(void);                      //0x4A
void LD_C_E(void);                      //0x4B
void LD_C_H(void);                      //0x4C
void LD_C_L(void);                      //0x4D
void LD_C_HLp(void);                    //0x4E
void LD_C_A(void);                      //0x4F

void LD_B_D(void);                      //0x50
void LD_D_C(void);                      //0x51
void LD_D_D(void);                      //0x52
void LD_D_E(void);                      //0x53
void LD_D_H(void);                      //0x54
void LD_D_L(void);                      //0x55
void LD_D_HLp(void);                    //0x56
void LD_D_A(void);                      //0x57
void LD_E_B(void);                      //0x58
void LD_E_C(void);                      //0x59
void LD_E_D(void);                      //0x5A
void LD_E_E(void);                      //0x5B
void LD_E_H(void);                      //0x5C
void LD_E_L(void);                      //0x5D
void LD_E_HLp(void);                    //0x5E
void LD_E_A(void);                      //0x5F

void LD_H_B(void);                      //0x60
void LD_H_C(void);                      //0x61
void LD_H_D(void);                      //0x62
void LD_H_E(void);                      //0x63
void LD_H_H(void);                      //0x64
void LD_H_L(void);                      //0x65
void LD_H_HLp(void);                    //0x66
void LD_H_A(void);                      //0x67
void LD_L_B(void);                      //0x68
void LD_L_C(void);                      //0x69
void LD_L_D(void);                      //0x6A
void LD_L_E(void);                      //0x6B
void LD_L_H(void);                      //0x6C
void LD_L_L(void);                      //0x6D
void LD_L_HLp(void);                    //0x6E
void LD_L_A(void);                      //0x6F

void LD_HLp_B(void);                    //0x70
void LD_HLp_C(void);                    //0x71
void LD_HLp_D(void);                    //0x72
void LD_HLp_E(void);                    //0x73
void LD_HLp_H(void);                    //0x74
void LD_HLp_L(void);                    //0x75
void HALT(void);                        //0x76
void LD_HLp_A(void);                    //0x77
void LD_A_B(void);                      //0x78
void LD_A_C(void);                      //0x79
void LD_A_D(void);                      //0x7A
void LD_A_E(void);                      //0x7B
void LD_A_H(void);                      //0x7C
void LD_A_L(void);                      //0x7D
void LD_A_HLp(void);                    //0x7E
void LD_A_A(void);                      //0x7F

void ADD_A_B(void);                     //0x80
void ADD_A_C(void);                     //0x81
void ADD_A_D(void);                     //0x82
void ADD_A_E(void);                     //0x83
void ADD_A_H(void);                     //0x84
void ADD_A_L(void);                     //0x85
void ADD_A_HLp(void);                   //0x86
void ADD_A_A(void);                     //0x87
void ADC_A_B(void);                     //0x88
void ADC_A_C(void);                     //0x89
void ADC_A_D(void);                     //0x8A
void ADC_A_E(void);                     //0x8B
void ADC_A_H(void);                     //0x8C
void ADC_A_L(void);                     //0x8D
void ADC_A_HLp(void);                   //0x8E
void ADC_A_A(void);                     //0x8F

void SUB_B(void);                       //0x90
void SUB_C(void);                       //0x91
void SUB_D(void);                       //0x92
void SUB_E(void);                       //0x93
void SUB_H(void);                       //0x94
void SUB_L(void);                       //0x95
void SUB_HLp(void);                     //0x96
void SUB_A(void);                       //0x97
void SBC_A_B(void);                     //0x98
void SBC_A_C(void);                     //0x99
void SBC_A_D(void);                     //0x9A
void SBC_A_E(void);                     //0x9B
void SBC_A_H(void);                     //0x9C
void SBC_A_L(void);                     //0x9D
void SBC_A_HLp(void);                   //0x9E
void SBC_A_A(void);                     //0x9F

void AND_B(void);                       //0xA0
void AND_C(void);                       //0xA1
void AND_D(void);                       //0xA2
void AND_E(void);                       //0xA3
void AND_H(void);                       //0xA4
void AND_L(void);                       //0xA5
void AND_HLp(void);                     //0xA6
void AND_A(void);                       //0xA7
void XOR_B(void);                       //0xA8
void XOR_C(void);                       //0xA9
void XOR_D(void);                       //0xAA
void XOR_E(void);                       //0xAB
void XOR_H(void);                       //0xAC
void XOR_L(void);                       //0xAD
void XOR_HLp(void);                     //0xAE
void XOR_A(void);                       //0xAF

void OR_B(void);                        //0xB0
void OR_C(void);                        //0xB1
void OR_D(void);                        //0xB2
void OR_E(void);                        //0xB3
void OR_H(void);                        //0xB4
void OR_L(void);                        //0xB5
void OR_HLp(void);                      //0xB6
void OR_A(void);                        //0xB7
void CP_B(void);                        //0xB8
void CP_C(void);                        //0xB9
void CP_D(void);                        //0xBA
void CP_E(void);                        //0xBB
void CP_H(void);                        //0xBC
void CP_L(void);                        //0xBD
void CP_HLp(void);                      //0xBE
void CP_A(void);                        //0xBF

void RET_NZ(void);                      //0xC0
void POP_BC(void);                      //0xC1
void JP_NZ_aa(unsigned short operand);  //0xC2
void JP_aa(unsigned short operand);     //0xC3
void CALL_NZ_aa(unsigned short operand);//0xC4
void PUSH_BC(void);                     //0xC5
void ADD_A_d(unsigned char operand);    //0xC6
void RST_00H(void);                     //0xC7
void RET_Z(void);                       //0xC8
void RET(void);                         //0xC9
void JP_Z_aa(unsigned short operand);   //0xCA
void PREFIX_CB(void);                   //0xCB
void CALL_Z_aa(unsigned short operand); //0xCC
void CALL_aa(unsigned short operand);   //0xCD
void ADC_A_d(unsigned char operand);    //0xCE
void RST_08H(void);                     //0xCF

void RET_NC(void);                      //0xD0
void POP_DE(void);                      //0xD1
void JP_NC_aa(unsigned short operand);  //0xD2
void CALL_NC_aa(unsigned short operand);//0xD4
void PUSH_DE(void);                     //0xD5
void SUB_d(unsigned char operand);      //0xD6
void RST_10H(void);                     //0xD7
void RET_C(void);                       //0xD8
void RETI(void);                        //0xD9
void JP_C_aa(unsigned short operand);   //0xDA
void CALL_C_aa(unsigned short operand); //0xDC
void SBC_A_d(unsigned char operand);    //0xDE
void RST_18H(void);                     //0xDF

void LDH_ap_A(unsigned char operand);   //0xE0
void POP_HL(void);                      //0xE1
void LD_Cp_A(void);                     //0xE2
void PUSH_HL(void);                     //0xE5
void AND_d(unsigned char operand);      //0xE6
void RST_20H(void);                     //0xE7
void ADD_SP_d(unsigned char operand);   //0xE8
void JP_HLp(void);                      //0xE9
void LD_aap_A(unsigned short operand);  //0xEA
void XOR_d(unsigned char operand);      //0xEE
void RST_28H(void);                     //0xEF

void LDH_A_ap(unsigned char operand);   //0xF0
void POP_AF(void);                      //0xF1
void LD_A_Cp(void);                     //0xF2
void DI(void);                          //0xF3
void PUSH_AF(void);                     //0xF5
void OR_d(unsigned char operand);       //0xF6
void RST_30H(void);                     //0xF7
void LD_HL_SP_d(unsigned char operand); //0xF8
void LD_SP_HL(void);                    //0xF9
void LD_A_aa(unsigned short operand);   //0xFA
void EI(void);                          //0xFB
void CP_d(unsigned char operand);       //0xFD
void RST_38H(void);                     //0xFE