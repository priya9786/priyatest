#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[289];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 288,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x5a\x01\x64\x02\x5a\x02\x64\x01\x5a\x03\x64\x03\x5a\x04\x64\x04\x5a\x05\x64\x05\x5a\x06\x64\x06\x5a\x07\x64\x07\x5a\x08\x64\x08\x64\x06\x6c\x09\x5a\x09\x64\x08\x64\x06\x6c\x0a\x5a\x0a\x64\x08\x64\x06\x6c\x0b\x5a\x0b\x64\x08\x64\x06\x6c\x0c\x5a\x0c\x64\x08\x64\x09\x6c\x0c\x54\x00\x67\x00\x64\x0a\xa2\x01\x5a\x0d\x64\x0b\x84\x00\x5a\x0e\x64\x0c\x84\x00\x5a\x0f\x64\x0d\x84\x00\x5a\x10\x64\x0e\x84\x00\x5a\x11\x64\x0f\x84\x00\x5a\x12\x64\x10\x84\x00\x5a\x13\x65\x0c\x6a\x14\x6a\x00\x65\x13\x5f\x00\x64\x11\x84\x00\x5a\x15\x64\x12\x84\x00\x5a\x16\x64\x13\x84\x00\x5a\x17\x64\x14\x84\x00\x5a\x18\x64\x15\x84\x00\x5a\x19\x64\x16\x84\x00\x5a\x1a\x64\x17\x84\x00\x5a\x1b\x64\x06\x61\x1c\x64\x06\x61\x1d\x64\x18\x84\x00\x5a\x1e\x09\x00\x64\x08\x64\x19\x6c\x1f\x6d\x20\x5a\x20\x01\x00\x6e\x0d\x23\x00\x65\x21\x79\x6f\x01\x00\x64\x1a\x84\x00\x5a\x22\x59\x00\x6e\x07\x77\x00\x78\x03\x59\x00\x77\x01\x64\x1b\x84\x00\x5a\x22\x64\x1c\x84\x00\x5a\x23\x64\x1d\x64\x1e\x9c\x01\x64\x1f\x84\x02\x5a\x24\x64\x20\x84\x00\x5a\x25\x65\x0a\x6a\x26\x64\x21\x6b\x02\x5a\x27\x64\x24\x64\x22\x84\x01\x5a\x28\x64\x23\x84\x00\x5a\x29\x64\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[474];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 473,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x6f\x6d\x6d\x6f\x6e\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x6f\x6e\x20\x50\x6f\x73\x69\x78\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x73\x2e\x0a\x0a\x49\x6e\x73\x74\x65\x61\x64\x20\x6f\x66\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x2c\x20\x69\x6d\x70\x6f\x72\x74\x20\x6f\x73\x20\x61\x6e\x64\x20\x72\x65\x66\x65\x72\x20\x74\x6f\x0a\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x61\x73\x20\x6f\x73\x2e\x70\x61\x74\x68\x2e\x20\x20\x54\x68\x65\x20\x22\x6f\x73\x2e\x70\x61\x74\x68\x22\x20\x6e\x61\x6d\x65\x20\x69\x73\x20\x61\x6e\x20\x61\x6c\x69\x61\x73\x20\x66\x6f\x72\x20\x74\x68\x69\x73\x0a\x6d\x6f\x64\x75\x6c\x65\x20\x6f\x6e\x20\x50\x6f\x73\x69\x78\x20\x73\x79\x73\x74\x65\x6d\x73\x3b\x20\x6f\x6e\x20\x6f\x74\x68\x65\x72\x20\x73\x79\x73\x74\x65\x6d\x73\x20\x28\x65\x2e\x67\x2e\x20\x57\x69\x6e\x64\x6f\x77\x73\x29\x2c\x0a\x6f\x73\x2e\x70\x61\x74\x68\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x69\x6e\x20\x61\x20\x6d\x61\x6e\x6e\x65\x72\x20\x73\x70\x65\x63\x69\x66\x69\x63\x20\x74\x6f\x20\x74\x68\x61\x74\x0a\x70\x6c\x61\x74\x66\x6f\x72\x6d\x2c\x20\x61\x6e\x64\x20\x69\x73\x20\x61\x6e\x20\x61\x6c\x69\x61\x73\x20\x74\x6f\x20\x61\x6e\x6f\x74\x68\x65\x72\x20\x6d\x6f\x64\x75\x6c\x65\x20\x28\x65\x2e\x67\x2e\x20\x6e\x74\x70\x61\x74\x68\x29\x2e\x0a\x0a\x53\x6f\x6d\x65\x20\x6f\x66\x20\x74\x68\x69\x73\x20\x63\x61\x6e\x20\x61\x63\x74\x75\x61\x6c\x6c\x79\x20\x62\x65\x20\x75\x73\x65\x66\x75\x6c\x20\x6f\x6e\x20\x6e\x6f\x6e\x2d\x50\x6f\x73\x69\x78\x20\x73\x79\x73\x74\x65\x6d\x73\x20\x74\x6f\x6f\x2c\x20\x65\x2e\x67\x2e\x0a\x66\x6f\x72\x20\x6d\x61\x6e\x69\x70\x75\x6c\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x20\x6f\x66\x20\x55\x52\x4c\x73\x2e\x0a",
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
    ._data = "/",
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
    ._data = ":",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5 = {
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
    ._data = "/bin:/usr/bin",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_7 = {
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
    ._data = "/dev/null",
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
        uint8_t _data[9];
    }
toplevel_consts_10_0 = {
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
toplevel_consts_10_1 = {
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
toplevel_consts_10_2 = {
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
toplevel_consts_10_3 = {
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
toplevel_consts_10_4 = {
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
toplevel_consts_10_5 = {
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
toplevel_consts_10_6 = {
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
toplevel_consts_10_7 = {
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
toplevel_consts_10_8 = {
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
toplevel_consts_10_9 = {
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
toplevel_consts_10_10 = {
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
toplevel_consts_10_11 = {
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
toplevel_consts_10_12 = {
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
toplevel_consts_10_13 = {
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
toplevel_consts_10_14 = {
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
toplevel_consts_10_15 = {
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
toplevel_consts_10_16 = {
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
toplevel_consts_10_17 = {
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
toplevel_consts_10_18 = {
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
toplevel_consts_10_19 = {
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
toplevel_consts_10_20 = {
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
toplevel_consts_10_21 = {
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
toplevel_consts_10_22 = {
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
        uint8_t _data[9];
    }
toplevel_consts_10_23 = {
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
toplevel_consts_10_24 = {
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
toplevel_consts_10_25 = {
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
toplevel_consts_10_26 = {
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
toplevel_consts_10_27 = {
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
toplevel_consts_10_28 = {
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
toplevel_consts_10_29 = {
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
toplevel_consts_10_30 = {
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
toplevel_consts_10_31 = {
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
toplevel_consts_10_32 = {
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
toplevel_consts_10_33 = {
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
toplevel_consts_10_34 = {
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
toplevel_consts_10_35 = {
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
toplevel_consts_10_36 = {
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
        uint8_t _data[11];
    }
toplevel_consts_10_37 = {
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
toplevel_consts_10 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 38,
        },
        .ob_item = {
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_10_3._ascii.ob_base,
            & toplevel_consts_10_4._ascii.ob_base,
            & toplevel_consts_10_5._ascii.ob_base,
            & toplevel_consts_10_6._ascii.ob_base,
            & toplevel_consts_10_7._ascii.ob_base,
            & toplevel_consts_10_8._ascii.ob_base,
            & toplevel_consts_10_9._ascii.ob_base,
            & toplevel_consts_10_10._ascii.ob_base,
            & toplevel_consts_10_11._ascii.ob_base,
            & toplevel_consts_10_12._ascii.ob_base,
            & toplevel_consts_10_13._ascii.ob_base,
            & toplevel_consts_10_14._ascii.ob_base,
            & toplevel_consts_10_15._ascii.ob_base,
            & toplevel_consts_10_16._ascii.ob_base,
            & toplevel_consts_10_17._ascii.ob_base,
            & toplevel_consts_10_18._ascii.ob_base,
            & toplevel_consts_10_19._ascii.ob_base,
            & toplevel_consts_10_20._ascii.ob_base,
            & toplevel_consts_10_21._ascii.ob_base,
            & toplevel_consts_10_22._ascii.ob_base,
            & toplevel_consts_10_23._ascii.ob_base,
            & toplevel_consts_10_24._ascii.ob_base,
            & toplevel_consts_10_25._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_27._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_10_29._ascii.ob_base,
            & toplevel_consts_10_30._ascii.ob_base,
            & toplevel_consts_10_31._ascii.ob_base,
            & toplevel_consts_10_32._ascii.ob_base,
            & toplevel_consts_10_33._ascii.ob_base,
            & toplevel_consts_10_34._ascii.ob_base,
            & toplevel_consts_10_35._ascii.ob_base,
            & toplevel_consts_10_36._ascii.ob_base,
            & toplevel_consts_10_37._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_11_code = {
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
        char ob_sval[2];
    }
toplevel_consts_11_consts_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_11_consts = {
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
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_names_0 = {
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
toplevel_consts_11_names_1 = {
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
toplevel_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_varnames_0 = {
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
toplevel_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
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
toplevel_consts_11_freevars = {
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
        uint8_t _data[19];
    }
toplevel_consts_11_filename = {
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
    ._data = "<frozen posixpath>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_name = {
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
    ._data = "_get_sep",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_11_linetable = {
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
toplevel_consts_11_endlinetable = {
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
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x13\x10\x14\x10\x14\x10\x13\x10\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_11_exceptiontable = {
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
toplevel_consts_11_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 41,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[55];
    }
toplevel_consts_12_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 54,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Normalize case of pathname.  Has no effect under Posix",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_12_names_0 = {
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
toplevel_consts_12_names_1 = {
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
        uint8_t _data[2];
    }
toplevel_consts_12_varnames_0 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x17\x0c\x18\x05\x18",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 52,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x7c\x00\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_13_consts_0 = {
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
        uint8_t _data[11];
    }
toplevel_consts_13_names_3 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
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
toplevel_consts_13_varnames = {
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
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
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
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0b\x13\x14\x15\x0b\x16\x05\x08\x0c\x0d\x0c\x1d\x19\x1c\x0c\x1d\x0c\x1d\x05\x1d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_13_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 60,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[171];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 170,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x02\x7c\x00\x7d\x03\x09\x00\x7c\x01\x73\x17\x7c\x03\x64\x01\x64\x02\x85\x02\x19\x00\x7c\x02\x7a\x00\x01\x00\x74\x03\x74\x00\x6a\x01\x7c\x01\xa9\x02\x44\x00\x5d\x1e\x7d\x04\x7c\x04\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x72\x28\x7c\x04\x7d\x03\x71\x1d\x7c\x03\x72\x30\x7c\x03\xa0\x05\x7c\x02\xa8\x01\xa9\x01\x72\x35\x7c\x03\x7c\x04\x7a\x0d\x7d\x03\x71\x1d\x7c\x03\x7c\x02\x7c\x04\x7a\x00\x7a\x0d\x7d\x03\x71\x1d\x09\x00\x7c\x03\x53\x00\x23\x00\x74\x06\x74\x07\x74\x08\x66\x03\x79\x51\x01\x00\x74\x09\x6a\x0a\x64\x03\x7c\x00\x67\x02\x7c\x01\xa2\x01\x52\x00\x8e\x00\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[231];
    }
toplevel_consts_14_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 230,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4a\x6f\x69\x6e\x20\x74\x77\x6f\x20\x6f\x72\x20\x6d\x6f\x72\x65\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x73\x2c\x20\x69\x6e\x73\x65\x72\x74\x69\x6e\x67\x20\x27\x2f\x27\x20\x61\x73\x20\x6e\x65\x65\x64\x65\x64\x2e\x0a\x20\x20\x20\x20\x49\x66\x20\x61\x6e\x79\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x20\x69\x73\x20\x61\x6e\x20\x61\x62\x73\x6f\x6c\x75\x74\x65\x20\x70\x61\x74\x68\x2c\x20\x61\x6c\x6c\x20\x70\x72\x65\x76\x69\x6f\x75\x73\x20\x70\x61\x74\x68\x20\x63\x6f\x6d\x70\x6f\x6e\x65\x6e\x74\x73\x0a\x20\x20\x20\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x64\x69\x73\x63\x61\x72\x64\x65\x64\x2e\x20\x20\x41\x6e\x20\x65\x6d\x70\x74\x79\x20\x6c\x61\x73\x74\x20\x70\x61\x72\x74\x20\x77\x69\x6c\x6c\x20\x72\x65\x73\x75\x6c\x74\x20\x69\x6e\x20\x61\x20\x70\x61\x74\x68\x20\x74\x68\x61\x74\x0a\x20\x20\x20\x20\x65\x6e\x64\x73\x20\x77\x69\x74\x68\x20\x61\x20\x73\x65\x70\x61\x72\x61\x74\x6f\x72\x2e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_14_names_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_14_names_5 = {
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
        uint8_t _data[10];
    }
toplevel_consts_14_names_6 = {
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
toplevel_consts_14_names_7 = {
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
toplevel_consts_14_names_8 = {
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
toplevel_consts_14_names_9 = {
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
toplevel_consts_14_names_10 = {
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
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_14_names_3._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_14_names_6._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_14_names_8._ascii.ob_base,
            & toplevel_consts_14_names_9._ascii.ob_base,
            & toplevel_consts_14_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_14_varnames_0 = {
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
    ._data = "a",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_14_varnames_1 = {
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
        uint8_t _data[2];
    }
toplevel_consts_14_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_14_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_0._ascii.ob_base,
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_14_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x05\x08\x01\x04\x01\x02\x01\x04\x01\x10\x01\x10\x01\x0c\x01\x06\x01\x10\x01\x0a\x01\x0e\x02\x02\xfa\x04\x0a\x02\x80\x0c\xfd\x14\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x05\x08\x01\x04\x01\x02\x0d\x02\xf5\x12\x01\x0a\x01\x04\x06\x02\xfa\x0a\x01\x02\x05\x06\xfc\x02\x01\x02\x03\x0a\xfd\x02\x03\x0a\xfe\x10\x02\x04\x04\x02\x80\x08\xfd\x04\x02\x14\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[171];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 170,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0b\x13\x14\x15\x0b\x16\x05\x08\x0c\x0d\x05\x09\x05\x0e\x10\x11\x09\x1b\x0d\x11\x12\x14\x13\x14\x12\x14\x0d\x15\x18\x1b\x0d\x1b\x0d\x1b\x12\x15\x16\x18\x16\x1f\x21\x22\x12\x23\x09\x20\x09\x20\x0d\x0e\x10\x11\x10\x21\x1d\x20\x10\x21\x10\x21\x0d\x20\x18\x19\x11\x15\x11\x15\x16\x1a\x0d\x20\x1e\x22\x1e\x30\x2c\x2f\x1e\x30\x1e\x30\x0d\x20\x11\x15\x19\x1a\x11\x1a\x11\x15\x11\x15\x11\x15\x19\x1c\x1f\x20\x19\x20\x11\x20\x11\x15\x11\x15\x09\x20\x0c\x10\x05\x10\x00\x00\x0d\x16\x18\x26\x28\x34\x0c\x35\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x2c\x2e\x2f\x09\x34\x32\x33\x09\x34\x09\x34\x09\x34\x09\x34\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_14_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 9,
    },
    .ob_shash = -1,
    .ob_sval = "\x8d\x2f\x3f\x00\xbf\x13\x41\x12\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_14_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_14_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 71,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[103];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 102,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x7c\x00\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x64\x01\x7a\x00\x7d\x02\x7c\x00\x64\x02\x7c\x02\x85\x02\x19\x00\x7c\x00\x7c\x02\x64\x02\x85\x02\x19\x00\x02\x02\x7d\x03\x7d\x04\x7c\x03\x72\x2f\x7c\x03\x7c\x01\x74\x04\x7c\x03\xa9\x01\x7a\x05\x6b\x03\x72\x2f\x7c\x03\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x7d\x03\x7c\x03\x7c\x04\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[129];
    }
toplevel_consts_15_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 128,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x70\x6c\x69\x74\x20\x61\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x2e\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x75\x70\x6c\x65\x20\x22\x28\x68\x65\x61\x64\x2c\x20\x74\x61\x69\x6c\x29\x22\x20\x77\x68\x65\x72\x65\x20\x22\x74\x61\x69\x6c\x22\x20\x69\x73\x0a\x20\x20\x20\x20\x65\x76\x65\x72\x79\x74\x68\x69\x6e\x67\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x66\x69\x6e\x61\x6c\x20\x73\x6c\x61\x73\x68\x2e\x20\x20\x45\x69\x74\x68\x65\x72\x20\x70\x61\x72\x74\x20\x6d\x61\x79\x20\x62\x65\x20\x65\x6d\x70\x74\x79\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_15_consts_1 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_15_names_3 = {
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
    ._data = "rfind",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_15_names_4 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_15_names_5 = {
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
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_15_names_3._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_15_varnames_2 = {
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
    ._data = "head",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_15_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x01\x10\x01\x1a\x01\x14\x01\x0c\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x01\x10\x01\x1a\x01\x02\x01\x02\x01\x0e\xff\x0e\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[103];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 102,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0b\x13\x14\x15\x0b\x16\x05\x08\x09\x0a\x09\x15\x11\x14\x09\x15\x09\x15\x18\x19\x09\x19\x05\x06\x12\x13\x14\x16\x15\x16\x14\x16\x12\x17\x19\x1a\x1b\x1c\x1b\x1d\x1b\x1d\x19\x1e\x12\x1e\x05\x09\x0b\x0f\x08\x0c\x05\x20\x11\x15\x19\x1c\x1d\x20\x21\x25\x1d\x26\x19\x26\x11\x26\x05\x20\x10\x14\x10\x20\x1c\x1f\x10\x20\x10\x20\x09\x0d\x0c\x10\x12\x16\x0c\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 100,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x10\x64\x01\x7d\x01\x64\x02\x7d\x02\x6e\x04\x64\x03\x7d\x01\x64\x04\x7d\x02\x74\x04\x6a\x05\x7c\x00\x7c\x01\x64\x00\x7c\x02\xa9\x04\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_16_consts_2 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_16_consts = {
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
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_16_names_5 = {
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
toplevel_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_14_names_9._ascii.ob_base,
            & toplevel_consts_16_names_5._ascii.ob_base,
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
toplevel_consts_16_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_10_32._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x04\x01\x06\x01\x04\x02\x04\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x08\x01\x02\x05\x04\xfc\x06\x01\x04\x02\x04\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x08\x12\x13\x14\x16\x1b\x08\x1c\x05\x15\x0f\x13\x09\x0c\x12\x16\x09\x0f\x09\x0f\x0f\x12\x09\x0c\x12\x15\x09\x0f\x0c\x17\x0c\x21\x22\x23\x25\x28\x2a\x2e\x30\x36\x0c\x37\x05\x37",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_16_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 117,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_5._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x7c\x00\x64\x01\x64\x02\x85\x02\x19\x00\x7c\x00\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[75];
    }
toplevel_consts_17_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 74,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x70\x6c\x69\x74\x20\x61\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x69\x6e\x74\x6f\x20\x64\x72\x69\x76\x65\x20\x61\x6e\x64\x20\x70\x61\x74\x68\x2e\x20\x4f\x6e\x20\x50\x6f\x73\x69\x78\x2c\x20\x64\x72\x69\x76\x65\x20\x69\x73\x20\x61\x6c\x77\x61\x79\x73\x0a\x20\x20\x20\x20\x65\x6d\x70\x74\x79\x2e",
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
            Py_None,
            & toplevel_consts_8.ob_base.ob_base,
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
toplevel_consts_17_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_17_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0c\x0d\x0e\x10\x0f\x10\x0e\x10\x0c\x11\x13\x14\x0c\x14\x05\x14",
};
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 131,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x7c\x00\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x64\x01\x7a\x00\x7d\x02\x7c\x00\x7c\x02\x64\x02\x85\x02\x19\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_18_consts_0 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_18_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
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
toplevel_consts_18_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_15_names_3._ascii.ob_base,
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
toplevel_consts_18_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
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
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x10\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0b\x13\x14\x15\x0b\x16\x05\x08\x09\x0a\x09\x15\x11\x14\x09\x15\x09\x15\x18\x19\x09\x19\x05\x06\x0c\x0d\x0e\x0f\x0e\x10\x0e\x10\x0c\x11\x05\x11",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 140,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\xa9\x01\x7d\x01\x7c\x00\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x64\x01\x7a\x00\x7d\x02\x7c\x00\x64\x02\x7c\x02\x85\x02\x19\x00\x7d\x03\x7c\x03\x72\x28\x7c\x03\x7c\x01\x74\x04\x7c\x03\xa9\x01\x7a\x05\x6b\x03\x72\x28\x7c\x03\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x7d\x03\x7c\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[46];
    }
toplevel_consts_19_consts_0 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_19_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_19_consts_0._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
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
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x10\x01\x0c\x01\x14\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x10\x01\x0c\x01\x02\x01\x02\x01\x0e\xff\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x09\x12\x13\x14\x09\x15\x05\x06\x0b\x13\x14\x15\x0b\x16\x05\x08\x09\x0a\x09\x15\x11\x14\x09\x15\x09\x15\x18\x19\x09\x19\x05\x06\x0c\x0d\x0e\x10\x0f\x10\x0e\x10\x0c\x11\x05\x09\x08\x0c\x05\x20\x11\x15\x19\x1c\x1d\x20\x21\x25\x1d\x26\x19\x26\x11\x26\x05\x20\x10\x14\x10\x20\x1c\x1f\x10\x20\x10\x20\x09\x0d\x0c\x10\x05\x10",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_19_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 150,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_7._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_20_code = {
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
        uint8_t _data[39];
    }
toplevel_consts_20_consts_0 = {
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
    ._data = "Test whether a path is a symbolic link",
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
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_20_names_1 = {
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
toplevel_consts_20_names_2 = {
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
toplevel_consts_20_names_3 = {
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
toplevel_consts_20_names_5 = {
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
toplevel_consts_20_names_6 = {
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
toplevel_consts_20_names_7 = {
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
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_20_names_2._ascii.ob_base,
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_20_names_5._ascii.ob_base,
            & toplevel_consts_20_names_6._ascii.ob_base,
            & toplevel_consts_20_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_20_varnames_1 = {
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
toplevel_consts_20_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_20_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0c\x01\x02\x80\x0c\x01\x06\x01\x02\xff\x06\x80\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_20_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x0c\xfe\x02\x80\x08\x01\x0c\x01\x06\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_20_columntable = {
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
toplevel_consts_20_exceptiontable = {
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
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_20_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 164,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_13._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_13._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_21_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x01\x00\x64\x02\x53\x00\x23\x00\x74\x02\x74\x03\x66\x02\x79\x12\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_21_consts_0 = {
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
toplevel_consts_21_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_20_names_2._ascii.ob_base,
            & toplevel_consts_20_names_3._ascii.ob_base,
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
    .ob_sval = "\x02\x00\x02\x02\x0a\x01\x04\x03\x02\x80\x0a\xfe\x06\x01\x02\xff\x06\x80",
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
    .ob_sval = "\x02\x00\x02\x05\x0a\xfe\x04\x03\x02\x80\x06\xfe\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_21_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x09\x0b\x09\x11\x12\x16\x09\x17\x09\x17\x0c\x10\x0c\x10\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00",
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
    .ob_sval = "\x82\x05\x09\x00\x89\x06\x13\x03\x92\x01\x13\x03",
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
    .co_stacksize = 4,
    .co_firstlineno = 174,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_15._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_15._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[191];
    }
toplevel_consts_22_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 190,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x01\x6e\x0d\x23\x00\x74\x02\x74\x03\x66\x02\x79\x11\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x04\x6a\x05\x7c\x01\x6a\x06\xa9\x01\x72\x1d\x64\x01\x53\x00\x74\x07\x7c\x00\x74\x08\xa9\x02\x72\x28\x74\x09\x7c\x00\x64\x02\xa9\x02\x7d\x02\x6e\x05\x74\x09\x7c\x00\x64\x03\xa9\x02\x7d\x02\x74\x0a\x7c\x02\xa9\x01\x7d\x02\x09\x00\x74\x00\x6a\x01\x7c\x02\xa9\x01\x7d\x03\x6e\x0d\x23\x00\x74\x02\x74\x03\x66\x02\x79\x41\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x6a\x0b\x7d\x04\x7c\x03\x6a\x0b\x7d\x05\x7c\x04\x7c\x05\x6b\x03\x72\x51\x64\x04\x53\x00\x7c\x01\x6a\x0c\x7d\x06\x7c\x03\x6a\x0c\x7d\x07\x7c\x06\x7c\x07\x6b\x02\x72\x5d\x64\x04\x53\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[37];
    }
toplevel_consts_22_consts_0 = {
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
    ._data = "Test whether a path is a mount point",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_22_consts_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_22_consts_0._ascii.ob_base,
            Py_False,
            & toplevel_consts_22_consts_2.ob_base.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            Py_True,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_22_names_11 = {
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
    ._data = "st_dev",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_22_names_12 = {
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
    ._data = "st_ino",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_20_names_2._ascii.ob_base,
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_20_names_5._ascii.ob_base,
            & toplevel_consts_20_names_6._ascii.ob_base,
            & toplevel_consts_20_names_7._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_10_34._ascii.ob_base,
            & toplevel_consts_22_names_11._ascii.ob_base,
            & toplevel_consts_22_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_22_varnames_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_22_varnames_2 = {
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
    ._data = "parent",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_22_varnames_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_varnames_4 = {
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
    ._data = "dev1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_varnames_5 = {
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
    ._data = "dev2",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_varnames_6 = {
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
    ._data = "ino1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_varnames_7 = {
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
    ._data = "ino2",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_22_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_22_varnames_2._ascii.ob_base,
            & toplevel_consts_22_varnames_3._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_22_varnames_5._ascii.ob_base,
            & toplevel_consts_22_varnames_6._ascii.ob_base,
            & toplevel_consts_22_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0c\x01\x02\x80\x0a\x01\x06\x02\x02\xfe\x06\x80\x0c\x05\x04\x01\x0a\x02\x0c\x01\x0a\x02\x08\x01\x02\x01\x0c\x01\x02\x80\x0a\x01\x06\x01\x02\xff\x06\x80\x06\x03\x06\x01\x08\x01\x04\x01\x06\x01\x06\x01\x08\x01\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0a\x0c\xf9\x02\x80\x06\x01\x0c\x02\x06\x80\x0a\x03\x06\x01\x08\x02\x02\x03\x0c\xfe\x0a\x02\x08\x01\x02\x04\x0c\xfe\x02\x80\x06\x01\x0c\x01\x06\x80\x06\x02\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[191];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 190,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x19\x0e\x10\x0e\x16\x17\x1b\x0e\x1c\x09\x0b\x09\x0b\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00\x0c\x10\x0c\x18\x19\x1b\x19\x23\x0c\x24\x09\x19\x14\x19\x14\x19\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x22\x12\x16\x17\x1b\x1d\x22\x12\x23\x09\x0f\x09\x0f\x12\x16\x17\x1b\x1d\x21\x12\x22\x09\x0f\x0e\x16\x17\x1d\x0e\x1e\x05\x0b\x05\x15\x0e\x10\x0e\x16\x17\x1d\x0e\x1e\x09\x0b\x09\x0b\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00\x0c\x0e\x0c\x15\x05\x09\x0c\x0e\x0c\x15\x05\x09\x08\x0c\x10\x14\x08\x14\x05\x14\x10\x14\x10\x14\x0c\x0e\x0c\x15\x05\x09\x0c\x0e\x0c\x15\x05\x09\x08\x0c\x10\x14\x08\x14\x05\x14\x10\x14\x10\x14\x0c\x11\x0c\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[28];
    }
toplevel_consts_22_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 27,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x05\x08\x00\x88\x06\x12\x03\x91\x01\x12\x03\xb2\x05\x38\x00\xb8\x06\x41\x02\x03\xc1\x01\x01\x41\x02\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_22_localspluskinds = {
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
    .co_firstlineno = 186,
    .co_code = & toplevel_consts_22_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_18._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_18._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[337];
    }
toplevel_consts_23_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 336,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x0e\x64\x01\x7d\x01\x6e\x02\x64\x02\x7d\x01\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x73\x18\x7c\x00\x53\x00\x74\x05\x7c\x00\xa9\x01\x7d\x02\x7c\x00\xa0\x06\x7c\x02\x64\x03\xa8\x02\xa9\x02\x7d\x03\x7c\x03\x64\x04\x6b\x00\x72\x2b\x74\x07\x7c\x00\xa9\x01\x7d\x03\x7c\x03\x64\x03\x6b\x02\x72\x55\x64\x05\x74\x00\x6a\x08\x76\x01\x72\x4f\x64\x04\x64\x06\x6c\x09\x7d\x04\x09\x00\x7c\x04\xa0\x0a\x74\x00\x6a\x0b\xa9\x00\xa8\x01\xa9\x01\x6a\x0c\x7d\x05\x6e\x3d\x23\x00\x74\x0d\x79\x4b\x01\x00\x7c\x00\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x00\x6a\x08\x64\x05\x19\x00\x7d\x05\x6e\x2b\x64\x04\x64\x06\x6c\x09\x7d\x04\x7c\x00\x64\x03\x7c\x03\x85\x02\x19\x00\x7d\x06\x74\x02\x7c\x06\x74\x03\xa9\x02\x72\x69\x74\x0e\x7c\x06\x64\x07\xa9\x02\x7d\x06\x09\x00\x7c\x04\xa0\x0f\x7c\x06\xa8\x01\xa9\x01\x7d\x07\x6e\x0c\x23\x00\x74\x0d\x79\x79\x01\x00\x7c\x00\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x07\x6a\x0c\x7d\x05\x7c\x05\x80\x89\x74\x10\x6a\x11\x64\x08\x6b\x02\x72\x89\x7c\x00\x53\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x96\x74\x00\x6a\x12\x7c\x05\xa9\x01\x7d\x05\x64\x09\x7d\x08\x6e\x02\x64\x0a\x7d\x08\x7c\x05\xa0\x13\x7c\x08\xa8\x01\xa9\x01\x7d\x05\x7c\x05\x7c\x00\x7c\x03\x64\x06\x85\x02\x19\x00\x7a\x00\x70\xa7\x7c\x08\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[80];
    }
toplevel_consts_23_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 79,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x78\x70\x61\x6e\x64\x20\x7e\x20\x61\x6e\x64\x20\x7e\x75\x73\x65\x72\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x69\x6f\x6e\x73\x2e\x20\x20\x49\x66\x20\x75\x73\x65\x72\x20\x6f\x72\x20\x24\x48\x4f\x4d\x45\x20\x69\x73\x20\x75\x6e\x6b\x6e\x6f\x77\x6e\x2c\x0a\x20\x20\x20\x20\x64\x6f\x20\x6e\x6f\x74\x68\x69\x6e\x67\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_23_consts_1 = {
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
toplevel_consts_23_consts_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_23_consts_5 = {
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
    ._data = "HOME",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23_consts_7 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_23_consts_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_23_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_23_consts_1.ob_base.ob_base,
            & toplevel_consts_23_consts_2._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_23_consts_5._ascii.ob_base,
            Py_None,
            & toplevel_consts_23_consts_7._ascii.ob_base,
            & toplevel_consts_23_consts_8._ascii.ob_base,
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_23_names_6 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_23_names_8 = {
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
toplevel_consts_23_names_9 = {
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
    ._data = "pwd",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_23_names_10 = {
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
    ._data = "getpwuid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_names_11 = {
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
        uint8_t _data[7];
    }
toplevel_consts_23_names_12 = {
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
    ._data = "pw_dir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_23_names_13 = {
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
        uint8_t _data[4];
    }
toplevel_consts_23_names_14 = {
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
        uint8_t _data[9];
    }
toplevel_consts_23_names_15 = {
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
    ._data = "getpwnam",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_23_names_16 = {
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
        uint8_t _data[9];
    }
toplevel_consts_23_names_17 = {
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
        uint8_t _data[9];
    }
toplevel_consts_23_names_18 = {
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
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_23_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_23_names_6._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_23_names_8._ascii.ob_base,
            & toplevel_consts_23_names_9._ascii.ob_base,
            & toplevel_consts_23_names_10._ascii.ob_base,
            & toplevel_consts_23_names_11._ascii.ob_base,
            & toplevel_consts_23_names_12._ascii.ob_base,
            & toplevel_consts_23_names_13._ascii.ob_base,
            & toplevel_consts_23_names_14._ascii.ob_base,
            & toplevel_consts_23_names_15._ascii.ob_base,
            & toplevel_consts_23_names_16._ascii.ob_base,
            & toplevel_consts_23_names_17._ascii.ob_base,
            & toplevel_consts_23_names_18._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23_varnames_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_23_varnames_5 = {
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
        uint8_t _data[5];
    }
toplevel_consts_23_varnames_6 = {
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
toplevel_consts_23_varnames_7 = {
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
    ._data = "pwent",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_23_varnames_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_23_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_23_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_23_names_9._ascii.ob_base,
            & toplevel_consts_23_varnames_5._ascii.ob_base,
            & toplevel_consts_23_varnames_6._ascii.ob_base,
            & toplevel_consts_23_varnames_7._ascii.ob_base,
            & toplevel_consts_23_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_23_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x0a\x01\x06\x01\x04\x02\x0c\x01\x04\x01\x08\x01\x0e\x01\x08\x01\x08\x01\x08\x01\x0a\x01\x08\x01\x02\x01\x14\x01\x02\x80\x06\x01\x08\x03\x02\xfd\x06\x80\x0c\x05\x08\x02\x0c\x01\x0a\x01\x0a\x01\x02\x01\x0e\x01\x02\x80\x06\x01\x08\x03\x02\xfd\x06\x80\x06\x04\x0e\x02\x04\x01\x0a\x01\x0a\x01\x06\x01\x04\x02\x0c\x01\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_23_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x01\x02\x03\x06\xfe\x04\x02\x0a\x01\x06\x01\x08\x01\x0e\x01\x06\x01\x0a\x01\x06\x01\x02\x16\x08\xeb\x02\x09\x08\xf8\x02\x06\x14\xfc\x02\x80\x02\x01\x0e\x03\x06\x80\x0c\x02\x08\x02\x0c\x01\x08\x01\x0c\x01\x02\x06\x0e\xfc\x02\x80\x02\x01\x0e\x03\x06\x80\x06\x01\x02\x02\x02\x01\x08\xff\x06\x01\x08\x01\x02\x04\x0a\xfd\x06\x01\x04\x02\x0c\x01\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[337];
    }
toplevel_consts_23_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 336,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x14\x11\x15\x09\x0e\x09\x0e\x11\x14\x09\x0e\x0c\x10\x0c\x22\x1c\x21\x0c\x22\x0c\x22\x05\x14\x10\x14\x09\x14\x0b\x13\x14\x18\x0b\x19\x05\x08\x09\x0d\x09\x1a\x13\x16\x18\x19\x09\x1a\x09\x1a\x05\x06\x08\x09\x0c\x0d\x08\x0d\x05\x16\x0d\x10\x11\x15\x0d\x16\x09\x0a\x08\x09\x0d\x0e\x08\x0e\x05\x20\x0c\x12\x1a\x1c\x1a\x24\x0c\x24\x09\x2a\x0d\x17\x0d\x17\x0d\x17\x0d\x17\x0d\x1c\x1c\x1f\x1c\x35\x29\x2b\x29\x32\x29\x34\x1c\x35\x1c\x35\x1c\x3c\x11\x19\x11\x19\x00\x00\x14\x1c\x0d\x1c\x0d\x1c\x18\x1c\x11\x1c\x11\x1c\x11\x1c\x0d\x1c\x00\x00\x00\x00\x00\x00\x18\x1a\x18\x22\x23\x29\x18\x2a\x0d\x15\x0d\x15\x09\x13\x09\x13\x09\x13\x09\x13\x10\x14\x15\x16\x17\x18\x15\x18\x10\x19\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x26\x14\x17\x18\x1c\x1e\x25\x14\x26\x0d\x11\x09\x18\x15\x18\x15\x27\x22\x26\x15\x27\x15\x27\x0d\x12\x0d\x12\x00\x00\x10\x18\x09\x18\x09\x18\x14\x18\x0d\x18\x0d\x18\x0d\x18\x09\x18\x00\x00\x00\x00\x00\x00\x14\x19\x14\x20\x09\x11\x08\x10\x05\x14\x1d\x20\x1d\x29\x2d\x36\x1d\x36\x05\x14\x10\x14\x09\x14\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x13\x14\x16\x14\x1f\x20\x28\x14\x29\x09\x11\x10\x14\x09\x0d\x09\x0d\x10\x13\x09\x0d\x10\x18\x10\x25\x20\x24\x10\x25\x10\x25\x05\x0d\x0d\x15\x18\x1c\x1d\x1e\x1d\x1f\x1d\x1f\x18\x20\x0d\x20\x0c\x29\x25\x29\x05\x29",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[36];
    }
toplevel_consts_23_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 35,
    },
    .ob_shash = -1,
    .ob_sval = "\xb9\x09\x41\x03\x00\xc1\x03\x06\x41\x0c\x03\xc1\x0b\x01\x41\x0c\x03\xc1\x2a\x06\x41\x31\x00\xc1\x31\x06\x41\x3a\x03\xc1\x39\x01\x41\x3a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_23_localspluskinds = {
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
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 228,
    .co_code = & toplevel_consts_23_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_19._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_19._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[351];
    }
toplevel_consts_24_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 350,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x2d\x64\x01\x7c\x00\x76\x01\x72\x11\x7c\x00\x53\x00\x74\x04\x73\x1f\x64\x02\x64\x03\x6c\x05\x7d\x01\x7c\x01\xa0\x06\x64\x04\x7c\x01\x6a\x07\xa8\x02\xa9\x02\x61\x04\x74\x04\x6a\x08\x7d\x02\x64\x05\x7d\x03\x64\x06\x7d\x04\x74\x09\x74\x00\x64\x07\x64\x03\xa9\x03\x7d\x05\x6e\x1e\x64\x08\x7c\x00\x76\x01\x72\x33\x7c\x00\x53\x00\x74\x0a\x73\x41\x64\x02\x64\x03\x6c\x05\x7d\x01\x7c\x01\xa0\x06\x64\x09\x7c\x01\x6a\x07\xa8\x02\xa9\x02\x61\x0a\x74\x0a\x6a\x08\x7d\x02\x64\x0a\x7d\x03\x64\x0b\x7d\x04\x74\x00\x6a\x0b\x7d\x05\x64\x02\x7d\x06\x09\x00\x7c\x02\x7c\x00\x7c\x06\xa9\x02\x7d\x07\x7c\x07\x73\x58\x09\x00\x7c\x00\x53\x00\x7c\x07\xa0\x0c\x64\x02\xa8\x01\xa9\x01\x5c\x02\x7d\x06\x7d\x08\x7c\x07\xa0\x0d\x64\x0d\xa8\x01\xa9\x01\x7d\x09\x7c\x09\xa0\x0e\x7c\x03\xa8\x01\xa9\x01\x72\x78\x7c\x09\xa0\x0f\x7c\x04\xa8\x01\xa9\x01\x72\x78\x7c\x09\x64\x0d\x64\x0e\x85\x02\x19\x00\x7d\x09\x09\x00\x7c\x05\x80\x87\x74\x00\x6a\x10\x74\x00\x6a\x0b\x74\x00\x6a\x11\x7c\x09\xa9\x01\x19\x00\xa9\x01\x7d\x0a\x6e\x04\x7c\x05\x7c\x09\x19\x00\x7d\x0a\x6e\x0c\x23\x00\x74\x12\x79\x94\x01\x00\x7c\x08\x7d\x06\x59\x00\x6e\x1a\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x7c\x08\x64\x03\x85\x02\x19\x00\x7d\x0b\x7c\x00\x64\x03\x7c\x06\x85\x02\x19\x00\x7c\x0a\x7a\x00\x7d\x00\x74\x13\x7c\x00\xa9\x01\x7d\x06\x7c\x00\x7c\x0b\x7a\x0d\x7d\x00\x71\x4e",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[91];
    }
toplevel_consts_24_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 90,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x78\x70\x61\x6e\x64\x20\x73\x68\x65\x6c\x6c\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73\x20\x6f\x66\x20\x66\x6f\x72\x6d\x20\x24\x76\x61\x72\x20\x61\x6e\x64\x20\x24\x7b\x76\x61\x72\x7d\x2e\x20\x20\x55\x6e\x6b\x6e\x6f\x77\x6e\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73\x0a\x20\x20\x20\x20\x61\x72\x65\x20\x6c\x65\x66\x74\x20\x75\x6e\x63\x68\x61\x6e\x67\x65\x64\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_24_consts_1 = {
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
        char ob_sval[18];
    }
toplevel_consts_24_consts_4 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 17,
    },
    .ob_shash = -1,
    .ob_sval = "\\$(\\w+|\\{[^}]*\\})",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_24_consts_5 = {
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
toplevel_consts_24_consts_6 = {
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
toplevel_consts_24_consts_7 = {
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
toplevel_consts_24_consts_8 = {
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
        uint8_t _data[18];
    }
toplevel_consts_24_consts_9 = {
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
    ._data = "\\$(\\w+|\\{[^}]*\\})",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_24_consts_10 = {
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
toplevel_consts_24_consts_11 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_24_consts_14 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_24_consts_1.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            Py_None,
            & toplevel_consts_24_consts_4.ob_base.ob_base,
            & toplevel_consts_24_consts_5.ob_base.ob_base,
            & toplevel_consts_24_consts_6.ob_base.ob_base,
            & toplevel_consts_24_consts_7._ascii.ob_base,
            & toplevel_consts_24_consts_8._ascii.ob_base,
            & toplevel_consts_24_consts_9._ascii.ob_base,
            & toplevel_consts_24_consts_10._ascii.ob_base,
            & toplevel_consts_24_consts_11._ascii.ob_base,
            Py_True,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
            & toplevel_consts_24_consts_14.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_24_names_4 = {
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
    ._data = "_varprogb",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_24_names_5 = {
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
    ._data = "re",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_24_names_6 = {
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
    ._data = "compile",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_names_8 = {
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
    ._data = "search",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_24_names_9 = {
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
        uint8_t _data[9];
    }
toplevel_consts_24_names_10 = {
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
    ._data = "_varprog",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_names_12 = {
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
    ._data = "span",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_names_13 = {
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
    ._data = "group",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_24_names_17 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 20,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_24_names_4._ascii.ob_base,
            & toplevel_consts_24_names_5._ascii.ob_base,
            & toplevel_consts_24_names_6._ascii.ob_base,
            & toplevel_consts_23_consts_7._ascii.ob_base,
            & toplevel_consts_24_names_8._ascii.ob_base,
            & toplevel_consts_24_names_9._ascii.ob_base,
            & toplevel_consts_24_names_10._ascii.ob_base,
            & toplevel_consts_23_names_8._ascii.ob_base,
            & toplevel_consts_24_names_12._ascii.ob_base,
            & toplevel_consts_24_names_13._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_23_names_18._ascii.ob_base,
            & toplevel_consts_24_names_17._ascii.ob_base,
            & toplevel_consts_23_names_13._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_varnames_3 = {
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
        uint8_t _data[4];
    }
toplevel_consts_24_varnames_4 = {
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
    ._data = "end",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_24_varnames_7 = {
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
        uint8_t _data[2];
    }
toplevel_consts_24_varnames_8 = {
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
    ._data = "j",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_varnames_10 = {
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
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_24_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_24_names_5._ascii.ob_base,
            & toplevel_consts_24_names_8._ascii.ob_base,
            & toplevel_consts_24_varnames_3._ascii.ob_base,
            & toplevel_consts_24_varnames_4._ascii.ob_base,
            & toplevel_consts_23_names_8._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_24_varnames_7._ascii.ob_base,
            & toplevel_consts_24_varnames_8._ascii.ob_base,
            & toplevel_consts_23_varnames_6._ascii.ob_base,
            & toplevel_consts_24_varnames_10._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[91];
    }
toplevel_consts_24_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 90,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x0a\x02\x08\x01\x04\x01\x04\x01\x08\x01\x10\x01\x06\x01\x04\x01\x04\x01\x0e\x01\x08\x02\x04\x01\x04\x01\x08\x01\x10\x01\x06\x01\x04\x01\x04\x01\x06\x01\x04\x01\x02\x01\x0a\x01\x04\x01\x02\x01\x04\x11\x10\xf0\x0c\x01\x18\x01\x0c\x01\x02\x01\x04\x01\x18\x01\x08\x02\x04\x80\x06\x01\x08\x01\x02\xff\x06\x80\x0c\x03\x10\x01\x08\x01\x08\x01\x02\xed",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_24_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x08\x02\x02\x13\x06\xee\x06\x01\x02\x01\x02\x02\x08\xff\x10\x01\x06\x01\x04\x01\x04\x01\x0e\x01\x06\x02\x06\x01\x02\x01\x02\x02\x08\xff\x10\x01\x06\x01\x04\x01\x04\x01\x06\x01\x04\x01\x02\x01\x0a\x01\x02\x01\x04\x01\x04\x11\x10\xf0\x0c\x01\x0a\x01\x02\x01\x0a\xff\x0e\x01\x02\x0c\x02\xf6\x02\x03\x18\xfe\x08\x02\x04\x80\x02\x01\x0e\x01\x06\x80\x0c\x02\x10\x01\x08\x01\x08\x01\x02\xed",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[351];
    }
toplevel_consts_24_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 350,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x1d\x0c\x10\x18\x1c\x0c\x1c\x09\x18\x14\x18\x0d\x18\x10\x19\x09\x44\x0d\x16\x0d\x16\x0d\x16\x0d\x16\x19\x1b\x19\x44\x24\x39\x3b\x3d\x3b\x43\x19\x44\x19\x44\x0d\x16\x12\x1b\x12\x22\x09\x0f\x11\x15\x09\x0e\x0f\x13\x09\x0c\x13\x1a\x1b\x1d\x1f\x29\x2b\x2f\x13\x30\x09\x10\x09\x10\x0c\x0f\x17\x1b\x0c\x1b\x09\x18\x14\x18\x0d\x18\x10\x18\x09\x42\x0d\x16\x0d\x16\x0d\x16\x0d\x16\x18\x1a\x18\x42\x23\x37\x39\x3b\x39\x41\x18\x42\x18\x42\x0d\x15\x12\x1a\x12\x21\x09\x0f\x11\x14\x09\x0e\x0f\x12\x09\x0c\x13\x15\x13\x1d\x09\x10\x09\x0a\x05\x06\x0b\x0f\x0d\x13\x14\x18\x1a\x1b\x0d\x1c\x09\x0a\x10\x11\x09\x12\x0d\x12\x0c\x10\x05\x10\x10\x11\x10\x19\x17\x18\x10\x19\x10\x19\x09\x0d\x09\x0a\x0c\x0d\x10\x11\x10\x1a\x18\x19\x10\x1a\x10\x1a\x09\x0d\x0c\x10\x0c\x22\x1c\x21\x0c\x22\x0c\x22\x09\x1e\x27\x2b\x27\x39\x35\x38\x27\x39\x27\x39\x09\x1e\x14\x18\x19\x1a\x1b\x1d\x19\x1d\x14\x1e\x0d\x11\x09\x19\x10\x17\x0d\x26\x19\x1b\x19\x24\x25\x27\x25\x2f\x30\x32\x30\x3b\x3c\x40\x30\x41\x25\x42\x19\x43\x11\x16\x11\x16\x19\x20\x21\x25\x19\x26\x11\x16\x00\x00\x00\x00\x10\x18\x09\x12\x09\x12\x11\x12\x0d\x0e\x0d\x0e\x0d\x0e\x09\x12\x00\x00\x00\x00\x00\x00\x14\x18\x19\x1a\x19\x1b\x19\x1b\x14\x1c\x0d\x11\x14\x18\x19\x1b\x1a\x1b\x19\x1b\x14\x1c\x1f\x24\x14\x24\x0d\x11\x11\x14\x15\x19\x11\x1a\x0d\x0e\x0d\x11\x15\x19\x0d\x19\x0d\x11\x0b\x0f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_24_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x39\x12\x42\x0c\x00\xc2\x0c\x06\x42\x15\x03\xc2\x14\x01\x42\x15\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_24_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_24_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 284,
    .co_code = & toplevel_consts_24_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_24_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_20._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_20._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_columntable.ob_base.ob_base,
    .co_nlocalsplus = 12,
    .co_nlocals = 12,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_25_0 = {
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
toplevel_consts_25 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_25_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[261];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 260,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x72\x14\x64\x01\x7d\x01\x64\x02\x7d\x02\x64\x03\x7d\x03\x64\x04\x7d\x04\x6e\x08\x64\x05\x7d\x01\x64\x06\x7d\x02\x64\x07\x7d\x03\x64\x08\x7d\x04\x7c\x00\x7c\x02\x6b\x02\x72\x22\x7c\x03\x53\x00\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x7d\x05\x7c\x05\x72\x3c\x7c\x00\xa0\x04\x7c\x01\x64\x09\x7a\x05\xa8\x01\xa9\x01\x72\x3c\x7c\x00\xa0\x04\x7c\x01\x64\x0a\x7a\x05\xa8\x01\xa9\x01\x73\x3c\x64\x09\x7d\x05\x7c\x00\xa0\x05\x7c\x01\xa8\x01\xa9\x01\x7d\x06\x67\x00\x7d\x07\x7c\x06\x44\x00\x5d\x27\x7d\x08\x7c\x08\x7c\x02\x7c\x03\x66\x02\x76\x00\x72\x4f\x71\x46\x7c\x08\x7c\x04\x6b\x03\x73\x5f\x7c\x05\x73\x57\x7c\x07\x72\x5f\x7c\x07\x72\x66\x7c\x07\x64\x0b\x19\x00\x7c\x04\x6b\x02\x72\x66\x7c\x07\xa0\x06\x7c\x08\xa8\x01\xa9\x01\x01\x00\x71\x46\x7c\x07\x72\x6d\x7c\x07\xa0\x07\xa8\x00\xa9\x00\x01\x00\x71\x46\x7c\x07\x7d\x06\x7c\x01\xa0\x08\x7c\x06\xa8\x01\xa9\x01\x7d\x00\x7c\x05\x72\x7e\x7c\x01\x7c\x05\x7a\x05\x7c\x00\x7a\x00\x7d\x00\x7c\x00\x70\x81\x7c\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_26_consts_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_26_consts_6 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_9 = {
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
toplevel_consts_26_consts_10 = {
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
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_11_exceptiontable.ob_base.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
            & toplevel_consts_22_consts_2.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_26_consts_6._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            & toplevel_consts_26_consts_9.ob_base.ob_base,
            & toplevel_consts_26_consts_10.ob_base.ob_base,
            & toplevel_consts_24_consts_14.ob_base.ob_base,
        },
    },
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
    ._data = "append",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_names_7 = {
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
    ._data = "pop",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_10_4._ascii.ob_base,
            & toplevel_consts_26_names_6._ascii.ob_base,
            & toplevel_consts_26_names_7._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_varnames_2 = {
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
    ._data = "empty",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_varnames_3 = {
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
    ._data = "dot",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_varnames_4 = {
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
    ._data = "dotdot",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_26_varnames_5 = {
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
    ._data = "initial_slashes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_varnames_6 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_varnames_7 = {
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
    ._data = "new_comps",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_varnames_8 = {
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
    ._data = "comp",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_26_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_26_varnames_2._ascii.ob_base,
            & toplevel_consts_26_varnames_3._ascii.ob_base,
            & toplevel_consts_26_varnames_4._ascii.ob_base,
            & toplevel_consts_26_varnames_5._ascii.ob_base,
            & toplevel_consts_26_varnames_6._ascii.ob_base,
            & toplevel_consts_26_varnames_7._ascii.ob_base,
            & toplevel_consts_26_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0a\x01\x04\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x01\x08\x01\x04\x01\x0c\x01\x04\x04\x0e\x01\x02\xff\x0e\x01\x02\xff\x04\x02\x0c\x01\x04\x01\x08\x01\x0c\x01\x02\x01\x10\x01\x02\x01\x02\xff\x0a\x01\x02\xff\x0e\x02\x04\x01\x0a\x01\x02\x80\x04\x01\x0c\x01\x04\x01\x0c\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[95];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x02\x09\x04\xf8\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x01\x06\x01\x06\x01\x0c\x01\x02\x04\x02\x02\x0e\xff\x02\x01\x0e\xff\x06\x01\x0c\x01\x04\x01\x02\x01\x04\x07\x02\xf9\x0a\x01\x04\x01\x06\x01\x02\x04\x02\xfc\x02\x04\x02\xfc\x02\x04\x02\xfd\x02\x03\x0a\xfd\x02\x03\x0e\xfe\x02\x01\x0c\x01\x02\x80\x04\x01\x0c\x01\x02\x01\x0e\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[261];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 260,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x19\x1a\x1e\x10\x1f\x09\x0d\x0c\x16\x17\x1b\x1d\x22\x0c\x23\x09\x1a\x13\x17\x0d\x10\x15\x18\x0d\x12\x13\x17\x0d\x10\x16\x1b\x0d\x13\x0d\x13\x13\x16\x0d\x10\x15\x17\x0d\x12\x13\x16\x0d\x10\x16\x1a\x0d\x13\x0c\x10\x14\x19\x0c\x19\x09\x17\x14\x17\x0d\x17\x1b\x1f\x1b\x2f\x2b\x2e\x1b\x2f\x1b\x2f\x09\x18\x0d\x1c\x09\x20\x0d\x11\x0d\x23\x1d\x20\x21\x22\x1d\x22\x0d\x23\x0d\x23\x09\x20\x2c\x30\x2c\x42\x3c\x3f\x40\x41\x3c\x41\x2c\x42\x2c\x42\x09\x20\x1f\x20\x0d\x1c\x11\x15\x11\x20\x1c\x1f\x11\x20\x11\x20\x09\x0e\x15\x17\x09\x12\x15\x1a\x09\x20\x09\x20\x0d\x11\x10\x14\x19\x1e\x20\x23\x18\x24\x10\x24\x0d\x19\x11\x19\x11\x15\x19\x1f\x11\x1f\x0d\x20\x28\x37\x0d\x20\x40\x49\x0d\x20\x13\x1c\x0d\x20\x21\x2a\x2b\x2d\x21\x2e\x32\x38\x21\x38\x0d\x20\x11\x1a\x11\x27\x22\x26\x11\x27\x11\x27\x11\x27\x11\x27\x12\x1b\x0d\x20\x11\x1a\x11\x20\x11\x20\x11\x20\x11\x20\x00\x00\x11\x1a\x09\x0e\x10\x13\x10\x1f\x19\x1e\x10\x1f\x10\x1f\x09\x0d\x0c\x1b\x09\x2e\x14\x17\x18\x27\x14\x27\x2a\x2e\x14\x2e\x0d\x11\x10\x14\x10\x1b\x18\x1b\x09\x1b",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 341,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_27_code = {
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
toplevel_consts_27_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
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
toplevel_consts_27_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_23_names_18._ascii.ob_base,
            & toplevel_consts_25_0._ascii.ob_base,
            & toplevel_consts_24_names_17._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_27_linetable = {
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
toplevel_consts_27_endlinetable = {
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
toplevel_consts_27_columntable = {
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
static struct PyCodeObject toplevel_consts_27 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_27_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_27_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_27_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 380,
    .co_code = & toplevel_consts_27_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_27_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_27_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_28_code = {
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
        uint8_t _data[25];
    }
toplevel_consts_28_consts_0 = {
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
    ._data = "Return an absolute path.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_28_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_28_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_28_names_5 = {
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
toplevel_consts_28_names_6 = {
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
toplevel_consts_28_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_28_names_5._ascii.ob_base,
            & toplevel_consts_28_names_6._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_10_21._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_28_varnames_1 = {
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
toplevel_consts_28_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_28_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x0a\x01\x0a\x01\x08\x02\x0a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_28_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x06\x01\x02\x05\x08\xfc\x02\x03\x0a\xfe\x08\x02\x0a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_28_columntable = {
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
static struct PyCodeObject toplevel_consts_28 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 388,
    .co_code = & toplevel_consts_28_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_22._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_22._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_30_0 = {
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
toplevel_consts_30 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_30_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_31_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x00\x74\x02\x7c\x00\x64\x01\x64\x02\x85\x02\x19\x00\x7c\x00\x7c\x01\x69\x00\xa9\x04\x5c\x02\x7d\x02\x7d\x03\x74\x03\x7c\x02\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[109];
    }
toplevel_consts_31_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 108,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x63\x61\x6e\x6f\x6e\x69\x63\x61\x6c\x20\x70\x61\x74\x68\x20\x6f\x66\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x2c\x20\x65\x6c\x69\x6d\x69\x6e\x61\x74\x69\x6e\x67\x20\x61\x6e\x79\x0a\x73\x79\x6d\x62\x6f\x6c\x69\x63\x20\x6c\x69\x6e\x6b\x73\x20\x65\x6e\x63\x6f\x75\x6e\x74\x65\x72\x65\x64\x20\x69\x6e\x20\x74\x68\x65\x20\x70\x61\x74\x68\x2e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_31_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_31_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_8.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_31_names_2 = {
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
    ._data = "_joinrealpath",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_31_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_31_names_2._ascii.ob_base,
            & toplevel_consts_10_22._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_31_varnames_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_31_varnames_3 = {
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
    ._data = "ok",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_31_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_31_varnames_0._ascii.ob_base,
            & toplevel_consts_30_0._ascii.ob_base,
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_31_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_31_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x1a\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_31_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x12\x10\x19\x1a\x22\x10\x23\x05\x0d\x10\x1d\x1e\x26\x27\x29\x28\x29\x27\x29\x1e\x2a\x2c\x34\x36\x3c\x3e\x40\x10\x41\x05\x0d\x05\x09\x0b\x0d\x0c\x13\x14\x18\x0c\x19\x05\x19",
};
static struct PyCodeObject toplevel_consts_31 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_31_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_31_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_31_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 5,
    .co_firstlineno = 403,
    .co_code = & toplevel_consts_31_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_34._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_34._ascii.ob_base,
    .co_linetable = & toplevel_consts_31_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_31_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_31_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[349];
    }
toplevel_consts_32_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 348,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x72\x0d\x64\x01\x7d\x04\x64\x02\x7d\x05\x64\x03\x7d\x06\x6e\x06\x64\x04\x7d\x04\x64\x05\x7d\x05\x64\x06\x7d\x06\x74\x02\x7c\x01\xa9\x01\x72\x1f\x7c\x01\x64\x07\x64\x00\x85\x02\x19\x00\x7d\x01\x7c\x04\x7d\x00\x7c\x01\x72\xaa\x7c\x01\xa0\x03\x7c\x04\xa8\x01\xa9\x01\x5c\x03\x7d\x07\x7d\x08\x7d\x01\x7c\x07\x72\x30\x7c\x07\x7c\x05\x6b\x02\x72\x31\x71\x1f\x7c\x07\x7c\x06\x6b\x02\x72\x4b\x7c\x00\x72\x48\x74\x04\x7c\x00\xa9\x01\x5c\x02\x7d\x00\x7d\x07\x7c\x07\x7c\x06\x6b\x02\x72\x47\x74\x05\x7c\x00\x7c\x06\x7c\x06\xa9\x03\x7d\x00\x6e\x02\x7c\x06\x7d\x00\x71\x1f\x74\x05\x7c\x00\x7c\x07\xa9\x02\x7d\x09\x09\x00\x74\x06\x6a\x07\x7c\x09\xa9\x01\x7d\x0a\x6e\x0f\x23\x00\x74\x08\x79\x62\x01\x00\x7c\x02\x72\x5e\x82\x00\x64\x08\x7d\x0b\x59\x00\x6e\x0a\x77\x00\x78\x03\x59\x00\x77\x01\x74\x09\x6a\x0a\x7c\x0a\x6a\x0b\xa9\x01\x7d\x0b\x7c\x0b\x73\x71\x7c\x09\x7d\x00\x71\x1f\x7c\x09\x7c\x03\x76\x00\x72\x8b\x7c\x03\x7c\x09\x19\x00\x7d\x00\x7c\x00\x81\x7c\x71\x1f\x7c\x02\x72\x84\x74\x06\x6a\x09\x7c\x09\xa9\x01\x01\x00\x6e\x07\x74\x05\x7c\x09\x7c\x01\xa9\x02\x64\x08\x66\x02\x53\x00\x64\x00\x7c\x03\x7c\x09\x3c\x00\x74\x0c\x7c\x00\x74\x06\x6a\x0d\x7c\x09\xa9\x01\x7c\x02\x7c\x03\xa9\x04\x5c\x02\x7d\x00\x7d\x0c\x7c\x0c\x73\xa4\x74\x05\x7c\x00\x7c\x01\xa9\x02\x64\x08\x66\x02\x53\x00\x7c\x00\x7c\x03\x7c\x09\x3c\x00\x7c\x01\x73\x21\x7c\x00\x64\x09\x66\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_32_consts = {
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
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
            & toplevel_consts_22_consts_2.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
            Py_False,
            Py_True,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_32_names_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_32_names_13 = {
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
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_32_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_32_names_3._ascii.ob_base,
            & toplevel_consts_10_4._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_20_names_2._ascii.ob_base,
            & toplevel_consts_20_names_5._ascii.ob_base,
            & toplevel_consts_20_names_6._ascii.ob_base,
            & toplevel_consts_20_names_7._ascii.ob_base,
            & toplevel_consts_31_names_2._ascii.ob_base,
            & toplevel_consts_32_names_13._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_32_varnames_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_32_varnames_3 = {
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
        uint8_t _data[2];
    }
toplevel_consts_32_varnames_8 = {
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
        uint8_t _data[8];
    }
toplevel_consts_32_varnames_9 = {
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
    ._data = "newpath",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_32_varnames_11 = {
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
    ._data = "is_link",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_32_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_32_varnames_1._ascii.ob_base,
            & toplevel_consts_30_0._ascii.ob_base,
            & toplevel_consts_32_varnames_3._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_27._ascii.ob_base,
            & toplevel_consts_23_varnames_6._ascii.ob_base,
            & toplevel_consts_32_varnames_8._ascii.ob_base,
            & toplevel_consts_32_varnames_9._ascii.ob_base,
            & toplevel_consts_20_varnames_1._ascii.ob_base,
            & toplevel_consts_32_varnames_11._ascii.ob_base,
            & toplevel_consts_31_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[103];
    }
toplevel_consts_32_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 102,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x08\x02\x0c\x01\x04\x01\x04\x02\x12\x01\x0c\x01\x02\x02\x08\x01\x04\x02\x0c\x01\x08\x01\x0c\x01\x02\x80\x04\x02\x02\x01\x0a\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x04\x01\x02\x01\x08\x01\x02\xfd\x06\x80\x0c\x05\x04\x01\x04\x01\x02\x01\x08\x02\x08\x02\x04\x01\x02\x02\x04\x02\x0c\x02\x0e\x03\x08\x01\x18\x01\x04\x01\x0e\x01\x08\x01\x04\xd4\x08\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[125];
    }
toplevel_consts_32_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 124,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x06\x02\x02\x02\x0c\xff\x04\x01\x02\x02\x02\x2c\x12\xd5\x02\x01\x02\x02\x06\xfe\x04\x02\x06\x01\x02\x08\x02\xfa\x02\x05\x0c\xfc\x06\x01\x0e\x01\x02\x80\x04\x02\x02\x01\x0a\x01\x02\x08\x0c\xfa\x02\x80\x02\x01\x04\x03\x02\xfe\x04\x01\x0a\x01\x06\x80\x0c\x02\x02\x01\x02\x02\x04\xff\x02\x01\x06\x02\x02\x0c\x08\xf6\x02\x01\x04\x02\x02\x02\x02\x05\x0c\xfd\x0e\x03\x08\x01\x18\x01\x02\x01\x10\x01\x08\x01\x02\xd4\x02\x2c\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[349];
    }
toplevel_consts_32_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 348,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x16\x0f\x13\x09\x0c\x12\x16\x09\x0f\x12\x17\x09\x0f\x09\x0f\x0f\x12\x09\x0c\x12\x15\x09\x0f\x12\x16\x09\x0f\x08\x0d\x0e\x12\x08\x13\x05\x13\x10\x14\x15\x16\x15\x17\x15\x17\x10\x18\x09\x0d\x10\x13\x09\x0d\x0b\x0f\x05\x1d\x19\x1d\x19\x2c\x28\x2b\x19\x2c\x19\x2c\x09\x16\x09\x0d\x0f\x10\x12\x16\x10\x14\x09\x15\x18\x1c\x20\x26\x18\x26\x09\x15\x0d\x15\x0c\x10\x14\x1a\x0c\x1a\x09\x15\x10\x14\x0d\x1e\x1e\x23\x24\x28\x1e\x29\x11\x1b\x11\x15\x17\x1b\x14\x18\x1c\x22\x14\x22\x11\x36\x1c\x20\x21\x25\x27\x2d\x2f\x35\x1c\x36\x15\x19\x00\x00\x18\x1e\x11\x15\x0d\x15\x13\x17\x18\x1c\x1e\x22\x13\x23\x09\x10\x09\x2f\x12\x14\x12\x1a\x1b\x22\x12\x23\x0d\x0f\x0d\x0f\x00\x00\x10\x17\x09\x1c\x09\x1c\x10\x16\x0d\x16\x11\x16\x17\x1c\x0d\x14\x0d\x14\x0d\x14\x09\x1c\x00\x00\x00\x00\x00\x00\x17\x1b\x17\x23\x24\x26\x24\x2e\x17\x2f\x0d\x14\x10\x17\x09\x15\x14\x1b\x0d\x11\x0d\x15\x0c\x13\x17\x1b\x0c\x1b\x09\x32\x14\x18\x19\x20\x14\x21\x0d\x11\x10\x14\x0d\x19\x11\x19\x10\x16\x0d\x32\x11\x13\x11\x18\x19\x20\x11\x21\x11\x21\x11\x21\x18\x1c\x1d\x24\x26\x2a\x18\x2b\x2d\x32\x18\x32\x11\x32\x19\x1d\x09\x0d\x0e\x15\x09\x16\x14\x21\x22\x26\x28\x2a\x28\x33\x34\x3b\x28\x3c\x3e\x44\x46\x4a\x14\x4b\x09\x11\x09\x0d\x0f\x11\x10\x12\x09\x2b\x14\x18\x19\x1d\x1f\x23\x14\x24\x26\x2b\x14\x2b\x0d\x2b\x19\x1d\x09\x0d\x0e\x15\x09\x16\x0b\x0f\x05\x1d\x0c\x10\x12\x16\x0c\x16\x05\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_32_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x11\x05\x41\x17\x00\xc1\x17\x09\x41\x23\x03\xc1\x22\x01\x41\x23\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[14];
    }
toplevel_consts_32_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 13,
    },
    .ob_shash = -1,
    .ob_sval = "             ",
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
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 412,
    .co_code = & toplevel_consts_32_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_32_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_32_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_names_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_31_names_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_32_columntable.ob_base.ob_base,
    .co_nlocalsplus = 13,
    .co_nlocals = 13,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_32_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_33 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_34_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x73\x07\x74\x00\x64\x01\xa9\x01\x82\x01\x74\x01\x6a\x02\x7c\x00\xa9\x01\x7d\x00\x74\x03\x7c\x00\x74\x04\xa9\x02\x72\x18\x64\x02\x7d\x02\x64\x03\x7d\x03\x64\x04\x7d\x04\x6e\x06\x64\x05\x7d\x02\x64\x06\x7d\x03\x64\x07\x7d\x04\x7c\x01\x80\x23\x7c\x02\x7d\x01\x6e\x05\x74\x01\x6a\x02\x7c\x01\xa9\x01\x7d\x01\x09\x00\x64\x09\x84\x00\x74\x05\x7c\x01\xa9\x01\xa0\x06\x7c\x03\xa8\x01\xa9\x01\x44\x00\xa9\x01\x7d\x05\x64\x0a\x84\x00\x74\x05\x7c\x00\xa9\x01\xa0\x06\x7c\x03\xa8\x01\xa9\x01\x44\x00\xa9\x01\x7d\x06\x74\x07\x74\x08\x7c\x05\x7c\x06\x67\x02\xa9\x01\xa9\x01\x7d\x07\x7c\x04\x67\x01\x74\x07\x7c\x05\xa9\x01\x7c\x07\x7a\x0a\x7a\x05\x7c\x06\x7c\x07\x64\x08\x85\x02\x19\x00\x7a\x00\x7d\x08\x7c\x08\x73\x5c\x7c\x02\x53\x00\x74\x09\x7c\x08\x8e\x00\x53\x00\x23\x00\x74\x0a\x74\x0b\x74\x0c\x74\x0d\x66\x04\x79\x70\x01\x00\x74\x0e\x6a\x0f\x64\x0b\x7c\x00\x7c\x01\xa9\x03\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_34_consts_0 = {
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
toplevel_consts_34_consts_1 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_34_consts_9_code = {
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
toplevel_consts_34_consts_9_varnames_0 = {
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
toplevel_consts_34_consts_9_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_34_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_34_consts_9_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_34_consts_9_name = {
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
toplevel_consts_34_consts_9_qualname = {
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
toplevel_consts_34_consts_9_linetable = {
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
toplevel_consts_34_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x41\x16\x41\x16\x41\x1d\x1e\x3f\x40\x16\x41\x17\x18\x16\x41\x16\x41\x16\x41",
};
static struct PyCodeObject toplevel_consts_34_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_34_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 499,
    .co_code = & toplevel_consts_34_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_34_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_34_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_34_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x3f\x15\x3f\x15\x3f\x1c\x1d\x3d\x3e\x15\x3f\x16\x17\x15\x3f\x15\x3f\x15\x3f",
};
static struct PyCodeObject toplevel_consts_34_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_34_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 500,
    .co_code = & toplevel_consts_34_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_34_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_34_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_34_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_34_consts_0._ascii.ob_base,
            & toplevel_consts_34_consts_1._ascii.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_22_consts_2.ob_base.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            Py_None,
            & toplevel_consts_34_consts_9.ob_base,
            & toplevel_consts_34_consts_10.ob_base,
            & toplevel_consts_10_36._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_34_names_13 = {
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
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_34_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_10_22._ascii.ob_base,
            & toplevel_consts_10_4._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_10_8._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_14_names_6._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_14_names_8._ascii.ob_base,
            & toplevel_consts_34_names_13._ascii.ob_base,
            & toplevel_consts_14_names_9._ascii.ob_base,
            & toplevel_consts_14_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_34_varnames_5 = {
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
toplevel_consts_34_varnames_6 = {
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
toplevel_consts_34_varnames_8 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_34_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_24_varnames_3._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_10_27._ascii.ob_base,
            & toplevel_consts_34_varnames_5._ascii.ob_base,
            & toplevel_consts_34_varnames_6._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_34_varnames_8._ascii.ob_base,
        },
    },
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
    .ob_sval = "\x02\x00\x04\x03\x08\x01\x0a\x02\x0a\x01\x04\x01\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x04\x02\x06\x01\x0a\x02\x02\x02\x18\x01\x18\x01\x10\x02\x1e\x02\x04\x01\x04\x01\x08\x01\x02\x80\x0e\x01\x0e\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_34_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x03\x0a\x01\x0a\x02\x08\x01\x02\x07\x04\xfa\x04\x01\x06\x01\x04\x02\x04\x01\x04\x01\x02\x02\x02\x03\x06\xfe\x0a\x02\x02\x0e\x18\xf5\x18\x01\x10\x02\x1e\x02\x02\x01\x06\x01\x08\x01\x02\x80\x0a\x01\x04\x02\x0e\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_34_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x05\x2e\x0f\x19\x1a\x2d\x0f\x2e\x09\x2e\x0c\x0e\x0c\x15\x16\x1a\x0c\x1b\x05\x09\x08\x12\x13\x17\x19\x1e\x08\x1f\x05\x16\x12\x16\x09\x0f\x0f\x13\x09\x0c\x12\x17\x09\x0f\x09\x0f\x12\x15\x09\x0f\x0f\x12\x09\x0c\x12\x16\x09\x0f\x08\x0d\x05\x21\x11\x17\x09\x0e\x09\x0e\x11\x13\x11\x1a\x1b\x20\x11\x21\x09\x0e\x05\x0e\x16\x41\x16\x41\x22\x29\x2a\x2f\x22\x30\x22\x3b\x37\x3a\x22\x3b\x22\x3b\x16\x41\x16\x41\x09\x13\x15\x3f\x15\x3f\x21\x28\x29\x2d\x21\x2e\x21\x39\x35\x38\x21\x39\x21\x39\x15\x3f\x15\x3f\x09\x12\x0d\x10\x11\x1d\x1f\x29\x2b\x34\x1e\x35\x11\x36\x0d\x37\x09\x0a\x15\x1b\x14\x1c\x20\x23\x24\x2e\x20\x2f\x30\x31\x20\x31\x14\x32\x35\x3e\x3f\x40\x3f\x41\x3f\x41\x35\x42\x14\x42\x09\x11\x10\x18\x09\x1a\x14\x1a\x0d\x1a\x10\x14\x16\x1e\x10\x1f\x09\x1f\x00\x00\x0d\x16\x18\x26\x28\x34\x36\x48\x0c\x49\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x2f\x31\x35\x37\x3c\x09\x3d\x09\x3d\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[18];
    }
toplevel_consts_34_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 17,
    },
    .ob_shash = -1,
    .ob_sval = "\xa9\x32\x41\x20\x00\xc1\x1c\x03\x41\x20\x00\xc1\x20\x11\x41\x31\x03",
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
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 477,
    .co_code = & toplevel_consts_34_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_34_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_36._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_36._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_34_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[295];
    }
toplevel_consts_35_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 294,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x09\x87\x0a\x97\x00\x7c\x00\x73\x09\x74\x00\x64\x01\xa9\x01\x82\x01\x74\x01\x74\x02\x74\x03\x6a\x04\x7c\x00\xa9\x02\xa9\x01\x7d\x00\x74\x05\x7c\x00\x64\x02\x19\x00\x74\x06\xa9\x02\x72\x1d\x64\x03\x8a\x0a\x64\x04\x8a\x09\x6e\x04\x64\x05\x8a\x0a\x64\x06\x8a\x09\x09\x00\x88\x0a\x66\x01\x64\x07\x84\x08\x7c\x00\x44\x00\xa9\x01\x7d\x01\x09\x00\x74\x07\x88\x0a\x66\x01\x64\x08\x84\x08\x7c\x00\x44\x00\xa9\x01\xa9\x01\x5c\x01\x7d\x02\x6e\x0d\x23\x00\x74\x00\x79\x40\x01\x00\x74\x00\x64\x09\xa9\x01\x64\x0a\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x88\x09\x66\x01\x64\x0b\x84\x08\x7c\x01\x44\x00\xa9\x01\x7d\x01\x74\x08\x7c\x01\xa9\x01\x7d\x03\x74\x09\x7c\x01\xa9\x01\x7d\x04\x7c\x03\x7d\x05\x74\x0a\x7c\x03\xa9\x01\x44\x00\x5d\x12\x5c\x02\x7d\x06\x7d\x07\x7c\x07\x7c\x04\x7c\x06\x19\x00\x6b\x03\x72\x6c\x7c\x03\x64\x0a\x7c\x06\x85\x02\x19\x00\x7d\x05\x01\x00\x6e\x01\x71\x5a\x7c\x02\x72\x71\x89\x0a\x6e\x05\x89\x0a\x64\x0a\x64\x02\x85\x02\x19\x00\x7d\x08\x7c\x08\x89\x0a\xa0\x0b\x7c\x05\xa8\x01\xa9\x01\x7a\x00\x53\x00\x23\x00\x74\x0c\x74\x0d\x66\x02\x79\x8f\x01\x00\x74\x0e\x6a\x0f\x64\x0c\x67\x01\x7c\x00\xa2\x01\x52\x00\x8e\x00\x01\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[69];
    }
toplevel_consts_35_consts_0 = {
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
toplevel_consts_35_consts_1 = {
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
        char ob_sval[29];
    }
toplevel_consts_35_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x67\x00\x7c\x00\x5d\x08\x7d\x01\x7c\x01\xa0\x00\x89\x02\xa8\x01\xa9\x01\x91\x02\x71\x04\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_35_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_10_4._ascii.ob_base,
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
toplevel_consts_35_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_11_varnames_0._ascii.ob_base,
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
toplevel_consts_35_consts_7_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_35_consts_7_qualname = {
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
toplevel_consts_35_consts_7_linetable = {
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
toplevel_consts_35_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x17\x3a\x17\x3a\x17\x3a\x2c\x30\x18\x1c\x18\x27\x23\x26\x18\x27\x18\x27\x17\x3a\x17\x3a\x17\x3a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_35_consts_7_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_35_consts_7_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_35_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_35_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_35_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 533,
    .co_code = & toplevel_consts_35_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_consts_7_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_35_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_35_consts_7_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_35_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x0c\x7d\x01\x7c\x01\x64\x00\x64\x01\x85\x02\x19\x00\x89\x02\x6b\x02\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_35_consts_8_consts = {
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
            & toplevel_consts_15_consts_1.ob_base.ob_base,
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
toplevel_consts_35_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_14_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_35_consts_8_name = {
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
toplevel_consts_35_consts_8_qualname = {
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
toplevel_consts_35_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x22\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_35_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x19\x36\x19\x36\x2b\x2c\x1a\x1b\x1c\x1e\x1d\x1e\x1c\x1e\x1a\x1f\x23\x26\x1a\x26\x19\x36\x19\x36\x19\x36\x19\x36\x19\x36\x19\x36",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_35_consts_8_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_35_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_35_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_35_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 536,
    .co_code = & toplevel_consts_35_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_consts_8_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_35_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_35_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_35_consts_7_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_35_consts_9 = {
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
        char ob_sval[33];
    }
toplevel_consts_35_consts_11_code = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_35_consts_11_consts_0_code = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_35_consts_11_consts_0_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_35_consts_11_consts_0_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_35_consts_11_consts_0_varnames_1._ascii.ob_base,
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
toplevel_consts_35_consts_11_consts_0_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_10_26._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_35_consts_11_consts_0_qualname = {
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
        char ob_sval[5];
    }
toplevel_consts_35_consts_11_consts_0_linetable = {
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
toplevel_consts_35_consts_11_consts_0_columntable = {
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
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_35_consts_11_consts_0_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_35_consts_11_consts_0_varnames_1._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_35_consts_11_consts_0 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_35_consts_11_consts_0_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 540,
    .co_code = & toplevel_consts_35_consts_11_consts_0_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_consts_11_consts_0_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_consts_11_consts_0_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_consts_11_consts_0_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_consts_11_consts_0_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_consts_11_consts_0_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_35_consts_11_consts_0_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_35_consts_11_consts_0_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_35_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_35_consts_11_consts_0.ob_base,
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
toplevel_consts_35_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_12_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_35_consts_11_columntable = {
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
toplevel_consts_35_consts_11_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_34_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_12_varnames_0._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_35_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_35_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_35_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 540,
    .co_code = & toplevel_consts_35_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_consts_11_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_consts_11_consts_0_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_consts_11_consts_0_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_35_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_35_consts_11_consts_0_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_35_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_35_consts_0._ascii.ob_base,
            & toplevel_consts_35_consts_1._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_11_consts_1.ob_base.ob_base,
            & toplevel_consts_16_consts_2.ob_base.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_35_consts_7.ob_base,
            & toplevel_consts_35_consts_8.ob_base,
            & toplevel_consts_35_consts_9._ascii.ob_base,
            Py_None,
            & toplevel_consts_35_consts_11.ob_base,
            & toplevel_consts_10_37._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_35_names_1 = {
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
toplevel_consts_35_names_7 = {
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
toplevel_consts_35_names_8 = {
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
toplevel_consts_35_names_9 = {
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
toplevel_consts_35_names_10 = {
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
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_35_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_35_names_1._ascii.ob_base,
            & toplevel_consts_14_names_3._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_names_1._ascii.ob_base,
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_35_names_7._ascii.ob_base,
            & toplevel_consts_35_names_8._ascii.ob_base,
            & toplevel_consts_35_names_9._ascii.ob_base,
            & toplevel_consts_35_names_10._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_14_names_6._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_14_names_9._ascii.ob_base,
            & toplevel_consts_14_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_35_varnames_0 = {
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
        uint8_t _data[12];
    }
toplevel_consts_35_varnames_1 = {
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
toplevel_consts_35_varnames_5 = {
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
        uint8_t _data[7];
    }
toplevel_consts_35_varnames_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_35_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_35_varnames_0._ascii.ob_base,
            & toplevel_consts_35_varnames_1._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_22_varnames_3._ascii.ob_base,
            & toplevel_consts_35_varnames_5._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_35_consts_11_consts_0_varnames_1._ascii.ob_base,
            & toplevel_consts_35_varnames_8._ascii.ob_base,
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
toplevel_consts_35_cellvars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_35_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x04\x03\x08\x01\x10\x02\x0e\x01\x04\x01\x06\x01\x04\x02\x04\x01\x02\x02\x10\x01\x02\x02\x18\x01\x02\x80\x06\x01\x0a\x01\x02\xff\x06\x80\x10\x03\x08\x01\x08\x01\x04\x01\x10\x01\x0c\x01\x0c\x01\x04\x01\x02\xfe\x14\x04\x10\x01\x02\x80\x0a\x01\x12\x01\x02\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[77];
    }
toplevel_consts_35_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 76,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x02\x03\x0a\x01\x10\x02\x0c\x01\x02\x05\x04\xfc\x06\x01\x04\x02\x04\x01\x02\x17\x10\xec\x02\x05\x18\xfe\x02\x80\x02\x01\x10\x01\x06\x80\x10\x02\x08\x01\x08\x01\x04\x01\x06\x01\x04\x03\x06\xfd\x0a\x01\x02\x02\x0c\xff\x06\x01\x14\x02\x10\x01\x02\x80\x06\x01\x04\x02\x12\xff\x04\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[295];
    }
toplevel_consts_35_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 294,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x0c\x11\x05\x42\x0f\x19\x1a\x41\x0f\x42\x09\x42\x0d\x12\x13\x16\x17\x19\x17\x20\x22\x27\x13\x28\x0d\x29\x05\x0a\x08\x12\x13\x18\x19\x1a\x13\x1b\x1d\x22\x08\x23\x05\x15\x0f\x13\x09\x0c\x12\x16\x09\x0f\x09\x0f\x0f\x12\x09\x0c\x12\x15\x09\x0f\x05\x0e\x17\x3a\x17\x3a\x17\x3a\x17\x3a\x34\x39\x17\x3a\x17\x3a\x09\x14\x09\x50\x16\x19\x19\x36\x19\x36\x19\x36\x19\x36\x30\x35\x19\x36\x19\x36\x16\x36\x0d\x13\x0d\x12\x0d\x12\x00\x00\x10\x1a\x09\x50\x09\x50\x13\x1d\x1e\x45\x13\x46\x4c\x50\x0d\x50\x09\x50\x00\x00\x00\x00\x00\x00\x17\x51\x17\x51\x17\x51\x17\x51\x45\x50\x17\x51\x17\x51\x09\x14\x0e\x11\x12\x1d\x0e\x1e\x09\x0b\x0e\x11\x12\x1d\x0e\x1e\x09\x0b\x12\x14\x09\x0f\x15\x1e\x1f\x21\x15\x22\x09\x16\x09\x16\x0d\x11\x0d\x0e\x10\x11\x10\x11\x15\x17\x18\x19\x15\x1a\x10\x1a\x0d\x16\x1a\x1c\x1d\x1f\x1e\x1f\x1d\x1f\x1a\x20\x11\x17\x11\x16\x11\x16\x0d\x16\x19\x1e\x12\x2b\x12\x15\x12\x15\x24\x27\x28\x2a\x29\x2a\x28\x2a\x24\x2b\x09\x0f\x10\x16\x19\x1c\x19\x29\x22\x28\x19\x29\x19\x29\x10\x29\x09\x29\x00\x00\x0d\x16\x18\x26\x0c\x27\x05\x0e\x05\x0e\x09\x14\x09\x25\x26\x32\x09\x3b\x35\x3a\x09\x3b\x09\x3b\x09\x3b\x09\x3b\x09\x0e\x05\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[32];
    }
toplevel_consts_35_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 31,
    },
    .ob_shash = -1,
    .ob_sval = "\xa2\x08\x41\x3f\x00\xab\x0b\x37\x00\xb6\x01\x41\x3f\x00\xb7\x0a\x41\x01\x03\xc1\x01\x3d\x41\x3f\x00\xc1\x3f\x11\x42\x10\x03",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_35_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_35_varnames_0._ascii.ob_base,
            & toplevel_consts_35_varnames_1._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_22_varnames_3._ascii.ob_base,
            & toplevel_consts_35_varnames_5._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_35_consts_11_consts_0_varnames_1._ascii.ob_base,
            & toplevel_consts_35_varnames_8._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_35_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 11,
    },
    .ob_shash = -1,
    .ob_sval = "         @@",
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
    .co_stacksize = 4,
    .co_firstlineno = 518,
    .co_code = & toplevel_consts_35_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_37._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_37._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_columntable.ob_base.ob_base,
    .co_nlocalsplus = 11,
    .co_nlocals = 9,
    .co_nplaincellvars = 2,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_35_cellvars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_36 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[37];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 37,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1._ascii.ob_base,
            & toplevel_consts_2._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_4._ascii.ob_base,
            & toplevel_consts_5._ascii.ob_base,
            Py_None,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_9._object.ob_base.ob_base,
            & toplevel_consts_10._object.ob_base.ob_base,
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
            & toplevel_consts_25._object.ob_base.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_27.ob_base,
            & toplevel_consts_28.ob_base,
            Py_False,
            & toplevel_consts_30._object.ob_base.ob_base,
            & toplevel_consts_31.ob_base,
            & toplevel_consts_32.ob_base,
            & toplevel_consts_33._ascii.ob_base,
            & toplevel_consts_34.ob_base,
            & toplevel_consts_35.ob_base,
            & toplevel_consts_36._object.ob_base.ob_base,
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
        uint8_t _data[6];
    }
toplevel_names_31 = {
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
        uint8_t _data[12];
    }
toplevel_names_33 = {
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
            PyObject *ob_item[42];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 42,
        },
        .ob_item = {
            & toplevel_names_0._ascii.ob_base,
            & toplevel_consts_10_26._ascii.ob_base,
            & toplevel_consts_10_27._ascii.ob_base,
            & toplevel_consts_10_32._ascii.ob_base,
            & toplevel_consts_10_28._ascii.ob_base,
            & toplevel_consts_10_29._ascii.ob_base,
            & toplevel_consts_10_30._ascii.ob_base,
            & toplevel_consts_10_31._ascii.ob_base,
            & toplevel_consts_10_33._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_23_names_16._ascii.ob_base,
            & toplevel_consts_20_names_5._ascii.ob_base,
            & toplevel_consts_14_names_9._ascii.ob_base,
            & toplevel_names_13._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_10_1._ascii.ob_base,
            & toplevel_consts_10_2._ascii.ob_base,
            & toplevel_consts_10_4._ascii.ob_base,
            & toplevel_consts_10_5._ascii.ob_base,
            & toplevel_consts_16_names_5._ascii.ob_base,
            & toplevel_consts_10_3._ascii.ob_base,
            & toplevel_consts_10_6._ascii.ob_base,
            & toplevel_consts_10_7._ascii.ob_base,
            & toplevel_consts_10_13._ascii.ob_base,
            & toplevel_consts_10_15._ascii.ob_base,
            & toplevel_consts_10_18._ascii.ob_base,
            & toplevel_consts_10_19._ascii.ob_base,
            & toplevel_consts_24_names_10._ascii.ob_base,
            & toplevel_consts_24_names_4._ascii.ob_base,
            & toplevel_consts_10_20._ascii.ob_base,
            & toplevel_names_31._ascii.ob_base,
            & toplevel_consts_25_0._ascii.ob_base,
            & toplevel_names_33._ascii.ob_base,
            & toplevel_consts_10_21._ascii.ob_base,
            & toplevel_consts_10_22._ascii.ob_base,
            & toplevel_consts_10_34._ascii.ob_base,
            & toplevel_consts_31_names_2._ascii.ob_base,
            & toplevel_consts_23_names_17._ascii.ob_base,
            & toplevel_consts_10_35._ascii.ob_base,
            & toplevel_consts_10_36._ascii.ob_base,
            & toplevel_consts_10_37._ascii.ob_base,
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
        char ob_sval[95];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x04\x0f\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x08\x02\x08\x01\x08\x01\x08\x01\x08\x01\x08\x02\x06\x0a\x06\x0b\x06\x08\x06\x0b\x06\x1d\x06\x11\x0a\x09\x06\x05\x06\x09\x06\x0a\x06\x0e\x06\x0a\x06\x0c\x06\x2a\x04\x35\x04\x01\x06\x02\x02\x35\x0e\x01\x02\x80\x06\x02\x0a\x01\x02\xff\x06\x80\x06\x28\x06\x08\x0c\x0f\x06\x09\x0a\x3f\x08\x02\x0a\x29",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x0a\x04\x05\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x08\x02\x08\x01\x08\x01\x08\x01\x08\x01\x06\x09\x02\xf9\x06\x0e\x06\x09\x06\x0a\x06\x1c\x06\x11\x06\x10\x0a\x01\x06\x09\x06\x0a\x06\x0d\x06\x0c\x06\x0a\x06\x24\x06\x3a\x04\x07\x04\x01\x06\x30\x02\x37\x0e\xd1\x02\x80\x02\x02\x10\x25\x06\x80\x06\x08\x06\x0c\x02\x06\x0a\x05\x06\x40\x0a\x03\x02\x02\x06\x21\x0a\x2b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[289];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 288,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x0a\x0d\x01\x07\x0a\x0e\x01\x07\x0a\x0d\x01\x07\x07\x0a\x01\x04\x0b\x0e\x01\x08\x0b\x1a\x01\x08\x0a\x0e\x01\x07\x0b\x16\x01\x08\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x13\x01\x13\x01\x13\x01\x13\x01\x1a\x01\x1a\x01\x1a\x01\x1a\x0b\x19\x0b\x19\x0b\x19\x01\x08\x01\x13\x01\x13\x01\x13\x01\x18\x01\x18\x01\x18\x01\x1d\x01\x1d\x01\x1d\x01\x10\x01\x10\x01\x10\x01\x16\x01\x16\x01\x16\x01\x37\x01\x37\x01\x37\x14\x1f\x14\x29\x14\x31\x01\x09\x01\x11\x01\x14\x01\x14\x01\x14\x01\x11\x01\x11\x01\x11\x01\x10\x01\x10\x01\x10\x01\x24\x01\x24\x01\x24\x01\x10\x01\x10\x01\x10\x01\x11\x01\x11\x01\x11\x01\x29\x01\x29\x01\x29\x0c\x10\x01\x09\x0d\x11\x01\x0a\x01\x10\x01\x10\x01\x10\x01\x2b\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25\x00\x00\x08\x13\x01\x1b\x01\x1b\x05\x1b\x05\x1b\x05\x1b\x05\x1b\x05\x1b\x01\x1b\x00\x00\x00\x00\x00\x00\x05\x2b\x05\x2b\x05\x2b\x01\x1a\x01\x1a\x01\x1a\x22\x27\x01\x19\x01\x19\x01\x19\x01\x19\x01\x19\x01\x16\x01\x16\x01\x16\x1f\x22\x1f\x2b\x2f\x37\x1f\x37\x01\x1b\x19\x1d\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x01\x0e",
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
    .ob_sval = "\xc1\x1f\x06\x41\x26\x00\xc1\x26\x07\x41\x30\x03\xc1\x2f\x01\x41\x30\x03",
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
    .co_localsplusnames = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_posixpath_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

