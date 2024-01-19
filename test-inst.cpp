#include "AMDGPUEmitter.h"
#include "MemBuffer.h"
#include "VegaDetails.h"

#include <stdio.h>

using namespace Vega;

// API question -- 64-bit values on AMDGPU require pairs of even aligned
// registers. Should this be considered implicit for our interfaces?

int main(int argc, char **argv) {
  MemBuffer codegenBuffer(100);
  AMDGPUEmitter emitter;

  printf("%lu\n", codegenBuffer.getOffset());
  // emitter.emitOp(S_ADD_U32, SGPR_3, SGPR_1, SGPR_2, codegenBuffer);
  // emitter.emitOp(S_ADD_I32, SGPR_3, SGPR_1, SGPR_2, codegenBuffer);
  // emitter.emitOp(S_OR_B32, SGPR_3, SGPR_1, SGPR_2, codegenBuffer);
  // emitter.emitRelOp(S_CMP_EQ_U32, [> SCC_DUMMY = <] 0, SGPR_1, SGPR_2,
  // codegenBuffer, 0); emitter.emitRelOpImm(S_CMPK_EQ_I32, [> SCC_DUMMY = <] 0,
  // SGPR_1, -5, codegenBuffer, 0); emitter.emitRelOpImm(S_CMPK_GT_U32, [>
  // SCC_DUMMY = <] 0, SGPR_1, 20, codegenBuffer, 0);
  //
  // emitter.emitTimesImm(SGPR_1, SGPR_1, -14, codegenBuffer);
  // emitter.emitLongJump(SGPR_4, SGPR_5, 0xdeadbeef, codegenBuffer);
  // emitter.emitNops(1, codegenBuffer);
  // emitter.emitConditionalBranch([>onConditionTrue<] true, 17, codegenBuffer);
  // emitter.emitConditionalBranch([>onConditionTrue<] false, 17,
  // codegenBuffer);
  // emitter.emitEndProgram(codegenBuffer);
  // emitter.emitShortJump(13, codegenBuffer);
  // emitter.emitIf(SGPR_1, SGPR_4, rc_no_control, codegenBuffer);

  emitter.emitLoadIndir(SGPR_1, SGPR_2, 1, codegenBuffer);
  emitter.emitLoadIndir(SGPR_1, SGPR_4, 1, codegenBuffer);
  emitter.emitLoadIndir(SGPR_2, SGPR_4, 2, codegenBuffer);
  emitter.emitLoadIndir(SGPR_4, SGPR_0, 4, codegenBuffer);
  // s_load_dword s1, s[4:5], 0x0            ; encoding:
  // [0x42,0x00,0x02,0xc0,0x00,0x00,0x00,0x00] s_load_dword s1, s[2:3], 0x0 ;
  // encoding: [0x41,0x00,0x02,0xc0,0x00,0x00,0x00,0x00]

  printf("%lu\n", codegenBuffer.getOffset());
  // FILE *f = fopen("codegen-buffer", "wb");
  // codegenBuffer.dump(f);
  // fclose(f);
}
