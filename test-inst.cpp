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
  emitter.emitLongJump(SGPR_4, SGPR_5, 0xdeadbeef, codegenBuffer);

  printf("%lu\n", codegenBuffer.getOffset());
  // FILE *f = fopen("codegen-buffer", "wb");
  // codegenBuffer.dump(f);
  // fclose(f);
}
