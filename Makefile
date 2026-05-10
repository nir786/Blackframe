CXX       = clang++
CXXFLAGS  = -std=c++20  -Wall -Wextra -Wpedantic -g -O0 -Iinclude -I/home/nir/Blackframe  -Ilibs/imgui -Ilibs/sol2/include -fcolor-diagnostics -MMD -MP -DDEBUG
LDFLAGS   = -lglfw -llua  -lGL

rwildcard = $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
SOURCES   = $(call rwildcard,$(SRC_DIR),*.cpp)
OBJECTS	  = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))



SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = bin
TARGET    = $(BIN_DIR)/Blackframe


$(info SRC_DIR = $(SRC_DIR))
$(info SOURCES = $(SOURCES))
$(info OBJECTS = $(OBJECTS))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean: 
	rm -rf $(BUILD_DIR) $(BIN_DIR)



run: all
	./$(TARGET)



DEPS	  := $(OBJECTS:.o=.d)
-include $(DEPS)


.PHONY: all clean run





