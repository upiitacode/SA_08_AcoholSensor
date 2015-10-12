.PHONY: test clean dist_clean test_clean
all: build
build:
	make --directory=./gcc
burn:
	make --directory=./gcc burn
test:
	make --directory=./tests test
clean:
	make --directory=./gcc clean
test_clean:
	make --directory=./tests clean
dist_clean: clean
	make --directory=./tests dist_clean
