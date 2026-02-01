# Paths
SRC := src/*.c
INCLUDE := -Iinclude
RUST_LIB := rust/target/release/librust.a

CFLAGS_DEBUG := -Wall -Wextra -pedantic-errors -g $(INCLUDE) $(RUST_LIB)
CFLAGS_RELEASE := -O3 -flto -DNDEBUG -mtune=generic -march=x86-64 $(INCLUDE) $(RUST_LIB)

BIN := bin/tgpc
BIN_DEBUG := bin/tgpc-debug
TEST_BIN := bin/tgpc-tests
TEST_SRC := tests/tests.c

all: $(BIN_DEBUG)

$(BIN_DEBUG): $(SRC)
	gcc $(SRC) $(CFLAGS_DEBUG) -o $(BIN_DEBUG)

release: $(SRC)
	gcc $(SRC) $(CFLAGS_RELEASE) -o $(BIN)

run: $(BIN_DEBUG)
	./$(BIN_DEBUG)

build: release
	mv ./$(BIN) ~/.local/bin/tgpc

install: release
	mv ./$(BIN) ~/.local/bin/tgpc

clean:
	rm -f $(BIN) $(BIN_DEBUG) $(TEST_BIN)

# Test target
tests: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(SRC)
	gcc $(TEST_SRC) $(SRC) $(CFLAGS_DEBUG) -DTESTING -o $(TEST_BIN)
