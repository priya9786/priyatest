#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[257];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 256,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x64\x02\x6c\x01\x5a\x01\x64\x01\x64\x02\x6c\x02\x5a\x03\x64\x01\x64\x02\x6c\x04\x5a\x03\x64\x01\x64\x02\x6c\x05\x5a\x05\x64\x01\x64\x02\x6c\x06\x5a\x06\x64\x03\x64\x04\x67\x02\x5a\x07\x65\x08\x65\x01\xa9\x01\x5a\x09\x47\x00\x64\x05\x84\x00\x64\x06\x65\x0a\xa9\x03\x5a\x0b\x47\x00\x64\x07\x84\x00\x64\x08\x65\x0a\xa9\x03\x5a\x0c\x09\x02\x09\x02\x09\x02\x64\x19\x64\x09\x84\x01\x5a\x0d\x09\x02\x09\x02\x09\x02\x64\x19\x64\x0a\x84\x01\x5a\x0e\x65\x0f\x66\x01\x64\x0b\x84\x01\x5a\x10\x47\x00\x64\x0c\x84\x00\x64\x0d\x65\x11\xa9\x03\x5a\x12\x64\x1a\x64\x0f\x84\x01\x5a\x13\x09\x02\x09\x10\x64\x1b\x64\x11\x84\x01\x5a\x14\x65\x0f\x66\x01\x64\x12\x84\x01\x5a\x15\x64\x13\x84\x00\x5a\x16\x64\x1c\x64\x14\x84\x01\x5a\x17\x65\x18\x64\x15\x6b\x02\x72\x7e\x65\x19\x65\x01\x6a\x1a\xa9\x01\x64\x16\x6b\x00\x72\x71\x65\x1b\x64\x17\x65\x01\x6a\x1c\x64\x18\xaa\x02\x01\x00\x64\x02\x53\x00\x65\x01\x6a\x1a\x64\x01\x3d\x00\x65\x13\x65\x01\x6a\x1a\x64\x01\x19\x00\xa9\x01\x01\x00\x64\x02\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[347];
    }
toplevel_consts_0 = {
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
    ._data = "\x72\x75\x6e\x70\x79\x2e\x70\x79\x20\x2d\x20\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x75\x6e\x6e\x69\x6e\x67\x20\x50\x79\x74\x68\x6f\x6e\x20\x63\x6f\x64\x65\x20\x75\x73\x69\x6e\x67\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x0a\x0a\x50\x72\x6f\x76\x69\x64\x65\x73\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x66\x6f\x72\x20\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x61\x6e\x64\x20\x72\x75\x6e\x6e\x69\x6e\x67\x20\x50\x79\x74\x68\x6f\x6e\x20\x73\x63\x72\x69\x70\x74\x73\x20\x75\x73\x69\x6e\x67\x20\x74\x68\x65\x20\x50\x79\x74\x68\x6f\x6e\x0a\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x20\x69\x6e\x73\x74\x65\x61\x64\x20\x6f\x66\x20\x74\x68\x65\x20\x6e\x61\x74\x69\x76\x65\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x2e\x0a\x0a\x54\x68\x69\x73\x20\x61\x6c\x6c\x6f\x77\x73\x20\x50\x79\x74\x68\x6f\x6e\x20\x63\x6f\x64\x65\x20\x74\x6f\x20\x70\x6c\x61\x79\x20\x6e\x69\x63\x65\x6c\x79\x20\x77\x69\x74\x68\x20\x6e\x6f\x6e\x2d\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x20\x62\x61\x73\x65\x64\x20\x50\x45\x50\x20\x33\x30\x32\x0a\x69\x6d\x70\x6f\x72\x74\x65\x72\x73\x20\x77\x68\x65\x6e\x20\x6c\x6f\x63\x61\x74\x69\x6e\x67\x20\x73\x75\x70\x70\x6f\x72\x74\x20\x73\x63\x72\x69\x70\x74\x73\x20\x61\x73\x20\x77\x65\x6c\x6c\x20\x61\x73\x20\x77\x68\x65\x6e\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x0a",
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
        uint8_t _data[11];
    }
toplevel_consts_3 = {
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
    ._data = "run_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_4 = {
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
    ._data = "run_path",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_5_consts_0 = {
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
    ._data = "_TempModule",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[68];
    }
toplevel_consts_5_consts_1 = {
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
    ._data = "Temporarily replace a module in sys.modules with an empty namespace",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_5_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x74\x01\x7c\x01\xa9\x01\x7c\x00\x5f\x02\x67\x00\x7c\x00\x5f\x03\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_5_consts_2_consts = {
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
        uint8_t _data[9];
    }
toplevel_consts_5_consts_2_names_0 = {
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
    ._data = "mod_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_5_consts_2_names_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_5_consts_2_names_2 = {
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
        uint8_t _data[14];
    }
toplevel_consts_5_consts_2_names_3 = {
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
    ._data = "_saved_module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_5_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_consts_2_varnames_0 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
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
toplevel_consts_5_consts_2_freevars = {
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
        uint8_t _data[15];
    }
toplevel_consts_5_consts_2_filename = {
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
    ._data = "<frozen runpy>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_consts_2_name = {
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
toplevel_consts_5_consts_2_qualname = {
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
    ._data = "_TempModule.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_5_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x0a\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_5_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x19\x21\x09\x0d\x09\x16\x17\x21\x22\x2a\x17\x2b\x09\x0d\x09\x14\x1e\x20\x09\x0d\x09\x1b\x09\x1b\x09\x1b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_5_consts_2_exceptiontable = {
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
toplevel_consts_5_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_5_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 28,
    .co_code = & toplevel_consts_5_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_5_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x01\x09\x00\x7c\x00\x6a\x01\xa0\x02\x74\x03\x6a\x04\x7c\x01\x19\x00\xa8\x01\xa9\x01\x01\x00\x6e\x0a\x23\x00\x74\x05\x79\x16\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x6a\x06\x74\x03\x6a\x04\x7c\x01\x3c\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_5_consts_3_names_2 = {
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
toplevel_consts_5_consts_3_names_3 = {
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
toplevel_consts_5_consts_3_names_4 = {
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
toplevel_consts_5_consts_3_names_5 = {
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
toplevel_consts_5_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_5_consts_3_name = {
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
toplevel_consts_5_consts_3_qualname = {
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
    ._data = "_TempModule.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_5_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x01\x16\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x0c\x02\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_5_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x04\x16\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_5_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x18\x14\x21\x09\x11\x09\x11\x0d\x11\x0d\x1f\x0d\x3d\x27\x2a\x27\x32\x33\x3b\x27\x3c\x0d\x3d\x0d\x3d\x0d\x3d\x0d\x3d\x00\x00\x10\x18\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x21\x25\x21\x2c\x09\x0c\x09\x14\x15\x1d\x09\x1e\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_consts_3_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x85\x0a\x10\x00\x90\x04\x17\x03\x96\x01\x17\x03",
};
static struct PyCodeObject toplevel_consts_5_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 33,
    .co_code = & toplevel_consts_5_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_5_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x72\x0e\x7c\x00\x6a\x00\x64\x01\x19\x00\x74\x01\x6a\x02\x7c\x00\x6a\x03\x3c\x00\x6e\x05\x74\x01\x6a\x02\x7c\x00\x6a\x03\x3d\x00\x67\x00\x7c\x00\x5f\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_5_consts_4_consts = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_5_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_5_consts_4_varnames_1 = {
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
toplevel_consts_5_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_5_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_consts_4_name = {
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
toplevel_consts_5_consts_4_qualname = {
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
    ._data = "_TempModule.__exit__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_5_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x14\x01\x0a\x02\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_5_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x02\x03\x14\xfe\x0a\x02\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_5_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x1e\x09\x2b\x2a\x2e\x2a\x3c\x3d\x3e\x2a\x3f\x0d\x10\x0d\x18\x19\x1d\x19\x26\x0d\x27\x0d\x27\x11\x14\x11\x1c\x1d\x21\x1d\x2a\x11\x2b\x1e\x20\x09\x0d\x09\x1b\x09\x1b\x09\x1b",
};
static struct PyCodeObject toplevel_consts_5_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 42,
    .co_code = & toplevel_consts_5_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_5_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_5_consts_2.ob_base,
            & toplevel_consts_5_consts_3.ob_base,
            & toplevel_consts_5_consts_4.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_5_names_0 = {
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
toplevel_consts_5_names_1 = {
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
toplevel_consts_5_names_2 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_2_name._ascii.ob_base,
            & toplevel_consts_5_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_consts_4_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x06\x01\x06\x05\x0a\x09",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x06\x04\x06\x09\x0a\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x4e\x05\x4e\x05\x20\x05\x20\x05\x20\x05\x14\x05\x14\x05\x14\x05\x20\x05\x20\x05\x20\x05\x20\x05\x20",
};
static struct PyCodeObject toplevel_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 26,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x84\x00\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_7_consts_0 = {
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
    ._data = "_ModifiedArgv0",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_7_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x74\x01\xa9\x00\x04\x00\x7c\x00\x5f\x02\x7c\x00\x5f\x03\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_7_consts_1_names_0 = {
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
        uint8_t _data[7];
    }
toplevel_consts_7_consts_1_names_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_7_consts_1_names_2 = {
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
    ._data = "_saved_value",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_7_consts_1_names_3 = {
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
    ._data = "_sentinel",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_7_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_7_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_3._ascii.ob_base,
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
toplevel_consts_7_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_7_consts_1_qualname = {
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
    ._data = "_ModifiedArgv0.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_7_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_7_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x1b\x09\x0d\x09\x13\x2e\x34\x2e\x36\x09\x36\x09\x0d\x09\x1a\x1d\x21\x1d\x2b\x1d\x2b\x1d\x2b",
};
static struct PyCodeObject toplevel_consts_7_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 50,
    .co_code = & toplevel_consts_7_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_1_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_7_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7c\x00\x6a\x01\x75\x01\x72\x0b\x74\x02\x64\x01\xa9\x01\x82\x01\x74\x03\x6a\x04\x64\x02\x19\x00\x7c\x00\x5f\x00\x7c\x00\x6a\x05\x74\x03\x6a\x04\x64\x02\x3c\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_7_consts_2_consts_1 = {
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
    ._data = "Already preserving saved value",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_7_consts_2_consts = {
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
            & toplevel_consts_7_consts_2_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_7_consts_2_names_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_2_names_4 = {
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
    ._data = "argv",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_7_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_7_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_0._ascii.ob_base,
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
toplevel_consts_7_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_7_consts_2_qualname = {
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
    ._data = "_ModifiedArgv0.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_7_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x08\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_7_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_7_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x1d\x25\x29\x25\x33\x0c\x33\x09\x41\x13\x1f\x20\x40\x13\x41\x0d\x41\x1d\x20\x1d\x25\x26\x27\x1d\x28\x09\x0d\x09\x1a\x17\x1b\x17\x21\x09\x0c\x09\x11\x12\x13\x09\x14\x09\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_7_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_7_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 54,
    .co_code = & toplevel_consts_7_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
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
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7c\x00\x5f\x01\x7c\x00\x6a\x02\x74\x03\x6a\x04\x64\x01\x3c\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_7_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_7_consts_1_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_7_consts_3_qualname = {
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
    ._data = "_ModifiedArgv0.__exit__",
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
    .ob_sval = "\x01\x01\x16\x1a\x16\x24\x09\x0d\x09\x13\x17\x1b\x17\x28\x09\x0c\x09\x11\x12\x13\x09\x14\x09\x14\x09\x14",
};
static struct PyCodeObject toplevel_consts_7_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 60,
    .co_code = & toplevel_consts_7_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_7_consts_1.ob_base,
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
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_2_name._ascii.ob_base,
            & toplevel_consts_5_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_consts_4_name._ascii.ob_base,
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
    .ob_sval = "\x0a\x00\x06\x01\x06\x04\x0a\x06",
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
    .ob_sval = "\x0a\x00\x06\x03\x06\x06\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x36\x05\x36\x05\x36\x05\x21\x05\x21\x05\x21\x05\x28\x05\x28\x05\x28\x05\x28\x05\x28",
};
static struct PyCodeObject toplevel_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 49,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x81\x09\x7c\x01\xa0\x00\x7c\x02\xa8\x01\xa9\x01\x01\x00\x7c\x04\x80\x12\x64\x01\x7d\x07\x7c\x06\x7d\x08\x64\x01\x7d\x09\x6e\x0e\x7c\x04\x6a\x01\x7d\x07\x7c\x04\x6a\x02\x7d\x08\x7c\x04\x6a\x03\x7d\x09\x7c\x05\x80\x20\x7c\x04\x6a\x04\x7d\x05\x7c\x01\xa0\x00\x7c\x03\x7c\x08\x7c\x09\x64\x01\x7c\x07\x7c\x05\x7c\x04\x64\x02\xa8\x08\xaa\x07\x01\x00\x74\x05\x7c\x00\x7c\x01\xa9\x02\x01\x00\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[42];
    }
toplevel_consts_9_consts_0 = {
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
    ._data = "Helper to run code in nominated namespace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_consts_2_1 = {
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
    ._data = "__file__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_9_consts_2_2 = {
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
    ._data = "__cached__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_9_consts_2_4 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_9_consts_2_5 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_consts_2_6 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_9_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_9_consts_2_1._ascii.ob_base,
            & toplevel_consts_9_consts_2_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_9_consts_2_4._ascii.ob_base,
            & toplevel_consts_9_consts_2_5._ascii.ob_base,
            & toplevel_consts_9_consts_2_6._ascii.ob_base,
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
toplevel_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_9_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_9_consts_2._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_9_names_0 = {
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
        uint8_t _data[7];
    }
toplevel_consts_9_names_1 = {
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
        uint8_t _data[7];
    }
toplevel_consts_9_names_2 = {
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
        uint8_t _data[7];
    }
toplevel_consts_9_names_3 = {
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
    ._data = "cached",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_9_names_4 = {
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
        uint8_t _data[5];
    }
toplevel_consts_9_names_5 = {
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
    ._data = "exec",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_9_names_0._ascii.ob_base,
            & toplevel_consts_9_names_1._ascii.ob_base,
            & toplevel_consts_9_names_2._ascii.ob_base,
            & toplevel_consts_9_names_3._ascii.ob_base,
            & toplevel_consts_9_names_4._ascii.ob_base,
            & toplevel_consts_9_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_9_varnames_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_9_varnames_1 = {
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
    ._data = "run_globals",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_9_varnames_2 = {
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
    ._data = "init_globals",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_varnames_4 = {
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
    ._data = "mod_spec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_9_varnames_5 = {
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
    ._data = "pkg_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_9_varnames_6 = {
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
    ._data = "script_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_9_varnames_8 = {
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
    ._data = "fname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_9_varnames_1._ascii.ob_base,
            & toplevel_consts_9_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_9_varnames_5._ascii.ob_base,
            & toplevel_consts_9_varnames_6._ascii.ob_base,
            & toplevel_consts_9_names_1._ascii.ob_base,
            & toplevel_consts_9_varnames_8._ascii.ob_base,
            & toplevel_consts_9_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_9_name = {
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
    ._data = "_run_code",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x04\x0c\x01\x04\x01\x04\x01\x04\x01\x06\x01\x06\x02\x06\x01\x06\x01\x04\x01\x06\x01\x06\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x08\xfa\x0a\x07\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x0e\x01\x02\x01\x02\x09\x04\xf8\x04\x01\x06\x01\x06\x02\x06\x01\x06\x01\x02\x01\x08\x01\x02\x01\x02\x06\x02\xfa\x02\x01\x02\x01\x02\x01\x02\x01\x02\x01\x0a\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x14\x05\x29\x09\x14\x09\x29\x1c\x28\x09\x29\x09\x29\x09\x29\x08\x10\x05\x27\x12\x16\x09\x0f\x11\x1c\x09\x0e\x12\x16\x09\x0f\x09\x0f\x12\x1a\x12\x21\x09\x0f\x11\x19\x11\x20\x09\x0e\x12\x1a\x12\x21\x09\x0f\x0c\x14\x09\x27\x18\x20\x18\x27\x0d\x15\x05\x10\x05\x2c\x23\x2b\x23\x28\x25\x2b\x22\x26\x25\x2b\x26\x2e\x23\x2b\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x09\x0a\x0e\x10\x1b\x05\x1c\x05\x1c\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_9_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 7,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 10,
    .co_firstlineno = 65,
    .co_code = & toplevel_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_9_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x03\x80\x05\x7c\x05\x6e\x02\x7c\x03\x6a\x00\x7d\x06\x74\x01\x7c\x02\xa9\x01\x35\x00\x7d\x07\x74\x02\x7c\x06\xa9\x01\x35\x00\x01\x00\x7c\x07\x6a\x03\x6a\x04\x7d\x08\x74\x05\x7c\x00\x7c\x08\x7c\x01\x7c\x02\x7c\x03\x7c\x04\x7c\x05\xa9\x07\x01\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x2d\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x3e\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x08\xa0\x06\xa8\x00\xa9\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_10_consts_0 = {
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
    ._data = "Helper to run code in new namespace with sys modified",
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
            & toplevel_consts_10_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_10_names_4 = {
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
        uint8_t _data[5];
    }
toplevel_consts_10_names_6 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_9_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_10_names_4._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
            & toplevel_consts_10_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_10_varnames_7 = {
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
    ._data = "temp_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_10_varnames_8 = {
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
    ._data = "mod_globals",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_9_varnames_2._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_9_varnames_5._ascii.ob_base,
            & toplevel_consts_9_varnames_6._ascii.ob_base,
            & toplevel_consts_9_varnames_8._ascii.ob_base,
            & toplevel_consts_10_varnames_7._ascii.ob_base,
            & toplevel_consts_10_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_10_name = {
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
    ._data = "_run_module_code",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x04\x14\x01\x08\x01\x08\x01\x08\x01\x04\xff\x14\xfe\x06\x80\x1c\x00\x06\x80\x08\x00\x0a\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x04\x06\x01\x02\x03\x08\xfd\x04\x03\x08\xfe\x08\x01\x20\x01\x06\x80\x1c\x00\x06\x80\x08\x00\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1c\x24\x0d\x41\x0d\x18\x0d\x18\x32\x3a\x32\x41\x05\x0a\x0a\x15\x16\x1e\x0a\x1f\x05\x3d\x23\x2e\x30\x3e\x3f\x44\x30\x45\x05\x3d\x05\x3d\x17\x22\x17\x29\x17\x32\x09\x14\x09\x12\x13\x17\x19\x24\x26\x32\x13\x1b\x1d\x25\x27\x2f\x31\x3c\x09\x3d\x09\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x00\x00\x00\x00\x00\x00\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x00\x00\x00\x00\x00\x00\x05\x3d\x05\x3d\x05\x3d\x05\x3d\x0c\x17\x0c\x1e\x0c\x1e\x0c\x1e\x05\x1e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_10_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x8c\x05\x37\x03\x91\x0f\x26\x05\xa0\x06\x37\x03\xa6\x04\x2a\x09\xaa\x03\x37\x03\xad\x01\x2a\x09\xae\x03\x37\x03\xb7\x04\x3b\x07\xbe\x01\x3b\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_10_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_10_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 6,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 10,
    .co_firstlineno = 91,
    .co_code = & toplevel_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_10_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[551];
    }
toplevel_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 550,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x72\x0b\x7c\x01\x64\x02\xa9\x01\x82\x01\x7c\x00\xa0\x01\x64\x01\xa8\x01\xa9\x01\x5c\x03\x7d\x02\x7d\x03\x7d\x03\x7c\x02\x72\x61\x09\x00\x74\x02\x7c\x02\xa9\x01\x01\x00\x6e\x23\x23\x00\x74\x03\x79\x3b\x7d\x04\x7c\x04\x6a\x04\x81\x31\x7c\x04\x6a\x04\x7c\x02\x6b\x03\x72\x32\x7c\x02\xa0\x00\x7c\x04\x6a\x04\x64\x01\x7a\x00\xa8\x01\xa9\x01\x73\x32\x82\x00\x59\x00\x64\x00\x7d\x04\x7e\x04\x6e\x08\x64\x00\x7d\x04\x7e\x04\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x74\x05\x6a\x06\xa0\x07\x7c\x00\xa8\x01\xa9\x01\x7d\x05\x7c\x05\x81\x61\x74\x08\x7c\x05\x64\x03\xa9\x02\x73\x61\x64\x04\x64\x05\x6c\x09\x6d\x0a\x7d\x06\x01\x00\x64\x06\xa0\x0b\x7c\x00\x7c\x02\x64\x07\xa8\x03\xaa\x02\x7d\x07\x7c\x06\x74\x0c\x7c\x07\xa9\x01\xa9\x01\x01\x00\x09\x00\x74\x0d\x6a\x0e\xa0\x0f\x7c\x00\xa8\x01\xa9\x01\x7d\x08\x6e\x35\x23\x00\x74\x03\x74\x10\x74\x11\x74\x12\x66\x04\x79\x9b\x7d\x09\x64\x08\x7d\x07\x7c\x00\xa0\x13\x64\x09\xa8\x01\xa9\x01\x72\x89\x7c\x07\x64\x0a\x7c\x00\x64\x00\x64\x0b\x85\x02\x19\x00\x9b\x00\x64\x0c\x7c\x00\x9b\x00\x64\x0d\x9d\x05\x7a\x0d\x7d\x07\x7c\x01\x7c\x07\xa0\x0b\x7c\x00\x74\x14\x7c\x09\xa9\x01\x6a\x15\x7c\x09\xa8\x03\xa9\x03\xa9\x01\x7c\x09\x82\x02\x64\x00\x7d\x09\x7e\x09\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x08\x80\xa7\x7c\x01\x64\x0e\x7c\x00\x7a\x06\xa9\x01\x82\x01\x7c\x08\x6a\x16\x81\xde\x7c\x00\x64\x0f\x6b\x02\x73\xb4\x7c\x00\xa0\x13\x64\x10\xa8\x01\xa9\x01\x72\xb8\x7c\x01\x64\x11\xa9\x01\x82\x01\x09\x00\x7c\x00\x64\x10\x7a\x00\x7d\x0a\x74\x17\x7c\x0a\x7c\x01\xa9\x02\x53\x00\x23\x00\x7c\x01\x79\xda\x7d\x04\x7c\x00\x74\x05\x6a\x06\x76\x01\x72\xcc\x82\x00\x7c\x01\x7c\x04\x9b\x01\x64\x12\x7c\x00\x9b\x02\x64\x13\x9d\x04\xa9\x01\x82\x01\x64\x00\x7d\x04\x7e\x04\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x08\x6a\x18\x7d\x0b\x7c\x0b\x80\xe9\x7c\x01\x64\x14\x7c\x00\x7a\x06\xa9\x01\x82\x01\x09\x00\x7c\x0b\xa0\x19\x7c\x00\xa8\x01\xa9\x01\x7d\x0c\x6e\x14\x23\x00\x74\x03\x90\x01\x79\x01\x7d\x04\x7c\x01\x74\x0b\x7c\x04\xa9\x01\xa9\x01\x7c\x04\x82\x02\x64\x00\x7d\x04\x7e\x04\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x0c\x90\x01\x80\x0e\x7c\x01\x64\x15\x7c\x00\x7a\x06\xa9\x01\x82\x01\x7c\x00\x7c\x08\x7c\x0c\x66\x03\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_11_consts_1 = {
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
        uint8_t _data[36];
    }
toplevel_consts_11_consts_2 = {
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
    ._data = "Relative module names not supported",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_consts_3 = {
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
        uint8_t _data[5];
    }
toplevel_consts_11_consts_5_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_11_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_11_consts_5_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[155];
    }
toplevel_consts_11_consts_6 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 154,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "{mod_name!r} found in sys.modules after import of package {pkg_name!r}, but prior to execution of {mod_name!r}; this may result in unpredictable behaviour",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_11_consts_7 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[59];
    }
toplevel_consts_11_consts_8 = {
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
    ._data = "Error while finding module specification for {!r} ({}: {})",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_11_consts_9 = {
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
    ._data = ".py",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_11_consts_10 = {
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
    ._data = ". Try using '",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_11_consts_11 = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyLong_Type,
        },
        .ob_size = -1,
    },
    .ob_digit = { 3 },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_11_consts_12 = {
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
    ._data = "' instead of '",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_11_consts_13 = {
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
    ._data = "' as the module name.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_11_consts_14 = {
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
    ._data = "No module named %s",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_consts_15 = {
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
        uint8_t _data[10];
    }
toplevel_consts_11_consts_16 = {
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
    ._data = ".__main__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[38];
    }
toplevel_consts_11_consts_17 = {
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
    ._data = "Cannot use package as __main__ module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_11_consts_18 = {
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
    ._data = "; ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[46];
    }
toplevel_consts_11_consts_19 = {
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
    ._data = " is a package and cannot be directly executed",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_11_consts_20 = {
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
    ._data = "%r is a namespace package and cannot be executed",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_11_consts_21 = {
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
    ._data = "No code object available for %s",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[22];
        }_object;
    }
toplevel_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 22,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_11_consts_1._ascii.ob_base,
            & toplevel_consts_11_consts_2._ascii.ob_base,
            & toplevel_consts_11_consts_3._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_11_consts_5._object.ob_base.ob_base,
            & toplevel_consts_11_consts_6._ascii.ob_base,
            & toplevel_consts_11_consts_7._object.ob_base.ob_base,
            & toplevel_consts_11_consts_8._ascii.ob_base,
            & toplevel_consts_11_consts_9._ascii.ob_base,
            & toplevel_consts_11_consts_10._ascii.ob_base,
            & toplevel_consts_11_consts_11.ob_base.ob_base,
            & toplevel_consts_11_consts_12._ascii.ob_base,
            & toplevel_consts_11_consts_13._ascii.ob_base,
            & toplevel_consts_11_consts_14._ascii.ob_base,
            & toplevel_consts_11_consts_15._ascii.ob_base,
            & toplevel_consts_11_consts_16._ascii.ob_base,
            & toplevel_consts_11_consts_17._ascii.ob_base,
            & toplevel_consts_11_consts_18._ascii.ob_base,
            & toplevel_consts_11_consts_19._ascii.ob_base,
            & toplevel_consts_11_consts_20._ascii.ob_base,
            & toplevel_consts_11_consts_21._ascii.ob_base,
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
    ._data = "startswith",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_11_names_1 = {
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
toplevel_consts_11_names_2 = {
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
        uint8_t _data[12];
    }
toplevel_consts_11_names_3 = {
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
toplevel_consts_11_names_4 = {
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
    ._data = "get",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_11_names_8 = {
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
        uint8_t _data[9];
    }
toplevel_consts_11_names_9 = {
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
        uint8_t _data[7];
    }
toplevel_consts_11_names_11 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_11_names_12 = {
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
    ._data = "RuntimeWarning",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_11_names_13 = {
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
    ._data = "importlib",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_names_14 = {
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
    ._data = "util",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_11_names_15 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_11_names_16 = {
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
        uint8_t _data[10];
    }
toplevel_consts_11_names_17 = {
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
        uint8_t _data[11];
    }
toplevel_consts_11_names_18 = {
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
        uint8_t _data[9];
    }
toplevel_consts_11_names_19 = {
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
        uint8_t _data[5];
    }
toplevel_consts_11_names_20 = {
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
        uint8_t _data[27];
    }
toplevel_consts_11_names_22 = {
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
    ._data = "submodule_search_locations",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_11_names_23 = {
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
    ._data = "_get_module_details",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_names_25 = {
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
    ._data = "get_code",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[26];
        }_object;
    }
toplevel_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 26,
        },
        .ob_item = {
            & toplevel_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_11_names_2._ascii.ob_base,
            & toplevel_consts_11_names_3._ascii.ob_base,
            & toplevel_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_11_names_7._ascii.ob_base,
            & toplevel_consts_11_names_8._ascii.ob_base,
            & toplevel_consts_11_names_9._ascii.ob_base,
            & toplevel_consts_11_consts_5_0._ascii.ob_base,
            & toplevel_consts_11_names_11._ascii.ob_base,
            & toplevel_consts_11_names_12._ascii.ob_base,
            & toplevel_consts_11_names_13._ascii.ob_base,
            & toplevel_consts_11_names_14._ascii.ob_base,
            & toplevel_consts_11_names_15._ascii.ob_base,
            & toplevel_consts_11_names_16._ascii.ob_base,
            & toplevel_consts_11_names_17._ascii.ob_base,
            & toplevel_consts_11_names_18._ascii.ob_base,
            & toplevel_consts_11_names_19._ascii.ob_base,
            & toplevel_consts_11_names_20._ascii.ob_base,
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_11_names_22._ascii.ob_base,
            & toplevel_consts_11_names_23._ascii.ob_base,
            & toplevel_consts_9_names_1._ascii.ob_base,
            & toplevel_consts_11_names_25._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_varnames_1 = {
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
    ._data = "_",
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
    ._data = "e",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_varnames_5 = {
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
    ._data = "existing",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_11_varnames_7 = {
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
    ._data = "msg",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_varnames_8 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_11_varnames_9 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_11_varnames_10 = {
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
    ._data = "pkg_main_name",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_9_varnames_5._ascii.ob_base,
            & toplevel_consts_11_varnames_3._ascii.ob_base,
            & toplevel_consts_11_varnames_4._ascii.ob_base,
            & toplevel_consts_11_varnames_5._ascii.ob_base,
            & toplevel_consts_11_consts_5_0._ascii.ob_base,
            & toplevel_consts_11_varnames_7._ascii.ob_base,
            & toplevel_consts_11_varnames_8._ascii.ob_base,
            & toplevel_consts_11_varnames_9._ascii.ob_base,
            & toplevel_consts_11_varnames_10._ascii.ob_base,
            & toplevel_consts_9_names_1._ascii.ob_base,
            & toplevel_consts_9_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[141];
    }
toplevel_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 140,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x08\x01\x12\x01\x04\x01\x02\x02\x0a\x01\x02\x80\x06\x01\x10\x04\x10\x01\x02\xff\x02\x02\x12\x80\x02\xfa\x06\x80\x0e\x08\x0e\x01\x0c\x01\x02\x01\x0c\x03\x02\xfd\x0c\x04\x02\x02\x10\x01\x02\x80\x0e\x01\x04\x04\x0c\x01\x12\x01\x02\x01\x0a\xff\x1c\x02\x08\x80\x02\xf8\x06\x80\x04\x09\x0c\x01\x06\x01\x14\x01\x08\x01\x02\x01\x08\x01\x0a\x01\x02\x80\x06\x01\x0a\x01\x02\x01\x02\x01\x0c\x01\x06\xff\x08\x80\x02\xfd\x06\x80\x06\x05\x04\x01\x04\x01\x02\x01\x06\xff\x02\x02\x0e\x01\x02\x80\x08\x01\x0e\x01\x08\x80\x02\xff\x06\x80\x06\x02\x0c\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[167];
    }
toplevel_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 166,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x0a\x01\x12\x01\x02\x01\x02\x13\x02\xf7\x0a\xf9\x02\x80\x02\x01\x04\x06\x04\xfe\x02\x02\x08\xfe\x02\x02\x10\xff\x04\x01\x12\x80\x02\x00\x06\x80\x0e\x02\x02\x01\x02\x06\x08\xfa\x02\x06\x0c\xfb\x0e\x04\x02\xfd\x0c\x04\x02\x0c\x10\xf7\x02\x80\x0a\x01\x04\x08\x04\xfc\x0a\x01\x02\x02\x02\xff\x02\x01\x0a\xff\x0e\x01\x02\xff\x1c\x02\x08\x80\x02\x00\x06\x80\x02\x01\x0e\x01\x04\x01\x02\x0a\x06\xf7\x02\x01\x0a\xff\x0a\x01\x02\x08\x08\xfa\x0a\x01\x02\x80\x02\x01\x04\x04\x08\xfd\x04\x01\x02\x01\x12\x01\x08\x80\x02\x00\x06\x80\x06\x01\x02\x01\x02\x02\x04\xff\x08\x01\x02\x04\x0e\xfe\x02\x80\x02\x01\x14\x01\x08\x80\x02\x00\x06\x80\x02\x01\x10\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[551];
    }
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 550,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x10\x08\x20\x1c\x1f\x08\x20\x08\x20\x05\x3b\x0f\x14\x15\x3a\x0f\x3b\x09\x3b\x16\x1e\x16\x2e\x2a\x2d\x16\x2e\x16\x2e\x05\x13\x05\x0d\x0f\x10\x12\x13\x08\x10\x05\x26\x09\x16\x0d\x17\x18\x20\x0d\x21\x0d\x21\x0d\x21\x00\x00\x10\x1b\x09\x16\x09\x16\x10\x11\x10\x16\x0d\x16\x23\x24\x23\x29\x2d\x35\x23\x35\x0d\x16\x19\x21\x19\x3a\x2d\x2e\x2d\x33\x36\x39\x2d\x39\x19\x3a\x19\x3a\x0d\x16\x11\x16\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x09\x16\x00\x00\x00\x00\x00\x00\x14\x17\x14\x1f\x14\x2d\x24\x2c\x14\x2d\x14\x2d\x09\x11\x0c\x14\x09\x26\x29\x30\x31\x39\x3b\x45\x29\x46\x09\x26\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x0d\x26\x13\x1c\x13\x49\x2d\x35\x40\x48\x13\x49\x13\x49\x13\x49\x0d\x10\x0d\x11\x12\x20\x21\x24\x12\x25\x0d\x26\x0d\x26\x05\x49\x10\x19\x10\x1e\x10\x32\x29\x31\x10\x32\x10\x32\x09\x0d\x09\x0d\x00\x00\x0d\x18\x1a\x28\x2a\x33\x35\x3f\x0c\x40\x05\x49\x05\x49\x0f\x4b\x09\x0c\x0c\x14\x0c\x24\x1e\x23\x0c\x24\x0c\x24\x09\x39\x0d\x10\x15\x38\x25\x2d\x2e\x31\x2f\x31\x2e\x31\x25\x32\x15\x38\x15\x38\x19\x21\x15\x38\x15\x38\x15\x38\x0d\x39\x0d\x10\x0f\x14\x15\x18\x15\x40\x20\x28\x2a\x2e\x2f\x31\x2a\x32\x2a\x3b\x3d\x3f\x15\x40\x15\x40\x0f\x41\x47\x49\x09\x49\x00\x00\x00\x00\x00\x00\x00\x00\x05\x49\x00\x00\x00\x00\x00\x00\x08\x0c\x05\x35\x0f\x14\x15\x29\x2c\x34\x15\x34\x0f\x35\x09\x35\x08\x0c\x08\x27\x05\x47\x0c\x14\x18\x22\x0c\x22\x09\x41\x26\x2e\x26\x44\x38\x43\x26\x44\x26\x44\x09\x41\x13\x18\x19\x40\x13\x41\x0d\x41\x09\x47\x1d\x25\x28\x33\x1d\x33\x0d\x1a\x14\x27\x28\x35\x37\x3c\x14\x3d\x0d\x3d\x00\x00\x10\x15\x09\x47\x09\x47\x10\x18\x20\x23\x20\x2b\x10\x2b\x0d\x16\x11\x16\x13\x18\x3a\x3b\x3a\x3b\x3a\x3b\x3d\x45\x3d\x45\x3d\x45\x19\x46\x13\x47\x0d\x47\x00\x00\x00\x00\x00\x00\x00\x00\x09\x47\x00\x00\x00\x00\x00\x00\x0e\x12\x0e\x19\x05\x0b\x08\x0e\x05\x4d\x0f\x14\x15\x47\x44\x4c\x15\x4c\x0f\x4d\x09\x4d\x05\x26\x10\x16\x10\x29\x20\x28\x10\x29\x10\x29\x09\x0d\x09\x0d\x00\x00\x0c\x17\x05\x26\x05\x26\x05\x26\x0f\x14\x15\x1b\x1c\x1d\x15\x1e\x0f\x1f\x25\x26\x09\x26\x00\x00\x00\x00\x00\x00\x00\x00\x05\x26\x00\x00\x00\x00\x00\x00\x08\x0c\x05\x42\x05\x42\x0f\x14\x15\x36\x39\x41\x15\x41\x0f\x42\x09\x42\x0c\x14\x16\x1a\x1c\x20\x0c\x20\x05\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_11_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x04\x1c\x00\x9c\x04\x3c\x03\xa0\x12\x37\x03\xb7\x05\x3c\x03\xc1\x22\x07\x41\x2a\x00\xc1\x2a\x08\x42\x1c\x03\xc1\x32\x25\x42\x17\x03\xc2\x17\x05\x42\x1c\x03\xc2\x39\x08\x43\x02\x00\xc3\x02\x04\x43\x1b\x03\xc3\x06\x10\x43\x16\x03\xc3\x16\x05\x43\x1b\x03\xc3\x2a\x06\x43\x31\x00\xc3\x31\x05\x44\x02\x03\xc3\x36\x07\x43\x3d\x03\xc3\x3d\x05\x44\x02\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[14];
    }
toplevel_consts_11_localspluskinds = {
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
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 105,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_names_23._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_names_23._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 13,
    .co_nlocals = 13,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_12_consts_0 = {
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
    ._data = "_Error",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[67];
    }
toplevel_consts_12_consts_1 = {
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
    ._data = "Error that _run_module_as_main() should report without a traceback",
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
            & toplevel_consts_12_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_1._ascii.ob_base,
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
toplevel_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_5_names_2._ascii.ob_base,
            & toplevel_consts_5_names_3._ascii.ob_base,
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
    .ob_sval = "\x0a\x00\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x4d\x05\x4d\x05\x4d\x05\x4d",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 166,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[155];
    }
toplevel_consts_15_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 154,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x01\x73\x08\x7c\x00\x64\x01\x6b\x03\x72\x11\x74\x00\x7c\x00\x74\x01\xa9\x02\x5c\x03\x7d\x00\x7d\x02\x7d\x03\x6e\x07\x74\x02\x74\x01\xa9\x01\x5c\x03\x7d\x00\x7d\x02\x7d\x03\x6e\x1e\x23\x00\x74\x01\x79\x33\x7d\x04\x74\x03\x6a\x04\x9b\x01\x64\x02\x7c\x04\x9b\x01\x9d\x03\x7d\x05\x74\x03\x6a\x05\x7c\x05\xa9\x01\x01\x00\x59\x00\x64\x03\x7d\x04\x7e\x04\x6e\x08\x64\x03\x7d\x04\x7e\x04\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x74\x03\x6a\x06\x64\x01\x19\x00\x6a\x07\x7d\x06\x7c\x01\x72\x45\x7c\x02\x6a\x08\x74\x03\x6a\x09\x64\x04\x3c\x00\x74\x0a\x7c\x03\x7c\x06\x64\x03\x64\x01\x7c\x02\xa9\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[454];
    }
toplevel_consts_15_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 453,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x75\x6e\x73\x20\x74\x68\x65\x20\x64\x65\x73\x69\x67\x6e\x61\x74\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x5f\x5f\x6d\x61\x69\x6e\x5f\x5f\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x4e\x6f\x74\x65\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x65\x78\x65\x63\x75\x74\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x20\x77\x69\x6c\x6c\x20\x68\x61\x76\x65\x20\x66\x75\x6c\x6c\x20\x61\x63\x63\x65\x73\x73\x20\x74\x6f\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x6d\x61\x69\x6e\x5f\x5f\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x2e\x20\x49\x66\x20\x74\x68\x69\x73\x20\x69\x73\x20\x6e\x6f\x74\x20\x64\x65\x73\x69\x72\x61\x62\x6c\x65\x2c\x20\x74\x68\x65\x20\x72\x75\x6e\x5f\x6d\x6f\x64\x75\x6c\x65\x28\x29\x0a\x20\x20\x20\x20\x20\x20\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x72\x75\x6e\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x63\x6f\x64\x65\x20\x69\x6e\x20\x61\x20\x66\x72\x65\x73\x68\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x41\x74\x20\x74\x68\x65\x20\x76\x65\x72\x79\x20\x6c\x65\x61\x73\x74\x2c\x20\x74\x68\x65\x73\x65\x20\x76\x61\x72\x69\x61\x62\x6c\x65\x73\x20\x69\x6e\x20\x5f\x5f\x6d\x61\x69\x6e\x5f\x5f\x20\x77\x69\x6c\x6c\x20\x62\x65\x20\x6f\x76\x65\x72\x77\x72\x69\x74\x74\x65\x6e\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x6e\x61\x6d\x65\x5f\x5f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x66\x69\x6c\x65\x5f\x5f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x63\x61\x63\x68\x65\x64\x5f\x5f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x6c\x6f\x61\x64\x65\x72\x5f\x5f\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_15_consts_2 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_15._ascii.ob_base,
            & toplevel_consts_15_consts_2._ascii.ob_base,
            Py_None,
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_15_names_2 = {
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
    ._data = "_get_main_module_details",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_15_names_4 = {
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
    ._data = "executable",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_15_names_5 = {
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
    ._data = "exit",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_11_names_23._ascii.ob_base,
            & toplevel_consts_12_consts_0._ascii.ob_base,
            & toplevel_consts_15_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
            & toplevel_consts_15_names_5._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_10_names_4._ascii.ob_base,
            & toplevel_consts_9_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_4._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_15_varnames_1 = {
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
    ._data = "alter_argv",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_15_varnames_4 = {
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
        uint8_t _data[13];
    }
toplevel_consts_15_varnames_6 = {
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
    ._data = "main_globals",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_15_varnames_1._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
            & toplevel_consts_11_varnames_7._ascii.ob_base,
            & toplevel_consts_15_varnames_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_15_name = {
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
    ._data = "_run_module_as_main",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0e\x0c\x01\x12\x01\x0e\x02\x04\x80\x06\x01\x10\x01\x14\x01\x08\x80\x02\xfe\x06\x80\x0c\x03\x04\x01\x0c\x01\x08\x01\x04\x01\x04\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x15\x02\xfa\x02\x03\x06\xfd\x02\x03\x12\xfe\x0e\x02\x04\x80\x02\x01\x04\x02\x10\xff\x14\x01\x08\x80\x02\x00\x06\x80\x0c\x01\x02\x01\x0e\x01\x08\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[155];
    }
toplevel_consts_15_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 154,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x16\x0c\x16\x09\x48\x1a\x22\x26\x30\x1a\x30\x09\x48\x28\x3b\x3c\x44\x46\x4c\x28\x4d\x0d\x25\x0d\x15\x17\x1f\x21\x25\x21\x25\x28\x40\x41\x47\x28\x48\x0d\x25\x0d\x15\x17\x1f\x21\x25\x00\x00\x00\x00\x0c\x12\x05\x16\x05\x16\x1b\x1e\x1b\x29\x1b\x29\x1b\x29\x2b\x2e\x2b\x2e\x0f\x2f\x09\x0c\x09\x0c\x09\x11\x12\x15\x09\x16\x09\x16\x09\x16\x09\x16\x09\x16\x09\x16\x09\x16\x00\x00\x00\x00\x00\x00\x00\x00\x05\x16\x00\x00\x00\x00\x00\x00\x14\x17\x14\x1f\x20\x2a\x14\x2b\x14\x34\x05\x11\x08\x12\x05\x26\x17\x1f\x17\x26\x09\x0c\x09\x11\x12\x13\x09\x14\x0c\x15\x16\x1a\x1c\x28\x2a\x2e\x16\x20\x22\x2a\x0c\x2b\x05\x2b",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_15_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x16\x19\x00\x99\x04\x34\x03\x9d\x0d\x2f\x03\xaf\x05\x34\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_15_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_15_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 173,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_15_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_17_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x5c\x03\x7d\x00\x7d\x04\x7d\x05\x7c\x02\x80\x0c\x7c\x00\x7d\x02\x7c\x03\x72\x15\x74\x01\x7c\x05\x7c\x01\x7c\x02\x7c\x04\xa9\x04\x53\x00\x74\x02\x7c\x05\x69\x00\x7c\x01\x7c\x02\x7c\x04\xa9\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[111];
    }
toplevel_consts_17_consts_0 = {
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
    ._data = "\x45\x78\x65\x63\x75\x74\x65\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x27\x73\x20\x63\x6f\x64\x65\x20\x77\x69\x74\x68\x6f\x75\x74\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x69\x74\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x74\x6f\x70\x20\x6c\x65\x76\x65\x6c\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x20\x64\x69\x63\x74\x69\x6f\x6e\x61\x72\x79\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_17_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_17_consts_0._ascii.ob_base,
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
toplevel_consts_17_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_11_names_23._ascii.ob_base,
            & toplevel_consts_10_name._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_17_varnames_2 = {
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
    ._data = "run_name",
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
    ._data = "alter_sys",
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
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_varnames_2._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_17_varnames_3._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_9_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_17_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x06\x04\x01\x04\x01\x04\x01\x0e\x01\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_17_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x06\x02\x01\x06\x01\x02\x01\x02\x04\x0e\xfd\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_17_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x20\x33\x34\x3c\x20\x3d\x05\x1d\x05\x0d\x0f\x17\x19\x1d\x08\x10\x05\x1c\x14\x1c\x09\x11\x08\x11\x05\x45\x10\x20\x21\x25\x27\x33\x35\x3d\x3f\x47\x10\x48\x09\x48\x10\x19\x1a\x1e\x20\x22\x24\x30\x32\x3a\x3c\x44\x10\x45\x09\x45",
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
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 201,
    .co_code = & toplevel_consts_17_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_17_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_17_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_17_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_17_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x01\x74\x00\x6a\x01\x7c\x01\x19\x00\x7d\x02\x74\x00\x6a\x01\x7c\x01\x3d\x00\x09\x00\x74\x02\x7c\x01\xa9\x01\x7c\x02\x74\x00\x6a\x01\x7c\x01\x3c\x00\x53\x00\x23\x00\x74\x03\x79\x33\x7d\x03\x7c\x01\x74\x04\x7c\x03\xa9\x01\x76\x00\x72\x2e\x7c\x00\x64\x02\x7c\x01\x9b\x02\x64\x03\x74\x00\x6a\x05\x64\x04\x19\x00\x9b\x02\x9d\x04\xa9\x01\x7c\x03\x82\x02\x82\x00\x64\x00\x7d\x03\x7e\x03\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x23\x00\x7c\x02\x74\x00\x6a\x01\x7c\x01\x3c\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_18_consts_2 = {
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
    ._data = "can't find ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_18_consts_3 = {
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
    ._data = " module in ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_18_consts = {
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
            & toplevel_consts_11_consts_15._ascii.ob_base,
            & toplevel_consts_18_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_18_names_4 = {
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
        uint8_t _data[5];
    }
toplevel_consts_18_names_5 = {
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
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_11_names_23._ascii.ob_base,
            & toplevel_consts_11_names_3._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_18_varnames_1 = {
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
    ._data = "main_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_18_varnames_2 = {
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
    ._data = "saved_main",
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
            & toplevel_consts_11_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_1._ascii.ob_base,
            & toplevel_consts_18_varnames_2._ascii.ob_base,
            & toplevel_consts_15_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x0a\x01\x08\x01\x02\x01\x06\x01\x0c\x07\x02\x80\x06\xfa\x0c\x01\x04\x01\x10\x01\x04\xff\x02\x01\x02\xff\x02\x02\x08\x80\x02\xfc\x08\x80\x12\x06",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_18_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x05\x0a\x01\x08\x01\x02\x09\x06\xf9\x0c\x07\x02\x80\x02\xfa\x04\x04\x0a\xfd\x02\x02\x04\xff\x18\x01\x02\x01\x08\x80\x02\x00\x08\x80\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[131];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 130,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x1b\x05\x0e\x12\x15\x12\x1d\x1e\x27\x12\x28\x05\x0f\x09\x0c\x09\x14\x15\x1e\x09\x1f\x05\x2c\x10\x23\x24\x2d\x10\x2e\x22\x2c\x09\x0c\x09\x14\x15\x1e\x09\x1f\x09\x1f\x00\x00\x0c\x17\x05\x0e\x05\x0e\x0c\x15\x19\x1c\x1d\x20\x19\x21\x0c\x21\x09\x41\x13\x18\x13\x18\x20\x29\x20\x29\x20\x29\x2b\x2e\x2b\x33\x34\x35\x2b\x36\x2b\x36\x19\x37\x13\x38\x3e\x41\x0d\x41\x09\x0e\x00\x00\x00\x00\x00\x00\x00\x00\x05\x0e\x00\x00\x00\x00\x00\x00\x00\x00\x22\x2c\x09\x0c\x09\x14\x15\x1e\x09\x1f\x09\x2c\x09\x2c\x09\x2c\x09\x2c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_18_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x8d\x03\x16\x00\x96\x04\x34\x03\x9a\x15\x2f\x03\xaf\x05\x34\x03\xb4\x03\x37\x00\xb7\x07\x3e\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_18_localspluskinds = {
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
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 216,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_18_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_names_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_names_2._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[171];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 170,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x64\x02\x6c\x00\x6d\x01\x7d\x02\x01\x00\x74\x02\x6a\x03\xa0\x04\x74\x02\x6a\x05\x7c\x01\xa9\x01\xa8\x01\xa9\x01\x7d\x03\x74\x06\x6a\x07\x7c\x03\xa9\x01\x35\x00\x7d\x04\x7c\x02\x7c\x04\xa9\x01\x7d\x05\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x28\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x05\x80\x51\x74\x06\x6a\x07\x7c\x03\xa9\x01\x35\x00\x7d\x04\x74\x08\x7c\x04\xa0\x09\xa8\x00\xa9\x00\x7c\x01\x64\x03\xa9\x03\x7d\x05\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x7c\x05\x7c\x01\x66\x02\x53\x00\x23\x00\x31\x00\x73\x4d\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x05\x7c\x01\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_19_consts_2_0 = {
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
    ._data = "read_code",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_19_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_19_consts_2_0._ascii.ob_base,
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
toplevel_consts_19_consts = {
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
            & toplevel_consts_19_consts_2._object.ob_base.ob_base,
            & toplevel_consts_9_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_19_names_0 = {
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
    ._data = "pkgutil",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_19_names_2 = {
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
        uint8_t _data[8];
    }
toplevel_consts_19_names_4 = {
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
toplevel_consts_19_names_5 = {
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
        uint8_t _data[3];
    }
toplevel_consts_19_names_6 = {
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
        uint8_t _data[10];
    }
toplevel_consts_19_names_7 = {
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
        uint8_t _data[8];
    }
toplevel_consts_19_names_8 = {
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
        uint8_t _data[5];
    }
toplevel_consts_19_names_9 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_19_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_19_names_0._ascii.ob_base,
            & toplevel_consts_19_consts_2_0._ascii.ob_base,
            & toplevel_consts_19_names_2._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_19_names_4._ascii.ob_base,
            & toplevel_consts_19_names_5._ascii.ob_base,
            & toplevel_consts_19_names_6._ascii.ob_base,
            & toplevel_consts_19_names_7._ascii.ob_base,
            & toplevel_consts_19_names_8._ascii.ob_base,
            & toplevel_consts_19_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_19_varnames_3 = {
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
    ._data = "decoded_path",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_19_varnames_4 = {
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
    ._data = "f",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_9_varnames_8._ascii.ob_base,
            & toplevel_consts_19_consts_2_0._ascii.ob_base,
            & toplevel_consts_19_varnames_3._ascii.ob_base,
            & toplevel_consts_19_varnames_4._ascii.ob_base,
            & toplevel_consts_9_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_19_name = {
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
    ._data = "_get_code_from_file",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x14\x01\x0c\x01\x08\x01\x14\xff\x06\x80\x08\x00\x04\x02\x0c\x02\x12\x01\x0a\xff\x08\x02\x08\xfe\x06\x80\x08\x00\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x14\x01\x08\x01\x02\x01\x02\xff\x1c\x01\x06\x80\x08\x00\x02\x01\x02\x03\x08\xff\x02\x01\x02\xff\x1c\x01\x08\x01\x08\xff\x06\x80\x08\x00\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[171];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 170,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22\x05\x22\x14\x16\x14\x1b\x14\x37\x24\x26\x24\x2f\x30\x35\x24\x36\x14\x37\x14\x37\x05\x11\x0a\x0c\x0a\x16\x17\x23\x0a\x24\x05\x1c\x28\x29\x10\x19\x1a\x1b\x10\x1c\x09\x0d\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x00\x00\x00\x00\x00\x00\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x08\x0c\x05\x34\x0e\x10\x0e\x1a\x1b\x27\x0e\x28\x09\x34\x2c\x2d\x14\x1b\x1c\x1d\x1c\x24\x1c\x24\x1c\x24\x26\x2b\x2d\x33\x14\x34\x0d\x11\x09\x34\x09\x34\x09\x34\x09\x34\x09\x34\x0c\x10\x12\x17\x0c\x17\x05\x17\x09\x34\x09\x34\x09\x34\x09\x34\x00\x00\x00\x00\x00\x00\x09\x34\x09\x34\x09\x34\x09\x34\x0c\x10\x12\x17\x0c\x17\x05\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[30];
    }
toplevel_consts_19_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 29,
    },
    .ob_shash = -1,
    .ob_sval = "\x96\x05\x21\x03\xa1\x04\x25\x07\xa8\x01\x25\x07\xb3\x0a\x41\x06\x03\xc1\x06\x04\x41\x0a\x07\xc1\x0d\x01\x41\x0a\x07",
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
    .co_firstlineno = 235,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_17_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[419];
    }
toplevel_consts_20_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 418,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x80\x05\x64\x02\x7d\x02\x7c\x02\xa0\x00\x64\x03\xa8\x01\xa9\x01\x64\x04\x19\x00\x7d\x03\x64\x04\x64\x05\x6c\x01\x6d\x02\x7d\x04\x01\x00\x7c\x04\x7c\x00\xa9\x01\x7d\x05\x64\x06\x7d\x06\x74\x03\x7c\x05\xa9\x01\x6a\x04\x64\x07\x6b\x02\x72\x29\x74\x03\x7c\x05\xa9\x01\x6a\x05\x64\x08\x6b\x02\x72\x29\x64\x09\x7d\x06\x74\x06\x7c\x05\x74\x03\x64\x01\xa9\x01\xa9\x02\x73\x32\x7c\x06\x72\x42\x74\x07\x7c\x02\x7c\x00\xa9\x02\x5c\x02\x7d\x07\x7d\x08\x74\x08\x7c\x07\x7c\x01\x7c\x02\x7c\x03\x7c\x08\x64\x0a\xaa\x05\x53\x00\x74\x09\x6a\x0a\xa0\x0b\x64\x04\x7c\x00\xa8\x02\xa9\x02\x01\x00\x09\x00\x74\x0c\xa9\x00\x5c\x03\x7d\x09\x7d\x0a\x7d\x07\x74\x0d\x7c\x02\xa9\x01\x35\x00\x7d\x0b\x74\x0e\x7c\x00\xa9\x01\x35\x00\x01\x00\x7c\x0b\x6a\x0f\x6a\x10\x7d\x0c\x74\x11\x7c\x07\x7c\x0c\x7c\x01\x7c\x02\x7c\x0a\x7c\x03\xa9\x06\xa0\x12\xa8\x00\xa9\x00\x02\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x02\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x09\x00\x74\x09\x6a\x0a\xa0\x13\x7c\x00\xa8\x01\xa9\x01\x01\x00\x53\x00\x23\x00\x74\x14\x79\x85\x01\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x23\x00\x31\x00\x73\x90\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\xa1\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x09\x00\x74\x09\x6a\x0a\xa0\x13\x7c\x00\xa8\x01\xa9\x01\x01\x00\x64\x01\x53\x00\x23\x00\x74\x14\x79\xb6\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x23\x00\x09\x00\x74\x09\x6a\x0a\xa0\x13\x7c\x00\xa8\x01\xa9\x01\x01\x00\x77\x00\x23\x00\x74\x14\x79\xca\x01\x00\x59\x00\x77\x00\x77\x00\x78\x03\x59\x00\x77\x01\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[352];
    }
toplevel_consts_20_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 351,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x45\x78\x65\x63\x75\x74\x65\x20\x63\x6f\x64\x65\x20\x6c\x6f\x63\x61\x74\x65\x64\x20\x61\x74\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x66\x69\x6c\x65\x73\x79\x73\x74\x65\x6d\x20\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x72\x65\x73\x75\x6c\x74\x69\x6e\x67\x20\x74\x6f\x70\x20\x6c\x65\x76\x65\x6c\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x20\x64\x69\x63\x74\x69\x6f\x6e\x61\x72\x79\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x66\x69\x6c\x65\x20\x70\x61\x74\x68\x20\x6d\x61\x79\x20\x72\x65\x66\x65\x72\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x20\x74\x6f\x20\x61\x20\x50\x79\x74\x68\x6f\x6e\x20\x73\x63\x72\x69\x70\x74\x20\x28\x69\x2e\x65\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x6f\x6e\x65\x20\x74\x68\x61\x74\x20\x63\x6f\x75\x6c\x64\x20\x62\x65\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x20\x65\x78\x65\x63\x75\x74\x65\x64\x20\x77\x69\x74\x68\x20\x65\x78\x65\x63\x66\x69\x6c\x65\x29\x20\x6f\x72\x20\x65\x6c\x73\x65\x0a\x20\x20\x20\x20\x20\x20\x20\x69\x74\x20\x6d\x61\x79\x20\x72\x65\x66\x65\x72\x20\x74\x6f\x20\x61\x20\x7a\x69\x70\x66\x69\x6c\x65\x20\x6f\x72\x20\x64\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x63\x6f\x6e\x74\x61\x69\x6e\x69\x6e\x67\x20\x61\x20\x74\x6f\x70\x0a\x20\x20\x20\x20\x20\x20\x20\x6c\x65\x76\x65\x6c\x20\x5f\x5f\x6d\x61\x69\x6e\x5f\x5f\x2e\x70\x79\x20\x73\x63\x72\x69\x70\x74\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_20_consts_2 = {
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
    ._data = "<run_path>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_20_consts_5_0 = {
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
    ._data = "get_importer",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_20_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_20_consts_5_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_20_consts_7 = {
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
    ._data = "imp",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_20_consts_8 = {
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
    ._data = "NullImporter",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_20_consts_10 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_9_varnames_5._ascii.ob_base,
            & toplevel_consts_9_varnames_6._ascii.ob_base,
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
toplevel_consts_20_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_20_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_20_consts_2._ascii.ob_base,
            & toplevel_consts_11_consts_1._ascii.ob_base,
            & toplevel_consts_1.ob_base.ob_base,
            & toplevel_consts_20_consts_5._object.ob_base.ob_base,
            Py_False,
            & toplevel_consts_20_consts_7._ascii.ob_base,
            & toplevel_consts_20_consts_8._ascii.ob_base,
            Py_True,
            & toplevel_consts_20_consts_10._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_20_names_6 = {
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
        uint8_t _data[7];
    }
toplevel_consts_20_names_11 = {
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
        uint8_t _data[7];
    }
toplevel_consts_20_names_19 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[21];
        }_object;
    }
toplevel_consts_20_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 21,
        },
        .ob_item = {
            & toplevel_consts_11_names_1._ascii.ob_base,
            & toplevel_consts_19_names_0._ascii.ob_base,
            & toplevel_consts_20_consts_5_0._ascii.ob_base,
            & toplevel_consts_11_names_20._ascii.ob_base,
            & toplevel_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_consts_20_names_6._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_10_name._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_18_names_5._ascii.ob_base,
            & toplevel_consts_20_names_11._ascii.ob_base,
            & toplevel_consts_15_names_2._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_10_names_4._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
            & toplevel_consts_10_names_6._ascii.ob_base,
            & toplevel_consts_20_names_19._ascii.ob_base,
            & toplevel_consts_11_names_18._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_varnames_0 = {
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
    ._data = "path_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_20_varnames_5 = {
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
    ._data = "importer",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_20_varnames_6 = {
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
    ._data = "is_NullImporter",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_20_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_20_varnames_0._ascii.ob_base,
            & toplevel_consts_9_varnames_2._ascii.ob_base,
            & toplevel_consts_17_varnames_2._ascii.ob_base,
            & toplevel_consts_9_varnames_5._ascii.ob_base,
            & toplevel_consts_20_consts_5_0._ascii.ob_base,
            & toplevel_consts_20_varnames_5._ascii.ob_base,
            & toplevel_consts_20_varnames_6._ascii.ob_base,
            & toplevel_consts_9_varnames_0._ascii.ob_base,
            & toplevel_consts_9_varnames_8._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_varnames_4._ascii.ob_base,
            & toplevel_consts_10_varnames_7._ascii.ob_base,
            & toplevel_consts_10_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_20_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x0a\x04\x01\x10\x01\x0c\x01\x08\x01\x04\x02\x0e\x01\x0e\x01\x04\x01\x12\x01\x0e\x03\x08\x01\x04\x01\x06\xff\x10\x05\x02\x01\x0c\x07\x0a\x01\x06\x01\x04\xff\x08\x02\x08\x01\x06\x01\x02\xff\x06\x01\x18\xfc\x02\x06\x10\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x08\xf8\x06\x80\x1c\x00\x06\x80\x08\x00\x02\x06\x12\x01\x02\x80\x06\x01\x06\x01\x02\xff\x08\x80\x02\xfe\x10\x01\x02\x80\x06\x01\x04\x01\x02\xff\x0c\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_20_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0a\x06\x01\x10\x01\x0c\x01\x08\x01\x04\x02\x0c\x01\x02\x02\x0c\xff\x06\x01\x0c\x01\x02\x1b\x02\xe5\x02\x1b\x0e\xe8\x08\x01\x0a\x01\x10\x04\x02\x12\x0c\xf6\x06\x01\x02\x04\x02\xfc\x06\x01\x04\x03\x08\xfe\x08\x01\x26\x01\x02\x05\x10\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x08\xfb\x06\x80\x1c\x00\x06\x80\x08\x00\x02\x05\x12\xfe\x02\x80\x02\x01\x0c\x01\x08\x80\x02\x00\x10\xfe\x02\x80\x02\x01\x0a\x01\x0c\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[419];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 418,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x10\x05\x20\x14\x20\x09\x11\x10\x18\x10\x28\x24\x27\x10\x28\x10\x28\x29\x2a\x10\x2b\x05\x0d\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25\x05\x25\x10\x1c\x1d\x26\x10\x27\x05\x0d\x17\x1c\x05\x14\x08\x0c\x0d\x15\x08\x16\x08\x21\x25\x2a\x08\x2a\x05\x23\x0c\x10\x11\x19\x0c\x1a\x0c\x23\x27\x35\x0c\x35\x09\x23\x1f\x23\x0d\x1c\x08\x12\x13\x1b\x1d\x21\x22\x26\x1d\x27\x08\x28\x05\x15\x2c\x3b\x05\x15\x17\x2a\x2b\x33\x35\x3e\x17\x3f\x09\x14\x09\x0d\x0f\x14\x10\x20\x21\x25\x27\x33\x35\x3d\x2a\x32\x40\x45\x10\x46\x10\x46\x09\x46\x09\x0c\x09\x11\x09\x26\x19\x1a\x1c\x25\x09\x26\x09\x26\x09\x26\x09\x15\x28\x40\x28\x42\x0d\x25\x0d\x15\x17\x1f\x21\x25\x12\x1d\x1e\x26\x12\x27\x0d\x49\x2b\x36\x12\x20\x21\x2a\x12\x2b\x0d\x49\x0d\x49\x1f\x2a\x1f\x31\x1f\x3a\x11\x1c\x18\x21\x22\x26\x28\x33\x35\x41\x25\x2d\x2f\x37\x39\x41\x18\x42\x18\x49\x18\x49\x18\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x15\x11\x14\x11\x19\x11\x2b\x21\x2a\x11\x2b\x11\x2b\x11\x2b\x11\x2b\x00\x00\x14\x1e\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x00\x00\x00\x00\x00\x00\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x00\x00\x00\x00\x00\x00\x0d\x49\x0d\x49\x0d\x49\x0d\x49\x0d\x15\x11\x14\x11\x19\x11\x2b\x21\x2a\x11\x2b\x11\x2b\x11\x2b\x11\x2b\x11\x2b\x00\x00\x14\x1e\x0d\x15\x0d\x15\x11\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x15\x11\x14\x11\x19\x11\x2b\x21\x2a\x11\x2b\x11\x2b\x11\x2b\x11\x2b\x00\x00\x14\x1e\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[163];
    }
toplevel_consts_20_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 162,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x0b\x0a\x42\x3a\x00\xc1\x15\x05\x42\x1a\x03\xc1\x1a\x10\x42\x09\x05\xc1\x2a\x06\x42\x1a\x03\xc1\x30\x06\x42\x3a\x00\xc1\x37\x07\x41\x3f\x02\xc1\x3f\x04\x42\x06\x05\xc2\x05\x01\x42\x06\x05\xc2\x09\x04\x42\x0d\x09\xc2\x0d\x03\x42\x1a\x03\xc2\x10\x01\x42\x0d\x09\xc2\x11\x03\x42\x1a\x03\xc2\x14\x06\x42\x3a\x00\xc2\x1a\x04\x42\x1e\x07\xc2\x1e\x03\x42\x3a\x00\xc2\x21\x01\x42\x1e\x07\xc2\x22\x03\x42\x3a\x00\xc2\x26\x07\x42\x2f\x00\xc2\x2f\x04\x42\x37\x03\xc2\x36\x01\x42\x37\x03\xc2\x3a\x01\x43\x0e\x03\xc2\x3c\x07\x43\x04\x04\xc3\x03\x01\x43\x0e\x03\xc3\x04\x04\x43\x0b\x07\xc3\x08\x02\x43\x0e\x03\xc3\x0a\x01\x43\x0b\x07\xc3\x0b\x03\x43\x0e\x03",
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
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 9,
    .co_firstlineno = 247,
    .co_code = & toplevel_consts_20_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_11_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_4._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 13,
    .co_nlocals = 13,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_22 = {
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
        uint8_t _data[34];
    }
toplevel_consts_23 = {
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
    ._data = "No module specified for execution",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_24_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_24 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_24_0._ascii.ob_base,
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
toplevel_consts_25 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
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
toplevel_consts_27 = {
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
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_28 = {
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
            Py_None,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_4._ascii.ob_base,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_9.ob_base,
            & toplevel_consts_10.ob_base,
            & toplevel_consts_11.ob_base,
            & toplevel_consts_12.ob_base,
            & toplevel_consts_12_consts_0._ascii.ob_base,
            Py_True,
            & toplevel_consts_15.ob_base,
            Py_False,
            & toplevel_consts_17.ob_base,
            & toplevel_consts_18.ob_base,
            & toplevel_consts_19.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_11_consts_15._ascii.ob_base,
            & toplevel_consts_22.ob_base.ob_base,
            & toplevel_consts_23._ascii.ob_base,
            & toplevel_consts_24._object.ob_base.ob_base,
            & toplevel_consts_25._object.ob_base.ob_base,
            & toplevel_consts_26._object.ob_base.ob_base,
            & toplevel_consts_27._object.ob_base.ob_base,
            & toplevel_consts_28._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_names_2 = {
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
    ._data = "importlib.machinery",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_names_4 = {
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
    ._data = "importlib.util",
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
toplevel_names_17 = {
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
        uint8_t _data[4];
    }
toplevel_names_25 = {
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
        uint8_t _data[6];
    }
toplevel_names_27 = {
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
        uint8_t _data[7];
    }
toplevel_names_28 = {
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
    ._data = "stderr",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[29];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 29,
        },
        .ob_item = {
            & toplevel_consts_5_names_3._ascii.ob_base,
            & toplevel_consts_5_consts_3_names_3._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_consts_11_names_13._ascii.ob_base,
            & toplevel_names_4._ascii.ob_base,
            & toplevel_consts_19_names_6._ascii.ob_base,
            & toplevel_consts_19_names_2._ascii.ob_base,
            & toplevel_names_7._ascii.ob_base,
            & toplevel_consts_11_names_20._ascii.ob_base,
            & toplevel_consts_5_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_9_name._ascii.ob_base,
            & toplevel_consts_10_name._ascii.ob_base,
            & toplevel_consts_11_names_3._ascii.ob_base,
            & toplevel_consts_11_names_23._ascii.ob_base,
            & toplevel_names_17._ascii.ob_base,
            & toplevel_consts_12_consts_0._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_3._ascii.ob_base,
            & toplevel_consts_15_names_2._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_4._ascii.ob_base,
            & toplevel_consts_5_names_0._ascii.ob_base,
            & toplevel_names_25._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_4._ascii.ob_base,
            & toplevel_names_27._ascii.ob_base,
            & toplevel_names_28._ascii.ob_base,
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
        char ob_sval[71];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x08\x0c\x08\x01\x08\x01\x08\x01\x08\x01\x04\x03\x04\xff\x08\x05\x0e\x02\x0e\x17\x02\x10\x02\x01\x02\x01\x08\xfe\x02\x1a\x02\x01\x02\x01\x08\xfe\x0a\x0e\x0e\x3d\x08\x07\x02\x1c\x02\x01\x08\xff\x0a\x0f\x06\x13\x08\x0c\x08\x32\x0e\x02\x12\x01\x08\x02\x12\x01\x04\xfa",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[95];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x07\x08\x05\x08\x01\x08\x01\x08\x01\x08\x01\x04\x03\x02\x01\x02\xfe\x08\x05\x08\x17\x02\xeb\x04\x15\x08\x0f\x02\xf3\x04\x0d\x02\x03\x02\x01\x02\x01\x08\x16\x02\x02\x02\x01\x02\x01\x08\x09\x02\x03\x08\x3b\x08\x03\x02\xff\x04\x01\x02\x06\x06\x1a\x02\x02\x02\x01\x08\x0c\x02\x02\x08\x10\x06\x0d\x02\x02\x06\x2f\x06\x03\x02\x06\x0c\xfc\x02\x04\x12\xfd\x08\x02\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[257];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 256,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x0b\x01\x0b\x01\x0b\x01\x0b\x01\x1b\x01\x1b\x01\x1b\x01\x1b\x01\x16\x01\x16\x01\x16\x01\x16\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x05\x11\x13\x1d\x0b\x02\x01\x08\x0e\x12\x13\x16\x0e\x17\x01\x0b\x01\x20\x01\x20\x01\x20\x01\x20\x13\x19\x01\x20\x01\x20\x01\x28\x01\x28\x01\x28\x01\x28\x16\x1c\x01\x28\x01\x28\x2f\x33\x18\x1c\x18\x1c\x01\x17\x01\x17\x01\x17\x01\x17\x29\x2d\x1e\x22\x1e\x22\x01\x1e\x01\x1e\x01\x1e\x01\x1e\x29\x34\x01\x20\x01\x20\x01\x20\x01\x20\x01\x4d\x01\x4d\x01\x4d\x01\x4d\x0e\x17\x01\x4d\x01\x4d\x2e\x32\x01\x2b\x01\x2b\x01\x2b\x27\x2b\x19\x1d\x01\x45\x01\x45\x01\x45\x01\x45\x24\x2f\x01\x2c\x01\x2c\x01\x2c\x01\x2c\x01\x17\x01\x17\x01\x17\x26\x2a\x01\x15\x01\x15\x01\x15\x04\x0c\x10\x1a\x04\x1a\x01\x29\x08\x0b\x0c\x0f\x0c\x14\x08\x15\x18\x19\x08\x19\x05\x29\x09\x0e\x0f\x32\x39\x3c\x39\x43\x09\x44\x09\x44\x09\x44\x09\x44\x09\x44\x0d\x10\x0d\x15\x16\x17\x0d\x18\x09\x1c\x1d\x20\x1d\x25\x26\x27\x1d\x28\x09\x29\x09\x29\x09\x29\x09\x29\x01\x29\x01\x29",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_5_consts_2_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_5_consts_2_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_5_consts_2_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_runpy_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

