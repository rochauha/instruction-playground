/*
 * We provide the Paradyn Tools (below described as "Paradyn")
 * on an AS IS basis, and do not warrant its validity or performance.
 * We reserve the right to update, modify, or discontinue this
 * software at any time.  We shall have no obligation to supply such
 * updates or modifications or any other form of support to you.
 *
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "AMDGPUEmitter.h"
#include "VegaDetails.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

using namespace Vega;

// ===== AMDGPUEmitter implementation begin =====

unsigned AMDGPUEmitter::emitIf(Register expr_reg, Register target,
                               RegControl rc, codeGen &gen) {
  printf("emitIf not implemented yet\n");
  return 0;
}

// AMDGPUEmitter implementation
void AMDGPUEmitter::emitOp(unsigned opcode, Register dest, Register src1,
                           Register src2, codeGen &gen) {
  emitSop2(opcode, dest, src1, src2, gen);
}

void AMDGPUEmitter::emitOpImm(unsigned opcode1, unsigned opcode2, Register dest,
                              Register src1, RegValue src2imm, codeGen &gen) {
  printf("not implemented yet\n");
}

void AMDGPUEmitter::emitRelOp(unsigned opcode, Register dest, Register src1,
                              Register src2, codeGen &gen, bool s) {
  // assert(Vega::isRelationalOp(opcode) &&
  //        "opcode must correspond to a relational operation");
  emitSopC(opcode, src1, src2, gen);
}

void AMDGPUEmitter::emitRelOpImm(unsigned op, Register dest, Register src1,
                                 RegValue src2imm, codeGen &gen, bool s) {
  emitSopK(op, src1, src2imm, gen);
}

void AMDGPUEmitter::emitDiv(Register dest, Register src1, Register src2,
                            codeGen &gen, bool s) {
  printf("emitDiv not implemented yet\n");
}

void AMDGPUEmitter::emitTimesImm(Register dest, Register src1, RegValue src2imm,
                                 codeGen &gen) {
  assert(dest == src1 && "SOPK instructions require dest = src1");
  Vega::emitSopK(Vega::S_MULK_I32, dest, src2imm, gen);
}

void AMDGPUEmitter::emitDivImm(Register dest, Register src1, RegValue src2imm,
                               codeGen &gen, bool s) {
  printf("emitDivImm not implemented yet\n");
}

void AMDGPUEmitter::emitLoad(Register dest, Address addr, int size,
                             codeGen &gen) {
  printf("emitLoad not implemented yet\n");
}

void AMDGPUEmitter::emitLoadConst(Register dest, Address imm, codeGen &gen) {
  // Caller must ensure that dest is available; and dest, dest+1 are available.

  assert(sizeof(Address) == 8); // must be a 64-bit address
  Register reg0 = dest;
  Register reg1 = dest + 1;

  assert(dest >= SGPR_0 && dest <= SGPR_101 && "reg0 must be an SGPR");
  assert(reg0 % 2 == 0 &&
         "reg0 must be even as we will use reg0, reg1 in pair");

  uint32_t lowerAddress = imm;
  uint32_t upperAddress = (imm >> 32);

  emitMovLiteral(reg0, upperAddress, gen);
  emitMovLiteral(reg1, lowerAddress, gen);
}

void AMDGPUEmitter::emitLoadIndir(Register dest, Register addr_reg, int size,
                                  codeGen &gen) {
  printf("emitLoadIndir not implemented yet\n");
}

bool AMDGPUEmitter::emitCallRelative(Register, Address, Register, codeGen &) {
  printf("emitCallRelative not implemented yet\n");
  return 0;
}

bool AMDGPUEmitter::emitLoadRelative(Register dest, Address offset,
                                     Register base, int size, codeGen &gen) {
  printf("emitLoadRelative not implemented yet\n");
  return 0;
}

// void AMDGPUEmitter::emitLoadShared(opCode op, Register dest,
//                                        const image_variable *var, bool
//                                        is_local, int size, codeGen &gen,
//                                        Address offset) {
//   printf("emitLoadShared not implemented yet\n");
// }

void AMDGPUEmitter::emitLoadFrameAddr(Register dest, Address offset,
                                      codeGen &gen) {
  printf("emitLoadFrameAddr not implemented yet\n");
}

// These implicitly use the stored original/non-inst value
void AMDGPUEmitter::emitLoadOrigFrameRelative(Register dest, Address offset,
                                              codeGen &gen) {
  printf("emitLoadOrigFrameRelative not implemented yet\n");
}

void AMDGPUEmitter::emitLoadOrigRegRelative(Register dest, Address offset,
                                            Register base, codeGen &gen,
                                            bool store) {
  printf("emitLoadOrigRegRelative not implemented yet\n");
}

void AMDGPUEmitter::emitLoadOrigRegister(Address register_num, Register dest,
                                         codeGen &gen) {
  printf("emitLoadOrigRegister not implemented yet\n");
}

void AMDGPUEmitter::emitStoreOrigRegister(Address register_num, Register dest,
                                          codeGen &gen) {
  printf("emitStoreOrigRegister not implemented yet\n");
}

void AMDGPUEmitter::emitStore(Address addr, Register src, int size,
                              codeGen &gen) {
  printf("emitStore not implemented yet\n");
}

void AMDGPUEmitter::emitStoreIndir(Register addr_reg, Register src, int size,
                                   codeGen &gen) {
  printf("emitStoreIndir not implemented yet\n");
}

void AMDGPUEmitter::emitStoreFrameRelative(Address offset, Register src,
                                           Register scratch, int size,
                                           codeGen &gen) {
  printf("emitStoreFrameRelative not implemented yet\n");
}

void AMDGPUEmitter::emitStoreRelative(Register source, Address offset,
                                      Register base, int size, codeGen &gen) {
  printf("emitStoreRelative not implemented yet\n");
}

// void AMDGPUEmitter::emitStoreShared(Register source,
//                                         const image_variable *var,
//                                         bool is_local, int size, codeGen
//                                         &gen) {
//   printf("emitStoreShared not implemented yet\n");
// }

bool AMDGPUEmitter::emitMoveRegToReg(Register src, Register dest,
                                     codeGen &gen) {
  printf("emitMoveRegToReg not implemented yet\n");
  return 0;
}

// bool AMDGPUEmitter::emitMoveRegToReg(registerSlot *src, registerSlot *dest,
//                                          codeGen &gen) {
//   printf("emitMoveRegToReg -- slot not implemented yet\n");
// }

// Register AMDGPUEmitter::emitCall(opCode op, codeGen &gen,
//                                      const std::vector<AstNodePtr> &operands,
//                                      bool noCost, func_instance *callee) {
//   printf("emitCall not implemented yet\n");
// }

void AMDGPUEmitter::emitGetRetVal(Register dest, bool addr_of, codeGen &gen) {
  printf("emitGetRetVal not implemented yet\n");
}

void AMDGPUEmitter::emitGetRetAddr(Register dest, codeGen &gen) {
  printf("emitGetRetAddr not implemented yet\n");
}

// void AMDGPUEmitter::emitGetParam(Register dest, Register param_num,
//                                      instPoint::Type pt_type, opCode op,
//                                      bool addr_of, codeGen &gen) {
//   printf("emitGetParam not implemented yet\n");
// }

void AMDGPUEmitter::emitASload(int ra, int rb, int sc, long imm, Register dest,
                               int stackShift, codeGen &gen) {
  printf("emitASload not implemented yet\n");
}

void AMDGPUEmitter::emitCSload(int ra, int rb, int sc, long imm, Register dest,
                               codeGen &gen) {
  printf("emitCSload not implemented yet\n");
}

void AMDGPUEmitter::emitPushFlags(codeGen &gen) {
  printf("emitPushFlags not implemented yet\n");
}

void AMDGPUEmitter::emitRestoreFlags(codeGen &gen, unsigned offset) {
  printf("emitRestoreFlags not implemented yet\n");
}

// Built-in offset...
void AMDGPUEmitter::emitRestoreFlagsFromStackSlot(codeGen &gen) {
  printf("emitRestoreFlagsFromStackSlot not implemented yet\n");
}

// bool AMDGPUEmitter::emitBTSaves(baseTramp *bt, codeGen &gen) {
//   printf("emitBTSaves not implemented yet\n");
// }

// bool AMDGPUEmitter::emitBTRestores(baseTramp *bt, codeGen &gen) {
//   printf("emitBTRestores not implemented yet\n");
// }

void AMDGPUEmitter::emitStoreImm(Address addr, int imm, codeGen &gen,
                                 bool noCost) {
  printf("emitStoreImm not implemented yet\n");
}

void AMDGPUEmitter::emitAddSignedImm(Address addr, int imm, codeGen &gen,
                                     bool noCost) {
  printf("emitAddSignedImm not implemented yet\n");
}

bool AMDGPUEmitter::emitPush(codeGen &, Register) {
  printf("emitPush not implemented yet\n");
  return 0;
}

bool AMDGPUEmitter::emitPop(codeGen &, Register) {
  printf("emitPop not implemented yet\n");
  return 0;
}

bool AMDGPUEmitter::emitAdjustStackPointer(int index, codeGen &gen) {
  printf("emitAdjustStackPointer not implemented yet\n");
  return 0;
}

// bool AMDGPUEmitter::clobberAllFuncCall(registerSpace *rs,
//                                            func_instance *callee) {
//   printf("clobberAllFuncCall not implemented yet\n");
// }

// Additional interfaces

void AMDGPUEmitter::emitNops(unsigned numNops, codeGen &gen) {
  assert(numNops >= 1 && numNops <= 16);
  // 0x0 inserts 1 nop, and 0xFF (15) inserts 16 nops, so subtract 1
  emitSopP(S_NOP, /* hasImm = */ true, (numNops - 1), gen);
}

void AMDGPUEmitter::emitEndProgram(codeGen &gen) {
  // Passing 0 as immediate value.
  // Value of immediate passed here doesn't matter as the instruction won't have
  // an immediate.
  emitSopP(S_ENDPGM, /* hasImm = */ false, 0, gen);
}

void AMDGPUEmitter::emitMovLiteral(Register reg, uint32_t literal,
                                   codeGen &gen) {
  // s_mov_b32 reg, < 32-bit constant literal >
  // The literal follows the instruction, so set src0 = 0xFF just like the
  // assembler does.
  emitSop1(S_MOV_B32, /* dest = */ reg, /* src0 = */ 0xFF,
           /* hasLiteral = */ true, literal, gen);
}

void AMDGPUEmitter::emitConditionalBranch(bool onConditionTrue,
                                          int16_t wordOffset, codeGen &gen) {
  unsigned opcode = onConditionTrue ? S_BRANCH_SCC0 : S_BRANCH_SCC1;
  emitSopP(opcode, /* hasImm = */ true, wordOffset, gen);
}

void AMDGPUEmitter::emitShortJump(int16_t wordOffset, codeGen &gen) {
  emitSopP(S_BRANCH, /* hasImm = */ true, wordOffset, gen);
}

void AMDGPUEmitter::emitLongJump(Register reg0, Register reg1,
                                 uint64_t toAddress, codeGen &gen) {
  // Right now only consider SGPRs
  assert(reg0 >= SGPR_0 && reg0 <= SGPR_101 && "reg0 must be an SGPR");
  assert(reg1 >= SGPR_0 && reg1 <= SGPR_101 && "reg1 must be an SGPR");
  assert(reg0 % 2 == 0 && reg1 == reg0 + 1 &&
         "register pair must be even aligned");

  emitLoadConst(reg0, toAddress, gen);

  // S_SETPC_B64 writes to the PC, so dest = 0 just like the assembler does.
  emitSop1(S_SETPC_B64, /* dest = */ 0, reg0, /* hasLiteral = */ false, 0, gen);
}

// ===== AMDGPUEmitter implementation end =====
