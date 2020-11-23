ROOT_DIR := $(shell pwd)
DEP_DIR := $(ROOT_DIR)/dep
OBJ_DIR := $(ROOT_DIR)/obj
SRC_DIR := $(ROOT_DIR)/src


CPP_FILE := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILE := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILE))
DEP_FILE := $(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(CPP_FILE))

CFLAG := -I$(ROOT_DIR)/inc -g -DTH_DEBUG -pthread
CPP   := g++

MKDEP := $(ROOT_DIR)/dep
MKOBJ := $(ROOT_DIR)/obj

TARGETNAME = a.out

$(TARGETNAME) : $(OBJ_FILE) 
	@$(CPP) $(CFLAG) $(OBJ_FILE) -o $@
	@echo "$(CPP) $(notdir $@)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(MKOBJ) $(MKDEP)
	@$(CPP) -MM $(CFLAG) $< -MT $(DEP_DIR)/$*.d -MT $(OBJ_DIR)/$*.o -o $(DEP_DIR)/$*.d
	@$(CPP) -c $(CFLAG) $< -o $@
	@echo "$(CPP) $(notdir $@)"


$(MKOBJ) $(MKDEP):
	@echo make DIR $@
	mkdir -p $@

clean:
	@echo "rm dep"
	@rm -rf $(DEP_DIR)

	@echo "rm obj"
	@rm -rf $(OBJ_DIR)
	
	@echo "rm $(TARGETNAME)"
	@rm -rf $(TARGETNAME)

ifneq ($(MAKECMDGOALS), clean)
include $(wildcard $(DEP_FILE))
endif

