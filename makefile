CFLAGS = -Wall

OBJECTS = 1-1 \
	1-2 \
	1-3 \
	1-4 \
	1-5 \
	1-6 \
	1-7 \
	1-8 \
	1-9 \
	1-10 \
	1-12 \
	1-13 \
	1-14 \
	1-15 \
	1-16 \
	1-17 \
	1-18 \
	1-19 \
	1-20 \
	1-21 \
	1-22 \
	1-23 \
	1-24 \
	2-1 \
	2-2 \
	2-3 \
	2-4 \
	2-5 \
	2-6 \
	2-7 \
	2-8 \
	2-9 \
	2-10 \
	3-1 \
	3-2 \
	3-3 \
	3-4 \
	3-5 \
	3-6 \
	4-1 \
	4-2 \
	4-3
		
all: $(OBJECTS)

clean:
	-rm $(OBJECTS)
