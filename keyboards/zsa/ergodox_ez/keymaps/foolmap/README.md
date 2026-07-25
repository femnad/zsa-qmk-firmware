# Forgot How to Flash Again?

## Build and Flash

To compile the firmware for ErgoDox EZ (m32u4 base), run:

```bash
qmk compile -kb zsa/ergodox_ez/m32u4/base -km foolmap
```

To compile and flash in one step:

```bash
qmk flash -kb zsa/ergodox_ez/m32u4/base -km foolmap
```

*Note: Replace `m32u4/base` with your specific model (e.g., `m32u4/glow`, `stm32/base`) if needed.*

## Setup Requirements

If the `qmk` command fails, ensure your environment is set up:

1. **Install Python dependencies**:
   ```bash
   python3 -m pip install -r requirements.txt
   ```

2. **Initialize and sync submodules**:
   ```bash
   qmk git-submodule --sync
   ```
