#ifndef MEM_BUFFER_H
#define MEM_BUFFER_H

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include <stdio.h>

// A stripped down 'lite' version of the 'codeGen' class in dyninstAPI/src.
class MemBuffer {
public:
  // Make a buffer with the given size
  MemBuffer(unsigned size) {
    start = (uint8_t *)new int8_t[size];
    memset((void *)start, 0, size);
    offset = 0;
    this->size = size;
  }

  ~MemBuffer() { delete[] start; }

  void *cur_ptr() { return (void *)(start + offset); }

  size_t getOffset() const { return offset; }

  void update(void *addr) {
    size_t diff = (uint8_t *)addr - (start + offset);
    // printf("%u\n", diff);
    assert(diff < size && "the update must fit in the buffer");
    offset += diff;
  }

  void dump(FILE *fileStream) {
    size_t bytesWritten =
        fwrite((const void *)start, sizeof(uint8_t), this->size, fileStream);
    assert(bytesWritten == size);
  }

private:
  uint8_t *start;
  size_t offset;
  size_t size;
};

// The codeGen class encapsulates a region in memory for code generation. So add
// a type alias here accordingly.
using codeGen = MemBuffer;

#endif
