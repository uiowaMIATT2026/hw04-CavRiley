# Curvature Anisotropic Diffusion Filter Analysis

## Parameter Effects on Smoothing and Edge Preservation

Curvature anisotropic diffusion uses edge curvature (in addition to gradient magnitude) to control diffusion, providing superior edge preservation compared to gradient-based methods.

### Conductance Parameter

Controls edge sensitivity:
- **Low (0.5-1.5)**: Strong edge preservation, minimal smoothing near boundaries
- **Medium (2.0-3.0)**: Balanced smoothing and edge retention
- **High (>4.0)**: More aggressive smoothing, reduced edge selectivity

### Time Step

Controls diffusion rate per iteration:
- **Small (0.01-0.05)**: Very stable, requires more iterations
- **Medium (0.0625-0.125)**: Good stability and efficiency
- **Large (>0.15)**: Risk of numerical instability

Must satisfy CFL stability condition (typically ≤ 0.125 for 3D curvature diffusion).

### Number of Iterations

Controls total smoothing strength:
- **Few (1-3)**: Light smoothing
- **Moderate (5-10)**: Effective noise reduction
- **Many (>15)**: Heavy smoothing, may over-smooth features

### Recommended Parameters

**Low noise**: Conductance = 1.5, Time step = 0.0625, Iterations = 5

**Moderate noise**: Conductance = 2.5, Time step = 0.0625, Iterations = 8

**High noise**: Conductance = 3.5, Time step = 0.0625, Iterations = 12
