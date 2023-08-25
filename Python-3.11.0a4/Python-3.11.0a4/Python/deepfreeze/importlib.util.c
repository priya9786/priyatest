#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[281];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 280,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x6d\x02\x5a\x02\x01\x00\x64\x01\x64\x03\x6c\x03\x6d\x04\x5a\x04\x01\x00\x64\x01\x64\x04\x6c\x03\x6d\x05\x5a\x05\x01\x00\x64\x01\x64\x05\x6c\x03\x6d\x06\x5a\x06\x01\x00\x64\x01\x64\x06\x6c\x03\x6d\x07\x5a\x07\x01\x00\x64\x01\x64\x07\x6c\x08\x6d\x09\x5a\x09\x01\x00\x64\x01\x64\x08\x6c\x08\x6d\x0a\x5a\x0a\x01\x00\x64\x01\x64\x09\x6c\x08\x6d\x0b\x5a\x0b\x01\x00\x64\x01\x64\x0a\x6c\x08\x6d\x0c\x5a\x0c\x01\x00\x64\x01\x64\x0b\x6c\x08\x6d\x0d\x5a\x0d\x01\x00\x64\x01\x64\x0c\x6c\x08\x6d\x0e\x5a\x0e\x01\x00\x64\x0d\x64\x0e\x6c\x0f\x6d\x10\x5a\x10\x01\x00\x64\x0d\x64\x0f\x6c\x11\x5a\x11\x64\x0d\x64\x0f\x6c\x12\x5a\x12\x64\x0d\x64\x0f\x6c\x13\x5a\x13\x64\x0d\x64\x0f\x6c\x14\x5a\x14\x64\x0d\x64\x0f\x6c\x15\x5a\x15\x64\x10\x84\x00\x5a\x16\x64\x11\x84\x00\x5a\x17\x64\x1c\x64\x12\x84\x01\x5a\x18\x64\x1c\x64\x13\x84\x01\x5a\x19\x65\x10\x64\x14\x84\x00\xa9\x01\x5a\x1a\x64\x15\x84\x00\x5a\x1b\x64\x16\x84\x00\x5a\x1c\x64\x17\x84\x00\x5a\x1d\x47\x00\x64\x18\x84\x00\x64\x19\x65\x14\x6a\x1e\xa9\x03\x5a\x1f\x47\x00\x64\x1a\x84\x00\x64\x1b\x65\x02\xa9\x03\x5a\x20\x64\x0f\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[46];
    }
toplevel_consts_0 = {
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
    ._data = "Utility code for constructing importers, etc.",
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
        .ob_size = 1,
    },
    .ob_digit = { 1 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_2_0 = {
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
    ._data = "Loader",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_2_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_3_0 = {
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
    ._data = "module_from_spec",
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
        uint8_t _data[14];
    }
toplevel_consts_4_0 = {
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
    ._data = "_resolve_name",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_5_0 = {
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
    ._data = "spec_from_loader",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_5_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_6_0 = {
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
    ._data = "_find_spec",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_6 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_6_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_7_0 = {
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
    ._data = "MAGIC_NUMBER",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_7 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_7_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_8_0 = {
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
    ._data = "_RAW_MAGIC_NUMBER",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_8 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_8_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_9_0 = {
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
    ._data = "cache_from_source",
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
        uint8_t _data[14];
    }
toplevel_consts_10_0 = {
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
    ._data = "decode_source",
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
        uint8_t _data[18];
    }
toplevel_consts_11_0 = {
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
    ._data = "source_from_cache",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_11 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_12_0 = {
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
    ._data = "spec_from_file_location",
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
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_13 = {
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
toplevel_consts_14_0 = {
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
    ._data = "contextmanager",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_14 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_14_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_16_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x74\x02\x7c\x00\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[67];
    }
toplevel_consts_16_consts_0 = {
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
    ._data = "Return the hash of *source_bytes* as used in hash-based pyc files.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_16_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_16_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_16_names_0 = {
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
    ._data = "_imp",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_16_names_1 = {
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
    ._data = "source_hash",
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
            & toplevel_consts_8_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_16_varnames_0 = {
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
    ._data = "source_bytes",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_16_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_16_varnames_0._ascii.ob_base,
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
toplevel_consts_16_freevars = {
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
        uint8_t _data[24];
    }
toplevel_consts_16_filename = {
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
    ._data = "<frozen importlib.util>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_16_linetable = {
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
toplevel_consts_16_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x1c\x1d\x2e\x30\x3c\x0c\x3d\x05\x3d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_16_exceptiontable = {
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
toplevel_consts_16_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_16 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_16_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_16_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 22,
    .co_code = & toplevel_consts_16_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_16_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_16_names_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_16_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_16_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[97];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 96,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x73\x09\x7c\x00\x53\x00\x7c\x01\x73\x15\x74\x01\x64\x02\x74\x02\x7c\x00\xa9\x01\x9b\x00\x64\x03\x9d\x03\xa9\x01\x82\x01\x64\x04\x7d\x02\x7c\x00\x44\x00\x5d\x0c\x7d\x03\x7c\x03\x64\x01\x6b\x03\x72\x21\x01\x00\x6e\x05\x7c\x02\x64\x05\x7a\x0d\x7d\x02\x71\x19\x74\x03\x7c\x00\x7c\x02\x64\x06\x85\x02\x19\x00\x7c\x01\x7c\x02\xa9\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[51];
    }
toplevel_consts_17_consts_0 = {
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
    ._data = "Resolve a relative module name to an absolute one.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_17_consts_1 = {
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
        uint8_t _data[26];
    }
toplevel_consts_17_consts_2 = {
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
    ._data = "no package specified for ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_17_consts_3 = {
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
    ._data = " (required for relative module names)",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_17_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_17_consts_0._ascii.ob_base,
            & toplevel_consts_17_consts_1._ascii.ob_base,
            & toplevel_consts_17_consts_2._ascii.ob_base,
            & toplevel_consts_17_consts_3._ascii.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
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
toplevel_consts_17_names_0 = {
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
        uint8_t _data[12];
    }
toplevel_consts_17_names_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_17_names_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_17_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_names_0._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_17_names_2._ascii.ob_base,
            & toplevel_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_17_varnames_0 = {
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
        uint8_t _data[8];
    }
toplevel_consts_17_varnames_1 = {
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
    ._data = "package",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_17_varnames_2 = {
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
    ._data = "level",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_17_varnames_3 = {
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
    ._data = "character",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_17_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_0._ascii.ob_base,
            & toplevel_consts_17_varnames_1._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_17_name = {
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
    ._data = "resolve_name",
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
    .ob_sval = "\x02\x00\x0c\x02\x04\x01\x04\x01\x14\x01\x04\x02\x08\x01\x08\x01\x04\x01\x0a\x01\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_17_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x02\x04\x04\xfd\x02\x01\x02\x02\x02\xff\x02\x01\x06\xff\x0a\x01\x04\x01\x02\x01\x04\x03\x02\xfd\x06\x01\x06\x01\x0a\x01\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[97];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 96,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x20\x1c\x1f\x0c\x20\x0c\x20\x05\x42\x10\x14\x09\x14\x0e\x15\x05\x42\x0f\x1a\x1b\x41\x37\x3b\x3c\x40\x37\x41\x1b\x41\x1b\x41\x1b\x41\x0f\x42\x09\x42\x0d\x0e\x05\x0a\x16\x1a\x05\x13\x05\x13\x09\x12\x0c\x15\x19\x1c\x0c\x1c\x09\x12\x0d\x12\x0d\x12\x09\x0e\x12\x13\x09\x13\x09\x0e\x09\x0e\x0c\x19\x1a\x1e\x1f\x24\x1f\x25\x1f\x25\x1a\x26\x28\x2f\x31\x36\x0c\x37\x05\x37",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_17_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_17 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_17_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_17_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_17_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 27,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_17_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_17_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[109];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x74\x00\x6a\x01\x76\x01\x72\x0b\x74\x02\x7c\x00\x7c\x01\xa9\x02\x53\x00\x74\x00\x6a\x01\x7c\x00\x19\x00\x7d\x02\x7c\x02\x80\x14\x64\x01\x53\x00\x09\x00\x7c\x02\x6a\x03\x7d\x03\x6e\x11\x23\x00\x74\x04\x79\x26\x01\x00\x74\x05\x64\x02\xa0\x06\x7c\x00\xa8\x01\xa9\x01\xa9\x01\x64\x01\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x03\x80\x34\x74\x05\x64\x03\xa0\x06\x7c\x00\xa8\x01\xa9\x01\xa9\x01\x82\x01\x7c\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[648];
    }
toplevel_consts_18_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 647,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x73\x70\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x46\x69\x72\x73\x74\x2c\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x20\x69\x73\x20\x63\x68\x65\x63\x6b\x65\x64\x20\x74\x6f\x20\x73\x65\x65\x20\x69\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x77\x61\x73\x20\x61\x6c\x72\x65\x61\x64\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2e\x20\x49\x66\x0a\x20\x20\x20\x20\x73\x6f\x2c\x20\x74\x68\x65\x6e\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x5b\x6e\x61\x6d\x65\x5d\x2e\x5f\x5f\x73\x70\x65\x63\x5f\x5f\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x2e\x20\x49\x66\x20\x74\x68\x61\x74\x20\x68\x61\x70\x70\x65\x6e\x73\x20\x74\x6f\x20\x62\x65\x0a\x20\x20\x20\x20\x73\x65\x74\x20\x74\x6f\x20\x4e\x6f\x6e\x65\x2c\x20\x74\x68\x65\x6e\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x20\x49\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x69\x6e\x0a\x20\x20\x20\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x2c\x20\x74\x68\x65\x6e\x20\x73\x79\x73\x2e\x6d\x65\x74\x61\x5f\x70\x61\x74\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x20\x73\x75\x69\x74\x61\x62\x6c\x65\x20\x73\x70\x65\x63\x20\x77\x69\x74\x68\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x27\x70\x61\x74\x68\x27\x20\x67\x69\x76\x65\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x66\x69\x6e\x64\x65\x72\x73\x2e\x20\x4e\x6f\x6e\x65\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x69\x66\x20\x6e\x6f\x20\x73\x70\x65\x63\x20\x63\x6f\x75\x6c\x64\x0a\x20\x20\x20\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20\x44\x6f\x74\x74\x65\x64\x20\x6e\x61\x6d\x65\x73\x20\x64\x6f\x20\x6e\x6f\x74\x20\x68\x61\x76\x65\x20\x74\x68\x65\x69\x72\x20\x70\x61\x72\x65\x6e\x74\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x69\x6d\x70\x6c\x69\x63\x69\x74\x6c\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2e\x20\x59\x6f\x75\x20\x77\x69\x6c\x6c\x0a\x20\x20\x20\x20\x6d\x6f\x73\x74\x20\x6c\x69\x6b\x65\x6c\x79\x20\x6e\x65\x65\x64\x20\x74\x6f\x20\x65\x78\x70\x6c\x69\x63\x69\x74\x6c\x79\x20\x69\x6d\x70\x6f\x72\x74\x20\x61\x6c\x6c\x20\x70\x61\x72\x65\x6e\x74\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x20\x69\x6e\x20\x74\x68\x65\x20\x70\x72\x6f\x70\x65\x72\x0a\x20\x20\x20\x20\x6f\x72\x64\x65\x72\x20\x66\x6f\x72\x20\x61\x20\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x20\x74\x6f\x20\x67\x65\x74\x20\x74\x68\x65\x20\x63\x6f\x72\x72\x65\x63\x74\x20\x73\x70\x65\x63\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_18_consts_2 = {
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
    ._data = "{}.__spec__ is not set",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_18_consts_3 = {
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
    ._data = "{}.__spec__ is None",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_18_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_18_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_18_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_18_names_0 = {
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
toplevel_consts_18_names_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_18_names_3 = {
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
        uint8_t _data[15];
    }
toplevel_consts_18_names_4 = {
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
        uint8_t _data[11];
    }
toplevel_consts_18_names_5 = {
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
        uint8_t _data[7];
    }
toplevel_consts_18_names_6 = {
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
            & toplevel_consts_18_names_0._ascii.ob_base,
            & toplevel_consts_18_names_1._ascii.ob_base,
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_18_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_varnames_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_18_varnames_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_varnames_3 = {
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
    ._data = "spec",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_18_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_0._ascii.ob_base,
            & toplevel_consts_18_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_18_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_18_name = {
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
    ._data = "_find_spec_from_path",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x0f\x0a\x01\x0a\x02\x04\x01\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x12\x01\x02\xff\x06\x80\x04\x03\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_18_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0f\x02\x0d\x0a\xf4\x0a\x02\x02\x01\x06\x01\x02\x08\x08\xfa\x02\x80\x02\x01\x18\x01\x06\x80\x02\x02\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[109];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0c\x14\x17\x14\x1f\x08\x1f\x05\x18\x10\x1a\x1b\x1f\x21\x25\x10\x26\x09\x26\x12\x15\x12\x1d\x1e\x22\x12\x23\x09\x0f\x0c\x12\x09\x18\x14\x18\x14\x18\x09\x18\x14\x1a\x14\x23\x0d\x11\x0d\x11\x00\x00\x10\x1e\x09\x4e\x09\x4e\x13\x1d\x1e\x36\x1e\x43\x3e\x42\x1e\x43\x1e\x43\x13\x44\x4a\x4e\x0d\x4e\x09\x4e\x00\x00\x00\x00\x00\x00\x10\x14\x0d\x45\x17\x21\x22\x37\x22\x44\x3f\x43\x22\x44\x22\x44\x17\x45\x11\x45\x14\x18\x0d\x18",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_18_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x03\x19\x00\x99\x0e\x27\x03",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_18_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 42,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_18_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x72\x0c\x74\x01\x7c\x00\x7c\x01\xa9\x02\x6e\x01\x7c\x00\x7d\x02\x7c\x02\x74\x02\x6a\x03\x76\x01\x72\x49\x7c\x02\xa0\x04\x64\x01\xa8\x01\xa9\x01\x64\x02\x19\x00\x7d\x03\x7c\x03\x72\x42\x74\x05\x7c\x03\x64\x03\x67\x01\x64\x04\xaa\x02\x7d\x04\x09\x00\x7c\x04\x6a\x06\x7d\x05\x6e\x1b\x23\x00\x74\x07\x79\x3e\x7d\x06\x74\x08\x64\x05\x7c\x03\x9b\x02\x64\x06\x7c\x02\x9b\x02\x9d\x04\x7c\x02\x64\x07\xaa\x02\x7c\x06\x82\x02\x64\x08\x7d\x06\x7e\x06\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x64\x08\x7d\x05\x74\x09\x7c\x02\x7c\x05\xa9\x02\x53\x00\x74\x02\x6a\x03\x7c\x02\x19\x00\x7d\x07\x7c\x07\x80\x52\x64\x08\x53\x00\x09\x00\x7c\x07\x6a\x0a\x7d\x08\x6e\x11\x23\x00\x74\x07\x79\x64\x01\x00\x74\x0b\x64\x09\xa0\x0c\x7c\x00\xa8\x01\xa9\x01\xa9\x01\x64\x08\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x08\x80\x72\x74\x0b\x64\x0a\xa0\x0c\x7c\x00\xa8\x01\xa9\x01\xa9\x01\x82\x01\x7c\x08\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[688];
    }
toplevel_consts_19_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 687,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x73\x70\x65\x63\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x46\x69\x72\x73\x74\x2c\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x20\x69\x73\x20\x63\x68\x65\x63\x6b\x65\x64\x20\x74\x6f\x20\x73\x65\x65\x20\x69\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x77\x61\x73\x20\x61\x6c\x72\x65\x61\x64\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2e\x20\x49\x66\x0a\x20\x20\x20\x20\x73\x6f\x2c\x20\x74\x68\x65\x6e\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x5b\x6e\x61\x6d\x65\x5d\x2e\x5f\x5f\x73\x70\x65\x63\x5f\x5f\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x2e\x20\x49\x66\x20\x74\x68\x61\x74\x20\x68\x61\x70\x70\x65\x6e\x73\x20\x74\x6f\x20\x62\x65\x0a\x20\x20\x20\x20\x73\x65\x74\x20\x74\x6f\x20\x4e\x6f\x6e\x65\x2c\x20\x74\x68\x65\x6e\x20\x56\x61\x6c\x75\x65\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x20\x49\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x69\x6e\x0a\x20\x20\x20\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x2c\x20\x74\x68\x65\x6e\x20\x73\x79\x73\x2e\x6d\x65\x74\x61\x5f\x70\x61\x74\x68\x20\x69\x73\x20\x73\x65\x61\x72\x63\x68\x65\x64\x20\x66\x6f\x72\x20\x61\x20\x73\x75\x69\x74\x61\x62\x6c\x65\x20\x73\x70\x65\x63\x20\x77\x69\x74\x68\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x76\x61\x6c\x75\x65\x20\x6f\x66\x20\x27\x70\x61\x74\x68\x27\x20\x67\x69\x76\x65\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x66\x69\x6e\x64\x65\x72\x73\x2e\x20\x4e\x6f\x6e\x65\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x69\x66\x20\x6e\x6f\x20\x73\x70\x65\x63\x20\x63\x6f\x75\x6c\x64\x0a\x20\x20\x20\x20\x62\x65\x20\x66\x6f\x75\x6e\x64\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x20\x69\x73\x20\x66\x6f\x72\x20\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x20\x28\x63\x6f\x6e\x74\x61\x69\x6e\x73\x20\x61\x20\x64\x6f\x74\x29\x2c\x20\x74\x68\x65\x20\x70\x61\x72\x65\x6e\x74\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x0a\x20\x20\x20\x20\x61\x75\x74\x6f\x6d\x61\x74\x69\x63\x61\x6c\x6c\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x6e\x61\x6d\x65\x20\x61\x6e\x64\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x77\x6f\x72\x6b\x20\x74\x68\x65\x20\x73\x61\x6d\x65\x20\x61\x73\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x2e\x69\x6d\x70\x6f\x72\x74\x5f\x6d\x6f\x64\x75\x6c\x65\x28\x29\x2e\x0a\x20\x20\x20\x20\x49\x6e\x20\x6f\x74\x68\x65\x72\x20\x77\x6f\x72\x64\x73\x2c\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x73\x20\x28\x77\x69\x74\x68\x20\x6c\x65\x61\x64\x69\x6e\x67\x20\x64\x6f\x74\x73\x29\x20\x77\x6f\x72\x6b\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_consts_3 = {
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
    ._data = "__path__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_consts_4_0 = {
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
    ._data = "fromlist",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_19_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_19_consts_4_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_19_consts_5 = {
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
    ._data = "__path__ attribute not found on ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_19_consts_6 = {
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
    ._data = " while trying to find ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_19_consts_7 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_0._ascii.ob_base,
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
toplevel_consts_19_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_19_consts_0._ascii.ob_base,
            & toplevel_consts_17_consts_1._ascii.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
            & toplevel_consts_19_consts_3._ascii.ob_base,
            & toplevel_consts_19_consts_4._object.ob_base.ob_base,
            & toplevel_consts_19_consts_5._ascii.ob_base,
            & toplevel_consts_19_consts_6._ascii.ob_base,
            & toplevel_consts_19_consts_7._object.ob_base.ob_base,
            Py_None,
            & toplevel_consts_18_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_19_names_4 = {
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
    ._data = "rpartition",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_19_names_5 = {
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
    ._data = "__import__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_19_names_8 = {
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
    ._data = "ModuleNotFoundError",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_19_names = {
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
            & toplevel_consts_17_name._ascii.ob_base,
            & toplevel_consts_18_names_0._ascii.ob_base,
            & toplevel_consts_18_names_1._ascii.ob_base,
            & toplevel_consts_19_names_4._ascii.ob_base,
            & toplevel_consts_19_names_5._ascii.ob_base,
            & toplevel_consts_19_consts_3._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_19_names_8._ascii.ob_base,
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_18_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_varnames_2 = {
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
        uint8_t _data[12];
    }
toplevel_consts_19_varnames_3 = {
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
    ._data = "parent_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_19_varnames_4 = {
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
        uint8_t _data[12];
    }
toplevel_consts_19_varnames_5 = {
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
    ._data = "parent_path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_19_varnames_6 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_0._ascii.ob_base,
            & toplevel_consts_17_varnames_1._ascii.ob_base,
            & toplevel_consts_19_varnames_2._ascii.ob_base,
            & toplevel_consts_19_varnames_3._ascii.ob_base,
            & toplevel_consts_19_varnames_4._ascii.ob_base,
            & toplevel_consts_19_varnames_5._ascii.ob_base,
            & toplevel_consts_19_varnames_6._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_18_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_19_name = {
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
    ._data = "find_spec",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x1a\x11\x0a\x01\x10\x01\x04\x01\x0e\x01\x02\x01\x08\x01\x02\x80\x06\x01\x02\x01\x08\x01\x02\x01\x04\xff\x02\x01\x04\xfe\x02\x02\x02\xfe\x08\x80\x02\xff\x06\x80\x04\x05\x0a\x01\x0a\x02\x04\x01\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x12\x01\x02\xff\x06\x80\x04\x03\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x1a\x11\x08\x01\x02\x18\x10\xe9\x02\x01\x02\x09\x0e\xf8\x02\x06\x08\xfc\x02\x80\x02\x01\x04\x03\x02\xfe\x02\x02\x02\xff\x14\x01\x08\x80\x02\x00\x06\x80\x04\x02\x0a\x01\x0a\x02\x02\x01\x06\x01\x02\x08\x08\xfa\x02\x80\x02\x01\x18\x01\x06\x80\x02\x02\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[233];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 232,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x2f\x33\x2f\x43\x3f\x42\x2f\x43\x2f\x43\x10\x4d\x10\x1c\x1d\x21\x23\x2a\x10\x2b\x10\x2b\x49\x4d\x05\x0d\x08\x10\x18\x1b\x18\x23\x08\x23\x05\x18\x17\x1f\x17\x2f\x2b\x2e\x17\x2f\x17\x2f\x30\x31\x17\x32\x09\x14\x0c\x17\x09\x1f\x16\x20\x21\x2c\x38\x42\x37\x43\x16\x44\x16\x44\x0d\x13\x0d\x50\x1f\x25\x1f\x2e\x11\x1c\x11\x1c\x00\x00\x14\x22\x0d\x50\x0d\x50\x17\x2a\x15\x39\x38\x43\x15\x39\x15\x39\x2d\x35\x15\x39\x15\x39\x40\x48\x17\x49\x17\x49\x4f\x50\x11\x50\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x50\x00\x00\x00\x00\x00\x00\x1b\x1f\x0d\x18\x10\x1a\x1b\x23\x25\x30\x10\x31\x09\x31\x12\x15\x12\x1d\x1e\x26\x12\x27\x09\x0f\x0c\x12\x09\x18\x14\x18\x14\x18\x09\x18\x14\x1a\x14\x23\x0d\x11\x0d\x11\x00\x00\x10\x1e\x09\x4e\x09\x4e\x13\x1d\x1e\x36\x1e\x43\x3e\x42\x1e\x43\x1e\x43\x13\x44\x4a\x4e\x0d\x4e\x09\x4e\x00\x00\x00\x00\x00\x00\x10\x14\x0d\x45\x17\x21\x22\x37\x22\x44\x3f\x43\x22\x44\x22\x44\x17\x45\x11\x45\x14\x18\x0d\x18",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_19_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\xa5\x03\x29\x00\xa9\x04\x3f\x03\xad\x0d\x3a\x03\xba\x05\x3f\x03\xc1\x13\x03\x41\x17\x00\xc1\x17\x0e\x41\x25\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_19_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_19_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 73,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[167];
    }
toplevel_consts_20_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 166,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x00\x97\x00\x7c\x00\x74\x00\x6a\x01\x76\x00\x7d\x01\x74\x00\x6a\x01\xa0\x02\x7c\x00\xa8\x01\xa9\x01\x7d\x02\x7c\x01\x73\x1e\x74\x03\x74\x00\xa9\x01\x7c\x00\xa9\x01\x7d\x02\x64\x01\x7c\x02\x5f\x04\x7c\x02\x74\x00\x6a\x01\x7c\x00\x3c\x00\x09\x00\x7c\x02\x56\x00\x97\x01\x01\x00\x6e\x1c\x23\x00\x74\x05\x79\x3c\x01\x00\x7c\x01\x73\x3a\x09\x00\x74\x00\x6a\x01\x7c\x00\x3d\x00\x6e\x0a\x23\x00\x74\x06\x79\x36\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x59\x00\x6e\x0a\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x64\x02\x7c\x02\x5f\x04\x64\x00\x53\x00\x64\x02\x7c\x02\x5f\x04\x64\x00\x53\x00\x23\x00\x64\x02\x7c\x02\x5f\x04\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_20_consts = {
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
        uint8_t _data[4];
    }
toplevel_consts_20_names_2 = {
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
    ._data = "type",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_20_names_4 = {
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
    ._data = "__initializing__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_names_5 = {
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
        uint8_t _data[9];
    }
toplevel_consts_20_names_6 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_18_names_0._ascii.ob_base,
            & toplevel_consts_18_names_1._ascii.ob_base,
            & toplevel_consts_20_names_2._ascii.ob_base,
            & toplevel_consts_20_names_3._ascii.ob_base,
            & toplevel_consts_20_names_4._ascii.ob_base,
            & toplevel_consts_20_names_5._ascii.ob_base,
            & toplevel_consts_20_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_varnames_1 = {
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
    ._data = "is_reload",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_20_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_0._ascii.ob_base,
            & toplevel_consts_20_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_20_name = {
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
    ._data = "_module_to_load",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x0e\x02\x04\x01\x0c\x04\x06\x03\x0a\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x0a\x80\x02\xfc\x06\x80\x02\xff\x14\x08\x02\x80\x0e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_20_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x0e\x02\x02\x01\x02\x08\x0c\xfc\x06\x03\x0a\x01\x02\x0a\x0a\xf8\x02\x80\x02\x01\x04\x05\x02\xfc\x04\x04\x0a\xfe\x02\x80\x02\x01\x0a\x01\x0a\x80\x02\x00\x06\x80\x02\xfa\x14\x08\x02\x80\x0e\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[167];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 166,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x11\x15\x19\x1c\x19\x24\x11\x24\x05\x0e\x0e\x11\x0e\x19\x0e\x23\x1e\x22\x0e\x23\x0e\x23\x05\x0b\x0c\x15\x05\x23\x12\x16\x17\x1a\x12\x1b\x1c\x20\x12\x21\x09\x0f\x23\x27\x09\x0f\x09\x20\x1d\x23\x09\x0c\x09\x14\x15\x19\x09\x1a\x05\x28\x0f\x15\x09\x15\x09\x15\x09\x15\x09\x15\x00\x00\x0c\x15\x05\x15\x05\x15\x10\x19\x09\x15\x0d\x15\x15\x18\x15\x20\x21\x25\x15\x26\x15\x26\x00\x00\x14\x1c\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05\x15\x00\x00\x00\x00\x00\x00\x09\x15\x23\x28\x09\x0f\x09\x20\x09\x20\x09\x20\x23\x28\x09\x0f\x09\x20\x09\x20\x09\x20\x00\x00\x23\x28\x09\x0f\x09\x20\x09\x28\x09\x28\x09\x28\x09\x28",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[58];
    }
toplevel_consts_20_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 57,
    },
    .ob_shash = -1,
    .ob_sval = "\x9f\x04\x24\x00\xa3\x01\x41\x0b\x00\xa4\x06\x3d\x03\xab\x04\x30\x02\xaf\x01\x3d\x03\xb0\x04\x37\x05\xb4\x02\x3d\x03\xb6\x01\x37\x05\xb7\x03\x3d\x03\xba\x02\x41\x0b\x00\xbc\x01\x3d\x03\xbd\x03\x41\x0b\x00\xc1\x0b\x05\x41\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_20_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_20_exceptiontable.ob_base.ob_base,
    .co_flags = 35,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 118,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_20_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_21_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x74\x00\x6a\x01\x89\x00\xa9\x01\x88\x00\x66\x01\x64\x01\x84\x08\xa9\x01\x7d\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[80];
    }
toplevel_consts_21_consts_0 = {
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
    ._data = "\x53\x65\x74\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x20\x6f\x6e\x20\x74\x68\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_21_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x6a\x01\x64\x01\x74\x02\x64\x02\x64\x03\xaa\x03\x01\x00\x89\x03\x7c\x00\x69\x00\x7c\x01\xa4\x01\x8e\x01\x7d\x02\x74\x03\x7c\x02\x64\x04\x64\x00\xa9\x03\x80\x2a\x7c\x02\x6a\x04\x7c\x02\x5f\x05\x74\x06\x7c\x02\x64\x05\xa9\x02\x73\x2a\x7c\x02\x6a\x05\xa0\x07\x64\x06\xa8\x01\xa9\x01\x64\x07\x19\x00\x7c\x02\x5f\x05\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[108];
    }
toplevel_consts_21_consts_1_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 107,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "The import system now takes care of this automatically; this decorator is slated for removal in Python 3.12",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_21_consts_1_consts_2 = {
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
toplevel_consts_21_consts_1_consts_3_0 = {
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
toplevel_consts_21_consts_1_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_consts_3_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_21_consts_1_consts_4 = {
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
    ._data = "__package__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_21_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_21_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_2.ob_base.ob_base,
            & toplevel_consts_21_consts_1_consts_3._object.ob_base.ob_base,
            & toplevel_consts_21_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_19_consts_3._ascii.ob_base,
            & toplevel_consts_17_consts_1._ascii.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_21_consts_1_names_0 = {
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
toplevel_consts_21_consts_1_names_1 = {
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
toplevel_consts_21_consts_1_names_2 = {
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
        uint8_t _data[8];
    }
toplevel_consts_21_consts_1_names_3 = {
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
toplevel_consts_21_consts_1_names_4 = {
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
toplevel_consts_21_consts_1_names_6 = {
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
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_21_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_6._ascii.ob_base,
            & toplevel_consts_19_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_21_consts_1_varnames_0 = {
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
toplevel_consts_21_consts_1_varnames_1 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_21_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_21_consts_1_freevars_0 = {
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
    ._data = "fxn",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_21_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_21_consts_1_name = {
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
    ._data = "set_package_wrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[41];
    }
toplevel_consts_21_consts_1_qualname = {
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
    ._data = "set_package.<locals>.set_package_wrapper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_21_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x02\x04\x02\x06\xfe\x0e\x03\x0c\x01\x08\x01\x0a\x01\x14\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_21_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x02\x02\x01\x0a\x01\x0e\x01\x0a\x01\x02\x03\x08\xfe\x08\x01\x16\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_21_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x09\x11\x09\x16\x17\x4c\x17\x29\x36\x37\x09\x38\x09\x38\x09\x38\x12\x15\x17\x1b\x12\x26\x1f\x25\x12\x26\x12\x26\x09\x0f\x0c\x13\x14\x1a\x1c\x29\x2b\x2f\x0c\x30\x09\x4b\x22\x28\x22\x31\x0d\x13\x0d\x1f\x14\x1b\x1c\x22\x24\x2e\x14\x2f\x0d\x4b\x26\x2c\x26\x38\x26\x48\x44\x47\x26\x48\x26\x48\x49\x4a\x26\x4b\x11\x17\x11\x23\x10\x16\x09\x16",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_21_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_21_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_21_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 31,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 150,
    .co_code = & toplevel_consts_21_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_21_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_21_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_21_names_0 = {
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
    ._data = "functools",
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
    ._data = "wraps",
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
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
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
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_21_name = {
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
    ._data = "set_package",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_21_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x08\x01\x02\xff\x02\x01\x04\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_21_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x08\x0a\x02\xf6\x02\x0a\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_21_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x06\x0f\x06\x15\x16\x19\x06\x1a\x05\x16\x05\x16\x05\x16\x05\x16\x06\x1a\x05\x16\x0c\x1f\x05\x1f",
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
    .ob_sval = "` ",
};
static struct PyCodeObject toplevel_consts_21 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 144,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[79];
    }
toplevel_consts_22_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 78,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x65\x74\x20\x5f\x5f\x6c\x6f\x61\x64\x65\x72\x5f\x5f\x20\x6f\x6e\x20\x74\x68\x65\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_22_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x6a\x01\x64\x01\x74\x02\x64\x02\x64\x03\xaa\x03\x01\x00\x89\x04\x7c\x00\x67\x01\x7c\x01\xa2\x01\x52\x00\x69\x00\x7c\x02\xa4\x01\x8e\x01\x7d\x03\x74\x03\x7c\x03\x64\x04\x64\x00\xa9\x03\x80\x1e\x7c\x00\x7c\x03\x5f\x04\x7c\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_22_consts_1_consts_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_22_consts_1_consts = {
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
            & toplevel_consts_21_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_2.ob_base.ob_base,
            & toplevel_consts_21_consts_1_consts_3._object.ob_base.ob_base,
            & toplevel_consts_22_consts_1_consts_4._ascii.ob_base,
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
toplevel_consts_22_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_22_consts_1_consts_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_22_consts_1_varnames_0 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_22_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_22_consts_1_name = {
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
    ._data = "set_loader_wrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[39];
    }
toplevel_consts_22_consts_1_qualname = {
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
    ._data = "set_loader.<locals>.set_loader_wrapper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x02\x04\x02\x06\xfe\x16\x03\x0c\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_22_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x02\x02\x01\x0a\x01\x16\x01\x0a\x01\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[65];
    }
toplevel_consts_22_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 64,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x09\x11\x09\x16\x17\x4c\x17\x29\x36\x37\x09\x38\x09\x38\x09\x38\x12\x15\x16\x1a\x12\x2c\x1d\x21\x12\x2c\x12\x2c\x12\x2c\x25\x2b\x12\x2c\x12\x2c\x09\x0f\x0c\x13\x14\x1a\x1c\x28\x2a\x2e\x0c\x2f\x09\x25\x21\x25\x0d\x13\x0d\x1e\x10\x16\x09\x16",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_22_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_22_consts_1_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 5,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x20\x20\x80",
};
static struct PyCodeObject toplevel_consts_22_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_22_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_22_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 31,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 170,
    .co_code = & toplevel_consts_22_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_22_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_22_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_consts_0._ascii.ob_base,
            & toplevel_consts_22_consts_1.ob_base,
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
toplevel_consts_22_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_22_consts_1_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_22_name = {
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
    ._data = "set_loader",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x08\x01\x02\xff\x02\x01\x04\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_22_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x06\x08\x08\x02\xf8\x02\x08\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x06\x0f\x06\x15\x16\x19\x06\x1a\x05\x16\x05\x16\x05\x16\x05\x16\x06\x1a\x05\x16\x0c\x1e\x05\x1e",
};
static struct PyCodeObject toplevel_consts_22 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_22_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 164,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_23_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x74\x00\x6a\x01\x64\x01\x74\x02\x64\x02\x64\x03\xaa\x03\x01\x00\x74\x03\x6a\x04\x89\x00\xa9\x01\x88\x00\x66\x01\x64\x04\x84\x08\xa9\x01\x7d\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[811];
    }
toplevel_consts_23_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 810,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x74\x6f\x20\x68\x61\x6e\x64\x6c\x65\x20\x73\x65\x6c\x65\x63\x74\x69\x6e\x67\x20\x74\x68\x65\x20\x70\x72\x6f\x70\x65\x72\x20\x6d\x6f\x64\x75\x6c\x65\x20\x66\x6f\x72\x20\x6c\x6f\x61\x64\x65\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x64\x65\x63\x6f\x72\x61\x74\x65\x64\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x70\x61\x73\x73\x65\x64\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x74\x6f\x20\x75\x73\x65\x20\x69\x6e\x73\x74\x65\x61\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x0a\x20\x20\x20\x20\x6e\x61\x6d\x65\x2e\x20\x54\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x70\x61\x73\x73\x65\x64\x20\x69\x6e\x20\x74\x6f\x20\x74\x68\x65\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x65\x69\x74\x68\x65\x72\x20\x66\x72\x6f\x6d\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x20\x69\x66\x0a\x20\x20\x20\x20\x69\x74\x20\x61\x6c\x72\x65\x61\x64\x79\x20\x65\x78\x69\x73\x74\x73\x20\x6f\x72\x20\x69\x73\x20\x61\x20\x6e\x65\x77\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x20\x49\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x6e\x65\x77\x2c\x20\x74\x68\x65\x6e\x20\x5f\x5f\x6e\x61\x6d\x65\x5f\x5f\x0a\x20\x20\x20\x20\x69\x73\x20\x73\x65\x74\x20\x74\x68\x65\x20\x66\x69\x72\x73\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x74\x6f\x20\x74\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x2c\x20\x5f\x5f\x6c\x6f\x61\x64\x65\x72\x5f\x5f\x20\x69\x73\x20\x73\x65\x74\x20\x74\x6f\x20\x73\x65\x6c\x66\x2c\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x20\x69\x73\x20\x73\x65\x74\x20\x61\x63\x63\x6f\x72\x64\x69\x6e\x67\x6c\x79\x20\x28\x69\x66\x20\x73\x65\x6c\x66\x2e\x69\x73\x5f\x70\x61\x63\x6b\x61\x67\x65\x28\x29\x20\x69\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x29\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x73\x65\x74\x0a\x20\x20\x20\x20\x62\x65\x66\x6f\x72\x65\x20\x69\x74\x20\x69\x73\x20\x70\x61\x73\x73\x65\x64\x20\x74\x6f\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x72\x61\x74\x65\x64\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x28\x69\x66\x20\x73\x65\x6c\x66\x2e\x69\x73\x5f\x70\x61\x63\x6b\x61\x67\x65\x28\x29\x20\x64\x6f\x65\x73\x0a\x20\x20\x20\x20\x6e\x6f\x74\x20\x77\x6f\x72\x6b\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x74\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x73\x65\x74\x20\x70\x6f\x73\x74\x2d\x6c\x6f\x61\x64\x29\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x61\x6e\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x63\x72\x65\x61\x74\x65\x64\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x74\x20\x69\x73\x0a\x20\x20\x20\x20\x73\x75\x62\x73\x65\x71\x75\x65\x6e\x74\x6c\x79\x20\x72\x65\x6d\x6f\x76\x65\x64\x20\x66\x72\x6f\x6d\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x61\x73\x73\x75\x6d\x65\x73\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x64\x65\x63\x6f\x72\x61\x74\x65\x64\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x74\x61\x6b\x65\x73\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x20\x61\x73\x0a\x20\x20\x20\x20\x74\x68\x65\x20\x73\x65\x63\x6f\x6e\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[153];
    }
toplevel_consts_23_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 152,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\x7c\x01\xa9\x01\x35\x00\x7d\x04\x7c\x00\x7c\x04\x5f\x01\x09\x00\x7c\x00\xa0\x02\x7c\x01\xa8\x01\xa9\x01\x7d\x05\x6e\x0c\x23\x00\x74\x03\x74\x04\x66\x02\x79\x1a\x01\x00\x59\x00\x6e\x13\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x72\x24\x7c\x01\x7c\x04\x5f\x05\x6e\x09\x7c\x01\xa0\x06\x64\x01\xa8\x01\xa9\x01\x64\x02\x19\x00\x7c\x04\x5f\x05\x89\x06\x7c\x00\x7c\x04\x67\x02\x7c\x02\xa2\x01\x52\x00\x69\x00\x7c\x03\xa4\x01\x8e\x01\x02\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x53\x00\x23\x00\x31\x00\x73\x46\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_23_consts_4_consts = {
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
            & toplevel_consts_17_consts_1._ascii.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_23_consts_4_names_2 = {
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
    ._data = "is_package",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_23_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_22_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_17_names_1._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_19_names_4._ascii.ob_base,
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
toplevel_consts_23_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_19_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_23_consts_4_name = {
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
    ._data = "module_for_loader_wrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[53];
    }
toplevel_consts_23_consts_4_qualname = {
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
    ._data = "module_for_loader.<locals>.module_for_loader_wrapper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_23_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x06\x01\x02\x01\x0e\x01\x02\x80\x0a\x01\x04\x01\x02\xff\x06\x80\x04\x03\x08\x01\x12\x02\x16\x02\x16\xf4\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_23_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x02\x02\x0c\x02\xf4\x06\x01\x02\x09\x0e\xf9\x02\x80\x06\x01\x0a\x01\x06\x80\x02\x02\x02\x03\x08\xfe\x12\x02\x2c\x02\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[153];
    }
toplevel_consts_23_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 152,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0e\x1d\x1e\x26\x0e\x27\x09\x36\x2b\x31\x21\x25\x0d\x13\x0d\x1e\x0d\x45\x1e\x22\x1e\x37\x2e\x36\x1e\x37\x1e\x37\x11\x1b\x11\x1b\x00\x00\x15\x20\x22\x30\x14\x31\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x14\x1e\x11\x45\x2a\x32\x15\x1b\x15\x27\x15\x27\x2a\x32\x2a\x42\x3e\x41\x2a\x42\x2a\x42\x43\x44\x2a\x45\x15\x1b\x15\x27\x14\x17\x18\x1c\x1e\x24\x14\x36\x27\x2b\x14\x36\x14\x36\x14\x36\x2f\x35\x14\x36\x14\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x00\x00\x00\x00\x00\x00\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[40];
    }
toplevel_consts_23_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 39,
    },
    .ob_shash = -1,
    .ob_sval = "\x86\x04\x3f\x03\x8b\x06\x12\x02\x91\x01\x3f\x03\x92\x06\x1b\x05\x98\x02\x3f\x03\x9a\x01\x1b\x05\x9b\x1d\x3f\x03\xbf\x04\x41\x03\x07\xc1\x06\x01\x41\x03\x07",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_23_consts_4_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_19_varnames_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_23_consts_4_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 7,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x20\x20\x20\x20\x80",
};
static struct PyCodeObject toplevel_consts_23_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_23_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 31,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 203,
    .co_code = & toplevel_consts_23_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_4_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_23_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_23_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_consts_2.ob_base.ob_base,
            & toplevel_consts_21_consts_1_consts_3._object.ob_base.ob_base,
            & toplevel_consts_23_consts_4.ob_base,
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
toplevel_consts_23_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
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
toplevel_consts_23_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_23_consts_4_name._ascii.ob_base,
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
    ._data = "module_for_loader",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_23_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x12\x04\x02\x06\xfe\x08\x03\x08\x01\x02\xff\x02\x01\x04\x0f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_23_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x04\x12\x02\x01\x0a\x01\x08\x01\x08\x0e\x02\xf2\x02\x0e\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_23_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x05\x0d\x05\x12\x13\x48\x13\x25\x32\x33\x05\x34\x05\x34\x05\x34\x06\x0f\x06\x15\x16\x19\x06\x1a\x05\x36\x05\x36\x05\x36\x05\x36\x06\x1a\x05\x36\x0c\x25\x05\x25",
};
static struct PyCodeObject toplevel_consts_23 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 182,
    .co_code = & toplevel_consts_23_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_21_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_21_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_24_code = {
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_24_consts_0 = {
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
    ._data = "_LazyModule",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[76];
    }
toplevel_consts_24_consts_1 = {
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
    ._data = "A subclass of the module type which triggers loading upon attribute access.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[199];
    }
toplevel_consts_24_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 198,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7c\x00\x5f\x02\x7c\x00\x6a\x03\x6a\x04\x7d\x02\x7c\x00\x6a\x03\x6a\x05\x64\x01\x19\x00\x7d\x03\x7c\x00\x6a\x06\x7d\x04\x69\x00\x7d\x05\x7c\x04\xa0\x07\xa8\x00\xa9\x00\x44\x00\x5d\x1d\x5c\x02\x7d\x06\x7d\x07\x7c\x06\x7c\x03\x76\x01\x72\x26\x7c\x07\x7c\x05\x7c\x06\x3c\x00\x71\x19\x74\x08\x7c\x04\x7c\x06\x19\x00\xa9\x01\x74\x08\x7c\x03\x7c\x06\x19\x00\xa9\x01\x6b\x03\x72\x36\x7c\x07\x7c\x05\x7c\x06\x3c\x00\x71\x19\x7c\x00\x6a\x03\x6a\x09\xa0\x0a\x7c\x00\xa8\x01\xa9\x01\x01\x00\x7c\x02\x74\x0b\x6a\x0c\x76\x00\x72\x57\x74\x08\x7c\x00\xa9\x01\x74\x08\x74\x0b\x6a\x0c\x7c\x02\x19\x00\xa9\x01\x6b\x03\x72\x57\x74\x0d\x64\x02\x7c\x02\x9b\x02\x64\x03\x9d\x03\xa9\x01\x82\x01\x7c\x00\x6a\x06\xa0\x0e\x7c\x05\xa8\x01\xa9\x01\x01\x00\x74\x0f\x7c\x00\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[57];
    }
toplevel_consts_24_consts_2_consts_0 = {
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
    ._data = "Trigger the load of the module and return the attribute.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_24_consts_2_consts_1 = {
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
        uint8_t _data[19];
    }
toplevel_consts_24_consts_2_consts_2 = {
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
    ._data = "module object for ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_24_consts_2_consts_3 = {
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
    ._data = " substituted in sys.modules during a lazy load",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_24_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_consts_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_2._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_consts_2_names_0 = {
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
    ._data = "types",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_24_consts_2_names_1 = {
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
    ._data = "ModuleType",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_24_consts_2_names_2 = {
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
        uint8_t _data[13];
    }
toplevel_consts_24_consts_2_names_5 = {
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
    ._data = "loader_state",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_24_consts_2_names_7 = {
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
        uint8_t _data[3];
    }
toplevel_consts_24_consts_2_names_8 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_2_names_9 = {
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
        uint8_t _data[12];
    }
toplevel_consts_24_consts_2_names_10 = {
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
    ._data = "exec_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_24_consts_2_names_14 = {
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
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_24_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_17_varnames_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_7._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_8._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_10._ascii.ob_base,
            & toplevel_consts_18_names_0._ascii.ob_base,
            & toplevel_consts_18_names_1._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_14._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_consts_2_varnames_1 = {
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
    ._data = "attr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_24_consts_2_varnames_2 = {
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
    ._data = "original_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_24_consts_2_varnames_3 = {
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
    ._data = "attrs_then",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_24_consts_2_varnames_4 = {
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
    ._data = "attrs_now",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_24_consts_2_varnames_5 = {
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
    ._data = "attrs_updated",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_24_consts_2_varnames_6 = {
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
toplevel_consts_24_consts_2_varnames_7 = {
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
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_24_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_3._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_4._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_6._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_24_consts_2_name = {
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
    ._data = "__getattribute__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_24_consts_2_qualname = {
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
    ._data = "_LazyModule.__getattribute__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_24_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x05\x08\x03\x0c\x03\x06\x01\x04\x01\x12\x01\x08\x03\x0a\x01\x18\x01\x08\x01\x02\x80\x10\x01\x0a\x03\x16\x01\x10\x01\x0e\x05\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_24_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x05\x08\x03\x0c\x03\x06\x01\x04\x01\x08\x01\x04\x06\x06\xfa\x06\x03\x02\x03\x0a\xfe\x16\x01\x0a\x01\x02\x80\x10\x01\x08\x03\x02\x04\x14\xfd\x02\x03\x02\xfe\x02\x02\x02\xfe\x0a\x02\x0e\x03\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[199];
    }
toplevel_consts_24_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 198,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1a\x1f\x1a\x2a\x09\x0d\x09\x17\x19\x1d\x19\x26\x19\x2b\x09\x16\x16\x1a\x16\x23\x16\x30\x31\x3b\x16\x3c\x09\x13\x15\x19\x15\x22\x09\x12\x19\x1b\x09\x16\x1b\x24\x1b\x2c\x1b\x2c\x1b\x2c\x09\x2b\x09\x2b\x0d\x17\x0d\x10\x12\x17\x10\x13\x1b\x25\x10\x25\x0d\x2b\x26\x2b\x11\x1e\x1f\x22\x11\x23\x11\x23\x12\x14\x15\x1e\x1f\x22\x15\x23\x12\x24\x28\x2a\x2b\x35\x36\x39\x2b\x3a\x28\x3b\x12\x3b\x0d\x2b\x26\x2b\x11\x1e\x1f\x22\x11\x23\x00\x00\x09\x0d\x09\x16\x09\x1d\x09\x2f\x2a\x2e\x09\x2f\x09\x2f\x09\x2f\x0c\x19\x1d\x20\x1d\x28\x0c\x28\x09\x2a\x10\x12\x13\x17\x10\x18\x1c\x1e\x1f\x22\x1f\x2a\x2b\x38\x1f\x39\x1c\x3a\x10\x3a\x0d\x2a\x17\x21\x22\x29\x37\x44\x22\x29\x22\x29\x22\x29\x17\x2a\x11\x2a\x09\x0d\x09\x16\x09\x2c\x1e\x2b\x09\x2c\x09\x2c\x09\x2c\x10\x17\x18\x1c\x1e\x22\x10\x23\x09\x23",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_24_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_24_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 226,
    .co_code = & toplevel_consts_24_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_24_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_24_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x01\x00\x74\x01\x7c\x00\x7c\x01\xa9\x02\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[48];
    }
toplevel_consts_24_consts_3_consts_0 = {
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
    ._data = "Trigger the load and then perform the deletion.",
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
        uint8_t _data[8];
    }
toplevel_consts_24_consts_3_names_1 = {
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
    ._data = "delattr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_24_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
            & toplevel_consts_24_consts_3_names_1._ascii.ob_base,
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
toplevel_consts_24_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_24_consts_3_name = {
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
    ._data = "__delattr__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_24_consts_3_qualname = {
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
    ._data = "_LazyModule.__delattr__",
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
    .ob_sval = "\x02\x00\x0c\x04\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_24_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x24\x1f\x23\x09\x24\x09\x24\x09\x24\x09\x10\x11\x15\x17\x1b\x09\x1c\x09\x1c\x09\x1c\x09\x1c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_24_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_24_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 260,
    .co_code = & toplevel_consts_24_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_24_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_24_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_24_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_24_consts_1._ascii.ob_base,
            & toplevel_consts_24_consts_2.ob_base,
            & toplevel_consts_24_consts_3.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_24_names_1 = {
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
toplevel_consts_24_names_2 = {
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
        uint8_t _data[8];
    }
toplevel_consts_24_names_3 = {
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
toplevel_consts_24_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_24_names_1._ascii.ob_base,
            & toplevel_consts_24_names_2._ascii.ob_base,
            & toplevel_consts_24_names_3._ascii.ob_base,
            & toplevel_consts_24_consts_2_name._ascii.ob_base,
            & toplevel_consts_24_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_24_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x02\x0a\x22",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_24_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x22\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_24_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x56\x05\x56\x05\x23\x05\x23\x05\x23\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_24 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_24_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_24_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_24_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 222,
    .co_code = & toplevel_consts_24_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_24_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_24_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_24_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_24_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x65\x04\x64\x02\x84\x00\xa9\x01\x5a\x05\x65\x06\x64\x03\x84\x00\xa9\x01\x5a\x07\x64\x04\x84\x00\x5a\x08\x64\x05\x84\x00\x5a\x09\x64\x06\x84\x00\x5a\x0a\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_26_consts_0 = {
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
    ._data = "LazyLoader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[76];
    }
toplevel_consts_26_consts_1 = {
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
    ._data = "A loader that creates a module which defers loading until attribute access.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x64\x01\xa9\x02\x73\x0a\x74\x01\x64\x02\xa9\x01\x82\x01\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_26_consts_2_consts_2 = {
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
    ._data = "loader must define exec_module()",
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
            Py_None,
            & toplevel_consts_24_consts_2_names_10._ascii.ob_base,
            & toplevel_consts_26_consts_2_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_26_consts_2_names_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_2_names_1._ascii.ob_base,
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
toplevel_consts_26_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_26_consts_2_name = {
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
    ._data = "__check_eager_loader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_26_consts_2_qualname = {
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
    ._data = "LazyLoader.__check_eager_loader",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x17\x18\x1e\x20\x2d\x10\x2e\x09\x40\x13\x1c\x1d\x3f\x13\x40\x0d\x40\x09\x40\x09\x40",
};
static struct PyCodeObject toplevel_consts_26_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 272,
    .co_code = & toplevel_consts_26_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_26_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x87\x01\x97\x00\x89\x00\xa0\x00\x89\x01\xa8\x01\xa9\x01\x01\x00\x88\x00\x88\x01\x66\x02\x64\x01\x84\x08\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[63];
    }
toplevel_consts_26_consts_3_consts_0 = {
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
    ._data = "Construct a callable which returns the eager loader made lazy.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_26_consts_3_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x02\x97\x00\x89\x02\x89\x03\x7c\x00\x69\x00\x7c\x01\xa4\x01\x8e\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_3_consts_1_consts = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_3_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_26_consts_3_consts_1_freevars_0 = {
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
toplevel_consts_26_consts_3_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_3_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_3_consts_1_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[37];
    }
toplevel_consts_26_consts_3_consts_1_qualname = {
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
    ._data = "LazyLoader.factory.<locals>.<lambda>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_26_consts_3_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x14\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_26_consts_3_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x28\x2b\x2c\x32\x34\x38\x2c\x43\x3c\x42\x2c\x43\x2c\x43\x28\x44\x01\x01",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_26_consts_3_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_26_consts_3_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_26_consts_3_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_26_consts_3_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_3_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_3_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 31,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 281,
    .co_code = & toplevel_consts_26_consts_3_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_3_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_consts_3_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_3_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_3_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_3_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_3_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_3_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_26_consts_3_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_26_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_3_consts_1.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_26_consts_3_names_0 = {
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
    ._data = "_LazyLoader__check_eager_loader",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_26_consts_3_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_consts_3_name = {
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
    ._data = "factory",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_26_consts_3_qualname = {
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
    ._data = "LazyLoader.factory",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_26_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x0c\x03\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_26_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x09\x0c\x09\x29\x22\x28\x09\x29\x09\x29\x09\x29\x10\x44\x10\x44\x10\x44\x10\x44\x10\x44\x09\x44",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_26_consts_3_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 2,
    },
    .ob_shash = -1,
    .ob_sval = "``",
};
static struct PyCodeObject toplevel_consts_26_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 277,
    .co_code = & toplevel_consts_26_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_26_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_26_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_26_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x7c\x01\xa8\x01\xa9\x01\x01\x00\x7c\x01\x7c\x00\x5f\x01\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_26_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
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
toplevel_consts_26_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_26_consts_4_name = {
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
        uint8_t _data[20];
    }
toplevel_consts_26_consts_4_qualname = {
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
    ._data = "LazyLoader.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_26_consts_4_linetable = {
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
toplevel_consts_26_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x2a\x23\x29\x09\x2a\x09\x2a\x09\x2a\x17\x1d\x09\x0d\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_26_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_3_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 283,
    .co_code = & toplevel_consts_26_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_24_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_26_consts_5_code = {
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
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_26_consts_5_names_1 = {
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
    ._data = "create_module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_26_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
            & toplevel_consts_26_consts_5_names_1._ascii.ob_base,
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
toplevel_consts_26_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_18_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_26_consts_5_qualname = {
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
    ._data = "LazyLoader.create_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_26_consts_5_linetable = {
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
toplevel_consts_26_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x1b\x10\x2f\x2a\x2e\x10\x2f\x10\x2f\x09\x2f",
};
static struct PyCodeObject toplevel_consts_26_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_3_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 287,
    .co_code = & toplevel_consts_26_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_24_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_5_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_26_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7c\x01\x6a\x01\x5f\x00\x7c\x00\x6a\x00\x7c\x01\x5f\x02\x69\x00\x7d\x02\x7c\x01\x6a\x03\xa0\x04\xa8\x00\xa9\x00\x7c\x02\x64\x01\x3c\x00\x7c\x01\x6a\x05\x7c\x02\x64\x02\x3c\x00\x7c\x02\x7c\x01\x6a\x01\x5f\x06\x74\x07\x7c\x01\x5f\x05\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_26_consts_6_consts_0 = {
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
    ._data = "Make the module load lazily.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_26_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_26_consts_6_consts_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_2._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_26_consts_6_names_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_26_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_24_consts_2_names_9._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_22_consts_1_consts_4._ascii.ob_base,
            & toplevel_consts_24_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_26_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_24_consts_0._ascii.ob_base,
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
toplevel_consts_26_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_22_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_26_consts_6_qualname = {
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
    ._data = "LazyLoader.exec_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_26_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x08\x01\x04\x05\x10\x01\x0a\x01\x08\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_26_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x22\x26\x22\x2d\x09\x0f\x09\x18\x09\x1f\x1d\x21\x1d\x28\x09\x0f\x09\x1a\x18\x1a\x09\x15\x24\x2a\x24\x33\x24\x3a\x24\x3a\x24\x3a\x09\x15\x16\x20\x09\x21\x25\x2b\x25\x35\x09\x15\x16\x21\x09\x22\x28\x34\x09\x0f\x09\x18\x09\x25\x1c\x27\x09\x0f\x09\x19\x09\x19\x09\x19",
};
static struct PyCodeObject toplevel_consts_26_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 290,
    .co_code = & toplevel_consts_26_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_20_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_24_consts_2_names_10._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_1._ascii.ob_base,
            & toplevel_consts_26_consts_2.ob_base,
            & toplevel_consts_26_consts_3.ob_base,
            & toplevel_consts_26_consts_4.ob_base,
            & toplevel_consts_26_consts_5.ob_base,
            & toplevel_consts_26_consts_6.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26_names_4 = {
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
    ._data = "staticmethod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_26_names_6 = {
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
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_21_consts_1_names_4._ascii.ob_base,
            & toplevel_consts_24_names_1._ascii.ob_base,
            & toplevel_consts_24_names_2._ascii.ob_base,
            & toplevel_consts_24_names_3._ascii.ob_base,
            & toplevel_consts_26_names_4._ascii.ob_base,
            & toplevel_consts_26_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_26_names_6._ascii.ob_base,
            & toplevel_consts_26_consts_3_name._ascii.ob_base,
            & toplevel_consts_26_consts_4_name._ascii.ob_base,
            & toplevel_consts_26_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_10._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x01\x02\xff\x02\x01\x02\x04\x04\x01\x02\xff\x02\x01\x06\x05\x06\x04\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x02\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x04\x04\x02\xfc\x02\x04\x06\x04\x06\x03\x0a\x0e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x56\x05\x56\x06\x12\x05\x40\x05\x40\x06\x12\x05\x40\x06\x11\x05\x44\x05\x44\x06\x11\x05\x44\x05\x1d\x05\x1d\x05\x1d\x05\x2f\x05\x2f\x05\x2f\x05\x27\x05\x27\x05\x27\x05\x27\x05\x27",
};
static struct PyCodeObject toplevel_consts_26 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_26_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_26_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_26_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 268,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
    .co_name = & toplevel_consts_26_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_26_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_2._object.ob_base.ob_base,
            & toplevel_consts_3._object.ob_base.ob_base,
            & toplevel_consts_4._object.ob_base.ob_base,
            & toplevel_consts_5._object.ob_base.ob_base,
            & toplevel_consts_6._object.ob_base.ob_base,
            & toplevel_consts_7._object.ob_base.ob_base,
            & toplevel_consts_8._object.ob_base.ob_base,
            & toplevel_consts_9._object.ob_base.ob_base,
            & toplevel_consts_10._object.ob_base.ob_base,
            & toplevel_consts_11._object.ob_base.ob_base,
            & toplevel_consts_12._object.ob_base.ob_base,
            & toplevel_consts_13.ob_base.ob_base,
            & toplevel_consts_14._object.ob_base.ob_base,
            Py_None,
            & toplevel_consts_16.ob_base,
            & toplevel_consts_17.ob_base,
            & toplevel_consts_18.ob_base,
            & toplevel_consts_19.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_21.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_23.ob_base,
            & toplevel_consts_24.ob_base,
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_26_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_3_consts_1_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_names_1 = {
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
    ._data = "_abc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_names_3 = {
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
    ._data = "_bootstrap",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_names_8 = {
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
    ._data = "_bootstrap_external",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_names_15 = {
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
    ._data = "contextlib",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[33];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 33,
        },
        .ob_item = {
            & toplevel_consts_24_names_3._ascii.ob_base,
            & toplevel_names_1._ascii.ob_base,
            & toplevel_consts_2_0._ascii.ob_base,
            & toplevel_names_3._ascii.ob_base,
            & toplevel_consts_3_0._ascii.ob_base,
            & toplevel_consts_4_0._ascii.ob_base,
            & toplevel_consts_5_0._ascii.ob_base,
            & toplevel_consts_6_0._ascii.ob_base,
            & toplevel_names_8._ascii.ob_base,
            & toplevel_consts_7_0._ascii.ob_base,
            & toplevel_consts_8_0._ascii.ob_base,
            & toplevel_consts_9_0._ascii.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_11_0._ascii.ob_base,
            & toplevel_consts_12_0._ascii.ob_base,
            & toplevel_names_15._ascii.ob_base,
            & toplevel_consts_14_0._ascii.ob_base,
            & toplevel_consts_16_names_0._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_18_names_0._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_21_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_16_names_1._ascii.ob_base,
            & toplevel_consts_17_name._ascii.ob_base,
            & toplevel_consts_18_name._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_22_name._ascii.ob_base,
            & toplevel_consts_23_name._ascii.ob_base,
            & toplevel_consts_24_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_24_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_0._ascii.ob_base,
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
    .ob_sval = "\x02\x80\x04\x00\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x02\x08\x01\x08\x01\x08\x01\x08\x01\x08\x01\x06\x03\x06\x05\x08\x0f\x08\x1f\x02\x2d\x04\x01\x02\xff\x02\x01\x06\x19\x06\x14\x06\x12\x10\x28\x12\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[77];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 76,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x02\x08\x01\x08\x01\x08\x01\x08\x01\x08\x01\x06\x05\x06\x0f\x02\x03\x06\x1c\x02\x03\x06\x2a\x02\x03\x04\x17\x02\xe9\x02\x17\x06\x14\x06\x12\x06\x28\x08\x2e\x04\xd5\x04\x2b\x08\x25\x02\xde\x08\x22",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[281];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 280,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x34\x01\x34\x01\x19\x01\x19\x01\x19\x01\x19\x01\x19\x01\x19\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x2e\x01\x2e\x01\x2e\x01\x2e\x01\x2e\x01\x2e\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x2f\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x33\x01\x39\x01\x39\x01\x39\x01\x39\x01\x39\x01\x39\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x26\x01\x0c\x01\x0c\x01\x0c\x01\x0c\x01\x11\x01\x11\x01\x11\x01\x11\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x0d\x01\x0d\x01\x0d\x01\x0d\x01\x10\x01\x10\x01\x10\x01\x10\x01\x3d\x01\x3d\x01\x3d\x01\x37\x01\x37\x01\x37\x25\x29\x01\x18\x01\x18\x01\x18\x1d\x21\x01\x18\x01\x18\x01\x18\x02\x10\x01\x28\x01\x28\x02\x10\x01\x28\x01\x1f\x01\x1f\x01\x1f\x01\x1e\x01\x1e\x01\x1e\x01\x25\x01\x25\x01\x25\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x13\x18\x13\x23\x01\x1c\x01\x1c\x01\x27\x01\x27\x01\x27\x01\x27\x12\x18\x01\x27\x01\x27\x01\x27\x01\x27",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_16_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_16_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_16_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_importlib_util_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

