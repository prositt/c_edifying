# initial test for makefile

center: center.c center.h
	@echo "Generating center from .c & .h"
	gcc center.c -o bin/center
