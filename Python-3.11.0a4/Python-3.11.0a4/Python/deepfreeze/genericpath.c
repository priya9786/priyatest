#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x64\x01\x64\x02\x6c\x02\x5a\x02\x67\x00\x64\x03\xa2\x01\x5a\x03\x64\x04\x84\x00\x5a\x04\x64\x05\x84\x00\x5a\x05\x64\x06\x84\x00\x5a\x06\x64\x07\x84\x00\x5a\x07\x64\x08\x84\x00\x5a\x08\x64\x09\x84\x00\x5a\x09\x64\x0a\x84\x00\x5a\x0a\x64\x0b\x84\x00\x5a\x0b\x64\x0c\x84\x00\x5a\x0c\x64\x0d\x84\x00\x5a\x0d\x64\x0e\x84\x00\x5a\x0e\x64\x0f\x84\x00\x5a\x0f\x64\x10\x84\x00\x5a\x10\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[153];
    }
toplevel_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 152,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x50\x61\x74\x68\x20\x6f\x70\x65\x72\x61\x74\x69\x6f\x6e\x73\x20\x63\x6f\x6d\x6d\x6f\x6e\x20\x74\x6f\x20\x6d\x6f\x72\x65\x20\x74\x68\x61\x6e\x20\x6f\x6e\x65\x20\x4f\x53\x0a\x44\x6f\x20\x6e\x6f\x74\x20\x75\x73\x65\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x2e\x20\x20\x54\x68\x65\x20\x4f\x53\x20\x73\x70\x65\x63\x69\x66\x69\x63\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x69\x6d\x70\x6f\x72\x74\x20\x74\x68\x65\x20\x61\x70\x70\x72\x6f\x70\x72\x69\x61\x74\x65\x0a\x66\x75\x6e\x63\x74\x69\x6f\x6e\x73\x20\x66\x72\x6f\x6d\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x74\x68\x65\x6d\x73\x65\x6c\x76\x65\x73\x2e\x0a",
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
        uint8_t _data[13];
    }
toplevel_consts_3_0 = {
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
        uint8_t _data[7];
    }
toplevel_consts_3_1 = {
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
toplevel_consts_3_2 = {
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
toplevel_consts_3_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_3_4 = {
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
        uint8_t _data[8];
    }
toplevel_consts_3_5 = {
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
        uint8_t _data[6];
    }
toplevel_consts_3_6 = {
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
toplevel_consts_3_7 = {
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
        uint8_t _data[9];
    }
toplevel_consts_3_8 = {
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
toplevel_consts_3_9 = {
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
toplevel_consts_3_10 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_3_0._ascii.ob_base,
            & toplevel_consts_3_1._ascii.ob_base,
            & toplevel_consts_3_2._ascii.ob_base,
            & toplevel_consts_3_3._ascii.ob_base,
            & toplevel_consts_3_4._ascii.ob_base,
            & toplevel_consts_3_5._ascii.ob_base,
            & toplevel_consts_3_6._ascii.ob_base,
            & toplevel_consts_3_7._ascii.ob_base,
            & toplevel_consts_3_8._ascii.ob_base,
            & toplevel_consts_3_9._ascii.ob_base,
            & toplevel_consts_3_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_4_code = {
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
        uint8_t _data[69];
    }
toplevel_consts_4_consts_0 = {
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
    ._data = "Test whether a path exists.  Returns False for broken symbolic links",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_consts_0._ascii.ob_base,
            Py_False,
            Py_True,
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
    ._data = "stat",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_4_names_2 = {
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
toplevel_consts_4_names_3 = {
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
toplevel_consts_4_names = {
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
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_4_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_4_varnames_0 = {
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
toplevel_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
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
toplevel_consts_4_freevars = {
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
        uint8_t _data[21];
    }
toplevel_consts_4_filename = {
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
    ._data = "<frozen genericpath>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_4_linetable = {
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
toplevel_consts_4_endlinetable = {
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
toplevel_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x09\x0b\x09\x10\x11\x15\x09\x16\x09\x16\x0c\x10\x0c\x10\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00",
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
    .ob_sval = "\x82\x05\x09\x00\x89\x06\x13\x03\x92\x01\x13\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 16,
    .co_code = & toplevel_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x01\x6e\x0d\x23\x00\x74\x02\x74\x03\x66\x02\x79\x11\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x74\x01\x6a\x04\x7c\x01\x6a\x05\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_5_consts_0 = {
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
    ._data = "Test whether a path is a regular file",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_names_4 = {
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
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_names_5 = {
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
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_5_names = {
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
            & toplevel_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_5_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_5_varnames_1 = {
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
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0c\x01\x02\x80\x0a\x01\x06\x01\x02\xff\x06\x80\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x05\x0c\xfe\x02\x80\x06\x01\x0c\x01\x06\x80\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x0e\x10\x0e\x15\x16\x1a\x0e\x1b\x09\x0b\x09\x0b\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00\x0c\x10\x0c\x18\x19\x1b\x19\x23\x0c\x24\x05\x24",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x05\x08\x00\x88\x06\x12\x03\x91\x01\x12\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_5_localspluskinds = {
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
    .co_stacksize = 4,
    .co_firstlineno = 27,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_7._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[61];
    }
toplevel_consts_6_consts_0 = {
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
    ._data = "Return true if the pathname refers to an existing directory.",
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
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_6_names_4 = {
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
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_5_names_5._ascii.ob_base,
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
    ._data = "s",
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
            & toplevel_consts_5_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x15\x0e\x10\x0e\x15\x16\x17\x0e\x18\x09\x0b\x09\x0b\x00\x00\x0d\x14\x16\x20\x0c\x21\x05\x15\x05\x15\x10\x15\x10\x15\x10\x15\x05\x15\x00\x00\x00\x00\x00\x00\x0c\x10\x0c\x18\x19\x1b\x19\x23\x0c\x24\x05\x24",
};
static struct PyCodeObject toplevel_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 39,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x6a\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[50];
    }
toplevel_consts_7_consts_0 = {
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
    ._data = "Return the size of a file, reported by os.stat().",
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
        uint8_t _data[8];
    }
toplevel_consts_7_names_2 = {
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
    ._data = "st_size",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_7_names = {
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
            & toplevel_consts_7_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_7_varnames_0 = {
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
toplevel_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_7_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_7_linetable = {
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
toplevel_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x13\x14\x1c\x0c\x1d\x0c\x25\x05\x25",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_7_exceptiontable = {
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
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 48,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_5._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_8_consts_0 = {
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
    ._data = "Return the last modification time of a file, reported by os.stat().",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_8_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_8_names_2 = {
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
    ._data = "st_mtime",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_8_names = {
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
            & toplevel_consts_8_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0e\x0c\x13\x14\x1c\x0c\x1d\x0c\x26\x05\x26",
};
static struct PyCodeObject toplevel_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 53,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[62];
    }
toplevel_consts_9_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 61,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Return the last access time of a file, reported by os.stat().",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_names_2 = {
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
    ._data = "st_atime",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_9_names = {
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
            & toplevel_consts_9_names_2._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 58,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[66];
    }
toplevel_consts_10_consts_0 = {
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
    ._data = "Return the metadata change time of a file, reported by os.stat().",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_10_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_10_names_2 = {
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
    ._data = "st_ctime",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_10_names = {
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
            & toplevel_consts_10_names_2._ascii.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 63,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[111];
    }
toplevel_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 110,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x73\x05\x64\x01\x53\x00\x74\x00\x7c\x00\x64\x02\x19\x00\x74\x01\x74\x02\x66\x02\xa9\x02\x73\x16\x74\x02\x74\x03\x74\x04\x6a\x05\x7c\x00\xa9\x02\xa9\x01\x7d\x00\x74\x06\x7c\x00\xa9\x01\x7d\x01\x74\x07\x7c\x00\xa9\x01\x7d\x02\x74\x08\x7c\x01\xa9\x01\x44\x00\x5d\x12\x5c\x02\x7d\x03\x7d\x04\x7c\x04\x7c\x02\x7c\x03\x19\x00\x6b\x03\x72\x34\x7c\x01\x64\x03\x7c\x03\x85\x02\x19\x00\x02\x00\x01\x00\x53\x00\x71\x22\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[72];
    }
toplevel_consts_11_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 71,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Given a list of pathnames, returns the longest common leading component",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1];
    }
toplevel_consts_11_consts_1 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
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
        uint8_t _data[5];
    }
toplevel_consts_11_names_1 = {
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
        uint8_t _data[6];
    }
toplevel_consts_11_names_2 = {
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
toplevel_consts_11_names_3 = {
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
        uint8_t _data[7];
    }
toplevel_consts_11_names_5 = {
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
        uint8_t _data[4];
    }
toplevel_consts_11_names_6 = {
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
toplevel_consts_11_names_7 = {
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
toplevel_consts_11_names_8 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_11_names_2._ascii.ob_base,
            & toplevel_consts_11_names_3._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_11_names_5._ascii.ob_base,
            & toplevel_consts_11_names_6._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
            & toplevel_consts_11_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_11_varnames_0 = {
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
        uint8_t _data[3];
    }
toplevel_consts_11_varnames_1 = {
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
toplevel_consts_11_varnames_2 = {
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
        uint8_t _data[2];
    }
toplevel_consts_11_varnames_3 = {
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
        uint8_t _data[2];
    }
toplevel_consts_11_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_11_varnames = {
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
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_2._ascii.ob_base,
            & toplevel_consts_11_varnames_3._ascii.ob_base,
            & toplevel_consts_11_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x12\x05\x10\x01\x08\x01\x08\x01\x10\x01\x0c\x01\x10\x01\x02\xff\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x10\x05\x12\x01\x08\x01\x08\x01\x06\x01\x04\x02\x06\xfe\x0a\x01\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[111];
    }
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 110,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x0d\x05\x18\x16\x18\x16\x18\x0c\x16\x17\x18\x19\x1a\x17\x1b\x1e\x22\x24\x29\x1d\x2a\x0c\x2b\x05\x25\x0d\x12\x13\x16\x17\x19\x17\x20\x22\x23\x13\x24\x0d\x25\x09\x0a\x0a\x0d\x0e\x0f\x0a\x10\x05\x07\x0a\x0d\x0e\x0f\x0a\x10\x05\x07\x11\x1a\x1b\x1d\x11\x1e\x05\x1a\x05\x1a\x09\x0d\x09\x0a\x0c\x0d\x0c\x0d\x11\x13\x14\x15\x11\x16\x0c\x16\x09\x1a\x14\x16\x17\x19\x18\x19\x17\x19\x14\x1a\x0d\x1a\x0d\x1a\x0d\x1a\x09\x1a\x0c\x0e\x05\x0e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_11_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 69,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7c\x01\x6a\x00\x6b\x02\x6f\x0c\x7c\x00\x6a\x01\x7c\x01\x6a\x01\x6b\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_12_consts_0 = {
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
    ._data = "Test whether two stat buffers reference the same file",
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
        uint8_t _data[7];
    }
toplevel_consts_12_names_0 = {
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
    ._data = "st_dev",
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_2._ascii.ob_base,
        },
    },
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
    .ob_sval = "\x02\x00\x0c\x02\x0a\x01\x02\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x0f\x0d\x16\x1a\x1c\x1a\x23\x0d\x23\x0d\x23\x0d\x0f\x0d\x16\x1a\x1c\x1a\x23\x0d\x23\x05\x24",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 87,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_10._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_10._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
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
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\xa9\x01\x7d\x02\x74\x00\x6a\x01\x7c\x01\xa9\x01\x7d\x03\x74\x02\x7c\x02\x7c\x03\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[214];
    }
toplevel_consts_13_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 213,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x54\x65\x73\x74\x20\x77\x68\x65\x74\x68\x65\x72\x20\x74\x77\x6f\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x73\x20\x72\x65\x66\x65\x72\x65\x6e\x63\x65\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x61\x63\x74\x75\x61\x6c\x20\x66\x69\x6c\x65\x20\x6f\x72\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x69\x73\x20\x64\x65\x74\x65\x72\x6d\x69\x6e\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x64\x65\x76\x69\x63\x65\x20\x6e\x75\x6d\x62\x65\x72\x20\x61\x6e\x64\x20\x69\x2d\x6e\x6f\x64\x65\x20\x6e\x75\x6d\x62\x65\x72\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x72\x61\x69\x73\x65\x73\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x66\x20\x61\x6e\x20\x6f\x73\x2e\x73\x74\x61\x74\x28\x29\x20\x63\x61\x6c\x6c\x20\x6f\x6e\x20\x65\x69\x74\x68\x65\x72\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x20\x66\x61\x69\x6c\x73\x2e\x0a\x20\x20\x20\x20",
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_13_names = {
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
            & toplevel_consts_3_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_13_varnames_0 = {
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
    ._data = "f1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_13_varnames_1 = {
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
    ._data = "f2",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_13_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13_varnames_0._ascii.ob_base,
            & toplevel_consts_13_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_2._ascii.ob_base,
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
    .ob_sval = "\x02\x00\x0a\x06\x0a\x01\x0a\x01",
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
    .ob_sval = "\x01\x01\x0a\x0c\x0a\x11\x12\x14\x0a\x15\x05\x07\x0a\x0c\x0a\x11\x12\x14\x0a\x15\x05\x07\x0c\x14\x15\x17\x19\x1b\x0c\x1c\x05\x1c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_13_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 94,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_8._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_8._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[59];
    }
toplevel_consts_14_consts_0 = {
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
    ._data = "Test whether two open file objects reference the same file",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_14_names_1 = {
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
    ._data = "fstat",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_14_names = {
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
            & toplevel_consts_14_names_1._ascii.ob_base,
            & toplevel_consts_3_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_14_varnames_0 = {
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
    ._data = "fp1",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_14_varnames_1 = {
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
    ._data = "fp2",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_14_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_14_varnames_0._ascii.ob_base,
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_11_varnames_2._ascii.ob_base,
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
    .ob_sval = "\x02\x00\x0a\x02\x0a\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0a\x0c\x0a\x12\x13\x16\x0a\x17\x05\x07\x0a\x0c\x0a\x12\x13\x16\x0a\x17\x05\x07\x0c\x14\x15\x17\x19\x1b\x0c\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 107,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_13_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_9._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_9._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[153];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 152,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x7d\x04\x7c\x02\x72\x14\x7c\x00\xa0\x00\x7c\x02\xa8\x01\xa9\x01\x7d\x05\x74\x01\x7c\x04\x7c\x05\xa9\x02\x7d\x04\x7c\x00\xa0\x00\x7c\x03\xa8\x01\xa9\x01\x7d\x06\x7c\x06\x7c\x04\x6b\x04\x72\x44\x7c\x04\x64\x01\x7a\x00\x7d\x07\x7c\x07\x7c\x06\x6b\x00\x72\x44\x7c\x00\x7c\x07\x7c\x07\x64\x01\x7a\x00\x85\x02\x19\x00\x7c\x03\x6b\x03\x72\x3c\x7c\x00\x64\x02\x7c\x06\x85\x02\x19\x00\x7c\x00\x7c\x06\x64\x02\x85\x02\x19\x00\x66\x02\x53\x00\x7c\x07\x64\x01\x7a\x0d\x7d\x07\x7c\x07\x7c\x06\x6b\x00\x73\x26\x7c\x00\x7c\x00\x64\x02\x64\x03\x85\x02\x19\x00\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[165];
    }
toplevel_consts_15_consts_0 = {
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
    ._data = "\x53\x70\x6c\x69\x74\x20\x74\x68\x65\x20\x65\x78\x74\x65\x6e\x73\x69\x6f\x6e\x20\x66\x72\x6f\x6d\x20\x61\x20\x70\x61\x74\x68\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x45\x78\x74\x65\x6e\x73\x69\x6f\x6e\x20\x69\x73\x20\x65\x76\x65\x72\x79\x74\x68\x69\x6e\x67\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x6c\x61\x73\x74\x20\x64\x6f\x74\x20\x74\x6f\x20\x74\x68\x65\x20\x65\x6e\x64\x2c\x20\x69\x67\x6e\x6f\x72\x69\x6e\x67\x0a\x20\x20\x20\x20\x6c\x65\x61\x64\x69\x6e\x67\x20\x64\x6f\x74\x73\x2e\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x22\x28\x72\x6f\x6f\x74\x2c\x20\x65\x78\x74\x29\x22\x3b\x20\x65\x78\x74\x20\x6d\x61\x79\x20\x62\x65\x20\x65\x6d\x70\x74\x79\x2e",
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_15_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_15_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_15_names_0._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_15_varnames_0 = {
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
        uint8_t _data[4];
    }
toplevel_consts_15_varnames_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_15_varnames_2 = {
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
toplevel_consts_15_varnames_3 = {
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
        uint8_t _data[9];
    }
toplevel_consts_15_varnames_4 = {
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
    ._data = "sepIndex",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_15_varnames_5 = {
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
    ._data = "altsepIndex",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_15_varnames_6 = {
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
    ._data = "dotIndex",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_15_varnames_7 = {
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
    ._data = "filenameIndex",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_15_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_3._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
            & toplevel_consts_15_varnames_5._ascii.ob_base,
            & toplevel_consts_15_varnames_6._ascii.ob_base,
            & toplevel_consts_15_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_15_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07\x04\x01\x0c\x01\x0a\x01\x0c\x02\x08\x01\x08\x02\x08\x01\x14\x01\x18\x01\x08\x01\x08\xfd\x10\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07\x02\x01\x02\x02\x0c\xff\x0a\x01\x0c\x02\x06\x01\x02\x06\x08\xfc\x06\x01\x02\x03\x12\xfe\x1a\x01\x08\x01\x06\xfd\x02\x03\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[153];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 152,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x11\x10\x1c\x18\x1b\x10\x1c\x10\x1c\x05\x0d\x08\x0e\x05\x2e\x17\x18\x17\x26\x1f\x25\x17\x26\x17\x26\x09\x14\x14\x17\x18\x20\x22\x2d\x14\x2e\x09\x11\x10\x11\x10\x1f\x18\x1e\x10\x1f\x10\x1f\x05\x0d\x08\x10\x13\x1b\x08\x1b\x05\x1f\x19\x21\x24\x25\x19\x25\x09\x16\x0f\x1c\x1f\x27\x0f\x27\x09\x1f\x10\x11\x12\x1f\x20\x2d\x2e\x2f\x20\x2f\x12\x2f\x10\x30\x34\x3a\x10\x3a\x0d\x32\x18\x19\x1a\x23\x1b\x23\x1a\x23\x18\x24\x26\x27\x28\x30\x28\x31\x28\x31\x26\x32\x18\x32\x11\x32\x0d\x1a\x1e\x1f\x0d\x1f\x0d\x1a\x0f\x1c\x1f\x27\x0f\x27\x09\x1f\x0c\x0d\x0f\x10\x11\x13\x12\x13\x11\x13\x0f\x14\x0c\x14\x05\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_15_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 121,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_15_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x04\x00\x7d\x02\x7d\x03\x7c\x01\x44\x00\x5d\x1d\x7d\x04\x74\x00\x7c\x04\x74\x01\xa9\x02\x72\x11\x64\x02\x7d\x02\x71\x07\x74\x00\x7c\x04\x74\x02\xa9\x02\x72\x19\x64\x02\x7d\x03\x71\x07\x74\x03\x7c\x00\x9b\x00\x64\x03\x7c\x04\x6a\x04\x6a\x05\x9b\x02\x9d\x03\xa9\x01\x64\x00\x82\x02\x7c\x02\x72\x2e\x7c\x03\x72\x30\x74\x03\x64\x04\xa9\x01\x64\x00\x82\x02\x64\x00\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[60];
    }
toplevel_consts_16_consts_3 = {
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
    ._data = "() argument must be str, bytes, or os.PathLike object, not ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_16_consts_4 = {
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
    ._data = "Can't mix strings and bytes in path components",
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
            Py_False,
            Py_True,
            & toplevel_consts_16_consts_3._ascii.ob_base,
            & toplevel_consts_16_consts_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_16_names_1 = {
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
        uint8_t _data[6];
    }
toplevel_consts_16_names_2 = {
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
        uint8_t _data[10];
    }
toplevel_consts_16_names_3 = {
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
        uint8_t _data[10];
    }
toplevel_consts_16_names_4 = {
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
toplevel_consts_16_names_5 = {
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
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_16_names_2._ascii.ob_base,
            & toplevel_consts_16_names_3._ascii.ob_base,
            & toplevel_consts_16_names_4._ascii.ob_base,
            & toplevel_consts_16_names_5._ascii.ob_base,
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
    ._data = "funcname",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_16_varnames_1 = {
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
toplevel_consts_16_varnames_2 = {
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
    ._data = "hasstr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_16_varnames_3 = {
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
    ._data = "hasbytes",
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
            & toplevel_consts_6_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_16_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_16_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x08\x01\x0a\x01\x06\x01\x0a\x01\x06\x01\x08\x02\x06\x01\x06\xff\x02\x01\x02\xff\x08\x02\x0a\x01\x08\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_16_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x02\x01\x04\x07\x02\xf9\x08\x01\x02\x06\x06\xfb\x08\x01\x02\x04\x06\xfd\x04\x02\x14\x01\x02\x01\x02\x01\x02\xff\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x19\x1e\x05\x1e\x05\x0b\x0e\x16\x0e\x12\x05\x5b\x05\x5b\x09\x0a\x0c\x16\x17\x18\x1a\x1d\x0c\x1e\x09\x5b\x16\x1a\x0d\x13\x0d\x13\x0e\x18\x19\x1a\x1c\x21\x0e\x22\x09\x5b\x18\x1c\x0d\x15\x0d\x15\x13\x1c\x20\x28\x1d\x50\x1d\x50\x38\x39\x38\x43\x38\x4c\x1d\x50\x1d\x50\x13\x51\x57\x5b\x0d\x5b\x08\x0e\x05\x54\x13\x1b\x05\x54\x0f\x18\x19\x49\x0f\x4a\x50\x54\x09\x54\x05\x54\x05\x54\x05\x54\x05\x54",
};
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 144,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
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
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_3._object.ob_base.ob_base,
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
    ._data = "__all__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[17];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 17,
        },
        .ob_item = {
            & toplevel_names_0._ascii.ob_base,
            & toplevel_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_names_3._ascii.ob_base,
            & toplevel_consts_3_1._ascii.ob_base,
            & toplevel_consts_3_7._ascii.ob_base,
            & toplevel_consts_3_6._ascii.ob_base,
            & toplevel_consts_3_5._ascii.ob_base,
            & toplevel_consts_3_4._ascii.ob_base,
            & toplevel_consts_3_2._ascii.ob_base,
            & toplevel_consts_3_3._ascii.ob_base,
            & toplevel_consts_3_0._ascii.ob_base,
            & toplevel_consts_3_10._ascii.ob_base,
            & toplevel_consts_3_8._ascii.ob_base,
            & toplevel_consts_3_9._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_16_name._ascii.ob_base,
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
        char ob_sval[37];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x05\x08\x01\x08\x02\x06\x07\x06\x0b\x06\x0c\x06\x09\x06\x05\x06\x05\x06\x05\x06\x06\x06\x12\x06\x07\x06\x0d\x06\x0e\x0a\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x04\x08\x01\x08\x01\x06\x04\x02\xfe\x06\x0d\x06\x0b\x06\x0c\x06\x05\x06\x05\x06\x05\x06\x05\x06\x12\x06\x07\x06\x0c\x06\x09\x06\x1f\x0a\x0d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x0b\x17\x0b\x17\x0b\x17\x01\x08\x01\x10\x01\x10\x01\x10\x01\x24\x01\x24\x01\x24\x01\x24\x01\x24\x01\x24\x01\x25\x01\x25\x01\x25\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x0e\x01\x0e\x01\x0e\x01\x24\x01\x24\x01\x24\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x14\x01\x14\x01\x14\x01\x54\x01\x54\x01\x54\x01\x54\x01\x54",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_4_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_4_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_genericpath_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

