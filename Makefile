# Makefile to clean the current directory

# The clean target deletes all files in the directory except the Makefile
clean:
	@echo "Cleaning the current directory..."
	@rm -f *.out 2>/dev/null
	@echo "Cleaning complete."

.PHONY: clean
