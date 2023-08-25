#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x47\x00\x64\x03\x84\x00\x64\x04\x65\x02\xa9\x03\x5a\x03\x47\x00\x64\x05\x84\x00\x64\x06\x65\x02\xa9\x03\x5a\x04\x47\x00\x64\x07\x84\x00\x64\x08\x65\x02\xa9\x03\x5a\x05\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[62];
    }
toplevel_consts_0 = {
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
    ._data = "\x0a\x54\x68\x65\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x75\x73\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x73\x69\x74\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x74\x6f\x20\x61\x64\x64\x20\x63\x75\x73\x74\x6f\x6d\x20\x62\x75\x69\x6c\x74\x69\x6e\x73\x2e\x0a",
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
        char ob_sval[35];
    }
toplevel_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x84\x00\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x05\x64\x04\x84\x01\x5a\x05\x64\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_consts_0 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_3_consts_1_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_3_consts_1_consts = {
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
        uint8_t _data[5];
    }
toplevel_consts_3_consts_1_names_0 = {
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
        uint8_t _data[4];
    }
toplevel_consts_3_consts_1_names_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_3_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_3_consts_1_varnames_0 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_3_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_names_1._ascii.ob_base,
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
toplevel_consts_3_consts_1_freevars = {
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
        uint8_t _data[23];
    }
toplevel_consts_3_consts_1_filename = {
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
    ._data = "<frozen _sitebuiltins>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_3_consts_1_name = {
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
        uint8_t _data[17];
    }
toplevel_consts_3_consts_1_qualname = {
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
    ._data = "Quitter.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_3_consts_1_linetable = {
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
toplevel_consts_3_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x19\x09\x0d\x09\x12\x14\x17\x09\x0d\x09\x11\x09\x11\x09\x11",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_3_consts_1_exceptiontable = {
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
        char ob_sval[4];
    }
toplevel_consts_3_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_3_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 14,
    .co_code = & toplevel_consts_3_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_3_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7c\x00\x6a\x00\x9b\x01\x64\x02\x7c\x00\x6a\x01\x9b\x01\x64\x03\x9d\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_3_consts_2_consts_1 = {
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
    ._data = "Use ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_3_consts_2_consts_2 = {
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
    ._data = "() or ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_3_consts_2_consts_3 = {
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
    ._data = " to exit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_3_consts_2_consts = {
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
            & toplevel_consts_3_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_3_consts_2_consts_2._ascii.ob_base,
            & toplevel_consts_3_consts_2_consts_3._ascii.ob_base,
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
toplevel_consts_3_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_3_consts_2_name = {
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
        uint8_t _data[17];
    }
toplevel_consts_3_consts_2_qualname = {
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
    ._data = "Quitter.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_3_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x00\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_3_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x2c\x30\x2c\x35\x2c\x35\x2c\x35\x37\x3b\x37\x3f\x37\x3f\x37\x3f\x10\x40\x09\x40",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_3_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_3_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 17,
    .co_code = & toplevel_consts_3_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_3_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x74\x00\x6a\x01\xa0\x02\xa8\x00\xa9\x00\x01\x00\x74\x03\x7c\x01\xa9\x01\x82\x01\x23\x00\x01\x00\x59\x00\x74\x03\x7c\x01\xa9\x01\x82\x01\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_3_consts_4_names_0 = {
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
toplevel_consts_3_consts_4_names_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_3_consts_4_names_2 = {
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
        uint8_t _data[11];
    }
toplevel_consts_3_consts_4_names_3 = {
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
    ._data = "SystemExit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_3_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_3_consts_4_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_3_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_3_consts_4_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_3_consts_4_varnames_1 = {
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
    ._data = "code",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_3_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_3_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_3_consts_4_name = {
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
        uint8_t _data[17];
    }
toplevel_consts_3_consts_4_qualname = {
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
    ._data = "Quitter.__call__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_3_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x03\x0c\x01\x08\x03\x02\x80\x02\xfe\x02\x01\x08\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_3_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x06\x0c\xfe\x08\x03\x02\x80\x04\xff\x08\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_3_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x11\x0d\x10\x0d\x16\x0d\x1e\x0d\x1e\x0d\x1e\x0d\x1e\x0f\x19\x1a\x1e\x0f\x1f\x09\x1f\x00\x00\x09\x11\x0d\x11\x0f\x19\x1a\x1e\x0f\x1f\x09\x1f\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_3_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x06\x0c\x00\x8c\x02\x13\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_3_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_3_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 19,
    .co_code = & toplevel_consts_3_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_3_consts_1.ob_base,
            & toplevel_consts_3_consts_2.ob_base,
            Py_None,
            & toplevel_consts_3_consts_4.ob_base,
            & toplevel_consts_3_consts_1_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_3_names_0 = {
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
toplevel_consts_3_names_1 = {
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
toplevel_consts_3_names_2 = {
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
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_3_consts_1_name._ascii.ob_base,
            & toplevel_consts_3_consts_2_name._ascii.ob_base,
            & toplevel_consts_3_consts_4_name._ascii.ob_base,
        },
    },
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
    .ob_sval = "\x0a\x00\x06\x01\x06\x03\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x03\x06\x02\x02\x01\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x17\x05\x17\x05\x17\x05\x40\x05\x40\x05\x40\x1d\x21\x05\x1f\x05\x1f\x05\x1f\x05\x1f\x05\x1f",
};
static struct PyCodeObject toplevel_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 13,
    .co_code = & toplevel_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x64\x09\x64\x04\x84\x01\x5a\x05\x64\x05\x84\x00\x5a\x06\x64\x06\x84\x00\x5a\x07\x64\x07\x84\x00\x5a\x08\x64\x08\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_consts_0 = {
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
        uint8_t _data[111];
    }
toplevel_consts_5_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 110,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x69\x6e\x74\x65\x72\x61\x63\x74\x69\x76\x65\x20\x70\x72\x6f\x6d\x70\x74\x20\x6f\x62\x6a\x65\x63\x74\x73\x20\x66\x6f\x72\x20\x70\x72\x69\x6e\x74\x69\x6e\x67\x20\x74\x68\x65\x20\x6c\x69\x63\x65\x6e\x73\x65\x20\x74\x65\x78\x74\x2c\x20\x61\x20\x6c\x69\x73\x74\x20\x6f\x66\x0a\x20\x20\x20\x20\x63\x6f\x6e\x74\x72\x69\x62\x75\x74\x6f\x72\x73\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x63\x6f\x70\x79\x72\x69\x67\x68\x74\x20\x6e\x6f\x74\x69\x63\x65\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_5_consts_2 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = 1,
    },
    .ob_digit = { 23 },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_5_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x03\x87\x05\x97\x00\x64\x01\x64\x00\x6c\x00\x8a\x05\x7c\x01\x7c\x00\x5f\x01\x7c\x02\x7c\x00\x5f\x02\x64\x00\x7c\x00\x5f\x03\x88\x03\x88\x05\x66\x02\x64\x02\x84\x08\x7c\x04\x44\x00\xa9\x01\x7c\x00\x5f\x04\x64\x00\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_5_consts_4_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x02\x97\x00\x67\x00\x7c\x00\x5d\x0f\x7d\x01\x89\x03\x44\x00\x5d\x0a\x7d\x02\x89\x04\x6a\x00\xa0\x01\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x91\x03\x71\x08\x71\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_consts_4_consts_2_names_0 = {
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
toplevel_consts_5_consts_4_consts_2_names_1 = {
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
toplevel_consts_5_consts_4_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_5_consts_4_consts_2_varnames_0 = {
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
        uint8_t _data[4];
    }
toplevel_consts_5_consts_4_consts_2_varnames_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_consts_4_consts_2_varnames_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_5_consts_4_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_consts_4_consts_2_freevars_0 = {
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
        uint8_t _data[3];
    }
toplevel_consts_5_consts_4_consts_2_freevars_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_4_consts_2_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_consts_2_freevars_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_consts_4_consts_2_name = {
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
toplevel_consts_5_consts_4_consts_2_qualname = {
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
    ._data = "_Printer.__init__.<locals>.<listcomp>",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_5_consts_4_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x08\x00\x02\x01\x02\x01\x04\xfe\x02\x02\x16\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_5_consts_4_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x02\x02\xff\x08\x01\x0e\xfe\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_5_consts_4_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x1c\x33\x1c\x33\x1c\x33\x21\x24\x2d\x32\x1c\x33\x1c\x33\x21\x29\x1d\x1f\x1d\x24\x1d\x38\x2a\x2d\x2f\x37\x1d\x38\x1d\x38\x1c\x33\x1c\x33\x1c\x33\x1c\x33",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_5_consts_4_consts_2_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_5_consts_4_consts_2_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 5,
    },
    .ob_shash = -1,
    .ob_sval = "\x20\x20\x20\x80\x80",
};
static struct PyCodeObject toplevel_consts_5_consts_4_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_4_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_4_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 40,
    .co_code = & toplevel_consts_5_consts_4_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_4_consts_2_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_4_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_4_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_4_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_4_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_4_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_4_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 2,
    .co_varnames = & toplevel_consts_5_consts_4_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_4_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_5_consts_4_consts = {
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
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_5_consts_4_consts_2.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_consts_4_names_1 = {
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
    ._data = "_Printer__name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_consts_4_names_2 = {
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
    ._data = "_Printer__data",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_5_consts_4_names_3 = {
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
    ._data = "_Printer__lines",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_5_consts_4_names_4 = {
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
    ._data = "_Printer__filenames",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_5_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_consts_2_freevars_1._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_consts_4_varnames_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_5_consts_4_varnames_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_5_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_5_consts_4_qualname = {
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
    ._data = "_Printer.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_5_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x06\x01\x06\x01\x06\x01\x0a\x01\x02\x01\x0c\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_5_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x04\x80\x02\x00\x08\x01\x06\x01\x06\x01\x06\x01\x0a\x03\x02\xff\x04\x01\x08\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_5_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x00\x00\x01\x01\x09\x12\x09\x12\x09\x12\x09\x12\x17\x1b\x09\x0d\x09\x14\x17\x1b\x09\x0d\x09\x14\x18\x1c\x09\x0d\x09\x15\x1c\x33\x1c\x33\x1c\x33\x1c\x33\x1c\x33\x28\x2c\x1c\x33\x1c\x33\x09\x0d\x09\x19\x09\x19\x09\x19",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_5_consts_4_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_4._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_freevars_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_5_consts_4_localspluskinds = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "   ` @",
};
static struct PyCodeObject toplevel_consts_5_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 5,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 35,
    .co_code = & toplevel_consts_5_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_4_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 5,
    .co_nplaincellvars = 1,
    .co_ncellvars = 2,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_4_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_5_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x72\x06\x64\x00\x53\x00\x64\x00\x7d\x01\x7c\x00\x6a\x01\x44\x00\x5d\x2b\x7d\x02\x09\x00\x74\x02\x7c\x02\x64\x01\x64\x02\xaa\x02\x35\x00\x7d\x03\x7c\x03\xa0\x03\xa8\x00\xa9\x00\x7d\x01\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x27\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x01\x00\x6e\x0a\x23\x00\x74\x04\x79\x33\x01\x00\x59\x00\x71\x0b\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x73\x3c\x7c\x00\x6a\x05\x7d\x01\x7c\x01\xa0\x06\x64\x03\xa8\x01\xa9\x01\x7c\x00\x5f\x00\x74\x07\x7c\x00\x6a\x00\xa9\x01\x7c\x00\x5f\x08\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_consts_5_consts_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_5_consts_5_consts_2_0 = {
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
toplevel_consts_5_consts_5_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_5_consts_5_consts_2_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_5_consts_5_consts_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_5_consts_5_consts = {
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
            & toplevel_consts_5_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_5_consts_5_consts_2._object.ob_base.ob_base,
            & toplevel_consts_5_consts_5_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_consts_5_names_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_5_consts_5_names_3 = {
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
        uint8_t _data[8];
    }
toplevel_consts_5_consts_5_names_4 = {
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
toplevel_consts_5_consts_5_names_6 = {
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
        uint8_t _data[4];
    }
toplevel_consts_5_consts_5_names_7 = {
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
        uint8_t _data[18];
    }
toplevel_consts_5_consts_5_names_8 = {
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
    ._data = "_Printer__linecnt",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_5_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_5_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_5_consts_5_varnames_3 = {
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
    ._data = "fp",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_5_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_5_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_consts_5_name = {
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
    ._data = "__setup",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_5_consts_5_qualname = {
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
    ._data = "_Printer.__setup",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_5_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x04\x01\x04\x01\x0a\x01\x02\x01\x0e\x01\x0a\x01\x14\xff\x06\x80\x08\x00\x04\x02\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x04\x02\x06\x01\x0e\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_5_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x06\x01\x04\x01\x04\x01\x04\x06\x02\xfa\x02\x06\x0a\xfc\x02\x01\x02\xff\x1e\x01\x06\x80\x08\x00\x04\x01\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x01\x08\x01\x0e\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_5_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x18\x09\x13\x0d\x13\x0d\x13\x10\x14\x09\x0d\x19\x1d\x19\x29\x09\x15\x09\x15\x0d\x15\x0d\x15\x16\x1a\x1b\x23\x2e\x35\x16\x36\x16\x36\x11\x25\x3a\x3c\x1c\x1e\x1c\x25\x1c\x25\x1c\x25\x15\x19\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x11\x25\x00\x00\x00\x00\x00\x00\x11\x25\x11\x25\x11\x25\x11\x25\x11\x16\x11\x16\x00\x00\x14\x1b\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x10\x14\x09\x1f\x14\x18\x14\x1f\x0d\x11\x18\x1c\x18\x28\x23\x27\x18\x28\x18\x28\x09\x0d\x09\x15\x1a\x1d\x1e\x22\x1e\x2a\x1a\x2b\x09\x0d\x09\x17\x09\x17\x09\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_5_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x8e\x06\x2d\x02\x94\x06\x20\x05\x9a\x06\x2d\x02\xa0\x04\x24\x09\xa4\x03\x2d\x02\xa7\x01\x24\x09\xa8\x03\x2d\x02\xad\x04\x34\x05\xb3\x01\x34\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_5_consts_5_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_5_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 44,
    .co_code = & toplevel_consts_5_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_5_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x74\x01\x7c\x00\x6a\x02\xa9\x01\x7c\x00\x6a\x03\x6b\x01\x72\x15\x64\x01\xa0\x04\x7c\x00\x6a\x02\xa8\x01\xa9\x01\x53\x00\x64\x02\x7c\x00\x6a\x05\x66\x01\x64\x03\x7a\x05\x7a\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[34];
    }
toplevel_consts_5_consts_6_consts_2 = {
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
    ._data = "Type %s() to see the full %s text",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_5_consts_6_consts_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_5_consts_6_consts = {
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
            & toplevel_consts_5_consts_5_consts_3._ascii.ob_base,
            & toplevel_consts_5_consts_6_consts_2._ascii.ob_base,
            & toplevel_consts_5_consts_6_consts_3.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_5_consts_6_names_0 = {
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
    ._data = "_Printer__setup",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_consts_6_names_3 = {
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
    ._data = "MAXLINES",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_5_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_5_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_5_names_7._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_6_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_4_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_5_consts_6_qualname = {
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
    ._data = "_Printer.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_5_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x10\x01\x0e\x01\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0e\x01\x02\x03\x0e\xfe\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_5_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x17\x09\x17\x09\x17\x09\x17\x0c\x0f\x10\x14\x10\x1c\x0c\x1d\x21\x25\x21\x2e\x0c\x2e\x09\x4c\x14\x18\x14\x2b\x1e\x22\x1e\x2a\x14\x2b\x14\x2b\x0d\x2b\x14\x37\x3c\x40\x3c\x47\x3b\x49\x4a\x4b\x3b\x4b\x14\x4c\x0d\x4c",
};
static struct PyCodeObject toplevel_consts_5_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 60,
    .co_code = & toplevel_consts_5_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[141];
    }
toplevel_consts_5_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 140,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\xa8\x00\xa9\x00\x01\x00\x64\x01\x7d\x01\x64\x02\x7d\x02\x09\x00\x09\x00\x74\x01\x7c\x02\x7c\x02\x7c\x00\x6a\x02\x7a\x00\xa9\x02\x44\x00\x5d\x09\x7d\x03\x74\x03\x7c\x00\x6a\x04\x7c\x03\x19\x00\xa9\x01\x01\x00\x71\x14\x6e\x0b\x23\x00\x74\x05\x79\x26\x01\x00\x59\x00\x64\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x7c\x00\x6a\x02\x7a\x0d\x7d\x02\x64\x00\x7d\x04\x7c\x04\x80\x3f\x74\x06\x7c\x01\xa9\x01\x7d\x04\x7c\x04\x64\x04\x76\x01\x72\x3d\x64\x00\x7d\x04\x7c\x04\x81\x33\x7c\x04\x64\x05\x6b\x02\x72\x45\x64\x00\x53\x00\x71\x0b",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_5_consts_7_consts_1 = {
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
    ._data = "Hit Return for more, or q (and Return) to quit: ",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_5_consts_7_consts_3 = {
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
        uint8_t _data[1];
    }
toplevel_consts_5_consts_7_consts_4_0 = {
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
        uint8_t _data[2];
    }
toplevel_consts_5_consts_7_consts_4_1 = {
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
    ._data = "q",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_7_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_7_consts_4_0._ascii.ob_base,
            & toplevel_consts_5_consts_7_consts_4_1._ascii.ob_base,
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
toplevel_consts_5_consts_7_consts = {
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
            & toplevel_consts_5_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_5_consts_7_consts_3.ob_base.ob_base,
            & toplevel_consts_5_consts_7_consts_4._object.ob_base.ob_base,
            & toplevel_consts_5_consts_7_consts_4_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_consts_7_names_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_consts_7_names_3 = {
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
        uint8_t _data[11];
    }
toplevel_consts_5_consts_7_names_5 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_5_consts_7_names_6 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_5_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_7_names_1._ascii.ob_base,
            & toplevel_consts_5_consts_6_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_4_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_7_names_5._ascii.ob_base,
            & toplevel_consts_5_consts_7_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_consts_7_varnames_1 = {
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
    ._data = "prompt",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_consts_7_varnames_2 = {
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
    ._data = "lineno",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_5_consts_7_varnames_3 = {
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
        uint8_t _data[4];
    }
toplevel_consts_5_consts_7_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_5_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_7_varnames_1._ascii.ob_base,
            & toplevel_consts_5_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_7_varnames_3._ascii.ob_base,
            & toplevel_consts_5_consts_7_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_5_consts_7_qualname = {
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
    ._data = "_Printer.__call__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_5_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x04\x01\x02\x01\x02\x01\x14\x01\x10\x01\x02\xff\x02\x80\x06\x02\x06\x01\x02\xff\x06\x80\x0a\x03\x04\x01\x04\x01\x08\x01\x08\x01\x04\x01\x04\xfd\x08\x04\x04\x01\x02\xf2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_5_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x04\x01\x02\x01\x02\x0e\x0e\xf4\x04\x01\x02\xff\x12\x01\x02\x80\x02\x01\x0c\x01\x06\x80\x0a\x02\x04\x01\x02\x01\x02\x03\x08\xfe\x06\x01\x06\x01\x02\xfd\x02\x03\x06\x01\x06\x01\x02\xf2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[141];
    }
toplevel_consts_5_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 140,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x17\x09\x17\x09\x17\x09\x17\x12\x44\x09\x0f\x12\x13\x09\x0f\x0f\x10\x0d\x1a\x1a\x1f\x20\x26\x28\x2e\x31\x35\x31\x3e\x28\x3e\x1a\x3f\x11\x2b\x11\x2b\x15\x16\x15\x1a\x1b\x1f\x1b\x27\x28\x29\x1b\x2a\x15\x2b\x15\x2b\x15\x2b\x11\x2b\x00\x00\x14\x1e\x0d\x16\x0d\x16\x11\x16\x11\x16\x11\x16\x0d\x16\x00\x00\x00\x00\x00\x00\x11\x17\x1b\x1f\x1b\x28\x11\x28\x11\x17\x17\x1b\x11\x14\x17\x1a\x11\x23\x1b\x20\x21\x27\x1b\x28\x15\x18\x18\x1b\x23\x2c\x18\x2c\x15\x23\x1f\x23\x19\x1c\x17\x1a\x11\x23\x14\x17\x1b\x1e\x14\x1e\x11\x1a\x15\x1a\x15\x1a\x0f\x10",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_consts_7_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x8c\x12\x1f\x00\x9f\x04\x27\x03\xa6\x01\x27\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_5_consts_7_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_5_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 67,
    .co_code = & toplevel_consts_5_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_9 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
            & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
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
toplevel_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_5_consts_2.ob_base.ob_base,
            & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
            & toplevel_consts_5_consts_4.ob_base,
            & toplevel_consts_5_consts_5.ob_base,
            & toplevel_consts_5_consts_6.ob_base,
            & toplevel_consts_5_consts_7.ob_base,
            Py_None,
            & toplevel_consts_5_consts_9._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_5_names_3 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_5_names = {
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
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_6_names_3._ascii.ob_base,
            & toplevel_consts_3_consts_1_name._ascii.ob_base,
            & toplevel_consts_5_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_2_name._ascii.ob_base,
            & toplevel_consts_3_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x03\x08\x02\x06\x09\x06\x10\x0a\x07",
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
    .ob_sval = "\x0a\x00\x04\x02\x04\x02\x02\x02\x06\x07\x06\x10\x06\x07\x0a\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x2e\x05\x2e\x10\x12\x05\x0d\x2a\x2c\x05\x33\x05\x33\x05\x33\x05\x2b\x05\x2b\x05\x2b\x05\x4c\x05\x4c\x05\x4c\x05\x1a\x05\x1a\x05\x1a\x05\x1a\x05\x1a",
};
static struct PyCodeObject toplevel_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 29,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_7_code = {
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
        uint8_t _data[8];
    }
toplevel_consts_7_consts_0 = {
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
        uint8_t _data[308];
    }
toplevel_consts_7_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 307,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x44\x65\x66\x69\x6e\x65\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x69\x6e\x20\x27\x68\x65\x6c\x70\x27\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x69\x73\x20\x61\x20\x77\x72\x61\x70\x70\x65\x72\x20\x61\x72\x6f\x75\x6e\x64\x20\x70\x79\x64\x6f\x63\x2e\x68\x65\x6c\x70\x20\x74\x68\x61\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x61\x20\x68\x65\x6c\x70\x66\x75\x6c\x20\x6d\x65\x73\x73\x61\x67\x65\x0a\x20\x20\x20\x20\x77\x68\x65\x6e\x20\x27\x68\x65\x6c\x70\x27\x20\x69\x73\x20\x74\x79\x70\x65\x64\x20\x61\x74\x20\x74\x68\x65\x20\x50\x79\x74\x68\x6f\x6e\x20\x69\x6e\x74\x65\x72\x61\x63\x74\x69\x76\x65\x20\x70\x72\x6f\x6d\x70\x74\x2e\x0a\x0a\x20\x20\x20\x20\x43\x61\x6c\x6c\x69\x6e\x67\x20\x68\x65\x6c\x70\x28\x29\x20\x61\x74\x20\x74\x68\x65\x20\x50\x79\x74\x68\x6f\x6e\x20\x70\x72\x6f\x6d\x70\x74\x20\x73\x74\x61\x72\x74\x73\x20\x61\x6e\x20\x69\x6e\x74\x65\x72\x61\x63\x74\x69\x76\x65\x20\x68\x65\x6c\x70\x20\x73\x65\x73\x73\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x43\x61\x6c\x6c\x69\x6e\x67\x20\x68\x65\x6c\x70\x28\x74\x68\x69\x6e\x67\x29\x20\x70\x72\x69\x6e\x74\x73\x20\x68\x65\x6c\x70\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x70\x79\x74\x68\x6f\x6e\x20\x6f\x62\x6a\x65\x63\x74\x20\x27\x74\x68\x69\x6e\x67\x27\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_7_consts_2_code = {
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
        uint8_t _data[73];
    }
toplevel_consts_7_consts_2_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 72,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "Type help() for interactive help, or help(object) for help about object.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_7_consts_2_consts = {
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
            & toplevel_consts_7_consts_2_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_7_consts_2_qualname = {
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
    ._data = "_Helper.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_7_consts_2_linetable = {
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
        char ob_sval[5];
    }
toplevel_consts_7_consts_2_endlinetable = {
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
toplevel_consts_7_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x38\x10\x38",
};
static struct PyCodeObject toplevel_consts_7_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 98,
    .co_code = & toplevel_consts_7_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_7_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x64\x00\x6c\x00\x7d\x03\x7c\x03\x6a\x01\x7c\x01\x69\x00\x7c\x02\xa4\x01\x8e\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_7_consts_3_consts = {
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
        uint8_t _data[6];
    }
toplevel_consts_7_consts_3_names_0 = {
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
    ._data = "pydoc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_3_names_1 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_7_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_3_varnames_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_7_consts_3_varnames_2 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_7_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_7_consts_3_qualname = {
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
    ._data = "_Helper.__call__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_7_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_7_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x15\x09\x15\x09\x15\x09\x15\x10\x15\x10\x1a\x1c\x20\x10\x29\x24\x28\x10\x29\x10\x29\x09\x29",
};
static struct PyCodeObject toplevel_consts_7_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 15,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 101,
    .co_code = & toplevel_consts_7_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_5_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_7_consts_2.ob_base,
            & toplevel_consts_7_consts_3.ob_base,
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
toplevel_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_3_consts_2_name._ascii.ob_base,
            & toplevel_consts_3_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x06\x09\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x08\x06\x04\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x05\x38\x05\x38\x05\x38\x05\x29\x05\x29\x05\x29\x05\x29\x05\x29",
};
static struct PyCodeObject toplevel_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 88,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_3.ob_base,
            & toplevel_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
        },
    },
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
    ._data = "object",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_3_consts_4_names_0._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
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
        char ob_sval[13];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x0a\x0e\x02\x0e\x10\x12\x3b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x02\x08\x08\x08\x0f\x02\xf3\x04\x0d\x08\x3b\x02\xc8\x04\x38\x08\x12\x02\xf1\x08\x0f",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x1f\x01\x1f\x01\x1f\x01\x1f\x0f\x15\x01\x1f\x01\x1f\x01\x1a\x01\x1a\x01\x1a\x01\x1a\x10\x16\x01\x1a\x01\x1a\x01\x29\x01\x29\x01\x29\x01\x29\x0f\x15\x01\x29\x01\x29\x01\x29\x01\x29",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_3_consts_1_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_3_consts_1_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get__sitebuiltins_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

