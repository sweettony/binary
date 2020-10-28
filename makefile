SOURCE_DIR := $(shell pwd)

CPP_FILE := $(wildcard $(SOURCE_DIR)/src/*.cpp)

OBJ_FILE := $(patsubst $(SOURCE_DIR)/src/%.cpp, $(SOURCE_DIR)/obj/%.o, $(CPP_FILE))
DEP_FILE := $(patsubst $(SOURCE_DIR)/src/%.cpp, $(SOURCE_DIR)/dep/%.d, $(CPP_FILE))

CFLAG := -I$(SOURCE_DIR)/inc
CPP   := g++

a.out : prebuild $(OBJ_FILE)
	$(CPP) $(CFLAG) $(OBJ_FILE) -o $@

$(SOURCE_DIR)/obj/%.o : $(SOURCE_DIR)/src/%.cpp
	$(CPP) -c $(CFLAG) $< -o $@
prebuild:
	mkdir -p dep
	mkdir -p obj

$(SOURCE_DIR)/dep/%.d : $(SOURCE_DIR)/src/%.cpp
	$(CPP) -MM $(CFLAG) $< -MT $(SOURCE_DIR)/dep/$*.d -MT $(SOURCE_DIR)/dep/$*.o -o $@

clean:
	rm -rf dep/*.d
	rm -rf obj/*.o 

sinclude $(DEP_FILE)



