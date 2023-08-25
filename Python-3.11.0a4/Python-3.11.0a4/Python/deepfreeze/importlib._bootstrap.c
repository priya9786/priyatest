#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[389];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 388,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x84\x00\x5a\x01\x64\x02\x5a\x02\x64\x02\x5a\x03\x64\x02\x5a\x04\x64\x02\x61\x05\x64\x03\x84\x00\x5a\x06\x64\x04\x84\x00\x5a\x07\x69\x00\x5a\x08\x69\x00\x5a\x09\x47\x00\x64\x05\x84\x00\x64\x06\x65\x0a\xa9\x03\x5a\x0b\x47\x00\x64\x07\x84\x00\x64\x08\xa9\x02\x5a\x0c\x47\x00\x64\x09\x84\x00\x64\x0a\xa9\x02\x5a\x0d\x47\x00\x64\x0b\x84\x00\x64\x0c\xa9\x02\x5a\x0e\x64\x0d\x84\x00\x5a\x0f\x64\x0e\x84\x00\x5a\x10\x64\x0f\x84\x00\x5a\x11\x64\x10\x64\x11\x9c\x01\x64\x12\x84\x02\x5a\x12\x64\x13\x84\x00\x5a\x13\x64\x14\x84\x00\x5a\x14\x64\x15\x84\x00\x5a\x15\x64\x16\x84\x00\x5a\x16\x47\x00\x64\x17\x84\x00\x64\x18\xa9\x02\x5a\x17\x64\x02\x64\x02\x64\x19\x9c\x02\x64\x1a\x84\x02\x5a\x18\x64\x3e\x64\x1b\x84\x01\x5a\x19\x64\x1c\x64\x1d\x9c\x01\x64\x1e\x84\x02\x5a\x1a\x64\x1f\x84\x00\x5a\x1b\x64\x20\x84\x00\x5a\x1c\x64\x21\x84\x00\x5a\x1d\x64\x22\x84\x00\x5a\x1e\x64\x23\x84\x00\x5a\x1f\x64\x24\x84\x00\x5a\x20\x47\x00\x64\x25\x84\x00\x64\x26\xa9\x02\x5a\x21\x47\x00\x64\x27\x84\x00\x64\x28\xa9\x02\x5a\x22\x47\x00\x64\x29\x84\x00\x64\x2a\xa9\x02\x5a\x23\x64\x2b\x84\x00\x5a\x24\x64\x2c\x84\x00\x5a\x25\x64\x3f\x64\x2d\x84\x01\x5a\x26\x64\x2e\x84\x00\x5a\x27\x64\x2f\x5a\x28\x65\x28\x64\x30\x7a\x00\x5a\x29\x64\x31\x84\x00\x5a\x2a\x65\x2b\xa9\x00\x5a\x2c\x64\x32\x84\x00\x5a\x2d\x64\x40\x64\x34\x84\x01\x5a\x2e\x64\x1c\x64\x35\x9c\x01\x64\x36\x84\x02\x5a\x2f\x64\x37\x84\x00\x5a\x30\x64\x41\x64\x39\x84\x01\x5a\x31\x64\x3a\x84\x00\x5a\x32\x64\x3b\x84\x00\x5a\x33\x64\x3c\x84\x00\x5a\x34\x64\x3d\x84\x00\x5a\x35\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[340];
    }
toplevel_consts_0 = {
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
    ._data = "\x43\x6f\x72\x65\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x69\x6d\x70\x6f\x72\x74\x2e\x0a\x0a\x54\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x4e\x4f\x54\x20\x6d\x65\x61\x6e\x74\x20\x74\x6f\x20\x62\x65\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x21\x20\x49\x74\x20\x68\x61\x73\x20\x62\x65\x65\x6e\x20\x64\x65\x73\x69\x67\x6e\x65\x64\x20\x73\x75\x63\x68\x0a\x74\x68\x61\x74\x20\x69\x74\x20\x63\x61\x6e\x20\x62\x65\x20\x62\x6f\x6f\x74\x73\x74\x72\x61\x70\x70\x65\x64\x20\x69\x6e\x74\x6f\x20\x50\x79\x74\x68\x6f\x6e\x20\x61\x73\x20\x74\x68\x65\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x69\x6d\x70\x6f\x72\x74\x2e\x20\x41\x73\x0a\x73\x75\x63\x68\x20\x69\x74\x20\x72\x65\x71\x75\x69\x72\x65\x73\x20\x74\x68\x65\x20\x69\x6e\x6a\x65\x63\x74\x69\x6f\x6e\x20\x6f\x66\x20\x73\x70\x65\x63\x69\x66\x69\x63\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x61\x6e\x64\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x73\x20\x69\x6e\x20\x6f\x72\x64\x65\x72\x20\x74\x6f\x0a\x77\x6f\x72\x6b\x2e\x20\x4f\x6e\x65\x20\x73\x68\x6f\x75\x6c\x64\x20\x75\x73\x65\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x20\x61\x73\x20\x74\x68\x65\x20\x70\x75\x62\x6c\x69\x63\x2d\x66\x61\x63\x69\x6e\x67\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x69\x73\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x6a\x00\x53\x00\x23\x00\x74\x01\x79\x10\x01\x00\x74\x02\x7c\x00\xa9\x01\x6a\x00\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_1_consts = {
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
        uint8_t _data[13];
    }
toplevel_consts_1_names_0 = {
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
        uint8_t _data[15];
    }
toplevel_consts_1_names_1 = {
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
        uint8_t _data[5];
    }
toplevel_consts_1_names_2 = {
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
toplevel_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_1_varnames_0 = {
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
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_1_varnames_0._ascii.ob_base,
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
toplevel_consts_1_freevars = {
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
        uint8_t _data[30];
    }
toplevel_consts_1_filename = {
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
    ._data = "<frozen importlib._bootstrap>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_1_name = {
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
    ._data = "_object_name",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x01\x06\x01\x02\x80\x06\x01\x0e\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x06\xfe\x02\x80\x02\x01\x14\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x26\x10\x13\x10\x20\x09\x20\x00\x00\x0c\x1a\x05\x26\x05\x26\x10\x14\x15\x18\x10\x19\x10\x26\x09\x26\x09\x26\x09\x26\x05\x26\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_1_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x02\x05\x00\x85\x09\x11\x03\x90\x01\x11\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 23,
    .co_code = & toplevel_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_1_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x44\x00\x5d\x10\x7d\x02\x74\x00\x7c\x01\x7c\x02\xa9\x02\x72\x13\x74\x01\x7c\x00\x7c\x02\x74\x02\x7c\x01\x7c\x02\xa9\x02\xa9\x03\x01\x00\x71\x03\x7c\x00\x6a\x03\xa0\x04\x7c\x01\x6a\x03\xa8\x01\xa9\x01\x01\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[48];
    }
toplevel_consts_3_consts_0 = {
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
    ._data = "Simple substitute for functools.update_wrapper.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_3_consts_1_0 = {
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
        uint8_t _data[9];
    }
toplevel_consts_3_consts_1_1 = {
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
toplevel_consts_3_consts_1_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_3_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
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
toplevel_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_3_consts_1._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_names_0 = {
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
        uint8_t _data[8];
    }
toplevel_consts_3_names_1 = {
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
    ._data = "setattr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_names_2 = {
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
toplevel_consts_3_names_3 = {
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
        uint8_t _data[7];
    }
toplevel_consts_3_names_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_3_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_3_varnames_0 = {
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
    ._data = "new",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_3_varnames_1 = {
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
    ._data = "old",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_3_varnames_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_3_name = {
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
    ._data = "_wrap",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x0a\x01\x12\x01\x02\x80\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x04\x02\x02\xfe\x08\x01\x14\x01\x02\x80\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x49\x05\x39\x05\x39\x09\x10\x0c\x13\x14\x17\x19\x20\x0c\x21\x09\x39\x0d\x14\x15\x18\x1a\x21\x23\x2a\x2b\x2e\x30\x37\x23\x38\x0d\x39\x0d\x39\x00\x00\x05\x08\x05\x11\x05\x26\x19\x1c\x19\x25\x05\x26\x05\x26\x05\x26\x05\x26\x05\x26",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_3_exceptiontable = {
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
toplevel_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 40,
    .co_code = & toplevel_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_3_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x74\x01\xa9\x01\x7c\x00\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_4_names_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
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
    ._data = "name",
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_4_name = {
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
    ._data = "_new_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_4_linetable = {
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
toplevel_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x11\x14\x0c\x15\x16\x1a\x0c\x1b\x05\x1b",
};
static struct PyCodeObject toplevel_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 48,
    .co_code = & toplevel_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_5_consts_0 = {
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
    ._data = "_DeadlockError",
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
            Py_None,
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
toplevel_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x09\x05\x09",
};
static struct PyCodeObject toplevel_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 61,
    .co_code = & toplevel_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_5_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_5_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_5_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x84\x00\x5a\x08\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_7_consts_0 = {
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
    ._data = "_ModuleLock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[170];
    }
toplevel_consts_7_consts_1 = {
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
    ._data = "\x41\x20\x72\x65\x63\x75\x72\x73\x69\x76\x65\x20\x6c\x6f\x63\x6b\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x77\x68\x69\x63\x68\x20\x69\x73\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x64\x65\x74\x65\x63\x74\x20\x64\x65\x61\x64\x6c\x6f\x63\x6b\x73\x0a\x20\x20\x20\x20\x28\x65\x2e\x67\x2e\x20\x74\x68\x72\x65\x61\x64\x20\x31\x20\x74\x72\x79\x69\x6e\x67\x20\x74\x6f\x20\x74\x61\x6b\x65\x20\x6c\x6f\x63\x6b\x73\x20\x41\x20\x74\x68\x65\x6e\x20\x42\x2c\x20\x61\x6e\x64\x20\x74\x68\x72\x65\x61\x64\x20\x32\x20\x74\x72\x79\x69\x6e\x67\x20\x74\x6f\x0a\x20\x20\x20\x20\x74\x61\x6b\x65\x20\x6c\x6f\x63\x6b\x73\x20\x42\x20\x74\x68\x65\x6e\x20\x41\x29\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_7_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x7c\x00\x5f\x02\x74\x00\xa0\x01\xa8\x00\xa9\x00\x7c\x00\x5f\x03\x7c\x01\x7c\x00\x5f\x04\x64\x00\x7c\x00\x5f\x05\x64\x01\x7c\x00\x5f\x06\x64\x01\x7c\x00\x5f\x07\x64\x00\x53\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_7_consts_2_consts_1 = {
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
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_7_consts_2_names_0 = {
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
    ._data = "_thread",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_7_consts_2_names_1 = {
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
    ._data = "allocate_lock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_2_names_2 = {
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
    ._data = "lock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_7_consts_2_names_3 = {
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
    ._data = "wakeup",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_7_consts_2_names_5 = {
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
    ._data = "owner",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_7_consts_2_names_6 = {
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
        uint8_t _data[8];
    }
toplevel_consts_7_consts_2_names_7 = {
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
    ._data = "waiters",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_7_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_2_varnames_0 = {
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
toplevel_consts_7_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_7_consts_2_name = {
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
toplevel_consts_7_consts_2_qualname = {
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
    ._data = "_ModuleLock.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_7_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0c\x01\x06\x01\x06\x01\x06\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_7_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x1c\x15\x2c\x15\x2c\x15\x2c\x09\x0d\x09\x12\x17\x1e\x17\x2e\x17\x2e\x17\x2e\x09\x0d\x09\x14\x15\x19\x09\x0d\x09\x12\x16\x1a\x09\x0d\x09\x13\x16\x17\x09\x0d\x09\x13\x18\x19\x09\x0d\x09\x15\x09\x15\x09\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_7_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_7_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 71,
    .co_code = & toplevel_consts_7_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[91];
    }
toplevel_consts_7_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 90,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x7d\x01\x7c\x00\x6a\x02\x7d\x02\x74\x03\xa9\x00\x7d\x03\x09\x00\x74\x04\xa0\x05\x7c\x02\xa8\x01\xa9\x01\x7d\x04\x7c\x04\x80\x17\x64\x02\x53\x00\x7c\x04\x6a\x02\x7d\x02\x7c\x02\x7c\x01\x6b\x02\x72\x20\x64\x01\x53\x00\x7c\x02\x7c\x03\x76\x00\x72\x26\x64\x02\x53\x00\x7c\x03\xa0\x06\x7c\x02\xa8\x01\xa9\x01\x01\x00\x71\x0d",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_7_consts_3_consts = {
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
        uint8_t _data[10];
    }
toplevel_consts_7_consts_3_names_1 = {
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
    ._data = "get_ident",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_7_consts_3_names_3 = {
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
        uint8_t _data[13];
    }
toplevel_consts_7_consts_3_names_4 = {
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
    ._data = "_blocking_on",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_7_consts_3_names_5 = {
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
        uint8_t _data[4];
    }
toplevel_consts_7_consts_3_names_6 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_7_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_7_consts_3_varnames_1 = {
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
    ._data = "me",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_7_consts_3_varnames_2 = {
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
    ._data = "tid",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_7_consts_3_varnames_3 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_7_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_7_consts_3_name = {
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
    ._data = "has_deadlock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_7_consts_3_qualname = {
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
    ._data = "_ModuleLock.has_deadlock",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_7_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x06\x01\x06\x01\x02\x01\x0c\x01\x04\x01\x04\x01\x06\x01\x08\x01\x04\x01\x08\x01\x04\x06\x0c\x01\x02\xf2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_7_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x06\x01\x06\x01\x02\x01\x0c\x01\x02\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x01\x06\x06\x0c\x01\x02\xf2",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[91];
    }
toplevel_consts_7_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 90,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x15\x0e\x21\x0e\x21\x0e\x21\x09\x0b\x0f\x13\x0f\x19\x09\x0c\x10\x13\x10\x15\x09\x0d\x0f\x13\x14\x20\x14\x29\x25\x28\x14\x29\x14\x29\x0d\x11\x10\x14\x0d\x1d\x18\x1d\x18\x1d\x13\x17\x13\x1d\x0d\x10\x10\x13\x17\x19\x10\x19\x0d\x1c\x18\x1c\x18\x1c\x10\x13\x17\x1b\x10\x1b\x0d\x1d\x18\x1d\x18\x1d\x0d\x11\x0d\x1a\x16\x19\x0d\x1a\x0d\x1a\x0d\x1a\x0f\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[6];
    }
toplevel_consts_7_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_7_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 79,
    .co_code = & toplevel_consts_7_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[221];
    }
toplevel_consts_7_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 220,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x7d\x01\x7c\x00\x74\x02\x7c\x01\x3c\x00\x09\x00\x09\x00\x7c\x00\x6a\x03\x35\x00\x01\x00\x7c\x00\x6a\x04\x64\x02\x6b\x02\x73\x1a\x7c\x00\x6a\x05\x7c\x01\x6b\x02\x72\x2f\x7c\x01\x7c\x00\x5f\x05\x7c\x00\x04\x00\x6a\x04\x64\x03\x7a\x0d\x02\x00\x5f\x04\x09\x00\x64\x04\x04\x00\x04\x00\xa9\x03\x01\x00\x74\x02\x7c\x01\x3d\x00\x64\x01\x53\x00\x7c\x00\xa0\x06\xa8\x00\xa9\x00\x72\x3a\x74\x07\x64\x05\x7c\x00\x7a\x06\xa9\x01\x82\x01\x7c\x00\x6a\x08\xa0\x09\x64\x06\xa8\x01\xa9\x01\x72\x48\x7c\x00\x04\x00\x6a\x0a\x64\x03\x7a\x0d\x02\x00\x5f\x0a\x64\x04\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x55\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x00\x6a\x08\xa0\x09\xa8\x00\xa9\x00\x01\x00\x7c\x00\x6a\x08\xa0\x0b\xa8\x00\xa9\x00\x01\x00\x71\x0c\x23\x00\x74\x02\x7c\x01\x3d\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[186];
    }
toplevel_consts_7_consts_4_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 185,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x41\x63\x71\x75\x69\x72\x65\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6c\x6f\x63\x6b\x2e\x20\x20\x49\x66\x20\x61\x20\x70\x6f\x74\x65\x6e\x74\x69\x61\x6c\x20\x64\x65\x61\x64\x6c\x6f\x63\x6b\x20\x69\x73\x20\x64\x65\x74\x65\x63\x74\x65\x64\x2c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x61\x20\x5f\x44\x65\x61\x64\x6c\x6f\x63\x6b\x45\x72\x72\x6f\x72\x20\x69\x73\x20\x72\x61\x69\x73\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x4f\x74\x68\x65\x72\x77\x69\x73\x65\x2c\x20\x74\x68\x65\x20\x6c\x6f\x63\x6b\x20\x69\x73\x20\x61\x6c\x77\x61\x79\x73\x20\x61\x63\x71\x75\x69\x72\x65\x64\x20\x61\x6e\x64\x20\x54\x72\x75\x65\x20\x69\x73\x20\x72\x65\x74\x75\x72\x6e\x65\x64\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_7_consts_4_consts_3 = {
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
        uint8_t _data[24];
    }
toplevel_consts_7_consts_4_consts_5 = {
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
    ._data = "deadlock detected by %r",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_7_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_7_consts_4_consts_0._ascii.ob_base,
            Py_True,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
            Py_None,
            & toplevel_consts_7_consts_4_consts_5._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_7_consts_4_names_9 = {
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
    ._data = "acquire",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_7_consts_4_names_11 = {
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
    ._data = "release",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_7_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_name._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_7._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
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
toplevel_consts_7_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_7_consts_4_qualname = {
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
    ._data = "_ModuleLock.acquire",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_7_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x08\x01\x02\x01\x02\x01\x08\x01\x14\x01\x06\x01\x0e\x01\x02\x01\x0a\xfc\x0a\x0d\x0a\xf8\x0c\x01\x0e\x01\x0e\x01\x14\xf8\x06\x80\x08\x00\x0c\x0a\x0c\x01\x02\xf4\x02\x80\x0e\x0e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_7_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x08\x01\x02\x10\x02\xf2\x04\x01\x04\x08\x08\xf9\x02\x03\x08\xfd\x02\x03\x06\xfe\x0e\x01\x02\x01\x0a\x04\x0a\x05\x08\xf8\x0e\x01\x0c\x01\x24\x01\x06\x80\x08\x00\x0c\x02\x0c\x01\x02\xf4\x02\x80\x0e\x0e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[221];
    }
toplevel_consts_7_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 220,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x16\x0f\x22\x0f\x22\x0f\x22\x09\x0c\x1d\x21\x09\x15\x16\x19\x09\x1a\x09\x22\x13\x17\x16\x1a\x16\x1f\x11\x2a\x11\x2a\x18\x1c\x18\x22\x26\x27\x18\x27\x15\x24\x2b\x2f\x2b\x35\x39\x3c\x2b\x3c\x15\x24\x26\x29\x19\x1d\x19\x23\x19\x1d\x19\x23\x19\x23\x27\x28\x19\x28\x19\x23\x19\x23\x20\x24\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x1d\x1e\x21\x11\x22\x11\x22\x11\x22\x18\x1c\x18\x2b\x18\x2b\x18\x2b\x15\x4f\x1f\x2d\x2e\x47\x4a\x4e\x2e\x4e\x1f\x4f\x19\x4f\x18\x1c\x18\x23\x18\x32\x2c\x31\x18\x32\x18\x32\x15\x2a\x19\x1d\x19\x25\x19\x25\x29\x2a\x19\x2a\x19\x25\x19\x25\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x00\x00\x00\x00\x00\x00\x11\x2a\x11\x2a\x11\x2a\x11\x2a\x11\x15\x11\x1c\x11\x26\x11\x26\x11\x26\x11\x26\x11\x15\x11\x1c\x11\x26\x11\x26\x11\x26\x11\x26\x13\x17\x00\x00\x11\x1d\x1e\x21\x11\x22\x0d\x22\x0d\x22\x0d\x22\x0d\x22",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_7_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x8b\x04\x41\x26\x00\x8f\x16\x41\x0e\x03\xa5\x05\x41\x26\x00\xaf\x19\x41\x0e\x03\xc1\x08\x06\x41\x26\x00\xc1\x0e\x04\x41\x12\x07\xc1\x12\x03\x41\x26\x00\xc1\x15\x01\x41\x12\x07\xc1\x16\x10\x41\x26\x00\xc1\x26\x05\x41\x2b\x03",
};
static struct PyCodeObject toplevel_consts_7_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 100,
    .co_code = & toplevel_consts_7_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[189];
    }
toplevel_consts_7_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 188,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x7d\x01\x7c\x00\x6a\x02\x35\x00\x01\x00\x7c\x00\x6a\x03\x7c\x01\x6b\x03\x72\x13\x74\x04\x64\x01\xa9\x01\x82\x01\x7c\x00\x6a\x05\x64\x02\x6b\x04\x73\x1a\x4a\x00\x82\x01\x7c\x00\x04\x00\x6a\x05\x64\x03\x7a\x17\x02\x00\x5f\x05\x7c\x00\x6a\x05\x64\x02\x6b\x02\x72\x41\x64\x00\x7c\x00\x5f\x03\x7c\x00\x6a\x06\x72\x49\x7c\x00\x04\x00\x6a\x06\x64\x03\x7a\x17\x02\x00\x5f\x06\x7c\x00\x6a\x07\xa0\x08\xa8\x00\xa9\x00\x01\x00\x09\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x64\x00\x53\x00\x09\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x64\x00\x53\x00\x09\x00\x64\x00\x04\x00\x04\x00\xa9\x03\x01\x00\x64\x00\x53\x00\x23\x00\x31\x00\x73\x58\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_7_consts_5_consts_1 = {
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
    ._data = "cannot release un-acquired lock",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_7_consts_5_consts = {
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
            & toplevel_consts_7_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_7_consts_5_names_4 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_7_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_7._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_7_consts_5_qualname = {
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
    ._data = "_ModuleLock.release",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_7_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x08\x01\x0a\x01\x08\x01\x0e\x01\x0e\x01\x0a\x01\x06\x01\x06\x01\x0e\x01\x0e\x01\x0e\xf7\x02\x05\x0e\xfb\x02\x07\x16\xf9\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_7_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x04\x01\x04\x09\x08\xf8\x0a\x01\x0e\x01\x0e\x01\x08\x01\x02\x04\x06\xfd\x04\x01\x02\x02\x0e\xff\x44\x01\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[189];
    }
toplevel_consts_7_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 188,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x16\x0f\x22\x0f\x22\x0f\x22\x09\x0c\x0e\x12\x0e\x17\x09\x2a\x09\x2a\x10\x14\x10\x1a\x1e\x21\x10\x21\x0d\x46\x17\x23\x24\x45\x17\x46\x11\x46\x14\x18\x14\x1e\x21\x22\x14\x22\x0d\x22\x0d\x22\x0d\x22\x0d\x11\x0d\x17\x0d\x17\x1b\x1c\x0d\x1c\x0d\x17\x0d\x17\x10\x14\x10\x1a\x1e\x1f\x10\x1f\x0d\x2a\x1e\x22\x11\x15\x11\x1b\x14\x18\x14\x20\x11\x2a\x15\x19\x15\x21\x15\x21\x25\x26\x15\x26\x15\x21\x15\x21\x15\x19\x15\x20\x15\x2a\x15\x2a\x15\x2a\x15\x2a\x15\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x0d\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x11\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x00\x00\x00\x00\x00\x00\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a\x09\x2a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[18];
    }
toplevel_consts_7_consts_5_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 17,
    },
    .ob_shash = -1,
    .ob_sval = "\x89\x30\x41\x11\x03\xc1\x11\x04\x41\x15\x07\xc1\x18\x01\x41\x15\x07",
};
static struct PyCodeObject toplevel_consts_7_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_7_consts_5_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 125,
    .co_code = & toplevel_consts_7_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_7_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\xa0\x00\x7c\x00\x6a\x01\x74\x02\x7c\x00\xa9\x01\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_7_consts_6_consts_1 = {
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
    ._data = "_ModuleLock({!r}) at {}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_7_consts_6_consts = {
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
            & toplevel_consts_7_consts_6_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_7_consts_6_names_0 = {
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
        uint8_t _data[3];
    }
toplevel_consts_7_consts_6_names_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_7_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_2._ascii.ob_base,
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
toplevel_consts_7_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_7_consts_6_name = {
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
        uint8_t _data[21];
    }
toplevel_consts_7_consts_6_qualname = {
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
    ._data = "_ModuleLock.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_7_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_7_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x29\x10\x45\x31\x35\x31\x3a\x3c\x3e\x3f\x43\x3c\x44\x10\x45\x10\x45\x09\x45",
};
static struct PyCodeObject toplevel_consts_7_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 138,
    .co_code = & toplevel_consts_7_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_7_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_7_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_7_consts_2.ob_base,
            & toplevel_consts_7_consts_3.ob_base,
            & toplevel_consts_7_consts_4.ob_base,
            & toplevel_consts_7_consts_5.ob_base,
            & toplevel_consts_7_consts_6.ob_base,
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
toplevel_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_name._ascii.ob_base,
            & toplevel_consts_7_consts_3_name._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
            & toplevel_consts_7_consts_6_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x06\x05\x06\x08\x06\x15\x06\x19\x0a\x0d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x04\x06\x08\x06\x15\x06\x19\x06\x0d\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x05\x19\x05\x19\x05\x19\x05\x1a\x05\x1a\x05\x1a\x05\x22\x05\x22\x05\x22\x05\x2a\x05\x2a\x05\x2a\x05\x45\x05\x45\x05\x45\x05\x45\x05\x45",
};
static struct PyCodeObject toplevel_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 65,
    .co_code = & toplevel_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x84\x00\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_9_consts_0 = {
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
    ._data = "_DummyModuleLock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[87];
    }
toplevel_consts_9_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 86,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x73\x69\x6d\x70\x6c\x65\x20\x5f\x4d\x6f\x64\x75\x6c\x65\x4c\x6f\x63\x6b\x20\x65\x71\x75\x69\x76\x61\x6c\x65\x6e\x74\x20\x66\x6f\x72\x20\x50\x79\x74\x68\x6f\x6e\x20\x62\x75\x69\x6c\x64\x73\x20\x77\x69\x74\x68\x6f\x75\x74\x0a\x20\x20\x20\x20\x6d\x75\x6c\x74\x69\x2d\x74\x68\x72\x65\x61\x64\x69\x6e\x67\x20\x73\x75\x70\x70\x6f\x72\x74\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_9_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x64\x01\x7c\x00\x5f\x01\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_9_consts_2_names = {
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
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_9_consts_2_qualname = {
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
    ._data = "_DummyModuleLock.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_9_consts_2_linetable = {
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
toplevel_consts_9_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x19\x09\x0d\x09\x12\x16\x17\x09\x0d\x09\x13\x09\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_9_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_7_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 146,
    .co_code = & toplevel_consts_9_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_9_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x04\x00\x6a\x00\x64\x01\x7a\x0d\x02\x00\x5f\x00\x64\x02\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_9_consts_3_consts = {
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
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
            Py_True,
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
toplevel_consts_9_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_9_consts_3_qualname = {
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
    ._data = "_DummyModuleLock.acquire",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_9_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_9_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x13\x09\x13\x17\x18\x09\x18\x09\x13\x09\x13\x10\x14\x10\x14",
};
static struct PyCodeObject toplevel_consts_9_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 150,
    .co_code = & toplevel_consts_9_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_9_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x64\x01\x6b\x02\x72\x0a\x74\x01\x64\x02\xa9\x01\x82\x01\x7c\x00\x04\x00\x6a\x00\x64\x03\x7a\x17\x02\x00\x5f\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_9_consts_4_consts = {
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
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_7_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
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
toplevel_consts_9_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_6._ascii.ob_base,
            & toplevel_consts_7_consts_5_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_9_consts_4_qualname = {
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
    ._data = "_DummyModuleLock.release",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_9_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x08\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_9_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x01\x0a\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_9_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x16\x1a\x1b\x0c\x1b\x09\x42\x13\x1f\x20\x41\x13\x42\x0d\x42\x09\x0d\x09\x13\x09\x13\x17\x18\x09\x18\x09\x13\x09\x13\x09\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_9_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 154,
    .co_code = & toplevel_consts_9_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_9_consts_5_consts_1 = {
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
    ._data = "_DummyModuleLock({!r}) at {}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_9_consts_5_consts = {
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
            & toplevel_consts_9_consts_5_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_9_consts_5_qualname = {
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
    ._data = "_DummyModuleLock.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_9_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x2e\x10\x4a\x36\x3a\x36\x3f\x41\x43\x44\x48\x41\x49\x10\x4a\x10\x4a\x09\x4a",
};
static struct PyCodeObject toplevel_consts_9_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_7_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_7_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 159,
    .co_code = & toplevel_consts_7_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_7_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_7_consts_6_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_9_consts_1._ascii.ob_base,
            & toplevel_consts_9_consts_2.ob_base,
            & toplevel_consts_9_consts_3.ob_base,
            & toplevel_consts_9_consts_4.ob_base,
            & toplevel_consts_9_consts_5.ob_base,
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
toplevel_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_name._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
            & toplevel_consts_7_consts_6_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x06\x03\x06\x04\x06\x04\x0a\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x04\x06\x04\x06\x05\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x20\x05\x20\x05\x17\x05\x17\x05\x17\x05\x14\x05\x14\x05\x14\x05\x18\x05\x18\x05\x18\x05\x4a\x05\x4a\x05\x4a\x05\x4a\x05\x4a",
};
static struct PyCodeObject toplevel_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 142,
    .co_code = & toplevel_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_9_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_9_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_11_code = {
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
        uint8_t _data[19];
    }
toplevel_consts_11_consts_0 = {
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
    ._data = "_ModuleLockManager",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_11_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x64\x00\x7c\x00\x5f\x01\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_consts_1_names_0 = {
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
    ._data = "_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_11_consts_1_names_1 = {
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
    ._data = "_lock",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_11_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_11_consts_1_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_11_consts_1_qualname = {
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
    ._data = "_ModuleLockManager.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_11_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x1a\x09\x0d\x09\x13\x16\x1a\x09\x0d\x09\x13\x09\x13\x09\x13",
};
static struct PyCodeObject toplevel_consts_11_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 165,
    .co_code = & toplevel_consts_11_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_9_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_9_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_11_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x7c\x00\x5f\x02\x7c\x00\x6a\x02\xa0\x03\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_11_consts_2_names_0 = {
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
    ._data = "_get_module_lock",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_11_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_11_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_11_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_11_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_11_consts_2_name = {
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
        uint8_t _data[29];
    }
toplevel_consts_11_consts_2_qualname = {
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
    ._data = "_ModuleLockManager.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_11_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_11_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x16\x26\x27\x2b\x27\x31\x16\x32\x09\x0d\x09\x13\x09\x0d\x09\x13\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d",
};
static struct PyCodeObject toplevel_consts_11_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 169,
    .co_code = & toplevel_consts_11_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_11_consts_3_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_11_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_11_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_11_consts_3_varnames_1 = {
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
toplevel_consts_11_consts_3_varnames_2 = {
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
toplevel_consts_11_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_11_consts_3_name = {
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
        uint8_t _data[28];
    }
toplevel_consts_11_consts_3_qualname = {
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
    ._data = "_ModuleLockManager.__exit__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_11_consts_3_linetable = {
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
toplevel_consts_11_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x13\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d\x09\x1d",
};
static struct PyCodeObject toplevel_consts_11_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 15,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 173,
    .co_code = & toplevel_consts_11_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_11_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_11_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_1.ob_base,
            & toplevel_consts_11_consts_2.ob_base,
            & toplevel_consts_11_consts_3.ob_base,
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
toplevel_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_name._ascii.ob_base,
            & toplevel_consts_11_consts_2_name._ascii.ob_base,
            & toplevel_consts_11_consts_3_name._ascii.ob_base,
        },
    },
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
    .ob_sval = "\x0a\x00\x06\x02\x06\x04\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_11_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x06\x04\x06\x04\x0a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x1a\x05\x1a\x05\x1a\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x05\x1d\x05\x1d",
};
static struct PyCodeObject toplevel_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 163,
    .co_code = & toplevel_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_11_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[159];
    }
toplevel_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 158,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x09\x00\x09\x00\x74\x02\x7c\x00\x19\x00\xa9\x00\x7d\x01\x6e\x0c\x23\x00\x74\x03\x79\x16\x01\x00\x64\x01\x7d\x01\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x80\x3d\x74\x04\x80\x23\x74\x05\x7c\x00\xa9\x01\x7d\x01\x6e\x04\x74\x06\x7c\x00\xa9\x01\x7d\x01\x7c\x00\x66\x01\x64\x02\x84\x01\x7d\x02\x74\x07\xa0\x08\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x74\x02\x7c\x00\x3c\x00\x09\x00\x74\x00\xa0\x09\xa8\x00\xa9\x00\x01\x00\x7c\x01\x53\x00\x09\x00\x74\x00\xa0\x09\xa8\x00\xa9\x00\x01\x00\x7c\x01\x53\x00\x23\x00\x74\x00\xa0\x09\xa8\x00\xa9\x00\x01\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[140];
    }
toplevel_consts_13_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 139,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x47\x65\x74\x20\x6f\x72\x20\x63\x72\x65\x61\x74\x65\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6c\x6f\x63\x6b\x20\x66\x6f\x72\x20\x61\x20\x67\x69\x76\x65\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x41\x63\x71\x75\x69\x72\x65\x2f\x72\x65\x6c\x65\x61\x73\x65\x20\x69\x6e\x74\x65\x72\x6e\x61\x6c\x6c\x79\x20\x74\x68\x65\x20\x67\x6c\x6f\x62\x61\x6c\x20\x69\x6d\x70\x6f\x72\x74\x20\x6c\x6f\x63\x6b\x20\x74\x6f\x20\x70\x72\x6f\x74\x65\x63\x74\x0a\x20\x20\x20\x20\x5f\x6d\x6f\x64\x75\x6c\x65\x5f\x6c\x6f\x63\x6b\x73\x2e",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_13_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x09\x00\x74\x02\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x7c\x00\x75\x00\x72\x1a\x74\x02\x7c\x01\x3d\x00\x09\x00\x74\x00\xa0\x04\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00\x09\x00\x74\x00\xa0\x04\xa8\x00\xa9\x00\x01\x00\x64\x00\x53\x00\x23\x00\x74\x00\xa0\x04\xa8\x00\xa9\x00\x01\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_13_consts_2_names_0 = {
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
        uint8_t _data[13];
    }
toplevel_consts_13_consts_2_names_1 = {
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
    ._data = "acquire_lock",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_13_consts_2_names_2 = {
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
    ._data = "_module_locks",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_13_consts_2_names_4 = {
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
    ._data = "release_lock",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_13_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_13_consts_2_varnames_0 = {
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
    ._data = "ref",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_13_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_13_consts_2_name = {
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
    ._data = "cb",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_13_consts_2_qualname = {
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
    ._data = "_get_module_lock.<locals>.cb",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_13_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x02\x01\x10\x04\x08\x01\x0e\x02\x02\xfd\x0e\x03\x02\x80\x0c\x00\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_13_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x01\x02\x08\x0e\xfd\x0a\x01\x0e\x02\x02\xfe\x0e\x02\x02\x80\x0c\x00\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_13_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x15\x11\x24\x11\x24\x11\x24\x11\x24\x11\x28\x18\x25\x18\x2f\x2a\x2e\x18\x2f\x18\x2f\x33\x36\x18\x36\x15\x30\x1d\x2a\x2b\x2f\x1d\x30\x1d\x30\x15\x19\x15\x28\x15\x28\x15\x28\x15\x28\x15\x28\x15\x28\x15\x30\x15\x19\x15\x28\x15\x28\x15\x28\x15\x28\x15\x28\x15\x28\x00\x00\x15\x19\x15\x28\x15\x28\x15\x28\x15\x28\x15\x28\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_13_consts_2_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x0b\x22\x00\xa2\x07\x29\x03",
};
static struct PyCodeObject toplevel_consts_13_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_13_consts_2_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 198,
    .co_code = & toplevel_consts_13_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_consts_2_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_13_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_13_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_13_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_13_consts_2.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_13_names_3 = {
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
toplevel_consts_13_names_7 = {
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
    ._data = "_weakref",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_13_names_7._ascii.ob_base,
            & toplevel_consts_13_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_4._ascii.ob_base,
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
toplevel_consts_13_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_13_consts_2_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_13_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x02\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x04\x03\x04\x01\x0a\x01\x08\x02\x0a\x02\x14\x0b\x0a\x02\x04\x02\x02\xeb\x0a\x13\x04\x02\x02\x80\x0c\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[53];
    }
toplevel_consts_13_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 52,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x06\x02\x1a\x02\xeb\x0c\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x02\x02\x02\x11\x02\xf0\x02\x03\x0a\xfe\x08\x02\x02\x02\x08\x09\x14\x02\x0a\x02\x04\x02\x02\xfc\x0a\x02\x04\x02\x02\x80\x0c\xfe\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[159];
    }
toplevel_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 158,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x09\x05\x18\x05\x18\x05\x18\x05\x18\x05\x1c\x09\x18\x14\x21\x22\x26\x14\x27\x14\x29\x0d\x11\x0d\x11\x00\x00\x10\x18\x09\x18\x09\x18\x14\x18\x0d\x11\x0d\x11\x0d\x11\x09\x18\x00\x00\x00\x00\x00\x00\x0c\x10\x09\x39\x10\x17\x0d\x29\x18\x28\x29\x2d\x18\x2e\x11\x15\x11\x15\x18\x23\x24\x28\x18\x29\x11\x15\x1e\x22\x0d\x28\x0d\x28\x0d\x28\x0d\x28\x23\x2b\x23\x39\x30\x34\x36\x38\x23\x39\x23\x39\x0d\x1a\x1b\x1f\x0d\x20\x0d\x20\x09\x0d\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x0c\x10\x05\x10\x09\x39\x09\x0d\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x0c\x10\x05\x10\x00\x00\x09\x0d\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[34];
    }
toplevel_consts_13_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 33,
    },
    .ob_shash = -1,
    .ob_sval = "\x88\x05\x0e\x00\x8d\x01\x41\x05\x00\x8e\x06\x17\x03\x94\x02\x41\x05\x00\x96\x01\x17\x03\x97\x1e\x41\x05\x00\xc1\x05\x07\x41\x0c\x03",
};
static struct PyCodeObject toplevel_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_13_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 179,
    .co_code = & toplevel_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_2_names_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_11_consts_2_names_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_13_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_13_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x7d\x01\x09\x00\x7c\x01\xa0\x01\xa8\x00\xa9\x00\x01\x00\x6e\x0b\x23\x00\x74\x02\x79\x13\x01\x00\x59\x00\x64\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\xa0\x03\xa8\x00\xa9\x00\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[190];
    }
toplevel_consts_14_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 189,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x63\x71\x75\x69\x72\x65\x73\x20\x74\x68\x65\x6e\x20\x72\x65\x6c\x65\x61\x73\x65\x73\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6c\x6f\x63\x6b\x20\x66\x6f\x72\x20\x61\x20\x67\x69\x76\x65\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x69\x73\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x65\x6e\x73\x75\x72\x65\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x63\x6f\x6d\x70\x6c\x65\x74\x65\x6c\x79\x20\x69\x6e\x69\x74\x69\x61\x6c\x69\x7a\x65\x64\x2c\x20\x69\x6e\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x65\x76\x65\x6e\x74\x20\x69\x74\x20\x69\x73\x20\x62\x65\x69\x6e\x67\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x20\x62\x79\x20\x61\x6e\x6f\x74\x68\x65\x72\x20\x74\x68\x72\x65\x61\x64\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
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
toplevel_consts_14_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_11_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_9._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_4_names_11._ascii.ob_base,
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
toplevel_consts_14_varnames = {
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
            & toplevel_consts_7_consts_2_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_14_name = {
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
    ._data = "_lock_unlock_module",
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
    .ob_sval = "\x02\x00\x08\x06\x02\x01\x0c\x01\x02\x80\x06\x01\x06\x03\x02\xfd\x06\x80\x0e\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x06\x02\x08\x0c\xfa\x02\x80\x02\x01\x0c\x03\x06\x80\x0e\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x1c\x1d\x21\x0c\x22\x05\x09\x05\x17\x09\x0d\x09\x17\x09\x17\x09\x17\x09\x17\x09\x17\x00\x00\x0c\x1a\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x09\x0d\x09\x17\x09\x17\x09\x17\x09\x17\x09\x17\x09\x17",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_14_exceptiontable = {
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
static struct PyCodeObject toplevel_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_14_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_14_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_14_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 216,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
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
    .ob_sval = "\x97\x00\x7c\x00\x7c\x01\x69\x00\x7c\x02\xa4\x01\x8e\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[303];
    }
toplevel_consts_15_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 302,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x72\x65\x6d\x6f\x76\x65\x5f\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x5f\x66\x72\x61\x6d\x65\x73\x20\x69\x6e\x20\x69\x6d\x70\x6f\x72\x74\x2e\x63\x20\x77\x69\x6c\x6c\x20\x61\x6c\x77\x61\x79\x73\x20\x72\x65\x6d\x6f\x76\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x73\x0a\x20\x20\x20\x20\x6f\x66\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x20\x66\x72\x61\x6d\x65\x73\x20\x74\x68\x61\x74\x20\x65\x6e\x64\x20\x77\x69\x74\x68\x20\x61\x20\x63\x61\x6c\x6c\x20\x74\x6f\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x0a\x0a\x20\x20\x20\x20\x55\x73\x65\x20\x69\x74\x20\x69\x6e\x73\x74\x65\x61\x64\x20\x6f\x66\x20\x61\x20\x6e\x6f\x72\x6d\x61\x6c\x20\x63\x61\x6c\x6c\x20\x69\x6e\x20\x70\x6c\x61\x63\x65\x73\x20\x77\x68\x65\x72\x65\x20\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x0a\x20\x20\x20\x20\x66\x72\x61\x6d\x65\x73\x20\x69\x6e\x74\x72\x6f\x64\x75\x63\x65\x73\x20\x75\x6e\x77\x61\x6e\x74\x65\x64\x20\x6e\x6f\x69\x73\x65\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x20\x74\x72\x61\x63\x65\x62\x61\x63\x6b\x20\x28\x65\x2e\x67\x2e\x20\x77\x68\x65\x6e\x20\x65\x78\x65\x63\x75\x74\x69\x6e\x67\x0a\x20\x20\x20\x20\x6d\x6f\x64\x75\x6c\x65\x20\x63\x6f\x64\x65\x29\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_15_consts_0._ascii.ob_base,
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
    ._data = "f",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_15_varnames_2 = {
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
toplevel_consts_15_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_15_varnames_0._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_15_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_15_name = {
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
    ._data = "_call_with_frames_removed",
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
    .ob_sval = "\x02\x00\x0e\x08",
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
    .ob_sval = "\x01\x01\x0c\x0d\x0f\x13\x0c\x1c\x17\x1b\x0c\x1c\x0c\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_15_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 15,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 233,
    .co_code = & toplevel_consts_15_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_15_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_17_0 = {
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
    ._data = "verbosity",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_17 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_17_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_18_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x6a\x02\x7c\x01\x6b\x05\x72\x1d\x7c\x00\xa0\x03\x64\x01\xa8\x01\xa9\x01\x73\x11\x64\x02\x7c\x00\x7a\x00\x7d\x00\x74\x04\x7c\x00\x6a\x05\x7c\x02\x8e\x00\x74\x00\x6a\x06\x64\x03\xaa\x02\x01\x00\x64\x04\x53\x00\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[62];
    }
toplevel_consts_18_consts_0 = {
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
    ._data = "Print the message to stderr if -v/PYTHONVERBOSE is turned on.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_18_consts_1_0 = {
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
    ._data = "#",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_18_consts_1_1 = {
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
    ._data = "import ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_18_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_18_consts_1_0._ascii.ob_base,
            & toplevel_consts_18_consts_1_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_18_consts_2 = {
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
    ._data = "# ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_18_consts_3_0 = {
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
toplevel_consts_18_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_18_consts_3_0._ascii.ob_base,
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
            & toplevel_consts_18_consts_0._ascii.ob_base,
            & toplevel_consts_18_consts_1._object.ob_base.ob_base,
            & toplevel_consts_18_consts_2._ascii.ob_base,
            & toplevel_consts_18_consts_3._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_18_names_1 = {
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
    ._data = "flags",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_18_names_2 = {
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
    ._data = "verbose",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_18_names_3 = {
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
        uint8_t _data[6];
    }
toplevel_consts_18_names_4 = {
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
    ._data = "stderr",
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
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_18_names_1._ascii.ob_base,
            & toplevel_consts_18_names_2._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_18_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_18_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_18_varnames_0 = {
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
    ._data = "message",
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
            & toplevel_consts_18_varnames_0._ascii.ob_base,
            & toplevel_consts_17_0._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_18_name = {
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
    ._data = "_verbose_message",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_18_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x0c\x01\x08\x01\x18\x01\x04\xfd",
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
    .ob_sval = "\x02\x00\x0a\x02\x02\x03\x0a\xfe\x0a\x01\x1c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_18_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0b\x08\x11\x08\x19\x1d\x26\x08\x26\x05\x36\x10\x17\x10\x34\x23\x33\x10\x34\x10\x34\x09\x25\x17\x1b\x1e\x25\x17\x25\x0d\x14\x09\x0e\x0f\x16\x0f\x1d\x1f\x23\x0f\x24\x2b\x2e\x2b\x35\x09\x36\x09\x36\x09\x36\x09\x36\x09\x36\x05\x36\x05\x36",
};
static struct PyCodeObject toplevel_consts_18 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_18_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_18_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_18_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 7,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 4,
    .co_firstlineno = 244,
    .co_code = & toplevel_consts_18_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_18_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_18_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_18_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_18_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_18_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_18_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_19_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x88\x00\x66\x01\x64\x01\x84\x08\x7d\x01\x74\x00\x7c\x01\x89\x00\xa9\x02\x01\x00\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[50];
    }
toplevel_consts_19_consts_0 = {
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
    ._data = "Decorator to verify the named module is built-in.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_19_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x7c\x01\x74\x00\x6a\x01\x76\x01\x72\x11\x74\x02\x64\x01\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x7c\x01\x64\x02\xaa\x02\x82\x01\x89\x02\x7c\x00\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_19_consts_1_consts_1 = {
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
    ._data = "{!r} is not a built-in module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_19_consts_1_consts = {
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
            & toplevel_consts_19_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_19_consts_1_names_1 = {
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
    ._data = "builtin_module_names",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_19_consts_1_names_2 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_19_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_19_consts_1_varnames_1 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_19_consts_1_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_19_consts_1_freevars_0 = {
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
toplevel_consts_19_consts_1_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_19_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_19_consts_1_name = {
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
    ._data = "_requires_builtin_wrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[53];
    }
toplevel_consts_19_consts_1_qualname = {
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
    ._data = "_requires_builtin.<locals>._requires_builtin_wrapper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_19_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x0c\x01\x02\x01\x06\xff\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_19_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x08\x01\x02\x02\x0c\xff\x08\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_19_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x0c\x14\x1c\x1f\x1c\x34\x0c\x34\x09\x2d\x13\x1e\x1f\x3e\x1f\x4f\x46\x4e\x1f\x4f\x1f\x4f\x24\x2c\x13\x2d\x13\x2d\x0d\x2d\x10\x13\x14\x18\x1a\x22\x10\x23\x09\x23",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_19_consts_1_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_19_consts_1_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_19_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 254,
    .co_code = & toplevel_consts_19_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_19_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_19_consts_1_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_19_consts_1.ob_base,
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
            & toplevel_consts_3_name._ascii.ob_base,
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
toplevel_consts_19_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_19_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_19_name = {
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
    ._data = "_requires_builtin",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_19_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x02\x0a\x05\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_19_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x06\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_19_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x0a\x0b\x24\x26\x29\x05\x2a\x05\x2a\x0c\x25\x05\x25",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_19_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_19 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_19_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 252,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_19_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_19_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_19_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_19_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_19_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[48];
    }
toplevel_consts_20_consts_0 = {
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
    ._data = "Decorator to verify the named module is frozen.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_20_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x73\x12\x74\x02\x64\x01\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x7c\x01\x64\x02\xaa\x02\x82\x01\x89\x02\x7c\x00\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_20_consts_1_consts_1 = {
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
    ._data = "{!r} is not a frozen module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_20_consts_1_consts = {
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
            & toplevel_consts_20_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_20_consts_1_names_1 = {
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
    ._data = "is_frozen",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_20_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_20_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_20_consts_1_name = {
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
    ._data = "_requires_frozen_wrapper",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[51];
    }
toplevel_consts_20_consts_1_qualname = {
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
    ._data = "_requires_frozen.<locals>._requires_frozen_wrapper",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_20_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0c\x01\x0c\x01\x02\x01\x06\xff\x0a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_20_consts_1_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x0a\x01\x02\x02\x0c\xff\x08\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_20_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x10\x14\x10\x28\x1f\x27\x10\x28\x10\x28\x09\x2d\x13\x1e\x1f\x3c\x1f\x4d\x44\x4c\x1f\x4d\x1f\x4d\x24\x2c\x13\x2d\x13\x2d\x0d\x2d\x10\x13\x14\x18\x1a\x22\x10\x23\x09\x23",
};
static struct PyCodeObject toplevel_consts_20_consts_1 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_20_consts_1_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_20_consts_1_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 19,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 265,
    .co_code = & toplevel_consts_20_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_19_consts_1_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_consts_1_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_20_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_20_consts_1_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_consts_1_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_19_consts_1_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_19_consts_1_freevars._object.ob_base.ob_base,
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
            & toplevel_consts_20_consts_1.ob_base,
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
            & toplevel_consts_19_consts_1_freevars_0._ascii.ob_base,
            & toplevel_consts_20_consts_1_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_20_name = {
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
    ._data = "_requires_frozen",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_20_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x0a\x0b\x23\x25\x28\x05\x29\x05\x29\x0c\x24\x05\x24",
};
static struct PyCodeObject toplevel_consts_20 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_20_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_19_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_19_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 263,
    .co_code = & toplevel_consts_19_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_19_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_20_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_20_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_19_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_19_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_20_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_20_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_19_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_21_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x02\x74\x00\xa0\x01\x7c\x02\x74\x02\xa8\x02\xa9\x02\x01\x00\x74\x03\x7c\x01\x7c\x00\xa9\x02\x7d\x03\x7c\x01\x74\x04\x6a\x05\x76\x00\x72\x23\x74\x04\x6a\x05\x7c\x01\x19\x00\x7d\x04\x74\x06\x7c\x03\x7c\x04\xa9\x02\x01\x00\x74\x04\x6a\x05\x7c\x01\x19\x00\x53\x00\x74\x07\x7c\x03\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[131];
    }
toplevel_consts_21_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 130,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4c\x6f\x61\x64\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x6e\x74\x6f\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x69\x74\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x20\x20\x55\x73\x65\x20\x6c\x6f\x61\x64\x65\x72\x2e\x65\x78\x65\x63\x5f\x6d\x6f\x64\x75\x6c\x65\x28\x29\x20\x69\x6e\x73\x74\x65\x61\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[104];
    }
toplevel_consts_21_consts_1 = {
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
    ._data = "the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead",
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
            & toplevel_consts_21_consts_1._ascii.ob_base,
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
    ._data = "_warnings",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_21_names_1 = {
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
toplevel_consts_21_names_2 = {
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
        uint8_t _data[17];
    }
toplevel_consts_21_names_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_21_names_5 = {
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
        uint8_t _data[6];
    }
toplevel_consts_21_names_6 = {
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
    ._data = "_exec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_21_names_7 = {
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
    ._data = "_load",
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
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_21_names_6._ascii.ob_base,
            & toplevel_consts_21_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_21_varnames_2 = {
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
toplevel_consts_21_varnames_3 = {
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
        uint8_t _data[7];
    }
toplevel_consts_21_varnames_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_21_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_2._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_21_name = {
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
    ._data = "_load_module_shim",
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
    .ob_sval = "\x02\x00\x04\x06\x0e\x02\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x0a\x01\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_21_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x02\xff\x0e\x02\x0a\x01\x08\x01\x02\x05\x0a\xfc\x0a\x01\x0a\x01\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[79];
    }
toplevel_consts_21_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 78,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x33\x05\x08\x05\x0e\x05\x2c\x14\x17\x19\x2b\x05\x2c\x05\x2c\x05\x2c\x0c\x1c\x1d\x25\x27\x2b\x0c\x2c\x05\x09\x08\x10\x14\x17\x14\x1f\x08\x1f\x05\x1b\x12\x15\x12\x1d\x1e\x26\x12\x27\x09\x0f\x09\x0e\x0f\x13\x15\x1b\x09\x1c\x09\x1c\x10\x13\x10\x1b\x1c\x24\x10\x25\x09\x25\x10\x15\x16\x1a\x10\x1b\x09\x1b",
};
static struct PyCodeObject toplevel_consts_21 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_21_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_21_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_21_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 275,
    .co_code = & toplevel_consts_21_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_21_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_21_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_21_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_21_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[195];
    }
toplevel_consts_22_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 194,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x64\x01\x64\x02\xa9\x03\x7d\x01\x74\x00\x7c\x00\x64\x03\x64\x02\xa9\x03\x04\x00\x7d\x02\x72\x13\x74\x01\x7c\x02\xa9\x01\x53\x00\x74\x02\x7c\x01\x64\x04\xa9\x02\x72\x29\x09\x00\x7c\x01\xa0\x03\x7c\x00\xa8\x01\xa9\x01\x53\x00\x23\x00\x74\x04\x79\x25\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x00\x6a\x05\x7d\x03\x6e\x0c\x23\x00\x74\x06\x79\x36\x01\x00\x64\x05\x7d\x03\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x00\x6a\x07\x7d\x04\x6e\x1b\x23\x00\x74\x06\x79\x56\x01\x00\x7c\x01\x80\x4d\x64\x06\xa0\x08\x7c\x03\xa8\x01\xa9\x01\x02\x00\x59\x00\x53\x00\x64\x07\xa0\x08\x7c\x03\x7c\x01\xa8\x02\xa9\x02\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x64\x08\xa0\x08\x7c\x03\x7c\x04\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_22_consts_0 = {
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
    ._data = "The implementation of ModuleType.__repr__().",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_22_consts_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_22_consts_3 = {
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
        uint8_t _data[12];
    }
toplevel_consts_22_consts_4 = {
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
    ._data = "module_repr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_22_consts_5 = {
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
    ._data = "?",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_22_consts_6 = {
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
    ._data = "<module {!r}>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_22_consts_7 = {
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
    ._data = "<module {!r} ({!r})>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_22_consts_8 = {
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
    ._data = "<module {!r} from {!r}>",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_22_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_22_consts_0._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            Py_None,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_22_consts_4._ascii.ob_base,
            & toplevel_consts_22_consts_5._ascii.ob_base,
            & toplevel_consts_22_consts_6._ascii.ob_base,
            & toplevel_consts_22_consts_7._ascii.ob_base,
            & toplevel_consts_22_consts_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_22_names_1 = {
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
    ._data = "_module_repr_from_spec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_22_names_4 = {
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
toplevel_consts_22_names_7 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_22_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_22_names_1._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_22_consts_4._ascii.ob_base,
            & toplevel_consts_22_names_4._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_22_varnames_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_22_varnames_4 = {
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_22_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_22_name = {
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
    ._data = "_module_repr",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_22_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x10\x01\x08\x01\x0a\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x02\x03\x08\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x02\x02\x08\x01\x02\x80\x06\x01\x04\x01\x10\x01\x12\x02\x02\xfc\x06\x80\x0e\x06",
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
    .ob_sval = "\x02\x00\x0c\x02\x0e\x01\x02\x06\x08\xfb\x08\x01\x04\x04\x0c\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x05\x08\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x02\x09\x08\xf9\x02\x80\x02\x01\x04\x04\x02\xfd\x02\x03\x10\xfe\x14\x02\x06\x80\x0e\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[195];
    }
toplevel_consts_22_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 194,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x15\x16\x1c\x1e\x2a\x2c\x30\x0e\x31\x05\x0b\x10\x17\x18\x1e\x20\x2a\x2c\x30\x10\x31\x08\x31\x08\x0c\x05\x11\x10\x26\x27\x2b\x10\x2c\x09\x2c\x0a\x11\x12\x18\x1a\x27\x0a\x28\x05\x11\x09\x11\x14\x1a\x14\x2e\x27\x2d\x14\x2e\x14\x2e\x0d\x2e\x00\x00\x10\x19\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x05\x13\x10\x16\x10\x1f\x09\x0d\x09\x0d\x00\x00\x0c\x1a\x05\x13\x05\x13\x10\x13\x09\x0d\x09\x0d\x09\x0d\x05\x13\x00\x00\x00\x00\x00\x00\x05\x40\x14\x1a\x14\x23\x09\x11\x09\x11\x00\x00\x0c\x1a\x05\x3f\x05\x3f\x0c\x12\x09\x3f\x14\x23\x14\x30\x2b\x2f\x14\x30\x14\x30\x0d\x30\x0d\x30\x0d\x30\x14\x2a\x14\x3f\x32\x36\x38\x3e\x14\x3f\x14\x3f\x0d\x3f\x0d\x3f\x0d\x3f\x05\x3f\x00\x00\x00\x00\x00\x00\x10\x29\x10\x40\x31\x35\x37\x3f\x10\x40\x10\x40\x09\x40",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[46];
    }
toplevel_consts_22_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 45,
    },
    .ob_shash = -1,
    .ob_sval = "\x99\x05\x1f\x00\x9f\x04\x26\x03\xa5\x01\x26\x03\xaa\x03\x2e\x00\xae\x06\x37\x03\xb6\x01\x37\x03\xbb\x03\x3f\x00\xbf\x0c\x41\x17\x03\xc1\x0d\x07\x41\x17\x03\xc1\x16\x01\x41\x17\x03",
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
    .co_stacksize = 5,
    .co_firstlineno = 294,
    .co_code = & toplevel_consts_22_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_22_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_22_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_22_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_22_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_23_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x64\x02\x64\x02\x64\x03\x9c\x03\x64\x04\x84\x02\x5a\x04\x64\x05\x84\x00\x5a\x05\x64\x06\x84\x00\x5a\x06\x65\x07\x64\x07\x84\x00\xa9\x01\x5a\x08\x65\x08\x6a\x09\x64\x08\x84\x00\xa9\x01\x5a\x08\x65\x07\x64\x09\x84\x00\xa9\x01\x5a\x0a\x65\x07\x64\x0a\x84\x00\xa9\x01\x5a\x0b\x65\x0b\x6a\x09\x64\x0b\x84\x00\xa9\x01\x5a\x0b\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_23_consts_0 = {
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
    ._data = "ModuleSpec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[1489];
    }
toplevel_consts_23_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 1488,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x54\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x63\x61\x74\x69\x6f\x6e\x20\x66\x6f\x72\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x2c\x20\x75\x73\x65\x64\x20\x66\x6f\x72\x20\x6c\x6f\x61\x64\x69\x6e\x67\x2e\x0a\x0a\x20\x20\x20\x20\x41\x20\x6d\x6f\x64\x75\x6c\x65\x27\x73\x20\x73\x70\x65\x63\x20\x69\x73\x20\x74\x68\x65\x20\x73\x6f\x75\x72\x63\x65\x20\x66\x6f\x72\x20\x69\x6e\x66\x6f\x72\x6d\x61\x74\x69\x6f\x6e\x20\x61\x62\x6f\x75\x74\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x20\x20\x46\x6f\x72\x0a\x20\x20\x20\x20\x64\x61\x74\x61\x20\x61\x73\x73\x6f\x63\x69\x61\x74\x65\x64\x20\x77\x69\x74\x68\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2c\x20\x69\x6e\x63\x6c\x75\x64\x69\x6e\x67\x20\x73\x6f\x75\x72\x63\x65\x2c\x20\x75\x73\x65\x20\x74\x68\x65\x20\x73\x70\x65\x63\x27\x73\x0a\x20\x20\x20\x20\x6c\x6f\x61\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x60\x6e\x61\x6d\x65\x60\x20\x69\x73\x20\x74\x68\x65\x20\x61\x62\x73\x6f\x6c\x75\x74\x65\x20\x6e\x61\x6d\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x20\x20\x60\x6c\x6f\x61\x64\x65\x72\x60\x20\x69\x73\x20\x74\x68\x65\x20\x6c\x6f\x61\x64\x65\x72\x0a\x20\x20\x20\x20\x74\x6f\x20\x75\x73\x65\x20\x77\x68\x65\x6e\x20\x6c\x6f\x61\x64\x69\x6e\x67\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x20\x20\x60\x70\x61\x72\x65\x6e\x74\x60\x20\x69\x73\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x20\x6f\x66\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x69\x6e\x2e\x20\x20\x54\x68\x65\x20\x70\x61\x72\x65\x6e\x74\x20\x69\x73\x20\x64\x65\x72\x69\x76\x65\x64\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x2e\x0a\x0a\x20\x20\x20\x20\x60\x69\x73\x5f\x70\x61\x63\x6b\x61\x67\x65\x60\x20\x64\x65\x74\x65\x72\x6d\x69\x6e\x65\x73\x20\x69\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x61\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x6f\x72\x0a\x20\x20\x20\x20\x6e\x6f\x74\x2e\x20\x20\x4f\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x74\x68\x69\x73\x20\x69\x73\x20\x72\x65\x66\x6c\x65\x63\x74\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x60\x5f\x5f\x70\x61\x74\x68\x5f\x5f\x60\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x2e\x0a\x0a\x20\x20\x20\x20\x60\x6f\x72\x69\x67\x69\x6e\x60\x20\x69\x73\x20\x74\x68\x65\x20\x73\x70\x65\x63\x69\x66\x69\x63\x20\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x20\x75\x73\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x6c\x6f\x61\x64\x65\x72\x20\x66\x72\x6f\x6d\x20\x77\x68\x69\x63\x68\x20\x74\x6f\x0a\x20\x20\x20\x20\x6c\x6f\x61\x64\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2c\x20\x69\x66\x20\x74\x68\x61\x74\x20\x69\x6e\x66\x6f\x72\x6d\x61\x74\x69\x6f\x6e\x20\x69\x73\x20\x61\x76\x61\x69\x6c\x61\x62\x6c\x65\x2e\x20\x20\x57\x68\x65\x6e\x20\x66\x69\x6c\x65\x6e\x61\x6d\x65\x20\x69\x73\x0a\x20\x20\x20\x20\x73\x65\x74\x2c\x20\x6f\x72\x69\x67\x69\x6e\x20\x77\x69\x6c\x6c\x20\x6d\x61\x74\x63\x68\x2e\x0a\x0a\x20\x20\x20\x20\x60\x68\x61\x73\x5f\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x60\x20\x69\x6e\x64\x69\x63\x61\x74\x65\x73\x20\x74\x68\x61\x74\x20\x61\x20\x73\x70\x65\x63\x27\x73\x20\x22\x6f\x72\x69\x67\x69\x6e\x22\x20\x72\x65\x66\x6c\x65\x63\x74\x73\x20\x61\x20\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x2e\x0a\x20\x20\x20\x20\x57\x68\x65\x6e\x20\x74\x68\x69\x73\x20\x69\x73\x20\x54\x72\x75\x65\x2c\x20\x60\x5f\x5f\x66\x69\x6c\x65\x5f\x5f\x60\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x73\x65\x74\x2e\x0a\x0a\x20\x20\x20\x20\x60\x63\x61\x63\x68\x65\x64\x60\x20\x69\x73\x20\x74\x68\x65\x20\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x20\x6f\x66\x20\x74\x68\x65\x20\x63\x61\x63\x68\x65\x64\x20\x62\x79\x74\x65\x63\x6f\x64\x65\x20\x66\x69\x6c\x65\x2c\x20\x69\x66\x20\x61\x6e\x79\x2e\x20\x20\x49\x74\x0a\x20\x20\x20\x20\x63\x6f\x72\x72\x65\x73\x70\x6f\x6e\x64\x73\x20\x74\x6f\x20\x74\x68\x65\x20\x60\x5f\x5f\x63\x61\x63\x68\x65\x64\x5f\x5f\x60\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x2e\x0a\x0a\x20\x20\x20\x20\x60\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x5f\x73\x65\x61\x72\x63\x68\x5f\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x73\x60\x20\x69\x73\x20\x74\x68\x65\x20\x73\x65\x71\x75\x65\x6e\x63\x65\x20\x6f\x66\x20\x70\x61\x74\x68\x20\x65\x6e\x74\x72\x69\x65\x73\x20\x74\x6f\x0a\x20\x20\x20\x20\x73\x65\x61\x72\x63\x68\x20\x77\x68\x65\x6e\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x20\x20\x49\x66\x20\x73\x65\x74\x2c\x20\x69\x73\x5f\x70\x61\x63\x6b\x61\x67\x65\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x0a\x20\x20\x20\x20\x54\x72\x75\x65\x2d\x2d\x61\x6e\x64\x20\x46\x61\x6c\x73\x65\x20\x6f\x74\x68\x65\x72\x77\x69\x73\x65\x2e\x0a\x0a\x20\x20\x20\x20\x50\x61\x63\x6b\x61\x67\x65\x73\x20\x61\x72\x65\x20\x73\x69\x6d\x70\x6c\x79\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x74\x68\x61\x74\x20\x28\x6d\x61\x79\x29\x20\x68\x61\x76\x65\x20\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x20\x20\x49\x66\x20\x61\x20\x73\x70\x65\x63\x0a\x20\x20\x20\x20\x68\x61\x73\x20\x61\x20\x6e\x6f\x6e\x2d\x4e\x6f\x6e\x65\x20\x76\x61\x6c\x75\x65\x20\x69\x6e\x20\x60\x73\x75\x62\x6d\x6f\x64\x75\x6c\x65\x5f\x73\x65\x61\x72\x63\x68\x5f\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x73\x60\x2c\x20\x74\x68\x65\x20\x69\x6d\x70\x6f\x72\x74\x0a\x20\x20\x20\x20\x73\x79\x73\x74\x65\x6d\x20\x77\x69\x6c\x6c\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x6c\x6f\x61\x64\x65\x64\x20\x66\x72\x6f\x6d\x20\x74\x68\x65\x20\x73\x70\x65\x63\x20\x61\x73\x20\x70\x61\x63\x6b\x61\x67\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x4f\x6e\x6c\x79\x20\x66\x69\x6e\x64\x65\x72\x73\x20\x28\x73\x65\x65\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x2e\x61\x62\x63\x2e\x4d\x65\x74\x61\x50\x61\x74\x68\x46\x69\x6e\x64\x65\x72\x20\x61\x6e\x64\x0a\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x2e\x61\x62\x63\x2e\x50\x61\x74\x68\x45\x6e\x74\x72\x79\x46\x69\x6e\x64\x65\x72\x29\x20\x73\x68\x6f\x75\x6c\x64\x20\x6d\x6f\x64\x69\x66\x79\x20\x4d\x6f\x64\x75\x6c\x65\x53\x70\x65\x63\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_3_0 = {
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
        uint8_t _data[13];
    }
toplevel_consts_23_consts_3_1 = {
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
        uint8_t _data[11];
    }
toplevel_consts_23_consts_3_2 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_23_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_23_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x7c\x00\x5f\x00\x7c\x02\x7c\x00\x5f\x01\x7c\x03\x7c\x00\x5f\x02\x7c\x04\x7c\x00\x5f\x03\x7c\x05\x72\x11\x67\x00\x6e\x01\x64\x00\x7c\x00\x5f\x04\x67\x00\x7c\x00\x5f\x05\x64\x01\x7c\x00\x5f\x06\x64\x00\x7c\x00\x5f\x07\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_23_consts_4_consts = {
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
        uint8_t _data[27];
    }
toplevel_consts_23_consts_4_names_4 = {
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
        uint8_t _data[26];
    }
toplevel_consts_23_consts_4_names_5 = {
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
    ._data = "_uninitialized_submodules",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_23_consts_4_names_6 = {
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
    ._data = "_set_fileattr",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_23_consts_4_names_7 = {
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
    ._data = "_cached",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_23_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_5._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_7._ascii.ob_base,
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
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_23_consts_4_qualname = {
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
    ._data = "ModuleSpec.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_23_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x06\x01\x06\x01\x06\x01\x0e\x01\x06\x01\x06\x03\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_23_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x15\x19\x09\x0d\x09\x12\x17\x1d\x09\x0d\x09\x14\x17\x1d\x09\x0d\x09\x14\x1d\x29\x09\x0d\x09\x1a\x31\x3b\x2b\x45\x2b\x2d\x2b\x2d\x41\x45\x09\x0d\x09\x28\x2a\x2c\x09\x0d\x09\x27\x1e\x23\x09\x0d\x09\x1b\x18\x1c\x09\x0d\x09\x15\x09\x15\x09\x15",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_23_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_23_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 3,
    .co_stacksize = 2,
    .co_firstlineno = 357,
    .co_code = & toplevel_consts_23_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_consts_23_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\xa0\x00\x7c\x00\x6a\x01\xa8\x01\xa9\x01\x64\x02\xa0\x00\x7c\x00\x6a\x02\xa8\x01\xa9\x01\x67\x02\x7d\x01\x7c\x00\x6a\x03\x81\x1d\x7c\x01\xa0\x04\x64\x03\xa0\x00\x7c\x00\x6a\x03\xa8\x01\xa9\x01\xa8\x01\xa9\x01\x01\x00\x7c\x00\x6a\x05\x81\x2b\x7c\x01\xa0\x04\x64\x04\xa0\x00\x7c\x00\x6a\x05\xa8\x01\xa9\x01\xa8\x01\xa9\x01\x01\x00\x64\x05\xa0\x00\x7c\x00\x6a\x06\x6a\x07\x64\x06\xa0\x08\x7c\x01\xa8\x01\xa9\x01\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_23_consts_5_consts_1 = {
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
    ._data = "name={!r}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_23_consts_5_consts_2 = {
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
    ._data = "loader={!r}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_23_consts_5_consts_3 = {
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
    ._data = "origin={!r}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_23_consts_5_consts_4 = {
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
    ._data = "submodule_search_locations={}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_5_consts_5 = {
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
    ._data = "{}({})",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_23_consts_5_consts_6 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_23_consts_5_consts = {
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
            & toplevel_consts_23_consts_5_consts_1._ascii.ob_base,
            & toplevel_consts_23_consts_5_consts_2._ascii.ob_base,
            & toplevel_consts_23_consts_5_consts_3._ascii.ob_base,
            & toplevel_consts_23_consts_5_consts_4._ascii.ob_base,
            & toplevel_consts_23_consts_5_consts_5._ascii.ob_base,
            & toplevel_consts_23_consts_5_consts_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_5_names_4 = {
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
        uint8_t _data[10];
    }
toplevel_consts_23_consts_5_names_6 = {
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
        uint8_t _data[5];
    }
toplevel_consts_23_consts_5_names_8 = {
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
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_23_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_5_names_6._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_23_consts_5_names_8._ascii.ob_base,
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
toplevel_consts_23_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_11_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_23_consts_5_qualname = {
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
    ._data = "ModuleSpec.__repr__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_23_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0c\x01\x04\xff\x06\x02\x16\x01\x06\x01\x06\x01\x0a\x01\x06\xff\x1a\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_23_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x0e\x01\x02\xff\x04\x02\x18\x01\x04\x01\x02\x02\x02\xff\x02\x01\x02\xff\x10\x01\x1a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_consts_23_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x1c\x11\x2e\x24\x28\x24\x2d\x11\x2e\x11\x2e\x11\x1e\x11\x32\x26\x2a\x26\x31\x11\x32\x11\x32\x10\x33\x09\x0d\x0c\x10\x0c\x17\x09\x3b\x0d\x11\x0d\x3b\x19\x26\x19\x3a\x2e\x32\x2e\x39\x19\x3a\x19\x3a\x0d\x3b\x0d\x3b\x0d\x3b\x0c\x10\x0c\x2b\x09\x42\x0d\x11\x0d\x42\x19\x38\x19\x41\x21\x25\x21\x40\x19\x41\x19\x41\x0d\x42\x0d\x42\x0d\x42\x10\x18\x10\x49\x20\x24\x20\x2e\x20\x37\x39\x3d\x39\x48\x43\x47\x39\x48\x39\x48\x10\x49\x10\x49\x09\x49",
};
static struct PyCodeObject toplevel_consts_23_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 370,
    .co_code = & toplevel_consts_23_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_7_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_23_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x02\x09\x00\x7c\x00\x6a\x01\x7c\x01\x6a\x01\x6b\x02\x6f\x27\x7c\x00\x6a\x02\x7c\x01\x6a\x02\x6b\x02\x6f\x27\x7c\x00\x6a\x03\x7c\x01\x6a\x03\x6b\x02\x6f\x27\x7c\x02\x7c\x01\x6a\x00\x6b\x02\x6f\x27\x7c\x00\x6a\x04\x7c\x01\x6a\x04\x6b\x02\x6f\x27\x7c\x00\x6a\x05\x7c\x01\x6a\x05\x6b\x02\x53\x00\x23\x00\x74\x06\x79\x30\x01\x00\x74\x07\x02\x00\x59\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_6_names_4 = {
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
        uint8_t _data[13];
    }
toplevel_consts_23_consts_6_names_5 = {
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
    ._data = "has_location",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_23_consts_6_names_7 = {
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
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_23_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23_consts_6_varnames_1 = {
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
toplevel_consts_23_consts_6_varnames_2 = {
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
    ._data = "smsl",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_23_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_6_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_6_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_6_name = {
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
        uint8_t _data[18];
    }
toplevel_consts_23_consts_6_qualname = {
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
    ._data = "ModuleSpec.__eq__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_23_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x01\x0c\x01\x0a\x01\x02\xff\x0a\x02\x02\xfe\x08\x03\x02\xfd\x0a\x04\x02\xfc\x0a\x05\x02\xfb\x02\x80\x06\x06\x08\x01\x02\xff\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_23_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x02\x09\x0a\xf9\x02\x05\x0a\xfc\x02\x04\x0a\xfd\x02\x03\x08\xfe\x02\x02\x0a\xff\x0e\x01\x02\x80\x02\x01\x0e\x01\x06\x80",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[105];
    }
toplevel_consts_23_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 104,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x2f\x09\x0d\x09\x22\x15\x19\x15\x1e\x22\x27\x22\x2c\x15\x2c\x15\x3c\x15\x19\x15\x20\x24\x29\x24\x30\x15\x30\x15\x3c\x15\x19\x15\x20\x24\x29\x24\x30\x15\x30\x15\x3c\x15\x19\x1d\x22\x1d\x3d\x15\x3d\x15\x3c\x15\x19\x15\x20\x24\x29\x24\x30\x15\x30\x15\x3c\x15\x19\x15\x26\x2a\x2f\x2a\x3c\x15\x3c\x0d\x3d\x00\x00\x10\x1e\x09\x22\x09\x22\x14\x22\x0d\x22\x0d\x22\x0d\x22\x09\x22\x00\x00\x00\x00\x00\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_23_consts_6_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x85\x22\x28\x00\xa8\x06\x31\x03\xb0\x01\x31\x03",
};
static struct PyCodeObject toplevel_consts_23_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_23_consts_6_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 380,
    .co_code = & toplevel_consts_23_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_23_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x80\x16\x7c\x00\x6a\x01\x81\x16\x7c\x00\x6a\x02\x72\x16\x74\x03\x80\x0e\x74\x04\x82\x01\x74\x03\xa0\x05\x7c\x00\x6a\x01\xa8\x01\xa9\x01\x7c\x00\x5f\x00\x7c\x00\x6a\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_23_consts_7_names_3 = {
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
        uint8_t _data[20];
    }
toplevel_consts_23_consts_7_names_4 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_23_consts_7_names_5 = {
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
    ._data = "_get_cached",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_23_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_23_consts_4_names_7._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_23_consts_7_qualname = {
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
    ._data = "ModuleSpec.cached",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_23_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0c\x01\x04\x01\x04\x01\x10\x01\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_23_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x02\x04\x04\xfd\x02\x03\x04\xfd\x02\x03\x02\xfe\x06\x01\x10\x01\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_23_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x18\x09\x4c\x10\x14\x10\x1b\x0d\x4c\x2c\x30\x2c\x3e\x0d\x4c\x14\x27\x11\x2e\x1b\x2e\x15\x2e\x20\x33\x20\x4c\x40\x44\x40\x4b\x20\x4c\x20\x4c\x11\x15\x11\x1d\x10\x14\x10\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_23_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 392,
    .co_code = & toplevel_consts_23_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_23_consts_8_code = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_23_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_23_consts_4_names_7._ascii.ob_base,
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
toplevel_consts_23_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_23_consts_8_linetable = {
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
toplevel_consts_23_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x18\x1e\x09\x0d\x09\x15\x09\x15\x09\x15",
};
static struct PyCodeObject toplevel_consts_23_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 401,
    .co_code = & toplevel_consts_23_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_23_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x80\x0d\x7c\x00\x6a\x01\xa0\x02\x64\x02\xa8\x01\xa9\x01\x64\x03\x19\x00\x53\x00\x7c\x00\x6a\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_23_consts_9_consts_0 = {
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
    ._data = "The name of the module's parent.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_23_consts_9_consts_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_23_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_23_consts_9_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_23_consts_9_names_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_23_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_9_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_23_consts_9_name = {
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
        uint8_t _data[18];
    }
toplevel_consts_23_consts_9_qualname = {
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
    ._data = "ModuleSpec.parent",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_23_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x03\x12\x01\x06\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_23_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x03\x02\x03\x12\xfe\x06\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_23_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x2b\x09\x1d\x14\x18\x14\x1d\x14\x2d\x29\x2c\x14\x2d\x14\x2d\x2e\x2f\x14\x30\x0d\x30\x14\x18\x14\x1d\x0d\x1d",
};
static struct PyCodeObject toplevel_consts_23_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 405,
    .co_code = & toplevel_consts_23_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_23_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_23_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_23_consts_4_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_23_consts_10_qualname = {
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
    ._data = "ModuleSpec.has_location",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_23_consts_10_linetable = {
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
toplevel_consts_23_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x22\x09\x22",
};
static struct PyCodeObject toplevel_consts_23_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 413,
    .co_code = & toplevel_consts_23_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_10_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_23_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x01\xa9\x01\x7c\x00\x5f\x01\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_23_consts_11_names_0 = {
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
    ._data = "bool",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_23_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_23_consts_11_names_0._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_23_consts_11_varnames_1 = {
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
toplevel_consts_23_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_11_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_23_consts_11_linetable = {
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
toplevel_consts_23_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x1e\x22\x23\x28\x1e\x29\x09\x0d\x09\x1b\x09\x1b\x09\x1b",
};
static struct PyCodeObject toplevel_consts_23_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 417,
    .co_code = & toplevel_consts_23_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_23_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_23_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_23_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_23_consts_1._ascii.ob_base,
            Py_None,
            & toplevel_consts_23_consts_3._object.ob_base.ob_base,
            & toplevel_consts_23_consts_4.ob_base,
            & toplevel_consts_23_consts_5.ob_base,
            & toplevel_consts_23_consts_6.ob_base,
            & toplevel_consts_23_consts_7.ob_base,
            & toplevel_consts_23_consts_8.ob_base,
            & toplevel_consts_23_consts_9.ob_base,
            & toplevel_consts_23_consts_10.ob_base,
            & toplevel_consts_23_consts_11.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_23_names_7 = {
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
        uint8_t _data[7];
    }
toplevel_consts_23_names_9 = {
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
    ._data = "setter",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_23_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_name._ascii.ob_base,
            & toplevel_consts_7_consts_6_name._ascii.ob_base,
            & toplevel_consts_23_consts_6_name._ascii.ob_base,
            & toplevel_consts_23_names_7._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_23_names_9._ascii.ob_base,
            & toplevel_consts_23_consts_9_name._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_23_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x04\x24\x02\x01\x0a\xff\x06\x0d\x06\x0a\x02\x0c\x04\x01\x02\xff\x02\x01\x04\x08\x04\x01\x02\xff\x02\x01\x02\x03\x04\x01\x02\xff\x02\x01\x02\x07\x04\x01\x02\xff\x02\x01\x04\x03\x04\x01\x02\xff\x06\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_23_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x23\x04\x02\x02\x01\x0a\x0a\x06\x0a\x06\x0c\x02\x02\x04\x07\x02\xf9\x02\x07\x04\x02\x04\x02\x02\xfe\x02\x02\x02\x02\x04\x06\x02\xfa\x02\x06\x02\x02\x04\x02\x02\xfe\x02\x02\x04\x02\x04\x02\x02\xfe\x06\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_23_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x30\x34\x43\x47\x1d\x21\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x49\x05\x49\x05\x49\x05\x22\x05\x22\x05\x22\x06\x0e\x05\x1c\x05\x1c\x06\x0e\x05\x1c\x06\x0c\x06\x13\x05\x1e\x05\x1e\x06\x13\x05\x1e\x06\x0e\x05\x1d\x05\x1d\x06\x0e\x05\x1d\x06\x0e\x05\x22\x05\x22\x06\x0e\x05\x22\x06\x12\x06\x19\x05\x29\x05\x29\x06\x19\x05\x29\x05\x29\x05\x29",
};
static struct PyCodeObject toplevel_consts_23 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_23_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_23_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_23_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 320,
    .co_code = & toplevel_consts_23_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_23_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_23_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_25 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[163];
    }
toplevel_consts_26_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 162,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x80\x09\x74\x00\x7c\x01\x64\x02\x64\x01\xa9\x03\x7d\x02\x7c\x02\x73\x2c\x74\x01\x7c\x01\x64\x03\xa9\x02\x72\x2c\x74\x02\x80\x14\x74\x03\x82\x01\x74\x02\x6a\x04\x7d\x04\x7c\x03\x80\x1f\x7c\x04\x7c\x00\x7c\x01\x64\x04\xaa\x02\x53\x00\x7c\x03\x72\x23\x67\x00\x6e\x01\x64\x01\x7d\x05\x7c\x04\x7c\x00\x7c\x01\x7c\x05\x64\x05\xaa\x03\x53\x00\x7c\x03\x80\x49\x74\x01\x7c\x01\x64\x06\xa9\x02\x72\x47\x09\x00\x7c\x01\xa0\x05\x7c\x00\xa8\x01\xa9\x01\x7d\x03\x6e\x0e\x23\x00\x74\x06\x79\x43\x01\x00\x64\x01\x7d\x03\x59\x00\x6e\x06\x77\x00\x78\x03\x59\x00\x77\x01\x64\x07\x7d\x03\x74\x07\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x64\x08\xaa\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_26_consts_0 = {
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
    ._data = "Return a module spec based on various loader methods.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_26_consts_2 = {
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
    ._data = "_ORIGIN",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_26_consts_3 = {
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
    ._data = "get_filename",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_26_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_22_varnames_1._ascii.ob_base,
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
toplevel_consts_26_consts_5 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
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
toplevel_consts_26_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_26_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_26_consts_2._ascii.ob_base,
            & toplevel_consts_26_consts_3._ascii.ob_base,
            & toplevel_consts_26_consts_4._object.ob_base.ob_base,
            & toplevel_consts_26_consts_5._object.ob_base.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
            Py_False,
            & toplevel_consts_25._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_26_names_4 = {
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
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_26_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_26_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_23_consts_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_26_varnames_5 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_26_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
            & toplevel_consts_26_names_4._ascii.ob_base,
            & toplevel_consts_26_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[49];
    }
toplevel_consts_26_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 48,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x0c\x01\x0e\x02\x04\x01\x04\x01\x06\x01\x04\x02\x0c\x01\x0c\x01\x06\x01\x02\x01\x06\xff\x04\x03\x0a\x01\x02\x01\x0e\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x04\x04\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_consts_26_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x0e\x01\x02\x02\x02\x09\x08\xf7\x02\x09\x02\xf8\x06\x01\x06\x01\x02\x02\x0e\x01\x0c\x01\x06\x01\x08\x01\x02\x02\x02\x08\x08\xf9\x02\x07\x02\xfd\x0e\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x04\x03\x10\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[163];
    }
toplevel_consts_26_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 162,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0e\x05\x32\x12\x19\x1a\x20\x22\x2b\x2d\x31\x12\x32\x09\x0f\x0c\x12\x05\x4a\x17\x1e\x1f\x25\x27\x35\x17\x36\x05\x4a\x0c\x1f\x09\x26\x13\x26\x0d\x26\x23\x36\x23\x4e\x09\x20\x0c\x16\x09\x40\x14\x2b\x2c\x30\x39\x3f\x14\x40\x14\x40\x0d\x40\x18\x22\x12\x2c\x12\x14\x12\x14\x28\x2c\x09\x0f\x10\x27\x28\x2c\x35\x3b\x43\x49\x10\x4a\x10\x4a\x09\x4a\x08\x12\x05\x1f\x0c\x13\x14\x1a\x1c\x28\x0c\x29\x09\x1f\x0d\x22\x1e\x24\x1e\x35\x30\x34\x1e\x35\x1e\x35\x11\x1b\x11\x1b\x00\x00\x14\x1f\x0d\x22\x0d\x22\x1e\x22\x11\x1b\x11\x1b\x11\x1b\x0d\x22\x00\x00\x00\x00\x00\x00\x1a\x1f\x0d\x17\x0c\x16\x17\x1b\x1d\x23\x2c\x32\x3f\x49\x0c\x4a\x0c\x4a\x05\x4a",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[16];
    }
toplevel_consts_26_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 15,
    },
    .ob_shash = -1,
    .ob_sval = "\xb4\x06\x3b\x00\xbb\x06\x41\x04\x03\xc1\x03\x01\x41\x04\x03",
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
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 2,
    .co_stacksize = 6,
    .co_firstlineno = 422,
    .co_code = & toplevel_consts_26_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_23_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_names_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_26_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_26_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_26_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_26_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[267];
    }
toplevel_consts_27_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 266,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x6a\x00\x7d\x03\x6e\x0a\x23\x00\x74\x01\x79\x0c\x01\x00\x59\x00\x6e\x08\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x03\x81\x14\x7c\x03\x53\x00\x7c\x00\x6a\x02\x7d\x04\x7c\x01\x80\x28\x09\x00\x7c\x00\x6a\x03\x7d\x01\x6e\x0a\x23\x00\x74\x01\x79\x24\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x00\x6a\x04\x7d\x05\x6e\x0c\x23\x00\x74\x01\x79\x35\x01\x00\x64\x00\x7d\x05\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x80\x49\x7c\x01\x81\x43\x74\x05\x7c\x01\x64\x01\x64\x00\xa9\x03\x7d\x02\x7c\x02\x73\x49\x7c\x05\x81\x49\x7c\x05\x7d\x02\x09\x00\x7c\x00\x6a\x06\x7d\x06\x6e\x0c\x23\x00\x74\x01\x79\x56\x01\x00\x64\x00\x7d\x06\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x74\x07\x7c\x00\x6a\x08\xa9\x01\x7d\x07\x6e\x0c\x23\x00\x74\x01\x79\x69\x01\x00\x64\x00\x7d\x07\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x09\x7c\x04\x7c\x01\x7c\x02\x64\x02\xaa\x03\x7d\x03\x7c\x05\x80\x78\x64\x03\x6e\x03\x7c\x02\x7c\x05\x6b\x02\x7c\x03\x5f\x0a\x7c\x06\x7c\x03\x5f\x0b\x7c\x07\x7c\x03\x5f\x0c\x7c\x03\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_27_consts_2 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
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
toplevel_consts_27_consts = {
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
            & toplevel_consts_26_consts_2._ascii.ob_base,
            & toplevel_consts_27_consts_2._object.ob_base.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_27_names_6 = {
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
        uint8_t _data[5];
    }
toplevel_consts_27_names_7 = {
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
        uint8_t _data[9];
    }
toplevel_consts_27_names_8 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_27_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_27_names_6._ascii.ob_base,
            & toplevel_consts_27_names_7._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_27_varnames_5 = {
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
    ._data = "location",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_27_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_27_varnames_5._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_27_name = {
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
    ._data = "_spec_from_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_27_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x08\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x04\x03\x04\x01\x06\x02\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x04\x02\x02\xfe\x06\x80\x02\x03\x08\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x04\x02\x04\x01\x0c\x01\x08\x01\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x02\x02\x0c\x01\x02\x80\x06\x01\x08\x01\x02\xff\x06\x80\x0e\x03\x12\x01\x06\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[97];
    }
toplevel_consts_27_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 96,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x08\x08\xfb\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x02\x06\x01\x06\x02\x02\x01\x04\x05\x08\xfd\x02\x80\x02\x01\x0a\x02\x06\x80\x02\x04\x08\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x02\x01\x02\x04\x02\xfd\x0e\x01\x02\x01\x02\x01\x02\xff\x06\x01\x02\x04\x08\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x02\x04\x0c\xfe\x02\x80\x02\x01\x0e\x01\x06\x80\x0e\x02\x12\x01\x06\x01\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[267];
    }
toplevel_consts_27_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 266,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x18\x10\x16\x10\x1f\x09\x0d\x09\x0d\x00\x00\x0c\x1a\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x0c\x10\x09\x18\x14\x18\x0d\x18\x0c\x12\x0c\x1b\x05\x09\x08\x0e\x05\x11\x09\x11\x16\x1c\x16\x27\x0d\x13\x0d\x13\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x05\x18\x14\x1a\x14\x23\x09\x11\x09\x11\x00\x00\x0c\x1a\x05\x18\x05\x18\x14\x18\x09\x11\x09\x11\x09\x11\x05\x18\x00\x00\x00\x00\x00\x00\x08\x0e\x05\x1e\x0c\x12\x09\x36\x16\x1d\x1e\x24\x26\x2f\x31\x35\x16\x36\x0d\x13\x10\x16\x09\x1e\x1b\x23\x09\x1e\x16\x1e\x0d\x13\x05\x16\x12\x18\x12\x23\x09\x0f\x09\x0f\x00\x00\x0c\x1a\x05\x16\x05\x16\x12\x16\x09\x0f\x09\x0f\x09\x0f\x05\x16\x00\x00\x00\x00\x00\x00\x05\x2a\x26\x2a\x2b\x31\x2b\x3a\x26\x3b\x09\x23\x09\x23\x00\x00\x0c\x1a\x05\x2a\x05\x2a\x26\x2a\x09\x23\x09\x23\x09\x23\x05\x2a\x00\x00\x00\x00\x00\x00\x0c\x16\x17\x1b\x1d\x23\x2c\x32\x0c\x33\x0c\x33\x05\x09\x23\x2b\x1a\x4d\x1a\x1f\x1a\x1f\x3a\x40\x44\x4c\x3a\x4c\x05\x09\x05\x17\x13\x19\x05\x09\x05\x10\x27\x41\x05\x09\x05\x24\x0c\x10\x05\x10",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_27_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x03\x06\x00\x86\x04\x0d\x03\x8c\x01\x0d\x03\x9a\x03\x1e\x00\x9e\x04\x25\x03\xa4\x01\x25\x03\xa9\x03\x2d\x00\xad\x06\x36\x03\xb5\x01\x36\x03\xc1\x0a\x03\x41\x0e\x00\xc1\x0e\x06\x41\x17\x03\xc1\x16\x01\x41\x17\x03\xc1\x1b\x05\x41\x21\x00\xc1\x21\x06\x41\x2a\x03\xc1\x29\x01\x41\x2a\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_27_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_27 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_27_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_27_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_27_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_27_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 451,
    .co_code = & toplevel_consts_27_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_27_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_27_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_27_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_27_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_27_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_27_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_27_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_27_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_29_0 = {
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
    ._data = "override",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_29 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_29_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[407];
    }
toplevel_consts_30_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 406,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x73\x09\x74\x00\x7c\x01\x64\x01\x64\x00\xa9\x03\x80\x19\x09\x00\x7c\x00\x6a\x01\x7c\x01\x5f\x02\x6e\x0a\x23\x00\x74\x03\x79\x15\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x73\x21\x74\x00\x7c\x01\x64\x02\x64\x00\xa9\x03\x80\x4f\x7c\x00\x6a\x04\x7d\x03\x7c\x03\x80\x40\x7c\x00\x6a\x05\x81\x40\x74\x06\x80\x2d\x74\x07\x82\x01\x74\x06\x6a\x08\x7d\x04\x7c\x04\xa0\x09\x7c\x04\xa8\x01\xa9\x01\x7d\x03\x7c\x00\x6a\x05\x7c\x03\x5f\x0a\x7c\x03\x7c\x00\x5f\x04\x64\x00\x7c\x01\x5f\x0b\x09\x00\x7c\x03\x7c\x01\x5f\x0c\x6e\x0a\x23\x00\x74\x03\x79\x4b\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x73\x57\x74\x00\x7c\x01\x64\x03\x64\x00\xa9\x03\x80\x67\x09\x00\x7c\x00\x6a\x0d\x7c\x01\x5f\x0e\x6e\x0a\x23\x00\x74\x03\x79\x63\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x7c\x00\x7c\x01\x5f\x0f\x6e\x0a\x23\x00\x74\x03\x79\x72\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x73\x7e\x74\x00\x7c\x01\x64\x04\x64\x00\xa9\x03\x80\x91\x7c\x00\x6a\x05\x81\x91\x09\x00\x7c\x00\x6a\x05\x7c\x01\x5f\x10\x6e\x0a\x23\x00\x74\x03\x79\x8d\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x00\x6a\x11\x72\xc9\x7c\x02\x73\x9c\x74\x00\x7c\x01\x64\x05\x64\x00\xa9\x03\x80\xac\x09\x00\x7c\x00\x6a\x12\x7c\x01\x5f\x0b\x6e\x0a\x23\x00\x74\x03\x79\xa8\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x73\xb4\x74\x00\x7c\x01\x64\x06\x64\x00\xa9\x03\x80\xc9\x7c\x00\x6a\x13\x81\xc9\x09\x00\x7c\x00\x6a\x13\x7c\x01\x5f\x14\x7c\x01\x53\x00\x23\x00\x74\x03\x79\xc5\x01\x00\x59\x00\x7c\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_30_consts_3 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_30_consts = {
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
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_30_consts_3._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_27_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_30_names_8 = {
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
    ._data = "NamespaceLoader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_30_names_9 = {
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
        uint8_t _data[6];
    }
toplevel_consts_30_names_10 = {
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
    ._data = "_path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[21];
        }_object;
    }
toplevel_consts_30_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 21,
        },
        .ob_item = {
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_30_names_8._ascii.ob_base,
            & toplevel_consts_30_names_9._ascii.ob_base,
            & toplevel_consts_30_names_10._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_23_consts_9_name._ascii.ob_base,
            & toplevel_consts_30_consts_3._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_4._ascii.ob_base,
            & toplevel_consts_27_names_6._ascii.ob_base,
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
toplevel_consts_30_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_29_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_30_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_30_name = {
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
    ._data = "_init_module_attrs",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[145];
    }
toplevel_consts_30_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 144,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x04\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x10\x03\x06\x01\x04\x01\x06\x02\x04\x01\x04\x01\x06\x01\x0c\x02\x08\x01\x06\x01\x06\x0b\x02\x01\x08\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x10\x03\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x02\x03\x08\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x10\x03\x06\x01\x02\x02\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x06\x03\x10\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x10\x03\x06\x01\x02\x01\x08\x01\x04\x03\x02\x80\x06\xfe\x02\x01\x04\x01\x02\xfe\x06\x80\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[169];
    }
toplevel_consts_30_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 168,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x04\x02\x04\x0a\xfc\x04\x04\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x02\x02\x1a\x0a\xe6\x02\x1a\x06\xe7\x02\x01\x02\x14\x04\xee\x02\x12\x02\xef\x06\x01\x06\x01\x0c\x02\x08\x01\x06\x01\x06\x0b\x02\x04\x08\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x02\x02\x04\x0a\xfc\x04\x04\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x05\x08\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x02\x02\x06\x0a\xfa\x02\x06\x04\xfb\x04\x05\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x04\x02\x02\x0c\x02\xf5\x02\x04\x0a\xfc\x04\x04\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x02\x02\x05\x0a\xfb\x02\x05\x04\xfc\x04\x04\x08\xfe\x04\x03\x02\x80\x02\xfe\x06\x01\x04\x01\x02\xff\x06\x80\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[407];
    }
toplevel_consts_30_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 406,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x11\x05\x11\x15\x1c\x1d\x23\x25\x2f\x31\x35\x15\x36\x05\x11\x09\x11\x1f\x23\x1f\x28\x0d\x13\x0d\x1c\x0d\x1c\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x08\x10\x05\x11\x14\x1b\x1c\x22\x24\x30\x32\x36\x14\x37\x05\x11\x12\x16\x12\x1d\x09\x0f\x0c\x12\x09\x27\x10\x14\x10\x2f\x0d\x27\x14\x27\x11\x2e\x1b\x2e\x15\x2e\x23\x36\x23\x46\x11\x20\x1a\x29\x1a\x42\x32\x41\x1a\x42\x1a\x42\x11\x17\x20\x24\x20\x3f\x11\x17\x11\x1d\x1f\x25\x11\x15\x11\x1c\x23\x27\x11\x17\x11\x20\x09\x11\x21\x27\x0d\x13\x0d\x1e\x0d\x1e\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x08\x10\x05\x11\x14\x1b\x1c\x22\x24\x31\x33\x37\x14\x38\x05\x11\x09\x11\x22\x26\x22\x2d\x0d\x13\x0d\x1f\x0d\x1f\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x05\x0d\x1b\x1f\x09\x0f\x09\x18\x09\x18\x00\x00\x0c\x1a\x05\x0d\x05\x0d\x09\x0d\x09\x0d\x05\x0d\x00\x00\x00\x00\x00\x00\x08\x10\x05\x15\x14\x1b\x1c\x22\x24\x2e\x30\x34\x14\x35\x05\x15\x0c\x10\x0c\x2b\x09\x15\x0d\x15\x23\x27\x23\x42\x11\x17\x11\x20\x11\x20\x00\x00\x14\x22\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x08\x0c\x08\x19\x05\x19\x0c\x14\x09\x15\x18\x1f\x20\x26\x28\x32\x34\x38\x18\x39\x09\x15\x0d\x15\x23\x27\x23\x2e\x11\x17\x11\x20\x11\x20\x00\x00\x14\x22\x0d\x15\x0d\x15\x11\x15\x11\x15\x0d\x15\x00\x00\x00\x00\x00\x00\x0c\x14\x09\x19\x18\x1f\x20\x26\x28\x34\x36\x3a\x18\x3b\x09\x19\x10\x14\x10\x1b\x0d\x19\x11\x19\x29\x2d\x29\x34\x15\x1b\x15\x26\x0c\x12\x05\x12\x00\x00\x18\x26\x11\x19\x11\x19\x15\x19\x0c\x12\x05\x12\x11\x19\x00\x00\x00\x00\x00\x00\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[121];
    }
toplevel_consts_30_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 120,
    },
    .ob_shash = -1,
    .ob_sval = "\x8a\x04\x0f\x00\x8f\x04\x16\x03\x95\x01\x16\x03\xc1\x01\x03\x41\x05\x00\xc1\x05\x04\x41\x0c\x03\xc1\x0b\x01\x41\x0c\x03\xc1\x18\x04\x41\x1d\x00\xc1\x1d\x04\x41\x24\x03\xc1\x23\x01\x41\x24\x03\xc1\x28\x03\x41\x2c\x00\xc1\x2c\x04\x41\x33\x03\xc1\x32\x01\x41\x33\x03\xc2\x02\x04\x42\x07\x00\xc2\x07\x04\x42\x0e\x03\xc2\x0d\x01\x42\x0e\x03\xc2\x1d\x04\x42\x22\x00\xc2\x22\x04\x42\x29\x03\xc2\x28\x01\x42\x29\x03\xc2\x38\x04\x42\x3e\x00\xc2\x3e\x04\x43\x06\x03\xc3\x05\x01\x43\x06\x03",
};
static struct PyCodeObject toplevel_consts_30 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_30_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_30_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_30_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_30_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 4,
    .co_firstlineno = 493,
    .co_code = & toplevel_consts_30_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_30_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_30_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_30_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_30_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_30_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_30_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_30_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_31_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7d\x01\x74\x00\x7c\x00\x6a\x01\x64\x02\xa9\x02\x72\x11\x7c\x00\x6a\x01\xa0\x02\x7c\x00\xa8\x01\xa9\x01\x7d\x01\x6e\x0a\x74\x00\x7c\x00\x6a\x01\x64\x03\xa9\x02\x72\x1b\x74\x03\x64\x04\xa9\x01\x82\x01\x7c\x01\x80\x22\x74\x04\x7c\x00\x6a\x05\xa9\x01\x7d\x01\x74\x06\x7c\x00\x7c\x01\xa9\x02\x01\x00\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[44];
    }
toplevel_consts_31_consts_0 = {
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
    ._data = "Create a module based on the provided spec.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_31_consts_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_31_consts_3 = {
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
        uint8_t _data[67];
    }
toplevel_consts_31_consts_4 = {
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
    ._data = "loaders that define exec_module() must also define create_module()",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_31_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_31_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_31_consts_2._ascii.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_31_consts_4._ascii.ob_base,
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
toplevel_consts_31_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_31_consts_2._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
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
toplevel_consts_31_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_31_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_31_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x03\x0c\x01\x10\x03\x0c\x01\x08\x01\x04\x02\x0a\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_31_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x03\x0a\x01\x02\x06\x10\xfd\x0a\x01\x02\x02\x02\xff\x06\x01\x02\x01\x0c\x01\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_31_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x12\x05\x0b\x08\x0f\x10\x14\x10\x1b\x1d\x2c\x08\x2d\x05\x3e\x12\x16\x12\x1d\x12\x31\x2c\x30\x12\x31\x12\x31\x09\x0f\x09\x0f\x0a\x11\x12\x16\x12\x1d\x1f\x2c\x0a\x2d\x05\x3e\x0f\x1a\x1b\x3d\x0f\x3e\x09\x3e\x08\x0e\x05\x28\x12\x1d\x1e\x22\x1e\x27\x12\x28\x09\x0f\x05\x17\x18\x1c\x1e\x24\x05\x25\x05\x25\x0c\x12\x05\x12",
};
static struct PyCodeObject toplevel_consts_31 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_31_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_31_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_31_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 566,
    .co_code = & toplevel_consts_31_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_31_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_31_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_31_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_31_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_32_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x80\x06\x64\x02\x6e\x02\x7c\x00\x6a\x00\x7d\x01\x7c\x00\x6a\x01\x80\x1d\x7c\x00\x6a\x02\x80\x15\x64\x03\xa0\x03\x7c\x01\xa8\x01\xa9\x01\x53\x00\x64\x04\xa0\x03\x7c\x01\x7c\x00\x6a\x02\xa8\x02\xa9\x02\x53\x00\x7c\x00\x6a\x04\x72\x28\x64\x05\xa0\x03\x7c\x01\x7c\x00\x6a\x01\xa8\x02\xa9\x02\x53\x00\x64\x06\xa0\x03\x7c\x00\x6a\x00\x7c\x00\x6a\x01\xa8\x02\xa9\x02\x53\x00",
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
    ._data = "Return the repr to use for the module.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_32_consts_6 = {
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
    ._data = "<module {!r} ({})>",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_32_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_32_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_22_consts_5._ascii.ob_base,
            & toplevel_consts_22_consts_6._ascii.ob_base,
            & toplevel_consts_22_consts_7._ascii.ob_base,
            & toplevel_consts_22_consts_8._ascii.ob_base,
            & toplevel_consts_32_consts_6._ascii.ob_base,
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
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_0._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
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
toplevel_consts_32_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_32_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x03\x06\x01\x06\x01\x0c\x01\x10\x02\x06\x02\x10\x01\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_32_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x03\x04\x01\x02\x09\x04\xf8\x02\x03\x0c\xfe\x10\x02\x04\x02\x02\x03\x10\xfe\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[99];
    }
toplevel_consts_32_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 98,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x13\x17\x13\x1c\x0c\x33\x0c\x0f\x0c\x0f\x2a\x2e\x2a\x33\x05\x09\x08\x0c\x08\x13\x05\x47\x0c\x10\x0c\x17\x09\x44\x14\x23\x14\x30\x2b\x2f\x14\x30\x14\x30\x0d\x30\x14\x2a\x14\x44\x32\x36\x38\x3c\x38\x43\x14\x44\x14\x44\x0d\x44\x0c\x10\x0c\x1d\x09\x47\x14\x2d\x14\x47\x35\x39\x3b\x3f\x3b\x46\x14\x47\x14\x47\x0d\x47\x14\x28\x14\x47\x30\x34\x30\x39\x3b\x3f\x3b\x46\x14\x47\x14\x47\x0d\x47",
};
static struct PyCodeObject toplevel_consts_32 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_32_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_32_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_32_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 583,
    .co_code = & toplevel_consts_32_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_32_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_22_names_1._ascii.ob_base,
    .co_linetable = & toplevel_consts_32_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_32_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_32_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_32_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[301];
    }
toplevel_consts_33_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 300,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x02\x74\x01\x7c\x02\xa9\x01\x35\x00\x01\x00\x74\x02\x6a\x03\xa0\x04\x7c\x02\xa8\x01\xa9\x01\x7c\x01\x75\x01\x72\x1e\x64\x01\xa0\x05\x7c\x02\xa8\x01\xa9\x01\x7d\x03\x74\x06\x7c\x03\x7c\x02\x64\x02\xaa\x02\x82\x01\x09\x00\x7c\x00\x6a\x07\x80\x34\x7c\x00\x6a\x08\x80\x2c\x74\x06\x64\x04\x7c\x00\x6a\x00\x64\x02\xaa\x02\x82\x01\x74\x09\x7c\x00\x7c\x01\x64\x05\x64\x06\xaa\x03\x01\x00\x6e\x2b\x74\x09\x7c\x00\x7c\x01\x64\x05\x64\x06\xaa\x03\x01\x00\x74\x0a\x7c\x00\x6a\x07\x64\x07\xa9\x02\x73\x58\x74\x0b\x7c\x00\x6a\x07\xa9\x01\x9b\x00\x64\x08\x9d\x02\x7d\x03\x74\x0c\xa0\x0d\x7c\x03\x74\x0e\xa8\x02\xa9\x02\x01\x00\x7c\x00\x6a\x07\xa0\x0f\x7c\x02\xa8\x01\xa9\x01\x01\x00\x6e\x07\x7c\x00\x6a\x07\xa0\x10\x7c\x01\xa8\x01\xa9\x01\x01\x00\x74\x02\x6a\x03\xa0\x11\x7c\x00\x6a\x00\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x74\x02\x6a\x03\x7c\x00\x6a\x00\x3c\x00\x6e\x13\x23\x00\x74\x02\x6a\x03\xa0\x11\x7c\x00\x6a\x00\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x74\x02\x6a\x03\x7c\x00\x6a\x00\x3c\x00\x77\x00\x78\x03\x59\x00\x77\x01\x09\x00\x64\x03\x04\x00\x04\x00\xa9\x03\x01\x00\x7c\x01\x53\x00\x23\x00\x31\x00\x73\x90\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[71];
    }
toplevel_consts_33_consts_0 = {
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
    ._data = "Execute the spec's specified module in an existing module's namespace.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[31];
    }
toplevel_consts_33_consts_1 = {
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
    ._data = "module {!r} not in sys.modules",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_33_consts_4 = {
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
    ._data = "missing loader",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[56];
    }
toplevel_consts_33_consts_8 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 55,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = ".exec_module() not found; falling back to load_module()",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_33_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_33_consts_0._ascii.ob_base,
            & toplevel_consts_33_consts_1._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
            Py_None,
            & toplevel_consts_33_consts_4._ascii.ob_base,
            Py_True,
            & toplevel_consts_29._object.ob_base.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_33_consts_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_33_names_14 = {
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
    ._data = "ImportWarning",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_33_names_15 = {
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
    ._data = "load_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_33_names_17 = {
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
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_33_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_1_name._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
            & toplevel_consts_33_names_15._ascii.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
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
toplevel_consts_33_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_21_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[57];
    }
toplevel_consts_33_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 56,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0a\x01\x12\x01\x0c\x01\x0c\x01\x02\x01\x06\x01\x06\x01\x0e\x01\x10\x02\x0e\x02\x0c\x01\x10\x01\x0e\x02\x10\x01\x0e\x02\x10\x04\x0e\x01\x02\x80\x10\xff\x16\x01\x0a\xe9\x04\x18\x08\xe8\x06\x80\x08\x00\x04\x18",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[67];
    }
toplevel_consts_33_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 66,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x06\x01\x04\x17\x10\xea\x02\x02\x0c\xff\x0c\x01\x02\x14\x04\xee\x02\x0d\x04\xf4\x10\x01\x10\x02\x0e\x02\x0a\x01\x02\x06\x08\xfb\x06\x01\x02\xff\x0e\x02\x10\x01\x0e\x02\x10\x04\x0e\x01\x02\x80\x10\xff\x20\x01\x04\x01\x08\xff\x06\x80\x08\x00\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[301];
    }
toplevel_consts_33_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 300,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x15\x05\x09\x0a\x1c\x1d\x21\x0a\x22\x05\x2c\x05\x2c\x0c\x0f\x0c\x17\x0c\x21\x1c\x20\x0c\x21\x0c\x21\x29\x2f\x0c\x2f\x09\x2e\x13\x33\x13\x40\x3b\x3f\x13\x40\x13\x40\x0d\x10\x13\x1e\x1f\x22\x29\x2d\x13\x2e\x13\x2e\x0d\x2e\x09\x2c\x10\x14\x10\x1b\x0d\x34\x14\x18\x14\x33\x11\x48\x1b\x26\x27\x37\x3e\x42\x3e\x47\x1b\x48\x1b\x48\x15\x48\x11\x23\x24\x28\x2a\x30\x3b\x3f\x11\x40\x11\x40\x11\x40\x11\x40\x11\x23\x24\x28\x2a\x30\x3b\x3f\x11\x40\x11\x40\x11\x40\x18\x1f\x20\x24\x20\x2b\x2d\x3a\x18\x3b\x11\x34\x1f\x2b\x2c\x30\x2c\x37\x1f\x38\x1c\x3b\x1c\x3b\x1c\x3b\x15\x18\x15\x1e\x15\x37\x24\x27\x29\x36\x15\x37\x15\x37\x15\x37\x15\x19\x15\x20\x15\x32\x2d\x31\x15\x32\x15\x32\x15\x32\x15\x32\x15\x19\x15\x20\x15\x34\x2d\x33\x15\x34\x15\x34\x15\x34\x16\x19\x16\x21\x16\x30\x26\x2a\x26\x2f\x16\x30\x16\x30\x0d\x13\x26\x2c\x0d\x10\x0d\x18\x19\x1d\x19\x22\x0d\x23\x0d\x23\x00\x00\x16\x19\x16\x21\x16\x30\x26\x2a\x26\x2f\x16\x30\x16\x30\x0d\x13\x26\x2c\x0d\x10\x0d\x18\x19\x1d\x19\x22\x0d\x23\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x2c\x0d\x23\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x0c\x12\x05\x12\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x00\x00\x00\x00\x00\x00\x05\x2c\x05\x2c\x05\x2c\x05\x2c\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[42];
    }
toplevel_consts_33_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 41,
    },
    .ob_shash = -1,
    .ob_sval = "\x88\x16\x42\x09\x03\x9f\x41\x00\x41\x2e\x02\xc1\x1f\x0f\x42\x09\x03\xc1\x2e\x10\x41\x3e\x05\xc1\x3e\x03\x42\x09\x03\xc2\x09\x04\x42\x0d\x07\xc2\x10\x01\x42\x0d\x07",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_33_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_33 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_33_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_33_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_33_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_33_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 600,
    .co_code = & toplevel_consts_33_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_33_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_names_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_33_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_33_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_33_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_33_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[271];
    }
toplevel_consts_34_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 270,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x09\x00\x7c\x00\x6a\x00\xa0\x01\x7c\x00\x6a\x02\xa8\x01\xa9\x01\x01\x00\x6e\x1a\x23\x00\x01\x00\x7c\x00\x6a\x02\x74\x03\x6a\x04\x76\x00\x72\x21\x74\x03\x6a\x04\xa0\x05\x7c\x00\x6a\x02\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x74\x03\x6a\x04\x7c\x00\x6a\x02\x3c\x00\x82\x00\x78\x03\x59\x00\x77\x01\x74\x03\x6a\x04\xa0\x05\x7c\x00\x6a\x02\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x74\x03\x6a\x04\x7c\x00\x6a\x02\x3c\x00\x74\x06\x7c\x01\x64\x01\x64\x00\xa9\x03\x80\x49\x09\x00\x7c\x00\x6a\x00\x7c\x01\x5f\x07\x6e\x0a\x23\x00\x74\x08\x79\x45\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x06\x7c\x01\x64\x02\x64\x00\xa9\x03\x80\x6e\x09\x00\x7c\x01\x6a\x09\x7c\x01\x5f\x0a\x74\x0b\x7c\x01\x64\x03\xa9\x02\x73\x63\x7c\x00\x6a\x02\xa0\x0c\x64\x04\xa8\x01\xa9\x01\x64\x05\x19\x00\x7c\x01\x5f\x0a\x6e\x0a\x23\x00\x74\x08\x79\x6a\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x74\x06\x7c\x01\x64\x06\x64\x00\xa9\x03\x80\x85\x09\x00\x7c\x00\x7c\x01\x5f\x0d\x7c\x01\x53\x00\x23\x00\x74\x08\x79\x81\x01\x00\x59\x00\x7c\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_34_consts = {
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
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_30_consts_3._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
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
toplevel_consts_34_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_33_names_15._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_22_consts_1._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_30_consts_3._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_23_consts_9_names_2._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_34_name = {
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
    ._data = "_load_backward_compatible",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_34_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x03\x12\x01\x02\x80\x02\x01\x0c\x01\x10\x01\x0c\x01\x02\x01\x06\x80\x10\x03\x0c\x01\x0c\x01\x02\x01\x0a\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x0c\x02\x02\x01\x08\x04\x0a\x01\x14\x01\x04\x80\x06\x01\x04\x01\x02\xff\x06\x80\x0c\x02\x02\x01\x06\x01\x04\x03\x02\x80\x06\xfe\x02\x01\x04\x01\x02\xfe\x06\x80\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_34_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x09\x12\xfb\x02\x80\x02\x05\x0a\xfd\x02\x02\x10\xff\x0c\x01\x02\x01\x06\x80\x10\x03\x0c\x01\x0a\x01\x04\x04\x0a\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x0a\x01\x04\x09\x08\xfc\x08\x01\x16\x01\x04\x80\x02\x01\x0a\x01\x06\x80\x0a\x01\x04\x04\x06\xfe\x04\x03\x02\x80\x02\xfe\x06\x01\x04\x01\x02\xff\x06\x80\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[271];
    }
toplevel_consts_34_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 270,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0e\x09\x0d\x09\x14\x09\x2b\x21\x25\x21\x2a\x09\x2b\x09\x2b\x09\x2b\x09\x2b\x00\x00\x05\x0e\x0c\x10\x0c\x15\x19\x1c\x19\x24\x0c\x24\x09\x2c\x16\x19\x16\x21\x16\x30\x26\x2a\x26\x2f\x16\x30\x16\x30\x0d\x13\x26\x2c\x0d\x10\x0d\x18\x19\x1d\x19\x22\x0d\x23\x09\x0e\x00\x00\x00\x00\x00\x00\x0e\x11\x0e\x19\x0e\x28\x1e\x22\x1e\x27\x0e\x28\x0e\x28\x05\x0b\x1e\x24\x05\x08\x05\x10\x11\x15\x11\x1a\x05\x1b\x08\x0f\x10\x16\x18\x24\x26\x2a\x08\x2b\x05\x11\x09\x11\x21\x25\x21\x2c\x0d\x13\x0d\x1e\x0d\x1e\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x08\x0f\x10\x16\x18\x25\x27\x2b\x08\x2c\x05\x11\x09\x11\x22\x28\x22\x31\x0d\x13\x0d\x1f\x14\x1b\x1c\x22\x24\x2e\x14\x2f\x0d\x42\x26\x2a\x26\x2f\x26\x3f\x3b\x3e\x26\x3f\x26\x3f\x40\x41\x26\x42\x11\x17\x11\x23\x00\x00\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0d\x11\x09\x11\x00\x00\x00\x00\x00\x00\x08\x0f\x10\x16\x18\x22\x24\x28\x08\x29\x05\x11\x09\x11\x1f\x23\x0d\x13\x0d\x1c\x0c\x12\x05\x12\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x0c\x12\x05\x12\x09\x11\x00\x00\x00\x00\x00\x00\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[60];
    }
toplevel_consts_34_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 59,
    },
    .ob_shash = -1,
    .ob_sval = "\x82\x08\x0b\x00\x8b\x17\x22\x03\xba\x04\x3f\x00\xbf\x04\x41\x06\x03\xc1\x05\x01\x41\x06\x03\xc1\x10\x13\x41\x24\x00\xc1\x24\x04\x41\x2b\x03\xc1\x2a\x01\x41\x2b\x03\xc1\x35\x03\x41\x3a\x00\xc1\x3a\x04\x42\x02\x03\xc2\x01\x01\x42\x02\x03",
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
    .co_firstlineno = 630,
    .co_code = & toplevel_consts_34_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_34_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_34_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_34_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_34_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_34_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_31_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[247];
    }
toplevel_consts_35_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 246,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x81\x1d\x74\x01\x7c\x00\x6a\x00\x64\x01\xa9\x02\x73\x1d\x74\x02\x7c\x00\x6a\x00\xa9\x01\x9b\x00\x64\x02\x9d\x02\x7d\x01\x74\x03\xa0\x04\x7c\x01\x74\x05\xa8\x02\xa9\x02\x01\x00\x74\x06\x7c\x00\xa9\x01\x53\x00\x74\x07\x7c\x00\xa9\x01\x7d\x02\x64\x03\x7c\x00\x5f\x08\x09\x00\x7c\x02\x74\x09\x6a\x0a\x7c\x00\x6a\x0b\x3c\x00\x09\x00\x7c\x00\x6a\x00\x80\x3a\x7c\x00\x6a\x0c\x80\x39\x74\x0d\x64\x04\x7c\x00\x6a\x0b\x64\x05\xaa\x02\x82\x01\x6e\x07\x7c\x00\x6a\x00\xa0\x0e\x7c\x02\xa8\x01\xa9\x01\x01\x00\x6e\x16\x23\x00\x01\x00\x09\x00\x74\x09\x6a\x0a\x7c\x00\x6a\x0b\x3d\x00\x82\x00\x23\x00\x74\x0f\x79\x51\x01\x00\x59\x00\x82\x00\x77\x00\x78\x03\x59\x00\x77\x01\x78\x03\x59\x00\x77\x01\x74\x09\x6a\x0a\xa0\x10\x7c\x00\x6a\x0b\xa8\x01\xa9\x01\x7d\x02\x7c\x02\x74\x09\x6a\x0a\x7c\x00\x6a\x0b\x3c\x00\x74\x11\x64\x06\x7c\x00\x6a\x0b\x7c\x00\x6a\x00\xa9\x03\x01\x00\x64\x07\x7c\x00\x5f\x08\x7c\x02\x53\x00\x23\x00\x64\x07\x7c\x00\x5f\x08\x77\x00\x78\x03\x59\x00\x77\x01",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_35_consts_6 = {
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
    ._data = "import {!r} # {!r}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_35_consts = {
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
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_33_consts_8._ascii.ob_base,
            Py_True,
            & toplevel_consts_33_consts_4._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
            & toplevel_consts_35_consts_6._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_35_names_8 = {
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
    ._data = "_initializing",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_35_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_1_name._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
            & toplevel_consts_34_name._ascii.ob_base,
            & toplevel_consts_31_name._ascii.ob_base,
            & toplevel_consts_35_names_8._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_13_names_3._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
            & toplevel_consts_18_name._ascii.ob_base,
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
toplevel_consts_35_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_2._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_35_name = {
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
    ._data = "_load_unlocked",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[69];
    }
toplevel_consts_35_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 68,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x0c\x02\x10\x01\x0e\x02\x08\x01\x08\x02\x06\x05\x02\x01\x0c\x01\x02\x01\x06\x01\x06\x01\x0e\x01\x02\xff\x0e\x04\x04\x80\x02\x01\x02\x01\x0a\x01\x02\x03\x02\x80\x06\xfe\x02\x01\x02\x01\x02\xfe\x0c\x80\x10\x07\x0c\x01\x10\x01\x06\x02\x04\x02\x02\x80\x0e\xfe",
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
    .ob_sval = "\x02\x00\x04\x02\x02\x06\x0a\xfc\x02\x04\x08\xfd\x06\x01\x02\xff\x0e\x02\x08\x01\x08\x02\x06\x05\x02\x18\x0c\xea\x02\x0d\x04\xf5\x02\x05\x04\xfc\x12\x01\x0e\x03\x04\x80\x02\x06\x02\xff\x0a\xfe\x02\x03\x02\x80\x02\xfe\x06\x01\x02\x01\x02\xff\x0c\x80\x10\x06\x0c\x01\x10\x01\x06\x02\x04\x02\x02\x80\x0e\xfe",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[247];
    }
toplevel_consts_35_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 246,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0c\x08\x13\x05\x33\x10\x17\x18\x1c\x18\x23\x25\x32\x10\x33\x09\x33\x17\x23\x24\x28\x24\x2f\x17\x30\x14\x34\x14\x34\x14\x34\x0d\x10\x0d\x16\x0d\x2f\x1c\x1f\x21\x2e\x0d\x2f\x0d\x2f\x0d\x2f\x14\x2d\x2e\x32\x14\x33\x0d\x33\x0e\x1e\x1f\x23\x0e\x24\x05\x0b\x1a\x1e\x05\x09\x05\x17\x05\x23\x22\x28\x09\x0c\x09\x14\x15\x19\x15\x1e\x09\x1f\x09\x12\x10\x14\x10\x1b\x0d\x30\x14\x18\x14\x33\x11\x48\x1b\x26\x27\x37\x3e\x42\x3e\x47\x1b\x48\x1b\x48\x15\x48\x11\x48\x11\x15\x11\x1c\x11\x30\x29\x2f\x11\x30\x11\x30\x11\x30\x00\x00\x00\x00\x09\x12\x0d\x15\x15\x18\x15\x20\x21\x25\x21\x2a\x15\x2b\x0d\x12\x00\x00\x14\x1c\x0d\x15\x0d\x15\x11\x15\x0d\x12\x0d\x15\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x12\x15\x12\x1d\x12\x2c\x22\x26\x22\x2b\x12\x2c\x12\x2c\x09\x0f\x22\x28\x09\x0c\x09\x14\x15\x19\x15\x1e\x09\x1f\x09\x19\x1a\x2e\x30\x34\x30\x39\x3b\x3f\x3b\x46\x09\x47\x09\x47\x1e\x23\x09\x0d\x09\x1b\x0c\x12\x05\x12\x00\x00\x1e\x23\x09\x0d\x09\x1b\x09\x23\x09\x23\x09\x23\x09\x23",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_35_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\xa5\x06\x41\x33\x00\xac\x15\x41\x02\x00\xc1\x01\x01\x41\x33\x00\xc1\x02\x02\x41\x15\x03\xc1\x05\x05\x41\x0b\x02\xc1\x0a\x01\x41\x15\x03\xc1\x0b\x04\x41\x12\x05\xc1\x0f\x02\x41\x15\x03\xc1\x11\x01\x41\x12\x05\xc1\x12\x03\x41\x15\x03\xc1\x15\x19\x41\x33\x00\xc1\x33\x05\x41\x38\x03",
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
    .co_firstlineno = 666,
    .co_code = & toplevel_consts_35_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_35_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_35_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_35_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_35_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_35_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_35_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_36_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x35\x00\x01\x00\x74\x02\x7c\x00\xa9\x01\x02\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x53\x00\x23\x00\x31\x00\x73\x18\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[192];
    }
toplevel_consts_36_consts_0 = {
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
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x61\x20\x6e\x65\x77\x20\x6d\x6f\x64\x75\x6c\x65\x20\x6f\x62\x6a\x65\x63\x74\x2c\x20\x6c\x6f\x61\x64\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x73\x70\x65\x63\x27\x73\x20\x6c\x6f\x61\x64\x65\x72\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x6e\x6f\x74\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x20\x69\x74\x73\x20\x70\x61\x72\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x73\x20\x61\x6c\x72\x65\x61\x64\x79\x20\x69\x6e\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x2c\x20\x74\x68\x61\x74\x20\x65\x78\x69\x73\x74\x69\x6e\x67\x20\x6d\x6f\x64\x75\x6c\x65\x20\x67\x65\x74\x73\x0a\x20\x20\x20\x20\x63\x6c\x6f\x62\x62\x65\x72\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_36_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_36_consts_0._ascii.ob_base,
            Py_None,
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
toplevel_consts_36_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
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
toplevel_consts_36_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_36_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x09\x06\x01\x16\xff\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_36_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x09\x20\x01\x06\x80\x0c\x00",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_36_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0a\x1c\x1d\x21\x1d\x26\x0a\x27\x05\x24\x05\x24\x10\x1e\x1f\x23\x10\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x00\x00\x00\x00\x00\x00\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24\x05\x24",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_36_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x86\x04\x11\x03\x91\x04\x15\x07\x98\x01\x15\x07",
};
static struct PyCodeObject toplevel_consts_36 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_36_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_36_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_36_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_36_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 711,
    .co_code = & toplevel_consts_36_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_21_names_7._ascii.ob_base,
    .co_qualname = & toplevel_consts_21_names_7._ascii.ob_base,
    .co_linetable = & toplevel_consts_36_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_36_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_36_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[127];
    }
toplevel_consts_37_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 126,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x07\x64\x0c\x64\x05\x84\x01\xa9\x01\x5a\x08\x65\x07\x64\x0d\x64\x06\x84\x01\xa9\x01\x5a\x09\x65\x05\x64\x07\x84\x00\xa9\x01\x5a\x0a\x65\x05\x64\x08\x84\x00\xa9\x01\x5a\x0b\x65\x07\x65\x0c\x64\x09\x84\x00\xa9\x01\xa9\x01\x5a\x0d\x65\x07\x65\x0c\x64\x0a\x84\x00\xa9\x01\xa9\x01\x5a\x0e\x65\x07\x65\x0c\x64\x0b\x84\x00\xa9\x01\xa9\x01\x5a\x0f\x65\x07\x65\x10\xa9\x01\x5a\x11\x64\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_37_consts_0 = {
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
    ._data = "BuiltinImporter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[145];
    }
toplevel_consts_37_consts_1 = {
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
    ._data = "\x4d\x65\x74\x61\x20\x70\x61\x74\x68\x20\x69\x6d\x70\x6f\x72\x74\x20\x66\x6f\x72\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x41\x6c\x6c\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x61\x72\x65\x20\x65\x69\x74\x68\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x73\x74\x61\x74\x69\x63\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x74\x6f\x20\x61\x76\x6f\x69\x64\x20\x74\x68\x65\x20\x6e\x65\x65\x64\x20\x74\x6f\x0a\x20\x20\x20\x20\x69\x6e\x73\x74\x61\x6e\x74\x69\x61\x74\x65\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_37_consts_2 = {
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
    ._data = "built-in",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_37_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x64\x01\x74\x02\xa8\x02\xa9\x02\x01\x00\x64\x02\x7c\x00\x6a\x03\x9b\x02\x64\x03\x74\x04\x6a\x05\x9b\x00\x64\x04\x9d\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[116];
    }
toplevel_consts_37_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 115,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x74\x75\x72\x6e\x20\x72\x65\x70\x72\x20\x66\x6f\x72\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x20\x20\x54\x68\x65\x20\x69\x6d\x70\x6f\x72\x74\x20\x6d\x61\x63\x68\x69\x6e\x65\x72\x79\x20\x64\x6f\x65\x73\x20\x74\x68\x65\x20\x6a\x6f\x62\x20\x69\x74\x73\x65\x6c\x66\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[82];
    }
toplevel_consts_37_consts_3_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 81,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "BuiltinImporter.module_repr() is deprecated and slated for removal in Python 3.12",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_37_consts_3_consts_2 = {
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
    ._data = "<module ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_37_consts_3_consts_3 = {
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
    ._data = " (",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[3];
    }
toplevel_consts_37_consts_3_consts_4 = {
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
    ._data = ")>",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_37_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_37_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_37_consts_3_consts_1._ascii.ob_base,
            & toplevel_consts_37_consts_3_consts_2._ascii.ob_base,
            & toplevel_consts_37_consts_3_consts_3._ascii.ob_base,
            & toplevel_consts_37_consts_3_consts_4._ascii.ob_base,
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
toplevel_consts_37_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
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
toplevel_consts_37_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_37_consts_3_qualname = {
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
    ._data = "BuiltinImporter.module_repr",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_37_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x07\x02\x01\x06\xff\x16\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_37_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x0c\x01\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_37_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x12\x09\x50\x18\x3b\x3d\x4f\x09\x50\x09\x50\x09\x50\x10\x4b\x1b\x21\x1b\x2a\x10\x4b\x10\x4b\x30\x3f\x30\x47\x10\x4b\x10\x4b\x10\x4b\x09\x4b",
};
static struct PyCodeObject toplevel_consts_37_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 737,
    .co_code = & toplevel_consts_37_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_37_consts_5_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x02\x81\x05\x64\x00\x53\x00\x74\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x72\x13\x74\x02\x7c\x01\x7c\x00\x7c\x00\x6a\x03\x64\x01\xaa\x03\x53\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_5_consts = {
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
            & toplevel_consts_27_consts_2._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_37_consts_5_names_1 = {
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
    ._data = "is_builtin",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_37_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_names_1._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_37_consts_5_varnames_0 = {
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
toplevel_consts_37_consts_5_varnames_2 = {
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
toplevel_consts_37_consts_5_varnames_3 = {
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
    ._data = "target",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_37_consts_5_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_37_consts_5_name = {
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
        uint8_t _data[26];
    }
toplevel_consts_37_consts_5_qualname = {
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
    ._data = "BuiltinImporter.find_spec",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_consts_5_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x02\x04\x01\x0c\x01\x10\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_37_consts_5_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x06\x01\x0a\x01\x02\x03\x10\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_37_consts_5_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x09\x18\x14\x18\x14\x18\x0c\x10\x0c\x25\x1c\x24\x0c\x25\x0c\x25\x09\x18\x14\x24\x25\x2d\x2f\x32\x3b\x3e\x3b\x46\x14\x47\x14\x47\x0d\x47\x14\x18\x14\x18",
};
static struct PyCodeObject toplevel_consts_37_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_5_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 748,
    .co_code = & toplevel_consts_37_consts_5_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_5_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_5_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_5_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_5_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_5_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_37_consts_6_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x64\x01\x74\x02\xa8\x02\xa9\x02\x01\x00\x7c\x00\xa0\x03\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x7d\x03\x7c\x03\x81\x14\x7c\x03\x6a\x04\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[176];
    }
toplevel_consts_37_consts_6_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 175,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x46\x69\x6e\x64\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x49\x66\x20\x27\x70\x61\x74\x68\x27\x20\x69\x73\x20\x65\x76\x65\x72\x20\x73\x70\x65\x63\x69\x66\x69\x65\x64\x20\x74\x68\x65\x6e\x20\x74\x68\x65\x20\x73\x65\x61\x72\x63\x68\x20\x69\x73\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x61\x20\x66\x61\x69\x6c\x75\x72\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x20\x20\x55\x73\x65\x20\x66\x69\x6e\x64\x5f\x73\x70\x65\x63\x28\x29\x20\x69\x6e\x73\x74\x65\x61\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[107];
    }
toplevel_consts_37_consts_6_consts_1 = {
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
    ._data = "BuiltinImporter.find_module() is deprecated and slated for removal in Python 3.12; use find_spec() instead",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_37_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_37_consts_6_consts_0._ascii.ob_base,
            & toplevel_consts_37_consts_6_consts_1._ascii.ob_base,
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
toplevel_consts_37_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
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
toplevel_consts_37_consts_6_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_37_consts_6_name = {
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
    ._data = "find_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_37_consts_6_qualname = {
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
    ._data = "BuiltinImporter.find_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x09\x02\x02\x06\xfe\x0e\x03\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_37_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x09\x02\x02\x02\xff\x08\x01\x0e\x01\x0e\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_37_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x12\x09\x2b\x18\x54\x18\x2a\x09\x2b\x09\x2b\x09\x2b\x10\x13\x10\x2d\x1e\x26\x28\x2c\x10\x2d\x10\x2d\x09\x0d\x1f\x23\x10\x39\x10\x14\x10\x1b\x09\x39\x35\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_37_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 757,
    .co_code = & toplevel_consts_37_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_6_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_6_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_37_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x74\x01\x6a\x02\x76\x01\x72\x13\x74\x03\x64\x01\xa0\x04\x7c\x00\x6a\x00\xa8\x01\xa9\x01\x7c\x00\x6a\x00\x64\x02\xaa\x02\x82\x01\x74\x05\x74\x06\x6a\x07\x7c\x00\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_37_consts_7_consts_0 = {
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
    ._data = "Create a built-in module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_37_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_37_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_consts_1._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_37_consts_7_names_7 = {
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
    ._data = "create_builtin",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_37_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_37_consts_7_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_37_consts_7_qualname = {
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
    ._data = "BuiltinImporter.create_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x03\x0e\x01\x04\x01\x06\xff\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_37_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x02\x02\x0e\xff\x0a\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_37_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x0c\x15\x1d\x20\x1d\x35\x0c\x35\x09\x2e\x13\x1e\x1f\x3e\x1f\x50\x46\x4a\x46\x4f\x1f\x50\x1f\x50\x24\x28\x24\x2d\x13\x2e\x13\x2e\x0d\x2e\x10\x29\x2a\x2e\x2a\x3d\x3f\x43\x10\x44\x09\x44",
};
static struct PyCodeObject toplevel_consts_37_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 772,
    .co_code = & toplevel_consts_37_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_consts_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_36_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_37_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x74\x01\x6a\x02\x7c\x00\xa9\x02\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_37_consts_8_consts_0 = {
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
    ._data = "Exec a built-in module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_37_consts_8_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_37_consts_8_names_2 = {
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
    ._data = "exec_builtin",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_37_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_37_consts_8_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_37_consts_8_qualname = {
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
    ._data = "BuiltinImporter.exec_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_37_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_37_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x22\x23\x27\x23\x34\x36\x3c\x09\x3d\x09\x3d\x09\x3d\x09\x3d",
};
static struct PyCodeObject toplevel_consts_37_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 780,
    .co_code = & toplevel_consts_37_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_consts_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_37_consts_9_code = {
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
        uint8_t _data[58];
    }
toplevel_consts_37_consts_9_consts_0 = {
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
    ._data = "Return None as built-in modules do not have code objects.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_37_consts_9_consts_0._ascii.ob_base,
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
toplevel_consts_37_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_37_consts_9_name = {
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
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_37_consts_9_qualname = {
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
    ._data = "BuiltinImporter.get_code",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_37_consts_9_linetable = {
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
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_37_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x14",
};
static struct PyCodeObject toplevel_consts_37_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 785,
    .co_code = & toplevel_consts_37_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[57];
    }
toplevel_consts_37_consts_10_consts_0 = {
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
    ._data = "Return None as built-in modules do not have source code.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_37_consts_10_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_37_consts_10_name = {
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
    ._data = "get_source",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_37_consts_10_qualname = {
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
    ._data = "BuiltinImporter.get_source",
};
static struct PyCodeObject toplevel_consts_37_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 791,
    .co_code = & toplevel_consts_37_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[53];
    }
toplevel_consts_37_consts_11_consts_0 = {
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
    ._data = "Return False as built-in modules are never packages.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_11_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_37_consts_11_consts_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_37_consts_11_qualname = {
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
    ._data = "BuiltinImporter.is_package",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_37_consts_11_columntable = {
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
static struct PyCodeObject toplevel_consts_37_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts_11_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 797,
    .co_code = & toplevel_consts_37_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_3_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_37_consts_12 = {
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
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_37_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_37_consts_1._ascii.ob_base,
            & toplevel_consts_37_consts_2._ascii.ob_base,
            & toplevel_consts_37_consts_3.ob_base,
            Py_None,
            & toplevel_consts_37_consts_5.ob_base,
            & toplevel_consts_37_consts_6.ob_base,
            & toplevel_consts_37_consts_7.ob_base,
            & toplevel_consts_37_consts_8.ob_base,
            & toplevel_consts_37_consts_9.ob_base,
            & toplevel_consts_37_consts_10.ob_base,
            & toplevel_consts_37_consts_11.ob_base,
            & toplevel_consts_37_consts_12._object.ob_base.ob_base,
            & toplevel_consts_1_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_37_names_5 = {
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
toplevel_consts_37_names_7 = {
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
            PyObject *ob_item[18];
        }_object;
    }
toplevel_consts_37_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 18,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
            & toplevel_consts_37_names_5._ascii.ob_base,
            & toplevel_consts_22_consts_4._ascii.ob_base,
            & toplevel_consts_37_names_7._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_37_consts_6_name._ascii.ob_base,
            & toplevel_consts_31_consts_2._ascii.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_37_consts_9_name._ascii.ob_base,
            & toplevel_consts_37_consts_10_name._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_33_names_15._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[85];
    }
toplevel_consts_37_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 84,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x07\x02\x02\x04\x01\x02\xff\x02\x01\x02\x0a\x06\x01\x02\xff\x02\x01\x02\x08\x06\x01\x02\xff\x02\x01\x02\x0e\x04\x01\x02\xff\x02\x01\x02\x07\x04\x01\x02\xff\x02\x01\x02\x04\x02\x01\x04\x01\x02\xff\x02\xff\x02\x02\x02\x04\x02\x01\x04\x01\x02\xff\x02\xff\x02\x02\x02\x04\x02\x01\x04\x01\x02\xff\x02\xff\x02\x02\x0c\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[89];
    }
toplevel_consts_37_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 88,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x07\x04\x02\x02\x02\x04\x09\x02\xf7\x02\x09\x02\x02\x02\x01\x04\x06\x02\xf9\x02\x07\x02\x02\x02\x01\x04\x0c\x02\xf3\x02\x0d\x02\x02\x04\x06\x02\xfa\x02\x06\x02\x02\x04\x03\x02\xfd\x02\x03\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x02\x04\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x02\x04\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x02\x04\x0c\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[127];
    }
toplevel_consts_37_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 126,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x0f\x19\x05\x0c\x06\x12\x05\x4b\x05\x4b\x06\x12\x05\x4b\x06\x11\x27\x2b\x05\x18\x05\x18\x06\x11\x05\x18\x06\x11\x29\x2d\x05\x39\x05\x39\x06\x11\x05\x39\x06\x12\x05\x44\x05\x44\x06\x12\x05\x44\x06\x12\x05\x3d\x05\x3d\x06\x12\x05\x3d\x06\x11\x06\x17\x05\x14\x05\x14\x06\x17\x06\x11\x05\x14\x06\x11\x06\x17\x05\x14\x05\x14\x06\x17\x06\x11\x05\x14\x06\x11\x06\x17\x05\x15\x05\x15\x06\x17\x06\x11\x05\x15\x13\x1e\x1f\x30\x13\x31\x05\x10\x05\x10\x05\x10",
};
static struct PyCodeObject toplevel_consts_37 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_37_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_37_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 726,
    .co_code = & toplevel_consts_37_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_37_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_39_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x65\x05\x64\x03\x84\x00\xa9\x01\x5a\x06\x65\x07\x64\x04\x84\x00\xa9\x01\x5a\x08\x65\x07\x64\x10\x64\x07\x84\x01\xa9\x01\x5a\x09\x65\x07\x64\x11\x64\x08\x84\x01\xa9\x01\x5a\x0a\x65\x07\x64\x12\x64\x09\x84\x01\xa9\x01\x5a\x0b\x65\x05\x64\x0a\x84\x00\xa9\x01\x5a\x0c\x65\x05\x64\x0b\x84\x00\xa9\x01\x5a\x0d\x65\x07\x64\x0c\x84\x00\xa9\x01\x5a\x0e\x65\x07\x65\x0f\x64\x0d\x84\x00\xa9\x01\xa9\x01\x5a\x10\x65\x07\x65\x0f\x64\x0e\x84\x00\xa9\x01\xa9\x01\x5a\x11\x65\x07\x65\x0f\x64\x0f\x84\x00\xa9\x01\xa9\x01\x5a\x12\x64\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_39_consts_0 = {
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
    ._data = "FrozenImporter",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[143];
    }
toplevel_consts_39_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 142,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4d\x65\x74\x61\x20\x70\x61\x74\x68\x20\x69\x6d\x70\x6f\x72\x74\x20\x66\x6f\x72\x20\x66\x72\x6f\x7a\x65\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x41\x6c\x6c\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x61\x72\x65\x20\x65\x69\x74\x68\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x6f\x72\x20\x73\x74\x61\x74\x69\x63\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x74\x6f\x20\x61\x76\x6f\x69\x64\x20\x74\x68\x65\x20\x6e\x65\x65\x64\x20\x74\x6f\x0a\x20\x20\x20\x20\x69\x6e\x73\x74\x61\x6e\x74\x69\x61\x74\x65\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_39_consts_2 = {
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
    ._data = "frozen",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_39_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x64\x01\x74\x02\xa8\x02\xa9\x02\x01\x00\x64\x02\xa0\x03\x7c\x00\x6a\x04\x74\x05\x6a\x06\xa8\x02\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[81];
    }
toplevel_consts_39_consts_3_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 80,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "FrozenImporter.module_repr() is deprecated and slated for removal in Python 3.12",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_39_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_37_consts_3_consts_0._ascii.ob_base,
            & toplevel_consts_39_consts_3_consts_1._ascii.ob_base,
            & toplevel_consts_32_consts_6._ascii.ob_base,
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
toplevel_consts_39_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_39_consts_0._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_39_consts_3_varnames_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_39_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_39_consts_3_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_39_consts_3_qualname = {
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
    ._data = "FrozenImporter.module_repr",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x07\x02\x01\x06\xff\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_39_consts_3_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x0c\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_39_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x12\x09\x50\x18\x3b\x3d\x4f\x09\x50\x09\x50\x09\x50\x10\x24\x10\x4f\x2c\x2d\x2c\x36\x38\x46\x38\x4e\x10\x4f\x10\x4f\x09\x4f",
};
static struct PyCodeObject toplevel_consts_39_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 817,
    .co_code = & toplevel_consts_39_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_22_consts_4._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_3_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[643];
    }
toplevel_consts_39_consts_4_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 642,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x6a\x00\x7d\x02\x7c\x02\x6a\x01\x7d\x03\x7c\x03\x80\x91\x74\x02\x7c\x01\xa9\x01\xa0\x03\x64\x01\x64\x00\xa8\x02\xa9\x02\x7d\x04\x7c\x04\x73\x18\x4a\x00\x64\x02\xa9\x01\x82\x01\x74\x04\x7c\x01\x64\x03\xa9\x02\x7d\x05\x74\x05\xa0\x06\x7c\x01\x6a\x07\xa8\x01\xa9\x01\x7c\x05\x6b\x02\x73\x2a\x4a\x00\x7c\x05\xa9\x01\x82\x01\x7c\x00\xa0\x08\x7c\x04\x7c\x02\x6a\x09\x7c\x05\xa8\x03\xa9\x03\x5c\x02\x7d\x06\x7d\x07\x74\x0a\x74\x0b\x6a\x0c\xa9\x01\x7c\x06\x7c\x04\x64\x04\xaa\x02\x7c\x02\x5f\x01\x7c\x02\x6a\x0d\x7d\x08\x7c\x05\x72\x57\x7c\x08\x67\x00\x6b\x02\x73\x4c\x4a\x00\x7c\x08\xa9\x01\x82\x01\x7c\x07\x72\x56\x7c\x02\x6a\x0d\xa0\x0e\x64\x05\x7c\x07\xa8\x02\xa9\x02\x01\x00\x6e\x06\x7c\x08\x81\x5d\x4a\x00\x7c\x08\xa9\x01\x82\x01\x74\x04\x7c\x01\x64\x06\xa9\x02\x72\x67\x4a\x00\x7c\x01\x6a\x0f\xa9\x01\x82\x01\x7c\x06\x72\x78\x09\x00\x7c\x06\x7c\x01\x5f\x0f\x6e\x0a\x23\x00\x74\x10\x79\x74\x01\x00\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x72\x90\x7c\x01\x6a\x11\x7c\x08\x6b\x03\x72\x90\x7c\x01\x6a\x11\x67\x00\x6b\x02\x73\x89\x4a\x00\x7c\x01\x6a\x11\xa9\x01\x82\x01\x7c\x01\x6a\x11\xa0\x12\x7c\x08\xa8\x01\xa9\x01\x01\x00\x6e\xa8\x7c\x02\x6a\x0d\x7d\x08\x7c\x08\x64\x00\x75\x01\x7d\x05\x74\x13\x74\x02\x7c\x03\xa9\x01\xa9\x01\x64\x07\x64\x08\x67\x02\x6b\x02\x73\xa6\x4a\x00\x7c\x03\xa9\x01\x82\x01\x7c\x03\x6a\x14\x72\xdc\x7c\x00\xa0\x08\x7c\x03\x6a\x14\x7c\x02\x6a\x09\x7c\x05\xa8\x03\xa9\x03\x5c\x02\x7d\x09\x7d\x07\x7c\x03\x6a\x15\x7c\x09\x6b\x02\x73\xc1\x4a\x00\x7c\x03\x6a\x15\x7c\x09\x66\x02\xa9\x01\x82\x01\x7c\x07\x72\xcf\x7c\x08\x7c\x07\x67\x01\x6b\x02\x73\xce\x4a\x00\x7c\x08\x7c\x07\x66\x02\xa9\x01\x82\x01\x6e\x23\x7c\x08\x7c\x05\x72\xd4\x67\x00\x6e\x01\x64\x00\x6b\x02\x73\xdb\x4a\x00\x7c\x08\xa9\x01\x82\x01\x6e\x16\x64\x00\x7d\x09\x7c\x03\x6a\x15\x81\xe6\x4a\x00\x7c\x03\x6a\x15\xa9\x01\x82\x01\x7c\x08\x7c\x05\x72\xeb\x67\x00\x6e\x01\x64\x00\x6b\x02\x73\xf2\x4a\x00\x7c\x08\xa9\x01\x82\x01\x7c\x09\x90\x01\x72\x0a\x74\x04\x7c\x01\x64\x06\xa9\x02\x73\xfc\x4a\x00\x82\x01\x7c\x01\x6a\x0f\x7c\x09\x6b\x02\x90\x01\x73\x09\x4a\x00\x7c\x01\x6a\x0f\x7c\x09\x66\x02\xa9\x01\x82\x01\x6e\x0b\x74\x04\x7c\x01\x64\x06\xa9\x02\x90\x01\x72\x15\x4a\x00\x7c\x01\x6a\x0f\xa9\x01\x82\x01\x7c\x05\x90\x01\x72\x2e\x74\x04\x7c\x01\x64\x03\xa9\x02\x90\x01\x73\x20\x4a\x00\x82\x01\x7c\x01\x6a\x11\x7c\x08\x6b\x02\x90\x01\x73\x2d\x4a\x00\x7c\x01\x6a\x11\x7c\x08\x66\x02\xa9\x01\x82\x01\x6e\x0b\x74\x04\x7c\x01\x64\x03\xa9\x02\x90\x01\x72\x39\x4a\x00\x7c\x01\x6a\x11\xa9\x01\x82\x01\x7c\x02\x6a\x16\x90\x01\x72\x3f\x4a\x00\x82\x01\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_39_consts_4_consts_1 = {
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
    ._data = "__origname__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_39_consts_4_consts_2 = {
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
    ._data = "see PyImport_ImportFrozenModuleObject()",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_39_consts_4_consts_4_1 = {
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
    ._data = "origname",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_39_consts_4_consts_4 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
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
toplevel_consts_39_consts_4_consts = {
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
            & toplevel_consts_39_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_2._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4._object.ob_base.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39_consts_4_names_2 = {
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
    ._data = "vars",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_39_consts_4_names_6 = {
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
    ._data = "is_frozen_package",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_39_consts_4_names_8 = {
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
    ._data = "_resolve_filename",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_39_consts_4_names_12 = {
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
    ._data = "implementation",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_39_consts_4_names_14 = {
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
toplevel_consts_39_consts_4_names_18 = {
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
        uint8_t _data[7];
    }
toplevel_consts_39_consts_4_names_19 = {
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
    ._data = "sorted",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[23];
        }_object;
    }
toplevel_consts_39_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 23,
        },
        .ob_item = {
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_6._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_12._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_14._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_18._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_19._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_23_consts_6_names_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_39_consts_4_varnames_3 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_39_consts_4_varnames_5 = {
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
    ._data = "ispkg",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_39_consts_4_varnames_7 = {
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
    ._data = "pkgdir",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_39_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_3._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_5._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_7._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_39_consts_4_name = {
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
    ._data = "_fix_up_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_39_consts_4_qualname = {
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
    ._data = "FrozenImporter._fix_up_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_consts_39_consts_4_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x06\x01\x04\x01\x12\x04\x0c\x01\x0a\x01\x1a\x01\x16\x01\x08\x01\x02\x01\x02\x01\x08\xfe\x06\x04\x04\x01\x10\x01\x04\x01\x10\x01\x02\x80\x0c\x02\x14\x03\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x04\x01\x02\xff\x06\x80\x04\x02\x0a\x01\x14\x01\x0e\x01\x02\x80\x06\x04\x08\x01\x1c\x02\x06\x01\x12\x03\x06\xff\x18\x02\x04\x01\x18\x01\x1a\x02\x04\x02\x10\x01\x18\x01\x06\x02\x0e\x01\x1c\x01\x16\x02\x06\x01\x10\x01\x1c\x01\x16\x02\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_consts_39_consts_4_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x06\x01\x02\x01\x02\x3e\x12\xc6\x0c\x01\x0a\x01\x1a\x01\x16\x01\x08\x01\x02\x01\x02\x01\x04\x01\x04\xfd\x06\x04\x02\x01\x02\x05\x10\xfc\x02\x01\x12\x01\x02\x80\x0c\x02\x14\x03\x02\x01\x04\x04\x08\xfe\x02\x80\x02\x01\x0a\x01\x06\x80\x02\x01\x02\x03\x08\xfe\x02\x02\x14\xff\x0e\x01\x02\x80\x06\x04\x08\x01\x1c\x02\x04\x01\x02\x0c\x14\xf7\x04\xff\x18\x02\x02\x01\x02\x03\x18\xfe\x1a\x02\x04\x02\x10\x01\x18\x01\x02\x02\x04\x04\x0e\xfd\x1c\x01\x16\x02\x02\x01\x04\x04\x10\xfd\x1c\x01\x16\x02\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[643];
    }
toplevel_consts_39_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 642,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x16\x10\x1f\x09\x0d\x11\x15\x11\x22\x09\x0e\x0c\x11\x09\x48\x18\x1c\x1d\x23\x18\x24\x18\x3e\x29\x37\x39\x3d\x18\x3e\x18\x3e\x0d\x15\x14\x1c\x0d\x47\x0d\x47\x1e\x47\x0d\x47\x0d\x47\x15\x1c\x1d\x23\x25\x2f\x15\x30\x0d\x12\x14\x18\x14\x3b\x2b\x31\x2b\x3a\x14\x3b\x14\x3b\x3f\x44\x14\x44\x0d\x4b\x0d\x4b\x46\x4b\x0d\x4b\x0d\x4b\x20\x23\x20\x51\x36\x3e\x40\x44\x40\x49\x4b\x50\x20\x51\x20\x51\x0d\x1d\x0d\x15\x17\x1d\x21\x25\x26\x29\x26\x38\x21\x39\x1a\x22\x1a\x22\x21\x0e\x21\x0e\x0d\x11\x0d\x1e\x18\x1c\x18\x37\x0d\x15\x10\x15\x0d\x32\x18\x20\x24\x26\x18\x26\x11\x30\x11\x30\x28\x30\x11\x30\x11\x30\x14\x1a\x11\x46\x15\x19\x15\x34\x15\x46\x3c\x3d\x3f\x45\x15\x46\x15\x46\x15\x46\x00\x00\x18\x20\x11\x32\x11\x32\x2a\x32\x11\x32\x11\x32\x18\x1f\x20\x26\x28\x32\x18\x33\x0d\x44\x0d\x44\x35\x3b\x35\x44\x0d\x44\x0d\x44\x10\x18\x0d\x19\x11\x19\x27\x2f\x15\x1b\x15\x24\x15\x24\x00\x00\x18\x26\x11\x19\x11\x19\x15\x19\x15\x19\x11\x19\x00\x00\x00\x00\x00\x00\x10\x15\x0d\x35\x14\x1a\x14\x23\x27\x2f\x14\x2f\x11\x35\x1c\x22\x1c\x2b\x2f\x31\x1c\x31\x15\x42\x15\x42\x33\x39\x33\x42\x15\x42\x15\x42\x15\x1b\x15\x24\x15\x35\x2c\x34\x15\x35\x15\x35\x15\x35\x00\x00\x18\x1c\x18\x37\x0d\x15\x15\x1d\x25\x29\x15\x29\x0d\x12\x14\x1a\x1b\x1f\x20\x25\x1b\x26\x14\x27\x2c\x36\x38\x42\x2b\x43\x14\x43\x0d\x4a\x0d\x4a\x45\x4a\x0d\x4a\x0d\x4a\x10\x15\x10\x1e\x0d\x45\x16\x19\x16\x4d\x2c\x31\x2c\x3a\x3c\x40\x3c\x45\x47\x4c\x16\x4d\x16\x4d\x11\x13\x12\x1a\x1c\x22\x18\x1d\x18\x26\x2a\x32\x18\x32\x11\x4e\x11\x4e\x35\x3a\x35\x43\x45\x4d\x34\x4e\x11\x4e\x11\x4e\x14\x1a\x11\x49\x1c\x24\x29\x2f\x28\x30\x1c\x30\x15\x44\x15\x44\x33\x3b\x3d\x43\x32\x44\x15\x44\x15\x44\x15\x44\x1c\x24\x2f\x34\x29\x3e\x29\x2b\x29\x2b\x3a\x3e\x1c\x3f\x15\x49\x15\x49\x41\x49\x15\x49\x15\x49\x15\x49\x1c\x20\x11\x19\x18\x1d\x18\x26\x11\x3e\x11\x3e\x30\x35\x30\x3e\x11\x3e\x11\x3e\x18\x20\x2b\x30\x25\x3a\x25\x27\x25\x27\x36\x3a\x18\x3b\x11\x45\x11\x45\x3d\x45\x11\x45\x11\x45\x10\x18\x0d\x48\x0d\x48\x18\x1f\x20\x26\x28\x32\x18\x33\x11\x33\x11\x33\x11\x33\x18\x1e\x18\x27\x2b\x33\x18\x33\x11\x50\x11\x50\x11\x50\x36\x3c\x36\x45\x47\x4f\x35\x50\x11\x50\x11\x50\x11\x50\x1c\x23\x24\x2a\x2c\x36\x1c\x37\x11\x48\x11\x48\x11\x48\x39\x3f\x39\x48\x11\x48\x11\x48\x10\x15\x0d\x48\x0d\x48\x18\x1f\x20\x26\x28\x32\x18\x33\x11\x33\x11\x33\x11\x33\x11\x33\x18\x1e\x18\x27\x2b\x33\x18\x33\x11\x50\x11\x50\x11\x50\x36\x3c\x36\x45\x47\x4f\x35\x50\x11\x50\x11\x50\x11\x50\x1c\x23\x24\x2a\x2c\x36\x1c\x37\x11\x48\x11\x48\x11\x48\x39\x3f\x39\x48\x11\x48\x11\x48\x14\x18\x14\x25\x09\x25\x09\x25\x09\x25\x09\x25\x09\x25\x09\x25",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_39_consts_4_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x2a\x03\x41\x2e\x00\xc1\x2e\x04\x41\x35\x03\xc1\x34\x01\x41\x35\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_consts_4_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_39_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_4_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_39_consts_4_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 828,
    .co_code = & toplevel_consts_39_consts_4_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_39_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_4_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[219];
    }
toplevel_consts_39_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 218,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x72\x09\x74\x00\x74\x01\x64\x01\x64\x00\xa9\x03\x73\x0b\x64\x02\x53\x00\x09\x00\x7c\x00\x6a\x02\x7d\x04\x6e\x16\x23\x00\x74\x03\x79\x22\x01\x00\x74\x01\x6a\x04\x64\x03\x6b\x02\x72\x1b\x64\x04\x6e\x01\x64\x05\x04\x00\x7d\x04\x7c\x00\x5f\x02\x59\x00\x6e\x04\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x01\x7c\x02\x6b\x03\x72\x40\x7c\x01\xa0\x05\x64\x06\xa8\x01\xa9\x01\x72\x3e\x7c\x01\x64\x07\x64\x00\x85\x02\x19\x00\x7d\x01\x7c\x03\x73\x3d\x7c\x01\x9b\x00\x64\x08\x9d\x02\x7d\x01\x6e\x02\x64\x09\x7d\x03\x7c\x01\xa0\x06\x64\x0a\x7c\x04\xa8\x02\xa9\x02\x7d\x05\x7c\x03\x72\x5d\x74\x01\x6a\x07\x9b\x00\x7c\x04\x9b\x00\x7c\x05\x9b\x00\x9d\x03\x7d\x06\x7c\x06\x9b\x00\x7c\x04\x9b\x00\x64\x0b\x9d\x03\x7d\x07\x7c\x07\x7c\x06\x66\x02\x53\x00\x64\x00\x7d\x06\x74\x01\x6a\x07\x9b\x00\x7c\x04\x9b\x00\x7c\x05\x9b\x00\x64\x0c\x9d\x04\x7d\x07\x7c\x07\x7c\x06\x66\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_39_consts_7_consts_1 = {
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
    ._data = "_stdlib_dir",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_39_consts_7_consts_3 = {
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
    ._data = "win32",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_39_consts_7_consts_4 = {
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
toplevel_consts_39_consts_7_consts_5 = {
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
toplevel_consts_39_consts_7_consts_6 = {
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
    ._data = "<",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_39_consts_7_consts_8 = {
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
    ._data = ".__init__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_39_consts_7_consts_11 = {
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
    ._data = "__init__.py",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_39_consts_7_consts_12 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[13];
        }_object;
    }
toplevel_consts_39_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 13,
        },
        .ob_item = {
            Py_None,
            & toplevel_consts_39_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_37_consts_12._object.ob_base.ob_base,
            & toplevel_consts_39_consts_7_consts_3._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_4._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_5._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_6._ascii.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
            & toplevel_consts_39_consts_7_consts_8._ascii.ob_base,
            Py_False,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_11._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_12._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39_consts_7_names_2 = {
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
    ._data = "_SEP",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_39_consts_7_names_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_39_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_39_consts_7_names_2._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_39_consts_7_names_4._ascii.ob_base,
            & toplevel_consts_18_names_3._ascii.ob_base,
            & toplevel_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_39_consts_7_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_39_consts_7_varnames_2 = {
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
    ._data = "alias",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_39_consts_7_varnames_4 = {
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
toplevel_consts_39_consts_7_varnames_5 = {
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
    ._data = "relfile",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_39_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_39_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_7_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_7_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_7._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_39_consts_7_qualname = {
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
    ._data = "FrozenImporter._resolve_filename",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_39_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x02\x04\x01\x02\x01\x08\x01\x02\x80\x06\x01\x1c\x01\x02\xff\x06\x80\x08\x03\x0c\x01\x0c\x01\x04\x01\x0a\x01\x02\x80\x04\x02\x0e\x01\x04\x01\x12\x01\x0e\x01\x08\x04\x04\xfe\x14\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[59];
    }
toplevel_consts_39_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 58,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x02\x02\x01\x0a\xff\x06\x01\x02\x04\x08\xfe\x02\x80\x02\x01\x22\x01\x06\x80\x06\x02\x02\x06\x0a\xfb\x02\x05\x0c\xfc\x02\x01\x0c\x01\x02\x80\x04\x02\x0e\x01\x02\x01\x02\x05\x12\xfc\x0e\x01\x08\x04\x04\xfe\x14\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[219];
    }
toplevel_consts_39_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 218,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x18\x09\x1e\x20\x27\x28\x2b\x2d\x3a\x3c\x40\x20\x41\x09\x1e\x14\x1e\x14\x1e\x09\x46\x13\x16\x13\x1b\x0d\x10\x0d\x10\x00\x00\x10\x1e\x09\x46\x09\x46\x26\x29\x26\x32\x36\x3d\x26\x3d\x1e\x46\x1e\x22\x1e\x22\x43\x46\x0d\x46\x0d\x10\x13\x16\x13\x1b\x13\x1b\x13\x1b\x09\x46\x00\x00\x00\x00\x00\x00\x0c\x14\x18\x1d\x0c\x1d\x09\x1e\x10\x18\x10\x28\x24\x27\x10\x28\x10\x28\x0d\x1e\x1c\x24\x25\x26\x25\x27\x25\x27\x1c\x28\x11\x19\x18\x1d\x11\x36\x23\x2b\x20\x36\x20\x36\x20\x36\x15\x1d\x00\x00\x19\x1e\x11\x16\x13\x1b\x13\x2d\x24\x27\x29\x2c\x13\x2d\x13\x2d\x09\x10\x0c\x11\x09\x3d\x19\x1c\x19\x28\x16\x38\x2a\x2d\x16\x38\x2f\x36\x16\x38\x16\x38\x0d\x13\x1b\x21\x18\x33\x23\x26\x18\x33\x18\x33\x18\x33\x0d\x15\x10\x18\x1a\x20\x10\x20\x09\x20\x16\x1a\x0d\x13\x1b\x1e\x1b\x2a\x18\x3d\x2c\x2f\x18\x3d\x31\x38\x18\x3d\x18\x3d\x18\x3d\x0d\x15\x10\x18\x1a\x20\x10\x20\x09\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_39_consts_7_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x8c\x03\x10\x00\x90\x10\x23\x03\xa2\x01\x23\x03",
};
static struct PyCodeObject toplevel_consts_39_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_39_consts_7_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 897,
    .co_code = & toplevel_consts_39_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_27_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_39_consts_4_names_8._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_39_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x74\x01\x6a\x02\x7c\x01\xa9\x02\x7d\x04\x7c\x04\x80\x0b\x64\x00\x53\x00\x7c\x04\x5c\x03\x7d\x05\x7d\x06\x7d\x07\x74\x03\x7c\x01\x7c\x00\x7c\x00\x6a\x04\x7c\x06\x64\x01\xaa\x04\x7d\x08\x7c\x00\xa0\x05\x7c\x07\x7c\x01\x7c\x06\xa8\x03\xa9\x03\x5c\x02\x7d\x09\x7d\x0a\x74\x06\x74\x07\x6a\x08\xa9\x01\x7c\x09\x7c\x07\x64\x02\xaa\x02\x7c\x08\x5f\x09\x7c\x0a\x72\x37\x7c\x08\x6a\x0a\xa0\x0b\x64\x03\x7c\x0a\xa8\x02\xa9\x02\x01\x00\x7c\x08\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_39_consts_8_consts = {
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
            & toplevel_consts_25._object.ob_base.ob_base,
            & toplevel_consts_39_consts_4_consts_4._object.ob_base.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_39_consts_8_names_2 = {
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
    ._data = "find_frozen",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_39_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_8_names_2._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_12._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39_consts_8_varnames_4 = {
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
        uint8_t _data[2];
    }
toplevel_consts_39_consts_8_varnames_5 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_39_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_3._ascii.ob_base,
            & toplevel_consts_39_consts_8_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_8_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_39_consts_8_qualname = {
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
    ._data = "FrozenImporter.find_spec",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_39_consts_8_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x04\x01\x04\x01\x0a\x0d\x06\x01\x04\x01\x02\x01\x06\xfe\x14\x03\x08\x01\x02\x01\x02\x01\x08\xfe\x04\x04\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_39_consts_8_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x02\x02\x01\x06\x01\x0a\x0d\x06\x01\x04\x01\x06\x01\x02\xfe\x14\x03\x08\x01\x02\x01\x02\x01\x04\x01\x04\xfd\x02\x04\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_39_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x29\x2a\x2e\x2a\x3a\x3c\x44\x10\x45\x09\x0d\x0c\x10\x09\x18\x14\x18\x14\x18\x1e\x22\x09\x1b\x09\x0a\x0c\x11\x13\x1b\x10\x20\x21\x29\x2b\x2e\x28\x2b\x28\x33\x2c\x31\x10\x32\x10\x32\x09\x0d\x1c\x1f\x1c\x4c\x32\x3a\x3c\x44\x46\x4b\x1c\x4c\x1c\x4c\x09\x19\x09\x11\x13\x19\x1d\x21\x22\x25\x22\x34\x1d\x35\x16\x1e\x16\x1e\x1d\x0a\x1d\x0a\x09\x0d\x09\x1a\x0c\x12\x09\x3e\x0d\x11\x0d\x2c\x0d\x3e\x34\x35\x37\x3d\x0d\x3e\x0d\x3e\x0d\x3e\x10\x14\x09\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[12];
    }
toplevel_consts_39_consts_8_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_39_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 922,
    .co_code = & toplevel_consts_39_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_8_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_8_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 11,
    .co_nlocals = 11,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_39_consts_9_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x64\x01\x74\x02\xa8\x02\xa9\x02\x01\x00\x74\x03\xa0\x04\x7c\x01\xa8\x01\xa9\x01\x72\x10\x7c\x00\x53\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[94];
    }
toplevel_consts_39_consts_9_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 93,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x46\x69\x6e\x64\x20\x61\x20\x66\x72\x6f\x7a\x65\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x20\x20\x55\x73\x65\x20\x66\x69\x6e\x64\x5f\x73\x70\x65\x63\x28\x29\x20\x69\x6e\x73\x74\x65\x61\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[106];
    }
toplevel_consts_39_consts_9_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 105,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "FrozenImporter.find_module() is deprecated and slated for removal in Python 3.12; use find_spec() instead",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_39_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_39_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_39_consts_9_consts_1._ascii.ob_base,
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
toplevel_consts_39_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_21_names_2._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_20_consts_1_names_1._ascii.ob_base,
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
toplevel_consts_39_consts_9_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_39_consts_9_qualname = {
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
    ._data = "FrozenImporter.find_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_consts_9_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x07\x02\x02\x06\xfe\x14\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_39_consts_9_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x07\x02\x02\x02\xff\x08\x01\x14\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_39_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x12\x09\x2b\x18\x54\x18\x2a\x09\x2b\x09\x2b\x09\x2b\x17\x1b\x17\x2f\x26\x2e\x17\x2f\x17\x2f\x10\x39\x10\x13\x09\x39\x35\x39\x09\x39",
};
static struct PyCodeObject toplevel_consts_39_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 952,
    .co_code = & toplevel_consts_39_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_6_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_9_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_39_consts_10_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x6a\x01\xa9\x01\x7d\x01\x09\x00\x7c\x00\x6a\x02\x6a\x03\x7d\x02\x6e\x0b\x23\x00\x74\x04\x79\x13\x01\x00\x59\x00\x7c\x01\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x02\x72\x1c\x7c\x02\x7c\x01\x5f\x05\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_39_consts_10_consts_0 = {
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
    ._data = "Set __file__, if able.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_39_consts_10_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_39_consts_10_consts_0._ascii.ob_base,
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
toplevel_consts_39_consts_10_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_23_consts_3_1._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_22_names_7._ascii.ob_base,
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
toplevel_consts_39_consts_10_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_22_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_39_consts_10_qualname = {
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
    ._data = "FrozenImporter.create_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_39_consts_10_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x02\x01\x0a\x01\x02\x80\x06\x01\x02\x01\x04\x04\x02\xfb\x06\x80\x04\x03\x06\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_39_consts_10_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x03\x02\x07\x0a\xfb\x02\x80\x02\x01\x06\x01\x04\x04\x02\xfc\x06\x80\x02\x02\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_39_consts_10_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x1d\x1e\x22\x1e\x27\x12\x28\x09\x0f\x09\x2b\x18\x1c\x18\x29\x18\x32\x0d\x15\x0d\x15\x00\x00\x10\x1e\x09\x11\x09\x11\x0d\x11\x10\x16\x09\x16\x09\x11\x00\x00\x00\x00\x00\x00\x10\x18\x0d\x2b\x23\x2b\x11\x17\x11\x20\x10\x16\x09\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_39_consts_10_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x04\x0c\x00\x8c\x04\x14\x03\x93\x01\x14\x03",
};
static struct PyCodeObject toplevel_consts_39_consts_10 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_10_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_10_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_10_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_39_consts_10_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 964,
    .co_code = & toplevel_consts_39_consts_10_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_10_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_consts_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_10_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_10_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_10_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_10_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_10_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_39_consts_11_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\x6a\x00\x7d\x01\x7c\x01\x6a\x01\x7d\x02\x74\x02\x74\x03\x6a\x04\x7c\x02\xa9\x02\x7d\x03\x74\x05\x7c\x03\x7c\x00\x6a\x06\xa9\x02\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_39_consts_11_names_4 = {
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
    ._data = "get_frozen_object",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39_consts_11_names_5 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_39_consts_11_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_11_names_4._ascii.ob_base,
            & toplevel_consts_39_consts_11_names_5._ascii.ob_base,
            & toplevel_consts_3_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_39_consts_11_varnames_3 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_39_consts_11_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_39_consts_11_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_39_consts_11_qualname = {
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
    ._data = "FrozenImporter.exec_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_39_consts_11_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x06\x01\x0c\x01\x10\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_39_consts_11_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x16\x10\x1f\x09\x0d\x10\x14\x10\x19\x09\x0d\x10\x29\x2a\x2e\x2a\x40\x42\x46\x10\x47\x09\x0d\x09\x0d\x0e\x12\x14\x1a\x14\x23\x09\x24\x09\x24\x09\x24\x09\x24",
};
static struct PyCodeObject toplevel_consts_39_consts_11 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_1_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_11_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_11_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 977,
    .co_code = & toplevel_consts_39_consts_11_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_11_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_31_consts_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_11_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_11_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_11_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_39_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\xa9\x02\x7d\x02\x74\x01\xa0\x02\x7c\x01\xa8\x01\xa9\x01\x7d\x03\x7c\x03\x80\x10\x4a\x00\x82\x01\x7c\x03\x5c\x03\x7d\x04\x7d\x05\x7d\x06\x7c\x06\x7c\x02\x5f\x03\x74\x04\x7c\x02\xa9\x01\xa0\x05\x64\x02\x64\x01\xa8\x02\xa9\x02\x01\x00\x7c\x05\x72\x26\x67\x00\x7c\x02\x5f\x06\x7c\x00\xa0\x07\x7c\x02\xa8\x01\xa9\x01\x01\x00\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[96];
    }
toplevel_consts_39_consts_12_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 95,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4c\x6f\x61\x64\x20\x61\x20\x66\x72\x6f\x7a\x65\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x54\x68\x69\x73\x20\x6d\x65\x74\x68\x6f\x64\x20\x69\x73\x20\x64\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2e\x20\x20\x55\x73\x65\x20\x65\x78\x65\x63\x5f\x6d\x6f\x64\x75\x6c\x65\x28\x29\x20\x69\x6e\x73\x74\x65\x61\x64\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_39_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_39_consts_12_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_22_names_7._ascii.ob_base,
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
toplevel_consts_39_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_8_names_2._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_1._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_2._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_39_consts_4_name._ascii.ob_base,
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
toplevel_consts_39_consts_12_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_37_consts_5_varnames_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_8_varnames_4._ascii.ob_base,
            & toplevel_consts_39_consts_8_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_4_varnames_5._ascii.ob_base,
            & toplevel_consts_39_consts_4_consts_4_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_39_consts_12_qualname = {
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
    ._data = "FrozenImporter.load_module",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_39_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x08\x0c\x01\x08\x01\x0a\x01\x06\x01\x12\x01\x04\x01\x06\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_39_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x08\x0c\x01\x08\x01\x0a\x01\x06\x01\x12\x01\x02\x01\x08\x01\x0c\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_39_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x12\x23\x24\x27\x29\x31\x12\x32\x09\x0f\x10\x14\x10\x2a\x21\x29\x10\x2a\x10\x2a\x09\x0d\x10\x14\x09\x20\x09\x20\x09\x20\x1e\x22\x09\x1b\x09\x0a\x0c\x11\x13\x1b\x1f\x27\x09\x0f\x09\x1c\x09\x0d\x0e\x14\x09\x15\x09\x2b\x1a\x24\x26\x2a\x09\x2b\x09\x2b\x09\x2b\x0c\x11\x09\x21\x1f\x21\x0d\x13\x0d\x1c\x09\x0c\x09\x23\x1c\x22\x09\x23\x09\x23\x09\x23\x10\x16\x09\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_39_consts_12_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_39_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 984,
    .co_code = & toplevel_consts_39_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_39_consts_12_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_12_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_33_names_15._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_12_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 7,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_39_consts_12_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_39_consts_13_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x01\xa8\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[46];
    }
toplevel_consts_39_consts_13_consts_0 = {
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
    ._data = "Return the code object for the frozen module.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_39_consts_13_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_39_consts_13_consts_0._ascii.ob_base,
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
toplevel_consts_39_consts_13_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_11_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_39_consts_13_qualname = {
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
    ._data = "FrozenImporter.get_code",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_39_consts_13_linetable = {
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
toplevel_consts_39_consts_13_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x10\x14\x10\x30\x27\x2f\x10\x30\x10\x30\x09\x30",
};
static struct PyCodeObject toplevel_consts_39_consts_13 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_13_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_13_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1003,
    .co_code = & toplevel_consts_39_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_13_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[55];
    }
toplevel_consts_39_consts_14_consts_0 = {
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
    ._data = "Return None as frozen modules do not have source code.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_39_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_39_consts_14_consts_0._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_39_consts_14_qualname = {
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
    ._data = "FrozenImporter.get_source",
};
static struct PyCodeObject toplevel_consts_39_consts_14 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_14_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_37_consts_9_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1009,
    .co_code = & toplevel_consts_37_consts_9_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_37_consts_10_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_14_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_37_consts_9_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_37_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_39_consts_15_consts_0 = {
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
    ._data = "Return True if the frozen module is a package.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_39_consts_15_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_39_consts_15_consts_0._ascii.ob_base,
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
toplevel_consts_39_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_39_consts_15_qualname = {
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
    ._data = "FrozenImporter.is_package",
};
static struct PyCodeObject toplevel_consts_39_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_consts_13_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1015,
    .co_code = & toplevel_consts_39_consts_13_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_23_consts_3_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_15_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_consts_13_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_consts_13_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_consts_13_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_37_consts_9_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_39_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_39_consts_0._ascii.ob_base,
            & toplevel_consts_39_consts_1._ascii.ob_base,
            & toplevel_consts_39_consts_2._ascii.ob_base,
            & toplevel_consts_39_consts_3.ob_base,
            & toplevel_consts_39_consts_4.ob_base,
            Py_None,
            Py_False,
            & toplevel_consts_39_consts_7.ob_base,
            & toplevel_consts_39_consts_8.ob_base,
            & toplevel_consts_39_consts_9.ob_base,
            & toplevel_consts_39_consts_10.ob_base,
            & toplevel_consts_39_consts_11.ob_base,
            & toplevel_consts_39_consts_12.ob_base,
            & toplevel_consts_39_consts_13.ob_base,
            & toplevel_consts_39_consts_14.ob_base,
            & toplevel_consts_39_consts_15.ob_base,
            & toplevel_consts_23_consts_4_consts._object.ob_base.ob_base,
            & toplevel_consts_37_consts_12._object.ob_base.ob_base,
            & toplevel_consts_1_consts._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_39_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_26_consts_2._ascii.ob_base,
            & toplevel_consts_37_names_5._ascii.ob_base,
            & toplevel_consts_22_consts_4._ascii.ob_base,
            & toplevel_consts_37_names_7._ascii.ob_base,
            & toplevel_consts_39_consts_4_name._ascii.ob_base,
            & toplevel_consts_39_consts_4_names_8._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_37_consts_6_name._ascii.ob_base,
            & toplevel_consts_31_consts_2._ascii.ob_base,
            & toplevel_consts_31_consts_3._ascii.ob_base,
            & toplevel_consts_33_names_15._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_37_consts_9_name._ascii.ob_base,
            & toplevel_consts_37_consts_10_name._ascii.ob_base,
            & toplevel_consts_23_consts_3_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[107];
    }
toplevel_consts_39_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 106,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x04\x07\x02\x02\x04\x01\x02\xff\x02\x01\x02\x0a\x04\x01\x02\xff\x02\x01\x02\x44\x06\x01\x02\xff\x02\x01\x02\x18\x06\x01\x02\xff\x02\x01\x02\x1d\x06\x01\x02\xff\x02\x01\x02\x0b\x04\x01\x02\xff\x02\x01\x02\x0c\x04\x01\x02\xff\x02\x01\x02\x06\x04\x01\x02\xff\x02\x01\x02\x12\x02\x01\x04\x01\x02\xff\x02\xff\x02\x02\x02\x04\x02\x01\x04\x01\x02\xff\x02\xff\x02\x02\x02\x04\x02\x01\x04\x01\x02\xff\x02\xff\x06\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[113];
    }
toplevel_consts_39_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 112,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x07\x04\x02\x02\x02\x04\x09\x02\xf7\x02\x09\x02\x02\x04\x43\x02\xbd\x02\x43\x02\x02\x02\x01\x04\x16\x02\xe9\x02\x17\x02\x02\x02\x01\x04\x1b\x02\xe4\x02\x1c\x02\x02\x02\x01\x04\x09\x02\xf6\x02\x0a\x02\x02\x04\x0b\x02\xf5\x02\x0b\x02\x02\x04\x05\x02\xfb\x02\x05\x02\x02\x04\x11\x02\xef\x02\x11\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x02\x04\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x02\x04\x02\x02\x02\x01\x04\x03\x02\xfd\x02\xff\x06\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[151];
    }
toplevel_consts_39_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 150,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x0f\x17\x05\x0c\x06\x12\x05\x4f\x05\x4f\x06\x12\x05\x4f\x06\x11\x05\x25\x05\x25\x06\x11\x05\x25\x06\x11\x30\x34\x05\x20\x05\x20\x06\x11\x05\x20\x06\x11\x27\x2b\x05\x14\x05\x14\x06\x11\x05\x14\x06\x11\x29\x2d\x05\x39\x05\x39\x06\x11\x05\x39\x06\x12\x05\x16\x05\x16\x06\x12\x05\x16\x06\x12\x05\x24\x05\x24\x06\x12\x05\x24\x06\x11\x05\x16\x05\x16\x06\x11\x05\x16\x06\x11\x06\x16\x05\x30\x05\x30\x06\x16\x06\x11\x05\x30\x06\x11\x06\x16\x05\x14\x05\x14\x06\x16\x06\x11\x05\x14\x06\x11\x06\x16\x05\x30\x05\x30\x06\x16\x06\x11\x05\x30\x05\x30\x05\x30",
};
static struct PyCodeObject toplevel_consts_39 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_39_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_39_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_39_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 806,
    .co_code = & toplevel_consts_39_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_39_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_39_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_39_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_39_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_39_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_41_code = {
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
        uint8_t _data[19];
    }
toplevel_consts_41_consts_0 = {
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
    ._data = "_ImportLockContext",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[37];
    }
toplevel_consts_41_consts_1 = {
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
    ._data = "Context manager for the import lock.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_41_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\xa8\x00\xa9\x00\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[25];
    }
toplevel_consts_41_consts_2_consts_0 = {
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
    ._data = "Acquire the import lock.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_41_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_41_consts_2_consts_0._ascii.ob_base,
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
toplevel_consts_41_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_41_consts_2_qualname = {
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
    ._data = "_ImportLockContext.__enter__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[17];
    }
toplevel_consts_41_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 16,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x09\x0d\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c\x09\x1c",
};
static struct PyCodeObject toplevel_consts_41_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_41_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_41_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_41_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1028,
    .co_code = & toplevel_consts_41_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_2_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_41_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_41_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_7_consts_6_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[61];
    }
toplevel_consts_41_consts_3_consts_0 = {
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
    ._data = "Release the import lock regardless of any raised exceptions.",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_41_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_41_consts_3_consts_0._ascii.ob_base,
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
toplevel_consts_41_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_41_consts_3_varnames_1 = {
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
    ._data = "exc_type",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_41_consts_3_varnames_2 = {
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
    ._data = "exc_value",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_41_consts_3_varnames_3 = {
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
    ._data = "exc_traceback",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_41_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_41_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_41_consts_3_varnames_2._ascii.ob_base,
            & toplevel_consts_41_consts_3_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_41_consts_3_qualname = {
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
    ._data = "_ImportLockContext.__exit__",
};
static struct PyCodeObject toplevel_consts_41_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_41_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_41_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_41_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 1032,
    .co_code = & toplevel_consts_41_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_41_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_11_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_41_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_23_consts_11_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_41_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_41_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_41_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_41_consts_0._ascii.ob_base,
            & toplevel_consts_41_consts_1._ascii.ob_base,
            & toplevel_consts_41_consts_2.ob_base,
            & toplevel_consts_41_consts_3.ob_base,
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
toplevel_consts_41_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_0._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_11_consts_2_name._ascii.ob_base,
            & toplevel_consts_11_consts_3_name._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_41_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x02\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_41_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x02\x06\x04\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_41_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x2f\x05\x2f\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c\x05\x1c",
};
static struct PyCodeObject toplevel_consts_41 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_41_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_41_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_41_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 1024,
    .co_code = & toplevel_consts_41_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_41_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_41_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_41_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_41_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_41_columntable.ob_base.ob_base,
    .co_nlocalsplus = 0,
    .co_nlocals = 0,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_43_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\xa0\x00\x64\x01\x7c\x02\x64\x02\x7a\x0a\xa8\x02\xa9\x02\x7d\x03\x74\x01\x7c\x03\xa9\x01\x7c\x02\x6b\x00\x72\x14\x74\x02\x64\x03\xa9\x01\x82\x01\x7c\x03\x64\x04\x19\x00\x7d\x04\x7c\x00\x72\x21\x64\x05\xa0\x03\x7c\x04\x7c\x00\xa8\x02\xa9\x02\x53\x00\x7c\x04\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[51];
    }
toplevel_consts_43_consts_0 = {
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
        uint8_t _data[51];
    }
toplevel_consts_43_consts_3 = {
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
    ._data = "attempted relative import beyond top-level package",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_43_consts_5 = {
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
    ._data = "{}.{}",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_43_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_43_consts_0._ascii.ob_base,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
            & toplevel_consts_43_consts_3._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_43_consts_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_43_names_0 = {
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
    ._data = "rsplit",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_43_names_1 = {
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
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_43_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_43_names_0._ascii.ob_base,
            & toplevel_consts_43_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_43_varnames_1 = {
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
toplevel_consts_43_varnames_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_43_varnames_3 = {
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
    ._data = "bits",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_43_varnames_4 = {
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
    ._data = "base",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_43_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_2._ascii.ob_base,
            & toplevel_consts_43_varnames_3._ascii.ob_base,
            & toplevel_consts_43_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_43_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_43_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x12\x02\x0c\x01\x08\x01\x08\x01\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_43_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x12\x02\x0a\x01\x0a\x01\x08\x01\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[71];
    }
toplevel_consts_43_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 70,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x13\x0c\x2a\x1b\x1e\x20\x25\x28\x29\x20\x29\x0c\x2a\x0c\x2a\x05\x09\x08\x0b\x0c\x10\x08\x11\x14\x19\x08\x19\x05\x50\x0f\x1a\x1b\x4f\x0f\x50\x09\x50\x0c\x10\x11\x12\x0c\x13\x05\x09\x2a\x2e\x0c\x38\x0c\x13\x0c\x26\x1b\x1f\x21\x25\x0c\x26\x0c\x26\x05\x38\x34\x38\x05\x38",
};
static struct PyCodeObject toplevel_consts_43 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_43_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_43_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_43_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1037,
    .co_code = & toplevel_consts_43_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_43_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_43_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_43_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_43_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_43_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_43_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_43_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_44_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x9b\x00\x64\x01\x9d\x02\x7d\x03\x74\x01\xa0\x02\x7c\x03\x74\x03\xa8\x02\xa9\x02\x01\x00\x7c\x00\xa0\x04\x7c\x01\x7c\x02\xa8\x02\xa9\x02\x7d\x04\x7c\x04\x80\x1a\x64\x00\x53\x00\x74\x05\x7c\x01\x7c\x04\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_44_consts_1 = {
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
    ._data = ".find_spec() not found; falling back to find_module()",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_44_consts = {
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
            & toplevel_consts_44_consts_1._ascii.ob_base,
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
toplevel_consts_44_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_1_name._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
            & toplevel_consts_37_consts_6_name._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_44_varnames_0 = {
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
    ._data = "finder",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_44_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_44_varnames_0._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_21_varnames_2._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_44_name = {
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
    ._data = "_find_spec_legacy",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_44_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0e\x01\x0e\x02\x0e\x01\x04\x01\x04\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[19];
    }
toplevel_consts_44_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 18,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x01\x06\x01\x02\xff\x0e\x02\x0e\x01\x02\x01\x06\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_44_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x1b\x1c\x22\x0f\x23\x0c\x3b\x0c\x3b\x0c\x3b\x05\x08\x05\x0e\x05\x27\x14\x17\x19\x26\x05\x27\x05\x27\x05\x27\x0e\x14\x0e\x2c\x21\x25\x27\x2b\x0e\x2c\x0e\x2c\x05\x0b\x08\x0e\x05\x14\x10\x14\x10\x14\x0c\x1c\x1d\x21\x23\x29\x0c\x2a\x05\x2a",
};
static struct PyCodeObject toplevel_consts_44 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_44_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_44_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_44_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1046,
    .co_code = & toplevel_consts_44_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_44_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_44_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_44_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_44_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_44_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_44_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_44_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[271];
    }
toplevel_consts_45_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 270,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\x7d\x03\x7c\x03\x80\x0a\x74\x02\x64\x02\xa9\x01\x82\x01\x7c\x03\x73\x13\x74\x03\xa0\x04\x64\x03\x74\x05\xa8\x02\xa9\x02\x01\x00\x7c\x00\x74\x00\x6a\x06\x76\x00\x7d\x04\x7c\x03\x44\x00\x5d\x6a\x7d\x05\x74\x07\xa9\x00\x35\x00\x01\x00\x09\x00\x7c\x05\x6a\x08\x7d\x06\x6e\x19\x23\x00\x74\x09\x79\x3a\x01\x00\x74\x0a\x7c\x05\x7c\x00\x7c\x01\xa9\x03\x7d\x07\x7c\x07\x80\x38\x59\x00\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x71\x1a\x59\x00\x6e\x0a\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x06\x7c\x00\x7c\x01\x7c\x02\xa9\x03\x7d\x07\x64\x01\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x51\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x7c\x07\x81\x84\x7c\x04\x73\x80\x7c\x00\x74\x00\x6a\x06\x76\x00\x72\x80\x74\x00\x6a\x06\x7c\x00\x19\x00\x7d\x08\x09\x00\x7c\x08\x6a\x0b\x7d\x09\x6e\x0e\x23\x00\x74\x09\x79\x72\x01\x00\x7c\x07\x02\x00\x59\x00\x02\x00\x01\x00\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x09\x80\x7c\x7c\x07\x02\x00\x01\x00\x53\x00\x7c\x09\x02\x00\x01\x00\x53\x00\x7c\x07\x02\x00\x01\x00\x53\x00\x71\x1a\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_45_consts_0 = {
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
    ._data = "Find a module's spec.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[54];
    }
toplevel_consts_45_consts_2 = {
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
    ._data = "sys.meta_path is None, Python is likely shutting down",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_45_consts_3 = {
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
    ._data = "sys.meta_path is empty",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_45_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_45_consts_0._ascii.ob_base,
            Py_None,
            & toplevel_consts_45_consts_2._ascii.ob_base,
            & toplevel_consts_45_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_45_names_1 = {
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
    ._data = "meta_path",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[12];
        }_object;
    }
toplevel_consts_45_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_45_names_1._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_41_consts_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_44_name._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_45_varnames_4 = {
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
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_45_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_3._ascii.ob_base,
            & toplevel_consts_45_names_1._ascii.ob_base,
            & toplevel_consts_45_varnames_4._ascii.ob_base,
            & toplevel_consts_44_varnames_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_45_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[81];
    }
toplevel_consts_45_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 80,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x04\x01\x08\x02\x04\x03\x0e\x01\x0a\x05\x08\x01\x08\x01\x02\x01\x08\x01\x02\x80\x06\x01\x0c\x01\x04\x01\x02\x01\x0c\xfa\x04\x05\x02\xfe\x06\x80\x0c\x05\x14\xf8\x06\x80\x08\x00\x04\x09\x0e\x02\x0a\x01\x02\x01\x08\x01\x02\x80\x06\x01\x0c\x04\x02\xfc\x06\x80\x04\x06\x08\x01\x08\x02\x08\x02\x02\xef\x04\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[93];
    }
toplevel_consts_45_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 92,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x02\x02\x01\x02\x03\x02\xff\x06\x01\x02\x02\x10\x01\x0a\x05\x02\x01\x04\x1d\x02\xe3\x04\x01\x06\x08\x08\xfa\x02\x80\x02\x01\x04\x03\x0c\xfe\x02\x01\x04\x01\x0c\x02\x06\xfe\x06\x80\x20\x02\x06\x80\x08\x00\x02\x01\x02\x11\x02\xf1\x02\x0f\x08\xf1\x02\x0f\x0a\xf2\x02\x0c\x08\xf6\x02\x80\x02\x01\x12\x04\x06\x80\x02\x02\x02\x03\x08\xfe\x08\x02\x0a\x02\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[271];
    }
toplevel_consts_45_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 270,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x11\x14\x11\x1e\x05\x0e\x08\x11\x05\x2b\x0f\x1a\x1b\x2a\x0f\x2b\x09\x2b\x0c\x15\x05\x40\x09\x12\x09\x40\x18\x30\x32\x3f\x09\x40\x09\x40\x09\x40\x11\x15\x19\x1c\x19\x24\x11\x24\x05\x0e\x13\x1c\x05\x14\x05\x14\x09\x0f\x0e\x20\x0e\x22\x09\x35\x09\x35\x0d\x35\x1d\x23\x1d\x2d\x11\x1a\x11\x1a\x00\x00\x14\x22\x0d\x1d\x0d\x1d\x18\x29\x2a\x30\x32\x36\x38\x3c\x18\x3d\x11\x15\x14\x18\x11\x1d\x15\x1d\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x11\x1d\x11\x1d\x0d\x1d\x00\x00\x00\x00\x00\x00\x18\x21\x22\x26\x28\x2c\x2e\x34\x18\x35\x11\x15\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x00\x00\x00\x00\x00\x00\x09\x35\x09\x35\x09\x35\x09\x35\x0c\x10\x09\x1c\x14\x1d\x0d\x1c\x22\x26\x2a\x2d\x2a\x35\x22\x35\x0d\x1c\x1a\x1d\x1a\x25\x26\x2a\x1a\x2b\x11\x17\x11\x28\x20\x26\x20\x2f\x15\x1d\x15\x1d\x00\x00\x18\x26\x11\x20\x11\x20\x1c\x20\x15\x20\x15\x20\x15\x20\x15\x20\x15\x20\x11\x20\x00\x00\x00\x00\x00\x00\x18\x20\x15\x28\x20\x24\x19\x24\x19\x24\x19\x24\x20\x28\x19\x28\x19\x28\x19\x28\x18\x1c\x11\x1c\x11\x1c\x11\x1c\x09\x1c\x10\x14\x10\x14",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[68];
    }
toplevel_consts_45_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 67,
    },
    .ob_shash = -1,
    .ob_sval = "\x9f\x01\x41\x0a\x05\xa1\x03\x25\x04\xa4\x01\x41\x0a\x05\xa5\x0c\x3b\x07\xb1\x01\x41\x0a\x05\xb8\x02\x41\x0a\x05\xba\x01\x3b\x07\xbb\x09\x41\x0a\x05\xc1\x0a\x04\x41\x0e\x09\xc1\x11\x01\x41\x0e\x09\xc1\x24\x03\x41\x28\x02\xc1\x28\x06\x41\x33\x05\xc1\x32\x01\x41\x33\x05",
};
static struct PyCodeObject toplevel_consts_45 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_45_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_45_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_45_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_45_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 1056,
    .co_code = & toplevel_consts_45_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_45_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_45_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_45_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_45_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_45_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_45_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_45_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_46_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x74\x01\xa9\x02\x73\x10\x74\x02\x64\x01\xa0\x03\x74\x04\x7c\x00\xa9\x01\xa8\x01\xa9\x01\xa9\x01\x82\x01\x7c\x02\x64\x02\x6b\x00\x72\x18\x74\x05\x64\x03\xa9\x01\x82\x01\x7c\x02\x64\x02\x6b\x04\x72\x2b\x74\x00\x7c\x01\x74\x01\xa9\x02\x73\x25\x74\x02\x64\x04\xa9\x01\x82\x01\x7c\x01\x73\x2b\x74\x06\x64\x05\xa9\x01\x82\x01\x7c\x00\x73\x35\x7c\x02\x64\x02\x6b\x02\x72\x37\x74\x05\x64\x06\xa9\x01\x82\x01\x64\x07\x53\x00\x64\x07\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_46_consts_0 = {
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
    ._data = "Verify arguments are \"sane\".",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_46_consts_1 = {
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
    ._data = "module name must be str, not {}",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_46_consts_3 = {
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
    ._data = "level must be >= 0",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[32];
    }
toplevel_consts_46_consts_4 = {
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
    ._data = "__package__ not set to a string",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[55];
    }
toplevel_consts_46_consts_5 = {
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
    ._data = "attempted relative import with no known parent package",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_46_consts_6 = {
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
    ._data = "Empty module name",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_46_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_46_consts_0._ascii.ob_base,
            & toplevel_consts_46_consts_1._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_46_consts_3._ascii.ob_base,
            & toplevel_consts_46_consts_4._ascii.ob_base,
            & toplevel_consts_46_consts_5._ascii.ob_base,
            & toplevel_consts_46_consts_6._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_46_names_0 = {
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
toplevel_consts_46_names_1 = {
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
        uint8_t _data[10];
    }
toplevel_consts_46_names_2 = {
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
toplevel_consts_46_names_5 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_46_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_46_names_1._ascii.ob_base,
            & toplevel_consts_46_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_46_names_5._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
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
toplevel_consts_46_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_46_name = {
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
    ._data = "_sanity_check",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[27];
    }
toplevel_consts_46_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 26,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x14\x01\x08\x01\x08\x01\x08\x01\x0a\x01\x08\x01\x04\x01\x08\x01\x0c\x02\x08\x01\x08\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_46_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x02\x16\x01\x06\x01\x0a\x01\x06\x01\x02\x05\x08\xfc\x02\x04\x08\xfd\x02\x01\x02\x02\x02\xff\x06\x01\x02\x01\x02\x01\x06\xff\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[115];
    }
toplevel_consts_46_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 114,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x16\x17\x1b\x1d\x20\x0c\x21\x05\x4e\x0f\x18\x19\x3a\x19\x4d\x42\x46\x47\x4b\x42\x4c\x19\x4d\x19\x4d\x0f\x4e\x09\x4e\x08\x0d\x10\x11\x08\x11\x05\x2f\x0f\x19\x1a\x2e\x0f\x2f\x09\x2f\x08\x0d\x10\x11\x08\x11\x05\x29\x10\x1a\x1b\x22\x24\x27\x10\x28\x09\x29\x13\x1c\x1d\x3e\x13\x3f\x0d\x3f\x12\x19\x09\x29\x13\x1e\x1f\x28\x13\x29\x0d\x29\x0c\x10\x05\x2e\x15\x1a\x1e\x1f\x15\x1f\x05\x2e\x0f\x19\x1a\x2d\x0f\x2e\x09\x2e\x05\x2e\x05\x2e\x05\x2e\x05\x2e",
};
static struct PyCodeObject toplevel_consts_46 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_46_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_46_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_46_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1103,
    .co_code = & toplevel_consts_46_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_46_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_46_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_46_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_46_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_46_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_47 = {
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
    ._data = "No module named ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_48 = {
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
    ._data = "{!r}",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[357];
    }
toplevel_consts_49_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 356,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x7d\x02\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x64\x02\x19\x00\x7d\x03\x64\x00\x7d\x04\x7c\x03\x72\x50\x7c\x03\x74\x01\x6a\x02\x76\x01\x72\x19\x74\x03\x7c\x01\x7c\x03\xa9\x02\x01\x00\x7c\x00\x74\x01\x6a\x02\x76\x00\x72\x23\x74\x01\x6a\x02\x7c\x00\x19\x00\x53\x00\x74\x01\x6a\x02\x7c\x03\x19\x00\x7d\x05\x09\x00\x7c\x05\x6a\x04\x7d\x02\x6e\x18\x23\x00\x74\x05\x79\x41\x01\x00\x74\x06\x64\x03\x7a\x00\xa0\x07\x7c\x00\x7c\x03\xa8\x02\xa9\x02\x7d\x06\x74\x08\x7c\x06\x7c\x00\x64\x04\xaa\x02\x64\x00\x82\x02\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x05\x6a\x09\x7d\x04\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x64\x05\x19\x00\x7d\x07\x74\x0a\x7c\x00\x7c\x02\xa9\x02\x7d\x08\x7c\x08\x80\x61\x74\x08\x74\x06\xa0\x07\x7c\x00\xa8\x01\xa9\x01\x7c\x00\x64\x04\xaa\x02\x82\x01\x7c\x04\x72\x6a\x7c\x04\x6a\x0b\xa0\x0c\x7c\x07\xa8\x01\xa9\x01\x01\x00\x09\x00\x74\x0d\x7c\x08\xa9\x01\x7d\x09\x7c\x04\x72\x77\x7c\x04\x6a\x0b\xa0\x0e\xa8\x00\xa9\x00\x01\x00\x6e\x0e\x23\x00\x7c\x04\x72\x82\x7c\x04\x6a\x0b\xa0\x0e\xa8\x00\xa9\x00\x01\x00\x77\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x03\x72\xb0\x74\x01\x6a\x02\x7c\x03\x19\x00\x7d\x05\x09\x00\x74\x0f\x7c\x05\x7c\x07\x7c\x09\xa9\x03\x01\x00\x7c\x09\x53\x00\x23\x00\x74\x05\x79\xac\x01\x00\x64\x06\x7c\x03\x9b\x02\x64\x07\x7c\x07\x9b\x02\x9d\x04\x7d\x06\x74\x10\xa0\x11\x7c\x06\x74\x12\xa8\x02\xa9\x02\x01\x00\x59\x00\x7c\x09\x53\x00\x77\x00\x78\x03\x59\x00\x77\x01\x7c\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_49_consts_3 = {
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
    ._data = "; {!r} is not a package",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_49_consts_5 = {
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
        uint8_t _data[28];
    }
toplevel_consts_49_consts_6 = {
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
    ._data = "Cannot set an attribute on ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_49_consts_7 = {
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
    ._data = " for child module ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_49_consts = {
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
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_49_consts_3._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
            & toplevel_consts_49_consts_5.ob_base.ob_base,
            & toplevel_consts_49_consts_6._ascii.ob_base,
            & toplevel_consts_49_consts_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_49_names_6 = {
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
    ._data = "_ERR_MSG",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_49_names_8 = {
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
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts_49_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_23_consts_9_names_2._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_49_names_6._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_49_names_8._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            & toplevel_consts_45_name._ascii.ob_base,
            & toplevel_consts_23_consts_4_names_5._ascii.ob_base,
            & toplevel_consts_23_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
            & toplevel_consts_33_names_17._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_49_varnames_1 = {
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
    ._data = "import_",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_49_varnames_4 = {
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
    ._data = "parent_spec",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_49_varnames_5 = {
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
    ._data = "parent_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_49_varnames_7 = {
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
    ._data = "child",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_49_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_49_varnames_1._ascii.ob_base,
            & toplevel_consts_37_consts_5_varnames_2._ascii.ob_base,
            & toplevel_consts_23_consts_9_name._ascii.ob_base,
            & toplevel_consts_49_varnames_4._ascii.ob_base,
            & toplevel_consts_49_varnames_5._ascii.ob_base,
            & toplevel_consts_21_varnames_2._ascii.ob_base,
            & toplevel_consts_49_varnames_7._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[24];
    }
toplevel_consts_49_name = {
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
    ._data = "_find_and_load_unlocked",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[95];
    }
toplevel_consts_49_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 94,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x10\x01\x04\x01\x04\x01\x0a\x01\x0a\x01\x0a\x02\x0a\x01\x0a\x01\x02\x01\x08\x01\x02\x80\x06\x01\x12\x01\x0e\x01\x02\xfe\x06\x80\x06\x03\x10\x01\x0a\x01\x04\x01\x14\x01\x04\x02\x0e\x03\x02\x01\x08\x01\x04\x02\x0c\x01\x04\x80\x04\xff\x0e\x01\x02\xff\x06\x80\x04\x02\x0a\x02\x02\x01\x0c\x01\x04\x04\x02\x80\x06\xfd\x10\x01\x10\x01\x04\x01\x02\xfd\x06\x80\x04\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[101];
    }
toplevel_consts_49_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 100,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x01\x10\x01\x04\x01\x02\x01\x02\x0d\x08\xf4\x0c\x01\x08\x02\x0c\x01\x0a\x01\x02\x05\x08\xfd\x02\x80\x02\x01\x04\x02\x12\xff\x10\x01\x06\x80\x06\x01\x10\x01\x0a\x01\x02\x01\x02\x0b\x14\xf6\x02\x02\x10\x03\x02\x05\x08\xfd\x02\x02\x0e\x01\x04\x80\x02\xff\x12\x01\x06\x80\x02\x01\x02\x07\x0a\xfb\x02\x05\x0c\xfd\x04\x04\x02\x80\x02\xfd\x04\x02\x10\xff\x10\x01\x04\x01\x02\xff\x06\x80\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[357];
    }
toplevel_consts_49_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 356,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x10\x05\x09\x0e\x12\x0e\x22\x1e\x21\x0e\x22\x0e\x22\x23\x24\x0e\x25\x05\x0b\x13\x17\x05\x10\x08\x0e\x05\x28\x0c\x12\x1a\x1d\x1a\x25\x0c\x25\x09\x37\x0d\x26\x27\x2e\x30\x36\x0d\x37\x0d\x37\x0c\x10\x14\x17\x14\x1f\x0c\x1f\x09\x25\x14\x17\x14\x1f\x20\x24\x14\x25\x0d\x25\x19\x1c\x19\x24\x25\x2b\x19\x2c\x09\x16\x09\x40\x14\x21\x14\x2a\x0d\x11\x0d\x11\x00\x00\x10\x1e\x09\x40\x09\x40\x14\x1c\x1f\x38\x14\x38\x13\x4e\x41\x45\x47\x4d\x13\x4e\x13\x4e\x0d\x10\x13\x26\x27\x2a\x31\x35\x13\x36\x13\x36\x3c\x40\x0d\x40\x09\x40\x00\x00\x00\x00\x00\x00\x17\x24\x17\x2d\x09\x14\x11\x15\x11\x25\x21\x24\x11\x25\x11\x25\x26\x27\x11\x28\x09\x0e\x0c\x16\x17\x1b\x1d\x21\x0c\x22\x05\x09\x08\x0c\x05\x3c\x0f\x22\x23\x2b\x23\x38\x33\x37\x23\x38\x23\x38\x3f\x43\x0f\x44\x0f\x44\x09\x44\x0c\x17\x09\x40\x0d\x18\x0d\x32\x0d\x40\x3a\x3f\x0d\x40\x0d\x40\x0d\x40\x09\x3c\x16\x24\x25\x29\x16\x2a\x0d\x13\x10\x1b\x0d\x3c\x11\x1c\x11\x36\x11\x3c\x11\x3c\x11\x3c\x11\x3c\x00\x00\x00\x00\x10\x1b\x0d\x3c\x11\x1c\x11\x36\x11\x3c\x11\x3c\x11\x3c\x11\x3c\x11\x3c\x0d\x3c\x00\x00\x00\x00\x00\x00\x08\x0e\x05\x2f\x19\x1c\x19\x24\x25\x2b\x19\x2c\x09\x16\x09\x2f\x0d\x14\x15\x22\x24\x29\x2b\x31\x0d\x32\x0d\x32\x0c\x12\x05\x12\x00\x00\x10\x1e\x09\x2f\x09\x2f\x13\x56\x31\x37\x13\x56\x13\x56\x4d\x52\x13\x56\x13\x56\x0d\x10\x0d\x16\x0d\x2f\x1c\x1f\x21\x2e\x0d\x2f\x0d\x2f\x0d\x2f\x0d\x2f\x0c\x12\x05\x12\x09\x2f\x00\x00\x00\x00\x00\x00\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[40];
    }
toplevel_consts_49_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 39,
    },
    .ob_shash = -1,
    .ob_sval = "\xa9\x03\x2d\x00\xad\x15\x41\x02\x03\xc1\x2b\x04\x41\x38\x00\xc1\x38\x0b\x42\x03\x03\xc2\x0e\x06\x42\x16\x00\xc2\x16\x13\x42\x2d\x03\xc2\x2c\x01\x42\x2d\x03",
};
static struct PyCodeObject toplevel_consts_49 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_49_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_49_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_49_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_49_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1122,
    .co_code = & toplevel_consts_49_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_49_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_49_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_49_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_49_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_49_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_49_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_49_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[179];
    }
toplevel_consts_50_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 178,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x6a\x01\xa0\x02\x7c\x00\x74\x03\xa8\x02\xa9\x02\x7d\x02\x7c\x02\x74\x03\x75\x00\x73\x17\x74\x04\x74\x04\x7c\x02\x64\x01\x64\x02\xa9\x03\x64\x03\x64\x04\xa9\x03\x72\x49\x74\x05\x7c\x00\xa9\x01\x35\x00\x01\x00\x74\x00\x6a\x01\xa0\x02\x7c\x00\x74\x03\xa8\x02\xa9\x02\x7d\x02\x7c\x02\x74\x03\x75\x00\x72\x33\x74\x06\x7c\x00\x7c\x01\xa9\x02\x02\x00\x64\x02\x04\x00\x04\x00\xa9\x03\x01\x00\x53\x00\x09\x00\x64\x02\x04\x00\x04\x00\xa9\x03\x01\x00\x6e\x0b\x23\x00\x31\x00\x73\x41\x77\x02\x78\x03\x59\x00\x77\x01\x01\x00\x59\x00\x01\x00\x01\x00\x74\x07\x7c\x00\xa9\x01\x01\x00\x7c\x02\x80\x57\x64\x05\xa0\x08\x7c\x00\xa8\x01\xa9\x01\x7d\x03\x74\x09\x7c\x03\x7c\x00\x64\x06\xaa\x02\x82\x01\x7c\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_50_consts_0 = {
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
    ._data = "Find and load the module.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[41];
    }
toplevel_consts_50_consts_5 = {
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
    ._data = "import of {} halted; None in sys.modules",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_50_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_50_consts_0._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            Py_None,
            & toplevel_consts_35_names_8._ascii.ob_base,
            Py_False,
            & toplevel_consts_50_consts_5._ascii.ob_base,
            & toplevel_consts_4_varnames._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_50_names_3 = {
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
    ._data = "_NEEDS_LOADING",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_50_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_50_names_3._ascii.ob_base,
            & toplevel_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_49_name._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_49_names_8._ascii.ob_base,
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
toplevel_consts_50_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_49_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_18_varnames_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_50_name = {
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
    ._data = "_find_and_load",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_50_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x05\x08\x01\x12\x01\x02\xff\x0a\x02\x10\x01\x08\x01\x08\x01\x0e\xfd\x02\x02\x14\xfe\x06\x80\x08\x00\x08\x09\x04\x02\x02\x01\x08\x01\x02\xff\x0c\x02\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[41];
    }
toplevel_consts_50_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 40,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x10\x05\x06\x01\x02\x0b\x12\xf6\x02\x0a\x06\xf7\x04\x03\x10\xfe\x06\x01\x2e\x01\x06\x80\x08\x00\x08\x06\x02\x02\x02\x03\x0a\xff\x02\xff\x0c\x02\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[179];
    }
toplevel_consts_50_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 178,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x11\x0e\x19\x0e\x33\x1e\x22\x24\x32\x0e\x33\x0e\x33\x05\x0b\x09\x0f\x13\x21\x09\x21\x05\x22\x09\x10\x11\x18\x19\x1f\x21\x2b\x2d\x31\x11\x32\x34\x43\x45\x4a\x09\x4b\x05\x22\x0e\x20\x21\x25\x0e\x26\x09\x3e\x09\x3e\x16\x19\x16\x21\x16\x3b\x26\x2a\x2c\x3a\x16\x3b\x16\x3b\x0d\x13\x10\x16\x1a\x28\x10\x28\x0d\x3e\x18\x2f\x30\x34\x36\x3d\x18\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x0d\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x00\x00\x00\x00\x00\x00\x09\x3e\x09\x3e\x09\x3e\x09\x3e\x09\x1c\x1d\x21\x09\x22\x09\x22\x08\x0e\x05\x36\x14\x29\x14\x36\x31\x35\x14\x36\x14\x36\x09\x10\x0f\x22\x23\x2a\x31\x35\x0f\x36\x0f\x36\x09\x36\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[14];
    }
toplevel_consts_50_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 13,
    },
    .ob_shash = -1,
    .ob_sval = "\x9b\x11\x3a\x03\xba\x04\x3e\x07\xc1\x01\x01\x3e\x07",
};
static struct PyCodeObject toplevel_consts_50 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_50_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_50_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_50_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_50_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 1167,
    .co_code = & toplevel_consts_50_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_50_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_33_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_50_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_50_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_50_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_50_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_50_columntable.ob_base.ob_base,
    .co_nlocalsplus = 4,
    .co_nlocals = 4,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_50_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_52_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\x7c\x02\xa9\x03\x01\x00\x7c\x02\x64\x01\x6b\x04\x72\x11\x74\x01\x7c\x00\x7c\x01\x7c\x02\xa9\x03\x7d\x00\x74\x02\x7c\x00\x74\x03\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[307];
    }
toplevel_consts_52_consts_0 = {
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
    ._data = "\x49\x6d\x70\x6f\x72\x74\x20\x61\x6e\x64\x20\x72\x65\x74\x75\x72\x6e\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x20\x62\x61\x73\x65\x64\x20\x6f\x6e\x20\x69\x74\x73\x20\x6e\x61\x6d\x65\x2c\x20\x74\x68\x65\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x74\x68\x65\x20\x63\x61\x6c\x6c\x20\x69\x73\x0a\x20\x20\x20\x20\x62\x65\x69\x6e\x67\x20\x6d\x61\x64\x65\x20\x66\x72\x6f\x6d\x2c\x20\x61\x6e\x64\x20\x74\x68\x65\x20\x6c\x65\x76\x65\x6c\x20\x61\x64\x6a\x75\x73\x74\x6d\x65\x6e\x74\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x73\x20\x74\x68\x65\x20\x67\x72\x65\x61\x74\x65\x73\x74\x20\x63\x6f\x6d\x6d\x6f\x6e\x20\x64\x65\x6e\x6f\x6d\x69\x6e\x61\x74\x6f\x72\x20\x6f\x66\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x61\x6c\x69\x74\x79\x0a\x20\x20\x20\x20\x62\x65\x74\x77\x65\x65\x6e\x20\x69\x6d\x70\x6f\x72\x74\x5f\x6d\x6f\x64\x75\x6c\x65\x20\x61\x6e\x64\x20\x5f\x5f\x69\x6d\x70\x6f\x72\x74\x5f\x5f\x2e\x20\x54\x68\x69\x73\x20\x69\x6e\x63\x6c\x75\x64\x65\x73\x20\x73\x65\x74\x74\x69\x6e\x67\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x20\x69\x66\x0a\x20\x20\x20\x20\x74\x68\x65\x20\x6c\x6f\x61\x64\x65\x72\x20\x64\x69\x64\x20\x6e\x6f\x74\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_52_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_52_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_52_names_3 = {
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
    ._data = "_gcd_import",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_52_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_46_name._ascii.ob_base,
            & toplevel_consts_43_name._ascii.ob_base,
            & toplevel_consts_50_name._ascii.ob_base,
            & toplevel_consts_52_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_52_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x09\x08\x01\x0c\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_52_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x09\x06\x01\x0e\x01\x0a\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_52_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x12\x13\x17\x19\x20\x22\x27\x05\x28\x05\x28\x08\x0d\x10\x11\x08\x11\x05\x33\x10\x1d\x1e\x22\x24\x2b\x2d\x32\x10\x33\x09\x0d\x0c\x1a\x1b\x1f\x21\x2c\x0c\x2d\x05\x2d",
};
static struct PyCodeObject toplevel_consts_52 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_52_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_52_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_52_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1194,
    .co_code = & toplevel_consts_52_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_52_names_3._ascii.ob_base,
    .co_qualname = & toplevel_consts_52_names_3._ascii.ob_base,
    .co_linetable = & toplevel_consts_52_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_52_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_52_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_46_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_53_0 = {
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
    ._data = "recursive",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_53 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_53_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[217];
    }
toplevel_consts_54_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 216,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x44\x00\x5d\x66\x7d\x04\x74\x00\x7c\x04\x74\x01\xa9\x02\x73\x21\x7c\x03\x72\x12\x7c\x00\x6a\x02\x64\x01\x7a\x00\x7d\x05\x6e\x02\x64\x02\x7d\x05\x74\x03\x64\x03\x7c\x05\x9b\x00\x64\x04\x74\x04\x7c\x04\xa9\x01\x6a\x02\x9b\x00\x9d\x04\xa9\x01\x82\x01\x7c\x04\x64\x05\x6b\x02\x72\x36\x7c\x03\x73\x35\x74\x05\x7c\x00\x64\x06\xa9\x02\x72\x35\x74\x06\x7c\x00\x7c\x00\x6a\x07\x7c\x02\x64\x07\x64\x08\xaa\x04\x01\x00\x71\x03\x74\x05\x7c\x00\x7c\x04\xa9\x02\x73\x69\x64\x09\xa0\x08\x7c\x00\x6a\x02\x7c\x04\xa8\x02\xa9\x02\x7d\x06\x09\x00\x74\x09\x7c\x02\x7c\x06\xa9\x02\x01\x00\x71\x03\x23\x00\x74\x0a\x79\x65\x7d\x07\x7c\x07\x6a\x0b\x7c\x06\x6b\x02\x72\x60\x74\x0c\x6a\x0d\xa0\x0e\x7c\x06\x74\x0f\xa8\x02\xa9\x02\x81\x60\x59\x00\x64\x0a\x7d\x07\x7e\x07\x71\x03\x82\x00\x64\x0a\x7d\x07\x7e\x07\x77\x01\x77\x00\x78\x03\x59\x00\x77\x01\x71\x03\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[239];
    }
toplevel_consts_54_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 238,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x46\x69\x67\x75\x72\x65\x20\x6f\x75\x74\x20\x77\x68\x61\x74\x20\x5f\x5f\x69\x6d\x70\x6f\x72\x74\x5f\x5f\x20\x73\x68\x6f\x75\x6c\x64\x20\x72\x65\x74\x75\x72\x6e\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x69\x6d\x70\x6f\x72\x74\x5f\x20\x70\x61\x72\x61\x6d\x65\x74\x65\x72\x20\x69\x73\x20\x61\x20\x63\x61\x6c\x6c\x61\x62\x6c\x65\x20\x77\x68\x69\x63\x68\x20\x74\x61\x6b\x65\x73\x20\x74\x68\x65\x20\x6e\x61\x6d\x65\x20\x6f\x66\x20\x6d\x6f\x64\x75\x6c\x65\x20\x74\x6f\x0a\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x2e\x20\x49\x74\x20\x69\x73\x20\x72\x65\x71\x75\x69\x72\x65\x64\x20\x74\x6f\x20\x64\x65\x63\x6f\x75\x70\x6c\x65\x20\x74\x68\x65\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x66\x72\x6f\x6d\x20\x61\x73\x73\x75\x6d\x69\x6e\x67\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x27\x73\x0a\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x20\x69\x73\x20\x64\x65\x73\x69\x72\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_54_consts_1 = {
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
    ._data = ".__all__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_54_consts_2 = {
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
    ._data = "``from list''",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_54_consts_3 = {
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
    ._data = "Item in ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_54_consts_4 = {
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
    ._data = " must be str, not ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_54_consts_5 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_54_consts_6 = {
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
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_54_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_54_consts_0._ascii.ob_base,
            & toplevel_consts_54_consts_1._ascii.ob_base,
            & toplevel_consts_54_consts_2._ascii.ob_base,
            & toplevel_consts_54_consts_3._ascii.ob_base,
            & toplevel_consts_54_consts_4._ascii.ob_base,
            & toplevel_consts_54_consts_5._ascii.ob_base,
            & toplevel_consts_54_consts_6._ascii.ob_base,
            Py_True,
            & toplevel_consts_53._object.ob_base.ob_base,
            & toplevel_consts_43_consts_5._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[17];
    }
toplevel_consts_54_names_6 = {
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
    ._data = "_handle_fromlist",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_54_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_46_names_1._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_46_names_2._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_54_names_6._ascii.ob_base,
            & toplevel_consts_54_consts_6._ascii.ob_base,
            & toplevel_consts_7_consts_6_names_0._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_49_names_8._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_50_names_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_54_varnames_1 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_54_varnames_4 = {
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
        uint8_t _data[6];
    }
toplevel_consts_54_varnames_5 = {
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
    ._data = "where",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_54_varnames_6 = {
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
    ._data = "from_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_54_varnames_7 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_54_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_54_varnames_1._ascii.ob_base,
            & toplevel_consts_49_varnames_1._ascii.ob_base,
            & toplevel_consts_53_0._ascii.ob_base,
            & toplevel_consts_54_varnames_4._ascii.ob_base,
            & toplevel_consts_54_varnames_5._ascii.ob_base,
            & toplevel_consts_54_varnames_6._ascii.ob_base,
            & toplevel_consts_54_varnames_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[63];
    }
toplevel_consts_54_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 62,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0a\x0a\x01\x04\x01\x0c\x01\x04\x02\x0a\x01\x08\x01\x08\xff\x08\x02\x0e\x01\x0a\x01\x02\x01\x06\xff\x02\x80\x0a\x02\x10\x01\x02\x01\x0c\x01\x02\x80\x06\x01\x0a\x04\x0e\x01\x02\xff\x0a\x02\x02\x01\x08\x80\x02\xf9\x06\x80\x02\xfc\x04\x0c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[83];
    }
toplevel_consts_54_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 82,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x02\x0a\x04\x17\x02\xe9\x08\x01\x02\x16\x02\xeb\x02\x03\x0c\xfe\x04\x02\x02\x01\x02\x01\x02\xff\x14\x01\x06\x01\x02\x0f\x02\xf2\x02\x02\x08\xfe\x02\x02\x0a\xff\x08\x01\x02\x80\x08\x01\x02\x0b\x10\xf6\x02\x0a\x0c\xf8\x02\x80\x02\x01\x04\x07\x08\xfd\x02\x02\x0e\xff\x0c\x01\x02\x01\x08\x80\x02\x00\x06\x80\x02\x00\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[217];
    }
toplevel_consts_54_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 216,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0e\x16\x05\x16\x05\x16\x09\x0a\x10\x1a\x1b\x1c\x1e\x21\x10\x22\x09\x16\x10\x19\x0d\x28\x19\x1f\x19\x28\x2b\x35\x19\x35\x11\x16\x11\x16\x19\x28\x11\x16\x13\x1c\x1d\x36\x28\x2d\x1d\x36\x1d\x36\x24\x28\x29\x2a\x24\x2b\x24\x34\x1d\x36\x1d\x36\x13\x37\x0d\x37\x0e\x0f\x13\x16\x0e\x16\x09\x16\x14\x1d\x0d\x31\x22\x29\x2a\x30\x32\x3b\x22\x3c\x0d\x31\x11\x21\x22\x28\x2a\x30\x2a\x38\x3a\x41\x2c\x30\x11\x31\x11\x31\x11\x31\x00\x00\x12\x19\x1a\x20\x22\x23\x12\x24\x09\x16\x19\x20\x19\x3b\x28\x2e\x28\x37\x39\x3a\x19\x3b\x19\x3b\x0d\x16\x0d\x16\x11\x2a\x2b\x32\x34\x3d\x11\x3e\x11\x3e\x11\x3e\x00\x00\x14\x27\x0d\x16\x0d\x16\x15\x18\x15\x1d\x21\x2a\x15\x2a\x11\x1d\x15\x18\x15\x20\x15\x3f\x25\x2e\x30\x3e\x15\x3f\x15\x3f\x11\x1d\x15\x1d\x15\x1d\x15\x1d\x15\x1d\x15\x1d\x11\x16\x00\x00\x00\x00\x00\x00\x00\x00\x0d\x16\x00\x00\x00\x00\x00\x00\x09\x16\x0c\x12\x05\x12",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[31];
    }
toplevel_consts_54_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 30,
    },
    .ob_shash = -1,
    .ob_sval = "\xc1\x04\x05\x41\x0a\x02\xc1\x0a\x04\x41\x26\x05\xc1\x0e\x0d\x41\x21\x05\xc1\x20\x01\x41\x21\x05\xc1\x21\x05\x41\x26\x05",
};
static struct PyCodeObject toplevel_consts_54 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_54_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_54_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_54_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_54_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 3,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 1,
    .co_stacksize = 7,
    .co_firstlineno = 1209,
    .co_code = & toplevel_consts_54_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_54_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_27_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_54_names_6._ascii.ob_base,
    .co_qualname = & toplevel_consts_54_names_6._ascii.ob_base,
    .co_linetable = & toplevel_consts_54_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_54_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_54_columntable.ob_base.ob_base,
    .co_nlocalsplus = 8,
    .co_nlocals = 8,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_54_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[147];
    }
toplevel_consts_55_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 146,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x00\xa0\x00\x64\x01\xa8\x01\xa9\x01\x7d\x01\x7c\x00\xa0\x00\x64\x02\xa8\x01\xa9\x01\x7d\x02\x7c\x01\x81\x29\x7c\x02\x81\x27\x7c\x01\x7c\x02\x6a\x01\x6b\x03\x72\x27\x74\x02\xa0\x03\x64\x04\x7c\x01\x9b\x02\x64\x05\x7c\x02\x6a\x01\x9b\x02\x64\x06\x9d\x05\x74\x04\x64\x07\x64\x08\xa8\x04\xaa\x03\x01\x00\x7c\x01\x53\x00\x7c\x02\x81\x2e\x7c\x02\x6a\x01\x53\x00\x74\x02\xa0\x03\x64\x09\x74\x04\x64\x07\x64\x08\xa8\x04\xaa\x03\x01\x00\x7c\x00\x64\x0a\x19\x00\x7d\x01\x64\x0b\x7c\x00\x76\x01\x72\x47\x7c\x01\xa0\x05\x64\x0c\xa8\x01\xa9\x01\x64\x0d\x19\x00\x7d\x01\x7c\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[168];
    }
toplevel_consts_55_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 167,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x43\x61\x6c\x63\x75\x6c\x61\x74\x65\x20\x77\x68\x61\x74\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x2e\x0a\x0a\x20\x20\x20\x20\x5f\x5f\x70\x61\x63\x6b\x61\x67\x65\x5f\x5f\x20\x69\x73\x20\x6e\x6f\x74\x20\x67\x75\x61\x72\x61\x6e\x74\x65\x65\x64\x20\x74\x6f\x20\x62\x65\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x6f\x72\x20\x63\x6f\x75\x6c\x64\x20\x62\x65\x20\x73\x65\x74\x20\x74\x6f\x20\x4e\x6f\x6e\x65\x0a\x20\x20\x20\x20\x74\x6f\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x20\x74\x68\x61\x74\x20\x69\x74\x73\x20\x70\x72\x6f\x70\x65\x72\x20\x76\x61\x6c\x75\x65\x20\x69\x73\x20\x75\x6e\x6b\x6e\x6f\x77\x6e\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[33];
    }
toplevel_consts_55_consts_4 = {
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
    ._data = "__package__ != __spec__.parent (",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_55_consts_5 = {
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
    ._data = " != ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_55_consts_6 = {
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
    ._data = ")",
};
static
    struct {
        PyObject_VAR_HEAD
        digit ob_digit[1];
    }
toplevel_consts_55_consts_7 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_55_consts_8_0 = {
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
toplevel_consts_55_consts_8 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_55_consts_8_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[90];
    }
toplevel_consts_55_consts_9 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 89,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "can't resolve package from __spec__ or __package__, falling back on __name__ and __path__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[14];
        }_object;
    }
toplevel_consts_55_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 14,
        },
        .ob_item = {
            & toplevel_consts_55_consts_0._ascii.ob_base,
            & toplevel_consts_30_consts_3._ascii.ob_base,
            & toplevel_consts_22_consts_3._ascii.ob_base,
            Py_None,
            & toplevel_consts_55_consts_4._ascii.ob_base,
            & toplevel_consts_55_consts_5._ascii.ob_base,
            & toplevel_consts_55_consts_6._ascii.ob_base,
            & toplevel_consts_55_consts_7.ob_base.ob_base,
            & toplevel_consts_55_consts_8._object.ob_base.ob_base,
            & toplevel_consts_55_consts_9._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
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
toplevel_consts_55_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_7_consts_3_names_5._ascii.ob_base,
            & toplevel_consts_23_consts_9_name._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_21_names_1._ascii.ob_base,
            & toplevel_consts_33_names_14._ascii.ob_base,
            & toplevel_consts_23_consts_9_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_55_varnames_0 = {
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
    ._data = "globals",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_55_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_55_varnames_0._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_55_name = {
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
    ._data = "_calc___package__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_55_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07\x0c\x01\x04\x01\x0e\x01\x06\x01\x02\x01\x04\xff\x04\x01\x06\xff\x04\x02\x08\xfe\x04\x03\x04\x01\x06\x01\x06\x02\x04\x02\x08\xfe\x08\x03\x08\x01\x10\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[51];
    }
toplevel_consts_55_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 50,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x07\x0c\x01\x02\x01\x02\x0e\x02\xf3\x02\x03\x08\xfd\x02\x03\x02\xfe\x02\x02\x12\xff\x0c\x01\x04\x01\x02\x01\x02\x08\x06\xf9\x02\x02\x02\x02\x02\xff\x0c\x01\x08\x01\x06\x01\x12\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[147];
    }
toplevel_consts_55_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 146,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0f\x16\x0f\x29\x1b\x28\x0f\x29\x0f\x29\x05\x0c\x0c\x13\x0c\x23\x18\x22\x0c\x23\x0c\x23\x05\x09\x08\x0f\x05\x31\x0c\x10\x09\x38\x21\x28\x2c\x30\x2c\x37\x21\x37\x09\x38\x0d\x16\x0d\x38\x1c\x3f\x20\x27\x1c\x3f\x1c\x3f\x2f\x33\x2f\x3a\x1c\x3f\x1c\x3f\x1c\x3f\x1c\x29\x36\x37\x0d\x38\x0d\x38\x0d\x38\x0d\x38\x10\x17\x09\x17\x0a\x0e\x05\x31\x10\x14\x10\x1b\x09\x1b\x09\x12\x09\x34\x18\x3f\x18\x25\x32\x33\x09\x34\x09\x34\x09\x34\x09\x34\x13\x1a\x1b\x25\x13\x26\x09\x10\x0c\x16\x1e\x25\x0c\x25\x09\x31\x17\x1e\x17\x2e\x2a\x2d\x17\x2e\x17\x2e\x2f\x30\x17\x31\x0d\x14\x0c\x13\x05\x13",
};
static struct PyCodeObject toplevel_consts_55 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_55_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_55_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_55_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 7,
    .co_firstlineno = 1246,
    .co_code = & toplevel_consts_55_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_55_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_55_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_55_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_55_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_55_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_55_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 3,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_55_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[177];
    }
toplevel_consts_57_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 176,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x04\x64\x01\x6b\x02\x72\x0a\x74\x00\x7c\x00\xa9\x01\x7d\x05\x6e\x10\x7c\x01\x81\x0e\x7c\x01\x6e\x01\x69\x00\x7d\x06\x74\x01\x7c\x06\xa9\x01\x7d\x07\x74\x00\x7c\x00\x7c\x07\x7c\x04\xa9\x03\x7d\x05\x7c\x03\x73\x4b\x7c\x04\x64\x01\x6b\x02\x72\x2a\x74\x00\x7c\x00\xa0\x02\x64\x03\xa8\x01\xa9\x01\x64\x01\x19\x00\xa9\x01\x53\x00\x7c\x00\x73\x2e\x7c\x05\x53\x00\x74\x03\x7c\x00\xa9\x01\x74\x03\x7c\x00\xa0\x02\x64\x03\xa8\x01\xa9\x01\x64\x01\x19\x00\xa9\x01\x7a\x0a\x7d\x08\x74\x04\x6a\x05\x7c\x05\x6a\x06\x64\x02\x74\x03\x7c\x05\x6a\x06\xa9\x01\x7c\x08\x7a\x0a\x85\x02\x19\x00\x19\x00\x53\x00\x74\x07\x7c\x05\x64\x04\xa9\x02\x72\x56\x74\x08\x7c\x05\x7c\x03\x74\x00\xa9\x03\x53\x00\x7c\x05\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[472];
    }
toplevel_consts_57_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 471,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x49\x6d\x70\x6f\x72\x74\x20\x61\x20\x6d\x6f\x64\x75\x6c\x65\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x27\x67\x6c\x6f\x62\x61\x6c\x73\x27\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x69\x73\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x69\x6e\x66\x65\x72\x20\x77\x68\x65\x72\x65\x20\x74\x68\x65\x20\x69\x6d\x70\x6f\x72\x74\x20\x69\x73\x20\x6f\x63\x63\x75\x72\x72\x69\x6e\x67\x20\x66\x72\x6f\x6d\x0a\x20\x20\x20\x20\x74\x6f\x20\x68\x61\x6e\x64\x6c\x65\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x20\x69\x6d\x70\x6f\x72\x74\x73\x2e\x20\x54\x68\x65\x20\x27\x6c\x6f\x63\x61\x6c\x73\x27\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x69\x73\x20\x69\x67\x6e\x6f\x72\x65\x64\x2e\x20\x54\x68\x65\x0a\x20\x20\x20\x20\x27\x66\x72\x6f\x6d\x6c\x69\x73\x74\x27\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x73\x70\x65\x63\x69\x66\x69\x65\x73\x20\x77\x68\x61\x74\x20\x73\x68\x6f\x75\x6c\x64\x20\x65\x78\x69\x73\x74\x20\x61\x73\x20\x61\x74\x74\x72\x69\x62\x75\x74\x65\x73\x20\x6f\x6e\x20\x74\x68\x65\x20\x6d\x6f\x64\x75\x6c\x65\x0a\x20\x20\x20\x20\x62\x65\x69\x6e\x67\x20\x69\x6d\x70\x6f\x72\x74\x65\x64\x20\x28\x65\x2e\x67\x2e\x20\x60\x60\x66\x72\x6f\x6d\x20\x6d\x6f\x64\x75\x6c\x65\x20\x69\x6d\x70\x6f\x72\x74\x20\x3c\x66\x72\x6f\x6d\x6c\x69\x73\x74\x3e\x60\x60\x29\x2e\x20\x20\x54\x68\x65\x20\x27\x6c\x65\x76\x65\x6c\x27\x0a\x20\x20\x20\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x20\x72\x65\x70\x72\x65\x73\x65\x6e\x74\x73\x20\x74\x68\x65\x20\x70\x61\x63\x6b\x61\x67\x65\x20\x6c\x6f\x63\x61\x74\x69\x6f\x6e\x20\x74\x6f\x20\x69\x6d\x70\x6f\x72\x74\x20\x66\x72\x6f\x6d\x20\x69\x6e\x20\x61\x20\x72\x65\x6c\x61\x74\x69\x76\x65\x0a\x20\x20\x20\x20\x69\x6d\x70\x6f\x72\x74\x20\x28\x65\x2e\x67\x2e\x20\x60\x60\x66\x72\x6f\x6d\x20\x2e\x2e\x70\x6b\x67\x20\x69\x6d\x70\x6f\x72\x74\x20\x6d\x6f\x64\x60\x60\x20\x77\x6f\x75\x6c\x64\x20\x68\x61\x76\x65\x20\x61\x20\x27\x6c\x65\x76\x65\x6c\x27\x20\x6f\x66\x20\x32\x29\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_57_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_57_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            Py_None,
            & toplevel_consts_23_consts_9_consts_2._ascii.ob_base,
            & toplevel_consts_27_names_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_57_names_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_57_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_52_names_3._ascii.ob_base,
            & toplevel_consts_55_name._ascii.ob_base,
            & toplevel_consts_57_names_2._ascii.ob_base,
            & toplevel_consts_43_names_1._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_3_names_0._ascii.ob_base,
            & toplevel_consts_54_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_57_varnames_2 = {
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
    ._data = "locals",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_57_varnames_6 = {
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
    ._data = "globals_",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_57_varnames_8 = {
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
    ._data = "cut_off",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[9];
        }_object;
    }
toplevel_consts_57_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 9,
        },
        .ob_item = {
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_55_varnames_0._ascii.ob_base,
            & toplevel_consts_57_varnames_2._ascii.ob_base,
            & toplevel_consts_54_varnames_1._ascii.ob_base,
            & toplevel_consts_43_varnames_2._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_57_varnames_6._ascii.ob_base,
            & toplevel_consts_43_varnames_1._ascii.ob_base,
            & toplevel_consts_57_varnames_8._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_57_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[33];
    }
toplevel_consts_57_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 32,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x0b\x0a\x01\x0c\x02\x08\x01\x0c\x01\x04\x01\x08\x03\x14\x01\x04\x01\x04\x01\x1c\x04\x1e\x03\x0a\x01\x0c\x01\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_57_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x0b\x02\x05\x0a\xfc\x0c\x02\x08\x01\x0c\x01\x02\x01\x02\x11\x06\xf2\x02\x0a\x14\xf7\x02\x01\x02\x08\x04\xf9\x1c\x04\x1e\x03\x08\x01\x02\x03\x0c\xfe\x04\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[177];
    }
toplevel_consts_57_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 176,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x08\x0d\x11\x12\x08\x12\x05\x33\x12\x1d\x1e\x22\x12\x23\x09\x0f\x09\x0f\x1f\x26\x14\x3a\x14\x1b\x14\x1b\x38\x3a\x09\x11\x13\x24\x25\x2d\x13\x2e\x09\x10\x12\x1d\x1e\x22\x24\x2b\x2d\x32\x12\x33\x09\x0f\x0c\x14\x05\x16\x0c\x11\x15\x16\x0c\x16\x09\x4f\x14\x1f\x20\x24\x20\x33\x2f\x32\x20\x33\x20\x33\x34\x35\x20\x36\x14\x37\x0d\x37\x12\x16\x09\x4f\x14\x1a\x0d\x1a\x17\x1a\x1b\x1f\x17\x20\x23\x26\x27\x2b\x27\x3a\x36\x39\x27\x3a\x27\x3a\x3b\x3c\x27\x3d\x23\x3e\x17\x3e\x0d\x14\x14\x17\x14\x1f\x20\x26\x20\x2f\x30\x4d\x31\x34\x35\x3b\x35\x44\x31\x45\x46\x4d\x31\x4d\x30\x4d\x20\x4e\x14\x4f\x0d\x4f\x0a\x11\x12\x18\x1a\x24\x0a\x25\x05\x16\x10\x20\x21\x27\x29\x31\x33\x3e\x10\x3f\x09\x3f\x10\x16\x09\x16",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[10];
    }
toplevel_consts_57_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_57 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_57_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_57_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_57_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 5,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1273,
    .co_code = & toplevel_consts_57_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_57_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_57_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_57_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_57_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_57_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_57_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_57_columntable.ob_base.ob_base,
    .co_nlocalsplus = 9,
    .co_nlocals = 9,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_57_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_58_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\xa0\x01\x7c\x00\xa8\x01\xa9\x01\x7d\x01\x7c\x01\x80\x0f\x74\x02\x64\x01\x7c\x00\x7a\x00\xa9\x01\x82\x01\x74\x03\x7c\x01\xa9\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_58_consts_1 = {
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
    ._data = "no built-in module named ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_58_consts = {
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
            & toplevel_consts_58_consts_1._ascii.ob_base,
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
toplevel_consts_58_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_37_consts_5_name._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
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
toplevel_consts_58_varnames = {
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
            & toplevel_consts_21_varnames_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_58_name = {
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
    ._data = "_builtin_from_name",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_58_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x04\x01\x0c\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_58_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0c\x01\x02\x01\x0e\x01\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_58_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x1b\x0c\x2b\x26\x2a\x0c\x2b\x0c\x2b\x05\x09\x08\x0c\x05\x3e\x0f\x1a\x1b\x36\x39\x3d\x1b\x3d\x0f\x3e\x09\x3e\x0c\x1a\x1b\x1f\x0c\x20\x05\x20",
};
static struct PyCodeObject toplevel_consts_58 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_58_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_58_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_58_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1310,
    .co_code = & toplevel_consts_58_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_58_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_58_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_58_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_58_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_58_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_58_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_58_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[193];
    }
toplevel_consts_59_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 192,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x7c\x01\x61\x00\x7c\x00\x61\x01\x74\x02\x74\x01\xa9\x01\x7d\x02\x74\x01\x6a\x03\xa0\x04\xa8\x00\xa9\x00\x44\x00\x5d\x2f\x5c\x02\x7d\x03\x7d\x04\x74\x05\x7c\x04\x7c\x02\xa9\x02\x72\x3e\x7c\x03\x74\x01\x6a\x06\x76\x00\x72\x20\x74\x07\x7d\x05\x6e\x0a\x74\x00\xa0\x08\x7c\x03\xa8\x01\xa9\x01\x72\x29\x74\x09\x7d\x05\x6e\x01\x71\x0f\x74\x0a\x7c\x04\x7c\x05\xa9\x02\x7d\x06\x74\x0b\x7c\x06\x7c\x04\xa9\x02\x01\x00\x7c\x05\x74\x09\x75\x00\x72\x3e\x7c\x05\xa0\x0c\x7c\x04\xa8\x01\xa9\x01\x01\x00\x71\x0f\x74\x01\x6a\x03\x74\x0d\x19\x00\x7d\x07\x64\x01\x44\x00\x5d\x17\x7d\x08\x7c\x08\x74\x01\x6a\x03\x76\x01\x72\x52\x74\x0e\x7c\x08\xa9\x01\x7d\x09\x6e\x05\x74\x01\x6a\x03\x7c\x08\x19\x00\x7d\x09\x74\x0f\x7c\x07\x7c\x08\x7c\x09\xa9\x03\x01\x00\x71\x46\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[251];
    }
toplevel_consts_59_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 250,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x53\x65\x74\x75\x70\x20\x69\x6d\x70\x6f\x72\x74\x6c\x69\x62\x20\x62\x79\x20\x69\x6d\x70\x6f\x72\x74\x69\x6e\x67\x20\x6e\x65\x65\x64\x65\x64\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x61\x6e\x64\x20\x69\x6e\x6a\x65\x63\x74\x69\x6e\x67\x20\x74\x68\x65\x6d\x0a\x20\x20\x20\x20\x69\x6e\x74\x6f\x20\x74\x68\x65\x20\x67\x6c\x6f\x62\x61\x6c\x20\x6e\x61\x6d\x65\x73\x70\x61\x63\x65\x2e\x0a\x0a\x20\x20\x20\x20\x41\x73\x20\x73\x79\x73\x20\x69\x73\x20\x6e\x65\x65\x64\x65\x64\x20\x66\x6f\x72\x20\x73\x79\x73\x2e\x6d\x6f\x64\x75\x6c\x65\x73\x20\x61\x63\x63\x65\x73\x73\x20\x61\x6e\x64\x20\x5f\x69\x6d\x70\x20\x69\x73\x20\x6e\x65\x65\x64\x65\x64\x20\x74\x6f\x20\x6c\x6f\x61\x64\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x0a\x20\x20\x20\x20\x6d\x6f\x64\x75\x6c\x65\x73\x2c\x20\x74\x68\x6f\x73\x65\x20\x74\x77\x6f\x20\x6d\x6f\x64\x75\x6c\x65\x73\x20\x6d\x75\x73\x74\x20\x62\x65\x20\x65\x78\x70\x6c\x69\x63\x69\x74\x6c\x79\x20\x70\x61\x73\x73\x65\x64\x20\x69\x6e\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_59_consts_1 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_13_names_7._ascii.ob_base,
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
toplevel_consts_59_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_59_consts_0._ascii.ob_base,
            & toplevel_consts_59_consts_1._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_59_names_4 = {
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
            PyObject *ob_item[16];
        }_object;
    }
toplevel_consts_59_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 16,
        },
        .ob_item = {
            & toplevel_consts_13_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_1_names_2._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_59_names_4._ascii.ob_base,
            & toplevel_consts_46_names_0._ascii.ob_base,
            & toplevel_consts_19_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_20_consts_1_names_1._ascii.ob_base,
            & toplevel_consts_39_consts_0._ascii.ob_base,
            & toplevel_consts_27_name._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
            & toplevel_consts_39_consts_4_name._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
            & toplevel_consts_58_name._ascii.ob_base,
            & toplevel_consts_3_names_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_59_varnames_0 = {
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
    ._data = "sys_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_59_varnames_1 = {
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
    ._data = "_imp_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_59_varnames_2 = {
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
    ._data = "module_type",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_consts_59_varnames_7 = {
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
    ._data = "self_module",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_59_varnames_8 = {
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
    ._data = "builtin_name",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_59_varnames_9 = {
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
    ._data = "builtin_module",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_59_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_59_varnames_0._ascii.ob_base,
            & toplevel_consts_59_varnames_1._ascii.ob_base,
            & toplevel_consts_59_varnames_2._ascii.ob_base,
            & toplevel_consts_4_varnames_0._ascii.ob_base,
            & toplevel_consts_21_varnames_4._ascii.ob_base,
            & toplevel_consts_22_varnames_1._ascii.ob_base,
            & toplevel_consts_21_varnames_3._ascii.ob_base,
            & toplevel_consts_59_varnames_7._ascii.ob_base,
            & toplevel_consts_59_varnames_8._ascii.ob_base,
            & toplevel_consts_59_varnames_9._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_59_name = {
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
    ._data = "_setup",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_59_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x09\x04\x01\x08\x03\x14\x01\x0a\x01\x0a\x01\x06\x01\x0c\x01\x06\x01\x02\x02\x0a\x01\x0a\x01\x08\x01\x0c\x01\x02\x80\x0a\x03\x08\x01\x0a\x01\x0a\x01\x0a\x02\x0e\x01\x04\xfb",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[61];
    }
toplevel_consts_59_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 60,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x04\x09\x04\x01\x08\x03\x0a\x01\x04\x0b\x06\xf5\x08\x01\x02\x0a\x08\xf7\x02\x05\x06\xfc\x0a\x01\x02\x03\x06\xfe\x02\x02\x0a\x01\x0a\x01\x06\x01\x0e\x01\x02\x80\x0a\x03\x02\x01\x04\x05\x02\xfb\x08\x01\x02\x03\x0a\xfe\x0a\x02\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[193];
    }
toplevel_consts_59_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 192,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x17\x05\x09\x0b\x15\x05\x08\x13\x17\x18\x1b\x13\x1c\x05\x10\x19\x1c\x19\x24\x19\x2c\x19\x2c\x19\x2c\x05\x2e\x05\x2e\x09\x15\x09\x0d\x0f\x15\x0c\x16\x17\x1d\x1f\x2a\x0c\x2b\x09\x2e\x10\x14\x18\x1b\x18\x30\x10\x30\x0d\x19\x1a\x29\x11\x17\x11\x17\x12\x16\x12\x26\x21\x25\x12\x26\x12\x26\x0d\x19\x1a\x28\x11\x17\x11\x17\x11\x19\x14\x25\x26\x2c\x2e\x34\x14\x35\x0d\x11\x0d\x1f\x20\x24\x26\x2c\x0d\x2d\x0d\x2d\x10\x16\x1a\x28\x10\x28\x0d\x2e\x11\x17\x11\x2e\x27\x2d\x11\x2e\x11\x2e\x11\x2e\x00\x00\x13\x16\x13\x1e\x1f\x27\x13\x28\x05\x10\x19\x3d\x05\x3b\x05\x3b\x09\x15\x0c\x18\x20\x23\x20\x2b\x0c\x2b\x09\x37\x1e\x30\x31\x3d\x1e\x3e\x0d\x1b\x0d\x1b\x1e\x21\x1e\x29\x2a\x36\x1e\x37\x0d\x1b\x09\x10\x11\x1c\x1e\x2a\x2c\x3a\x09\x3b\x09\x3b\x09\x3b\x05\x3b\x05\x3b",
};
static struct PyCodeObject toplevel_consts_59 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_59_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_59_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_59_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 1317,
    .co_code = & toplevel_consts_59_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_59_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_39_consts_4_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_59_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_59_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_59_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_59_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_59_columntable.ob_base.ob_base,
    .co_nlocalsplus = 10,
    .co_nlocals = 10,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_59_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_60_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\xa9\x02\x01\x00\x74\x01\x6a\x02\xa0\x03\x74\x04\xa8\x01\xa9\x01\x01\x00\x74\x01\x6a\x02\xa0\x03\x74\x05\xa8\x01\xa9\x01\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[49];
    }
toplevel_consts_60_consts_0 = {
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
    ._data = "Install importers for builtin and frozen modules",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_60_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_60_consts_0._ascii.ob_base,
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
toplevel_consts_60_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_59_name._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_45_names_1._ascii.ob_base,
            & toplevel_consts_23_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_39_consts_0._ascii.ob_base,
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
toplevel_consts_60_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_59_varnames_0._ascii.ob_base,
            & toplevel_consts_59_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_60_name = {
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
    ._data = "_install",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_60_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x02\x0e\x02\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[45];
    }
toplevel_consts_60_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 44,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x0b\x0c\x16\x18\x23\x05\x24\x05\x24\x05\x08\x05\x12\x05\x2a\x1a\x29\x05\x2a\x05\x2a\x05\x2a\x05\x08\x05\x12\x05\x29\x1a\x28\x05\x29\x05\x29\x05\x29\x05\x29\x05\x29",
};
static struct PyCodeObject toplevel_consts_60 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_60_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_60_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_60_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 1354,
    .co_code = & toplevel_consts_60_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_60_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_7_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_60_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_60_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_60_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_60_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_60_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_60_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_61_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x64\x02\x6c\x00\x7d\x00\x7c\x00\x61\x01\x7c\x00\xa0\x02\x74\x03\x6a\x04\x74\x05\x19\x00\xa8\x01\xa9\x01\x01\x00\x64\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[58];
    }
toplevel_consts_61_consts_0 = {
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
    ._data = "Install importers that require external filesystem access",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_61_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_61_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[27];
    }
toplevel_consts_61_names_0 = {
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
    ._data = "_frozen_importlib_external",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_61_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_61_names_0._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_60_name._ascii.ob_base,
            & toplevel_consts_4_names_1._ascii.ob_base,
            & toplevel_consts_21_names_5._ascii.ob_base,
            & toplevel_consts_3_consts_1_1._ascii.ob_base,
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
toplevel_consts_61_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_61_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_61_name = {
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
    ._data = "_install_external_importers",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_61_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x03\x04\x01\x16\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[37];
    }
toplevel_consts_61_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 36,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x05\x26\x05\x26\x05\x26\x05\x26\x1b\x35\x05\x18\x05\x1f\x05\x3f\x29\x2c\x29\x34\x35\x3d\x29\x3e\x05\x3f\x05\x3f\x05\x3f\x05\x3f\x05\x3f",
};
static struct PyCodeObject toplevel_consts_61 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_61_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_61_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_61_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1362,
    .co_code = & toplevel_consts_61_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_61_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_61_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_61_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_61_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_61_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_61_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_61_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_65 = {
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
            Py_None,
            & toplevel_consts_1_freevars._object.ob_base.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[66];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 66,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base,
            Py_None,
            & toplevel_consts_3.ob_base,
            & toplevel_consts_4.ob_base,
            & toplevel_consts_5.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_9.ob_base,
            & toplevel_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_11.ob_base,
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_13.ob_base,
            & toplevel_consts_14.ob_base,
            & toplevel_consts_15.ob_base,
            & toplevel_consts_7_consts_4_consts_3.ob_base.ob_base,
            & toplevel_consts_17._object.ob_base.ob_base,
            & toplevel_consts_18.ob_base,
            & toplevel_consts_19.ob_base,
            & toplevel_consts_20.ob_base,
            & toplevel_consts_21.ob_base,
            & toplevel_consts_22.ob_base,
            & toplevel_consts_23.ob_base,
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_25._object.ob_base.ob_base,
            & toplevel_consts_26.ob_base,
            & toplevel_consts_27.ob_base,
            Py_False,
            & toplevel_consts_29._object.ob_base.ob_base,
            & toplevel_consts_30.ob_base,
            & toplevel_consts_31.ob_base,
            & toplevel_consts_32.ob_base,
            & toplevel_consts_33.ob_base,
            & toplevel_consts_34.ob_base,
            & toplevel_consts_35.ob_base,
            & toplevel_consts_36.ob_base,
            & toplevel_consts_37.ob_base,
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_39.ob_base,
            & toplevel_consts_39_consts_0._ascii.ob_base,
            & toplevel_consts_41.ob_base,
            & toplevel_consts_41_consts_0._ascii.ob_base,
            & toplevel_consts_43.ob_base,
            & toplevel_consts_44.ob_base,
            & toplevel_consts_45.ob_base,
            & toplevel_consts_46.ob_base,
            & toplevel_consts_47._ascii.ob_base,
            & toplevel_consts_48._ascii.ob_base,
            & toplevel_consts_49.ob_base,
            & toplevel_consts_50.ob_base,
            & toplevel_consts_7_consts_2_consts_1.ob_base.ob_base,
            & toplevel_consts_52.ob_base,
            & toplevel_consts_53._object.ob_base.ob_base,
            & toplevel_consts_54.ob_base,
            & toplevel_consts_55.ob_base,
            & toplevel_consts_1_freevars._object.ob_base.ob_base,
            & toplevel_consts_57.ob_base,
            & toplevel_consts_58.ob_base,
            & toplevel_consts_59.ob_base,
            & toplevel_consts_60.ob_base,
            & toplevel_consts_61.ob_base,
            & toplevel_consts_37_consts_12._object.ob_base.ob_base,
            & toplevel_consts_1_consts._object.ob_base.ob_base,
            & toplevel_consts_7_consts_2_consts._object.ob_base.ob_base,
            & toplevel_consts_65._object.ob_base.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_names_40 = {
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
    ._data = "_ERR_MSG_PREFIX",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_names_43 = {
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
            PyObject *ob_item[54];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 54,
        },
        .ob_item = {
            & toplevel_consts_3_consts_1_3._ascii.ob_base,
            & toplevel_consts_1_name._ascii.ob_base,
            & toplevel_consts_7_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_21_names_0._ascii.ob_base,
            & toplevel_consts_13_names_7._ascii.ob_base,
            & toplevel_consts_23_consts_7_names_3._ascii.ob_base,
            & toplevel_consts_3_name._ascii.ob_base,
            & toplevel_consts_4_name._ascii.ob_base,
            & toplevel_consts_13_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_7_consts_3_names_4._ascii.ob_base,
            & toplevel_consts_7_consts_5_names_4._ascii.ob_base,
            & toplevel_consts_5_consts_0._ascii.ob_base,
            & toplevel_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_9_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_0._ascii.ob_base,
            & toplevel_consts_11_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_15_name._ascii.ob_base,
            & toplevel_consts_18_name._ascii.ob_base,
            & toplevel_consts_19_name._ascii.ob_base,
            & toplevel_consts_20_name._ascii.ob_base,
            & toplevel_consts_21_name._ascii.ob_base,
            & toplevel_consts_22_name._ascii.ob_base,
            & toplevel_consts_23_consts_0._ascii.ob_base,
            & toplevel_consts_21_names_3._ascii.ob_base,
            & toplevel_consts_27_name._ascii.ob_base,
            & toplevel_consts_30_name._ascii.ob_base,
            & toplevel_consts_31_name._ascii.ob_base,
            & toplevel_consts_22_names_1._ascii.ob_base,
            & toplevel_consts_21_names_6._ascii.ob_base,
            & toplevel_consts_34_name._ascii.ob_base,
            & toplevel_consts_35_name._ascii.ob_base,
            & toplevel_consts_21_names_7._ascii.ob_base,
            & toplevel_consts_37_consts_0._ascii.ob_base,
            & toplevel_consts_39_consts_0._ascii.ob_base,
            & toplevel_consts_41_consts_0._ascii.ob_base,
            & toplevel_consts_43_name._ascii.ob_base,
            & toplevel_consts_44_name._ascii.ob_base,
            & toplevel_consts_45_name._ascii.ob_base,
            & toplevel_consts_46_name._ascii.ob_base,
            & toplevel_names_40._ascii.ob_base,
            & toplevel_consts_49_names_6._ascii.ob_base,
            & toplevel_consts_49_name._ascii.ob_base,
            & toplevel_names_43._ascii.ob_base,
            & toplevel_consts_50_names_3._ascii.ob_base,
            & toplevel_consts_50_name._ascii.ob_base,
            & toplevel_consts_52_names_3._ascii.ob_base,
            & toplevel_consts_54_names_6._ascii.ob_base,
            & toplevel_consts_55_name._ascii.ob_base,
            & toplevel_consts_57_name._ascii.ob_base,
            & toplevel_consts_58_name._ascii.ob_base,
            & toplevel_consts_59_name._ascii.ob_base,
            & toplevel_consts_60_name._ascii.ob_base,
            & toplevel_consts_61_name._ascii.ob_base,
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
        char ob_sval[109];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 108,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x00\x06\x16\x04\x09\x04\x01\x04\x01\x04\x03\x06\x03\x06\x08\x04\x08\x04\x02\x0e\x03\x0c\x04\x0c\x4d\x0c\x15\x06\x10\x06\x25\x06\x11\x0c\x0b\x06\x08\x06\x0b\x06\x0c\x06\x13\x0c\x1a\x0e\x66\x08\x1d\x0c\x2a\x06\x49\x06\x11\x06\x11\x06\x1e\x06\x24\x06\x2d\x0c\x0f\x0c\x50\x00\x7f\x0c\x5b\x06\x0d\x06\x09\x08\x0a\x06\x2f\x04\x10\x08\x01\x06\x02\x06\x2a\x06\x03\x08\x1b\x0c\x0f\x06\x25\x08\x1b\x06\x25\x06\x07\x06\x25\x0a\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[129];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 128,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x07\x06\x13\x04\x05\x04\x01\x04\x01\x04\x03\x06\x08\x06\x04\x04\x07\x04\x02\x08\x04\x02\xff\x04\x01\x0c\x4d\x0c\x15\x0c\x0e\x06\x27\x06\x11\x06\x0b\x02\x03\x0a\x05\x06\x0b\x06\x0b\x06\x13\x06\x1b\x0c\x66\x04\x03\x0a\x1a\x02\x03\x06\x27\x02\x03\x0a\x46\x06\x11\x06\x10\x06\x1f\x06\x25\x06\x2b\x06\x0e\x0c\x52\x00\x7f\x0c\x59\x0c\x0f\x06\x09\x06\x0a\x02\x03\x06\x2c\x06\x10\x04\x03\x08\x01\x06\x29\x06\x03\x06\x1b\x02\x03\x06\x0c\x02\x03\x0a\x22\x06\x1b\x02\x03\x06\x22\x06\x07\x06\x25\x06\x08\x0a\x08",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[389];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 388,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x04\x01\x04\x01\x26\x01\x26\x01\x26\x0b\x0f\x01\x08\x0d\x11\x01\x0a\x0c\x10\x01\x09\x17\x1b\x01\x14\x01\x26\x01\x26\x01\x26\x01\x1b\x01\x1b\x01\x1b\x11\x13\x01\x0e\x10\x12\x01\x0d\x01\x09\x01\x09\x01\x09\x01\x09\x16\x22\x01\x09\x01\x09\x01\x45\x01\x45\x01\x45\x01\x45\x01\x45\x01\x45\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x1d\x01\x1d\x01\x1d\x01\x1d\x01\x1d\x01\x1d\x01\x10\x01\x10\x01\x10\x01\x17\x01\x17\x01\x17\x01\x1c\x01\x1c\x01\x1c\x30\x31\x01\x36\x01\x36\x01\x36\x01\x36\x01\x36\x01\x25\x01\x25\x01\x25\x01\x24\x01\x24\x01\x24\x01\x1b\x01\x1b\x01\x1b\x01\x40\x01\x40\x01\x40\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x01\x29\x2e\x32\x3f\x43\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x01\x4a\x26\x2a\x01\x10\x01\x10\x01\x10\x32\x37\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x47\x01\x47\x01\x47\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x24\x01\x24\x01\x24\x01\x31\x01\x31\x01\x31\x01\x31\x01\x31\x01\x31\x01\x30\x01\x30\x01\x30\x01\x30\x01\x30\x01\x30\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x1c\x01\x38\x01\x38\x01\x38\x01\x2a\x01\x2a\x01\x2a\x23\x27\x01\x14\x01\x14\x01\x14\x01\x2e\x01\x2e\x01\x2e\x13\x25\x01\x10\x0c\x1b\x1e\x24\x0c\x24\x01\x09\x01\x12\x01\x12\x01\x12\x12\x18\x12\x1a\x01\x0f\x01\x12\x01\x12\x01\x12\x1f\x23\x01\x2d\x01\x2d\x01\x2d\x3e\x43\x01\x12\x01\x12\x01\x12\x01\x12\x01\x12\x01\x13\x01\x13\x01\x13\x1e\x22\x01\x16\x01\x16\x01\x16\x01\x20\x01\x20\x01\x20\x01\x3b\x01\x3b\x01\x3b\x01\x29\x01\x29\x01\x29\x01\x3f\x01\x3f\x01\x3f\x01\x3f\x01\x3f",
};
static struct PyCodeObject toplevel = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts._object.ob_base.ob_base,
    .co_names = & toplevel_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 4,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_3_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
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
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};

static void do_patchups(void) {
}

PyObject *
_Py_get_importlib__bootstrap_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

