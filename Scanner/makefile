# Definition der Variablen
HEADERDIR = includes
SRCDIR = src
OBJDIR = objs
BINDIRTEST = debug
AUTOMATDIR = ../Automat
BUFFERDIR = ../Buffer
SYMBOLTABLEDIR = ../Symboltable

# hier alle Object Files eintragen, ausser das File mit der Mainmethode
# darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Scanner.o \
	$(OBJDIR)/Information.o \
	$(OBJDIR)/Token.o

# linken der Object-files 
makeTestScanner: $(OBJS) ScannerTest

$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

ScannerTest: $(SRCDIR)/TestScanner.cpp $(HEADERDIR)/Scanner.h
	g++ -g  -c -Wall src/TestScanner.cpp -o $(BINDIRTEST)/TestScanner.o
	g++ -g $(BINDIRTEST)/TestScanner.o $(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/ScannerTest  

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen
cleanScanner:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestScanner

