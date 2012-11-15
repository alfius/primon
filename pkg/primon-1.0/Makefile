PREFIX=$(DESTDIR)/usr
BINDIR=$(PREFIX)/bin
PIXMAPDIR=$(PREFIX)/share/pixmaps
DESKTOPDIR=$(PREFIX)/share/applications

all: primon

.PHONY: all install

install: primon
	mkdir -p $(BINDIR)
	mkdir -p $(PIXMAPDIR)
	mkdir -p $(DESKTOPDIR)
	install primon $(BINDIR)/primon
	install primon.xpm $(PIXMAPDIR)
	install primon.desktop $(DESKTOPDIR)
