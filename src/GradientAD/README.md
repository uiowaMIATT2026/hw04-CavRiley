# Gradient Anisotropic Diffusion Filter Analysis

## Parameter Effects on Smoothing and Edge Preservation

Gradient anisotropic diffusion smooths homogeneous regions while preserving edges by reducing diffusion near high-gradient areas.

### Conductance Parameter

Controls edge sensitivity:
- **Low (0.5-1.5)**: Preserves weak edges, less smoothing
- **Medium (2.0-3.0)**: Balanced edge preservation and smoothing
- **High (>4.0)**: More uniform smoothing, may blur edges

### Time Step

Controls diffusion amount per iteration:
- **Small (0.01-0.05)**: Stable but slow, needs more iterations
- **Medium (0.1-0.15)**: Good balance (typical choice)
- **Large (>0.2)**: Faster but risks instability/artifacts

Must satisfy stability condition (typically ≤ 0.25 for 3D).

### Number of Iterations

Controls total smoothing:
- **Few (1-3)**: Minimal smoothing
- **Moderate (5-10)**: Good noise suppression
- **Many (>15)**: Strong smoothing, potential edge loss

### Recommended Parameters

**Low noise**: Conductance = 2.0, Time step = 0.1, Iterations = 5

**Moderate noise**: Conductance = 3.0, Time step = 0.1, Iterations = 8

**High noise**: Conductance = 4.0, Time step = 0.1, Iterations = 10

### Key Advantage

Preserves sharp edges while smoothing noise, unlike Gaussian filters which blur everything uniformly.