# qviolet
cQASM interpreter written in C. The purpose of qviolet is to locally simulate a (preferably small) quantum system, on your machine.

Currently, qviolet is assumed to support cQASM v1.0. The detailed language specification can be found at https://arxiv.org/abs/1805.09607. If the project proves successful, support for v1.x or even 2.0 may be added in the future (don't bet on it).

## Building
```
git clone https://github.com/0xyoy/qviolet
cd qviolet
mkdir build
cd build
cmake ..
make
```

then, run with `./qviolet`.
