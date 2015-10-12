.PHONY: test clean dist_clean
all: test
test:
	make --directory=./tests test
clean:
	make --directory=./tests clean
dist_clean:
	make --directory=./tests dist_clean
