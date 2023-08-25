#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[563];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 562,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x5a\x01\x64\x02\x5a\x02\x64\x03\x5a\x03\x64\x04\x5a\x04\x64\x05\x5a\x05\x64\x06\x5a\x06\x64\x07\x5a\x07\x64\x08\x5a\x08\x64\x09\x5a\x09\x64\x0a\x5a\x0a\x64\x0b\x84\x00\x5a\x0b\x64\x0c\x84\x00\x5a\x0c\x64\x0d\x5a\x0d\x64\x0e\x5a\x0e\x64\x0f\x5a\x0f\x64\x10\x5a\x10\x64\x11\x5a\x11\x64\x12\x5a\x12\x64\x13\x5a\x13\x64\x01\x5a\x14\x64\x01\x5a\x15\x64\x01\x5a\x16\x64\x14\x84\x00\x5a\x17\x64\x15\x84\x00\x5a\x18\x64\x16\x84\x00\x5a\x19\x64\x17\x84\x00\x5a\x1a\x64\x18\x84\x00\x5a\x1b\x64\x19\x84\x00\x5a\x1c\x64\x1a\x84\x00\x5a\x1d\x64\x1b\x84\x00\x5a\x1e\x64\x1c\x84\x00\x5a\x1f\x64\x1d\x84\x00\x5a\x20\x64\x1e\x5a\x21\x64\x1f\x5a\x22\x65\x22\x5a\x23\x64\x20\x5a\x24\x64\x21\x5a\x25\x64\x22\x5a\x26\x64\x23\x5a\x27\x64\x24\x5a\x28\x64\x21\x5a\x29\x64\x22\x5a\x2a\x64\x23\x5a\x2b\x64\x25\x5a\x2c\x64\x26\x5a\x2d\x64\x27\x5a\x2e\x64\x09\x5a\x2f\x64\x08\x5a\x30\x64\x05\x5a\x31\x64\x03\x5a\x32\x64\x02\x5a\x33\x64\x02\x5a\x34\x64\x03\x5a\x35\x64\x05\x5a\x36\x64\x09\x5a\x37\x64\x27\x5a\x38\x64\x26\x5a\x39\x64\x10\x5a\x3a\x64\x28\x5a\x3b\x64\x29\x5a\x3c\x64\x2a\x5a\x3d\x64\x2b\x5a\x3e\x64\x2c\x5a\x3f\x65\x12\x64\x2d\x66\x02\x65\x13\x64\x2e\x66\x02\x65\x10\x64\x2f\x66\x02\x65\x0f\x64\x30\x66\x02\x65\x0d\x64\x31\x66\x02\x65\x0e\x64\x32\x66\x02\x65\x11\x64\x33\x66\x02\x66\x07\x65\x29\x64\x34\x66\x02\x66\x01\x65\x2a\x64\x35\x66\x02\x66\x01\x65\x2b\x65\x21\x7a\x07\x64\x2e\x66\x02\x65\x21\x64\x36\x66\x02\x65\x2b\x64\x37\x66\x02\x66\x03\x65\x2d\x64\x34\x66\x02\x66\x01\x65\x2e\x64\x35\x66\x02\x66\x01\x65\x2f\x65\x22\x7a\x07\x64\x2e\x66\x02\x65\x22\x64\x36\x66\x02\x65\x2f\x64\x37\x66\x02\x66\x03\x65\x31\x64\x34\x66\x02\x66\x01\x65\x32\x64\x35\x66\x02\x66\x01\x65\x33\x65\x24\x7a\x07\x64\x38\x66\x02\x65\x24\x64\x39\x66\x02\x65\x33\x64\x37\x66\x02\x66\x03\x66\x0a\x5a\x40\x64\x3a\x84\x00\x5a\x41\x64\x26\x5a\x42\x64\x1e\x5a\x43\x64\x23\x5a\x44\x64\x27\x5a\x45\x64\x0d\x5a\x46\x64\x03\x5a\x47\x64\x10\x5a\x48\x64\x22\x5a\x49\x64\x0e\x5a\x4a\x64\x29\x5a\x4b\x64\x11\x5a\x4c\x64\x02\x5a\x4d\x64\x1f\x5a\x4e\x64\x20\x5a\x4f\x64\x05\x5a\x50\x64\x21\x5a\x51\x64\x28\x5a\x52\x09\x00\x64\x01\x64\x3b\x6c\x53\x54\x00\x64\x3c\x53\x00\x23\x00\x65\x54\x90\x01\x79\x15\x01\x00\x59\x00\x64\x3c\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[112];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 111,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x6f\x6e\x73\x74\x61\x6e\x74\x73\x2f\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x66\x6f\x72\x20\x69\x6e\x74\x65\x72\x70\x72\x65\x74\x69\x6e\x67\x20\x72\x65\x73\x75\x6c\x74\x73\x20\x6f\x66\x20\x6f\x73\x2e\x73\x74\x61\x74\x28\x29\x20\x61\x6e\x64\x20\x6f\x73\x2e\x6c\x73\x74\x61\x74\x28\x29\x2e\x0a\x0a\x53\x75\x67\x67\x65\x73\x74\x65\x64\x20\x75\x73\x61\x67\x65\x3a\x20\x66\x72\x6f\x6d\x20\x73\x74\x61\x74\x20\x69\x6d\x70\x6f\x72\x74\x20\x2a\x0a",
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
        digit ob_digit[1];
    }
toplevel_consts_2 = {
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
toplevel_consts_3 = {
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
toplevel_consts_4 = {
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
toplevel_consts_5 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_6 = {
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
toplevel_consts_7 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 6 },
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
    .ob_digit = { 7 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_9 = {
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 9 },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x64\x01\x7a\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[78];
    }
toplevel_consts_11_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 77,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x6f\x72\x74\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x27\x73\x20\x6d\x6f\x64\x65\x20\x74\x68\x61\x74\x20\x63\x61\x6e\x20\x62\x65\x20\x73\x65\x74\x20\x62\x79\x0a\x20\x20\x20\x20\x6f\x73\x2e\x63\x68\x6d\x6f\x64\x28\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_11_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4095 },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_1.ob_base.ob_base,
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
toplevel_consts_11_names = {
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
    ._data = "mode",
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
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_11_filename = {
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
    ._data = "<frozen stat>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_name = {
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
    ._data = "S_IMODE",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x13\x19\x0c\x19\x05\x19",
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
    .co_stacksize = 2,
    .co_firstlineno = 21,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[77];
    }
toplevel_consts_12_consts_0 = {
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
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x70\x6f\x72\x74\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x66\x69\x6c\x65\x27\x73\x20\x6d\x6f\x64\x65\x20\x74\x68\x61\x74\x20\x64\x65\x73\x63\x72\x69\x62\x65\x73\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x66\x69\x6c\x65\x20\x74\x79\x70\x65\x2e\x0a\x20\x20\x20\x20",
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_12_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 28672, 1 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_12_consts_1 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 61440 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_12_name = {
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
    ._data = "S_IFMT",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x13\x1b\x0c\x1b\x05\x1b",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 27,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_13 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 16384 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_14 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 8192 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_15 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 24576 },
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_16 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 1 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_16 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 32768 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_17 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 4096 },
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_18 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 8192, 1 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_18 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 40960 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_19 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 16384, 1 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_19 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 49152 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_20_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x74\x01\x6b\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[41];
    }
toplevel_consts_20_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 40,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return True if mode is from a directory.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_20_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_20_consts_0._ascii.ob_base,
        },
    },
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
    ._data = "S_IFDIR",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_20_name = {
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
    .ob_sval = "\x02\x00\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x12\x13\x17\x0c\x18\x1c\x23\x0c\x23\x05\x23",
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 50,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[61];
    }
toplevel_consts_21_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 60,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return True if mode is from a character special device file.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_21_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_names_1 = {
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
    ._data = "S_IFCHR",
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
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_name = {
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
    ._data = "S_ISCHR",
};
static struct PyCodeObject toplevel_consts_21 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 54,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[57];
    }
toplevel_consts_22_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 56,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return True if mode is from a block special device file.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_22_names_1 = {
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
    ._data = "S_IFBLK",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_22_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_22_name = {
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
    ._data = "S_ISBLK",
};
static struct PyCodeObject toplevel_consts_22 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 58,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[44];
    }
toplevel_consts_23_consts_0 = {
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
    ._data = "Return True if mode is from a regular file.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_23_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_23_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_23_names_1 = {
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
    ._data = "S_IFREG",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_23_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_23_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_23_name = {
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
    ._data = "S_ISREG",
};
static struct PyCodeObject toplevel_consts_23 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 62,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_24_consts_0 = {
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
    ._data = "Return True if mode is from a FIFO (named pipe).",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_24_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_24_names_1 = {
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
    ._data = "S_IFIFO",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_24_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_24_name = {
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
    ._data = "S_ISFIFO",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 66,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_25_consts_0 = {
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
    ._data = "Return True if mode is from a symbolic link.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_25_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_25_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_25_names_1 = {
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
    ._data = "S_IFLNK",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_25_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_25_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_25_name = {
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
static struct PyCodeObject toplevel_consts_25 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_25_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_25_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 70,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_25_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_25_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_26_consts_0 = {
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
    ._data = "Return True if mode is from a socket.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_names_1 = {
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
    ._data = "S_IFSOCK",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_26_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_name = {
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
    ._data = "S_ISSOCK",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x12\x13\x17\x0c\x18\x1c\x24\x0c\x24\x05\x24",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 74,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_27_code = {
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
        uint8_t _data[36];
    }
toplevel_consts_27_consts_0 = {
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
    ._data = "Return True if mode is from a door.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_27_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_27_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_27_name = {
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
    ._data = "S_ISDOOR",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_27_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_27_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x11\x0c\x11",
};
static struct PyCodeObject toplevel_consts_27 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_27_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_27_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 78,
    .co_code = & toplevel_consts_27_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_27_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_27_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_27_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[43];
    }
toplevel_consts_28_consts_0 = {
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
    ._data = "Return True if mode is from an event port.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_28_name = {
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
    ._data = "S_ISPORT",
};
static struct PyCodeObject toplevel_consts_28 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_27_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 82,
    .co_code = & toplevel_consts_27_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_28_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_27_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_29_consts_0 = {
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
    ._data = "Return True if mode is from a whiteout.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_29_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_29_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_29_name = {
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
    ._data = "S_ISWHT",
};
static struct PyCodeObject toplevel_consts_29 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_29_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_27_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 86,
    .co_code = & toplevel_consts_27_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_29_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_29_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_27_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_30 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 2048 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_31 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 1024 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_32 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 512 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_33 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 256 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_34 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 128 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_35 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 64 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_36 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 448 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_37 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 56 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_38 = {
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
toplevel_consts_39 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 16 },
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_40 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 2 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_40 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 65536 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_41 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 4 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_41 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 131072 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_42 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 8 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_42 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 262144 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_43 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 32 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_43 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 1048576 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_44 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 0, 64 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_44 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 2097152 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_45 = {
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
    ._data = "l",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_46 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_47 = {
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
    ._data = "-",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_48 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_49 = {
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
toplevel_consts_50 = {
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
        uint8_t _data[2];
    }
toplevel_consts_51 = {
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
toplevel_consts_52 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_53 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_54 = {
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
    ._data = "S",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_55 = {
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
toplevel_consts_56 = {
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
    ._data = "t",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_57 = {
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
    ._data = "T",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_58_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7d\x01\x74\x00\x44\x00\x5d\x1d\x7d\x02\x7c\x02\x44\x00\x5d\x12\x5c\x02\x7d\x03\x7d\x04\x7c\x00\x7c\x03\x7a\x01\x7c\x03\x6b\x02\x72\x1b\x7c\x01\xa0\x01\x7c\x04\xa8\x01\xa9\x01\x01\x00\x01\x00\x6e\x07\x71\x09\x7c\x01\xa0\x01\x64\x01\xa8\x01\xa9\x01\x01\x00\x71\x05\x64\x02\xa0\x02\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[60];
    }
toplevel_consts_58_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 59,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Convert a file's mode to a string of the form '-rwxrwxrwx'.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_58_consts_2 = {
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
toplevel_consts_58_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_58_consts_0._ascii.ob_base,
            & toplevel_consts_47._ascii.ob_base,
            & toplevel_consts_58_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_58_names_0 = {
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
    ._data = "_filemode_table",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_58_names_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_58_names_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_58_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_58_names_0._ascii.ob_base,
            & toplevel_consts_58_names_1._ascii.ob_base,
            & toplevel_consts_58_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_58_varnames_1 = {
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
    ._data = "perm",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_58_varnames_2 = {
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
    ._data = "table",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_58_varnames_3 = {
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
    ._data = "bit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_58_varnames_4 = {
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
    ._data = "char",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_58_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_0._ascii.ob_base,
            & toplevel_consts_58_varnames_1._ascii.ob_base,
            & toplevel_consts_58_varnames_2._ascii.ob_base,
            & toplevel_consts_58_varnames_3._ascii.ob_base,
            & toplevel_consts_58_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_58_name = {
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
    ._data = "filemode",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_58_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x08\x01\x0c\x01\x0c\x01\x0c\x01\x04\x01\x02\xfe\x0c\x04\x02\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_58_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x02\x01\x04\x06\x02\xfa\x02\x01\x04\x05\x06\xfb\x0a\x01\x02\x02\x0c\xff\x06\x01\x0c\x02\x02\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_58_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x05\x09\x12\x21\x05\x1d\x05\x1d\x09\x0e\x1a\x1f\x09\x1d\x09\x1d\x0d\x16\x0d\x10\x12\x16\x10\x14\x17\x1a\x10\x1a\x1e\x21\x10\x21\x0d\x16\x11\x15\x11\x22\x1d\x21\x11\x22\x11\x22\x11\x22\x11\x16\x11\x16\x0d\x16\x0d\x11\x0d\x1d\x19\x1c\x0d\x1d\x0d\x1d\x0d\x1d\x00\x00\x0c\x0e\x0c\x19\x14\x18\x0c\x19\x0c\x19\x05\x19",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_58_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_58 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_58_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_58_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_58_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_11_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 156,
    .co_code = & toplevel_consts_58_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_58_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_58_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_11_filename._ascii.ob_base,
    .co_name = & toplevel_consts_58_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_58_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_58_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_58_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_58_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_58_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_59_0 = {
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
toplevel_consts_59 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_59_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[61];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 61,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_2.ob_base.ob_base,
            & toplevel_consts_3.ob_base.ob_base,
            & toplevel_consts_4.ob_base.ob_base,
            & toplevel_consts_5.ob_base.ob_base,
            & toplevel_consts_6.ob_base.ob_base,
            & toplevel_consts_7.ob_base.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
            & toplevel_consts_10.ob_base.ob_base,
            & toplevel_consts_11.ob_base,
            & toplevel_consts_12.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
            & toplevel_consts_14.ob_base.ob_base,
            & toplevel_consts_15.ob_base.ob_base,
            & toplevel_consts_16.ob_base.ob_base,
            & toplevel_consts_17.ob_base.ob_base,
            & toplevel_consts_18.ob_base.ob_base,
            & toplevel_consts_19.ob_base.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_21.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_23.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_25.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_27.ob_base,
            & toplevel_consts_28.ob_base,
            & toplevel_consts_29.ob_base,
            & toplevel_consts_30.ob_base.ob_base,
            & toplevel_consts_31.ob_base.ob_base,
            & toplevel_consts_32.ob_base.ob_base,
            & toplevel_consts_33.ob_base.ob_base,
            & toplevel_consts_34.ob_base.ob_base,
            & toplevel_consts_35.ob_base.ob_base,
            & toplevel_consts_36.ob_base.ob_base,
            & toplevel_consts_37.ob_base.ob_base,
            & toplevel_consts_38.ob_base.ob_base,
            & toplevel_consts_39.ob_base.ob_base,
            & toplevel_consts_40.ob_base.ob_base,
            & toplevel_consts_41.ob_base.ob_base,
            & toplevel_consts_42.ob_base.ob_base,
            & toplevel_consts_43.ob_base.ob_base,
            & toplevel_consts_44.ob_base.ob_base,
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
            & toplevel_consts_58.ob_base,
            & toplevel_consts_59._object.ob_base.ob_base,
            Py_None,
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
toplevel_names_1 = {
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
    ._data = "ST_MODE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_2 = {
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
    ._data = "ST_INO",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_3 = {
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
    ._data = "ST_DEV",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_4 = {
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
    ._data = "ST_NLINK",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_5 = {
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
    ._data = "ST_UID",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_6 = {
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
    ._data = "ST_GID",
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
    ._data = "ST_SIZE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_8 = {
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
    ._data = "ST_ATIME",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_9 = {
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
    ._data = "ST_MTIME",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_10 = {
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
    ._data = "ST_CTIME",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_20 = {
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
    ._data = "S_IFDOOR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_21 = {
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
    ._data = "S_IFPORT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_22 = {
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
    ._data = "S_IFWHT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_33 = {
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
    ._data = "S_ISUID",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_34 = {
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
    ._data = "S_ISGID",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_35 = {
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
    ._data = "S_ENFMT",
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
    ._data = "S_ISVTX",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_37 = {
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
    ._data = "S_IREAD",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_38 = {
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
    ._data = "S_IWRITE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_39 = {
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
    ._data = "S_IEXEC",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_40 = {
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
    ._data = "S_IRWXU",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_41 = {
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
    ._data = "S_IRUSR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_42 = {
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
    ._data = "S_IWUSR",
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
    ._data = "S_IXUSR",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_44 = {
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
    ._data = "S_IRWXG",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_45 = {
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
    ._data = "S_IRGRP",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_46 = {
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
    ._data = "S_IWGRP",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_47 = {
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
    ._data = "S_IXGRP",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_48 = {
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
    ._data = "S_IRWXO",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_49 = {
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
    ._data = "S_IROTH",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_50 = {
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
    ._data = "S_IWOTH",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_51 = {
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
    ._data = "S_IXOTH",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_52 = {
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
    ._data = "UF_NODUMP",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_53 = {
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
    ._data = "UF_IMMUTABLE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_54 = {
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
    ._data = "UF_APPEND",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_55 = {
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
    ._data = "UF_OPAQUE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_56 = {
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
    ._data = "UF_NOUNLINK",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_names_57 = {
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
    ._data = "UF_COMPRESSED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_58 = {
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
    ._data = "UF_HIDDEN",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_59 = {
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
    ._data = "SF_ARCHIVED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_60 = {
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
    ._data = "SF_IMMUTABLE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_61 = {
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
    ._data = "SF_APPEND",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_62 = {
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
    ._data = "SF_NOUNLINK",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_63 = {
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
    ._data = "SF_SNAPSHOT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_names_66 = {
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
    ._data = "FILE_ATTRIBUTE_ARCHIVE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_names_67 = {
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
    ._data = "FILE_ATTRIBUTE_COMPRESSED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_names_68 = {
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
    ._data = "FILE_ATTRIBUTE_DEVICE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_names_69 = {
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
    ._data = "FILE_ATTRIBUTE_DIRECTORY",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_names_70 = {
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
    ._data = "FILE_ATTRIBUTE_ENCRYPTED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_names_71 = {
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
    ._data = "FILE_ATTRIBUTE_HIDDEN",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_names_72 = {
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
    ._data = "FILE_ATTRIBUTE_INTEGRITY_STREAM",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_names_73 = {
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
    ._data = "FILE_ATTRIBUTE_NORMAL",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[35];
    }
toplevel_names_74 = {
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
    ._data = "FILE_ATTRIBUTE_NOT_CONTENT_INDEXED",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_names_75 = {
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
    ._data = "FILE_ATTRIBUTE_NO_SCRUB_DATA",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_names_76 = {
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
    ._data = "FILE_ATTRIBUTE_OFFLINE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_names_77 = {
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
    ._data = "FILE_ATTRIBUTE_READONLY",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_names_78 = {
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
    ._data = "FILE_ATTRIBUTE_REPARSE_POINT",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_names_79 = {
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
    ._data = "FILE_ATTRIBUTE_SPARSE_FILE",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_names_80 = {
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
    ._data = "FILE_ATTRIBUTE_SYSTEM",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_names_81 = {
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
    ._data = "FILE_ATTRIBUTE_TEMPORARY",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_names_82 = {
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
    ._data = "FILE_ATTRIBUTE_VIRTUAL",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_names_83 = {
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
    ._data = "_stat",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_84 = {
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
            PyObject *ob_item[85];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 85,
        },
        .ob_item = {
            & toplevel_names_0._ascii.ob_base,
            & toplevel_names_1._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_names_3._ascii.ob_base,
            & toplevel_names_4._ascii.ob_base,
            & toplevel_names_5._ascii.ob_base,
            & toplevel_names_6._ascii.ob_base,
            & toplevel_names_7._ascii.ob_base,
            & toplevel_names_8._ascii.ob_base,
            & toplevel_names_9._ascii.ob_base,
            & toplevel_names_10._ascii.ob_base,
            & toplevel_consts_11_name._ascii.ob_base,
            & toplevel_consts_12_name._ascii.ob_base,
            & toplevel_consts_20_names_1._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_22_names_1._ascii.ob_base,
            & toplevel_consts_23_names_1._ascii.ob_base,
            & toplevel_consts_24_names_1._ascii.ob_base,
            & toplevel_consts_25_names_1._ascii.ob_base,
            & toplevel_consts_26_names_1._ascii.ob_base,
            & toplevel_names_20._ascii.ob_base,
            & toplevel_names_21._ascii.ob_base,
            & toplevel_names_22._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_22_name._ascii.ob_base,
            & toplevel_consts_23_name._ascii.ob_base,
            & toplevel_consts_24_name._ascii.ob_base,
            & toplevel_consts_25_name._ascii.ob_base,
            & toplevel_consts_26_name._ascii.ob_base,
            & toplevel_consts_27_name._ascii.ob_base,
            & toplevel_consts_28_name._ascii.ob_base,
            & toplevel_consts_29_name._ascii.ob_base,
            & toplevel_names_33._ascii.ob_base,
            & toplevel_names_34._ascii.ob_base,
            & toplevel_names_35._ascii.ob_base,
            & toplevel_names_36._ascii.ob_base,
            & toplevel_names_37._ascii.ob_base,
            & toplevel_names_38._ascii.ob_base,
            & toplevel_names_39._ascii.ob_base,
            & toplevel_names_40._ascii.ob_base,
            & toplevel_names_41._ascii.ob_base,
            & toplevel_names_42._ascii.ob_base,
            & toplevel_names_43._ascii.ob_base,
            & toplevel_names_44._ascii.ob_base,
            & toplevel_names_45._ascii.ob_base,
            & toplevel_names_46._ascii.ob_base,
            & toplevel_names_47._ascii.ob_base,
            & toplevel_names_48._ascii.ob_base,
            & toplevel_names_49._ascii.ob_base,
            & toplevel_names_50._ascii.ob_base,
            & toplevel_names_51._ascii.ob_base,
            & toplevel_names_52._ascii.ob_base,
            & toplevel_names_53._ascii.ob_base,
            & toplevel_names_54._ascii.ob_base,
            & toplevel_names_55._ascii.ob_base,
            & toplevel_names_56._ascii.ob_base,
            & toplevel_names_57._ascii.ob_base,
            & toplevel_names_58._ascii.ob_base,
            & toplevel_names_59._ascii.ob_base,
            & toplevel_names_60._ascii.ob_base,
            & toplevel_names_61._ascii.ob_base,
            & toplevel_names_62._ascii.ob_base,
            & toplevel_names_63._ascii.ob_base,
            & toplevel_consts_58_names_0._ascii.ob_base,
            & toplevel_consts_58_name._ascii.ob_base,
            & toplevel_names_66._ascii.ob_base,
            & toplevel_names_67._ascii.ob_base,
            & toplevel_names_68._ascii.ob_base,
            & toplevel_names_69._ascii.ob_base,
            & toplevel_names_70._ascii.ob_base,
            & toplevel_names_71._ascii.ob_base,
            & toplevel_names_72._ascii.ob_base,
            & toplevel_names_73._ascii.ob_base,
            & toplevel_names_74._ascii.ob_base,
            & toplevel_names_75._ascii.ob_base,
            & toplevel_names_76._ascii.ob_base,
            & toplevel_names_77._ascii.ob_base,
            & toplevel_names_78._ascii.ob_base,
            & toplevel_names_79._ascii.ob_base,
            & toplevel_names_80._ascii.ob_base,
            & toplevel_names_81._ascii.ob_base,
            & toplevel_names_82._ascii.ob_base,
            & toplevel_names_83._ascii.ob_base,
            & toplevel_names_84._ascii.ob_base,
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
        char ob_sval[235];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 234,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x04\x07\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x04\x06\x06\x04\x09\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x02\x04\x01\x04\x01\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x04\x06\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x04\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x04\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x02\xfa\x08\x08\x08\x01\x0a\x01\x06\x01\x06\x01\x02\xfe\x08\x04\x08\x01\x0a\x01\x06\x01\x06\x01\x02\xfe\x08\x04\x08\x01\x0a\x01\x06\x01\x06\x01\x02\xfe\x04\xe9\x06\x1c\x04\x10\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x02\x04\x0c\x01\x02\x80\x08\x01\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[227];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 226,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x03\x04\x04\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x08\x06\x06\x04\x05\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x02\x04\x01\x04\x01\x06\x06\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x06\x04\x04\x04\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x04\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x06\x04\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x08\x01\x08\x02\x08\x01\x0a\x01\x06\x01\x08\x01\x08\x02\x08\x01\x0a\x01\x06\x01\x08\x01\x08\x02\x08\x01\x0a\x01\x06\x01\x08\x01\x02\x01\x02\xe6\x06\x26\x04\x06\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x04\x01\x02\x07\x0c\xfe\x02\x80\x02\x01\x0e\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[563];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 562,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x0c\x0d\x01\x08\x0c\x0d\x01\x07\x0c\x0d\x01\x07\x0c\x0d\x01\x09\x0c\x0d\x01\x07\x0c\x0d\x01\x07\x0c\x0d\x01\x08\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x01\x19\x01\x19\x01\x19\x01\x1b\x01\x1b\x01\x1b\x0c\x14\x01\x08\x0c\x14\x01\x08\x0c\x14\x01\x08\x0c\x14\x01\x08\x0c\x14\x01\x08\x0c\x14\x01\x08\x0c\x14\x01\x09\x0c\x0d\x01\x09\x0c\x0d\x01\x09\x0b\x0c\x01\x08\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x24\x01\x24\x01\x24\x01\x11\x01\x11\x01\x11\x01\x11\x01\x11\x01\x11\x01\x11\x01\x11\x01\x11\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x12\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0c\x12\x01\x09\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x0b\x11\x01\x08\x10\x1a\x01\x0a\x10\x1a\x01\x0d\x10\x1a\x01\x0a\x10\x1a\x01\x0a\x10\x1a\x01\x0c\x11\x1b\x01\x0e\x10\x1a\x01\x0a\x10\x1a\x01\x0c\x10\x1a\x01\x0d\x10\x1a\x01\x0a\x10\x1a\x01\x0c\x10\x1a\x01\x0c\x07\x0e\x18\x1b\x06\x1c\x07\x0f\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x05\x1d\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x0f\x16\x07\x16\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x05\x1d\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x0f\x16\x07\x16\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x05\x1d\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x18\x1b\x06\x1c\x05\x1e\x07\x0e\x0f\x16\x07\x16\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x07\x0e\x18\x1b\x06\x1c\x05\x1d\x13\x02\x01\x10\x01\x19\x01\x19\x01\x19\x1a\x1c\x01\x17\x1d\x21\x01\x1a\x19\x1b\x01\x16\x1c\x1e\x01\x19\x1c\x21\x01\x19\x19\x1a\x01\x16\x23\x28\x01\x20\x19\x1c\x01\x16\x26\x2a\x01\x23\x20\x26\x01\x1d\x1a\x1e\x01\x17\x1b\x1c\x01\x18\x20\x24\x01\x1d\x1e\x21\x01\x1b\x19\x1a\x01\x16\x1c\x1f\x01\x19\x1a\x1f\x01\x17\x01\x09\x05\x18\x05\x18\x05\x18\x05\x18\x05\x18\x05\x18\x00\x00\x08\x13\x01\x09\x01\x09\x01\x09\x05\x09\x05\x09\x05\x09\x01\x09\x00\x00\x00\x00\x00\x00",
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
    .ob_sval = "\xc4\x07\x04\x44\x0d\x00\xc4\x0d\x05\x44\x16\x03\xc4\x15\x01\x44\x16\x03",
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
    .co_stacksize = 13,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_names._object.ob_base.ob_base,
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
    .co_varnames = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_11_names._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_stat_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

