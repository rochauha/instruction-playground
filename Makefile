OUTPUT_BIN = test-inst
OBJECTS = test-inst.o VegaDetails.o AMDGPUEmitter.o
CXX = g++
CFLAGS = -std=c++14 -c -O3 -Wall -g

$(OUTPUT_BIN) : $(OBJECTS)
	$(CXX) -o $(OUTPUT_BIN) $(OBJECTS)

test-inst.o: test-inst.cpp VegaDetails.o AMDGPUEmitter.o
	$(CXX) $(CFLAGS) test-inst.cpp

VegaDetails.o: VegaDetails.h VegaDetails.cpp
	$(CXX) $(CFLAGS) VegaDetails.cpp

AMDGPUEmitter.o: MemBuffer.h Emitter.h VegaDetails.h AMDGPUEmitter.h VegaDetails.cpp AMDGPUEmitter.cpp
	$(CXX) $(CFLAGS) AMDGPUEmitter.cpp


.PHONY: clean_obj clean_all
clean_obj:
	rm -f *.o

clean_all:
	rm -f *.o $(OUTPUT_BIN)
