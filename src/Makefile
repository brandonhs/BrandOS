SUBDIRS = \
	kernel \

.PHONY: all clean

all:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir all; \
    done

clean:
	for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done
