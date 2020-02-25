#pragma once

struct extended_instruction {
    char *disassembly;
    void (*execute)(void);
}   extern const extededInstructionList[256];

extern const unsigned char extendedInstructionCycles[256];

void CB_N(unsigned char instruction);

void RLC_B(void);                   //0x0*
void RLC_C(void);
void RLC_D(void);
void RLC_E(void);
void RLC_H(void);
void RLC_L(void);
void RLC_HLp(void);
void RLC_A(void);
void RRC_B(void);
void RRC_C(void);
void RRC_D(void);
void RRC_E(void);
void RRC_H(void);
void RRC_L(void);
void RRC_HLp(void);
void RRC_A(void);

void RL_B(void);                    //0x1*
void RL_C(void);
void RL_D(void);
void RL_E(void);
void RL_H(void);
void RL_L(void);
void RL_HLp(void);
void RL_A(void);
void RR_B(void);
void RR_C(void);
void RR_D(void);
void RR_E(void);
void RR_H(void);
void RR_L(void);
void RR_HLp(void);
void RR_A(void);

void SLA_B(void);                   //0x2*
void SLA_C(void);
void SLA_D(void);
void SLA_E(void);
void SLA_H(void);
void SLA_L(void);
void SLA_HLp(void);
void SLA_A(void);
void SRA_B(void);
void SRA_C(void);
void SRA_D(void);
void SRA_E(void);
void SRA_H(void);
void SRA_L(void);
void SRA_HLp(void);
void SRA_A(void);

void SWAP_B(void);                  //0x3*
void SWAP_C(void);
void SWAP_D(void);
void SWAP_E(void);
void SWAP_H(void);
void SWAP_L(void);
void SWAP_HLp(void);
void SWAP_A(void);
void SRL_B(void);
void SRL_C(void);
void SRL_D(void);
void SRL_E(void);
void SRL_H(void);
void SRL_L(void);
void SRL_HLp(void);
void SRL_A(void);

void BIT_0_B(void);                 //0x4*
void BIT_0_C(void);
void BIT_0_D(void);
void BIT_0_E(void);
void BIT_0_H(void);
void BIT_0_L(void);
void BIT_0_HLp(void);
void BIT_0_A(void);
void BIT_1_B(void);
void BIT_1_C(void);
void BIT_1_D(void);
void BIT_1_E(void);
void BIT_1_H(void);
void BIT_1_L(void);
void BIT_1_HLp(void);
void BIT_1_A(void);

void BIT_2_B(void);                 //0x5*
void BIT_2_C(void);
void BIT_2_D(void);
void BIT_2_E(void);
void BIT_2_H(void);
void BIT_2_L(void);
void BIT_2_HLp(void);
void BIT_2_A(void);
void BIT_3_B(void);
void BIT_3_C(void);
void BIT_3_D(void);
void BIT_3_E(void);
void BIT_3_H(void);
void BIT_3_L(void);
void BIT_3_HLp(void);
void BIT_3_A(void);

void BIT_4_B(void);                 //0x6*
void BIT_4_C(void);
void BIT_4_D(void);
void BIT_4_E(void);
void BIT_4_H(void);
void BIT_4_L(void);
void BIT_4_HLp(void);
void BIT_4_A(void);
void BIT_5_B(void);
void BIT_5_C(void);
void BIT_5_D(void);
void BIT_5_E(void);
void BIT_5_H(void);
void BIT_5_L(void);
void BIT_5_HLp(void);
void BIT_5_A(void);

