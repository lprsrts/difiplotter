# Directional Field Plotter (DiFiPlotter)

A C++ study project for visualizing directional fields of differential equations using SFML.

## Purpose

This project is designed as a learning tool to:
- Practice C++ programming concepts
- Learn SFML graphics programming
- Study differential equations visually
- Understand numerical methods for ODE visualization

## What is a Directional Field?

A directional field (or slope field) is a visual representation of a first-order differential equation dy/dx = f(x,y). At each point (x,y) in the coordinate plane, we draw a small line segment with slope f(x,y). This helps us understand the behavior of solutions without solving the equation analytically.

## Project Structure

```
difiplotter/
├── CMakeLists.txt         # Build configuration
├── README.md
├── src/                   # Source files
├── assets/                # Future: resources, fonts
└── build/                 # Build directory
```

## Getting Started

### Build and Run

```bash
mkdir build && cd build
cmake ..
make
./difiplotter
```

## Study Goals & Implementation Tasks

### Phase 1: Basic Setup ✓
- [x] Project structure
- [x] SFML window creation
- [x] Basic event handling

### Phase 2: Coordinate System
- [x] Implement world-to-screen coordinate conversion
- [ ] Draw coordinate axes (x and y)
- [ ] Add grid lines for reference
- [ ] Implement zooming and panning

### Phase 3: Directional Field Visualization
- [x] Implement slope calculation at grid points
- [x] Draw direction lines
- [x] Color-code arrows based on slope magnitude
- [ ] Add different differential equations to study:
  - [x] dy/dx = x (simple linear)
  - [x] dy/dx = y (exponential)
  - [x] dy/dx = -x/y (circular)
  - [x] dy/dx = x + y
  - [ ] dy/dx = sin(x) + cos(y)

### Phase 4: Interactive Features
- [ ] Switch between different equations with keyboard
- [ ] Adjust arrow density
- [ ] Click to draw solution curves (integral curves)
- [ ] Display equation information on screen

### Phase 5: Advanced Features
- [ ] Animate solution curves
- [ ] Load equations from config file
- [ ] Export plots as images
- [ ] Add equilibrium point detection
