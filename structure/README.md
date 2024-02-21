# Project structure for pel 2023/2024


Compile each file in src as object file

```bash
g++ -std=c++11 -c src/myfunction.cpp -o build/myfunction.o -I include/
```

Compile main
```bash
g++ -std=c++11 tools/myapp.cpp -I include build/myfunction.o -o build/myapp
```
