PREFIX=$(DESTDIR)/usr
BINDIR=$(PREFIX)/bin

all: primon

.PHONY: all install

install: primon
	mkdir -p $(BINDIR)
	install primon $(BINDIR)/primon
