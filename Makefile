CC = @g++
LDFLAGS = -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lGLEW -lSOIL -lGL -lGLU -lnanogui
SRCS = $(shell find src/ -type f -name '*.cxx')
OBJ = $(SRCS:.cxx=.o)
CFLAGS = -c -fconcepts -fpermissive
OUTFILE = lovelyEngine.exec

# CL = color
CL_LIGHT_BLUE = \e[94m
CL_RESET = \e[39m
CL_GREEN = \e[32m

all: $(OUTFILE)
	@printf "$(CL_GREEN)DONE$(CL_RESET)\n";

$(OUTFILE): $(OBJ)
	@printf "Linking: $(CL_LIGHT_BLUE)$^$(CL_RESET) ---> Creating: $@\n";
	$(CC) $^ $(LDFLAGS) -o $@

clean:
	rm $(OBJ) || @echo "" # Just to catch some file not found errors
	
run:
	./$(OUTFILE)
	
%.o: %.cxx
	@printf "Compiling: $@\n";
	$(CC) $(CFLAGS) $< -o $@
