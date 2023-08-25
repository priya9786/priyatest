#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[329];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 328,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x5a\x01\x67\x00\x64\x02\xa2\x01\x5a\x02\x64\x03\x64\x04\x6c\x03\x5a\x03\x64\x03\x64\x04\x6c\x04\x5a\x04\x64\x03\x64\x05\x6c\x03\x6d\x05\x5a\x05\x6d\x06\x5a\x06\x6d\x07\x5a\x07\x6d\x08\x5a\x08\x6d\x09\x5a\x09\x6d\x0a\x5a\x0a\x6d\x0b\x5a\x0b\x6d\x0c\x5a\x0c\x6d\x0d\x5a\x0d\x6d\x0e\x5a\x0e\x6d\x0f\x5a\x0f\x6d\x10\x5a\x10\x6d\x11\x5a\x11\x6d\x12\x5a\x12\x6d\x13\x5a\x13\x01\x00\x64\x06\x84\x00\x5a\x14\x64\x07\x65\x07\x5f\x15\x64\x03\x5a\x16\x64\x08\x5a\x17\x64\x09\x5a\x18\x47\x00\x64\x0a\x84\x00\x64\x0b\x65\x03\x6a\x19\x65\x04\x6a\x1a\x64\x0c\xaa\x04\x5a\x1b\x47\x00\x64\x0d\x84\x00\x64\x0e\x65\x03\x6a\x1c\x65\x1b\xa9\x04\x5a\x1d\x47\x00\x64\x0f\x84\x00\x64\x10\x65\x03\x6a\x1e\x65\x1b\xa9\x04\x5a\x1f\x47\x00\x64\x11\x84\x00\x64\x12\x65\x03\x6a\x20\x65\x1b\xa9\x04\x5a\x21\x65\x1d\xa0\x22\x65\x0a\xa8\x01\xa9\x01\x01\x00\x65\x0b\x65\x0d\x65\x0e\x65\x10\x65\x0f\x66\x05\x44\x00\x5d\x08\x5a\x23\x65\x1f\xa0\x22\x65\x23\xa8\x01\xa9\x01\x01\x00\x71\x72\x65\x0c\x65\x13\x66\x02\x44\x00\x5d\x08\x5a\x23\x65\x21\xa0\x22\x65\x23\xa8\x01\xa9\x01\x01\x00\x71\x7f\x5b\x23\x09\x00\x64\x03\x64\x13\x6c\x03\x6d\x24\x5a\x24\x01\x00\x6e\x0b\x23\x00\x65\x25\x79\x98\x01\x00\x59\x00\x64\x04\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x65\x1d\xa0\x22\x65\x24\xa8\x01\xa9\x01\x01\x00\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1474];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1473,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x54\x68\x65\x20\x69\x6f\x20\x6d\x6f\x64\x75\x6c\x65\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x74\x68\x65\x20\x50\x79\x74\x68\x6f\x6e\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x73\x20\x74\x6f\x20\x73\x74\x72\x65\x61\x6d\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x2e\x20\x54\x68\x65\x0a\x62\x75\x69\x6c\x74\x69\x6e\x20\x6f\x70\x65\x6e\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x69\x6e\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x41\x74\x20\x74\x68\x65\x20\x74\x6f\x70\x20\x6f\x66\x20\x74\x68\x65\x20\x49\x2f\x4f\x20\x68\x69\x65\x72\x61\x72\x63\x68\x79\x20\x69\x73\x20\x74\x68\x65\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x62\x61\x73\x65\x20\x63\x6c\x61\x73\x73\x20\x49\x4f\x42\x61\x73\x65\x2e\x20\x49\x74\x0a\x64\x65\x66\x69\x6e\x65\x73\x20\x74\x68\x65\x20\x62\x61\x73\x69\x63\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x74\x6f\x20\x61\x20\x73\x74\x72\x65\x61\x6d\x2e\x20\x4e\x6f\x74\x65\x2c\x20\x68\x6f\x77\x65\x76\x65\x72\x2c\x20\x74\x68\x61\x74\x20\x74\x68\x65\x72\x65\x20\x69\x73\x20\x6e\x6f\x0a\x73\x65\x70\x61\x72\x61\x74\x69\x6f\x6e\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x72\x65\x61\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x77\x72\x69\x74\x69\x6e\x67\x20\x74\x6f\x20\x73\x74\x72\x65\x61\x6d\x73\x3b\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x61\x72\x65\x0a\x61\x6c\x6c\x6f\x77\x65\x64\x20\x74\x6f\x20\x72\x61\x69\x73\x65\x20\x61\x6e\x20\x4f\x53\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x74\x68\x65\x79\x20\x64\x6f\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x61\x20\x67\x69\x76\x65\x6e\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x45\x78\x74\x65\x6e\x64\x69\x6e\x67\x20\x49\x4f\x42\x61\x73\x65\x20\x69\x73\x20\x52\x61\x77\x49\x4f\x42\x61\x73\x65\x20\x77\x68\x69\x63\x68\x20\x64\x65\x61\x6c\x73\x20\x73\x69\x6d\x70\x6c\x79\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x72\x65\x61\x64\x69\x6e\x67\x20\x61\x6e\x64\x0a\x77\x72\x69\x74\x69\x6e\x67\x20\x6f\x66\x20\x72\x61\x77\x20\x62\x79\x74\x65\x73\x20\x74\x6f\x20\x61\x20\x73\x74\x72\x65\x61\x6d\x2e\x20\x46\x69\x6c\x65\x49\x4f\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x20\x52\x61\x77\x49\x4f\x42\x61\x73\x65\x20\x74\x6f\x20\x70\x72\x6f\x76\x69\x64\x65\x0a\x61\x6e\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x74\x6f\x20\x4f\x53\x20\x66\x69\x6c\x65\x73\x2e\x0a\x0a\x42\x75\x66\x66\x65\x72\x65\x64\x49\x4f\x42\x61\x73\x65\x20\x64\x65\x61\x6c\x73\x20\x77\x69\x74\x68\x20\x62\x75\x66\x66\x65\x72\x69\x6e\x67\x20\x6f\x6e\x20\x61\x20\x72\x61\x77\x20\x62\x79\x74\x65\x20\x73\x74\x72\x65\x61\x6d\x20\x28\x52\x61\x77\x49\x4f\x42\x61\x73\x65\x29\x2e\x20\x49\x74\x73\x0a\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x2c\x20\x42\x75\x66\x66\x65\x72\x65\x64\x57\x72\x69\x74\x65\x72\x2c\x20\x42\x75\x66\x66\x65\x72\x65\x64\x52\x65\x61\x64\x65\x72\x2c\x20\x61\x6e\x64\x20\x42\x75\x66\x66\x65\x72\x65\x64\x52\x57\x50\x61\x69\x72\x20\x62\x75\x66\x66\x65\x72\x0a\x73\x74\x72\x65\x61\x6d\x73\x20\x74\x68\x61\x74\x20\x61\x72\x65\x20\x72\x65\x61\x64\x61\x62\x6c\x65\x2c\x20\x77\x72\x69\x74\x61\x62\x6c\x65\x2c\x20\x61\x6e\x64\x20\x62\x6f\x74\x68\x20\x72\x65\x73\x70\x65\x63\x74\x69\x76\x65\x6c\x79\x2e\x0a\x42\x75\x66\x66\x65\x72\x65\x64\x52\x61\x6e\x64\x6f\x6d\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x61\x20\x62\x75\x66\x66\x65\x72\x65\x64\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x74\x6f\x20\x72\x61\x6e\x64\x6f\x6d\x20\x61\x63\x63\x65\x73\x73\x0a\x73\x74\x72\x65\x61\x6d\x73\x2e\x20\x42\x79\x74\x65\x73\x49\x4f\x20\x69\x73\x20\x61\x20\x73\x69\x6d\x70\x6c\x65\x20\x73\x74\x72\x65\x61\x6d\x20\x6f\x66\x20\x69\x6e\x2d\x6d\x65\x6d\x6f\x72\x79\x20\x62\x79\x74\x65\x73\x2e\x0a\x0a\x41\x6e\x6f\x74\x68\x65\x72\x20\x49\x4f\x42\x61\x73\x65\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x2c\x20\x54\x65\x78\x74\x49\x4f\x42\x61\x73\x65\x2c\x20\x64\x65\x61\x6c\x73\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x0a\x6f\x66\x20\x73\x74\x72\x65\x61\x6d\x73\x20\x69\x6e\x74\x6f\x20\x74\x65\x78\x74\x2e\x20\x54\x65\x78\x74\x49\x4f\x57\x72\x61\x70\x70\x65\x72\x2c\x20\x77\x68\x69\x63\x68\x20\x65\x78\x74\x65\x6e\x64\x73\x20\x69\x74\x2c\x20\x69\x73\x20\x61\x20\x62\x75\x66\x66\x65\x72\x65\x64\x20\x74\x65\x78\x74\x0a\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x74\x6f\x20\x61\x20\x62\x75\x66\x66\x65\x72\x65\x64\x20\x72\x61\x77\x20\x73\x74\x72\x65\x61\x6d\x20\x28\x60\x42\x75\x66\x66\x65\x72\x65\x64\x49\x4f\x42\x61\x73\x65\x60\x29\x2e\x20\x46\x69\x6e\x61\x6c\x6c\x79\x2c\x20\x53\x74\x72\x69\x6e\x67\x49\x4f\x0a\x69\x73\x20\x61\x6e\x20\x69\x6e\x2d\x6d\x65\x6d\x6f\x72\x79\x20\x73\x74\x72\x65\x61\x6d\x20\x66\x6f\x72\x20\x74\x65\x78\x74\x2e\x0a\x0a\x41\x72\x67\x75\x6d\x65\x6e\x74\x20\x6e\x61\x6d\x65\x73\x20\x61\x72\x65\x20\x6e\x6f\x74\x20\x70\x61\x72\x74\x20\x6f\x66\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x2c\x20\x61\x6e\x64\x20\x6f\x6e\x6c\x79\x20\x74\x68\x65\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x0a\x6f\x66\x20\x6f\x70\x65\x6e\x28\x29\x20\x61\x72\x65\x20\x69\x6e\x74\x65\x6e\x64\x65\x64\x20\x74\x6f\x20\x62\x65\x20\x75\x73\x65\x64\x20\x61\x73\x20\x6b\x65\x79\x77\x6f\x72\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x2e\x0a\x0a\x64\x61\x74\x61\x3a\x0a\x0a\x44\x45\x46\x41\x55\x4c\x54\x5f\x42\x55\x46\x46\x45\x52\x5f\x53\x49\x5a\x45\x0a\x0a\x20\x20\x20\x41\x6e\x20\x69\x6e\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x69\x6e\x67\x20\x74\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x62\x75\x66\x66\x65\x72\x20\x73\x69\x7a\x65\x20\x75\x73\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x27\x73\x20\x62\x75\x66\x66\x65\x72\x65\x64\x0a\x20\x20\x20\x49\x2f\x4f\x20\x63\x6c\x61\x73\x73\x65\x73\x2e\x20\x6f\x70\x65\x6e\x28\x29\x20\x75\x73\x65\x73\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x27\x73\x20\x62\x6c\x6b\x73\x69\x7a\x65\x20\x28\x61\x73\x20\x6f\x62\x74\x61\x69\x6e\x65\x64\x20\x62\x79\x20\x6f\x73\x2e\x73\x74\x61\x74\x29\x20\x69\x66\x0a\x20\x20\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x2e\x0a",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[236];
    }
toplevel_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 235,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Guido van Rossum <guido@python.org>, Mike Verdone <mike.verdone@gmail.com>, Mark Russell <mark.russell@zen.co.uk>, Antoine Pitrou <solipsis@pitrou.net>, Amaury Forgeot d'Arc <amauryfa@gmail.com>, Benjamin Peterson <benjamin@python.org>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_2_0 = {
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
    ._data = "BlockingIOError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_2_1 = {
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
toplevel_consts_2_2 = {
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
        uint8_t _data[7];
    }
toplevel_consts_2_3 = {
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
    ._data = "IOBase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_2_4 = {
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
    ._data = "RawIOBase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_2_5 = {
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
    ._data = "FileIO",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_2_6 = {
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
    ._data = "BytesIO",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_2_7 = {
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
    ._data = "StringIO",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_2_8 = {
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
    ._data = "BufferedIOBase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_2_9 = {
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
    ._data = "BufferedReader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_2_10 = {
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
    ._data = "BufferedWriter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_2_11 = {
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
    ._data = "BufferedRWPair",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_2_12 = {
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
    ._data = "BufferedRandom",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_2_13 = {
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
    ._data = "TextIOBase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_2_14 = {
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
        uint8_t _data[21];
    }
toplevel_consts_2_15 = {
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
    ._data = "UnsupportedOperation",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_2_16 = {
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
toplevel_consts_2_17 = {
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
toplevel_consts_2_18 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_2_2._ascii.ob_base,
            & toplevel_consts_2_3._ascii.ob_base,
            & toplevel_consts_2_4._ascii.ob_base,
            & toplevel_consts_2_5._ascii.ob_base,
            & toplevel_consts_2_6._ascii.ob_base,
            & toplevel_consts_2_7._ascii.ob_base,
            & toplevel_consts_2_8._ascii.ob_base,
            & toplevel_consts_2_9._ascii.ob_base,
            & toplevel_consts_2_10._ascii.ob_base,
            & toplevel_consts_2_11._ascii.ob_base,
            & toplevel_consts_2_12._ascii.ob_base,
            & toplevel_consts_2_13._ascii.ob_base,
            & toplevel_consts_2_14._ascii.ob_base,
            & toplevel_consts_2_15._ascii.ob_base,
            & toplevel_consts_2_16._ascii.ob_base,
            & toplevel_consts_2_17._ascii.ob_base,
            & toplevel_consts_2_18._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_3 = {
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
        uint8_t _data[20];
    }
toplevel_consts_5_0 = {
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
    ._data = "DEFAULT_BUFFER_SIZE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_5_12 = {
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
    ._data = "IncrementalNewlineDecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5_13 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_5_0._ascii.ob_base,
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_consts_2_15._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_2_2._ascii.ob_base,
            & toplevel_consts_2_5._ascii.ob_base,
            & toplevel_consts_2_6._ascii.ob_base,
            & toplevel_consts_2_7._ascii.ob_base,
            & toplevel_consts_2_9._ascii.ob_base,
            & toplevel_consts_2_10._ascii.ob_base,
            & toplevel_consts_2_11._ascii.ob_base,
            & toplevel_consts_2_12._ascii.ob_base,
            & toplevel_consts_5_12._ascii.ob_base,
            & toplevel_consts_5_13._ascii.ob_base,
            & toplevel_consts_2_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x64\x01\x6b\x02\x72\x16\x64\x02\x64\x00\x6c\x00\x7d\x01\x7c\x01\xa0\x01\x64\x03\x74\x02\x64\x04\x64\x05\xa8\x04\xaa\x03\x01\x00\x74\x03\x61\x04\x74\x04\x53\x00\x74\x05\x7c\x00\xa9\x01\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_6_consts_1 = {
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
    ._data = "OpenWrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[44];
    }
toplevel_consts_6_consts_3 = {
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
    ._data = "OpenWrapper is deprecated, use open instead",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_6_consts_4 = {
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
        uint8_t _data[11];
    }
toplevel_consts_6_consts_5_0 = {
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
    ._data = "stacklevel",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_6_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_consts_5_0._ascii.ob_base,
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
toplevel_consts_6_consts = {
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
            & toplevel_consts_6_consts_1._ascii.ob_base,
            & toplevel_consts_3.ob_base.ob_base,
            & toplevel_consts_6_consts_3._ascii.ob_base,
            & toplevel_consts_6_consts_4.ob_base.ob_base,
            & toplevel_consts_6_consts_5._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_names_0 = {
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
        uint8_t _data[5];
    }
toplevel_consts_6_names_1 = {
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
    ._data = "warn",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_6_names_2 = {
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
    ._data = "DeprecationWarning",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_6_names_5 = {
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
            & toplevel_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_6_consts_1._ascii.ob_base,
            & toplevel_consts_6_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_6_varnames_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_6_varnames_0._ascii.ob_base,
            & toplevel_consts_6_names_0._ascii.ob_base,
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
toplevel_consts_6_freevars = {
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
toplevel_consts_6_filename = {
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
    ._data = "<frozen io>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_6_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x08\x06\x06\x01\x04\x01\x08\xff\x04\x03\x04\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x0b\x08\xfb\x02\x01\x02\x01\x02\xff\x0c\x01\x04\x02\x04\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0c\x10\x1d\x08\x1d\x05\x1b\x09\x18\x09\x18\x09\x18\x09\x18\x09\x11\x09\x38\x17\x44\x17\x29\x36\x37\x09\x38\x09\x38\x09\x38\x09\x38\x17\x1b\x09\x14\x10\x1b\x09\x1b\x0b\x19\x1a\x1e\x0b\x1f\x05\x1f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_6_exceptiontable = {
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
        char ob_sval[3];
    }
toplevel_consts_6_localspluskinds = {
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
    .co_stacksize = 6,
    .co_firstlineno = 60,
    .co_code = & toplevel_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_7 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_8 = {
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
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x65\x03\x6a\x04\x6a\x05\x5a\x05\x64\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_2_3._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_10_names_0 = {
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
toplevel_consts_10_names_1 = {
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
    ._data = "__qualname__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_10_names_3 = {
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
    ._data = "_io",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_names_4 = {
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
    ._data = "_IOBase",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_names_5 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_10_names_1._ascii.ob_base,
            & toplevel_consts_10_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_10_names_4._ascii.ob_base,
            & toplevel_consts_10_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x0f\x12\x0f\x1a\x0f\x22\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 87,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_12_0 = {
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
    ._data = "metaclass",
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_2_4._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_13_names_4 = {
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
    ._data = "_RawIOBase",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_10_names_1._ascii.ob_base,
            & toplevel_consts_10_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_10_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x0f\x12\x0f\x1d\x0f\x25\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 90,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_2_8._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_15_names_4 = {
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
    ._data = "_BufferedIOBase",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_10_names_1._ascii.ob_base,
            & toplevel_consts_10_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_10_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x0f\x12\x0f\x22\x0f\x2a\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 93,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_8._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_8._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_2_13._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_17_names_4 = {
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
    ._data = "_TextIOBase",
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
            & toplevel_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_10_names_1._ascii.ob_base,
            & toplevel_consts_10_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_consts_17_names_4._ascii.ob_base,
            & toplevel_consts_10_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x0f\x12\x0f\x1e\x0f\x26\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 96,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_13._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_13._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_19_0 = {
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
    ._data = "_WindowsConsoleIO",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_19 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_19_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._object.ob_base.ob_base,
            & toplevel_consts_3.ob_base.ob_base,
            Py_None,
            & toplevel_consts_5._object.ob_base.ob_base,
            & toplevel_consts_6.ob_base,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_6_consts_4.ob_base.ob_base,
            & toplevel_consts_10.ob_base,
            & toplevel_consts_2_3._ascii.ob_base,
            & toplevel_consts_12._object.ob_base.ob_base,
            & toplevel_consts_13.ob_base,
            & toplevel_consts_2_4._ascii.ob_base,
            & toplevel_consts_15.ob_base,
            & toplevel_consts_2_8._ascii.ob_base,
            & toplevel_consts_17.ob_base,
            & toplevel_consts_2_13._ascii.ob_base,
            & toplevel_consts_19._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_names_1 = {
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
    ._data = "__author__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_2 = {
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
        uint8_t _data[4];
    }
toplevel_names_4 = {
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
        uint8_t _data[8];
    }
toplevel_names_26 = {
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
    ._data = "ABCMeta",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_34 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_names_35 = {
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
    ._data = "klass",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_37 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[38];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 38,
        },
        .ob_item = {
            & toplevel_consts_10_names_5._ascii.ob_base,
            & toplevel_names_1._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_consts_10_names_3._ascii.ob_base,
            & toplevel_names_4._ascii.ob_base,
            & toplevel_consts_5_0._ascii.ob_base,
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_consts_2_15._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_2_2._ascii.ob_base,
            & toplevel_consts_2_5._ascii.ob_base,
            & toplevel_consts_2_6._ascii.ob_base,
            & toplevel_consts_2_7._ascii.ob_base,
            & toplevel_consts_2_9._ascii.ob_base,
            & toplevel_consts_2_10._ascii.ob_base,
            & toplevel_consts_2_11._ascii.ob_base,
            & toplevel_consts_2_12._ascii.ob_base,
            & toplevel_consts_5_12._ascii.ob_base,
            & toplevel_consts_5_13._ascii.ob_base,
            & toplevel_consts_2_14._ascii.ob_base,
            & toplevel_consts_6_name._ascii.ob_base,
            & toplevel_consts_10_names_1._ascii.ob_base,
            & toplevel_consts_2_16._ascii.ob_base,
            & toplevel_consts_2_17._ascii.ob_base,
            & toplevel_consts_2_18._ascii.ob_base,
            & toplevel_consts_10_names_4._ascii.ob_base,
            & toplevel_names_26._ascii.ob_base,
            & toplevel_consts_2_3._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_2_4._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_2_8._ascii.ob_base,
            & toplevel_consts_17_names_4._ascii.ob_base,
            & toplevel_consts_2_13._ascii.ob_base,
            & toplevel_names_34._ascii.ob_base,
            & toplevel_names_35._ascii.ob_base,
            & toplevel_consts_19_0._ascii.ob_base,
            & toplevel_names_37._ascii.ob_base,
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
        char ob_sval[65];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x04\x24\x08\x07\x08\x07\x08\x01\x44\x02\x06\x06\x06\x11\x04\x03\x04\x01\x04\x01\x16\x05\x12\x03\x12\x03\x12\x03\x0c\x03\x08\x02\x02\x01\x08\xff\x0e\x02\x0c\x02\x0e\x01\x02\x01\x02\x02\x0e\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x21\x02\x08\x02\xfb\x06\x0b\x02\xfc\x08\x07\x08\x01\x44\x05\x06\x10\x06\x04\x04\x03\x04\x01\x04\x01\x08\x06\x08\xff\x06\x01\x08\x03\x06\xff\x04\x01\x08\x03\x06\xff\x04\x01\x08\x03\x06\xff\x04\x01\x0c\x02\x08\x02\x04\x01\x04\x01\x02\xfe\x0e\x02\x06\x02\x04\x01\x02\xff\x0e\x01\x02\x01\x02\x07\x0e\xfc\x02\x80\x02\x01\x0c\x01\x06\x80\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[329];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 328,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x0f\x38\x01\x0b\x0b\x47\x0b\x47\x0b\x47\x01\x08\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x1f\x01\x1f\x01\x1f\x23\x27\x01\x15\x01\x20\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x01\x22\x01\x22\x01\x22\x01\x22\x0e\x11\x0e\x19\x25\x28\x25\x30\x01\x22\x01\x22\x01\x22\x01\x25\x01\x25\x01\x25\x01\x25\x11\x14\x11\x1f\x21\x27\x01\x25\x01\x25\x01\x2a\x01\x2a\x01\x2a\x01\x2a\x16\x19\x16\x29\x2b\x31\x01\x2a\x01\x2a\x01\x26\x01\x26\x01\x26\x01\x26\x12\x15\x12\x21\x23\x29\x01\x26\x01\x26\x01\x0a\x01\x1b\x14\x1a\x01\x1b\x01\x1b\x01\x1b\x0f\x16\x18\x26\x28\x36\x38\x46\x0f\x1d\x0e\x1e\x01\x23\x01\x23\x05\x0a\x05\x13\x05\x23\x1d\x22\x05\x23\x05\x23\x05\x23\x05\x23\x0f\x17\x19\x26\x0e\x27\x01\x1f\x01\x1f\x05\x0a\x05\x0f\x05\x1f\x19\x1e\x05\x1f\x05\x1f\x05\x1f\x05\x1f\x05\x0a\x01\x2a\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x00\x00\x08\x13\x01\x09\x01\x09\x05\x09\x05\x09\x05\x09\x01\x09\x00\x00\x00\x00\x00\x00\x05\x0e\x05\x2a\x18\x29\x05\x2a\x05\x2a\x05\x2a\x05\x2a\x05\x2a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc2\x0a\x06\x42\x11\x00\xc2\x11\x04\x42\x19\x03\xc2\x18\x01\x42\x19\x03",
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
    .co_localsplusnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_6_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_6_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_6_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_io_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

