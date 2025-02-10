# Compiler and flags
RISCV_GCC = riscv32-unknown-elf-gcc
RISCV_OBJDUMP = riscv32-unknown-elf-objdump
RISCV_OBJCOPY = riscv32-unknown-elf-objcopy
RISCV_ARCH = -march=rv32imc -mabi=ilp32
CFLAGS = -Wall -O2 $(RISCV_ARCH)
LDFLAGS = -nostartfiles -T simple_system.ld

# Source files
SRC = fibonacci.c
ELF = fibonacci.elf
HEX = fibonacci.hex
DUMP = fibonacci.dump

# Verilator
VERILATOR_DIR = dv/verilator
VERILATOR_BIN = $(VERILATOR_DIR)/obj_dir/Vibex_simple_system

# Default target
all: $(HEX)

# Compile to ELF
$(ELF): $(SRC)
	$(RISCV_GCC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Generate HEX file for Ibex simple system
$(HEX): $(ELF)
	$(RISCV_OBJCOPY) -O verilog $< $@

# Generate disassembly
$(DUMP): $(ELF)
	$(RISCV_OBJDUMP) -D $< > $@

# Run in Verilator simulation
run: $(HEX)
	make -C $(VERILATOR_DIR) hello
	$(VERILATOR_BIN)

# Clean files
clean:
	rm -f $(ELF) $(HEX) $(DUMP)
