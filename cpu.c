

#include "cpuh.h"
#include "registersh.h"
#include "romh.h"
#include "platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if dd or aa is used, use 0x%04X to signify four bytes (unsigned shorts)
//if d or a is used, use 0x%02X to signify two bytes (unsigned chars)
//length of instructions starts with 0, but is represented differently in the opcode table. if the length of an instruction is 1 in the table, set it to 0 here, if 2, then 1, etc.
//ex. {"NOP", 0, nop}
//     name  len ref
const struct instruction instructionList[256] {
    {"NOP", 0, nop},
    {"LD BC, 0x%04X", 2, ld_bc_xx},
    {"LD (BC), A", 0, ld_bcp_a},
    {"INC BC", 0, inc_bc},
    {"INC B", 0, inc_b},
    {"DEC B", 0, dec_b},
    {"LD B, 0x%02X", 1, ld_b_x},
    {"RLCA", 0, rlca},
    {"LD (0x%04X), SP", 2, ld_xx_sp},
    {"ADD HL, BC", 0, add_hl_bc},
    {"LD A, (BC)", 0, ld_a_bcp},
    {"DEC BC", 0, dec_bc},
    {"INC C", 0, inc_c},
    {"DEC C", 0, dec_c},
    {"LD C, 0x%02X", 1, ld_c_x},
    {"RRCA", 0, rrca},
    {"STOP 0x%02X", 1, stop},
    {"LD DE, 0x%04X", 2, ld_de_xx},
    {"LD (DE), A", 0, ld_dep_a},
    {"INC DE", 0, inc_de},
    {"INC D", 0, inc_d},
    {"DEC D", 0, dec_d},
    {"LD D 0x%02X", 1, ld_d_x},
    {"RLA", 0, rla},
    {"JR 0x%02X", 1, jr_x},
    {"ADD HL, DE", 0, add_hl_de},
    {"LD A, (DE)", 0, ld_a_dep},
    {"DEC DE", 0, dec_de},
    {"INC E", 0, inc_e},
    {"DEC E", 0, dec_e},
    {"LD E, 0x%02X", 1, ld_e_x},
    {"RRA", 0, rra},
    {"JR NZ, 0x%02X", 1, jr_nz_x},
    {"LD HL, 0x%04X", 2, ld_hl_xx},
    {"LD (HL+), A", 0, ld_hlpi_a},
    {"INC HL", 0, inc_hl},
    {"INC H", 0, inc_h},
    {"DEC H", 0, dec_h},
    {"LD H, 0x%02X", 1, ld_h_x},
    {"DAA", 0, daa},
    {"JR Z, 0x%02X", 1, jr_z_x},
    {"ADD HL, HL", 0, add_hl_hl},
    {"LD A, (HL+)", 0, ld_a_hlpi},

}