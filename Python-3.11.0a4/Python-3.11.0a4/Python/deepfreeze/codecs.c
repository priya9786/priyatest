#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[535];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 534,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x64\x01\x64\x02\x6c\x02\x5a\x02\x09\x00\x64\x01\x64\x03\x6c\x03\x54\x00\x6e\x12\x23\x00\x65\x04\x79\x1f\x5a\x05\x65\x06\x64\x04\x65\x05\x7a\x06\xa9\x01\x82\x01\x64\x02\x5a\x05\x5b\x05\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x67\x00\x64\x05\xa2\x01\x5a\x07\x64\x06\x5a\x08\x64\x07\x04\x00\x5a\x09\x5a\x0a\x64\x08\x04\x00\x5a\x0b\x5a\x0c\x64\x09\x5a\x0d\x64\x0a\x5a\x0e\x65\x02\x6a\x0f\x64\x0b\x6b\x02\x72\x41\x65\x0a\x04\x00\x5a\x10\x5a\x11\x65\x0d\x5a\x12\x6e\x06\x65\x0c\x04\x00\x5a\x10\x5a\x11\x65\x0e\x5a\x12\x65\x0a\x5a\x13\x65\x0c\x5a\x14\x65\x0d\x5a\x15\x65\x0e\x5a\x16\x47\x00\x64\x0c\x84\x00\x64\x0d\x65\x17\xa9\x03\x5a\x18\x47\x00\x64\x0e\x84\x00\x64\x0f\xa9\x02\x5a\x19\x47\x00\x64\x10\x84\x00\x64\x11\x65\x1a\xa9\x03\x5a\x1b\x47\x00\x64\x12\x84\x00\x64\x13\x65\x1b\xa9\x03\x5a\x1c\x47\x00\x64\x14\x84\x00\x64\x15\x65\x1a\xa9\x03\x5a\x1d\x47\x00\x64\x16\x84\x00\x64\x17\x65\x1d\xa9\x03\x5a\x1e\x47\x00\x64\x18\x84\x00\x64\x19\x65\x19\xa9\x03\x5a\x1f\x47\x00\x64\x1a\x84\x00\x64\x1b\x65\x19\xa9\x03\x5a\x20\x47\x00\x64\x1c\x84\x00\x64\x1d\xa9\x02\x5a\x21\x47\x00\x64\x1e\x84\x00\x64\x1f\xa9\x02\x5a\x22\x64\x37\x64\x23\x84\x01\x5a\x23\x64\x38\x64\x24\x84\x01\x5a\x24\x64\x25\x84\x00\x5a\x25\x64\x26\x84\x00\x5a\x26\x64\x27\x84\x00\x5a\x27\x64\x28\x84\x00\x5a\x28\x64\x29\x84\x00\x5a\x29\x64\x2a\x84\x00\x5a\x2a\x64\x39\x64\x2b\x84\x01\x5a\x2b\x64\x39\x64\x2c\x84\x01\x5a\x2c\x64\x2d\x84\x00\x5a\x2d\x64\x2e\x84\x00\x5a\x2e\x09\x00\x65\x2f\x64\x21\xa9\x01\x5a\x30\x65\x2f\x64\x2f\xa9\x01\x5a\x31\x65\x2f\x64\x30\xa9\x01\x5a\x32\x65\x2f\x64\x31\xa9\x01\x5a\x33\x65\x2f\x64\x32\xa9\x01\x5a\x34\x65\x2f\x64\x33\xa9\x01\x5a\x35\x6e\x16\x23\x00\x65\x36\x79\xe6\x01\x00\x64\x02\x5a\x30\x64\x02\x5a\x31\x64\x02\x5a\x32\x64\x02\x5a\x33\x64\x02\x5a\x34\x64\x02\x5a\x35\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x64\x01\x5a\x37\x65\x37\x72\xf2\x64\x01\x64\x02\x6c\x38\x5a\x38\x65\x39\x64\x34\x6b\x02\x90\x01\x72\x09\x65\x24\x65\x02\x6a\x3a\x64\x35\x64\x36\xa9\x03\x65\x02\x5f\x3a\x65\x24\x65\x02\x6a\x3b\x64\x36\x64\x35\xa9\x03\x65\x02\x5f\x3b\x64\x02\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[159];
    }
toplevel_consts_0 = {
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
    ._data = "\x20\x63\x6f\x64\x65\x63\x73\x20\x2d\x2d\x20\x50\x79\x74\x68\x6f\x6e\x20\x43\x6f\x64\x65\x63\x20\x52\x65\x67\x69\x73\x74\x72\x79\x2c\x20\x41\x50\x49\x20\x61\x6e\x64\x20\x68\x65\x6c\x70\x65\x72\x73\x2e\x0a\x0a\x0a\x57\x72\x69\x74\x74\x65\x6e\x20\x62\x79\x20\x4d\x61\x72\x63\x2d\x41\x6e\x64\x72\x65\x20\x4c\x65\x6d\x62\x75\x72\x67\x20\x28\x6d\x61\x6c\x40\x6c\x65\x6d\x62\x75\x72\x67\x2e\x63\x6f\x6d\x29\x2e\x0a\x0a\x28\x63\x29\x20\x43\x6f\x70\x79\x72\x69\x67\x68\x74\x20\x43\x4e\x52\x49\x2c\x20\x41\x6c\x6c\x20\x52\x69\x67\x68\x74\x73\x20\x52\x65\x73\x65\x72\x76\x65\x64\x2e\x20\x4e\x4f\x20\x57\x41\x52\x52\x41\x4e\x54\x59\x2e\x0a\x0a",
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
        uint8_t _data[2];
    }
toplevel_consts_3_0 = {
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
        uint8_t _data[38];
    }
toplevel_consts_4 = {
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
    ._data = "Failed to load the builtin codecs: %s",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_0 = {
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
        uint8_t _data[7];
    }
toplevel_consts_5_1 = {
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
    ._data = "lookup",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_2 = {
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
        uint8_t _data[12];
    }
toplevel_consts_5_3 = {
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
    ._data = "EncodedFile",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_5_4 = {
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
    ._data = "BOM",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_5 = {
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
    ._data = "BOM_BE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_6 = {
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
    ._data = "BOM_LE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_7 = {
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
    ._data = "BOM32_BE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_8 = {
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
    ._data = "BOM32_LE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_9 = {
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
    ._data = "BOM64_BE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_10 = {
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
    ._data = "BOM64_LE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_11 = {
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
    ._data = "BOM_UTF8",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_12 = {
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
    ._data = "BOM_UTF16",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_13 = {
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
    ._data = "BOM_UTF16_LE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_14 = {
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
    ._data = "BOM_UTF16_BE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_15 = {
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
    ._data = "BOM_UTF32",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_16 = {
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
    ._data = "BOM_UTF32_LE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_17 = {
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
    ._data = "BOM_UTF32_BE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_18 = {
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
    ._data = "CodecInfo",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_19 = {
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
    ._data = "Codec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_5_20 = {
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
    ._data = "IncrementalEncoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_5_21 = {
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
    ._data = "IncrementalDecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_22 = {
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
    ._data = "StreamReader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_23 = {
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
    ._data = "StreamWriter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_5_24 = {
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
    ._data = "StreamReaderWriter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5_25 = {
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
    ._data = "StreamRecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_26 = {
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
    ._data = "getencoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_27 = {
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
    ._data = "getdecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_5_28 = {
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
    ._data = "getincrementalencoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_5_29 = {
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
    ._data = "getincrementaldecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_30 = {
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
    ._data = "getreader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_31 = {
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
    ._data = "getwriter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_32 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_33 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_34 = {
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
    ._data = "iterencode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_35 = {
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
    ._data = "iterdecode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5_36 = {
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
    ._data = "strict_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_5_37 = {
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
    ._data = "ignore_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_38 = {
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
    ._data = "replace_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_5_39 = {
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
    ._data = "xmlcharrefreplace_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_5_40 = {
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
    ._data = "backslashreplace_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_5_41 = {
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
    ._data = "namereplace_errors",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_42 = {
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
    ._data = "register_error",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_5_43 = {
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
    ._data = "lookup_error",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[44];
        }_object;
    }
toplevel_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 44,
        },
        .ob_item = {
            & toplevel_consts_5_0._ascii.ob_base,
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_5_2._ascii.ob_base,
            & toplevel_consts_5_3._ascii.ob_base,
            & toplevel_consts_5_4._ascii.ob_base,
            & toplevel_consts_5_5._ascii.ob_base,
            & toplevel_consts_5_6._ascii.ob_base,
            & toplevel_consts_5_7._ascii.ob_base,
            & toplevel_consts_5_8._ascii.ob_base,
            & toplevel_consts_5_9._ascii.ob_base,
            & toplevel_consts_5_10._ascii.ob_base,
            & toplevel_consts_5_11._ascii.ob_base,
            & toplevel_consts_5_12._ascii.ob_base,
            & toplevel_consts_5_13._ascii.ob_base,
            & toplevel_consts_5_14._ascii.ob_base,
            & toplevel_consts_5_15._ascii.ob_base,
            & toplevel_consts_5_16._ascii.ob_base,
            & toplevel_consts_5_17._ascii.ob_base,
            & toplevel_consts_5_18._ascii.ob_base,
            & toplevel_consts_5_19._ascii.ob_base,
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_5_22._ascii.ob_base,
            & toplevel_consts_5_23._ascii.ob_base,
            & toplevel_consts_5_24._ascii.ob_base,
            & toplevel_consts_5_25._ascii.ob_base,
            & toplevel_consts_5_26._ascii.ob_base,
            & toplevel_consts_5_27._ascii.ob_base,
            & toplevel_consts_5_28._ascii.ob_base,
            & toplevel_consts_5_29._ascii.ob_base,
            & toplevel_consts_5_30._ascii.ob_base,
            & toplevel_consts_5_31._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_5_34._ascii.ob_base,
            & toplevel_consts_5_35._ascii.ob_base,
            & toplevel_consts_5_36._ascii.ob_base,
            & toplevel_consts_5_37._ascii.ob_base,
            & toplevel_consts_5_38._ascii.ob_base,
            & toplevel_consts_5_39._ascii.ob_base,
            & toplevel_consts_5_40._ascii.ob_base,
            & toplevel_consts_5_41._ascii.ob_base,
            & toplevel_consts_5_42._ascii.ob_base,
            & toplevel_consts_5_43._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_6 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 3,
    },
    .ob_shash = -1,
    .ob_sval = "\xef\xbb\xbf",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_7 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\xff\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_8 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\xfe\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\xff\xfe\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\xfe\xff",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_11 = {
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
    ._data = "little",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x09\x03\x09\x03\x64\x07\x64\x03\x64\x04\x9c\x01\x64\x05\x84\x03\x5a\x05\x64\x06\x84\x00\x5a\x06\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_12_consts_1 = {
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
    ._data = "Codec details when looking up the codec registry",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_12_consts_4_0 = {
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
    ._data = "_is_text_encoding",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_12_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x7c\x04\x66\x04\xa8\x02\xa9\x02\x7d\x09\x7c\x07\x7c\x09\x5f\x02\x7c\x01\x7c\x09\x5f\x03\x7c\x02\x7c\x09\x5f\x04\x7c\x05\x7c\x09\x5f\x05\x7c\x06\x7c\x09\x5f\x06\x7c\x04\x7c\x09\x5f\x07\x7c\x03\x7c\x09\x5f\x08\x7c\x08\x81\x26\x7c\x08\x7c\x09\x5f\x09\x7c\x09\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts_5_consts = {
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
        uint8_t _data[6];
    }
toplevel_consts_12_consts_5_names_0 = {
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
toplevel_consts_12_consts_5_names_1 = {
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
    ._data = "__new__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_12_consts_5_names_2 = {
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
        uint8_t _data[19];
    }
toplevel_consts_12_consts_5_names_5 = {
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
    ._data = "incrementalencoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_12_consts_5_names_6 = {
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
    ._data = "incrementaldecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_12_consts_5_names_7 = {
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
    ._data = "streamwriter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_12_consts_5_names_8 = {
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
    ._data = "streamreader",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_12_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_5._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_8._ascii.ob_base,
            & toplevel_consts_12_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_12_consts_5_varnames_0 = {
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
        uint8_t _data[5];
    }
toplevel_consts_12_consts_5_varnames_9 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_12_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_8._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_5._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_12_consts_4_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
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
toplevel_consts_12_consts_5_freevars = {
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
toplevel_consts_12_consts_5_filename = {
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
    ._data = "<frozen codecs>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_12_consts_5_qualname = {
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
    ._data = "CodecInfo.__new__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_12_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x16\x03\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x04\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_12_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x16\x03\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x02\x01\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_12_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x15\x10\x50\x1e\x21\x24\x2a\x2c\x32\x34\x40\x42\x4e\x23\x4f\x10\x50\x10\x50\x09\x0d\x15\x19\x09\x0d\x09\x12\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x23\x35\x09\x0d\x09\x20\x23\x35\x09\x0d\x09\x20\x1d\x29\x09\x0d\x09\x1a\x1d\x29\x09\x0d\x09\x1a\x0c\x1d\x09\x37\x26\x37\x0d\x11\x0d\x23\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_12_consts_5_exceptiontable = {
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
        char ob_sval[11];
    }
toplevel_consts_12_consts_5_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 8,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 7,
    .co_firstlineno = 94,
    .co_code = & toplevel_consts_12_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_5_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_12_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7c\x00\x6a\x00\x6a\x01\x7c\x00\x6a\x00\x6a\x02\x7c\x00\x6a\x03\x74\x04\x7c\x00\xa9\x01\x66\x04\x7a\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_12_consts_6_consts_1 = {
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
    ._data = "<%s.%s object for encoding %s at %#x>",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts_6_consts = {
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
            & toplevel_consts_12_consts_6_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_12_consts_6_names_0 = {
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
        uint8_t _data[11];
    }
toplevel_consts_12_consts_6_names_1 = {
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
toplevel_consts_12_consts_6_names_2 = {
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
        uint8_t _data[3];
    }
toplevel_consts_12_consts_6_names_4 = {
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
    ._data = "id",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_12_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_12_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_4._ascii.ob_base,
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
toplevel_consts_12_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_consts_6_name = {
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
        uint8_t _data[19];
    }
toplevel_consts_12_consts_6_qualname = {
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
    ._data = "CodecInfo.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_12_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x0c\x01\x0a\x01\x02\xff\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_12_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_12_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x37\x12\x16\x12\x20\x12\x2b\x2d\x31\x2d\x3b\x2d\x48\x12\x16\x12\x1b\x1d\x1f\x20\x24\x1d\x25\x11\x26\x10\x26\x09\x26",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_12_consts_6_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 109,
    .co_code = & toplevel_consts_12_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_12_consts_7 = {
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
            Py_None,
            Py_None,
            Py_None,
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
toplevel_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_5_18._ascii.ob_base,
            & toplevel_consts_12_consts_1._ascii.ob_base,
            Py_True,
            Py_None,
            & toplevel_consts_12_consts_4._object.ob_base.ob_base,
            & toplevel_consts_12_consts_5.ob_base,
            & toplevel_consts_12_consts_6.ob_base,
            & toplevel_consts_12_consts_7._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_names_0 = {
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
        uint8_t _data[8];
    }
toplevel_consts_12_names_3 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_12_names = {
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
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_12_consts_4_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x08\x02\x02\x02\x01\x02\xff\x02\x02\x0a\xfe\x0a\x0f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x08\x02\x02\x02\x01\x02\x0c\x02\xf5\x0a\x0b\x0a\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x3b\x05\x3b\x19\x1d\x05\x16\x33\x37\x1c\x20\x05\x14\x1e\x22\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 83,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_18._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_18._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x06\x64\x03\x84\x01\x5a\x04\x64\x06\x64\x04\x84\x01\x5a\x05\x64\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1082];
    }
toplevel_consts_14_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1081,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x44\x65\x66\x69\x6e\x65\x73\x20\x74\x68\x65\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x66\x6f\x72\x20\x73\x74\x61\x74\x65\x6c\x65\x73\x73\x20\x65\x6e\x63\x6f\x64\x65\x72\x73\x2f\x64\x65\x63\x6f\x64\x65\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x2e\x65\x6e\x63\x6f\x64\x65\x28\x29\x2f\x2e\x64\x65\x63\x6f\x64\x65\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x6d\x61\x79\x20\x75\x73\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x65\x72\x72\x6f\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x73\x63\x68\x65\x6d\x65\x73\x20\x62\x79\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x73\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x20\x54\x68\x65\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x69\x6e\x67\x20\x76\x61\x6c\x75\x65\x73\x20\x61\x72\x65\x20\x70\x72\x65\x64\x65\x66\x69\x6e\x65\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x2d\x20\x72\x61\x69\x73\x65\x20\x61\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x65\x72\x72\x6f\x72\x20\x28\x6f\x72\x20\x61\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x69\x67\x6e\x6f\x72\x65\x27\x20\x2d\x20\x69\x67\x6e\x6f\x72\x65\x20\x74\x68\x65\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x61\x6e\x64\x20\x63\x6f\x6e\x74\x69\x6e\x75\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x6e\x65\x78\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x2d\x20\x72\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x61\x20\x73\x75\x69\x74\x61\x62\x6c\x65\x20\x72\x65\x70\x6c\x61\x63\x65\x6d\x65\x6e\x74\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x3b\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x50\x79\x74\x68\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x75\x73\x65\x20\x74\x68\x65\x20\x6f\x66\x66\x69\x63\x69\x61\x6c\x20\x55\x2b\x46\x46\x46\x44\x20\x52\x45\x50\x4c\x41\x43\x45\x4d\x45\x4e\x54\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x43\x48\x41\x52\x41\x43\x54\x45\x52\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x69\x6e\x20\x55\x6e\x69\x63\x6f\x64\x65\x20\x63\x6f\x64\x65\x63\x73\x20\x6f\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x27\x3f\x27\x20\x6f\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x75\x72\x72\x6f\x67\x61\x74\x65\x65\x73\x63\x61\x70\x65\x27\x20\x2d\x20\x72\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x70\x72\x69\x76\x61\x74\x65\x20\x63\x6f\x64\x65\x20\x70\x6f\x69\x6e\x74\x73\x20\x55\x2b\x44\x43\x6e\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x78\x6d\x6c\x63\x68\x61\x72\x72\x65\x66\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x61\x70\x70\x72\x6f\x70\x72\x69\x61\x74\x65\x20\x58\x4d\x4c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x20\x28\x6f\x6e\x6c\x79\x20\x66\x6f\x72\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x65\x64\x20\x65\x73\x63\x61\x70\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x6e\x61\x6d\x65\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x20\x20\x20\x20\x20\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x5c\x4e\x7b\x2e\x2e\x2e\x7d\x20\x65\x73\x63\x61\x70\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x28\x6f\x6e\x6c\x79\x20\x66\x6f\x72\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x73\x65\x74\x20\x6f\x66\x20\x61\x6c\x6c\x6f\x77\x65\x64\x20\x76\x61\x6c\x75\x65\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x65\x78\x74\x65\x6e\x64\x65\x64\x20\x76\x69\x61\x20\x72\x65\x67\x69\x73\x74\x65\x72\x5f\x65\x72\x72\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_14_consts_2 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_14_consts_3_code = {
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
        uint8_t _data[548];
    }
toplevel_consts_14_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 547,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x45\x6e\x63\x6f\x64\x65\x73\x20\x74\x68\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x61\x20\x74\x75\x70\x6c\x65\x20\x28\x6f\x75\x74\x70\x75\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x62\x6a\x65\x63\x74\x2c\x20\x6c\x65\x6e\x67\x74\x68\x20\x63\x6f\x6e\x73\x75\x6d\x65\x64\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x64\x65\x66\x69\x6e\x65\x73\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x74\x6f\x20\x61\x70\x70\x6c\x79\x2e\x20\x49\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x20\x74\x6f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x20\x6d\x61\x79\x20\x6e\x6f\x74\x20\x73\x74\x6f\x72\x65\x20\x73\x74\x61\x74\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x43\x6f\x64\x65\x63\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x20\x55\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x66\x6f\x72\x20\x63\x6f\x64\x65\x63\x73\x20\x77\x68\x69\x63\x68\x20\x68\x61\x76\x65\x20\x74\x6f\x20\x6b\x65\x65\x70\x20\x73\x74\x61\x74\x65\x20\x69\x6e\x20\x6f\x72\x64\x65\x72\x20\x74\x6f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x6b\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x65\x66\x66\x69\x63\x69\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x72\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x68\x61\x6e\x64\x6c\x65\x20\x7a\x65\x72\x6f\x20\x6c\x65\x6e\x67\x74\x68\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x61\x6e\x20\x65\x6d\x70\x74\x79\x20\x6f\x62\x6a\x65\x63\x74\x20\x6f\x66\x20\x74\x68\x65\x20\x6f\x75\x74\x70\x75\x74\x20\x6f\x62\x6a\x65\x63\x74\x20\x74\x79\x70\x65\x20\x69\x6e\x20\x74\x68\x69\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x69\x74\x75\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_3_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_14_consts_3_names_0 = {
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
toplevel_consts_14_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_3_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_14_consts_3_varnames_1 = {
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
    ._data = "input",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_14_consts_3_varnames_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_14_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_14_consts_3_qualname = {
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
    ._data = "Codec.encode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_14_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_14_consts_3_columntable = {
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
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_14_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_14_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 138,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_32._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[755];
    }
toplevel_consts_14_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 754,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x44\x65\x63\x6f\x64\x65\x73\x20\x74\x68\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x61\x20\x74\x75\x70\x6c\x65\x20\x28\x6f\x75\x74\x70\x75\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x62\x6a\x65\x63\x74\x2c\x20\x6c\x65\x6e\x67\x74\x68\x20\x63\x6f\x6e\x73\x75\x6d\x65\x64\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x70\x75\x74\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x20\x77\x68\x69\x63\x68\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x74\x68\x65\x20\x62\x66\x5f\x67\x65\x74\x72\x65\x61\x64\x62\x75\x66\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x75\x66\x66\x65\x72\x20\x73\x6c\x6f\x74\x2e\x20\x50\x79\x74\x68\x6f\x6e\x20\x73\x74\x72\x69\x6e\x67\x73\x2c\x20\x62\x75\x66\x66\x65\x72\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x61\x6e\x64\x20\x6d\x65\x6d\x6f\x72\x79\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x70\x70\x65\x64\x20\x66\x69\x6c\x65\x73\x20\x61\x72\x65\x20\x65\x78\x61\x6d\x70\x6c\x65\x73\x20\x6f\x66\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x69\x73\x20\x73\x6c\x6f\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x64\x65\x66\x69\x6e\x65\x73\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x74\x6f\x20\x61\x70\x70\x6c\x79\x2e\x20\x49\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x20\x74\x6f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x20\x6d\x61\x79\x20\x6e\x6f\x74\x20\x73\x74\x6f\x72\x65\x20\x73\x74\x61\x74\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x43\x6f\x64\x65\x63\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x20\x55\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x20\x66\x6f\x72\x20\x63\x6f\x64\x65\x63\x73\x20\x77\x68\x69\x63\x68\x20\x68\x61\x76\x65\x20\x74\x6f\x20\x6b\x65\x65\x70\x20\x73\x74\x61\x74\x65\x20\x69\x6e\x20\x6f\x72\x64\x65\x72\x20\x74\x6f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x6b\x65\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x65\x66\x66\x69\x63\x69\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x68\x61\x6e\x64\x6c\x65\x20\x7a\x65\x72\x6f\x20\x6c\x65\x6e\x67\x74\x68\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x20\x61\x6e\x20\x65\x6d\x70\x74\x79\x20\x6f\x62\x6a\x65\x63\x74\x20\x6f\x66\x20\x74\x68\x65\x20\x6f\x75\x74\x70\x75\x74\x20\x6f\x62\x6a\x65\x63\x74\x20\x74\x79\x70\x65\x20\x69\x6e\x20\x74\x68\x69\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x69\x74\x75\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_4_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_14_consts_4_qualname = {
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
    ._data = "Codec.decode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_14_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x15",
};
static struct PyCodeObject toplevel_consts_14_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 157,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_33._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14_consts_6 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_2._ascii.ob_base,
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
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_19._ascii.ob_base,
            & toplevel_consts_14_consts_1._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_14_consts_3.ob_base,
            & toplevel_consts_14_consts_4.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
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
toplevel_consts_14_names = {
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
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x08\x16\x0c\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x17\x02\x01\x06\x11\x02\x02\x0a\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x24\x2c\x05\x22\x05\x22\x05\x22\x24\x2c\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22",
};
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 114,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_19._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_19._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x0a\x64\x03\x84\x01\x5a\x04\x64\x0b\x64\x05\x84\x01\x5a\x05\x64\x06\x84\x00\x5a\x06\x64\x07\x84\x00\x5a\x07\x64\x08\x84\x00\x5a\x08\x64\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[233];
    }
toplevel_consts_16_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 232,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x41\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x20\x65\x6e\x63\x6f\x64\x65\x73\x20\x61\x6e\x20\x69\x6e\x70\x75\x74\x20\x69\x6e\x20\x6d\x75\x6c\x74\x69\x70\x6c\x65\x20\x73\x74\x65\x70\x73\x2e\x20\x54\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x63\x61\x6e\x0a\x20\x20\x20\x20\x62\x65\x20\x70\x61\x73\x73\x65\x64\x20\x70\x69\x65\x63\x65\x20\x62\x79\x20\x70\x69\x65\x63\x65\x20\x74\x6f\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x2e\x20\x54\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x72\x65\x6d\x65\x6d\x62\x65\x72\x73\x20\x74\x68\x65\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x70\x72\x6f\x63\x65\x73\x73\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x63\x61\x6c\x6c\x73\x20\x74\x6f\x20\x65\x6e\x63\x6f\x64\x65\x28\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_16_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x64\x01\x7c\x00\x5f\x01\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[245];
    }
toplevel_consts_16_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 244,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x20\x6d\x61\x79\x20\x75\x73\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x73\x63\x68\x65\x6d\x65\x73\x20\x62\x79\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x73\x20\x6b\x65\x79\x77\x6f\x72\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x20\x53\x65\x65\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x64\x6f\x63\x73\x74\x72\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x20\x76\x61\x6c\x75\x65\x73\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_16_consts_3_consts_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_16_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_16_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_16_consts_3_consts_1._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_16_consts_3_names_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
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
toplevel_consts_16_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_consts_3_name = {
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
        uint8_t _data[28];
    }
toplevel_consts_16_consts_3_qualname = {
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
    ._data = "IncrementalEncoder.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_16_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x08\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_16_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x17\x19\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_16_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_16_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 186,
    .co_code = & toplevel_consts_16_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[66];
    }
toplevel_consts_16_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 65,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x45\x6e\x63\x6f\x64\x65\x73\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_16_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_16_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_16_consts_5_varnames_2 = {
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
    ._data = "final",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_16_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_16_consts_5_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_16_consts_5_qualname = {
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
    ._data = "IncrementalEncoder.encode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_16_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x04",
};
static struct PyCodeObject toplevel_consts_16_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 197,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_32._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_16_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[59];
    }
toplevel_consts_16_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 58,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x73\x65\x74\x73\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x72\x20\x74\x6f\x20\x74\x68\x65\x20\x69\x6e\x69\x74\x69\x61\x6c\x20\x73\x74\x61\x74\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_16_consts_6_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_16_consts_6_name = {
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
        uint8_t _data[25];
    }
toplevel_consts_16_consts_6_qualname = {
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
    ._data = "IncrementalEncoder.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_16_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x06\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_16_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01",
};
static struct PyCodeObject toplevel_consts_16_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 203,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[59];
    }
toplevel_consts_16_consts_7_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 58,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_16_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_consts_7_name = {
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
    ._data = "getstate",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_16_consts_7_qualname = {
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
    ._data = "IncrementalEncoder.getstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_16_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x11\x10\x11",
};
static struct PyCodeObject toplevel_consts_16_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 208,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[109];
    }
toplevel_consts_16_consts_8_consts_0 = {
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
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x53\x65\x74\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x72\x2e\x20\x73\x74\x61\x74\x65\x20\x6d\x75\x73\x74\x20\x68\x61\x76\x65\x20\x62\x65\x65\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x62\x79\x20\x67\x65\x74\x73\x74\x61\x74\x65\x28\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_16_consts_8_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_16_consts_8_varnames_1 = {
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
    ._data = "state",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_16_consts_8_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_consts_8_name = {
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
    ._data = "setstate",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_16_consts_8_qualname = {
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
    ._data = "IncrementalEncoder.setstate",
};
static struct PyCodeObject toplevel_consts_16_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 214,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_16_consts_11 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            Py_False,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_16_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_16_consts_1._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_16_consts_3.ob_base,
            Py_False,
            & toplevel_consts_16_consts_5.ob_base,
            & toplevel_consts_16_consts_6.ob_base,
            & toplevel_consts_16_consts_7.ob_base,
            & toplevel_consts_16_consts_8.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_16_consts_11._object.ob_base.ob_base,
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
toplevel_consts_16_names = {
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
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_7_name._ascii.ob_base,
            & toplevel_consts_16_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x05\x08\x0b\x06\x06\x06\x05\x0a\x06",
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
    .ob_sval = "\x0a\x00\x04\x05\x02\x01\x06\x09\x02\x02\x06\x04\x06\x05\x06\x06\x0a\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1f\x27\x05\x19\x05\x19\x05\x19\x23\x28\x05\x22\x05\x22\x05\x22\x05\x0c\x05\x0c\x05\x0c\x05\x11\x05\x11\x05\x11\x05\x0c\x05\x0c\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 180,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_20._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_20._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x0b\x64\x03\x84\x01\x5a\x04\x64\x04\x84\x00\x5a\x05\x64\x0c\x64\x06\x84\x01\x5a\x06\x64\x07\x84\x00\x5a\x07\x64\x08\x84\x00\x5a\x08\x64\x09\x84\x00\x5a\x09\x64\x0a\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_18_consts_0 = {
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
    ._data = "BufferedIncrementalEncoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[193];
    }
toplevel_consts_18_consts_1 = {
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
    ._data = "\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x20\x6f\x66\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x20\x63\x61\x6e\x20\x62\x65\x20\x75\x73\x65\x64\x20\x61\x73\x20\x74\x68\x65\x20\x62\x61\x73\x65\x63\x6c\x61\x73\x73\x20\x66\x6f\x72\x20\x61\x6e\x0a\x20\x20\x20\x20\x69\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x20\x65\x6e\x63\x6f\x64\x65\x72\x20\x69\x66\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x65\x72\x20\x6d\x75\x73\x74\x20\x6b\x65\x65\x70\x20\x73\x6f\x6d\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x6f\x75\x74\x70\x75\x74\x20\x69\x6e\x20\x61\x0a\x20\x20\x20\x20\x62\x75\x66\x66\x65\x72\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x63\x61\x6c\x6c\x73\x20\x74\x6f\x20\x65\x6e\x63\x6f\x64\x65\x28\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_18_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x00\x7c\x01\xa8\x02\xa9\x02\x01\x00\x64\x01\x7c\x00\x5f\x02\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_18_consts_3_consts = {
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
            & toplevel_consts_16_consts_3_consts_1._ascii.ob_base,
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
toplevel_consts_18_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_18_consts_3_qualname = {
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
    ._data = "BufferedIncrementalEncoder.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_18_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x01\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_18_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x1b\x09\x32\x25\x29\x2b\x31\x09\x32\x09\x32\x09\x32\x17\x19\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_18_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 226,
    .co_code = & toplevel_consts_18_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_18_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_16_consts_5_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_18_consts_4_name = {
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
    ._data = "_buffer_encode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_18_consts_4_qualname = {
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
    ._data = "BufferedIncrementalEncoder._buffer_encode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_18_consts_4_linetable = {
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
        char ob_sval[5];
    }
toplevel_consts_18_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_18_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 231,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_18_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_18_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7c\x01\x7a\x00\x7d\x03\x7c\x00\xa0\x01\x7c\x03\x7c\x00\x6a\x02\x7c\x02\xa8\x03\xa9\x03\x5c\x02\x7d\x04\x7d\x05\x7c\x03\x7c\x05\x64\x00\x85\x02\x19\x00\x7c\x00\x5f\x00\x7c\x04\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_18_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_18_consts_4_name._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_consts_6_varnames_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_18_consts_6_varnames_4 = {
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
    ._data = "result",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_18_consts_6_varnames_5 = {
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
    ._data = "consumed",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_18_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_16_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_4._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_18_consts_6_qualname = {
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
    ._data = "BufferedIncrementalEncoder.encode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_18_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x16\x01\x0e\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_18_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x1e\x23\x10\x23\x09\x0d\x1e\x22\x1e\x4b\x32\x36\x38\x3c\x38\x43\x45\x4a\x1e\x4b\x1e\x4b\x09\x1b\x0a\x10\x12\x1a\x17\x1b\x1c\x24\x1c\x25\x1c\x25\x17\x26\x09\x0d\x09\x14\x10\x16\x09\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_18_consts_6_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_18_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 236,
    .co_code = & toplevel_consts_18_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_32._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_18_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x00\xa8\x01\xa9\x01\x01\x00\x64\x01\x7c\x00\x5f\x02\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_18_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_18_consts_7_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 32,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "BufferedIncrementalEncoder.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_18_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_18_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x1b\x09\x27\x22\x26\x09\x27\x09\x27\x09\x27\x17\x19\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_18_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 244,
    .co_code = & toplevel_consts_18_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_18_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x70\x05\x64\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_18_consts_8_consts = {
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
            & toplevel_consts_1.ob_base.ob_base,
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
toplevel_consts_18_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_18_consts_8_qualname = {
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
    ._data = "BufferedIncrementalEncoder.getstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_18_consts_8_linetable = {
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
toplevel_consts_18_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x20\x1f\x20\x09\x20",
};
static struct PyCodeObject toplevel_consts_18_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 248,
    .co_code = & toplevel_consts_18_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_18_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x70\x04\x64\x01\x7c\x00\x5f\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_18_consts_9_qualname = {
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
    ._data = "BufferedIncrementalEncoder.setstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_18_consts_9_linetable = {
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
toplevel_consts_18_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1c\x17\x22\x20\x22\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_18_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 251,
    .co_code = & toplevel_consts_18_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_18_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_18_consts_1._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3.ob_base,
            & toplevel_consts_18_consts_4.ob_base,
            Py_False,
            & toplevel_consts_18_consts_6.ob_base,
            & toplevel_consts_18_consts_7.ob_base,
            & toplevel_consts_18_consts_8.ob_base,
            & toplevel_consts_18_consts_9.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_16_consts_11._object.ob_base.ob_base,
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
toplevel_consts_18_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_18_consts_4_name._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_7_name._ascii.ob_base,
            & toplevel_consts_16_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x05\x06\x05\x08\x05\x06\x08\x06\x04\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_18_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x05\x02\x01\x06\x03\x06\x05\x02\x02\x06\x06\x06\x04\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1f\x27\x05\x19\x05\x19\x05\x19\x05\x22\x05\x22\x05\x22\x23\x28\x05\x16\x05\x16\x05\x16\x05\x19\x05\x19\x05\x19\x05\x20\x05\x20\x05\x20\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 220,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_18_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[233];
    }
toplevel_consts_20_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 232,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x41\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x20\x64\x65\x63\x6f\x64\x65\x73\x20\x61\x6e\x20\x69\x6e\x70\x75\x74\x20\x69\x6e\x20\x6d\x75\x6c\x74\x69\x70\x6c\x65\x20\x73\x74\x65\x70\x73\x2e\x20\x54\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x63\x61\x6e\x0a\x20\x20\x20\x20\x62\x65\x20\x70\x61\x73\x73\x65\x64\x20\x70\x69\x65\x63\x65\x20\x62\x79\x20\x70\x69\x65\x63\x65\x20\x74\x6f\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x2e\x20\x54\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x72\x65\x6d\x65\x6d\x62\x65\x72\x73\x20\x74\x68\x65\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x70\x72\x6f\x63\x65\x73\x73\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x63\x61\x6c\x6c\x73\x20\x74\x6f\x20\x64\x65\x63\x6f\x64\x65\x28\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_20_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[244];
    }
toplevel_consts_20_consts_3_consts_0 = {
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
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x43\x72\x65\x61\x74\x65\x20\x61\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x20\x6d\x61\x79\x20\x75\x73\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x73\x63\x68\x65\x6d\x65\x73\x20\x62\x79\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x73\x20\x6b\x65\x79\x77\x6f\x72\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x20\x53\x65\x65\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x64\x6f\x63\x73\x74\x72\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x20\x76\x61\x6c\x75\x65\x73\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_20_consts_3_consts_0._ascii.ob_base,
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
toplevel_consts_20_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_20_consts_3_qualname = {
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
    ._data = "IncrementalDecoder.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_20_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_20_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_20_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 260,
    .co_code = & toplevel_consts_20_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[65];
    }
toplevel_consts_20_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 64,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x44\x65\x63\x6f\x64\x65\x20\x69\x6e\x70\x75\x74\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_20_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_20_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_20_consts_5_qualname = {
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
    ._data = "IncrementalDecoder.decode",
};
static struct PyCodeObject toplevel_consts_20_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 270,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_33._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[58];
    }
toplevel_consts_20_consts_6_consts_0 = {
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
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x73\x65\x74\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x74\x6f\x20\x74\x68\x65\x20\x69\x6e\x69\x74\x69\x61\x6c\x20\x73\x74\x61\x74\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_20_consts_6_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_20_consts_6_qualname = {
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
    ._data = "IncrementalDecoder.reset",
};
static struct PyCodeObject toplevel_consts_20_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 276,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[522];
    }
toplevel_consts_20_consts_7_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 521,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x28\x62\x75\x66\x66\x65\x72\x65\x64\x5f\x69\x6e\x70\x75\x74\x2c\x20\x61\x64\x64\x69\x74\x69\x6f\x6e\x61\x6c\x5f\x73\x74\x61\x74\x65\x5f\x69\x6e\x66\x6f\x29\x20\x74\x75\x70\x6c\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x62\x75\x66\x66\x65\x72\x65\x64\x5f\x69\x6e\x70\x75\x74\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x62\x79\x74\x65\x73\x20\x6f\x62\x6a\x65\x63\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x69\x6e\x67\x20\x62\x79\x74\x65\x73\x20\x74\x68\x61\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x77\x65\x72\x65\x20\x70\x61\x73\x73\x65\x64\x20\x74\x6f\x20\x64\x65\x63\x6f\x64\x65\x28\x29\x20\x74\x68\x61\x74\x20\x68\x61\x76\x65\x20\x6e\x6f\x74\x20\x79\x65\x74\x20\x62\x65\x65\x6e\x20\x63\x6f\x6e\x76\x65\x72\x74\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x64\x64\x69\x74\x69\x6f\x6e\x61\x6c\x5f\x73\x74\x61\x74\x65\x5f\x69\x6e\x66\x6f\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x6e\x6f\x6e\x2d\x6e\x65\x67\x61\x74\x69\x76\x65\x20\x69\x6e\x74\x65\x67\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x69\x6e\x67\x20\x74\x68\x65\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x57\x49\x54\x48\x4f\x55\x54\x20\x79\x65\x74\x20\x68\x61\x76\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x6f\x63\x65\x73\x73\x65\x64\x20\x74\x68\x65\x20\x63\x6f\x6e\x74\x65\x6e\x74\x73\x20\x6f\x66\x20\x62\x75\x66\x66\x65\x72\x65\x64\x5f\x69\x6e\x70\x75\x74\x2e\x20\x20\x49\x6e\x20\x74\x68\x65\x20\x69\x6e\x69\x74\x69\x61\x6c\x20\x73\x74\x61\x74\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x61\x66\x74\x65\x72\x20\x72\x65\x73\x65\x74\x28\x29\x2c\x20\x67\x65\x74\x73\x74\x61\x74\x65\x28\x29\x20\x6d\x75\x73\x74\x20\x72\x65\x74\x75\x72\x6e\x20\x28\x62\x22\x22\x2c\x20\x30\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts_7_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
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
toplevel_consts_20_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_20_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_20_consts_7_consts_1._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_20_consts_7_qualname = {
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
    ._data = "IncrementalDecoder.getstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_20_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_20_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x18\x10\x18",
};
static struct PyCodeObject toplevel_consts_20_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 281,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[183];
    }
toplevel_consts_20_consts_8_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 182,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x53\x65\x74\x20\x74\x68\x65\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x73\x74\x61\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x61\x74\x65\x20\x6d\x75\x73\x74\x20\x68\x61\x76\x65\x20\x62\x65\x65\x6e\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x62\x79\x20\x67\x65\x74\x73\x74\x61\x74\x65\x28\x29\x2e\x20\x20\x54\x68\x65\x20\x65\x66\x66\x65\x63\x74\x20\x6f\x66\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x73\x65\x74\x73\x74\x61\x74\x65\x28\x28\x62\x22\x22\x2c\x20\x30\x29\x29\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x65\x71\x75\x69\x76\x61\x6c\x65\x6e\x74\x20\x74\x6f\x20\x72\x65\x73\x65\x74\x28\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_20_consts_8_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_20_consts_8_qualname = {
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
    ._data = "IncrementalDecoder.setstate",
};
static struct PyCodeObject toplevel_consts_20_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 295,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_20_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_20_consts_1._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_20_consts_3.ob_base,
            Py_False,
            & toplevel_consts_20_consts_5.ob_base,
            & toplevel_consts_20_consts_6.ob_base,
            & toplevel_consts_20_consts_7.ob_base,
            & toplevel_consts_20_consts_8.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_16_consts_11._object.ob_base.ob_base,
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
toplevel_consts_20_names = {
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
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_7_name._ascii.ob_base,
            & toplevel_consts_16_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x05\x08\x0a\x06\x06\x06\x05\x0a\x0e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_20_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x05\x02\x01\x06\x08\x02\x02\x06\x04\x06\x05\x06\x0e\x0a\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1f\x27\x05\x1d\x05\x1d\x05\x1d\x23\x28\x05\x22\x05\x22\x05\x22\x05\x0c\x05\x0c\x05\x0c\x05\x18\x05\x18\x05\x18\x05\x0c\x05\x0c\x05\x0c\x05\x0c\x05\x0c",
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 254,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_22_consts_0 = {
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
    ._data = "BufferedIncrementalDecoder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[175];
    }
toplevel_consts_22_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 174,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x20\x6f\x66\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x20\x63\x61\x6e\x20\x62\x65\x20\x75\x73\x65\x64\x20\x61\x73\x20\x74\x68\x65\x20\x62\x61\x73\x65\x63\x6c\x61\x73\x73\x20\x66\x6f\x72\x20\x61\x6e\x0a\x20\x20\x20\x20\x69\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x69\x66\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x68\x61\x6e\x64\x6c\x65\x20\x69\x6e\x63\x6f\x6d\x70\x6c\x65\x74\x65\x0a\x20\x20\x20\x20\x62\x79\x74\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_consts_3_consts = {
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
            & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
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
toplevel_consts_22_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_22_consts_3_qualname = {
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
    ._data = "BufferedIncrementalDecoder.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_22_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x1b\x09\x32\x25\x29\x2b\x31\x09\x32\x09\x32\x09\x32\x17\x1a\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_22_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 309,
    .co_code = & toplevel_consts_18_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_22_consts_4_name = {
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
    ._data = "_buffer_decode",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_22_consts_4_qualname = {
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
    ._data = "BufferedIncrementalDecoder._buffer_decode",
};
static struct PyCodeObject toplevel_consts_22_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 314,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_22_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_22_consts_6_qualname = {
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
    ._data = "BufferedIncrementalDecoder.decode",
};
static struct PyCodeObject toplevel_consts_22_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 319,
    .co_code = & toplevel_consts_18_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_33._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_22_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_22_consts_7_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 32,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "BufferedIncrementalDecoder.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_22_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x1b\x09\x27\x22\x26\x09\x27\x09\x27\x09\x27\x17\x1a\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_22_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 327,
    .co_code = & toplevel_consts_18_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_22_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x64\x01\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_22_consts_8_qualname = {
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
    ._data = "BufferedIncrementalDecoder.getstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_22_consts_8_linetable = {
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
toplevel_consts_22_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x15\x11\x1c\x1e\x1f\x10\x20\x09\x20",
};
static struct PyCodeObject toplevel_consts_22_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 331,
    .co_code = & toplevel_consts_22_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x64\x01\x19\x00\x7c\x00\x5f\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[36];
    }
toplevel_consts_22_consts_9_qualname = {
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
    ._data = "BufferedIncrementalDecoder.setstate",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_22_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1c\x1d\x1e\x17\x1f\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_22_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 335,
    .co_code = & toplevel_consts_22_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_22_consts_0._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_22_consts_3.ob_base,
            & toplevel_consts_22_consts_4.ob_base,
            Py_False,
            & toplevel_consts_22_consts_6.ob_base,
            & toplevel_consts_22_consts_7.ob_base,
            & toplevel_consts_22_consts_8.ob_base,
            & toplevel_consts_22_consts_9.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_16_consts_11._object.ob_base.ob_base,
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
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_16_consts_7_name._ascii.ob_base,
            & toplevel_consts_16_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x05\x06\x05\x08\x05\x06\x08\x06\x04\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x05\x02\x01\x06\x03\x06\x05\x02\x02\x06\x06\x06\x04\x06\x04\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1f\x27\x05\x1a\x05\x1a\x05\x1a\x05\x22\x05\x22\x05\x22\x23\x28\x05\x16\x05\x16\x05\x16\x05\x1a\x05\x1a\x05\x1a\x05\x20\x05\x20\x05\x20\x05\x1f\x05\x1f\x05\x1f\x05\x1f\x05\x1f",
};
static struct PyCodeObject toplevel_consts_22 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 303,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_24_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x0c\x64\x02\x84\x01\x5a\x03\x64\x03\x84\x00\x5a\x04\x64\x04\x84\x00\x5a\x05\x64\x05\x84\x00\x5a\x06\x64\x0d\x64\x07\x84\x01\x5a\x07\x65\x08\x66\x01\x64\x08\x84\x01\x5a\x09\x64\x09\x84\x00\x5a\x0a\x64\x0a\x84\x00\x5a\x0b\x64\x0b\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_24_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[888];
    }
toplevel_consts_24_consts_2_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 887,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x65\x61\x6d\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x66\x69\x6c\x65\x2d\x6c\x69\x6b\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x6f\x70\x65\x6e\x20\x66\x6f\x72\x20\x77\x72\x69\x74\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x6d\x61\x79\x20\x75\x73\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x63\x68\x65\x6d\x65\x73\x20\x62\x79\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x73\x20\x6b\x65\x79\x77\x6f\x72\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x20\x54\x68\x65\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x73\x20\x61\x72\x65\x20\x70\x72\x65\x64\x65\x66\x69\x6e\x65\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x2d\x20\x72\x61\x69\x73\x65\x20\x61\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x28\x6f\x72\x20\x61\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x69\x67\x6e\x6f\x72\x65\x27\x20\x2d\x20\x69\x67\x6e\x6f\x72\x65\x20\x74\x68\x65\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x61\x6e\x64\x20\x63\x6f\x6e\x74\x69\x6e\x75\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x6e\x65\x78\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x72\x65\x70\x6c\x61\x63\x65\x27\x2d\x20\x72\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x61\x20\x73\x75\x69\x74\x61\x62\x6c\x65\x20\x72\x65\x70\x6c\x61\x63\x65\x6d\x65\x6e\x74\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x78\x6d\x6c\x63\x68\x61\x72\x72\x65\x66\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x61\x70\x70\x72\x6f\x70\x72\x69\x61\x74\x65\x20\x58\x4d\x4c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x65\x64\x20\x65\x73\x63\x61\x70\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x6e\x61\x6d\x65\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x20\x20\x20\x20\x20\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x5c\x4e\x7b\x2e\x2e\x2e\x7d\x20\x65\x73\x63\x61\x70\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x73\x65\x74\x20\x6f\x66\x20\x61\x6c\x6c\x6f\x77\x65\x64\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x20\x76\x61\x6c\x75\x65\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x65\x78\x74\x65\x6e\x64\x65\x64\x20\x76\x69\x61\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x67\x69\x73\x74\x65\x72\x5f\x65\x72\x72\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_2_names_0 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
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
toplevel_consts_24_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_24_consts_2_qualname = {
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
    ._data = "StreamWriter.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_24_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x16\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_24_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_24_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 348,
    .co_code = & toplevel_consts_24_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_24_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\x7c\x00\x6a\x01\xa8\x02\xa9\x02\x5c\x02\x7d\x02\x7d\x03\x7c\x00\x6a\x02\xa0\x03\x7c\x02\xa8\x01\xa9\x01\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[63];
    }
toplevel_consts_24_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 62,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x57\x72\x69\x74\x65\x73\x20\x74\x68\x65\x20\x6f\x62\x6a\x65\x63\x74\x27\x73\x20\x63\x6f\x6e\x74\x65\x6e\x74\x73\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x74\x6f\x20\x73\x65\x6c\x66\x2e\x73\x74\x72\x65\x61\x6d\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_3_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_consts_3_names_3 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_24_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_3_varnames_1 = {
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
    ._data = "object",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_24_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_24_consts_3_qualname = {
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
    ._data = "StreamWriter.write",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_24_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x14\x04\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_24_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1a\x1e\x1a\x3a\x26\x2c\x2e\x32\x2e\x39\x1a\x3a\x1a\x3a\x09\x17\x09\x0d\x0f\x17\x09\x0d\x09\x14\x09\x20\x1b\x1f\x09\x20\x09\x20\x09\x20\x09\x20\x09\x20",
};
static struct PyCodeObject toplevel_consts_24_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 373,
    .co_code = & toplevel_consts_24_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_24_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa0\x01\x7c\x01\xa8\x01\xa9\x01\xa8\x01\xa9\x01\x01\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[92];
    }
toplevel_consts_24_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 91,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x57\x72\x69\x74\x65\x73\x20\x74\x68\x65\x20\x63\x6f\x6e\x63\x61\x74\x65\x6e\x61\x74\x65\x64\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x73\x74\x72\x69\x6e\x67\x73\x20\x74\x6f\x20\x74\x68\x65\x20\x73\x74\x72\x65\x61\x6d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x75\x73\x69\x6e\x67\x20\x2e\x77\x72\x69\x74\x65\x28\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_24_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_24_consts_4_consts_0._ascii.ob_base,
            & toplevel_consts_16_consts_3_consts_1._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_consts_4_names_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_24_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_consts_4_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_24_consts_4_name = {
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
    ._data = "writelines",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_24_consts_4_qualname = {
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
    ._data = "StreamWriter.writelines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x18\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_24_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x22\x14\x16\x14\x21\x1c\x20\x14\x21\x14\x21\x09\x22\x09\x22\x09\x22\x09\x22\x09\x22",
};
static struct PyCodeObject toplevel_consts_24_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 380,
    .co_code = & toplevel_consts_24_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[307];
    }
toplevel_consts_24_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 306,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x73\x65\x74\x73\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x62\x75\x66\x66\x65\x72\x73\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x6b\x65\x65\x70\x69\x6e\x67\x20\x69\x6e\x74\x65\x72\x6e\x61\x6c\x20\x73\x74\x61\x74\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x43\x61\x6c\x6c\x69\x6e\x67\x20\x74\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x73\x68\x6f\x75\x6c\x64\x20\x65\x6e\x73\x75\x72\x65\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x64\x61\x74\x61\x20\x6f\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x75\x74\x70\x75\x74\x20\x69\x73\x20\x70\x75\x74\x20\x69\x6e\x74\x6f\x20\x61\x20\x63\x6c\x65\x61\x6e\x20\x73\x74\x61\x74\x65\x2c\x20\x74\x68\x61\x74\x20\x61\x6c\x6c\x6f\x77\x73\x20\x61\x70\x70\x65\x6e\x64\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x66\x20\x6e\x65\x77\x20\x66\x72\x65\x73\x68\x20\x64\x61\x74\x61\x20\x77\x69\x74\x68\x6f\x75\x74\x20\x68\x61\x76\x69\x6e\x67\x20\x74\x6f\x20\x72\x65\x73\x63\x61\x6e\x20\x74\x68\x65\x20\x77\x68\x6f\x6c\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x65\x61\x6d\x20\x74\x6f\x20\x72\x65\x63\x6f\x76\x65\x72\x20\x73\x74\x61\x74\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_5_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_24_consts_5_qualname = {
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
    ._data = "StreamWriter.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_24_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x0d",
};
static struct PyCodeObject toplevel_consts_24_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 387,
    .co_code = & toplevel_consts_16_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_24_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x01\x00\x7c\x02\x64\x01\x6b\x02\x72\x18\x7c\x01\x64\x01\x6b\x02\x72\x1a\x7c\x00\xa0\x02\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_consts_7_names_1 = {
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
    ._data = "seek",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_24_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_7_varnames_1 = {
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
    ._data = "offset",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_7_varnames_2 = {
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
    ._data = "whence",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_24_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_24_consts_7_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_24_consts_7_qualname = {
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
    ._data = "StreamWriter.seek",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_24_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x10\x01\x0e\x01\x08\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_24_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x06\x01\x02\x01\x06\xff\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_24_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x29\x1a\x20\x22\x28\x09\x29\x09\x29\x09\x29\x0c\x12\x16\x17\x0c\x17\x09\x19\x1c\x22\x26\x27\x1c\x27\x09\x19\x0d\x11\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x09\x19\x09\x19\x09\x19\x09\x19",
};
static struct PyCodeObject toplevel_consts_24_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 399,
    .co_code = & toplevel_consts_24_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_24_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x7c\x00\x6a\x00\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[64];
    }
toplevel_consts_24_consts_8_consts_0 = {
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
    ._data = "\x20\x49\x6e\x68\x65\x72\x69\x74\x20\x61\x6c\x6c\x20\x6f\x74\x68\x65\x72\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x75\x6e\x64\x65\x72\x6c\x79\x69\x6e\x67\x20\x73\x74\x72\x65\x61\x6d\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_24_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_24_consts_8_consts_0._ascii.ob_base,
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
toplevel_consts_24_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_24_consts_8_varnames_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_24_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_8_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_24_consts_8_name = {
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
        uint8_t _data[25];
    }
toplevel_consts_24_consts_8_qualname = {
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
    ._data = "StreamWriter.__getattr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_24_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x17\x18\x1c\x18\x23\x25\x29\x10\x2a\x09\x2a",
};
static struct PyCodeObject toplevel_consts_24_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 404,
    .co_code = & toplevel_consts_24_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_24_consts_9_code = {
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
toplevel_consts_24_consts_9_name = {
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
        uint8_t _data[23];
    }
toplevel_consts_24_consts_9_qualname = {
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
    ._data = "StreamWriter.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_9_linetable = {
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
toplevel_consts_24_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_24_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 411,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_24_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_consts_10_names_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_10_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_consts_10_varnames_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_consts_10_varnames_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_24_consts_10_varnames_3 = {
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
    ._data = "tb",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_24_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_10_varnames_1._ascii.ob_base,
            & toplevel_consts_24_consts_10_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_10_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_24_consts_10_name = {
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
        uint8_t _data[22];
    }
toplevel_consts_24_consts_10_qualname = {
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
    ._data = "StreamWriter.__exit__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_24_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_24_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 414,
    .co_code = & toplevel_consts_24_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_24_consts_13 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_5_23._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_24_consts_2.ob_base,
            & toplevel_consts_24_consts_3.ob_base,
            & toplevel_consts_24_consts_4.ob_base,
            & toplevel_consts_24_consts_5.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_24_consts_7.ob_base,
            & toplevel_consts_24_consts_8.ob_base,
            & toplevel_consts_24_consts_9.ob_base,
            & toplevel_consts_24_consts_10.ob_base,
            Py_None,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_24_consts_13._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_24_consts_4_name._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_8_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_8_name._ascii.ob_base,
            & toplevel_consts_24_consts_9_name._ascii.ob_base,
            & toplevel_consts_24_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_24_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x08\x02\x06\x19\x06\x07\x06\x07\x08\x0c\x02\x06\x08\xff\x06\x07\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_24_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x02\x02\x06\x17\x06\x07\x06\x07\x06\x0c\x02\x02\x06\x03\x02\x03\x08\x04\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_24_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x27\x2f\x05\x1d\x05\x1d\x05\x1d\x05\x20\x05\x20\x05\x20\x05\x22\x05\x22\x05\x22\x05\x0d\x05\x0d\x05\x0d\x23\x24\x05\x19\x05\x19\x05\x19\x1d\x24\x05\x2a\x05\x2a\x05\x2a\x05\x2a\x05\x14\x05\x14\x05\x14\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 346,
    .co_code = & toplevel_consts_24_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_23._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_23._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x65\x03\x5a\x04\x64\x13\x64\x02\x84\x01\x5a\x05\x64\x13\x64\x03\x84\x01\x5a\x06\x64\x14\x64\x06\x84\x01\x5a\x07\x64\x15\x64\x09\x84\x01\x5a\x08\x64\x15\x64\x0a\x84\x01\x5a\x09\x64\x0b\x84\x00\x5a\x0a\x64\x16\x64\x0d\x84\x01\x5a\x0b\x64\x0e\x84\x00\x5a\x0c\x64\x0f\x84\x00\x5a\x0d\x65\x0e\x66\x01\x64\x10\x84\x01\x5a\x0f\x64\x11\x84\x00\x5a\x10\x64\x12\x84\x00\x5a\x11\x64\x07\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_26_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x64\x01\x7c\x00\x5f\x02\x7c\x00\xa0\x03\xa8\x00\xa9\x00\x7c\x00\x5f\x04\x7c\x00\x6a\x04\x7c\x00\x5f\x05\x64\x02\x7c\x00\x5f\x06\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[654];
    }
toplevel_consts_26_consts_2_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 653,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x65\x61\x6d\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x66\x69\x6c\x65\x2d\x6c\x69\x6b\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x6f\x70\x65\x6e\x20\x66\x6f\x72\x20\x72\x65\x61\x64\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x20\x6d\x61\x79\x20\x75\x73\x65\x20\x64\x69\x66\x66\x65\x72\x65\x6e\x74\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x63\x68\x65\x6d\x65\x73\x20\x62\x79\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x73\x20\x6b\x65\x79\x77\x6f\x72\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x20\x54\x68\x65\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x73\x20\x61\x72\x65\x20\x70\x72\x65\x64\x65\x66\x69\x6e\x65\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x2d\x20\x72\x61\x69\x73\x65\x20\x61\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x28\x6f\x72\x20\x61\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x69\x67\x6e\x6f\x72\x65\x27\x20\x2d\x20\x69\x67\x6e\x6f\x72\x65\x20\x74\x68\x65\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x61\x6e\x64\x20\x63\x6f\x6e\x74\x69\x6e\x75\x65\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x6e\x65\x78\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x72\x65\x70\x6c\x61\x63\x65\x27\x2d\x20\x72\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x61\x20\x73\x75\x69\x74\x61\x62\x6c\x65\x20\x72\x65\x70\x6c\x61\x63\x65\x6d\x65\x6e\x74\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x27\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x72\x65\x70\x6c\x61\x63\x65\x27\x20\x2d\x20\x52\x65\x70\x6c\x61\x63\x65\x20\x77\x69\x74\x68\x20\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x65\x64\x20\x65\x73\x63\x61\x70\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x3b\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x73\x65\x74\x20\x6f\x66\x20\x61\x6c\x6c\x6f\x77\x65\x64\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x20\x76\x61\x6c\x75\x65\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x65\x78\x74\x65\x6e\x64\x65\x64\x20\x76\x69\x61\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x67\x69\x73\x74\x65\x72\x5f\x65\x72\x72\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_26_consts_2_names_2 = {
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
    ._data = "bytebuffer",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_26_consts_2_names_3 = {
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
    ._data = "charbuffertype",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_26_consts_2_names_4 = {
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
    ._data = "_empty_charbuffer",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_26_consts_2_names_5 = {
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
    ._data = "charbuffer",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_26_consts_2_names_6 = {
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
    ._data = "linebuffer",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_26_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_26_consts_2_qualname = {
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
    ._data = "StreamReader.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_26_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x12\x06\x01\x06\x01\x0c\x01\x08\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_26_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x1b\x1e\x09\x0d\x09\x18\x22\x26\x22\x37\x22\x37\x22\x37\x09\x0d\x09\x1f\x1b\x1f\x1b\x31\x09\x0d\x09\x18\x1b\x1f\x09\x0d\x09\x18\x09\x18\x09\x18",
};
static struct PyCodeObject toplevel_consts_26_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 423,
    .co_code = & toplevel_consts_26_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_26_consts_3_qualname = {
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
    ._data = "StreamReader.decode",
};
static struct PyCodeObject toplevel_consts_26_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 448,
    .co_code = & toplevel_consts_14_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_33._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_4 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[343];
    }
toplevel_consts_26_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 342,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x72\x10\x7c\x00\x6a\x01\xa0\x02\x7c\x00\x6a\x00\xa8\x01\xa9\x01\x7c\x00\x5f\x03\x64\x01\x7c\x00\x5f\x00\x7c\x02\x64\x02\x6b\x00\x72\x16\x7c\x01\x7d\x02\x09\x00\x7c\x02\x64\x02\x6b\x05\x72\x23\x74\x04\x7c\x00\x6a\x03\xa9\x01\x7c\x02\x6b\x05\x72\x23\x6e\x6a\x7c\x01\x64\x02\x6b\x00\x72\x2e\x7c\x00\x6a\x05\xa0\x06\xa8\x00\xa9\x00\x7d\x04\x6e\x07\x7c\x00\x6a\x05\xa0\x06\x7c\x01\xa8\x01\xa9\x01\x7d\x04\x7c\x00\x6a\x07\x7c\x04\x7a\x00\x7d\x05\x7c\x05\x73\x3d\x6e\x50\x09\x00\x7c\x00\xa0\x08\x7c\x05\x7c\x00\x6a\x09\xa8\x02\xa9\x02\x5c\x02\x7d\x06\x7d\x07\x6e\x32\x23\x00\x74\x0a\x79\x77\x7d\x08\x7c\x03\x72\x6d\x7c\x00\xa0\x08\x7c\x05\x64\x01\x7c\x08\x6a\x0b\x85\x02\x19\x00\x7c\x00\x6a\x09\xa8\x02\xa9\x02\x5c\x02\x7d\x06\x7d\x07\x7c\x06\xa0\x0c\x64\x03\x64\x04\xa8\x02\xaa\x01\x7d\x09\x74\x04\x7c\x09\xa9\x01\x64\x05\x6b\x01\x72\x6c\x82\x00\x6e\x01\x82\x00\x59\x00\x64\x01\x7d\x08\x7e\x08\x6e\x08\x64\x01\x7d\x08\x7e\x08\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x7c\x07\x64\x01\x85\x02\x19\x00\x7c\x00\x5f\x07\x7c\x00\x04\x00\x6a\x03\x7c\x06\x7a\x0d\x02\x00\x5f\x03\x7c\x04\x73\x8c\x6e\x01\x71\x17\x7c\x02\x64\x02\x6b\x00\x72\x9a\x7c\x00\x6a\x03\x7d\x0a\x7c\x00\x6a\x01\x7c\x00\x5f\x03\x7c\x0a\x53\x00\x7c\x00\x6a\x03\x64\x01\x7c\x02\x85\x02\x19\x00\x7d\x0a\x7c\x00\x6a\x03\x7c\x02\x64\x01\x85\x02\x19\x00\x7c\x00\x5f\x03\x7c\x0a\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1261];
    }
toplevel_consts_26_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1260,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x44\x65\x63\x6f\x64\x65\x73\x20\x64\x61\x74\x61\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x73\x74\x72\x65\x61\x6d\x20\x73\x65\x6c\x66\x2e\x73\x74\x72\x65\x61\x6d\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x68\x61\x72\x73\x20\x69\x6e\x64\x69\x63\x61\x74\x65\x73\x20\x74\x68\x65\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x64\x65\x63\x6f\x64\x65\x64\x20\x63\x6f\x64\x65\x20\x70\x6f\x69\x6e\x74\x73\x20\x6f\x72\x20\x62\x79\x74\x65\x73\x20\x74\x6f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x2e\x20\x72\x65\x61\x64\x28\x29\x20\x77\x69\x6c\x6c\x20\x6e\x65\x76\x65\x72\x20\x72\x65\x74\x75\x72\x6e\x20\x6d\x6f\x72\x65\x20\x64\x61\x74\x61\x20\x74\x68\x61\x6e\x20\x72\x65\x71\x75\x65\x73\x74\x65\x64\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x75\x74\x20\x69\x74\x20\x6d\x69\x67\x68\x74\x20\x72\x65\x74\x75\x72\x6e\x20\x6c\x65\x73\x73\x2c\x20\x69\x66\x20\x74\x68\x65\x72\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x65\x6e\x6f\x75\x67\x68\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x69\x7a\x65\x20\x69\x6e\x64\x69\x63\x61\x74\x65\x73\x20\x74\x68\x65\x20\x61\x70\x70\x72\x6f\x78\x69\x6d\x61\x74\x65\x20\x6d\x61\x78\x69\x6d\x75\x6d\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x64\x65\x63\x6f\x64\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x62\x79\x74\x65\x73\x20\x6f\x72\x20\x63\x6f\x64\x65\x20\x70\x6f\x69\x6e\x74\x73\x20\x74\x6f\x20\x72\x65\x61\x64\x20\x66\x6f\x72\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x2e\x20\x54\x68\x65\x20\x64\x65\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x61\x6e\x20\x6d\x6f\x64\x69\x66\x79\x20\x74\x68\x69\x73\x20\x73\x65\x74\x74\x69\x6e\x67\x20\x61\x73\x20\x61\x70\x70\x72\x6f\x70\x72\x69\x61\x74\x65\x2e\x20\x54\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x76\x61\x6c\x75\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2d\x31\x20\x69\x6e\x64\x69\x63\x61\x74\x65\x73\x20\x74\x6f\x20\x72\x65\x61\x64\x20\x61\x6e\x64\x20\x64\x65\x63\x6f\x64\x65\x20\x61\x73\x20\x6d\x75\x63\x68\x20\x61\x73\x20\x70\x6f\x73\x73\x69\x62\x6c\x65\x2e\x20\x20\x73\x69\x7a\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x69\x73\x20\x69\x6e\x74\x65\x6e\x64\x65\x64\x20\x74\x6f\x20\x70\x72\x65\x76\x65\x6e\x74\x20\x68\x61\x76\x69\x6e\x67\x20\x74\x6f\x20\x64\x65\x63\x6f\x64\x65\x20\x68\x75\x67\x65\x20\x66\x69\x6c\x65\x73\x20\x69\x6e\x20\x6f\x6e\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x65\x70\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x66\x69\x72\x73\x74\x6c\x69\x6e\x65\x20\x69\x73\x20\x74\x72\x75\x65\x2c\x20\x61\x6e\x64\x20\x61\x20\x55\x6e\x69\x63\x6f\x64\x65\x44\x65\x63\x6f\x64\x65\x45\x72\x72\x6f\x72\x20\x68\x61\x70\x70\x65\x6e\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x66\x69\x72\x73\x74\x20\x6c\x69\x6e\x65\x20\x74\x65\x72\x6d\x69\x6e\x61\x74\x6f\x72\x20\x69\x6e\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x6f\x6e\x6c\x79\x20\x74\x68\x65\x20\x66\x69\x72\x73\x74\x20\x6c\x69\x6e\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x2c\x20\x74\x68\x65\x20\x72\x65\x73\x74\x20\x6f\x66\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x6b\x65\x70\x74\x20\x75\x6e\x74\x69\x6c\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6e\x65\x78\x74\x20\x63\x61\x6c\x6c\x20\x74\x6f\x20\x72\x65\x61\x64\x28\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x20\x73\x68\x6f\x75\x6c\x64\x20\x75\x73\x65\x20\x61\x20\x67\x72\x65\x65\x64\x79\x20\x72\x65\x61\x64\x20\x73\x74\x72\x61\x74\x65\x67\x79\x2c\x20\x6d\x65\x61\x6e\x69\x6e\x67\x20\x74\x68\x61\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x72\x65\x61\x64\x20\x61\x73\x20\x6d\x75\x63\x68\x20\x64\x61\x74\x61\x20\x61\x73\x20\x69\x73\x20\x61\x6c\x6c\x6f\x77\x65\x64\x20\x77\x69\x74\x68\x69\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x69\x6e\x69\x74\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x73\x69\x7a\x65\x2c\x20\x65\x2e\x67\x2e\x20\x20\x69\x66\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x65\x6e\x64\x69\x6e\x67\x73\x20\x6f\x72\x20\x73\x74\x61\x74\x65\x20\x6d\x61\x72\x6b\x65\x72\x73\x20\x61\x72\x65\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x6e\x20\x74\x68\x65\x20\x73\x74\x72\x65\x61\x6d\x2c\x20\x74\x68\x65\x73\x65\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x72\x65\x61\x64\x20\x74\x6f\x6f\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_6_consts_4_0 = {
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
    ._data = "keepends",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_6_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_6_consts_5 = {
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
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_26_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
            Py_True,
            & toplevel_consts_26_consts_6_consts_4._object.ob_base.ob_base,
            & toplevel_consts_26_consts_6_consts_5.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_consts_6_names_4 = {
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
        uint8_t _data[5];
    }
toplevel_consts_26_consts_6_names_6 = {
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
    ._data = "read",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_26_consts_6_names_10 = {
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
    ._data = "UnicodeDecodeError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_consts_6_names_11 = {
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
        uint8_t _data[11];
    }
toplevel_consts_26_consts_6_names_12 = {
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
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_26_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_24_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_10._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_11._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_consts_6_varnames_1 = {
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
    ._data = "size",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_26_consts_6_varnames_2 = {
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
    ._data = "chars",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_consts_6_varnames_3 = {
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
    ._data = "firstline",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_consts_6_varnames_4 = {
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
    ._data = "newdata",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_6_varnames_6 = {
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
    ._data = "newchars",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26_consts_6_varnames_7 = {
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
    ._data = "decodedbytes",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_consts_6_varnames_8 = {
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
        uint8_t _data[6];
    }
toplevel_consts_26_consts_6_varnames_9 = {
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
    ._data = "lines",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_26_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_2._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_4._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_6._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_7._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_8._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_9._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_26_consts_6_qualname = {
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
    ._data = "StreamReader.read",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_26_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x1c\x12\x01\x06\x01\x08\x02\x04\x03\x02\x03\x08\x02\x0e\x01\x02\x01\x08\x02\x0e\x01\x0e\x02\x0a\x02\x04\x01\x02\x01\x02\x01\x16\x01\x02\x80\x06\x01\x04\x01\x18\x02\x06\xff\x0e\x02\x0c\x01\x02\x01\x02\xff\x02\x03\x0a\xfd\x08\x80\x02\xfb\x06\x80\x0e\x0a\x0e\x02\x04\x02\x02\x01\x02\xe1\x08\x20\x06\x02\x08\x01\x04\x05\x0e\xfe\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_26_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x1c\x02\x02\x12\xff\x06\x01\x06\x02\x06\x03\x02\x03\x06\x02\x02\x02\x0c\xff\x04\x01\x06\x02\x02\x03\x0e\xfe\x0e\x02\x0a\x02\x02\x01\x04\x01\x02\x0b\x16\xf7\x02\x80\x02\x01\x04\x08\x02\xf9\x02\x07\x18\xfb\x06\xff\x0e\x02\x0a\x01\x06\x01\x02\x02\x0a\xfe\x08\x80\x02\x02\x06\x80\x0e\x02\x0e\x02\x02\x02\x04\x01\x02\xe1\x06\x20\x02\x07\x06\xfb\x08\x01\x04\x05\x0e\xfe\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[343];
    }
toplevel_consts_26_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 342,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x1b\x09\x23\x1f\x23\x1f\x35\x1f\x4b\x3b\x3f\x3b\x4a\x1f\x4b\x1f\x4b\x0d\x11\x0d\x1c\x1f\x23\x0d\x11\x0d\x1c\x0c\x11\x14\x15\x0c\x15\x09\x19\x15\x19\x0d\x12\x0f\x13\x10\x15\x19\x1a\x10\x1a\x0d\x1a\x14\x17\x18\x1c\x18\x27\x14\x28\x2c\x31\x14\x31\x11\x1a\x15\x1a\x10\x14\x17\x18\x10\x18\x0d\x31\x1b\x1f\x1b\x26\x1b\x2d\x1b\x2d\x1b\x2d\x11\x18\x11\x18\x1b\x1f\x1b\x26\x1b\x31\x2c\x30\x1b\x31\x1b\x31\x11\x18\x14\x18\x14\x23\x26\x2d\x14\x2d\x0d\x11\x14\x18\x0d\x16\x11\x16\x0d\x1a\x2a\x2e\x2a\x48\x36\x3a\x3c\x40\x3c\x47\x2a\x48\x2a\x48\x11\x27\x11\x19\x1b\x27\x1b\x27\x00\x00\x14\x26\x0d\x1a\x0d\x1a\x14\x1d\x11\x1a\x19\x1d\x19\x43\x25\x29\x2a\x34\x2b\x2e\x2b\x34\x2a\x34\x25\x35\x37\x3b\x37\x42\x19\x43\x19\x43\x15\x2b\x15\x1d\x1f\x2b\x1d\x25\x1d\x3f\x3a\x3e\x1d\x3f\x1d\x3f\x1d\x3f\x15\x1a\x18\x1b\x1c\x21\x18\x22\x24\x25\x18\x25\x15\x1e\x19\x1e\x15\x1e\x15\x1a\x15\x1e\x15\x1e\x15\x1e\x15\x1e\x15\x1e\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x1a\x00\x00\x00\x00\x00\x00\x1f\x23\x24\x30\x24\x31\x24\x31\x1f\x32\x0d\x11\x0d\x1c\x0d\x11\x0d\x1c\x0d\x1c\x20\x28\x0d\x28\x0d\x1c\x0d\x1c\x14\x1b\x0d\x16\x11\x16\x0f\x13\x0c\x11\x14\x15\x0c\x15\x09\x36\x16\x1a\x16\x25\x0d\x13\x1f\x23\x1f\x35\x0d\x11\x0d\x1c\x10\x16\x09\x16\x16\x1a\x16\x25\x26\x2c\x27\x2c\x26\x2c\x16\x2d\x0d\x13\x1f\x23\x1f\x2e\x2f\x34\x2f\x35\x2f\x35\x1f\x36\x0d\x11\x0d\x1c\x10\x16\x09\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[24];
    }
toplevel_consts_26_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 23,
    },
    .ob_shash = -1,
    .ob_sval = "\xbe\x0a\x41\x09\x00\xc1\x09\x04\x41\x38\x03\xc1\x0d\x21\x41\x33\x03\xc1\x33\x05\x41\x38\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_26_consts_6_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_26_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_26_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 451,
    .co_code = & toplevel_consts_26_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 11,
    .co_nlocals = 11,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[475];
    }
toplevel_consts_26_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 474,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x72\x2a\x7c\x00\x6a\x00\x64\x01\x19\x00\x7d\x03\x7c\x00\x6a\x00\x64\x01\x3d\x00\x74\x01\x7c\x00\x6a\x00\xa9\x01\x64\x02\x6b\x02\x72\x1d\x7c\x00\x6a\x00\x64\x01\x19\x00\x7c\x00\x5f\x02\x64\x03\x7c\x00\x5f\x00\x7c\x02\x73\x28\x7c\x03\xa0\x03\x64\x04\x64\x05\xa8\x02\xaa\x01\x64\x01\x19\x00\x7d\x03\x7c\x03\x53\x00\x7c\x01\x70\x2d\x64\x06\x7d\x04\x7c\x00\x6a\x04\x7d\x03\x09\x00\x7c\x00\xa0\x05\x7c\x04\x64\x07\x64\x08\xa8\x03\xaa\x02\x7d\x05\x7c\x05\x72\x5c\x74\x06\x7c\x05\x74\x07\xa9\x02\x72\x47\x7c\x05\xa0\x08\x64\x09\xa8\x01\xa9\x01\x73\x52\x74\x06\x7c\x05\x74\x09\xa9\x02\x72\x5c\x7c\x05\xa0\x08\x64\x0a\xa8\x01\xa9\x01\x72\x5c\x7c\x05\x7c\x00\xa0\x05\x64\x02\x64\x02\x64\x0b\xa8\x03\xaa\x02\x7a\x0d\x7d\x05\x7c\x03\x7c\x05\x7a\x0d\x7d\x03\x7c\x03\xa0\x03\x64\x07\x64\x05\xa8\x02\xaa\x01\x7d\x06\x7c\x06\x72\xd0\x74\x01\x7c\x06\xa9\x01\x64\x02\x6b\x04\x72\xa2\x7c\x06\x64\x01\x19\x00\x7d\x03\x7c\x06\x64\x01\x3d\x00\x74\x01\x7c\x06\xa9\x01\x64\x02\x6b\x04\x72\x8c\x7c\x06\x64\x0c\x05\x00\x19\x00\x7c\x00\x6a\x02\x7a\x0d\x03\x00\x3c\x00\x7c\x06\x7c\x00\x5f\x00\x64\x03\x7c\x00\x5f\x02\x6e\x08\x7c\x06\x64\x01\x19\x00\x7c\x00\x6a\x02\x7a\x00\x7c\x00\x5f\x02\x7c\x02\x73\x9f\x7c\x03\xa0\x03\x64\x04\x64\x05\xa8\x02\xaa\x01\x64\x01\x19\x00\x7d\x03\x09\x00\x7c\x03\x53\x00\x7c\x06\x64\x01\x19\x00\x7d\x07\x7c\x06\x64\x01\x19\x00\xa0\x03\x64\x04\x64\x05\xa8\x02\xaa\x01\x64\x01\x19\x00\x7d\x08\x7c\x07\x7c\x08\x6b\x03\x72\xd0\x7c\x00\x6a\x04\xa0\x0a\x7c\x06\x64\x02\x64\x03\x85\x02\x19\x00\xa8\x01\xa9\x01\x7c\x00\x6a\x02\x7a\x00\x7c\x00\x5f\x02\x7c\x02\x72\xcb\x7c\x07\x7d\x03\x09\x00\x7c\x03\x53\x00\x7c\x08\x7d\x03\x09\x00\x7c\x03\x53\x00\x7c\x05\x72\xd4\x7c\x01\x81\xe4\x7c\x03\x72\xe1\x7c\x02\x73\xe1\x7c\x03\xa0\x03\x64\x04\x64\x05\xa8\x02\xaa\x01\x64\x01\x19\x00\x7d\x03\x09\x00\x7c\x03\x53\x00\x7c\x04\x64\x0d\x6b\x00\x72\xec\x7c\x04\x64\x0e\x7a\x12\x7d\x04\x71\x32",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[178];
    }
toplevel_consts_26_consts_9_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 177,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x61\x64\x20\x6f\x6e\x65\x20\x6c\x69\x6e\x65\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x73\x74\x72\x65\x61\x6d\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x63\x6f\x64\x65\x64\x20\x64\x61\x74\x61\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x69\x7a\x65\x2c\x20\x69\x66\x20\x67\x69\x76\x65\x6e\x2c\x20\x69\x73\x20\x70\x61\x73\x73\x65\x64\x20\x61\x73\x20\x73\x69\x7a\x65\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x74\x6f\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x61\x64\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_9_consts_6 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 72 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_9_consts_8 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_26_consts_9_consts_9 = {
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
    ._data = "\x0d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_26_consts_9_consts_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "\x0d",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_9_consts_11 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_9_consts_13 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 8000 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_26_consts_9_consts_14 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_26_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_26_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_26_consts_6_consts_5.ob_base.ob_base,
            Py_None,
            Py_False,
            & toplevel_consts_26_consts_6_consts_4._object.ob_base.ob_base,
            & toplevel_consts_26_consts_9_consts_6.ob_base.ob_base,
            Py_True,
            & toplevel_consts_26_consts_9_consts_8._object.ob_base.ob_base,
            & toplevel_consts_26_consts_9_consts_9._ascii.ob_base,
            & toplevel_consts_26_consts_9_consts_10.ob_base.ob_base,
            & toplevel_consts_26_consts_9_consts_11._object.ob_base.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            & toplevel_consts_26_consts_9_consts_13.ob_base.ob_base,
            & toplevel_consts_26_consts_9_consts_14.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_26_consts_9_names_6 = {
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
        uint8_t _data[4];
    }
toplevel_consts_26_consts_9_names_7 = {
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
toplevel_consts_26_consts_9_names_8 = {
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
        uint8_t _data[6];
    }
toplevel_consts_26_consts_9_names_9 = {
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
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_26_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_12._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_9_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_9_names_7._ascii.ob_base,
            & toplevel_consts_26_consts_9_names_8._ascii.ob_base,
            & toplevel_consts_26_consts_9_names_9._ascii.ob_base,
            & toplevel_consts_24_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_consts_9_varnames_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_26_consts_9_varnames_4 = {
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
    ._data = "readsize",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26_consts_9_varnames_7 = {
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
    ._data = "line0withend",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_26_consts_9_varnames_8 = {
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
    ._data = "line0withoutend",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_26_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_consts_4_0._ascii.ob_base,
            & toplevel_consts_26_consts_9_varnames_3._ascii.ob_base,
            & toplevel_consts_26_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_9_varnames_7._ascii.ob_base,
            & toplevel_consts_26_consts_9_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_9_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_26_consts_9_qualname = {
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
    ._data = "StreamReader.readline",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_26_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0b\x0a\x01\x08\x01\x0e\x01\x0c\x03\x06\x01\x04\x01\x12\x01\x04\x01\x08\x02\x06\x01\x02\x02\x10\x01\x04\x01\x16\x04\x08\x01\x02\xff\x0a\x01\x02\xff\x14\x02\x08\x02\x0e\x01\x04\x01\x0c\x01\x08\x03\x06\x01\x0c\x01\x12\x02\x06\x01\x08\x01\x10\x03\x04\x01\x12\x01\x02\x01\x04\x13\x08\xee\x16\x01\x08\x01\x14\x02\x04\x01\x06\xff\x04\x02\x04\x01\x02\x03\x04\x08\x04\xf7\x02\x01\x04\x08\x08\xfa\x08\x01\x12\x01\x02\x01\x04\x03\x08\xfe\x08\x01\x02\xd2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[145];
    }
toplevel_consts_26_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 144,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0b\x02\x0a\x0a\xf7\x08\x01\x0c\x01\x02\x04\x0c\xff\x06\x01\x02\x01\x14\x01\x04\x01\x08\x02\x06\x01\x02\x02\x10\x01\x02\x01\x02\x06\x08\xfe\x02\x02\x0a\xfe\x02\x02\x08\xff\x02\x01\x0a\xff\x16\x01\x08\x02\x0e\x01\x02\x01\x02\x1b\x0a\xe6\x02\x0f\x08\xf4\x06\x01\x0a\x01\x02\x07\x12\xfb\x06\x01\x08\x01\x10\x03\x02\x01\x14\x01\x02\x01\x04\x13\x08\xee\x16\x01\x06\x01\x02\x08\x14\xfa\x06\x01\x04\xff\x02\x02\x02\x03\x04\xfe\x02\x03\x04\x08\x04\xf7\x02\x01\x04\x08\x02\xfa\x02\x03\x02\xfd\x02\x03\x02\xfe\x02\x01\x02\xff\x14\x01\x02\x01\x04\x03\x06\xfe\x0a\x01\x02\xd2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[475];
    }
toplevel_consts_26_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 474,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x1b\x09\x18\x14\x18\x14\x23\x24\x25\x14\x26\x0d\x11\x11\x15\x11\x20\x21\x22\x11\x23\x10\x13\x14\x18\x14\x23\x10\x24\x28\x29\x10\x29\x0d\x27\x23\x27\x23\x32\x33\x34\x23\x35\x11\x15\x11\x20\x23\x27\x11\x15\x11\x20\x14\x1c\x0d\x3a\x18\x1c\x18\x37\x31\x36\x18\x37\x18\x37\x18\x37\x38\x39\x18\x3a\x11\x15\x14\x18\x0d\x18\x14\x18\x14\x1e\x1c\x1e\x09\x11\x10\x14\x10\x26\x09\x0d\x0f\x13\x14\x18\x14\x37\x1e\x26\x32\x36\x14\x37\x14\x37\x14\x37\x0d\x11\x10\x14\x0d\x37\x15\x1f\x20\x24\x26\x29\x15\x2a\x11\x37\x2f\x33\x2f\x42\x3d\x41\x2f\x42\x2f\x42\x11\x37\x15\x1f\x20\x24\x26\x2b\x15\x2c\x11\x37\x31\x35\x31\x45\x3f\x44\x31\x45\x31\x45\x11\x37\x15\x19\x1d\x21\x1d\x37\x2c\x2d\x35\x36\x1d\x37\x1d\x37\x1d\x37\x15\x37\x15\x19\x0d\x11\x15\x19\x0d\x19\x0d\x11\x15\x19\x15\x33\x2e\x32\x15\x33\x15\x33\x15\x33\x0d\x12\x10\x15\x0d\x1a\x14\x17\x18\x1d\x14\x1e\x21\x22\x14\x22\x11\x1a\x1c\x21\x22\x23\x1c\x24\x15\x19\x19\x1e\x1f\x20\x19\x21\x18\x1b\x1c\x21\x18\x22\x25\x26\x18\x26\x15\x45\x19\x1e\x1f\x21\x19\x22\x19\x22\x26\x2a\x26\x35\x19\x35\x19\x22\x19\x22\x2b\x30\x19\x1d\x19\x28\x2b\x2f\x19\x1d\x19\x28\x19\x28\x2b\x30\x31\x32\x2b\x33\x36\x3a\x36\x45\x2b\x45\x19\x1d\x19\x28\x1c\x24\x15\x42\x20\x24\x20\x3f\x39\x3e\x20\x3f\x20\x3f\x20\x3f\x40\x41\x20\x42\x19\x1d\x15\x1a\x10\x14\x09\x14\x20\x25\x26\x27\x20\x28\x11\x1d\x23\x28\x29\x2a\x23\x2b\x23\x46\x40\x45\x23\x46\x23\x46\x23\x46\x47\x48\x23\x49\x11\x20\x14\x20\x24\x33\x14\x33\x11\x1a\x27\x2b\x27\x3d\x27\x4d\x43\x48\x49\x4a\x49\x4b\x49\x4b\x43\x4c\x27\x4d\x27\x4d\x27\x2b\x27\x36\x27\x36\x15\x19\x15\x24\x18\x20\x15\x2f\x20\x2c\x19\x1d\x15\x1a\x10\x14\x09\x14\x20\x2f\x19\x1d\x15\x1a\x10\x14\x09\x14\x14\x18\x0d\x16\x1c\x20\x0d\x16\x14\x18\x11\x3e\x21\x29\x11\x3e\x1c\x20\x1c\x3b\x35\x3a\x1c\x3b\x1c\x3b\x1c\x3b\x3c\x3d\x1c\x3e\x15\x19\x11\x16\x10\x14\x09\x14\x10\x18\x1b\x1f\x10\x1f\x0d\x1e\x11\x19\x1d\x1e\x11\x1e\x11\x19\x0f\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_26_consts_9_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_26_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 531,
    .co_code = & toplevel_consts_26_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_consts_9_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x7d\x03\x7c\x03\xa0\x01\x7c\x02\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[340];
    }
toplevel_consts_26_consts_10_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 339,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x61\x64\x20\x61\x6c\x6c\x20\x6c\x69\x6e\x65\x73\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x20\x6f\x6e\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x73\x74\x72\x65\x61\x6d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x6d\x20\x61\x73\x20\x61\x20\x6c\x69\x73\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x4c\x69\x6e\x65\x20\x62\x72\x65\x61\x6b\x73\x20\x61\x72\x65\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x65\x64\x20\x75\x73\x69\x6e\x67\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x27\x73\x20\x64\x65\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x20\x61\x6e\x64\x20\x61\x72\x65\x20\x69\x6e\x63\x6c\x75\x64\x65\x64\x20\x69\x6e\x20\x74\x68\x65\x20\x6c\x69\x73\x74\x20\x65\x6e\x74\x72\x69\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x69\x7a\x65\x68\x69\x6e\x74\x2c\x20\x69\x66\x20\x67\x69\x76\x65\x6e\x2c\x20\x69\x73\x20\x69\x67\x6e\x6f\x72\x65\x64\x20\x73\x69\x6e\x63\x65\x20\x74\x68\x65\x72\x65\x20\x69\x73\x20\x6e\x6f\x20\x65\x66\x66\x69\x63\x69\x65\x6e\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x77\x61\x79\x20\x74\x6f\x20\x66\x69\x6e\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x74\x72\x75\x65\x20\x65\x6e\x64\x2d\x6f\x66\x2d\x6c\x69\x6e\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_10_consts_0._ascii.ob_base,
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
toplevel_consts_26_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_10_varnames_1 = {
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
    ._data = "sizehint",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_26_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_10_varnames_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_consts_4_0._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_consts_10_name = {
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
    ._data = "readlines",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_26_consts_10_qualname = {
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
    ._data = "StreamReader.readlines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x0c\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x1b\x10\x1b\x09\x0d\x10\x14\x10\x29\x20\x28\x10\x29\x10\x29\x09\x29",
};
static struct PyCodeObject toplevel_consts_26_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 606,
    .co_code = & toplevel_consts_26_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7c\x00\x5f\x00\x7c\x00\x6a\x01\x7c\x00\x5f\x02\x64\x02\x7c\x00\x5f\x03\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[237];
    }
toplevel_consts_26_consts_11_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 236,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x73\x65\x74\x73\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x62\x75\x66\x66\x65\x72\x73\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x6b\x65\x65\x70\x69\x6e\x67\x20\x69\x6e\x74\x65\x72\x6e\x61\x6c\x20\x73\x74\x61\x74\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x6e\x6f\x20\x73\x74\x72\x65\x61\x6d\x20\x72\x65\x70\x6f\x73\x69\x74\x69\x6f\x6e\x69\x6e\x67\x20\x73\x68\x6f\x75\x6c\x64\x20\x74\x61\x6b\x65\x20\x70\x6c\x61\x63\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x70\x72\x69\x6d\x61\x72\x69\x6c\x79\x20\x69\x6e\x74\x65\x6e\x64\x65\x64\x20\x74\x6f\x20\x62\x65\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x72\x65\x63\x6f\x76\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x66\x72\x6f\x6d\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x65\x72\x72\x6f\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_26_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
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
toplevel_consts_26_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_26_consts_11_qualname = {
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
    ._data = "StreamReader.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x09\x08\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1b\x1e\x09\x0d\x09\x18\x1b\x1f\x1b\x31\x09\x0d\x09\x18\x1b\x1f\x09\x0d\x09\x18\x09\x18\x09\x18",
};
static struct PyCodeObject toplevel_consts_26_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 621,
    .co_code = & toplevel_consts_26_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_26_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x01\x00\x7c\x00\xa0\x02\xa8\x00\xa9\x00\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[113];
    }
toplevel_consts_26_consts_13_consts_0 = {
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
    ._data = "\x20\x53\x65\x74\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x73\x74\x72\x65\x61\x6d\x27\x73\x20\x63\x75\x72\x72\x65\x6e\x74\x20\x70\x6f\x73\x69\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x73\x65\x74\x73\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x62\x75\x66\x66\x65\x72\x73\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x6b\x65\x65\x70\x69\x6e\x67\x20\x73\x74\x61\x74\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_13_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_26_consts_13_qualname = {
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
    ._data = "StreamReader.seek",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_13_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x05\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_26_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x29\x1a\x20\x22\x28\x09\x29\x09\x29\x09\x29\x09\x0d\x09\x15\x09\x15\x09\x15\x09\x15\x09\x15\x09\x15",
};
static struct PyCodeObject toplevel_consts_26_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 634,
    .co_code = & toplevel_consts_26_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x7d\x01\x7c\x01\x72\x0a\x7c\x01\x53\x00\x74\x01\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[53];
    }
toplevel_consts_26_consts_14_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 52,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = " Return the next decoded line from the input stream.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_14_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_26_consts_14_names_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
            & toplevel_consts_26_consts_14_names_1._ascii.ob_base,
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
toplevel_consts_26_consts_14_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_9_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_14_name = {
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
    ._data = "__next__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_26_consts_14_qualname = {
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
    ._data = "StreamReader.__next__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_26_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x04\x01\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_26_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x02\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1f\x10\x1f\x10\x1f\x09\x0d\x0c\x10\x09\x18\x14\x18\x0d\x18\x0f\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_26_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 642,
    .co_code = & toplevel_consts_26_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_14_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_15_name = {
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
        uint8_t _data[22];
    }
toplevel_consts_26_consts_15_qualname = {
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
    ._data = "StreamReader.__iter__",
};
static struct PyCodeObject toplevel_consts_26_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 650,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_15_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_26_consts_16_qualname = {
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
    ._data = "StreamReader.__getattr__",
};
static struct PyCodeObject toplevel_consts_26_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 653,
    .co_code = & toplevel_consts_24_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_16_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_26_consts_17_qualname = {
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
    ._data = "StreamReader.__enter__",
};
static struct PyCodeObject toplevel_consts_26_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 660,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_17_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_26_consts_18_qualname = {
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
    ._data = "StreamReader.__exit__",
};
static struct PyCodeObject toplevel_consts_26_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 663,
    .co_code = & toplevel_consts_24_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_18_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_20 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            Py_False,
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
toplevel_consts_26_consts_21 = {
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
            Py_True,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[23];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 23,
        },
        .ob_item = {
            & toplevel_consts_5_22._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_26_consts_2.ob_base,
            & toplevel_consts_26_consts_3.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            Py_False,
            & toplevel_consts_26_consts_6.ob_base,
            Py_None,
            Py_True,
            & toplevel_consts_26_consts_9.ob_base,
            & toplevel_consts_26_consts_10.ob_base,
            & toplevel_consts_26_consts_11.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_26_consts_13.ob_base,
            & toplevel_consts_26_consts_14.ob_base,
            & toplevel_consts_26_consts_15.ob_base,
            & toplevel_consts_26_consts_16.ob_base,
            & toplevel_consts_26_consts_17.ob_base,
            & toplevel_consts_26_consts_18.ob_base,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_26_consts_20._object.ob_base.ob_base,
            & toplevel_consts_26_consts_21._object.ob_base.ob_base,
            & toplevel_consts_24_consts_13._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_26_consts_9_names_7._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
            & toplevel_consts_26_consts_10_name._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_14_name._ascii.ob_base,
            & toplevel_consts_26_consts_15_name._ascii.ob_base,
            & toplevel_consts_24_consts_8_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_8_name._ascii.ob_base,
            & toplevel_consts_24_consts_9_name._ascii.ob_base,
            & toplevel_consts_24_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x08\x02\x08\x19\x08\x03\x08\x50\x08\x4b\x06\x0f\x08\x0d\x06\x08\x06\x08\x02\x04\x08\xff\x06\x07\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x06\x17\x02\x02\x06\x01\x02\x02\x06\x4e\x02\x02\x06\x49\x02\x02\x06\x0d\x06\x0d\x02\x02\x06\x06\x06\x08\x06\x03\x02\x03\x08\x04\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x16\x19\x05\x13\x27\x2f\x05\x1f\x05\x1f\x05\x1f\x24\x2c\x05\x22\x05\x22\x05\x22\x19\x1b\x05\x16\x05\x16\x05\x16\x1d\x21\x05\x14\x05\x14\x05\x14\x22\x26\x05\x29\x05\x29\x05\x29\x05\x1f\x05\x1f\x05\x1f\x23\x24\x05\x15\x05\x15\x05\x15\x05\x1c\x05\x1c\x05\x1c\x05\x14\x05\x14\x05\x14\x1d\x24\x05\x2a\x05\x2a\x05\x2a\x05\x2a\x05\x14\x05\x14\x05\x14\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 419,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_22._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_22._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_28_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x14\x64\x04\x84\x01\x5a\x05\x64\x15\x64\x06\x84\x01\x5a\x06\x64\x16\x64\x08\x84\x01\x5a\x07\x64\x16\x64\x09\x84\x01\x5a\x08\x64\x0a\x84\x00\x5a\x09\x64\x0b\x84\x00\x5a\x0a\x64\x0c\x84\x00\x5a\x0b\x64\x0d\x84\x00\x5a\x0c\x64\x0e\x84\x00\x5a\x0d\x64\x17\x64\x10\x84\x01\x5a\x0e\x65\x0f\x66\x01\x64\x11\x84\x01\x5a\x10\x64\x12\x84\x00\x5a\x11\x64\x13\x84\x00\x5a\x12\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[258];
    }
toplevel_consts_28_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 257,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x57\x72\x69\x74\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x73\x20\x61\x6c\x6c\x6f\x77\x20\x77\x72\x61\x70\x70\x69\x6e\x67\x20\x73\x74\x72\x65\x61\x6d\x73\x20\x77\x68\x69\x63\x68\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x77\x6f\x72\x6b\x20\x69\x6e\x20\x62\x6f\x74\x68\x20\x72\x65\x61\x64\x20\x61\x6e\x64\x20\x77\x72\x69\x74\x65\x20\x6d\x6f\x64\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x64\x65\x73\x69\x67\x6e\x20\x69\x73\x20\x73\x75\x63\x68\x20\x74\x68\x61\x74\x20\x6f\x6e\x65\x20\x63\x61\x6e\x20\x75\x73\x65\x20\x74\x68\x65\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x2e\x6c\x6f\x6f\x6b\x75\x70\x28\x29\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x74\x6f\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_28_consts_2 = {
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
    ._data = "unknown",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_28_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x01\x7c\x04\xa9\x02\x7c\x00\x5f\x01\x7c\x03\x7c\x01\x7c\x04\xa9\x02\x7c\x00\x5f\x02\x7c\x04\x7c\x00\x5f\x03\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[339];
    }
toplevel_consts_28_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 338,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x57\x72\x69\x74\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x65\x61\x6d\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x53\x74\x72\x65\x61\x6d\x2d\x6c\x69\x6b\x65\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x61\x64\x65\x72\x2c\x20\x57\x72\x69\x74\x65\x72\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x6f\x72\x20\x63\x6c\x61\x73\x73\x65\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x2c\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x20\x72\x65\x73\x70\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x45\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x69\x73\x20\x64\x6f\x6e\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x77\x61\x79\x20\x61\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x66\x6f\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x2f\x52\x65\x61\x64\x65\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_4_names_1 = {
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
    ._data = "reader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_4_names_2 = {
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
    ._data = "writer",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_28_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_4_varnames_2 = {
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
    ._data = "Reader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_4_varnames_3 = {
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
    ._data = "Writer",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_28_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_28_consts_4_varnames_3._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_28_consts_4_qualname = {
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
    ._data = "StreamReaderWriter.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_28_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0d\x0c\x01\x0c\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_28_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x17\x1d\x1e\x24\x26\x2c\x17\x2d\x09\x0d\x09\x14\x17\x1d\x1e\x24\x26\x2c\x17\x2d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_28_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_28_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 5,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 681,
    .co_code = & toplevel_consts_28_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_28_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
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
toplevel_consts_28_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_28_consts_6_qualname = {
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
    ._data = "StreamReaderWriter.read",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x26\x21\x25\x10\x26\x10\x26\x09\x26",
};
static struct PyCodeObject toplevel_consts_28_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 699,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_28_consts_8_qualname = {
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
    ._data = "StreamReaderWriter.readline",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x2a\x25\x29\x10\x2a\x10\x2a\x09\x2a",
};
static struct PyCodeObject toplevel_consts_28_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 703,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_10_name._ascii.ob_base,
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
toplevel_consts_28_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_10_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_28_consts_9_qualname = {
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
    ._data = "StreamReaderWriter.readlines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x2f\x26\x2e\x10\x2f\x10\x2f\x09\x2f",
};
static struct PyCodeObject toplevel_consts_28_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 707,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_10_code = {
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
        uint8_t _data[5];
    }
toplevel_consts_28_consts_10_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_28_consts_10_qualname = {
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
    ._data = "StreamReaderWriter.__next__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_28_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x15\x19\x15\x20\x10\x21\x09\x21",
};
static struct PyCodeObject toplevel_consts_28_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 711,
    .co_code = & toplevel_consts_28_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_28_consts_11_qualname = {
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
    ._data = "StreamReaderWriter.__iter__",
};
static struct PyCodeObject toplevel_consts_28_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 716,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
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
toplevel_consts_28_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_28_consts_12_qualname = {
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
    ._data = "StreamReaderWriter.write",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x27\x22\x26\x10\x27\x10\x27\x09\x27",
};
static struct PyCodeObject toplevel_consts_28_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 719,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_28_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_28_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_28_consts_13_qualname = {
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
    ._data = "StreamReaderWriter.writelines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_28_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x2c\x27\x2b\x10\x2c\x10\x2c\x09\x2c",
};
static struct PyCodeObject toplevel_consts_28_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 723,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_28_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x7c\x00\x6a\x02\xa0\x01\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_28_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_28_consts_14_qualname = {
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
    ._data = "StreamReaderWriter.reset",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_28_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_28_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x0d\x09\x14\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_28_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 727,
    .co_code = & toplevel_consts_28_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_14_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_14_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_28_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x01\x00\x7c\x00\x6a\x02\xa0\x03\xa8\x00\xa9\x00\x01\x00\x7c\x02\x64\x01\x6b\x02\x72\x1f\x7c\x01\x64\x01\x6b\x02\x72\x21\x7c\x00\x6a\x04\xa0\x03\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_28_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_28_consts_16_qualname = {
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
    ._data = "StreamReaderWriter.seek",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x0c\x01\x10\x01\x10\x01\x08\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_28_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x01\x0c\x01\x06\x01\x02\x01\x06\xff\x1a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_28_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x29\x1a\x20\x22\x28\x09\x29\x09\x29\x09\x29\x09\x0d\x09\x14\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x0c\x12\x16\x17\x0c\x17\x09\x20\x1c\x22\x26\x27\x1c\x27\x09\x20\x0d\x11\x0d\x18\x0d\x20\x0d\x20\x0d\x20\x0d\x20\x0d\x20\x0d\x20\x09\x20\x09\x20\x09\x20\x09\x20",
};
static struct PyCodeObject toplevel_consts_28_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 732,
    .co_code = & toplevel_consts_28_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_16_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_28_consts_17_qualname = {
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
    ._data = "StreamReaderWriter.__getattr__",
};
static struct PyCodeObject toplevel_consts_28_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 738,
    .co_code = & toplevel_consts_24_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_17_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_28_consts_18_qualname = {
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
    ._data = "StreamReaderWriter.__enter__",
};
static struct PyCodeObject toplevel_consts_28_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 747,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_18_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_28_consts_19_qualname = {
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
    ._data = "StreamReaderWriter.__exit__",
};
static struct PyCodeObject toplevel_consts_28_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 750,
    .co_code = & toplevel_consts_24_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_19_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_28_consts_21 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_4.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[24];
        }_object;
    }
toplevel_consts_28_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 24,
        },
        .ob_item = {
            & toplevel_consts_5_24._ascii.ob_base,
            & toplevel_consts_28_consts_1._ascii.ob_base,
            & toplevel_consts_28_consts_2._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_28_consts_4.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            & toplevel_consts_28_consts_6.ob_base,
            Py_None,
            & toplevel_consts_28_consts_8.ob_base,
            & toplevel_consts_28_consts_9.ob_base,
            & toplevel_consts_28_consts_10.ob_base,
            & toplevel_consts_28_consts_11.ob_base,
            & toplevel_consts_28_consts_12.ob_base,
            & toplevel_consts_28_consts_13.ob_base,
            & toplevel_consts_28_consts_14.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_28_consts_16.ob_base,
            & toplevel_consts_28_consts_17.ob_base,
            & toplevel_consts_28_consts_18.ob_base,
            & toplevel_consts_28_consts_19.ob_base,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_28_consts_21._object.ob_base.ob_base,
            & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
            & toplevel_consts_24_consts_13._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_28_names_4 = {
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
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_28_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
            & toplevel_consts_26_consts_10_name._ascii.ob_base,
            & toplevel_consts_26_consts_14_name._ascii.ob_base,
            & toplevel_consts_26_consts_15_name._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_24_consts_4_name._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_8_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_8_name._ascii.ob_base,
            & toplevel_consts_24_consts_9_name._ascii.ob_base,
            & toplevel_consts_24_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_28_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x09\x08\x02\x08\x12\x08\x04\x08\x04\x06\x04\x06\x05\x06\x03\x06\x04\x06\x04\x08\x05\x02\x07\x08\xff\x06\x09\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_28_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x09\x04\x02\x02\x02\x06\x10\x02\x02\x06\x02\x02\x02\x06\x02\x02\x02\x06\x02\x06\x05\x06\x03\x06\x04\x06\x04\x06\x05\x02\x02\x06\x04\x02\x03\x08\x04\x06\x05\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_28_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x10\x19\x05\x0d\x37\x3f\x05\x1d\x05\x1d\x05\x1d\x19\x1b\x05\x26\x05\x26\x05\x26\x1d\x21\x05\x2a\x05\x2a\x05\x2a\x22\x26\x05\x2f\x05\x2f\x05\x2f\x05\x21\x05\x21\x05\x21\x05\x14\x05\x14\x05\x14\x05\x27\x05\x27\x05\x27\x05\x2c\x05\x2c\x05\x2c\x05\x1c\x05\x1c\x05\x1c\x23\x24\x05\x20\x05\x20\x05\x20\x1d\x24\x05\x2a\x05\x2a\x05\x2a\x05\x2a\x05\x14\x05\x14\x05\x14\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_28 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 668,
    .co_code = & toplevel_consts_28_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_24._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_24._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[121];
    }
toplevel_consts_30_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 120,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x02\x5a\x05\x09\x03\x64\x14\x64\x04\x84\x01\x5a\x06\x64\x15\x64\x06\x84\x01\x5a\x07\x64\x16\x64\x08\x84\x01\x5a\x08\x64\x16\x64\x09\x84\x01\x5a\x09\x64\x0a\x84\x00\x5a\x0a\x64\x0b\x84\x00\x5a\x0b\x64\x0c\x84\x00\x5a\x0c\x64\x0d\x84\x00\x5a\x0d\x64\x0e\x84\x00\x5a\x0e\x64\x17\x64\x10\x84\x01\x5a\x0f\x65\x10\x66\x01\x64\x11\x84\x01\x5a\x11\x64\x12\x84\x00\x5a\x12\x64\x13\x84\x00\x5a\x13\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[579];
    }
toplevel_consts_30_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 578,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x63\x6f\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x73\x20\x74\x72\x61\x6e\x73\x6c\x61\x74\x65\x20\x64\x61\x74\x61\x20\x66\x72\x6f\x6d\x20\x6f\x6e\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x74\x6f\x20\x61\x6e\x6f\x74\x68\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x79\x20\x75\x73\x65\x20\x74\x68\x65\x20\x63\x6f\x6d\x70\x6c\x65\x74\x65\x20\x73\x65\x74\x20\x6f\x66\x20\x41\x50\x49\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x62\x79\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x64\x65\x63\x73\x2e\x6c\x6f\x6f\x6b\x75\x70\x28\x29\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x74\x6f\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x20\x74\x68\x65\x69\x72\x20\x74\x61\x73\x6b\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x44\x61\x74\x61\x20\x77\x72\x69\x74\x74\x65\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x63\x6f\x64\x65\x72\x20\x69\x73\x20\x66\x69\x72\x73\x74\x20\x64\x65\x63\x6f\x64\x65\x64\x20\x69\x6e\x74\x6f\x20\x61\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x20\x66\x6f\x72\x6d\x61\x74\x20\x28\x64\x65\x70\x65\x6e\x64\x69\x6e\x67\x20\x6f\x6e\x20\x74\x68\x65\x20\x22\x64\x65\x63\x6f\x64\x65\x22\x20\x63\x6f\x64\x65\x63\x29\x20\x61\x6e\x64\x20\x74\x68\x65\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x77\x72\x69\x74\x74\x65\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x75\x6e\x64\x65\x72\x6c\x79\x69\x6e\x67\x20\x73\x74\x72\x65\x61\x6d\x20\x75\x73\x69\x6e\x67\x20\x61\x6e\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x70\x72\x6f\x76\x69\x64\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x57\x72\x69\x74\x65\x72\x20\x63\x6c\x61\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x6e\x20\x74\x68\x65\x20\x6f\x74\x68\x65\x72\x20\x64\x69\x72\x65\x63\x74\x69\x6f\x6e\x2c\x20\x64\x61\x74\x61\x20\x69\x73\x20\x72\x65\x61\x64\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x75\x6e\x64\x65\x72\x6c\x79\x69\x6e\x67\x20\x73\x74\x72\x65\x61\x6d\x20\x75\x73\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x20\x52\x65\x61\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x20\x61\x6e\x64\x20\x74\x68\x65\x6e\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x74\x6f\x20\x74\x68\x65\x20\x63\x61\x6c\x6c\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_30_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x7c\x03\x7c\x00\x5f\x02\x7c\x04\x7c\x01\x7c\x06\xa9\x02\x7c\x00\x5f\x03\x7c\x05\x7c\x01\x7c\x06\xa9\x02\x7c\x00\x5f\x04\x7c\x06\x7c\x00\x5f\x05\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[746];
    }
toplevel_consts_30_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 745,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x63\x6f\x64\x65\x72\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x20\x77\x68\x69\x63\x68\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x73\x20\x61\x20\x74\x77\x6f\x2d\x77\x61\x79\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f\x6e\x3a\x20\x65\x6e\x63\x6f\x64\x65\x20\x61\x6e\x64\x20\x64\x65\x63\x6f\x64\x65\x20\x77\x6f\x72\x6b\x20\x6f\x6e\x20\x74\x68\x65\x20\x66\x72\x6f\x6e\x74\x65\x6e\x64\x20\x28\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x61\x74\x61\x20\x76\x69\x73\x69\x62\x6c\x65\x20\x74\x6f\x20\x2e\x72\x65\x61\x64\x28\x29\x20\x61\x6e\x64\x20\x2e\x77\x72\x69\x74\x65\x28\x29\x29\x20\x77\x68\x69\x6c\x65\x20\x52\x65\x61\x64\x65\x72\x20\x61\x6e\x64\x20\x57\x72\x69\x74\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x77\x6f\x72\x6b\x20\x6f\x6e\x20\x74\x68\x65\x20\x62\x61\x63\x6b\x65\x6e\x64\x20\x28\x74\x68\x65\x20\x64\x61\x74\x61\x20\x69\x6e\x20\x73\x74\x72\x65\x61\x6d\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x59\x6f\x75\x20\x63\x61\x6e\x20\x75\x73\x65\x20\x74\x68\x65\x73\x65\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x74\x6f\x20\x64\x6f\x20\x74\x72\x61\x6e\x73\x70\x61\x72\x65\x6e\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x74\x72\x61\x6e\x73\x63\x6f\x64\x69\x6e\x67\x73\x20\x66\x72\x6f\x6d\x20\x65\x2e\x67\x2e\x20\x6c\x61\x74\x69\x6e\x2d\x31\x20\x74\x6f\x20\x75\x74\x66\x2d\x38\x20\x61\x6e\x64\x20\x62\x61\x63\x6b\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x73\x74\x72\x65\x61\x6d\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x61\x20\x66\x69\x6c\x65\x2d\x6c\x69\x6b\x65\x20\x6f\x62\x6a\x65\x63\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x65\x20\x61\x6e\x64\x20\x64\x65\x63\x6f\x64\x65\x20\x6d\x75\x73\x74\x20\x61\x64\x68\x65\x72\x65\x20\x74\x6f\x20\x74\x68\x65\x20\x43\x6f\x64\x65\x63\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x3b\x20\x52\x65\x61\x64\x65\x72\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x57\x72\x69\x74\x65\x72\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x6f\x72\x20\x63\x6c\x61\x73\x73\x65\x73\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x20\x61\x6e\x64\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x69\x6e\x74\x65\x72\x66\x61\x63\x65\x73\x20\x72\x65\x73\x70\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x45\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x20\x69\x73\x20\x64\x6f\x6e\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x77\x61\x79\x20\x61\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x66\x6f\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x2f\x52\x65\x61\x64\x65\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_30_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_30_consts_4_consts_0._ascii.ob_base,
            Py_None,
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
toplevel_consts_30_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
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
toplevel_consts_30_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_28_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_28_consts_4_varnames_3._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_30_consts_4_qualname = {
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
    ._data = "StreamRecoder.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_30_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x15\x06\x01\x06\x01\x0c\x01\x0c\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_30_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x17\x1d\x1e\x24\x26\x2c\x17\x2d\x09\x0d\x09\x14\x17\x1d\x1e\x24\x26\x2c\x17\x2d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_30_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_30_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 7,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 775,
    .co_code = & toplevel_consts_30_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_30_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_30_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x7d\x02\x7c\x00\xa0\x02\x7c\x02\x7c\x00\x6a\x03\xa8\x02\xa9\x02\x5c\x02\x7d\x02\x7d\x03\x7c\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_30_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_30_consts_6_varnames_3 = {
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
    ._data = "bytesencoded",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_30_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_30_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_30_consts_6_qualname = {
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
    ._data = "StreamRecoder.read",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_30_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x02\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_30_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x26\x21\x25\x10\x26\x10\x26\x09\x0d\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_30_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 803,
    .co_code = & toplevel_consts_30_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_30_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x80\x0a\x7c\x00\x6a\x00\xa0\x01\xa8\x00\xa9\x00\x7d\x02\x6e\x07\x7c\x00\x6a\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x7d\x02\x7c\x00\xa0\x02\x7c\x02\x7c\x00\x6a\x03\xa8\x02\xa9\x02\x5c\x02\x7d\x02\x7d\x03\x7c\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_30_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_30_consts_8_qualname = {
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
    ._data = "StreamRecoder.readline",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_30_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x0e\x01\x0e\x02\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_30_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x02\x03\x0e\xfe\x0e\x02\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_30_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x09\x2e\x14\x18\x14\x1f\x14\x2a\x14\x2a\x14\x2a\x0d\x11\x0d\x11\x14\x18\x14\x1f\x14\x2e\x29\x2d\x14\x2e\x14\x2e\x0d\x11\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_30_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 809,
    .co_code = & toplevel_consts_30_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_30_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\xa8\x00\xa9\x00\x7d\x02\x7c\x00\xa0\x02\x7c\x02\x7c\x00\x6a\x03\xa8\x02\xa9\x02\x5c\x02\x7d\x02\x7d\x03\x7c\x02\xa0\x04\x64\x01\x64\x02\xa8\x02\xaa\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_30_consts_9_consts = {
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
            & toplevel_consts_26_consts_6_consts_4._object.ob_base.ob_base,
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
toplevel_consts_30_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_12._ascii.ob_base,
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
toplevel_consts_30_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_26_consts_10_varnames_1._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_30_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_30_consts_9_qualname = {
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
    ._data = "StreamRecoder.readlines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_30_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x14\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_30_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x22\x10\x22\x10\x22\x09\x0d\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x10\x2e\x29\x2d\x10\x2e\x10\x2e\x10\x2e\x09\x2e",
};
static struct PyCodeObject toplevel_consts_30_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 818,
    .co_code = & toplevel_consts_30_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_30_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x7d\x01\x7c\x00\xa0\x02\x7c\x01\x7c\x00\x6a\x03\xa8\x02\xa9\x02\x5c\x02\x7d\x01\x7d\x02\x7c\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_30_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_28_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
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
toplevel_consts_30_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_30_consts_6_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_30_consts_10_qualname = {
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
    ._data = "StreamRecoder.__next__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_30_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_30_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x15\x19\x15\x20\x10\x21\x09\x0d\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_30_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 824,
    .co_code = & toplevel_consts_30_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_30_consts_11_qualname = {
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
    ._data = "StreamRecoder.__iter__",
};
static struct PyCodeObject toplevel_consts_30_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 831,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_30_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\x7c\x00\x6a\x01\xa8\x02\xa9\x02\x5c\x02\x7d\x01\x7d\x02\x7c\x00\x6a\x02\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_30_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_30_consts_12_varnames_2 = {
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
    ._data = "bytesdecoded",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_30_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_30_consts_12_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_30_consts_12_qualname = {
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
    ._data = "StreamRecoder.write",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_30_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x14\x02\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_30_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x10\x1b\x10\x27\x22\x26\x10\x27\x10\x27\x09\x27",
};
static struct PyCodeObject toplevel_consts_30_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 834,
    .co_code = & toplevel_consts_30_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_12_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_30_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x7d\x02\x7c\x00\xa0\x01\x7c\x02\x7c\x00\x6a\x02\xa8\x02\xa9\x02\x5c\x02\x7d\x02\x7d\x03\x7c\x00\x6a\x03\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_30_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_24_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
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
toplevel_consts_30_consts_13_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_12_consts_5_varnames_9._ascii.ob_base,
            & toplevel_consts_24_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_18_consts_6_varnames_3._ascii.ob_base,
            & toplevel_consts_30_consts_12_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_30_consts_13_qualname = {
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
    ._data = "StreamRecoder.writelines",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_30_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x13\x10\x1e\x19\x1d\x10\x1e\x10\x1e\x09\x0d\x1e\x22\x1e\x3c\x2a\x2e\x30\x34\x30\x3b\x1e\x3c\x1e\x3c\x09\x1b\x09\x0d\x0f\x1b\x10\x14\x10\x1b\x10\x27\x22\x26\x10\x27\x10\x27\x09\x27",
};
static struct PyCodeObject toplevel_consts_30_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 839,
    .co_code = & toplevel_consts_30_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_30_consts_14_qualname = {
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
    ._data = "StreamRecoder.reset",
};
static struct PyCodeObject toplevel_consts_30_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 845,
    .co_code = & toplevel_consts_28_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_14_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_14_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_30_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x01\x00\x7c\x00\x6a\x02\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_30_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_28_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_28_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_30_consts_16_qualname = {
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
    ._data = "StreamRecoder.seek",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_30_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x03\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_30_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x14\x09\x29\x1a\x20\x22\x28\x09\x29\x09\x29\x09\x29\x09\x0d\x09\x14\x09\x29\x1a\x20\x22\x28\x09\x29\x09\x29\x09\x29\x09\x29\x09\x29",
};
static struct PyCodeObject toplevel_consts_30_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 850,
    .co_code = & toplevel_consts_30_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_16_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_16_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_30_consts_17_qualname = {
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
    ._data = "StreamRecoder.__getattr__",
};
static struct PyCodeObject toplevel_consts_30_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 856,
    .co_code = & toplevel_consts_24_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_17_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_30_consts_18_qualname = {
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
    ._data = "StreamRecoder.__enter__",
};
static struct PyCodeObject toplevel_consts_30_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 863,
    .co_code = & toplevel_consts_24_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_18_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_30_consts_19_qualname = {
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
    ._data = "StreamRecoder.__exit__",
};
static struct PyCodeObject toplevel_consts_30_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 866,
    .co_code = & toplevel_consts_24_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_19_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[24];
        }_object;
    }
toplevel_consts_30_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 24,
        },
        .ob_item = {
            & toplevel_consts_5_25._ascii.ob_base,
            & toplevel_consts_30_consts_1._ascii.ob_base,
            & toplevel_consts_28_consts_2._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_30_consts_4.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            & toplevel_consts_30_consts_6.ob_base,
            Py_None,
            & toplevel_consts_30_consts_8.ob_base,
            & toplevel_consts_30_consts_9.ob_base,
            & toplevel_consts_30_consts_10.ob_base,
            & toplevel_consts_30_consts_11.ob_base,
            & toplevel_consts_30_consts_12.ob_base,
            & toplevel_consts_30_consts_13.ob_base,
            & toplevel_consts_30_consts_14.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_30_consts_16.ob_base,
            & toplevel_consts_30_consts_17.ob_base,
            & toplevel_consts_30_consts_18.ob_base,
            & toplevel_consts_30_consts_19.ob_base,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
            & toplevel_consts_28_consts_21._object.ob_base.ob_base,
            & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
            & toplevel_consts_24_consts_13._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_30_names_4 = {
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
    ._data = "data_encoding",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_30_names_5 = {
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
    ._data = "file_encoding",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[20];
        }_object;
    }
toplevel_consts_30_names = {
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
            & toplevel_consts_12_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_6_names_2._ascii.ob_base,
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_30_names_4._ascii.ob_base,
            & toplevel_consts_30_names_5._ascii.ob_base,
            & toplevel_consts_16_consts_3_name._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_9_name._ascii.ob_base,
            & toplevel_consts_26_consts_10_name._ascii.ob_base,
            & toplevel_consts_26_consts_14_name._ascii.ob_base,
            & toplevel_consts_26_consts_15_name._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_24_consts_4_name._ascii.ob_base,
            & toplevel_consts_16_consts_6_name._ascii.ob_base,
            & toplevel_consts_24_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_8_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_8_name._ascii.ob_base,
            & toplevel_consts_24_consts_9_name._ascii.ob_base,
            & toplevel_consts_24_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_30_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x0f\x04\x01\x02\x03\x08\xff\x08\x1c\x08\x06\x08\x09\x06\x06\x06\x07\x06\x03\x06\x05\x06\x06\x08\x05\x02\x07\x08\xff\x06\x07\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_30_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x0f\x04\x02\x04\x01\x02\x03\x08\x19\x02\x02\x06\x04\x02\x02\x06\x07\x02\x02\x06\x04\x06\x07\x06\x03\x06\x05\x06\x06\x06\x05\x02\x02\x06\x04\x02\x03\x08\x04\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[121];
    }
toplevel_consts_30_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 120,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x15\x1e\x05\x12\x15\x1e\x05\x12\x19\x21\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x19\x1b\x05\x14\x05\x14\x05\x14\x1d\x21\x05\x14\x05\x14\x05\x14\x22\x26\x05\x2e\x05\x2e\x05\x2e\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x27\x05\x27\x05\x27\x05\x27\x05\x27\x05\x27\x05\x1c\x05\x1c\x05\x1c\x23\x24\x05\x29\x05\x29\x05\x29\x1d\x24\x05\x2a\x05\x2a\x05\x2a\x05\x2a\x05\x14\x05\x14\x05\x14\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_30 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 755,
    .co_code = & toplevel_consts_30_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_25._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_25._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_32 = {
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
        char ob_sval[105];
    }
toplevel_consts_35_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x81\x0b\x64\x02\x7c\x01\x76\x01\x72\x0b\x7c\x01\x64\x02\x7a\x00\x7d\x01\x74\x00\x6a\x01\x7c\x00\x7c\x01\x7c\x04\xa9\x03\x7d\x05\x7c\x02\x80\x16\x7c\x05\x53\x00\x09\x00\x74\x02\x7c\x02\xa9\x01\x7d\x06\x74\x03\x7c\x05\x7c\x06\x6a\x04\x7c\x06\x6a\x05\x7c\x03\xa9\x04\x7d\x07\x7c\x02\x7c\x07\x5f\x06\x7c\x07\x53\x00\x23\x00\x01\x00\x7c\x05\xa0\x07\xa8\x00\xa9\x00\x01\x00\x82\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1138];
    }
toplevel_consts_35_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1137,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x4f\x70\x65\x6e\x20\x61\x6e\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x66\x69\x6c\x65\x20\x75\x73\x69\x6e\x67\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x6d\x6f\x64\x65\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x20\x77\x72\x61\x70\x70\x65\x64\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x70\x72\x6f\x76\x69\x64\x69\x6e\x67\x20\x74\x72\x61\x6e\x73\x70\x61\x72\x65\x6e\x74\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2f\x64\x65\x63\x6f\x64\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4e\x6f\x74\x65\x3a\x20\x54\x68\x65\x20\x77\x72\x61\x70\x70\x65\x64\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x77\x69\x6c\x6c\x20\x6f\x6e\x6c\x79\x20\x61\x63\x63\x65\x70\x74\x20\x74\x68\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x66\x6f\x72\x6d\x61\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x73\x2c\x20\x69\x2e\x65\x2e\x20\x55\x6e\x69\x63\x6f\x64\x65\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x66\x6f\x72\x20\x6d\x6f\x73\x74\x20\x62\x75\x69\x6c\x74\x69\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6f\x64\x65\x63\x73\x2e\x20\x4f\x75\x74\x70\x75\x74\x20\x69\x73\x20\x61\x6c\x73\x6f\x20\x63\x6f\x64\x65\x63\x20\x64\x65\x70\x65\x6e\x64\x65\x6e\x74\x20\x61\x6e\x64\x20\x77\x69\x6c\x6c\x20\x75\x73\x75\x61\x6c\x6c\x79\x20\x62\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x55\x6e\x69\x63\x6f\x64\x65\x20\x61\x73\x20\x77\x65\x6c\x6c\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x55\x6e\x64\x65\x72\x6c\x79\x69\x6e\x67\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x66\x69\x6c\x65\x73\x20\x61\x72\x65\x20\x61\x6c\x77\x61\x79\x73\x20\x6f\x70\x65\x6e\x65\x64\x20\x69\x6e\x20\x62\x69\x6e\x61\x72\x79\x20\x6d\x6f\x64\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x66\x69\x6c\x65\x20\x6d\x6f\x64\x65\x20\x69\x73\x20\x27\x72\x27\x2c\x20\x6d\x65\x61\x6e\x69\x6e\x67\x20\x74\x6f\x20\x6f\x70\x65\x6e\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x20\x69\x6e\x20\x72\x65\x61\x64\x20\x6d\x6f\x64\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x73\x70\x65\x63\x69\x66\x69\x65\x73\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x68\x69\x63\x68\x20\x69\x73\x20\x74\x6f\x20\x62\x65\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x67\x69\x76\x65\x6e\x20\x74\x6f\x20\x64\x65\x66\x69\x6e\x65\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x2e\x20\x49\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x74\x6f\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x77\x68\x69\x63\x68\x20\x63\x61\x75\x73\x65\x73\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x73\x20\x74\x6f\x20\x62\x65\x20\x72\x61\x69\x73\x65\x64\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x61\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x65\x72\x72\x6f\x72\x20\x6f\x63\x63\x75\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x62\x75\x66\x66\x65\x72\x69\x6e\x67\x20\x68\x61\x73\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x6d\x65\x61\x6e\x69\x6e\x67\x20\x61\x73\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x69\x6e\x20\x6f\x70\x65\x6e\x28\x29\x20\x41\x50\x49\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x20\x74\x6f\x20\x2d\x31\x20\x77\x68\x69\x63\x68\x20\x6d\x65\x61\x6e\x73\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x64\x65\x66\x61\x75\x6c\x74\x20\x62\x75\x66\x66\x65\x72\x20\x73\x69\x7a\x65\x20\x77\x69\x6c\x6c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x62\x65\x20\x75\x73\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x77\x72\x61\x70\x70\x65\x64\x20\x66\x69\x6c\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x61\x6e\x20\x65\x78\x74\x72\x61\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x68\x69\x63\x68\x20\x61\x6c\x6c\x6f\x77\x73\x20\x71\x75\x65\x72\x79\x69\x6e\x67\x20\x74\x68\x65\x20\x75\x73\x65\x64\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2e\x20\x54\x68\x69\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x20\x69\x73\x20\x6f\x6e\x6c\x79\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x20\x69\x66\x20\x61\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x61\x73\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x61\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_35_consts_2 = {
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
            & toplevel_consts_35_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_35_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_35_names_0 = {
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
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_35_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_35_names_0._ascii.ob_base,
            & toplevel_consts_5_2._ascii.ob_base,
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_5_24._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_8._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_24_consts_10_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_35_varnames_0 = {
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
        uint8_t _data[5];
    }
toplevel_consts_35_varnames_1 = {
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
        uint8_t _data[10];
    }
toplevel_consts_35_varnames_4 = {
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
    ._data = "file",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_35_varnames_6 = {
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
    ._data = "info",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_35_varnames_7 = {
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
    ._data = "srw",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_35_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_35_varnames_0._ascii.ob_base,
            & toplevel_consts_35_varnames_1._ascii.ob_base,
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_35_varnames_4._ascii.ob_base,
            & toplevel_consts_35_varnames_5._ascii.ob_base,
            & toplevel_consts_35_varnames_6._ascii.ob_base,
            & toplevel_consts_35_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_35_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x1e\x06\x01\x02\xff\x08\x03\x0e\x01\x04\x01\x04\x01\x02\x02\x08\x01\x12\x01\x06\x02\x04\x01\x02\x80\x02\x01\x0a\x01\x02\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_35_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x1e\x02\x03\x06\xfe\x0a\x02\x0e\x01\x02\x01\x06\x01\x02\x0a\x08\xf9\x12\x01\x06\x02\x04\x01\x02\x80\x02\x03\x0a\xff\x02\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_35_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x10\x05\x1a\x08\x0b\x13\x17\x08\x17\x05\x1a\x10\x14\x17\x1a\x10\x1a\x09\x0d\x0c\x14\x0c\x19\x1a\x22\x24\x28\x2a\x33\x0c\x34\x05\x09\x08\x10\x05\x14\x10\x14\x09\x14\x05\x0e\x10\x16\x17\x1f\x10\x20\x09\x0d\x0f\x21\x22\x26\x28\x2c\x28\x39\x3b\x3f\x3b\x4c\x4e\x54\x0f\x55\x09\x0c\x18\x20\x09\x0c\x09\x15\x10\x13\x09\x13\x00\x00\x05\x0e\x09\x0d\x09\x15\x09\x15\x09\x15\x09\x15\x09\x0e\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_35_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x11\x29\x00\xa9\x08\x31\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_35_localspluskinds = {
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
    .co_argcount = 5,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 871,
    .co_code = & toplevel_consts_35_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_35_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_36_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x80\x05\x7c\x01\x7d\x02\x74\x00\x7c\x01\xa9\x01\x7d\x04\x74\x00\x7c\x02\xa9\x01\x7d\x05\x74\x01\x7c\x00\x7c\x04\x6a\x02\x7c\x04\x6a\x03\x7c\x05\x6a\x04\x7c\x05\x6a\x05\x7c\x03\xa9\x06\x7d\x06\x7c\x01\x7c\x06\x5f\x06\x7c\x02\x7c\x06\x5f\x07\x7c\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[987];
    }
toplevel_consts_36_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 986,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x74\x75\x72\x6e\x20\x61\x20\x77\x72\x61\x70\x70\x65\x64\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x6f\x66\x20\x66\x69\x6c\x65\x20\x77\x68\x69\x63\x68\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x74\x72\x61\x6e\x73\x70\x61\x72\x65\x6e\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x74\x72\x61\x6e\x73\x6c\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x44\x61\x74\x61\x20\x77\x72\x69\x74\x74\x65\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x77\x72\x61\x70\x70\x65\x64\x20\x66\x69\x6c\x65\x20\x69\x73\x20\x64\x65\x63\x6f\x64\x65\x64\x20\x61\x63\x63\x6f\x72\x64\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x74\x6f\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x64\x61\x74\x61\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x74\x68\x65\x6e\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x74\x6f\x20\x74\x68\x65\x20\x75\x6e\x64\x65\x72\x6c\x79\x69\x6e\x67\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x69\x6c\x65\x20\x75\x73\x69\x6e\x67\x20\x66\x69\x6c\x65\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2e\x20\x54\x68\x65\x20\x69\x6e\x74\x65\x72\x6d\x65\x64\x69\x61\x74\x65\x20\x64\x61\x74\x61\x20\x74\x79\x70\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x77\x69\x6c\x6c\x20\x75\x73\x75\x61\x6c\x6c\x79\x20\x62\x65\x20\x55\x6e\x69\x63\x6f\x64\x65\x20\x62\x75\x74\x20\x64\x65\x70\x65\x6e\x64\x73\x20\x6f\x6e\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x63\x6f\x64\x65\x63\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x42\x79\x74\x65\x73\x20\x72\x65\x61\x64\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x20\x61\x72\x65\x20\x64\x65\x63\x6f\x64\x65\x64\x20\x75\x73\x69\x6e\x67\x20\x66\x69\x6c\x65\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x74\x68\x65\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x73\x73\x65\x64\x20\x62\x61\x63\x6b\x20\x74\x6f\x20\x74\x68\x65\x20\x63\x61\x6c\x6c\x65\x72\x20\x65\x6e\x63\x6f\x64\x65\x64\x20\x75\x73\x69\x6e\x67\x20\x64\x61\x74\x61\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x66\x69\x6c\x65\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x69\x73\x20\x6e\x6f\x74\x20\x67\x69\x76\x65\x6e\x2c\x20\x69\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x20\x74\x6f\x20\x64\x61\x74\x61\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x6d\x61\x79\x20\x62\x65\x20\x67\x69\x76\x65\x6e\x20\x74\x6f\x20\x64\x65\x66\x69\x6e\x65\x20\x74\x68\x65\x20\x65\x72\x72\x6f\x72\x20\x68\x61\x6e\x64\x6c\x69\x6e\x67\x2e\x20\x49\x74\x20\x64\x65\x66\x61\x75\x6c\x74\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x74\x6f\x20\x27\x73\x74\x72\x69\x63\x74\x27\x20\x77\x68\x69\x63\x68\x20\x63\x61\x75\x73\x65\x73\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x73\x20\x74\x6f\x20\x62\x65\x20\x72\x61\x69\x73\x65\x64\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x61\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x65\x72\x72\x6f\x72\x20\x6f\x63\x63\x75\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x77\x72\x61\x70\x70\x65\x64\x20\x66\x69\x6c\x65\x20\x6f\x62\x6a\x65\x63\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x74\x77\x6f\x20\x65\x78\x74\x72\x61\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x64\x61\x74\x61\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x2e\x66\x69\x6c\x65\x5f\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x77\x68\x69\x63\x68\x20\x72\x65\x66\x6c\x65\x63\x74\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x6e\x61\x6d\x65\x2e\x20\x54\x68\x65\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6e\x74\x72\x6f\x73\x70\x65\x63\x74\x69\x6f\x6e\x20\x62\x79\x20\x50\x79\x74\x68\x6f\x6e\x20\x70\x72\x6f\x67\x72\x61\x6d\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_36_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_36_consts_0._ascii.ob_base,
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
toplevel_consts_36_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_5_25._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_8._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_30_names_4._ascii.ob_base,
            & toplevel_consts_30_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_36_varnames_4 = {
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
    ._data = "data_info",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_36_varnames_5 = {
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
    ._data = "file_info",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_36_varnames_6 = {
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
    ._data = "sr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_36_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_35_varnames_5._ascii.ob_base,
            & toplevel_consts_30_names_4._ascii.ob_base,
            & toplevel_consts_30_names_5._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_36_varnames_4._ascii.ob_base,
            & toplevel_consts_36_varnames_5._ascii.ob_base,
            & toplevel_consts_36_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_36_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x19\x04\x01\x08\x01\x08\x01\x0c\x01\x0a\x01\x04\xff\x06\x03\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_36_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x19\x06\x01\x08\x01\x08\x01\x0c\x01\x0c\x01\x02\xff\x06\x03\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_36_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x15\x05\x26\x19\x26\x09\x16\x11\x17\x18\x25\x11\x26\x05\x0e\x11\x17\x18\x25\x11\x26\x05\x0e\x0a\x17\x18\x1c\x1e\x27\x1e\x2e\x30\x39\x30\x40\x18\x21\x18\x2e\x30\x39\x30\x46\x48\x4e\x0a\x4f\x05\x07\x18\x25\x05\x07\x05\x15\x18\x25\x05\x07\x05\x15\x0c\x0e\x05\x0e",
};
static struct PyCodeObject toplevel_consts_36 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_36_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_36_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 919,
    .co_code = & toplevel_consts_36_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_30_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_36_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_36_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_36_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x6a\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[159];
    }
toplevel_consts_37_consts_0 = {
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
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x65\x6e\x63\x6f\x64\x65\x72\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_37_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_37_consts_0._ascii.ob_base,
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
toplevel_consts_37_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
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
toplevel_consts_37_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_28_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x12\x13\x1b\x0c\x1c\x0c\x23\x05\x23",
};
static struct PyCodeObject toplevel_consts_37 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 957,
    .co_code = & toplevel_consts_37_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_26._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_26._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[159];
    }
toplevel_consts_38_consts_0 = {
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
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x64\x65\x63\x6f\x64\x65\x72\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_38_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_38_consts_0._ascii.ob_base,
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
toplevel_consts_38_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_38 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_38_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_38_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 967,
    .co_code = & toplevel_consts_37_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_27._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_27._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_39_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x6a\x01\x7d\x01\x7c\x01\x80\x0c\x74\x02\x7c\x00\xa9\x01\x82\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[248];
    }
toplevel_consts_39_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 247,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x72\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x73\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x20\x61\x6e\x20\x69\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x20\x65\x6e\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_39_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_39_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_39_names_2 = {
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
    ._data = "LookupError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_39_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_5._ascii.ob_base,
            & toplevel_consts_39_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_39_varnames_1 = {
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
    ._data = "encoder",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_39_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_39_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x09\x04\x01\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x09\x02\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_39_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x15\x16\x1e\x0f\x1f\x0f\x32\x05\x0c\x08\x0f\x05\x24\x0f\x1a\x1b\x23\x0f\x24\x09\x24\x0c\x13\x05\x13",
};
static struct PyCodeObject toplevel_consts_39 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 977,
    .co_code = & toplevel_consts_39_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_28._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_28._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[248];
    }
toplevel_consts_40_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 247,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6f\x72\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x73\x20\x64\x6f\x65\x73\x6e\x27\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x20\x61\x6e\x20\x69\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x20\x64\x65\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_40_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_40_consts_0._ascii.ob_base,
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
toplevel_consts_40_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_39_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_40_varnames_1 = {
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
    ._data = "decoder",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_40_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_40_varnames_1._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_40 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_40_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 991,
    .co_code = & toplevel_consts_39_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_40_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_29._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_29._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_40_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[181];
    }
toplevel_consts_41_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 180,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x53\x74\x72\x65\x61\x6d\x52\x65\x61\x64\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_41_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_41_consts_0._ascii.ob_base,
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
toplevel_consts_41_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_41_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x12\x13\x1b\x0c\x1c\x0c\x29\x05\x29",
};
static struct PyCodeObject toplevel_consts_41 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_41_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_41_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1005,
    .co_code = & toplevel_consts_37_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_30._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_30._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_41_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[181];
    }
toplevel_consts_42_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 180,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x4c\x6f\x6f\x6b\x75\x70\x20\x75\x70\x20\x74\x68\x65\x20\x63\x6f\x64\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x67\x69\x76\x65\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x74\x73\x20\x53\x74\x72\x65\x61\x6d\x57\x72\x69\x74\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x66\x61\x63\x74\x6f\x72\x79\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x61\x20\x4c\x6f\x6f\x6b\x75\x70\x45\x72\x72\x6f\x72\x20\x69\x6e\x20\x63\x61\x73\x65\x20\x74\x68\x65\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_42_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_42_consts_0._ascii.ob_base,
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
toplevel_consts_42_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_1._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_7._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_42 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_42_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_42_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1015,
    .co_code = & toplevel_consts_37_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_31._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_31._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_41_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_43_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x7c\x01\xa9\x01\x7c\x02\x66\x01\x69\x00\x7c\x03\xa4\x01\x8e\x01\x7d\x04\x7c\x00\x44\x00\x5d\x0e\x7d\x05\x7c\x04\xa0\x01\x7c\x05\xa8\x01\xa9\x01\x7d\x06\x7c\x06\x72\x1c\x7c\x06\x56\x00\x97\x01\x01\x00\x71\x0e\x7c\x04\xa0\x01\x64\x01\x64\x02\xa8\x02\xa9\x02\x7d\x06\x7c\x06\x72\x2c\x7c\x06\x56\x00\x97\x01\x01\x00\x64\x03\x53\x00\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[192];
    }
toplevel_consts_43_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 191,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x45\x6e\x63\x6f\x64\x69\x6e\x67\x20\x69\x74\x65\x72\x61\x74\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20\x45\x6e\x63\x6f\x64\x65\x73\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x73\x74\x72\x69\x6e\x67\x73\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x69\x74\x65\x72\x61\x74\x6f\x72\x20\x75\x73\x69\x6e\x67\x20\x61\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x61\x6e\x64\x20\x6b\x77\x61\x72\x67\x73\x20\x61\x72\x65\x20\x70\x61\x73\x73\x65\x64\x20\x74\x68\x72\x6f\x75\x67\x68\x20\x74\x6f\x20\x74\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x45\x6e\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_43_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_43_consts_0._ascii.ob_base,
            & toplevel_consts_16_consts_3_consts_1._ascii.ob_base,
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
toplevel_consts_43_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_28._ascii.ob_base,
            & toplevel_consts_5_32._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_43_varnames_0 = {
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
    ._data = "iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_43_varnames_3 = {
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
    ._data = "output",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_43_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_43_varnames_0._ascii.ob_base,
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_43_varnames_3._ascii.ob_base,
            & toplevel_consts_39_varnames_1._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_43_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x09\x08\x01\x0c\x01\x04\x01\x08\x01\x02\x80\x0e\x01\x04\x01\x0c\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_43_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x09\x02\x01\x04\x03\x02\xfd\x0c\x01\x02\x01\x0a\x01\x02\x80\x0e\x01\x02\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_43_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0f\x24\x25\x2d\x0f\x2e\x2f\x35\x0f\x40\x0f\x40\x39\x3f\x0f\x40\x0f\x40\x05\x0c\x12\x1a\x05\x19\x05\x19\x09\x0e\x12\x19\x12\x27\x21\x26\x12\x27\x12\x27\x09\x0f\x0c\x12\x09\x19\x13\x19\x0d\x19\x0d\x19\x0d\x19\x00\x00\x0e\x15\x0e\x26\x1d\x1f\x21\x25\x0e\x26\x0e\x26\x05\x0b\x08\x0e\x05\x15\x0f\x15\x09\x15\x09\x15\x09\x15\x09\x15\x09\x15\x05\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_43 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_43_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 43,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1025,
    .co_code = & toplevel_consts_43_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_30_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_34._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_34._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_43_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[192];
    }
toplevel_consts_44_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 191,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x44\x65\x63\x6f\x64\x69\x6e\x67\x20\x69\x74\x65\x72\x61\x74\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20\x44\x65\x63\x6f\x64\x65\x73\x20\x74\x68\x65\x20\x69\x6e\x70\x75\x74\x20\x73\x74\x72\x69\x6e\x67\x73\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x69\x74\x65\x72\x61\x74\x6f\x72\x20\x75\x73\x69\x6e\x67\x20\x61\x6e\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x65\x72\x72\x6f\x72\x73\x20\x61\x6e\x64\x20\x6b\x77\x61\x72\x67\x73\x20\x61\x72\x65\x20\x70\x61\x73\x73\x65\x64\x20\x74\x68\x72\x6f\x75\x67\x68\x20\x74\x6f\x20\x74\x68\x65\x20\x49\x6e\x63\x72\x65\x6d\x65\x6e\x74\x61\x6c\x44\x65\x63\x6f\x64\x65\x72\x0a\x20\x20\x20\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_44_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
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
toplevel_consts_44_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_29._ascii.ob_base,
            & toplevel_consts_5_33._ascii.ob_base,
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
toplevel_consts_44_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_43_varnames_0._ascii.ob_base,
            & toplevel_consts_28_names_4._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_43_varnames_3._ascii.ob_base,
            & toplevel_consts_40_varnames_1._ascii.ob_base,
            & toplevel_consts_14_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_44_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0f\x24\x25\x2d\x0f\x2e\x2f\x35\x0f\x40\x0f\x40\x39\x3f\x0f\x40\x0f\x40\x05\x0c\x12\x1a\x05\x19\x05\x19\x09\x0e\x12\x19\x12\x27\x21\x26\x12\x27\x12\x27\x09\x0f\x0c\x12\x09\x19\x13\x19\x0d\x19\x0d\x19\x0d\x19\x00\x00\x0e\x15\x0e\x27\x1d\x20\x22\x26\x0e\x27\x0e\x27\x05\x0b\x08\x0e\x05\x15\x0f\x15\x09\x15\x09\x15\x09\x15\x09\x15\x09\x15\x05\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_44 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 43,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1043,
    .co_code = & toplevel_consts_43_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_30_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_35._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_35._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_45_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x84\x00\x7c\x00\x44\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[137];
    }
toplevel_consts_45_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 136,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x6d\x61\x6b\x65\x5f\x69\x64\x65\x6e\x74\x69\x74\x79\x5f\x64\x69\x63\x74\x28\x72\x6e\x67\x29\x20\x2d\x3e\x20\x64\x69\x63\x74\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x61\x20\x64\x69\x63\x74\x69\x6f\x6e\x61\x72\x79\x20\x77\x68\x65\x72\x65\x20\x65\x6c\x65\x6d\x65\x6e\x74\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x72\x6e\x67\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x20\x61\x72\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x61\x70\x70\x65\x64\x20\x74\x6f\x20\x74\x68\x65\x6d\x73\x65\x6c\x76\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_45_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x69\x00\x7c\x00\x5d\x05\x7d\x01\x7c\x01\x7c\x01\x93\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_45_consts_1_varnames_0 = {
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
toplevel_consts_45_consts_1_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_45_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_45_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_45_consts_1_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_45_consts_1_name = {
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
    ._data = "<dictcomp>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_45_consts_1_qualname = {
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
    ._data = "make_identity_dict.<locals>.<dictcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_45_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "\x14\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_45_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x1e\x0c\x1e\x0c\x1e\x15\x16\x0d\x0e\x0f\x10\x0c\x1e\x0c\x1e\x0c\x1e",
};
static struct PyCodeObject toplevel_consts_45_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_45_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1071,
    .co_code = & toplevel_consts_45_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_45_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_45_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_45_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_45_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_45_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_45_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_45_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_45_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_45_consts_0._ascii.ob_base,
            & toplevel_consts_45_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_45_varnames_0 = {
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
    ._data = "rng",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_45_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_45_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_45_name = {
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
    ._data = "make_identity_dict",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_45_linetable = {
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
toplevel_consts_45_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x1e\x0c\x1e\x1a\x1d\x0c\x1e\x0c\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_45 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_45_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_45_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1063,
    .co_code = & toplevel_consts_45_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_45_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_6_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_45_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_45_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_45_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_45_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_45_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_45_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_46_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x69\x00\x7d\x01\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x44\x00\x5d\x11\x5c\x02\x7d\x02\x7d\x03\x7c\x03\x7c\x01\x76\x01\x72\x15\x7c\x02\x7c\x01\x7c\x03\x3c\x00\x71\x08\x64\x01\x7c\x01\x7c\x03\x3c\x00\x71\x08\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[387];
    }
toplevel_consts_46_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 386,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x43\x72\x65\x61\x74\x65\x73\x20\x61\x6e\x20\x65\x6e\x63\x6f\x64\x69\x6e\x67\x20\x6d\x61\x70\x20\x66\x72\x6f\x6d\x20\x61\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x6d\x61\x70\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x61\x20\x74\x61\x72\x67\x65\x74\x20\x6d\x61\x70\x70\x69\x6e\x67\x20\x69\x6e\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x64\x69\x6e\x67\x20\x6d\x61\x70\x20\x6f\x63\x63\x75\x72\x73\x20\x6d\x75\x6c\x74\x69\x70\x6c\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x74\x69\x6d\x65\x73\x2c\x20\x74\x68\x65\x6e\x20\x74\x68\x61\x74\x20\x74\x61\x72\x67\x65\x74\x20\x69\x73\x20\x6d\x61\x70\x70\x65\x64\x20\x74\x6f\x20\x4e\x6f\x6e\x65\x20\x28\x75\x6e\x64\x65\x66\x69\x6e\x65\x64\x20\x6d\x61\x70\x70\x69\x6e\x67\x29\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x61\x75\x73\x69\x6e\x67\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x77\x68\x65\x6e\x20\x65\x6e\x63\x6f\x75\x6e\x74\x65\x72\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x63\x68\x61\x72\x6d\x61\x70\x20\x63\x6f\x64\x65\x63\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x64\x75\x72\x69\x6e\x67\x20\x74\x72\x61\x6e\x73\x6c\x61\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4f\x6e\x65\x20\x65\x78\x61\x6d\x70\x6c\x65\x20\x77\x68\x65\x72\x65\x20\x74\x68\x69\x73\x20\x68\x61\x70\x70\x65\x6e\x73\x20\x69\x73\x20\x63\x70\x38\x37\x35\x2e\x70\x79\x20\x77\x68\x69\x63\x68\x20\x64\x65\x63\x6f\x64\x65\x73\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x6d\x75\x6c\x74\x69\x70\x6c\x65\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72\x20\x74\x6f\x20\x5c\x75\x30\x30\x31\x61\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_46_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_46_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_46_names_0 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_46_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_46_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_46_varnames_0 = {
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
    ._data = "decoding_map",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_46_varnames_1 = {
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
toplevel_consts_46_varnames_2 = {
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
    ._data = "k",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_46_varnames_3 = {
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
    ._data = "v",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_46_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_46_varnames_0._ascii.ob_base,
            & toplevel_consts_46_varnames_1._ascii.ob_base,
            & toplevel_consts_46_varnames_2._ascii.ob_base,
            & toplevel_consts_46_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_46_name = {
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
    ._data = "make_encoding_map",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_46_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0d\x12\x01\x08\x01\x0a\x01\x0a\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_46_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0d\x08\x01\x04\x04\x06\xfc\x06\x01\x02\x03\x0a\xfe\x0a\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_46_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0b\x05\x06\x10\x1c\x10\x24\x10\x24\x10\x24\x05\x18\x05\x18\x09\x0c\x09\x0a\x0b\x0c\x10\x11\x15\x16\x10\x16\x09\x18\x14\x15\x0d\x0e\x0f\x10\x0d\x11\x0d\x11\x14\x18\x0d\x0e\x0f\x10\x0d\x11\x0d\x11\x0c\x0d\x05\x0d",
};
static struct PyCodeObject toplevel_consts_46 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_46_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_46_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_46_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1073,
    .co_code = & toplevel_consts_46_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_46_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_46_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_46_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_46_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_46_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
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
    ._data = "ignore",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_48 = {
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
        uint8_t _data[18];
    }
toplevel_consts_49 = {
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
    ._data = "xmlcharrefreplace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_50 = {
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
    ._data = "backslashreplace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_51 = {
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
    ._data = "namereplace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_52 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_53 = {
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
    ._data = "latin-1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_54 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_55 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_32._ascii.ob_base,
            Py_None,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
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
toplevel_consts_56 = {
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
            & toplevel_consts_14_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[58];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 58,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_3._object.ob_base.ob_base,
            & toplevel_consts_4._ascii.ob_base,
            & toplevel_consts_5._object.ob_base.ob_base,
            & toplevel_consts_6.ob_base.ob_base,
            & toplevel_consts_7.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
            & toplevel_consts_10.ob_base.ob_base,
            & toplevel_consts_11._ascii.ob_base,
            & toplevel_consts_12.ob_base,
            & toplevel_consts_5_18._ascii.ob_base,
            & toplevel_consts_14.ob_base,
            & toplevel_consts_5_19._ascii.ob_base,
            & toplevel_consts_16.ob_base,
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_18.ob_base,
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_22_consts_0._ascii.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_5_23._ascii.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_5_22._ascii.ob_base,
            & toplevel_consts_28.ob_base,
            & toplevel_consts_5_24._ascii.ob_base,
            & toplevel_consts_30.ob_base,
            & toplevel_consts_5_25._ascii.ob_base,
            & toplevel_consts_32._ascii.ob_base,
            & toplevel_consts_14_consts_2._ascii.ob_base,
            & toplevel_consts_26_consts_4.ob_base.ob_base,
            & toplevel_consts_35.ob_base,
            & toplevel_consts_36.ob_base,
            & toplevel_consts_37.ob_base,
            & toplevel_consts_38.ob_base,
            & toplevel_consts_39.ob_base,
            & toplevel_consts_40.ob_base,
            & toplevel_consts_41.ob_base,
            & toplevel_consts_42.ob_base,
            & toplevel_consts_43.ob_base,
            & toplevel_consts_44.ob_base,
            & toplevel_consts_45.ob_base,
            & toplevel_consts_46.ob_base,
            & toplevel_consts_47._ascii.ob_base,
            & toplevel_consts_48._ascii.ob_base,
            & toplevel_consts_49._ascii.ob_base,
            & toplevel_consts_50._ascii.ob_base,
            & toplevel_consts_51._ascii.ob_base,
            & toplevel_consts_52._ascii.ob_base,
            & toplevel_consts_53._ascii.ob_base,
            & toplevel_consts_54._ascii.ob_base,
            & toplevel_consts_55._object.ob_base.ob_base,
            & toplevel_consts_56._object.ob_base.ob_base,
            & toplevel_consts_14_consts_6._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_names_2 = {
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
toplevel_names_3 = {
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
    ._data = "_codecs",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_4 = {
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
        uint8_t _data[4];
    }
toplevel_names_5 = {
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
    ._data = "why",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_6 = {
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
    ._data = "SystemError",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_7 = {
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
        uint8_t _data[10];
    }
toplevel_names_15 = {
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
    ._data = "byteorder",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_55 = {
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
    ._data = "_false",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_56 = {
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
    ._data = "encodings",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_58 = {
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
        uint8_t _data[6];
    }
toplevel_names_59 = {
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
            PyObject *ob_item[60];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 60,
        },
        .ob_item = {
            & toplevel_consts_12_names_3._ascii.ob_base,
            & toplevel_consts_35_names_0._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_names_3._ascii.ob_base,
            & toplevel_names_4._ascii.ob_base,
            & toplevel_names_5._ascii.ob_base,
            & toplevel_names_6._ascii.ob_base,
            & toplevel_names_7._ascii.ob_base,
            & toplevel_consts_5_11._ascii.ob_base,
            & toplevel_consts_5_6._ascii.ob_base,
            & toplevel_consts_5_13._ascii.ob_base,
            & toplevel_consts_5_5._ascii.ob_base,
            & toplevel_consts_5_14._ascii.ob_base,
            & toplevel_consts_5_16._ascii.ob_base,
            & toplevel_consts_5_17._ascii.ob_base,
            & toplevel_names_15._ascii.ob_base,
            & toplevel_consts_5_4._ascii.ob_base,
            & toplevel_consts_5_12._ascii.ob_base,
            & toplevel_consts_5_15._ascii.ob_base,
            & toplevel_consts_5_8._ascii.ob_base,
            & toplevel_consts_5_7._ascii.ob_base,
            & toplevel_consts_5_10._ascii.ob_base,
            & toplevel_consts_5_9._ascii.ob_base,
            & toplevel_consts_12_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_5_18._ascii.ob_base,
            & toplevel_consts_5_19._ascii.ob_base,
            & toplevel_consts_24_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_5_20._ascii.ob_base,
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_5_21._ascii.ob_base,
            & toplevel_consts_22_consts_0._ascii.ob_base,
            & toplevel_consts_5_23._ascii.ob_base,
            & toplevel_consts_5_22._ascii.ob_base,
            & toplevel_consts_5_24._ascii.ob_base,
            & toplevel_consts_5_25._ascii.ob_base,
            & toplevel_consts_5_2._ascii.ob_base,
            & toplevel_consts_5_3._ascii.ob_base,
            & toplevel_consts_5_26._ascii.ob_base,
            & toplevel_consts_5_27._ascii.ob_base,
            & toplevel_consts_5_28._ascii.ob_base,
            & toplevel_consts_5_29._ascii.ob_base,
            & toplevel_consts_5_30._ascii.ob_base,
            & toplevel_consts_5_31._ascii.ob_base,
            & toplevel_consts_5_34._ascii.ob_base,
            & toplevel_consts_5_35._ascii.ob_base,
            & toplevel_consts_45_name._ascii.ob_base,
            & toplevel_consts_46_name._ascii.ob_base,
            & toplevel_consts_5_43._ascii.ob_base,
            & toplevel_consts_5_36._ascii.ob_base,
            & toplevel_consts_5_37._ascii.ob_base,
            & toplevel_consts_5_38._ascii.ob_base,
            & toplevel_consts_5_39._ascii.ob_base,
            & toplevel_consts_5_40._ascii.ob_base,
            & toplevel_consts_5_41._ascii.ob_base,
            & toplevel_consts_39_names_2._ascii.ob_base,
            & toplevel_names_55._ascii.ob_base,
            & toplevel_names_56._ascii.ob_base,
            & toplevel_consts_12_names_0._ascii.ob_base,
            & toplevel_names_58._ascii.ob_base,
            & toplevel_names_59._ascii.ob_base,
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
        char ob_sval[149];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 148,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x09\x08\x01\x02\x04\x0a\x01\x02\x80\x06\x01\x0c\x01\x08\x80\x02\xff\x06\x80\x08\x03\x04\x18\x08\x03\x08\x03\x04\x03\x04\x03\x0a\x02\x08\x03\x06\x03\x08\x05\x04\x03\x04\x03\x04\x01\x04\x01\x04\x01\x0e\x05\x0c\x1f\x0e\x42\x0e\x28\x0e\x22\x0e\x31\x0e\x2b\x0e\x49\x00\x7f\x0c\x7a\x0c\x57\x08\x74\x08\x30\x06\x26\x06\x0a\x06\x0a\x06\x0e\x06\x0e\x06\x0a\x08\x0a\x08\x12\x06\x14\x06\x0a\x02\x17\x08\x01\x08\x01\x08\x01\x08\x01\x08\x01\x0a\x01\x02\x80\x06\x01\x04\x02\x04\x01\x04\x01\x04\x01\x04\x01\x08\x01\x02\xf9\x06\x80\x04\x0b\x04\x01\x08\x01\x0a\x04\x10\x03\x14\x03\x04\xfa",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[193];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 192,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x07\x08\x02\x08\x01\x02\x07\x0a\xfe\x02\x80\x02\x01\x10\x01\x08\x80\x02\x00\x06\x80\x06\x0f\x02\xf3\x04\x18\x08\x03\x08\x03\x04\x03\x04\x03\x08\x02\x02\x0e\x08\xf5\x06\x03\x08\x05\x04\x03\x04\x03\x04\x01\x04\x01\x04\x01\x08\x22\x02\xe3\x04\x1d\x0c\x42\x08\x28\x02\xda\x04\x26\x08\x22\x02\xe0\x04\x20\x08\x31\x02\xd1\x04\x2f\x08\x24\x02\xde\x04\x22\x08\x4e\x02\xbb\x04\x45\x00\x7f\x08\x7a\x00\x81\x02\x8a\x00\x7f\x04\x76\x0c\x57\x0c\x74\x02\x04\x06\x2e\x02\x02\x06\x22\x06\x0c\x06\x0a\x06\x0e\x06\x0e\x06\x0a\x06\x0a\x02\x02\x06\x10\x02\x02\x06\x10\x06\x0c\x06\x15\x02\x12\x08\xf3\x08\x01\x08\x01\x08\x01\x08\x01\x0a\x01\x02\x80\x02\x01\x04\x07\x04\xfb\x04\x01\x04\x01\x04\x01\x04\x01\x0a\x01\x06\x80\x04\x04\x02\x01\x0a\x01\x06\x04\x04\x06\x10\xfd\x18\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[535];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 534,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x10\x01\x10\x01\x10\x01\x10\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x45\x05\x1a\x05\x1a\x05\x1a\x05\x1a\x05\x1a\x00\x00\x08\x13\x01\x45\x01\x45\x0b\x16\x17\x3e\x41\x44\x17\x44\x0b\x45\x05\x45\x00\x00\x00\x00\x00\x00\x00\x00\x01\x45\x00\x00\x00\x00\x00\x00\x0b\x2d\x0b\x2d\x0b\x2d\x01\x08\x0c\x1b\x01\x09\x19\x24\x01\x24\x01\x07\x0a\x16\x19\x24\x01\x24\x01\x07\x0a\x16\x10\x23\x01\x0d\x10\x23\x01\x0d\x04\x07\x04\x11\x15\x1d\x04\x1d\x01\x1d\x17\x23\x05\x23\x05\x08\x0b\x14\x11\x1d\x05\x0e\x05\x0e\x17\x23\x05\x23\x05\x08\x0b\x14\x11\x1d\x05\x0e\x0c\x18\x01\x09\x0c\x18\x01\x09\x0c\x18\x01\x09\x0c\x18\x01\x09\x01\x26\x01\x26\x01\x26\x01\x26\x11\x16\x01\x26\x01\x26\x01\x22\x01\x22\x01\x22\x01\x22\x01\x22\x01\x22\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x1a\x20\x01\x0c\x01\x0c\x01\x22\x01\x22\x01\x22\x01\x22\x22\x34\x01\x22\x01\x22\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x1a\x20\x01\x0c\x01\x0c\x01\x1f\x01\x1f\x01\x1f\x01\x1f\x22\x34\x01\x1f\x01\x1f\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x14\x19\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x14\x19\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x19\x1c\x01\x0e\x01\x0e\x01\x0e\x34\x38\x01\x0e\x01\x0e\x01\x0e\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x13\x01\x13\x01\x13\x01\x13\x01\x13\x01\x13\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x2b\x33\x01\x15\x01\x15\x01\x15\x2b\x33\x01\x15\x01\x15\x01\x15\x01\x1e\x01\x1e\x01\x1e\x01\x0d\x01\x0d\x01\x0d\x01\x1e\x15\x21\x22\x2a\x15\x2b\x05\x12\x15\x21\x22\x2a\x15\x2b\x05\x12\x16\x22\x23\x2c\x16\x2d\x05\x13\x20\x2c\x2d\x40\x20\x41\x05\x1d\x1f\x2b\x2c\x3e\x1f\x3f\x05\x1c\x1a\x26\x27\x34\x1a\x35\x05\x17\x05\x17\x00\x00\x08\x13\x01\x1e\x01\x1e\x15\x19\x05\x12\x15\x19\x05\x12\x16\x1a\x05\x13\x20\x24\x05\x1d\x1f\x23\x05\x1c\x1a\x1e\x05\x17\x05\x17\x05\x17\x01\x1e\x00\x00\x00\x00\x00\x00\x0a\x0b\x01\x07\x04\x0a\x01\x15\x05\x15\x05\x15\x05\x15\x05\x15\x04\x0c\x10\x1a\x04\x1a\x01\x3b\x01\x3b\x12\x1d\x1e\x21\x1e\x28\x2a\x33\x35\x3c\x12\x3d\x05\x08\x05\x0f\x11\x1c\x1d\x20\x1d\x26\x28\x2f\x31\x3a\x11\x3b\x05\x08\x05\x0e\x05\x0e\x05\x0e\x01\x3b\x01\x3b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x8c\x04\x11\x00\x91\x04\x20\x03\x95\x06\x1b\x03\x9b\x05\x20\x03\xc2\x3b\x18\x43\x14\x00\xc3\x14\x10\x43\x27\x03\xc3\x26\x01\x43\x27\x03",
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
    .co_localsplusnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_12_consts_5_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_12_consts_5_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_codecs_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

