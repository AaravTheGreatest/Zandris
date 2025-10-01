UNAME_S := $(shell uname -s)
CXX := g++
ifeq ($(UNAME_S),Darwin)
    CXX := clang++
endif

CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -Iinclude
LDFLAGS := -lsfml-window -lsfml-graphics -lsfml-system

SRC_DIR := src
BUILD_DIR := build

ifeq ($(OS),Windows_NT)
    MKDIR := mkdir $(BUILD_DIR) 2>nul || echo ""
    RM := del /Q $(BUILD_DIR)\* 2>nul && rmdir $(BUILD_DIR)
else
    MKDIR := mkdir -p $(BUILD_DIR)
    RM := rm -rf $(BUILD_DIR)
endif

# --- Targets ---
all: game textGame

# --- Game (graphics) ---
GRAPHIC_SRCS := $(SRC_DIR)/Main.cpp $(SRC_DIR)/glad.c
GRAPHIC_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(GRAPHIC_SRCS))) \
                $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(GRAPHIC_SRCS)))

game: $(BUILD_DIR) $(GRAPHIC_OBJS)
	$(CXX) -o $@ $(GRAPHIC_OBJS) $(LDFLAGS)

# --- Text-only game ---
TEXT_SRCS := $(SRC_DIR)/main.cpp
TEXT_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEXT_SRCS))

textGame: $(BUILD_DIR) $(TEXT_OBJS)
	$(CXX) -o $@ $(TEXT_OBJS)

# --- Build directory ---
$(BUILD_DIR):
	$(MKDIR)

# --- Compile rules ---
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM)

.PHONY: all clean
