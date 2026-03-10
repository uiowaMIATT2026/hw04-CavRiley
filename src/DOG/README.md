# Difference of Gaussians (DOG) Filter Analysis

## Effect of σ1 and σ2 on Edge Response

### Fundamental Principle

The DOG filter subtracts two Gaussian-blurred images (DOG(f) = Gσ1(f) - Gσ2(f)), creating a band-pass filter that highlights edges at specific scales while suppressing noise and gradual intensity variations.

### Parameter Effects

**σ1 (smaller sigma)** controls fine-scale sensitivity:
- Small σ1 (0.5-1.0): Detects sharp edges and fine details, more sensitive to noise
- Larger σ1 (2.0-3.0): Smoother response, reduced noise sensitivity, may miss fine edges

**σ2 (larger sigma)** controls coarse-scale component:
- Moderate σ2 (2.0-3.0): Narrow scale range when close to σ1
- Large σ2 (>5.0): Broader scale detection

### Effect of σ2 - σ1 Difference

**Small difference (<1.0)**: Narrow band-pass, detects edges at specific scales, weak enhancement

**Moderate difference (1.0-2.0)**: Balanced edge detection, good for most applications
- Example: σ1 = 1.5, σ2 = 3.0

**Large difference (>2.0)**: Broad band-pass, strong enhancement but may include noise

### Scale Ratio (σ2/σ1)

- **1.2-1.6**: Fine-scale edges and textures
- **1.6-2.0**: Medium-scale edges (balanced)
- **>2.0**: Large-scale boundaries

### Experimental Observations

- Sharp edges: Best with smaller σ1 and moderate difference
- Gradual boundaries: Require larger σ values with sufficient separation
- Noise reduction: Increase both σ1 and σ2 while maintaining difference
- Edge localization: Smaller σ values give better spatial precision

### Recommended Parameters

- High-resolution edges: σ1 = 1.0, σ2 = 2.0
- General edge enhancement: σ1 = 1.5, σ2 = 3.0
- Large structures: σ1 = 2.5, σ2 = 5.0