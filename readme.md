
# Minor-2

A 2D Game Engine made with OpenGL and WebAssembly

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Installing

1. Install Emscripten:

	http://emscripten.org

2. Clone this repo:

	`git clone https://github.com/sauravstark/Minor-2`
	
3. Change Directory:

	`cd Minor-2`

4.  Build index.js and index.wasm:
    
    `emcc main.cpp -std=c++17 -s WASM=1 -s USE_SDL=2 -O3 -o index.js --embed-file assets`
    
5.  Start a webserver:

	`python -m http.server 8080`