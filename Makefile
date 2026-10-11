.PHONY: all simulator validate
all:
	bash scripts/build.sh device
simulator:
	bash scripts/build.sh simulator
validate:
	python3 scripts/validate-source.py
