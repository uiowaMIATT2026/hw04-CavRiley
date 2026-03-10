# Gaussian Low-Pass Filter Analysis

## Effect of Sigma on Smoothing and Image Resolution

### Smoothing Characteristics

By increasing the sigma (σ) value of the Gaussian low-pass filter, the blurring effect becomes more intense. This occurs because a larger σ value creates a wider Gaussian kernel, which averages pixel values over a larger neighborhood. The relationship between σ and the kernel size is fundamental to understanding the filter's behavior:

- **Small σ (e.g., σ = 0.5-1.0)**: Minimal smoothing, preserves fine details and textures
- **Medium σ (e.g., σ = 2.0-3.0)**: Moderate smoothing, reduces noise while maintaining major structures but reduces resolution
- **Large σ (e.g., σ > 3.0)**: Heavy smoothing, significant noise reduction but substantial detail loss

### Loss of Image Resolution

The tradeoff between noise reduction and detail preservation is inherent to Gaussian filtering:

1. **Edge Degradation**: As σ increases, sharp edges become progressively blurred. High-frequency components representing edges and fine details are attenuated more strongly.

2. **Feature Loss**: Small anatomical structures and texture information are increasingly lost with larger σ values. Features smaller than approximately 3σ in size become difficult to distinguish.

3. **Contrast Reduction**: The local contrast around boundaries and interfaces decreases as the filter size grows, making it harder to distinguish between adjacent regions.

### Optimal Parameter Selection

For the noisy test images, an optimal σ value balances noise suppression against detail preservation:

- For low-noise images: σ = 1.0-1.5 provides gentle smoothing
- For moderate noise: σ = 2.0-3.0 offers good noise reduction while preserving major structures
- For high-noise images: σ = 3.5-5.0 may be necessary, though significant detail loss occurs

The choice depends on the specific application requirements and the acceptable level of resolution loss.