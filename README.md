# Directional Field Plotter (DiFiPlotter)

A C++ study project for visualizing directional fields of differential equations using SFML.

## Purpose

This project is designed as a learning tool to:
- Practice C++ programming concepts
- Study differential equations visually
- Learn SFML graphics programming
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
- [ ] Color-code arrows based on slope magnitude
- [ ] Add different differential equations to study:
  - [ ] dy/dx = x (simple linear)
  - [ ] dy/dx = y (exponential)
  - [ ] dy/dx = -x/y (circular)
  - [ ] dy/dx = x + y
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

## Differential Equations to Study

1. **dy/dx = x**
   - Linear growth
   - Solutions: y = x²/2 + C

2. **dy/dx = y**
   - Exponential growth/decay
   - Solutions: y = Ce^x

3. **dy/dx = -x/y**
   - Circular/elliptical solutions
   - Solutions: x² + y² = C

4. **dy/dx = x + y**
   - Combined linear and exponential
   - More complex behavior

5. **dy/dx = sin(x) + cos(y)**
   - Trigonometric field
   - Periodic behavior

## Learning Resources

### C++ Concepts to Practice
- Classes and object-oriented design
- STL containers (vector, function)
- Function pointers/lambdas
- Mathematical computations
- Graphics programming with SFML

### Differential Equations Concepts
- First-order ODEs
- Direction fields
- Solution curves (integral curves)
- Equilibrium points
- Stability analysis
- Numerical methods (Euler's method)
