SOURCE_DIR := $(shell pwd)

$(shell mkdir -p dep > /dev/null)
$(shell mkdir -p obj > /dev/null)

CPP_FILE := $(wildcard $(SOURCE_DIR)/src/*.cpp)
OBJ_FILE := $(patsubst $(SOURCE_DIR)/src/%.cpp, $(SOURCE_DIR)/obj/%.o, $(CPP_FILE))
DEP_FILE := $(patsubst $(SOURCE_DIR)/src/%.cpp, $(SOURCE_DIR)/dep/%.d, $(CPP_FILE))

CFLAG := -I$(SOURCE_DIR)/inc -g -DTH_DEBUG
CPP   := g++

TARGETNAME = a.out
$(TARGETNAME) : $(DEP_FILE) $(OBJ_FILE)
	@$(CPP) $(CFLAG) $(OBJ_FILE) -o $@
	@echo "$(CPP) $(notdir $@)"

$(SOURCE_DIR)/obj/%.o : $(SOURCE_DIR)/src/%.cpp
	@$(CPP) -c $(CFLAG) $< -o $@
	@echo "$(CPP) $(notdir $@)"

$(SOURCE_DIR)/dep/%.d : $(SOURCE_DIR)/src/%.cpp
	@$(CPP) -MM $(CFLAG) $< -MT $(SOURCE_DIR)/dep/$*.d -MT $(SOURCE_DIR)/dep/$*.o -o $@
	@echo "$(CPP) $(notdir $@)"

clean:
	@rm -rf dep
	@echo "rm dep"
	@rm -rf obj
	@echo "rm obj"
	@rm -rf $(TARGETNAME)
	@echo "rm $(TARGETNAME)"

include $(DEP_FILE)

