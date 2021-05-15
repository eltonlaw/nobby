# 3D Printing Firmware

## Testing

Run unit tests

    cmake . && make && CTEST_OUTPUT_ON_FAILURE=1 make test

Run CLI

    cmake . && make && ./nobby/nobbyd
