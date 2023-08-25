#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[257];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 256,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x64\x01\x64\x02\x6c\x02\x5a\x02\x64\x01\x64\x02\x6c\x03\x5a\x03\x64\x01\x64\x02\x6c\x04\x5a\x04\x64\x01\x64\x02\x6c\x05\x5a\x05\x65\x01\x6a\x06\x65\x01\x6a\x07\x67\x02\x61\x08\x64\x02\x61\x09\x64\x02\x61\x0a\x64\x02\x61\x0b\x64\x03\x84\x00\x5a\x0c\x64\x04\x84\x00\x5a\x0d\x64\x05\x84\x00\x5a\x0e\x64\x06\x84\x00\x5a\x0f\x64\x07\x84\x00\x5a\x10\x64\x08\x84\x00\x5a\x11\x64\x1c\x64\x09\x84\x01\x5a\x12\x64\x0a\x84\x00\x5a\x13\x64\x0b\x84\x00\x5a\x14\x64\x0c\x84\x00\x5a\x15\x64\x0d\x84\x00\x5a\x16\x64\x0e\x84\x00\x5a\x17\x64\x0f\x84\x00\x5a\x18\x64\x1c\x64\x10\x84\x01\x5a\x19\x64\x1c\x64\x11\x84\x01\x5a\x1a\x64\x12\x84\x00\x5a\x1b\x64\x13\x84\x00\x5a\x1c\x64\x14\x84\x00\x5a\x1d\x64\x15\x84\x00\x5a\x1e\x64\x16\x84\x00\x5a\x1f\x64\x17\x84\x00\x5a\x20\x64\x18\x84\x00\x5a\x21\x64\x19\x84\x00\x5a\x22\x65\x01\x6a\x23\x6a\x24\x73\x72\x65\x22\xa9\x00\x01\x00\x64\x1a\x84\x00\x5a\x25\x65\x26\x64\x1b\x6b\x02\x72\x7e\x65\x25\xa9\x00\x01\x00\x64\x02\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2999];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2998,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x70\x70\x65\x6e\x64\x20\x6d\x6f\x64\x75\x6c\x65\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x73\x20\x66\x6f\x72\x20\x74\x68\x69\x72\x64\x2d\x70\x61\x72\x74\x79\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x2e\x0a\x0a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x0a\x2a\x20\x54\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x20\x64\x75\x72\x69\x6e\x67\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x61\x74\x69\x6f\x6e\x2e\x20\x2a\x0a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x2a\x0a\x0a\x54\x68\x69\x73\x20\x77\x69\x6c\x6c\x20\x61\x70\x70\x65\x6e\x64\x20\x73\x69\x74\x65\x2d\x73\x70\x65\x63\x69\x66\x69\x63\x20\x70\x61\x74\x68\x73\x20\x74\x6f\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x2e\x20\x20\x4f\x6e\x0a\x55\x6e\x69\x78\x20\x28\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x4d\x61\x63\x20\x4f\x53\x58\x29\x2c\x20\x69\x74\x20\x73\x74\x61\x72\x74\x73\x20\x77\x69\x74\x68\x20\x73\x79\x73\x2e\x70\x72\x65\x66\x69\x78\x20\x61\x6e\x64\x0a\x73\x79\x73\x2e\x65\x78\x65\x63\x5f\x70\x72\x65\x66\x69\x78\x20\x28\x69\x66\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x29\x20\x61\x6e\x64\x20\x61\x70\x70\x65\x6e\x64\x73\x0a\x6c\x69\x62\x2f\x70\x79\x74\x68\x6f\x6e\x3c\x76\x65\x72\x73\x69\x6f\x6e\x3e\x2f\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x2e\x0a\x4f\x6e\x20\x6f\x74\x68\x65\x72\x20\x70\x6c\x61\x74\x66\x6f\x72\x6d\x73\x20\x28\x73\x75\x63\x68\x20\x61\x73\x20\x57\x69\x6e\x64\x6f\x77\x73\x29\x2c\x20\x69\x74\x20\x74\x72\x69\x65\x73\x20\x65\x61\x63\x68\x20\x6f\x66\x20\x74\x68\x65\x0a\x70\x72\x65\x66\x69\x78\x65\x73\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x2c\x20\x61\x73\x20\x77\x65\x6c\x6c\x20\x61\x73\x20\x77\x69\x74\x68\x20\x6c\x69\x62\x2f\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x61\x70\x70\x65\x6e\x64\x65\x64\x2e\x20\x20\x54\x68\x65\x0a\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x2c\x20\x69\x66\x20\x74\x68\x65\x79\x20\x65\x78\x69\x73\x74\x2c\x20\x61\x72\x65\x20\x61\x70\x70\x65\x6e\x64\x65\x64\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x2c\x20\x61\x6e\x64\x0a\x61\x6c\x73\x6f\x20\x69\x6e\x73\x70\x65\x63\x74\x65\x64\x20\x66\x6f\x72\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x66\x69\x6c\x65\x73\x2e\x0a\x0a\x49\x66\x20\x61\x20\x66\x69\x6c\x65\x20\x6e\x61\x6d\x65\x64\x20\x22\x70\x79\x76\x65\x6e\x76\x2e\x63\x66\x67\x22\x20\x65\x78\x69\x73\x74\x73\x20\x6f\x6e\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x62\x6f\x76\x65\x20\x73\x79\x73\x2e\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x2c\x0a\x73\x79\x73\x2e\x70\x72\x65\x66\x69\x78\x20\x61\x6e\x64\x20\x73\x79\x73\x2e\x65\x78\x65\x63\x5f\x70\x72\x65\x66\x69\x78\x20\x61\x72\x65\x20\x73\x65\x74\x20\x74\x6f\x20\x74\x68\x61\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x6e\x64\x0a\x69\x74\x20\x69\x73\x20\x61\x6c\x73\x6f\x20\x63\x68\x65\x63\x6b\x65\x64\x20\x66\x6f\x72\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x28\x73\x79\x73\x2e\x62\x61\x73\x65\x5f\x70\x72\x65\x66\x69\x78\x20\x61\x6e\x64\x0a\x73\x79\x73\x2e\x62\x61\x73\x65\x5f\x65\x78\x65\x63\x5f\x70\x72\x65\x66\x69\x78\x20\x77\x69\x6c\x6c\x20\x61\x6c\x77\x61\x79\x73\x20\x62\x65\x20\x74\x68\x65\x20\x22\x72\x65\x61\x6c\x22\x20\x70\x72\x65\x66\x69\x78\x65\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x50\x79\x74\x68\x6f\x6e\x0a\x69\x6e\x73\x74\x61\x6c\x6c\x61\x74\x69\x6f\x6e\x29\x2e\x20\x49\x66\x20\x22\x70\x79\x76\x65\x6e\x76\x2e\x63\x66\x67\x22\x20\x28\x61\x20\x62\x6f\x6f\x74\x73\x74\x72\x61\x70\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x66\x69\x6c\x65\x29\x20\x63\x6f\x6e\x74\x61\x69\x6e\x73\x0a\x74\x68\x65\x20\x6b\x65\x79\x20\x22\x69\x6e\x63\x6c\x75\x64\x65\x2d\x73\x79\x73\x74\x65\x6d\x2d\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x22\x20\x73\x65\x74\x20\x74\x6f\x20\x61\x6e\x79\x74\x68\x69\x6e\x67\x20\x6f\x74\x68\x65\x72\x20\x74\x68\x61\x6e\x20\x22\x66\x61\x6c\x73\x65\x22\x0a\x28\x63\x61\x73\x65\x2d\x69\x6e\x73\x65\x6e\x73\x69\x74\x69\x76\x65\x29\x2c\x20\x74\x68\x65\x20\x73\x79\x73\x74\x65\x6d\x2d\x6c\x65\x76\x65\x6c\x20\x70\x72\x65\x66\x69\x78\x65\x73\x20\x77\x69\x6c\x6c\x20\x73\x74\x69\x6c\x6c\x20\x61\x6c\x73\x6f\x20\x62\x65\x0a\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x3b\x20\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x74\x68\x65\x79\x20\x77\x6f\x6e\x27\x74\x2e\x0a\x0a\x41\x6c\x6c\x20\x6f\x66\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x73\x69\x74\x65\x2d\x73\x70\x65\x63\x69\x66\x69\x63\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x2c\x20\x69\x66\x20\x74\x68\x65\x79\x20\x65\x78\x69\x73\x74\x2c\x20\x61\x72\x65\x0a\x61\x70\x70\x65\x6e\x64\x65\x64\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x2c\x20\x61\x6e\x64\x20\x61\x6c\x73\x6f\x20\x69\x6e\x73\x70\x65\x63\x74\x65\x64\x20\x66\x6f\x72\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x0a\x66\x69\x6c\x65\x73\x2e\x0a\x0a\x41\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x66\x69\x6c\x65\x20\x69\x73\x20\x61\x20\x66\x69\x6c\x65\x20\x77\x68\x6f\x73\x65\x20\x6e\x61\x6d\x65\x20\x68\x61\x73\x20\x74\x68\x65\x20\x66\x6f\x72\x6d\x0a\x3c\x70\x61\x63\x6b\x61\x67\x65\x3e\x2e\x70\x74\x68\x3b\x20\x69\x74\x73\x20\x63\x6f\x6e\x74\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x61\x64\x64\x69\x74\x69\x6f\x6e\x61\x6c\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x28\x6f\x6e\x65\x20\x70\x65\x72\x20\x6c\x69\x6e\x65\x29\x0a\x74\x6f\x20\x62\x65\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x2e\x20\x20\x4e\x6f\x6e\x2d\x65\x78\x69\x73\x74\x69\x6e\x67\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x28\x6f\x72\x0a\x6e\x6f\x6e\x2d\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x29\x20\x61\x72\x65\x20\x6e\x65\x76\x65\x72\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x3b\x20\x6e\x6f\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x0a\x73\x79\x73\x2e\x70\x61\x74\x68\x20\x6d\x6f\x72\x65\x20\x74\x68\x61\x6e\x20\x6f\x6e\x63\x65\x2e\x20\x20\x42\x6c\x61\x6e\x6b\x20\x6c\x69\x6e\x65\x73\x20\x61\x6e\x64\x20\x6c\x69\x6e\x65\x73\x20\x62\x65\x67\x69\x6e\x6e\x69\x6e\x67\x20\x77\x69\x74\x68\x0a\x27\x23\x27\x20\x61\x72\x65\x20\x73\x6b\x69\x70\x70\x65\x64\x2e\x20\x4c\x69\x6e\x65\x73\x20\x73\x74\x61\x72\x74\x69\x6e\x67\x20\x77\x69\x74\x68\x20\x27\x69\x6d\x70\x6f\x72\x74\x27\x20\x61\x72\x65\x20\x65\x78\x65\x63\x75\x74\x65\x64\x2e\x0a\x0a\x46\x6f\x72\x20\x65\x78\x61\x6d\x70\x6c\x65\x2c\x20\x73\x75\x70\x70\x6f\x73\x65\x20\x73\x79\x73\x2e\x70\x72\x65\x66\x69\x78\x20\x61\x6e\x64\x20\x73\x79\x73\x2e\x65\x78\x65\x63\x5f\x70\x72\x65\x66\x69\x78\x20\x61\x72\x65\x20\x73\x65\x74\x20\x74\x6f\x0a\x2f\x75\x73\x72\x2f\x6c\x6f\x63\x61\x6c\x20\x61\x6e\x64\x20\x74\x68\x65\x72\x65\x20\x69\x73\x20\x61\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x2f\x75\x73\x72\x2f\x6c\x6f\x63\x61\x6c\x2f\x6c\x69\x62\x2f\x70\x79\x74\x68\x6f\x6e\x32\x2e\x35\x2f\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x0a\x77\x69\x74\x68\x20\x74\x68\x72\x65\x65\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x2c\x20\x66\x6f\x6f\x2c\x20\x62\x61\x72\x20\x61\x6e\x64\x20\x73\x70\x61\x6d\x2c\x20\x61\x6e\x64\x20\x74\x77\x6f\x20\x70\x61\x74\x68\x0a\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x66\x69\x6c\x65\x73\x2c\x20\x66\x6f\x6f\x2e\x70\x74\x68\x20\x61\x6e\x64\x20\x62\x61\x72\x2e\x70\x74\x68\x2e\x20\x20\x41\x73\x73\x75\x6d\x65\x20\x66\x6f\x6f\x2e\x70\x74\x68\x20\x63\x6f\x6e\x74\x61\x69\x6e\x73\x20\x74\x68\x65\x0a\x66\x6f\x6c\x6c\x6f\x77\x69\x6e\x67\x3a\x0a\x0a\x20\x20\x23\x20\x66\x6f\x6f\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x0a\x20\x20\x66\x6f\x6f\x0a\x20\x20\x62\x61\x72\x0a\x20\x20\x62\x6c\x65\x74\x63\x68\x0a\x0a\x61\x6e\x64\x20\x62\x61\x72\x2e\x70\x74\x68\x20\x63\x6f\x6e\x74\x61\x69\x6e\x73\x3a\x0a\x0a\x20\x20\x23\x20\x62\x61\x72\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x0a\x20\x20\x62\x61\x72\x0a\x0a\x54\x68\x65\x6e\x20\x74\x68\x65\x20\x66\x6f\x6c\x6c\x6f\x77\x69\x6e\x67\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x61\x72\x65\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x2c\x20\x69\x6e\x20\x74\x68\x69\x73\x20\x6f\x72\x64\x65\x72\x3a\x0a\x0a\x20\x20\x2f\x75\x73\x72\x2f\x6c\x6f\x63\x61\x6c\x2f\x6c\x69\x62\x2f\x70\x79\x74\x68\x6f\x6e\x32\x2e\x35\x2f\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x2f\x62\x61\x72\x0a\x20\x20\x2f\x75\x73\x72\x2f\x6c\x6f\x63\x61\x6c\x2f\x6c\x69\x62\x2f\x70\x79\x74\x68\x6f\x6e\x32\x2e\x35\x2f\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x2f\x66\x6f\x6f\x0a\x0a\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x62\x6c\x65\x74\x63\x68\x20\x69\x73\x20\x6f\x6d\x69\x74\x74\x65\x64\x20\x62\x65\x63\x61\x75\x73\x65\x20\x69\x74\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x65\x78\x69\x73\x74\x3b\x20\x62\x61\x72\x20\x70\x72\x65\x63\x65\x64\x65\x73\x20\x66\x6f\x6f\x0a\x62\x65\x63\x61\x75\x73\x65\x20\x62\x61\x72\x2e\x70\x74\x68\x20\x63\x6f\x6d\x65\x73\x20\x61\x6c\x70\x68\x61\x62\x65\x74\x69\x63\x61\x6c\x6c\x79\x20\x62\x65\x66\x6f\x72\x65\x20\x66\x6f\x6f\x2e\x70\x74\x68\x3b\x20\x61\x6e\x64\x20\x73\x70\x61\x6d\x20\x69\x73\x0a\x6f\x6d\x69\x74\x74\x65\x64\x20\x62\x65\x63\x61\x75\x73\x65\x20\x69\x74\x20\x69\x73\x20\x6e\x6f\x74\x20\x6d\x65\x6e\x74\x69\x6f\x6e\x65\x64\x20\x69\x6e\x20\x65\x69\x74\x68\x65\x72\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x66\x69\x6c\x65\x2e\x0a\x0a\x54\x68\x65\x20\x72\x65\x61\x64\x6c\x69\x6e\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x61\x6c\x73\x6f\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x65\x64\x20\x74\x6f\x20\x65\x6e\x61\x62\x6c\x65\x0a\x63\x6f\x6d\x70\x6c\x65\x74\x69\x6f\x6e\x20\x66\x6f\x72\x20\x73\x79\x73\x74\x65\x6d\x73\x20\x74\x68\x61\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x69\x74\x2e\x20\x20\x54\x68\x69\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x6f\x76\x65\x72\x72\x69\x64\x64\x65\x6e\x20\x69\x6e\x0a\x73\x69\x74\x65\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x2c\x20\x75\x73\x65\x72\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x20\x6f\x72\x20\x50\x59\x54\x48\x4f\x4e\x53\x54\x41\x52\x54\x55\x50\x2e\x20\x20\x53\x74\x61\x72\x74\x69\x6e\x67\x20\x50\x79\x74\x68\x6f\x6e\x20\x69\x6e\x0a\x69\x73\x6f\x6c\x61\x74\x65\x64\x20\x6d\x6f\x64\x65\x20\x28\x2d\x49\x29\x20\x64\x69\x73\x61\x62\x6c\x65\x73\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x20\x72\x65\x61\x64\x6c\x69\x6e\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x41\x66\x74\x65\x72\x20\x74\x68\x65\x73\x65\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x2c\x20\x61\x6e\x20\x61\x74\x74\x65\x6d\x70\x74\x20\x69\x73\x20\x6d\x61\x64\x65\x20\x74\x6f\x20\x69\x6d\x70\x6f\x72\x74\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x0a\x6e\x61\x6d\x65\x64\x20\x73\x69\x74\x65\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x2c\x20\x77\x68\x69\x63\x68\x20\x63\x61\x6e\x20\x70\x65\x72\x66\x6f\x72\x6d\x20\x61\x72\x62\x69\x74\x72\x61\x72\x79\x20\x61\x64\x64\x69\x74\x69\x6f\x6e\x61\x6c\x0a\x73\x69\x74\x65\x2d\x73\x70\x65\x63\x69\x66\x69\x63\x20\x63\x75\x73\x74\x6f\x6d\x69\x7a\x61\x74\x69\x6f\x6e\x73\x2e\x20\x20\x49\x66\x20\x74\x68\x69\x73\x20\x69\x6d\x70\x6f\x72\x74\x20\x66\x61\x69\x6c\x73\x20\x77\x69\x74\x68\x20\x61\x6e\x0a\x49\x6d\x70\x6f\x72\x74\x45\x72\x72\x6f\x72\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x2c\x20\x69\x74\x20\x69\x73\x20\x73\x69\x6c\x65\x6e\x74\x6c\x79\x20\x69\x67\x6e\x6f\x72\x65\x64\x2e\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 0,
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x6a\x02\x72\x0e\x74\x03\x7c\x00\x74\x00\x6a\x04\x64\x01\xaa\x02\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_3_consts_1_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "file",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_3_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_3_consts_1._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_3_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sys",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_3_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "flags",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "verbose",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_3_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "print",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_3_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "stderr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_3_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "message",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_3_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
        }_object;
    }
toplevel_consts_3_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 0,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_3_filename = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "<frozen site>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_3_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_trace",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x12\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0b\x08\x11\x08\x19\x05\x28\x09\x0e\x0f\x16\x1d\x20\x1d\x27\x09\x28\x09\x28\x09\x28\x09\x28\x09\x28\x05\x28\x05\x28",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_3_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 0,
    },
    .ob_shash = -1,
    .ob_sval = "",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_3_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = " ",
};
static struct PyCodeObject toplevel_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 91,
    .co_code = & toplevel_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x6a\x02\x7c\x00\x8e\x00\x7d\x01\x09\x00\x74\x00\x6a\x01\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x7d\x01\x6e\x0a\x23\x00\x74\x04\x79\x16\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x74\x00\x6a\x01\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x66\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_4_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "os",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_4_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_4_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "join",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_4_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "abspath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_4_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "OSError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "normcase",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_4_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_4_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "paths",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_4_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "dir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "makepath",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x02\x01\x10\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x02\x04\x10\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0d\x0b\x12\x0b\x17\x19\x1e\x0b\x1f\x05\x08\x05\x0d\x0f\x11\x0f\x16\x0f\x23\x1f\x22\x0f\x23\x0f\x23\x09\x0c\x09\x0c\x00\x00\x0c\x13\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x0c\x0f\x11\x13\x11\x18\x11\x26\x22\x25\x11\x26\x11\x26\x0c\x26\x05\x26",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x88\x07\x10\x00\x90\x04\x17\x03\x96\x01\x17\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_4_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "  ",
};
static struct PyCodeObject toplevel_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 96,
    .co_code = & toplevel_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[203];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 202,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x74\x01\x6a\x02\xa0\x03\xa8\x00\xa9\x00\xa9\x01\x44\x00\x5d\x59\x7d\x00\x64\x01\x7d\x01\x09\x00\x7c\x00\x6a\x04\x6a\x05\x7d\x01\x6e\x1b\x23\x00\x74\x06\x79\x2a\x01\x00\x09\x00\x7c\x00\x6a\x07\x6a\x08\x6a\x05\x7d\x01\x6e\x0a\x23\x00\x74\x06\x79\x24\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x64\x02\x76\x01\x72\x33\x71\x09\x09\x00\x74\x09\x6a\x0a\xa0\x0b\x7c\x00\x6a\x0c\xa8\x01\xa9\x01\x7c\x00\x5f\x0c\x6e\x0d\x23\x00\x74\x06\x74\x0d\x74\x0e\x66\x03\x79\x47\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x74\x09\x6a\x0a\xa0\x0b\x7c\x00\x6a\x0f\xa8\x01\xa9\x01\x7c\x00\x5f\x0f\x71\x09\x23\x00\x74\x06\x74\x0d\x74\x0e\x66\x03\x79\x5f\x01\x00\x59\x00\x71\x09\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[70];
    }
toplevel_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 69,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Set all module __file__ and __cached__ attributes to an absolute path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_5_consts_2_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_frozen_importlib",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_5_consts_2_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 26,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_frozen_importlib_external",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_1._ascii.ob_base,
        },
    },
};
// TODO: The above tuple should be a frozenset
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_5_consts_2._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_5_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "set",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "modules",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "values",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__loader__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__module__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_names_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "AttributeError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__spec__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_names_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "loader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_names_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__file__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_names_14 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "TypeError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_names_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__cached__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_5_names_5._ascii.ob_base,
            & toplevel_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_5_names_8._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_5_names_12._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_5_names_14._ascii.ob_base,
            & toplevel_consts_5_names_15._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_5_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "m",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "loader_module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "abs_paths",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x14\x02\x04\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x04\x01\x02\xff\x0a\x80\x02\xfd\x06\x80\x08\x05\x02\x01\x02\x01\x14\x01\x02\x80\x0c\x01\x04\x01\x02\xff\x06\x80\x02\x02\x14\x01\x02\x80\x0c\x01\x04\x01\x02\xff\x06\x80\x04\xef",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x02\x04\x12\x02\xee\x04\x01\x02\x07\x0a\xfb\x02\x80\x02\x01\x06\x04\x0c\xfe\x02\x80\x02\x01\x0a\x01\x0a\x80\x02\x00\x06\x80\x06\x01\x04\x01\x02\x04\x14\xfe\x02\x80\x08\x01\x0a\x01\x06\x80\x02\x04\x14\xfe\x02\x80\x08\x01\x0a\x01\x06\x80\x04\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[203];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 202,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x11\x12\x15\x12\x1d\x12\x26\x12\x26\x12\x26\x0e\x27\x05\x11\x05\x11\x09\x0a\x19\x1d\x09\x16\x09\x15\x1d\x1e\x1d\x29\x1d\x34\x0d\x1a\x0d\x1a\x00\x00\x10\x1e\x09\x15\x09\x15\x0d\x15\x21\x22\x21\x2b\x21\x32\x21\x3d\x11\x1e\x11\x1e\x00\x00\x14\x22\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x15\x00\x00\x00\x00\x00\x00\x0c\x19\x21\x54\x0c\x54\x09\x15\x0d\x15\x09\x11\x1a\x1c\x1a\x21\x1a\x35\x2a\x2b\x2a\x34\x1a\x35\x1a\x35\x0d\x0e\x0d\x17\x0d\x17\x00\x00\x11\x1f\x21\x28\x2a\x33\x10\x34\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x09\x11\x1c\x1e\x1c\x23\x1c\x39\x2c\x2d\x2c\x38\x1c\x39\x1c\x39\x0d\x0e\x0d\x19\x0d\x19\x00\x00\x11\x1f\x21\x28\x2a\x33\x10\x34\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x05\x11\x05\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[70];
    }
toplevel_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 69,
    },
    .ob_shash = -1,
    .ob_sval = "\x8e\x04\x13\x02\x93\x04\x2b\x05\x98\x05\x1e\x04\x9d\x01\x2b\x05\x9e\x04\x25\x07\xa2\x02\x2b\x05\xa4\x01\x25\x07\xa5\x03\x2b\x05\xaa\x01\x2b\x05\xb4\x09\x3e\x02\xbe\x07\x41\x08\x05\xc1\x07\x01\x41\x08\x05\xc1\x0c\x09\x41\x16\x02\xc1\x16\x07\x41\x20\x05\xc1\x1f\x01\x41\x20\x05",
};
static struct PyCodeObject toplevel_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 105,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7d\x00\x74\x00\xa9\x00\x7d\x01\x74\x01\x6a\x02\x44\x00\x5d\x18\x7d\x02\x74\x03\x7c\x02\xa9\x01\x5c\x02\x7d\x02\x7d\x03\x7c\x03\x7c\x01\x76\x01\x72\x21\x7c\x00\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x01\x00\x7c\x01\xa0\x05\x7c\x03\xa8\x01\xa9\x01\x01\x00\x71\x09\x7c\x00\x74\x01\x6a\x02\x64\x01\x64\x01\x85\x02\x3c\x00\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[76];
    }
toplevel_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 75,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x6d\x6f\x76\x65\x20\x64\x75\x70\x6c\x69\x63\x61\x74\x65\x20\x65\x6e\x74\x72\x69\x65\x73\x20\x66\x72\x6f\x6d\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x20\x61\x6c\x6f\x6e\x67\x20\x77\x69\x74\x68\x20\x6d\x61\x6b\x69\x6e\x67\x20\x74\x68\x65\x6d\x0a\x20\x20\x20\x20\x61\x62\x73\x6f\x6c\x75\x74\x65",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_6_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_6_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "append",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_6_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "add",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_6_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "L",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_6_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "known_paths",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_6_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "dircase",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_0._ascii.ob_base,
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_6_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "removeduppaths",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x06\x01\x0a\x01\x0c\x04\x08\x01\x0c\x01\x0c\x01\x02\x80\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x06\x01\x04\x01\x04\x07\x02\xf9\x0c\x04\x06\x01\x02\x02\x0c\xff\x0c\x01\x02\x80\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x05\x06\x13\x16\x13\x18\x05\x10\x10\x13\x10\x18\x05\x25\x05\x25\x09\x0c\x18\x20\x21\x24\x18\x25\x09\x15\x09\x0c\x0e\x15\x0c\x13\x1b\x26\x0c\x26\x09\x25\x0d\x0e\x0d\x1a\x16\x19\x0d\x1a\x0d\x1a\x0d\x1a\x0d\x18\x0d\x25\x1d\x24\x0d\x25\x0d\x25\x0d\x25\x00\x00\x13\x14\x05\x08\x05\x0d\x0e\x0f\x0e\x0f\x0e\x0f\x05\x10\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_6_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "    ",
};
static struct PyCodeObject toplevel_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 128,
    .co_code = & toplevel_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa9\x00\x7d\x00\x74\x01\x6a\x02\x44\x00\x5d\x20\x7d\x01\x09\x00\x74\x03\x6a\x02\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x72\x1d\x74\x05\x7c\x01\xa9\x01\x5c\x02\x7d\x02\x7d\x03\x7c\x00\xa0\x06\x7c\x03\xa8\x01\xa9\x01\x01\x00\x71\x07\x23\x00\x74\x07\x79\x24\x01\x00\x59\x00\x71\x07\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[70];
    }
toplevel_consts_7_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 69,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return a set containing all existing file system items from sys.path.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_7_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_7_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exists",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_5_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_7_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "d",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "item",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_7_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_7_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "itemcase",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_7_varnames_0._ascii.ob_base,
            & toplevel_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_7_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_7_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_init_pathinfo",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0a\x01\x02\x01\x0e\x01\x0c\x01\x0c\x01\x04\x80\x06\x01\x04\x01\x02\xff\x06\x80\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x04\x01\x04\x06\x02\xfa\x02\x06\x0c\xfc\x02\x02\x0c\xff\x0c\x01\x04\x80\x02\x01\x0a\x01\x06\x80\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0c\x09\x0e\x05\x06\x11\x14\x11\x19\x05\x15\x05\x15\x09\x0d\x09\x15\x10\x12\x10\x17\x10\x24\x1f\x23\x10\x24\x10\x24\x0d\x20\x1f\x27\x28\x2c\x1f\x2d\x11\x1c\x11\x12\x14\x1c\x11\x12\x11\x20\x17\x1f\x11\x20\x11\x20\x11\x20\x00\x00\x00\x00\x10\x19\x09\x15\x09\x15\x0d\x15\x0d\x15\x09\x15\x00\x00\x00\x00\x00\x00\x0c\x0d\x05\x0d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_7_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x8a\x13\x1e\x02\x9e\x04\x25\x05\xa4\x01\x25\x05",
};
static struct PyCodeObject toplevel_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 147,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[421];
    }
toplevel_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 420,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x80\x09\x74\x00\xa9\x00\x7d\x02\x64\x02\x7d\x03\x6e\x02\x64\x03\x7d\x03\x74\x01\x6a\x02\xa0\x03\x7c\x00\x7c\x01\xa8\x02\xa9\x02\x7d\x04\x74\x04\x64\x04\x7c\x04\x9b\x02\x9d\x02\xa9\x01\x01\x00\x09\x00\x74\x05\x6a\x06\x74\x05\x6a\x07\x7c\x04\xa9\x01\x64\x05\x64\x06\xaa\x02\x7d\x05\x6e\x0b\x23\x00\x74\x08\x79\x2d\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x35\x00\x01\x00\x74\x09\x7c\x05\xa9\x01\x44\x00\x5d\x82\x5c\x02\x7d\x06\x7d\x07\x7c\x07\xa0\x0a\x64\x07\xa8\x01\xa9\x01\x72\x43\x71\x38\x7c\x07\xa0\x0b\xa8\x00\xa9\x00\x64\x08\x6b\x02\x72\x4b\x71\x38\x09\x00\x7c\x07\xa0\x0a\x64\x09\xa8\x01\xa9\x01\x72\x57\x74\x0c\x7c\x07\xa9\x01\x01\x00\x71\x38\x7c\x07\xa0\x0d\xa8\x00\xa9\x00\x7d\x07\x74\x0e\x7c\x00\x7c\x07\xa9\x02\x5c\x02\x7d\x08\x7d\x09\x7c\x09\x7c\x02\x76\x01\x72\x7b\x74\x01\x6a\x02\xa0\x0f\x7c\x08\xa8\x01\xa9\x01\x72\x7b\x74\x10\x6a\x02\xa0\x11\x7c\x08\xa8\x01\xa9\x01\x01\x00\x7c\x02\xa0\x12\x7c\x09\xa8\x01\xa9\x01\x01\x00\x71\x38\x23\x00\x74\x13\x79\xb7\x01\x00\x74\x14\x64\x0a\xa0\x15\x7c\x06\x64\x0b\x7a\x00\x7c\x04\xa8\x02\xa9\x02\x74\x10\x6a\x16\x64\x0c\xaa\x02\x01\x00\x64\x0d\x64\x01\x6c\x17\x7d\x0a\x7c\x0a\x6a\x18\x74\x10\x6a\x19\xa9\x00\x8e\x00\x44\x00\x5d\x13\x7d\x0b\x7c\x0b\xa0\x1a\xa8\x00\xa9\x00\x44\x00\x5d\x0b\x7d\x07\x74\x14\x64\x0e\x7c\x07\x7a\x00\x74\x10\x6a\x16\x64\x0c\xaa\x02\x01\x00\x71\xa0\x71\x99\x74\x14\x64\x0f\x74\x10\x6a\x16\x64\x0c\xaa\x02\x01\x00\x59\x00\x01\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\xc8\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x03\x72\xd0\x64\x01\x7d\x02\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[215];
    }
toplevel_consts_8_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 214,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x50\x72\x6f\x63\x65\x73\x73\x20\x61\x20\x2e\x70\x74\x68\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x69\x6e\x20\x74\x68\x65\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x46\x6f\x72\x20\x65\x61\x63\x68\x20\x6c\x69\x6e\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x2c\x20\x65\x69\x74\x68\x65\x72\x20\x63\x6f\x6d\x62\x69\x6e\x65\x20\x69\x74\x20\x77\x69\x74\x68\x20\x73\x69\x74\x65\x64\x69\x72\x20\x74\x6f\x20\x61\x20\x70\x61\x74\x68\x0a\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x61\x64\x64\x20\x74\x68\x61\x74\x20\x74\x6f\x20\x6b\x6e\x6f\x77\x6e\x5f\x70\x61\x74\x68\x73\x2c\x20\x6f\x72\x20\x65\x78\x65\x63\x75\x74\x65\x20\x69\x74\x20\x69\x66\x20\x69\x74\x20\x73\x74\x61\x72\x74\x73\x20\x77\x69\x74\x68\x20\x27\x69\x6d\x70\x6f\x72\x74\x20\x27\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_8_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 22,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Processing .pth file: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_8_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "locale",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_8_consts_6_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "encoding",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_8_consts_6 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_8_consts_6_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_8_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "#",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_8_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 0,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_8_consts_9_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "import ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_8_consts_9_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x69\x6d\x70\x6f\x72\x74\x09",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_8_consts_9 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_8_consts_9_0._ascii.ob_base,
            & toplevel_consts_8_consts_9_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[35];
    }
toplevel_consts_8_consts_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 34,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x72\x72\x6f\x72\x20\x70\x72\x6f\x63\x65\x73\x73\x69\x6e\x67\x20\x6c\x69\x6e\x65\x20\x7b\x3a\x64\x7d\x20\x6f\x66\x20\x7b\x7d\x3a\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_8_consts_11 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 1 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_8_consts_14 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "  ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_8_consts_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 26,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x52\x65\x6d\x61\x69\x6e\x64\x65\x72\x20\x6f\x66\x20\x66\x69\x6c\x65\x20\x69\x67\x6e\x6f\x72\x65\x64",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_8_consts_0._ascii.ob_base,
            Py_None,
            Py_True,
            Py_False,
            & toplevel_consts_8_consts_4._ascii.ob_base,
            & toplevel_consts_8_consts_5._ascii.ob_base,
            & toplevel_consts_8_consts_6._object.ob_base.ob_base,
            & toplevel_consts_8_consts_7._ascii.ob_base,
            & toplevel_consts_8_consts_8._ascii.ob_base,
            & toplevel_consts_8_consts_9._object.ob_base.ob_base,
            & toplevel_consts_8_consts_10._ascii.ob_base,
            & toplevel_consts_8_consts_11.ob_base.ob_base,
            & toplevel_consts_3_consts_1._object.ob_base.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_8_consts_14._ascii.ob_base,
            & toplevel_consts_8_consts_15._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_8_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "io",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_8_names_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "TextIOWrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_8_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "open_code",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_8_names_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "enumerate",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_8_names_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "startswith",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_8_names_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "strip",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_8_names_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_8_names_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "rstrip",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_8_names_19 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Exception",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_8_names_21 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "format",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_8_names_23 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "traceback",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_8_names_24 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 16,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "format_exception",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_8_names_25 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exc_info",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_8_names_26 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "splitlines",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[27];
        }_object;
    }
toplevel_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 27,
        },
        .ob_item = {
            & toplevel_consts_7_name._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_8_names_5._ascii.ob_base,
            & toplevel_consts_8_names_6._ascii.ob_base,
            & toplevel_consts_8_names_7._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_8_names_9._ascii.ob_base,
            & toplevel_consts_8_names_10._ascii.ob_base,
            & toplevel_consts_8_names_11._ascii.ob_base,
            & toplevel_consts_8_names_12._ascii.ob_base,
            & toplevel_consts_8_names_13._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_8_names_19._ascii.ob_base,
            & toplevel_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_8_names_21._ascii.ob_base,
            & toplevel_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_8_names_23._ascii.ob_base,
            & toplevel_consts_8_names_24._ascii.ob_base,
            & toplevel_consts_8_names_25._ascii.ob_base,
            & toplevel_consts_8_names_26._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_8_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sitedir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_8_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_8_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "reset",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_8_varnames_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "fullname",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_8_varnames_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "f",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_8_varnames_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "n",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_8_varnames_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "line",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_8_varnames_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "record",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_8_varnames_0._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_8_varnames_3._ascii.ob_base,
            & toplevel_consts_8_varnames_4._ascii.ob_base,
            & toplevel_consts_8_varnames_5._ascii.ob_base,
            & toplevel_consts_8_varnames_6._ascii.ob_base,
            & toplevel_consts_8_varnames_7._ascii.ob_base,
            & toplevel_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_8_names_23._ascii.ob_base,
            & toplevel_consts_8_varnames_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_8_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "addpackage",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x06\x01\x06\x01\x04\x02\x10\x01\x0e\x01\x02\x01\x16\x03\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x06\x02\x10\x01\x0c\x01\x02\x01\x0e\x01\x02\x01\x02\x01\x0c\x01\x08\x01\x02\x01\x0a\x01\x0e\x01\x16\x01\x0e\x01\x0c\x01\x04\x80\x06\x01\x12\x01\x04\x01\x06\xff\x08\x02\x12\x01\x0e\x01\x14\x01\x02\xff\x0e\x02\x06\x01\x02\xf8\x06\x80\x14\xf1\x06\x80\x08\x00\x04\x18\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[117];
    }
toplevel_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 116,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x02\x04\x06\xfd\x06\x01\x04\x02\x10\x01\x0e\x01\x02\x06\x16\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x02\x01\x04\x17\x06\xea\x04\x16\x06\xea\x0a\x01\x04\x01\x0c\x01\x04\x01\x02\x12\x0a\xf0\x02\x02\x08\xff\x02\x01\x0a\x01\x0e\x01\x06\x01\x02\x02\x0c\xfe\x02\x02\x0e\xff\x0c\x01\x04\x80\x02\x01\x04\x08\x12\xf9\x0a\x01\x08\x01\x0c\x01\x04\x02\x02\xfe\x08\x01\x04\x01\x02\xff\x16\x01\x0e\x01\x08\x01\x06\x80\x14\x00\x06\x80\x08\x00\x02\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[421];
    }
toplevel_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 420,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x13\x05\x16\x17\x25\x17\x27\x09\x14\x11\x15\x09\x0e\x09\x0e\x11\x16\x09\x0e\x10\x12\x10\x17\x10\x2b\x1d\x24\x26\x2a\x10\x2b\x10\x2b\x05\x0d\x05\x0b\x0c\x31\x25\x2d\x0c\x31\x0c\x31\x05\x32\x05\x32\x05\x0f\x0d\x0f\x0d\x1d\x1e\x20\x1e\x2a\x2b\x33\x1e\x34\x3f\x47\x0d\x48\x0d\x48\x09\x0a\x09\x0a\x00\x00\x0c\x13\x05\x0f\x05\x0f\x09\x0f\x09\x0f\x09\x0f\x05\x0f\x00\x00\x00\x00\x00\x00\x0a\x0b\x05\x16\x05\x16\x18\x21\x22\x23\x18\x24\x09\x16\x09\x16\x0d\x14\x0d\x0e\x10\x14\x10\x14\x10\x24\x20\x23\x10\x24\x10\x24\x0d\x19\x11\x19\x10\x14\x10\x1c\x10\x1c\x10\x1c\x20\x22\x10\x22\x0d\x19\x11\x19\x0d\x16\x14\x18\x14\x3c\x24\x3b\x14\x3c\x14\x3c\x11\x1d\x15\x19\x1a\x1e\x15\x1f\x15\x1f\x15\x1d\x18\x1c\x18\x25\x18\x25\x18\x25\x11\x15\x20\x28\x29\x30\x32\x36\x20\x37\x11\x1d\x11\x14\x16\x1d\x18\x1f\x23\x2e\x18\x2e\x11\x2d\x33\x35\x33\x3a\x33\x46\x42\x45\x33\x46\x33\x46\x11\x2d\x15\x18\x15\x1d\x15\x29\x25\x28\x15\x29\x15\x29\x15\x29\x15\x20\x15\x2d\x25\x2c\x15\x2d\x15\x2d\x15\x2d\x00\x00\x00\x00\x14\x1d\x0d\x16\x0d\x16\x11\x16\x17\x3c\x17\x52\x44\x45\x46\x47\x44\x47\x49\x51\x17\x52\x17\x52\x1c\x1f\x1c\x26\x11\x27\x11\x27\x11\x27\x11\x21\x11\x21\x11\x21\x11\x21\x1f\x28\x1f\x39\x3b\x3e\x3b\x47\x3b\x49\x1f\x4a\x11\x3a\x11\x3a\x15\x1b\x21\x27\x21\x34\x21\x34\x21\x34\x15\x3a\x15\x3a\x19\x1d\x19\x1e\x1f\x23\x24\x28\x1f\x28\x2f\x32\x2f\x39\x19\x3a\x19\x3a\x19\x3a\x19\x3a\x15\x3a\x11\x16\x17\x34\x3b\x3e\x3b\x45\x11\x46\x11\x46\x11\x46\x11\x16\x11\x16\x11\x16\x0d\x16\x00\x00\x00\x00\x00\x00\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x05\x16\x00\x00\x00\x00\x00\x00\x05\x16\x05\x16\x05\x16\x05\x16\x08\x0d\x05\x1b\x17\x1b\x09\x14\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[78];
    }
toplevel_consts_8_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 77,
    },
    .ob_shash = -1,
    .ob_sval = "\x9b\x0a\x26\x00\xa6\x04\x2e\x03\xad\x01\x2e\x03\xb3\x18\x43\x01\x03\xc1\x0c\x0a\x41\x3c\x04\xc1\x16\x01\x43\x01\x03\xc1\x17\x24\x41\x3c\x04\xc1\x3b\x01\x43\x01\x03\xc1\x3c\x38\x42\x38\x07\xc2\x34\x03\x43\x01\x03\xc2\x37\x01\x42\x38\x07\xc2\x38\x03\x43\x01\x03\xc3\x01\x04\x43\x05\x07\xc3\x08\x01\x43\x05\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_8_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "            ",
};
static struct PyCodeObject toplevel_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_8_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 9,
    .co_firstlineno = 160,
    .co_code = & toplevel_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_8_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_8_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 12,
    .co_nlocals = 12,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[169];
    }
toplevel_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 168,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x64\x01\x7c\x00\x9b\x02\x9d\x02\xa9\x01\x01\x00\x7c\x01\x80\x10\x74\x01\xa9\x00\x7d\x01\x64\x03\x7d\x02\x6e\x02\x64\x04\x7d\x02\x74\x02\x7c\x00\xa9\x01\x5c\x02\x7d\x00\x7d\x03\x7c\x03\x7c\x01\x76\x01\x72\x29\x74\x03\x6a\x04\xa0\x05\x7c\x00\xa8\x01\xa9\x01\x01\x00\x7c\x01\xa0\x06\x7c\x03\xa8\x01\xa9\x01\x01\x00\x09\x00\x74\x07\x6a\x08\x7c\x00\xa9\x01\x7d\x04\x6e\x0b\x23\x00\x74\x09\x79\x37\x01\x00\x59\x00\x64\x02\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x64\x05\x84\x00\x7c\x04\x44\x00\xa9\x01\x7d\x04\x74\x0a\x7c\x04\xa9\x01\x44\x00\x5d\x08\x7d\x05\x74\x0b\x7c\x00\x7c\x05\x7c\x01\xa9\x03\x01\x00\x71\x45\x7c\x02\x72\x52\x64\x02\x7d\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[85];
    }
toplevel_consts_9_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 84,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x64\x64\x20\x27\x73\x69\x74\x65\x64\x69\x72\x27\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x20\x69\x66\x20\x6d\x69\x73\x73\x69\x6e\x67\x20\x61\x6e\x64\x20\x68\x61\x6e\x64\x6c\x65\x20\x2e\x70\x74\x68\x20\x66\x69\x6c\x65\x73\x20\x69\x6e\x0a\x20\x20\x20\x20\x27\x73\x69\x74\x65\x64\x69\x72\x27",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_9_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 18,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Adding directory: ",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_9_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7c\x00\x5d\x0a\x7d\x01\x7c\x01\xa0\x00\x64\x00\xa8\x01\xa9\x01\x72\x03\x7c\x01\x91\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_9_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".pth",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_9_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_consts_5_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "endswith",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_9_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_9_consts_5_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".0",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_9_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_9_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_9_consts_5_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "<listcomp>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_9_consts_5_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 30,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "addsitedir.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_9_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x1e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_9_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x3e\x0d\x3e\x0d\x3e\x17\x1b\x28\x2c\x28\x3d\x36\x3c\x28\x3d\x28\x3d\x0d\x3e\x0e\x12\x0d\x3e\x0d\x3e\x0d\x3e",
};
static struct PyCodeObject toplevel_consts_9_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 224,
    .co_code = & toplevel_consts_9_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_9_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_9_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_9_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_9_consts_1._ascii.ob_base,
            Py_None,
            Py_True,
            Py_False,
            & toplevel_consts_9_consts_5.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_9_names_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "listdir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_9_names_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sorted",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_7_name._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_9_names_8._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_9_names_10._ascii.ob_base,
            & toplevel_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_9_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sitedircase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_9_varnames_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "names",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_8_varnames_0._ascii.ob_base,
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_8_varnames_3._ascii.ob_base,
            & toplevel_consts_9_varnames_3._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_9_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "addsitedir",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x03\x04\x01\x06\x01\x06\x01\x04\x02\x0c\x01\x08\x01\x0e\x01\x0c\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x0c\x02\x0c\x01\x0e\x01\x04\x01\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x03\x02\x01\x02\x04\x06\xfd\x06\x01\x04\x02\x0c\x01\x06\x01\x02\x02\x0e\xff\x0c\x01\x02\x04\x0c\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x0c\x01\x06\x01\x04\x01\x02\xff\x0e\x01\x02\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[169];
    }
toplevel_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 168,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0b\x0c\x2c\x21\x28\x0c\x2c\x0c\x2c\x05\x2d\x05\x2d\x08\x13\x05\x16\x17\x25\x17\x27\x09\x14\x11\x15\x09\x0e\x09\x0e\x11\x16\x09\x0e\x1c\x24\x25\x2c\x1c\x2d\x05\x19\x05\x0c\x0e\x19\x0c\x17\x1b\x26\x0c\x26\x05\x25\x09\x0c\x09\x11\x09\x21\x19\x20\x09\x21\x09\x21\x09\x21\x09\x14\x09\x25\x19\x24\x09\x25\x09\x25\x09\x25\x05\x0f\x11\x13\x11\x1b\x1c\x23\x11\x24\x09\x0e\x09\x0e\x00\x00\x0c\x13\x05\x0f\x05\x0f\x09\x0f\x09\x0f\x09\x0f\x05\x0f\x00\x00\x00\x00\x00\x00\x0d\x3e\x0d\x3e\x1f\x24\x0d\x3e\x0d\x3e\x05\x0a\x11\x17\x18\x1d\x11\x1e\x05\x2f\x05\x2f\x09\x0d\x09\x13\x14\x1b\x1d\x21\x23\x2e\x09\x2f\x09\x2f\x09\x2f\x08\x0d\x05\x1b\x17\x1b\x09\x14\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_9_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\xaa\x05\x30\x00\xb0\x04\x38\x03\xb7\x01\x38\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_9_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "      ",
};
static struct PyCodeObject toplevel_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_9_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 207,
    .co_code = & toplevel_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_9_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x6a\x02\x72\x07\x64\x01\x53\x00\x74\x03\x74\x04\x64\x02\xa9\x02\x72\x1b\x74\x03\x74\x04\x64\x03\xa9\x02\x72\x1b\x74\x04\x6a\x05\xa9\x00\x74\x04\x6a\x06\xa9\x00\x6b\x03\x72\x1b\x64\x04\x53\x00\x74\x03\x74\x04\x64\x05\xa9\x02\x72\x2f\x74\x03\x74\x04\x64\x06\xa9\x02\x72\x2f\x74\x04\x6a\x07\xa9\x00\x74\x04\x6a\x08\xa9\x00\x6b\x03\x72\x2f\x64\x04\x53\x00\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[301];
    }
toplevel_consts_10_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 300,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x68\x65\x63\x6b\x20\x69\x66\x20\x75\x73\x65\x72\x20\x73\x69\x74\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x73\x61\x66\x65\x20\x66\x6f\x72\x20\x69\x6e\x63\x6c\x75\x73\x69\x6f\x6e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x74\x65\x73\x74\x73\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x63\x6f\x6d\x6d\x61\x6e\x64\x20\x6c\x69\x6e\x65\x20\x66\x6c\x61\x67\x20\x28\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x29\x2c\x0a\x20\x20\x20\x20\x70\x72\x6f\x63\x65\x73\x73\x20\x75\x69\x64\x2f\x67\x69\x64\x20\x65\x71\x75\x61\x6c\x20\x74\x6f\x20\x65\x66\x66\x65\x63\x74\x69\x76\x65\x20\x75\x69\x64\x2f\x67\x69\x64\x2e\x0a\x0a\x20\x20\x20\x20\x4e\x6f\x6e\x65\x3a\x20\x44\x69\x73\x61\x62\x6c\x65\x64\x20\x66\x6f\x72\x20\x73\x65\x63\x75\x72\x69\x74\x79\x20\x72\x65\x61\x73\x6f\x6e\x73\x0a\x20\x20\x20\x20\x46\x61\x6c\x73\x65\x3a\x20\x44\x69\x73\x61\x62\x6c\x65\x64\x20\x62\x79\x20\x75\x73\x65\x72\x20\x28\x63\x6f\x6d\x6d\x61\x6e\x64\x20\x6c\x69\x6e\x65\x20\x6f\x70\x74\x69\x6f\x6e\x29\x0a\x20\x20\x20\x20\x54\x72\x75\x65\x3a\x20\x53\x61\x66\x65\x20\x61\x6e\x64\x20\x65\x6e\x61\x62\x6c\x65\x64\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_10_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getuid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "geteuid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_10_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getgid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getegid",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_10_consts_0._ascii.ob_base,
            Py_False,
            & toplevel_consts_10_consts_2._ascii.ob_base,
            & toplevel_consts_10_consts_3._ascii.ob_base,
            Py_None,
            & toplevel_consts_10_consts_5._ascii.ob_base,
            & toplevel_consts_10_consts_6._ascii.ob_base,
            Py_True,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_10_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "no_user_site",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "hasattr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_10_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_10_consts_3._ascii.ob_base,
            & toplevel_consts_10_consts_2._ascii.ob_base,
            & toplevel_consts_10_consts_6._ascii.ob_base,
            & toplevel_consts_10_consts_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_10_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 20,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "check_enableusersite",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x04\x01\x14\x02\x10\x02\x04\x01\x14\x01\x10\x02\x04\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0a\x06\x01\x08\x02\x02\x03\x08\xfd\x02\x03\x0e\xff\x06\x01\x08\x01\x02\x03\x08\xfd\x02\x03\x0e\xff\x06\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0b\x08\x11\x08\x1e\x05\x15\x10\x15\x10\x15\x08\x0f\x10\x12\x14\x1c\x08\x1d\x05\x18\x22\x29\x2a\x2c\x2e\x37\x22\x38\x05\x18\x0c\x0e\x0c\x16\x0c\x18\x1c\x1e\x1c\x25\x1c\x27\x0c\x27\x09\x18\x14\x18\x14\x18\x08\x0f\x10\x12\x14\x1c\x08\x1d\x05\x18\x22\x29\x2a\x2c\x2e\x37\x22\x38\x05\x18\x0c\x0e\x0c\x16\x0c\x18\x1c\x1e\x1c\x25\x1c\x27\x0c\x27\x09\x18\x14\x18\x14\x18\x0c\x10\x0c\x10",
};
static struct PyCodeObject toplevel_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 232,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[141];
    }
toplevel_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 140,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\xa0\x02\x64\x01\x64\x00\xa8\x02\xa9\x02\x7d\x00\x7c\x00\x72\x0d\x7c\x00\x53\x00\x74\x03\x6a\x04\x64\x02\x6b\x02\x72\x14\x64\x00\x53\x00\x64\x03\x84\x00\x7d\x01\x74\x00\x6a\x05\x64\x04\x6b\x02\x72\x2a\x74\x00\x6a\x01\xa0\x02\x64\x05\xa8\x01\xa9\x01\x70\x24\x64\x06\x7d\x02\x7c\x01\x7c\x02\x64\x07\xa9\x02\x53\x00\x74\x03\x6a\x04\x64\x08\x6b\x02\x72\x41\x74\x03\x6a\x06\x72\x41\x7c\x01\x64\x06\x64\x09\x74\x03\x6a\x06\x64\x0a\x74\x03\x6a\x07\x64\x00\x64\x0b\x85\x02\x19\x00\x7a\x06\xa9\x04\x53\x00\x7c\x01\x64\x06\x64\x0c\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_11_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "PYTHONUSERBASE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "vxworks",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_11_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\xa0\x02\x74\x00\x6a\x01\x6a\x03\x7c\x00\x8e\x00\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_consts_3_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "expanduser",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_11_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_11_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_consts_3_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "args",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_11_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_consts_3_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_consts_3_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "joinuser",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_11_consts_3_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 30,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_getuserbase.<locals>.joinuser",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_11_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_11_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x17\x10\x37\x23\x25\x23\x2a\x23\x2f\x31\x35\x23\x36\x10\x37\x10\x37\x09\x37",
};
static struct PyCodeObject toplevel_consts_11_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 23,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 273,
    .co_code = & toplevel_consts_11_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_11_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "nt",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "APPDATA",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_11_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "~",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Python",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "darwin",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_consts_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Library",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_consts_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "%d.%d",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_11_consts_11 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 2 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11_consts_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".local",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_11_consts_1._ascii.ob_base,
            & toplevel_consts_11_consts_2._ascii.ob_base,
            & toplevel_consts_11_consts_3.ob_base,
            & toplevel_consts_11_consts_4._ascii.ob_base,
            & toplevel_consts_11_consts_5._ascii.ob_base,
            & toplevel_consts_11_consts_6._ascii.ob_base,
            & toplevel_consts_11_consts_7._ascii.ob_base,
            & toplevel_consts_11_consts_8._ascii.ob_base,
            & toplevel_consts_11_consts_9._ascii.ob_base,
            & toplevel_consts_11_consts_10._ascii.ob_base,
            & toplevel_consts_11_consts_11.ob_base.ob_base,
            & toplevel_consts_11_consts_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "environ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_11_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "get",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "platform",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_names_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_framework",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_11_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "version_info",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_11_names_2._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_11_names_6._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "env_base",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "base",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_11_consts_3_name._ascii.ob_base,
            & toplevel_consts_11_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_11_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_getuserbase",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x04\x01\x04\x01\x0a\x03\x04\x01\x06\x02\x0a\x03\x12\x01\x0a\x01\x10\x02\x0a\x01\x10\x01\x04\xff\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x02\x01\x06\x01\x08\x03\x06\x01\x06\x03\x08\x02\x02\x02\x12\xff\x0a\x01\x08\x02\x02\x02\x04\xfe\x02\x02\x0a\xff\x14\x01\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[141];
    }
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 140,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x1a\x10\x36\x1f\x2f\x31\x35\x10\x36\x10\x36\x05\x0d\x08\x10\x05\x18\x10\x18\x09\x18\x08\x0b\x08\x14\x18\x21\x08\x21\x05\x14\x10\x14\x10\x14\x05\x37\x05\x37\x05\x37\x08\x0a\x08\x0f\x13\x17\x08\x17\x05\x28\x10\x12\x10\x1a\x10\x29\x1f\x28\x10\x29\x10\x29\x10\x30\x2d\x30\x09\x0d\x10\x18\x19\x1d\x1f\x27\x10\x28\x09\x28\x08\x0b\x08\x14\x18\x20\x08\x20\x05\x38\x25\x28\x25\x33\x05\x38\x10\x18\x19\x1c\x1e\x27\x29\x2c\x29\x37\x19\x20\x23\x26\x23\x33\x34\x36\x35\x36\x34\x36\x23\x37\x19\x37\x10\x38\x09\x38\x0c\x14\x15\x18\x1a\x22\x0c\x23\x05\x23",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_11_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 3,
    },
    .ob_shash = -1,
    .ob_sval = "   ",
};
static struct PyCodeObject toplevel_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 8,
    .co_firstlineno = 264,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7d\x01\x74\x02\x6a\x03\x64\x01\x6b\x02\x72\x19\x74\x00\x6a\x04\xa0\x05\x64\x02\x64\x03\xa8\x02\xa9\x02\x7d\x02\x7c\x00\x9b\x00\x64\x04\x7c\x02\x9b\x00\x64\x05\x9d\x04\x53\x00\x74\x00\x6a\x06\x64\x06\x6b\x02\x72\x26\x74\x00\x6a\x07\x72\x26\x7c\x00\x9b\x00\x64\x07\x9d\x02\x53\x00\x7c\x00\x9b\x00\x64\x08\x7c\x01\x64\x09\x19\x00\x9b\x00\x64\x02\x7c\x01\x64\x0a\x19\x00\x9b\x00\x64\x0b\x9d\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_12_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_12_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\\Python",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_12_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\\site-packages",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_12_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 25,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "/lib/python/site-packages",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_12_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "/lib/python",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_12_consts_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "/site-packages",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_11_consts_4._ascii.ob_base,
            & toplevel_consts_12_consts_2._ascii.ob_base,
            & toplevel_consts_8_consts_8._ascii.ob_base,
            & toplevel_consts_12_consts_4._ascii.ob_base,
            & toplevel_consts_12_consts_5._ascii.ob_base,
            & toplevel_consts_11_consts_8._ascii.ob_base,
            & toplevel_consts_12_consts_7._ascii.ob_base,
            & toplevel_consts_12_consts_8._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_8_consts_11.ob_base.ob_base,
            & toplevel_consts_12_consts_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_12_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "winver",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_12_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "replace",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_12_names_4._ascii.ob_base,
            & toplevel_consts_12_names_5._ascii.ob_base,
            & toplevel_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_11_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "userbase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_12_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "version",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_12_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "ver_nodot",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_12_varnames_1._ascii.ob_base,
            & toplevel_consts_12_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_12_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_get_path",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0a\x02\x10\x01\x10\x01\x10\x02\x0a\x01\x1e\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x08\x02\x02\x02\x10\xff\x10\x01\x08\x02\x02\x01\x04\xff\x0c\x01\x1e\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x12\x0f\x1f\x05\x0c\x08\x0a\x08\x0f\x13\x17\x08\x17\x05\x3f\x15\x18\x15\x1f\x15\x30\x28\x2b\x2d\x2f\x15\x30\x15\x30\x09\x12\x13\x1b\x10\x3f\x10\x3f\x25\x2e\x10\x3f\x10\x3f\x10\x3f\x09\x3f\x08\x0b\x08\x14\x18\x20\x08\x20\x05\x36\x25\x28\x25\x33\x05\x36\x13\x1b\x10\x36\x10\x36\x10\x36\x09\x36\x0f\x17\x0c\x4b\x0c\x4b\x24\x2b\x2c\x2d\x24\x2e\x0c\x4b\x0c\x4b\x31\x38\x39\x3a\x31\x3b\x0c\x4b\x0c\x4b\x0c\x4b\x05\x4b",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 288,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x80\x06\x74\x01\xa9\x00\x61\x00\x74\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[204];
    }
toplevel_consts_13_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 203,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x60\x75\x73\x65\x72\x20\x62\x61\x73\x65\x60\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x70\x61\x74\x68\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x60\x75\x73\x65\x72\x20\x62\x61\x73\x65\x60\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x63\x61\x6e\x20\x62\x65\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x73\x74\x6f\x72\x65\x20\x64\x61\x74\x61\x2e\x20\x49\x66\x20\x74\x68\x65\x20\x67\x6c\x6f\x62\x61\x6c\x0a\x20\x20\x20\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x20\x60\x60\x55\x53\x45\x52\x5f\x42\x41\x53\x45\x60\x60\x20\x69\x73\x20\x6e\x6f\x74\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x64\x20\x79\x65\x74\x2c\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x61\x6c\x73\x6f\x20\x73\x65\x74\x0a\x20\x20\x20\x20\x69\x74\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_13_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_13_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "USER_BASE",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_13_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getuserbase",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_13_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x08\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_13_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x08\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x11\x05\x23\x15\x21\x15\x23\x09\x12\x0c\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 301,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_13_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_13_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa9\x00\x7d\x00\x74\x01\x80\x10\x7c\x00\x80\x0c\x64\x02\x61\x02\x74\x01\x53\x00\x74\x03\x7c\x00\xa9\x01\x61\x01\x74\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[163];
    }
toplevel_consts_14_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 162,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x75\x73\x65\x72\x2d\x73\x70\x65\x63\x69\x66\x69\x63\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x70\x61\x74\x68\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x74\x68\x65\x20\x67\x6c\x6f\x62\x61\x6c\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x20\x60\x60\x55\x53\x45\x52\x5f\x53\x49\x54\x45\x60\x60\x20\x69\x73\x20\x6e\x6f\x74\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x64\x20\x79\x65\x74\x2c\x20\x74\x68\x69\x73\x0a\x20\x20\x20\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x61\x6c\x73\x6f\x20\x73\x65\x74\x20\x69\x74\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
            Py_None,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_14_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "USER_SITE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_14_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 16,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "ENABLE_USER_SITE",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13_name._ascii.ob_base,
            & toplevel_consts_14_names_1._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_14_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 19,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getusersitepackages",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x07\x04\x02\x04\x01\x04\x01\x04\x04\x08\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x07\x02\x02\x02\x04\x02\xfd\x02\x03\x04\xfe\x04\x04\x08\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1b\x10\x1d\x05\x0d\x08\x11\x05\x2c\x0c\x14\x09\x2c\x20\x25\x0d\x1d\x0c\x15\x05\x15\x19\x22\x23\x2b\x19\x2c\x0d\x16\x0c\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 314,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x64\x01\xa9\x01\x01\x00\x74\x01\xa9\x00\x7d\x01\x74\x02\x72\x16\x74\x03\x6a\x04\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x72\x16\x74\x06\x7c\x01\x7c\x00\xa9\x02\x01\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[135];
    }
toplevel_consts_15_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 134,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x64\x64\x20\x61\x20\x70\x65\x72\x20\x75\x73\x65\x72\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x20\x74\x6f\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x0a\x0a\x20\x20\x20\x20\x45\x61\x63\x68\x20\x75\x73\x65\x72\x20\x68\x61\x73\x20\x69\x74\x73\x20\x6f\x77\x6e\x20\x70\x79\x74\x68\x6f\x6e\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x77\x69\x74\x68\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x69\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x68\x6f\x6d\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_15_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 29,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Processing user site-packages",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_15_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_15_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "isdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_15_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "user_site",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_15_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_15_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 19,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "addusersitepackages",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x08\x06\x01\x12\x02\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x08\x06\x01\x02\x02\x02\x01\x0c\xff\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0b\x0c\x2b\x05\x2c\x05\x2c\x11\x24\x11\x26\x05\x0e\x08\x18\x05\x2b\x1d\x1f\x1d\x24\x1d\x35\x2b\x34\x1d\x35\x1d\x35\x05\x2b\x09\x13\x14\x1d\x1f\x2a\x09\x2b\x09\x2b\x0c\x17\x05\x17",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 331,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[197];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 196,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7d\x01\x74\x00\xa9\x00\x7d\x02\x7c\x00\x80\x0a\x74\x01\x7d\x00\x7c\x00\x44\x00\x5d\x53\x7d\x03\x7c\x03\x72\x14\x7c\x03\x7c\x02\x76\x00\x72\x15\x71\x0c\x7c\x02\xa0\x02\x7c\x03\xa8\x01\xa9\x01\x01\x00\x74\x03\x6a\x04\x64\x02\x6b\x02\x72\x4c\x74\x05\x6a\x06\x67\x01\x7d\x04\x74\x05\x6a\x06\x64\x03\x6b\x03\x72\x2f\x7c\x04\xa0\x07\x64\x03\xa8\x01\xa9\x01\x01\x00\x7c\x04\x44\x00\x5d\x19\x7d\x05\x74\x03\x6a\x08\xa0\x09\x7c\x03\x7c\x05\x64\x04\x74\x05\x6a\x0a\x64\x01\x64\x05\x85\x02\x19\x00\x7a\x06\x64\x06\xa8\x04\xa9\x04\x7d\x06\x7c\x01\xa0\x07\x7c\x06\xa8\x01\xa9\x01\x01\x00\x71\x31\x71\x0c\x7c\x01\xa0\x07\x7c\x03\xa8\x01\xa9\x01\x01\x00\x7c\x01\xa0\x07\x74\x03\x6a\x08\xa0\x09\x7c\x03\x64\x07\x64\x06\xa8\x03\xa9\x03\xa8\x01\xa9\x01\x01\x00\x71\x0c\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[287];
    }
toplevel_consts_16_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 286,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x73\x20\x61\x20\x6c\x69\x73\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x69\x6e\x67\x20\x61\x6c\x6c\x20\x67\x6c\x6f\x62\x61\x6c\x20\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x46\x6f\x72\x20\x65\x61\x63\x68\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x70\x72\x65\x73\x65\x6e\x74\x20\x69\x6e\x20\x60\x60\x70\x72\x65\x66\x69\x78\x65\x73\x60\x60\x20\x28\x6f\x72\x20\x74\x68\x65\x20\x67\x6c\x6f\x62\x61\x6c\x20\x60\x60\x50\x52\x45\x46\x49\x58\x45\x53\x60\x60\x29\x2c\x0a\x20\x20\x20\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x66\x69\x6e\x64\x20\x69\x74\x73\x20\x60\x73\x69\x74\x65\x2d\x70\x61\x63\x6b\x61\x67\x65\x73\x60\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x64\x65\x70\x65\x6e\x64\x69\x6e\x67\x20\x6f\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x73\x79\x73\x74\x65\x6d\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2c\x20\x61\x6e\x64\x20\x77\x69\x6c\x6c\x20\x72\x65\x74\x75\x72\x6e\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x66\x75\x6c\x6c\x20\x70\x61\x74\x68\x73\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_16_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "/",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_16_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "lib",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_16_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "python%d.%d",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_16_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "site-packages",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_16_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Lib",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_16_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_16_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_16_consts_2._ascii.ob_base,
            & toplevel_consts_16_consts_3._ascii.ob_base,
            & toplevel_consts_16_consts_4._ascii.ob_base,
            & toplevel_consts_11_consts_11.ob_base.ob_base,
            & toplevel_consts_16_consts_6._ascii.ob_base,
            & toplevel_consts_16_consts_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "PREFIXES",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_16_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sep",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_16_names_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "platlibdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_16_names_4._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_16_names_6._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "prefixes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_16_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sitepackages",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_16_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "seen",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_16_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_16_varnames_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "libdirs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_16_varnames_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "libdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_16_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_16_varnames_0._ascii.ob_base,
            & toplevel_consts_16_varnames_1._ascii.ob_base,
            & toplevel_consts_16_varnames_2._ascii.ob_base,
            & toplevel_consts_16_varnames_3._ascii.ob_base,
            & toplevel_consts_16_varnames_4._ascii.ob_base,
            & toplevel_consts_16_varnames_5._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_16_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 15,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getsitepackages",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x07\x06\x01\x04\x02\x04\x01\x08\x02\x0c\x01\x02\x01\x0c\x01\x0a\x02\x08\x01\x0a\x01\x0c\x01\x08\x02\x0a\x01\x10\x01\x02\x01\x06\xfe\x0e\x03\x02\xfc\x0c\x06\x1c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x07\x06\x01\x02\x02\x06\x01\x02\x02\x04\x11\x02\xef\x02\x01\x02\x01\x06\xff\x04\x01\x0c\x01\x08\x02\x02\x0c\x08\xf5\x08\x01\x0e\x01\x02\x02\x04\x04\x02\xfc\x04\x01\x02\x02\x04\xfe\x10\x01\x06\x01\x02\xfe\x10\x03\x0c\x02\x1c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[197];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 196,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x16\x05\x11\x0c\x0f\x0c\x11\x05\x09\x08\x10\x05\x1c\x14\x1c\x09\x11\x13\x1b\x05\x4e\x05\x4e\x09\x0f\x10\x16\x09\x15\x1a\x20\x24\x28\x1a\x28\x09\x15\x0d\x15\x09\x0d\x09\x19\x12\x18\x09\x19\x09\x19\x09\x19\x0c\x0e\x0c\x12\x16\x19\x0c\x19\x09\x4e\x18\x1b\x18\x26\x17\x27\x0d\x14\x10\x13\x10\x1e\x22\x27\x10\x27\x0d\x26\x11\x18\x11\x26\x20\x25\x11\x26\x11\x26\x11\x26\x1b\x22\x0d\x2a\x0d\x2a\x11\x17\x18\x1a\x18\x1f\x18\x35\x25\x2b\x2d\x33\x25\x32\x35\x38\x35\x45\x46\x48\x47\x48\x46\x48\x35\x49\x25\x49\x25\x34\x18\x35\x18\x35\x11\x15\x11\x1d\x11\x2a\x25\x29\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x0d\x2a\x0d\x19\x0d\x28\x21\x27\x0d\x28\x0d\x28\x0d\x28\x0d\x19\x0d\x4e\x21\x23\x21\x28\x21\x4d\x2e\x34\x36\x3b\x3d\x4c\x21\x4d\x21\x4d\x0d\x4e\x0d\x4e\x0d\x4e\x0d\x4e\x0c\x18\x05\x18",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_16_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 7,
    },
    .ob_shash = -1,
    .ob_sval = "       ",
};
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 10,
    .co_firstlineno = 346,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x64\x01\xa9\x01\x01\x00\x74\x01\x7c\x01\xa9\x01\x44\x00\x5d\x0e\x7d\x02\x74\x02\x6a\x03\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x72\x17\x74\x05\x7c\x02\x7c\x00\xa9\x02\x01\x00\x71\x09\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_17_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 29,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Add site-packages to sys.path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_17_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 31,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Processing global site-packages",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_17_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_0._ascii.ob_base,
            & toplevel_consts_17_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_17_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_17_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_16_varnames_0._ascii.ob_base,
            & toplevel_consts_8_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_17_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 15,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "addsitepackages",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_17_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0c\x01\x0e\x01\x0a\x01\x02\x80\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_17_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x06\x01\x04\x02\x02\xfe\x0c\x01\x0c\x01\x02\x80\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0b\x0c\x2d\x05\x2e\x05\x2e\x14\x23\x24\x2c\x14\x2d\x05\x2d\x05\x2d\x09\x10\x0c\x0e\x0c\x13\x0c\x22\x1a\x21\x0c\x22\x0c\x22\x09\x2d\x0d\x17\x18\x1f\x21\x2c\x0d\x2d\x0d\x2d\x00\x00\x0c\x17\x05\x17",
};
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 379,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_17_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x64\x01\x6b\x02\x72\x09\x64\x02\x7d\x00\x6e\x02\x64\x03\x7d\x00\x74\x02\x6a\x03\x64\x04\x7c\x00\xa9\x02\x74\x04\x5f\x05\x74\x02\x6a\x03\x64\x05\x7c\x00\xa9\x02\x74\x04\x5f\x06\x64\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[174];
    }
toplevel_consts_18_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 173,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x65\x66\x69\x6e\x65\x20\x6e\x65\x77\x20\x62\x75\x69\x6c\x74\x69\x6e\x73\x20\x27\x71\x75\x69\x74\x27\x20\x61\x6e\x64\x20\x27\x65\x78\x69\x74\x27\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x73\x65\x20\x61\x72\x65\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x77\x68\x69\x63\x68\x20\x6d\x61\x6b\x65\x20\x74\x68\x65\x20\x69\x6e\x74\x65\x72\x70\x72\x65\x74\x65\x72\x20\x65\x78\x69\x74\x20\x77\x68\x65\x6e\x20\x63\x61\x6c\x6c\x65\x64\x2e\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x72\x65\x70\x72\x20\x6f\x66\x20\x65\x61\x63\x68\x20\x6f\x62\x6a\x65\x63\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x73\x20\x61\x20\x68\x69\x6e\x74\x20\x61\x74\x20\x68\x6f\x77\x20\x69\x74\x20\x77\x6f\x72\x6b\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_18_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\\",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_18_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 18,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Ctrl-Z plus Return",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_18_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Ctrl-D (i.e. EOF)",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "quit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_18_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_18_consts_1._ascii.ob_base,
            & toplevel_consts_18_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3._ascii.ob_base,
            & toplevel_consts_18_consts_4._ascii.ob_base,
            & toplevel_consts_18_consts_5._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_18_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_sitebuiltins",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_18_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Quitter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_18_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "builtins",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_18_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_16_names_4._ascii.ob_base,
            & toplevel_consts_18_names_2._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_18_consts_4._ascii.ob_base,
            & toplevel_consts_18_consts_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_18_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "eof",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_18_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_18_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_18_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "setquit",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x07\x06\x01\x04\x02\x0e\x02\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_18_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x07\x02\x03\x06\xfe\x04\x02\x0e\x02\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0a\x08\x0e\x12\x16\x08\x16\x05\x22\x0f\x23\x09\x0c\x09\x0c\x0f\x22\x09\x0c\x15\x22\x15\x2a\x2b\x31\x33\x36\x15\x37\x05\x0d\x05\x12\x15\x22\x15\x2a\x2b\x31\x33\x36\x15\x37\x05\x0d\x05\x12\x05\x12\x05\x12",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 388,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_18_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[195];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 194,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x64\x01\x74\x02\x6a\x03\xa9\x02\x74\x04\x5f\x03\x74\x02\x6a\x05\x64\x02\x64\x03\x85\x02\x19\x00\x64\x04\x6b\x02\x72\x1a\x74\x00\x6a\x01\x64\x05\x64\x06\xa9\x02\x74\x04\x5f\x06\x6e\x07\x74\x00\x6a\x01\x64\x05\x64\x07\xa9\x02\x74\x04\x5f\x06\x67\x00\x67\x00\x02\x02\x7d\x00\x7d\x01\x74\x07\x74\x02\x64\x08\x64\x02\xa9\x03\x7d\x02\x7c\x02\x73\x3b\x74\x08\x74\x09\x64\x09\xa9\x02\x72\x3b\x74\x09\x6a\x0a\xa0\x0b\x74\x09\x6a\x0c\xa8\x01\xa9\x01\x7d\x02\x7c\x02\x72\x56\x7c\x00\xa0\x0d\x64\x0a\x64\x0b\x67\x02\xa8\x01\xa9\x01\x01\x00\x7c\x01\xa0\x0d\x74\x09\x6a\x0a\xa0\x0e\x7c\x02\x74\x09\x6a\x0f\xa8\x02\xa9\x02\x7c\x02\x74\x09\x6a\x10\x67\x03\xa8\x01\xa9\x01\x01\x00\x74\x00\x6a\x01\x64\x0c\x64\x0d\x7c\x00\x7c\x01\xa9\x04\x74\x04\x5f\x11\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_19_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 41,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Set 'copyright' and 'credits' in builtins",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_19_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "copyright",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_19_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_19_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "java",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "credits",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[64];
    }
toplevel_consts_19_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 63,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Jython is maintained by the Jython developers (www.jython.org).",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[159];
    }
toplevel_consts_19_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 158,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x20\x20\x20\x54\x68\x61\x6e\x6b\x73\x20\x74\x6f\x20\x43\x57\x49\x2c\x20\x43\x4e\x52\x49\x2c\x20\x42\x65\x4f\x70\x65\x6e\x2e\x63\x6f\x6d\x2c\x20\x5a\x6f\x70\x65\x20\x43\x6f\x72\x70\x6f\x72\x61\x74\x69\x6f\x6e\x20\x61\x6e\x64\x20\x61\x20\x63\x61\x73\x74\x20\x6f\x66\x20\x74\x68\x6f\x75\x73\x61\x6e\x64\x73\x0a\x20\x20\x20\x20\x66\x6f\x72\x20\x73\x75\x70\x70\x6f\x72\x74\x69\x6e\x67\x20\x50\x79\x74\x68\x6f\x6e\x20\x64\x65\x76\x65\x6c\x6f\x70\x6d\x65\x6e\x74\x2e\x20\x20\x53\x65\x65\x20\x77\x77\x77\x2e\x70\x79\x74\x68\x6f\x6e\x2e\x6f\x72\x67\x20\x66\x6f\x72\x20\x6d\x6f\x72\x65\x20\x69\x6e\x66\x6f\x72\x6d\x61\x74\x69\x6f\x6e\x2e",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_19_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_stdlib_dir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_19_consts_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "LICENSE.txt",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_consts_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "LICENSE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_consts_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "license",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_19_consts_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 39,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "See https://www.python.org/psf/license/",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_19_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_19_consts_0._ascii.ob_base,
            & toplevel_consts_19_consts_1._ascii.ob_base,
            Py_None,
            & toplevel_consts_19_consts_3.ob_base.ob_base,
            & toplevel_consts_19_consts_4._ascii.ob_base,
            & toplevel_consts_19_consts_5._ascii.ob_base,
            & toplevel_consts_19_consts_6._ascii.ob_base,
            & toplevel_consts_19_consts_7._ascii.ob_base,
            & toplevel_consts_19_consts_8._ascii.ob_base,
            & toplevel_consts_5_names_12._ascii.ob_base,
            & toplevel_consts_19_consts_10._ascii.ob_base,
            & toplevel_consts_19_consts_11._ascii.ob_base,
            & toplevel_consts_19_consts_12._ascii.ob_base,
            & toplevel_consts_19_consts_13._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_Printer",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getattr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_names_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "dirname",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_19_names_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "extend",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_19_names_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "pardir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_19_names_16 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "curdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_19_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_18_names_2._ascii.ob_base,
            & toplevel_consts_19_names_1._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_19_consts_1._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_19_consts_5._ascii.ob_base,
            & toplevel_consts_19_names_7._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_19_names_11._ascii.ob_base,
            & toplevel_consts_5_names_12._ascii.ob_base,
            & toplevel_consts_19_names_13._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_19_names_15._ascii.ob_base,
            & toplevel_consts_19_names_16._ascii.ob_base,
            & toplevel_consts_19_consts_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_19_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "files",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_19_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "dirs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_19_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "here",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_19_varnames_1._ascii.ob_base,
            & toplevel_consts_19_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_19_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "setcopyright",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x02\x12\x01\x04\x01\x02\x01\x02\x01\x08\xfe\x0e\x04\x0a\x03\x0c\x03\x0e\x01\x10\x01\x04\x01\x10\x01\x22\x01\x04\x01\x02\x01\x02\x01\x04\x01\x0a\xfd",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x02\x10\x01\x02\x07\x04\xfa\x02\x01\x04\x01\x06\xfe\x06\x04\x04\x02\x04\xfe\x0a\x03\x0c\x03\x02\x01\x02\x01\x08\xff\x12\x01\x02\x01\x02\x02\x10\xff\x22\x01\x04\x01\x02\x01\x02\x01\x06\x01\x08\xfd",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[195];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 194,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1a\x27\x1a\x30\x31\x3c\x3e\x41\x3e\x4b\x1a\x4c\x05\x0d\x05\x17\x08\x0b\x08\x14\x15\x17\x16\x17\x15\x17\x08\x18\x1c\x22\x08\x22\x05\x55\x1c\x29\x1c\x32\x0d\x16\x0d\x4e\x1c\x4f\x09\x11\x09\x19\x09\x19\x1c\x29\x1c\x32\x33\x3c\x3e\x54\x1c\x55\x09\x11\x09\x19\x13\x15\x17\x19\x13\x19\x05\x0a\x0c\x10\x0c\x13\x14\x17\x19\x26\x28\x2c\x0c\x2d\x05\x09\x0c\x10\x05\x2c\x15\x1c\x1d\x1f\x21\x2b\x15\x2c\x05\x2c\x10\x12\x10\x17\x10\x2c\x20\x22\x20\x2b\x10\x2c\x10\x2c\x09\x0d\x08\x0c\x05\x46\x09\x0e\x09\x31\x17\x24\x26\x2f\x16\x30\x09\x31\x09\x31\x09\x31\x09\x0d\x09\x46\x16\x18\x16\x1d\x16\x33\x23\x27\x29\x2b\x29\x32\x16\x33\x16\x33\x35\x39\x3b\x3d\x3b\x44\x15\x45\x09\x46\x09\x46\x09\x46\x18\x25\x18\x2e\x09\x12\x09\x32\x09\x0e\x10\x14\x18\x15\x05\x0d\x05\x15\x05\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 404,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_20_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\xa9\x00\x74\x02\x5f\x03\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_20_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_Helper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_20_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "help",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_18_names_2._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_20_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sethelper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x22\x15\x2a\x15\x2c\x05\x0d\x05\x12\x05\x12\x05\x12",
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 430,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_21_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x84\x00\x7d\x00\x7c\x00\x74\x00\x5f\x01\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[363];
    }
toplevel_consts_21_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 362,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x6e\x61\x62\x6c\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x72\x65\x61\x64\x6c\x69\x6e\x65\x20\x63\x6f\x6e\x66\x69\x67\x75\x72\x61\x74\x69\x6f\x6e\x20\x6f\x6e\x20\x69\x6e\x74\x65\x72\x61\x63\x74\x69\x76\x65\x20\x70\x72\x6f\x6d\x70\x74\x73\x2c\x20\x62\x79\x0a\x20\x20\x20\x20\x72\x65\x67\x69\x73\x74\x65\x72\x69\x6e\x67\x20\x61\x20\x73\x79\x73\x2e\x5f\x5f\x69\x6e\x74\x65\x72\x61\x63\x74\x69\x76\x65\x68\x6f\x6f\x6b\x5f\x5f\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x74\x68\x65\x20\x72\x65\x61\x64\x6c\x69\x6e\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x63\x61\x6e\x20\x62\x65\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2c\x20\x74\x68\x65\x20\x68\x6f\x6f\x6b\x20\x77\x69\x6c\x6c\x20\x73\x65\x74\x20\x74\x68\x65\x20\x54\x61\x62\x20\x6b\x65\x79\x0a\x20\x20\x20\x20\x61\x73\x20\x63\x6f\x6d\x70\x6c\x65\x74\x69\x6f\x6e\x20\x6b\x65\x79\x20\x61\x6e\x64\x20\x72\x65\x67\x69\x73\x74\x65\x72\x20\x7e\x2f\x2e\x70\x79\x74\x68\x6f\x6e\x5f\x68\x69\x73\x74\x6f\x72\x79\x20\x61\x73\x20\x68\x69\x73\x74\x6f\x72\x79\x20\x66\x69\x6c\x65\x2e\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x6f\x76\x65\x72\x72\x69\x64\x64\x65\x6e\x20\x69\x6e\x20\x74\x68\x65\x20\x73\x69\x74\x65\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x20\x6f\x72\x20\x75\x73\x65\x72\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2c\x0a\x20\x20\x20\x20\x6f\x72\x20\x69\x6e\x20\x61\x20\x50\x59\x54\x48\x4f\x4e\x53\x54\x41\x52\x54\x55\x50\x20\x66\x69\x6c\x65\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[249];
    }
toplevel_consts_21_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 248,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x04\x87\x05\x97\x00\x64\x01\x64\x00\x6c\x00\x7d\x00\x09\x00\x64\x01\x64\x00\x6c\x01\x8a\x05\x64\x01\x64\x00\x6c\x02\x7d\x01\x6e\x0b\x23\x00\x74\x03\x79\x18\x01\x00\x59\x00\x64\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x04\x89\x05\x64\x02\x64\x03\xa9\x03\x7d\x02\x7c\x02\x81\x2f\x64\x04\x7c\x02\x76\x00\x72\x2f\x89\x05\xa0\x05\x64\x05\xa8\x01\xa9\x01\x01\x00\x6e\x06\x89\x05\xa0\x05\x64\x06\xa8\x01\xa9\x01\x01\x00\x09\x00\x89\x05\xa0\x06\xa8\x00\xa9\x00\x01\x00\x6e\x0a\x23\x00\x74\x07\x79\x42\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x89\x05\xa0\x08\xa8\x00\xa9\x00\x64\x01\x6b\x02\x72\x7a\x74\x09\x6a\x0a\xa0\x0b\x74\x09\x6a\x0a\xa0\x0c\x64\x07\xa8\x01\xa9\x01\x64\x08\xa8\x02\xa9\x02\x8a\x04\x09\x00\x89\x05\xa0\x0d\x89\x04\xa8\x01\xa9\x01\x01\x00\x6e\x0a\x23\x00\x74\x07\x79\x68\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x88\x04\x88\x05\x66\x02\x64\x09\x84\x08\x7d\x03\x7c\x00\xa0\x0e\x7c\x03\xa8\x01\xa9\x01\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_consts_1_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__doc__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_consts_1_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "libedit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_21_consts_1_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 19,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "bind ^I rl_complete",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_21_consts_1_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "tab: complete",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_21_consts_1_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 15,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".python_history",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_21_consts_1_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x02\x97\x00\x09\x00\x89\x01\xa0\x00\x89\x00\xa8\x01\xa9\x01\x01\x00\x64\x00\x53\x00\x23\x00\x74\x01\x79\x12\x01\x00\x59\x00\x64\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_21_consts_1_consts_9_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 18,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "write_history_file",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_21_consts_1_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_consts_9_names_0._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_consts_1_consts_9_freevars_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "history",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_21_consts_1_consts_9_freevars_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "readline",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_21_consts_1_consts_9_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_consts_9_freevars_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_21_consts_1_consts_9_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "write_history",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_21_consts_1_consts_9_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 67,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "enablerlcompleter.<locals>.register_readline.<locals>.write_history",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_21_consts_1_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x01\x10\x01\x02\x80\x06\x01\x06\x03\x02\xfd\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_21_consts_1_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x06\x10\xfc\x02\x80\x02\x01\x0c\x03\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_21_consts_1_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x11\x19\x15\x1d\x15\x39\x31\x38\x15\x39\x15\x39\x15\x39\x15\x39\x15\x39\x00\x00\x18\x1f\x11\x19\x11\x19\x15\x19\x15\x19\x15\x19\x11\x19\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_21_consts_1_consts_9_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x83\x06\x0b\x00\x8b\x04\x13\x03\x92\x01\x13\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_21_consts_1_consts_9_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x80\x80",
};
static struct PyCodeObject toplevel_consts_21_consts_1_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_consts_1_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_consts_1_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_21_consts_1_consts_9_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 480,
    .co_code = & toplevel_consts_21_consts_1_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_consts_1_consts_9_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_consts_1_consts_9_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_consts_1_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_consts_1_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_consts_1_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_consts_1_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_consts_1_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_21_consts_1_consts_9_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_21_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_21_consts_1_consts_2._ascii.ob_base,
            & toplevel_consts_8_consts_8._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_5._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_6._ascii.ob_base,
            & toplevel_consts_11_consts_6._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_8._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_21_consts_1_names_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "atexit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_21_consts_1_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "rlcompleter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_21_consts_1_names_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "ImportError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_21_consts_1_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "parse_and_bind",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_21_consts_1_names_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 14,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "read_init_file",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_21_consts_1_names_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 26,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "get_current_history_length",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_21_consts_1_names_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "read_history_file",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_21_consts_1_names_14 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "register",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_21_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_freevars_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_19_names_7._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_5._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_6._ascii.ob_base,
            & toplevel_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_8._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_11_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_13._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_21_consts_1_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "readline_doc",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_21_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_21_consts_1_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "register_readline",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_21_consts_1_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 44,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "enablerlcompleter.<locals>.register_readline",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_21_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x02\x01\x08\x01\x0a\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x0c\x05\x0c\x01\x0e\x01\x0c\x02\x02\x02\x0c\x01\x02\x80\x06\x01\x04\x05\x02\xfb\x06\x80\x0e\x07\x12\x06\x02\x01\x06\xff\x02\x02\x0e\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x0c\x03\x10\x08\x04\xeb",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[77];
    }
toplevel_consts_21_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 76,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x02\x05\x08\xfd\x0a\x01\x02\x80\x02\x01\x0c\x01\x06\x80\x0c\x04\x02\x01\x02\x03\x06\xfd\x02\x03\x0e\xfe\x0c\x02\x02\x09\x0c\xfa\x02\x80\x02\x01\x0a\x05\x06\x80\x0c\x02\x02\x15\x04\xf1\x02\x01\x0c\xff\x06\x01\x02\xff\x02\x05\x0e\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x0c\x08\x14\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[249];
    }
toplevel_consts_21_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 248,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x09\x16\x09\x16\x09\x16\x09\x16\x09\x13\x0d\x1c\x0d\x1c\x0d\x1c\x0d\x1c\x0d\x1f\x0d\x1f\x0d\x1f\x0d\x1f\x0d\x1f\x00\x00\x10\x1b\x09\x13\x09\x13\x0d\x13\x0d\x13\x0d\x13\x09\x13\x00\x00\x00\x00\x00\x00\x18\x1f\x20\x28\x2a\x33\x35\x37\x18\x38\x09\x15\x0c\x18\x09\x35\x29\x32\x36\x42\x29\x42\x09\x35\x0d\x15\x0d\x3b\x25\x3a\x0d\x3b\x0d\x3b\x0d\x3b\x0d\x3b\x0d\x15\x0d\x35\x25\x34\x0d\x35\x0d\x35\x0d\x35\x09\x11\x0d\x15\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x00\x00\x10\x17\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x0c\x14\x0c\x31\x0c\x31\x0c\x31\x35\x36\x0c\x36\x09\x2b\x17\x19\x17\x1e\x17\x36\x24\x26\x24\x2b\x24\x3b\x37\x3a\x24\x3b\x24\x3b\x24\x35\x17\x36\x17\x36\x0d\x14\x0d\x15\x11\x19\x11\x34\x2c\x33\x11\x34\x11\x34\x11\x34\x11\x34\x00\x00\x14\x1b\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x13\x0d\x2b\x1d\x2a\x0d\x2b\x0d\x2b\x0d\x2b\x0d\x2b\x0d\x2b\x09\x2b\x09\x2b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[46];
    }
toplevel_consts_21_consts_1_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 45,
    },
    .ob_shash = -1,
    .ob_sval = "\x88\x08\x11\x00\x91\x04\x19\x03\x98\x01\x19\x03\xb6\x05\x3c\x00\xbc\x04\x41\x03\x03\xc1\x02\x01\x41\x03\x03\xc1\x1b\x06\x41\x22\x00\xc1\x22\x04\x41\x29\x03\xc1\x28\x01\x41\x29\x03",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_21_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_name._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_freevars_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_9_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_21_consts_1_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "    @@",
};
static struct PyCodeObject toplevel_consts_21_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_21_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 442,
    .co_code = & toplevel_consts_21_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 4,
    .co_nplaincellvars = 2,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_21_consts_1_consts_9_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_21_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_21_consts_0._ascii.ob_base,
            & toplevel_consts_21_consts_1.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_21_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 19,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__interactivehook__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_21_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_21_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_21_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "enablerlcompleter",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_21_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x09\x0a\x30",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_21_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x37\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_21_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x2b\x05\x2b\x05\x2b\x1f\x30\x05\x08\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_21 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 433,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[375];
    }
toplevel_consts_22_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 374,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7d\x01\x74\x02\x6a\x03\x64\x01\x6b\x02\x72\x16\x64\x02\x7c\x01\x76\x00\x72\x16\x74\x00\x6a\x01\x64\x02\x19\x00\x04\x00\x7d\x02\x74\x02\x5f\x04\x6e\x03\x74\x02\x6a\x05\x7d\x02\x74\x00\x6a\x06\xa0\x07\x74\x00\x6a\x06\xa0\x08\x7c\x02\xa8\x01\xa9\x01\xa8\x01\xa9\x01\x5c\x02\x7d\x03\x7d\x04\x74\x00\x6a\x06\xa0\x09\x7c\x03\xa8\x01\xa9\x01\x7d\x05\x64\x00\x74\x02\x5f\x0a\x64\x03\x7d\x06\x64\x04\x84\x00\x74\x00\x6a\x06\xa0\x0b\x7c\x03\x7c\x06\xa8\x02\xa9\x02\x74\x00\x6a\x06\xa0\x0b\x7c\x05\x7c\x06\xa8\x02\xa9\x02\x66\x02\x44\x00\xa9\x01\x7d\x07\x7c\x07\x72\xb9\x7c\x07\x64\x05\x19\x00\x7d\x08\x64\x06\x7d\x09\x74\x0c\x7c\x08\x64\x07\x64\x08\xaa\x02\x35\x00\x7d\x0a\x7c\x0a\x44\x00\x5d\x2d\x7d\x0b\x64\x09\x7c\x0b\x76\x00\x72\x85\x7c\x0b\xa0\x0d\x64\x09\xa8\x01\xa9\x01\x5c\x03\x7d\x0c\x7d\x04\x7d\x0d\x7c\x0c\xa0\x0e\xa8\x00\xa9\x00\xa0\x0f\xa8\x00\xa9\x00\x7d\x0c\x7c\x0d\xa0\x0e\xa8\x00\xa9\x00\x7d\x0d\x7c\x0c\x64\x0a\x6b\x02\x72\x7e\x7c\x0d\xa0\x0f\xa8\x00\xa9\x00\x7d\x09\x71\x58\x7c\x0c\x64\x0b\x6b\x02\x72\x85\x7c\x0d\x74\x02\x5f\x0a\x71\x58\x09\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x94\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x05\x04\x00\x74\x02\x5f\x10\x74\x02\x5f\x11\x74\x12\x7c\x00\x74\x02\x6a\x10\x67\x01\xa9\x02\x01\x00\x7c\x09\x64\x06\x6b\x02\x72\xb3\x74\x13\xa0\x14\x64\x05\x74\x02\x6a\x10\xa8\x02\xa9\x02\x01\x00\x7c\x00\x53\x00\x74\x02\x6a\x10\x67\x01\x61\x13\x64\x0c\x61\x15\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_22_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 19,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__PYVENV_LAUNCHER__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_22_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "pyvenv.cfg",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_22_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7c\x00\x5d\x0b\x7d\x01\x74\x00\x6a\x01\xa0\x02\x7c\x01\xa8\x01\xa9\x01\x72\x03\x7c\x01\x91\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_22_consts_4_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "isfile",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_22_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_22_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_22_consts_4_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "conffile",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_9_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_22_consts_4_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 24,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "venv.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_22_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x08\x00\x02\x01\x0c\x04\x02\xfb\x02\x01\x06\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_22_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x06\x02\xfb\x0c\x04\x02\x01\x02\xfb\x06\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_22_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x0a\x17\x0a\x17\x0a\x16\x1e\x0c\x0e\x0c\x13\x0c\x24\x1b\x23\x0c\x24\x0c\x24\x17\x0a\x09\x11\x17\x0a\x17\x0a\x17\x0a",
};
static struct PyCodeObject toplevel_consts_22_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 504,
    .co_code = & toplevel_consts_22_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_9_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "true",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_consts_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "utf-8",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_22_consts_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "=",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_22_consts_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 28,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "include-system-site-packages",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_consts_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "home",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_11_consts_8._ascii.ob_base,
            & toplevel_consts_22_consts_2._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_22_consts_4.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_22_consts_6._ascii.ob_base,
            & toplevel_consts_22_consts_7._ascii.ob_base,
            & toplevel_consts_8_consts_6._object.ob_base.ob_base,
            & toplevel_consts_22_consts_9._ascii.ob_base,
            & toplevel_consts_22_consts_10._ascii.ob_base,
            & toplevel_consts_22_consts_11._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_22_names_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 16,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_base_executable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_22_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "executable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "split",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_names_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_home",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_names_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "open",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_22_names_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "partition",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_names_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "lower",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_22_names_17 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exec_prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_22_names_20 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "insert",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[22];
        }_object;
    }
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 22,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_22_names_4._ascii.ob_base,
            & toplevel_consts_22_names_5._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_19_names_11._ascii.ob_base,
            & toplevel_consts_22_names_10._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_22_names_12._ascii.ob_base,
            & toplevel_consts_22_names_13._ascii.ob_base,
            & toplevel_consts_8_names_11._ascii.ob_base,
            & toplevel_consts_22_names_15._ascii.ob_base,
            & toplevel_consts_16_varnames_3._ascii.ob_base,
            & toplevel_consts_22_names_17._ascii.ob_base,
            & toplevel_consts_17_name._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_22_names_20._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_22_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "env",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_22_varnames_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exe_dir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_22_varnames_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "site_prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_22_varnames_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "conf_basename",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_22_varnames_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 15,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "candidate_confs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_22_varnames_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "virtual_conf",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_22_varnames_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "system_site",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_22_varnames_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "key",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_varnames_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "value",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_22_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_22_names_5._ascii.ob_base,
            & toplevel_consts_22_varnames_3._ascii.ob_base,
            & toplevel_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_22_varnames_5._ascii.ob_base,
            & toplevel_consts_22_varnames_6._ascii.ob_base,
            & toplevel_consts_22_varnames_7._ascii.ob_base,
            & toplevel_consts_22_varnames_8._ascii.ob_base,
            & toplevel_consts_22_varnames_9._ascii.ob_base,
            & toplevel_consts_8_varnames_5._ascii.ob_base,
            & toplevel_consts_8_varnames_7._ascii.ob_base,
            & toplevel_consts_22_varnames_12._ascii.ob_base,
            & toplevel_consts_22_varnames_13._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "venv",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x03\x12\x01\x12\x01\x06\x02\x1c\x01\x0e\x01\x06\x01\x04\x01\x04\x01\x0e\x02\x0e\x01\x02\xfe\x06\xff\x04\x08\x08\x01\x04\x01\x0e\x03\x08\x01\x08\x01\x12\x01\x10\x01\x0a\x01\x08\x01\x0c\x01\x08\x01\x06\x01\x02\x80\x02\xf8\x14\xff\x06\x80\x08\x00\x0c\x0b\x0e\x03\x08\x04\x10\x01\x04\x05\x08\xfd\x04\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[103];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 102,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x03\x08\x01\x02\x03\x06\xfd\x02\x03\x12\xfe\x06\x02\x1c\x01\x0e\x01\x06\x01\x04\x01\x04\x07\x0e\xfc\x0e\x01\x02\x01\x04\x02\x02\xfa\x02\x08\x02\x1b\x08\xe6\x04\x01\x0a\x03\x02\x09\x02\xf7\x02\x01\x04\x08\x02\xf8\x06\x01\x02\x07\x12\xfa\x10\x01\x0a\x01\x06\x01\x02\x03\x0c\xfe\x06\x01\x08\x01\x02\x80\x16\x00\x06\x80\x08\x00\x0c\x02\x0e\x03\x06\x04\x02\x04\x10\xfd\x04\x05\x08\xfd\x04\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[375];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 374,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0d\x0b\x15\x05\x08\x08\x0b\x08\x14\x18\x20\x08\x20\x05\x24\x25\x3a\x3e\x41\x25\x41\x05\x24\x2d\x2f\x2d\x37\x38\x4d\x2d\x4e\x09\x4e\x09\x13\x16\x19\x16\x2a\x16\x2a\x16\x19\x16\x24\x09\x13\x12\x14\x12\x19\x12\x3c\x20\x22\x20\x27\x20\x3b\x30\x3a\x20\x3b\x20\x3b\x12\x3c\x12\x3c\x05\x0f\x05\x0c\x0e\x0f\x13\x15\x13\x1a\x13\x2b\x23\x2a\x13\x2b\x13\x2b\x05\x10\x11\x15\x05\x08\x05\x0e\x15\x21\x05\x12\x17\x0a\x17\x0a\x0d\x0f\x0d\x14\x0d\x31\x1a\x21\x23\x30\x0d\x31\x0d\x31\x0d\x0f\x0d\x14\x0d\x35\x1a\x25\x27\x34\x0d\x35\x0d\x35\x22\x0e\x17\x0a\x17\x0a\x05\x14\x08\x17\x05\x25\x18\x27\x28\x29\x18\x2a\x09\x15\x17\x1d\x09\x14\x0e\x12\x13\x1f\x2a\x31\x0e\x32\x0e\x32\x09\x2a\x36\x37\x19\x1a\x0d\x2a\x0d\x2a\x11\x15\x14\x17\x1b\x1f\x14\x1f\x11\x2a\x25\x29\x25\x38\x34\x37\x25\x38\x25\x38\x15\x22\x15\x18\x1a\x1b\x1d\x22\x1b\x1e\x1b\x26\x1b\x26\x1b\x26\x1b\x2e\x1b\x2e\x1b\x2e\x15\x18\x1d\x22\x1d\x2a\x1d\x2a\x1d\x2a\x15\x1a\x18\x1b\x1f\x3d\x18\x3d\x15\x2a\x27\x2c\x27\x34\x27\x34\x27\x34\x19\x24\x19\x24\x1a\x1d\x21\x27\x1a\x27\x15\x2a\x25\x2a\x19\x1c\x19\x22\x00\x00\x0d\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x00\x00\x00\x00\x00\x00\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x28\x33\x09\x33\x09\x0c\x09\x13\x16\x19\x16\x25\x09\x18\x19\x24\x27\x2a\x27\x31\x26\x32\x09\x33\x09\x33\x0c\x17\x1b\x21\x0c\x21\x09\x25\x0d\x15\x0d\x2b\x1d\x1e\x20\x23\x20\x2a\x0d\x2b\x0d\x2b\x0d\x2b\x0c\x17\x05\x17\x19\x1c\x19\x23\x18\x24\x0d\x15\x20\x25\x0d\x1d\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x15\x31\x42\x0d\x03\xc2\x0d\x04\x42\x11\x07\xc2\x14\x01\x42\x11\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_22_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "              ",
};
static struct PyCodeObject toplevel_consts_22 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_22_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 492,
    .co_code = & toplevel_consts_22_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 14,
    .co_nlocals = 14,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[173];
    }
toplevel_consts_23_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 172,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x09\x00\x64\x01\x64\x02\x6c\x00\x7d\x00\x64\x02\x53\x00\x23\x00\x74\x01\x79\x1e\x7d\x01\x7c\x01\x6a\x02\x64\x03\x6b\x02\x72\x13\x6e\x01\x82\x00\x59\x00\x64\x02\x7d\x01\x7e\x01\x64\x02\x53\x00\x64\x02\x7d\x01\x7e\x01\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x23\x00\x74\x03\x79\x52\x7d\x02\x74\x04\x6a\x05\x6a\x06\x72\x32\x74\x04\x6a\x07\x74\x04\x6a\x08\xa9\x00\x8e\x00\x01\x00\x6e\x16\x74\x04\x6a\x09\xa0\x0a\x64\x04\x7c\x02\x6a\x0b\x6a\x0c\x9b\x01\x64\x05\x7c\x02\x9b\x01\x64\x06\x9d\x05\xa8\x01\xa9\x01\x01\x00\x59\x00\x64\x02\x7d\x02\x7e\x02\x64\x02\x53\x00\x59\x00\x64\x02\x7d\x02\x7e\x02\x64\x02\x53\x00\x64\x02\x7d\x02\x7e\x02\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_23_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 44,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Run custom site specific code, if available.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_23_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sitecustomize",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[58];
    }
toplevel_consts_23_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 57,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x73\x69\x74\x65\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x3b\x20\x73\x65\x74\x20\x50\x59\x54\x48\x4f\x4e\x56\x45\x52\x42\x4f\x53\x45\x20\x66\x6f\x72\x20\x74\x72\x61\x63\x65\x62\x61\x63\x6b\x3a\x0a",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_23_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ": ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_23_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_23_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_23_consts_3._ascii.ob_base,
            & toplevel_consts_23_consts_4._ascii.ob_base,
            & toplevel_consts_23_consts_5._ascii.ob_base,
            & toplevel_consts_23_consts_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_23_names_7 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 10,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "excepthook",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23_names_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 5,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "write",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_23_names_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__class__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_23_names_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__name__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_23_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_23_consts_3._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_8_names_19._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_23_names_7._ascii.ob_base,
            & toplevel_consts_8_names_25._ascii.ob_base,
            & toplevel_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_23_names_10._ascii.ob_base,
            & toplevel_consts_23_names_11._ascii.ob_base,
            & toplevel_consts_23_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_23_varnames_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "exc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_23_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 3,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "err",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_23_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_23_consts_3._ascii.ob_base,
            & toplevel_consts_23_varnames_1._ascii.ob_base,
            & toplevel_consts_23_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_23_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "execsitecustomize",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_23_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x02\x01\x0c\x01\x02\x80\x06\x01\x0a\x01\x02\x01\x02\x02\x0c\xfe\x08\x80\x02\xfe\x08\x80\x06\x05\x08\x01\x10\x01\x08\x02\x10\x03\x02\xfe\x12\xff\x0c\xfe\x08\x80\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_23_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x11\x02\xf8\x0c\xfb\x02\x80\x02\x01\x04\x04\x08\xfd\x02\x03\x02\xfe\x02\x02\x0c\xfe\x08\x80\x02\x02\x08\x80\x02\x01\x04\x07\x06\xfa\x02\x06\x10\xfb\x04\x02\x28\x03\x0c\xfb\x08\x80\x02\x05\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[173];
    }
toplevel_consts_23_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 172,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x2f\x09\x16\x0d\x21\x0d\x21\x0d\x21\x0d\x21\x0d\x21\x0d\x21\x00\x00\x10\x1b\x09\x16\x09\x16\x10\x13\x10\x18\x1c\x2b\x10\x2b\x0d\x16\x11\x15\x11\x16\x11\x15\x11\x15\x11\x15\x11\x15\x11\x15\x11\x15\x00\x00\x00\x00\x00\x00\x00\x00\x09\x16\x00\x00\x00\x00\x00\x00\x00\x00\x0c\x15\x05\x2f\x05\x2f\x0c\x0f\x0c\x15\x0c\x1d\x09\x2f\x0d\x10\x0d\x1b\x1d\x20\x1d\x29\x1d\x2b\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x10\x0d\x17\x0d\x2f\x0d\x2f\x12\x15\x12\x1f\x12\x28\x12\x28\x12\x28\x2a\x2d\x2a\x2d\x2a\x2d\x11\x2e\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x00\x00\x00\x00\x00\x00\x00\x00\x05\x2f\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_23_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x83\x04\x09\x00\x89\x04\x1f\x03\x8d\x07\x1a\x03\x94\x04\x22\x00\x9a\x05\x1f\x03\x9f\x03\x22\x00\xa2\x04\x41\x13\x03\xa6\x1c\x41\x0e\x03\xc1\x0e\x05\x41\x13\x03",
};
static struct PyCodeObject toplevel_consts_23 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_23_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 8,
    .co_firstlineno = 544,
    .co_code = & toplevel_consts_23_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_24_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 44,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Run custom user specific code, if available.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_24_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "usercustomize",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[58];
    }
toplevel_consts_24_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 57,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x75\x73\x65\x72\x63\x75\x73\x74\x6f\x6d\x69\x7a\x65\x3b\x20\x73\x65\x74\x20\x50\x59\x54\x48\x4f\x4e\x56\x45\x52\x42\x4f\x53\x45\x20\x66\x6f\x72\x20\x74\x72\x61\x63\x65\x62\x61\x63\x6b\x3a\x0a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_24_consts_3._ascii.ob_base,
            & toplevel_consts_24_consts_4._ascii.ob_base,
            & toplevel_consts_23_consts_5._ascii.ob_base,
            & toplevel_consts_23_consts_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_24_consts_3._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_8_names_19._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_23_names_7._ascii.ob_base,
            & toplevel_consts_8_names_25._ascii.ob_base,
            & toplevel_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_23_names_10._ascii.ob_base,
            & toplevel_consts_23_names_11._ascii.ob_base,
            & toplevel_consts_23_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_24_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_24_consts_3._ascii.ob_base,
            & toplevel_consts_23_varnames_1._ascii.ob_base,
            & toplevel_consts_23_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_24_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 17,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "execusercustomize",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_23_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 8,
    .co_firstlineno = 564,
    .co_code = & toplevel_consts_23_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_consts_25_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x64\x01\x64\x01\x85\x02\x19\x00\x7d\x00\x74\x02\xa9\x00\x7d\x01\x7c\x00\x74\x00\x6a\x01\x6b\x03\x72\x13\x74\x03\xa9\x00\x01\x00\x74\x04\x7c\x01\xa9\x01\x7d\x01\x74\x05\x80\x1c\x74\x06\xa9\x00\x61\x05\x74\x07\x7c\x01\xa9\x01\x7d\x01\x74\x08\x7c\x01\xa9\x01\x7d\x01\x74\x09\xa9\x00\x01\x00\x74\x0a\xa9\x00\x01\x00\x74\x0b\xa9\x00\x01\x00\x74\x00\x6a\x0c\x6a\x0d\x73\x34\x74\x0e\xa9\x00\x01\x00\x74\x0f\xa9\x00\x01\x00\x74\x05\x72\x3e\x74\x10\xa9\x00\x01\x00\x64\x01\x53\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[208];
    }
toplevel_consts_25_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 207,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x64\x64\x20\x73\x74\x61\x6e\x64\x61\x72\x64\x20\x73\x69\x74\x65\x2d\x73\x70\x65\x63\x69\x66\x69\x63\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x74\x6f\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x63\x61\x6c\x6c\x65\x64\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x77\x68\x65\x6e\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2c\x0a\x20\x20\x20\x20\x75\x6e\x6c\x65\x73\x73\x20\x74\x68\x65\x20\x70\x79\x74\x68\x6f\x6e\x20\x69\x6e\x74\x65\x72\x70\x72\x65\x74\x65\x72\x20\x77\x61\x73\x20\x73\x74\x61\x72\x74\x65\x64\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x2d\x53\x20\x66\x6c\x61\x67\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_25_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_25_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_25_names_13 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "isolated",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts_25_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_6_name._ascii.ob_base,
            & toplevel_consts_5_name._ascii.ob_base,
            & toplevel_consts_22_name._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_10_name._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_17_name._ascii.ob_base,
            & toplevel_consts_18_name._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_25_names_13._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_23_name._ascii.ob_base,
            & toplevel_consts_24_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_25_varnames_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "orig_path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_25_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_25_varnames_0._ascii.ob_base,
            & toplevel_consts_6_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_25_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "main",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_25_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x08\x06\x01\x0a\x01\x06\x03\x08\x02\x04\x01\x06\x01\x08\x01\x08\x01\x06\x01\x06\x01\x06\x01\x08\x01\x06\x01\x06\x01\x04\x01\x0a\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_25_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x08\x06\x01\x08\x01\x08\x03\x08\x02\x02\x01\x08\x01\x08\x01\x08\x01\x06\x01\x06\x01\x06\x01\x06\x01\x08\x01\x06\x01\x02\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_consts_25_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x14\x11\x19\x1a\x1b\x1a\x1b\x1a\x1b\x11\x1c\x05\x0e\x13\x21\x13\x23\x05\x10\x08\x11\x15\x18\x15\x1d\x08\x1d\x05\x14\x09\x12\x09\x14\x09\x14\x13\x17\x18\x23\x13\x24\x05\x10\x08\x18\x05\x32\x1c\x30\x1c\x32\x09\x19\x13\x26\x27\x32\x13\x33\x05\x10\x13\x22\x23\x2e\x13\x2f\x05\x10\x05\x0c\x05\x0e\x05\x0e\x05\x11\x05\x13\x05\x13\x05\x0e\x05\x10\x05\x10\x0c\x0f\x0c\x15\x0c\x1e\x05\x1c\x09\x1a\x09\x1c\x09\x1c\x05\x16\x05\x18\x05\x18\x08\x18\x05\x1c\x09\x1a\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_25 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_25_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_25_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_25_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 584,
    .co_code = & toplevel_consts_25_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_25_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_25_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_25_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_25_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_25_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_25_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_25_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[355];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 354,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x00\x74\x00\x6a\x01\x64\x02\x64\x00\x85\x02\x19\x00\x7d\x01\x7c\x01\x73\x51\x74\x02\xa9\x00\x7d\x02\x74\x03\xa9\x00\x7d\x03\x74\x04\x64\x03\xa9\x01\x01\x00\x74\x00\x6a\x05\x44\x00\x5d\x0a\x7d\x04\x74\x04\x64\x04\x7c\x04\x9b\x02\x64\x05\x9d\x03\xa9\x01\x01\x00\x71\x19\x74\x04\x64\x06\xa9\x01\x01\x00\x64\x07\x84\x00\x7d\x05\x74\x04\x64\x08\x7c\x02\x9b\x02\x64\x09\x7c\x05\x7c\x02\xa9\x01\x9b\x00\x64\x0a\x9d\x05\xa9\x01\x01\x00\x74\x04\x64\x0b\x7c\x03\x9b\x02\x64\x09\x7c\x05\x7c\x03\xa9\x01\x9b\x00\x64\x0a\x9d\x05\xa9\x01\x01\x00\x74\x04\x64\x0c\x74\x06\x9b\x02\x9d\x02\xa9\x01\x01\x00\x74\x00\x6a\x07\x64\x0d\xa9\x01\x01\x00\x67\x00\x7d\x06\x64\x0e\x7c\x01\x76\x00\x72\x5d\x7c\x06\xa0\x08\x74\x09\xa8\x01\xa9\x01\x01\x00\x64\x0f\x7c\x01\x76\x00\x72\x67\x7c\x06\xa0\x08\x74\x0a\xa8\x01\xa9\x01\x01\x00\x7c\x06\x72\x96\x74\x04\x74\x0b\x6a\x0c\xa0\x0d\x7c\x06\xa8\x01\xa9\x01\xa9\x01\x01\x00\x74\x06\x72\x7b\x74\x00\x6a\x07\x64\x0d\xa9\x01\x01\x00\x64\x00\x53\x00\x74\x06\x64\x10\x75\x00\x72\x86\x74\x00\x6a\x07\x64\x02\xa9\x01\x01\x00\x64\x00\x53\x00\x74\x06\x80\x8f\x74\x00\x6a\x07\x64\x11\xa9\x01\x01\x00\x64\x00\x53\x00\x74\x00\x6a\x07\x64\x12\xa9\x01\x01\x00\x64\x00\x53\x00\x64\x0d\x64\x00\x6c\x0e\x7d\x07\x74\x04\x7c\x07\xa0\x0f\x7c\x00\x74\x00\x6a\x01\x64\x0d\x19\x00\x74\x0b\x6a\x0c\x66\x02\x7a\x06\xa8\x01\xa9\x01\xa9\x01\x01\x00\x74\x00\x6a\x07\x64\x13\xa9\x01\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[435];
    }
toplevel_consts_26_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 434,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x20\x20\x20\x25\x73\x20\x5b\x2d\x2d\x75\x73\x65\x72\x2d\x62\x61\x73\x65\x5d\x20\x5b\x2d\x2d\x75\x73\x65\x72\x2d\x73\x69\x74\x65\x5d\x0a\x0a\x20\x20\x20\x20\x57\x69\x74\x68\x6f\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x72\x69\x6e\x74\x20\x73\x6f\x6d\x65\x20\x75\x73\x65\x66\x75\x6c\x20\x69\x6e\x66\x6f\x72\x6d\x61\x74\x69\x6f\x6e\x0a\x20\x20\x20\x20\x57\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x72\x69\x6e\x74\x20\x74\x68\x65\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x55\x53\x45\x52\x5f\x42\x41\x53\x45\x20\x61\x6e\x64\x2f\x6f\x72\x20\x55\x53\x45\x52\x5f\x53\x49\x54\x45\x20\x73\x65\x70\x61\x72\x61\x74\x65\x64\x0a\x20\x20\x20\x20\x62\x79\x20\x27\x25\x73\x27\x2e\x0a\x0a\x20\x20\x20\x20\x45\x78\x69\x74\x20\x63\x6f\x64\x65\x73\x20\x77\x69\x74\x68\x20\x2d\x2d\x75\x73\x65\x72\x2d\x62\x61\x73\x65\x20\x6f\x72\x20\x2d\x2d\x75\x73\x65\x72\x2d\x73\x69\x74\x65\x3a\x0a\x20\x20\x20\x20\x20\x20\x30\x20\x2d\x20\x75\x73\x65\x72\x20\x73\x69\x74\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x65\x6e\x61\x62\x6c\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x31\x20\x2d\x20\x75\x73\x65\x72\x20\x73\x69\x74\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x64\x69\x73\x61\x62\x6c\x65\x64\x20\x62\x79\x20\x75\x73\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x32\x20\x2d\x20\x75\x73\x65\x72\x20\x73\x69\x74\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x64\x69\x73\x61\x62\x6c\x65\x64\x20\x62\x79\x20\x73\x75\x70\x65\x72\x20\x75\x73\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x72\x20\x66\x6f\x72\x20\x73\x65\x63\x75\x72\x69\x74\x79\x20\x72\x65\x61\x73\x6f\x6e\x73\x0a\x20\x20\x20\x20\x20\x3e\x32\x20\x2d\x20\x75\x6e\x6b\x6e\x6f\x77\x6e\x20\x65\x72\x72\x6f\x72\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 12,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "sys.path = [",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_consts_4 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "    ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ",",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "]",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_26_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x81\x0c\x74\x00\x6a\x01\xa0\x02\x7c\x00\xa8\x01\xa9\x01\x72\x0c\x64\x01\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_26_consts_7_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 13,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "doesn't exist",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_7_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_26_consts_7_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 23,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_script.<locals>.exists",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x12\x01\x04\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_26_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x02\x03\x0c\xfd\x02\x03\x04\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_26_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x0d\x27\x25\x27\x25\x2c\x25\x38\x33\x37\x25\x38\x25\x38\x0d\x27\x18\x20\x18\x20\x18\x27\x18\x27",
};
static struct PyCodeObject toplevel_consts_26_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 641,
    .co_code = & toplevel_consts_26_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_26_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "USER_BASE: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_26_consts_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = " (",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_10 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ")",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_26_consts_11 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "USER_SITE: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_26_consts_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 18,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "ENABLE_USER_SITE: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_26_consts_14 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "--user-base",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_26_consts_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 11,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "--user-site",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_18 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 3 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_19 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 10 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_26_consts_1._ascii.ob_base,
            & toplevel_consts_8_consts_11.ob_base.ob_base,
            & toplevel_consts_26_consts_3._ascii.ob_base,
            & toplevel_consts_26_consts_4._ascii.ob_base,
            & toplevel_consts_26_consts_5._ascii.ob_base,
            & toplevel_consts_26_consts_6._ascii.ob_base,
            & toplevel_consts_26_consts_7.ob_base,
            & toplevel_consts_26_consts_8._ascii.ob_base,
            & toplevel_consts_26_consts_9._ascii.ob_base,
            & toplevel_consts_26_consts_10._ascii.ob_base,
            & toplevel_consts_26_consts_11._ascii.ob_base,
            & toplevel_consts_26_consts_12._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_26_consts_14._ascii.ob_base,
            & toplevel_consts_26_consts_15._ascii.ob_base,
            Py_False,
            & toplevel_consts_11_consts_11.ob_base.ob_base,
            & toplevel_consts_26_consts_18.ob_base.ob_base,
            & toplevel_consts_26_consts_19.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_names_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 4,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "argv",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_names_12 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "pathsep",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_names_14 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "textwrap",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_names_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "dedent",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_26_names_1._ascii.ob_base,
            & toplevel_consts_13_name._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_18_consts_5._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_14_names_1._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_26_names_12._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_26_names_14._ascii.ob_base,
            & toplevel_consts_26_names_15._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_varnames_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 9,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "user_base",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_varnames_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 6,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "buffer",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_26_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_26_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_26_varnames_6._ascii.ob_base,
            & toplevel_consts_26_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_script",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x0e\x0e\x04\x01\x06\x01\x06\x01\x08\x01\x0a\x01\x12\x01\x08\x01\x06\x01\x1a\x05\x1a\x01\x0e\x01\x0a\x01\x04\x02\x08\x01\x0c\x01\x08\x01\x0c\x01\x04\x02\x12\x01\x04\x01\x0e\x01\x08\x01\x0e\x01\x04\x01\x0e\x01\x0e\x02\x08\x02\x20\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0e\x02\xf3\x0e\x0e\x02\x01\x02\x0f\x06\xf2\x06\x01\x08\x01\x04\x01\x04\x01\x02\xff\x12\x01\x08\x01\x06\x05\x1a\x01\x1a\x01\x0e\x01\x0a\x01\x04\x02\x06\x01\x0e\x01\x06\x01\x0e\x01\x02\x02\x02\x0d\x12\xf4\x02\x01\x02\x07\x0e\xfa\x06\x01\x02\x05\x0e\xfc\x02\x01\x02\x03\x0e\xfe\x0e\x02\x08\x02\x20\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[355];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 354,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x08\x05\x09\x0c\x0f\x0c\x14\x15\x16\x15\x17\x15\x17\x0c\x18\x05\x09\x0c\x10\x05\x14\x15\x20\x15\x22\x09\x12\x15\x28\x15\x2a\x09\x12\x09\x0e\x0f\x1d\x09\x1e\x09\x1e\x14\x17\x14\x1c\x09\x26\x09\x26\x0d\x10\x0d\x12\x0d\x12\x20\x23\x20\x23\x20\x23\x13\x25\x0d\x26\x0d\x26\x0d\x26\x09\x0e\x0f\x12\x09\x13\x09\x13\x09\x27\x09\x27\x09\x27\x09\x0e\x0f\x40\x1d\x26\x0f\x40\x0f\x40\x2c\x32\x33\x3c\x2c\x3d\x0f\x40\x0f\x40\x0f\x40\x09\x41\x09\x41\x09\x0e\x0f\x40\x1d\x26\x0f\x40\x0f\x40\x2c\x32\x33\x3c\x2c\x3d\x0f\x40\x0f\x40\x0f\x40\x09\x41\x09\x41\x09\x0e\x0f\x38\x24\x34\x0f\x38\x0f\x38\x09\x39\x09\x39\x09\x0c\x09\x11\x12\x13\x09\x14\x09\x14\x0e\x10\x05\x0b\x08\x15\x19\x1d\x08\x1d\x05\x21\x09\x0f\x09\x21\x17\x20\x09\x21\x09\x21\x09\x21\x08\x15\x19\x1d\x08\x1d\x05\x21\x09\x0f\x09\x21\x17\x20\x09\x21\x09\x21\x09\x21\x08\x0e\x05\x15\x09\x0e\x0f\x11\x0f\x19\x0f\x26\x1f\x25\x0f\x26\x0f\x26\x09\x27\x09\x27\x0c\x1c\x09\x18\x0d\x10\x0d\x15\x16\x17\x0d\x18\x0d\x18\x0d\x18\x0d\x18\x0e\x1e\x22\x27\x0e\x27\x09\x18\x0d\x10\x0d\x15\x16\x17\x0d\x18\x0d\x18\x0d\x18\x0d\x18\x0e\x1e\x09\x18\x0d\x10\x0d\x15\x16\x17\x0d\x18\x0d\x18\x0d\x18\x0d\x18\x0d\x10\x0d\x15\x16\x17\x0d\x18\x0d\x18\x0d\x18\x0d\x18\x09\x18\x09\x18\x09\x18\x09\x18\x09\x0e\x0f\x17\x0f\x40\x1f\x23\x27\x2a\x27\x2f\x30\x31\x27\x32\x34\x36\x34\x3e\x26\x3f\x1f\x3f\x0f\x40\x0f\x40\x09\x41\x09\x41\x09\x0c\x09\x11\x12\x14\x09\x15\x09\x15\x09\x15\x09\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "        ",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 618,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_27 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "__main__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[29];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 29,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_3.ob_base,
            & toplevel_consts_4.ob_base,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_6.ob_base,
            & toplevel_consts_7.ob_base,
            & toplevel_consts_8.ob_base,
            & toplevel_consts_9.ob_base,
            & toplevel_consts_10.ob_base,
            & toplevel_consts_11.ob_base,
            & toplevel_consts_12.ob_base,
            & toplevel_consts_13.ob_base,
            & toplevel_consts_14.ob_base,
            & toplevel_consts_15.ob_base,
            & toplevel_consts_16.ob_base,
            & toplevel_consts_17.ob_base,
            & toplevel_consts_18.ob_base,
            & toplevel_consts_19.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_21.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_23.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_25.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_27._ascii.ob_base,
            & toplevel_consts_4_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_36 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 7,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "no_site",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[39];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 39,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_consts_2._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_18_names_2._ascii.ob_base,
            & toplevel_consts_8_names_5._ascii.ob_base,
            & toplevel_consts_16_varnames_3._ascii.ob_base,
            & toplevel_consts_22_names_17._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_14_names_1._ascii.ob_base,
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_5_name._ascii.ob_base,
            & toplevel_consts_6_name._ascii.ob_base,
            & toplevel_consts_7_name._ascii.ob_base,
            & toplevel_consts_8_name._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
            & toplevel_consts_10_name._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_13_name._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_17_name._ascii.ob_base,
            & toplevel_consts_18_name._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_22_name._ascii.ob_base,
            & toplevel_consts_23_name._ascii.ob_base,
            & toplevel_consts_24_name._ascii.ob_base,
            & toplevel_consts_25_name._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_names_36._ascii.ob_base,
            & toplevel_consts_26_name._ascii.ob_base,
            & toplevel_consts_23_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_name = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 8,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "<module>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x47\x08\x01\x08\x01\x08\x01\x08\x01\x0c\x03\x04\x03\x04\x05\x04\x01\x06\x03\x06\x05\x06\x09\x06\x17\x06\x13\x06\x0d\x08\x2f\x06\x19\x06\x20\x06\x18\x06\x0d\x06\x0d\x06\x11\x08\x0f\x08\x21\x06\x09\x06\x10\x06\x1a\x06\x03\x06\x3b\x06\x34\x06\x14\x06\x14\x08\x1f\x06\x01\x06\x02\x08\x36\x0a\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x45\x08\x02\x08\x01\x08\x01\x08\x01\x08\x01\x0c\x03\x04\x03\x04\x05\x04\x01\x06\x05\x06\x09\x06\x17\x06\x13\x06\x0d\x06\x2f\x02\x03\x06\x16\x06\x19\x06\x1e\x06\x0e\x06\x0d\x06\x12\x06\x0f\x02\x02\x06\x1f\x02\x02\x06\x07\x06\x0f\x06\x1a\x06\x04\x06\x3b\x06\x33\x06\x14\x06\x14\x06\x1e\x06\x04\x08\x01\x06\x36\x06\x02\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[257];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 256,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x10\x01\x10\x01\x10\x01\x10\x01\x15\x01\x15\x01\x15\x01\x15\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x0d\x10\x0d\x17\x19\x1c\x19\x28\x0c\x29\x01\x09\x14\x18\x01\x11\x0d\x11\x01\x0a\x0d\x11\x01\x0a\x01\x28\x01\x28\x01\x28\x01\x26\x01\x26\x01\x26\x01\x11\x01\x11\x01\x11\x01\x17\x01\x17\x01\x17\x01\x0d\x01\x0d\x01\x0d\x01\x17\x01\x17\x01\x17\x25\x29\x01\x17\x01\x17\x01\x17\x01\x10\x01\x10\x01\x10\x01\x23\x01\x23\x01\x23\x01\x4b\x01\x4b\x01\x4b\x01\x15\x01\x15\x01\x15\x01\x15\x01\x15\x01\x15\x01\x17\x01\x17\x01\x17\x1e\x22\x01\x18\x01\x18\x01\x18\x2b\x2f\x01\x17\x01\x17\x01\x17\x01\x37\x01\x37\x01\x37\x01\x15\x01\x15\x01\x15\x01\x2c\x01\x2c\x01\x2c\x01\x30\x01\x30\x01\x30\x01\x17\x01\x17\x01\x17\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x1c\x01\x1c\x01\x1c\x08\x0b\x08\x11\x08\x19\x01\x0b\x05\x09\x05\x0b\x05\x0b\x01\x15\x01\x15\x01\x15\x04\x0c\x10\x1a\x04\x1a\x01\x0e\x05\x0c\x05\x0e\x05\x0e\x05\x0e\x05\x0e\x01\x0e\x01\x0e",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_filename._ascii.ob_base,
    .co_name = & toplevel_name._ascii.ob_base,
    .co_qualname = & toplevel_name._ascii.ob_base,
    .co_linetable = & toplevel_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_site_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

