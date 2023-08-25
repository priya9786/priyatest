#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[469];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 468,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x5a\x01\x64\x02\x5a\x02\x64\x01\x5a\x03\x64\x03\x5a\x04\x64\x04\x5a\x05\x64\x05\x5a\x06\x64\x06\x5a\x07\x64\x07\x5a\x08\x64\x08\x64\x09\x6c\x09\x5a\x09\x64\x08\x64\x09\x6c\x0a\x5a\x0a\x64\x08\x64\x09\x6c\x0b\x5a\x0b\x64\x08\x64\x09\x6c\x0c\x5a\x0c\x64\x08\x64\x0a\x6c\x0c\x54\x00\x67\x00\x64\x0b\xa2\x01\x5a\x0d\x64\x0c\x84\x00\x5a\x0e\x64\x0d\x84\x00\x5a\x0f\x64\x0e\x84\x00\x5a\x10\x64\x0f\x84\x00\x5a\x11\x64\x10\x84\x00\x5a\x12\x64\x11\x84\x00\x5a\x13\x64\x12\x84\x00\x5a\x14\x65\x0c\x6a\x15\x6a\x00\x65\x14\x5f\x00\x64\x13\x84\x00\x5a\x16\x64\x14\x84\x00\x5a\x17\x64\x15\x84\x00\x5a\x18\x64\x16\x84\x00\x5a\x19\x09\x00\x64\x08\x64\x17\x6c\x1a\x6d\x1b\x5a\x1b\x01\x00\x6e\x0c\x23\x00\x65\x1c\x79\x61\x01\x00\x64\x09\x5a\x1b\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x18\x84\x00\x5a\x1d\x64\x19\x84\x00\x5a\x1e\x64\x1a\x84\x00\x5a\x1f\x09\x00\x64\x08\x64\x1b\x6c\x1a\x6d\x20\x5a\x20\x01\x00\x6e\x0d\x23\x00\x65\x1c\x79\x7f\x01\x00\x64\x1c\x84\x00\x5a\x21\x59\x00\x6e\x07\x77\x00\x78\x03\x59\x00\x77\x01\x64\x1d\x84\x00\x5a\x21\x64\x1e\x84\x00\x5a\x22\x09\x00\x64\x08\x64\x1f\x6c\x1a\x6d\x23\x5a\x23\x01\x00\x6e\x0c\x23\x00\x65\x1c\x79\x99\x01\x00\x65\x22\x5a\x24\x59\x00\x6e\x07\x77\x00\x78\x03\x59\x00\x77\x01\x64\x20\x84\x00\x5a\x24\x09\x00\x64\x08\x64\x21\x6c\x1a\x6d\x25\x5a\x25\x6d\x26\x5a\x27\x01\x00\x6e\x0c\x23\x00\x65\x1c\x79\xb2\x01\x00\x65\x24\x5a\x28\x59\x00\x6e\x10\x77\x00\x78\x03\x59\x00\x77\x01\x64\x22\x84\x00\x5a\x29\x64\x23\x84\x00\x5a\x2a\x64\x24\x64\x25\x9c\x01\x64\x26\x84\x02\x5a\x28\x65\x2b\x65\x0a\x64\x27\xa9\x02\x6f\xce\x65\x0a\x6a\x2c\xa9\x00\x64\x28\x19\x00\x64\x29\x6b\x05\x5a\x2d\x64\x2d\x64\x2a\x84\x01\x5a\x2e\x64\x2b\x84\x00\x5a\x2f\x09\x00\x64\x08\x64\x2c\x6c\x1a\x6d\x30\x5a\x31\x01\x00\x64\x09\x53\x00\x23\x00\x65\x1c\x79\xe6\x01\x00\x59\x00\x64\x09\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[145];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 144,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x6f\x6d\x6d\x6f\x6e\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x6d\x61\x6e\x69\x70\x75\x6c\x61\x74\x69\x6f\x6e\x73\x2c\x20\x57\x69\x6e\x64\x6f\x77\x73\x4e\x54\x2f\x39\x35\x20\x76\x65\x72\x73\x69\x6f\x6e\x2e\x0a\x0a\x49\x6e\x73\x74\x65\x61\x64\x20\x6f\x66\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x2c\x20\x69\x6d\x70\x6f\x72\x74\x20\x6f\x73\x20\x61\x6e\x64\x20\x72\x65\x66\x65\x72\x20\x74\x6f\x20\x74\x68\x69\x73\x0a\x6d\x6f\x64\x75\x6c\x65\x20\x61\x73\x20\x6f\x73\x2e\x70\x61\x74\x68\x2e\x0a",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_1 = {
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
        uint8_t _data[3];
    }
toplevel_consts_2 = {
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
    ._data = "..",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_3 = {
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
        uint8_t _data[2];
    }
toplevel_consts_4 = {
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
    ._data = ";",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_5 = {
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
        uint8_t _data[9];
    }
toplevel_consts_6 = {
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
    ._data = ".;C:\\bin",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_7 = {
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
    ._data = "nul",
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
        .ob_size = 0,
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_10_0 = {
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
        uint8_t _data[9];
    }
toplevel_consts_11_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_1 = {
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
    ._data = "isabs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_2 = {
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
        uint8_t _data[11];
    }
toplevel_consts_11_3 = {
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
    ._data = "splitdrive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_4 = {
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
        uint8_t _data[9];
    }
toplevel_consts_11_5 = {
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
    ._data = "splitext",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_6 = {
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
    ._data = "basename",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_7 = {
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
        uint8_t _data[13];
    }
toplevel_consts_11_8 = {
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
    ._data = "commonprefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_9 = {
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
    ._data = "getsize",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_10 = {
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
    ._data = "getmtime",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_11 = {
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
    ._data = "getatime",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_12 = {
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
    ._data = "getctime",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11_13 = {
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
        uint8_t _data[7];
    }
toplevel_consts_11_14 = {
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
        uint8_t _data[8];
    }
toplevel_consts_11_15 = {
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
    ._data = "lexists",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_16 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11_17 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_18 = {
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
    ._data = "ismount",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_19 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_20 = {
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
    ._data = "expandvars",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_21 = {
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
    ._data = "normpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_22 = {
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
        uint8_t _data[7];
    }
toplevel_consts_11_23 = {
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
toplevel_consts_11_24 = {
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
toplevel_consts_11_25 = {
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
toplevel_consts_11_26 = {
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
toplevel_consts_11_27 = {
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
        uint8_t _data[7];
    }
toplevel_consts_11_28 = {
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
toplevel_consts_11_29 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_30 = {
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
toplevel_consts_11_31 = {
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
    ._data = "realpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_11_32 = {
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
    ._data = "supports_unicode_filenames",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_33 = {
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
    ._data = "relpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_34 = {
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
    ._data = "samefile",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_11_35 = {
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
    ._data = "sameopenfile",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_36 = {
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
        uint8_t _data[11];
    }
toplevel_consts_11_37 = {
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
    ._data = "commonpath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[38];
        }_object;
    }
toplevel_consts_11 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 38,
        },
        .ob_item = {
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
            & toplevel_consts_11_5._ascii.ob_base,
            & toplevel_consts_11_6._ascii.ob_base,
            & toplevel_consts_11_7._ascii.ob_base,
            & toplevel_consts_11_8._ascii.ob_base,
            & toplevel_consts_11_9._ascii.ob_base,
            & toplevel_consts_11_10._ascii.ob_base,
            & toplevel_consts_11_11._ascii.ob_base,
            & toplevel_consts_11_12._ascii.ob_base,
            & toplevel_consts_11_13._ascii.ob_base,
            & toplevel_consts_11_14._ascii.ob_base,
            & toplevel_consts_11_15._ascii.ob_base,
            & toplevel_consts_11_16._ascii.ob_base,
            & toplevel_consts_11_17._ascii.ob_base,
            & toplevel_consts_11_18._ascii.ob_base,
            & toplevel_consts_11_19._ascii.ob_base,
            & toplevel_consts_11_20._ascii.ob_base,
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_11_22._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_24._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_11_26._ascii.ob_base,
            & toplevel_consts_11_27._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_29._ascii.ob_base,
            & toplevel_consts_11_30._ascii.ob_base,
            & toplevel_consts_11_31._ascii.ob_base,
            & toplevel_consts_11_32._ascii.ob_base,
            & toplevel_consts_11_33._ascii.ob_base,
            & toplevel_consts_11_34._ascii.ob_base,
            & toplevel_consts_11_35._ascii.ob_base,
            & toplevel_consts_11_36._ascii.ob_base,
            & toplevel_consts_11_37._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x72\x08\x64\x01\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_12_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\\/",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_12_consts_2 = {
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
    ._data = "\\/",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_12_consts = {
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
            & toplevel_consts_12_consts_1.ob_base.ob_base,
            & toplevel_consts_12_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_12_names_0 = {
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
toplevel_consts_12_names_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_12_varnames_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_varnames = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
        }_object;
    }
toplevel_consts_12_freevars = {
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
        uint8_t _data[16];
    }
toplevel_consts_12_filename = {
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
    ._data = "<frozen ntpath>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_12_name = {
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
    ._data = "_get_bothseps",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x03\x04\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x15\x10\x16\x10\x16\x10\x15\x10\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_12_exceptiontable = {
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
toplevel_consts_12_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 34,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x15\x7c\x00\xa0\x04\x64\x01\x64\x02\xa8\x02\xa9\x02\xa0\x05\xa8\x00\xa9\x00\x53\x00\x7c\x00\xa0\x04\x64\x03\x64\x04\xa8\x02\xa9\x02\xa0\x05\xa8\x00\xa9\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[98];
    }
toplevel_consts_13_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 97,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4e\x6f\x72\x6d\x61\x6c\x69\x7a\x65\x20\x63\x61\x73\x65\x20\x6f\x66\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x4d\x61\x6b\x65\x73\x20\x61\x6c\x6c\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x73\x20\x6c\x6f\x77\x65\x72\x63\x61\x73\x65\x20\x61\x6e\x64\x20\x61\x6c\x6c\x20\x73\x6c\x61\x73\x68\x65\x73\x20\x69\x6e\x74\x6f\x20\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x65\x73\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_13_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "/",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_13_consts_2 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "\\",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_13_consts_0._ascii.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_13_names_0 = {
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
        uint8_t _data[7];
    }
toplevel_consts_13_names_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_13_names_4 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_13_names_5 = {
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
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_13_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_13_varnames_0 = {
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
    ._data = "s",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_13_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_13_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_13_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x0a\x01\x14\x01\x14\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_13_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x08\x01\x02\x03\x14\xfe\x14\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x08\x12\x13\x14\x16\x1b\x08\x1c\x05\x2c\x10\x11\x10\x26\x1a\x1e\x20\x25\x10\x26\x10\x26\x10\x2e\x10\x2e\x10\x2e\x09\x2e\x10\x11\x10\x24\x1a\x1d\x1f\x23\x10\x24\x10\x24\x10\x2c\x10\x2c\x10\x2c\x09\x2c",
};
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 44,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[125];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 124,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x19\x7c\x00\xa0\x04\x64\x01\x64\x02\xa8\x02\xa9\x02\xa0\x05\x64\x03\xa8\x01\xa9\x01\x72\x18\x64\x04\x53\x00\x6e\x0d\x7c\x00\xa0\x04\x64\x05\x64\x06\xa8\x02\xa9\x02\xa0\x05\x64\x07\xa8\x01\xa9\x01\x72\x26\x64\x04\x53\x00\x74\x06\x7c\x00\xa9\x01\x64\x08\x19\x00\x7d\x00\x74\x07\x7c\x00\xa9\x01\x64\x09\x6b\x04\x6f\x3d\x7c\x00\x64\x09\x19\x00\x6f\x3d\x7c\x00\x64\x09\x19\x00\x74\x08\x7c\x00\xa9\x01\x76\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_14_consts_0 = {
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
    ._data = "Test whether a path is absolute",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_14_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\\\\?\\",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_14_consts_7 = {
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
    ._data = "\\\\?\\",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_14_consts_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_14_consts_3.ob_base.ob_base,
            Py_True,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_14_consts_7._ascii.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_14_names_5 = {
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
        uint8_t _data[4];
    }
toplevel_consts_14_names_7 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0a\x03\x16\x01\x04\x01\x02\xff\x16\x03\x04\x01\x0c\x01\x24\x01",
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
    .ob_sval = "\x02\x00\x0a\x02\x08\x03\x02\x05\x14\xfc\x08\x01\x14\x02\x06\x01\x0c\x01\x24\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[125];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 124,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x08\x12\x13\x14\x16\x1b\x08\x1c\x05\x18\x0c\x0d\x0c\x22\x16\x1a\x1c\x21\x0c\x22\x0c\x22\x0c\x39\x2e\x38\x0c\x39\x0c\x39\x09\x18\x14\x18\x14\x18\x09\x18\x0c\x0d\x0c\x20\x16\x19\x1b\x1f\x0c\x20\x0c\x20\x0c\x36\x2c\x35\x0c\x36\x0c\x36\x09\x18\x14\x18\x14\x18\x09\x13\x14\x15\x09\x16\x17\x18\x09\x19\x05\x06\x0c\x0f\x10\x11\x0c\x12\x15\x16\x0c\x16\x0c\x3c\x1b\x1c\x1d\x1e\x1b\x1f\x0c\x3c\x24\x25\x26\x27\x24\x28\x2c\x39\x3a\x3b\x2c\x3c\x24\x3c\x05\x3c",
};
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 61,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[325];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 324,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x12\x64\x01\x7d\x02\x64\x02\x7d\x03\x64\x03\x7d\x04\x6e\x06\x64\x04\x7d\x02\x64\x05\x7d\x03\x64\x06\x7d\x04\x09\x00\x7c\x01\x73\x23\x7c\x00\x64\x00\x64\x07\x85\x02\x19\x00\x7c\x02\x7a\x00\x01\x00\x74\x04\x7c\x00\xa9\x01\x5c\x02\x7d\x05\x7d\x06\x74\x05\x74\x00\x6a\x01\x7c\x01\xa9\x02\x44\x00\x5d\x40\x7d\x07\x74\x04\x7c\x07\xa9\x01\x5c\x02\x7d\x08\x7d\x09\x7c\x09\x72\x48\x7c\x09\x64\x07\x19\x00\x7c\x03\x76\x00\x72\x48\x7c\x08\x73\x43\x7c\x05\x73\x45\x7c\x08\x7d\x05\x7c\x09\x7d\x06\x71\x2f\x7c\x08\x72\x5f\x7c\x08\x7c\x05\x6b\x03\x72\x5f\x7c\x08\xa0\x06\xa8\x00\xa9\x00\x7c\x05\xa0\x06\xa8\x00\xa9\x00\x6b\x03\x72\x5d\x7c\x08\x7d\x05\x7c\x09\x7d\x06\x71\x2f\x7c\x08\x7d\x05\x7c\x06\x72\x6b\x7c\x06\x64\x08\x19\x00\x7c\x03\x76\x01\x72\x6b\x7c\x06\x7c\x02\x7a\x00\x7d\x06\x7c\x06\x7c\x09\x7a\x00\x7d\x06\x71\x2f\x7c\x06\x72\x88\x7c\x06\x64\x07\x19\x00\x7c\x03\x76\x01\x72\x88\x7c\x05\x72\x88\x7c\x05\x64\x08\x64\x00\x85\x02\x19\x00\x7c\x04\x6b\x03\x72\x88\x7c\x05\x7c\x02\x7a\x00\x7c\x06\x7a\x00\x53\x00\x7c\x05\x7c\x06\x7a\x00\x53\x00\x23\x00\x74\x07\x74\x08\x74\x09\x66\x03\x79\x9e\x01\x00\x74\x0a\x6a\x0b\x64\x09\x7c\x00\x67\x02\x7c\x01\xa2\x01\x52\x00\x8e\x00\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_15_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = ":",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_15_consts_6 = {
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
    ._data = ":",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_15_consts_8 = {
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
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_15_consts = {
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
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_12_consts_1.ob_base.ob_base,
            & toplevel_consts_15_consts_3.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_12_consts_2._ascii.ob_base,
            & toplevel_consts_15_consts_6._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_15_consts_8.ob_base.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_15_names_5 = {
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
        uint8_t _data[10];
    }
toplevel_consts_15_names_7 = {
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
        uint8_t _data[15];
    }
toplevel_consts_15_names_8 = {
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
        uint8_t _data[13];
    }
toplevel_consts_15_names_9 = {
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
        uint8_t _data[12];
    }
toplevel_consts_15_names_10 = {
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
    ._data = "genericpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_15_names_11 = {
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
    ._data = "_check_arg_types",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
            & toplevel_consts_13_names_5._ascii.ob_base,
            & toplevel_consts_15_names_7._ascii.ob_base,
            & toplevel_consts_15_names_8._ascii.ob_base,
            & toplevel_consts_15_names_9._ascii.ob_base,
            & toplevel_consts_15_names_10._ascii.ob_base,
            & toplevel_consts_15_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_15_varnames_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_15_varnames_3 = {
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
    ._data = "seps",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_15_varnames_4 = {
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
    ._data = "colon",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_15_varnames_5 = {
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
    ._data = "result_drive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_15_varnames_6 = {
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
    ._data = "result_path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_15_varnames_7 = {
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
    ._data = "p",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_15_varnames_8 = {
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
    ._data = "p_drive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_15_varnames_9 = {
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
    ._data = "p_path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
            & toplevel_consts_15_varnames_5._ascii.ob_base,
            & toplevel_consts_15_varnames_6._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
            & toplevel_consts_15_varnames_8._ascii.ob_base,
            & toplevel_consts_15_varnames_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x01\x04\x01\x10\x01\x0c\x01\x10\x01\x0c\x01\x10\x01\x08\x02\x04\x01\x04\x01\x02\x01\x0c\x01\x14\x01\x04\x02\x04\x01\x02\x01\x04\x02\x10\x02\x08\x01\x0a\x01\x10\x02\x02\x01\x02\xff\x0e\x01\x02\xff\x0c\x02\x08\x01\x02\x80\x0c\x01\x14\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[117];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 116,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x08\x01\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x20\x02\xe2\x12\x01\x0c\x01\x0a\x01\x04\x13\x02\xed\x0c\x01\x02\x01\x02\x0d\x0a\xf3\x02\x0d\x02\xf5\x02\x01\x02\xff\x06\x01\x04\x01\x02\x01\x02\x01\x02\x07\x06\xf9\x02\x07\x12\xfa\x02\x04\x04\xfe\x04\x01\x02\x01\x04\x02\x02\x02\x02\x01\x0a\xff\x0a\x01\x0a\x01\x02\x02\x02\x02\x0a\xfe\x02\x02\x02\xff\x02\x01\x0e\xff\x0e\x01\x08\x01\x02\x80\x08\x01\x04\x02\x14\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[325];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 324,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x14\x0f\x14\x09\x0c\x10\x16\x09\x0d\x11\x15\x09\x0e\x09\x0e\x0f\x13\x09\x0c\x10\x15\x09\x0d\x11\x14\x09\x0e\x05\x0e\x10\x15\x09\x1b\x0d\x11\x12\x14\x13\x14\x12\x14\x0d\x15\x18\x1b\x0d\x1b\x0d\x1b\x25\x2f\x30\x34\x25\x35\x09\x22\x09\x15\x17\x22\x12\x15\x16\x18\x16\x1f\x21\x26\x12\x27\x09\x2f\x09\x2f\x0d\x0e\x1f\x29\x2a\x2b\x1f\x2c\x0d\x1c\x0d\x14\x16\x1c\x10\x16\x0d\x27\x1b\x21\x22\x23\x1b\x24\x28\x2c\x1b\x2c\x0d\x27\x14\x1b\x11\x2b\x23\x2f\x11\x2b\x24\x2b\x15\x21\x1f\x25\x11\x1c\x11\x19\x12\x19\x0d\x27\x1e\x25\x29\x35\x1e\x35\x0d\x27\x14\x1b\x14\x23\x14\x23\x14\x23\x27\x33\x27\x3b\x27\x3b\x27\x3b\x14\x3b\x11\x1d\x24\x2b\x15\x21\x23\x29\x15\x20\x15\x1d\x20\x27\x11\x1d\x10\x1b\x0d\x30\x20\x2b\x2c\x2e\x20\x2f\x37\x3b\x20\x3b\x0d\x30\x1f\x2a\x2d\x30\x1f\x30\x11\x1c\x1b\x26\x29\x2f\x1b\x2f\x0d\x18\x0d\x18\x0d\x18\x09\x34\x1d\x28\x29\x2a\x1d\x2b\x33\x37\x1d\x37\x09\x34\x0d\x19\x09\x34\x1e\x2a\x2b\x2d\x2b\x2e\x2b\x2e\x1e\x2f\x33\x38\x1e\x38\x09\x34\x14\x20\x23\x26\x14\x26\x29\x34\x14\x34\x0d\x34\x10\x1c\x1f\x2a\x10\x2a\x09\x2a\x00\x00\x0d\x16\x18\x26\x28\x34\x0c\x35\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x2c\x2e\x32\x09\x3b\x35\x3a\x09\x3b\x09\x3b\x09\x3b\x09\x3b\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_15_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x99\x41\x2e\x42\x0c\x00\xc2\x08\x03\x42\x0c\x00\xc2\x0c\x13\x42\x1f\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_15_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "          ",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_15_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 77,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_15_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[291];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 290,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x64\x01\x6b\x05\x72\x89\x74\x03\x7c\x00\x74\x04\xa9\x02\x72\x18\x64\x02\x7d\x01\x64\x03\x7d\x02\x64\x04\x7d\x03\x6e\x06\x64\x05\x7d\x01\x64\x06\x7d\x02\x64\x07\x7d\x03\x7c\x00\xa0\x05\x7c\x02\x7c\x01\xa8\x02\xa9\x02\x7d\x04\x7c\x04\x64\x08\x64\x01\x85\x02\x19\x00\x7c\x01\x64\x01\x7a\x05\x6b\x02\x72\x75\x7c\x04\x64\x01\x64\x09\x85\x02\x19\x00\x7c\x01\x6b\x03\x72\x75\x7c\x04\xa0\x06\x7c\x01\x64\x01\xa8\x02\xa9\x02\x7d\x05\x7c\x05\x64\x0a\x6b\x02\x72\x4a\x7c\x00\x64\x0b\x64\x08\x85\x02\x19\x00\x7c\x00\x66\x02\x53\x00\x7c\x04\xa0\x06\x7c\x01\x7c\x05\x64\x0c\x7a\x00\xa8\x02\xa9\x02\x7d\x06\x7c\x06\x7c\x05\x64\x0c\x7a\x00\x6b\x02\x72\x61\x7c\x00\x64\x0b\x64\x08\x85\x02\x19\x00\x7c\x00\x66\x02\x53\x00\x7c\x06\x64\x0a\x6b\x02\x72\x69\x74\x02\x7c\x00\xa9\x01\x7d\x06\x7c\x00\x64\x0b\x7c\x06\x85\x02\x19\x00\x7c\x00\x7c\x06\x64\x0b\x85\x02\x19\x00\x66\x02\x53\x00\x7c\x04\x64\x0c\x64\x01\x85\x02\x19\x00\x7c\x03\x6b\x02\x72\x89\x7c\x00\x64\x0b\x64\x01\x85\x02\x19\x00\x7c\x00\x64\x01\x64\x0b\x85\x02\x19\x00\x66\x02\x53\x00\x7c\x00\x64\x0b\x64\x08\x85\x02\x19\x00\x7c\x00\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[731];
    }
toplevel_consts_16_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 730,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x70\x6c\x69\x74\x20\x61\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x69\x6e\x74\x6f\x20\x64\x72\x69\x76\x65\x2f\x55\x4e\x43\x20\x73\x68\x61\x72\x65\x70\x6f\x69\x6e\x74\x20\x61\x6e\x64\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x20\x70\x61\x74\x68\x20\x73\x70\x65\x63\x69\x66\x69\x65\x72\x73\x2e\x0a\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x61\x20\x32\x2d\x74\x75\x70\x6c\x65\x20\x28\x64\x72\x69\x76\x65\x5f\x6f\x72\x5f\x75\x6e\x63\x2c\x20\x70\x61\x74\x68\x29\x3b\x20\x65\x69\x74\x68\x65\x72\x20\x70\x61\x72\x74\x20\x6d\x61\x79\x20\x62\x65\x20\x65\x6d\x70\x74\x79\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x79\x6f\x75\x20\x61\x73\x73\x69\x67\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x73\x70\x6c\x69\x74\x64\x72\x69\x76\x65\x28\x70\x29\x0a\x20\x20\x20\x20\x49\x74\x20\x69\x73\x20\x61\x6c\x77\x61\x79\x73\x20\x74\x72\x75\x65\x20\x74\x68\x61\x74\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x73\x75\x6c\x74\x5b\x30\x5d\x20\x2b\x20\x72\x65\x73\x75\x6c\x74\x5b\x31\x5d\x20\x3d\x3d\x20\x70\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x74\x68\x65\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x64\x20\x61\x20\x64\x72\x69\x76\x65\x20\x6c\x65\x74\x74\x65\x72\x2c\x20\x64\x72\x69\x76\x65\x5f\x6f\x72\x5f\x75\x6e\x63\x20\x77\x69\x6c\x6c\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x65\x76\x65\x72\x79\x74\x68\x69\x6e\x67\x0a\x20\x20\x20\x20\x75\x70\x20\x74\x6f\x20\x61\x6e\x64\x20\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x6f\x6c\x6f\x6e\x2e\x20\x20\x65\x2e\x67\x2e\x20\x73\x70\x6c\x69\x74\x64\x72\x69\x76\x65\x28\x22\x63\x3a\x2f\x64\x69\x72\x22\x29\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x28\x22\x63\x3a\x22\x2c\x20\x22\x2f\x64\x69\x72\x22\x29\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x74\x68\x65\x20\x70\x61\x74\x68\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x64\x20\x61\x20\x55\x4e\x43\x20\x70\x61\x74\x68\x2c\x20\x74\x68\x65\x20\x64\x72\x69\x76\x65\x5f\x6f\x72\x5f\x75\x6e\x63\x20\x77\x69\x6c\x6c\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x74\x68\x65\x20\x68\x6f\x73\x74\x20\x6e\x61\x6d\x65\x0a\x20\x20\x20\x20\x61\x6e\x64\x20\x73\x68\x61\x72\x65\x20\x75\x70\x20\x74\x6f\x20\x62\x75\x74\x20\x6e\x6f\x74\x20\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x66\x6f\x75\x72\x74\x68\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x2e\x0a\x20\x20\x20\x20\x65\x2e\x67\x2e\x20\x73\x70\x6c\x69\x74\x64\x72\x69\x76\x65\x28\x22\x2f\x2f\x68\x6f\x73\x74\x2f\x63\x6f\x6d\x70\x75\x74\x65\x72\x2f\x64\x69\x72\x22\x29\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x28\x22\x2f\x2f\x68\x6f\x73\x74\x2f\x63\x6f\x6d\x70\x75\x74\x65\x72\x22\x2c\x20\x22\x2f\x64\x69\x72\x22\x29\x0a\x0a\x20\x20\x20\x20\x50\x61\x74\x68\x73\x20\x63\x61\x6e\x6e\x6f\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x62\x6f\x74\x68\x20\x61\x20\x64\x72\x69\x76\x65\x20\x6c\x65\x74\x74\x65\x72\x20\x61\x6e\x64\x20\x61\x20\x55\x4e\x43\x20\x70\x61\x74\x68\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_16_consts_1 = {
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
toplevel_consts_16_consts_9 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_16_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_16_consts_0._ascii.ob_base,
            & toplevel_consts_16_consts_1.ob_base.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_15_consts_3.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_15_consts_6._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_16_consts_9.ob_base.ob_base,
            & toplevel_consts_15_consts_8.ob_base.ob_base,
            Py_None,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_16_names_6 = {
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
    ._data = "find",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_16_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_16_varnames_4 = {
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
    ._data = "normp",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_16_varnames_5 = {
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
    ._data = "index",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_16_varnames_6 = {
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
    ._data = "index2",
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
            & toplevel_consts_15_varnames_7._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
            & toplevel_consts_16_varnames_4._ascii.ob_base,
            & toplevel_consts_16_varnames_5._ascii.ob_base,
            & toplevel_consts_16_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x13\x0c\x01\x0a\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x0e\x01\x24\x01\x0e\x05\x08\x01\x10\x01\x12\x01\x0c\x03\x10\x01\x08\x01\x08\x01\x18\x01\x10\x01\x18\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x13\x0a\x01\x02\x1b\x08\xe6\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x0e\x01\x12\x01\x02\x0f\x0e\xf1\x02\x0f\x0e\xf6\x06\x01\x12\x01\x12\x01\x0a\x03\x12\x01\x06\x01\x0a\x01\x18\x01\x0e\x01\x1a\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[291];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 290,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x08\x0b\x0c\x0d\x08\x0e\x12\x13\x08\x13\x05\x20\x0c\x16\x17\x18\x1a\x1f\x0c\x20\x09\x18\x13\x18\x0d\x10\x16\x1a\x0d\x13\x15\x19\x0d\x12\x0d\x12\x13\x17\x0d\x10\x16\x19\x0d\x13\x15\x18\x0d\x12\x11\x12\x11\x27\x1b\x21\x23\x26\x11\x27\x11\x27\x09\x0e\x0d\x12\x13\x14\x15\x16\x13\x16\x0d\x17\x1b\x1e\x1f\x20\x1b\x20\x0d\x20\x09\x2a\x27\x2c\x2d\x2e\x2f\x30\x2d\x30\x27\x31\x35\x38\x27\x38\x09\x2a\x15\x1a\x15\x27\x20\x23\x25\x26\x15\x27\x15\x27\x0d\x12\x10\x15\x19\x1b\x10\x1b\x0d\x20\x18\x19\x1a\x1c\x1b\x1c\x1a\x1c\x18\x1d\x1f\x20\x18\x20\x11\x20\x16\x1b\x16\x30\x21\x24\x26\x2b\x2e\x2f\x26\x2f\x16\x30\x16\x30\x0d\x13\x10\x16\x1a\x1f\x22\x23\x1a\x23\x10\x23\x0d\x20\x18\x19\x1a\x1c\x1b\x1c\x1a\x1c\x18\x1d\x1f\x20\x18\x20\x11\x20\x10\x16\x1a\x1c\x10\x1c\x0d\x20\x1a\x1d\x1e\x1f\x1a\x20\x11\x17\x14\x15\x16\x1d\x17\x1d\x16\x1d\x14\x1e\x20\x21\x22\x28\x22\x29\x22\x29\x20\x2a\x14\x2a\x0d\x2a\x0c\x11\x12\x13\x14\x15\x12\x15\x0c\x16\x1a\x1f\x0c\x1f\x09\x20\x14\x15\x16\x18\x17\x18\x16\x18\x14\x19\x1b\x1c\x1d\x1e\x1d\x1f\x1d\x1f\x1b\x20\x14\x20\x0d\x20\x0c\x0d\x0e\x10\x0f\x10\x0e\x10\x0c\x11\x13\x14\x0c\x14\x05\x14",
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
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 124,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x74\x03\x7c\x00\xa9\x01\x5c\x02\x7d\x02\x7d\x00\x74\x04\x7c\x00\xa9\x01\x7d\x03\x7c\x03\x72\x2c\x7c\x00\x7c\x03\x64\x01\x7a\x0a\x19\x00\x7c\x01\x76\x01\x72\x2c\x7c\x03\x64\x01\x7a\x17\x7d\x03\x7c\x03\x72\x2c\x7c\x00\x7c\x03\x64\x01\x7a\x0a\x19\x00\x7c\x01\x76\x01\x73\x1e\x7c\x00\x64\x02\x7c\x03\x85\x02\x19\x00\x7c\x00\x7c\x03\x64\x02\x85\x02\x19\x00\x02\x02\x7d\x04\x7d\x05\x7c\x04\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x70\x40\x7c\x04\x7d\x04\x7c\x02\x7c\x04\x7a\x00\x7c\x05\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[127];
    }
toplevel_consts_17_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 126,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x70\x6c\x69\x74\x20\x61\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x74\x75\x70\x6c\x65\x20\x28\x68\x65\x61\x64\x2c\x20\x74\x61\x69\x6c\x29\x20\x77\x68\x65\x72\x65\x20\x74\x61\x69\x6c\x20\x69\x73\x20\x65\x76\x65\x72\x79\x74\x68\x69\x6e\x67\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x66\x69\x6e\x61\x6c\x20\x73\x6c\x61\x73\x68\x2e\x0a\x20\x20\x20\x20\x45\x69\x74\x68\x65\x72\x20\x70\x61\x72\x74\x20\x6d\x61\x79\x20\x62\x65\x20\x65\x6d\x70\x74\x79\x2e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_17_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_0._ascii.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_17_names_5 = {
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
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_17_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_17_varnames_2 = {
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
        uint8_t _data[2];
    }
toplevel_consts_17_varnames_3 = {
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
    ._data = "i",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_17_varnames_4 = {
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
toplevel_consts_17_varnames_5 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_17_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_15_varnames_7._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_17_varnames_4._ascii.ob_base,
            & toplevel_consts_17_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_17_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x05\x08\x01\x0c\x01\x08\x02\x14\x01\x08\x01\x14\xff\x1a\x02\x10\x02\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_17_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x05\x08\x01\x0c\x01\x08\x02\x02\x01\x02\x01\x0e\xff\x0a\x01\x02\xff\x02\x01\x0e\xff\x02\x01\x1a\x01\x10\x02\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0c\x19\x1a\x1b\x0c\x1c\x05\x09\x0c\x16\x17\x18\x0c\x19\x05\x09\x05\x06\x08\x09\x09\x0c\x0d\x0e\x09\x0f\x05\x06\x0b\x0c\x05\x0f\x11\x12\x13\x14\x15\x16\x13\x16\x11\x17\x1f\x23\x11\x23\x05\x0f\x09\x0a\x0e\x0f\x09\x0f\x09\x0a\x0b\x0c\x05\x0f\x11\x12\x13\x14\x15\x16\x13\x16\x11\x17\x1f\x23\x11\x23\x05\x0f\x12\x13\x14\x16\x15\x16\x14\x16\x12\x17\x19\x1a\x1b\x1c\x1b\x1d\x1b\x1d\x19\x1e\x12\x1e\x05\x09\x0b\x0f\x0c\x10\x0c\x1d\x18\x1c\x0c\x1d\x0c\x1d\x0c\x25\x21\x25\x05\x09\x0c\x0d\x10\x14\x0c\x14\x16\x1a\x0c\x1a\x05\x1a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_17_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 180,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
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
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x13\x74\x04\x6a\x05\x7c\x00\x64\x01\x64\x02\x64\x03\xa9\x04\x53\x00\x74\x04\x6a\x05\x7c\x00\x64\x04\x64\x05\x64\x06\xa9\x04\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_18_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = ".",
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
            Py_None,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_18_consts_3.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_18_names_5 = {
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
    ._data = "_splitext",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_18_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_15_names_10._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
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
            & toplevel_consts_15_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x10\x01\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_18_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x08\x01\x02\x03\x10\xfe\x10\x02",
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
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x08\x12\x13\x14\x16\x1b\x08\x1c\x05\x38\x10\x1b\x10\x25\x26\x27\x29\x2e\x30\x34\x36\x3a\x10\x3b\x09\x3b\x10\x1b\x10\x25\x26\x27\x29\x2d\x2f\x32\x34\x37\x10\x38\x09\x38",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 203,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_5._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x64\x01\x19\x00\x53\x00",
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
    ._data = "Returns the final component of a pathname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_19_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_19_consts_0._ascii.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
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
toplevel_consts_19_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x11\x12\x13\x0c\x14\x15\x16\x0c\x17\x05\x17",
};
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 214,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[46];
    }
toplevel_consts_20_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 45,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Returns the directory component of a pathname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_20_consts_0._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 221,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_7._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_21_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x01\x6e\x0e\x23\x00\x74\x02\x74\x03\x74\x04\x66\x03\x79\x12\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x05\x6a\x06\x7c\x01\x6a\x07\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[105];
    }
toplevel_consts_21_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 104,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x54\x65\x73\x74\x20\x77\x68\x65\x74\x68\x65\x72\x20\x61\x20\x70\x61\x74\x68\x20\x69\x73\x20\x61\x20\x73\x79\x6d\x62\x6f\x6c\x69\x63\x20\x6c\x69\x6e\x6b\x2e\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x77\x69\x6c\x6c\x20\x61\x6c\x77\x61\x79\x73\x20\x72\x65\x74\x75\x72\x6e\x20\x66\x61\x6c\x73\x65\x20\x66\x6f\x72\x20\x57\x69\x6e\x64\x6f\x77\x73\x20\x70\x72\x69\x6f\x72\x20\x74\x6f\x20\x36\x2e\x30\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_21_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_21_names_1 = {
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
    ._data = "lstat",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_names_2 = {
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
        uint8_t _data[11];
    }
toplevel_consts_21_names_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_21_names_5 = {
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
        uint8_t _data[8];
    }
toplevel_consts_21_names_6 = {
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
    ._data = "S_ISLNK",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_names_7 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_21_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_15_names_8._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_21_names_6._ascii.ob_base,
            & toplevel_consts_21_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_21_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_21_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_21_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_21_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x0c\x01\x02\x80\x0c\x01\x06\x01\x02\xff\x06\x80\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_21_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x0c\xfe\x02\x80\x08\x01\x0c\x01\x06\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_21_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x0e\x10\x0e\x16\x17\x1b\x0e\x1c\x09\x0b\x09\x0b\x00\x00\x0d\x14\x16\x20\x22\x30\x0c\x31\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00\x0c\x10\x0c\x18\x19\x1b\x19\x23\x0c\x24\x05\x24",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_21_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x05\x08\x00\x88\x07\x13\x03\x92\x01\x13\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_21_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_21 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_21_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 228,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_13._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_13._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_22_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x01\x64\x02\x53\x00\x23\x00\x74\x02\x74\x03\x66\x02\x79\x12\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_22_consts_0 = {
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
    ._data = "Test whether a path exists.  Returns True for broken symbolic links",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_22_consts_0._ascii.ob_base,
            Py_False,
            Py_True,
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
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0a\x01\x04\x03\x02\x80\x0a\xfe\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x0a\xfe\x04\x03\x02\x80\x06\xfe\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x0e\x10\x0e\x16\x17\x1b\x0e\x1c\x09\x0b\x0c\x10\x0c\x10\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_22_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x05\x09\x00\x89\x06\x13\x03\x92\x01\x13\x03",
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
    .co_stacksize = 4,
    .co_firstlineno = 240,
    .co_code = & toplevel_consts_22_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_15._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_15._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_23_0 = {
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
    ._data = "_getvolumepathname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_23 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_23_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_24_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x74\x03\x7c\x00\xa9\x01\x7d\x00\x74\x04\x7c\x00\xa9\x01\x5c\x02\x7d\x02\x7d\x03\x7c\x02\x72\x23\x7c\x02\x64\x01\x19\x00\x7c\x01\x76\x00\x72\x23\x7c\x03\x0c\x00\x70\x22\x7c\x03\x7c\x01\x76\x00\x53\x00\x7c\x03\x72\x2b\x7c\x03\x7c\x01\x76\x00\x72\x2b\x64\x02\x53\x00\x74\x05\x72\x45\x7c\x00\xa0\x06\x7c\x01\xa8\x01\xa9\x01\x7d\x04\x74\x05\x7c\x00\xa9\x01\xa0\x06\x7c\x01\xa8\x01\xa9\x01\x7d\x05\x7c\x04\xa0\x07\xa8\x00\xa9\x00\x7c\x05\xa0\x07\xa8\x00\xa9\x00\x6b\x02\x53\x00\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[98];
    }
toplevel_consts_24_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 97,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x54\x65\x73\x74\x20\x77\x68\x65\x74\x68\x65\x72\x20\x61\x20\x70\x61\x74\x68\x20\x69\x73\x20\x61\x20\x6d\x6f\x75\x6e\x74\x20\x70\x6f\x69\x6e\x74\x20\x28\x61\x20\x64\x72\x69\x76\x65\x20\x72\x6f\x6f\x74\x2c\x20\x74\x68\x65\x20\x72\x6f\x6f\x74\x20\x6f\x66\x20\x61\x0a\x20\x20\x20\x20\x73\x68\x61\x72\x65\x2c\x20\x6f\x72\x20\x61\x20\x6d\x6f\x75\x6e\x74\x65\x64\x20\x76\x6f\x6c\x75\x6d\x65\x29",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            Py_True,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_24_names_7 = {
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
    ._data = "casefold",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_11_22._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_23_0._ascii.ob_base,
            & toplevel_consts_17_names_5._ascii.ob_base,
            & toplevel_consts_24_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_varnames_2 = {
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
    ._data = "root",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_varnames_3 = {
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
    ._data = "rest",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_24_varnames_4 = {
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
    ._data = "x",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_24_varnames_5 = {
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
    ._data = "y",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_24_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_24_varnames_2._ascii.ob_base,
            & toplevel_consts_24_varnames_3._ascii.ob_base,
            & toplevel_consts_24_varnames_4._ascii.ob_base,
            & toplevel_consts_24_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_24_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x01\x08\x01\x0c\x01\x10\x01\x0e\x01\x0c\x01\x04\x01\x04\x02\x0c\x01\x10\x01\x14\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_24_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x01\x08\x01\x0c\x01\x02\x01\x02\x01\x0a\xff\x10\x01\x02\x01\x02\x01\x06\xff\x06\x01\x02\x02\x02\x05\x0c\xfc\x10\x01\x14\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_24_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x0c\x19\x1a\x1e\x0c\x1f\x05\x09\x0c\x13\x14\x18\x0c\x19\x05\x09\x12\x1c\x1d\x21\x12\x22\x05\x0f\x05\x09\x0b\x0f\x08\x0c\x05\x2c\x11\x15\x16\x17\x11\x18\x1c\x20\x11\x20\x05\x2c\x15\x19\x11\x19\x10\x2c\x1f\x23\x27\x2b\x1f\x2b\x09\x2c\x08\x0c\x05\x14\x11\x15\x19\x1d\x11\x1d\x05\x14\x10\x14\x10\x14\x08\x1a\x05\x15\x0d\x11\x0d\x1e\x19\x1d\x0d\x1e\x0d\x1e\x09\x0a\x0c\x1e\x1f\x23\x0c\x24\x0c\x31\x2c\x30\x0c\x31\x0c\x31\x09\x0a\x10\x11\x10\x1c\x10\x1c\x10\x1c\x20\x21\x20\x2c\x20\x2c\x20\x2c\x10\x2c\x09\x2c\x10\x15\x10\x15",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 262,
    .co_code = & toplevel_consts_24_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_18._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_18._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[337];
    }
toplevel_consts_25_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 336,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x0e\x64\x01\x7d\x01\x6e\x02\x64\x02\x7d\x01\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x73\x18\x7c\x00\x53\x00\x64\x03\x74\x05\x7c\x00\xa9\x01\x02\x02\x7d\x02\x7d\x03\x7c\x02\x7c\x03\x6b\x00\x72\x3b\x7c\x00\x7c\x02\x19\x00\x74\x06\x7c\x00\xa9\x01\x76\x01\x72\x3b\x7c\x02\x64\x03\x7a\x0d\x7d\x02\x7c\x02\x7c\x03\x6b\x00\x72\x3b\x7c\x00\x7c\x02\x19\x00\x74\x06\x7c\x00\xa9\x01\x76\x01\x73\x2b\x64\x04\x74\x00\x6a\x07\x76\x00\x72\x46\x74\x00\x6a\x07\x64\x04\x19\x00\x7d\x04\x6e\x22\x64\x05\x74\x00\x6a\x07\x76\x01\x72\x4d\x7c\x00\x53\x00\x09\x00\x74\x00\x6a\x07\x64\x06\x19\x00\x7d\x05\x6e\x0c\x23\x00\x74\x08\x79\x5c\x01\x00\x64\x07\x7d\x05\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x09\x7c\x05\x74\x00\x6a\x07\x64\x05\x19\x00\xa9\x02\x7d\x04\x7c\x02\x64\x03\x6b\x03\x72\x96\x7c\x00\x64\x03\x7c\x02\x85\x02\x19\x00\x7d\x06\x74\x02\x7c\x06\x74\x03\xa9\x02\x72\x7c\x74\x00\x6a\x0a\x7c\x06\xa9\x01\x7d\x06\x74\x00\x6a\x07\xa0\x0b\x64\x08\xa8\x01\xa9\x01\x7d\x07\x7c\x06\x7c\x07\x6b\x03\x72\x96\x7c\x07\x74\x0c\x7c\x04\xa9\x01\x6b\x03\x72\x8f\x7c\x00\x53\x00\x74\x09\x74\x0d\x7c\x04\xa9\x01\x7c\x06\xa9\x02\x7d\x04\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\xa0\x74\x00\x6a\x0e\x7c\x04\xa9\x01\x7d\x04\x7c\x04\x7c\x00\x7c\x02\x64\x09\x85\x02\x19\x00\x7a\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[77];
    }
toplevel_consts_25_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 76,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x78\x70\x61\x6e\x64\x20\x7e\x20\x61\x6e\x64\x20\x7e\x75\x73\x65\x72\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x73\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x75\x73\x65\x72\x20\x6f\x72\x20\x24\x48\x4f\x4d\x45\x20\x69\x73\x20\x75\x6e\x6b\x6e\x6f\x77\x6e\x2c\x20\x64\x6f\x20\x6e\x6f\x74\x68\x69\x6e\x67\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_25_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "~",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_25_consts_2 = {
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
        uint8_t _data[12];
    }
toplevel_consts_25_consts_4 = {
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
    ._data = "USERPROFILE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_25_consts_5 = {
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
    ._data = "HOMEPATH",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_25_consts_6 = {
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
    ._data = "HOMEDRIVE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_25_consts_7 = {
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
        uint8_t _data[9];
    }
toplevel_consts_25_consts_8 = {
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
    ._data = "USERNAME",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_25_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_25_consts_0._ascii.ob_base,
            & toplevel_consts_25_consts_1.ob_base.ob_base,
            & toplevel_consts_25_consts_2._ascii.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_25_consts_4._ascii.ob_base,
            & toplevel_consts_25_consts_5._ascii.ob_base,
            & toplevel_consts_25_consts_6._ascii.ob_base,
            & toplevel_consts_25_consts_7._ascii.ob_base,
            & toplevel_consts_25_consts_8._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_25_names_7 = {
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
        uint8_t _data[9];
    }
toplevel_consts_25_names_8 = {
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
        uint8_t _data[9];
    }
toplevel_consts_25_names_10 = {
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
        uint8_t _data[4];
    }
toplevel_consts_25_names_11 = {
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
toplevel_consts_25_names_14 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_25_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_25_names_7._ascii.ob_base,
            & toplevel_consts_25_names_8._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_25_names_10._ascii.ob_base,
            & toplevel_consts_25_names_11._ascii.ob_base,
            & toplevel_consts_11_6._ascii.ob_base,
            & toplevel_consts_11_7._ascii.ob_base,
            & toplevel_consts_25_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_25_varnames_1 = {
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
    ._data = "tilde",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_25_varnames_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_25_varnames_4 = {
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
    ._data = "userhome",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_25_varnames_5 = {
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
    ._data = "drive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_25_varnames_6 = {
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
    ._data = "target_user",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_25_varnames_7 = {
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
    ._data = "current_user",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_25_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_25_varnames_1._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_25_varnames_3._ascii.ob_base,
            & toplevel_consts_25_varnames_4._ascii.ob_base,
            & toplevel_consts_25_varnames_5._ascii.ob_base,
            & toplevel_consts_25_varnames_6._ascii.ob_base,
            & toplevel_consts_25_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_25_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x0a\x01\x06\x01\x04\x02\x0c\x01\x04\x01\x0e\x01\x18\x01\x08\x01\x18\xff\x0a\x03\x0c\x01\x0a\x01\x04\x01\x02\x02\x0c\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x10\x02\x08\x02\x0c\x01\x0a\x01\x0a\x01\x0e\x01\x08\x02\x0c\x06\x04\x01\x0e\x01\x0a\x02\x0a\x01\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_25_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x08\x01\x02\x03\x06\xfe\x04\x02\x0a\x01\x06\x01\x0e\x01\x06\x01\x02\x01\x0e\xff\x0a\x01\x06\xff\x02\x01\x0e\xff\x02\x01\x08\x02\x02\x09\x0c\xf8\x08\x01\x02\x07\x04\xfa\x02\x05\x0c\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x10\x01\x06\x02\x02\x0e\x0c\xf3\x08\x01\x0c\x01\x0e\x01\x06\x02\x02\x08\x0a\xfe\x06\x01\x0e\x01\x08\x02\x0c\x01\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[337];
    }
toplevel_consts_25_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 336,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x14\x11\x15\x09\x0e\x09\x0e\x11\x14\x09\x0e\x0c\x10\x0c\x22\x1c\x21\x0c\x22\x0c\x22\x05\x14\x10\x14\x09\x14\x0c\x0d\x0f\x12\x13\x17\x0f\x18\x0c\x18\x05\x06\x08\x09\x0b\x0c\x0f\x10\x0b\x10\x05\x0f\x15\x19\x1a\x1b\x15\x1c\x24\x31\x32\x36\x24\x37\x15\x37\x05\x0f\x09\x0a\x0e\x0f\x09\x0f\x09\x0a\x0b\x0c\x0f\x10\x0b\x10\x05\x0f\x15\x19\x1a\x1b\x15\x1c\x24\x31\x32\x36\x24\x37\x15\x37\x05\x0f\x08\x15\x19\x1b\x19\x23\x08\x23\x05\x37\x14\x16\x14\x1e\x1f\x2c\x14\x2d\x09\x11\x09\x11\x0e\x18\x1c\x1e\x1c\x26\x0e\x26\x05\x37\x10\x14\x09\x14\x09\x17\x15\x17\x15\x1f\x20\x2b\x15\x2c\x0d\x12\x0d\x12\x00\x00\x10\x18\x09\x17\x09\x17\x15\x17\x0d\x12\x0d\x12\x0d\x12\x09\x17\x00\x00\x00\x00\x00\x00\x14\x18\x19\x1e\x20\x22\x20\x2a\x2b\x35\x20\x36\x14\x37\x09\x11\x08\x09\x0d\x0e\x08\x0e\x05\x3c\x17\x1b\x1c\x1d\x1e\x1f\x1c\x1f\x17\x20\x09\x14\x0c\x16\x17\x22\x24\x29\x0c\x2a\x09\x33\x1b\x1d\x1b\x26\x27\x32\x1b\x33\x0d\x18\x18\x1a\x18\x22\x18\x32\x27\x31\x18\x32\x18\x32\x09\x15\x0c\x17\x1b\x27\x0c\x27\x09\x3c\x10\x1c\x20\x28\x29\x31\x20\x32\x10\x32\x0d\x1c\x18\x1c\x11\x1c\x18\x1c\x1d\x24\x25\x2d\x1d\x2e\x30\x3b\x18\x3c\x0d\x15\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x29\x14\x16\x14\x1f\x20\x28\x14\x29\x09\x11\x0c\x14\x17\x1b\x1c\x1d\x1c\x1e\x1c\x1e\x17\x1f\x0c\x1f\x05\x1f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_25_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x0e\x05\x41\x14\x00\xc1\x14\x06\x41\x1d\x03\xc1\x1c\x01\x41\x1d\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_25_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_25 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_25_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_25_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_25_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_25_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 291,
    .co_code = & toplevel_consts_25_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_25_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_25_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_19._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_19._ascii.ob_base,
    .co_linetable = & toplevel_consts_25_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_25_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_25_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_25_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1069];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1068,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x35\x64\x01\x7c\x00\x76\x01\x72\x15\x64\x02\x7c\x00\x76\x01\x72\x15\x7c\x00\x53\x00\x64\x03\x64\x04\x6c\x04\x7d\x01\x74\x03\x7c\x01\x6a\x05\x7c\x01\x6a\x06\x7a\x00\x64\x05\x7a\x00\x64\x06\xa9\x02\x7d\x02\x64\x07\x7d\x03\x64\x02\x7d\x04\x64\x08\x7d\x05\x64\x09\x7d\x06\x64\x01\x7d\x07\x74\x07\x74\x00\x64\x0a\x64\x04\xa9\x03\x7d\x08\x6e\x23\x64\x0b\x7c\x00\x76\x01\x72\x3f\x64\x0c\x7c\x00\x76\x01\x72\x3f\x7c\x00\x53\x00\x64\x03\x64\x04\x6c\x04\x7d\x01\x7c\x01\x6a\x05\x7c\x01\x6a\x06\x7a\x00\x64\x05\x7a\x00\x7d\x02\x64\x0d\x7d\x03\x64\x0c\x7d\x04\x64\x0e\x7d\x05\x64\x0f\x7d\x06\x64\x0b\x7d\x07\x74\x00\x6a\x08\x7d\x08\x7c\x00\x64\x04\x64\x03\x85\x02\x19\x00\x7d\x09\x64\x03\x7d\x0a\x74\x09\x7c\x00\xa9\x01\x7d\x0b\x7c\x0a\x7c\x0b\x6b\x00\x90\x02\x72\x14\x7c\x00\x7c\x0a\x7c\x0a\x64\x10\x7a\x00\x85\x02\x19\x00\x7d\x0c\x7c\x0c\x7c\x03\x6b\x02\x72\xab\x7c\x00\x7c\x0a\x64\x10\x7a\x00\x64\x04\x85\x02\x19\x00\x7d\x00\x74\x09\x7c\x00\xa9\x01\x7d\x0b\x09\x00\x7c\x00\xa0\x0a\x7c\x0c\xa8\x01\xa9\x01\x7d\x0a\x7c\x09\x7c\x0c\x7c\x00\x64\x04\x7c\x0a\x64\x10\x7a\x00\x85\x02\x19\x00\x7a\x00\x7a\x0d\x7d\x09\x90\x01\x6e\x76\x23\x00\x74\x0b\x79\xa7\x01\x00\x7c\x09\x7c\x0c\x7c\x00\x7a\x00\x7a\x0d\x7d\x09\x7c\x0b\x64\x10\x7a\x0a\x7d\x0a\x59\x00\x90\x01\x6e\x65\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x0c\x7c\x04\x6b\x02\x90\x01\x72\x20\x7c\x00\x7c\x0a\x64\x10\x7a\x00\x7c\x0a\x64\x11\x7a\x00\x85\x02\x19\x00\x7c\x04\x6b\x02\x72\xc6\x7c\x09\x7c\x0c\x7a\x0d\x7d\x09\x7c\x0a\x64\x10\x7a\x0d\x7d\x0a\x90\x01\x6e\x46\x7c\x00\x7c\x0a\x64\x10\x7a\x00\x64\x04\x85\x02\x19\x00\x7d\x00\x74\x09\x7c\x00\xa9\x01\x7d\x0b\x09\x00\x7c\x00\xa0\x0a\x7c\x04\xa8\x01\xa9\x01\x7d\x0a\x6e\x15\x23\x00\x74\x0b\x79\xeb\x01\x00\x7c\x09\x7c\x04\x7c\x00\x7a\x00\x7a\x0d\x7d\x09\x7c\x0b\x64\x10\x7a\x0a\x7d\x0a\x59\x00\x90\x01\x6e\x21\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x64\x04\x7c\x0a\x85\x02\x19\x00\x7d\x0d\x09\x00\x7c\x08\x90\x01\x80\x05\x74\x00\x6a\x0c\x74\x00\x6a\x08\x74\x00\x6a\x0d\x7c\x0d\xa9\x01\x19\x00\xa9\x01\x7d\x0e\x6e\x04\x7c\x08\x7c\x0d\x19\x00\x7d\x0e\x6e\x11\x23\x00\x74\x0e\x90\x01\x79\x17\x01\x00\x7c\x04\x7c\x0d\x7a\x00\x7c\x04\x7a\x00\x7d\x0e\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x09\x7c\x0e\x7a\x0d\x7d\x09\x6e\xec\x7c\x0c\x7c\x07\x6b\x02\x90\x02\x72\x08\x7c\x00\x7c\x0a\x64\x10\x7a\x00\x7c\x0a\x64\x11\x7a\x00\x85\x02\x19\x00\x7c\x07\x6b\x02\x90\x01\x72\x3b\x7c\x09\x7c\x0c\x7a\x0d\x7d\x09\x7c\x0a\x64\x10\x7a\x0d\x7d\x0a\x6e\xd1\x7c\x00\x7c\x0a\x64\x10\x7a\x00\x7c\x0a\x64\x11\x7a\x00\x85\x02\x19\x00\x7c\x05\x6b\x02\x90\x01\x72\xa6\x7c\x00\x7c\x0a\x64\x11\x7a\x00\x64\x04\x85\x02\x19\x00\x7d\x00\x74\x09\x7c\x00\xa9\x01\x7d\x0b\x09\x00\x7c\x00\xa0\x0a\x7c\x06\xa8\x01\xa9\x01\x7d\x0a\x6e\x17\x23\x00\x74\x0b\x90\x01\x79\x6f\x01\x00\x7c\x09\x7c\x07\x7c\x05\x7a\x00\x7c\x00\x7a\x00\x7a\x0d\x7d\x09\x7c\x0b\x64\x10\x7a\x0a\x7d\x0a\x59\x00\x6e\x9d\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x64\x04\x7c\x0a\x85\x02\x19\x00\x7d\x0d\x09\x00\x7c\x08\x90\x01\x80\x89\x74\x00\x6a\x0c\x74\x00\x6a\x08\x74\x00\x6a\x0d\x7c\x0d\xa9\x01\x19\x00\xa9\x01\x7d\x0e\x6e\x04\x7c\x08\x7c\x0d\x19\x00\x7d\x0e\x6e\x13\x23\x00\x74\x0e\x90\x01\x79\x9d\x01\x00\x7c\x07\x7c\x05\x7a\x00\x7c\x0d\x7a\x00\x7c\x06\x7a\x00\x7d\x0e\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x09\x7c\x0e\x7a\x0d\x7d\x09\x6e\x66\x7c\x00\x64\x04\x64\x03\x85\x02\x19\x00\x7d\x0d\x7c\x0a\x64\x10\x7a\x0d\x7d\x0a\x7c\x00\x7c\x0a\x7c\x0a\x64\x10\x7a\x00\x85\x02\x19\x00\x7d\x0c\x7c\x0c\x90\x01\x72\xd8\x7c\x0c\x7c\x02\x76\x00\x90\x01\x72\xd8\x7c\x0d\x7c\x0c\x7a\x0d\x7d\x0d\x7c\x0a\x64\x10\x7a\x0d\x7d\x0a\x7c\x00\x7c\x0a\x7c\x0a\x64\x10\x7a\x00\x85\x02\x19\x00\x7d\x0c\x7c\x0c\x90\x01\x72\xd8\x7c\x0c\x7c\x02\x76\x00\x90\x01\x73\xc0\x09\x00\x7c\x08\x90\x01\x80\xe8\x74\x00\x6a\x0c\x74\x00\x6a\x08\x74\x00\x6a\x0d\x7c\x0d\xa9\x01\x19\x00\xa9\x01\x7d\x0e\x6e\x04\x7c\x08\x7c\x0d\x19\x00\x7d\x0e\x6e\x0f\x23\x00\x74\x0e\x90\x01\x79\xf8\x01\x00\x7c\x07\x7c\x0d\x7a\x00\x7d\x0e\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x09\x7c\x0e\x7a\x0d\x7d\x09\x7c\x0c\x90\x02\x72\x07\x7c\x0a\x64\x10\x7a\x17\x7d\x0a\x6e\x04\x7c\x09\x7c\x0c\x7a\x0d\x7d\x09\x7c\x0a\x64\x10\x7a\x0d\x7d\x0a\x7c\x0a\x7c\x0b\x6b\x00\x73\x69\x7c\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[103];
    }
toplevel_consts_26_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 102,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x78\x70\x61\x6e\x64\x20\x73\x68\x65\x6c\x6c\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x66\x6f\x72\x6d\x73\x20\x24\x76\x61\x72\x2c\x20\x24\x7b\x76\x61\x72\x7d\x20\x61\x6e\x64\x20\x25\x76\x61\x72\x25\x2e\x0a\x0a\x20\x20\x20\x20\x55\x6e\x6b\x6e\x6f\x77\x6e\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73\x20\x61\x72\x65\x20\x6c\x65\x66\x74\x20\x75\x6e\x63\x68\x61\x6e\x67\x65\x64\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "$",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_2 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "%",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_26_consts_5 = {
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
    ._data = "_-",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_consts_6 = {
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
    ._data = "ascii",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_7 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "'",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_8 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "{",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_10 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_11 = {
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
    ._data = "$",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_12 = {
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
    ._data = "%",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_13 = {
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
    ._data = "'",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_14 = {
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
    ._data = "{",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_15 = {
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
    ._data = "}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_1.ob_base.ob_base,
            & toplevel_consts_26_consts_2.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            Py_None,
            & toplevel_consts_26_consts_5._ascii.ob_base,
            & toplevel_consts_26_consts_6._ascii.ob_base,
            & toplevel_consts_26_consts_7.ob_base.ob_base,
            & toplevel_consts_26_consts_8.ob_base.ob_base,
            & toplevel_consts_26_consts_9.ob_base.ob_base,
            & toplevel_consts_26_consts_10._ascii.ob_base,
            & toplevel_consts_26_consts_11._ascii.ob_base,
            & toplevel_consts_26_consts_12._ascii.ob_base,
            & toplevel_consts_26_consts_13._ascii.ob_base,
            & toplevel_consts_26_consts_14._ascii.ob_base,
            & toplevel_consts_26_consts_15._ascii.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_16_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_names_4 = {
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
    ._data = "string",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_26_names_5 = {
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
    ._data = "ascii_letters",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_names_6 = {
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
    ._data = "digits",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_names_7 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_26_names_4._ascii.ob_base,
            & toplevel_consts_26_names_5._ascii.ob_base,
            & toplevel_consts_26_names_6._ascii.ob_base,
            & toplevel_consts_26_names_7._ascii.ob_base,
            & toplevel_consts_25_names_7._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_16_varnames_5._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_25_names_14._ascii.ob_base,
            & toplevel_consts_25_names_10._ascii.ob_base,
            & toplevel_consts_25_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_varnames_2 = {
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
    ._data = "varchars",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_varnames_3 = {
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
    ._data = "quote",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_varnames_4 = {
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
    ._data = "percent",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_varnames_5 = {
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
    ._data = "brace",
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
    ._data = "rbrace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_varnames_7 = {
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
    ._data = "dollar",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_varnames_9 = {
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
    ._data = "res",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_varnames_11 = {
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
    ._data = "pathlen",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_varnames_12 = {
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
    ._data = "c",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_varnames_13 = {
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
    ._data = "var",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_varnames_14 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_26_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_26_names_4._ascii.ob_base,
            & toplevel_consts_26_varnames_2._ascii.ob_base,
            & toplevel_consts_26_varnames_3._ascii.ob_base,
            & toplevel_consts_26_varnames_4._ascii.ob_base,
            & toplevel_consts_26_varnames_5._ascii.ob_base,
            & toplevel_consts_26_varnames_6._ascii.ob_base,
            & toplevel_consts_26_varnames_7._ascii.ob_base,
            & toplevel_consts_25_names_7._ascii.ob_base,
            & toplevel_consts_26_varnames_9._ascii.ob_base,
            & toplevel_consts_16_varnames_5._ascii.ob_base,
            & toplevel_consts_26_varnames_11._ascii.ob_base,
            & toplevel_consts_26_varnames_12._ascii.ob_base,
            & toplevel_consts_26_varnames_13._ascii.ob_base,
            & toplevel_consts_26_varnames_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x0a\x01\x10\x01\x04\x01\x08\x01\x16\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x0e\x01\x10\x02\x04\x01\x08\x01\x10\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x01\x0c\x01\x04\x01\x08\x01\x0a\x01\x10\x01\x08\x01\x10\x01\x08\x01\x02\x01\x0c\x01\x1c\x01\x02\x80\x06\x01\x0c\x01\x0e\x01\x02\xfe\x06\x80\x0a\x03\x18\x01\x08\x01\x0c\x01\x10\x02\x08\x01\x02\x01\x0e\x01\x02\x80\x06\x01\x0c\x01\x0e\x01\x02\xfe\x06\x80\x0c\x04\x02\x01\x06\x01\x18\x01\x08\x02\x04\x80\x08\x01\x10\x01\x02\xff\x06\x80\x0a\x02\x0a\x01\x1a\x01\x08\x01\x0a\x01\x1a\x01\x10\x01\x08\x01\x02\x01\x0e\x01\x02\x80\x08\x01\x10\x01\x0c\x01\x02\xfe\x06\x80\x0c\x04\x02\x01\x06\x01\x18\x01\x08\x02\x04\x80\x08\x01\x14\x01\x02\xff\x06\x80\x0a\x02\x0c\x02\x08\x01\x10\x01\x10\x01\x08\x01\x08\x01\x10\x01\x10\xfd\x02\x04\x06\x01\x18\x01\x08\x02\x04\x80\x08\x01\x0c\x01\x02\xff\x06\x80\x08\x02\x06\x01\x08\x01\x02\x80\x08\x02\x08\x01\x08\xb5\x04\x4c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[271];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 270,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x04\x08\x01\x02\x15\x06\xec\x02\x01\x06\xff\x06\x01\x08\x01\x16\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x0e\x01\x06\x02\x02\x01\x06\xff\x06\x01\x08\x01\x10\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x01\x0c\x01\x04\x01\x08\x01\x06\x01\x04\x4b\x10\xb6\x06\x01\x02\x48\x10\xb9\x08\x01\x02\x06\x0c\xfc\x1c\x01\x02\x80\x02\x01\x04\x02\x0c\xff\x10\x01\x06\x80\x06\x01\x04\x3f\x16\xc2\x02\x14\x08\xed\x0c\x01\x10\x02\x08\x01\x02\x0f\x0e\xf3\x02\x80\x02\x01\x04\x02\x0c\xff\x10\x01\x06\x80\x0c\x02\x02\x07\x02\xfb\x04\x03\x18\xfe\x08\x02\x04\x80\x02\x01\x18\x01\x06\x80\x0a\x01\x06\x01\x04\x29\x16\xd8\x04\x26\x08\xdb\x0a\x01\x16\x01\x04\x23\x10\xde\x08\x01\x02\x0f\x0e\xf3\x02\x80\x02\x01\x06\x02\x10\xff\x0e\x01\x06\x80\x0c\x02\x02\x07\x02\xfb\x04\x03\x18\xfe\x08\x02\x04\x80\x02\x01\x1c\x01\x06\x80\x0a\x01\x0c\x02\x08\x01\x10\x01\x02\x01\x04\x03\x06\xfd\x04\x03\x08\xfe\x08\x01\x10\x01\x02\xfd\x04\x03\x06\xfd\x04\x03\x02\x07\x02\xfb\x04\x03\x18\xfe\x08\x02\x04\x80\x02\x01\x14\x01\x06\x80\x08\x01\x02\x01\x0c\x01\x02\x80\x08\x02\x08\x01\x06\xb5\x02\x4b\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1069];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1068,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x1d\x0c\x10\x18\x1c\x0c\x1c\x09\x18\x21\x25\x2d\x31\x21\x31\x09\x18\x14\x18\x0d\x18\x09\x16\x09\x16\x09\x16\x09\x16\x14\x19\x1a\x20\x1a\x2e\x31\x37\x31\x3e\x1a\x3e\x41\x45\x1a\x45\x47\x4e\x14\x4f\x09\x11\x11\x16\x09\x0e\x13\x17\x09\x10\x11\x15\x09\x0e\x12\x16\x09\x0f\x12\x16\x09\x0f\x13\x1a\x1b\x1d\x1f\x29\x2b\x2f\x13\x30\x09\x10\x09\x10\x0c\x0f\x17\x1b\x0c\x1b\x09\x18\x20\x23\x2b\x2f\x20\x2f\x09\x18\x14\x18\x0d\x18\x09\x16\x09\x16\x09\x16\x09\x16\x14\x1a\x14\x28\x2b\x31\x2b\x38\x14\x38\x3b\x3f\x14\x3f\x09\x11\x11\x15\x09\x0e\x13\x16\x09\x10\x11\x14\x09\x0e\x12\x15\x09\x0f\x12\x15\x09\x0f\x13\x15\x13\x1d\x09\x10\x0b\x0f\x10\x12\x11\x12\x10\x12\x0b\x13\x05\x08\x0d\x0e\x05\x0a\x0f\x12\x13\x17\x0f\x18\x05\x0c\x0b\x10\x13\x1a\x0b\x1a\x05\x13\x05\x13\x0d\x11\x12\x17\x18\x1d\x1e\x1f\x18\x1f\x12\x1f\x0d\x20\x09\x0a\x0c\x0d\x11\x16\x0c\x16\x09\x15\x14\x18\x19\x1e\x21\x22\x19\x22\x19\x23\x19\x23\x14\x24\x0d\x11\x17\x1a\x1b\x1f\x17\x20\x0d\x14\x0d\x24\x19\x1d\x19\x26\x24\x25\x19\x26\x19\x26\x11\x16\x11\x14\x18\x19\x1c\x20\x21\x2b\x22\x27\x2a\x2b\x22\x2b\x21\x2b\x1c\x2c\x18\x2c\x11\x2c\x11\x14\x11\x14\x11\x14\x00\x00\x14\x1e\x0d\x24\x0d\x24\x11\x14\x18\x19\x1c\x20\x18\x20\x11\x20\x11\x14\x19\x20\x23\x24\x19\x24\x11\x16\x11\x16\x11\x16\x11\x16\x0d\x24\x00\x00\x00\x00\x00\x00\x0e\x0f\x13\x1a\x0e\x1a\x09\x15\x09\x15\x10\x14\x15\x1a\x1d\x1e\x15\x1e\x1f\x24\x27\x28\x1f\x28\x15\x28\x10\x29\x2d\x34\x10\x34\x0d\x21\x11\x14\x18\x19\x11\x19\x11\x14\x11\x16\x1a\x1b\x11\x1b\x11\x16\x11\x16\x11\x16\x18\x1c\x1d\x22\x23\x24\x1d\x24\x1d\x25\x1d\x25\x18\x26\x11\x15\x1b\x1e\x1f\x23\x1b\x24\x11\x18\x11\x21\x1d\x21\x1d\x30\x28\x2f\x1d\x30\x1d\x30\x15\x1a\x15\x1a\x00\x00\x18\x22\x11\x28\x11\x28\x15\x18\x1c\x23\x26\x2a\x1c\x2a\x15\x2a\x15\x18\x1d\x24\x27\x28\x1d\x28\x15\x1a\x15\x1a\x15\x1a\x15\x1a\x11\x28\x00\x00\x00\x00\x00\x00\x1b\x1f\x20\x26\x21\x26\x20\x26\x1b\x27\x15\x18\x15\x38\x1c\x23\x19\x31\x19\x31\x25\x27\x25\x30\x31\x33\x31\x3b\x3c\x3e\x3c\x47\x48\x4b\x3c\x4c\x31\x4d\x25\x4e\x1d\x22\x1d\x22\x25\x2c\x2d\x30\x25\x31\x1d\x22\x00\x00\x00\x00\x1c\x24\x15\x38\x15\x38\x15\x38\x21\x28\x2b\x2e\x21\x2e\x31\x38\x21\x38\x19\x1e\x19\x1e\x19\x1e\x15\x38\x00\x00\x00\x00\x00\x00\x15\x18\x1c\x21\x15\x21\x15\x18\x15\x18\x0e\x0f\x13\x19\x0e\x19\x09\x15\x09\x15\x10\x14\x15\x1a\x1d\x1e\x15\x1e\x1f\x24\x27\x28\x1f\x28\x15\x28\x10\x29\x2d\x33\x10\x33\x0d\x1f\x0d\x1f\x11\x14\x18\x19\x11\x19\x11\x14\x11\x16\x1a\x1b\x11\x1b\x11\x16\x11\x16\x12\x16\x17\x1c\x1f\x20\x17\x20\x21\x26\x29\x2a\x21\x2a\x17\x2a\x12\x2b\x2f\x34\x12\x34\x0d\x1f\x0d\x1f\x18\x1c\x1d\x22\x23\x24\x1d\x24\x1d\x25\x1d\x25\x18\x26\x11\x15\x1b\x1e\x1f\x23\x1b\x24\x11\x18\x11\x21\x1d\x21\x1d\x2f\x28\x2e\x1d\x2f\x1d\x2f\x15\x1a\x15\x1a\x00\x00\x18\x22\x11\x28\x11\x28\x11\x28\x15\x18\x1c\x22\x25\x2a\x1c\x2a\x2d\x31\x1c\x31\x15\x31\x15\x18\x1d\x24\x27\x28\x1d\x28\x15\x1a\x15\x1a\x15\x1a\x11\x28\x00\x00\x00\x00\x00\x00\x1b\x1f\x20\x26\x21\x26\x20\x26\x1b\x27\x15\x18\x15\x3e\x1c\x23\x19\x31\x19\x31\x25\x27\x25\x30\x31\x33\x31\x3b\x3c\x3e\x3c\x47\x48\x4b\x3c\x4c\x31\x4d\x25\x4e\x1d\x22\x1d\x22\x25\x2c\x2d\x30\x25\x31\x1d\x22\x00\x00\x00\x00\x1c\x24\x15\x3e\x15\x3e\x15\x3e\x21\x27\x2a\x2f\x21\x2f\x32\x35\x21\x35\x38\x3e\x21\x3e\x19\x1e\x19\x1e\x19\x1e\x15\x3e\x00\x00\x00\x00\x00\x00\x15\x18\x1c\x21\x15\x21\x15\x18\x15\x18\x17\x1b\x1c\x1e\x1d\x1e\x1c\x1e\x17\x1f\x11\x14\x11\x16\x1a\x1b\x11\x1b\x11\x16\x15\x19\x1a\x1f\x20\x25\x28\x29\x20\x29\x1a\x29\x15\x2a\x11\x12\x17\x18\x11\x2e\x11\x2e\x1d\x1e\x22\x2a\x1d\x2a\x11\x2e\x11\x2e\x15\x18\x1c\x1d\x15\x1d\x15\x18\x15\x1a\x1e\x1f\x15\x1f\x15\x1a\x19\x1d\x1e\x23\x24\x29\x2c\x2d\x24\x2d\x1e\x2d\x19\x2e\x15\x16\x17\x18\x11\x2e\x11\x2e\x1d\x1e\x22\x2a\x1d\x2a\x11\x2e\x11\x2e\x11\x29\x18\x1f\x15\x2d\x15\x2d\x21\x23\x21\x2c\x2d\x2f\x2d\x37\x38\x3a\x38\x43\x44\x47\x38\x48\x2d\x49\x21\x4a\x19\x1e\x19\x1e\x21\x28\x29\x2c\x21\x2d\x19\x1e\x00\x00\x00\x00\x18\x20\x11\x29\x11\x29\x11\x29\x1d\x23\x26\x29\x1d\x29\x15\x1a\x15\x1a\x15\x1a\x11\x29\x00\x00\x00\x00\x00\x00\x11\x14\x18\x1d\x11\x1d\x11\x14\x14\x15\x11\x1f\x11\x1f\x15\x1a\x1e\x1f\x15\x1f\x15\x1a\x00\x00\x0d\x10\x14\x15\x0d\x15\x0d\x10\x09\x0e\x12\x13\x09\x13\x09\x0e\x0b\x10\x13\x1a\x0b\x1a\x05\x13\x0c\x0f\x05\x0f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[109];
    }
toplevel_consts_26_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\xc2\x02\x12\x42\x16\x00\xc2\x16\x0e\x42\x28\x03\xc2\x27\x01\x42\x28\x03\xc3\x13\x06\x43\x1a\x00\xc3\x1a\x0e\x43\x2c\x03\xc3\x2b\x01\x43\x2c\x03\xc3\x36\x13\x44\x0a\x00\xc4\x0a\x0b\x44\x18\x03\xc4\x17\x01\x44\x18\x03\xc5\x15\x06\x45\x1c\x00\xc5\x1c\x11\x45\x30\x03\xc5\x2f\x01\x45\x30\x03\xc5\x3a\x13\x46\x0e\x00\xc6\x0e\x0d\x46\x1e\x03\xc6\x1d\x01\x46\x1e\x03\xc7\x19\x13\x47\x2d\x00\xc7\x2d\x09\x47\x39\x03\xc7\x38\x01\x47\x39\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[16];
    }
toplevel_consts_26_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 15,
    },
    .ob_shash = -1,
    .ob_sval = "               ",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_26_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 352,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_20._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_20._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 15,
    .co_nlocals = 15,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_27_0 = {
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
    ._data = "_path_normpath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_27 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_27_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[353];
    }
toplevel_consts_28_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 352,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x16\x64\x01\x7d\x01\x64\x02\x7d\x02\x64\x03\x7d\x03\x64\x04\x7d\x04\x64\x05\x7d\x05\x6e\x0a\x64\x06\x7d\x01\x64\x07\x7d\x02\x64\x08\x7d\x03\x64\x09\x7d\x04\x64\x0a\x7d\x05\x7c\x00\xa0\x04\x7c\x05\xa8\x01\xa9\x01\x72\x28\x7c\x00\x53\x00\x7c\x00\xa0\x05\x7c\x02\x7c\x01\xa8\x02\xa9\x02\x7d\x00\x74\x06\x7c\x00\xa9\x01\x5c\x02\x7d\x06\x7d\x00\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x72\x45\x7c\x06\x7c\x01\x7a\x0d\x7d\x06\x7c\x00\xa0\x07\x7c\x01\xa8\x01\xa9\x01\x7d\x00\x7c\x00\xa0\x08\x7c\x01\xa8\x01\xa9\x01\x7d\x07\x64\x0b\x7d\x08\x7c\x08\x74\x09\x7c\x07\xa9\x01\x6b\x00\x72\x9e\x7c\x07\x7c\x08\x19\x00\x72\x5d\x7c\x07\x7c\x08\x19\x00\x7c\x03\x6b\x02\x72\x61\x7c\x07\x7c\x08\x3d\x00\x6e\x37\x7c\x07\x7c\x08\x19\x00\x7c\x04\x6b\x02\x72\x94\x7c\x08\x64\x0b\x6b\x04\x72\x81\x7c\x07\x7c\x08\x64\x0c\x7a\x0a\x19\x00\x7c\x04\x6b\x03\x72\x81\x7c\x07\x7c\x08\x64\x0c\x7a\x0a\x7c\x08\x64\x0c\x7a\x00\x85\x02\x3d\x00\x7c\x08\x64\x0c\x7a\x17\x7d\x08\x6e\x17\x7c\x08\x64\x0b\x6b\x02\x72\x8f\x7c\x06\xa0\x0a\x7c\x01\xa8\x01\xa9\x01\x72\x8f\x7c\x07\x7c\x08\x3d\x00\x6e\x09\x7c\x08\x64\x0c\x7a\x0d\x7d\x08\x6e\x04\x7c\x08\x64\x0c\x7a\x0d\x7d\x08\x7c\x08\x74\x09\x7c\x07\xa9\x01\x6b\x00\x73\x53\x7c\x06\x73\xa8\x7c\x07\x73\xa8\x7c\x07\xa0\x0b\x7c\x03\xa8\x01\xa9\x01\x01\x00\x7c\x06\x7c\x01\xa0\x0c\x7c\x07\xa8\x01\xa9\x01\x7a\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_28_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 48,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Normalize path, eliminating double slashes, etc.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_28_consts_4 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "..",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_28_consts_5_0 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\\\\.\\",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_5_0.ob_base.ob_base,
            & toplevel_consts_14_consts_3.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_28_consts_10_0 = {
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
    ._data = "\\\\.\\",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_10 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_10_0._ascii.ob_base,
            & toplevel_consts_14_consts_7._ascii.ob_base,
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
toplevel_consts_28_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_28_consts_0._ascii.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_18_consts_3.ob_base.ob_base,
            & toplevel_consts_28_consts_4.ob_base.ob_base,
            & toplevel_consts_28_consts_5._object.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            & toplevel_consts_28_consts_10._object.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_names_7 = {
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
    ._data = "lstrip",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_28_names_10 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_names_11 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_28_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_28_names_7._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_28_names_10._ascii.ob_base,
            & toplevel_consts_28_names_11._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_28_varnames_5 = {
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
    ._data = "special_prefixes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_varnames_6 = {
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
        uint8_t _data[6];
    }
toplevel_consts_28_varnames_7 = {
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
    ._data = "comps",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_28_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_24._ascii.ob_base,
            & toplevel_consts_28_varnames_5._ascii.ob_base,
            & toplevel_consts_28_varnames_6._ascii.ob_base,
            & toplevel_consts_28_varnames_7._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[75];
    }
toplevel_consts_28_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 74,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0a\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x01\x04\x01\x0c\x01\x04\x06\x0e\x01\x0c\x01\x0c\x03\x08\x01\x0c\x01\x0c\x02\x04\x01\x0c\x01\x14\x01\x08\x01\x0c\x01\x18\x01\x12\x01\x0a\x01\x14\x01\x08\x01\x0a\x02\x08\x02\x0c\xf4\x08\x0e\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_28_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x02\x0b\x04\xf6\x04\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x01\x04\x01\x0a\x01\x06\x06\x0e\x01\x0c\x01\x0a\x03\x02\x02\x08\xff\x0c\x01\x0c\x02\x04\x01\x0a\x01\x02\x0c\x06\xf5\x02\x0b\x0a\xf5\x02\x0b\x08\xf6\x0a\x01\x02\x09\x06\xf8\x02\x06\x0e\xfa\x02\x06\x12\xfb\x0a\x01\x06\x01\x02\x03\x0a\xfd\x02\x03\x08\xfe\x0a\x02\x08\x02\x0a\xf4\x02\x0c\x02\x02\x02\x01\x02\xff\x0e\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[353];
    }
toplevel_consts_28_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 352,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x19\x1a\x1e\x10\x1f\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x36\x13\x18\x0d\x10\x16\x1a\x0d\x13\x16\x1a\x0d\x13\x16\x1b\x0d\x13\x20\x38\x0d\x1d\x0d\x1d\x13\x17\x0d\x10\x16\x19\x0d\x13\x16\x19\x0d\x13\x16\x1a\x0d\x13\x20\x36\x0d\x1d\x0c\x10\x0c\x2d\x1c\x2c\x0c\x2d\x0c\x2d\x09\x18\x14\x18\x0d\x18\x10\x14\x10\x29\x1d\x23\x25\x28\x10\x29\x10\x29\x09\x0d\x18\x22\x23\x27\x18\x28\x09\x15\x09\x0f\x11\x15\x0c\x10\x0c\x20\x1c\x1f\x0c\x20\x0c\x20\x09\x24\x0d\x13\x17\x1a\x0d\x1a\x0d\x13\x14\x18\x14\x24\x20\x23\x14\x24\x14\x24\x0d\x11\x11\x15\x11\x20\x1c\x1f\x11\x20\x11\x20\x09\x0e\x0d\x0e\x09\x0a\x0f\x10\x13\x16\x17\x1c\x13\x1d\x0f\x1d\x09\x17\x14\x19\x1a\x1b\x14\x1c\x0d\x17\x20\x25\x26\x27\x20\x28\x2c\x32\x20\x32\x0d\x17\x15\x1a\x1b\x1c\x15\x1d\x15\x1d\x12\x17\x18\x19\x12\x1a\x1e\x24\x12\x24\x0d\x17\x14\x15\x18\x19\x14\x19\x11\x1b\x1e\x23\x24\x25\x26\x27\x24\x27\x1e\x28\x2c\x32\x1e\x32\x11\x1b\x19\x1e\x1f\x20\x21\x22\x1f\x22\x23\x24\x25\x26\x23\x26\x1f\x26\x19\x27\x15\x16\x1a\x1b\x15\x1b\x15\x16\x15\x16\x16\x17\x1b\x1c\x16\x1c\x11\x1b\x21\x27\x21\x35\x31\x34\x21\x35\x21\x35\x11\x1b\x19\x1e\x1f\x20\x19\x21\x19\x21\x15\x16\x1a\x1b\x15\x1b\x15\x16\x15\x16\x11\x12\x16\x17\x11\x17\x11\x12\x0f\x10\x13\x16\x17\x1c\x13\x1d\x0f\x1d\x09\x17\x10\x16\x09\x21\x1f\x24\x09\x21\x0d\x12\x0d\x21\x1a\x20\x0d\x21\x0d\x21\x0d\x21\x10\x16\x19\x1c\x19\x28\x22\x27\x19\x28\x19\x28\x10\x28\x09\x28",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_28_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 9,
    },
    .ob_shash = -1,
    .ob_sval = "         ",
};
static struct PyCodeObject toplevel_consts_28 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 468,
    .co_code = & toplevel_consts_28_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_28_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_29_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x17\x74\x00\x6a\x04\x74\x05\x74\x00\x6a\x06\x7c\x00\xa9\x01\xa9\x01\xa9\x01\x70\x16\x64\x01\x53\x00\x74\x05\x7c\x00\xa9\x01\x70\x1c\x64\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_29_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_28_consts_0._ascii.ob_base,
            & toplevel_consts_18_consts_3.ob_base.ob_base,
            & toplevel_consts_1._ascii.ob_base,
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
toplevel_consts_29_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_25_names_14._ascii.ob_base,
            & toplevel_consts_27_0._ascii.ob_base,
            & toplevel_consts_25_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_29_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0a\x01\x18\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_29_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x1a\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_29_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x19\x1a\x1e\x10\x1f\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x4a\x14\x16\x14\x1f\x20\x2e\x2f\x31\x2f\x3a\x3b\x3f\x2f\x40\x20\x41\x14\x42\x14\x4a\x46\x4a\x0d\x4a\x10\x1e\x1f\x23\x10\x24\x10\x2b\x28\x2b\x09\x2b",
};
static struct PyCodeObject toplevel_consts_29 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_29_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_29_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_29_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 519,
    .co_code = & toplevel_consts_29_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_29_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_29_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_29_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_30_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x73\x1d\x74\x03\x7c\x00\x74\x04\xa9\x02\x72\x14\x74\x00\x6a\x05\xa9\x00\x7d\x01\x6e\x04\x74\x00\x6a\x06\xa9\x00\x7d\x01\x74\x07\x7c\x01\x7c\x00\xa9\x02\x7d\x00\x74\x08\x7c\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[165];
    }
toplevel_consts_30_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 164,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x61\x62\x73\x6f\x6c\x75\x74\x65\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x6f\x66\x20\x61\x20\x70\x61\x74\x68\x20\x61\x73\x20\x61\x20\x66\x61\x6c\x6c\x62\x61\x63\x6b\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x6e\x20\x63\x61\x73\x65\x0a\x20\x20\x20\x20\x60\x6e\x74\x2e\x5f\x67\x65\x74\x66\x75\x6c\x6c\x70\x61\x74\x68\x6e\x61\x6d\x65\x60\x20\x69\x73\x20\x6e\x6f\x74\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x73\x20\x4f\x53\x45\x72\x72\x6f\x72\x2e\x20\x53\x65\x65\x20\x62\x70\x6f\x2d\x33\x31\x30\x34\x37\x20\x66\x6f\x72\x0a\x20\x20\x20\x20\x6d\x6f\x72\x65\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_30_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_30_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_30_names_5 = {
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
    ._data = "getcwdb",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_30_names_6 = {
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
    ._data = "getcwd",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_30_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_30_names_5._ascii.ob_base,
            & toplevel_consts_30_names_6._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_11_21._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_30_varnames_1 = {
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
    ._data = "cwd",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_30_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_30_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_30_name = {
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
    ._data = "_abspath_fallback",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_30_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x07\x08\x01\x0a\x01\x0a\x01\x08\x02\x0a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_30_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x07\x06\x01\x02\x05\x08\xfc\x02\x03\x0a\xfe\x08\x02\x0a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_30_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x0c\x11\x12\x16\x0c\x17\x05\x1f\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x1e\x13\x15\x13\x1d\x13\x1f\x0d\x10\x0d\x10\x13\x15\x13\x1c\x13\x1e\x0d\x10\x10\x14\x15\x18\x1a\x1e\x10\x1f\x09\x0d\x0c\x14\x15\x19\x0c\x1a\x05\x1a",
};
static struct PyCodeObject toplevel_consts_30 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 527,
    .co_code = & toplevel_consts_30_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_31_0 = {
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
    ._data = "_getfullpathname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_31 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_31_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_32_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x74\x01\x7c\x00\xa9\x01\xa9\x01\x53\x00\x23\x00\x74\x02\x74\x03\x66\x02\x79\x14\x01\x00\x74\x04\x7c\x00\xa9\x01\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_32_consts_0 = {
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
    ._data = "Return the absolute version of a path.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_32_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_32_consts_0._ascii.ob_base,
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
toplevel_consts_32_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_31_0._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_32_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0c\x01\x02\x80\x0a\x01\x0c\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_32_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x0c\xfe\x02\x80\x06\x01\x12\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_32_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x2b\x14\x1c\x1d\x2d\x2e\x32\x1d\x33\x14\x34\x0d\x34\x00\x00\x11\x18\x1a\x24\x10\x25\x09\x2b\x09\x2b\x14\x25\x26\x2a\x14\x2b\x0d\x2b\x0d\x2b\x0d\x2b\x09\x2b\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_32_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x05\x08\x00\x88\x0a\x15\x03\x94\x01\x15\x03",
};
static struct PyCodeObject toplevel_consts_32 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_32_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_32_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_32_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_32_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 551,
    .co_code = & toplevel_consts_32_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_22._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_22._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_32_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_33_0 = {
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
    ._data = "_getfinalpathname",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_33_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_33 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_33_0._ascii.ob_base,
            & toplevel_consts_33_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[177];
    }
toplevel_consts_34_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 176,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x01\x74\x00\xa9\x00\x7d\x02\x74\x01\x7c\x00\xa9\x01\x7c\x02\x76\x01\x72\x56\x7c\x02\xa0\x02\x74\x01\x7c\x00\xa9\x01\xa8\x01\xa9\x01\x01\x00\x09\x00\x7c\x00\x7d\x03\x74\x03\x7c\x00\xa9\x01\x7d\x00\x74\x04\x7c\x00\xa9\x01\x73\x31\x74\x05\x7c\x03\xa9\x01\x73\x28\x7c\x03\x7d\x00\x09\x00\x7c\x00\x53\x00\x74\x06\x74\x07\x74\x08\x7c\x03\xa9\x01\x7c\x00\xa9\x02\xa9\x01\x7d\x00\x6e\x1e\x23\x00\x74\x09\x79\x46\x7d\x04\x7c\x04\x6a\x0a\x7c\x01\x76\x00\x72\x41\x59\x00\x64\x00\x7d\x04\x7e\x04\x7c\x00\x53\x00\x82\x00\x64\x00\x7d\x04\x7e\x04\x77\x01\x74\x0b\x79\x4c\x01\x00\x59\x00\x7c\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x01\x7c\x00\xa9\x01\x7c\x02\x76\x01\x73\x0c\x7c\x00\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 5 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_4 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 21 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_5 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 32 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_6 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 50 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_7 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 67 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_8 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 87 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4390 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4392 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34_consts_1_11 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4393 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_34_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_16_consts_1.ob_base.ob_base,
            & toplevel_consts_16_consts_9.ob_base.ob_base,
            & toplevel_consts_34_consts_1_3.ob_base.ob_base,
            & toplevel_consts_34_consts_1_4.ob_base.ob_base,
            & toplevel_consts_34_consts_1_5.ob_base.ob_base,
            & toplevel_consts_34_consts_1_6.ob_base.ob_base,
            & toplevel_consts_34_consts_1_7.ob_base.ob_base,
            & toplevel_consts_34_consts_1_8.ob_base.ob_base,
            & toplevel_consts_34_consts_1_9.ob_base.ob_base,
            & toplevel_consts_34_consts_1_10.ob_base.ob_base,
            & toplevel_consts_34_consts_1_11.ob_base.ob_base,
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
toplevel_consts_34_consts = {
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
            & toplevel_consts_34_consts_1._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_34_names_0 = {
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
        uint8_t _data[4];
    }
toplevel_consts_34_names_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_34_names_3 = {
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
    ._data = "_nt_readlink",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_34_names_10 = {
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
    ._data = "winerror",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_34_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_34_names_0._ascii.ob_base,
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_34_names_2._ascii.ob_base,
            & toplevel_consts_34_names_3._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_11_13._ascii.ob_base,
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_11_7._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_34_names_10._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_34_varnames_1 = {
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
    ._data = "allowed_winerror",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_34_varnames_2 = {
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
        uint8_t _data[9];
    }
toplevel_consts_34_varnames_3 = {
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
    ._data = "old_path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_34_varnames_4 = {
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
    ._data = "ex",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_34_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_34_varnames_1._ascii.ob_base,
            & toplevel_consts_34_varnames_2._ascii.ob_base,
            & toplevel_consts_34_varnames_3._ascii.ob_base,
            & toplevel_consts_34_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_34_name = {
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
    ._data = "_readlink_deep",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_34_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0f\x06\x02\x0c\x01\x10\x01\x02\x01\x04\x01\x08\x01\x08\x03\x08\x04\x04\x01\x02\x01\x04\x09\x12\xf8\x04\x80\x06\x01\x0a\x01\x08\x01\x04\x05\x02\xfc\x08\x80\x06\x01\x02\x02\x04\x01\x02\xfd\x06\x80\x0c\xed\x04\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_34_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0f\x06\x02\x0a\x01\x02\x15\x10\xec\x02\x14\x04\xee\x08\x01\x06\x03\x02\x07\x06\xfd\x02\x02\x04\xff\x02\x01\x04\x09\x12\xf8\x04\x80\x02\x01\x04\x03\x08\xfe\x0a\x01\x04\x05\x02\xfc\x08\x80\x02\x01\x06\x02\x04\x01\x02\xff\x06\x80\x0a\xeb\x02\x15\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[177];
    }
toplevel_consts_34_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 176,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1c\x4c\x09\x19\x10\x13\x10\x15\x09\x0d\x0f\x17\x18\x1c\x0f\x1d\x25\x29\x0f\x29\x09\x16\x0d\x11\x0d\x25\x16\x1e\x1f\x23\x16\x24\x0d\x25\x0d\x25\x0d\x25\x0d\x16\x1c\x20\x11\x19\x18\x24\x25\x29\x18\x2a\x11\x15\x18\x1d\x1e\x22\x18\x23\x11\x43\x1c\x22\x23\x2b\x1c\x2c\x15\x1e\x20\x28\x19\x1d\x19\x1e\x10\x14\x09\x14\x1c\x24\x25\x29\x2a\x31\x32\x3a\x2a\x3b\x3d\x41\x25\x42\x1c\x43\x15\x19\x00\x00\x00\x00\x14\x1b\x0d\x16\x0d\x16\x14\x16\x14\x1f\x23\x33\x14\x33\x11\x1a\x15\x1a\x15\x1a\x15\x1a\x15\x1a\x10\x14\x09\x14\x11\x16\x00\x00\x00\x00\x00\x00\x00\x00\x14\x1e\x0d\x16\x0d\x16\x11\x16\x10\x14\x09\x14\x0d\x16\x00\x00\x00\x00\x00\x00\x0f\x17\x18\x1c\x0f\x1d\x25\x29\x0f\x29\x09\x16\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_34_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x10\x32\x00\xa8\x09\x32\x00\xb2\x04\x41\x0d\x03\xb6\x05\x41\x02\x03\xc1\x01\x01\x41\x02\x03\xc1\x02\x07\x41\x0d\x03\xc1\x0c\x01\x41\x0d\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_34_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 5,
    },
    .ob_shash = -1,
    .ob_sval = "     ",
};
static struct PyCodeObject toplevel_consts_34 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_34_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_34_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_34_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_34_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 564,
    .co_code = & toplevel_consts_34_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_34_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_34_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_34_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[221];
    }
toplevel_consts_35_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 220,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x01\x64\x02\x7d\x02\x7c\x00\x72\x6c\x09\x00\x74\x00\x7c\x00\xa9\x01\x7d\x00\x7c\x02\x72\x13\x74\x01\x7c\x00\x7c\x02\xa9\x02\x53\x00\x7c\x00\x53\x00\x23\x00\x74\x02\x79\x66\x7d\x03\x7c\x03\x6a\x03\x7c\x01\x76\x01\x72\x1f\x82\x00\x09\x00\x74\x04\x7c\x00\xa9\x01\x7d\x04\x7c\x04\x7c\x00\x6b\x03\x72\x36\x7c\x02\x72\x2f\x74\x01\x7c\x04\x7c\x02\xa9\x02\x6e\x01\x7c\x04\x02\x00\x59\x00\x64\x00\x7d\x03\x7e\x03\x53\x00\x6e\x0a\x23\x00\x74\x02\x79\x3d\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x05\x7c\x00\xa9\x01\x5c\x02\x7d\x00\x7d\x05\x7c\x00\x72\x54\x7c\x05\x73\x54\x7c\x00\x7c\x02\x7a\x00\x02\x00\x59\x00\x64\x00\x7d\x03\x7e\x03\x53\x00\x7c\x02\x72\x5b\x74\x01\x7c\x05\x7c\x02\xa9\x02\x6e\x01\x7c\x05\x7d\x02\x59\x00\x64\x00\x7d\x03\x7e\x03\x6e\x08\x64\x00\x7d\x03\x7e\x03\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x73\x07\x7c\x02\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_35_consts_1_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 123 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_35_consts_1_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 1920 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_35_consts_1_11 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 1921 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_35_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_16_consts_1.ob_base.ob_base,
            & toplevel_consts_16_consts_9.ob_base.ob_base,
            & toplevel_consts_34_consts_1_3.ob_base.ob_base,
            & toplevel_consts_34_consts_1_4.ob_base.ob_base,
            & toplevel_consts_34_consts_1_5.ob_base.ob_base,
            & toplevel_consts_34_consts_1_6.ob_base.ob_base,
            & toplevel_consts_34_consts_1_7.ob_base.ob_base,
            & toplevel_consts_34_consts_1_8.ob_base.ob_base,
            & toplevel_consts_35_consts_1_9.ob_base.ob_base,
            & toplevel_consts_35_consts_1_10.ob_base.ob_base,
            & toplevel_consts_35_consts_1_11.ob_base.ob_base,
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
toplevel_consts_35_consts = {
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
            & toplevel_consts_35_consts_1._object.ob_base.ob_base,
            & toplevel_consts_25_consts_7._ascii.ob_base,
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
toplevel_consts_35_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_33_0._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_34_names_10._ascii.ob_base,
            & toplevel_consts_34_name._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_35_varnames_4 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_35_varnames_5 = {
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
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_35_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_34_varnames_1._ascii.ob_base,
            & toplevel_consts_17_varnames_5._ascii.ob_base,
            & toplevel_consts_34_varnames_4._ascii.ob_base,
            & toplevel_consts_35_varnames_4._ascii.ob_base,
            & toplevel_consts_35_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_35_name = {
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
    ._data = "_getfinalpathname_nonstrict",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_35_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0f\x04\x04\x04\x01\x02\x01\x08\x01\x12\x01\x02\x80\x06\x01\x0a\x01\x02\x01\x02\x01\x08\x04\x08\x01\x1c\x01\x02\xff\x02\x80\x06\x02\x04\x02\x02\xfe\x06\x80\x0c\x03\x08\x04\x12\x01\x1c\x01\x08\x80\x02\xed\x06\x80\x04\xfc\x04\x18",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_35_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0f\x04\x04\x02\x01\x04\x17\x08\xeb\x12\x01\x02\x80\x02\x01\x04\x13\x08\xee\x04\x01\x02\x0a\x08\xfb\x06\x01\x20\x01\x02\x80\x02\x01\x0a\x02\x06\x80\x0c\x01\x02\x04\x02\x01\x02\xff\x14\x01\x1c\x01\x08\x80\x02\x00\x06\x80\x02\xe9\x02\x17\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[221];
    }
toplevel_consts_35_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 220,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1c\x4b\x09\x19\x10\x12\x09\x0d\x0f\x13\x09\x3a\x0d\x3a\x18\x29\x2a\x2e\x18\x2f\x11\x15\x2c\x30\x18\x3a\x18\x1c\x1d\x21\x23\x27\x18\x28\x11\x3a\x36\x3a\x11\x3a\x00\x00\x14\x1b\x0d\x3a\x0d\x3a\x14\x16\x14\x1f\x27\x37\x14\x37\x11\x1a\x15\x1a\x11\x19\x20\x2e\x2f\x33\x20\x34\x15\x1d\x18\x20\x24\x28\x18\x28\x15\x4a\x38\x3c\x20\x4a\x20\x24\x25\x2d\x2f\x33\x20\x34\x20\x34\x42\x4a\x19\x4a\x19\x4a\x19\x4a\x19\x4a\x19\x4a\x19\x4a\x15\x4a\x00\x00\x18\x1f\x11\x19\x11\x19\x15\x19\x15\x19\x11\x19\x00\x00\x00\x00\x00\x00\x1e\x23\x24\x28\x1e\x29\x11\x1b\x11\x15\x17\x1b\x14\x18\x11\x27\x21\x25\x11\x27\x1c\x20\x23\x27\x1c\x27\x15\x27\x15\x27\x15\x27\x15\x27\x15\x27\x15\x27\x2c\x30\x18\x3a\x18\x1c\x1d\x21\x23\x27\x18\x28\x18\x28\x36\x3a\x11\x15\x11\x15\x11\x15\x11\x15\x11\x15\x11\x15\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x3a\x00\x00\x00\x00\x00\x00\x0f\x13\x09\x3a\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_35_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x88\x0a\x15\x00\x93\x01\x15\x00\x95\x04\x41\x27\x03\x99\x06\x41\x22\x03\xa0\x10\x37\x02\xb0\x01\x41\x27\x03\xb6\x01\x41\x22\x03\xb7\x04\x3e\x05\xbb\x02\x41\x22\x03\xbd\x01\x3e\x05\xbe\x10\x41\x22\x03\xc1\x0e\x01\x41\x27\x03\xc1\x14\x09\x41\x22\x03\xc1\x22\x05\x41\x27\x03",
};
static struct PyCodeObject toplevel_consts_35 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_35_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_35_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_35_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_35_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 606,
    .co_code = & toplevel_consts_35_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_35_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_37_0 = {
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
    ._data = "strict",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_37 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_37_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[375];
    }
toplevel_consts_38_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 374,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x00\x74\x01\x7c\x00\x74\x02\xa9\x02\x72\x22\x64\x01\x7d\x02\x64\x02\x7d\x03\x64\x03\x7d\x04\x74\x03\x6a\x04\xa9\x00\x7d\x05\x74\x05\x7c\x00\xa9\x01\x74\x05\x74\x03\x6a\x06\x74\x07\xa9\x01\xa9\x01\x6b\x02\x72\x21\x64\x04\x53\x00\x6e\x14\x64\x05\x7d\x02\x64\x06\x7d\x03\x64\x07\x7d\x04\x74\x03\x6a\x08\xa9\x00\x7d\x05\x74\x05\x7c\x00\xa9\x01\x74\x05\x74\x07\xa9\x01\x6b\x02\x72\x36\x64\x08\x53\x00\x7c\x00\xa0\x09\x7c\x02\xa8\x01\xa9\x01\x7d\x06\x7c\x06\x73\x47\x74\x0a\x7c\x00\xa9\x01\x73\x47\x74\x0b\x7c\x05\x7c\x00\xa9\x02\x7d\x00\x09\x00\x74\x0c\x7c\x00\xa9\x01\x7d\x00\x64\x09\x7d\x07\x6e\x1b\x23\x00\x74\x0d\x79\x66\x7d\x08\x7c\x01\x72\x56\x82\x00\x7c\x08\x6a\x0e\x7d\x07\x74\x0f\x7c\x00\xa9\x01\x7d\x00\x59\x00\x64\x00\x7d\x08\x7e\x08\x6e\x08\x64\x00\x7d\x08\x7e\x08\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x06\x73\xb9\x7c\x00\xa0\x09\x7c\x02\xa8\x01\xa9\x01\x72\xb9\x7c\x00\xa0\x09\x7c\x03\xa8\x01\xa9\x01\x72\x83\x7c\x04\x7c\x00\x74\x10\x7c\x03\xa9\x01\x64\x00\x85\x02\x19\x00\x7a\x00\x7d\x09\x6e\x08\x7c\x00\x74\x10\x7c\x02\xa9\x01\x64\x00\x85\x02\x19\x00\x7d\x09\x09\x00\x74\x0c\x7c\x09\xa9\x01\x7c\x00\x6b\x02\x72\x97\x7c\x09\x7d\x00\x09\x00\x7c\x00\x53\x00\x09\x00\x7c\x00\x53\x00\x23\x00\x74\x0d\x79\xb5\x7d\x08\x7c\x08\x6a\x0e\x7c\x07\x6b\x02\x72\xab\x7c\x09\x7d\x00\x59\x00\x64\x00\x7d\x08\x7e\x08\x7c\x00\x53\x00\x59\x00\x64\x00\x7d\x08\x7e\x08\x7c\x00\x53\x00\x64\x00\x7d\x08\x7e\x08\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_38_consts_2 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\\\\?\\UNC\\",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_38_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\\\\",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_38_consts_4 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 7,
    },
    .ob_shash = -1,
    .ob_sval = "\\\\.\\NUL",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_38_consts_6 = {
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
    ._data = "\\\\?\\UNC\\",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_38_consts_7 = {
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
    ._data = "\\\\",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_38_consts_8 = {
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
    ._data = "\\\\.\\NUL",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_38_consts = {
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
            & toplevel_consts_14_consts_3.ob_base.ob_base,
            & toplevel_consts_38_consts_2.ob_base.ob_base,
            & toplevel_consts_38_consts_3.ob_base.ob_base,
            & toplevel_consts_38_consts_4.ob_base.ob_base,
            & toplevel_consts_14_consts_7._ascii.ob_base,
            & toplevel_consts_38_consts_6._ascii.ob_base,
            & toplevel_consts_38_consts_7._ascii.ob_base,
            & toplevel_consts_38_consts_8._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts_38_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_30_names_5._ascii.ob_base,
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_25_names_14._ascii.ob_base,
            & toplevel_consts_11_30._ascii.ob_base,
            & toplevel_consts_30_names_6._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_33_0._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_34_names_10._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_38_varnames_3 = {
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
    ._data = "unc_prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_38_varnames_4 = {
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
    ._data = "new_unc_prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_38_varnames_6 = {
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
    ._data = "had_prefix",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_38_varnames_7 = {
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
    ._data = "initial_winerror",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_38_varnames_9 = {
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
    ._data = "spath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_38_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_37_0._ascii.ob_base,
            & toplevel_consts_28_varnames_6._ascii.ob_base,
            & toplevel_consts_38_varnames_3._ascii.ob_base,
            & toplevel_consts_38_varnames_4._ascii.ob_base,
            & toplevel_consts_30_varnames_1._ascii.ob_base,
            & toplevel_consts_38_varnames_6._ascii.ob_base,
            & toplevel_consts_38_varnames_7._ascii.ob_base,
            & toplevel_consts_34_varnames_4._ascii.ob_base,
            & toplevel_consts_38_varnames_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_38_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0a\x01\x04\x01\x04\x01\x04\x01\x08\x01\x16\x02\x04\x01\x02\xff\x04\x03\x04\x01\x04\x01\x08\x01\x10\x02\x04\x01\x0c\x01\x0c\x01\x0a\x01\x02\x01\x08\x01\x06\x01\x02\x80\x06\x01\x04\x01\x02\x01\x06\x01\x12\x01\x08\x80\x02\xfc\x06\x80\x10\x08\x0c\x03\x16\x01\x10\x02\x02\x02\x0c\x01\x06\x01\x04\x06\x02\xf9\x04\x07\x02\x80\x06\xfb\x0a\x03\x0c\x01\x04\x01\x08\xfe\x04\x02\x08\x80\x02\xfb\x06\x80\x04\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[121];
    }
toplevel_consts_38_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 120,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x08\x01\x02\x0f\x04\xf2\x04\x01\x04\x01\x08\x01\x14\x02\x08\x01\x04\x02\x04\x01\x04\x01\x08\x01\x0e\x02\x06\x01\x0c\x01\x02\x01\x02\x01\x06\xff\x0c\x01\x02\x08\x08\xfa\x06\x01\x02\x80\x02\x01\x04\x04\x02\xfd\x04\x01\x06\x01\x12\x01\x08\x80\x02\x00\x06\x80\x02\x04\x02\x0f\x0a\xf1\x02\x0f\x0a\xf4\x02\x03\x16\xfe\x10\x02\x02\x09\x0a\xfa\x08\x01\x04\x06\x02\xfa\x04\x06\x02\x80\x02\xfb\x04\x04\x08\xff\x0e\x01\x04\x01\x08\xff\x04\x01\x08\x80\x02\xff\x06\x80\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[375];
    }
toplevel_consts_38_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 374,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x18\x19\x1d\x10\x1e\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x24\x16\x20\x0d\x13\x1a\x29\x0d\x17\x1e\x25\x0d\x1b\x13\x15\x13\x1d\x13\x1f\x0d\x10\x10\x18\x19\x1d\x10\x1e\x22\x2a\x2b\x2d\x2b\x36\x37\x3e\x2b\x3f\x22\x40\x10\x40\x0d\x25\x18\x25\x18\x25\x0d\x25\x16\x1f\x0d\x13\x1a\x28\x0d\x17\x1e\x24\x0d\x1b\x13\x15\x13\x1c\x13\x1e\x0d\x10\x10\x18\x19\x1d\x10\x1e\x22\x2a\x2b\x32\x22\x33\x10\x33\x0d\x24\x18\x24\x18\x24\x16\x1a\x16\x2d\x26\x2c\x16\x2d\x16\x2d\x09\x13\x10\x1a\x09\x23\x23\x28\x29\x2d\x23\x2e\x09\x23\x14\x18\x19\x1c\x1e\x22\x14\x23\x0d\x11\x09\x35\x14\x25\x26\x2a\x14\x2b\x0d\x11\x20\x21\x0d\x1d\x0d\x1d\x00\x00\x10\x17\x09\x35\x09\x35\x10\x16\x0d\x16\x11\x16\x20\x22\x20\x2b\x0d\x1d\x14\x2f\x30\x34\x14\x35\x0d\x11\x0d\x11\x0d\x11\x0d\x11\x0d\x11\x0d\x11\x00\x00\x00\x00\x00\x00\x00\x00\x09\x35\x00\x00\x00\x00\x00\x00\x10\x1a\x09\x21\x1f\x23\x1f\x36\x2f\x35\x1f\x36\x1f\x36\x09\x21\x10\x14\x10\x2b\x20\x2a\x10\x2b\x10\x2b\x0d\x2b\x19\x27\x2a\x2e\x2f\x32\x33\x3d\x2f\x3e\x2f\x3f\x2f\x3f\x2a\x40\x19\x40\x11\x16\x11\x16\x19\x1d\x1e\x21\x22\x28\x1e\x29\x1e\x2a\x1e\x2a\x19\x2b\x11\x16\x0d\x21\x14\x25\x26\x2b\x14\x2c\x30\x34\x14\x34\x11\x21\x1c\x21\x15\x19\x15\x19\x10\x14\x09\x14\x11\x21\x10\x14\x09\x14\x00\x00\x14\x1b\x0d\x21\x0d\x21\x14\x16\x14\x1f\x23\x33\x14\x33\x11\x21\x1c\x21\x15\x19\x15\x19\x15\x19\x15\x19\x15\x19\x10\x14\x09\x14\x11\x21\x11\x21\x11\x21\x11\x21\x10\x14\x09\x14\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x21\x00\x00\x00\x00\x00\x00\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_38_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x08\x06\x41\x0f\x00\xc1\x0f\x04\x41\x27\x03\xc1\x13\x0a\x41\x22\x03\xc1\x22\x05\x41\x27\x03\xc2\x0c\x08\x42\x1a\x00\xc2\x1a\x04\x42\x36\x03\xc2\x1e\x07\x42\x31\x03\xc2\x31\x05\x42\x36\x03",
};
static struct PyCodeObject toplevel_consts_38 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_38_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_38_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_38_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_38_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 4,
    .co_firstlineno = 652,
    .co_code = & toplevel_consts_38_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_38_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_15_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_31._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_31._ascii.ob_base,
    .co_linetable = & toplevel_consts_38_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_38_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_38_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_38_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_39 = {
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
    ._data = "getwindowsversion",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[345];
    }
toplevel_consts_42_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 344,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x12\x64\x01\x7d\x02\x64\x02\x7d\x03\x64\x03\x7d\x04\x6e\x06\x64\x04\x7d\x02\x64\x05\x7d\x03\x64\x06\x7d\x04\x7c\x01\x80\x1c\x7c\x03\x7d\x01\x7c\x00\x73\x22\x74\x04\x64\x08\xa9\x01\x82\x01\x74\x00\x6a\x01\x7c\x01\xa9\x01\x7d\x01\x09\x00\x74\x05\x74\x06\x7c\x01\xa9\x01\xa9\x01\x7d\x05\x74\x05\x74\x06\x7c\x00\xa9\x01\xa9\x01\x7d\x06\x74\x07\x7c\x05\xa9\x01\x5c\x02\x7d\x07\x7d\x08\x74\x07\x7c\x06\xa9\x01\x5c\x02\x7d\x09\x7d\x0a\x74\x08\x7c\x07\xa9\x01\x74\x08\x7c\x09\xa9\x01\x6b\x03\x72\x52\x74\x04\x64\x09\x7c\x09\x9b\x02\x64\x0a\x7c\x07\x9b\x02\x9d\x04\xa9\x01\x82\x01\x64\x0b\x84\x00\x7c\x08\xa0\x09\x7c\x02\xa8\x01\xa9\x01\x44\x00\xa9\x01\x7d\x0b\x64\x0c\x84\x00\x7c\x0a\xa0\x09\x7c\x02\xa8\x01\xa9\x01\x44\x00\xa9\x01\x7d\x0c\x64\x0d\x7d\x0d\x74\x0a\x7c\x0b\x7c\x0c\xa9\x02\x44\x00\x5d\x12\x5c\x02\x7d\x0e\x7d\x0f\x74\x08\x7c\x0e\xa9\x01\x74\x08\x7c\x0f\xa9\x01\x6b\x03\x72\x7b\x01\x00\x6e\x05\x7c\x0d\x64\x0e\x7a\x0d\x7d\x0d\x71\x6d\x7c\x04\x67\x01\x74\x0b\x7c\x0b\xa9\x01\x7c\x0d\x7a\x0a\x7a\x05\x7c\x0c\x7c\x0d\x64\x07\x85\x02\x19\x00\x7a\x00\x7d\x10\x7c\x10\x73\x93\x7c\x03\x53\x00\x74\x0c\x7c\x10\x8e\x00\x53\x00\x23\x00\x74\x0d\x74\x04\x74\x0e\x74\x0f\x74\x10\x66\x05\x79\xa8\x01\x00\x74\x11\x6a\x12\x64\x0f\x7c\x00\x7c\x01\xa9\x03\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_42_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 35,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return a relative version of a path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_42_consts_8 = {
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
    ._data = "no path specified",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_42_consts_9 = {
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
    ._data = "path is on mount ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_42_consts_10 = {
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
    ._data = ", start on mount ",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_42_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7c\x00\x5d\x06\x7d\x01\x7c\x01\x72\x03\x7c\x01\x91\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_42_consts_11_varnames_0 = {
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
toplevel_consts_42_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_24_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_42_consts_11_name = {
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
        uint8_t _data[28];
    }
toplevel_consts_42_consts_11_qualname = {
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
    ._data = "relpath.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_42_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x16\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_42_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x3d\x16\x3d\x16\x3d\x1d\x1e\x3b\x3c\x16\x3d\x17\x18\x16\x3d\x16\x3d\x16\x3d",
};
static struct PyCodeObject toplevel_consts_42_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_42_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 735,
    .co_code = & toplevel_consts_42_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_42_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_42_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_42_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_42_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_42_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_42_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_42_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x3b\x15\x3b\x15\x3b\x1c\x1d\x39\x3a\x15\x3b\x16\x17\x15\x3b\x15\x3b\x15\x3b",
};
static struct PyCodeObject toplevel_consts_42_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_42_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 736,
    .co_code = & toplevel_consts_42_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_42_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_42_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_42_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_42_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_42_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_42_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_42_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_42_consts_0._ascii.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_18_consts_3.ob_base.ob_base,
            & toplevel_consts_28_consts_4.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            Py_None,
            & toplevel_consts_42_consts_8._ascii.ob_base,
            & toplevel_consts_42_consts_9._ascii.ob_base,
            & toplevel_consts_42_consts_10._ascii.ob_base,
            & toplevel_consts_42_consts_11.ob_base,
            & toplevel_consts_42_consts_12.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_11_33._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_42_names_10 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_42_names_16 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_42_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_11_22._ascii.ob_base,
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
            & toplevel_consts_42_names_10._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_15_names_7._ascii.ob_base,
            & toplevel_consts_15_names_8._ascii.ob_base,
            & toplevel_consts_15_names_9._ascii.ob_base,
            & toplevel_consts_42_names_16._ascii.ob_base,
            & toplevel_consts_15_names_10._ascii.ob_base,
            & toplevel_consts_15_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_42_varnames_1 = {
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
    ._data = "start",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_42_varnames_5 = {
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
    ._data = "start_abs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_42_varnames_6 = {
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
    ._data = "path_abs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_42_varnames_7 = {
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
    ._data = "start_drive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_42_varnames_8 = {
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
    ._data = "start_rest",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_42_varnames_9 = {
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
    ._data = "path_drive",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_42_varnames_10 = {
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
    ._data = "path_rest",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_42_varnames_11 = {
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
    ._data = "start_list",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_42_varnames_12 = {
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
        uint8_t _data[3];
    }
toplevel_consts_42_varnames_14 = {
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
    ._data = "e1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_42_varnames_15 = {
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
    ._data = "e2",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_42_varnames_16 = {
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
    ._data = "rel_list",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts_42_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_42_varnames_1._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_24._ascii.ob_base,
            & toplevel_consts_42_varnames_5._ascii.ob_base,
            & toplevel_consts_42_varnames_6._ascii.ob_base,
            & toplevel_consts_42_varnames_7._ascii.ob_base,
            & toplevel_consts_42_varnames_8._ascii.ob_base,
            & toplevel_consts_42_varnames_9._ascii.ob_base,
            & toplevel_consts_42_varnames_10._ascii.ob_base,
            & toplevel_consts_42_varnames_11._ascii.ob_base,
            & toplevel_consts_42_varnames_12._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_42_varnames_14._ascii.ob_base,
            & toplevel_consts_42_varnames_15._ascii.ob_base,
            & toplevel_consts_42_varnames_16._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_42_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0a\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x02\x04\x01\x04\x02\x08\x01\x0a\x02\x02\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x10\x01\x04\x01\x0a\x01\x06\xff\x14\x03\x14\x01\x04\x02\x12\x01\x10\x01\x04\x01\x0a\x01\x1e\x02\x04\x01\x04\x01\x08\x01\x02\x80\x10\x01\x0e\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_42_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x02\x06\x01\x02\x02\x0a\x01\x0a\x02\x02\x19\x0c\xe9\x0c\x01\x0c\x01\x0c\x01\x0e\x01\x02\x02\x04\xff\x10\x01\x14\x02\x14\x01\x04\x02\x08\x01\x04\x03\x06\xfd\x0e\x01\x06\x01\x0a\x01\x1e\x02\x02\x01\x06\x01\x08\x01\x02\x80\x0c\x01\x04\x02\x0e\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[345];
    }
toplevel_consts_42_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 344,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x16\x0f\x14\x09\x0c\x12\x16\x09\x0f\x12\x17\x09\x0f\x09\x0f\x0f\x13\x09\x0c\x12\x15\x09\x0f\x12\x16\x09\x0f\x08\x0d\x05\x17\x11\x17\x09\x0e\x0c\x10\x05\x2e\x0f\x19\x1a\x2d\x0f\x2e\x09\x2e\x0d\x0f\x0d\x16\x17\x1c\x0d\x1d\x05\x0a\x05\x0e\x15\x1c\x1d\x25\x26\x2b\x1d\x2c\x15\x2d\x09\x12\x14\x1b\x1c\x24\x25\x29\x1c\x2a\x14\x2b\x09\x11\x23\x2d\x2e\x37\x23\x38\x09\x20\x09\x14\x16\x20\x21\x2b\x2c\x34\x21\x35\x09\x1e\x09\x13\x15\x1e\x0c\x14\x15\x20\x0c\x21\x25\x2d\x2e\x38\x25\x39\x0c\x39\x09\x2a\x13\x1d\x13\x1d\x11\x1b\x11\x1b\x11\x1b\x1d\x28\x1d\x28\x1e\x29\x13\x2a\x0d\x2a\x16\x3d\x16\x3d\x22\x2c\x22\x37\x33\x36\x22\x37\x22\x37\x16\x3d\x16\x3d\x09\x13\x15\x3b\x15\x3b\x21\x2a\x21\x35\x31\x34\x21\x35\x21\x35\x15\x3b\x15\x3b\x09\x12\x0d\x0e\x09\x0a\x17\x1a\x1b\x25\x27\x30\x17\x31\x09\x13\x09\x13\x0d\x13\x0d\x0f\x11\x13\x10\x18\x19\x1b\x10\x1c\x20\x28\x29\x2b\x20\x2c\x10\x2c\x0d\x16\x11\x16\x11\x16\x0d\x0e\x12\x13\x0d\x13\x0d\x0e\x0d\x0e\x15\x1b\x14\x1c\x20\x23\x24\x2e\x20\x2f\x30\x31\x20\x31\x14\x32\x35\x3e\x3f\x40\x3f\x41\x3f\x41\x35\x42\x14\x42\x09\x11\x10\x18\x09\x1a\x14\x1a\x0d\x1a\x10\x14\x16\x1e\x10\x1f\x09\x1f\x00\x00\x0d\x16\x18\x22\x24\x32\x34\x40\x42\x54\x0c\x55\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x2f\x31\x35\x37\x3c\x09\x3d\x09\x3d\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_42_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xa8\x41\x2a\x42\x17\x00\xc2\x13\x03\x42\x17\x00\xc2\x17\x12\x42\x29\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[18];
    }
toplevel_consts_42_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_42 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_42_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_42_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_42_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_42_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 707,
    .co_code = & toplevel_consts_42_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_42_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_42_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_33._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_33._ascii.ob_base,
    .co_linetable = & toplevel_consts_42_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_42_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_42_columntable.ob_base.ob_base,
    .co_nlocalsplus = 17,
    .co_nlocals = 17,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_42_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[417];
    }
toplevel_consts_43_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 416,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x0c\x87\x0d\x87\x0e\x97\x00\x7c\x00\x73\x0a\x74\x00\x64\x01\xa9\x01\x82\x01\x74\x01\x74\x02\x74\x03\x6a\x04\x7c\x00\xa9\x02\xa9\x01\x7d\x00\x74\x05\x7c\x00\x64\x02\x19\x00\x74\x06\xa9\x02\x72\x20\x64\x03\x8a\x0e\x64\x04\x8a\x0c\x64\x05\x8a\x0d\x6e\x06\x64\x06\x8a\x0e\x64\x07\x8a\x0c\x64\x08\x8a\x0d\x09\x00\x88\x0c\x88\x0e\x66\x02\x64\x09\x84\x08\x7c\x00\x44\x00\xa9\x01\x7d\x01\x88\x0e\x66\x01\x64\x0a\x84\x08\x7c\x01\x44\x00\xa9\x01\x7d\x02\x09\x00\x74\x07\x88\x0e\x66\x01\x64\x0b\x84\x08\x7c\x01\x44\x00\xa9\x01\xa9\x01\x5c\x01\x7d\x03\x6e\x0d\x23\x00\x74\x00\x79\x4e\x01\x00\x74\x00\x64\x0c\xa9\x01\x64\x0d\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x74\x08\x74\x07\x64\x0e\x84\x00\x7c\x01\x44\x00\xa9\x01\xa9\x01\xa9\x01\x64\x0f\x6b\x03\x72\x62\x74\x00\x64\x10\xa9\x01\x82\x01\x74\x09\x7c\x00\x64\x02\x19\x00\xa0\x0a\x89\x0c\x89\x0e\xa8\x02\xa9\x02\xa9\x01\x5c\x02\x7d\x04\x7d\x05\x7c\x05\xa0\x0b\x89\x0e\xa8\x01\xa9\x01\x7d\x06\x88\x0d\x66\x01\x64\x11\x84\x08\x7c\x06\x44\x00\xa9\x01\x7d\x06\x88\x0d\x66\x01\x64\x12\x84\x08\x7c\x02\x44\x00\xa9\x01\x7d\x02\x74\x0c\x7c\x02\xa9\x01\x7d\x07\x74\x0d\x7c\x02\xa9\x01\x7d\x08\x74\x0e\x7c\x07\xa9\x01\x44\x00\x5d\x12\x5c\x02\x7d\x09\x7d\x0a\x7c\x0a\x7c\x08\x7c\x09\x19\x00\x6b\x03\x72\xa3\x7c\x06\x64\x0d\x7c\x09\x85\x02\x19\x00\x7d\x06\x01\x00\x6e\x09\x71\x91\x7c\x06\x64\x0d\x74\x08\x7c\x07\xa9\x01\x85\x02\x19\x00\x7d\x06\x7c\x03\x72\xb2\x7c\x04\x89\x0e\x7a\x00\x6e\x01\x7c\x04\x7d\x0b\x7c\x0b\x89\x0e\xa0\x0f\x7c\x06\xa8\x01\xa9\x01\x7a\x00\x53\x00\x23\x00\x74\x10\x74\x11\x66\x02\x79\xcc\x01\x00\x74\x12\x6a\x13\x64\x13\x67\x01\x7c\x00\xa2\x01\x52\x00\x8e\x00\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[69];
    }
toplevel_consts_43_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 68,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Given a sequence of path names, returns the longest common sub-path.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_43_consts_1 = {
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
    ._data = "commonpath() arg is an empty sequence",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_43_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x02\x97\x00\x67\x00\x7c\x00\x5d\x0e\x7d\x01\x74\x00\x7c\x01\xa0\x01\x89\x02\x89\x03\xa8\x02\xa9\x02\xa0\x02\xa8\x00\xa9\x00\xa9\x01\x91\x02\x71\x04\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_43_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_13_names_5._ascii.ob_base,
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
toplevel_consts_43_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
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
toplevel_consts_43_consts_9_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_43_consts_9_qualname = {
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
    ._data = "commonpath.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x26\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_43_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x17\x52\x17\x52\x17\x52\x47\x48\x18\x22\x23\x24\x23\x39\x2d\x33\x35\x38\x23\x39\x23\x39\x23\x41\x23\x41\x23\x41\x18\x42\x17\x52\x17\x52\x17\x52",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_43_consts_9_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_9_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x80\x80",
};
static struct PyCodeObject toplevel_consts_43_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_43_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 780,
    .co_code = & toplevel_consts_43_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_9_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_9_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_43_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_9_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x67\x00\x7c\x00\x5d\x0a\x5c\x02\x7d\x01\x7d\x02\x7c\x02\xa0\x00\x89\x03\xa8\x01\xa9\x01\x91\x02\x71\x04\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_43_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
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
toplevel_consts_43_consts_10_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x1e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x17\x3d\x17\x3d\x17\x3d\x29\x2d\x29\x2a\x2c\x2d\x18\x19\x18\x24\x20\x23\x18\x24\x18\x24\x17\x3d\x17\x3d\x17\x3d",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_43_consts_10_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_10_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_43_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 781,
    .co_code = & toplevel_consts_43_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_10_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_10_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_43_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_10_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_43_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x0e\x5c\x02\x7d\x01\x7d\x02\x7c\x02\x64\x00\x64\x01\x85\x02\x19\x00\x89\x03\x6b\x02\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_43_consts_11_consts = {
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
            & toplevel_consts_14_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_43_consts_11_name = {
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
        uint8_t _data[30];
    }
toplevel_consts_43_consts_11_qualname = {
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
    ._data = "commonpath.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x26\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_43_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x19\x3f\x19\x3f\x2b\x2f\x2b\x2c\x2e\x2f\x1a\x1b\x1c\x1e\x1d\x1e\x1c\x1e\x1a\x1f\x23\x26\x1a\x26\x19\x3f\x19\x3f\x19\x3f\x19\x3f\x19\x3f\x19\x3f",
};
static struct PyCodeObject toplevel_consts_43_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 784,
    .co_code = & toplevel_consts_43_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_10_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_10_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_43_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_43_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_10_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_43_consts_12 = {
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
    ._data = "Can't mix absolute and relative paths",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_43_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x5d\x08\x5c\x02\x7d\x01\x7d\x02\x7c\x01\x56\x00\x97\x01\x01\x00\x71\x03\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_43_consts_14_consts = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_43_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x1a\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_43_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x13\x2e\x13\x2e\x1a\x1e\x1a\x1b\x1d\x1e\x14\x15\x13\x2e\x13\x2e\x13\x2e\x13\x2e\x13\x2e\x13\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_43_consts_14_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_43_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 791,
    .co_code = & toplevel_consts_43_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_14_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_43_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_14_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_43_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_43_consts_16 = {
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
    ._data = "Paths don't have the same drive",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x67\x00\x7c\x00\x5d\x0a\x7d\x01\x7c\x01\x72\x04\x7c\x01\x89\x02\x6b\x03\x72\x04\x7c\x01\x91\x02\x71\x04\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_43_consts_17_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_26_varnames_12._ascii.ob_base,
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
toplevel_consts_43_consts_17_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_23._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x12\x3a\x12\x3a\x12\x3a\x19\x1a\x28\x29\x12\x3a\x2e\x2f\x33\x39\x2e\x39\x12\x3a\x13\x14\x12\x3a\x12\x3a\x12\x3a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_43_consts_17_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_26_varnames_12._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_43_consts_17_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 3,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x80",
};
static struct PyCodeObject toplevel_consts_43_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 796,
    .co_code = & toplevel_consts_43_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_17_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_43_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_17_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x67\x00\x7c\x00\x5d\x0a\x7d\x01\x88\x02\x66\x01\x64\x00\x84\x08\x7c\x01\x44\x00\xa9\x01\x91\x02\x71\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_43_consts_18_consts_0_qualname = {
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
    ._data = "commonpath.<locals>.<listcomp>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_18_consts_0_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x18\x3b\x18\x3b\x18\x3b\x1f\x20\x29\x2a\x18\x3b\x2f\x30\x34\x3a\x2f\x3a\x18\x3b\x19\x1a\x18\x3b\x18\x3b\x18\x3b",
};
static struct PyCodeObject toplevel_consts_43_consts_18_consts_0 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 798,
    .co_code = & toplevel_consts_43_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_17_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_18_consts_0_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_18_consts_0_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_43_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_17_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_43_consts_18_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_43_consts_18_consts_0.ob_base,
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
toplevel_consts_43_consts_18_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_13_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_43_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x17\x51\x17\x51\x17\x51\x40\x41\x18\x3b\x18\x3b\x18\x3b\x18\x3b\x24\x25\x18\x3b\x18\x3b\x17\x51\x17\x51\x17\x51",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_43_consts_18_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_42_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_13_varnames_0._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_43_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 798,
    .co_code = & toplevel_consts_43_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_consts_18_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_42_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_43_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_43_consts_17_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_43_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            & toplevel_consts_43_consts_0._ascii.ob_base,
            & toplevel_consts_43_consts_1._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_13_consts_2.ob_base.ob_base,
            & toplevel_consts_13_consts_1.ob_base.ob_base,
            & toplevel_consts_18_consts_3.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_43_consts_9.ob_base,
            & toplevel_consts_43_consts_10.ob_base,
            & toplevel_consts_43_consts_11.ob_base,
            & toplevel_consts_43_consts_12._ascii.ob_base,
            Py_None,
            & toplevel_consts_43_consts_14.ob_base,
            & toplevel_consts_14_consts_8.ob_base.ob_base,
            & toplevel_consts_43_consts_16._ascii.ob_base,
            & toplevel_consts_43_consts_17.ob_base,
            & toplevel_consts_43_consts_18.ob_base,
            & toplevel_consts_11_37._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_43_names_1 = {
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
        uint8_t _data[4];
    }
toplevel_consts_43_names_12 = {
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
    ._data = "min",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_43_names_13 = {
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
    ._data = "max",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_43_names_14 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_43_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_43_names_1._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_consts_13_names_1._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_34_names_0._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_13_names_4._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
            & toplevel_consts_43_names_12._ascii.ob_base,
            & toplevel_consts_43_names_13._ascii.ob_base,
            & toplevel_consts_43_names_14._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_15_names_7._ascii.ob_base,
            & toplevel_consts_15_names_8._ascii.ob_base,
            & toplevel_consts_15_names_10._ascii.ob_base,
            & toplevel_consts_15_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_43_varnames_1 = {
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
    ._data = "drivesplits",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_43_varnames_2 = {
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
    ._data = "split_paths",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_43_varnames_6 = {
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
    ._data = "common",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_43_varnames_7 = {
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
    ._data = "s1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_43_varnames_8 = {
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
    ._data = "s2",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_43_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_2._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_25_varnames_5._ascii.ob_base,
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_43_varnames_6._ascii.ob_base,
            & toplevel_consts_43_varnames_7._ascii.ob_base,
            & toplevel_consts_43_varnames_8._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_26_varnames_12._ascii.ob_base,
            & toplevel_consts_28_varnames_6._ascii.ob_base,
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
toplevel_consts_43_cellvars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_43_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x06\x80\x02\x00\x04\x03\x08\x01\x10\x02\x0e\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x02\x12\x01\x10\x01\x02\x02\x18\x01\x02\x80\x06\x01\x0a\x01\x02\xff\x06\x80\x18\x06\x08\x01\x1a\x02\x0c\x01\x10\x01\x10\x02\x08\x01\x08\x01\x10\x01\x0c\x01\x0c\x01\x04\x01\x02\xfe\x10\x04\x10\x02\x10\x01\x02\x80\x0a\x01\x12\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_43_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x06\x80\x02\x00\x02\x03\x0a\x01\x10\x02\x0c\x01\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x23\x12\xe0\x10\x01\x02\x05\x18\xfe\x02\x80\x02\x01\x10\x01\x06\x80\x16\x05\x0a\x01\x1a\x02\x0c\x01\x10\x01\x10\x02\x08\x01\x08\x01\x06\x01\x04\x05\x06\xfb\x0a\x01\x02\x02\x0c\xff\x06\x01\x10\x02\x10\x02\x10\x01\x02\x80\x06\x01\x04\x02\x12\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[417];
    }
toplevel_consts_43_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 416,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x00\x00\x01\x01\x0c\x11\x05\x42\x0f\x19\x1a\x41\x0f\x42\x09\x42\x0d\x12\x13\x16\x17\x19\x17\x20\x22\x27\x13\x28\x0d\x29\x05\x0a\x08\x12\x13\x18\x19\x1a\x13\x1b\x1d\x22\x08\x23\x05\x15\x0f\x14\x09\x0c\x12\x16\x09\x0f\x12\x16\x09\x0f\x09\x0f\x0f\x13\x09\x0c\x12\x15\x09\x0f\x12\x15\x09\x0f\x05\x0e\x17\x52\x17\x52\x17\x52\x17\x52\x17\x52\x4c\x51\x17\x52\x17\x52\x09\x14\x17\x3d\x17\x3d\x17\x3d\x17\x3d\x31\x3c\x17\x3d\x17\x3d\x09\x14\x09\x50\x16\x19\x19\x3f\x19\x3f\x19\x3f\x19\x3f\x33\x3e\x19\x3f\x19\x3f\x16\x3f\x0d\x13\x0d\x12\x0d\x12\x00\x00\x10\x1a\x09\x50\x09\x50\x13\x1d\x1e\x45\x13\x46\x4c\x50\x0d\x50\x09\x50\x00\x00\x00\x00\x00\x00\x0c\x0f\x10\x13\x13\x2e\x13\x2e\x22\x2d\x13\x2e\x13\x2e\x10\x2e\x0c\x2f\x33\x34\x0c\x34\x09\x40\x13\x1d\x1e\x3f\x13\x40\x0d\x40\x17\x21\x22\x27\x28\x29\x22\x2a\x22\x3f\x33\x39\x3b\x3e\x22\x3f\x22\x3f\x17\x40\x09\x14\x09\x0e\x10\x14\x12\x16\x12\x21\x1d\x20\x12\x21\x12\x21\x09\x0f\x12\x3a\x12\x3a\x12\x3a\x12\x3a\x1e\x24\x12\x3a\x12\x3a\x09\x0f\x17\x51\x17\x51\x17\x51\x17\x51\x45\x50\x17\x51\x17\x51\x09\x14\x0e\x11\x12\x1d\x0e\x1e\x09\x0b\x0e\x11\x12\x1d\x0e\x1e\x09\x0b\x15\x1e\x1f\x21\x15\x22\x09\x26\x09\x26\x0d\x11\x0d\x0e\x10\x11\x10\x11\x15\x17\x18\x19\x15\x1a\x10\x1a\x0d\x16\x1a\x20\x21\x23\x22\x23\x21\x23\x1a\x24\x11\x17\x11\x16\x11\x16\x0d\x16\x16\x1c\x1d\x25\x1e\x21\x22\x24\x1e\x25\x1d\x25\x16\x26\x0d\x13\x21\x26\x12\x31\x12\x17\x1a\x1d\x12\x1d\x12\x1d\x2c\x31\x09\x0f\x10\x16\x19\x1c\x19\x29\x22\x28\x19\x29\x19\x29\x10\x29\x09\x29\x00\x00\x0d\x16\x18\x26\x0c\x27\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x32\x09\x3b\x35\x3a\x09\x3b\x09\x3b\x09\x3b\x09\x3b\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[36];
    }
toplevel_consts_43_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 35,
    },
    .ob_shash = -1,
    .ob_sval = "\xa7\x11\x42\x3c\x00\xb9\x0b\x41\x05\x00\xc1\x04\x01\x42\x3c\x00\xc1\x05\x0a\x41\x0f\x03\xc1\x0f\x41\x2c\x42\x3c\x00\xc2\x3c\x11\x43\x0d\x03",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_43_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_2._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_25_varnames_5._ascii.ob_base,
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_43_varnames_6._ascii.ob_base,
            & toplevel_consts_43_varnames_7._ascii.ob_base,
            & toplevel_consts_43_varnames_8._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_26_varnames_12._ascii.ob_base,
            & toplevel_consts_28_varnames_6._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[16];
    }
toplevel_consts_43_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 15,
    },
    .ob_shash = -1,
    .ob_sval = "            @@@",
};
static struct PyCodeObject toplevel_consts_43 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_43_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_43_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 763,
    .co_code = & toplevel_consts_43_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_43_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_37._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_37._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_columntable.ob_base.ob_base,
    .co_nlocalsplus = 15,
    .co_nlocals = 12,
    .co_nplaincellvars = 3,
    .co_ncellvars = 3,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_43_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_43_cellvars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_0 = {
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
    ._data = "_isdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_44 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[46];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 46,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_4._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            & toplevel_consts_6._ascii.ob_base,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            Py_None,
            & toplevel_consts_10._object.ob_base.ob_base,
            & toplevel_consts_11._object.ob_base.ob_base,
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
            & toplevel_consts_23._object.ob_base.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_25.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_27._object.ob_base.ob_base,
            & toplevel_consts_28.ob_base,
            & toplevel_consts_29.ob_base,
            & toplevel_consts_30.ob_base,
            & toplevel_consts_31._object.ob_base.ob_base,
            & toplevel_consts_32.ob_base,
            & toplevel_consts_33._object.ob_base.ob_base,
            & toplevel_consts_34.ob_base,
            & toplevel_consts_35.ob_base,
            Py_False,
            & toplevel_consts_37._object.ob_base.ob_base,
            & toplevel_consts_38.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_16_consts_9.ob_base.ob_base,
            & toplevel_consts_16_consts_1.ob_base.ob_base,
            & toplevel_consts_42.ob_base,
            & toplevel_consts_43.ob_base,
            & toplevel_consts_44._object.ob_base.ob_base,
            & toplevel_consts_43_consts_14_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_0 = {
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
toplevel_names_10 = {
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
        uint8_t _data[8];
    }
toplevel_names_13 = {
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
        uint8_t _data[3];
    }
toplevel_names_26 = {
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
        uint8_t _data[12];
    }
toplevel_names_28 = {
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
        uint8_t _data[8];
    }
toplevel_names_43 = {
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
            PyObject *ob_item[50];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 50,
        },
        .ob_item = {
            & toplevel_names_0._ascii.ob_base,
            & toplevel_consts_11_23._ascii.ob_base,
            & toplevel_consts_11_24._ascii.ob_base,
            & toplevel_consts_11_29._ascii.ob_base,
            & toplevel_consts_11_25._ascii.ob_base,
            & toplevel_consts_11_26._ascii.ob_base,
            & toplevel_consts_11_28._ascii.ob_base,
            & toplevel_consts_11_27._ascii.ob_base,
            & toplevel_consts_11_30._ascii.ob_base,
            & toplevel_consts_13_names_0._ascii.ob_base,
            & toplevel_names_10._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_15_names_10._ascii.ob_base,
            & toplevel_names_13._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_11_1._ascii.ob_base,
            & toplevel_consts_11_2._ascii.ob_base,
            & toplevel_consts_11_3._ascii.ob_base,
            & toplevel_consts_11_4._ascii.ob_base,
            & toplevel_consts_11_5._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_11_6._ascii.ob_base,
            & toplevel_consts_11_7._ascii.ob_base,
            & toplevel_consts_11_13._ascii.ob_base,
            & toplevel_consts_11_15._ascii.ob_base,
            & toplevel_names_26._ascii.ob_base,
            & toplevel_consts_23_0._ascii.ob_base,
            & toplevel_names_28._ascii.ob_base,
            & toplevel_consts_11_18._ascii.ob_base,
            & toplevel_consts_11_19._ascii.ob_base,
            & toplevel_consts_11_20._ascii.ob_base,
            & toplevel_consts_27_0._ascii.ob_base,
            & toplevel_consts_11_21._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
            & toplevel_consts_31_0._ascii.ob_base,
            & toplevel_consts_11_22._ascii.ob_base,
            & toplevel_consts_33_0._ascii.ob_base,
            & toplevel_consts_33_1._ascii.ob_base,
            & toplevel_consts_34_names_3._ascii.ob_base,
            & toplevel_consts_11_31._ascii.ob_base,
            & toplevel_consts_34_name._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
            & toplevel_names_43._ascii.ob_base,
            & toplevel_consts_39._ascii.ob_base,
            & toplevel_consts_11_32._ascii.ob_base,
            & toplevel_consts_11_33._ascii.ob_base,
            & toplevel_consts_11_37._ascii.ob_base,
            & toplevel_consts_44_0._ascii.ob_base,
            & toplevel_consts_11_16._ascii.ob_base,
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
        char ob_sval[155];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 154,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x01\x04\x09\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x08\x02\x08\x01\x08\x01\x08\x01\x08\x01\x08\x02\x06\x08\x06\x0a\x06\x11\x06\x10\x06\x2f\x06\x38\x06\x17\x0a\x06\x06\x05\x06\x07\x06\x07\x06\x0c\x02\x12\x0e\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x06\x02\x06\x1d\x06\x3d\x02\x70\x0e\x01\x02\x80\x06\x02\x0a\x01\x02\xff\x06\x80\x06\x34\x06\x08\x02\x11\x0e\x01\x02\x80\x06\x02\x08\x01\x02\xff\x06\x80\x06\x04\x02\x07\x12\x01\x02\x80\x06\x01\x08\x02\x02\xfe\x06\x80\x06\x04\x06\x2a\x0c\x2e\x0a\x34\x0e\x01\x02\xff\x08\x03\x06\x38\x02\x34\x10\x05\x02\x80\x06\x01\x06\x02\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[155];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 154,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x05\x04\x05\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x08\x02\x08\x01\x08\x01\x08\x01\x08\x01\x06\x08\x02\xfa\x06\x0c\x06\x0e\x06\x15\x06\x2d\x06\x36\x06\x17\x06\x0d\x0a\x01\x06\x07\x06\x07\x06\x0d\x06\x0a\x02\x0f\x0e\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x06\x12\x06\x39\x06\x7a\x02\x42\x0e\xc5\x02\x80\x02\x02\x10\x31\x06\x80\x06\x08\x06\x11\x02\x0f\x0e\xf5\x02\x80\x02\x02\x0e\x01\x06\x80\x06\x08\x00\x7f\x02\x11\x00\x81\x12\xf2\x02\x80\x02\x01\x0e\x02\x06\x80\x06\x2a\x06\x2e\x02\x02\x0a\x30\x08\x04\x10\x01\x02\xff\x02\x03\x06\x2b\x06\x3e\x02\x0b\x10\xfd\x02\x80\x02\x01\x0c\x02\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[469];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 468,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x0a\x0d\x01\x07\x0a\x0e\x01\x07\x0a\x0d\x01\x07\x07\x0b\x01\x04\x0b\x0e\x01\x08\x0a\x0d\x01\x07\x0b\x16\x01\x08\x0b\x10\x01\x08\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x13\x01\x13\x01\x13\x01\x13\x01\x1a\x01\x1a\x01\x1a\x01\x1a\x0b\x41\x0b\x41\x0b\x41\x01\x08\x01\x15\x01\x15\x01\x15\x01\x2c\x01\x2c\x01\x2c\x01\x3c\x01\x3c\x01\x3c\x01\x0e\x01\x0e\x01\x0e\x01\x14\x01\x14\x01\x14\x01\x1a\x01\x1a\x01\x1a\x01\x38\x01\x38\x01\x38\x14\x1f\x14\x29\x14\x31\x01\x09\x01\x11\x01\x17\x01\x17\x01\x17\x01\x17\x01\x17\x01\x17\x01\x24\x01\x24\x01\x24\x01\x10\x01\x10\x01\x10\x01\x1e\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26\x00\x00\x08\x13\x01\x1e\x01\x1e\x1a\x1e\x05\x17\x05\x17\x05\x17\x01\x1e\x00\x00\x00\x00\x00\x00\x01\x15\x01\x15\x01\x15\x01\x1f\x01\x1f\x01\x1f\x01\x0f\x01\x0f\x01\x0f\x01\x2b\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22\x00\x00\x08\x13\x01\x28\x01\x28\x05\x28\x05\x28\x05\x28\x05\x28\x05\x28\x01\x28\x00\x00\x00\x00\x00\x00\x05\x2b\x05\x2b\x05\x2b\x01\x1a\x01\x1a\x01\x1a\x01\x2b\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x00\x00\x08\x13\x01\x20\x01\x20\x0f\x20\x05\x0c\x05\x0c\x05\x0c\x01\x20\x00\x00\x00\x00\x00\x00\x05\x2b\x05\x2b\x05\x2b\x01\x14\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x00\x00\x08\x13\x01\x17\x01\x17\x10\x17\x05\x0d\x05\x0d\x05\x0d\x01\x17\x00\x00\x00\x00\x00\x00\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x22\x27\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x1f\x26\x27\x2a\x2c\x3f\x1f\x40\x1f\x3e\x1f\x22\x1f\x34\x1f\x36\x37\x38\x1f\x39\x3d\x3e\x1f\x3e\x01\x1b\x19\x1d\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x09\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x00\x00\x08\x13\x01\x09\x01\x09\x05\x09\x05\x09\x05\x09\x01\x09\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[91];
    }
toplevel_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 90,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x12\x06\x41\x19\x00\xc1\x19\x06\x41\x22\x03\xc1\x21\x01\x41\x22\x03\xc1\x2f\x06\x41\x36\x00\xc1\x36\x07\x42\x00\x03\xc1\x3f\x01\x42\x00\x03\xc2\x0a\x06\x42\x11\x00\xc2\x11\x06\x42\x1a\x03\xc2\x19\x01\x42\x1a\x03\xc2\x21\x08\x42\x2a\x00\xc2\x2a\x06\x42\x33\x03\xc2\x32\x01\x42\x33\x03\xc3\x17\x06\x43\x1f\x00\xc3\x1f\x04\x43\x27\x03\xc3\x26\x01\x43\x27\x03",
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
    .co_stacksize = 4,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_ntpath_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

