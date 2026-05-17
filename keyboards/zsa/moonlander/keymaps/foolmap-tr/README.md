# Forgot How to Flash Again?

## Build and Flash

To compile the firmware for Moonlander (Revision A), run:

```bash
make zsa/moonlander/reva:foolmap-tr
```

To compile and flash in one step:

```bash
make zsa/moonlander/reva:foolmap-tr:flash
```

## Setup Requirements

If the `make` command fails with "No rule to make target", ensure your environment is set up:

1. **Install Python dependencies**:
   ```bash
   python3 -m pip install -r requirements.txt
   ```

2. **Initialize and sync submodules**:
   ```bash
   qmk git-submodule --sync
   ```
