#
# Specifiy the target
all:	Jean-BaptisteJunhson-jjeanba2-Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Jean-BaptisteJunhson-jjeanba2-Hello:	Jean-BaptisteJunhson-jjeanba2-Hello.o Hello_Class.o
	g++  Jean-BaptisteJunhson-jjeanba2-Hello.o Hello_Class.o -o Jean-BaptisteJunhson-jjeanba2-Hello.exe

# Specify how the object files should be created from source files
Jean-BaptisteJunhson-jjeanba2-Hello.o:	Jean-BaptisteJunhson-jjeanba2-Hello.cpp
	g++ -c Jean-BaptisteJunhson-jjeanba2-Hello.cpp

# Create the Hello_Class.o file
Hello_Class.o: Hello_Class.cpp
	g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Jean-BaptisteJunhson-jjeanba2-Hello.exe

