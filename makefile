SOURCE_FILES=main.c file.c
INCLUDE_DIR=.
TARGET_FILE=main
OUTPUT_DIR=build
TARGET=$(OUTPUT_DIR)/$(TARGET_FILE)


.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SOURCE_FILES)
	mkdir -p $(OUTPUT_DIR)
	gcc -g $^ -I$(INCLUDE_DIR) -o $(TARGET)

clean:
	rm -rf $(OUTPUT_DIR)
