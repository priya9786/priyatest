#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1183];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1182,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x6d\x02\x5a\x02\x6d\x03\x5a\x03\x01\x00\x64\x01\x64\x03\x6c\x04\x5a\x04\x65\x05\x65\x06\x65\x07\x19\x00\xa9\x01\x5a\x08\x65\x05\x64\x04\xa9\x01\x5a\x09\x64\x05\x84\x00\x5a\x0a\x65\x05\x65\x0a\xa9\x01\x5a\x0b\x5b\x0a\x67\x00\x64\x06\xa2\x01\x5a\x0c\x64\x07\x5a\x0d\x65\x05\x65\x0e\x64\x08\xa9\x01\xa9\x01\x5a\x0f\x65\x05\x65\x0e\x65\x10\xa9\x00\xa9\x01\xa9\x01\x5a\x11\x65\x05\x65\x0e\x69\x00\xa0\x12\xa8\x00\xa9\x00\xa9\x01\xa9\x01\x5a\x13\x65\x05\x65\x0e\x69\x00\xa0\x14\xa8\x00\xa9\x00\xa9\x01\xa9\x01\x5a\x15\x65\x05\x65\x0e\x69\x00\xa0\x16\xa8\x00\xa9\x00\xa9\x01\xa9\x01\x5a\x17\x65\x05\x65\x0e\x67\x00\xa9\x01\xa9\x01\x5a\x18\x65\x05\x65\x0e\x65\x19\x67\x00\xa9\x01\xa9\x01\xa9\x01\x5a\x1a\x65\x05\x65\x0e\x65\x1b\x64\x01\xa9\x01\xa9\x01\xa9\x01\x5a\x1c\x65\x05\x65\x0e\x65\x1b\x64\x09\x64\x0a\x7a\x03\xa9\x01\xa9\x01\xa9\x01\x5a\x1d\x65\x05\x65\x0e\x65\x1e\xa9\x00\xa9\x01\xa9\x01\x5a\x1f\x65\x05\x65\x0e\x64\x0b\xa9\x01\xa9\x01\x5a\x20\x65\x05\x65\x0e\x64\x0c\xa9\x01\xa9\x01\x5a\x21\x65\x05\x65\x0e\x65\x22\xa9\x00\xa9\x01\xa9\x01\x5a\x23\x65\x05\x69\x00\xa0\x12\xa8\x00\xa9\x00\xa9\x01\x5a\x24\x65\x05\x69\x00\xa0\x14\xa8\x00\xa9\x00\xa9\x01\x5a\x25\x65\x05\x69\x00\xa0\x16\xa8\x00\xa9\x00\xa9\x01\x5a\x26\x65\x05\x65\x05\x6a\x27\xa9\x01\x5a\x28\x65\x05\x64\x0d\x84\x00\xa9\x00\xa9\x01\x5a\x29\x64\x0e\x84\x00\x5a\x2a\x65\x2a\xa9\x00\x5a\x2a\x65\x05\x65\x2a\xa9\x01\x5a\x2b\x65\x2a\xa0\x2c\xa8\x00\xa9\x00\x01\x00\x5b\x2a\x64\x0f\x84\x00\x5a\x2d\x65\x2d\xa9\x00\x5a\x2d\x65\x05\x65\x2d\xa9\x01\x5a\x2e\x5b\x2d\x64\x10\x84\x00\x5a\x2f\x47\x00\x64\x11\x84\x00\x64\x12\x65\x02\x64\x13\xaa\x03\x5a\x30\x47\x00\x64\x14\x84\x00\x64\x15\x65\x02\x64\x13\xaa\x03\x5a\x31\x47\x00\x64\x16\x84\x00\x64\x17\x65\x31\xa9\x03\x5a\x32\x65\x32\xa0\x33\x65\x2b\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x18\x84\x00\x64\x19\x65\x02\x64\x13\xaa\x03\x5a\x34\x47\x00\x64\x1a\x84\x00\x64\x1b\x65\x34\xa9\x03\x5a\x35\x47\x00\x64\x1c\x84\x00\x64\x1d\x65\x35\xa9\x03\x5a\x36\x65\x36\xa0\x33\x65\x2e\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x1e\x84\x00\x64\x1f\x65\x02\x64\x13\xaa\x03\x5a\x37\x47\x00\x64\x20\x84\x00\x64\x21\x65\x37\xa9\x03\x5a\x38\x65\x38\xa0\x33\x65\x0f\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x11\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x13\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x15\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x17\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x18\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x1a\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x1c\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x1d\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x1f\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x20\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x21\xa8\x01\xa9\x01\x01\x00\x65\x38\xa0\x33\x65\x23\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x22\x84\x00\x64\x23\x65\x37\xa9\x03\x5a\x39\x47\x00\x64\x24\x84\x00\x64\x25\x65\x38\xa9\x03\x5a\x3a\x65\x3a\xa0\x33\x65\x29\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x26\x84\x00\x64\x27\x65\x02\x64\x13\xaa\x03\x5a\x3b\x47\x00\x64\x28\x84\x00\x64\x29\x65\x02\x64\x13\xaa\x03\x5a\x3c\x47\x00\x64\x2a\x84\x00\x64\x2b\x65\x3b\x65\x37\x65\x3c\xa9\x05\x5a\x3d\x47\x00\x64\x2c\x84\x00\x64\x2d\x65\x08\xa9\x03\x5a\x3e\x64\x2e\x84\x00\x5a\x3f\x64\x2f\x84\x00\x5a\x40\x64\x30\x84\x00\x5a\x41\x47\x00\x64\x31\x84\x00\x64\x32\x65\x02\x64\x13\xaa\x03\x5a\x42\x47\x00\x64\x33\x84\x00\x64\x34\x65\x3d\xa9\x03\x5a\x43\x65\x43\xa0\x33\x65\x44\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x35\x84\x00\x64\x36\x65\x43\xa9\x03\x5a\x45\x65\x45\xa0\x33\x65\x1e\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x37\x84\x00\x64\x38\x65\x3d\xa9\x03\x5a\x46\x65\x46\xa0\x33\x65\x28\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x39\x84\x00\x64\x3a\x65\x3b\xa9\x03\x5a\x47\x47\x00\x64\x3b\x84\x00\x64\x3c\x65\x47\x65\x43\xa9\x04\x5a\x48\x65\x48\xa0\x33\x65\x24\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x3d\x84\x00\x64\x3e\x65\x47\x65\x43\xa9\x04\x5a\x49\x65\x49\xa0\x33\x65\x26\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x3f\x84\x00\x64\x40\x65\x47\x65\x3d\xa9\x04\x5a\x4a\x65\x4a\xa0\x33\x65\x25\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x41\x84\x00\x64\x42\x65\x46\xa9\x03\x5a\x4b\x65\x4b\xa0\x33\x65\x4c\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x43\x84\x00\x64\x44\x65\x39\x65\x3d\xa9\x04\x5a\x4d\x65\x4d\xa0\x33\x65\x4e\xa8\x01\xa9\x01\x01\x00\x65\x4d\xa0\x33\x65\x4f\xa8\x01\xa9\x01\x01\x00\x65\x4d\xa0\x33\x65\x1b\xa8\x01\xa9\x01\x01\x00\x65\x4d\xa0\x33\x65\x50\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x45\x84\x00\x64\x46\x65\x4d\xa9\x03\x5a\x51\x65\x51\xa0\x33\x65\x52\xa8\x01\xa9\x01\x01\x00\x65\x51\xa0\x33\x65\x10\xa8\x01\xa9\x01\x01\x00\x47\x00\x64\x47\x84\x00\x64\x48\x65\x4d\xa9\x03\x5a\x53\x65\x53\xa0\x33\x65\x06\xa8\x01\xa9\x01\x01\x00\x65\x53\xa0\x33\x65\x10\xa8\x01\xa9\x01\x01\x00\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[107];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 106,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x62\x73\x74\x72\x61\x63\x74\x20\x42\x61\x73\x65\x20\x43\x6c\x61\x73\x73\x65\x73\x20\x28\x41\x42\x43\x73\x29\x20\x66\x6f\x72\x20\x63\x6f\x6c\x6c\x65\x63\x74\x69\x6f\x6e\x73\x2c\x20\x61\x63\x63\x6f\x72\x64\x69\x6e\x67\x20\x74\x6f\x20\x50\x45\x50\x20\x33\x31\x31\x39\x2e\x0a\x0a\x55\x6e\x69\x74\x20\x74\x65\x73\x74\x73\x20\x61\x72\x65\x20\x69\x6e\x20\x74\x65\x73\x74\x5f\x63\x6f\x6c\x6c\x65\x63\x74\x69\x6f\x6e\x73\x2e\x0a",
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
        uint8_t _data[8];
    }
toplevel_consts_2_0 = {
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
        uint8_t _data[15];
    }
toplevel_consts_2_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x53\x00",
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
        }_object;
    }
toplevel_consts_5_names = {
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
        uint8_t _data[26];
    }
toplevel_consts_5_filename = {
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
    ._data = "<frozen _collections_abc>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_5_name = {
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
    ._data = "_f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_5_linetable = {
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
toplevel_consts_5_columntable = {
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
    .co_stacksize = 1,
    .co_firstlineno = 14,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_6_0 = {
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
    ._data = "Awaitable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_6_1 = {
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
    ._data = "Coroutine",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_6_2 = {
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
    ._data = "AsyncIterable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_6_3 = {
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
    ._data = "AsyncIterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_6_4 = {
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
    ._data = "AsyncGenerator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_5 = {
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
    ._data = "Hashable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_6 = {
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
    ._data = "Iterable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_7 = {
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
    ._data = "Iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_6_8 = {
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
    ._data = "Generator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_9 = {
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
    ._data = "Reversible",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_6_10 = {
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
    ._data = "Sized",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_6_11 = {
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
    ._data = "Container",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_12 = {
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
    ._data = "Callable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_13 = {
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
    ._data = "Collection",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_6_14 = {
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
    ._data = "Set",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_15 = {
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
    ._data = "MutableSet",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_6_16 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_6_17 = {
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
        uint8_t _data[12];
    }
toplevel_consts_6_18 = {
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
    ._data = "MappingView",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_19 = {
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
    ._data = "KeysView",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_6_20 = {
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
    ._data = "ItemsView",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_21 = {
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
    ._data = "ValuesView",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_6_22 = {
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
    ._data = "Sequence",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_6_23 = {
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
    ._data = "MutableSequence",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_24 = {
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
    ._data = "ByteString",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[25];
        }_object;
    }
toplevel_consts_6 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 25,
        },
        .ob_item = {
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_6_1._ascii.ob_base,
            & toplevel_consts_6_2._ascii.ob_base,
            & toplevel_consts_6_3._ascii.ob_base,
            & toplevel_consts_6_4._ascii.ob_base,
            & toplevel_consts_6_5._ascii.ob_base,
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_6_7._ascii.ob_base,
            & toplevel_consts_6_8._ascii.ob_base,
            & toplevel_consts_6_9._ascii.ob_base,
            & toplevel_consts_6_10._ascii.ob_base,
            & toplevel_consts_6_11._ascii.ob_base,
            & toplevel_consts_6_12._ascii.ob_base,
            & toplevel_consts_6_13._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_6_15._ascii.ob_base,
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_6_17._ascii.ob_base,
            & toplevel_consts_6_18._ascii.ob_base,
            & toplevel_consts_6_19._ascii.ob_base,
            & toplevel_consts_6_20._ascii.ob_base,
            & toplevel_consts_6_21._ascii.ob_base,
            & toplevel_consts_6_22._ascii.ob_base,
            & toplevel_consts_6_23._ascii.ob_base,
            & toplevel_consts_6_24._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_7 = {
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
    ._data = "collections.abc",
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
    .ob_digit = { 1 },
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
    .ob_digit = { 1000 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_11 = {
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
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x64\x00\x56\x00\x97\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_13_name = {
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
    ._data = "<lambda>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_13_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x1c\x21\x1c\x21\x1c\x21\x1c\x21",
};
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 62,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_13_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_13_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_14_name = {
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
    ._data = "_coro",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x06\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x01\x01\x01\x01",
};
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 64,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x64\x00\x56\x00\x97\x01\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_15_name = {
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
    ._data = "_ag",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x12\x17\x12\x17\x12\x17\x12\x17\x12\x17\x12\x17",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 515,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 70,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[77];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 76,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x02\x7c\x01\x44\x00\x5d\x1d\x7d\x03\x7c\x02\x44\x00\x5d\x14\x7d\x04\x7c\x03\x7c\x04\x6a\x01\x76\x00\x72\x1e\x7c\x04\x6a\x01\x7c\x03\x19\x00\x80\x1c\x74\x02\x02\x00\x01\x00\x02\x00\x01\x00\x53\x00\x01\x00\x6e\x05\x71\x0a\x74\x02\x02\x00\x01\x00\x53\x00\x71\x06\x64\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_16_consts = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_16_names_0 = {
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
    ._data = "__mro__",
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
    ._data = "__dict__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_16_names_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_16_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_16_names_0._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_16_varnames_0 = {
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
    ._data = "C",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_16_varnames_1 = {
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
    ._data = "methods",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_16_varnames_2 = {
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
    ._data = "mro",
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
    ._data = "method",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_16_varnames_4 = {
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
    ._data = "B",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_16_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_16_varnames_0._ascii.ob_base,
            & toplevel_consts_16_varnames_1._ascii.ob_base,
            & toplevel_consts_16_varnames_2._ascii.ob_base,
            & toplevel_consts_16_varnames_3._ascii.ob_base,
            & toplevel_consts_16_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_16_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x08\x01\x08\x01\x0a\x01\x0a\x01\x0c\x01\x04\x01\x02\xfd\x08\x05\x02\xfe\x04\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x01\x04\x07\x02\xf9\x02\x01\x04\x06\x02\xfa\x08\x01\x02\x03\x08\xfe\x0e\x01\x06\x01\x08\x02\x02\xfe\x04\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[77];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 76,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0c\x0b\x14\x05\x08\x13\x1a\x05\x22\x05\x22\x09\x0f\x12\x15\x09\x22\x09\x22\x0d\x0e\x10\x16\x1a\x1b\x1a\x24\x10\x24\x0d\x16\x14\x15\x14\x1e\x1f\x25\x14\x26\x11\x2a\x1c\x2a\x15\x2a\x15\x2a\x15\x2a\x15\x2a\x15\x2a\x11\x16\x11\x16\x0d\x16\x14\x22\x0d\x22\x0d\x22\x0d\x22\x11\x16\x0c\x10\x0c\x10",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_16_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 78,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x65\x06\x64\x03\x84\x00\xa9\x01\x5a\x07\x64\x04\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_17_consts_2_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_17_consts_2_consts = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_17_consts_2_varnames_0 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_17_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_17_consts_2_name = {
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
    ._data = "__hash__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_17_consts_2_qualname = {
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
    ._data = "Hashable.__hash__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_17_consts_2_linetable = {
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
toplevel_consts_17_consts_2_columntable = {
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
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_17_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_17_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 94,
    .co_code = & toplevel_consts_17_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_17_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_17_consts_3_code = {
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
toplevel_consts_17_consts_3_consts = {
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
            & toplevel_consts_17_consts_2_name._ascii.ob_base,
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
toplevel_consts_17_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_5._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_17_consts_3_varnames_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_17_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_16_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_17_consts_3_name = {
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
toplevel_consts_17_consts_3_qualname = {
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
    ._data = "Hashable.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_17_consts_3_linetable = {
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
toplevel_consts_17_consts_3_endlinetable = {
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
toplevel_consts_17_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1b\x0c\x1b\x09\x31\x14\x22\x23\x24\x26\x30\x14\x31\x0d\x31\x10\x1e\x09\x1e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_17_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_17_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 98,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_17_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_17_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_5._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_17_consts_2.ob_base,
            & toplevel_consts_17_consts_3.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_17_names_0 = {
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
toplevel_consts_17_names_1 = {
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
toplevel_consts_17_names_2 = {
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
        uint8_t _data[10];
    }
toplevel_consts_17_names_3 = {
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
    ._data = "__slots__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_17_names_6 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_17_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_17_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_17_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_17_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x04\x02\xfc\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x11\x05\x11\x06\x14\x05\x11\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 90,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_5._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_19_0 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_20_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x65\x06\x64\x03\x84\x00\xa9\x01\x5a\x07\x65\x06\x65\x08\xa9\x01\x5a\x09\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_consts_2_name = {
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
    ._data = "__await__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_20_consts_2_qualname = {
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
    ._data = "Awaitable.__await__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_20_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_20_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x09\x0e\x09\x0e\x09\x0e\x09\x0e\x09\x0e\x09\x0e",
};
static struct PyCodeObject toplevel_consts_20_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 109,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
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
            Py_None,
            & toplevel_consts_20_consts_2_name._ascii.ob_base,
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
toplevel_consts_20_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_20_consts_3_qualname = {
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
    ._data = "Awaitable.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_20_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1c\x0c\x1c\x09\x32\x14\x22\x23\x24\x26\x31\x14\x32\x0d\x32\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_20_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 113,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_20_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_20_consts_2.ob_base,
            & toplevel_consts_20_consts_3.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_20_names_8 = {
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
toplevel_consts_20_names_9 = {
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
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_20_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x02\x01\x0c\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_20_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x04\x02\xfc\x02\x04\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x0e\x05\x0e\x06\x14\x05\x0e\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 105,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_22_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x65\x04\x64\x07\x64\x04\x84\x01\xa9\x01\x5a\x06\x64\x05\x84\x00\x5a\x07\x65\x08\x64\x06\x84\x00\xa9\x01\x5a\x09\x64\x03\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_22_consts_2_code = {
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
        uint8_t _data[100];
    }
toplevel_consts_22_consts_2_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 99,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x65\x6e\x64\x20\x61\x20\x76\x61\x6c\x75\x65\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x20\x63\x6f\x72\x6f\x75\x74\x69\x6e\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_22_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_2_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_22_consts_2_names_0 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_22_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_consts_2_varnames_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_consts_2_name = {
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
    ._data = "send",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_22_consts_2_qualname = {
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
    ._data = "Coroutine.send",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_22_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_22_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_22_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 126,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_22_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x80\x0a\x7c\x03\x80\x07\x7c\x01\x82\x01\x7c\x01\xa9\x00\x7d\x02\x7c\x03\x81\x12\x7c\x02\xa0\x00\x7c\x03\xa8\x01\xa9\x01\x7d\x02\x7c\x02\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[104];
    }
toplevel_consts_22_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 103,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x61\x69\x73\x65\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x6e\x20\x74\x68\x65\x20\x63\x6f\x72\x6f\x75\x74\x69\x6e\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_22_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_4_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_22_consts_4_names_0 = {
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
    ._data = "with_traceback",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_22_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_4_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_22_consts_4_varnames_1 = {
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
    ._data = "typ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_22_consts_4_varnames_2 = {
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
    ._data = "val",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_22_consts_4_varnames_3 = {
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
toplevel_consts_22_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_22_consts_4_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_consts_4_name = {
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
    ._data = "throw",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_22_consts_4_qualname = {
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
    ._data = "Coroutine.throw",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x04\x01\x04\x01\x06\x01\x04\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x02\x03\x02\xfe\x06\x01\x06\x01\x02\x01\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_22_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x09\x18\x10\x12\x0d\x1a\x17\x1a\x11\x1a\x13\x16\x13\x18\x0d\x10\x0c\x0e\x09\x29\x13\x16\x13\x29\x26\x28\x13\x29\x13\x29\x0d\x10\x0f\x12\x09\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_22_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_22_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 133,
    .co_code = & toplevel_consts_22_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_22_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\xa0\x00\x74\x01\xa8\x01\xa9\x01\x01\x00\x74\x03\x64\x01\xa9\x01\x82\x01\x23\x00\x74\x01\x74\x02\x66\x02\x79\x15\x01\x00\x59\x00\x64\x02\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_22_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 46,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x61\x69\x73\x65\x20\x47\x65\x6e\x65\x72\x61\x74\x6f\x72\x45\x78\x69\x74\x20\x69\x6e\x73\x69\x64\x65\x20\x63\x6f\x72\x6f\x75\x74\x69\x6e\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_22_consts_5_consts_1 = {
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
    ._data = "coroutine ignored GeneratorExit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_22_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_22_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_22_consts_5_consts_1._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_22_consts_5_names_1 = {
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
    ._data = "GeneratorExit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_22_consts_5_names_3 = {
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
    ._data = "RuntimeError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_22_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_22_consts_5_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_22_consts_5_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_22_consts_5_qualname = {
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
    ._data = "Coroutine.close",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x03\x0c\x01\x08\x04\x02\x80\x0a\xfd\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_22_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x08\x0c\xfc\x08\x04\x02\x80\x06\xfd\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_22_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x42\x0d\x11\x0d\x26\x18\x25\x0d\x26\x0d\x26\x0d\x26\x13\x1f\x20\x41\x13\x42\x0d\x42\x00\x00\x11\x1e\x20\x2d\x10\x2e\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_22_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x06\x0c\x00\x8c\x06\x16\x03\x95\x01\x16\x03",
};
static struct PyCodeObject toplevel_consts_22_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_22_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 146,
    .co_code = & toplevel_consts_22_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_22_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x75\x00\x72\x0d\x74\x01\x7c\x01\x64\x01\x64\x02\x64\x03\x64\x04\xa9\x05\x53\x00\x74\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_22_consts_6_consts = {
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
            & toplevel_consts_20_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_name._ascii.ob_base,
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
            & toplevel_consts_6_1._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_22_consts_6_qualname = {
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
    ._data = "Coroutine.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_22_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_22_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_22_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1c\x0c\x1c\x09\x4c\x14\x22\x23\x24\x26\x31\x33\x39\x3b\x42\x44\x4b\x14\x4c\x0d\x4c\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_22_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 156,
    .co_code = & toplevel_consts_22_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_consts_7 = {
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
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_6_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_22_consts_2.ob_base,
            Py_None,
            & toplevel_consts_22_consts_4.ob_base,
            & toplevel_consts_22_consts_5.ob_base,
            & toplevel_consts_22_consts_6.ob_base,
            & toplevel_consts_22_consts_7._object.ob_base.ob_base,
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
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x06\x06\x01\x02\xff\x02\x01\x06\x0c\x02\x0a\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x05\x02\xfb\x02\x05\x02\x02\x02\x01\x04\x0a\x02\xf5\x02\x0b\x06\x0a\x02\x02\x04\x04\x02\xfc\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x1c\x05\x1c\x06\x14\x05\x1c\x06\x14\x1e\x22\x05\x12\x05\x12\x06\x14\x05\x12\x05\x42\x05\x42\x05\x42\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_22 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 122,
    .co_code = & toplevel_consts_22_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_24_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa9\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_24_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_24_consts_2_name = {
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
    ._data = "__aiter__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_24_consts_2_qualname = {
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
    ._data = "AsyncIterable.__aiter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_24_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_24_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1d\x10\x1f\x09\x1f",
};
static struct PyCodeObject toplevel_consts_24_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 170,
    .co_code = & toplevel_consts_24_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
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
            Py_None,
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
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
toplevel_consts_24_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_2._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_24_consts_3_qualname = {
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
    ._data = "AsyncIterable.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_24_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x20\x0c\x20\x09\x32\x14\x22\x23\x24\x26\x31\x14\x32\x0d\x32\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_24_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 174,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_24_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_2._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_24_consts_2.ob_base,
            & toplevel_consts_24_consts_3.ob_base,
            Py_None,
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
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_24_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x1f\x05\x1f\x06\x14\x05\x1f\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 166,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x64\x03\x84\x00\x5a\x06\x65\x07\x64\x04\x84\x00\xa9\x01\x5a\x08\x64\x05\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[65];
    }
toplevel_consts_26_consts_2_consts_0 = {
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
    ._data = "Return the next item or raise StopAsyncIteration when exhausted.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_26_consts_2_names_0 = {
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
    ._data = "StopAsyncIteration",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_consts_2_name = {
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
    ._data = "__anext__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_26_consts_2_qualname = {
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
    ._data = "AsyncIterator.__anext__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0f\x21\x09\x21",
};
static struct PyCodeObject toplevel_consts_26_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 187,
    .co_code = & toplevel_consts_26_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_3_code = {
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
        uint8_t _data[24];
    }
toplevel_consts_26_consts_3_qualname = {
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
    ._data = "AsyncIterator.__aiter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_26_consts_3_linetable = {
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
toplevel_consts_26_consts_3_columntable = {
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
static struct PyCodeObject toplevel_consts_26_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 192,
    .co_code = & toplevel_consts_26_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x75\x00\x72\x0b\x74\x01\x7c\x01\x64\x01\x64\x02\xa9\x03\x53\x00\x74\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_26_consts_4_consts = {
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
            & toplevel_consts_26_consts_2_name._ascii.ob_base,
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
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
toplevel_consts_26_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_3._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_26_consts_4_qualname = {
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
    ._data = "AsyncIterator.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x20\x0c\x20\x09\x3f\x14\x22\x23\x24\x26\x31\x33\x3e\x14\x3f\x0d\x3f\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_26_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 195,
    .co_code = & toplevel_consts_26_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_6_3._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_26_consts_2.ob_base,
            & toplevel_consts_26_consts_3.ob_base,
            & toplevel_consts_26_consts_4.ob_base,
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
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_26_consts_2_name._ascii.ob_base,
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x06\x04\x02\x03\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x06\x03\x02\x02\x04\x04\x02\xfc\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x21\x05\x21\x06\x14\x05\x21\x05\x14\x05\x14\x05\x14\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 183,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_28_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x05\x64\x08\x64\x05\x84\x01\xa9\x01\x5a\x07\x64\x06\x84\x00\x5a\x08\x65\x09\x64\x07\x84\x00\xa9\x01\x5a\x0a\x64\x04\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_28_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x49\x00\x64\x01\x7b\x02\x97\x03\x71\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[113];
    }
toplevel_consts_28_consts_2_consts_0 = {
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
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x6e\x65\x78\x74\x20\x69\x74\x65\x6d\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x61\x73\x79\x6e\x63\x68\x72\x6f\x6e\x6f\x75\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x57\x68\x65\x6e\x20\x65\x78\x68\x61\x75\x73\x74\x65\x64\x2c\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x41\x73\x79\x6e\x63\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_28_consts_2_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_28_consts_2_names_0 = {
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
    ._data = "asend",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_28_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_28_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_28_consts_2_qualname = {
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
    ._data = "AsyncGenerator.__anext__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_28_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x16\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_28_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x16\x1a\x16\x26\x21\x25\x16\x26\x16\x26\x10\x26\x10\x26\x10\x26\x10\x26\x10\x26\x09\x26",
};
static struct PyCodeObject toplevel_consts_28_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 206,
    .co_code = & toplevel_consts_28_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[118];
    }
toplevel_consts_28_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 117,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x65\x6e\x64\x20\x61\x20\x76\x61\x6c\x75\x65\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x20\x61\x73\x79\x6e\x63\x68\x72\x6f\x6e\x6f\x75\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x41\x73\x79\x6e\x63\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_28_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_28_consts_3_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_28_consts_3_qualname = {
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
    ._data = "AsyncGenerator.asend",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_28_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x05",
};
static struct PyCodeObject toplevel_consts_28_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 212,
    .co_code = & toplevel_consts_26_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_28_consts_2_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_28_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x02\x80\x0b\x7c\x03\x80\x08\x7c\x01\x82\x01\x7c\x01\xa9\x00\x7d\x02\x7c\x03\x81\x13\x7c\x02\xa0\x00\x7c\x03\xa8\x01\xa9\x01\x7d\x02\x7c\x02\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[122];
    }
toplevel_consts_28_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 121,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x61\x69\x73\x65\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x6e\x20\x74\x68\x65\x20\x61\x73\x79\x6e\x63\x68\x72\x6f\x6e\x6f\x75\x73\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x41\x73\x79\x6e\x63\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_28_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_28_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_5_name = {
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
    ._data = "athrow",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_28_consts_5_qualname = {
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
    ._data = "AsyncGenerator.athrow",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_28_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x05\x04\x01\x04\x01\x06\x01\x04\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_28_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x05\x02\x03\x02\xfe\x06\x01\x06\x01\x02\x01\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_28_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0c\x0f\x09\x18\x10\x12\x0d\x1a\x17\x1a\x11\x1a\x13\x16\x13\x18\x0d\x10\x0c\x0e\x09\x29\x13\x16\x13\x29\x26\x28\x13\x29\x13\x29\x0d\x10\x0f\x12\x09\x12",
};
static struct PyCodeObject toplevel_consts_28_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 219,
    .co_code = & toplevel_consts_28_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_28_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_28_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x09\x00\x7c\x00\xa0\x00\x74\x01\xa8\x01\xa9\x01\x49\x00\x64\x01\x7b\x02\x97\x03\x71\x0a\x01\x00\x74\x03\x64\x02\xa9\x01\x82\x01\x23\x00\x74\x01\x74\x02\x66\x02\x79\x1b\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_28_consts_6_consts_2 = {
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
    ._data = "asynchronous generator ignored GeneratorExit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_28_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_22_consts_5_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_28_consts_6_consts_2._ascii.ob_base,
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
toplevel_consts_28_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_28_consts_5_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_22_consts_5_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_28_consts_6_name = {
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
    ._data = "aclose",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_28_consts_6_qualname = {
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
    ._data = "AsyncGenerator.aclose",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_28_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x03\x16\x01\x08\x04\x02\x80\x0a\xfd\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_28_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x02\x08\x16\xfc\x08\x04\x02\x80\x06\xfd\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_28_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x09\x4f\x13\x17\x13\x2d\x1f\x2c\x13\x2d\x13\x2d\x0d\x2d\x0d\x2d\x0d\x2d\x0d\x2d\x0d\x2d\x0d\x2d\x13\x1f\x20\x4e\x13\x4f\x0d\x4f\x00\x00\x11\x1e\x20\x32\x10\x33\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x83\x0b\x12\x00\x92\x06\x1c\x03\x9b\x01\x1c\x03",
};
static struct PyCodeObject toplevel_consts_28_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_28_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 131,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 232,
    .co_code = & toplevel_consts_28_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_28_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_28_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x75\x00\x72\x0e\x74\x01\x7c\x01\x64\x01\x64\x02\x64\x03\x64\x04\x64\x05\xa9\x06\x53\x00\x74\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_28_consts_7_consts = {
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
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
            & toplevel_consts_26_consts_2_name._ascii.ob_base,
            & toplevel_consts_28_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_5_name._ascii.ob_base,
            & toplevel_consts_28_consts_6_name._ascii.ob_base,
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
toplevel_consts_28_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_4._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_28_consts_7_qualname = {
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
    ._data = "AsyncGenerator.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x08\x01\x06\x01\x04\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_28_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x02\x02\x08\xff\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_28_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x21\x0c\x21\x09\x3f\x14\x22\x23\x24\x26\x31\x33\x3e\x23\x2a\x2c\x34\x36\x3e\x14\x3f\x0d\x3f\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_28_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 242,
    .co_code = & toplevel_consts_28_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_28_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_28_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_6_4._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_28_consts_2.ob_base,
            & toplevel_consts_28_consts_3.ob_base,
            Py_None,
            & toplevel_consts_28_consts_5.ob_base,
            & toplevel_consts_28_consts_6.ob_base,
            & toplevel_consts_28_consts_7.ob_base,
            & toplevel_consts_22_consts_7._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_28_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_26_consts_2_name._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_28_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_28_consts_5_name._ascii.ob_base,
            & toplevel_consts_28_consts_6_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_28_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x02\x02\x06\x04\x01\x02\xff\x02\x01\x02\x06\x06\x01\x02\xff\x02\x01\x06\x0c\x02\x0a\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_28_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x06\x02\x02\x04\x05\x02\xfb\x02\x05\x02\x02\x02\x01\x04\x0a\x02\xf5\x02\x0b\x06\x0a\x02\x02\x04\x05\x02\xfb\x06\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_28_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x05\x26\x05\x26\x05\x26\x06\x14\x05\x21\x05\x21\x06\x14\x05\x21\x06\x14\x25\x29\x05\x12\x05\x12\x06\x14\x05\x12\x05\x4f\x05\x4f\x05\x4f\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_28 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_28_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_28_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 202,
    .co_code = & toplevel_consts_28_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_28_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_30_consts_2_name = {
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
toplevel_consts_30_consts_2_qualname = {
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
    ._data = "Iterable.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_30_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_30_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0f\x14\x0f\x14",
};
static struct PyCodeObject toplevel_consts_30_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 257,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_30_consts_3_consts = {
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
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
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
toplevel_consts_30_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_30_consts_3_qualname = {
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
    ._data = "Iterable.__subclasshook__",
};
static struct PyCodeObject toplevel_consts_30_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 262,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_30_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_30_consts_2.ob_base,
            & toplevel_consts_30_consts_3.ob_base,
            Py_None,
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
toplevel_consts_30_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_30_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x04\x04\x01\x02\xff\x02\x01\x0c\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_30_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x04\x04\x02\xfc\x02\x04\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_30_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x17\x05\x17\x06\x14\x05\x17\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_30 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 253,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[76];
    }
toplevel_consts_32_consts_2_consts_0 = {
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
    ._data = "Return the next item from the iterator. When exhausted, raise StopIteration",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_32_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_32_consts_2_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_32_consts_2_name = {
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
        uint8_t _data[18];
    }
toplevel_consts_32_consts_2_qualname = {
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
    ._data = "Iterator.__next__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_32_consts_2_linetable = {
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
static struct PyCodeObject toplevel_consts_32_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_32_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 275,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_32_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_32_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_32_consts_3_qualname = {
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
    ._data = "Iterator.__iter__",
};
static struct PyCodeObject toplevel_consts_32_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 280,
    .co_code = & toplevel_consts_26_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_32_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_32_consts_4_consts = {
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
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_32_consts_2_name._ascii.ob_base,
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
toplevel_consts_32_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_7._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_32_consts_4_qualname = {
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
    ._data = "Iterator.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_32_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1b\x0c\x1b\x09\x3d\x14\x22\x23\x24\x26\x30\x32\x3c\x14\x3d\x0d\x3d\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_32_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_32_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_32_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 283,
    .co_code = & toplevel_consts_26_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_32_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_32_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_32_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_6_7._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_32_consts_2.ob_base,
            & toplevel_consts_32_consts_3.ob_base,
            & toplevel_consts_32_consts_4.ob_base,
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
toplevel_consts_32_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_32_consts_2_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_32_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x1c\x05\x1c\x06\x14\x05\x1c\x05\x14\x05\x14\x05\x14\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_32 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_32_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_32_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 271,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_7._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_32_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_34_consts_2_name = {
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
    ._data = "__reversed__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_34_consts_2_qualname = {
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
    ._data = "Reversible.__reversed__",
};
static struct PyCodeObject toplevel_consts_34_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 310,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_34_consts_3_consts = {
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
            & toplevel_consts_34_consts_2_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
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
toplevel_consts_34_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_9._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_34_consts_3_qualname = {
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
    ._data = "Reversible.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_34_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1d\x0c\x1d\x09\x41\x14\x22\x23\x24\x26\x34\x36\x40\x14\x41\x0d\x41\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_34_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_34_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_34_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 315,
    .co_code = & toplevel_consts_26_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_34_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_9._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_34_consts_2.ob_base,
            & toplevel_consts_34_consts_3.ob_base,
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
toplevel_consts_34_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_34_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_34_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x04\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_34_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x04\x04\x02\xfc\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_34_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x17\x05\x17\x06\x14\x05\x17\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_34 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_34_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_34_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 306,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_9._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_9._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_36_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[95];
    }
toplevel_consts_36_consts_2_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 94,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x6e\x65\x78\x74\x20\x69\x74\x65\x6d\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x57\x68\x65\x6e\x20\x65\x78\x68\x61\x75\x73\x74\x65\x64\x2c\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_36_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_36_consts_2_consts_0._ascii.ob_base,
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
toplevel_consts_36_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_2_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_36_consts_2_qualname = {
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
    ._data = "Generator.__next__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_36_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_36_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1f\x1a\x1e\x10\x1f\x10\x1f\x09\x1f",
};
static struct PyCodeObject toplevel_consts_36_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_36_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_36_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 326,
    .co_code = & toplevel_consts_36_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_32_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_36_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_36_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_36_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_36_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[100];
    }
toplevel_consts_36_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 99,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x65\x6e\x64\x20\x61\x20\x76\x61\x6c\x75\x65\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_36_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_36_consts_3_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_36_consts_3_qualname = {
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
    ._data = "Generator.send",
};
static struct PyCodeObject toplevel_consts_36_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 332,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_36_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[104];
    }
toplevel_consts_36_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 103,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x61\x69\x73\x65\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x6e\x20\x74\x68\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x20\x6e\x65\x78\x74\x20\x79\x69\x65\x6c\x64\x65\x64\x20\x76\x61\x6c\x75\x65\x20\x6f\x72\x20\x72\x61\x69\x73\x65\x20\x53\x74\x6f\x70\x49\x74\x65\x72\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_36_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_36_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_36_consts_5_qualname = {
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
    ._data = "Generator.throw",
};
static struct PyCodeObject toplevel_consts_36_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 339,
    .co_code = & toplevel_consts_22_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_36_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_36_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 46,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x61\x69\x73\x65\x20\x47\x65\x6e\x65\x72\x61\x74\x6f\x72\x45\x78\x69\x74\x20\x69\x6e\x73\x69\x64\x65\x20\x67\x65\x6e\x65\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_36_consts_6_consts_1 = {
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
    ._data = "generator ignored GeneratorExit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_36_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_36_consts_6_consts_0._ascii.ob_base,
            & toplevel_consts_36_consts_6_consts_1._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_36_consts_6_qualname = {
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
    ._data = "Generator.close",
};
static struct PyCodeObject toplevel_consts_36_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_22_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 352,
    .co_code = & toplevel_consts_22_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_36_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_36_consts_7_consts = {
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
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_32_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_name._ascii.ob_base,
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
toplevel_consts_36_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_8._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_36_consts_7_qualname = {
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
    ._data = "Generator.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_36_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1c\x0c\x1c\x09\x3c\x14\x22\x23\x24\x26\x30\x32\x3c\x23\x29\x2b\x32\x34\x3b\x14\x3c\x0d\x3c\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_36_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_36_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 362,
    .co_code = & toplevel_consts_28_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_36_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_36_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_36_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_6_8._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_36_consts_2.ob_base,
            & toplevel_consts_36_consts_3.ob_base,
            Py_None,
            & toplevel_consts_36_consts_5.ob_base,
            & toplevel_consts_36_consts_6.ob_base,
            & toplevel_consts_36_consts_7.ob_base,
            & toplevel_consts_22_consts_7._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_36_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_32_consts_2_name._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_name._ascii.ob_base,
            & toplevel_consts_22_consts_4_name._ascii.ob_base,
            & toplevel_consts_22_consts_5_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_36_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x05\x1f\x05\x1f\x05\x1f\x06\x14\x05\x1c\x05\x1c\x06\x14\x05\x1c\x06\x14\x1e\x22\x05\x12\x05\x12\x06\x14\x05\x12\x05\x42\x05\x42\x05\x42\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_36 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_36_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_28_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 322,
    .co_code = & toplevel_consts_28_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_8._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_8._ascii.ob_base,
    .co_linetable = & toplevel_consts_28_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_28_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_36_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_38_consts_2_name = {
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
        uint8_t _data[14];
    }
toplevel_consts_38_consts_2_qualname = {
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
    ._data = "Sized.__len__",
};
static struct PyCodeObject toplevel_consts_38_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 377,
    .co_code = & toplevel_consts_17_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_38_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_38_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_38_consts_3_consts = {
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
            & toplevel_consts_38_consts_2_name._ascii.ob_base,
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
toplevel_consts_38_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_10._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_38_consts_3_qualname = {
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
    ._data = "Sized.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_38_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x18\x0c\x18\x09\x30\x14\x22\x23\x24\x26\x2f\x14\x30\x0d\x30\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_38_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_38_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_38_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 381,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_38_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_38_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_38_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_10._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_38_consts_2.ob_base,
            & toplevel_consts_38_consts_3.ob_base,
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
toplevel_consts_38_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_38_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
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
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 373,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_10._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_10._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_40_consts_2_consts = {
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
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_40_consts_2_varnames_1 = {
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
toplevel_consts_40_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_40_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_40_consts_2_name = {
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
    ._data = "__contains__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_40_consts_2_qualname = {
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
    ._data = "Container.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_40_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x15\x10\x15",
};
static struct PyCodeObject toplevel_consts_40_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 392,
    .co_code = & toplevel_consts_17_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_40_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_40_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_40_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_40_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_40_consts_3_consts = {
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
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
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
toplevel_consts_40_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_11._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_40_consts_3_qualname = {
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
    ._data = "Container.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_40_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1c\x0c\x1c\x09\x35\x14\x22\x23\x24\x26\x34\x14\x35\x0d\x35\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_40_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_40_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 396,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_40_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_40_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_40_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_11._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_40_consts_2.ob_base,
            & toplevel_consts_40_consts_3.ob_base,
            Py_None,
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
toplevel_consts_40_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_40_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x15\x05\x15\x06\x14\x05\x15\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_40 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_40_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 388,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_11._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_11._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_40_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_42_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x64\x03\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_42_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x75\x00\x72\x0c\x74\x01\x7c\x01\x64\x01\x64\x02\x64\x03\xa9\x04\x53\x00\x74\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_42_consts_2_consts = {
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
            & toplevel_consts_38_consts_2_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
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
toplevel_consts_42_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_13._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_42_consts_2_qualname = {
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
    ._data = "Collection.__subclasshook__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_42_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_42_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_42_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0f\x13\x1d\x0c\x1d\x09\x4d\x14\x22\x23\x24\x27\x30\x32\x3c\x3e\x4c\x14\x4d\x0d\x4d\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_42_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_42_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_42_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_42_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 409,
    .co_code = & toplevel_consts_42_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_42_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_42_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_42_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_42_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_42_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_13._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_42_consts_2.ob_base,
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
toplevel_consts_42_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_42_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_42_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x04\x02\xfc\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_42_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x05\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_42 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_42_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_42_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_42_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 405,
    .co_code = & toplevel_consts_42_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_13._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_13._ascii.ob_base,
    .co_linetable = & toplevel_consts_42_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_42_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_42_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_44_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x88\x00\x66\x01\x64\x03\x84\x08\x5a\x05\x65\x06\x64\x04\x84\x00\xa9\x01\x5a\x07\x88\x00\x66\x01\x64\x05\x84\x08\x5a\x08\x64\x06\x84\x00\x5a\x09\x64\x07\x84\x00\x5a\x0a\x88\x00\x04\x00\x5a\x0b\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_44_consts_0 = {
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
    ._data = "_CallableGenericAlias",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[253];
    }
toplevel_consts_44_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 252,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x52\x65\x70\x72\x65\x73\x65\x6e\x74\x20\x60\x43\x61\x6c\x6c\x61\x62\x6c\x65\x5b\x61\x72\x67\x74\x79\x70\x65\x73\x2c\x20\x72\x65\x73\x75\x6c\x74\x74\x79\x70\x65\x5d\x60\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x73\x65\x74\x73\x20\x60\x60\x5f\x5f\x61\x72\x67\x73\x5f\x5f\x60\x60\x20\x74\x6f\x20\x61\x20\x74\x75\x70\x6c\x65\x20\x63\x6f\x6e\x74\x61\x69\x6e\x69\x6e\x67\x20\x74\x68\x65\x20\x66\x6c\x61\x74\x74\x65\x6e\x65\x64\x20\x60\x60\x61\x72\x67\x74\x79\x70\x65\x73\x60\x60\x0a\x20\x20\x20\x20\x66\x6f\x6c\x6c\x6f\x77\x65\x64\x20\x62\x79\x20\x60\x60\x72\x65\x73\x75\x6c\x74\x74\x79\x70\x65\x60\x60\x2e\x0a\x0a\x20\x20\x20\x20\x45\x78\x61\x6d\x70\x6c\x65\x3a\x20\x60\x60\x43\x61\x6c\x6c\x61\x62\x6c\x65\x5b\x5b\x69\x6e\x74\x2c\x20\x73\x74\x72\x5d\x2c\x20\x66\x6c\x6f\x61\x74\x5d\x60\x60\x20\x73\x65\x74\x73\x20\x60\x60\x5f\x5f\x61\x72\x67\x73\x5f\x5f\x60\x60\x20\x74\x6f\x0a\x20\x20\x20\x20\x60\x60\x28\x69\x6e\x74\x2c\x20\x73\x74\x72\x2c\x20\x66\x6c\x6f\x61\x74\x29\x60\x60\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[109];
    }
toplevel_consts_44_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x7c\x02\x74\x01\xa9\x02\x72\x0d\x74\x02\x7c\x02\xa9\x01\x64\x01\x6b\x02\x73\x11\x74\x03\x64\x02\xa9\x01\x82\x01\x7c\x02\x5c\x02\x7d\x03\x7d\x04\x74\x00\x7c\x03\x74\x04\xa9\x02\x72\x22\x67\x00\x7c\x03\xa2\x01\x7c\x04\x91\x01\x52\x00\x7d\x02\x6e\x0b\x74\x05\x7c\x03\xa9\x01\x73\x2d\x74\x03\x64\x03\x7c\x03\x9b\x00\x9d\x02\xa9\x01\x82\x01\x74\x06\xa9\x00\xa0\x07\x7c\x00\x7c\x01\x7c\x02\xa8\x03\xa9\x03\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_44_consts_3_consts_1 = {
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
        uint8_t _data[55];
    }
toplevel_consts_44_consts_3_consts_2 = {
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
    ._data = "Callable must be used as Callable[[arg, ...], result].",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[71];
    }
toplevel_consts_44_consts_3_consts_3 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 70,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Expected a list of types, an ellipsis, ParamSpec, or Concatenate. Got ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_44_consts_3_consts = {
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
            & toplevel_consts_44_consts_3_consts_1.ob_base.ob_base,
            & toplevel_consts_44_consts_3_consts_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_44_consts_3_names_0 = {
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
toplevel_consts_44_consts_3_names_1 = {
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
toplevel_consts_44_consts_3_names_2 = {
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
        uint8_t _data[10];
    }
toplevel_consts_44_consts_3_names_3 = {
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
        uint8_t _data[5];
    }
toplevel_consts_44_consts_3_names_4 = {
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
        uint8_t _data[15];
    }
toplevel_consts_44_consts_3_names_5 = {
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
    ._data = "_is_param_expr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_44_consts_3_names_6 = {
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
    ._data = "super",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_44_consts_3_names_7 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_44_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_consts_3_varnames_1 = {
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
    ._data = "origin",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_44_consts_3_varnames_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_consts_3_varnames_3 = {
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
    ._data = "t_args",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_3_varnames_4 = {
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
    ._data = "t_result",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_44_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_17_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_3._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_44_consts_3_freevars_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_44_consts_3_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_44_consts_3_qualname = {
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
    ._data = "_CallableGenericAlias.__new__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_44_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x16\x01\x02\x01\x02\x01\x04\xff\x08\x02\x0a\x01\x10\x01\x08\x01\x04\x01\x02\x01\x08\xff\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_44_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x01\x02\x02\x0a\xfe\x02\x02\x02\xff\x06\x01\x08\x01\x08\x01\x02\x04\x10\xfd\x06\x01\x02\x02\x02\xff\x0c\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[109];
    }
toplevel_consts_44_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x11\x1b\x1c\x20\x22\x27\x11\x28\x09\x4a\x2d\x30\x31\x35\x2d\x36\x3a\x3b\x2d\x3b\x09\x4a\x13\x1c\x11\x49\x13\x4a\x0d\x4a\x1c\x20\x09\x19\x09\x0f\x11\x19\x0c\x16\x17\x1d\x1f\x23\x0c\x24\x09\x48\x14\x27\x16\x1c\x14\x27\x1e\x26\x14\x27\x14\x27\x0d\x11\x0d\x11\x12\x20\x21\x27\x12\x28\x09\x48\x13\x1c\x1d\x47\x3f\x45\x1d\x47\x1d\x47\x13\x48\x0d\x48\x10\x15\x10\x17\x10\x32\x20\x23\x25\x2b\x2d\x31\x10\x32\x10\x32\x09\x32",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_44_consts_3_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_17_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_3._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_4._ascii.ob_base,
            & toplevel_consts_44_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_44_consts_3_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x20\x20\x20\x80",
};
static struct PyCodeObject toplevel_consts_44_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 428,
    .co_code = & toplevel_consts_44_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_3_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_3_names_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_44_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_44_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_44_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7d\x01\x7c\x00\x6a\x00\x44\x00\x5d\x1f\x7d\x02\x74\x01\x7c\x02\x64\x01\xa9\x02\x72\x1b\x74\x02\x7c\x02\x6a\x03\x74\x04\xa9\x02\x72\x1b\x7c\x01\xa0\x05\x7c\x02\x6a\x03\xa8\x01\xa9\x01\x01\x00\x71\x06\x74\x06\x7c\x02\xa9\x01\x72\x25\x7c\x01\xa0\x07\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x06\x74\x04\x74\x08\xa0\x09\x7c\x01\xa8\x01\xa9\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_44_consts_4_consts_1 = {
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
    ._data = "__parameters__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_44_consts_4_consts = {
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
            & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_4_names_0 = {
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
    ._data = "__args__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_44_consts_4_names_1 = {
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
toplevel_consts_44_consts_4_names_5 = {
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
        uint8_t _data[16];
    }
toplevel_consts_44_consts_4_names_6 = {
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
    ._data = "_is_typevarlike",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_consts_4_names_7 = {
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
toplevel_consts_44_consts_4_names_8 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_4_names_9 = {
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
    ._data = "fromkeys",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_44_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_44_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_7._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_consts_4_varnames_1 = {
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
    ._data = "params",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_44_consts_4_varnames_2 = {
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
    ._data = "arg",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_44_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_4_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[37];
    }
toplevel_consts_44_consts_4_qualname = {
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
    ._data = "_CallableGenericAlias.__parameters__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_44_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x0a\x01\x16\x02\x10\x01\x08\x02\x0c\x01\x02\x80\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_44_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x04\x01\x04\x06\x02\xfa\x08\x02\x02\x04\x0a\xfc\x02\x04\x10\xfd\x06\x02\x0e\x01\x02\x80\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_44_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x14\x09\x0f\x14\x18\x14\x21\x09\x27\x09\x27\x0d\x10\x10\x17\x18\x1b\x1d\x2d\x10\x2e\x0d\x27\x33\x3d\x3e\x41\x3e\x50\x52\x57\x33\x58\x0d\x27\x11\x17\x11\x32\x1f\x22\x1f\x31\x11\x32\x11\x32\x11\x32\x11\x32\x14\x23\x24\x27\x14\x28\x11\x27\x15\x1b\x15\x27\x23\x26\x15\x27\x15\x27\x15\x27\x00\x00\x10\x15\x16\x1a\x16\x2b\x24\x2a\x16\x2b\x16\x2b\x10\x2c\x09\x2c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_44_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_44_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 440,
    .co_code = & toplevel_consts_44_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_44_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x64\x01\x6b\x02\x72\x16\x74\x02\x7c\x00\x6a\x01\x64\x02\x19\x00\xa9\x01\x72\x16\x74\x03\xa9\x00\xa0\x04\xa8\x00\xa9\x00\x53\x00\x64\x03\x64\x04\xa0\x05\x64\x05\x84\x00\x7c\x00\x6a\x01\x64\x00\x64\x06\x85\x02\x19\x00\x44\x00\xa9\x01\xa8\x01\xa9\x01\x9b\x00\x64\x07\x74\x06\x7c\x00\x6a\x01\x64\x06\x19\x00\xa9\x01\x9b\x00\x64\x08\x9d\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_44_consts_5_consts_3 = {
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
    ._data = "collections.abc.Callable[[",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_44_consts_5_consts_4 = {
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
        char ob_sval[23];
    }
toplevel_consts_44_consts_5_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x67\x00\x7c\x00\x5d\x06\x7d\x01\x74\x00\x7c\x01\xa9\x01\x91\x02\x71\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_44_consts_5_consts_5_names_0 = {
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
    ._data = "_type_repr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_44_consts_5_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_44_consts_5_consts_5_varnames_0 = {
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
toplevel_consts_44_consts_5_consts_5_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_44_consts_5_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_44_consts_5_consts_5_name = {
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
        uint8_t _data[51];
    }
toplevel_consts_44_consts_5_consts_5_qualname = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 50,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "_CallableGenericAlias.__repr__.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_44_consts_5_consts_5_linetable = {
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
toplevel_consts_44_consts_5_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x20\x4b\x20\x4b\x20\x4b\x33\x34\x21\x2b\x2c\x2d\x21\x2e\x20\x4b\x20\x4b\x20\x4b",
};
static struct PyCodeObject toplevel_consts_44_consts_5_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_5_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_5_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 456,
    .co_code = & toplevel_consts_44_consts_5_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_5_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_5_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_5_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_5_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_5_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_5_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_consts_5_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_44_consts_5_consts_6 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_44_consts_5_consts_7 = {
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
    ._data = "], ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_44_consts_5_consts_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_44_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_44_consts_3_consts_1.ob_base.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_44_consts_5_consts_3._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_4._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_5.ob_base,
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
            & toplevel_consts_44_consts_5_consts_7._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_5_names_4 = {
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
        uint8_t _data[5];
    }
toplevel_consts_44_consts_5_names_5 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_44_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_5_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_44_consts_5_qualname = {
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
    ._data = "_CallableGenericAlias.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_44_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x1c\x01\x0c\x01\x02\x01\x1c\x01\x04\xff\x0c\x02\x08\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_44_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0c\x01\x02\x01\x0c\xff\x0e\x01\x02\x03\x1c\xff\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_44_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0c\x0f\x10\x14\x10\x1d\x0c\x1e\x22\x23\x0c\x23\x09\x26\x28\x36\x37\x3b\x37\x44\x45\x46\x37\x47\x28\x48\x09\x26\x14\x19\x14\x1b\x14\x26\x14\x26\x14\x26\x0d\x26\x11\x34\x16\x1a\x16\x4c\x20\x4b\x20\x4b\x38\x3c\x38\x45\x46\x49\x47\x49\x46\x49\x38\x4a\x20\x4b\x20\x4b\x16\x4c\x16\x4c\x11\x34\x11\x34\x14\x1e\x1f\x23\x1f\x2c\x2d\x2f\x1f\x30\x14\x31\x11\x34\x11\x34\x11\x34\x09\x35",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_44_consts_5_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_44_consts_5_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_44_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 452,
    .co_code = & toplevel_consts_44_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_5_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_5_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_44_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_44_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x01\x74\x01\x7c\x01\xa9\x01\x64\x01\x6b\x02\x72\x10\x74\x02\x7c\x01\x64\x02\x19\x00\xa9\x01\x73\x1c\x74\x03\x7c\x01\x64\x00\x64\x03\x85\x02\x19\x00\xa9\x01\x7c\x01\x64\x03\x19\x00\x66\x02\x7d\x01\x74\x04\x74\x05\x7c\x01\x66\x02\x66\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_44_consts_6_consts = {
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
            & toplevel_consts_44_consts_3_consts_1.ob_base.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
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
toplevel_consts_44_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_44_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_6_12._ascii.ob_base,
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
toplevel_consts_44_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_44_consts_6_name = {
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
    ._data = "__reduce__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_44_consts_6_qualname = {
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
    ._data = "_CallableGenericAlias.__reduce__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_44_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x18\x01\x18\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_44_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0a\x01\x02\x01\x0a\xff\x1a\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_44_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1d\x09\x0d\x11\x14\x15\x19\x11\x1a\x1e\x1f\x11\x1f\x09\x2d\x24\x32\x33\x37\x38\x39\x33\x3a\x24\x3b\x09\x2d\x14\x18\x19\x1d\x1e\x21\x1f\x21\x1e\x21\x19\x22\x14\x23\x25\x29\x2a\x2c\x25\x2d\x14\x2d\x0d\x11\x10\x25\x28\x30\x32\x36\x27\x37\x10\x37\x09\x37",
};
static struct PyCodeObject toplevel_consts_44_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 459,
    .co_code = & toplevel_consts_44_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[379];
    }
toplevel_consts_44_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 378,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x0a\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x7d\x02\x7c\x02\x64\x01\x6b\x02\x72\x12\x74\x02\x7c\x00\x9b\x00\x64\x02\x9d\x02\xa9\x01\x82\x01\x74\x03\x7c\x01\x74\x04\xa9\x02\x73\x1a\x7c\x01\x66\x01\x7d\x01\x7c\x02\x64\x03\x6b\x02\x72\x32\x74\x05\x7c\x00\x6a\x01\x64\x01\x19\x00\xa9\x01\x72\x32\x7c\x01\x72\x32\x74\x05\x7c\x01\x64\x01\x19\x00\xa9\x01\x73\x32\x74\x06\x7c\x01\xa9\x01\x66\x01\x7d\x01\x74\x00\x7c\x01\xa9\x01\x7d\x03\x7c\x03\x7c\x02\x6b\x03\x72\x50\x74\x02\x64\x04\x7c\x03\x7c\x02\x6b\x04\x72\x42\x64\x05\x6e\x01\x64\x06\x9b\x00\x64\x07\x7c\x00\x9b\x00\x64\x08\x7c\x03\x9b\x00\x64\x09\x7c\x02\x9b\x00\x9d\x08\xa9\x01\x82\x01\x74\x07\x74\x08\x7c\x00\x6a\x01\x7c\x01\xa9\x02\xa9\x01\x8a\x0a\x67\x00\x7d\x04\x7c\x00\x6a\x09\x44\x00\x5d\x43\x7d\x05\x74\x0a\x7c\x05\xa9\x01\x72\x7c\x74\x05\x7c\x05\xa9\x01\x72\x77\x89\x0a\x7c\x05\x19\x00\x7d\x05\x74\x05\x7c\x05\xa9\x01\x73\x76\x74\x02\x64\x0a\x7c\x05\x9b\x00\x9d\x02\xa9\x01\x82\x01\x6e\x23\x89\x0a\x7c\x05\x19\x00\x7d\x05\x6e\x1e\x74\x0b\x7c\x05\x64\x0b\xa9\x02\x72\x9a\x74\x03\x7c\x05\x6a\x01\x74\x04\xa9\x02\x72\x9a\x7c\x05\x6a\x01\x7d\x06\x7c\x06\x72\x9a\x74\x04\x88\x0a\x66\x01\x64\x0c\x84\x08\x7c\x06\x44\x00\xa9\x01\xa9\x01\x7d\x07\x7c\x05\x7c\x07\x19\x00\x7d\x05\x7c\x04\xa0\x0c\x7c\x05\xa8\x01\xa9\x01\x01\x00\x71\x5d\x74\x03\x7c\x04\x64\x01\x19\x00\x74\x06\xa9\x02\x73\xb6\x7c\x04\x64\x0d\x19\x00\x7d\x08\x7c\x04\x64\x00\x64\x0d\x85\x02\x19\x00\x7d\x09\x7c\x09\x7c\x08\x66\x02\x7d\x04\x74\x0d\x74\x0e\x74\x04\x7c\x04\xa9\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_44_consts_7_consts_2 = {
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
    ._data = " is not a generic class",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_44_consts_7_consts_4 = {
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
    ._data = "Too ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_44_consts_7_consts_5 = {
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
    ._data = "many",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_44_consts_7_consts_6 = {
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
    ._data = "few",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_44_consts_7_consts_7 = {
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
    ._data = " arguments for ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_44_consts_7_consts_8 = {
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
    ._data = "; actual ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_44_consts_7_consts_9 = {
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
    ._data = ", expected ",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_44_consts_7_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x08\x7d\x01\x89\x02\x7c\x01\x19\x00\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_44_consts_7_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_40_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_44_consts_7_consts_12_freevars_0 = {
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
    ._data = "subst",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_44_consts_7_consts_12_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_consts_7_consts_12_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_44_consts_7_consts_12_name = {
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
        uint8_t _data[53];
    }
toplevel_consts_44_consts_7_consts_12_qualname = {
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
    ._data = "_CallableGenericAlias.__getitem__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_44_consts_7_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x1a\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_44_consts_7_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x24\x41\x24\x41\x32\x33\x25\x2a\x2b\x2c\x25\x2d\x24\x41\x24\x41\x24\x41\x24\x41\x24\x41\x24\x41",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_44_consts_7_consts_12_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_40_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_12_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_44_consts_7_consts_12_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_44_consts_7_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_7_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 501,
    .co_code = & toplevel_consts_44_consts_7_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_7_consts_12_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_7_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_7_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_7_consts_12_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_7_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_44_consts_7_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_44_consts_7_consts_12_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_44_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_44_consts_7_consts_2._ascii.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
            & toplevel_consts_44_consts_7_consts_4._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_5._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_6._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_7._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_8._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_9._ascii.ob_base,
            & toplevel_consts_44_consts_3_consts_3._ascii.ob_base,
            & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_12.ob_base,
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_44_consts_7_names_8 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_44_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_44_consts_7_names_8._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_7._ascii.ob_base,
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_6_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_44_consts_7_varnames_1 = {
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
        uint8_t _data[10];
    }
toplevel_consts_44_consts_7_varnames_2 = {
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
    ._data = "param_len",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_7_varnames_3 = {
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
    ._data = "item_len",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_44_consts_7_varnames_4 = {
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
    ._data = "new_args",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_44_consts_7_varnames_6 = {
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
    ._data = "subparams",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_44_consts_7_varnames_7 = {
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
    ._data = "subargs",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_44_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_3._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_4._ascii.ob_base,
            & toplevel_consts_44_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_6._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_7._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_4._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_44_consts_7_name = {
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
        uint8_t _data[34];
    }
toplevel_consts_44_consts_7_qualname = {
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
    ._data = "_CallableGenericAlias.__getitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[91];
    }
toplevel_consts_44_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 90,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x08\x08\x01\x0e\x01\x0a\x01\x06\x01\x16\x01\x02\x01\x02\xff\x0a\x01\x02\xff\x0a\x02\x08\x01\x08\x01\x16\x01\x02\x01\x04\xff\x02\x02\x04\xfe\x02\x02\x08\xfe\x10\x03\x04\x01\x0a\x01\x08\x01\x08\x01\x08\x01\x08\x01\x04\x01\x02\x01\x08\xff\x02\xff\x0a\x04\x16\x02\x06\x01\x04\x01\x14\x01\x08\x01\x0e\x01\x0e\x03\x08\x01\x0c\x01\x08\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[111];
    }
toplevel_consts_44_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 110,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x08\x06\x01\x10\x01\x08\x01\x08\x01\x06\x01\x02\x02\x0c\xfe\x02\x02\x02\xff\x02\x01\x0a\xff\x0c\x01\x08\x01\x06\x01\x02\x03\x02\xfe\x02\x02\x0e\xfe\x04\x02\x02\xff\x14\x01\x10\x01\x04\x01\x04\x01\x04\x0f\x02\xf1\x06\x01\x02\x0d\x06\xf4\x02\x06\x08\xfb\x06\x01\x02\x02\x02\xff\x0e\x01\x0a\x02\x08\x02\x02\x04\x0a\xfc\x02\x04\x06\xfd\x02\x01\x02\x02\x14\xff\x08\x01\x0e\x01\x0c\x03\x02\x03\x08\xfe\x0c\x01\x08\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[379];
    }
toplevel_consts_44_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 378,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x15\x18\x19\x1d\x19\x2c\x15\x2d\x09\x12\x0c\x15\x19\x1a\x0c\x1a\x09\x3e\x13\x1c\x20\x24\x1d\x3d\x1d\x3d\x1d\x3d\x13\x3e\x0d\x3e\x10\x1a\x1b\x1f\x21\x26\x10\x27\x09\x1b\x15\x19\x14\x1b\x0d\x11\x0d\x16\x1a\x1b\x0d\x1b\x09\x21\x20\x2e\x2f\x33\x2f\x42\x43\x44\x2f\x45\x20\x46\x09\x21\x15\x19\x09\x21\x22\x30\x31\x35\x36\x37\x31\x38\x22\x39\x09\x21\x15\x19\x1a\x1e\x15\x1f\x14\x21\x0d\x11\x14\x17\x18\x1c\x14\x1d\x09\x11\x0c\x14\x18\x21\x0c\x21\x09\x49\x13\x1c\x1d\x48\x2e\x36\x39\x42\x2e\x42\x24\x4d\x24\x2a\x24\x2a\x48\x4d\x1d\x48\x1d\x48\x2f\x33\x1d\x48\x1d\x48\x28\x30\x1d\x48\x1d\x48\x3d\x46\x1d\x48\x1d\x48\x13\x49\x0d\x49\x11\x15\x16\x19\x1a\x1e\x1a\x2d\x2f\x33\x16\x34\x11\x35\x09\x0e\x14\x16\x09\x11\x14\x18\x14\x21\x09\x21\x09\x21\x0d\x10\x10\x1f\x20\x23\x10\x24\x0d\x27\x14\x22\x23\x26\x14\x27\x11\x25\x1b\x20\x21\x24\x1b\x25\x15\x18\x1c\x2a\x2b\x2e\x1c\x2f\x15\x51\x1f\x28\x29\x50\x4b\x4e\x29\x50\x29\x50\x1f\x51\x19\x51\x15\x51\x1b\x20\x21\x24\x1b\x25\x15\x18\x15\x18\x12\x19\x1a\x1d\x1f\x2f\x12\x30\x0d\x27\x35\x3f\x40\x43\x40\x52\x54\x59\x35\x5a\x0d\x27\x1d\x20\x1d\x2f\x11\x1a\x14\x1d\x11\x27\x1f\x24\x24\x41\x24\x41\x24\x41\x24\x41\x37\x40\x24\x41\x24\x41\x1f\x41\x15\x1c\x1b\x1e\x1f\x26\x1b\x27\x15\x18\x0d\x15\x0d\x21\x1d\x20\x0d\x21\x0d\x21\x0d\x21\x0d\x21\x10\x1a\x1b\x23\x24\x25\x1b\x26\x28\x2c\x10\x2d\x09\x2a\x18\x20\x21\x23\x18\x24\x0d\x15\x16\x1e\x1f\x22\x20\x22\x1f\x22\x16\x23\x0d\x13\x19\x1f\x21\x29\x18\x2a\x0d\x15\x10\x25\x26\x2e\x30\x35\x36\x3e\x30\x3f\x10\x40\x09\x40",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_44_consts_7_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_3._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_4._ascii.ob_base,
            & toplevel_consts_44_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_6._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_7._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_4._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_3._ascii.ob_base,
            & toplevel_consts_44_consts_7_consts_12_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_44_consts_7_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 11,
    },
    .ob_shash = -1,
    .ob_sval = "          @",
};
static struct PyCodeObject toplevel_consts_44_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 9,
    .co_firstlineno = 465,
    .co_code = & toplevel_consts_44_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_7_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 11,
    .co_nlocals = 10,
    .co_nplaincellvars = 1,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_44_consts_7_consts_12_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_44_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_44_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_44_consts_3.ob_base,
            & toplevel_consts_44_consts_4.ob_base,
            & toplevel_consts_44_consts_5.ob_base,
            & toplevel_consts_44_consts_6.ob_base,
            & toplevel_consts_44_consts_7.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_44_names_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_44_names_6 = {
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
    ._data = "property",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_44_names_11 = {
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
    ._data = "__classcell__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_44_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_7._ascii.ob_base,
            & toplevel_consts_44_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_44_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_6_name._ascii.ob_base,
            & toplevel_consts_44_consts_7_name._ascii.ob_base,
            & toplevel_consts_44_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_44_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x01\x04\x09\x0a\x02\x02\x0c\x04\x01\x02\xff\x02\x01\x0a\x0b\x06\x07\x0e\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_44_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x08\x04\x02\x0a\x0c\x02\x02\x04\x0a\x02\xf6\x02\x0a\x0a\x07\x06\x06\x0e\x2f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_44_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x05\x32\x05\x32\x05\x32\x05\x32\x05\x32\x06\x0e\x05\x2c\x05\x2c\x06\x0e\x05\x2c\x05\x35\x05\x35\x05\x35\x05\x35\x05\x35\x05\x37\x05\x37\x05\x37\x05\x40\x05\x40\x05\x40\x05\x40\x05\x40\x05\x40\x05\x40",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_44_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1,
    },
    .ob_shash = -1,
    .ob_sval = "@",
};
static struct PyCodeObject toplevel_consts_44 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 416,
    .co_code = & toplevel_consts_44_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 0,
    .co_nplaincellvars = 1,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_44_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_46_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x01\x7c\x01\x6a\x01\x64\x01\x6b\x02\x6f\x0e\x7c\x01\x6a\x02\x64\x02\x76\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_46_consts_1 = {
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
    ._data = "typing",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_46_consts_2_0 = {
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
    ._data = "ParamSpec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_46_consts_2_1 = {
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
    ._data = "TypeVar",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_46_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_46_consts_2_0._ascii.ob_base,
            & toplevel_consts_46_consts_2_1._ascii.ob_base,
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
toplevel_consts_46_consts = {
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
            & toplevel_consts_46_consts_1._ascii.ob_base,
            & toplevel_consts_46_consts_2._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_46_names_0 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_46_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_46_varnames_1 = {
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
    ._data = "obj",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_46_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_46_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_46_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0a\x02\x08\x01\x02\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_46_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x08\x02\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_46_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0b\x0f\x10\x13\x0b\x14\x05\x08\x0d\x10\x0d\x1b\x1f\x27\x0d\x27\x0d\x39\x11\x14\x11\x1d\x21\x39\x11\x39\x05\x3a",
};
static struct PyCodeObject toplevel_consts_46 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_46_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_46_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_46_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 513,
    .co_code = & toplevel_consts_46_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_4_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_4_names_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_46_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_46_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_46_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_47_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x89\x00\x74\x00\x75\x00\x72\x08\x64\x01\x53\x00\x74\x01\x89\x00\x74\x02\xa9\x02\x72\x0f\x64\x01\x53\x00\x74\x03\x89\x00\xa9\x01\x8a\x00\x64\x02\x7d\x01\x89\x00\x6a\x04\x64\x03\x6b\x02\x6f\x23\x74\x05\x88\x00\x66\x01\x64\x04\x84\x08\x7c\x01\x44\x00\xa9\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[125];
    }
toplevel_consts_47_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 124,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x68\x65\x63\x6b\x73\x20\x69\x66\x20\x6f\x62\x6a\x20\x6d\x61\x74\x63\x68\x65\x73\x20\x65\x69\x74\x68\x65\x72\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x20\x74\x79\x70\x65\x73\x2c\x20\x60\x60\x2e\x2e\x2e\x60\x60\x2c\x20\x60\x60\x50\x61\x72\x61\x6d\x53\x70\x65\x63\x60\x60\x20\x6f\x72\x0a\x20\x20\x20\x20\x60\x60\x5f\x43\x6f\x6e\x63\x61\x74\x65\x6e\x61\x74\x65\x47\x65\x6e\x65\x72\x69\x63\x41\x6c\x69\x61\x73\x60\x60\x20\x66\x72\x6f\x6d\x20\x74\x79\x70\x69\x6e\x67\x2e\x70\x79\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_47_consts_2_1 = {
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
    ._data = "_ConcatenateGenericAlias",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_47_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_46_consts_2_0._ascii.ob_base,
            & toplevel_consts_47_consts_2_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_47_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x09\x7d\x01\x89\x02\x6a\x00\x7c\x01\x6b\x02\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_47_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_47_consts_4_varnames_1 = {
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
toplevel_consts_47_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_47_consts_4_varnames_1._ascii.ob_base,
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
toplevel_consts_47_consts_4_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_46_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_47_consts_4_qualname = {
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
    ._data = "_is_param_expr.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_47_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x1c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_47_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x2e\x56\x2e\x56\x48\x4c\x2f\x32\x2f\x3b\x3f\x43\x2f\x43\x2e\x56\x2e\x56\x2e\x56\x2e\x56\x2e\x56\x2e\x56",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_47_consts_4_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_47_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_46_varnames_1._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_47_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_47_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_47_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 529,
    .co_code = & toplevel_consts_47_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_47_consts_4_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_47_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_47_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_47_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_47_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_47_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_47_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_47_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_47_consts_0._ascii.ob_base,
            Py_True,
            & toplevel_consts_47_consts_2._object.ob_base.ob_base,
            & toplevel_consts_46_consts_1._ascii.ob_base,
            & toplevel_consts_47_consts_4.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_47_names_0 = {
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
    ._data = "Ellipsis",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_47_names_5 = {
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
    ._data = "any",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_47_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_47_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_47_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_47_varnames_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_47_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_46_varnames_1._ascii.ob_base,
            & toplevel_consts_47_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_47_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x04\x04\x01\x0a\x01\x04\x01\x08\x01\x04\x01\x1e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_47_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x04\x06\x01\x08\x01\x06\x01\x08\x01\x04\x01\x1e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_47_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x08\x0b\x0f\x17\x08\x17\x05\x14\x10\x14\x10\x14\x08\x12\x13\x16\x18\x1c\x08\x1d\x05\x14\x10\x14\x10\x14\x0b\x0f\x10\x13\x0b\x14\x05\x08\x0d\x36\x05\x0a\x0c\x0f\x0c\x1a\x1e\x26\x0c\x26\x0c\x56\x2b\x2e\x2e\x56\x2e\x56\x2e\x56\x2e\x56\x50\x55\x2e\x56\x2e\x56\x2b\x56\x05\x56",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_47_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_47 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_47_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_47_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_47_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 519,
    .co_code = & toplevel_consts_47_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_47_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_47_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
    .co_linetable = & toplevel_consts_47_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_47_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_47_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_47_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_47_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_48_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x72\x0a\x74\x02\x7c\x00\xa9\x01\x53\x00\x74\x00\x7c\x00\x74\x03\xa9\x02\x72\x20\x7c\x00\x6a\x04\x64\x01\x6b\x02\x72\x17\x7c\x00\x6a\x05\x53\x00\x7c\x00\x6a\x04\x9b\x00\x64\x02\x7c\x00\x6a\x05\x9b\x00\x9d\x03\x53\x00\x7c\x00\x74\x06\x75\x00\x72\x26\x64\x03\x53\x00\x74\x00\x7c\x00\x74\x07\xa9\x02\x72\x2e\x7c\x00\x6a\x08\x53\x00\x74\x02\x7c\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[167];
    }
toplevel_consts_48_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 166,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x72\x65\x70\x72\x28\x29\x20\x6f\x66\x20\x61\x6e\x20\x6f\x62\x6a\x65\x63\x74\x2c\x20\x73\x70\x65\x63\x69\x61\x6c\x2d\x63\x61\x73\x69\x6e\x67\x20\x74\x79\x70\x65\x73\x20\x28\x69\x6e\x74\x65\x72\x6e\x61\x6c\x20\x68\x65\x6c\x70\x65\x72\x29\x2e\x0a\x0a\x20\x20\x20\x20\x43\x6f\x70\x69\x65\x64\x20\x66\x72\x6f\x6d\x20\x3a\x6d\x6f\x64\x3a\x60\x74\x79\x70\x69\x6e\x67\x60\x20\x73\x69\x6e\x63\x65\x20\x63\x6f\x6c\x6c\x65\x63\x74\x69\x6f\x6e\x73\x2e\x61\x62\x63\x0a\x20\x20\x20\x20\x73\x68\x6f\x75\x6c\x64\x6e\x27\x74\x20\x64\x65\x70\x65\x6e\x64\x20\x6f\x6e\x20\x74\x68\x61\x74\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_48_consts_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_48_consts_2 = {
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
        uint8_t _data[4];
    }
toplevel_consts_48_consts_3 = {
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
    ._data = "...",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_48_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_48_consts_0._ascii.ob_base,
            & toplevel_consts_48_consts_1._ascii.ob_base,
            & toplevel_consts_48_consts_2._ascii.ob_base,
            & toplevel_consts_48_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_48_names_2 = {
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
    ._data = "repr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_48_names_7 = {
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
    ._data = "FunctionType",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_48_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_48_names_2._ascii.ob_base,
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_47_names_0._ascii.ob_base,
            & toplevel_consts_48_names_7._ascii.ob_base,
            & toplevel_consts_17_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_48_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x08\x01\x0a\x01\x0a\x01\x06\x01\x12\x01\x08\x01\x04\x01\x0a\x01\x06\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_48_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x06\x0a\x01\x08\x01\x02\x03\x08\xfe\x08\x01\x12\x01\x06\x01\x06\x01\x08\x01\x08\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_48_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x12\x13\x16\x18\x24\x08\x25\x05\x19\x10\x14\x15\x18\x10\x19\x09\x19\x08\x12\x13\x16\x18\x1c\x08\x1d\x05\x36\x0c\x0f\x0c\x1a\x1e\x28\x0c\x28\x09\x24\x14\x17\x14\x24\x0d\x24\x13\x16\x13\x21\x10\x36\x10\x36\x24\x27\x24\x34\x10\x36\x10\x36\x09\x36\x08\x0b\x0f\x17\x08\x17\x05\x15\x10\x15\x10\x15\x08\x12\x13\x16\x18\x24\x08\x25\x05\x1c\x10\x13\x10\x1c\x09\x1c\x0c\x10\x11\x14\x0c\x15\x05\x15",
};
static struct PyCodeObject toplevel_consts_48 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_48_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_48_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_48_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 531,
    .co_code = & toplevel_consts_48_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_47_consts_4_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_5_consts_5_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_consts_5_consts_5_names_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_48_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_48_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_48_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_47_consts_4_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_49_consts_2_varnames_2 = {
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
    ._data = "kwds",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_49_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_49_consts_2_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_49_consts_2_name = {
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
    ._data = "__call__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_49_consts_2_qualname = {
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
    ._data = "Callable.__call__",
};
static struct PyCodeObject toplevel_consts_49_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 15,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 554,
    .co_code = & toplevel_consts_17_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_49_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_49_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_49_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_40_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_49_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_49_consts_3_consts = {
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
            & toplevel_consts_49_consts_2_name._ascii.ob_base,
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
toplevel_consts_49_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_6_12._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_49_consts_3_qualname = {
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
    ._data = "Callable.__subclasshook__",
};
static struct PyCodeObject toplevel_consts_49_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_49_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_49_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 558,
    .co_code = & toplevel_consts_17_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_49_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_49_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_12._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_49_consts_2.ob_base,
            & toplevel_consts_49_consts_3.ob_base,
            Py_None,
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
toplevel_consts_49_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_49_consts_2_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_17_consts_3_name._ascii.ob_base,
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_49_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x14\x05\x15\x05\x15\x06\x14\x05\x15\x06\x11\x05\x1e\x05\x1e\x06\x11\x05\x1e\x19\x24\x25\x3a\x19\x3b\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_49 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_49_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_49_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 550,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_12._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_12._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_49_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[117];
    }
toplevel_consts_51_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 116,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x84\x00\x5a\x08\x64\x07\x84\x00\x5a\x09\x65\x0a\x64\x08\x84\x00\xa9\x01\x5a\x0b\x64\x09\x84\x00\x5a\x0c\x65\x0c\x5a\x0d\x64\x0a\x84\x00\x5a\x0e\x64\x0b\x84\x00\x5a\x0f\x65\x0f\x5a\x10\x64\x0c\x84\x00\x5a\x11\x64\x0d\x84\x00\x5a\x12\x64\x0e\x84\x00\x5a\x13\x65\x13\x5a\x14\x64\x0f\x84\x00\x5a\x15\x64\x10\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[347];
    }
toplevel_consts_51_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 346,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x73\x65\x74\x20\x69\x73\x20\x61\x20\x66\x69\x6e\x69\x74\x65\x2c\x20\x69\x74\x65\x72\x61\x62\x6c\x65\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x63\x6c\x61\x73\x73\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x63\x6f\x6e\x63\x72\x65\x74\x65\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x6f\x66\x20\x61\x6c\x6c\x0a\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x65\x78\x63\x65\x70\x74\x20\x66\x6f\x72\x20\x5f\x5f\x63\x6f\x6e\x74\x61\x69\x6e\x73\x5f\x5f\x2c\x20\x5f\x5f\x69\x74\x65\x72\x5f\x5f\x20\x61\x6e\x64\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2e\x0a\x0a\x20\x20\x20\x20\x54\x6f\x20\x6f\x76\x65\x72\x72\x69\x64\x65\x20\x74\x68\x65\x20\x63\x6f\x6d\x70\x61\x72\x69\x73\x6f\x6e\x73\x20\x28\x70\x72\x65\x73\x75\x6d\x61\x62\x6c\x79\x20\x66\x6f\x72\x20\x73\x70\x65\x65\x64\x2c\x20\x61\x73\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x73\x65\x6d\x61\x6e\x74\x69\x63\x73\x20\x61\x72\x65\x20\x66\x69\x78\x65\x64\x29\x2c\x20\x72\x65\x64\x65\x66\x69\x6e\x65\x20\x5f\x5f\x6c\x65\x5f\x5f\x20\x61\x6e\x64\x20\x5f\x5f\x67\x65\x5f\x5f\x2c\x0a\x20\x20\x20\x20\x74\x68\x65\x6e\x20\x74\x68\x65\x20\x6f\x74\x68\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x77\x69\x6c\x6c\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x66\x6f\x6c\x6c\x6f\x77\x20\x73\x75\x69\x74\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x01\xa9\x01\x6b\x04\x72\x12\x64\x01\x53\x00\x7c\x00\x44\x00\x5d\x09\x7d\x02\x7c\x02\x7c\x01\x76\x01\x72\x1d\x01\x00\x64\x01\x53\x00\x71\x14\x64\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_3_consts = {
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
toplevel_consts_51_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_51_consts_3_varnames_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_51_consts_3_varnames_2 = {
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
    ._data = "elem",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_3_name = {
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
    ._data = "__le__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_3_qualname = {
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
    ._data = "Set.__le__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_51_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x10\x01\x04\x01\x08\x01\x08\x01\x06\x01\x02\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_51_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x06\x01\x0e\x01\x06\x01\x02\x01\x04\x02\x02\xfe\x06\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x22\x14\x22\x0d\x22\x0c\x0f\x10\x14\x0c\x15\x18\x1b\x1c\x21\x18\x22\x0c\x22\x09\x19\x14\x19\x14\x19\x15\x19\x09\x1d\x09\x1d\x0d\x11\x10\x14\x1c\x21\x10\x21\x0d\x1d\x18\x1d\x18\x1d\x18\x1d\x0d\x1d\x10\x14\x10\x14",
};
static struct PyCodeObject toplevel_consts_51_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 583,
    .co_code = & toplevel_consts_51_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x01\xa9\x01\x6b\x00\x6f\x15\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_51_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_51_consts_3_name._ascii.ob_base,
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
toplevel_consts_51_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_4_name = {
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
    ._data = "__lt__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_4_qualname = {
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
    ._data = "Set.__lt__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_51_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x1c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_51_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x06\x01\x1c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x22\x14\x22\x0d\x22\x10\x13\x14\x18\x10\x19\x1c\x1f\x20\x25\x1c\x26\x10\x26\x10\x3d\x2b\x2f\x2b\x3d\x37\x3c\x2b\x3d\x2b\x3d\x09\x3d",
};
static struct PyCodeObject toplevel_consts_51_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 593,
    .co_code = & toplevel_consts_51_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x01\xa9\x01\x6b\x04\x6f\x15\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_5_names_4 = {
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
    ._data = "__ge__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_51_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_51_consts_5_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_5_name = {
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
    ._data = "__gt__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_5_qualname = {
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
    ._data = "Set.__gt__",
};
static struct PyCodeObject toplevel_consts_51_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 598,
    .co_code = & toplevel_consts_51_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x01\xa9\x01\x6b\x00\x72\x12\x64\x01\x53\x00\x7c\x01\x44\x00\x5d\x09\x7d\x02\x7c\x02\x7c\x00\x76\x01\x72\x1d\x01\x00\x64\x01\x53\x00\x71\x14\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_6_qualname = {
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
    ._data = "Set.__ge__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x22\x14\x22\x0d\x22\x0c\x0f\x10\x14\x0c\x15\x18\x1b\x1c\x21\x18\x22\x0c\x22\x09\x19\x14\x19\x14\x19\x15\x1a\x09\x1d\x09\x1d\x0d\x11\x10\x14\x1c\x20\x10\x20\x0d\x1d\x18\x1d\x18\x1d\x18\x1d\x0d\x1d\x10\x14\x10\x14",
};
static struct PyCodeObject toplevel_consts_51_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 603,
    .co_code = & toplevel_consts_51_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_5_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x01\xa9\x01\x6b\x02\x6f\x15\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_7_name = {
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
    ._data = "__eq__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_7_qualname = {
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
    ._data = "Set.__eq__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x22\x14\x22\x0d\x22\x10\x13\x14\x18\x10\x19\x1d\x20\x21\x26\x1d\x27\x10\x27\x10\x3e\x2c\x30\x2c\x3e\x38\x3d\x2c\x3e\x2c\x3e\x09\x3e",
};
static struct PyCodeObject toplevel_consts_51_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 613,
    .co_code = & toplevel_consts_51_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x7c\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[189];
    }
toplevel_consts_51_consts_8_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 188,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x6f\x6e\x73\x74\x72\x75\x63\x74\x20\x61\x6e\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x20\x66\x72\x6f\x6d\x20\x61\x6e\x79\x20\x69\x74\x65\x72\x61\x62\x6c\x65\x20\x69\x6e\x70\x75\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4d\x75\x73\x74\x20\x6f\x76\x65\x72\x72\x69\x64\x65\x20\x74\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x66\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x20\x63\x6f\x6e\x73\x74\x72\x75\x63\x74\x6f\x72\x20\x73\x69\x67\x6e\x61\x74\x75\x72\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x20\x61\x63\x63\x65\x70\x74\x20\x61\x6e\x20\x69\x74\x65\x72\x61\x62\x6c\x65\x20\x66\x6f\x72\x20\x61\x6e\x20\x69\x6e\x70\x75\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_51_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_51_consts_8_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_51_consts_8_varnames_1 = {
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
    ._data = "it",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_8_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_51_consts_8_name = {
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
    ._data = "_from_iterable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_51_consts_8_qualname = {
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
    ._data = "Set._from_iterable",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_51_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x13\x14\x16\x10\x17\x09\x17",
};
static struct PyCodeObject toplevel_consts_51_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 618,
    .co_code = & toplevel_consts_51_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_51_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x09\x74\x02\x53\x00\x89\x00\xa0\x03\x88\x00\x66\x01\x64\x01\x84\x08\x7c\x01\x44\x00\xa9\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_9_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x0a\x7d\x01\x7c\x01\x89\x02\x76\x00\x72\x04\x7c\x01\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_9_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_51_consts_9_consts_1_qualname = {
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
    ._data = "Set.__and__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_51_consts_9_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x1e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_9_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x23\x4e\x23\x4e\x2e\x33\x40\x45\x49\x4d\x40\x4d\x23\x4e\x24\x29\x23\x4e\x23\x4e\x23\x4e\x23\x4e\x23\x4e\x23\x4e",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_9_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_51_consts_9_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_9_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 630,
    .co_code = & toplevel_consts_51_consts_9_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_9_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_9_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_9_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_9_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_9_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_51_consts_9_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_9_consts = {
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
            & toplevel_consts_51_consts_9_consts_1.ob_base,
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
toplevel_consts_51_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_51_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_51_consts_9_name = {
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
    ._data = "__and__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_51_consts_9_qualname = {
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
    ._data = "Set.__and__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x04\x01\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x01\x06\x01\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_51_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x1a\x1b\x20\x22\x2a\x10\x2b\x09\x22\x14\x22\x0d\x22\x10\x14\x10\x4e\x23\x4e\x23\x4e\x23\x4e\x23\x4e\x37\x3c\x23\x4e\x23\x4e\x10\x4e\x10\x4e\x09\x4e",
};
static struct PyCodeObject toplevel_consts_51_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 627,
    .co_code = & toplevel_consts_51_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_47_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_51_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x44\x00\x5d\x09\x7d\x02\x7c\x02\x7c\x00\x76\x00\x72\x0c\x01\x00\x64\x01\x53\x00\x71\x03\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[50];
    }
toplevel_consts_51_consts_10_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 49,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return True if two sets have a null intersection.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_51_consts_10_consts_0._ascii.ob_base,
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_51_consts_10_name = {
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
    ._data = "isdisjoint",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_51_consts_10_qualname = {
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
    ._data = "Set.isdisjoint",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_51_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x08\x01\x06\x01\x02\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_51_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x04\x02\x02\xfe\x06\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_51_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x1b\x09\x1d\x09\x1d\x0d\x12\x10\x15\x19\x1d\x10\x1d\x0d\x1d\x18\x1d\x18\x1d\x18\x1d\x0d\x1d\x10\x14\x10\x14",
};
static struct PyCodeObject toplevel_consts_51_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 634,
    .co_code = & toplevel_consts_51_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x64\x01\x84\x00\x7c\x00\x7c\x01\x66\x02\x44\x00\xa9\x01\x7d\x02\x7c\x00\xa0\x03\x7c\x02\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_11_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x5d\x0b\x7d\x01\x7c\x01\x44\x00\x5d\x06\x7d\x02\x7c\x02\x56\x00\x97\x01\x01\x00\x71\x07\x71\x03\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_51_consts_11_consts_1_varnames_1 = {
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
toplevel_consts_51_consts_11_consts_1_varnames_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_11_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_11_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_11_consts_1_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_51_consts_11_consts_1_qualname = {
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
    ._data = "Set.__or__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_51_consts_11_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x20\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_11_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x11\x36\x11\x36\x18\x19\x34\x35\x11\x36\x11\x36\x2f\x30\x12\x13\x11\x36\x11\x36\x11\x36\x11\x36\x11\x36\x11\x36\x11\x36",
};
static struct PyCodeObject toplevel_consts_51_consts_11_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_11_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 644,
    .co_code = & toplevel_consts_51_consts_11_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_11_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_11_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_11_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_11_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_11_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_11_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_11_consts = {
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
            & toplevel_consts_51_consts_11_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_51_consts_11_varnames_2 = {
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
    ._data = "chain",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_11_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_51_consts_11_name = {
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
        uint8_t _data[11];
    }
toplevel_consts_51_consts_11_qualname = {
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
    ._data = "Set.__or__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x10\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_51_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x06\x01\x10\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x2a\x10\x2b\x09\x22\x14\x22\x0d\x22\x11\x36\x11\x36\x1e\x22\x24\x29\x1d\x2a\x11\x36\x11\x36\x09\x0e\x10\x14\x10\x2a\x24\x29\x10\x2a\x10\x2a\x09\x2a",
};
static struct PyCodeObject toplevel_consts_51_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 641,
    .co_code = & toplevel_consts_51_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x01\x97\x00\x74\x00\x89\x01\x74\x01\xa9\x02\x73\x14\x74\x00\x89\x01\x74\x02\xa9\x02\x73\x0e\x74\x03\x53\x00\x7c\x00\xa0\x04\x89\x01\xa8\x01\xa9\x01\x8a\x01\x7c\x00\xa0\x04\x88\x01\x66\x01\x64\x01\x84\x08\x7c\x00\x44\x00\xa9\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_12_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x0a\x7d\x01\x7c\x01\x89\x02\x76\x01\x72\x04\x7c\x01\x56\x00\x97\x01\x01\x00\x71\x04\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_51_consts_12_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_51_consts_12_consts_1_qualname = {
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
    ._data = "Set.__sub__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_51_consts_12_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x08\x00\x06\x01\x10\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_51_consts_12_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x04\x01\x02\xff\x08\x01\x02\xff\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_12_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x23\x3a\x23\x3a\x2e\x33\x27\x2c\x34\x39\x27\x39\x23\x3a\x24\x29\x23\x3a\x23\x3a\x23\x3a\x23\x3a\x23\x3a\x23\x3a",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_51_consts_12_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_51_consts_12_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_12_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 654,
    .co_code = & toplevel_consts_51_consts_12_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_12_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_12_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_12_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_12_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_12_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_51_consts_9_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_51_consts_12_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_12_consts = {
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
            & toplevel_consts_51_consts_12_consts_1.ob_base,
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
toplevel_consts_51_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_51_consts_8_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_51_consts_12_name = {
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
    ._data = "__sub__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_51_consts_12_qualname = {
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
    ._data = "Set.__sub__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_51_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x0a\x01\x04\x01\x0c\x01\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_51_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x01\x02\x03\x08\xfe\x06\x01\x0c\x01\x02\x01\x0a\x01\x02\xff\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x2f\x14\x1e\x1f\x24\x26\x2e\x14\x2f\x0d\x26\x18\x26\x11\x26\x15\x19\x15\x2f\x29\x2e\x15\x2f\x15\x2f\x0d\x12\x10\x14\x10\x3a\x23\x3a\x23\x3a\x23\x3a\x23\x3a\x37\x3b\x23\x3a\x23\x3a\x10\x3a\x10\x3a\x09\x3a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_51_consts_12_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = " `",
};
static struct PyCodeObject toplevel_consts_51_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 649,
    .co_code = & toplevel_consts_51_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_51_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_51_consts_12_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x14\x74\x00\x7c\x01\x74\x02\xa9\x02\x73\x0e\x74\x03\x53\x00\x89\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x7d\x01\x89\x00\xa0\x04\x88\x00\x66\x01\x64\x01\x84\x08\x7c\x01\x44\x00\xa9\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_51_consts_13_consts_1_qualname = {
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
    ._data = "Set.__rsub__.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_51_consts_13_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x23\x39\x23\x39\x2e\x33\x27\x2c\x34\x38\x27\x38\x23\x39\x24\x29\x23\x39\x23\x39\x23\x39\x23\x39\x23\x39\x23\x39",
};
static struct PyCodeObject toplevel_consts_51_consts_13_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_12_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 662,
    .co_code = & toplevel_consts_51_consts_12_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_9_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_13_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_12_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_12_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_13_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_51_consts_9_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_51_consts_13_consts = {
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
            & toplevel_consts_51_consts_13_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_51_consts_13_name = {
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
    ._data = "__rsub__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_51_consts_13_qualname = {
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
    ._data = "Set.__rsub__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_51_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x2f\x14\x1e\x1f\x24\x26\x2e\x14\x2f\x0d\x26\x18\x26\x11\x26\x15\x19\x15\x2f\x29\x2e\x15\x2f\x15\x2f\x0d\x12\x10\x14\x10\x39\x23\x39\x23\x39\x23\x39\x23\x39\x37\x3c\x23\x39\x23\x39\x10\x39\x10\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_51_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 657,
    .co_code = & toplevel_consts_51_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_47_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_13_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_51_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x13\x74\x00\x7c\x01\x74\x02\xa9\x02\x73\x0d\x74\x03\x53\x00\x7c\x00\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x7d\x01\x7c\x00\x7c\x01\x7a\x0a\x7c\x01\x7c\x00\x7a\x0a\x7a\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_51_consts_14_name = {
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
    ._data = "__xor__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_51_consts_14_qualname = {
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
    ._data = "Set.__xor__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_51_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x04\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_51_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x03\x08\xfe\x06\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_51_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x25\x10\x26\x09\x2f\x14\x1e\x1f\x24\x26\x2e\x14\x2f\x0d\x26\x18\x26\x11\x26\x15\x19\x15\x2f\x29\x2e\x15\x2f\x15\x2f\x0d\x12\x11\x15\x18\x1d\x11\x1d\x22\x27\x2a\x2e\x22\x2e\x10\x2f\x09\x2f",
};
static struct PyCodeObject toplevel_consts_51_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 665,
    .co_code = & toplevel_consts_51_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_14_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[175];
    }
toplevel_consts_51_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 174,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7d\x01\x64\x01\x7c\x01\x7a\x05\x64\x02\x7a\x00\x7d\x02\x74\x02\x7c\x00\xa9\x01\x7d\x03\x64\x03\x7c\x03\x64\x02\x7a\x00\x7a\x05\x7d\x04\x7c\x04\x7c\x02\x7a\x0e\x7d\x04\x7c\x00\x44\x00\x5d\x16\x7d\x05\x74\x03\x7c\x05\xa9\x01\x7d\x06\x7c\x04\x7c\x06\x7c\x06\x64\x04\x7a\x03\x7a\x0c\x64\x05\x7a\x0c\x64\x06\x7a\x05\x7a\x19\x7d\x04\x7c\x04\x7c\x02\x7a\x0e\x7d\x04\x71\x1a\x7c\x04\x7c\x04\x64\x07\x7a\x09\x7c\x04\x64\x08\x7a\x09\x7a\x0c\x7a\x19\x7d\x04\x7c\x04\x64\x09\x7a\x05\x64\x0a\x7a\x00\x7d\x04\x7c\x04\x7c\x02\x7a\x0e\x7d\x04\x7c\x04\x7c\x01\x6b\x04\x72\x4f\x7c\x04\x7c\x02\x64\x02\x7a\x00\x7a\x17\x7d\x04\x7c\x04\x64\x0b\x6b\x02\x72\x55\x64\x0c\x7d\x04\x7c\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[556];
    }
toplevel_consts_51_consts_15_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 555,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x6f\x6d\x70\x75\x74\x65\x20\x74\x68\x65\x20\x68\x61\x73\x68\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x61\x20\x73\x65\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x77\x65\x20\x64\x6f\x6e\x27\x74\x20\x64\x65\x66\x69\x6e\x65\x20\x5f\x5f\x68\x61\x73\x68\x5f\x5f\x3a\x20\x6e\x6f\x74\x20\x61\x6c\x6c\x20\x73\x65\x74\x73\x20\x61\x72\x65\x20\x68\x61\x73\x68\x61\x62\x6c\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x42\x75\x74\x20\x69\x66\x20\x79\x6f\x75\x20\x64\x65\x66\x69\x6e\x65\x20\x61\x20\x68\x61\x73\x68\x61\x62\x6c\x65\x20\x73\x65\x74\x20\x74\x79\x70\x65\x2c\x20\x69\x74\x73\x20\x5f\x5f\x68\x61\x73\x68\x5f\x5f\x20\x73\x68\x6f\x75\x6c\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x61\x6c\x6c\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x63\x6f\x6d\x70\x61\x74\x69\x62\x6c\x65\x20\x5f\x5f\x65\x71\x5f\x5f\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x41\x6c\x6c\x20\x73\x65\x74\x73\x20\x6f\x75\x67\x68\x74\x20\x74\x6f\x20\x63\x6f\x6d\x70\x61\x72\x65\x20\x65\x71\x75\x61\x6c\x20\x69\x66\x20\x74\x68\x65\x79\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6c\x65\x6d\x65\x6e\x74\x73\x2c\x20\x72\x65\x67\x61\x72\x64\x6c\x65\x73\x73\x20\x6f\x66\x20\x68\x6f\x77\x20\x74\x68\x65\x79\x20\x61\x72\x65\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x65\x64\x2c\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x67\x61\x72\x64\x6c\x65\x73\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x6f\x72\x64\x65\x72\x20\x6f\x66\x20\x74\x68\x65\x20\x65\x6c\x65\x6d\x65\x6e\x74\x73\x3b\x20\x73\x6f\x20\x74\x68\x65\x72\x65\x27\x73\x20\x6e\x6f\x74\x20\x6d\x75\x63\x68\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x66\x72\x65\x65\x64\x6f\x6d\x20\x66\x6f\x72\x20\x5f\x5f\x65\x71\x5f\x5f\x20\x6f\x72\x20\x5f\x5f\x68\x61\x73\x68\x5f\x5f\x2e\x20\x20\x57\x65\x20\x6d\x61\x74\x63\x68\x20\x74\x68\x65\x20\x61\x6c\x67\x6f\x72\x69\x74\x68\x6d\x20\x75\x73\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x62\x79\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x20\x66\x72\x6f\x7a\x65\x6e\x73\x65\x74\x20\x74\x79\x70\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[3];
    }
toplevel_consts_51_consts_15_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 3,
    },
    .ob_digit = { 28493, 26065, 1 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_51_consts_15_consts_3 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 854126413, 1 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_4 = {
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
toplevel_consts_51_consts_15_consts_5 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 19891, 2742 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_5 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 89869747 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[3];
    }
toplevel_consts_51_consts_15_consts_6 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 3,
    },
    .ob_digit = { 13527, 12926, 3 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_51_consts_15_consts_6 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 423572695, 3 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_7 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 11 },
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_8 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 25 },
};
#if PYLONG_BITS_IN_DIGIT == 15
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[2];
    }
toplevel_consts_51_consts_15_consts_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 3533, 2 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_9 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 69069 },
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
toplevel_consts_51_consts_15_consts_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 17379, 27683 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_10 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 907133923 },
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
toplevel_consts_51_consts_15_consts_12 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 2,
    },
    .ob_digit = { 18369, 18033 },
};
#elif PYLONG_BITS_IN_DIGIT == 30
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_51_consts_15_consts_12 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 590923713 },
};
#else
#error "PYLONG_BITS_IN_DIGIT should be 15 or 30"
#endif
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_51_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_51_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_consts_1.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_3.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_4.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_5.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_6.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_7.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_8.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_9.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_10.ob_base.ob_base,
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
            & toplevel_consts_51_consts_15_consts_12.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_51_consts_15_names_0 = {
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
toplevel_consts_51_consts_15_names_1 = {
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
    ._data = "maxsize",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_51_consts_15_names_3 = {
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
    ._data = "hash",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_51_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_51_consts_15_names_0._ascii.ob_base,
            & toplevel_consts_51_consts_15_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_51_consts_15_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_51_consts_15_varnames_1 = {
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
    ._data = "MAX",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_51_consts_15_varnames_2 = {
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
    ._data = "MASK",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_51_consts_15_varnames_3 = {
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
        uint8_t _data[2];
    }
toplevel_consts_51_consts_15_varnames_4 = {
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
    ._data = "h",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_51_consts_15_varnames_6 = {
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
    ._data = "hx",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_51_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_4._ascii.ob_base,
            & toplevel_consts_40_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_51_consts_15_name = {
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
    ._data = "_hash",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_51_consts_15_qualname = {
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
    ._data = "Set._hash",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_51_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0f\x0c\x01\x08\x01\x0c\x01\x08\x01\x08\x01\x08\x01\x18\x01\x0a\x01\x14\x01\x0c\x01\x08\x01\x08\x01\x0c\x01\x08\x01\x04\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_51_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0f\x0c\x01\x08\x01\x0c\x01\x08\x01\x02\x01\x04\x03\x02\xfd\x08\x01\x18\x01\x0a\x01\x14\x01\x0c\x01\x08\x01\x06\x01\x0e\x01\x06\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[175];
    }
toplevel_consts_51_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 174,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x12\x0f\x1a\x09\x0c\x10\x11\x14\x17\x10\x17\x1a\x1b\x10\x1b\x09\x0d\x0d\x10\x11\x15\x0d\x16\x09\x0a\x0d\x17\x1b\x1c\x1f\x20\x1b\x20\x0d\x21\x09\x0a\x09\x0a\x0e\x12\x09\x12\x09\x0a\x12\x16\x09\x16\x09\x16\x0d\x0e\x12\x16\x17\x18\x12\x19\x0d\x0f\x0d\x0e\x13\x15\x19\x1b\x1f\x21\x19\x21\x13\x22\x25\x2d\x13\x2d\x32\x3c\x12\x3c\x0d\x3c\x0d\x0e\x0d\x0e\x12\x16\x0d\x16\x0d\x0e\x0d\x0e\x09\x0a\x0f\x10\x14\x16\x0f\x16\x1b\x1c\x20\x22\x1b\x22\x0e\x23\x09\x23\x09\x0a\x0d\x0e\x11\x16\x0d\x16\x19\x22\x0d\x22\x09\x0a\x09\x0a\x0e\x12\x09\x12\x09\x0a\x0c\x0d\x10\x13\x0c\x13\x09\x1a\x0d\x0e\x12\x16\x19\x1a\x12\x1a\x0d\x1a\x0d\x0e\x0c\x0d\x11\x13\x0c\x13\x09\x1a\x11\x1a\x0d\x0e\x10\x11\x09\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_51_consts_15_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_51_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 674,
    .co_code = & toplevel_consts_51_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_51_consts_15_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_51_consts_15_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts_51_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_51_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_51_consts_3.ob_base,
            & toplevel_consts_51_consts_4.ob_base,
            & toplevel_consts_51_consts_5.ob_base,
            & toplevel_consts_51_consts_6.ob_base,
            & toplevel_consts_51_consts_7.ob_base,
            & toplevel_consts_51_consts_8.ob_base,
            & toplevel_consts_51_consts_9.ob_base,
            & toplevel_consts_51_consts_10.ob_base,
            & toplevel_consts_51_consts_11.ob_base,
            & toplevel_consts_51_consts_12.ob_base,
            & toplevel_consts_51_consts_13.ob_base,
            & toplevel_consts_51_consts_14.ob_base,
            & toplevel_consts_51_consts_15.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_51_names_13 = {
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
    ._data = "__rand__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_51_names_16 = {
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
        uint8_t _data[9];
    }
toplevel_consts_51_names_20 = {
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
    ._data = "__rxor__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[22];
        }_object;
    }
toplevel_consts_51_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 22,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_51_consts_3_name._ascii.ob_base,
            & toplevel_consts_51_consts_4_name._ascii.ob_base,
            & toplevel_consts_51_consts_5_name._ascii.ob_base,
            & toplevel_consts_51_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_51_consts_7_name._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_51_consts_8_name._ascii.ob_base,
            & toplevel_consts_51_consts_9_name._ascii.ob_base,
            & toplevel_consts_51_names_13._ascii.ob_base,
            & toplevel_consts_51_consts_10_name._ascii.ob_base,
            & toplevel_consts_51_consts_11_name._ascii.ob_base,
            & toplevel_consts_51_names_16._ascii.ob_base,
            & toplevel_consts_51_consts_12_name._ascii.ob_base,
            & toplevel_consts_51_consts_13_name._ascii.ob_base,
            & toplevel_consts_51_consts_14_name._ascii.ob_base,
            & toplevel_consts_51_names_20._ascii.ob_base,
            & toplevel_consts_51_consts_15_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x0a\x06\x02\x06\x0a\x06\x05\x06\x05\x06\x0a\x02\x05\x04\x01\x02\xff\x02\x01\x06\x08\x04\x05\x06\x02\x06\x07\x04\x06\x06\x02\x06\x08\x06\x08\x04\x07\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_51_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x09\x04\x02\x06\x0a\x06\x05\x06\x05\x06\x0a\x06\x05\x02\x02\x04\x07\x02\xf9\x02\x07\x06\x05\x04\x02\x06\x07\x06\x06\x04\x02\x06\x08\x06\x08\x06\x07\x04\x02\x0a\x21",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[117];
    }
toplevel_consts_51_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 116,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x05\x14\x05\x14\x05\x14\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x14\x05\x14\x05\x14\x05\x3e\x05\x3e\x05\x3e\x06\x11\x05\x17\x05\x17\x06\x11\x05\x17\x05\x4e\x05\x4e\x05\x4e\x10\x17\x05\x0d\x05\x14\x05\x14\x05\x14\x05\x2a\x05\x2a\x05\x2a\x0f\x15\x05\x0c\x05\x3a\x05\x3a\x05\x3a\x05\x39\x05\x39\x05\x39\x05\x2f\x05\x2f\x05\x2f\x10\x17\x05\x0d\x05\x11\x05\x11\x05\x11\x05\x11\x05\x11",
};
static struct PyCodeObject toplevel_consts_51 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_51_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_51_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 570,
    .co_code = & toplevel_consts_51_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_14._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_14._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_53_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x05\x64\x04\x84\x00\xa9\x01\x5a\x07\x64\x05\x84\x00\x5a\x08\x64\x06\x84\x00\x5a\x09\x64\x07\x84\x00\x5a\x0a\x64\x08\x84\x00\x5a\x0b\x64\x09\x84\x00\x5a\x0c\x64\x0a\x84\x00\x5a\x0d\x64\x0b\x84\x00\x5a\x0e\x64\x0c\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[392];
    }
toplevel_consts_53_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 391,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x6d\x75\x74\x61\x62\x6c\x65\x20\x73\x65\x74\x20\x69\x73\x20\x61\x20\x66\x69\x6e\x69\x74\x65\x2c\x20\x69\x74\x65\x72\x61\x62\x6c\x65\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x63\x6c\x61\x73\x73\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x63\x6f\x6e\x63\x72\x65\x74\x65\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x6f\x66\x20\x61\x6c\x6c\x0a\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x65\x78\x63\x65\x70\x74\x20\x66\x6f\x72\x20\x5f\x5f\x63\x6f\x6e\x74\x61\x69\x6e\x73\x5f\x5f\x2c\x20\x5f\x5f\x69\x74\x65\x72\x5f\x5f\x2c\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2c\x0a\x20\x20\x20\x20\x61\x64\x64\x28\x29\x2c\x20\x61\x6e\x64\x20\x64\x69\x73\x63\x61\x72\x64\x28\x29\x2e\x0a\x0a\x20\x20\x20\x20\x54\x6f\x20\x6f\x76\x65\x72\x72\x69\x64\x65\x20\x74\x68\x65\x20\x63\x6f\x6d\x70\x61\x72\x69\x73\x6f\x6e\x73\x20\x28\x70\x72\x65\x73\x75\x6d\x61\x62\x6c\x79\x20\x66\x6f\x72\x20\x73\x70\x65\x65\x64\x2c\x20\x61\x73\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x73\x65\x6d\x61\x6e\x74\x69\x63\x73\x20\x61\x72\x65\x20\x66\x69\x78\x65\x64\x29\x2c\x20\x61\x6c\x6c\x20\x79\x6f\x75\x20\x68\x61\x76\x65\x20\x74\x6f\x20\x64\x6f\x20\x69\x73\x20\x72\x65\x64\x65\x66\x69\x6e\x65\x20\x5f\x5f\x6c\x65\x5f\x5f\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x74\x68\x65\x6e\x20\x74\x68\x65\x20\x6f\x74\x68\x65\x72\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x77\x69\x6c\x6c\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x66\x6f\x6c\x6c\x6f\x77\x20\x73\x75\x69\x74\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_53_consts_3_consts_0 = {
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
    ._data = "Add an element.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_53_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_3_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_53_consts_3_names_0 = {
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
toplevel_consts_53_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_3_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_53_consts_3_name = {
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
        uint8_t _data[15];
    }
toplevel_consts_53_consts_3_qualname = {
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
    ._data = "MutableSet.add",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_53_consts_3_columntable = {
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
static struct PyCodeObject toplevel_consts_53_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 725,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[57];
    }
toplevel_consts_53_consts_4_consts_0 = {
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
    ._data = "Remove an element.  Do not raise an exception if absent.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_53_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_4_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_53_consts_4_name = {
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
    ._data = "discard",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_53_consts_4_qualname = {
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
    ._data = "MutableSet.discard",
};
static struct PyCodeObject toplevel_consts_53_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 730,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_53_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x76\x01\x72\x09\x74\x00\x7c\x01\xa9\x01\x82\x01\x7c\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_53_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 53,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Remove an element. If not a member, raise a KeyError.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_53_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_5_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_53_consts_5_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_53_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_53_consts_5_name = {
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
    ._data = "remove",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_53_consts_5_qualname = {
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
    ._data = "MutableSet.remove",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_53_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x08\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_53_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0a\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_53_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x11\x19\x1d\x0c\x1d\x09\x22\x13\x1b\x1c\x21\x13\x22\x0d\x22\x09\x0d\x09\x1c\x16\x1b\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_53_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 735,
    .co_code = & toplevel_consts_53_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_53_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x01\x09\x00\x74\x01\x7c\x01\xa9\x01\x7d\x02\x6e\x0b\x23\x00\x74\x02\x79\x12\x01\x00\x74\x03\x64\x01\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x01\x00\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[51];
    }
toplevel_consts_53_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 50,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return the popped value.  Raise KeyError if empty.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_53_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_6_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_53_consts_6_names_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_53_consts_6_names_1 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_53_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_53_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
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
toplevel_consts_53_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_8_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_53_consts_6_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_53_consts_6_qualname = {
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
    ._data = "MutableSet.pop",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_53_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x02\x01\x0a\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x0c\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_53_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x02\x04\x0a\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_53_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x12\x13\x17\x0e\x18\x09\x0b\x09\x25\x15\x19\x1a\x1c\x15\x1d\x0d\x12\x0d\x12\x00\x00\x10\x1d\x09\x25\x09\x25\x13\x1b\x21\x25\x0d\x25\x09\x25\x00\x00\x00\x00\x00\x00\x09\x0d\x09\x1c\x16\x1b\x09\x1c\x09\x1c\x09\x1c\x10\x15\x09\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_53_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x86\x04\x0b\x00\x8b\x08\x13\x03",
};
static struct PyCodeObject toplevel_consts_53_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_53_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 741,
    .co_code = & toplevel_consts_53_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_53_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x09\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x71\x03\x23\x00\x74\x01\x79\x10\x01\x00\x59\x00\x64\x02\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[55];
    }
toplevel_consts_53_consts_7_consts_0 = {
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
    ._data = "This is slow (creates N new iterators!) but effective.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_53_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_53_consts_7_consts_0._ascii.ob_base,
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
toplevel_consts_53_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_6_name._ascii.ob_base,
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_53_consts_7_name = {
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
    ._data = "clear",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_53_consts_7_qualname = {
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
    ._data = "MutableSet.clear",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_53_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x02\x01\x0a\x01\x02\xff\x02\x80\x06\x02\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_53_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x06\x02\xfd\x0a\x01\x02\xff\x02\x80\x02\x02\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_53_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x11\x13\x17\x11\x15\x11\x1b\x11\x1b\x11\x1b\x11\x1b\x13\x17\x00\x00\x10\x18\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_53_consts_7_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x07\x09\x00\x89\x04\x11\x03\x90\x01\x11\x03",
};
static struct PyCodeObject toplevel_consts_53_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_53_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 751,
    .co_code = & toplevel_consts_53_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_53_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x44\x00\x5d\x08\x7d\x02\x7c\x00\xa0\x00\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x03\x7c\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_53_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_53_consts_8_name = {
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
        uint8_t _data[19];
    }
toplevel_consts_53_consts_8_qualname = {
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
    ._data = "MutableSet.__ior__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_53_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_53_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x04\x01\x02\xff\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_53_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x18\x09\x1c\x09\x1c\x0d\x12\x0d\x11\x0d\x1c\x16\x1b\x0d\x1c\x0d\x1c\x0d\x1c\x0d\x1c\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_53_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 759,
    .co_code = & toplevel_consts_53_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_53_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x7c\x01\x7a\x0a\x44\x00\x5d\x08\x7d\x02\x7c\x00\xa0\x00\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x05\x7c\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_53_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_53_consts_9_name = {
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
    ._data = "__iand__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_53_consts_9_qualname = {
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
    ._data = "MutableSet.__iand__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_53_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_53_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x04\x01\x02\xff\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_53_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x17\x1b\x1e\x20\x17\x20\x09\x20\x09\x20\x0d\x12\x0d\x11\x0d\x20\x1a\x1f\x0d\x20\x0d\x20\x0d\x20\x0d\x20\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_53_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 764,
    .co_code = & toplevel_consts_53_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[95];
    }
toplevel_consts_53_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x75\x00\x72\x0c\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x7c\x00\x53\x00\x74\x01\x7c\x01\x74\x02\xa9\x02\x73\x17\x7c\x00\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x44\x00\x5d\x13\x7d\x02\x7c\x02\x7c\x00\x76\x00\x72\x26\x7c\x00\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x19\x7c\x00\xa0\x05\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x19\x7c\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_53_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_53_consts_7_name._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_51_consts_8_name._ascii.ob_base,
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
            & toplevel_consts_53_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_53_consts_10_name = {
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
    ._data = "__ixor__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_53_consts_10_qualname = {
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
    ._data = "MutableSet.__ixor__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_53_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0a\x01\x04\x09\x0a\xf9\x0c\x01\x08\x01\x08\x01\x0e\x01\x0e\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_53_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x09\x0a\xf8\x04\x09\x08\xf9\x0e\x01\x02\x01\x04\x04\x02\xfc\x06\x01\x02\x03\x0e\xfe\x0e\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[95];
    }
toplevel_consts_53_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x12\x16\x0c\x16\x09\x24\x0d\x11\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x10\x14\x09\x14\x14\x1e\x1f\x21\x23\x26\x14\x27\x0d\x2d\x16\x1a\x16\x2d\x2a\x2c\x16\x2d\x16\x2d\x11\x13\x1a\x1c\x0d\x24\x0d\x24\x11\x16\x14\x19\x1d\x21\x14\x21\x11\x24\x15\x19\x15\x28\x22\x27\x15\x28\x15\x28\x15\x28\x15\x28\x15\x19\x15\x24\x1e\x23\x15\x24\x15\x24\x15\x24\x15\x24\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_53_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 769,
    .co_code = & toplevel_consts_53_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_53_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x75\x00\x72\x0c\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x7c\x00\x53\x00\x7c\x01\x44\x00\x5d\x08\x7d\x02\x7c\x00\xa0\x01\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x0e\x7c\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_53_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_7_name._ascii.ob_base,
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_53_consts_11_name = {
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
    ._data = "__isub__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_53_consts_11_qualname = {
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
    ._data = "MutableSet.__isub__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_53_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0a\x01\x04\x04\x08\xfe\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_53_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x04\x0a\xfd\x04\x04\x02\xfe\x04\x01\x02\xff\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_53_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x12\x16\x0c\x16\x09\x24\x0d\x11\x0d\x19\x0d\x19\x0d\x19\x0d\x19\x10\x14\x09\x14\x1a\x1c\x0d\x24\x0d\x24\x11\x16\x11\x15\x11\x24\x1e\x23\x11\x24\x11\x24\x11\x24\x11\x24\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_53_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 782,
    .co_code = & toplevel_consts_53_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_53_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_53_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_53_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_6_15._ascii.ob_base,
            & toplevel_consts_53_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_53_consts_3.ob_base,
            & toplevel_consts_53_consts_4.ob_base,
            & toplevel_consts_53_consts_5.ob_base,
            & toplevel_consts_53_consts_6.ob_base,
            & toplevel_consts_53_consts_7.ob_base,
            & toplevel_consts_53_consts_8.ob_base,
            & toplevel_consts_53_consts_9.ob_base,
            & toplevel_consts_53_consts_10.ob_base,
            & toplevel_consts_53_consts_11.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_53_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_53_consts_3_name._ascii.ob_base,
            & toplevel_consts_53_consts_4_name._ascii.ob_base,
            & toplevel_consts_53_consts_5_name._ascii.ob_base,
            & toplevel_consts_53_consts_6_name._ascii.ob_base,
            & toplevel_consts_53_consts_7_name._ascii.ob_base,
            & toplevel_consts_53_consts_8_name._ascii.ob_base,
            & toplevel_consts_53_consts_9_name._ascii.ob_base,
            & toplevel_consts_53_consts_10_name._ascii.ob_base,
            & toplevel_consts_53_consts_11_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_53_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x0b\x02\x02\x04\x01\x02\xff\x02\x01\x02\x04\x04\x01\x02\xff\x02\x01\x06\x04\x06\x06\x06\x0a\x06\x08\x06\x05\x06\x05\x0a\x0d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_53_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x0a\x04\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x04\x03\x02\xfd\x02\x03\x06\x06\x06\x0a\x06\x08\x06\x05\x06\x05\x06\x0d\x0a\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_53_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x06\x14\x05\x22\x05\x22\x06\x14\x05\x22\x06\x14\x05\x22\x05\x22\x06\x14\x05\x22\x05\x1c\x05\x1c\x05\x1c\x05\x15\x05\x15\x05\x15\x05\x11\x05\x11\x05\x11\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14",
};
static struct PyCodeObject toplevel_consts_53 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_53_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_53_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 711,
    .co_code = & toplevel_consts_53_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_15._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_15._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_53_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_55_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x03\x5a\x05\x65\x06\x64\x04\x84\x00\xa9\x01\x5a\x07\x64\x0c\x64\x06\x84\x01\x5a\x08\x64\x07\x84\x00\x5a\x09\x64\x08\x84\x00\x5a\x0a\x64\x09\x84\x00\x5a\x0b\x64\x0a\x84\x00\x5a\x0c\x64\x0b\x84\x00\x5a\x0d\x64\x05\x5a\x0e\x64\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[199];
    }
toplevel_consts_55_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 198,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x4d\x61\x70\x70\x69\x6e\x67\x20\x69\x73\x20\x61\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x20\x66\x6f\x72\x20\x61\x73\x73\x6f\x63\x69\x61\x74\x69\x6e\x67\x20\x6b\x65\x79\x2f\x76\x61\x6c\x75\x65\x0a\x20\x20\x20\x20\x70\x61\x69\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x63\x6c\x61\x73\x73\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x63\x6f\x6e\x63\x72\x65\x74\x65\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x6f\x66\x20\x61\x6c\x6c\x0a\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x65\x78\x63\x65\x70\x74\x20\x66\x6f\x72\x20\x5f\x5f\x67\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x69\x74\x65\x72\x5f\x5f\x2c\x20\x61\x6e\x64\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_55_consts_3 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_55_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_55_consts_4_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_55_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_55_consts_4_qualname = {
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
    ._data = "Mapping.__getitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_55_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x17\x09\x17",
};
static struct PyCodeObject toplevel_consts_55_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 809,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_55_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x7c\x01\x19\x00\x53\x00\x23\x00\x74\x00\x79\x0e\x01\x00\x7c\x02\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[61];
    }
toplevel_consts_55_consts_6_consts_0 = {
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
    ._data = "D.get(k[,d]) -> D[k] if k in D, else d.  d defaults to None.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_55_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_55_consts_6_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_55_consts_6_varnames_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_55_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_55_consts_6_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_55_consts_6_name = {
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
        uint8_t _data[12];
    }
toplevel_consts_55_consts_6_qualname = {
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
    ._data = "Mapping.get",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_55_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x08\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_55_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x08\xfe\x02\x80\x02\x01\x0e\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_55_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x1b\x14\x18\x19\x1c\x14\x1d\x0d\x1d\x00\x00\x10\x18\x09\x1b\x09\x1b\x14\x1b\x0d\x1b\x0d\x1b\x0d\x1b\x09\x1b\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_55_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x03\x06\x00\x86\x06\x0f\x03\x8e\x01\x0f\x03",
};
static struct PyCodeObject toplevel_consts_55_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_55_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 813,
    .co_code = & toplevel_consts_55_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_55_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_55_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x7c\x01\x19\x00\x01\x00\x64\x02\x53\x00\x23\x00\x74\x00\x79\x0f\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_55_consts_7_qualname = {
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
    ._data = "Mapping.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_55_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x08\x01\x04\x04\x02\x80\x06\xfd\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_55_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x06\x08\xfc\x04\x04\x02\x80\x02\xfd\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_55_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x18\x0d\x11\x12\x15\x0d\x16\x0d\x16\x14\x18\x14\x18\x00\x00\x10\x18\x09\x19\x09\x19\x14\x19\x14\x19\x14\x19\x09\x19\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_55_consts_7_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x04\x08\x00\x88\x04\x10\x03\x8f\x01\x10\x03",
};
static struct PyCodeObject toplevel_consts_55_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_51_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_55_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 820,
    .co_code = & toplevel_consts_55_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_55_consts_8_code = {
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
        uint8_t _data[59];
    }
toplevel_consts_55_consts_8_consts_0 = {
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
    ._data = "D.keys() -> a set-like object providing a view on D's keys",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_55_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_55_consts_8_consts_0._ascii.ob_base,
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
toplevel_consts_55_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_19._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_55_consts_8_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_55_consts_8_qualname = {
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
    ._data = "Mapping.keys",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_55_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_55_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x18\x19\x1d\x10\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_55_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 828,
    .co_code = & toplevel_consts_55_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_55_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[61];
    }
toplevel_consts_55_consts_9_consts_0 = {
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
    ._data = "D.items() -> a set-like object providing a view on D's items",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_55_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_55_consts_9_consts_0._ascii.ob_base,
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
toplevel_consts_55_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_20._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_55_consts_9_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_55_consts_9_qualname = {
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
    ._data = "Mapping.items",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_55_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x19\x1a\x1e\x10\x1f\x09\x1f",
};
static struct PyCodeObject toplevel_consts_55_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 832,
    .co_code = & toplevel_consts_55_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_55_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[55];
    }
toplevel_consts_55_consts_10_consts_0 = {
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
    ._data = "D.values() -> an object providing a view on D's values",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_55_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_55_consts_10_consts_0._ascii.ob_base,
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
toplevel_consts_55_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_21._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_55_consts_10_name = {
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
        uint8_t _data[15];
    }
toplevel_consts_55_consts_10_qualname = {
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
    ._data = "Mapping.values",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_55_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x1f\x10\x20\x09\x20",
};
static struct PyCodeObject toplevel_consts_55_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 836,
    .co_code = & toplevel_consts_55_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_55_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_55_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x08\x74\x02\x53\x00\x74\x03\x7c\x00\xa0\x04\xa8\x00\xa9\x00\xa9\x01\x74\x03\x7c\x01\xa0\x04\xa8\x00\xa9\x00\xa9\x01\x6b\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_55_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_55_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_55_consts_11_qualname = {
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
    ._data = "Mapping.__eq__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_55_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x1a\x1b\x20\x22\x29\x10\x2a\x09\x22\x14\x22\x0d\x22\x10\x14\x15\x19\x15\x21\x15\x21\x15\x21\x10\x22\x26\x2a\x2b\x30\x2b\x38\x2b\x38\x2b\x38\x26\x39\x10\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_55_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 840,
    .co_code = & toplevel_consts_55_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_51_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_51_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_51_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_55_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_55_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_55_consts_3.ob_base.ob_base,
            & toplevel_consts_55_consts_4.ob_base,
            Py_None,
            & toplevel_consts_55_consts_6.ob_base,
            & toplevel_consts_55_consts_7.ob_base,
            & toplevel_consts_55_consts_8.ob_base,
            & toplevel_consts_55_consts_9.ob_base,
            & toplevel_consts_55_consts_10.ob_base,
            & toplevel_consts_55_consts_11.ob_base,
            & toplevel_consts_5_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_55_names_5 = {
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
    ._data = "__abc_tpflags__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_55_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_55_names_5._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_name._ascii.ob_base,
            & toplevel_consts_55_consts_6_name._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
            & toplevel_consts_55_consts_8_name._ascii.ob_base,
            & toplevel_consts_55_consts_9_name._ascii.ob_base,
            & toplevel_consts_55_consts_10_name._ascii.ob_base,
            & toplevel_consts_51_consts_7_name._ascii.ob_base,
            & toplevel_consts_34_consts_2_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_55_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x07\x04\x03\x02\x02\x04\x01\x02\xff\x02\x01\x08\x03\x06\x07\x06\x08\x06\x04\x06\x04\x06\x04\x08\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_55_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x06\x04\x02\x04\x03\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x06\x05\x06\x08\x06\x04\x06\x04\x06\x04\x06\x05\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_55_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x17\x1d\x05\x14\x06\x14\x05\x17\x05\x17\x06\x14\x05\x17\x20\x24\x05\x1b\x05\x1b\x05\x1b\x05\x18\x05\x18\x05\x18\x05\x1e\x05\x1e\x05\x1e\x05\x1f\x05\x1f\x05\x1f\x05\x20\x05\x20\x05\x20\x05\x39\x05\x39\x05\x39\x14\x18\x05\x11\x05\x11\x05\x11",
};
static struct PyCodeObject toplevel_consts_55 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 796,
    .co_code = & toplevel_consts_55_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_16._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_16._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_57_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x65\x07\x65\x08\xa9\x01\x5a\x09\x64\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_57_consts_1_0 = {
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
    ._data = "_mapping",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_57_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_57_consts_1_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_57_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_57_consts_2_varnames_1 = {
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
    ._data = "mapping",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_57_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_57_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_57_consts_2_name = {
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
        uint8_t _data[21];
    }
toplevel_consts_57_consts_2_qualname = {
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
    ._data = "MappingView.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_57_consts_2_linetable = {
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
toplevel_consts_57_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x19\x20\x09\x0d\x09\x16\x09\x16\x09\x16",
};
static struct PyCodeObject toplevel_consts_57_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_57_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 854,
    .co_code = & toplevel_consts_57_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_57_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_57_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_57_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_57_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_57_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_57_consts_3_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_57_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_57_consts_1_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_57_consts_3_qualname = {
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
    ._data = "MappingView.__len__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_57_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x13\x14\x18\x14\x21\x10\x22\x09\x22",
};
static struct PyCodeObject toplevel_consts_57_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_57_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 857,
    .co_code = & toplevel_consts_57_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_38_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_57_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_57_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_57_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\xa0\x00\x7c\x00\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_57_consts_4_consts_1 = {
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
    ._data = "{0.__class__.__name__}({0._mapping!r})",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_57_consts_4_consts = {
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
            & toplevel_consts_57_consts_4_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_57_consts_4_names_0 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_57_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_57_consts_4_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_57_consts_4_qualname = {
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
    ._data = "MappingView.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_57_consts_4_linetable = {
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
toplevel_consts_57_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x38\x10\x45\x40\x44\x10\x45\x10\x45\x09\x45",
};
static struct PyCodeObject toplevel_consts_57_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_57_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_57_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 860,
    .co_code = & toplevel_consts_57_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_5_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_57_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_57_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_57_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_6_18._ascii.ob_base,
            & toplevel_consts_57_consts_1._object.ob_base.ob_base,
            & toplevel_consts_57_consts_2.ob_base,
            & toplevel_consts_57_consts_3.ob_base,
            & toplevel_consts_57_consts_4.ob_base,
            Py_None,
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
toplevel_consts_57_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_57_consts_2_name._ascii.ob_base,
            & toplevel_consts_38_consts_2_name._ascii.ob_base,
            & toplevel_consts_44_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_consts_20_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_57_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x02\x06\x03\x06\x03\x0c\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_57_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x03\x06\x03\x06\x03\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_57_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x1c\x05\x0e\x05\x20\x05\x20\x05\x20\x05\x22\x05\x22\x05\x22\x05\x45\x05\x45\x05\x45\x19\x24\x25\x31\x19\x32\x05\x16\x05\x16\x05\x16",
};
static struct PyCodeObject toplevel_consts_57 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_57_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_57_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 850,
    .co_code = & toplevel_consts_57_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_18._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_18._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_57_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_59_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x64\x03\x84\x00\x5a\x06\x64\x04\x84\x00\x5a\x07\x64\x05\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_59_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_59_consts_2_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_59_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_59_consts_2_names_0._ascii.ob_base,
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
toplevel_consts_59_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_8_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_59_consts_2_qualname = {
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
    ._data = "KeysView._from_iterable",
};
static struct PyCodeObject toplevel_consts_59_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_59_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 870,
    .co_code = & toplevel_consts_59_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_59_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_59_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_59_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_59_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x6a\x00\x76\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_59_consts_3_qualname = {
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
    ._data = "KeysView.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_59_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x13\x17\x1b\x17\x24\x10\x24\x09\x24",
};
static struct PyCodeObject toplevel_consts_59_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 874,
    .co_code = & toplevel_consts_59_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_59_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_59_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_59_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x6a\x00\x45\x00\x64\x00\x7b\x02\x97\x02\x71\x06\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_59_consts_4_qualname = {
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
    ._data = "KeysView.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_59_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_59_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x18\x14\x21\x09\x21\x09\x21\x09\x21\x09\x21\x09\x21\x09\x21\x09\x21\x09\x21",
};
static struct PyCodeObject toplevel_consts_59_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 877,
    .co_code = & toplevel_consts_59_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_59_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_59_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_59_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_59_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_59_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_6_19._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_59_consts_2.ob_base,
            & toplevel_consts_59_consts_3.ob_base,
            & toplevel_consts_59_consts_4.ob_base,
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
toplevel_consts_59_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_17_names_6._ascii.ob_base,
            & toplevel_consts_51_consts_8_name._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_59_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_59_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x06\x03\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_59_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x11\x05\x17\x05\x17\x06\x11\x05\x17\x05\x24\x05\x24\x05\x24\x05\x21\x05\x21\x05\x21\x05\x21\x05\x21",
};
static struct PyCodeObject toplevel_consts_59 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_59_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_59_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 866,
    .co_code = & toplevel_consts_59_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_19._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_19._ascii.ob_base,
    .co_linetable = & toplevel_consts_59_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_59_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_59_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_61_consts_2_qualname = {
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
    ._data = "ItemsView._from_iterable",
};
static struct PyCodeObject toplevel_consts_61_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_59_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 888,
    .co_code = & toplevel_consts_59_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_59_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_51_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_61_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_51_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_59_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_61_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x5c\x02\x7d\x02\x7d\x03\x09\x00\x7c\x00\x6a\x00\x7c\x02\x19\x00\x7d\x04\x6e\x0b\x23\x00\x74\x01\x79\x13\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x04\x7c\x03\x75\x00\x70\x1e\x7c\x04\x7c\x03\x6b\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_61_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_57_consts_1_0._ascii.ob_base,
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_61_consts_3_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_61_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_44_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_61_consts_3_qualname = {
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
    ._data = "ItemsView.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_61_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_61_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x06\x0c\xfc\x02\x80\x02\x01\x0c\x01\x06\x80\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_61_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x1a\x09\x13\x09\x0c\x0e\x13\x09\x2c\x11\x15\x11\x1e\x1f\x22\x11\x23\x0d\x0e\x0d\x0e\x00\x00\x10\x18\x09\x19\x09\x19\x14\x19\x14\x19\x14\x19\x09\x19\x00\x00\x00\x00\x00\x00\x14\x15\x19\x1e\x14\x1e\x14\x2c\x22\x23\x27\x2c\x22\x2c\x0d\x2c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_61_consts_3_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x86\x05\x0c\x00\x8c\x04\x14\x03\x93\x01\x14\x03",
};
static struct PyCodeObject toplevel_consts_61_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_40_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_61_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_61_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_61_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 892,
    .co_code = & toplevel_consts_61_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_61_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_61_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_61_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_61_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_61_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_61_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_61_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x6a\x00\x44\x00\x5d\x0b\x7d\x01\x7c\x01\x7c\x00\x6a\x00\x7c\x01\x19\x00\x66\x02\x56\x00\x97\x01\x01\x00\x71\x05\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_61_consts_4_qualname = {
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
    ._data = "ItemsView.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_61_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x14\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_61_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x04\x01\x02\xff\x18\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_61_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x18\x14\x21\x09\x2c\x09\x2c\x0d\x10\x14\x17\x19\x1d\x19\x26\x27\x2a\x19\x2b\x13\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x09\x2c\x09\x2c",
};
static struct PyCodeObject toplevel_consts_61_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_61_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 901,
    .co_code = & toplevel_consts_61_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_61_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_61_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_61_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_61_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_61_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_6_20._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_61_consts_2.ob_base,
            & toplevel_consts_61_consts_3.ob_base,
            & toplevel_consts_61_consts_4.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_61_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x06\x03\x0a\x09",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_61_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x06\x09\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_61_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x06\x11\x05\x17\x05\x17\x06\x11\x05\x17\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x2c",
};
static struct PyCodeObject toplevel_consts_61 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_61_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_59_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 884,
    .co_code = & toplevel_consts_59_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_20._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_20._ascii.ob_base,
    .co_linetable = & toplevel_consts_61_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_61_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_61_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_63_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_63_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x44\x00\x5d\x12\x7d\x02\x7c\x00\x6a\x00\x7c\x02\x19\x00\x7d\x03\x7c\x03\x7c\x01\x75\x00\x73\x13\x7c\x03\x7c\x01\x6b\x02\x72\x16\x01\x00\x64\x01\x53\x00\x71\x04\x64\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_63_consts_2_consts = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_63_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_63_consts_2_qualname = {
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
    ._data = "ValuesView.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_63_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x10\x01\x06\x01\x02\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_63_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x04\x03\x02\xfd\x0a\x01\x06\x01\x02\x01\x06\xff\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_63_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x18\x14\x21\x09\x1c\x09\x1c\x0d\x10\x11\x15\x11\x1e\x1f\x22\x11\x23\x0d\x0e\x10\x11\x15\x1a\x10\x1a\x0d\x1c\x1e\x1f\x23\x28\x1e\x28\x0d\x1c\x18\x1c\x18\x1c\x18\x1c\x0d\x1c\x10\x15\x10\x15",
};
static struct PyCodeObject toplevel_consts_63_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_63_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_63_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 913,
    .co_code = & toplevel_consts_63_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_63_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_63_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_63_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_63_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_63_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_63_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_63_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x6a\x00\x44\x00\x5d\x09\x7d\x01\x7c\x00\x6a\x00\x7c\x01\x19\x00\x56\x00\x97\x01\x01\x00\x71\x05\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_63_consts_3_qualname = {
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
    ._data = "ValuesView.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_63_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x10\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_63_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x04\x01\x02\xff\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_63_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x14\x18\x14\x21\x09\x25\x09\x25\x0d\x10\x13\x17\x13\x20\x21\x24\x13\x25\x0d\x25\x0d\x25\x0d\x25\x0d\x25\x09\x25\x09\x25",
};
static struct PyCodeObject toplevel_consts_63_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_consts_1._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_63_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 920,
    .co_code = & toplevel_consts_63_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_63_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_63_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_63_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_63_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_63_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_6_21._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_63_consts_2.ob_base,
            & toplevel_consts_63_consts_3.ob_base,
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
toplevel_consts_63_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_63_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x02\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_63_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x07\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_63_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x11\x13\x05\x0e\x05\x15\x05\x15\x05\x15\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25",
};
static struct PyCodeObject toplevel_consts_63 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_63_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_63_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_63_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 909,
    .co_code = & toplevel_consts_63_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_21._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_21._ascii.ob_base,
    .co_linetable = & toplevel_consts_63_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_63_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_63_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_65_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x05\x64\x04\x84\x00\xa9\x01\x5a\x07\x65\x08\xa9\x00\x5a\x09\x65\x09\x66\x01\x64\x05\x84\x01\x5a\x0a\x64\x06\x84\x00\x5a\x0b\x64\x07\x84\x00\x5a\x0c\x64\x0b\x64\x08\x84\x01\x5a\x0d\x64\x0c\x64\x0a\x84\x01\x5a\x0e\x64\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[236];
    }
toplevel_consts_65_consts_1 = {
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
    ._data = "\x41\x20\x4d\x75\x74\x61\x62\x6c\x65\x4d\x61\x70\x70\x69\x6e\x67\x20\x69\x73\x20\x61\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x63\x6f\x6e\x74\x61\x69\x6e\x65\x72\x20\x66\x6f\x72\x20\x61\x73\x73\x6f\x63\x69\x61\x74\x69\x6e\x67\x0a\x20\x20\x20\x20\x6b\x65\x79\x2f\x76\x61\x6c\x75\x65\x20\x70\x61\x69\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x63\x6c\x61\x73\x73\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x63\x6f\x6e\x63\x72\x65\x74\x65\x20\x67\x65\x6e\x65\x72\x69\x63\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x6f\x66\x20\x61\x6c\x6c\x0a\x20\x20\x20\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x65\x78\x63\x65\x70\x74\x20\x66\x6f\x72\x20\x5f\x5f\x67\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x73\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x64\x65\x6c\x69\x74\x65\x6d\x5f\x5f\x2c\x0a\x20\x20\x20\x20\x5f\x5f\x69\x74\x65\x72\x5f\x5f\x2c\x20\x61\x6e\x64\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_65_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_65_consts_3_name = {
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
        uint8_t _data[27];
    }
toplevel_consts_65_consts_3_qualname = {
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
    ._data = "MutableMapping.__setitem__",
};
static struct PyCodeObject toplevel_consts_65_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 939,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_65_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_65_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_65_consts_4_name = {
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
        uint8_t _data[27];
    }
toplevel_consts_65_consts_4_qualname = {
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
    ._data = "MutableMapping.__delitem__",
};
static struct PyCodeObject toplevel_consts_65_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 943,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_65_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x7c\x01\x19\x00\x7d\x03\x6e\x12\x23\x00\x74\x00\x79\x15\x01\x00\x7c\x02\x7c\x00\x6a\x01\x75\x00\x72\x11\x82\x00\x7c\x02\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x7c\x01\x3d\x00\x7c\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[170];
    }
toplevel_consts_65_consts_5_consts_0 = {
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
    ._data = "\x44\x2e\x70\x6f\x70\x28\x6b\x5b\x2c\x64\x5d\x29\x20\x2d\x3e\x20\x76\x2c\x20\x72\x65\x6d\x6f\x76\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x6b\x65\x79\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x63\x6f\x72\x72\x65\x73\x70\x6f\x6e\x64\x69\x6e\x67\x20\x76\x61\x6c\x75\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x6b\x65\x79\x20\x69\x73\x20\x6e\x6f\x74\x20\x66\x6f\x75\x6e\x64\x2c\x20\x64\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x69\x66\x20\x67\x69\x76\x65\x6e\x2c\x20\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x20\x4b\x65\x79\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_65_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_65_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_65_consts_5_names_1 = {
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
    ._data = "_MutableMapping__marker",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_65_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_65_consts_5_names_1._ascii.ob_base,
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
toplevel_consts_65_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_55_consts_6_varnames_2._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_65_consts_5_qualname = {
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
    ._data = "MutableMapping.pop",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_65_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x0a\x01\x02\x80\x06\x01\x0a\x01\x02\x01\x08\x01\x02\xfd\x06\x80\x06\x05\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_65_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0c\x0a\xf9\x02\x80\x02\x01\x04\x03\x08\xfe\x04\x01\x0a\x01\x06\x80\x06\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_65_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x19\x15\x19\x1a\x1d\x15\x1e\x0d\x12\x0d\x12\x00\x00\x10\x18\x09\x1b\x09\x1b\x10\x17\x1b\x1f\x1b\x28\x10\x28\x0d\x16\x11\x16\x14\x1b\x0d\x1b\x0d\x1b\x0d\x1b\x09\x1b\x00\x00\x00\x00\x00\x00\x11\x15\x16\x19\x11\x1a\x14\x19\x0d\x19",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_65_consts_5_exceptiontable = {
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
static struct PyCodeObject toplevel_consts_65_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_65_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_65_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_65_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 949,
    .co_code = & toplevel_consts_65_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_65_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_65_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_65_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_65_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_65_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x74\x01\x7c\x00\xa9\x01\xa9\x01\x7d\x01\x6e\x0b\x23\x00\x74\x02\x79\x10\x01\x00\x74\x03\x64\x01\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x7c\x01\x19\x00\x7d\x02\x7c\x00\x7c\x01\x3d\x00\x7c\x01\x7c\x02\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[132];
    }
toplevel_consts_65_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 131,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x2e\x70\x6f\x70\x69\x74\x65\x6d\x28\x29\x20\x2d\x3e\x20\x28\x6b\x2c\x20\x76\x29\x2c\x20\x72\x65\x6d\x6f\x76\x65\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x73\x6f\x6d\x65\x20\x28\x6b\x65\x79\x2c\x20\x76\x61\x6c\x75\x65\x29\x20\x70\x61\x69\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x61\x73\x20\x61\x20\x32\x2d\x74\x75\x70\x6c\x65\x3b\x20\x62\x75\x74\x20\x72\x61\x69\x73\x65\x20\x4b\x65\x79\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x44\x20\x69\x73\x20\x65\x6d\x70\x74\x79\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_65_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_65_consts_6_consts_0._ascii.ob_base,
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
toplevel_consts_65_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_53_consts_6_names_1._ascii.ob_base,
            & toplevel_consts_53_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_65_consts_6_name = {
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
    ._data = "popitem",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_65_consts_6_qualname = {
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
    ._data = "MutableMapping.popitem",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_65_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x0e\x01\x02\x80\x06\x01\x06\x01\x02\xff\x06\x80\x08\x02\x06\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_65_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x0e\xfe\x02\x80\x02\x01\x0c\x01\x06\x80\x08\x01\x06\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_65_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x25\x13\x17\x18\x1c\x1d\x21\x18\x22\x13\x23\x0d\x10\x0d\x10\x00\x00\x10\x1d\x09\x25\x09\x25\x13\x1b\x21\x25\x0d\x25\x09\x25\x00\x00\x00\x00\x00\x00\x11\x15\x16\x19\x11\x1a\x09\x0e\x0d\x11\x12\x15\x0d\x16\x10\x13\x15\x1a\x10\x1a\x09\x1a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_65_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x06\x09\x00\x89\x08\x11\x03",
};
static struct PyCodeObject toplevel_consts_65_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_65_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_65_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_65_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 963,
    .co_code = & toplevel_consts_65_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_65_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_65_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_65_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_65_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_65_consts_7_consts_0 = {
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
    ._data = "D.clear() -> None.  Remove all items from D.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_65_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_65_consts_7_consts_0._ascii.ob_base,
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
toplevel_consts_65_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_65_consts_6_name._ascii.ob_base,
            & toplevel_consts_53_consts_5_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_65_consts_7_qualname = {
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
    ._data = "MutableMapping.clear",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_65_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x11\x13\x17\x11\x15\x11\x1f\x11\x1f\x11\x1f\x11\x1f\x13\x17\x00\x00\x10\x18\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00",
};
static struct PyCodeObject toplevel_consts_65_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_65_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_53_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 975,
    .co_code = & toplevel_consts_53_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_65_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\x74\x01\xa9\x02\x72\x12\x7c\x01\x44\x00\x5d\x08\x7d\x03\x7c\x01\x7c\x03\x19\x00\x7c\x00\x7c\x03\x3c\x00\x71\x08\x6e\x1f\x74\x02\x7c\x01\x64\x01\xa9\x02\x72\x26\x7c\x01\xa0\x03\xa8\x00\xa9\x00\x44\x00\x5d\x08\x7d\x03\x7c\x01\x7c\x03\x19\x00\x7c\x00\x7c\x03\x3c\x00\x71\x1c\x6e\x0b\x7c\x01\x44\x00\x5d\x08\x5c\x02\x7d\x03\x7d\x04\x7c\x04\x7c\x00\x7c\x03\x3c\x00\x71\x28\x7c\x02\xa0\x04\xa8\x00\xa9\x00\x44\x00\x5d\x08\x5c\x02\x7d\x03\x7d\x04\x7c\x04\x7c\x00\x7c\x03\x3c\x00\x71\x36\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[332];
    }
toplevel_consts_65_consts_8_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 331,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x20\x44\x2e\x75\x70\x64\x61\x74\x65\x28\x5b\x45\x2c\x20\x5d\x2a\x2a\x46\x29\x20\x2d\x3e\x20\x4e\x6f\x6e\x65\x2e\x20\x20\x55\x70\x64\x61\x74\x65\x20\x44\x20\x66\x72\x6f\x6d\x20\x6d\x61\x70\x70\x69\x6e\x67\x2f\x69\x74\x65\x72\x61\x62\x6c\x65\x20\x45\x20\x61\x6e\x64\x20\x46\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x45\x20\x70\x72\x65\x73\x65\x6e\x74\x20\x61\x6e\x64\x20\x68\x61\x73\x20\x61\x20\x2e\x6b\x65\x79\x73\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x2c\x20\x64\x6f\x65\x73\x3a\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x6b\x20\x69\x6e\x20\x45\x3a\x20\x44\x5b\x6b\x5d\x20\x3d\x20\x45\x5b\x6b\x5d\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x45\x20\x70\x72\x65\x73\x65\x6e\x74\x20\x61\x6e\x64\x20\x6c\x61\x63\x6b\x73\x20\x2e\x6b\x65\x79\x73\x28\x29\x20\x6d\x65\x74\x68\x6f\x64\x2c\x20\x64\x6f\x65\x73\x3a\x20\x20\x20\x20\x20\x66\x6f\x72\x20\x28\x6b\x2c\x20\x76\x29\x20\x69\x6e\x20\x45\x3a\x20\x44\x5b\x6b\x5d\x20\x3d\x20\x76\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x49\x6e\x20\x65\x69\x74\x68\x65\x72\x20\x63\x61\x73\x65\x2c\x20\x74\x68\x69\x73\x20\x69\x73\x20\x66\x6f\x6c\x6c\x6f\x77\x65\x64\x20\x62\x79\x3a\x20\x66\x6f\x72\x20\x6b\x2c\x20\x76\x20\x69\x6e\x20\x46\x2e\x69\x74\x65\x6d\x73\x28\x29\x3a\x20\x44\x5b\x6b\x5d\x20\x3d\x20\x76\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_65_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_65_consts_8_consts_0._ascii.ob_base,
            & toplevel_consts_55_consts_8_name._ascii.ob_base,
            Py_None,
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
toplevel_consts_65_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_55_consts_8_name._ascii.ob_base,
            & toplevel_consts_55_consts_9_name._ascii.ob_base,
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
toplevel_consts_65_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_49_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_55_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_65_consts_8_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_65_consts_8_qualname = {
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
    ._data = "MutableMapping.update",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_65_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x08\x01\x0e\x01\x02\xff\x0a\x02\x0e\x01\x0e\x01\x02\xff\x0c\x03\x0a\x01\x12\x01\x0a\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_65_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x06\x02\x08\x02\xf9\x04\x01\x02\xff\x10\x01\x08\x01\x02\x05\x08\xfc\x04\x01\x02\xff\x10\x01\x02\x02\x04\x01\x06\xff\x0a\x01\x08\x01\x04\x01\x06\xff\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_65_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x16\x17\x1c\x1e\x25\x0c\x26\x09\x22\x18\x1d\x0d\x27\x0d\x27\x11\x14\x1d\x22\x23\x26\x1d\x27\x11\x15\x16\x19\x11\x1a\x11\x1a\x0d\x27\x0e\x15\x16\x1b\x1d\x23\x0e\x24\x09\x22\x18\x1d\x18\x24\x18\x24\x18\x24\x0d\x27\x0d\x27\x11\x14\x1d\x22\x23\x26\x1d\x27\x11\x15\x16\x19\x11\x1a\x11\x1a\x0d\x27\x1f\x24\x0d\x22\x0d\x22\x11\x1b\x11\x14\x16\x1b\x1d\x22\x11\x15\x16\x19\x11\x1a\x11\x1a\x1b\x1f\x1b\x27\x1b\x27\x1b\x27\x09\x1e\x09\x1e\x0d\x17\x0d\x10\x12\x17\x19\x1e\x0d\x11\x12\x15\x0d\x16\x0d\x16\x09\x1e\x09\x1e",
};
static struct PyCodeObject toplevel_consts_65_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_65_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_65_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 11,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 2,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 983,
    .co_code = & toplevel_consts_65_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_65_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_65_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_65_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_65_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_65_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x7c\x01\x19\x00\x53\x00\x23\x00\x74\x00\x79\x11\x01\x00\x7c\x02\x7c\x00\x7c\x01\x3c\x00\x59\x00\x7c\x02\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[65];
    }
toplevel_consts_65_consts_10_consts_0 = {
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
    ._data = "D.setdefault(k[,d]) -> D.get(k,d), also set D[k]=d if k not in D",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_65_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_65_consts_10_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_65_consts_10_name = {
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
        uint8_t _data[26];
    }
toplevel_consts_65_consts_10_qualname = {
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
    ._data = "MutableMapping.setdefault",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_65_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x08\x01\x02\x80\x06\x01\x0a\x01\x04\x01\x02\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_65_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x08\xfe\x02\x80\x02\x01\x0e\x01\x04\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_65_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x20\x14\x18\x19\x1c\x14\x1d\x0d\x1d\x00\x00\x10\x18\x09\x20\x09\x20\x19\x20\x0d\x11\x12\x15\x0d\x16\x0d\x16\x10\x17\x09\x17\x09\x20\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_65_consts_10_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x03\x06\x00\x86\x08\x12\x03\x91\x01\x12\x03",
};
static struct PyCodeObject toplevel_consts_65_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_65_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_65_consts_10_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1001,
    .co_code = & toplevel_consts_65_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_65_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_65_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_65_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_65_consts_11 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_5_names._object.ob_base.ob_base,
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
toplevel_consts_65_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_6_17._ascii.ob_base,
            & toplevel_consts_65_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_65_consts_3.ob_base,
            & toplevel_consts_65_consts_4.ob_base,
            & toplevel_consts_65_consts_5.ob_base,
            & toplevel_consts_65_consts_6.ob_base,
            & toplevel_consts_65_consts_7.ob_base,
            & toplevel_consts_65_consts_8.ob_base,
            Py_None,
            & toplevel_consts_65_consts_10.ob_base,
            & toplevel_consts_65_consts_11._object.ob_base.ob_base,
            & toplevel_consts_5_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_65_names_8 = {
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
            PyObject *ob_item[15];
        }_object;
    }
toplevel_consts_65_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 15,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_65_consts_3_name._ascii.ob_base,
            & toplevel_consts_65_consts_4_name._ascii.ob_base,
            & toplevel_consts_65_names_8._ascii.ob_base,
            & toplevel_consts_65_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_53_consts_6_name._ascii.ob_base,
            & toplevel_consts_65_consts_6_name._ascii.ob_base,
            & toplevel_consts_53_consts_7_name._ascii.ob_base,
            & toplevel_consts_65_consts_8_name._ascii.ob_base,
            & toplevel_consts_65_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_65_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x08\x02\x02\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x02\x01\x06\x03\x0a\x02\x06\x0e\x06\x0c\x08\x08\x0c\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_65_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x07\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x06\x02\x02\x02\x08\x0c\x06\x0c\x06\x08\x02\x02\x06\x10\x02\x02\x0a\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[87];
    }
toplevel_consts_65_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 86,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x06\x14\x05\x17\x05\x17\x06\x14\x05\x17\x06\x14\x05\x17\x05\x17\x06\x14\x05\x17\x10\x16\x10\x18\x05\x0d\x20\x28\x05\x19\x05\x19\x05\x19\x05\x19\x05\x1a\x05\x1a\x05\x1a\x05\x11\x05\x11\x05\x11\x1c\x1e\x05\x1e\x05\x1e\x05\x1e\x27\x2b\x05\x17\x05\x17\x05\x17\x05\x17\x05\x17",
};
static struct PyCodeObject toplevel_consts_65 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_65_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_65_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_65_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 928,
    .co_code = & toplevel_consts_65_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_17._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_17._ascii.ob_base,
    .co_linetable = & toplevel_consts_65_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_65_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_65_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_67_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x03\x5a\x05\x65\x06\x64\x04\x84\x00\xa9\x01\x5a\x07\x64\x05\x84\x00\x5a\x08\x64\x06\x84\x00\x5a\x09\x64\x07\x84\x00\x5a\x0a\x64\x0c\x64\x0a\x84\x01\x5a\x0b\x64\x0b\x84\x00\x5a\x0c\x64\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[139];
    }
toplevel_consts_67_consts_1 = {
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
    ._data = "\x41\x6c\x6c\x20\x74\x68\x65\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x6f\x6e\x20\x61\x20\x72\x65\x61\x64\x2d\x6f\x6e\x6c\x79\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x43\x6f\x6e\x63\x72\x65\x74\x65\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x20\x6d\x75\x73\x74\x20\x6f\x76\x65\x72\x72\x69\x64\x65\x20\x5f\x5f\x6e\x65\x77\x5f\x5f\x20\x6f\x72\x20\x5f\x5f\x69\x6e\x69\x74\x5f\x5f\x2c\x0a\x20\x20\x20\x20\x5f\x5f\x67\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x61\x6e\x64\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_67_consts_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_67_consts_4_names_0 = {
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
    ._data = "IndexError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_67_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_67_consts_4_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_67_consts_4_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_67_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_67_consts_4_qualname = {
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
    ._data = "Sequence.__getitem__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_67_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x19\x09\x19",
};
static struct PyCodeObject toplevel_consts_67_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1027,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_67_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x64\x01\x7d\x01\x09\x00\x09\x00\x7c\x00\x7c\x01\x19\x00\x7d\x02\x7c\x02\x56\x00\x97\x01\x01\x00\x7c\x01\x64\x03\x7a\x0d\x7d\x01\x71\x06\x23\x00\x74\x00\x79\x1a\x01\x00\x59\x00\x64\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_67_consts_5_consts = {
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
            Py_True,
            & toplevel_consts_9.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_67_consts_5_varnames_1 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_67_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_67_consts_5_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_67_consts_5_qualname = {
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
    ._data = "Sequence.__iter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_67_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x02\x01\x02\x01\x08\x01\x08\x01\x08\x01\x02\xfd\x02\x80\x06\x04\x06\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_67_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x01\x02\x07\x02\xfb\x08\x01\x08\x01\x08\x01\x02\xfd\x02\x80\x02\x04\x0c\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_67_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0d\x0e\x09\x0a\x09\x13\x13\x17\x15\x19\x1a\x1b\x15\x1c\x11\x12\x17\x18\x11\x18\x11\x18\x11\x18\x11\x12\x16\x17\x11\x17\x11\x12\x13\x17\x00\x00\x10\x1a\x09\x13\x09\x13\x0d\x13\x0d\x13\x0d\x13\x09\x13\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_67_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x85\x0e\x13\x00\x93\x04\x1b\x03\x9a\x01\x1b\x03",
};
static struct PyCodeObject toplevel_consts_67_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_67_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_67_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1031,
    .co_code = & toplevel_consts_67_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_67_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x44\x00\x5d\x0d\x7d\x02\x7c\x02\x7c\x01\x75\x00\x73\x0d\x7c\x02\x7c\x01\x6b\x02\x72\x10\x01\x00\x64\x01\x53\x00\x71\x03\x64\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_67_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_67_consts_6_qualname = {
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
    ._data = "Sequence.__contains__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_67_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x10\x01\x06\x01\x02\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_67_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x04\x02\x02\xfe\x06\x01\x02\x01\x06\xff\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_67_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x16\x09\x1c\x09\x1c\x0d\x0e\x10\x11\x15\x1a\x10\x1a\x0d\x1c\x1e\x1f\x23\x28\x1e\x28\x0d\x1c\x18\x1c\x18\x1c\x18\x1c\x0d\x1c\x10\x15\x10\x15",
};
static struct PyCodeObject toplevel_consts_67_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_63_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1041,
    .co_code = & toplevel_consts_67_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_40_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_67_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x74\x00\x74\x01\x74\x02\x7c\x00\xa9\x01\xa9\x01\xa9\x01\x44\x00\x5d\x08\x7d\x01\x7c\x00\x7c\x01\x19\x00\x56\x00\x97\x01\x01\x00\x71\x0a\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_67_consts_7_names_0 = {
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
    ._data = "reversed",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_67_consts_7_names_1 = {
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
    ._data = "range",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_67_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_67_consts_7_names_0._ascii.ob_base,
            & toplevel_consts_67_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
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
toplevel_consts_67_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_67_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_67_consts_7_qualname = {
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
    ._data = "Sequence.__reversed__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_67_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x01\x0e\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_67_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0e\x01\x04\x01\x02\xff\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_67_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x12\x1a\x1b\x20\x21\x24\x25\x29\x21\x2a\x1b\x2b\x12\x2c\x09\x1a\x09\x1a\x0d\x0e\x13\x17\x18\x19\x13\x1a\x0d\x1a\x0d\x1a\x0d\x1a\x0d\x1a\x09\x1a\x09\x1a",
};
static struct PyCodeObject toplevel_consts_67_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1047,
    .co_code = & toplevel_consts_67_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_67_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x81\x10\x7c\x02\x64\x02\x6b\x00\x72\x10\x74\x00\x74\x01\x7c\x00\xa9\x01\x7c\x02\x7a\x00\x64\x02\xa9\x02\x7d\x02\x7c\x03\x81\x1c\x7c\x03\x64\x02\x6b\x00\x72\x1c\x7c\x03\x74\x01\x7c\x00\xa9\x01\x7a\x0d\x7d\x03\x7c\x02\x7d\x04\x7c\x03\x81\x24\x7c\x04\x7c\x03\x6b\x00\x72\x49\x09\x00\x7c\x00\x7c\x04\x19\x00\x7d\x05\x7c\x05\x7c\x01\x75\x00\x73\x31\x7c\x05\x7c\x01\x6b\x02\x72\x33\x7c\x04\x53\x00\x6e\x0b\x23\x00\x74\x02\x79\x3b\x01\x00\x59\x00\x74\x03\x82\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x04\x64\x03\x7a\x0d\x7d\x04\x7c\x03\x81\x24\x7c\x04\x7c\x03\x6b\x00\x73\x24\x74\x03\x82\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[231];
    }
toplevel_consts_67_consts_10_consts_0 = {
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
    ._data = "\x53\x2e\x69\x6e\x64\x65\x78\x28\x76\x61\x6c\x75\x65\x2c\x20\x5b\x73\x74\x61\x72\x74\x2c\x20\x5b\x73\x74\x6f\x70\x5d\x5d\x29\x20\x2d\x3e\x20\x69\x6e\x74\x65\x67\x65\x72\x20\x2d\x2d\x20\x72\x65\x74\x75\x72\x6e\x20\x66\x69\x72\x73\x74\x20\x69\x6e\x64\x65\x78\x20\x6f\x66\x20\x76\x61\x6c\x75\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x73\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x74\x68\x65\x20\x76\x61\x6c\x75\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x53\x75\x70\x70\x6f\x72\x74\x69\x6e\x67\x20\x73\x74\x61\x72\x74\x20\x61\x6e\x64\x20\x73\x74\x6f\x70\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x69\x73\x20\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x2c\x20\x62\x75\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x72\x65\x63\x6f\x6d\x6d\x65\x6e\x64\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_67_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_67_consts_10_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_67_consts_10_names_0 = {
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
        uint8_t _data[11];
    }
toplevel_consts_67_consts_10_names_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_67_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_67_consts_10_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_67_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_67_consts_10_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_67_consts_10_varnames_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_67_consts_10_varnames_3 = {
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
    ._data = "stop",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_67_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_67_consts_10_varnames_2._ascii.ob_base,
            & toplevel_consts_67_consts_10_varnames_3._ascii.ob_base,
            & toplevel_consts_67_consts_5_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_67_consts_10_qualname = {
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
    ._data = "Sequence.index",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_67_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07\x12\x01\x0c\x01\x0c\x01\x04\x02\x0c\x01\x02\x01\x08\x01\x10\x01\x04\x01\x02\xff\x02\x80\x06\x02\x02\x01\x04\x02\x02\xfd\x06\x80\x08\x02\x0c\xf9\x04\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_67_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x02\x01\x06\xff\x14\x01\x02\x01\x02\x01\x06\xff\x0e\x01\x04\x02\x02\x01\x02\x07\x06\xf9\x02\x07\x02\xff\x08\xfc\x06\x01\x02\x01\x06\xff\x08\x01\x02\x80\x02\x01\x06\x01\x04\x02\x02\xfe\x06\x80\x08\x01\x02\xf9\x02\x07\x06\xf9\x02\x07\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_67_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x11\x09\x2e\x22\x27\x2a\x2b\x22\x2b\x09\x2e\x15\x18\x19\x1c\x1d\x21\x19\x22\x25\x2a\x19\x2a\x2c\x2d\x15\x2e\x0d\x12\x0c\x10\x09\x1e\x21\x25\x28\x29\x21\x29\x09\x1e\x0d\x11\x15\x18\x19\x1d\x15\x1e\x0d\x1e\x0d\x11\x0d\x12\x09\x0a\x0f\x13\x09\x13\x1f\x20\x23\x27\x1f\x27\x09\x13\x0d\x16\x15\x19\x1a\x1b\x15\x1c\x11\x12\x14\x15\x19\x1e\x14\x1e\x11\x1d\x22\x23\x27\x2c\x22\x2c\x11\x1d\x1c\x1d\x15\x1d\x11\x1d\x00\x00\x14\x1e\x0d\x16\x0d\x16\x11\x16\x0f\x19\x09\x19\x0d\x16\x00\x00\x00\x00\x00\x00\x0d\x0e\x12\x13\x0d\x13\x0d\x0e\x0f\x13\x09\x13\x1f\x20\x23\x27\x1f\x27\x09\x13\x0f\x19\x09\x19",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_67_consts_10_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\xa5\x0d\x34\x00\xb4\x04\x3c\x03\xbb\x01\x3c\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_67_consts_10_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_67_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_67_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_67_consts_10_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1051,
    .co_code = & toplevel_consts_67_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_67_consts_10_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_67_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x01\x97\x00\x74\x00\x88\x01\x66\x01\x64\x01\x84\x08\x7c\x00\x44\x00\xa9\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[67];
    }
toplevel_consts_67_consts_11_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 66,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "S.count(value) -> integer -- return number of occurrences of value",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_67_consts_11_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x01\x00\x97\x00\x7c\x00\x5d\x0e\x7d\x01\x7c\x01\x89\x02\x75\x00\x73\x0e\x7c\x01\x89\x02\x6b\x02\x72\x04\x64\x00\x56\x00\x97\x01\x01\x00\x71\x04\x64\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_67_consts_11_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_9.ob_base.ob_base,
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
toplevel_consts_67_consts_11_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
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
toplevel_consts_67_consts_11_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_67_consts_11_consts_1_qualname = {
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
    ._data = "Sequence.count.<locals>.<genexpr>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_67_consts_11_consts_1_linetable = {
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
toplevel_consts_67_consts_11_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x13\x40\x13\x40\x1a\x1b\x27\x28\x2c\x31\x27\x31\x13\x40\x35\x36\x3a\x3f\x35\x3f\x13\x40\x14\x15\x13\x40\x13\x40\x13\x40\x13\x40\x13\x40\x13\x40",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_67_consts_11_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_67_consts_11_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_67_consts_11_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_11_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 51,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1076,
    .co_code = & toplevel_consts_67_consts_11_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_11_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_7_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_7_consts_12_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_11_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_11_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_11_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_11_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_67_consts_11_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_67_consts_11_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_67_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_67_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_67_consts_11_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_67_consts_11_names_0 = {
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
    ._data = "sum",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_67_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_67_consts_11_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_67_consts_11_name = {
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
    ._data = "count",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_67_consts_11_qualname = {
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
    ._data = "Sequence.count",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_67_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x14\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_67_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x13\x13\x40\x13\x40\x13\x40\x13\x40\x1f\x23\x13\x40\x13\x40\x10\x40\x09\x40",
};
static struct PyCodeObject toplevel_consts_67_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_67_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1074,
    .co_code = & toplevel_consts_67_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_51_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_67_consts_11_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_67_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_67_consts_11_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_67_consts_12 = {
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
            Py_None,
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
toplevel_consts_67_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_6_22._ascii.ob_base,
            & toplevel_consts_67_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_67_consts_3.ob_base.ob_base,
            & toplevel_consts_67_consts_4.ob_base,
            & toplevel_consts_67_consts_5.ob_base,
            & toplevel_consts_67_consts_6.ob_base,
            & toplevel_consts_67_consts_7.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_67_consts_10.ob_base,
            & toplevel_consts_67_consts_11.ob_base,
            & toplevel_consts_67_consts_12._object.ob_base.ob_base,
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
toplevel_consts_67_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_55_names_5._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_44_consts_7_name._ascii.ob_base,
            & toplevel_consts_30_consts_2_name._ascii.ob_base,
            & toplevel_consts_40_consts_2_name._ascii.ob_base,
            & toplevel_consts_34_consts_2_name._ascii.ob_base,
            & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_67_consts_11_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_67_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x06\x04\x03\x02\x02\x04\x01\x02\xff\x02\x01\x06\x03\x06\x0a\x06\x06\x08\x04\x0a\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_67_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x05\x04\x02\x04\x03\x02\x02\x04\x02\x02\xfe\x02\x02\x06\x0a\x06\x06\x06\x04\x02\x02\x06\x15\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_67_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x17\x1d\x05\x14\x06\x14\x05\x19\x05\x19\x06\x14\x05\x19\x05\x13\x05\x13\x05\x13\x05\x15\x05\x15\x05\x15\x05\x1a\x05\x1a\x05\x1a\x22\x23\x05\x19\x05\x19\x05\x19\x05\x40\x05\x40\x05\x40\x05\x40\x05\x40",
};
static struct PyCodeObject toplevel_consts_67 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_67_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_67_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1015,
    .co_code = & toplevel_consts_67_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_22._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_22._ascii.ob_base,
    .co_linetable = & toplevel_consts_67_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_67_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_69_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[78];
    }
toplevel_consts_69_consts_1 = {
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
    ._data = "\x54\x68\x69\x73\x20\x75\x6e\x69\x66\x69\x65\x73\x20\x62\x79\x74\x65\x73\x20\x61\x6e\x64\x20\x62\x79\x74\x65\x61\x72\x72\x61\x79\x2e\x0a\x0a\x20\x20\x20\x20\x58\x58\x58\x20\x53\x68\x6f\x75\x6c\x64\x20\x61\x64\x64\x20\x61\x6c\x6c\x20\x74\x68\x65\x69\x72\x20\x6d\x65\x74\x68\x6f\x64\x73\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_69_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_24._ascii.ob_base,
            & toplevel_consts_69_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            Py_None,
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
toplevel_consts_69_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_69_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_69_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x04\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_69_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x05\x0e\x05\x0e",
};
static struct PyCodeObject toplevel_consts_69 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_69_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_69_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_69_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1084,
    .co_code = & toplevel_consts_69_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_24._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_24._ascii.ob_base,
    .co_linetable = & toplevel_consts_69_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_69_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_69_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[97];
    }
toplevel_consts_71_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 96,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x05\x64\x04\x84\x00\xa9\x01\x5a\x07\x65\x05\x64\x05\x84\x00\xa9\x01\x5a\x08\x64\x06\x84\x00\x5a\x09\x64\x07\x84\x00\x5a\x0a\x64\x08\x84\x00\x5a\x0b\x64\x09\x84\x00\x5a\x0c\x64\x0f\x64\x0b\x84\x01\x5a\x0d\x64\x0c\x84\x00\x5a\x0e\x64\x0d\x84\x00\x5a\x0f\x64\x0e\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[175];
    }
toplevel_consts_71_consts_1 = {
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
    ._data = "\x41\x6c\x6c\x20\x74\x68\x65\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x6f\x6e\x20\x61\x20\x72\x65\x61\x64\x2d\x77\x72\x69\x74\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x43\x6f\x6e\x63\x72\x65\x74\x65\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x20\x6d\x75\x73\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x20\x5f\x5f\x6e\x65\x77\x5f\x5f\x20\x6f\x72\x20\x5f\x5f\x69\x6e\x69\x74\x5f\x5f\x2c\x0a\x20\x20\x20\x20\x5f\x5f\x67\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x73\x65\x74\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x64\x65\x6c\x69\x74\x65\x6d\x5f\x5f\x2c\x20\x5f\x5f\x6c\x65\x6e\x5f\x5f\x2c\x20\x61\x6e\x64\x20\x69\x6e\x73\x65\x72\x74\x28\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_71_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_22_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_71_consts_3_qualname = {
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
    ._data = "MutableSequence.__setitem__",
};
static struct PyCodeObject toplevel_consts_71_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1105,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_71_consts_4_qualname = {
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
    ._data = "MutableSequence.__delitem__",
};
static struct PyCodeObject toplevel_consts_71_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1109,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_67_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_65_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_67_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[52];
    }
toplevel_consts_71_consts_5_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 51,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "S.insert(index, value) -- insert value before index",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_71_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_71_consts_5_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_71_consts_5_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_71_consts_5_qualname = {
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
    ._data = "MutableSequence.insert",
};
static struct PyCodeObject toplevel_consts_71_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_67_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1113,
    .co_code = & toplevel_consts_22_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_71_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_67_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_71_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x74\x01\x7c\x00\xa9\x01\x7c\x01\xa8\x02\xa9\x02\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[59];
    }
toplevel_consts_71_consts_6_consts_0 = {
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
    ._data = "S.append(value) -- append value to the end of the sequence",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_71_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_71_consts_6_consts_0._ascii.ob_base,
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
toplevel_consts_71_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_71_consts_5_name._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_71_consts_6_qualname = {
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
    ._data = "MutableSequence.append",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_71_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x16\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_71_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x26\x15\x18\x19\x1d\x15\x1e\x20\x25\x09\x26\x09\x26\x09\x26\x09\x26\x09\x26",
};
static struct PyCodeObject toplevel_consts_71_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1118,
    .co_code = & toplevel_consts_71_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_4_names_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_71_consts_7_consts_0 = {
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
    ._data = "S.clear() -> None -- remove all items from S",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_71_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_71_consts_7_consts_0._ascii.ob_base,
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
toplevel_consts_71_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_53_consts_6_name._ascii.ob_base,
            & toplevel_consts_67_consts_4_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_71_consts_7_qualname = {
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
    ._data = "MutableSequence.clear",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_71_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x11\x13\x17\x11\x15\x11\x1b\x11\x1b\x11\x1b\x11\x1b\x13\x17\x00\x00\x10\x1a\x09\x11\x09\x11\x0d\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00",
};
static struct PyCodeObject toplevel_consts_71_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_53_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_53_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1122,
    .co_code = & toplevel_consts_53_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_53_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_53_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[75];
    }
toplevel_consts_71_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 74,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x01\x74\x01\x7c\x01\x64\x01\x7a\x02\xa9\x01\x44\x00\x5d\x17\x7d\x02\x7c\x00\x7c\x01\x7c\x02\x7a\x0a\x64\x02\x7a\x0a\x19\x00\x7c\x00\x7c\x02\x19\x00\x02\x02\x7c\x00\x7c\x02\x3c\x00\x7c\x00\x7c\x01\x7c\x02\x7a\x0a\x64\x02\x7a\x0a\x3c\x00\x71\x0b\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_71_consts_8_consts_0 = {
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
    ._data = "S.reverse() -- reverse *IN PLACE*",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_71_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_71_consts_8_consts_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_consts_1.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
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
toplevel_consts_71_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_67_consts_7_names_1._ascii.ob_base,
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
toplevel_consts_71_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_51_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_67_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_71_consts_8_name = {
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
    ._data = "reverse",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_71_consts_8_qualname = {
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
    ._data = "MutableSequence.reverse",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_71_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x10\x01\x2c\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_71_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0a\x01\x04\x01\x02\xff\x30\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[75];
    }
toplevel_consts_71_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 74,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x10\x11\x15\x0d\x16\x09\x0a\x12\x17\x18\x19\x1b\x1c\x18\x1c\x12\x1d\x09\x38\x09\x38\x0d\x0e\x24\x28\x29\x2a\x2b\x2c\x29\x2c\x2d\x2e\x29\x2e\x24\x2f\x31\x35\x36\x37\x31\x38\x24\x38\x0d\x11\x12\x13\x0d\x14\x16\x1a\x1b\x1c\x1d\x1e\x1b\x1e\x1f\x20\x1b\x20\x16\x21\x16\x21\x09\x38\x09\x38",
};
static struct PyCodeObject toplevel_consts_71_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1130,
    .co_code = & toplevel_consts_71_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_71_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_71_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x75\x00\x72\x09\x74\x00\x7c\x01\xa9\x01\x7d\x01\x7c\x01\x44\x00\x5d\x08\x7d\x02\x7c\x00\xa0\x01\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x0b\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[78];
    }
toplevel_consts_71_consts_9_consts_0 = {
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
    ._data = "S.extend(iterable) -- extend sequence by appending elements from the iterable",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_71_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_71_consts_9_consts_0._ascii.ob_base,
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
toplevel_consts_71_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_7._ascii.ob_base,
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
toplevel_consts_71_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_10_name._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_71_consts_9_qualname = {
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
    ._data = "MutableSequence.extend",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_71_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x08\x01\x08\x01\x0e\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_71_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0a\x01\x02\x01\x04\x01\x02\xff\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_71_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x12\x16\x1a\x0c\x1a\x09\x22\x16\x1a\x1b\x21\x16\x22\x0d\x13\x12\x18\x09\x1b\x09\x1b\x0d\x0e\x0d\x11\x0d\x1b\x19\x1a\x0d\x1b\x0d\x1b\x0d\x1b\x0d\x1b\x09\x1b\x09\x1b",
};
static struct PyCodeObject toplevel_consts_71_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1136,
    .co_code = & toplevel_consts_71_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_consts_4_names_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_71_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x7c\x01\x19\x00\x7d\x02\x7c\x00\x7c\x01\x3d\x00\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[154];
    }
toplevel_consts_71_consts_11_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 153,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x2e\x70\x6f\x70\x28\x5b\x69\x6e\x64\x65\x78\x5d\x29\x20\x2d\x3e\x20\x69\x74\x65\x6d\x20\x2d\x2d\x20\x72\x65\x6d\x6f\x76\x65\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x69\x74\x65\x6d\x20\x61\x74\x20\x69\x6e\x64\x65\x78\x20\x28\x64\x65\x66\x61\x75\x6c\x74\x20\x6c\x61\x73\x74\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x20\x49\x6e\x64\x65\x78\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x6c\x69\x73\x74\x20\x69\x73\x20\x65\x6d\x70\x74\x79\x20\x6f\x72\x20\x69\x6e\x64\x65\x78\x20\x69\x73\x20\x6f\x75\x74\x20\x6f\x66\x20\x72\x61\x6e\x67\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_71_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_71_consts_11_consts_0._ascii.ob_base,
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
toplevel_consts_71_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
            & toplevel_consts_61_consts_3_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_71_consts_11_qualname = {
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
    ._data = "MutableSequence.pop",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_71_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x04\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_71_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x11\x12\x17\x0d\x18\x09\x0a\x0d\x11\x12\x17\x0d\x18\x10\x11\x09\x11",
};
static struct PyCodeObject toplevel_consts_71_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1143,
    .co_code = & toplevel_consts_71_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_44_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_71_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x3d\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[119];
    }
toplevel_consts_71_consts_12_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 118,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x2e\x72\x65\x6d\x6f\x76\x65\x28\x76\x61\x6c\x75\x65\x29\x20\x2d\x2d\x20\x72\x65\x6d\x6f\x76\x65\x20\x66\x69\x72\x73\x74\x20\x6f\x63\x63\x75\x72\x72\x65\x6e\x63\x65\x20\x6f\x66\x20\x76\x61\x6c\x75\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x61\x69\x73\x65\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x69\x66\x20\x74\x68\x65\x20\x76\x61\x6c\x75\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_71_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_71_consts_12_consts_0._ascii.ob_base,
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
toplevel_consts_71_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_67_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_71_consts_12_qualname = {
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
    ._data = "MutableSequence.remove",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_71_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x12\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_71_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x11\x12\x16\x12\x23\x1d\x22\x12\x23\x12\x23\x0d\x24\x0d\x24\x0d\x24",
};
static struct PyCodeObject toplevel_consts_71_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1151,
    .co_code = & toplevel_consts_71_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_53_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_12_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_71_consts_13_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_71_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_consts_4_names_5._ascii.ob_base,
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
toplevel_consts_71_consts_13_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_17_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_55_consts_10_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_71_consts_13_name = {
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
    ._data = "__iadd__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_71_consts_13_qualname = {
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
    ._data = "MutableSequence.__iadd__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_71_consts_13_linetable = {
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
toplevel_consts_71_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x1c\x15\x1b\x09\x1c\x09\x1c\x09\x1c\x10\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_71_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1157,
    .co_code = & toplevel_consts_71_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_71_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_71_consts_13_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_71_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_71_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_71_consts_15 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_71_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_6_23._ascii.ob_base,
            & toplevel_consts_71_consts_1._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_71_consts_3.ob_base,
            & toplevel_consts_71_consts_4.ob_base,
            & toplevel_consts_71_consts_5.ob_base,
            & toplevel_consts_71_consts_6.ob_base,
            & toplevel_consts_71_consts_7.ob_base,
            & toplevel_consts_71_consts_8.ob_base,
            & toplevel_consts_71_consts_9.ob_base,
            & toplevel_consts_44_consts_5_consts_6.ob_base.ob_base,
            & toplevel_consts_71_consts_11.ob_base,
            & toplevel_consts_71_consts_12.ob_base,
            & toplevel_consts_71_consts_13.ob_base,
            Py_None,
            & toplevel_consts_71_consts_15._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_71_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_consts_17_names_3._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_65_consts_3_name._ascii.ob_base,
            & toplevel_consts_65_consts_4_name._ascii.ob_base,
            & toplevel_consts_71_consts_5_name._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_7._ascii.ob_base,
            & toplevel_consts_53_consts_7_name._ascii.ob_base,
            & toplevel_consts_71_consts_8_name._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_5._ascii.ob_base,
            & toplevel_consts_53_consts_6_name._ascii.ob_base,
            & toplevel_consts_53_consts_5_name._ascii.ob_base,
            & toplevel_consts_71_consts_13_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_71_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x06\x02\x02\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x02\x01\x06\x04\x06\x04\x06\x08\x06\x06\x08\x07\x06\x08\x0a\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_71_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x05\x04\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x06\x04\x06\x08\x06\x06\x06\x07\x02\x02\x06\x06\x06\x06\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[97];
    }
toplevel_consts_71_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 96,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x11\x13\x05\x0e\x06\x14\x05\x19\x05\x19\x06\x14\x05\x19\x06\x14\x05\x19\x05\x19\x06\x14\x05\x19\x06\x14\x05\x19\x05\x19\x06\x14\x05\x19\x05\x26\x05\x26\x05\x26\x05\x11\x05\x11\x05\x11\x05\x38\x05\x38\x05\x38\x05\x1b\x05\x1b\x05\x1b\x19\x1b\x05\x11\x05\x11\x05\x11\x05\x24\x05\x24\x05\x24\x05\x14\x05\x14\x05\x14\x05\x14\x05\x14",
};
static struct PyCodeObject toplevel_consts_71 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_71_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_71_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_71_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1096,
    .co_code = & toplevel_consts_71_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_23._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_23._ascii.ob_base,
    .co_linetable = & toplevel_consts_71_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_71_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_71_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[73];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 73,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_2._object.ob_base.ob_base,
            Py_None,
            Py_Ellipsis,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_6._object.ob_base.ob_base,
            & toplevel_consts_7._ascii.ob_base,
            & toplevel_consts_5_exceptiontable.ob_base.ob_base,
            & toplevel_consts_9.ob_base.ob_base,
            & toplevel_consts_10.ob_base.ob_base,
            & toplevel_consts_11._ascii.ob_base,
            & toplevel_consts_5_names._object.ob_base.ob_base,
            & toplevel_consts_13.ob_base,
            & toplevel_consts_14.ob_base,
            & toplevel_consts_15.ob_base,
            & toplevel_consts_16.ob_base,
            & toplevel_consts_17.ob_base,
            & toplevel_consts_6_5._ascii.ob_base,
            & toplevel_consts_19._object.ob_base.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_6_1._ascii.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_6_2._ascii.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_6_3._ascii.ob_base,
            & toplevel_consts_28.ob_base,
            & toplevel_consts_6_4._ascii.ob_base,
            & toplevel_consts_30.ob_base,
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_32.ob_base,
            & toplevel_consts_6_7._ascii.ob_base,
            & toplevel_consts_34.ob_base,
            & toplevel_consts_6_9._ascii.ob_base,
            & toplevel_consts_36.ob_base,
            & toplevel_consts_6_8._ascii.ob_base,
            & toplevel_consts_38.ob_base,
            & toplevel_consts_6_10._ascii.ob_base,
            & toplevel_consts_40.ob_base,
            & toplevel_consts_6_11._ascii.ob_base,
            & toplevel_consts_42.ob_base,
            & toplevel_consts_6_13._ascii.ob_base,
            & toplevel_consts_44.ob_base,
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_46.ob_base,
            & toplevel_consts_47.ob_base,
            & toplevel_consts_48.ob_base,
            & toplevel_consts_49.ob_base,
            & toplevel_consts_6_12._ascii.ob_base,
            & toplevel_consts_51.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_consts_53.ob_base,
            & toplevel_consts_6_15._ascii.ob_base,
            & toplevel_consts_55.ob_base,
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_57.ob_base,
            & toplevel_consts_6_18._ascii.ob_base,
            & toplevel_consts_59.ob_base,
            & toplevel_consts_6_19._ascii.ob_base,
            & toplevel_consts_61.ob_base,
            & toplevel_consts_6_20._ascii.ob_base,
            & toplevel_consts_63.ob_base,
            & toplevel_consts_6_21._ascii.ob_base,
            & toplevel_consts_65.ob_base,
            & toplevel_consts_6_17._ascii.ob_base,
            & toplevel_consts_67.ob_base,
            & toplevel_consts_6_22._ascii.ob_base,
            & toplevel_consts_69.ob_base,
            & toplevel_consts_6_24._ascii.ob_base,
            & toplevel_consts_71.ob_base,
            & toplevel_consts_6_23._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_names_1 = {
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
        uint8_t _data[4];
    }
toplevel_names_7 = {
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
        uint8_t _data[13];
    }
toplevel_names_9 = {
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
    ._data = "EllipsisType",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_names_12 = {
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
toplevel_names_15 = {
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
    ._data = "bytes_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_16 = {
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
    ._data = "bytearray",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_names_17 = {
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
    ._data = "bytearray_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_names_19 = {
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
    ._data = "dict_keyiterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_names_21 = {
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
    ._data = "dict_valueiterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_names_23 = {
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
    ._data = "dict_itemiterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_names_24 = {
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
    ._data = "list_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_names_26 = {
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
    ._data = "list_reverseiterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_names_28 = {
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
    ._data = "range_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_names_29 = {
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
    ._data = "longrange_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_31 = {
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
    ._data = "set_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_32 = {
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
    ._data = "str_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_names_33 = {
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
    ._data = "tuple_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_35 = {
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
    ._data = "zip_iterator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_36 = {
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
    ._data = "dict_keys",
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
    ._data = "dict_values",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_names_38 = {
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
    ._data = "dict_items",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_40 = {
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
    ._data = "mappingproxy",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_41 = {
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
    ._data = "generator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_names_43 = {
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
    ._data = "coroutine",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_names_46 = {
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
    ._data = "async_generator",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_names_51 = {
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
        uint8_t _data[10];
    }
toplevel_names_68 = {
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
    ._data = "frozenset",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_names_79 = {
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
        uint8_t _data[11];
    }
toplevel_names_80 = {
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
    ._data = "memoryview",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_names_82 = {
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
            PyObject *ob_item[84];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 84,
        },
        .ob_item = {
            & toplevel_consts_44_names_3._ascii.ob_base,
            & toplevel_names_1._ascii.ob_base,
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_consts_2_1._ascii.ob_base,
            & toplevel_consts_51_consts_15_names_0._ascii.ob_base,
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_4._ascii.ob_base,
            & toplevel_names_7._ascii.ob_base,
            & toplevel_consts_20_names_8._ascii.ob_base,
            & toplevel_names_9._ascii.ob_base,
            & toplevel_consts_5_name._ascii.ob_base,
            & toplevel_consts_48_names_7._ascii.ob_base,
            & toplevel_names_12._ascii.ob_base,
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_53_consts_6_names_0._ascii.ob_base,
            & toplevel_names_15._ascii.ob_base,
            & toplevel_names_16._ascii.ob_base,
            & toplevel_names_17._ascii.ob_base,
            & toplevel_consts_55_consts_8_name._ascii.ob_base,
            & toplevel_names_19._ascii.ob_base,
            & toplevel_consts_55_consts_10_name._ascii.ob_base,
            & toplevel_names_21._ascii.ob_base,
            & toplevel_consts_55_consts_9_name._ascii.ob_base,
            & toplevel_names_23._ascii.ob_base,
            & toplevel_names_24._ascii.ob_base,
            & toplevel_consts_67_consts_7_names_0._ascii.ob_base,
            & toplevel_names_26._ascii.ob_base,
            & toplevel_consts_67_consts_7_names_1._ascii.ob_base,
            & toplevel_names_28._ascii.ob_base,
            & toplevel_names_29._ascii.ob_base,
            & toplevel_consts_59_consts_2_names_0._ascii.ob_base,
            & toplevel_names_31._ascii.ob_base,
            & toplevel_names_32._ascii.ob_base,
            & toplevel_names_33._ascii.ob_base,
            & toplevel_consts_44_consts_7_names_8._ascii.ob_base,
            & toplevel_names_35._ascii.ob_base,
            & toplevel_names_36._ascii.ob_base,
            & toplevel_names_37._ascii.ob_base,
            & toplevel_names_38._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_names_40._ascii.ob_base,
            & toplevel_names_41._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_names_43._ascii.ob_base,
            & toplevel_consts_22_consts_5_name._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_names_46._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
            & toplevel_consts_6_5._ascii.ob_base,
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_6_1._ascii.ob_base,
            & toplevel_names_51._ascii.ob_base,
            & toplevel_consts_6_2._ascii.ob_base,
            & toplevel_consts_6_3._ascii.ob_base,
            & toplevel_consts_6_4._ascii.ob_base,
            & toplevel_consts_6_6._ascii.ob_base,
            & toplevel_consts_6_7._ascii.ob_base,
            & toplevel_consts_6_9._ascii.ob_base,
            & toplevel_consts_6_8._ascii.ob_base,
            & toplevel_consts_6_10._ascii.ob_base,
            & toplevel_consts_6_11._ascii.ob_base,
            & toplevel_consts_6_13._ascii.ob_base,
            & toplevel_consts_44_consts_0._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_44_consts_5_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_6_12._ascii.ob_base,
            & toplevel_consts_6_14._ascii.ob_base,
            & toplevel_names_68._ascii.ob_base,
            & toplevel_consts_6_15._ascii.ob_base,
            & toplevel_consts_6_16._ascii.ob_base,
            & toplevel_consts_6_18._ascii.ob_base,
            & toplevel_consts_6_19._ascii.ob_base,
            & toplevel_consts_6_20._ascii.ob_base,
            & toplevel_consts_6_21._ascii.ob_base,
            & toplevel_consts_6_17._ascii.ob_base,
            & toplevel_consts_44_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_6_22._ascii.ob_base,
            & toplevel_consts_44_consts_3_names_1._ascii.ob_base,
            & toplevel_names_79._ascii.ob_base,
            & toplevel_names_80._ascii.ob_base,
            & toplevel_consts_6_24._ascii.ob_base,
            & toplevel_names_82._ascii.ob_base,
            & toplevel_consts_6_23._ascii.ob_base,
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
        char ob_sval[201];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 200,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x03\x10\x05\x08\x01\x0c\x02\x08\x01\x06\x01\x08\x01\x02\x01\x08\x02\x04\x0f\x0c\x09\x0e\x01\x12\x02\x12\x01\x12\x01\x0c\x01\x10\x01\x10\x01\x14\x01\x0e\x01\x0c\x01\x0c\x01\x0e\x01\x0e\x02\x0e\x01\x0e\x01\x0a\x02\x0c\x01\x06\x02\x06\x01\x08\x01\x0a\x01\x02\x01\x06\x02\x06\x01\x08\x01\x02\x01\x06\x05\x10\x0c\x10\x0f\x0e\x11\x0c\x29\x10\x03\x0e\x11\x0e\x13\x0c\x30\x10\x03\x0e\x12\x0c\x13\x0c\x01\x0c\x02\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0e\x03\x0e\x10\x0c\x30\x10\x03\x10\x0f\x12\x11\x0e\x0b\x06\x61\x06\x06\x06\x0c\x10\x13\x0e\x14\x00\x7f\x0c\x0b\x0e\x03\x0c\x50\x0e\x05\x0c\x33\x0e\x03\x10\x10\x0c\x0f\x10\x03\x0c\x16\x10\x03\x0c\x10\x0e\x03\x0c\x52\x10\x05\x0c\x3f\x0c\x01\x0c\x01\x0c\x01\x0e\x03\x0c\x08\x0c\x01\x0e\x03\x0c\x42\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[311];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 310,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x06\x10\x02\x08\x01\x0c\x02\x08\x01\x06\x01\x08\x01\x02\x01\x06\x0b\x02\xf7\x04\x0f\x0c\x09\x0e\x01\x12\x02\x12\x01\x12\x01\x0c\x01\x10\x01\x10\x01\x14\x01\x0e\x01\x0c\x01\x0c\x01\x0e\x01\x0e\x02\x0e\x01\x0e\x01\x0a\x02\x0c\x01\x06\x02\x06\x01\x08\x01\x0a\x01\x02\x01\x06\x02\x06\x01\x08\x01\x02\x01\x06\x0f\x08\x0e\x02\xf4\x06\x0c\x08\x11\x02\xf2\x06\x0e\x08\x29\x02\xda\x04\x26\x0c\x03\x08\x11\x02\xf2\x06\x0e\x08\x13\x02\xf0\x04\x10\x08\x30\x02\xd3\x04\x2d\x0c\x03\x08\x12\x02\xf1\x06\x0f\x08\x13\x02\xf0\x04\x10\x0c\x03\x0c\x01\x0c\x02\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x08\x10\x02\xf3\x04\x0d\x08\x30\x02\xd3\x04\x2d\x0c\x03\x08\x0f\x02\xf4\x06\x0c\x08\x11\x02\xf2\x06\x0e\x08\x0b\x06\xf8\x04\x08\x08\x61\x02\xa2\x04\x5e\x06\x07\x06\x0c\x06\x12\x08\x11\x02\xf2\x06\x0e\x00\x7f\x08\x0e\x00\x81\x02\xf8\x00\x7f\x04\x08\x0c\x03\x08\x50\x02\xb3\x04\x4d\x0c\x03\x08\x36\x02\xcf\x04\x31\x0c\x02\x08\x10\x02\xf3\x04\x0d\x08\x0f\x04\xf4\x04\x0c\x0c\x03\x08\x16\x04\xed\x04\x13\x0c\x03\x08\x10\x04\xf3\x04\x0d\x0c\x03\x08\x52\x02\xb1\x04\x4f\x0c\x03\x08\x42\x04\xc3\x04\x3d\x0c\x02\x0c\x01\x0c\x01\x0c\x01\x08\x09\x02\xfa\x04\x06\x0c\x02\x0c\x01\x08\x42\x02\xc1\x04\x3f\x0c\x03\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1183];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 1182,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x28\x01\x28\x01\x28\x01\x28\x01\x28\x01\x28\x01\x28\x01\x28\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x10\x14\x15\x19\x1a\x1d\x15\x1e\x10\x1f\x01\x0d\x10\x14\x15\x18\x10\x19\x01\x0d\x01\x0f\x01\x0f\x01\x0f\x10\x14\x15\x17\x10\x18\x01\x0d\x05\x07\x0b\x0d\x0b\x0d\x0b\x0d\x01\x08\x0c\x1d\x01\x09\x12\x16\x17\x1b\x1c\x1f\x17\x20\x12\x21\x01\x0f\x16\x1a\x1b\x1f\x20\x29\x20\x2b\x1b\x2c\x16\x2d\x01\x13\x14\x18\x19\x1d\x1e\x20\x1e\x27\x1e\x27\x1e\x27\x19\x28\x14\x29\x01\x11\x16\x1a\x1b\x1f\x20\x22\x20\x2b\x20\x2b\x20\x2b\x1b\x2c\x16\x2d\x01\x13\x15\x19\x1a\x1e\x1f\x21\x1f\x29\x1f\x29\x1f\x29\x1a\x2a\x15\x2b\x01\x12\x11\x15\x16\x1a\x1b\x1d\x16\x1e\x11\x1f\x01\x0e\x18\x1c\x1d\x21\x22\x2a\x2b\x2d\x22\x2e\x1d\x2f\x18\x30\x01\x15\x12\x16\x17\x1b\x1c\x21\x22\x23\x1c\x24\x17\x25\x12\x26\x01\x0f\x16\x1a\x1b\x1f\x20\x25\x26\x27\x2b\x2f\x26\x2f\x20\x30\x1b\x31\x16\x32\x01\x13\x10\x14\x15\x19\x1a\x1d\x1a\x1f\x15\x20\x10\x21\x01\x0d\x10\x14\x15\x19\x1a\x1c\x15\x1d\x10\x1e\x01\x0d\x12\x16\x17\x1b\x1c\x1e\x17\x1f\x12\x20\x01\x0f\x10\x14\x15\x19\x1a\x1d\x1a\x1f\x15\x20\x10\x21\x01\x0d\x0d\x11\x12\x14\x12\x1b\x12\x1b\x12\x1b\x0d\x1c\x01\x0a\x0f\x13\x14\x16\x14\x1f\x14\x1f\x14\x1f\x0f\x20\x01\x0c\x0e\x12\x13\x15\x13\x1d\x13\x1d\x13\x1d\x0e\x1e\x01\x0b\x10\x14\x15\x19\x15\x22\x10\x23\x01\x0d\x0d\x11\x13\x22\x13\x22\x12\x25\x0d\x26\x01\x0a\x01\x18\x01\x18\x01\x18\x09\x0e\x09\x10\x01\x06\x0d\x11\x12\x17\x0d\x18\x01\x0a\x01\x06\x01\x0e\x01\x0e\x01\x0e\x01\x0e\x05\x0a\x01\x17\x01\x17\x01\x17\x07\x0a\x07\x0c\x01\x04\x13\x17\x18\x1b\x13\x1c\x01\x10\x05\x08\x01\x10\x01\x10\x01\x10\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x1a\x21\x01\x1e\x01\x1e\x01\x1e\x01\x32\x01\x32\x01\x32\x01\x32\x1b\x22\x01\x32\x01\x32\x01\x32\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x11\x1a\x01\x1e\x01\x1e\x01\x0a\x01\x1e\x14\x1d\x01\x1e\x01\x1e\x01\x1e\x01\x32\x01\x32\x01\x32\x01\x32\x1f\x26\x01\x32\x01\x32\x01\x32\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x15\x22\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x16\x23\x01\x1e\x01\x1e\x01\x0f\x01\x29\x19\x28\x01\x29\x01\x29\x01\x29\x01\x32\x01\x32\x01\x32\x01\x32\x1a\x21\x01\x32\x01\x32\x01\x32\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x10\x18\x01\x1e\x01\x1e\x01\x09\x01\x22\x13\x21\x01\x22\x01\x22\x01\x22\x01\x09\x01\x26\x13\x25\x01\x26\x01\x26\x01\x26\x01\x09\x01\x24\x13\x23\x01\x24\x01\x24\x01\x24\x01\x09\x01\x26\x13\x25\x01\x26\x01\x26\x01\x26\x01\x09\x01\x25\x13\x24\x01\x25\x01\x25\x01\x25\x01\x09\x01\x21\x13\x20\x01\x21\x01\x21\x01\x21\x01\x09\x01\x28\x13\x27\x01\x28\x01\x28\x01\x28\x01\x09\x01\x22\x13\x21\x01\x22\x01\x22\x01\x22\x01\x09\x01\x26\x13\x25\x01\x26\x01\x26\x01\x26\x01\x09\x01\x20\x13\x1f\x01\x20\x01\x20\x01\x20\x01\x09\x01\x20\x13\x1f\x01\x20\x01\x20\x01\x20\x01\x09\x01\x22\x13\x21\x01\x22\x01\x22\x01\x22\x01\x09\x01\x20\x13\x1f\x01\x20\x01\x20\x01\x20\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x12\x1a\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x11\x19\x01\x1e\x01\x1e\x01\x0a\x01\x1e\x14\x1d\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x17\x1e\x01\x1e\x01\x1e\x01\x1e\x01\x32\x01\x32\x01\x32\x01\x32\x1b\x22\x01\x32\x01\x32\x01\x32\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x12\x17\x19\x21\x23\x2c\x01\x1e\x01\x1e\x01\x40\x01\x40\x01\x40\x01\x40\x1d\x29\x01\x40\x01\x40\x01\x3a\x01\x3a\x01\x3a\x01\x56\x01\x56\x01\x56\x01\x15\x01\x15\x01\x15\x01\x3b\x01\x3b\x01\x3b\x01\x3b\x1a\x21\x01\x3b\x01\x3b\x01\x3b\x01\x11\x01\x11\x01\x11\x01\x11\x0b\x15\x01\x11\x01\x11\x01\x04\x01\x18\x0e\x17\x01\x18\x01\x18\x01\x18\x01\x14\x01\x14\x01\x14\x01\x14\x12\x15\x01\x14\x01\x14\x01\x0b\x01\x19\x15\x18\x01\x19\x01\x19\x01\x19\x01\x18\x01\x18\x01\x18\x01\x18\x0f\x19\x01\x18\x01\x18\x01\x08\x01\x1f\x12\x1e\x01\x1f\x01\x1f\x01\x1f\x01\x32\x01\x32\x01\x32\x01\x32\x13\x18\x01\x32\x01\x32\x01\x21\x01\x21\x01\x21\x01\x21\x10\x1b\x1d\x20\x01\x21\x01\x21\x01\x09\x01\x1d\x13\x1c\x01\x1d\x01\x1d\x01\x1d\x01\x2c\x01\x2c\x01\x2c\x01\x2c\x11\x1c\x1e\x21\x01\x2c\x01\x2c\x01\x0a\x01\x1f\x14\x1e\x01\x1f\x01\x1f\x01\x1f\x01\x25\x01\x25\x01\x25\x01\x25\x12\x1d\x1f\x29\x01\x25\x01\x25\x01\x0b\x01\x21\x15\x20\x01\x21\x01\x21\x01\x21\x01\x17\x01\x17\x01\x17\x01\x17\x16\x1d\x01\x17\x01\x17\x01\x0f\x01\x1e\x19\x1d\x01\x1e\x01\x1e\x01\x1e\x01\x40\x01\x40\x01\x40\x01\x40\x10\x1a\x1c\x26\x01\x40\x01\x40\x01\x09\x01\x19\x13\x18\x01\x19\x01\x19\x01\x19\x01\x09\x01\x17\x13\x16\x01\x17\x01\x17\x01\x17\x01\x09\x01\x19\x13\x18\x01\x19\x01\x19\x01\x19\x01\x09\x01\x1e\x13\x1d\x01\x1e\x01\x1e\x01\x1e\x01\x13\x01\x13\x01\x13\x01\x13\x12\x1a\x01\x13\x01\x13\x01\x0b\x01\x1b\x15\x1a\x01\x1b\x01\x1b\x01\x1b\x01\x0b\x01\x1f\x15\x1e\x01\x1f\x01\x1f\x01\x1f\x01\x14\x01\x14\x01\x14\x01\x14\x17\x1f\x01\x14\x01\x14\x01\x10\x01\x1f\x1a\x1e\x01\x1f\x01\x1f\x01\x1f\x01\x10\x01\x24\x1a\x23\x01\x24\x01\x24\x01\x24\x01\x24\x01\x24",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_names._object.ob_base.ob_base,
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
    .co_varnames = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_names._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get__collections_abc_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

