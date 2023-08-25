#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1595];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1594,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x64\x01\x64\x02\x6c\x02\x5a\x02\x64\x01\x64\x02\x6c\x03\x5a\x04\x64\x01\x64\x03\x6c\x05\x6d\x06\x5a\x06\x01\x00\x65\x07\x65\x08\x65\x09\x19\x00\xa9\x01\x5a\x0a\x65\x02\x6a\x0b\x5a\x0c\x67\x00\x64\x04\xa2\x01\x5a\x0d\x64\x05\x84\x00\x5a\x0e\x64\x06\x84\x00\x5a\x0f\x64\x07\x65\x0c\x76\x00\x72\x70\x64\x07\x5a\x10\x64\x08\x5a\x11\x64\x01\x64\x09\x6c\x12\x54\x00\x09\x00\x64\x01\x64\x0a\x6c\x12\x6d\x13\x5a\x13\x01\x00\x65\x0d\xa0\x14\x64\x0b\xa8\x01\xa9\x01\x01\x00\x6e\x0a\x23\x00\x65\x15\x79\x48\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x64\x02\x6c\x16\x5a\x17\x09\x00\x64\x01\x64\x0c\x6c\x12\x6d\x18\x5a\x18\x01\x00\x6e\x0a\x23\x00\x65\x15\x79\x5e\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x64\x02\x6c\x12\x5a\x12\x65\x0d\xa0\x19\x65\x0f\x65\x12\xa9\x01\xa8\x01\xa9\x01\x01\x00\x5b\x12\x6e\x4b\x64\x0d\x65\x0c\x76\x00\x72\xb7\x64\x0d\x5a\x10\x64\x0e\x5a\x11\x64\x01\x64\x09\x6c\x1a\x54\x00\x09\x00\x64\x01\x64\x0a\x6c\x1a\x6d\x13\x5a\x13\x01\x00\x65\x0d\xa0\x14\x64\x0b\xa8\x01\xa9\x01\x01\x00\x6e\x0a\x23\x00\x65\x15\x79\x90\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x64\x02\x6c\x1b\x5a\x17\x64\x01\x64\x02\x6c\x1a\x5a\x1a\x65\x0d\xa0\x19\x65\x0f\x65\x1a\xa9\x01\xa8\x01\xa9\x01\x01\x00\x5b\x1a\x09\x00\x64\x01\x64\x0c\x6c\x1a\x6d\x18\x5a\x18\x01\x00\x6e\x0e\x23\x00\x65\x15\x79\xb3\x01\x00\x59\x00\x6e\x08\x77\x00\x78\x03\x59\x00\x77\x01\x65\x15\x64\x0f\xa9\x01\x82\x01\x65\x17\x65\x02\x6a\x1c\x64\x10\x3c\x00\x64\x01\x64\x11\x6c\x1d\x6d\x1e\x5a\x1e\x6d\x1f\x5a\x1f\x6d\x20\x5a\x20\x6d\x21\x5a\x21\x6d\x22\x5a\x22\x6d\x23\x5a\x23\x6d\x24\x5a\x24\x6d\x25\x5a\x25\x01\x00\x5b\x0c\x65\x0e\x64\x12\xa9\x01\x90\x01\x72\xd5\x65\x26\xa9\x00\x5a\x27\x64\x13\x84\x00\x5a\x28\x65\x29\xa9\x00\x5a\x2a\x65\x28\x64\x14\x64\x15\xa9\x02\x01\x00\x65\x28\x64\x16\x64\x17\xa9\x02\x01\x00\x65\x28\x64\x18\x64\x19\xa9\x02\x01\x00\x65\x28\x64\x1a\x64\x1b\xa9\x02\x01\x00\x65\x28\x64\x1c\x64\x1d\xa9\x02\x01\x00\x65\x28\x64\x1e\x64\x1f\xa9\x02\x01\x00\x65\x28\x64\x20\x64\x21\xa9\x02\x01\x00\x65\x28\x64\x22\x64\x23\xa9\x02\x01\x00\x65\x28\x64\x24\x64\x25\xa9\x02\x01\x00\x65\x28\x64\x26\x64\x27\xa9\x02\x01\x00\x65\x28\x64\x28\x64\x29\xa9\x02\x01\x00\x65\x28\x64\x2a\x64\x2b\xa9\x02\x01\x00\x65\x28\x64\x2c\x64\x2d\xa9\x02\x01\x00\x65\x28\x64\x2e\x64\x2f\xa9\x02\x01\x00\x65\x28\x64\x2e\x64\x30\xa9\x02\x01\x00\x65\x28\x64\x31\x64\x1d\xa9\x02\x01\x00\x65\x2a\x5a\x2b\x65\x29\xa9\x00\x5a\x2a\x65\x28\x64\x14\x64\x15\xa9\x02\x01\x00\x65\x2a\x5a\x2c\x65\x29\xa9\x00\x5a\x2a\x65\x28\x64\x32\x64\x33\xa9\x02\x01\x00\x65\x28\x64\x34\x64\x17\xa9\x02\x01\x00\x65\x28\x64\x35\x64\x19\xa9\x02\x01\x00\x65\x28\x64\x36\x64\x37\xa9\x02\x01\x00\x65\x28\x64\x36\x64\x38\xa9\x02\x01\x00\x65\x28\x64\x39\x64\x3a\xa9\x02\x01\x00\x65\x2a\xa0\x2d\x65\x03\xa8\x01\xa9\x01\x01\x00\x65\x28\x64\x3b\x64\x3c\xa9\x02\x01\x00\x65\x28\x64\x3d\x64\x1d\xa9\x02\x01\x00\x65\x28\x64\x3e\x64\x1d\xa9\x02\x01\x00\x65\x28\x64\x3f\x64\x40\xa9\x02\x01\x00\x65\x0e\x64\x41\xa9\x01\x90\x01\x72\x89\x65\x0e\x64\x42\xa9\x01\x90\x01\x72\x89\x65\x28\x64\x43\x64\x41\xa9\x02\x01\x00\x65\x2a\x5a\x2e\x65\x29\xa9\x00\x5a\x2a\x65\x28\x64\x14\x64\x15\xa9\x02\x01\x00\x65\x28\x64\x18\x64\x19\xa9\x02\x01\x00\x65\x28\x64\x1a\x64\x1b\xa9\x02\x01\x00\x65\x28\x64\x44\x64\x45\xa9\x02\x01\x00\x65\x28\x64\x46\x64\x17\xa9\x02\x01\x00\x65\x0e\x64\x47\xa9\x01\x90\x01\x72\xb1\x65\x28\x64\x48\x64\x19\xa9\x02\x01\x00\x65\x28\x64\x1e\x64\x1f\xa9\x02\x01\x00\x65\x28\x64\x49\x64\x1d\xa9\x02\x01\x00\x65\x28\x64\x4a\x64\x1b\xa9\x02\x01\x00\x65\x28\x64\x1a\x64\x1b\xa9\x02\x01\x00\x65\x28\x64\x31\x64\x1d\xa9\x02\x01\x00\x65\x28\x64\x4b\x64\x1b\xa9\x02\x01\x00\x65\x2a\x5a\x2f\x5b\x2a\x5b\x18\x5b\x27\x5b\x28\x64\x01\x5a\x30\x64\x4c\x5a\x31\x64\x4d\x5a\x32\x64\x92\x64\x50\x84\x01\x5a\x33\x64\x51\x84\x00\x5a\x34\x64\x52\x84\x00\x5a\x35\x65\x0d\xa0\x19\x67\x00\x64\x53\xa2\x01\xa8\x01\xa9\x01\x01\x00\x64\x93\x64\x55\x84\x01\x5a\x36\x64\x56\x84\x00\x5a\x37\x65\x0d\xa0\x14\x64\x57\xa8\x01\xa9\x01\x01\x00\x65\x38\x65\x03\x68\x02\x65\x2b\x6b\x01\x90\x02\x72\x19\x65\x39\x65\x03\x68\x02\x65\x2e\x6b\x01\x90\x02\x72\x19\x64\x94\x64\x4f\x64\x02\x64\x59\x9c\x02\x64\x5a\x84\x03\x5a\x3a\x64\x5b\x84\x00\x5a\x3b\x65\x0d\xa0\x14\x64\x5c\xa8\x01\xa9\x01\x01\x00\x64\x5d\x84\x00\x5a\x3c\x64\x5e\x84\x00\x5a\x3d\x64\x5f\x84\x00\x5a\x3e\x64\x60\x84\x00\x5a\x3f\x64\x61\x84\x00\x5a\x40\x64\x62\x84\x00\x5a\x41\x65\x0d\xa0\x19\x67\x00\x64\x63\xa2\x01\xa8\x01\xa9\x01\x01\x00\x64\x95\x64\x64\x84\x01\x5a\x42\x64\x95\x64\x65\x84\x01\x5a\x43\x64\x01\x64\x66\x6c\x05\x6d\x44\x5a\x44\x6d\x45\x5a\x45\x01\x00\x47\x00\x64\x67\x84\x00\x64\x68\x65\x44\xa9\x03\x5a\x46\x64\x69\x84\x00\x5a\x47\x65\x47\xa9\x00\x5a\x48\x5b\x47\x64\x95\x64\x6a\x84\x01\x5a\x49\x65\x10\x64\x0d\x6b\x03\x5a\x4a\x65\x0d\xa0\x19\x64\x6b\xa8\x01\xa9\x01\x01\x00\x65\x4a\x90\x02\x72\x79\x64\x6c\x84\x00\x5a\x4b\x65\x46\x65\x48\x6a\x4c\x65\x4b\x65\x4d\x65\x4b\x65\x4d\xa9\x05\x5a\x4e\x5b\x4b\x64\x95\x64\x6d\x84\x01\x5a\x4f\x65\x0d\xa0\x19\x64\x6e\xa8\x01\xa9\x01\x01\x00\x64\x6f\x84\x00\x5a\x50\x65\x50\xa9\x00\x5c\x02\x5a\x51\x5a\x52\x5b\x50\x65\x0e\x64\x70\xa9\x01\x90\x02\x72\xb6\x65\x0e\x64\x71\xa9\x01\x90\x02\x73\xb6\x65\x0e\x64\x72\xa9\x01\x90\x02\x72\xb6\x64\x01\x5a\x53\x64\x4c\x04\x00\x5a\x54\x5a\x55\x65\x0d\xa0\x19\x67\x00\x64\x73\xa2\x01\xa8\x01\xa9\x01\x01\x00\x64\x74\x84\x00\x5a\x56\x64\x75\x84\x00\x5a\x57\x64\x76\x84\x00\x5a\x58\x64\x77\x84\x00\x5a\x59\x64\x78\x84\x00\x5a\x5a\x65\x0d\xa0\x19\x67\x00\x64\x79\xa2\x01\xa8\x01\xa9\x01\x01\x00\x65\x0e\x64\x71\xa9\x01\x90\x02\x72\xc9\x64\x7a\x84\x00\x5a\x5b\x64\x7b\x84\x00\x5a\x5c\x65\x0d\xa0\x19\x64\x7c\x64\x7d\x67\x02\xa8\x01\xa9\x01\x01\x00\x65\x0e\x64\x7e\xa9\x01\x90\x02\x72\xdc\x64\x7f\x84\x00\x5a\x5d\x64\x80\x84\x00\x5a\x5e\x65\x0d\xa0\x19\x64\x81\x64\x82\x67\x02\xa8\x01\xa9\x01\x01\x00\x65\x02\x6a\x5f\x64\x83\x6b\x03\x90\x02\x72\xf2\x64\x96\x64\x86\x84\x01\x5a\x60\x47\x00\x64\x87\x84\x00\x64\x88\xa9\x02\x5a\x61\x65\x0d\xa0\x14\x64\x89\xa8\x01\xa9\x01\x01\x00\x64\x97\x64\x8a\x84\x01\x5a\x62\x64\x8b\x84\x00\x5a\x63\x65\x0e\x64\x8c\xa9\x01\x90\x03\x73\x03\x65\x63\x5a\x64\x64\x8c\x65\x64\x5f\x65\x47\x00\x64\x8d\x84\x00\x64\x8e\x65\x01\x6a\x66\xa9\x03\x5a\x67\x65\x10\x64\x0d\x6b\x02\x90\x03\x72\x1b\x47\x00\x64\x8f\x84\x00\x64\x90\xa9\x02\x5a\x68\x64\x91\x84\x00\x5a\x69\x64\x02\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1103];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1102,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4f\x53\x20\x72\x6f\x75\x74\x69\x6e\x65\x73\x20\x66\x6f\x72\x20\x4e\x54\x20\x6f\x72\x20\x50\x6f\x73\x69\x78\x20\x64\x65\x70\x65\x6e\x64\x69\x6e\x67\x20\x6f\x6e\x20\x77\x68\x61\x74\x20\x73\x79\x73\x74\x65\x6d\x20\x77\x65\x27\x72\x65\x20\x6f\x6e\x2e\x0a\x0a\x54\x68\x69\x73\x20\x65\x78\x70\x6f\x72\x74\x73\x3a\x0a\x20\x20\x2d\x20\x61\x6c\x6c\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x66\x72\x6f\x6d\x20\x70\x6f\x73\x69\x78\x20\x6f\x72\x20\x6e\x74\x2c\x20\x65\x2e\x67\x2e\x20\x75\x6e\x6c\x69\x6e\x6b\x2c\x20\x73\x74\x61\x74\x2c\x20\x65\x74\x63\x2e\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x70\x61\x74\x68\x20\x69\x73\x20\x65\x69\x74\x68\x65\x72\x20\x70\x6f\x73\x69\x78\x70\x61\x74\x68\x20\x6f\x72\x20\x6e\x74\x70\x61\x74\x68\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x6e\x61\x6d\x65\x20\x69\x73\x20\x65\x69\x74\x68\x65\x72\x20\x27\x70\x6f\x73\x69\x78\x27\x20\x6f\x72\x20\x27\x6e\x74\x27\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x63\x75\x72\x64\x69\x72\x20\x69\x73\x20\x61\x20\x73\x74\x72\x69\x6e\x67\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x28\x61\x6c\x77\x61\x79\x73\x20\x27\x2e\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x70\x61\x72\x64\x69\x72\x20\x69\x73\x20\x61\x20\x73\x74\x72\x69\x6e\x67\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x69\x6e\x67\x20\x74\x68\x65\x20\x70\x61\x72\x65\x6e\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x28\x61\x6c\x77\x61\x79\x73\x20\x27\x2e\x2e\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x73\x65\x70\x20\x69\x73\x20\x74\x68\x65\x20\x28\x6f\x72\x20\x61\x20\x6d\x6f\x73\x74\x20\x63\x6f\x6d\x6d\x6f\x6e\x29\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x28\x27\x2f\x27\x20\x6f\x72\x20\x27\x5c\x5c\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x65\x78\x74\x73\x65\x70\x20\x69\x73\x20\x74\x68\x65\x20\x65\x78\x74\x65\x6e\x73\x69\x6f\x6e\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x28\x61\x6c\x77\x61\x79\x73\x20\x27\x2e\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x61\x6c\x74\x73\x65\x70\x20\x69\x73\x20\x74\x68\x65\x20\x61\x6c\x74\x65\x72\x6e\x61\x74\x65\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x28\x4e\x6f\x6e\x65\x20\x6f\x72\x20\x27\x2f\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x70\x61\x74\x68\x73\x65\x70\x20\x69\x73\x20\x74\x68\x65\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x75\x73\x65\x64\x20\x69\x6e\x20\x24\x50\x41\x54\x48\x20\x65\x74\x63\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x6c\x69\x6e\x65\x73\x65\x70\x20\x69\x73\x20\x74\x68\x65\x20\x6c\x69\x6e\x65\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x69\x6e\x20\x74\x65\x78\x74\x20\x66\x69\x6c\x65\x73\x20\x28\x27\x5c\x72\x27\x20\x6f\x72\x20\x27\x5c\x6e\x27\x20\x6f\x72\x20\x27\x5c\x72\x5c\x6e\x27\x29\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x64\x65\x66\x70\x61\x74\x68\x20\x69\x73\x20\x74\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x20\x66\x6f\x72\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x73\x0a\x20\x20\x2d\x20\x6f\x73\x2e\x64\x65\x76\x6e\x75\x6c\x6c\x20\x69\x73\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x20\x70\x61\x74\x68\x20\x6f\x66\x20\x74\x68\x65\x20\x6e\x75\x6c\x6c\x20\x64\x65\x76\x69\x63\x65\x20\x28\x27\x2f\x64\x65\x76\x2f\x6e\x75\x6c\x6c\x27\x2c\x20\x65\x74\x63\x2e\x29\x0a\x0a\x50\x72\x6f\x67\x72\x61\x6d\x73\x20\x74\x68\x61\x74\x20\x69\x6d\x70\x6f\x72\x74\x20\x61\x6e\x64\x20\x75\x73\x65\x20\x27\x6f\x73\x27\x20\x73\x74\x61\x6e\x64\x20\x61\x20\x62\x65\x74\x74\x65\x72\x20\x63\x68\x61\x6e\x63\x65\x20\x6f\x66\x20\x62\x65\x69\x6e\x67\x0a\x70\x6f\x72\x74\x61\x62\x6c\x65\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x70\x6c\x61\x74\x66\x6f\x72\x6d\x73\x2e\x20\x20\x4f\x66\x20\x63\x6f\x75\x72\x73\x65\x2c\x20\x74\x68\x65\x79\x20\x6d\x75\x73\x74\x20\x74\x68\x65\x6e\x0a\x6f\x6e\x6c\x79\x20\x75\x73\x65\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x74\x68\x61\x74\x20\x61\x72\x65\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x62\x79\x20\x61\x6c\x6c\x20\x70\x6c\x61\x74\x66\x6f\x72\x6d\x73\x20\x28\x65\x2e\x67\x2e\x2c\x20\x75\x6e\x6c\x69\x6e\x6b\x0a\x61\x6e\x64\x20\x6f\x70\x65\x6e\x64\x69\x72\x29\x2c\x20\x61\x6e\x64\x20\x6c\x65\x61\x76\x65\x20\x61\x6c\x6c\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x6d\x61\x6e\x69\x70\x75\x6c\x61\x74\x69\x6f\x6e\x20\x74\x6f\x20\x6f\x73\x2e\x70\x61\x74\x68\x0a\x28\x65\x2e\x67\x2e\x2c\x20\x73\x70\x6c\x69\x74\x20\x61\x6e\x64\x20\x6a\x6f\x69\x6e\x29\x2e\x0a",
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
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_3_0 = {
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
    ._data = "_check_methods",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_3_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_4_0 = {
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
    ._data = "altsep",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_4_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_4_2 = {
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
        uint8_t _data[4];
    }
toplevel_consts_4_3 = {
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
        uint8_t _data[8];
    }
toplevel_consts_4_4 = {
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
        uint8_t _data[8];
    }
toplevel_consts_4_5 = {
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
    ._data = "linesep",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_4_6 = {
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
    ._data = "defpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_4_7 = {
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
        uint8_t _data[5];
    }
toplevel_consts_4_8 = {
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
        uint8_t _data[8];
    }
toplevel_consts_4_9 = {
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
    ._data = "devnull",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_10 = {
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
    ._data = "SEEK_SET",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_11 = {
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
    ._data = "SEEK_CUR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_12 = {
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
    ._data = "SEEK_END",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_13 = {
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
    ._data = "fsencode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4_14 = {
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
    ._data = "fsdecode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_4_15 = {
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
    ._data = "get_exec_path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_4_16 = {
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
    ._data = "fdopen",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_4_17 = {
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
    ._data = "extsep",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_4_0._ascii.ob_base,
            & toplevel_consts_4_1._ascii.ob_base,
            & toplevel_consts_4_2._ascii.ob_base,
            & toplevel_consts_4_3._ascii.ob_base,
            & toplevel_consts_4_4._ascii.ob_base,
            & toplevel_consts_4_5._ascii.ob_base,
            & toplevel_consts_4_6._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_4_9._ascii.ob_base,
            & toplevel_consts_4_10._ascii.ob_base,
            & toplevel_consts_4_11._ascii.ob_base,
            & toplevel_consts_4_12._ascii.ob_base,
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_4_14._ascii.ob_base,
            & toplevel_consts_4_15._ascii.ob_base,
            & toplevel_consts_4_16._ascii.ob_base,
            & toplevel_consts_4_17._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\xa9\x00\x76\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_5_consts = {
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
        uint8_t _data[8];
    }
toplevel_consts_5_names_0 = {
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
    ._data = "globals",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
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
toplevel_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_4_7._ascii.ob_base,
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
toplevel_consts_5_freevars = {
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
        uint8_t _data[12];
    }
toplevel_consts_5_filename = {
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
    ._data = "<frozen os>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_name = {
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
    ._data = "_exists",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x14\x1b\x14\x1d\x0c\x1d\x05\x1d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_5_exceptiontable = {
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
toplevel_consts_5_localspluskinds = {
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
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 41,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x53\x00\x23\x00\x74\x02\x79\x15\x01\x00\x64\x01\x84\x00\x74\x03\x7c\x00\xa9\x01\x44\x00\xa9\x01\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_6_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7c\x00\x5d\x0a\x7d\x01\x7c\x01\x64\x00\x19\x00\x64\x01\x6b\x03\x72\x03\x7c\x01\x91\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_6_consts_1_consts_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_6_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_6_consts_1_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_6_consts_1_varnames_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_6_consts_1_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_6_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_6_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_6_consts_1_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_consts_1_name = {
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
        uint8_t _data[38];
    }
toplevel_consts_6_consts_1_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 37,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_get_exports_list.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_6_consts_1_linetable = {
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
toplevel_consts_6_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x37\x10\x37\x10\x37\x17\x18\x2b\x2c\x2d\x2e\x2b\x2f\x33\x36\x2b\x36\x10\x37\x11\x12\x10\x37\x10\x37\x10\x37",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_6_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_6_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_6_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_6_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 48,
    .co_code = & toplevel_consts_6_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_6_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_6_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
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
            Py_None,
            & toplevel_consts_6_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_6_names_0 = {
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
    ._data = "list",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_6_names_1 = {
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
    ._data = "__all__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_6_names_2 = {
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
        uint8_t _data[4];
    }
toplevel_consts_6_names_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_6_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_6_varnames_0 = {
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
    ._data = "module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_6_name = {
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
    ._data = "_get_exports_list",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x0a\x01\x02\x80\x06\x01\x14\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x0a\xfe\x02\x80\x02\x01\x1a\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x37\x10\x14\x15\x1b\x15\x23\x10\x24\x09\x24\x00\x00\x0c\x1a\x05\x37\x05\x37\x10\x37\x10\x37\x1c\x1f\x20\x26\x1c\x27\x10\x37\x10\x37\x09\x37\x09\x37\x09\x37\x05\x37\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x04\x07\x00\x87\x0c\x16\x03\x95\x01\x16\x03",
};
static struct PyCodeObject toplevel_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 44,
    .co_code = & toplevel_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_7 = {
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
    ._data = "posix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_8 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_9_0 = {
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
    ._data = "*",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_9 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_10_0 = {
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
    ._data = "_exit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_10 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_10_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_12_0 = {
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
    ._data = "_have_functions",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_13 = {
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
        uint8_t _data[3];
    }
toplevel_consts_14 = {
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
    ._data = "\x0d\x0a",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_15 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 27,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "no os specific module found",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_16 = {
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
    ._data = "os.path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_17 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_4_1._ascii.ob_base,
            & toplevel_consts_4_2._ascii.ob_base,
            & toplevel_consts_4_3._ascii.ob_base,
            & toplevel_consts_4_4._ascii.ob_base,
            & toplevel_consts_4_6._ascii.ob_base,
            & toplevel_consts_4_17._ascii.ob_base,
            & toplevel_consts_4_0._ascii.ob_base,
            & toplevel_consts_4_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x74\x00\x76\x00\x72\x13\x7c\x00\x74\x01\x76\x00\x72\x15\x74\x02\xa0\x03\x74\x00\x7c\x01\x19\x00\xa8\x01\xa9\x01\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_names_0 = {
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
    ._data = "_globals",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_19_names_2 = {
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
    ._data = "_set",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_19_names_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_19_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_19_names_0._ascii.ob_base,
            & toplevel_consts_12_0._ascii.ob_base,
            & toplevel_consts_19_names_2._ascii.ob_base,
            & toplevel_consts_19_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_19_varnames_0 = {
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
    ._data = "str",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_19_varnames_1 = {
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
    ._data = "fn",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_19_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_19_name = {
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
    ._data = "_add",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x14\x01\x08\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x01\x06\xff\x1e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x0f\x13\x1b\x0d\x1b\x09\x23\x22\x25\x29\x38\x22\x38\x09\x23\x0d\x11\x0d\x23\x16\x1e\x1f\x21\x16\x22\x0d\x23\x0d\x23\x0d\x23\x0d\x23\x0d\x23\x09\x23\x09\x23\x09\x23\x09\x23",
};
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 104,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_20 = {
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
    ._data = "HAVE_FACCESSAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_21 = {
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
    ._data = "access",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_22 = {
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
    ._data = "HAVE_FCHMODAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23 = {
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
    ._data = "chmod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_24 = {
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
    ._data = "HAVE_FCHOWNAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_25 = {
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
    ._data = "chown",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26 = {
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
    ._data = "HAVE_FSTATAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_27 = {
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
    ._data = "stat",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_28 = {
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
    ._data = "HAVE_FUTIMESAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_29 = {
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
    ._data = "utime",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_30 = {
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
    ._data = "HAVE_LINKAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_31 = {
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
    ._data = "link",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_32 = {
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
    ._data = "HAVE_MKDIRAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_33 = {
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
    ._data = "mkdir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_34 = {
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
    ._data = "HAVE_MKFIFOAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_35 = {
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
    ._data = "mkfifo",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_36 = {
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
    ._data = "HAVE_MKNODAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_37 = {
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
    ._data = "mknod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_38 = {
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
    ._data = "HAVE_OPENAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39 = {
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
        uint8_t _data[16];
    }
toplevel_consts_40 = {
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
    ._data = "HAVE_READLINKAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_41 = {
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
    ._data = "readlink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_42 = {
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
    ._data = "HAVE_RENAMEAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_43 = {
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
    ._data = "rename",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_44 = {
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
    ._data = "HAVE_SYMLINKAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_45 = {
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
    ._data = "symlink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_46 = {
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
    ._data = "HAVE_UNLINKAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_47 = {
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
    ._data = "unlink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_48 = {
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
    ._data = "rmdir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_49 = {
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
    ._data = "HAVE_UTIMENSAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_50 = {
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
    ._data = "HAVE_FCHDIR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_51 = {
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
    ._data = "chdir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_52 = {
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
    ._data = "HAVE_FCHMOD",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_53 = {
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
    ._data = "HAVE_FCHOWN",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_54 = {
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
    ._data = "HAVE_FDOPENDIR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_55 = {
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
        uint8_t _data[8];
    }
toplevel_consts_56 = {
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
    ._data = "scandir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_57 = {
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
    ._data = "HAVE_FEXECVE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_58 = {
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
    ._data = "execve",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_59 = {
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
    ._data = "HAVE_FTRUNCATE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_60 = {
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
    ._data = "truncate",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_61 = {
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
    ._data = "HAVE_FUTIMENS",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_62 = {
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
    ._data = "HAVE_FUTIMES",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_63 = {
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
    ._data = "HAVE_FPATHCONF",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_64 = {
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
    ._data = "pathconf",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_65 = {
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
    ._data = "statvfs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_66 = {
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
    ._data = "fstatvfs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_67 = {
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
    ._data = "HAVE_FSTATVFS",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_68 = {
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
    ._data = "HAVE_LCHFLAGS",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_69 = {
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
    ._data = "chflags",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_70 = {
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
    ._data = "HAVE_LCHMOD",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_71 = {
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
    ._data = "lchown",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_72 = {
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
    ._data = "HAVE_LCHOWN",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_73 = {
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
    ._data = "HAVE_LUTIMES",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_74 = {
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
    ._data = "HAVE_LSTAT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_75 = {
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
    ._data = "MS_WINDOWS",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_76 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_77 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_78 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 511 },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[179];
    }
toplevel_consts_80_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 178,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x5c\x02\x7d\x03\x7d\x04\x7c\x04\x73\x11\x74\x00\x6a\x01\x7c\x03\xa9\x01\x5c\x02\x7d\x03\x7d\x04\x7c\x03\x72\x3e\x7c\x04\x72\x3e\x74\x00\x6a\x02\x7c\x03\xa9\x01\x73\x3e\x09\x00\x74\x03\x7c\x03\x7c\x02\x64\x01\xaa\x02\x01\x00\x6e\x0a\x23\x00\x74\x04\x79\x28\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x05\x7d\x05\x74\x06\x7c\x04\x74\x07\xa9\x02\x72\x38\x74\x07\x74\x05\x64\x02\xa9\x02\x7d\x05\x7c\x04\x7c\x05\x6b\x02\x72\x3e\x64\x03\x53\x00\x09\x00\x74\x08\x7c\x00\x7c\x01\xa9\x02\x01\x00\x64\x03\x53\x00\x23\x00\x74\x09\x79\x55\x01\x00\x7c\x02\x72\x51\x74\x00\x6a\x0a\x7c\x00\xa9\x01\x73\x52\x82\x00\x59\x00\x64\x03\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[396];
    }
toplevel_consts_80_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 395,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x6d\x61\x6b\x65\x64\x69\x72\x73\x28\x6e\x61\x6d\x65\x20\x5b\x2c\x20\x6d\x6f\x64\x65\x3d\x30\x6f\x37\x37\x37\x5d\x5b\x2c\x20\x65\x78\x69\x73\x74\x5f\x6f\x6b\x3d\x46\x61\x6c\x73\x65\x5d\x29\x0a\x0a\x20\x20\x20\x20\x53\x75\x70\x65\x72\x2d\x6d\x6b\x64\x69\x72\x3b\x20\x63\x72\x65\x61\x74\x65\x20\x61\x20\x6c\x65\x61\x66\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x6e\x64\x20\x61\x6c\x6c\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x20\x6f\x6e\x65\x73\x2e\x20\x20\x57\x6f\x72\x6b\x73\x20\x6c\x69\x6b\x65\x0a\x20\x20\x20\x20\x6d\x6b\x64\x69\x72\x2c\x20\x65\x78\x63\x65\x70\x74\x20\x74\x68\x61\x74\x20\x61\x6e\x79\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x20\x70\x61\x74\x68\x20\x73\x65\x67\x6d\x65\x6e\x74\x20\x28\x6e\x6f\x74\x20\x6a\x75\x73\x74\x20\x74\x68\x65\x20\x72\x69\x67\x68\x74\x6d\x6f\x73\x74\x29\x0a\x20\x20\x20\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x63\x72\x65\x61\x74\x65\x64\x20\x69\x66\x20\x69\x74\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x65\x78\x69\x73\x74\x2e\x20\x49\x66\x20\x74\x68\x65\x20\x74\x61\x72\x67\x65\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x6c\x72\x65\x61\x64\x79\x0a\x20\x20\x20\x20\x65\x78\x69\x73\x74\x73\x2c\x20\x72\x61\x69\x73\x65\x20\x61\x6e\x20\x4f\x53\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x65\x78\x69\x73\x74\x5f\x6f\x6b\x20\x69\x73\x20\x46\x61\x6c\x73\x65\x2e\x20\x4f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x6e\x6f\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x73\x0a\x20\x20\x20\x20\x72\x61\x69\x73\x65\x64\x2e\x20\x20\x54\x68\x69\x73\x20\x69\x73\x20\x72\x65\x63\x75\x72\x73\x69\x76\x65\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_80_consts_1_0 = {
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
    ._data = "exist_ok",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_80_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_80_consts_1_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_80_consts_2 = {
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
    ._data = "ASCII",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_80_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_80_consts_0._ascii.ob_base,
            & toplevel_consts_80_consts_1._object.ob_base.ob_base,
            & toplevel_consts_80_consts_2._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_80_names_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_80_names_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_80_names_3 = {
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
    ._data = "makedirs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_80_names_4 = {
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
    ._data = "FileExistsError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_80_names_6 = {
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
    ._data = "isinstance",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_80_names_7 = {
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
    ._data = "bytes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_80_names_9 = {
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
        uint8_t _data[6];
    }
toplevel_consts_80_names_10 = {
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
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_80_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_80_names_1._ascii.ob_base,
            & toplevel_consts_80_names_2._ascii.ob_base,
            & toplevel_consts_80_names_3._ascii.ob_base,
            & toplevel_consts_80_names_4._ascii.ob_base,
            & toplevel_consts_4_1._ascii.ob_base,
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_33._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
            & toplevel_consts_80_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_80_varnames_1 = {
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
    ._data = "mode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_80_varnames_3 = {
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
    ._data = "head",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_80_varnames_4 = {
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
    ._data = "tail",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_80_varnames_5 = {
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
    ._data = "cdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_80_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_80_consts_1_0._ascii.ob_base,
            & toplevel_consts_80_varnames_3._ascii.ob_base,
            & toplevel_consts_80_varnames_4._ascii.ob_base,
            & toplevel_consts_80_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_80_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x0a\x04\x01\x0e\x01\x12\x01\x02\x01\x0e\x01\x02\x80\x06\x01\x04\x02\x02\xfe\x06\x80\x04\x03\x0a\x01\x0a\x01\x08\x01\x04\x01\x02\x01\x0e\x01\x02\x80\x06\x01\x0e\x03\x02\x01\x06\xff\x02\xfd\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_80_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x0a\x02\x01\x10\x01\x02\x01\x02\x0a\x02\xf6\x02\x0a\x08\xf6\x02\x0a\x02\xfb\x0e\xfd\x02\x80\x02\x01\x0a\x02\x06\x80\x04\x01\x08\x01\x0c\x01\x06\x01\x06\x01\x02\x07\x0e\xfb\x02\x80\x02\x01\x04\x04\x02\xff\x02\x01\x08\xff\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[179];
    }
toplevel_consts_80_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 178,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x16\x12\x1c\x1d\x21\x12\x22\x05\x0f\x05\x09\x0b\x0f\x0c\x10\x05\x26\x16\x1a\x16\x20\x21\x25\x16\x26\x09\x13\x09\x0d\x0f\x13\x08\x0c\x05\x13\x11\x15\x05\x13\x1e\x22\x1e\x29\x2a\x2e\x1e\x2f\x05\x13\x09\x11\x0d\x15\x16\x1a\x25\x2d\x0d\x2e\x0d\x2e\x0d\x2e\x0d\x2e\x00\x00\x10\x1f\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x10\x16\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x2a\x14\x19\x1a\x20\x22\x29\x14\x2a\x0d\x11\x0c\x10\x14\x18\x0c\x18\x09\x13\x0d\x13\x0d\x13\x05\x12\x09\x0e\x0f\x13\x15\x19\x09\x1a\x09\x1a\x09\x1a\x09\x1a\x00\x00\x0c\x13\x05\x12\x05\x12\x10\x18\x09\x12\x20\x24\x20\x2a\x2b\x2f\x20\x30\x09\x12\x0d\x12\x09\x12\x09\x12\x09\x12\x05\x12\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[30];
    }
toplevel_consts_80_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 29,
    },
    .ob_shash = -1,
    .ob_sval = "\x9b\x06\x22\x00\xa2\x04\x29\x03\xa8\x01\x29\x03\xbf\x05\x41\x06\x00\xc1\x06\x0c\x41\x16\x03\xc1\x15\x01\x41\x16\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_80_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_80 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_80_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_80_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_80_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_80_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 200,
    .co_code = & toplevel_consts_80_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_80_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_80_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_80_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_80_names_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_80_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_80_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_80_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_80_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[123];
    }
toplevel_consts_81_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 122,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x01\x00\x74\x01\x6a\x02\x7c\x00\xa9\x01\x5c\x02\x7d\x01\x7d\x02\x7c\x02\x73\x15\x74\x01\x6a\x02\x7c\x01\xa9\x01\x5c\x02\x7d\x01\x7d\x02\x7c\x01\x72\x37\x7c\x02\x72\x39\x09\x00\x74\x00\x7c\x01\xa9\x01\x01\x00\x6e\x0b\x23\x00\x74\x03\x79\x26\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x01\x6a\x02\x7c\x01\xa9\x01\x5c\x02\x7d\x01\x7d\x02\x7c\x01\x72\x3b\x7c\x02\x73\x19\x64\x01\x53\x00\x64\x01\x53\x00\x64\x01\x53\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[429];
    }
toplevel_consts_81_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 428,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x72\x65\x6d\x6f\x76\x65\x64\x69\x72\x73\x28\x6e\x61\x6d\x65\x29\x0a\x0a\x20\x20\x20\x20\x53\x75\x70\x65\x72\x2d\x72\x6d\x64\x69\x72\x3b\x20\x72\x65\x6d\x6f\x76\x65\x20\x61\x20\x6c\x65\x61\x66\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x6e\x64\x20\x61\x6c\x6c\x20\x65\x6d\x70\x74\x79\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x0a\x20\x20\x20\x20\x6f\x6e\x65\x73\x2e\x20\x20\x57\x6f\x72\x6b\x73\x20\x6c\x69\x6b\x65\x20\x72\x6d\x64\x69\x72\x20\x65\x78\x63\x65\x70\x74\x20\x74\x68\x61\x74\x2c\x20\x69\x66\x20\x74\x68\x65\x20\x6c\x65\x61\x66\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x0a\x20\x20\x20\x20\x73\x75\x63\x63\x65\x73\x73\x66\x75\x6c\x6c\x79\x20\x72\x65\x6d\x6f\x76\x65\x64\x2c\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x63\x6f\x72\x72\x65\x73\x70\x6f\x6e\x64\x69\x6e\x67\x20\x74\x6f\x20\x72\x69\x67\x68\x74\x6d\x6f\x73\x74\x20\x70\x61\x74\x68\x0a\x20\x20\x20\x20\x73\x65\x67\x6d\x65\x6e\x74\x73\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x70\x72\x75\x6e\x65\x64\x20\x61\x77\x61\x79\x20\x75\x6e\x74\x69\x6c\x20\x65\x69\x74\x68\x65\x72\x20\x74\x68\x65\x20\x77\x68\x6f\x6c\x65\x20\x70\x61\x74\x68\x20\x69\x73\x0a\x20\x20\x20\x20\x63\x6f\x6e\x73\x75\x6d\x65\x64\x20\x6f\x72\x20\x61\x6e\x20\x65\x72\x72\x6f\x72\x20\x6f\x63\x63\x75\x72\x73\x2e\x20\x20\x45\x72\x72\x6f\x72\x73\x20\x64\x75\x72\x69\x6e\x67\x20\x74\x68\x69\x73\x20\x6c\x61\x74\x74\x65\x72\x20\x70\x68\x61\x73\x65\x20\x61\x72\x65\x0a\x20\x20\x20\x20\x69\x67\x6e\x6f\x72\x65\x64\x20\x2d\x2d\x20\x74\x68\x65\x79\x20\x67\x65\x6e\x65\x72\x61\x6c\x6c\x79\x20\x6d\x65\x61\x6e\x20\x74\x68\x61\x74\x20\x61\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x77\x61\x73\x20\x6e\x6f\x74\x20\x65\x6d\x70\x74\x79\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_81_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_81_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_81_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_48._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_80_names_1._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
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
toplevel_consts_81_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_80_varnames_3._ascii.ob_base,
            & toplevel_consts_80_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_81_name = {
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
    ._data = "removedirs",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_81_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0b\x0e\x01\x04\x01\x0e\x01\x08\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x0e\x02\x18\xfb",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_81_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0b\x0e\x01\x02\x01\x10\x01\x02\x01\x02\x05\x02\xfb\x02\x05\x02\xff\x0a\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x0e\x01\x02\xfb\x02\x05\x02\xfb\x12\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[123];
    }
toplevel_consts_81_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 122,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0a\x0b\x0f\x05\x10\x05\x10\x12\x16\x12\x1c\x1d\x21\x12\x22\x05\x0f\x05\x09\x0b\x0f\x0c\x10\x05\x26\x16\x1a\x16\x20\x21\x25\x16\x26\x09\x13\x09\x0d\x0f\x13\x0b\x0f\x05\x26\x14\x18\x05\x26\x09\x12\x0d\x12\x13\x17\x0d\x18\x0d\x18\x0d\x18\x00\x00\x10\x17\x09\x12\x09\x12\x0d\x12\x0d\x12\x0d\x12\x09\x12\x00\x00\x00\x00\x00\x00\x16\x1a\x16\x20\x21\x25\x16\x26\x09\x13\x09\x0d\x0f\x13\x0b\x0f\x05\x26\x14\x18\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_81_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x9a\x04\x1f\x00\x9f\x04\x27\x03\xa6\x01\x27\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_81_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_81 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_81_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_81_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_81_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_81_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 232,
    .co_code = & toplevel_consts_81_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_81_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_81_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_81_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_81_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_81_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_81_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_81_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[119];
    }
toplevel_consts_82_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 118,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x01\xa9\x01\x5c\x02\x7d\x02\x7d\x03\x7c\x02\x72\x15\x7c\x03\x72\x15\x74\x00\x6a\x02\x7c\x02\xa9\x01\x73\x15\x74\x03\x7c\x02\xa9\x01\x01\x00\x74\x04\x7c\x00\x7c\x01\xa9\x02\x01\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x5c\x02\x7d\x02\x7d\x03\x7c\x02\x72\x37\x7c\x03\x72\x39\x09\x00\x74\x05\x7c\x02\xa9\x01\x01\x00\x64\x01\x53\x00\x23\x00\x74\x06\x79\x33\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x53\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[573];
    }
toplevel_consts_82_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 572,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x72\x65\x6e\x61\x6d\x65\x73\x28\x6f\x6c\x64\x2c\x20\x6e\x65\x77\x29\x0a\x0a\x20\x20\x20\x20\x53\x75\x70\x65\x72\x2d\x72\x65\x6e\x61\x6d\x65\x3b\x20\x63\x72\x65\x61\x74\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x61\x73\x20\x6e\x65\x63\x65\x73\x73\x61\x72\x79\x20\x61\x6e\x64\x20\x64\x65\x6c\x65\x74\x65\x20\x61\x6e\x79\x20\x6c\x65\x66\x74\x0a\x20\x20\x20\x20\x65\x6d\x70\x74\x79\x2e\x20\x20\x57\x6f\x72\x6b\x73\x20\x6c\x69\x6b\x65\x20\x72\x65\x6e\x61\x6d\x65\x2c\x20\x65\x78\x63\x65\x70\x74\x20\x63\x72\x65\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x61\x6e\x79\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x0a\x20\x20\x20\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x6e\x65\x65\x64\x65\x64\x20\x74\x6f\x20\x6d\x61\x6b\x65\x20\x74\x68\x65\x20\x6e\x65\x77\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x67\x6f\x6f\x64\x20\x69\x73\x20\x61\x74\x74\x65\x6d\x70\x74\x65\x64\x0a\x20\x20\x20\x20\x66\x69\x72\x73\x74\x2e\x20\x20\x41\x66\x74\x65\x72\x20\x74\x68\x65\x20\x72\x65\x6e\x61\x6d\x65\x2c\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x63\x6f\x72\x72\x65\x73\x70\x6f\x6e\x64\x69\x6e\x67\x20\x74\x6f\x20\x72\x69\x67\x68\x74\x6d\x6f\x73\x74\x0a\x20\x20\x20\x20\x70\x61\x74\x68\x20\x73\x65\x67\x6d\x65\x6e\x74\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x6f\x6c\x64\x20\x6e\x61\x6d\x65\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x70\x72\x75\x6e\x65\x64\x20\x75\x6e\x74\x69\x6c\x20\x65\x69\x74\x68\x65\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x77\x68\x6f\x6c\x65\x20\x70\x61\x74\x68\x20\x69\x73\x20\x63\x6f\x6e\x73\x75\x6d\x65\x64\x20\x6f\x72\x20\x61\x20\x6e\x6f\x6e\x65\x6d\x70\x74\x79\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20\x4e\x6f\x74\x65\x3a\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x63\x61\x6e\x20\x66\x61\x69\x6c\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x6e\x65\x77\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x73\x74\x72\x75\x63\x74\x75\x72\x65\x20\x6d\x61\x64\x65\x0a\x20\x20\x20\x20\x69\x66\x20\x79\x6f\x75\x20\x6c\x61\x63\x6b\x20\x70\x65\x72\x6d\x69\x73\x73\x69\x6f\x6e\x73\x20\x6e\x65\x65\x64\x65\x64\x20\x74\x6f\x20\x75\x6e\x6c\x69\x6e\x6b\x20\x74\x68\x65\x20\x6c\x65\x61\x66\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x6f\x72\x0a\x20\x20\x20\x20\x66\x69\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_82_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_82_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_82_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_80_names_1._ascii.ob_base,
            & toplevel_consts_80_names_2._ascii.ob_base,
            & toplevel_consts_80_names_3._ascii.ob_base,
            & toplevel_consts_43._ascii.ob_base,
            & toplevel_consts_81_name._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_82_varnames_0 = {
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
    ._data = "old",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_82_varnames_1 = {
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
    ._data = "new",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_82_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_82_varnames_0._ascii.ob_base,
            & toplevel_consts_82_varnames_1._ascii.ob_base,
            & toplevel_consts_80_varnames_3._ascii.ob_base,
            & toplevel_consts_80_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_82_name = {
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
    ._data = "renames",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_82_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x0f\x12\x01\x08\x01\x0a\x01\x0e\x01\x08\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x08\xfd",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_82_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x0f\x02\x01\x02\x01\x02\xff\x02\x01\x08\xff\x0a\x01\x0a\x01\x0e\x01\x02\x01\x02\x04\x02\xfc\x04\x04\x0c\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x08\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[119];
    }
toplevel_consts_82_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 118,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x16\x12\x1c\x1d\x20\x12\x21\x05\x0f\x05\x09\x0b\x0f\x08\x0c\x05\x17\x11\x15\x05\x17\x1e\x22\x1e\x29\x2a\x2e\x1e\x2f\x05\x17\x09\x11\x12\x16\x09\x17\x09\x17\x05\x0b\x0c\x0f\x11\x14\x05\x15\x05\x15\x12\x16\x12\x1c\x1d\x20\x12\x21\x05\x0f\x05\x09\x0b\x0f\x08\x0c\x05\x11\x11\x15\x05\x11\x09\x11\x0d\x17\x18\x1c\x0d\x1d\x0d\x1d\x0d\x1d\x0d\x1d\x00\x00\x10\x17\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x05\x11\x05\x11\x05\x11\x05\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_82_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\xa6\x04\x2c\x00\xac\x04\x34\x03\xb3\x01\x34\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_82_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_82 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_82_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_82_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_82_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_82_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 254,
    .co_code = & toplevel_consts_82_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_82_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_82_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_82_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_82_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_82_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_82_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_82_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_83 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_80_names_3._ascii.ob_base,
            & toplevel_consts_81_name._ascii.ob_base,
            & toplevel_consts_82_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_85_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x64\x01\x7c\x00\x7c\x01\x7c\x02\x7c\x03\xa9\x05\x01\x00\x74\x02\x74\x03\x7c\x00\xa9\x01\x7c\x01\x7c\x02\x7c\x03\xa9\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2818];
    }
toplevel_consts_85_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 2817,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x74\x72\x65\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20\x46\x6f\x72\x20\x65\x61\x63\x68\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x6e\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x74\x72\x65\x65\x20\x72\x6f\x6f\x74\x65\x64\x20\x61\x74\x20\x74\x6f\x70\x20\x28\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x74\x6f\x70\x0a\x20\x20\x20\x20\x69\x74\x73\x65\x6c\x66\x2c\x20\x62\x75\x74\x20\x65\x78\x63\x6c\x75\x64\x69\x6e\x67\x20\x27\x2e\x27\x20\x61\x6e\x64\x20\x27\x2e\x2e\x27\x29\x2c\x20\x79\x69\x65\x6c\x64\x73\x20\x61\x20\x33\x2d\x74\x75\x70\x6c\x65\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x72\x70\x61\x74\x68\x2c\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x2c\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x73\x0a\x0a\x20\x20\x20\x20\x64\x69\x72\x70\x61\x74\x68\x20\x69\x73\x20\x61\x20\x73\x74\x72\x69\x6e\x67\x2c\x20\x74\x68\x65\x20\x70\x61\x74\x68\x20\x74\x6f\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x2e\x20\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x20\x69\x73\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x0a\x20\x20\x20\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x69\x6e\x20\x64\x69\x72\x70\x61\x74\x68\x20\x28\x65\x78\x63\x6c\x75\x64\x69\x6e\x67\x20\x27\x2e\x27\x20\x61\x6e\x64\x20\x27\x2e\x2e\x27\x29\x2e\x0a\x20\x20\x20\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x73\x20\x69\x73\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x6e\x6f\x6e\x2d\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x66\x69\x6c\x65\x73\x20\x69\x6e\x20\x64\x69\x72\x70\x61\x74\x68\x2e\x0a\x20\x20\x20\x20\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x73\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x69\x73\x74\x73\x20\x61\x72\x65\x20\x6a\x75\x73\x74\x20\x6e\x61\x6d\x65\x73\x2c\x20\x77\x69\x74\x68\x20\x6e\x6f\x20\x70\x61\x74\x68\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x73\x2e\x0a\x20\x20\x20\x20\x54\x6f\x20\x67\x65\x74\x20\x61\x20\x66\x75\x6c\x6c\x20\x70\x61\x74\x68\x20\x28\x77\x68\x69\x63\x68\x20\x62\x65\x67\x69\x6e\x73\x20\x77\x69\x74\x68\x20\x74\x6f\x70\x29\x20\x74\x6f\x20\x61\x20\x66\x69\x6c\x65\x20\x6f\x72\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x6e\x0a\x20\x20\x20\x20\x64\x69\x72\x70\x61\x74\x68\x2c\x20\x64\x6f\x20\x6f\x73\x2e\x70\x61\x74\x68\x2e\x6a\x6f\x69\x6e\x28\x64\x69\x72\x70\x61\x74\x68\x2c\x20\x6e\x61\x6d\x65\x29\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x61\x72\x67\x20\x27\x74\x6f\x70\x64\x6f\x77\x6e\x27\x20\x69\x73\x20\x74\x72\x75\x65\x20\x6f\x72\x20\x6e\x6f\x74\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x2c\x20\x74\x68\x65\x20\x74\x72\x69\x70\x6c\x65\x20\x66\x6f\x72\x20\x61\x0a\x20\x20\x20\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x20\x62\x65\x66\x6f\x72\x65\x20\x74\x68\x65\x20\x74\x72\x69\x70\x6c\x65\x73\x20\x66\x6f\x72\x20\x61\x6e\x79\x20\x6f\x66\x20\x69\x74\x73\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x0a\x20\x20\x20\x20\x28\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x61\x72\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x20\x74\x6f\x70\x20\x64\x6f\x77\x6e\x29\x2e\x20\x20\x49\x66\x20\x74\x6f\x70\x64\x6f\x77\x6e\x20\x69\x73\x20\x66\x61\x6c\x73\x65\x2c\x20\x74\x68\x65\x20\x74\x72\x69\x70\x6c\x65\x0a\x20\x20\x20\x20\x66\x6f\x72\x20\x61\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x69\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x74\x72\x69\x70\x6c\x65\x73\x20\x66\x6f\x72\x20\x61\x6c\x6c\x20\x6f\x66\x20\x69\x74\x73\x0a\x20\x20\x20\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x28\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x61\x72\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x20\x62\x6f\x74\x74\x6f\x6d\x20\x75\x70\x29\x2e\x0a\x0a\x20\x20\x20\x20\x57\x68\x65\x6e\x20\x74\x6f\x70\x64\x6f\x77\x6e\x20\x69\x73\x20\x74\x72\x75\x65\x2c\x20\x74\x68\x65\x20\x63\x61\x6c\x6c\x65\x72\x20\x63\x61\x6e\x20\x6d\x6f\x64\x69\x66\x79\x20\x74\x68\x65\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x20\x6c\x69\x73\x74\x20\x69\x6e\x2d\x70\x6c\x61\x63\x65\x0a\x20\x20\x20\x20\x28\x65\x2e\x67\x2e\x2c\x20\x76\x69\x61\x20\x64\x65\x6c\x20\x6f\x72\x20\x73\x6c\x69\x63\x65\x20\x61\x73\x73\x69\x67\x6e\x6d\x65\x6e\x74\x29\x2c\x20\x61\x6e\x64\x20\x77\x61\x6c\x6b\x20\x77\x69\x6c\x6c\x20\x6f\x6e\x6c\x79\x20\x72\x65\x63\x75\x72\x73\x65\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x77\x68\x6f\x73\x65\x20\x6e\x61\x6d\x65\x73\x20\x72\x65\x6d\x61\x69\x6e\x20\x69\x6e\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x3b\x20\x74\x68\x69\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x70\x72\x75\x6e\x65\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x73\x65\x61\x72\x63\x68\x2c\x20\x6f\x72\x20\x74\x6f\x20\x69\x6d\x70\x6f\x73\x65\x20\x61\x20\x73\x70\x65\x63\x69\x66\x69\x63\x20\x6f\x72\x64\x65\x72\x20\x6f\x66\x20\x76\x69\x73\x69\x74\x69\x6e\x67\x2e\x20\x20\x4d\x6f\x64\x69\x66\x79\x69\x6e\x67\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x20\x77\x68\x65\x6e\x0a\x20\x20\x20\x20\x74\x6f\x70\x64\x6f\x77\x6e\x20\x69\x73\x20\x66\x61\x6c\x73\x65\x20\x68\x61\x73\x20\x6e\x6f\x20\x65\x66\x66\x65\x63\x74\x20\x6f\x6e\x20\x74\x68\x65\x20\x62\x65\x68\x61\x76\x69\x6f\x72\x20\x6f\x66\x20\x6f\x73\x2e\x77\x61\x6c\x6b\x28\x29\x2c\x20\x73\x69\x6e\x63\x65\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x69\x6e\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x20\x68\x61\x76\x65\x20\x61\x6c\x72\x65\x61\x64\x79\x20\x62\x65\x65\x6e\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x74\x69\x6d\x65\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x0a\x20\x20\x20\x20\x69\x74\x73\x65\x6c\x66\x20\x69\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x2e\x20\x4e\x6f\x20\x6d\x61\x74\x74\x65\x72\x20\x74\x68\x65\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x74\x6f\x70\x64\x6f\x77\x6e\x2c\x20\x74\x68\x65\x20\x6c\x69\x73\x74\x20\x6f\x66\x0a\x20\x20\x20\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x69\x73\x20\x72\x65\x74\x72\x69\x65\x76\x65\x64\x20\x62\x65\x66\x6f\x72\x65\x20\x74\x68\x65\x20\x74\x75\x70\x6c\x65\x73\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x61\x6e\x64\x20\x69\x74\x73\x0a\x20\x20\x20\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x61\x72\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20\x42\x79\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x65\x72\x72\x6f\x72\x73\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x6f\x73\x2e\x73\x63\x61\x6e\x64\x69\x72\x28\x29\x20\x63\x61\x6c\x6c\x20\x61\x72\x65\x20\x69\x67\x6e\x6f\x72\x65\x64\x2e\x20\x20\x49\x66\x0a\x20\x20\x20\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x61\x72\x67\x20\x27\x6f\x6e\x65\x72\x72\x6f\x72\x27\x20\x69\x73\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x2c\x20\x69\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x61\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x3b\x20\x69\x74\x0a\x20\x20\x20\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x63\x61\x6c\x6c\x65\x64\x20\x77\x69\x74\x68\x20\x6f\x6e\x65\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2c\x20\x61\x6e\x20\x4f\x53\x45\x72\x72\x6f\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x20\x20\x49\x74\x20\x63\x61\x6e\x0a\x20\x20\x20\x20\x72\x65\x70\x6f\x72\x74\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x20\x74\x6f\x20\x63\x6f\x6e\x74\x69\x6e\x75\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x77\x61\x6c\x6b\x2c\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x74\x68\x65\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x0a\x20\x20\x20\x20\x74\x6f\x20\x61\x62\x6f\x72\x74\x20\x74\x68\x65\x20\x77\x61\x6c\x6b\x2e\x20\x20\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x69\x73\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x20\x61\x73\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x0a\x20\x20\x20\x20\x42\x79\x20\x64\x65\x66\x61\x75\x6c\x74\x2c\x20\x6f\x73\x2e\x77\x61\x6c\x6b\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x66\x6f\x6c\x6c\x6f\x77\x20\x73\x79\x6d\x62\x6f\x6c\x69\x63\x20\x6c\x69\x6e\x6b\x73\x20\x74\x6f\x20\x73\x75\x62\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x6f\x6e\x0a\x20\x20\x20\x20\x73\x79\x73\x74\x65\x6d\x73\x20\x74\x68\x61\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x74\x68\x65\x6d\x2e\x20\x20\x49\x6e\x20\x6f\x72\x64\x65\x72\x20\x74\x6f\x20\x67\x65\x74\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x61\x6c\x69\x74\x79\x2c\x20\x73\x65\x74\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x27\x66\x6f\x6c\x6c\x6f\x77\x6c\x69\x6e\x6b\x73\x27\x20\x74\x6f\x20\x74\x72\x75\x65\x2e\x0a\x0a\x20\x20\x20\x20\x43\x61\x75\x74\x69\x6f\x6e\x3a\x20\x20\x69\x66\x20\x79\x6f\x75\x20\x70\x61\x73\x73\x20\x61\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x66\x6f\x72\x20\x74\x6f\x70\x2c\x20\x64\x6f\x6e\x27\x74\x20\x63\x68\x61\x6e\x67\x65\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x77\x6f\x72\x6b\x69\x6e\x67\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x72\x65\x73\x75\x6d\x70\x74\x69\x6f\x6e\x73\x20\x6f\x66\x20\x77\x61\x6c\x6b\x2e\x20\x20\x77\x61\x6c\x6b\x20\x6e\x65\x76\x65\x72\x0a\x20\x20\x20\x20\x63\x68\x61\x6e\x67\x65\x73\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x2c\x20\x61\x6e\x64\x20\x61\x73\x73\x75\x6d\x65\x73\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x63\x6c\x69\x65\x6e\x74\x20\x64\x6f\x65\x73\x6e\x27\x74\x0a\x20\x20\x20\x20\x65\x69\x74\x68\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x45\x78\x61\x6d\x70\x6c\x65\x3a\x0a\x0a\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x20\x6f\x73\x0a\x20\x20\x20\x20\x66\x72\x6f\x6d\x20\x6f\x73\x2e\x70\x61\x74\x68\x20\x69\x6d\x70\x6f\x72\x74\x20\x6a\x6f\x69\x6e\x2c\x20\x67\x65\x74\x73\x69\x7a\x65\x0a\x20\x20\x20\x20\x66\x6f\x72\x20\x72\x6f\x6f\x74\x2c\x20\x64\x69\x72\x73\x2c\x20\x66\x69\x6c\x65\x73\x20\x69\x6e\x20\x6f\x73\x2e\x77\x61\x6c\x6b\x28\x27\x70\x79\x74\x68\x6f\x6e\x2f\x4c\x69\x62\x2f\x65\x6d\x61\x69\x6c\x27\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x72\x6f\x6f\x74\x2c\x20\x22\x63\x6f\x6e\x73\x75\x6d\x65\x73\x22\x2c\x20\x65\x6e\x64\x3d\x22\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x73\x75\x6d\x28\x67\x65\x74\x73\x69\x7a\x65\x28\x6a\x6f\x69\x6e\x28\x72\x6f\x6f\x74\x2c\x20\x6e\x61\x6d\x65\x29\x29\x20\x66\x6f\x72\x20\x6e\x61\x6d\x65\x20\x69\x6e\x20\x66\x69\x6c\x65\x73\x29\x2c\x20\x65\x6e\x64\x3d\x22\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x22\x62\x79\x74\x65\x73\x20\x69\x6e\x22\x2c\x20\x6c\x65\x6e\x28\x66\x69\x6c\x65\x73\x29\x2c\x20\x22\x6e\x6f\x6e\x2d\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x66\x69\x6c\x65\x73\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x66\x20\x27\x43\x56\x53\x27\x20\x69\x6e\x20\x64\x69\x72\x73\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x72\x73\x2e\x72\x65\x6d\x6f\x76\x65\x28\x27\x43\x56\x53\x27\x29\x20\x20\x23\x20\x64\x6f\x6e\x27\x74\x20\x76\x69\x73\x69\x74\x20\x43\x56\x53\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_85_consts_1 = {
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
    ._data = "os.walk",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_85_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_85_consts_0._ascii.ob_base,
            & toplevel_consts_85_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_85_names_0 = {
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
toplevel_consts_85_names_1 = {
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
    ._data = "audit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_85_names_2 = {
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
    ._data = "_walk",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_85_names_3 = {
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
    ._data = "fspath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_85_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_85_names_0._ascii.ob_base,
            & toplevel_consts_85_names_1._ascii.ob_base,
            & toplevel_consts_85_names_2._ascii.ob_base,
            & toplevel_consts_85_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_85_varnames_0 = {
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
    ._data = "top",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_85_varnames_1 = {
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
    ._data = "topdown",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_85_varnames_2 = {
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
    ._data = "onerror",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_85_varnames_3 = {
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
    ._data = "followlinks",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_85_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_85_varnames_0._ascii.ob_base,
            & toplevel_consts_85_varnames_1._ascii.ob_base,
            & toplevel_consts_85_varnames_2._ascii.ob_base,
            & toplevel_consts_85_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_85_name = {
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
    ._data = "walk",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_85_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x12\x3b\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_85_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x08\x05\x0e\x0f\x18\x1a\x1d\x1f\x26\x28\x2f\x31\x3c\x05\x3d\x05\x3d\x0c\x11\x12\x18\x19\x1c\x12\x1d\x1f\x26\x28\x2f\x31\x3c\x0c\x3d\x05\x3d",
};
static struct PyCodeObject toplevel_consts_85 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_85_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_85_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_85_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 282,
    .co_code = & toplevel_consts_85_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_85_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_85_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_85_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_85_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_85_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_85_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_85_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[513];
    }
toplevel_consts_86_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 512,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x67\x00\x7d\x04\x67\x00\x7d\x05\x67\x00\x7d\x06\x09\x00\x74\x00\x7c\x00\xa9\x01\x7d\x07\x6e\x18\x23\x00\x74\x01\x79\x22\x7d\x08\x7c\x02\x81\x18\x7c\x02\x7c\x08\xa9\x01\x01\x00\x59\x00\x64\x00\x7d\x08\x7e\x08\x64\x00\x53\x00\x64\x00\x7d\x08\x7e\x08\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x07\x35\x00\x01\x00\x09\x00\x09\x00\x09\x00\x74\x02\x7c\x07\xa9\x01\x7d\x09\x6e\x0a\x23\x00\x74\x03\x79\x37\x01\x00\x59\x00\x6e\x6f\x77\x00\x78\x03\x59\x00\x77\x01\x6e\x1d\x23\x00\x74\x01\x79\x55\x7d\x08\x7c\x02\x81\x46\x7c\x02\x7c\x08\xa9\x01\x01\x00\x59\x00\x64\x00\x7d\x08\x7e\x08\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x64\x00\x53\x00\x64\x00\x7d\x08\x7e\x08\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x09\xa0\x04\xa8\x00\xa9\x00\x7d\x0a\x6e\x0c\x23\x00\x74\x01\x79\x68\x01\x00\x64\x02\x7d\x0a\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x0a\x72\x76\x7c\x04\xa0\x05\x7c\x09\x6a\x06\xa8\x01\xa9\x01\x01\x00\x6e\x07\x7c\x05\xa0\x05\x7c\x09\x6a\x06\xa8\x01\xa9\x01\x01\x00\x7c\x01\x73\xa5\x7c\x0a\x72\xa5\x7c\x03\x72\x86\x64\x01\x7d\x0b\x6e\x16\x09\x00\x7c\x09\xa0\x07\xa8\x00\xa9\x00\x7d\x0c\x6e\x0c\x23\x00\x74\x01\x79\x95\x01\x00\x64\x02\x7d\x0c\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x0c\x0c\x00\x7d\x0b\x7c\x0b\x72\xa5\x7c\x06\xa0\x05\x7c\x09\x6a\x08\xa8\x01\xa9\x01\x01\x00\x71\x2a\x09\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\xb4\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x01\x72\xe6\x7c\x00\x7c\x04\x7c\x05\x66\x03\x56\x00\x97\x01\x01\x00\x74\x08\x6a\x09\x74\x08\x6a\x0a\x02\x02\x7d\x0d\x7d\x0e\x7c\x04\x44\x00\x5d\x19\x7d\x0f\x7c\x0e\x7c\x00\x7c\x0f\xa9\x02\x7d\x10\x7c\x03\x73\xd7\x7c\x0d\x7c\x10\xa9\x01\x73\xe3\x74\x0b\x7c\x10\x7c\x01\x7c\x02\x7c\x03\xa9\x04\x45\x00\x64\x00\x7b\x02\x97\x02\x71\xdf\x01\x00\x71\xca\x64\x00\x53\x00\x7c\x06\x44\x00\x5d\x0e\x7d\x10\x74\x0b\x7c\x10\x7c\x01\x7c\x02\x7c\x03\xa9\x04\x45\x00\x64\x00\x7b\x02\x97\x02\x71\xf2\x01\x00\x71\xe8\x7c\x00\x7c\x04\x7c\x05\x66\x03\x56\x00\x97\x01\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_86_consts = {
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
            Py_True,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_86_names_2 = {
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
    ._data = "next",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_86_names_3 = {
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
    ._data = "StopIteration",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_86_names_4 = {
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
    ._data = "is_dir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_86_names_5 = {
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
        uint8_t _data[11];
    }
toplevel_consts_86_names_7 = {
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
    ._data = "is_symlink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_86_names_9 = {
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
    ._data = "islink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_86_names_10 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_86_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_56._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
            & toplevel_consts_86_names_2._ascii.ob_base,
            & toplevel_consts_86_names_3._ascii.ob_base,
            & toplevel_consts_86_names_4._ascii.ob_base,
            & toplevel_consts_86_names_5._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_86_names_7._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_86_names_9._ascii.ob_base,
            & toplevel_consts_86_names_10._ascii.ob_base,
            & toplevel_consts_85_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_86_varnames_4 = {
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
        uint8_t _data[8];
    }
toplevel_consts_86_varnames_5 = {
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
    ._data = "nondirs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_86_varnames_6 = {
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
    ._data = "walk_dirs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_86_varnames_7 = {
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
    ._data = "scandir_it",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_86_varnames_8 = {
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
    ._data = "error",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_86_varnames_9 = {
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
    ._data = "entry",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_86_varnames_11 = {
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
    ._data = "walk_into",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_86_varnames_15 = {
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
        uint8_t _data[9];
    }
toplevel_consts_86_varnames_16 = {
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
    ._data = "new_path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts_86_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_85_varnames_0._ascii.ob_base,
            & toplevel_consts_85_varnames_1._ascii.ob_base,
            & toplevel_consts_85_varnames_2._ascii.ob_base,
            & toplevel_consts_85_varnames_3._ascii.ob_base,
            & toplevel_consts_86_varnames_4._ascii.ob_base,
            & toplevel_consts_86_varnames_5._ascii.ob_base,
            & toplevel_consts_86_varnames_6._ascii.ob_base,
            & toplevel_consts_86_varnames_7._ascii.ob_base,
            & toplevel_consts_86_varnames_8._ascii.ob_base,
            & toplevel_consts_86_varnames_9._ascii.ob_base,
            & toplevel_consts_86_names_4._ascii.ob_base,
            & toplevel_consts_86_varnames_11._ascii.ob_base,
            & toplevel_consts_86_names_7._ascii.ob_base,
            & toplevel_consts_86_names_9._ascii.ob_base,
            & toplevel_consts_86_names_10._ascii.ob_base,
            & toplevel_consts_86_varnames_15._ascii.ob_base,
            & toplevel_consts_86_varnames_16._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_86_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x04\x01\x04\x01\x02\x07\x0a\x03\x02\x80\x06\x01\x04\x01\x08\x01\x0c\x01\x08\x80\x02\xfd\x06\x80\x06\x05\x02\x01\x02\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x02\xff\x02\x80\x06\x03\x04\x01\x08\x01\x08\x01\x0e\xf6\x08\x80\x02\x07\x06\x80\x02\x05\x0c\x01\x02\x80\x06\x01\x08\x03\x02\xfd\x06\x80\x04\x05\x10\x01\x0e\x02\x08\x02\x04\x03\x06\x01\x02\x02\x0c\x01\x02\x80\x06\x01\x08\x04\x02\xfc\x06\x80\x06\x05\x04\x02\x0e\x01\x02\xd9\x02\x05\x14\xfa\x06\x80\x08\x00\x04\x2b\x0e\x01\x0e\x03\x08\x01\x0a\x01\x0c\x05\x18\x01\x02\x80\x04\xf9\x08\x0a\x1a\x01\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[175];
    }
toplevel_consts_86_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 174,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x04\x01\x04\x01\x02\x0e\x0a\xfc\x02\x80\x02\x01\x04\x03\x02\xfe\x0a\x01\x0c\x01\x08\x80\x02\x00\x06\x80\x02\x02\x04\x28\x02\xd9\x02\x09\x02\xfc\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\xfe\x02\x80\x02\x03\x04\x03\x02\xfe\x0a\x01\x08\x01\x0e\x1e\x08\x80\x02\xe2\x06\x80\x02\x07\x0c\xfc\x02\x80\x02\x01\x0e\x03\x06\x80\x02\x02\x02\x03\x10\xfe\x0e\x02\x02\x02\x02\x10\x02\xf0\x02\x10\x02\xf3\x02\x0a\x06\xf7\x02\x08\x0c\xfb\x02\x80\x02\x01\x0e\x04\x06\x80\x06\x01\x02\x02\x10\x01\x02\xd9\x02\x05\x14\x22\x06\x80\x08\x00\x02\x03\x02\x12\x0e\xef\x0e\x03\x02\x01\x04\x07\x02\xf9\x0a\x01\x02\x05\x02\x01\x06\xff\x1a\x01\x02\x80\x04\x00\x02\x03\x04\x01\x02\xff\x1a\x01\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[513];
    }
toplevel_consts_86_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 512,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0c\x0e\x05\x09\x0f\x11\x05\x0c\x11\x13\x05\x0e\x05\x0f\x16\x1d\x1e\x21\x16\x22\x09\x13\x09\x13\x00\x00\x0c\x13\x05\x0f\x05\x0f\x0c\x13\x09\x1b\x0d\x14\x15\x1a\x0d\x1b\x0d\x1b\x09\x0f\x09\x0f\x09\x0f\x09\x0f\x09\x0f\x09\x0f\x00\x00\x00\x00\x00\x00\x00\x00\x05\x0f\x00\x00\x00\x00\x00\x00\x0a\x14\x05\x31\x05\x31\x0f\x13\x0d\x17\x11\x1a\x1d\x21\x22\x2c\x1d\x2d\x15\x1a\x15\x1a\x00\x00\x18\x25\x11\x1a\x11\x1a\x15\x1a\x15\x1a\x11\x1a\x00\x00\x00\x00\x00\x00\x15\x1a\x00\x00\x14\x1b\x0d\x17\x0d\x17\x14\x1b\x11\x23\x15\x1c\x1d\x22\x15\x23\x15\x23\x11\x17\x11\x17\x11\x17\x11\x17\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x17\x00\x00\x00\x00\x00\x00\x0d\x1f\x1a\x1f\x1a\x28\x1a\x28\x1a\x28\x11\x17\x11\x17\x00\x00\x14\x1b\x0d\x1f\x0d\x1f\x1a\x1f\x11\x17\x11\x17\x11\x17\x0d\x1f\x00\x00\x00\x00\x00\x00\x10\x16\x0d\x2b\x11\x15\x11\x28\x1d\x22\x1d\x27\x11\x28\x11\x28\x11\x28\x11\x28\x11\x18\x11\x2b\x20\x25\x20\x2a\x11\x2b\x11\x2b\x11\x2b\x14\x1b\x0d\x31\x20\x26\x0d\x31\x14\x1f\x11\x2f\x21\x25\x15\x1e\x15\x1e\x15\x2b\x26\x2b\x26\x38\x26\x38\x26\x38\x19\x23\x19\x23\x00\x00\x1c\x23\x15\x2b\x15\x2b\x26\x2b\x19\x23\x19\x23\x19\x23\x15\x2b\x00\x00\x00\x00\x00\x00\x25\x2f\x21\x2f\x15\x1e\x14\x1d\x11\x31\x15\x1e\x15\x31\x26\x2b\x26\x30\x15\x31\x15\x31\x15\x31\x0f\x13\x15\x1a\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x00\x00\x00\x00\x00\x00\x05\x31\x05\x31\x05\x31\x05\x31\x08\x0f\x05\x21\x0f\x12\x14\x18\x1a\x21\x0f\x21\x09\x21\x09\x21\x09\x21\x18\x1c\x18\x23\x25\x29\x25\x2e\x18\x2e\x09\x0f\x11\x15\x18\x1c\x09\x4a\x09\x4a\x0d\x14\x18\x1c\x1d\x20\x22\x29\x18\x2a\x0d\x15\x10\x1b\x0d\x4a\x23\x29\x2a\x32\x23\x33\x0d\x4a\x1c\x21\x22\x2a\x2c\x33\x35\x3c\x3e\x49\x1c\x4a\x11\x4a\x11\x4a\x11\x4a\x11\x4a\x11\x4a\x11\x4a\x00\x00\x09\x4a\x09\x4a\x19\x22\x09\x46\x09\x46\x0d\x15\x18\x1d\x1e\x26\x28\x2f\x31\x38\x3a\x45\x18\x46\x0d\x46\x0d\x46\x0d\x46\x0d\x46\x0d\x46\x0d\x46\x0d\x46\x0f\x12\x14\x18\x1a\x21\x0f\x21\x09\x21\x09\x21\x09\x21\x09\x21\x09\x21",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[169];
    }
toplevel_consts_86_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 168,
    },
    .ob_shash = -1,
    .ob_sval = "\x89\x04\x0e\x00\x8e\x04\x23\x03\x92\x06\x1e\x03\x9e\x05\x23\x03\xa8\x02\x42\x2d\x03\xac\x04\x31\x02\xb0\x01\x3c\x02\xb1\x04\x38\x05\xb5\x01\x3c\x02\xb6\x01\x42\x2d\x03\xb7\x01\x38\x05\xb8\x03\x3c\x02\xbb\x01\x42\x2d\x03\xbc\x04\x41\x16\x05\xc1\x00\x06\x41\x11\x05\xc1\x06\x04\x42\x2d\x03\xc1\x11\x05\x41\x16\x05\xc1\x16\x03\x42\x2d\x03\xc1\x1a\x05\x41\x20\x02\xc1\x1f\x01\x42\x2d\x03\xc1\x20\x06\x41\x29\x05\xc1\x26\x02\x42\x2d\x03\xc1\x28\x01\x41\x29\x05\xc1\x29\x1d\x42\x2d\x03\xc2\x07\x05\x42\x0d\x02\xc2\x0c\x01\x42\x2d\x03\xc2\x0d\x06\x42\x16\x05\xc2\x13\x02\x42\x2d\x03\xc2\x15\x01\x42\x16\x05\xc2\x16\x10\x42\x2d\x03\xc2\x2d\x04\x42\x31\x07\xc2\x34\x01\x42\x31\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[18];
    }
toplevel_consts_86_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 17,
    },
    .ob_shash = -1,
    .ob_sval = "                 ",
};
static struct PyCodeObject toplevel_consts_86 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_86_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_86_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_86_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_86_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 344,
    .co_code = & toplevel_consts_86_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_86_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_86_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_85_names_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_85_names_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_86_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_86_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_86_columntable.ob_base.ob_base,
    .co_nlocalsplus = 17,
    .co_nlocals = 17,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_86_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_88 = {
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
        uint8_t _data[16];
    }
toplevel_consts_89_0 = {
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
    ._data = "follow_symlinks",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_89_1 = {
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
    ._data = "dir_fd",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_89 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_89_0._ascii.ob_base,
            & toplevel_consts_89_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[193];
    }
toplevel_consts_90_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 192,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x6a\x01\x64\x01\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x7c\x04\xa9\x06\x01\x00\x74\x02\x7c\x00\xa9\x01\x7d\x00\x7c\x03\x73\x19\x74\x03\x7c\x00\x64\x02\x7c\x04\x64\x03\xaa\x03\x7d\x05\x74\x04\x7c\x00\x74\x05\x7c\x04\x64\x04\xaa\x03\x7d\x06\x09\x00\x7c\x03\x73\x31\x74\x06\x6a\x07\x7c\x05\x6a\x08\xa9\x01\x72\x49\x74\x09\x6a\x0a\x7c\x05\x74\x03\x7c\x06\xa9\x01\xa9\x02\x72\x50\x74\x0b\x7c\x06\x7c\x00\x74\x0c\x7c\x00\x74\x0d\xa9\x02\x7c\x01\x7c\x02\x7c\x03\xa9\x06\x45\x00\x64\x05\x7b\x02\x97\x02\x71\x3e\x01\x00\x09\x00\x74\x0e\x7c\x06\xa9\x01\x01\x00\x64\x05\x53\x00\x09\x00\x74\x0e\x7c\x06\xa9\x01\x01\x00\x64\x05\x53\x00\x09\x00\x74\x0e\x7c\x06\xa9\x01\x01\x00\x64\x05\x53\x00\x23\x00\x74\x0e\x7c\x06\xa9\x01\x01\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1283];
    }
toplevel_consts_90_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1282,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x74\x72\x65\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x62\x65\x68\x61\x76\x65\x73\x20\x65\x78\x61\x63\x74\x6c\x79\x20\x6c\x69\x6b\x65\x20\x77\x61\x6c\x6b\x28\x29\x2c\x20\x65\x78\x63\x65\x70\x74\x20\x74\x68\x61\x74\x20\x69\x74\x20\x79\x69\x65\x6c\x64\x73\x20\x61\x20\x34\x2d\x74\x75\x70\x6c\x65\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x72\x70\x61\x74\x68\x2c\x20\x64\x69\x72\x6e\x61\x6d\x65\x73\x2c\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x73\x2c\x20\x64\x69\x72\x66\x64\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x60\x64\x69\x72\x70\x61\x74\x68\x60\x2c\x20\x60\x64\x69\x72\x6e\x61\x6d\x65\x73\x60\x20\x61\x6e\x64\x20\x60\x66\x69\x6c\x65\x6e\x61\x6d\x65\x73\x60\x20\x61\x72\x65\x20\x69\x64\x65\x6e\x74\x69\x63\x61\x6c\x20\x74\x6f\x20\x77\x61\x6c\x6b\x28\x29\x20\x6f\x75\x74\x70\x75\x74\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x60\x64\x69\x72\x66\x64\x60\x20\x69\x73\x20\x61\x20\x66\x69\x6c\x65\x20\x64\x65\x73\x63\x72\x69\x70\x74\x6f\x72\x20\x72\x65\x66\x65\x72\x72\x69\x6e\x67\x20\x74\x6f\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x60\x64\x69\x72\x70\x61\x74\x68\x60\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x61\x64\x76\x61\x6e\x74\x61\x67\x65\x20\x6f\x66\x20\x66\x77\x61\x6c\x6b\x28\x29\x20\x6f\x76\x65\x72\x20\x77\x61\x6c\x6b\x28\x29\x20\x69\x73\x20\x74\x68\x61\x74\x20\x69\x74\x27\x73\x20\x73\x61\x66\x65\x20\x61\x67\x61\x69\x6e\x73\x74\x20\x73\x79\x6d\x6c\x69\x6e\x6b\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x61\x63\x65\x73\x20\x28\x77\x68\x65\x6e\x20\x66\x6f\x6c\x6c\x6f\x77\x5f\x73\x79\x6d\x6c\x69\x6e\x6b\x73\x20\x69\x73\x20\x46\x61\x6c\x73\x65\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x64\x69\x72\x5f\x66\x64\x20\x69\x73\x20\x6e\x6f\x74\x20\x4e\x6f\x6e\x65\x2c\x20\x69\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x61\x20\x66\x69\x6c\x65\x20\x64\x65\x73\x63\x72\x69\x70\x74\x6f\x72\x20\x6f\x70\x65\x6e\x20\x74\x6f\x20\x61\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x74\x6f\x70\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x3b\x20\x74\x6f\x70\x20\x77\x69\x6c\x6c\x20\x74\x68\x65\x6e\x20\x62\x65\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x20\x74\x6f\x20\x74\x68\x61\x74\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x28\x64\x69\x72\x5f\x66\x64\x20\x69\x73\x20\x61\x6c\x77\x61\x79\x73\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x20\x66\x6f\x72\x20\x66\x77\x61\x6c\x6b\x2e\x29\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x43\x61\x75\x74\x69\x6f\x6e\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x53\x69\x6e\x63\x65\x20\x66\x77\x61\x6c\x6b\x28\x29\x20\x79\x69\x65\x6c\x64\x73\x20\x66\x69\x6c\x65\x20\x64\x65\x73\x63\x72\x69\x70\x74\x6f\x72\x73\x2c\x20\x74\x68\x6f\x73\x65\x20\x61\x72\x65\x20\x6f\x6e\x6c\x79\x20\x76\x61\x6c\x69\x64\x20\x75\x6e\x74\x69\x6c\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6e\x65\x78\x74\x20\x69\x74\x65\x72\x61\x74\x69\x6f\x6e\x20\x73\x74\x65\x70\x2c\x20\x73\x6f\x20\x79\x6f\x75\x20\x73\x68\x6f\x75\x6c\x64\x20\x64\x75\x70\x28\x29\x20\x74\x68\x65\x6d\x20\x69\x66\x20\x79\x6f\x75\x20\x77\x61\x6e\x74\x20\x74\x6f\x20\x6b\x65\x65\x70\x20\x74\x68\x65\x6d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x61\x20\x6c\x6f\x6e\x67\x65\x72\x20\x70\x65\x72\x69\x6f\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x45\x78\x61\x6d\x70\x6c\x65\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x20\x6f\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x72\x6f\x6f\x74\x2c\x20\x64\x69\x72\x73\x2c\x20\x66\x69\x6c\x65\x73\x2c\x20\x72\x6f\x6f\x74\x66\x64\x20\x69\x6e\x20\x6f\x73\x2e\x66\x77\x61\x6c\x6b\x28\x27\x70\x79\x74\x68\x6f\x6e\x2f\x4c\x69\x62\x2f\x65\x6d\x61\x69\x6c\x27\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x72\x6f\x6f\x74\x2c\x20\x22\x63\x6f\x6e\x73\x75\x6d\x65\x73\x22\x2c\x20\x65\x6e\x64\x3d\x22\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x73\x75\x6d\x28\x6f\x73\x2e\x73\x74\x61\x74\x28\x6e\x61\x6d\x65\x2c\x20\x64\x69\x72\x5f\x66\x64\x3d\x72\x6f\x6f\x74\x66\x64\x29\x2e\x73\x74\x5f\x73\x69\x7a\x65\x20\x66\x6f\x72\x20\x6e\x61\x6d\x65\x20\x69\x6e\x20\x66\x69\x6c\x65\x73\x29\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x64\x3d\x22\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x69\x6e\x74\x28\x22\x62\x79\x74\x65\x73\x20\x69\x6e\x22\x2c\x20\x6c\x65\x6e\x28\x66\x69\x6c\x65\x73\x29\x2c\x20\x22\x6e\x6f\x6e\x2d\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x66\x69\x6c\x65\x73\x22\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x69\x66\x20\x27\x43\x56\x53\x27\x20\x69\x6e\x20\x64\x69\x72\x73\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x72\x73\x2e\x72\x65\x6d\x6f\x76\x65\x28\x27\x43\x56\x53\x27\x29\x20\x20\x23\x20\x64\x6f\x6e\x27\x74\x20\x76\x69\x73\x69\x74\x20\x43\x56\x53\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_90_consts_1 = {
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
    ._data = "os.fwalk",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_90_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_89_1._ascii.ob_base,
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
toplevel_consts_90_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_90_consts_0._ascii.ob_base,
            & toplevel_consts_90_consts_1._ascii.ob_base,
            Py_False,
            & toplevel_consts_89._object.ob_base.ob_base,
            & toplevel_consts_90_consts_4._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_90_names_5 = {
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
    ._data = "O_RDONLY",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_90_names_6 = {
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
    ._data = "st",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_90_names_7 = {
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
    ._data = "S_ISDIR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_90_names_8 = {
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
    ._data = "st_mode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_90_names_10 = {
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
    ._data = "samestat",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_90_names_11 = {
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
    ._data = "_fwalk",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_90_names_14 = {
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
    ._data = "close",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_90_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_85_names_0._ascii.ob_base,
            & toplevel_consts_85_names_1._ascii.ob_base,
            & toplevel_consts_85_names_3._ascii.ob_base,
            & toplevel_consts_27._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_90_names_5._ascii.ob_base,
            & toplevel_consts_90_names_6._ascii.ob_base,
            & toplevel_consts_90_names_7._ascii.ob_base,
            & toplevel_consts_90_names_8._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_90_names_10._ascii.ob_base,
            & toplevel_consts_90_names_11._ascii.ob_base,
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_90_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_90_varnames_5 = {
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
    ._data = "orig_st",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_90_varnames_6 = {
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
    ._data = "topfd",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_90_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_85_varnames_0._ascii.ob_base,
            & toplevel_consts_85_varnames_1._ascii.ob_base,
            & toplevel_consts_85_varnames_2._ascii.ob_base,
            & toplevel_consts_89_0._ascii.ob_base,
            & toplevel_consts_89_1._ascii.ob_base,
            & toplevel_consts_90_varnames_5._ascii.ob_base,
            & toplevel_consts_90_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_90_name = {
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
    ._data = "fwalk",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_90_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x21\x08\x01\x04\x03\x0e\x01\x0e\x01\x02\x01\x10\x01\x0e\x01\x02\xff\x0e\x02\x06\x01\x10\xff\x0c\x03\x02\xfb\x0c\x05\x02\xfb\x0c\x05\x02\x80\x0a\x00\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_90_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x21\x08\x01\x02\x03\x10\x01\x0e\x01\x02\x07\x02\xfb\x02\x03\x0a\xfd\x02\x03\x0e\xfe\x02\x02\x0e\xff\x16\x01\x0c\x02\x02\xfe\x0c\x02\x02\xfe\x0c\x02\x02\x80\x0a\x00\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[193];
    }
toplevel_consts_90_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 192,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x09\x0c\x09\x12\x13\x1d\x1f\x22\x24\x2b\x2d\x34\x36\x45\x47\x4d\x09\x4e\x09\x4e\x0f\x15\x16\x19\x0f\x1a\x09\x0c\x10\x1f\x09\x46\x17\x1b\x1c\x1f\x31\x36\x3f\x45\x17\x46\x17\x46\x0d\x14\x11\x15\x16\x19\x1b\x23\x2c\x32\x11\x33\x11\x33\x09\x0e\x09\x19\x11\x20\x0d\x45\x25\x27\x25\x2f\x30\x37\x30\x3f\x25\x40\x0d\x45\x25\x29\x25\x32\x33\x3a\x3c\x40\x41\x46\x3c\x47\x25\x48\x0d\x45\x1c\x22\x23\x28\x2a\x2d\x2f\x39\x3a\x3d\x3f\x44\x2f\x45\x23\x2a\x2c\x33\x35\x44\x1c\x45\x11\x45\x11\x45\x11\x45\x11\x45\x11\x45\x11\x45\x11\x45\x0d\x12\x13\x18\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x45\x0d\x12\x13\x18\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x45\x0d\x12\x13\x18\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x00\x00\x0d\x12\x13\x18\x0d\x19\x0d\x19\x0d\x19\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_90_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 11,
    },
    .ob_shash = -1,
    .ob_sval = "\xa1\x21\x41\x17\x00\xc1\x17\x06\x41\x1d\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_90_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_90 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_90_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_90_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_90_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_90_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 2,
    .co_stacksize = 7,
    .co_firstlineno = 430,
    .co_code = & toplevel_consts_90_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_90_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_90_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_90_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_90_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_90_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_90_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_90_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_90_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[463];
    }
toplevel_consts_91_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 462,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x06\x67\x00\x7d\x07\x67\x00\x7d\x08\x7c\x03\x73\x0e\x7c\x05\x72\x10\x64\x00\x6e\x01\x67\x00\x7d\x09\x7c\x06\x44\x00\x5d\x47\x7d\x0a\x7c\x0a\x6a\x01\x7d\x0b\x7c\x02\x72\x1f\x74\x02\x7c\x0b\xa9\x01\x7d\x0b\x09\x00\x7c\x0a\xa0\x03\xa8\x00\xa9\x00\x72\x34\x7c\x07\xa0\x04\x7c\x0b\xa8\x01\xa9\x01\x01\x00\x7c\x09\x81\x33\x7c\x09\xa0\x04\x7c\x0a\xa8\x01\xa9\x01\x01\x00\x6e\x06\x7c\x08\xa0\x04\x7c\x0b\xa8\x01\xa9\x01\x01\x00\x71\x14\x23\x00\x74\x05\x79\x58\x01\x00\x09\x00\x7c\x0a\xa0\x06\xa8\x00\xa9\x00\x72\x4b\x7c\x08\xa0\x04\x7c\x0b\xa8\x01\xa9\x01\x01\x00\x6e\x0a\x23\x00\x74\x05\x79\x52\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x59\x00\x71\x14\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x03\x72\x66\x7c\x01\x7c\x07\x7c\x08\x7c\x00\x66\x04\x56\x00\x97\x01\x01\x00\x7c\x09\x80\x6a\x7c\x07\x6e\x04\x74\x07\x7c\x07\x7c\x09\xa9\x02\x44\x00\x5d\x69\x7d\x0b\x09\x00\x7c\x05\x73\x8d\x7c\x03\x72\x7e\x74\x08\x7c\x0b\x7c\x00\x64\x01\x64\x02\xaa\x03\x7d\x0c\x6e\x0f\x7c\x09\x80\x82\x4a\x00\x82\x01\x7c\x0b\x5c\x02\x7d\x0b\x7d\x0a\x7c\x0a\xa0\x08\x64\x01\x64\x03\xa8\x02\xaa\x01\x7d\x0c\x74\x09\x7c\x0b\x74\x0a\x7c\x00\x64\x04\xaa\x03\x7d\x0d\x6e\x17\x23\x00\x74\x05\x79\xa8\x7d\x0e\x7c\x04\x81\x9f\x7c\x04\x7c\x0e\xa9\x01\x01\x00\x59\x00\x64\x00\x7d\x0e\x7e\x0e\x71\x6f\x64\x00\x7d\x0e\x7e\x0e\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x05\x73\xb7\x74\x0b\x6a\x0c\x7c\x0c\x74\x08\x7c\x0d\xa9\x01\xa9\x02\x72\xcb\x74\x0b\x6a\x0d\x7c\x01\x7c\x0b\xa9\x02\x7d\x0f\x74\x0e\x7c\x0d\x7c\x0f\x7c\x02\x7c\x03\x7c\x04\x7c\x05\xa9\x06\x45\x00\x64\x00\x7b\x02\x97\x02\x71\xc7\x01\x00\x74\x0f\x7c\x0d\xa9\x01\x01\x00\x71\x6f\x23\x00\x74\x0f\x7c\x0d\xa9\x01\x01\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x03\x73\xe5\x7c\x01\x7c\x07\x7c\x08\x7c\x00\x66\x04\x56\x00\x97\x01\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_91_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_89_1._ascii.ob_base,
            & toplevel_consts_89_0._ascii.ob_base,
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
toplevel_consts_91_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_89_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_91_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            Py_None,
            Py_False,
            & toplevel_consts_91_consts_2._object.ob_base.ob_base,
            & toplevel_consts_91_consts_3._object.ob_base.ob_base,
            & toplevel_consts_90_consts_4._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_91_names_7 = {
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
    ._data = "zip",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_91_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_56._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_86_names_4._ascii.ob_base,
            & toplevel_consts_86_names_5._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
            & toplevel_consts_86_names_7._ascii.ob_base,
            & toplevel_consts_91_names_7._ascii.ob_base,
            & toplevel_consts_27._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_90_names_5._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_90_names_10._ascii.ob_base,
            & toplevel_consts_86_names_10._ascii.ob_base,
            & toplevel_consts_90_names_11._ascii.ob_base,
            & toplevel_consts_90_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_91_varnames_1 = {
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
    ._data = "toppath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_91_varnames_2 = {
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
    ._data = "isbytes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_91_varnames_9 = {
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
    ._data = "entries",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_91_varnames_13 = {
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
    ._data = "dirfd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_91_varnames_14 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_91_varnames_15 = {
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
    ._data = "dirpath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_91_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_90_varnames_6._ascii.ob_base,
            & toplevel_consts_91_varnames_1._ascii.ob_base,
            & toplevel_consts_91_varnames_2._ascii.ob_base,
            & toplevel_consts_85_varnames_1._ascii.ob_base,
            & toplevel_consts_85_varnames_2._ascii.ob_base,
            & toplevel_consts_89_0._ascii.ob_base,
            & toplevel_consts_86_varnames_7._ascii.ob_base,
            & toplevel_consts_86_varnames_4._ascii.ob_base,
            & toplevel_consts_86_varnames_5._ascii.ob_base,
            & toplevel_consts_91_varnames_9._ascii.ob_base,
            & toplevel_consts_86_varnames_9._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_90_varnames_5._ascii.ob_base,
            & toplevel_consts_91_varnames_13._ascii.ob_base,
            & toplevel_consts_91_varnames_14._ascii.ob_base,
            & toplevel_consts_91_varnames_15._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[123];
    }
toplevel_consts_91_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 122,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x05\x04\x01\x04\x01\x10\x01\x08\x01\x06\x01\x04\x01\x08\x01\x02\x01\x0a\x01\x0c\x01\x04\x01\x0c\x01\x02\x80\x0c\x02\x04\x80\x06\x01\x02\x01\x0a\x02\x0c\x01\x04\x80\x06\x01\x04\x01\x02\xff\x0a\x80\x02\xfb\x06\x80\x04\x08\x10\x01\x16\x02\x02\x01\x04\x01\x04\x01\x10\x01\x08\x02\x08\x01\x0e\x01\x10\x01\x02\x80\x06\x01\x04\x01\x08\x01\x0a\x01\x08\x80\x02\xfd\x06\x80\x02\x04\x14\x01\x0c\x01\x08\x01\x06\x01\x0e\xff\x0a\x03\x02\x80\x0a\x00\x06\x80\x04\x02\x14\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[139];
    }
toplevel_consts_91_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 138,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x05\x04\x01\x04\x01\x10\x01\x02\x01\x04\x11\x02\xef\x06\x01\x02\x01\x0a\x01\x02\x0e\x08\xf4\x02\x05\x0c\xfc\x02\x01\x0e\x01\x02\x80\x0c\x02\x04\x80\x02\x01\x06\x06\x08\xfd\x0e\x01\x04\x80\x02\x01\x0a\x01\x0a\x80\x02\x00\x06\x80\x02\x02\x12\x01\x10\x02\x04\x14\x02\xec\x02\x0d\x02\xf5\x02\x06\x02\xfb\x02\x05\x10\xfc\x08\x02\x08\x01\x0e\x01\x10\x01\x02\x80\x02\x01\x04\x03\x02\xfe\x0a\x01\x0a\x01\x08\x80\x02\x00\x06\x80\x02\x07\x02\xfb\x02\x03\x0e\xfd\x02\x03\x0c\xfe\x08\x01\x14\x01\x0a\x02\x02\x80\x0a\x00\x06\x80\x02\x02\x1a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[463];
    }
toplevel_consts_91_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 462,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x16\x1d\x1e\x23\x16\x24\x09\x13\x10\x12\x09\x0d\x13\x15\x09\x10\x1b\x22\x13\x3d\x26\x35\x13\x3d\x13\x17\x13\x17\x3b\x3d\x09\x10\x16\x20\x09\x19\x09\x19\x0d\x12\x14\x19\x14\x1e\x0d\x11\x10\x17\x0d\x26\x18\x20\x21\x25\x18\x26\x11\x15\x0d\x19\x14\x19\x14\x22\x14\x22\x14\x22\x11\x29\x15\x19\x15\x26\x21\x25\x15\x26\x15\x26\x15\x26\x18\x1f\x15\x2e\x19\x20\x19\x2e\x28\x2d\x19\x2e\x19\x2e\x19\x2e\x00\x00\x15\x1c\x15\x29\x24\x28\x15\x29\x15\x29\x15\x29\x00\x00\x00\x00\x14\x1b\x0d\x19\x0d\x19\x11\x19\x18\x1d\x18\x2a\x18\x2a\x18\x2a\x15\x2d\x19\x20\x19\x2d\x28\x2c\x19\x2d\x19\x2d\x19\x2d\x00\x00\x00\x00\x18\x1f\x11\x19\x11\x19\x15\x19\x15\x19\x11\x19\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x19\x00\x00\x00\x00\x00\x00\x0c\x13\x09\x30\x13\x1a\x1c\x20\x22\x29\x2b\x30\x13\x30\x0d\x30\x0d\x30\x0d\x30\x1d\x24\x15\x44\x15\x19\x15\x19\x32\x35\x36\x3a\x3c\x43\x32\x44\x09\x1d\x09\x1d\x0d\x11\x0d\x19\x18\x27\x11\x44\x18\x1f\x15\x44\x23\x27\x28\x2c\x35\x3a\x4c\x51\x23\x52\x23\x52\x19\x20\x19\x20\x20\x27\x19\x33\x19\x33\x19\x33\x27\x2b\x19\x24\x19\x1d\x1f\x24\x23\x28\x23\x44\x3e\x43\x23\x44\x23\x44\x23\x44\x19\x20\x19\x1d\x1e\x22\x24\x2c\x35\x3a\x19\x3b\x19\x3b\x11\x16\x11\x16\x00\x00\x14\x1b\x0d\x19\x0d\x19\x14\x1b\x11\x21\x15\x1c\x1d\x20\x15\x21\x15\x21\x11\x19\x11\x19\x11\x19\x11\x19\x11\x19\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x19\x00\x00\x00\x00\x00\x00\x0d\x1d\x14\x23\x11\x49\x27\x2b\x27\x34\x35\x3c\x3e\x42\x43\x48\x3e\x49\x27\x4a\x11\x49\x1f\x23\x1f\x28\x29\x30\x32\x36\x1f\x37\x15\x1c\x20\x26\x27\x2c\x2e\x35\x37\x3e\x27\x2e\x30\x37\x39\x48\x20\x49\x15\x49\x15\x49\x15\x49\x15\x49\x15\x49\x15\x49\x11\x16\x17\x1c\x11\x1d\x11\x1d\x11\x1d\x00\x00\x11\x16\x17\x1c\x11\x1d\x11\x1d\x11\x1d\x00\x00\x00\x00\x00\x00\x10\x17\x09\x30\x13\x1a\x1c\x20\x22\x29\x2b\x30\x13\x30\x0d\x30\x0d\x30\x0d\x30\x0d\x30\x0d\x30\x09\x30\x09\x30",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[88];
    }
toplevel_consts_91_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 87,
    },
    .ob_shash = -1,
    .ob_sval = "\xa0\x1a\x3b\x02\xbb\x04\x41\x19\x05\xc1\x00\x0b\x41\x0c\x04\xc1\x0b\x01\x41\x19\x05\xc1\x0c\x04\x41\x13\x07\xc1\x10\x02\x41\x19\x05\xc1\x12\x01\x41\x13\x07\xc1\x13\x03\x41\x19\x05\xc1\x18\x01\x41\x19\x05\xc1\x32\x22\x42\x15\x02\xc2\x15\x04\x42\x29\x05\xc2\x19\x06\x42\x24\x05\xc2\x24\x05\x42\x29\x05\xc2\x2d\x1e\x43\x10\x02\xc3\x10\x06\x43\x16\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_91_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "                ",
};
static struct PyCodeObject toplevel_consts_91 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_91_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_91_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_91_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_91_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 6,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 8,
    .co_firstlineno = 478,
    .co_code = & toplevel_consts_91_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_91_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_91_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_90_names_11._ascii.ob_base,
    .co_qualname = & toplevel_consts_90_names_11._ascii.ob_base,
    .co_linetable = & toplevel_consts_91_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_91_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_91_columntable.ob_base.ob_base,
    .co_nlocalsplus = 16,
    .co_nlocals = 16,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_91_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_93_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\xa9\x02\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[113];
    }
toplevel_consts_93_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 112,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x6c\x28\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_93_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_93_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_93_names_0 = {
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
    ._data = "execv",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_93_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_93_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_93_varnames_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_93_varnames_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_93_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_93_name = {
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
    ._data = "execl",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_93_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_93_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0a\x0b\x0f\x11\x15\x05\x16\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_93 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_93_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_93_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_93_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 536,
    .co_code = & toplevel_consts_93_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_93_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_93_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_93_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_93_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_93_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_94_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x64\x01\x19\x00\x7d\x02\x74\x00\x7c\x00\x7c\x01\x64\x02\x64\x01\x85\x02\x19\x00\x7c\x02\xa9\x03\x01\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[139];
    }
toplevel_consts_94_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 138,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x6c\x65\x28\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x65\x6e\x76\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_94_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = -1,
    },
    .ob_digit = { 1 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_94_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_94_consts_0._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            Py_None,
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
toplevel_consts_94_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_58._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_94_varnames_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_94_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
            & toplevel_consts_94_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_94_name = {
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
    ._data = "execle",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_94_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x05\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_94_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0f\x10\x12\x0b\x13\x05\x08\x05\x0b\x0c\x10\x12\x16\x17\x1a\x18\x1a\x17\x1a\x12\x1b\x1d\x20\x05\x21\x05\x21\x05\x21\x05\x21",
};
static struct PyCodeObject toplevel_consts_94 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_94_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_94_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_94_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 543,
    .co_code = & toplevel_consts_94_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_94_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_94_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_94_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_94_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_94_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[150];
    }
toplevel_consts_95_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 149,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x6c\x70\x28\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x0a\x20\x20\x20\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_95_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_95_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_95_names_0 = {
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
    ._data = "execvp",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_95_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_95_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_95_name = {
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
    ._data = "execlp",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_95_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0b\x0c\x10\x12\x16\x05\x17\x05\x17\x05\x17\x05\x17",
};
static struct PyCodeObject toplevel_consts_95 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_95_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_95_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_93_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 551,
    .co_code = & toplevel_consts_93_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_95_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_95_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_93_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_93_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_95_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[180];
    }
toplevel_consts_96_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 179,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x6c\x70\x65\x28\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x0a\x20\x20\x20\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x20\x61\x6e\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x65\x6e\x76\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x0a\x20\x20\x20\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_96_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_96_consts_0._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_96_names_0 = {
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
    ._data = "execvpe",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_96_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_96_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_96_name = {
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
    ._data = "execlpe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_96_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x06\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_96_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0f\x10\x12\x0b\x13\x05\x08\x05\x0c\x0d\x11\x13\x17\x18\x1b\x19\x1b\x18\x1b\x13\x1c\x1e\x21\x05\x22\x05\x22\x05\x22\x05\x22",
};
static struct PyCodeObject toplevel_consts_96 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_96_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_96_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_94_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 558,
    .co_code = & toplevel_consts_94_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_96_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_96_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_96_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_96_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_96_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[193];
    }
toplevel_consts_97_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 192,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x76\x70\x28\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x0a\x20\x20\x20\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x20\x20\x20\x20\x61\x72\x67\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x72\x20\x74\x75\x70\x6c\x65\x20\x6f\x66\x20\x73\x74\x72\x69\x6e\x67\x73\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_97_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_97_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_97_names_0 = {
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
    ._data = "_execvpe",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_97_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_97_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_97_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_97_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0d\x0e\x12\x14\x18\x05\x19\x05\x19\x05\x19\x05\x19",
};
static struct PyCodeObject toplevel_consts_97 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_97_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_97_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_93_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 567,
    .co_code = & toplevel_consts_93_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_95_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_95_names_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_97_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_97_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_97_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_93_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_98_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\x7c\x02\xa9\x03\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[223];
    }
toplevel_consts_98_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 222,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x65\x78\x65\x63\x76\x70\x65\x28\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x0a\x0a\x20\x20\x20\x20\x45\x78\x65\x63\x75\x74\x65\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x0a\x20\x20\x20\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x6c\x69\x73\x74\x20\x61\x72\x67\x73\x20\x61\x6e\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x65\x6e\x76\x2c\x20\x72\x65\x70\x6c\x61\x63\x69\x6e\x67\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x20\x20\x20\x20\x61\x72\x67\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x72\x20\x74\x75\x70\x6c\x65\x20\x6f\x66\x20\x73\x74\x72\x69\x6e\x67\x73\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_98_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_98_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_98_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_98_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0d\x0e\x12\x14\x18\x1a\x1d\x05\x1e\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_98 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_98_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_97_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_98_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 575,
    .co_code = & toplevel_consts_98_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_96_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_96_names_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_98_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_98_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_98_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_94_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_99 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_93_name._ascii.ob_base,
            & toplevel_consts_94_name._ascii.ob_base,
            & toplevel_consts_95_name._ascii.ob_base,
            & toplevel_consts_96_name._ascii.ob_base,
            & toplevel_consts_95_names_0._ascii.ob_base,
            & toplevel_consts_96_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_100_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x81\x0a\x74\x00\x7d\x03\x7c\x01\x7c\x02\x66\x02\x7d\x04\x6e\x07\x74\x01\x7d\x03\x7c\x01\x66\x01\x7d\x04\x74\x02\x7d\x02\x74\x03\x6a\x04\x7c\x00\xa9\x01\x72\x20\x7c\x03\x7c\x00\x67\x01\x7c\x04\xa2\x01\x52\x00\x8e\x00\x01\x00\x64\x00\x53\x00\x64\x00\x7d\x05\x74\x05\x7c\x02\xa9\x01\x7d\x06\x74\x06\x64\x01\x6b\x03\x72\x33\x74\x07\x7c\x00\xa9\x01\x7d\x00\x74\x08\x74\x07\x7c\x06\xa9\x02\x7d\x06\x7c\x06\x44\x00\x5d\x38\x7d\x07\x74\x03\x6a\x09\x7c\x07\x7c\x00\xa9\x02\x7d\x08\x09\x00\x7c\x03\x7c\x08\x67\x01\x7c\x04\xa2\x01\x52\x00\x8e\x00\x01\x00\x71\x35\x23\x00\x74\x0a\x74\x0b\x66\x02\x79\x58\x7d\x09\x7c\x09\x7d\x0a\x59\x00\x64\x00\x7d\x09\x7e\x09\x71\x35\x64\x00\x7d\x09\x7e\x09\x77\x01\x74\x0c\x79\x6a\x7d\x09\x7c\x09\x7d\x0a\x7c\x05\x80\x61\x7c\x09\x7d\x05\x59\x00\x64\x00\x7d\x09\x7e\x09\x71\x35\x64\x00\x7d\x09\x7e\x09\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x81\x72\x7c\x05\x82\x01\x7c\x0a\x82\x01",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_100_consts = {
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
            & toplevel_consts_13._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_100_names_2 = {
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
toplevel_consts_100_names_8 = {
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
    ._data = "map",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_100_names_10 = {
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
    ._data = "FileNotFoundError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_100_names_11 = {
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
    ._data = "NotADirectoryError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_100_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_58._ascii.ob_base,
            & toplevel_consts_93_names_0._ascii.ob_base,
            & toplevel_consts_100_names_2._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_86_varnames_15._ascii.ob_base,
            & toplevel_consts_4_15._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_100_names_8._ascii.ob_base,
            & toplevel_consts_86_names_10._ascii.ob_base,
            & toplevel_consts_100_names_10._ascii.ob_base,
            & toplevel_consts_100_names_11._ascii.ob_base,
            & toplevel_consts_80_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_100_varnames_3 = {
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
    ._data = "exec_func",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_100_varnames_4 = {
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
    ._data = "argrest",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_100_varnames_5 = {
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
    ._data = "saved_exc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_100_varnames_6 = {
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
    ._data = "path_list",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_100_varnames_8 = {
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
toplevel_consts_100_varnames_9 = {
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
    ._data = "e",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_100_varnames_10 = {
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
    ._data = "last_exc",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_100_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
            & toplevel_consts_94_varnames_2._ascii.ob_base,
            & toplevel_consts_100_varnames_3._ascii.ob_base,
            & toplevel_consts_100_varnames_4._ascii.ob_base,
            & toplevel_consts_100_varnames_5._ascii.ob_base,
            & toplevel_consts_100_varnames_6._ascii.ob_base,
            & toplevel_consts_6_names_3._ascii.ob_base,
            & toplevel_consts_100_varnames_8._ascii.ob_base,
            & toplevel_consts_100_varnames_9._ascii.ob_base,
            & toplevel_consts_100_varnames_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_100_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x04\x01\x0a\x01\x04\x02\x06\x01\x04\x01\x0a\x02\x10\x01\x04\x01\x04\x01\x08\x01\x08\x01\x08\x01\x0a\x01\x08\x01\x0c\x01\x02\x01\x12\x01\x02\x80\x0a\x01\x0e\x01\x08\x80\x06\x01\x04\x01\x04\x01\x04\x01\x12\x80\x02\xfd\x06\x80\x04\x04\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_100_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x02\x06\x04\xfb\x0a\x01\x04\x02\x06\x01\x04\x01\x08\x02\x02\x02\x10\xff\x04\x01\x04\x01\x08\x01\x06\x01\x02\x02\x08\xff\x0a\x01\x02\x01\x04\x09\x02\xf7\x0c\x01\x02\x08\x12\xfa\x02\x80\x06\x01\x12\x01\x08\x80\x02\x01\x04\x03\x04\xfe\x02\x01\x06\x01\x12\x80\x02\x00\x06\x80\x02\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_100_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0b\x05\x16\x15\x1b\x09\x12\x14\x18\x1a\x1d\x13\x1e\x09\x10\x09\x10\x15\x1a\x09\x12\x14\x18\x13\x1a\x09\x10\x0f\x16\x09\x0c\x08\x0c\x08\x14\x15\x19\x08\x1a\x05\x0f\x09\x12\x13\x17\x09\x22\x1a\x21\x09\x22\x09\x22\x09\x22\x09\x22\x09\x0f\x09\x0f\x11\x15\x05\x0e\x11\x1e\x1f\x22\x11\x23\x05\x0e\x08\x0c\x10\x14\x08\x14\x05\x2d\x10\x18\x19\x1d\x10\x1e\x09\x0d\x15\x18\x19\x21\x23\x2c\x15\x2d\x09\x12\x10\x19\x05\x1e\x05\x1e\x09\x0c\x14\x18\x14\x1d\x1e\x21\x23\x27\x14\x28\x09\x11\x09\x1e\x0d\x16\x17\x1f\x0d\x2a\x22\x29\x0d\x2a\x0d\x2a\x0d\x2a\x0d\x2a\x0d\x2a\x00\x00\x11\x22\x24\x36\x10\x37\x09\x19\x09\x19\x18\x19\x0d\x15\x0d\x15\x0d\x15\x0d\x15\x0d\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x10\x17\x09\x1e\x09\x1e\x18\x19\x0d\x15\x10\x19\x0d\x1e\x1d\x1e\x11\x1a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x1e\x00\x00\x00\x00\x00\x00\x08\x11\x05\x18\x0f\x18\x09\x18\x0b\x13\x05\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[36];
    }
toplevel_consts_100_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 35,
    },
    .ob_shash = -1,
    .ob_sval = "\xbe\x08\x41\x07\x02\xc1\x07\x06\x41\x2b\x05\xc1\x0d\x02\x41\x14\x05\xc1\x14\x07\x41\x2b\x05\xc1\x1b\x06\x41\x26\x05\xc1\x26\x05\x41\x2b\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_100_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 11,
    },
    .ob_shash = -1,
    .ob_sval = "           ",
};
static struct PyCodeObject toplevel_consts_100 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_100_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_100_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_100_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_100_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 586,
    .co_code = & toplevel_consts_100_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_100_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_100_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_97_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_97_names_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_100_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_100_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_100_columntable.ob_base.ob_base,
    .co_nlocalsplus = 11,
    .co_nlocals = 11,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_100_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[217];
    }
toplevel_consts_101_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 216,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x64\x02\x6c\x00\x7d\x01\x7c\x00\x80\x09\x74\x01\x7d\x00\x7c\x01\xa0\x02\xa8\x00\xa9\x00\x35\x00\x01\x00\x7c\x01\xa0\x03\x64\x03\x74\x04\xa8\x02\xa9\x02\x01\x00\x09\x00\x7c\x00\xa0\x05\x64\x04\xa8\x01\xa9\x01\x7d\x02\x6e\x0c\x23\x00\x74\x06\x79\x26\x01\x00\x64\x02\x7d\x02\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x07\x72\x51\x09\x00\x7c\x00\x64\x05\x19\x00\x7d\x03\x6e\x0c\x23\x00\x74\x08\x74\x06\x66\x02\x79\x3a\x01\x00\x59\x00\x6e\x0c\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x81\x44\x74\x09\x64\x06\xa9\x01\x82\x01\x7c\x03\x7d\x02\x7c\x02\x81\x51\x74\x0a\x7c\x02\x74\x0b\xa9\x02\x72\x51\x74\x0c\x7c\x02\xa9\x01\x7d\x02\x64\x02\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x5e\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x02\x80\x66\x74\x0d\x7d\x02\x7c\x02\xa0\x0e\x74\x0f\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[244];
    }
toplevel_consts_101_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 243,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x20\x6f\x66\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x69\x65\x73\x20\x74\x68\x61\x74\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x6e\x61\x6d\x65\x64\x20\x65\x78\x65\x63\x75\x74\x61\x62\x6c\x65\x20\x28\x73\x69\x6d\x69\x6c\x61\x72\x20\x74\x6f\x20\x61\x20\x73\x68\x65\x6c\x6c\x29\x20\x77\x68\x65\x6e\x20\x6c\x61\x75\x6e\x63\x68\x69\x6e\x67\x20\x61\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20\x2a\x65\x6e\x76\x2a\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x6e\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x20\x64\x69\x63\x74\x20\x6f\x72\x20\x4e\x6f\x6e\x65\x2e\x20\x20\x49\x66\x20\x2a\x65\x6e\x76\x2a\x20\x69\x73\x20\x4e\x6f\x6e\x65\x2c\x0a\x20\x20\x20\x20\x6f\x73\x2e\x65\x6e\x76\x69\x72\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x75\x73\x65\x64\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_101_consts_3 = {
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
    ._data = "ignore",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_101_consts_4 = {
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
    ._data = "PATH",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_101_consts_5 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "PATH",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[43];
    }
toplevel_consts_101_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 42,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "env cannot contain 'PATH' and b'PATH' keys",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_101_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_101_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_101_consts_3._ascii.ob_base,
            & toplevel_consts_101_consts_4._ascii.ob_base,
            & toplevel_consts_101_consts_5.ob_base.ob_base,
            & toplevel_consts_101_consts_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_101_names_0 = {
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
    ._data = "warnings",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_101_names_2 = {
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
    ._data = "catch_warnings",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_101_names_3 = {
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
    ._data = "simplefilter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_101_names_4 = {
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
    ._data = "BytesWarning",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_101_names_5 = {
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
        uint8_t _data[10];
    }
toplevel_consts_101_names_6 = {
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
        uint8_t _data[23];
    }
toplevel_consts_101_names_7 = {
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
    ._data = "supports_bytes_environ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_101_names_8 = {
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
    ._data = "KeyError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_101_names_9 = {
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
    ._data = "ValueError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_101_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_101_names_0._ascii.ob_base,
            & toplevel_consts_100_names_2._ascii.ob_base,
            & toplevel_consts_101_names_2._ascii.ob_base,
            & toplevel_consts_101_names_3._ascii.ob_base,
            & toplevel_consts_101_names_4._ascii.ob_base,
            & toplevel_consts_101_names_5._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_101_names_7._ascii.ob_base,
            & toplevel_consts_101_names_8._ascii.ob_base,
            & toplevel_consts_101_names_9._ascii.ob_base,
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_4_14._ascii.ob_base,
            & toplevel_consts_4_6._ascii.ob_base,
            & toplevel_consts_80_names_1._ascii.ob_base,
            & toplevel_consts_4_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_101_varnames_3 = {
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
    ._data = "path_listb",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_101_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_94_varnames_2._ascii.ob_base,
            & toplevel_consts_101_names_0._ascii.ob_base,
            & toplevel_consts_100_varnames_6._ascii.ob_base,
            & toplevel_consts_101_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_101_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x04\x02\x04\x01\x0c\x04\x0e\x01\x02\x02\x0e\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x04\x03\x02\x01\x0a\x01\x02\x80\x0a\x01\x04\x01\x02\xff\x06\x80\x04\x03\x02\x01\x02\x01\x04\xff\x04\x02\x0e\x02\x08\x01\x14\xec\x06\x80\x08\x00\x04\x16\x04\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_101_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x02\x02\x06\x01\x08\x04\x04\x14\x0e\xed\x02\x05\x0e\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x02\x02\x02\x0c\x02\xfd\x0a\xf9\x02\x80\x06\x01\x0a\x01\x06\x80\x02\x02\x02\x02\x02\xff\x06\x01\x04\x01\x02\x02\x02\x01\x08\xff\x1e\x01\x06\x80\x08\x00\x02\x02\x06\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[217];
    }
toplevel_consts_101_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 216,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x14\x05\x14\x05\x14\x05\x14\x08\x0b\x05\x16\x0f\x16\x09\x0c\x0a\x12\x0a\x23\x0a\x23\x0a\x23\x05\x30\x05\x30\x09\x11\x09\x36\x1f\x27\x29\x35\x09\x36\x09\x36\x09\x36\x09\x1d\x19\x1c\x19\x28\x21\x27\x19\x28\x19\x28\x0d\x16\x0d\x16\x00\x00\x10\x19\x09\x1d\x09\x1d\x19\x1d\x0d\x16\x0d\x16\x0d\x16\x09\x1d\x00\x00\x00\x00\x00\x00\x0c\x22\x09\x30\x0d\x27\x1e\x21\x22\x29\x1e\x2a\x11\x1b\x11\x1b\x00\x00\x15\x1d\x1f\x28\x14\x29\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x14\x1d\x11\x46\x1b\x25\x19\x45\x1b\x46\x15\x46\x1d\x27\x11\x1a\x10\x19\x0d\x30\x2a\x34\x35\x3e\x40\x45\x2a\x46\x0d\x30\x1d\x25\x26\x2f\x1d\x30\x11\x1a\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x05\x30\x00\x00\x00\x00\x00\x00\x05\x30\x05\x30\x05\x30\x05\x30\x08\x11\x05\x1c\x15\x1c\x09\x12\x0c\x15\x0c\x24\x1c\x23\x0c\x24\x0c\x24\x05\x24",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[72];
    }
toplevel_consts_101_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 71,
    },
    .ob_shash = -1,
    .ob_sval = "\x8e\x08\x41\x17\x03\x97\x06\x1e\x02\x9d\x01\x41\x17\x03\x9e\x06\x27\x05\xa4\x02\x41\x17\x03\xa6\x01\x27\x05\xa7\x05\x41\x17\x03\xad\x04\x32\x02\xb1\x01\x41\x17\x03\xb2\x06\x3b\x05\xb8\x02\x41\x17\x03\xba\x01\x3b\x05\xbb\x16\x41\x17\x03\xc1\x17\x04\x41\x1b\x07\xc1\x1e\x01\x41\x1b\x07",
};
static struct PyCodeObject toplevel_consts_101 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_101_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_101_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_101_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_101_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 618,
    .co_code = & toplevel_consts_101_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_101_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_15._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_15._ascii.ob_base,
    .co_linetable = & toplevel_consts_101_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_101_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_101_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_101_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_102_0 = {
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
    ._data = "MutableMapping",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_102_1 = {
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
    ._data = "Mapping",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_102 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_102_0._ascii.ob_base,
            & toplevel_consts_102_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_103_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x84\x00\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x84\x00\x5a\x08\x64\x07\x84\x00\x5a\x09\x64\x08\x84\x00\x5a\x0a\x64\x09\x84\x00\x5a\x0b\x64\x0a\x84\x00\x5a\x0c\x64\x0b\x84\x00\x5a\x0d\x64\x0c\x84\x00\x5a\x0e\x64\x0d\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_consts_0 = {
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
    ._data = "_Environ",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_103_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x7c\x00\x5f\x00\x7c\x03\x7c\x00\x5f\x01\x7c\x04\x7c\x00\x5f\x02\x7c\x05\x7c\x00\x5f\x03\x7c\x01\x7c\x00\x5f\x04\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_103_consts_1_names_0 = {
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
    ._data = "encodekey",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_103_consts_1_names_1 = {
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
    ._data = "decodekey",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_103_consts_1_names_2 = {
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
    ._data = "encodevalue",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_103_consts_1_names_3 = {
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
    ._data = "decodevalue",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_103_consts_1_names_4 = {
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
    ._data = "_data",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_103_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_103_consts_1_varnames_0 = {
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
    ._data = "self",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_103_consts_1_varnames_1 = {
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
    ._data = "data",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_103_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_consts_1_name = {
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
    ._data = "__init__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_103_consts_1_qualname = {
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
    ._data = "_Environ.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x06\x01\x06\x01\x06\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_103_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1a\x23\x09\x0d\x09\x17\x1a\x23\x09\x0d\x09\x17\x1c\x27\x09\x0d\x09\x19\x1c\x27\x09\x0d\x09\x19\x16\x1a\x09\x0d\x09\x13\x09\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_103_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 6,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 666,
    .co_code = & toplevel_consts_103_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_80_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_103_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x6a\x00\x7c\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x19\x00\x7d\x02\x6e\x0d\x23\x00\x74\x02\x79\x15\x01\x00\x74\x02\x7c\x01\xa9\x01\x64\x00\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\xa0\x03\x7c\x02\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_103_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_101_names_8._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_103_consts_2_varnames_1 = {
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
toplevel_consts_103_consts_2_varnames_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_103_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_103_consts_2_name = {
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
    ._data = "__getitem__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_103_consts_2_qualname = {
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
    ._data = "_Environ.__getitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_103_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x14\x01\x02\x80\x06\x01\x0a\x02\x02\xfe\x06\x80\x0c\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_103_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x14\xfd\x02\x80\x02\x01\x10\x02\x06\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_103_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x2a\x15\x19\x15\x1f\x20\x24\x20\x33\x2f\x32\x20\x33\x20\x33\x15\x34\x0d\x12\x0d\x12\x00\x00\x10\x18\x09\x2a\x09\x2a\x13\x1b\x1c\x1f\x13\x20\x26\x2a\x0d\x2a\x09\x2a\x00\x00\x00\x00\x00\x00\x10\x14\x10\x27\x21\x26\x10\x27\x10\x27\x09\x27",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_103_consts_2_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x09\x0c\x00\x8c\x0a\x16\x03",
};
static struct PyCodeObject toplevel_consts_103_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_103_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 673,
    .co_code = & toplevel_consts_103_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_103_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x7d\x01\x7c\x00\xa0\x01\x7c\x02\xa8\x01\xa9\x01\x7d\x02\x74\x02\x7c\x01\x7c\x02\xa9\x02\x01\x00\x7c\x02\x7c\x00\x6a\x03\x7c\x01\x3c\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_103_consts_3_names_2 = {
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
    ._data = "putenv",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_103_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_103_consts_3_name = {
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
    ._data = "__setitem__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_103_consts_3_qualname = {
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
    ._data = "_Environ.__setitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_103_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0c\x01\x0a\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_103_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x13\x0f\x22\x1e\x21\x0f\x22\x0f\x22\x09\x0c\x11\x15\x11\x28\x22\x27\x11\x28\x11\x28\x09\x0e\x09\x0f\x10\x13\x15\x1a\x09\x1b\x09\x1b\x1b\x20\x09\x0d\x09\x13\x14\x17\x09\x18\x09\x18\x09\x18",
};
static struct PyCodeObject toplevel_consts_103_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 681,
    .co_code = & toplevel_consts_103_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_103_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x7d\x02\x74\x01\x7c\x02\xa9\x01\x01\x00\x09\x00\x7c\x00\x6a\x02\x7c\x02\x3d\x00\x64\x00\x53\x00\x23\x00\x74\x03\x79\x1b\x01\x00\x74\x03\x7c\x01\xa9\x01\x64\x00\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_consts_4_names_1 = {
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
    ._data = "unsetenv",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_103_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_101_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_103_consts_4_varnames_2 = {
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
    ._data = "encodedkey",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_103_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_4_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_103_consts_4_name = {
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
    ._data = "__delitem__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_103_consts_4_qualname = {
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
    ._data = "_Environ.__delitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_103_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x08\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x0a\x02\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_103_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x08\x01\x02\x05\x0c\xfd\x02\x80\x02\x01\x10\x02\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_103_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x1a\x16\x29\x25\x28\x16\x29\x16\x29\x09\x13\x09\x11\x12\x1c\x09\x1d\x09\x1d\x09\x2a\x11\x15\x11\x1b\x1c\x26\x11\x27\x11\x27\x11\x27\x00\x00\x10\x18\x09\x2a\x09\x2a\x13\x1b\x1c\x1f\x13\x20\x26\x2a\x0d\x2a\x09\x2a\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_103_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x8c\x04\x12\x00\x92\x0a\x1c\x03",
};
static struct PyCodeObject toplevel_consts_103_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_103_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 687,
    .co_code = & toplevel_consts_103_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_103_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x7d\x01\x7c\x01\x44\x00\x5d\x0a\x7d\x02\x7c\x00\xa0\x02\x7c\x02\xa8\x01\xa9\x01\x56\x00\x97\x01\x01\x00\x71\x09\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_103_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_103_consts_5_varnames_1 = {
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
    ._data = "keys",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_103_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_5_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_consts_5_name = {
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
    ._data = "__iter__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_103_consts_5_qualname = {
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
    ._data = "_Environ.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x08\x01\x12\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_103_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x02\x01\x04\x01\x02\xff\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_103_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x14\x15\x19\x15\x1f\x10\x20\x09\x0d\x14\x18\x09\x26\x09\x26\x0d\x10\x13\x17\x13\x26\x22\x25\x13\x26\x13\x26\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x09\x26\x09\x26",
};
static struct PyCodeObject toplevel_consts_103_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 696,
    .co_code = & toplevel_consts_103_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_103_consts_6_names_0 = {
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
    ._data = "len",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_103_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
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
toplevel_consts_103_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_103_consts_6_name = {
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
    ._data = "__len__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_103_consts_6_qualname = {
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
    ._data = "_Environ.__len__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x13\x14\x18\x14\x1e\x10\x1f\x09\x1f",
};
static struct PyCodeObject toplevel_consts_103_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 702,
    .co_code = & toplevel_consts_103_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_103_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x64\x01\xa0\x00\x88\x00\x66\x01\x64\x02\x84\x08\x89\x00\x6a\x01\xa0\x02\xa8\x00\xa9\x00\x44\x00\xa9\x01\xa8\x01\xa9\x01\x7d\x01\x64\x03\x7c\x01\x9b\x00\x64\x04\x9d\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_103_consts_7_consts_1 = {
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
    ._data = ", ",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_103_consts_7_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x15\x5c\x02\x7d\x01\x7d\x02\x89\x03\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x9b\x02\x64\x00\x89\x03\xa0\x01\x7c\x02\xa8\x01\xa9\x01\x9b\x02\x9d\x03\x56\x00\x97\x01\x01\x00\x71\x04\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_103_consts_7_consts_2_consts_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_103_consts_7_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_7_consts_2_consts_0._ascii.ob_base,
            Py_None,
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
toplevel_consts_103_consts_7_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_3._ascii.ob_base,
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
toplevel_consts_103_consts_7_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_103_consts_7_consts_2_name = {
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
    ._data = "<genexpr>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[37];
    }
toplevel_consts_103_consts_7_consts_2_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 36,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_Environ.__repr__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_103_consts_7_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x06\x00\x06\x02\x1c\xff\x0c\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_7_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x04\x03\x06\xff\x1c\xff\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_103_consts_7_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x24\x0a\x24\x0a\x11\x1b\x11\x14\x16\x1b\x10\x14\x10\x23\x1f\x22\x10\x23\x10\x23\x0d\x44\x0d\x44\x29\x2d\x29\x40\x3a\x3f\x29\x40\x29\x40\x0d\x44\x0d\x44\x24\x0a\x24\x0a\x24\x0a\x24\x0a\x24\x0a\x24\x0a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_103_consts_7_consts_2_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_103_consts_7_consts_2_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x20\x80",
};
static struct PyCodeObject toplevel_consts_103_consts_7_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_103_consts_7_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_7_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_7_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 706,
    .co_code = & toplevel_consts_103_consts_7_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_7_consts_2_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_103_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_7_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_7_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_7_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_7_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_7_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_103_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_103_consts_7_consts_3 = {
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
    ._data = "environ({",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_103_consts_7_consts_4 = {
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
    ._data = "})",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_103_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_103_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_103_consts_7_consts_2.ob_base,
            & toplevel_consts_103_consts_7_consts_3._ascii.ob_base,
            & toplevel_consts_103_consts_7_consts_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_103_consts_7_names_2 = {
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
    ._data = "items",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_103_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_86_names_10._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_103_consts_7_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_103_consts_7_varnames_1 = {
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
    ._data = "formatted_items",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_103_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_7_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_consts_7_name = {
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
    ._data = "__repr__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_103_consts_7_qualname = {
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
    ._data = "_Environ.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0c\x01\x0a\x02\x0a\xfe\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_103_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x01\x0a\x03\x0a\xff\x08\x01\x02\xfd\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_103_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x1b\x1f\x1b\x0a\x24\x0a\x24\x0a\x24\x0a\x24\x0a\x1f\x23\x1f\x29\x1f\x31\x1f\x31\x1f\x31\x24\x0a\x24\x0a\x1b\x0a\x1b\x0a\x09\x18\x10\x31\x1d\x2c\x10\x31\x10\x31\x10\x31\x09\x31",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_103_consts_7_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "` ",
};
static struct PyCodeObject toplevel_consts_103_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_103_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 705,
    .co_code = & toplevel_consts_103_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_103_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_103_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_103_consts_8_names_0 = {
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
    ._data = "dict",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_103_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_103_consts_8_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_103_consts_8_name = {
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
    ._data = "copy",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_103_consts_8_qualname = {
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
    ._data = "_Environ.copy",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_103_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_103_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x15\x19\x10\x1a\x09\x1a",
};
static struct PyCodeObject toplevel_consts_103_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 712,
    .co_code = & toplevel_consts_103_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_103_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x76\x01\x72\x09\x7c\x02\x7c\x00\x7c\x01\x3c\x00\x7c\x00\x7c\x01\x19\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_103_consts_9_name = {
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
    ._data = "setdefault",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_103_consts_9_qualname = {
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
    ._data = "_Environ.setdefault",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_103_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x08\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_103_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_103_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x17\x1b\x0c\x1b\x09\x1e\x19\x1e\x0d\x11\x12\x15\x0d\x16\x10\x14\x15\x18\x10\x19\x09\x19",
};
static struct PyCodeObject toplevel_consts_103_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 715,
    .co_code = & toplevel_consts_103_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_103_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x01\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_103_consts_10_names_0 = {
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
    ._data = "update",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_103_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_103_consts_10_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_103_consts_10_varnames_1 = {
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
    ._data = "other",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_103_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_10_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_103_consts_10_name = {
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
    ._data = "__ior__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_103_consts_10_qualname = {
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
    ._data = "_Environ.__ior__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_103_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_103_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x1b\x15\x1a\x09\x1b\x09\x1b\x09\x1b\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_103_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 720,
    .co_code = & toplevel_consts_103_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_103_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x7d\x02\x7c\x02\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x01\x00\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_103_consts_11_names_2 = {
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
    ._data = "NotImplemented",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_103_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_102_1._ascii.ob_base,
            & toplevel_consts_103_consts_11_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_8_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_10_names_0._ascii.ob_base,
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
toplevel_consts_103_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_103_consts_10_varnames_1._ascii.ob_base,
            & toplevel_consts_82_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_103_consts_11_name = {
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
    ._data = "__or__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_103_consts_11_qualname = {
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
    ._data = "_Environ.__or__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x08\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_103_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x06\x01\x08\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_103_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x29\x10\x2a\x09\x22\x14\x22\x0d\x22\x0f\x13\x14\x18\x0f\x19\x09\x0c\x09\x0c\x09\x1a\x14\x19\x09\x1a\x09\x1a\x09\x1a\x10\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_103_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 724,
    .co_code = & toplevel_consts_103_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_103_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x01\xa9\x01\x7d\x02\x7c\x02\xa0\x04\x7c\x00\xa8\x01\xa9\x01\x01\x00\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_103_consts_12_name = {
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
    ._data = "__ror__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_103_consts_12_qualname = {
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
    ._data = "_Environ.__ror__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_103_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x29\x10\x2a\x09\x22\x14\x22\x0d\x22\x0f\x13\x14\x19\x0f\x1a\x09\x0c\x09\x0c\x09\x19\x14\x18\x09\x19\x09\x19\x09\x19\x10\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_103_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 731,
    .co_code = & toplevel_consts_103_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_103_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_103_consts_0._ascii.ob_base,
            & toplevel_consts_103_consts_1.ob_base,
            & toplevel_consts_103_consts_2.ob_base,
            & toplevel_consts_103_consts_3.ob_base,
            & toplevel_consts_103_consts_4.ob_base,
            & toplevel_consts_103_consts_5.ob_base,
            & toplevel_consts_103_consts_6.ob_base,
            & toplevel_consts_103_consts_7.ob_base,
            & toplevel_consts_103_consts_8.ob_base,
            & toplevel_consts_103_consts_9.ob_base,
            & toplevel_consts_103_consts_10.ob_base,
            & toplevel_consts_103_consts_11.ob_base,
            & toplevel_consts_103_consts_12.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_103_names_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_103_names_1 = {
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
        uint8_t _data[13];
    }
toplevel_consts_103_names_2 = {
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
    ._data = "__qualname__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_103_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_103_names_1._ascii.ob_base,
            & toplevel_consts_103_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_name._ascii.ob_base,
            & toplevel_consts_103_consts_2_name._ascii.ob_base,
            & toplevel_consts_103_consts_3_name._ascii.ob_base,
            & toplevel_consts_103_consts_4_name._ascii.ob_base,
            & toplevel_consts_103_consts_5_name._ascii.ob_base,
            & toplevel_consts_103_consts_6_name._ascii.ob_base,
            & toplevel_consts_103_consts_7_name._ascii.ob_base,
            & toplevel_consts_103_consts_8_name._ascii.ob_base,
            & toplevel_consts_103_consts_9_name._ascii.ob_base,
            & toplevel_consts_103_consts_10_name._ascii.ob_base,
            & toplevel_consts_103_consts_11_name._ascii.ob_base,
            & toplevel_consts_103_consts_12_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_103_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x01\x06\x07\x06\x08\x06\x06\x06\x09\x06\x06\x06\x03\x06\x07\x06\x03\x06\x05\x06\x04\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_103_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x06\x06\x08\x06\x06\x06\x09\x06\x06\x06\x03\x06\x07\x06\x03\x06\x05\x06\x04\x06\x07\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_103_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x1a\x05\x1a\x05\x1a\x05\x27\x05\x27\x05\x27\x05\x20\x05\x20\x05\x20\x05\x2a\x05\x2a\x05\x2a\x05\x26\x05\x26\x05\x26\x05\x1f\x05\x1f\x05\x1f\x05\x31\x05\x31\x05\x31\x05\x1a\x05\x1a\x05\x1a\x05\x19\x05\x19\x05\x19\x05\x14\x05\x14\x05\x14\x05\x13\x05\x13\x05\x13\x05\x13\x05\x13\x05\x13\x05\x13\x05\x13",
};
static struct PyCodeObject toplevel_consts_103 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_103_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_103_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 665,
    .co_code = & toplevel_consts_103_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_103_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_103_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_103_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_103_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_consts_105_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x06\x87\x07\x97\x00\x74\x00\x64\x01\x6b\x02\x72\x26\x64\x02\x84\x00\x7d\x00\x7c\x00\x8a\x06\x74\x01\x7d\x01\x88\x06\x66\x01\x64\x03\x84\x08\x7d\x02\x69\x00\x7d\x03\x74\x02\xa0\x03\xa8\x00\xa9\x00\x44\x00\x5d\x0a\x5c\x02\x7d\x04\x7d\x05\x7c\x05\x7c\x03\x7c\x02\x7c\x04\xa9\x01\x3c\x00\x71\x1a\x6e\x12\x74\x04\x6a\x05\xa9\x00\x8a\x07\x88\x07\x66\x01\x64\x04\x84\x08\x8a\x06\x88\x07\x66\x01\x64\x05\x84\x08\x7d\x01\x89\x06\x7d\x02\x74\x02\x7d\x03\x74\x06\x7c\x03\x7c\x02\x7c\x01\x89\x06\x7c\x01\xa9\x05\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_105_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x73\x0f\x74\x02\x64\x01\x74\x03\x7c\x00\xa9\x01\x6a\x04\x7a\x06\xa9\x01\x82\x01\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_105_consts_2_consts_1 = {
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
    ._data = "str expected, not %s",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_105_consts_2_consts = {
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
            & toplevel_consts_105_consts_2_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_105_consts_2_names_3 = {
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
    ._data = "type",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_105_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_103_names_0._ascii.ob_base,
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
toplevel_consts_105_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_105_consts_2_name = {
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
    ._data = "check_str",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_105_consts_2_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 33,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_createenviron.<locals>.check_str",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_105_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_105_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_105_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x1e\x1f\x24\x26\x29\x14\x2a\x0d\x4f\x17\x20\x21\x37\x3a\x3e\x3f\x44\x3a\x45\x3a\x4e\x21\x4e\x17\x4f\x11\x4f\x14\x19\x0d\x19",
};
static struct PyCodeObject toplevel_consts_105_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_105_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_105_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 741,
    .co_code = & toplevel_consts_105_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_105_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_105_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_105_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_105_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x89\x01\x7c\x00\xa9\x01\xa0\x00\xa8\x00\xa9\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_105_consts_3_names_0 = {
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
    ._data = "upper",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_105_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_105_consts_3_names_0._ascii.ob_base,
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
toplevel_consts_105_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_105_consts_3_freevars_0 = {
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
    ._data = "encode",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_105_consts_3_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_105_consts_3_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 33,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_createenviron.<locals>.encodekey",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_105_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_105_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x1a\x1b\x1e\x14\x1f\x14\x27\x14\x27\x14\x27\x0d\x27",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_105_consts_3_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_105_consts_3_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x80",
};
static struct PyCodeObject toplevel_consts_105_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_105_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 747,
    .co_code = & toplevel_consts_105_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_consts_3_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_105_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_105_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_105_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_105_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_105_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_105_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x73\x10\x74\x02\x64\x01\x74\x03\x7c\x00\xa9\x01\x6a\x04\x7a\x06\xa9\x01\x82\x01\x7c\x00\xa0\x05\x89\x01\x64\x02\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_105_consts_4_consts_2 = {
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
    ._data = "surrogateescape",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_105_consts_4_consts = {
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
            & toplevel_consts_105_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_105_consts_4_consts_2._ascii.ob_base,
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
toplevel_consts_105_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_105_consts_4_freevars_0 = {
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
toplevel_consts_105_consts_4_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_105_consts_4_qualname = {
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
    ._data = "_createenviron.<locals>.encode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_105_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x12\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_105_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x01\x14\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_105_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x1e\x1f\x24\x26\x29\x14\x2a\x0d\x4f\x17\x20\x21\x37\x3a\x3e\x3f\x44\x3a\x45\x3a\x4e\x21\x4e\x17\x4f\x11\x4f\x14\x19\x14\x3d\x21\x29\x2b\x3c\x14\x3d\x14\x3d\x0d\x3d",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_105_consts_4_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_105_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_105_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_105_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 755,
    .co_code = & toplevel_consts_105_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_consts_4_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_105_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_105_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_105_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_105_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_105_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x7c\x00\xa0\x00\x89\x01\x64\x01\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_105_consts_5_consts = {
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
            & toplevel_consts_105_consts_4_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_105_consts_5_names_0 = {
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
    ._data = "decode",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_105_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_105_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_105_consts_5_qualname = {
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
    ._data = "_createenviron.<locals>.decode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_105_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x19\x14\x3d\x21\x29\x2b\x3c\x14\x3d\x14\x3d\x0d\x3d",
};
static struct PyCodeObject toplevel_consts_105_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_105_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_105_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 759,
    .co_code = & toplevel_consts_105_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_consts_4_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_105_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_105_consts_5_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_105_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_105_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_105_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_105_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_consts_105_consts_2.ob_base,
            & toplevel_consts_105_consts_3.ob_base,
            & toplevel_consts_105_consts_4.ob_base,
            & toplevel_consts_105_consts_5.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_105_names_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 21,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "getfilesystemencoding",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_105_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_100_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_7_names_2._ascii.ob_base,
            & toplevel_consts_85_names_0._ascii.ob_base,
            & toplevel_consts_105_names_5._ascii.ob_base,
            & toplevel_consts_103_consts_0._ascii.ob_base,
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
toplevel_consts_105_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_105_consts_2_name._ascii.ob_base,
            & toplevel_consts_105_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
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
toplevel_consts_105_cellvars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_105_name = {
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
    ._data = "_createenviron",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_105_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x06\x02\x04\x04\x04\x01\x0a\x01\x04\x02\x12\x01\x0e\x01\x02\xff\x08\x04\x0a\x01\x0a\x04\x04\x02\x04\x01\x04\x01\x04\x01\x04\x01\x04\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_105_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x06\x01\x02\x17\x06\xee\x04\x01\x04\x01\x0a\x02\x04\x01\x08\x01\x04\x01\x06\xff\x10\x01\x08\x03\x0a\x04\x0a\x02\x04\x01\x04\x01\x04\x01\x04\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_consts_105_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x08\x0c\x10\x14\x08\x14\x05\x17\x09\x19\x09\x19\x09\x19\x12\x1b\x09\x0f\x12\x15\x09\x0f\x09\x27\x09\x27\x09\x27\x09\x27\x09\x27\x10\x12\x09\x0d\x1b\x22\x1b\x2a\x1b\x2a\x1b\x2a\x09\x29\x09\x29\x0d\x17\x0d\x10\x12\x17\x24\x29\x0d\x11\x12\x1b\x1c\x1f\x12\x20\x0d\x21\x0d\x21\x09\x29\x14\x17\x14\x2d\x14\x2f\x09\x11\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x09\x3d\x15\x1b\x09\x12\x10\x17\x09\x0d\x0c\x14\x15\x19\x09\x12\x14\x1a\x09\x0f\x11\x17\x0c\x18\x05\x18",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_105_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_105_consts_2_name._ascii.ob_base,
            & toplevel_consts_105_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_103_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_103_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_105_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "      @@",
};
static struct PyCodeObject toplevel_consts_105 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_105_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_105_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 738,
    .co_code = & toplevel_consts_105_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_105_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_105_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_105_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_105_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 6,
    .co_nplaincellvars = 2,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_105_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_105_cellvars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_106_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x00\x7c\x01\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[170];
    }
toplevel_consts_106_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 169,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x47\x65\x74\x20\x61\x6e\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x2c\x20\x72\x65\x74\x75\x72\x6e\x20\x4e\x6f\x6e\x65\x20\x69\x66\x20\x69\x74\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x65\x78\x69\x73\x74\x2e\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x73\x65\x63\x6f\x6e\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x63\x61\x6e\x20\x73\x70\x65\x63\x69\x66\x79\x20\x61\x6e\x20\x61\x6c\x74\x65\x72\x6e\x61\x74\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x2e\x0a\x20\x20\x20\x20\x6b\x65\x79\x2c\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x20\x61\x72\x65\x20\x73\x74\x72\x2e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_106_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_106_consts_0._ascii.ob_base,
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
toplevel_consts_106_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_100_names_2._ascii.ob_base,
            & toplevel_consts_101_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_106_varnames_1 = {
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
    ._data = "default",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_106_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_106_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_106_name = {
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
    ._data = "getenv",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_106_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_106_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x13\x0c\x25\x18\x1b\x1d\x24\x0c\x25\x0c\x25\x05\x25",
};
static struct PyCodeObject toplevel_consts_106 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_106_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_106_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_106_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 772,
    .co_code = & toplevel_consts_106_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_106_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_106_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_106_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_106_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_106_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_106_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_106_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_107 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_106_name._ascii.ob_base,
            & toplevel_consts_101_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_108_consts_1 = {
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
    ._data = "bytes expected, not %s",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_108_consts = {
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
            & toplevel_consts_108_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_108_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_103_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_108_name = {
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
    ._data = "_check_bytes",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_108_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x27\x10\x28\x09\x4d\x13\x1c\x1d\x35\x38\x3c\x3d\x42\x38\x43\x38\x4c\x1d\x4c\x13\x4d\x0d\x4d\x10\x15\x09\x15",
};
static struct PyCodeObject toplevel_consts_108 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_108_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_108_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_105_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 782,
    .co_code = & toplevel_consts_105_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_108_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_108_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_105_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_105_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_108_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_105_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[180];
    }
toplevel_consts_109_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 179,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x47\x65\x74\x20\x61\x6e\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x2c\x20\x72\x65\x74\x75\x72\x6e\x20\x4e\x6f\x6e\x65\x20\x69\x66\x20\x69\x74\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x65\x78\x69\x73\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x73\x65\x63\x6f\x6e\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x63\x61\x6e\x20\x73\x70\x65\x63\x69\x66\x79\x20\x61\x6e\x20\x61\x6c\x74\x65\x72\x6e\x61\x74\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6b\x65\x79\x2c\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x20\x61\x72\x65\x20\x62\x79\x74\x65\x73\x2e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_109_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_109_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_109_names_0 = {
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
    ._data = "environb",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_109_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_109_names_0._ascii.ob_base,
            & toplevel_consts_101_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_109_name = {
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
    ._data = "getenvb",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_109_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x18\x10\x2a\x1d\x20\x22\x29\x10\x2a\x10\x2a\x09\x2a",
};
static struct PyCodeObject toplevel_consts_109 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_109_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_109_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_106_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 793,
    .co_code = & toplevel_consts_106_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_106_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_109_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_109_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_106_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_106_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_109_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_106_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_110 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_109_names_0._ascii.ob_base,
            & toplevel_consts_109_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_111_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x02\x87\x03\x97\x00\x74\x00\x6a\x01\xa9\x00\x8a\x02\x74\x00\x6a\x02\xa9\x00\x8a\x03\x88\x02\x88\x03\x66\x02\x64\x01\x84\x08\x7d\x00\x88\x02\x88\x03\x66\x02\x64\x02\x84\x08\x7d\x01\x7c\x00\x7c\x01\x66\x02\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_111_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x02\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x00\x74\x01\x7c\x00\x74\x02\xa9\x02\x72\x12\x7c\x00\xa0\x03\x89\x01\x89\x02\xa8\x02\xa9\x02\x53\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[280];
    }
toplevel_consts_111_consts_1_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 279,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x6e\x63\x6f\x64\x65\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x28\x61\x6e\x20\x6f\x73\x2e\x50\x61\x74\x68\x4c\x69\x6b\x65\x2c\x20\x62\x79\x74\x65\x73\x2c\x20\x6f\x72\x20\x73\x74\x72\x29\x20\x74\x6f\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x69\x74\x68\x20\x27\x73\x75\x72\x72\x6f\x67\x61\x74\x65\x65\x73\x63\x61\x70\x65\x27\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x65\x72\x2c\x20\x72\x65\x74\x75\x72\x6e\x20\x62\x79\x74\x65\x73\x20\x75\x6e\x63\x68\x61\x6e\x67\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4f\x6e\x20\x57\x69\x6e\x64\x6f\x77\x73\x2c\x20\x75\x73\x65\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x65\x72\x20\x69\x66\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x20\x73\x79\x73\x74\x65\x6d\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x69\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x27\x6d\x62\x63\x73\x27\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x74\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_111_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_111_consts_1_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_111_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_85_names_3._ascii.ob_base,
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_105_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_111_consts_1_varnames_0 = {
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
    ._data = "filename",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_111_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_111_consts_1_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_111_consts_1_freevars_1 = {
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
    ._data = "errors",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_111_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
            & toplevel_consts_111_consts_1_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_111_consts_1_qualname = {
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
    ._data = "_fscodec.<locals>.fsencode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_111_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x0a\x01\x0e\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_111_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x08\x01\x02\x03\x0e\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_111_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x1a\x1b\x23\x14\x24\x09\x11\x0c\x16\x17\x1f\x21\x24\x0c\x25\x09\x1c\x14\x1c\x14\x35\x24\x2c\x2e\x34\x14\x35\x14\x35\x0d\x35\x14\x1c\x0d\x1c",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_111_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_111_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
            & toplevel_consts_111_consts_1_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_111_consts_1_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 3,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x80\x80",
};
static struct PyCodeObject toplevel_consts_111_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_111_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_111_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_111_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 805,
    .co_code = & toplevel_consts_111_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_111_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_111_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_13._ascii.ob_base,
    .co_qualname = & toplevel_consts_111_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_111_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_111_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_111_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_111_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_111_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[280];
    }
toplevel_consts_111_consts_2_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 279,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x65\x63\x6f\x64\x65\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x28\x61\x6e\x20\x6f\x73\x2e\x50\x61\x74\x68\x4c\x69\x6b\x65\x2c\x20\x62\x79\x74\x65\x73\x2c\x20\x6f\x72\x20\x73\x74\x72\x29\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x69\x74\x68\x20\x27\x73\x75\x72\x72\x6f\x67\x61\x74\x65\x65\x73\x63\x61\x70\x65\x27\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x65\x72\x2c\x20\x72\x65\x74\x75\x72\x6e\x20\x73\x74\x72\x20\x75\x6e\x63\x68\x61\x6e\x67\x65\x64\x2e\x20\x4f\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x57\x69\x6e\x64\x6f\x77\x73\x2c\x20\x75\x73\x65\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x65\x72\x20\x69\x66\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x20\x73\x79\x73\x74\x65\x6d\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x69\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x27\x6d\x62\x63\x73\x27\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x74\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_111_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_111_consts_2_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_111_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_85_names_3._ascii.ob_base,
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_105_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_111_consts_2_qualname = {
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
    ._data = "_fscodec.<locals>.fsdecode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_111_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x1a\x1b\x23\x14\x24\x09\x11\x0c\x16\x17\x1f\x21\x26\x0c\x27\x09\x1c\x14\x1c\x14\x35\x24\x2c\x2e\x34\x14\x35\x14\x35\x0d\x35\x14\x1c\x0d\x1c",
};
static struct PyCodeObject toplevel_consts_111_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_111_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_111_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_111_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 817,
    .co_code = & toplevel_consts_111_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_111_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_111_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_14._ascii.ob_base,
    .co_qualname = & toplevel_consts_111_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_111_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_111_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_111_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_111_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_111_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_111_consts = {
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
            & toplevel_consts_111_consts_1.ob_base,
            & toplevel_consts_111_consts_2.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_111_names_2 = {
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
    ._data = "getfilesystemencodeerrors",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_111_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_85_names_0._ascii.ob_base,
            & toplevel_consts_105_names_5._ascii.ob_base,
            & toplevel_consts_111_names_2._ascii.ob_base,
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
toplevel_consts_111_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_4_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_111_name = {
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
    ._data = "_fscodec",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_111_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x08\x01\x0c\x02\x0c\x0c\x08\x0c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_111_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x08\x01\x0c\x0c\x0c\x0c\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_111_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x10\x13\x10\x29\x10\x2b\x05\x0d\x0e\x11\x0e\x2b\x0e\x2d\x05\x0b\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x0c\x14\x16\x1e\x0c\x1e\x05\x1e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_111_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_4_14._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
            & toplevel_consts_111_consts_1_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_111_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "  @@",
};
static struct PyCodeObject toplevel_consts_111 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_111_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_111_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_111_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 801,
    .co_code = & toplevel_consts_111_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_111_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_111_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_111_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_111_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_111_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_111_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_111_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 2,
    .co_nplaincellvars = 2,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_111_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_111_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_112 = {
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
    ._data = "fork",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_113 = {
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
    ._data = "spawnv",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_115_0 = {
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
    ._data = "P_WAIT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_115_1 = {
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
    ._data = "P_NOWAIT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_115_2 = {
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
    ._data = "P_NOWAITO",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_115 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_115_0._ascii.ob_base,
            & toplevel_consts_115_1._ascii.ob_base,
            & toplevel_consts_115_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[163];
    }
toplevel_consts_116_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 162,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x02\x74\x01\x74\x02\x66\x02\xa9\x02\x73\x0c\x74\x03\x64\x01\xa9\x01\x82\x01\x7c\x02\x72\x12\x7c\x02\x64\x02\x19\x00\x73\x16\x74\x04\x64\x03\xa9\x01\x82\x01\x74\x05\xa9\x00\x7d\x05\x7c\x05\x73\x3a\x09\x00\x7c\x03\x80\x24\x7c\x04\x7c\x01\x7c\x02\xa9\x02\x01\x00\x6e\x08\x7c\x04\x7c\x01\x7c\x02\x7c\x03\xa9\x03\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00\x23\x00\x01\x00\x74\x06\x64\x04\xa9\x01\x01\x00\x59\x00\x64\x00\x53\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x74\x07\x6b\x02\x72\x40\x7c\x05\x53\x00\x09\x00\x74\x08\x7c\x05\x64\x02\xa9\x02\x5c\x02\x7d\x06\x7d\x07\x74\x09\x7c\x07\xa9\x01\x72\x4d\x71\x40\x74\x0a\x7c\x07\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_116_consts_1 = {
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
    ._data = "argv must be a tuple or a list",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[35];
    }
toplevel_consts_116_consts_3 = {
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
    ._data = "argv first element cannot be empty",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_116_consts_4 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 127 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_116_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_116_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_116_consts_3._ascii.ob_base,
            & toplevel_consts_116_consts_4.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_116_names_1 = {
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
    ._data = "tuple",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_116_names_8 = {
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
    ._data = "waitpid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_116_names_9 = {
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
    ._data = "WIFSTOPPED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_116_names_10 = {
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
    ._data = "waitstatus_to_exitcode",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_116_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_116_names_1._ascii.ob_base,
            & toplevel_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_101_names_9._ascii.ob_base,
            & toplevel_consts_112._ascii.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_115_1._ascii.ob_base,
            & toplevel_consts_116_names_8._ascii.ob_base,
            & toplevel_consts_116_names_9._ascii.ob_base,
            & toplevel_consts_116_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_116_varnames_4 = {
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
    ._data = "func",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_116_varnames_5 = {
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
    ._data = "pid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_116_varnames_6 = {
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
    ._data = "wpid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_116_varnames_7 = {
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
    ._data = "sts",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_116_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
            & toplevel_consts_94_varnames_2._ascii.ob_base,
            & toplevel_consts_116_varnames_4._ascii.ob_base,
            & toplevel_consts_116_varnames_5._ascii.ob_base,
            & toplevel_consts_116_varnames_6._ascii.ob_base,
            & toplevel_consts_116_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_116_name = {
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
    ._data = "_spawnvef",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_116_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x02\x08\x01\x0c\x01\x08\x01\x06\x01\x04\x01\x02\x02\x04\x01\x0c\x01\x10\x02\x04\xfe\x02\x80\x02\x03\x0e\x01\x06\x80\x08\x03\x04\x01\x02\x01\x0e\x01\x08\x01\x02\x01\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_116_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x0a\x01\x02\x01\x02\x01\x06\xff\x0a\x01\x06\x01\x02\x01\x02\x12\x02\xf6\x02\xfb\x02\x03\x0c\xfe\x10\x02\x04\xfe\x02\x80\x10\x04\x06\x80\x06\x03\x06\x01\x02\x01\x0e\x01\x06\x01\x04\x01\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[163];
    }
toplevel_consts_116_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 162,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x1f\x22\x27\x29\x2d\x21\x2e\x10\x2f\x09\x3e\x13\x1c\x1d\x3d\x13\x3e\x0d\x3e\x10\x14\x09\x43\x1c\x20\x21\x22\x1c\x23\x09\x43\x13\x1d\x1e\x42\x13\x43\x0d\x43\x0f\x13\x0f\x15\x09\x0c\x10\x13\x09\x33\x0d\x1b\x14\x17\x11\x2a\x15\x19\x1a\x1e\x20\x24\x15\x25\x15\x25\x15\x25\x15\x19\x1a\x1e\x20\x24\x26\x29\x15\x2a\x15\x2a\x15\x2a\x15\x2a\x15\x25\x15\x25\x00\x00\x0d\x1b\x11\x16\x17\x1a\x11\x1b\x11\x1b\x11\x1b\x11\x1b\x11\x1b\x00\x00\x00\x00\x00\x00\x10\x14\x18\x20\x10\x20\x0d\x1b\x18\x1b\x11\x1b\x13\x14\x1d\x24\x25\x28\x2a\x2b\x1d\x2c\x11\x1a\x11\x15\x17\x1a\x14\x1e\x1f\x22\x14\x23\x11\x1d\x15\x1d\x18\x2e\x2f\x32\x18\x33\x11\x33",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_116_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x9c\x0e\x2e\x00\xae\x06\x37\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_116_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_116 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_116_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_116_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_116_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_116_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 5,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 846,
    .co_code = & toplevel_consts_116_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_116_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_116_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_116_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_116_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_116_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_116_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_116_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_116_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_117_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\x7c\x02\x64\x01\x74\x01\xa9\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[278];
    }
toplevel_consts_117_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 277,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x76\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x20\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_117_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_117_consts_0._ascii.ob_base,
            Py_None,
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
toplevel_consts_117_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_116_name._ascii.ob_base,
            & toplevel_consts_93_names_0._ascii.ob_base,
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
toplevel_consts_117_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_117_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x19\x1a\x1e\x20\x24\x26\x2a\x2c\x30\x32\x37\x10\x38\x09\x38",
};
static struct PyCodeObject toplevel_consts_117 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_117_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_117_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_117_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 873,
    .co_code = & toplevel_consts_117_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_113._ascii.ob_base,
    .co_qualname = & toplevel_consts_113._ascii.ob_base,
    .co_linetable = & toplevel_consts_98_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_98_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_117_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_118_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x74\x01\xa9\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[315];
    }
toplevel_consts_118_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 314,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x76\x65\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x20\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x0a\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_118_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_118_consts_0._ascii.ob_base,
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
toplevel_consts_118_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_116_name._ascii.ob_base,
            & toplevel_consts_58._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_118_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_93_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
            & toplevel_consts_94_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_118_name = {
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
    ._data = "spawnve",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_118_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_118_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x19\x1a\x1e\x20\x24\x26\x2a\x2c\x2f\x31\x37\x10\x38\x09\x38",
};
static struct PyCodeObject toplevel_consts_118 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_118_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_118_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_118_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 882,
    .co_code = & toplevel_consts_118_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_118_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_118_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_118_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[313];
    }
toplevel_consts_119_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 312,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x76\x70\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x6c\x6f\x6f\x6b\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x0a\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_119_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_119_consts_0._ascii.ob_base,
            Py_None,
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
toplevel_consts_119_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_116_name._ascii.ob_base,
            & toplevel_consts_95_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_119_name = {
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
    ._data = "spawnvp",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_119_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x19\x1a\x1e\x20\x24\x26\x2a\x2c\x30\x32\x38\x10\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_119 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_119_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_119_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_117_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 894,
    .co_code = & toplevel_consts_117_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_119_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_119_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_119_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[349];
    }
toplevel_consts_120_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 348,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x76\x70\x65\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x6c\x6f\x6f\x6b\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x0a\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x73\x75\x70\x70\x6c\x69\x65\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_120_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_120_consts_0._ascii.ob_base,
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
toplevel_consts_120_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_116_name._ascii.ob_base,
            & toplevel_consts_96_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_120_name = {
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
    ._data = "spawnvpe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_120_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x19\x1a\x1e\x20\x24\x26\x2a\x2c\x2f\x31\x38\x10\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_120 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_120_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_120_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_118_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 904,
    .co_code = & toplevel_consts_118_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_120_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_120_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_118_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_120_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_121 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_113._ascii.ob_base,
            & toplevel_consts_118_name._ascii.ob_base,
            & toplevel_consts_119_name._ascii.ob_base,
            & toplevel_consts_120_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_122_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\x7c\x02\xa9\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[279];
    }
toplevel_consts_122_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 278,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x6c\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x20\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_122_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_122_consts_0._ascii.ob_base,
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
toplevel_consts_122_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_113._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_122_name = {
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
    ._data = "spawnl",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_122_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_122_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x16\x17\x1b\x1d\x21\x23\x27\x10\x28\x09\x28",
};
static struct PyCodeObject toplevel_consts_122 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_122_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_122_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_122_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 922,
    .co_code = & toplevel_consts_122_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_122_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_122_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_122_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_122_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_122_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_123_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x64\x01\x19\x00\x7d\x03\x74\x00\x7c\x00\x7c\x01\x7c\x02\x64\x02\x64\x01\x85\x02\x19\x00\x7c\x03\xa9\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[315];
    }
toplevel_consts_123_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 314,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x6c\x65\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x20\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x0a\x73\x75\x70\x70\x6c\x69\x65\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_123_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_123_consts_0._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            Py_None,
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
toplevel_consts_123_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_118_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_123_name = {
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
    ._data = "spawnle",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_123_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x08\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_123_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x13\x14\x16\x0f\x17\x09\x0c\x10\x17\x18\x1c\x1e\x22\x24\x28\x29\x2c\x2a\x2c\x29\x2c\x24\x2d\x2f\x32\x10\x33\x09\x33",
};
static struct PyCodeObject toplevel_consts_123 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_123_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_123_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_123_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 931,
    .co_code = & toplevel_consts_123_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_123_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_123_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_123_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_123_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_123_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[344];
    }
toplevel_consts_127_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 343,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x6c\x70\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x6c\x6f\x6f\x6b\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x0a\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x73\x75\x70\x70\x6c\x69\x65\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_127_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_127_consts_0._ascii.ob_base,
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
toplevel_consts_127_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_119_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_127_name = {
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
    ._data = "spawnlp",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_127_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_127_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x17\x18\x1c\x1e\x22\x24\x28\x10\x29\x09\x29",
};
static struct PyCodeObject toplevel_consts_127 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_127_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_127_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_122_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 949,
    .co_code = & toplevel_consts_122_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_127_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_127_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_127_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_127_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_127_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_117_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[350];
    }
toplevel_consts_128_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 349,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x73\x70\x61\x77\x6e\x6c\x70\x65\x28\x6d\x6f\x64\x65\x2c\x20\x66\x69\x6c\x65\x2c\x20\x2a\x61\x72\x67\x73\x2c\x20\x65\x6e\x76\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x0a\x45\x78\x65\x63\x75\x74\x65\x20\x66\x69\x6c\x65\x20\x28\x77\x68\x69\x63\x68\x20\x69\x73\x20\x6c\x6f\x6f\x6b\x65\x64\x20\x66\x6f\x72\x20\x61\x6c\x6f\x6e\x67\x20\x24\x50\x41\x54\x48\x29\x20\x77\x69\x74\x68\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x66\x72\x6f\x6d\x0a\x61\x72\x67\x73\x20\x69\x6e\x20\x61\x20\x73\x75\x62\x70\x72\x6f\x63\x65\x73\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x73\x75\x70\x70\x6c\x69\x65\x64\x20\x65\x6e\x76\x69\x72\x6f\x6e\x6d\x65\x6e\x74\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x4e\x4f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x69\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x2e\x0a\x49\x66\x20\x6d\x6f\x64\x65\x20\x3d\x3d\x20\x50\x5f\x57\x41\x49\x54\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x63\x65\x73\x73\x27\x73\x20\x65\x78\x69\x74\x20\x63\x6f\x64\x65\x20\x69\x66\x20\x69\x74\x20\x65\x78\x69\x74\x73\x20\x6e\x6f\x72\x6d\x61\x6c\x6c\x79\x3b\x0a\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x72\x65\x74\x75\x72\x6e\x20\x2d\x53\x49\x47\x2c\x20\x77\x68\x65\x72\x65\x20\x53\x49\x47\x20\x69\x73\x20\x74\x68\x65\x20\x73\x69\x67\x6e\x61\x6c\x20\x74\x68\x61\x74\x20\x6b\x69\x6c\x6c\x65\x64\x20\x69\x74\x2e\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_128_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_128_consts_0._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            Py_None,
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
toplevel_consts_128_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_120_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_128_name = {
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
    ._data = "spawnlpe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_128_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x13\x14\x16\x0f\x17\x09\x0c\x10\x18\x19\x1d\x1f\x23\x25\x29\x2a\x2d\x2b\x2d\x2a\x2d\x25\x2e\x30\x33\x10\x34\x09\x34",
};
static struct PyCodeObject toplevel_consts_128 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_128_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_128_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_123_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 959,
    .co_code = & toplevel_consts_123_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_128_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_128_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_123_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_123_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_128_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_118_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_131 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_132 = {
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
    ._data = "r",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[165];
    }
toplevel_consts_134_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 164,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x73\x0e\x74\x02\x64\x01\x74\x03\x7c\x00\xa9\x01\x7a\x06\xa9\x01\x82\x01\x7c\x01\x64\x02\x76\x01\x72\x18\x74\x04\x64\x03\x7c\x01\x7a\x06\xa9\x01\x82\x01\x7c\x02\x64\x04\x6b\x02\x73\x1e\x7c\x02\x80\x22\x74\x04\x64\x05\xa9\x01\x82\x01\x64\x04\x64\x00\x6c\x05\x7d\x03\x64\x04\x64\x00\x6c\x06\x7d\x04\x7c\x01\x64\x06\x6b\x02\x72\x40\x7c\x03\xa0\x07\x7c\x00\x64\x07\x64\x07\x7c\x03\x6a\x08\x7c\x02\x64\x08\xa8\x06\xaa\x05\x7d\x05\x74\x09\x7c\x05\x6a\x0a\x7c\x05\xa9\x02\x53\x00\x7c\x03\xa0\x07\x7c\x00\x64\x07\x64\x07\x7c\x03\x6a\x08\x7c\x02\x64\x09\xa8\x06\xaa\x05\x7d\x05\x74\x09\x7c\x05\x6a\x0b\x7c\x05\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_134_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 38,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "invalid cmd type (%s, expected string)",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_134_consts_2_1 = {
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
    ._data = "w",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_134_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_132._ascii.ob_base,
            & toplevel_consts_134_consts_2_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_134_consts_3 = {
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
    ._data = "invalid mode %r",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[44];
    }
toplevel_consts_134_consts_5 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 43,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "popen() does not support unbuffered streams",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_134_consts_8_0 = {
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
    ._data = "shell",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_134_consts_8_1 = {
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
    ._data = "text",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_134_consts_8_2 = {
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
    ._data = "stdout",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_134_consts_8_3 = {
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
    ._data = "bufsize",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_134_consts_8 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_134_consts_8_0._ascii.ob_base,
            & toplevel_consts_134_consts_8_1._ascii.ob_base,
            & toplevel_consts_134_consts_8_2._ascii.ob_base,
            & toplevel_consts_134_consts_8_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_134_consts_9_2 = {
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
    ._data = "stdin",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_134_consts_9 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_134_consts_8_0._ascii.ob_base,
            & toplevel_consts_134_consts_8_1._ascii.ob_base,
            & toplevel_consts_134_consts_9_2._ascii.ob_base,
            & toplevel_consts_134_consts_8_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_134_consts = {
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
            & toplevel_consts_134_consts_1._ascii.ob_base,
            & toplevel_consts_134_consts_2._object.ob_base.ob_base,
            & toplevel_consts_134_consts_3._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_134_consts_5._ascii.ob_base,
            & toplevel_consts_132._ascii.ob_base,
            Py_True,
            & toplevel_consts_134_consts_8._object.ob_base.ob_base,
            & toplevel_consts_134_consts_9._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_134_names_5 = {
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
    ._data = "subprocess",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_134_names_6 = {
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
        uint8_t _data[6];
    }
toplevel_consts_134_names_7 = {
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
    ._data = "Popen",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_134_names_8 = {
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
    ._data = "PIPE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_134_names_9 = {
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
    ._data = "_wrap_close",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_134_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_101_names_9._ascii.ob_base,
            & toplevel_consts_134_names_5._ascii.ob_base,
            & toplevel_consts_134_names_6._ascii.ob_base,
            & toplevel_consts_134_names_7._ascii.ob_base,
            & toplevel_consts_134_names_8._ascii.ob_base,
            & toplevel_consts_134_names_9._ascii.ob_base,
            & toplevel_consts_134_consts_8_2._ascii.ob_base,
            & toplevel_consts_134_consts_9_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_134_varnames_0 = {
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
    ._data = "cmd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_134_varnames_2 = {
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
    ._data = "buffering",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_134_varnames_5 = {
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
    ._data = "proc",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_134_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_134_varnames_0._ascii.ob_base,
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_134_varnames_2._ascii.ob_base,
            & toplevel_consts_134_names_5._ascii.ob_base,
            & toplevel_consts_134_names_6._ascii.ob_base,
            & toplevel_consts_134_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_134_name = {
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
    ._data = "popen",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_134_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x10\x01\x08\x01\x0c\x01\x0c\x01\x08\x01\x10\x01\x08\x01\x06\x01\x04\x01\x04\x01\x02\x01\x08\xfd\x0c\x04\x06\x02\x04\x01\x04\x01\x02\x01\x08\xfd\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_134_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x12\x01\x06\x01\x0e\x01\x06\x01\x02\x01\x02\xff\x0a\x01\x10\x01\x06\x01\x02\x0b\x02\xf6\x02\x03\x02\xfd\x04\x01\x04\x01\x08\x01\x02\xfd\x0c\x04\x02\x02\x02\x03\x02\xfd\x04\x01\x04\x01\x08\x01\x02\xfd\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[165];
    }
toplevel_consts_134_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 164,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x1e\x20\x23\x10\x24\x09\x52\x13\x1c\x1d\x45\x48\x4c\x4d\x50\x48\x51\x1d\x51\x13\x52\x0d\x52\x0c\x10\x18\x22\x0c\x22\x09\x37\x13\x1d\x1e\x2f\x32\x36\x1e\x36\x13\x37\x0d\x37\x0c\x15\x19\x1a\x0c\x1a\x09\x4c\x1e\x27\x09\x4c\x13\x1d\x1e\x4b\x13\x4c\x0d\x4c\x09\x1e\x09\x1e\x09\x1e\x09\x1e\x09\x1e\x09\x1e\x09\x1e\x09\x1e\x0c\x10\x14\x17\x0c\x17\x09\x31\x14\x1e\x14\x37\x25\x28\x2b\x2f\x36\x3a\x2c\x36\x2c\x3b\x2d\x36\x14\x37\x14\x37\x14\x37\x0d\x11\x14\x1f\x20\x24\x20\x2b\x2d\x31\x14\x32\x0d\x32\x14\x1e\x14\x37\x25\x28\x2b\x2f\x36\x3a\x2b\x35\x2b\x3a\x2d\x36\x14\x37\x14\x37\x14\x37\x0d\x11\x14\x1f\x20\x24\x20\x2a\x2c\x30\x14\x31\x0d\x31",
};
static struct PyCodeObject toplevel_consts_134 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_134_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_134_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_134_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 8,
    .co_firstlineno = 977,
    .co_code = & toplevel_consts_134_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_134_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_80_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_134_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_134_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_134_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_134_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_134_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_134_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_135_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x84\x00\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x84\x00\x5a\x08\x64\x07\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_135_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_135_consts_1_names_0 = {
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
    ._data = "_stream",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_135_consts_1_names_1 = {
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
    ._data = "_proc",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_135_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_135_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_135_consts_1_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_135_consts_1_varnames_1 = {
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
    ._data = "stream",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_135_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_135_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_134_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_135_consts_1_qualname = {
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
    ._data = "_wrap_close.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_135_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_135_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1c\x22\x0d\x11\x0d\x19\x1a\x1e\x0d\x11\x0d\x17\x0d\x17\x0d\x17",
};
static struct PyCodeObject toplevel_consts_135_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1000,
    .co_code = & toplevel_consts_135_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_135_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_135_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_135_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x7c\x00\x6a\x02\xa0\x03\xa8\x00\xa9\x00\x7d\x01\x7c\x01\x64\x01\x6b\x02\x72\x13\x64\x00\x53\x00\x74\x04\x64\x02\x6b\x02\x72\x19\x7c\x01\x53\x00\x7c\x01\x64\x03\x7a\x03\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_135_consts_2_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 8 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_135_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_consts_135_consts_2_consts_3.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_135_consts_2_names_3 = {
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
    ._data = "wait",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_135_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_135_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_90_names_14._ascii.ob_base,
            & toplevel_consts_135_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_135_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_135_consts_2_varnames_1 = {
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
    ._data = "returncode",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_135_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_135_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_135_consts_2_qualname = {
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
    ._data = "_wrap_close.close",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_135_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0c\x01\x08\x01\x04\x01\x08\x01\x04\x01\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_135_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0c\x01\x06\x01\x06\x01\x06\x01\x02\x03\x04\xfe\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_135_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x11\x0d\x19\x0d\x21\x0d\x21\x0d\x21\x0d\x21\x1a\x1e\x1a\x24\x1a\x2b\x1a\x2b\x1a\x2b\x0d\x17\x10\x1a\x1e\x1f\x10\x1f\x0d\x1c\x18\x1c\x18\x1c\x10\x14\x18\x1c\x10\x1c\x0d\x27\x18\x22\x11\x22\x18\x22\x26\x27\x18\x27\x11\x27",
};
static struct PyCodeObject toplevel_consts_135_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_135_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1003,
    .co_code = & toplevel_consts_135_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_135_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_90_names_14._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_135_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_135_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_135_consts_3_name = {
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
    ._data = "__enter__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_135_consts_3_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 21,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_wrap_close.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_135_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_135_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x18\x0d\x18",
};
static struct PyCodeObject toplevel_consts_135_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1012,
    .co_code = & toplevel_consts_135_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_135_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_135_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_135_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_90_names_14._ascii.ob_base,
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
toplevel_consts_135_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_135_consts_4_name = {
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
    ._data = "__exit__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_135_consts_4_qualname = {
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
    ._data = "_wrap_close.__exit__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_135_consts_4_linetable = {
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
toplevel_consts_135_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x11\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19",
};
static struct PyCodeObject toplevel_consts_135_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1014,
    .co_code = & toplevel_consts_135_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_135_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_135_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_135_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_135_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_135_consts_5_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_135_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_135_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_135_consts_1_names_0._ascii.ob_base,
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
toplevel_consts_135_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_135_consts_5_name = {
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
    ._data = "__getattr__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_135_consts_5_qualname = {
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
    ._data = "_wrap_close.__getattr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_135_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_135_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x1b\x1c\x20\x1c\x28\x2a\x2e\x14\x2f\x0d\x2f",
};
static struct PyCodeObject toplevel_consts_135_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1016,
    .co_code = & toplevel_consts_135_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_135_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_135_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_135_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_135_consts_6_names_0 = {
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
    ._data = "iter",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_135_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_135_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_135_consts_1_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_135_consts_6_qualname = {
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
    ._data = "_wrap_close.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_135_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x18\x19\x1d\x19\x25\x14\x26\x0d\x26",
};
static struct PyCodeObject toplevel_consts_135_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_103_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1018,
    .co_code = & toplevel_consts_103_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_135_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_135_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_134_names_9._ascii.ob_base,
            & toplevel_consts_135_consts_1.ob_base,
            & toplevel_consts_135_consts_2.ob_base,
            & toplevel_consts_135_consts_3.ob_base,
            & toplevel_consts_135_consts_4.ob_base,
            & toplevel_consts_135_consts_5.ob_base,
            & toplevel_consts_135_consts_6.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_135_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_103_names_1._ascii.ob_base,
            & toplevel_consts_103_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_name._ascii.ob_base,
            & toplevel_consts_90_names_14._ascii.ob_base,
            & toplevel_consts_135_consts_3_name._ascii.ob_base,
            & toplevel_consts_135_consts_4_name._ascii.ob_base,
            & toplevel_consts_135_consts_5_name._ascii.ob_base,
            & toplevel_consts_103_consts_5_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_135_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x01\x06\x03\x06\x09\x06\x02\x06\x02\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_135_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x03\x06\x09\x06\x02\x06\x02\x06\x02\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_135_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x09\x1e\x09\x1e\x09\x1e\x09\x27\x09\x27\x09\x27\x09\x18\x09\x18\x09\x18\x09\x19\x09\x19\x09\x19\x09\x2f\x09\x2f\x09\x2f\x09\x26\x09\x26\x09\x26\x09\x26\x09\x26",
};
static struct PyCodeObject toplevel_consts_135 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_135_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 999,
    .co_code = & toplevel_consts_135_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_134_names_9._ascii.ob_base,
    .co_qualname = & toplevel_consts_134_names_9._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_138_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x73\x0e\x74\x02\x64\x01\x74\x03\x7c\x00\xa9\x01\x7a\x06\xa9\x01\x82\x01\x64\x02\x64\x00\x6c\x04\x7d\x06\x64\x03\x7c\x01\x76\x01\x72\x1c\x7c\x06\xa0\x05\x7c\x03\xa8\x01\xa9\x01\x7d\x03\x7c\x06\x6a\x06\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x67\x04\x7c\x04\xa2\x01\x52\x00\x69\x00\x7c\x05\xa4\x01\x8e\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_138_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 38,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "invalid fd type (%s, expected integer)",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_138_consts_3 = {
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
    ._data = "b",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_138_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_138_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_138_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_138_names_1 = {
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
    ._data = "int",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_138_names_5 = {
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
    ._data = "text_encoding",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_138_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_138_names_1._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_134_names_6._ascii.ob_base,
            & toplevel_consts_138_names_5._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_138_varnames_0 = {
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
    ._data = "fd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_138_varnames_5 = {
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
    ._data = "kwargs",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_138_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_138_varnames_0._ascii.ob_base,
            & toplevel_consts_80_varnames_1._ascii.ob_base,
            & toplevel_consts_134_varnames_2._ascii.ob_base,
            & toplevel_consts_105_consts_4_freevars_0._ascii.ob_base,
            & toplevel_consts_93_varnames_1._ascii.ob_base,
            & toplevel_consts_138_varnames_5._ascii.ob_base,
            & toplevel_consts_134_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_138_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x10\x01\x08\x01\x08\x01\x0c\x01\x1e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_138_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x12\x01\x08\x01\x06\x01\x0e\x01\x1e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_138_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x16\x17\x19\x1b\x1e\x0c\x1f\x05\x4d\x0f\x18\x19\x41\x44\x48\x49\x4b\x44\x4c\x19\x4c\x0f\x4d\x09\x4d\x05\x0e\x05\x0e\x05\x0e\x05\x0e\x08\x0b\x13\x17\x08\x17\x05\x2e\x14\x16\x14\x2e\x25\x2d\x14\x2e\x14\x2e\x09\x11\x0c\x0e\x0c\x13\x14\x16\x18\x1c\x1e\x27\x29\x31\x0c\x43\x34\x38\x0c\x43\x0c\x43\x0c\x43\x3c\x42\x0c\x43\x0c\x43\x05\x43",
};
static struct PyCodeObject toplevel_consts_138 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_138_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_138_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_138_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 15,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1024,
    .co_code = & toplevel_consts_138_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_138_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_90_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_16._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_16._ascii.ob_base,
    .co_linetable = & toplevel_consts_138_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_138_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_138_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_138_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_139_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\x74\x02\x66\x02\xa9\x02\x72\x0a\x7c\x00\x53\x00\x74\x03\x7c\x00\xa9\x01\x7d\x01\x09\x00\x7c\x01\xa0\x04\x7c\x00\xa8\x01\xa9\x01\x7d\x02\x6e\x15\x23\x00\x74\x05\x79\x27\x01\x00\x74\x06\x7c\x01\x64\x01\xa9\x02\x72\x20\x82\x00\x74\x07\x64\x02\x7c\x01\x6a\x08\x7a\x00\xa9\x01\x82\x01\x77\x00\x78\x03\x59\x00\x77\x01\x74\x00\x7c\x02\x74\x01\x74\x02\x66\x02\xa9\x02\x72\x34\x7c\x02\x53\x00\x74\x07\x64\x03\xa0\x09\x7c\x01\x6a\x08\x74\x03\x7c\x02\xa9\x01\x6a\x08\xa8\x02\xa9\x02\xa9\x01\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[354];
    }
toplevel_consts_139_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 353,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x61\x74\x68\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x61\x20\x70\x61\x74\x68\x2d\x6c\x69\x6b\x65\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x73\x74\x72\x20\x6f\x72\x20\x62\x79\x74\x65\x73\x20\x69\x73\x20\x70\x61\x73\x73\x65\x64\x20\x69\x6e\x2c\x20\x69\x74\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x75\x6e\x63\x68\x61\x6e\x67\x65\x64\x2e\x20\x4f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x6f\x73\x2e\x50\x61\x74\x68\x4c\x69\x6b\x65\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x69\x73\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x67\x65\x74\x20\x74\x68\x65\x20\x70\x61\x74\x68\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x61\x74\x69\x6f\x6e\x2e\x20\x49\x66\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x70\x61\x74\x68\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x69\x73\x20\x6e\x6f\x74\x20\x73\x74\x72\x20\x6f\x72\x20\x62\x79\x74\x65\x73\x2c\x20\x54\x79\x70\x65\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x20\x49\x66\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x70\x72\x6f\x76\x69\x64\x65\x64\x20\x70\x61\x74\x68\x20\x69\x73\x20\x6e\x6f\x74\x20\x73\x74\x72\x2c\x20\x62\x79\x74\x65\x73\x2c\x20\x6f\x72\x20\x6f\x73\x2e\x50\x61\x74\x68\x4c\x69\x6b\x65\x2c\x20\x54\x79\x70\x65\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_139_consts_1 = {
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
    ._data = "__fspath__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[48];
    }
toplevel_consts_139_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 47,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "expected str, bytes or os.PathLike object, not ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[56];
    }
toplevel_consts_139_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 55,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "expected {}.__fspath__() to return str or bytes, not {}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_139_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_139_consts_0._ascii.ob_base,
            & toplevel_consts_139_consts_1._ascii.ob_base,
            & toplevel_consts_139_consts_2._ascii.ob_base,
            & toplevel_consts_139_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_139_names_6 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_139_names_9 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_139_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_80_names_6._ascii.ob_base,
            & toplevel_consts_19_varnames_0._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_139_consts_1._ascii.ob_base,
            & toplevel_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_139_names_6._ascii.ob_base,
            & toplevel_consts_101_names_6._ascii.ob_base,
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_139_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_139_varnames_1 = {
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
    ._data = "path_type",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_139_varnames_2 = {
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
    ._data = "path_repr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_139_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_139_varnames_1._ascii.ob_base,
            & toplevel_consts_139_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_139_name = {
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
    ._data = "_fspath",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_139_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x08\x04\x01\x08\x04\x02\x01\x0e\x01\x02\x80\x06\x01\x0a\x01\x02\x01\x04\x02\x04\x01\x06\xff\x02\xfc\x06\x80\x0e\x06\x04\x01\x04\x02\x06\x01\x08\x01\x04\xff\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_139_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x08\x06\x01\x08\x04\x02\x08\x0e\xfa\x02\x80\x02\x01\x04\x05\x08\xfc\x02\x04\x02\xfd\x02\x02\x0e\x01\x06\x80\x0c\x01\x02\x05\x04\xfc\x02\x02\x02\x01\x02\x01\x04\xff\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_139_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x12\x13\x17\x1a\x1d\x1f\x24\x19\x25\x08\x26\x05\x14\x10\x14\x09\x14\x11\x15\x16\x1a\x11\x1b\x05\x0e\x05\x39\x15\x1e\x15\x2f\x2a\x2e\x15\x2f\x15\x2f\x09\x12\x09\x12\x00\x00\x0c\x1a\x05\x39\x05\x39\x0c\x13\x14\x1d\x1f\x2b\x0c\x2c\x09\x39\x0d\x12\x13\x1c\x1d\x23\x26\x2f\x26\x38\x1d\x38\x13\x39\x0d\x39\x05\x39\x00\x00\x00\x00\x00\x00\x08\x12\x13\x1c\x1f\x22\x24\x29\x1e\x2a\x08\x2b\x05\x43\x10\x19\x09\x19\x0f\x18\x19\x21\x19\x42\x29\x32\x29\x3b\x29\x2d\x2e\x37\x29\x38\x29\x41\x19\x42\x19\x42\x0f\x43\x09\x43",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_139_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x8f\x06\x16\x00\x96\x12\x28\x03",
};
static struct PyCodeObject toplevel_consts_139 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_139_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_139_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_139_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_139_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 1035,
    .co_code = & toplevel_consts_139_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_139_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_139_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_139_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_139_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_139_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_139_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_139_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_141_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x6a\x05\x64\x02\x84\x00\xa9\x01\x5a\x06\x65\x07\x64\x03\x84\x00\xa9\x01\x5a\x08\x65\x07\x65\x09\xa9\x01\x5a\x0a\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_141_consts_0 = {
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
    ._data = "PathLike",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_141_consts_1 = {
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
    ._data = "Abstract base class for implementing the file system path protocol.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_141_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[58];
    }
toplevel_consts_141_consts_2_consts_0 = {
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
    ._data = "Return the file system path representation of the object.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_141_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_141_consts_2_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_141_consts_2_names_0 = {
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
    ._data = "NotImplementedError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_141_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_141_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_141_consts_2_qualname = {
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
    ._data = "PathLike.__fspath__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_141_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_141_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x22\x09\x22",
};
static struct PyCodeObject toplevel_consts_141_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_141_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_141_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_141_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1075,
    .co_code = & toplevel_consts_141_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_139_consts_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_141_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_141_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_141_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_141_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_141_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x75\x00\x72\x0a\x74\x01\x7c\x01\x64\x01\xa9\x02\x53\x00\x74\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_141_consts_3_consts = {
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
            & toplevel_consts_139_consts_1._ascii.ob_base,
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
toplevel_consts_141_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_141_consts_0._ascii.ob_base,
            & toplevel_consts_3_0._ascii.ob_base,
            & toplevel_consts_103_consts_11_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_141_consts_3_varnames_0 = {
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
    ._data = "cls",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_141_consts_3_varnames_1 = {
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
    ._data = "subclass",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_141_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_141_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_141_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_141_consts_3_name = {
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
    ._data = "__subclasshook__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_141_consts_3_qualname = {
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
    ._data = "PathLike.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_141_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_141_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_141_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1b\x0c\x1b\x09\x3a\x14\x22\x23\x2b\x2d\x39\x14\x3a\x0d\x3a\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_141_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_141_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_141_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_141_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1080,
    .co_code = & toplevel_consts_141_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_141_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_141_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_141_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_141_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_141_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_141_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_141_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_141_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_141_consts_0._ascii.ob_base,
            & toplevel_consts_141_consts_1._ascii.ob_base,
            & toplevel_consts_141_consts_2.ob_base,
            & toplevel_consts_141_consts_3.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_141_names_3 = {
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
        uint8_t _data[4];
    }
toplevel_consts_141_names_4 = {
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
    ._data = "abc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_141_names_5 = {
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
    ._data = "abstractmethod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_141_names_7 = {
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
    ._data = "classmethod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_141_names_9 = {
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
    ._data = "GenericAlias",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_141_names_10 = {
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
    ._data = "__class_getitem__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_141_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_103_names_1._ascii.ob_base,
            & toplevel_consts_103_names_2._ascii.ob_base,
            & toplevel_consts_141_names_3._ascii.ob_base,
            & toplevel_consts_141_names_4._ascii.ob_base,
            & toplevel_consts_141_names_5._ascii.ob_base,
            & toplevel_consts_139_consts_1._ascii.ob_base,
            & toplevel_consts_141_names_7._ascii.ob_base,
            & toplevel_consts_141_consts_3_name._ascii.ob_base,
            & toplevel_consts_141_names_9._ascii.ob_base,
            & toplevel_consts_141_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_141_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x02\x04\x01\x02\xff\x02\x01\x02\x04\x04\x01\x02\xff\x02\x01\x0c\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_141_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x04\x04\x02\xfc\x02\x04\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_141_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x4e\x05\x4e\x06\x09\x06\x18\x05\x22\x05\x22\x06\x18\x05\x22\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_141 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_141_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_141_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_141_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1071,
    .co_code = & toplevel_consts_141_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_141_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_141_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_141_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_141_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_141_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_143_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x84\x00\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_143_consts_0 = {
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
    ._data = "_AddedDllDirectory",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_143_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x7c\x03\x7c\x00\x5f\x02\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_143_consts_1_names_1 = {
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
    ._data = "_cookie",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_143_consts_1_names_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 21,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_remove_dll_directory",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_143_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_143_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_143_consts_1_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_143_consts_1_varnames_2 = {
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
    ._data = "cookie",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_143_consts_1_varnames_3 = {
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
    ._data = "remove_dll_directory",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_143_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_103_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_143_consts_1_varnames_2._ascii.ob_base,
            & toplevel_consts_143_consts_1_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_143_consts_1_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 27,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_AddedDllDirectory.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_143_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x06\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_143_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x19\x1d\x0d\x11\x0d\x16\x1c\x22\x0d\x11\x0d\x19\x2a\x3e\x0d\x11\x0d\x27\x0d\x27\x0d\x27",
};
static struct PyCodeObject toplevel_consts_143_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_143_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_143_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1091,
    .co_code = & toplevel_consts_143_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_143_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_82_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_143_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_143_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_143_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_143_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_143_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x00\x6a\x01\xa8\x01\xa9\x01\x01\x00\x64\x00\x7c\x00\x5f\x02\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_143_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_143_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_143_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_143_consts_2_qualname = {
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
    ._data = "_AddedDllDirectory.close",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_143_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_143_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x11\x0d\x35\x28\x2c\x28\x34\x0d\x35\x0d\x35\x0d\x35\x19\x1d\x0d\x11\x0d\x16\x0d\x16\x0d\x16",
};
static struct PyCodeObject toplevel_consts_143_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_143_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_143_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1095,
    .co_code = & toplevel_consts_143_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_90_names_14._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_143_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_143_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_143_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_143_consts_3_qualname = {
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
    ._data = "_AddedDllDirectory.__enter__",
};
static struct PyCodeObject toplevel_consts_143_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1098,
    .co_code = & toplevel_consts_135_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_135_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_143_consts_4_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 27,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_AddedDllDirectory.__exit__",
};
static struct PyCodeObject toplevel_consts_143_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_135_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_135_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1100,
    .co_code = & toplevel_consts_135_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_135_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_135_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_135_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_135_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_135_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_135_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_143_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x72\x0b\x64\x01\xa0\x01\x7c\x00\x6a\x00\xa8\x01\xa9\x01\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_143_consts_5_consts_1 = {
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
    ._data = "<AddedDllDirectory({!r})>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_143_consts_5_consts_2 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 21,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "<AddedDllDirectory()>",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_143_consts_5_consts = {
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
            & toplevel_consts_143_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_143_consts_5_consts_2._ascii.ob_base,
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
toplevel_consts_143_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_139_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_143_consts_5_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 27,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_AddedDllDirectory.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_143_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_143_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_143_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x19\x0d\x45\x18\x33\x18\x45\x3b\x3f\x3b\x44\x18\x45\x18\x45\x11\x45\x14\x2b\x14\x2b",
};
static struct PyCodeObject toplevel_consts_143_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_143_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_143_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_143_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1102,
    .co_code = & toplevel_consts_143_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_103_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_143_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_143_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_143_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_103_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_143_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_143_consts_0._ascii.ob_base,
            & toplevel_consts_143_consts_1.ob_base,
            & toplevel_consts_143_consts_2.ob_base,
            & toplevel_consts_143_consts_3.ob_base,
            & toplevel_consts_143_consts_4.ob_base,
            & toplevel_consts_143_consts_5.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_143_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_consts_103_names_1._ascii.ob_base,
            & toplevel_consts_103_names_2._ascii.ob_base,
            & toplevel_consts_103_consts_1_name._ascii.ob_base,
            & toplevel_consts_90_names_14._ascii.ob_base,
            & toplevel_consts_135_consts_3_name._ascii.ob_base,
            & toplevel_consts_135_consts_4_name._ascii.ob_base,
            & toplevel_consts_103_consts_7_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_143_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x01\x06\x04\x06\x03\x06\x02\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_143_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x04\x06\x03\x06\x02\x06\x02\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_143_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x09\x3e\x09\x3e\x09\x3e\x09\x1d\x09\x1d\x09\x1d\x09\x18\x09\x18\x09\x18\x09\x19\x09\x19\x09\x19\x09\x2b\x09\x2b\x09\x2b\x09\x2b\x09\x2b",
};
static struct PyCodeObject toplevel_consts_143 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_143_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_143_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_143_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1090,
    .co_code = & toplevel_consts_143_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_143_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_143_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_143_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_143_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_143_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_145_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x64\x02\x6c\x00\x7d\x01\x7c\x01\x6a\x01\x7c\x00\xa9\x01\x7d\x02\x74\x02\x7c\x00\x7c\x02\x7c\x01\x6a\x03\xa9\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[336];
    }
toplevel_consts_145_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 335,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x64\x64\x20\x61\x20\x70\x61\x74\x68\x20\x74\x6f\x20\x74\x68\x65\x20\x44\x4c\x4c\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x73\x65\x61\x72\x63\x68\x20\x70\x61\x74\x68\x20\x69\x73\x20\x75\x73\x65\x64\x20\x77\x68\x65\x6e\x20\x72\x65\x73\x6f\x6c\x76\x69\x6e\x67\x20\x64\x65\x70\x65\x6e\x64\x65\x6e\x63\x69\x65\x73\x20\x66\x6f\x72\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x78\x74\x65\x6e\x73\x69\x6f\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x28\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x74\x73\x65\x6c\x66\x20\x69\x73\x20\x72\x65\x73\x6f\x6c\x76\x65\x64\x20\x74\x68\x72\x6f\x75\x67\x68\x20\x73\x79\x73\x2e\x70\x61\x74\x68\x29\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x61\x6c\x73\x6f\x20\x62\x79\x20\x63\x74\x79\x70\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x6d\x6f\x76\x65\x20\x74\x68\x65\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x62\x79\x20\x63\x61\x6c\x6c\x69\x6e\x67\x20\x63\x6c\x6f\x73\x65\x28\x29\x20\x6f\x6e\x20\x74\x68\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x6f\x62\x6a\x65\x63\x74\x20\x6f\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x75\x73\x69\x6e\x67\x20\x69\x74\x20\x69\x6e\x20\x61\x20\x77\x69\x74\x68\x20\x73\x74\x61\x74\x65\x6d\x65\x6e\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_145_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_145_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_145_names_1 = {
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
    ._data = "_add_dll_directory",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_145_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_consts_145_names_1._ascii.ob_base,
            & toplevel_consts_143_consts_0._ascii.ob_base,
            & toplevel_consts_143_consts_1_names_2._ascii.ob_base,
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
toplevel_consts_145_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_consts_143_consts_1_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_145_name = {
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
    ._data = "add_dll_directory",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_145_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x0a\x01\x02\x01\x02\x01\x02\x01\x04\x01\x04\xfd",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_145_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x0a\x01\x02\x01\x02\x01\x02\x01\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_145_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x12\x09\x12\x09\x12\x09\x12\x12\x14\x12\x27\x28\x2c\x12\x2d\x09\x0f\x10\x22\x0d\x11\x0d\x13\x0d\x0f\x0d\x25\x10\x0a\x09\x0a",
};
static struct PyCodeObject toplevel_consts_145 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_145_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_145_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_145_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1107,
    .co_code = & toplevel_consts_145_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_145_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_81_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_145_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_145_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_145_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_145_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_145_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_145_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_146 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_78.ob_base.ob_base,
            Py_False,
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
toplevel_consts_147 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            Py_True,
            Py_None,
            Py_False,
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
toplevel_consts_148 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_88._ascii.ob_base,
            Py_True,
            Py_None,
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
toplevel_consts_150 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_132._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
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
toplevel_consts_151 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_132._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[152];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 152,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_3._object.ob_base.ob_base,
            & toplevel_consts_4._object.ob_base.ob_base,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_6.ob_base,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_8._ascii.ob_base,
            & toplevel_consts_9._object.ob_base.ob_base,
            & toplevel_consts_10._object.ob_base.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_12._object.ob_base.ob_base,
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_consts_14._ascii.ob_base,
            & toplevel_consts_15._ascii.ob_base,
            & toplevel_consts_16._ascii.ob_base,
            & toplevel_consts_17._object.ob_base.ob_base,
            & toplevel_consts_12_0._ascii.ob_base,
            & toplevel_consts_19.ob_base,
            & toplevel_consts_20._ascii.ob_base,
            & toplevel_consts_21._ascii.ob_base,
            & toplevel_consts_22._ascii.ob_base,
            & toplevel_consts_23._ascii.ob_base,
            & toplevel_consts_24._ascii.ob_base,
            & toplevel_consts_25._ascii.ob_base,
            & toplevel_consts_26._ascii.ob_base,
            & toplevel_consts_27._ascii.ob_base,
            & toplevel_consts_28._ascii.ob_base,
            & toplevel_consts_29._ascii.ob_base,
            & toplevel_consts_30._ascii.ob_base,
            & toplevel_consts_31._ascii.ob_base,
            & toplevel_consts_32._ascii.ob_base,
            & toplevel_consts_33._ascii.ob_base,
            & toplevel_consts_34._ascii.ob_base,
            & toplevel_consts_35._ascii.ob_base,
            & toplevel_consts_36._ascii.ob_base,
            & toplevel_consts_37._ascii.ob_base,
            & toplevel_consts_38._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_40._ascii.ob_base,
            & toplevel_consts_41._ascii.ob_base,
            & toplevel_consts_42._ascii.ob_base,
            & toplevel_consts_43._ascii.ob_base,
            & toplevel_consts_44._ascii.ob_base,
            & toplevel_consts_45._ascii.ob_base,
            & toplevel_consts_46._ascii.ob_base,
            & toplevel_consts_47._ascii.ob_base,
            & toplevel_consts_48._ascii.ob_base,
            & toplevel_consts_49._ascii.ob_base,
            & toplevel_consts_50._ascii.ob_base,
            & toplevel_consts_51._ascii.ob_base,
            & toplevel_consts_52._ascii.ob_base,
            & toplevel_consts_53._ascii.ob_base,
            & toplevel_consts_54._ascii.ob_base,
            & toplevel_consts_55._ascii.ob_base,
            & toplevel_consts_56._ascii.ob_base,
            & toplevel_consts_57._ascii.ob_base,
            & toplevel_consts_58._ascii.ob_base,
            & toplevel_consts_59._ascii.ob_base,
            & toplevel_consts_60._ascii.ob_base,
            & toplevel_consts_61._ascii.ob_base,
            & toplevel_consts_62._ascii.ob_base,
            & toplevel_consts_63._ascii.ob_base,
            & toplevel_consts_64._ascii.ob_base,
            & toplevel_consts_65._ascii.ob_base,
            & toplevel_consts_66._ascii.ob_base,
            & toplevel_consts_67._ascii.ob_base,
            & toplevel_consts_68._ascii.ob_base,
            & toplevel_consts_69._ascii.ob_base,
            & toplevel_consts_70._ascii.ob_base,
            & toplevel_consts_71._ascii.ob_base,
            & toplevel_consts_72._ascii.ob_base,
            & toplevel_consts_73._ascii.ob_base,
            & toplevel_consts_74._ascii.ob_base,
            & toplevel_consts_75._ascii.ob_base,
            & toplevel_consts_76.ob_base.ob_base,
            & toplevel_consts_77.ob_base.ob_base,
            & toplevel_consts_78.ob_base.ob_base,
            Py_False,
            & toplevel_consts_80.ob_base,
            & toplevel_consts_81.ob_base,
            & toplevel_consts_82.ob_base,
            & toplevel_consts_83._object.ob_base.ob_base,
            Py_True,
            & toplevel_consts_85.ob_base,
            & toplevel_consts_86.ob_base,
            & toplevel_consts_85_name._ascii.ob_base,
            & toplevel_consts_88._ascii.ob_base,
            & toplevel_consts_89._object.ob_base.ob_base,
            & toplevel_consts_90.ob_base,
            & toplevel_consts_91.ob_base,
            & toplevel_consts_90_name._ascii.ob_base,
            & toplevel_consts_93.ob_base,
            & toplevel_consts_94.ob_base,
            & toplevel_consts_95.ob_base,
            & toplevel_consts_96.ob_base,
            & toplevel_consts_97.ob_base,
            & toplevel_consts_98.ob_base,
            & toplevel_consts_99._object.ob_base.ob_base,
            & toplevel_consts_100.ob_base,
            & toplevel_consts_101.ob_base,
            & toplevel_consts_102._object.ob_base.ob_base,
            & toplevel_consts_103.ob_base,
            & toplevel_consts_103_consts_0._ascii.ob_base,
            & toplevel_consts_105.ob_base,
            & toplevel_consts_106.ob_base,
            & toplevel_consts_107._object.ob_base.ob_base,
            & toplevel_consts_108.ob_base,
            & toplevel_consts_109.ob_base,
            & toplevel_consts_110._object.ob_base.ob_base,
            & toplevel_consts_111.ob_base,
            & toplevel_consts_112._ascii.ob_base,
            & toplevel_consts_113._ascii.ob_base,
            & toplevel_consts_93_names_0._ascii.ob_base,
            & toplevel_consts_115._object.ob_base.ob_base,
            & toplevel_consts_116.ob_base,
            & toplevel_consts_117.ob_base,
            & toplevel_consts_118.ob_base,
            & toplevel_consts_119.ob_base,
            & toplevel_consts_120.ob_base,
            & toplevel_consts_121._object.ob_base.ob_base,
            & toplevel_consts_122.ob_base,
            & toplevel_consts_123.ob_base,
            & toplevel_consts_122_name._ascii.ob_base,
            & toplevel_consts_123_name._ascii.ob_base,
            & toplevel_consts_119_name._ascii.ob_base,
            & toplevel_consts_127.ob_base,
            & toplevel_consts_128.ob_base,
            & toplevel_consts_127_name._ascii.ob_base,
            & toplevel_consts_128_name._ascii.ob_base,
            & toplevel_consts_131._ascii.ob_base,
            & toplevel_consts_132._ascii.ob_base,
            & toplevel_consts_94_consts_1.ob_base.ob_base,
            & toplevel_consts_134.ob_base,
            & toplevel_consts_135.ob_base,
            & toplevel_consts_134_names_9._ascii.ob_base,
            & toplevel_consts_134_name._ascii.ob_base,
            & toplevel_consts_138.ob_base,
            & toplevel_consts_139.ob_base,
            & toplevel_consts_85_names_3._ascii.ob_base,
            & toplevel_consts_141.ob_base,
            & toplevel_consts_141_consts_0._ascii.ob_base,
            & toplevel_consts_143.ob_base,
            & toplevel_consts_143_consts_0._ascii.ob_base,
            & toplevel_consts_145.ob_base,
            & toplevel_consts_146._object.ob_base.ob_base,
            & toplevel_consts_147._object.ob_base.ob_base,
            & toplevel_consts_148._object.ob_base.ob_base,
            & toplevel_consts_5_consts._object.ob_base.ob_base,
            & toplevel_consts_150._object.ob_base.ob_base,
            & toplevel_consts_151._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_names_5 = {
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
    ._data = "_collections_abc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_names_11 = {
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
    ._data = "builtin_module_names",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_12 = {
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
    ._data = "_names",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_21 = {
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
        uint8_t _data[10];
    }
toplevel_names_22 = {
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
    ._data = "posixpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_25 = {
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
toplevel_names_27 = {
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
    ._data = "ntpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_28 = {
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
        uint8_t _data[4];
    }
toplevel_names_41 = {
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
        uint8_t _data[16];
    }
toplevel_names_43 = {
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
    ._data = "supports_dir_fd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_names_44 = {
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
    ._data = "supports_effective_ids",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_46 = {
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
    ._data = "supports_fd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_names_47 = {
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
    ._data = "supports_follow_symlinks",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_95 = {
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
        uint8_t _data[4];
    }
toplevel_names_102 = {
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
    ._data = "ABC",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[106];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 106,
        },
        .ob_item = {
            & toplevel_consts_141_names_3._ascii.ob_base,
            & toplevel_consts_141_names_4._ascii.ob_base,
            & toplevel_consts_85_names_0._ascii.ob_base,
            & toplevel_consts_27._ascii.ob_base,
            & toplevel_consts_90_names_6._ascii.ob_base,
            & toplevel_names_5._ascii.ob_base,
            & toplevel_consts_3_0._ascii.ob_base,
            & toplevel_consts_105_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_138_names_1._ascii.ob_base,
            & toplevel_consts_141_names_9._ascii.ob_base,
            & toplevel_names_11._ascii.ob_base,
            & toplevel_names_12._ascii.ob_base,
            & toplevel_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_5_name._ascii.ob_base,
            & toplevel_consts_6_name._ascii.ob_base,
            & toplevel_consts_4_7._ascii.ob_base,
            & toplevel_consts_4_5._ascii.ob_base,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_86_names_5._ascii.ob_base,
            & toplevel_names_21._ascii.ob_base,
            & toplevel_names_22._ascii.ob_base,
            & toplevel_consts_4_8._ascii.ob_base,
            & toplevel_consts_12_0._ascii.ob_base,
            & toplevel_names_25._ascii.ob_base,
            & toplevel_consts_13._ascii.ob_base,
            & toplevel_names_27._ascii.ob_base,
            & toplevel_names_28._ascii.ob_base,
            & toplevel_consts_16._ascii.ob_base,
            & toplevel_consts_4_1._ascii.ob_base,
            & toplevel_consts_4_2._ascii.ob_base,
            & toplevel_consts_4_3._ascii.ob_base,
            & toplevel_consts_4_4._ascii.ob_base,
            & toplevel_consts_4_6._ascii.ob_base,
            & toplevel_consts_4_17._ascii.ob_base,
            & toplevel_consts_4_0._ascii.ob_base,
            & toplevel_consts_4_9._ascii.ob_base,
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_19_names_0._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_names_41._ascii.ob_base,
            & toplevel_consts_19_names_2._ascii.ob_base,
            & toplevel_names_43._ascii.ob_base,
            & toplevel_names_44._ascii.ob_base,
            & toplevel_consts_19_names_3._ascii.ob_base,
            & toplevel_names_46._ascii.ob_base,
            & toplevel_names_47._ascii.ob_base,
            & toplevel_consts_4_10._ascii.ob_base,
            & toplevel_consts_4_11._ascii.ob_base,
            & toplevel_consts_4_12._ascii.ob_base,
            & toplevel_consts_80_names_3._ascii.ob_base,
            & toplevel_consts_81_name._ascii.ob_base,
            & toplevel_consts_82_name._ascii.ob_base,
            & toplevel_consts_85_name._ascii.ob_base,
            & toplevel_consts_85_names_2._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_56._ascii.ob_base,
            & toplevel_consts_90_name._ascii.ob_base,
            & toplevel_consts_90_names_11._ascii.ob_base,
            & toplevel_consts_93_name._ascii.ob_base,
            & toplevel_consts_94_name._ascii.ob_base,
            & toplevel_consts_95_name._ascii.ob_base,
            & toplevel_consts_96_name._ascii.ob_base,
            & toplevel_consts_95_names_0._ascii.ob_base,
            & toplevel_consts_96_names_0._ascii.ob_base,
            & toplevel_consts_97_names_0._ascii.ob_base,
            & toplevel_consts_4_15._ascii.ob_base,
            & toplevel_consts_102_0._ascii.ob_base,
            & toplevel_consts_102_1._ascii.ob_base,
            & toplevel_consts_103_consts_0._ascii.ob_base,
            & toplevel_consts_105_name._ascii.ob_base,
            & toplevel_consts_100_names_2._ascii.ob_base,
            & toplevel_consts_106_name._ascii.ob_base,
            & toplevel_consts_101_names_7._ascii.ob_base,
            & toplevel_consts_108_name._ascii.ob_base,
            & toplevel_consts_103_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_80_names_7._ascii.ob_base,
            & toplevel_consts_109_names_0._ascii.ob_base,
            & toplevel_consts_109_name._ascii.ob_base,
            & toplevel_consts_111_name._ascii.ob_base,
            & toplevel_consts_4_13._ascii.ob_base,
            & toplevel_consts_4_14._ascii.ob_base,
            & toplevel_consts_115_0._ascii.ob_base,
            & toplevel_consts_115_1._ascii.ob_base,
            & toplevel_consts_115_2._ascii.ob_base,
            & toplevel_consts_116_name._ascii.ob_base,
            & toplevel_consts_113._ascii.ob_base,
            & toplevel_consts_118_name._ascii.ob_base,
            & toplevel_consts_119_name._ascii.ob_base,
            & toplevel_consts_120_name._ascii.ob_base,
            & toplevel_consts_122_name._ascii.ob_base,
            & toplevel_consts_123_name._ascii.ob_base,
            & toplevel_consts_127_name._ascii.ob_base,
            & toplevel_consts_128_name._ascii.ob_base,
            & toplevel_names_95._ascii.ob_base,
            & toplevel_consts_134_name._ascii.ob_base,
            & toplevel_consts_134_names_9._ascii.ob_base,
            & toplevel_consts_4_16._ascii.ob_base,
            & toplevel_consts_139_name._ascii.ob_base,
            & toplevel_consts_85_names_3._ascii.ob_base,
            & toplevel_consts_103_names_0._ascii.ob_base,
            & toplevel_names_102._ascii.ob_base,
            & toplevel_consts_141_consts_0._ascii.ob_base,
            & toplevel_consts_143_consts_0._ascii.ob_base,
            & toplevel_consts_145_name._ascii.ob_base,
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
        char ob_sval[389];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 388,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x18\x08\x01\x08\x01\x0c\x02\x0c\x02\x06\x02\x08\x03\x06\x05\x06\x03\x08\x08\x04\x01\x04\x01\x08\x01\x02\x01\x0c\x01\x0e\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x08\x02\x02\x02\x0e\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x08\x03\x10\x01\x04\x01\x08\x02\x04\x01\x04\x01\x08\x01\x02\x01\x0c\x01\x0e\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x08\x02\x08\x02\x10\x01\x02\x01\x02\x02\x0e\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x08\x04\x0a\x02\x28\x01\x02\x03\x0a\x03\x06\x01\x06\x01\x06\x04\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x04\x01\x06\x02\x0a\x01\x04\x01\x06\x02\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0c\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x14\x01\x0a\x01\x04\x01\x06\x02\x0a\x01\x0a\x16\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x04\x01\x02\x02\x02\x01\x02\x01\x02\x01\x04\x06\x04\x01\x04\x01\x08\x05\x06\x20\x06\x16\x10\x1a\x08\x02\x06\x3e\x0c\x52\x1c\x02\x10\x02\x06\x30\x0c\x38\x06\x02\x06\x07\x06\x08\x06\x07\x06\x09\x06\x08\x10\x09\x08\x02\x08\x20\x10\x2d\x0e\x02\x06\x49\x06\x1e\x02\x01\x08\x03\x08\x06\x0c\x01\x06\x02\x06\x01\x06\x06\x04\x01\x04\x01\x04\xfe\x02\x03\x08\x02\x0c\x06\x06\x02\x0a\x1e\x02\x01\x1e\x03\x04\x02\x08\x01\x10\x02\x06\x06\x06\x1b\x06\x09\x06\x0c\x06\x0a\x10\x0b\x0a\x03\x06\x04\x06\x09\x10\x0c\x0a\x03\x06\x03\x06\x0a\x10\x0c\x0c\x04\x08\x02\x0c\x16\x0c\x16\x08\x03\x06\x0b\x0a\x1f\x04\x01\x06\x01\x10\x03\x0a\x12\x0c\x01\x0a\x11\x04\xee",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[445];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 444,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x15\x08\x03\x08\x01\x08\x01\x0c\x02\x0c\x02\x06\x02\x06\x06\x02\xfd\x06\x06\x06\x06\x06\x04\x02\x29\x04\xd8\x04\x01\x08\x01\x02\x05\x0c\xfd\x0e\x01\x02\x80\x02\x01\x0a\x01\x06\x80\x08\x01\x02\x05\x0e\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x08\x02\x10\x01\x04\x01\x06\x02\x02\x15\x04\xec\x04\x01\x08\x01\x02\x05\x0c\xfd\x0e\x01\x02\x80\x02\x01\x0a\x01\x06\x80\x08\x01\x08\x02\x10\x01\x02\x01\x02\x05\x0e\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x08\x03\x0a\x02\x28\x02\x02\x02\x06\x03\x04\x55\x06\xac\x06\x03\x06\x02\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x04\x01\x06\x02\x0a\x01\x04\x01\x06\x02\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0c\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x06\x01\x04\x01\x06\xff\x0e\x01\x04\x01\x06\x02\x0a\x01\x0a\x16\x0a\x01\x0a\x01\x0a\x01\x06\x01\x0e\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x04\x01\x02\x02\x02\x01\x02\x01\x02\x01\x04\x06\x04\x01\x04\x01\x02\x05\x06\x1e\x06\x16\x06\x1a\x10\x02\x02\x02\x06\x3c\x06\x52\x0c\x02\x0a\x02\x04\x6a\x0a\x96\x04\x6a\x06\x98\x0a\x2e\x06\x38\x0c\x02\x06\x07\x06\x08\x06\x07\x06\x09\x06\x08\x06\x09\x10\x02\x02\x02\x06\x1d\x02\x03\x06\x29\x10\x04\x08\x49\x02\xb9\x04\x47\x06\x1d\x06\x03\x02\x01\x02\x03\x06\x04\x08\x02\x0c\x01\x02\x02\x04\x12\x06\xf2\x06\x03\x04\x01\x06\x01\x02\xfe\x02\x03\x02\x02\x06\x04\x0c\x02\x06\x1e\x0a\x02\x02\x01\x06\x03\x04\x50\x06\xb0\x04\x50\x06\xb0\x04\x50\x04\xb2\x08\x01\x10\x02\x06\x1f\x06\x09\x06\x0a\x06\x0c\x06\x0a\x10\x03\x06\x03\x04\x19\x06\xf2\x06\x0b\x10\x03\x06\x03\x04\x19\x06\xf2\x06\x0b\x10\x03\x08\x04\x04\x2e\x02\xd4\x06\x13\x0c\x17\x0c\x02\x02\x03\x06\x06\x06\x20\x06\x04\x04\x02\x04\xff\x06\x01\x08\x12\x04\xf1\x04\x0f\x06\x03\x04\x22\x0c\xee\x0e\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1595];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1594,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x12\x01\x12\x01\x12\x01\x12\x01\x2c\x01\x2c\x01\x2c\x01\x2c\x01\x2c\x01\x2c\x10\x14\x15\x19\x1a\x1d\x15\x1e\x10\x1f\x01\x0d\x0a\x0d\x0a\x22\x01\x07\x0b\x15\x0b\x15\x0b\x15\x01\x08\x01\x1d\x01\x1d\x01\x1d\x01\x37\x01\x37\x01\x37\x04\x0b\x0f\x15\x04\x15\x01\x35\x0c\x13\x05\x09\x0f\x13\x05\x0c\x05\x18\x05\x18\x05\x18\x05\x18\x05\x0d\x09\x20\x09\x20\x09\x20\x09\x20\x09\x20\x09\x20\x09\x10\x09\x20\x18\x1f\x09\x20\x09\x20\x09\x20\x09\x20\x00\x00\x0c\x17\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x05\x0d\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x00\x00\x0c\x17\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x05\x11\x05\x11\x05\x11\x05\x11\x05\x0c\x05\x2d\x14\x25\x26\x2b\x14\x2c\x05\x2d\x05\x2d\x05\x2d\x09\x0e\x09\x0e\x06\x0a\x0e\x14\x06\x14\x01\x35\x0c\x10\x05\x09\x0f\x15\x05\x0c\x05\x15\x05\x15\x05\x15\x05\x15\x05\x0d\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x10\x09\x20\x18\x1f\x09\x20\x09\x20\x09\x20\x09\x20\x00\x00\x0c\x17\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x05\x1a\x05\x1a\x05\x1a\x05\x1a\x05\x0e\x05\x0e\x05\x0e\x05\x0e\x05\x0c\x05\x2a\x14\x25\x26\x28\x14\x29\x05\x2a\x05\x2a\x05\x2a\x09\x0b\x05\x0d\x09\x27\x09\x27\x09\x27\x09\x27\x09\x27\x09\x27\x09\x27\x00\x00\x0c\x17\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x0b\x16\x17\x34\x0b\x35\x05\x35\x1a\x1e\x01\x04\x01\x0c\x0d\x16\x01\x17\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x05\x0b\x04\x0b\x0c\x1d\x04\x1e\x01\x0d\x01\x0d\x10\x17\x10\x19\x05\x0d\x05\x23\x05\x23\x05\x23\x0c\x0f\x0c\x11\x05\x09\x05\x09\x0a\x1a\x1d\x25\x05\x26\x05\x26\x05\x09\x0a\x19\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x19\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x18\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x1a\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x17\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x18\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x19\x1d\x25\x05\x26\x05\x26\x05\x09\x0a\x18\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x17\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x1b\x1d\x27\x05\x28\x05\x28\x05\x09\x0a\x19\x1d\x25\x05\x26\x05\x26\x05\x09\x0a\x1a\x1d\x26\x05\x27\x05\x27\x05\x09\x0a\x19\x1d\x25\x05\x26\x05\x26\x05\x09\x0a\x19\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x1a\x1d\x24\x05\x25\x05\x25\x17\x1b\x05\x14\x0c\x0f\x0c\x11\x05\x09\x05\x09\x0a\x1a\x1d\x25\x05\x26\x05\x26\x1e\x22\x05\x1b\x0c\x0f\x0c\x11\x05\x09\x05\x09\x0a\x17\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x17\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x17\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x1a\x1d\x26\x05\x27\x05\x27\x05\x09\x0a\x1a\x1d\x26\x05\x27\x05\x27\x05\x09\x0a\x18\x1d\x25\x05\x26\x05\x26\x05\x09\x05\x13\x0e\x12\x05\x13\x05\x13\x05\x13\x05\x09\x0a\x1a\x1d\x27\x05\x28\x05\x28\x05\x09\x0a\x19\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x18\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x1a\x1d\x27\x05\x28\x05\x28\x08\x0f\x10\x19\x08\x1a\x05\x29\x05\x29\x1f\x26\x27\x31\x1f\x32\x05\x29\x05\x29\x09\x0d\x0e\x1d\x1f\x28\x09\x29\x09\x29\x13\x17\x05\x10\x0c\x0f\x0c\x11\x05\x09\x05\x09\x0a\x1a\x1d\x25\x05\x26\x05\x26\x05\x09\x0a\x19\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x18\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x19\x1d\x26\x05\x27\x05\x27\x05\x09\x0a\x17\x1d\x24\x05\x25\x05\x25\x08\x0f\x10\x18\x08\x19\x05\x25\x05\x25\x09\x0d\x0e\x1b\x1d\x24\x09\x25\x09\x25\x05\x09\x0a\x17\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x18\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x16\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x18\x1d\x23\x05\x24\x05\x24\x05\x09\x0a\x1a\x1d\x24\x05\x25\x05\x25\x05\x09\x0a\x16\x1d\x23\x05\x24\x05\x24\x20\x24\x05\x1d\x09\x0d\x09\x18\x09\x11\x09\x0d\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x19\x1e\x01\x12\x01\x12\x01\x12\x01\x26\x01\x26\x01\x26\x01\x11\x01\x11\x01\x11\x01\x08\x01\x36\x10\x35\x10\x35\x10\x35\x01\x36\x01\x36\x01\x36\x17\x1b\x01\x3d\x01\x3d\x01\x3d\x01\x21\x01\x21\x01\x21\x01\x08\x01\x17\x10\x16\x01\x17\x01\x17\x01\x17\x05\x09\x0b\x0f\x04\x10\x14\x23\x04\x23\x01\x1c\x01\x1c\x29\x30\x32\x36\x28\x37\x3b\x46\x28\x46\x01\x1c\x01\x1c\x13\x16\x47\x4c\x55\x59\x05\x19\x05\x19\x05\x19\x05\x19\x05\x19\x05\x30\x05\x30\x05\x30\x05\x0c\x05\x1c\x14\x1b\x05\x1c\x05\x1c\x05\x1c\x01\x16\x01\x16\x01\x16\x01\x21\x01\x21\x01\x21\x01\x17\x01\x17\x01\x17\x01\x22\x01\x22\x01\x22\x01\x19\x01\x19\x01\x19\x01\x1e\x01\x1e\x01\x1e\x01\x08\x01\x49\x10\x48\x10\x48\x10\x48\x01\x49\x01\x49\x01\x49\x1e\x22\x01\x13\x01\x13\x01\x13\x17\x1b\x01\x24\x01\x24\x01\x24\x01\x35\x01\x35\x01\x35\x01\x35\x01\x35\x01\x35\x01\x35\x01\x35\x01\x13\x01\x13\x01\x13\x01\x13\x10\x1e\x01\x13\x01\x13\x01\x18\x01\x18\x01\x18\x0b\x19\x0b\x1b\x01\x08\x05\x13\x19\x1d\x01\x25\x01\x25\x01\x25\x1b\x1f\x23\x27\x1b\x27\x01\x17\x01\x08\x01\x35\x10\x34\x01\x35\x01\x35\x01\x35\x04\x1a\x01\x2c\x01\x2c\x05\x15\x05\x15\x05\x15\x10\x18\x19\x20\x19\x26\x09\x15\x17\x1c\x09\x15\x17\x1c\x10\x1d\x05\x0d\x09\x15\x1e\x22\x05\x2a\x05\x2a\x05\x2a\x05\x0c\x05\x2c\x14\x2b\x05\x2c\x05\x2c\x05\x2c\x01\x1e\x01\x1e\x01\x1e\x16\x1e\x16\x20\x01\x13\x01\x09\x0b\x13\x05\x0d\x04\x0b\x0c\x12\x04\x13\x01\x41\x01\x41\x1c\x23\x24\x2c\x1c\x2d\x01\x41\x01\x41\x32\x39\x3a\x41\x32\x42\x01\x41\x01\x41\x0e\x0f\x05\x0b\x1c\x1d\x05\x1d\x05\x0d\x10\x19\x05\x0c\x05\x38\x14\x37\x14\x37\x14\x37\x05\x38\x05\x38\x05\x38\x05\x33\x05\x33\x05\x33\x05\x38\x05\x38\x05\x38\x05\x38\x05\x38\x05\x38\x05\x39\x05\x39\x05\x39\x05\x39\x05\x39\x05\x39\x05\x0c\x05\x41\x14\x40\x14\x40\x14\x40\x05\x41\x05\x41\x05\x41\x04\x0b\x0c\x14\x04\x15\x01\x2a\x01\x2a\x05\x28\x05\x28\x05\x28\x05\x33\x05\x33\x05\x33\x05\x0c\x05\x2a\x15\x1d\x1f\x28\x14\x29\x05\x2a\x05\x2a\x05\x2a\x04\x0b\x0c\x15\x04\x16\x01\x2c\x01\x2c\x05\x29\x05\x29\x05\x29\x05\x34\x05\x34\x05\x34\x05\x0c\x05\x2c\x15\x1e\x20\x2a\x14\x2b\x05\x2c\x05\x2c\x05\x2c\x04\x07\x04\x10\x14\x1d\x04\x1d\x01\x1c\x01\x1c\x19\x1c\x05\x31\x05\x31\x05\x31\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x0c\x05\x1c\x14\x1b\x05\x1c\x05\x1c\x05\x1c\x15\x18\x01\x43\x01\x43\x01\x43\x01\x43\x01\x43\x01\x43\x08\x0f\x10\x18\x08\x19\x01\x1f\x01\x1f\x0e\x15\x05\x0b\x17\x1f\x05\x0b\x05\x14\x01\x32\x01\x32\x01\x32\x01\x32\x10\x13\x10\x17\x01\x32\x01\x32\x04\x08\x0c\x10\x04\x10\x01\x0a\x01\x0a\x05\x2b\x05\x2b\x05\x2b\x05\x2b\x05\x2b\x05\x2b\x05\x0a\x05\x0a\x05\x0a\x05\x0a\x05\x0a\x01\x0a\x01\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[72];
    }
toplevel_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 71,
    },
    .ob_shash = -1,
    .ob_sval = "\xb5\x0c\x41\x02\x00\xc1\x02\x04\x41\x09\x03\xc1\x08\x01\x41\x09\x03\xc1\x11\x06\x41\x18\x00\xc1\x18\x04\x41\x1f\x03\xc1\x1e\x01\x41\x1f\x03\xc1\x3d\x0c\x42\x0a\x00\xc2\x0a\x04\x42\x11\x03\xc2\x10\x01\x42\x11\x03\xc2\x26\x06\x42\x2d\x00\xc2\x2d\x04\x42\x34\x03\xc2\x33\x01\x42\x34\x03",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_os_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

