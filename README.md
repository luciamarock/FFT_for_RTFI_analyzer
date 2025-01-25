# FFT Implementation for Real-Time Frequency Identifier (RTFI) Analyzer

Welcome to the FFT_for_RTFI_analyzer repository. This repository contains a personalized implementation of the Fast Fourier Transform (FFT) algorithm, designed to be used alongside the Polyphonic Pitch Detector algorithm available on my GitHub profile.

## Purpose and Overview

The main goal of this implementation is to provide a robust and efficient Fast Fourier Transform (FFT) algorithm for real-time frequency analysis. The FFT algorithm is utilized here to accurately identify and analyze the frequencies present in audio signals. This implementation complements the Polyphonic Pitch Detector algorithm by enhancing the accuracy and reliability of frequency identification.

## Getting Started

To execute the code, follow these steps:

1. Clone the repository to your local machine
2. Navigate to the repository directory
3. Make sure you have Python installed with the required dependencies:
   - numpy
   - matplotlib
4. Run the `start.sh` script using:
   ```bash
   ./start.sh
   ```
   This will:
   - Execute the FFT implementation
   - Generate frequency amplitude data
   - Display the resulting frequency plot

For a visual guide on how to run the code, you can watch the demonstration video at the following link: [Execution Demonstration](https://youtu.be/w8N4eMQA5dQ).

## Usage and Integration

1. **Prepare Input**:
   - Place your WAV audio file in the `./audiofiles/` directory (the code expects `short.wav`)
   - The code supports files up to 4096 samples (defined in `N` constant)

2. **Run the Analysis**:
   Execute the `start.sh` script:
   ```bash
   ./start.sh
   ```
   This script will:
   - Run the C implementation of FFT via `plotter.py`
   - Run the Python reference implementation via `analyzer.py`
   - Display both results for comparison

3. **What Happens Under the Hood**:

   a. The C implementation (`fft.c`):
   - Reads the WAV file
   - Processes it through the FFT algorithm
   - Outputs two files:
     - `ampiezza.txt`: Contains the FFT magnitude values
     - `ascisse.txt`: Contains the frequency values

   b. The Python implementation (`analyzer.py`):
   - Reads the same WAV file
   - Performs FFT using NumPy's implementation
   - Displays the results directly

4. **View Results**:
   You'll see two plots:
   - From `plotter.py`: Shows the C implementation results
   - From `analyzer.py`: Shows:
     - Top plot: Original audio signal in time domain
     - Bottom plot: Frequency spectrum after FFT

5. **Clean Up**:
   After analysis, temporary files are automatically cleaned using `clean.sh`:
   ```bash
   ./clean.sh
   ```

**Typical Usage Example**:
```bash
# 1. Place your WAV file in audiofiles/short.wav
# 2. Run the analysis
./start.sh
# 3. View the plots that appear
# 4. Files are automatically cleaned up
```

The main advantage of this workflow is that it allows you to:
- Verify the C implementation against Python's NumPy FFT
- Visualize both time and frequency domain representations
- Compare results easily through plots
- Keep the workspace clean with automatic cleanup

Note: The implementation is specifically designed for real-time frequency analysis and is optimized for integration with the Polyphonic Pitch Detector algorithm.

## Contribution and Feedback

The FFT implementation in this repository can be seamlessly integrated with the Polyphonic Pitch Detector algorithm available on my GitHub profile. By combining these two algorithms, you can create a comprehensive real-time frequency analysis tool for audio signals.

Contributions, suggestions, and feedback are always welcome. If you find ways to optimize the implementation, improve its accuracy, or enhance its functionalities, please don't hesitate to create a pull request or reach out to me via the contact information provided below.