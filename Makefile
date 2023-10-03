CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC_DIR = /Users/pradyundevarakonda/Documents/miniC/src#The path to 'src' folder of this repo
OUTPUT_DIR = /Users/pradyundevarakonda/Documents/miniC/src/Output#The path to 'output' folder in src
OUTPUT_NAME = main
SRC_FILES = main.c interpreter.c variable.c print.c arithmetic.c condition.c

all: $(OUTPUT_NAME)

$(OUTPUT_NAME): $(SRC_FILES:%.c=$(SRC_DIR)/%.o)
	$(CC) $(CFLAGS) $^ -o $(OUTPUT_DIR)/$@

$(SRC_FILES:%.c=$(SRC_DIR)/%.o): $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_FILES:%.c=$(SRC_DIR)/%.o) $(OUTPUT_DIR)/$(OUTPUT_NAME)

