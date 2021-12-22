MAKE = make
SUBDIRS = $(ls -l | grep ^d | awk '{print $9." "}')

$(SUBDIRS): 
	for dir in $(SUBDIRS); do \
		@+$(MAKE) -C $$dir; \
	done

clean:$(SUBDIRS)
	
	$(MAKE) -C  clean