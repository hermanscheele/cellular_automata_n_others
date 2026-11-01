CXX      := clang++
CXXFLAGS := -std=c++17 -O2 -Iinclude
SFML     := $(shell pkg-config --cflags --libs sfml-graphics sfml-window sfml-system)
RAYLIB   := $(shell pkg-config --cflags --libs raylib)
BUILD    := build

APPS := life_2d record_2d life_3d record_3d brownian_motion_3d normal_dist_3d

all: $(addprefix $(BUILD)/,$(APPS))

$(BUILD):
	mkdir -p $@

# Game of Life, 2D (SFML)
$(BUILD)/life_2d $(BUILD)/record_2d: $(BUILD)/%: apps/%.cpp src/life.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $^ $(SFML) -o $@

# Game of Life, 3D (raylib)
$(BUILD)/life_3d $(BUILD)/record_3d: $(BUILD)/%: apps/%.cpp src/life.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $^ $(RAYLIB) -o $@

# Brownian motion paths in 3D (raylib)
$(BUILD)/brownian_motion_3d: apps/brownian_motion_3d.cpp src/brownian_motion.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $^ $(RAYLIB) -o $@

# Normal distribution histogram in 3D (raylib)
$(BUILD)/normal_dist_3d: apps/normal_dist_3d.cpp src/utils_3d.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $^ $(RAYLIB) -o $@

clean:
	rm -rf $(BUILD)

.PHONY: all clean
