default: exec

build_directory:
	rm -r build || true
	mkdir build || true

build_linux: build_directory
	clang prog1.c -o build/prog1.o

build_windows: build_directory
	clang -I C:\libs\c\includes\10.0.18362.0\ucrt -c prog1.c -o build\prog1.exe

exec_linux: build_linux
	./build/prog1.o

exec_windows: build_windows
	.\build\prog1.exe

exec:
	echo "Choose your system operation: make exec_linux or nmake exec_windows"

clean:
	rm -r build