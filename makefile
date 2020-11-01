ROOT_DIR := $(shell pwd)
DEP_DIR := $(ROOT_DIR)/dep
OBJ_DIR := $(ROOT_DIR)/obj
SRC_DIR := $(ROOT_DIR)/src
$(shell mkdir -p dep > /dev/null)
$(shell mkdir -p obj > /dev/null)

CPP_FILE := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILE := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILE))
DEP_FILE := $(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(CPP_FILE))

CFLAG := -I$(ROOT_DIR)/inc -g -DTH_DEBUG -pthread
CPP   := g++

TARGETNAME = a.out
$(TARGETNAME) : $(DEP_FILE) $(OBJ_FILE)
	@$(CPP) $(CFLAG) $(OBJ_FILE) -o $@
	@echo "$(CPP) $(notdir $@)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(CPP) -c $(CFLAG) $< -o $@
	@echo "$(CPP) $(notdir $@)"

$(DEP_DIR)/%.d : $(SRC_DIR)/%.cpp
	@$(CPP) -MM $(CFLAG) $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $@
	@echo "$(CPP) $(notdir $@)"

clean:
	@rm -rf dep
	@echo "rm dep"
	@rm -rf obj
	@echo "rm obj"
	@rm -rf $(TARGETNAME)
	@echo "rm $(TARGETNAME)"

include $(DEP_FILE)

