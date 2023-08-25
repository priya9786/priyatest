#include "Python.h"
#include "internal/pycore_gc.h"
#include "internal/pycore_code.h"

static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[181];
    }
toplevel_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 180,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x00\x5a\x00\x64\x01\x84\x00\x5a\x01\x47\x00\x64\x02\x84\x00\x64\x03\x65\x02\xa9\x03\x5a\x03\x47\x00\x64\x04\x84\x00\x64\x05\x65\x04\xa9\x03\x5a\x05\x47\x00\x64\x06\x84\x00\x64\x07\x65\x06\xa9\x03\x5a\x07\x09\x00\x64\x08\x64\x09\x6c\x08\x6d\x09\x5a\x09\x6d\x0a\x5a\x0a\x6d\x0b\x5a\x0b\x6d\x0c\x5a\x0c\x6d\x0d\x5a\x0d\x6d\x0e\x5a\x0e\x6d\x0f\x5a\x0f\x6d\x10\x5a\x10\x01\x00\x6e\x15\x23\x00\x65\x11\x79\x42\x01\x00\x64\x08\x64\x0a\x6c\x12\x6d\x13\x5a\x13\x6d\x09\x5a\x09\x01\x00\x64\x0b\x65\x13\x5f\x14\x59\x00\x6e\x0b\x77\x00\x78\x03\x59\x00\x77\x01\x47\x00\x64\x0c\x84\x00\x64\x0d\x65\x15\xa9\x03\x5a\x13\x64\x0e\x84\x00\x5a\x16\x47\x00\x64\x0f\x84\x00\x64\x10\x65\x13\x64\x11\xaa\x03\x5a\x17\x64\x12\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[52];
    }
toplevel_consts_0 = {
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
    ._data = "Abstract Base Classes (ABCs) according to PEP 3119.",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_1_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x64\x01\x7c\x00\x5f\x00\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[573];
    }
toplevel_consts_1_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 572,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x69\x6e\x64\x69\x63\x61\x74\x69\x6e\x67\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x2e\x0a\x0a\x20\x20\x20\x20\x52\x65\x71\x75\x69\x72\x65\x73\x20\x74\x68\x61\x74\x20\x74\x68\x65\x20\x6d\x65\x74\x61\x63\x6c\x61\x73\x73\x20\x69\x73\x20\x41\x42\x43\x4d\x65\x74\x61\x20\x6f\x72\x20\x64\x65\x72\x69\x76\x65\x64\x20\x66\x72\x6f\x6d\x20\x69\x74\x2e\x20\x20\x41\x0a\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x74\x68\x61\x74\x20\x68\x61\x73\x20\x61\x20\x6d\x65\x74\x61\x63\x6c\x61\x73\x73\x20\x64\x65\x72\x69\x76\x65\x64\x20\x66\x72\x6f\x6d\x20\x41\x42\x43\x4d\x65\x74\x61\x20\x63\x61\x6e\x6e\x6f\x74\x20\x62\x65\x0a\x20\x20\x20\x20\x69\x6e\x73\x74\x61\x6e\x74\x69\x61\x74\x65\x64\x20\x75\x6e\x6c\x65\x73\x73\x20\x61\x6c\x6c\x20\x6f\x66\x20\x69\x74\x73\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x61\x72\x65\x20\x6f\x76\x65\x72\x72\x69\x64\x64\x65\x6e\x2e\x0a\x20\x20\x20\x20\x54\x68\x65\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x63\x61\x6e\x20\x62\x65\x20\x63\x61\x6c\x6c\x65\x64\x20\x75\x73\x69\x6e\x67\x20\x61\x6e\x79\x20\x6f\x66\x20\x74\x68\x65\x20\x6e\x6f\x72\x6d\x61\x6c\x0a\x20\x20\x20\x20\x27\x73\x75\x70\x65\x72\x27\x20\x63\x61\x6c\x6c\x20\x6d\x65\x63\x68\x61\x6e\x69\x73\x6d\x73\x2e\x20\x20\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x28\x29\x20\x6d\x61\x79\x20\x62\x65\x20\x75\x73\x65\x64\x20\x74\x6f\x20\x64\x65\x63\x6c\x61\x72\x65\x0a\x20\x20\x20\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x66\x6f\x72\x20\x70\x72\x6f\x70\x65\x72\x74\x69\x65\x73\x20\x61\x6e\x64\x20\x64\x65\x73\x63\x72\x69\x70\x74\x6f\x72\x73\x2e\x0a\x0a\x20\x20\x20\x20\x55\x73\x61\x67\x65\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x43\x28\x6d\x65\x74\x61\x63\x6c\x61\x73\x73\x3d\x41\x42\x43\x4d\x65\x74\x61\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x20\x6d\x79\x5f\x61\x62\x73\x74\x72\x61\x63\x74\x5f\x6d\x65\x74\x68\x6f\x64\x28\x73\x65\x6c\x66\x2c\x20\x2e\x2e\x2e\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x2e\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_1_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_1_consts_0._ascii.ob_base,
            Py_True,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_1_names_0 = {
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
    ._data = "__isabstractmethod__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_1_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_1_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_1_varnames_0 = {
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
    ._data = "funcobj",
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
        uint8_t _data[13];
    }
toplevel_consts_1_filename = {
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
    ._data = "<frozen abc>",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_1_name = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_1_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x06\x11\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_1_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x24\x28\x05\x0c\x05\x21\x0c\x13\x05\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[1];
    }
toplevel_consts_1_exceptiontable = {
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
    .co_stacksize = 2,
    .co_firstlineno = 7,
    .co_code = & toplevel_consts_1_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_1_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_1_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_1_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_1_linetable.ob_base.ob_base,
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
        char ob_sval[39];
    }
toplevel_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x64\x02\x5a\x04\x88\x00\x66\x01\x64\x03\x84\x08\x5a\x05\x88\x00\x04\x00\x5a\x06\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_2_consts_0 = {
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
    ._data = "abstractclassmethod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[265];
    }
toplevel_consts_2_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 264,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x69\x6e\x64\x69\x63\x61\x74\x69\x6e\x67\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x63\x6c\x61\x73\x73\x6d\x65\x74\x68\x6f\x64\x73\x2e\x0a\x0a\x20\x20\x20\x20\x44\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2c\x20\x75\x73\x65\x20\x27\x63\x6c\x61\x73\x73\x6d\x65\x74\x68\x6f\x64\x27\x20\x77\x69\x74\x68\x20\x27\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x27\x20\x69\x6e\x73\x74\x65\x61\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x43\x28\x41\x42\x43\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x63\x6c\x61\x73\x73\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x20\x6d\x79\x5f\x61\x62\x73\x74\x72\x61\x63\x74\x5f\x63\x6c\x61\x73\x73\x6d\x65\x74\x68\x6f\x64\x28\x63\x6c\x73\x2c\x20\x2e\x2e\x2e\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x2e\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_2_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x64\x01\x7c\x01\x5f\x00\x74\x01\xa9\x00\xa0\x02\x7c\x01\xa8\x01\xa9\x01\x01\x00\x64\x00\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_2_consts_3_consts = {
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
        uint8_t _data[6];
    }
toplevel_consts_2_consts_3_names_1 = {
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
        uint8_t _data[9];
    }
toplevel_consts_2_consts_3_names_2 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_2_consts_3_names = {
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
            & toplevel_consts_2_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_2_consts_3_names_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_2_consts_3_varnames_0 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_2_consts_3_varnames_1 = {
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
    ._data = "callable",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_2_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_2_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_2_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_2_consts_3_freevars_0 = {
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
toplevel_consts_2_consts_3_freevars = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_2_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[29];
    }
toplevel_consts_2_consts_3_qualname = {
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
    ._data = "abstractclassmethod.__init__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[9];
    }
toplevel_consts_2_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 8,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x06\x01\x12\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[29];
    }
toplevel_consts_2_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 28,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x29\x2d\x09\x11\x09\x26\x09\x0e\x09\x10\x09\x23\x1a\x22\x09\x23\x09\x23\x09\x23\x09\x23\x09\x23",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_2_consts_3_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_2_consts_3_varnames_0._ascii.ob_base,
            & toplevel_consts_2_consts_3_varnames_1._ascii.ob_base,
            & toplevel_consts_2_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[4];
    }
toplevel_consts_2_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_2_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_2_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_2_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_2_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 43,
    .co_code = & toplevel_consts_2_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_2_consts_3_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_2_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_consts_3_names_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_2_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_2_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_2_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_2_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_2_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_2_consts_0._ascii.ob_base,
            & toplevel_consts_2_consts_1._ascii.ob_base,
            Py_True,
            & toplevel_consts_2_consts_3.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_2_names_0 = {
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
toplevel_consts_2_names_1 = {
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
toplevel_consts_2_names_2 = {
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
toplevel_consts_2_names_3 = {
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
        uint8_t _data[14];
    }
toplevel_consts_2_names_6 = {
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
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
            & toplevel_consts_2_consts_3_names_2._ascii.ob_base,
            & toplevel_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x01\x04\x0c\x12\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_2_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x0b\x04\x02\x12\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[39];
    }
toplevel_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 38,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1c\x20\x05\x19\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23\x05\x23",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[2];
    }
toplevel_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 28,
    .co_code = & toplevel_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_2_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 0,
    .co_nplaincellvars = 1,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[21];
    }
toplevel_consts_4_consts_0 = {
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
    ._data = "abstractstaticmethod",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[264];
    }
toplevel_consts_4_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 263,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x69\x6e\x64\x69\x63\x61\x74\x69\x6e\x67\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x73\x74\x61\x74\x69\x63\x6d\x65\x74\x68\x6f\x64\x73\x2e\x0a\x0a\x20\x20\x20\x20\x44\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2c\x20\x75\x73\x65\x20\x27\x73\x74\x61\x74\x69\x63\x6d\x65\x74\x68\x6f\x64\x27\x20\x77\x69\x74\x68\x20\x27\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x27\x20\x69\x6e\x73\x74\x65\x61\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x43\x28\x41\x42\x43\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x73\x74\x61\x74\x69\x63\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x20\x6d\x79\x5f\x61\x62\x73\x74\x72\x61\x63\x74\x5f\x73\x74\x61\x74\x69\x63\x6d\x65\x74\x68\x6f\x64\x28\x2e\x2e\x2e\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x2e\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_4_consts_3_qualname = {
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
    ._data = "abstractstaticmethod.__init__",
};
static struct PyCodeObject toplevel_consts_4_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_2_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_2_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_2_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 63,
    .co_code = & toplevel_consts_2_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_2_consts_3_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_2_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_2_consts_3_names_2._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_2_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_2_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_2_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 3,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_2_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_4_consts_0._ascii.ob_base,
            & toplevel_consts_4_consts_1._ascii.ob_base,
            Py_True,
            & toplevel_consts_4_consts_3.ob_base,
        },
    },
};
static struct PyCodeObject toplevel_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 48,
    .co_code = & toplevel_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_4_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_4_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_2_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 0,
    .co_nplaincellvars = 1,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_6_code = {
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
        uint8_t _data[17];
    }
toplevel_consts_6_consts_0 = {
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
    ._data = "abstractproperty",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[250];
    }
toplevel_consts_6_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 249,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x41\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x20\x69\x6e\x64\x69\x63\x61\x74\x69\x6e\x67\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x70\x72\x6f\x70\x65\x72\x74\x69\x65\x73\x2e\x0a\x0a\x20\x20\x20\x20\x44\x65\x70\x72\x65\x63\x61\x74\x65\x64\x2c\x20\x75\x73\x65\x20\x27\x70\x72\x6f\x70\x65\x72\x74\x79\x27\x20\x77\x69\x74\x68\x20\x27\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x27\x20\x69\x6e\x73\x74\x65\x61\x64\x3a\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x43\x28\x41\x42\x43\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x70\x72\x6f\x70\x65\x72\x74\x79\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x40\x61\x62\x73\x74\x72\x61\x63\x74\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x66\x20\x6d\x79\x5f\x61\x62\x73\x74\x72\x61\x63\x74\x5f\x70\x72\x6f\x70\x65\x72\x74\x79\x28\x73\x65\x6c\x66\x29\x3a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x2e\x2e\x2e\x0a\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[4];
        }_object;
    }
toplevel_consts_6_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 4,
        },
        .ob_item = {
            & toplevel_consts_6_consts_0._ascii.ob_base,
            & toplevel_consts_6_consts_1._ascii.ob_base,
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
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_6_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_1_names_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_6_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x0c",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_6_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x0b\x08\x02",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_6_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x05\x08\x05\x08\x1c\x20\x05\x19\x05\x19\x05\x19",
};
static struct PyCodeObject toplevel_consts_6 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_6_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_6_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 68,
    .co_code = & toplevel_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_6_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_6_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_6_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_6_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_6_columntable.ob_base.ob_base,
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
        uint8_t _data[16];
    }
toplevel_consts_9_0 = {
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
    ._data = "get_cache_token",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_9_1 = {
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
    ._data = "_abc_init",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_9_2 = {
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
    ._data = "_abc_register",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_9_3 = {
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
    ._data = "_abc_instancecheck",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[19];
    }
toplevel_consts_9_4 = {
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
    ._data = "_abc_subclasscheck",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_9_5 = {
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
    ._data = "_get_dump",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_9_6 = {
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
    ._data = "_reset_registry",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_9_7 = {
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
    ._data = "_reset_caches",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[8];
        }_object;
    }
toplevel_consts_9 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 8,
        },
        .ob_item = {
            & toplevel_consts_9_0._ascii.ob_base,
            & toplevel_consts_9_1._ascii.ob_base,
            & toplevel_consts_9_2._ascii.ob_base,
            & toplevel_consts_9_3._ascii.ob_base,
            & toplevel_consts_9_4._ascii.ob_base,
            & toplevel_consts_9_5._ascii.ob_base,
            & toplevel_consts_9_6._ascii.ob_base,
            & toplevel_consts_9_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_10_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_10 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_9_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_11 = {
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
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_12_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x87\x00\x97\x00\x65\x00\x5a\x01\x64\x00\x5a\x02\x64\x01\x5a\x03\x88\x00\x66\x01\x64\x02\x84\x08\x5a\x04\x64\x03\x84\x00\x5a\x05\x64\x04\x84\x00\x5a\x06\x64\x05\x84\x00\x5a\x07\x64\x0a\x64\x07\x84\x01\x5a\x08\x64\x08\x84\x00\x5a\x09\x64\x09\x84\x00\x5a\x0a\x88\x00\x04\x00\x5a\x0b\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[657];
    }
toplevel_consts_12_consts_1 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 656,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x4d\x65\x74\x61\x63\x6c\x61\x73\x73\x20\x66\x6f\x72\x20\x64\x65\x66\x69\x6e\x69\x6e\x67\x20\x41\x62\x73\x74\x72\x61\x63\x74\x20\x42\x61\x73\x65\x20\x43\x6c\x61\x73\x73\x65\x73\x20\x28\x41\x42\x43\x73\x29\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x55\x73\x65\x20\x74\x68\x69\x73\x20\x6d\x65\x74\x61\x63\x6c\x61\x73\x73\x20\x74\x6f\x20\x63\x72\x65\x61\x74\x65\x20\x61\x6e\x20\x41\x42\x43\x2e\x20\x20\x41\x6e\x20\x41\x42\x43\x20\x63\x61\x6e\x20\x62\x65\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x64\x69\x72\x65\x63\x74\x6c\x79\x2c\x20\x61\x6e\x64\x20\x74\x68\x65\x6e\x20\x61\x63\x74\x73\x20\x61\x73\x20\x61\x20\x6d\x69\x78\x2d\x69\x6e\x20\x63\x6c\x61\x73\x73\x2e\x20\x20\x59\x6f\x75\x20\x63\x61\x6e\x20\x61\x6c\x73\x6f\x20\x72\x65\x67\x69\x73\x74\x65\x72\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x75\x6e\x72\x65\x6c\x61\x74\x65\x64\x20\x63\x6f\x6e\x63\x72\x65\x74\x65\x20\x63\x6c\x61\x73\x73\x65\x73\x20\x28\x65\x76\x65\x6e\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x20\x63\x6c\x61\x73\x73\x65\x73\x29\x20\x61\x6e\x64\x20\x75\x6e\x72\x65\x6c\x61\x74\x65\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x41\x42\x43\x73\x20\x61\x73\x20\x27\x76\x69\x72\x74\x75\x61\x6c\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x27\x20\x2d\x2d\x20\x74\x68\x65\x73\x65\x20\x61\x6e\x64\x20\x74\x68\x65\x69\x72\x20\x64\x65\x73\x63\x65\x6e\x64\x61\x6e\x74\x73\x20\x77\x69\x6c\x6c\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x62\x65\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x65\x73\x20\x6f\x66\x20\x74\x68\x65\x20\x72\x65\x67\x69\x73\x74\x65\x72\x69\x6e\x67\x20\x41\x42\x43\x20\x62\x79\x20\x74\x68\x65\x20\x62\x75\x69\x6c\x74\x2d\x69\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x73\x73\x75\x62\x63\x6c\x61\x73\x73\x28\x29\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x2c\x20\x62\x75\x74\x20\x74\x68\x65\x20\x72\x65\x67\x69\x73\x74\x65\x72\x69\x6e\x67\x20\x41\x42\x43\x20\x77\x6f\x6e\x27\x74\x20\x73\x68\x6f\x77\x20\x75\x70\x20\x69\x6e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x74\x68\x65\x69\x72\x20\x4d\x52\x4f\x20\x28\x4d\x65\x74\x68\x6f\x64\x20\x52\x65\x73\x6f\x6c\x75\x74\x69\x6f\x6e\x20\x4f\x72\x64\x65\x72\x29\x20\x6e\x6f\x72\x20\x77\x69\x6c\x6c\x20\x6d\x65\x74\x68\x6f\x64\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x61\x74\x69\x6f\x6e\x73\x20\x64\x65\x66\x69\x6e\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x72\x65\x67\x69\x73\x74\x65\x72\x69\x6e\x67\x20\x41\x42\x43\x20\x62\x65\x20\x63\x61\x6c\x6c\x61\x62\x6c\x65\x20\x28\x6e\x6f\x74\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x65\x76\x65\x6e\x20\x76\x69\x61\x20\x73\x75\x70\x65\x72\x28\x29\x29\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_12_consts_2_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x95\x01\x97\x00\x74\x00\xa9\x00\x6a\x01\x7c\x00\x7c\x01\x7c\x02\x7c\x03\x66\x04\x69\x00\x7c\x04\xa4\x01\x8e\x01\x7d\x05\x74\x02\x7c\x05\xa9\x01\x01\x00\x7c\x05\x53\x00",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts_2_consts = {
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
        uint8_t _data[8];
    }
toplevel_consts_12_consts_2_names_1 = {
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
            PyObject *ob_item[3];
        }_object;
    }
toplevel_consts_12_consts_2_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 3,
        },
        .ob_item = {
            & toplevel_consts_2_consts_3_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_9_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_12_consts_2_varnames_0 = {
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
    ._data = "mcls",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_12_consts_2_varnames_1 = {
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
toplevel_consts_12_consts_2_varnames_2 = {
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
    ._data = "bases",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_12_consts_2_varnames_3 = {
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
    ._data = "namespace",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[7];
    }
toplevel_consts_12_consts_2_varnames_4 = {
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
        uint8_t _data[4];
    }
toplevel_consts_12_consts_2_varnames_5 = {
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
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_12_consts_2_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_3._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_4._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_12_consts_2_qualname = {
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
    ._data = "ABCMeta.__new__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[11];
    }
toplevel_consts_12_consts_2_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 10,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x02\x00\x1a\x01\x08\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[43];
    }
toplevel_consts_12_consts_2_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 42,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x13\x18\x13\x1a\x13\x22\x23\x27\x29\x2d\x2f\x34\x36\x3f\x13\x4a\x13\x4a\x43\x49\x13\x4a\x13\x4a\x0d\x10\x0d\x16\x17\x1a\x0d\x1b\x0d\x1b\x14\x17\x0d\x17",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[7];
        }_object;
    }
toplevel_consts_12_consts_2_localsplusnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 7,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_0._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_2._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_3._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_4._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_2_consts_3_freevars_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[8];
    }
toplevel_consts_12_consts_2_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12_consts_2 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_2_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_2_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_2_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 11,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 4,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 105,
    .co_code = & toplevel_consts_12_consts_2_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_2_localsplusnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_2_names_1._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_2_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_2_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_2_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_2_columntable.ob_base.ob_base,
    .co_nlocalsplus = 7,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 1,
    .co_varnames = & toplevel_consts_12_consts_2_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_12_consts_3_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x7c\x01\xa9\x02\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[124];
    }
toplevel_consts_12_consts_3_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 123,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x67\x69\x73\x74\x65\x72\x20\x61\x20\x76\x69\x72\x74\x75\x61\x6c\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x20\x6f\x66\x20\x61\x6e\x20\x41\x42\x43\x2e\x0a\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x74\x68\x65\x20\x73\x75\x62\x63\x6c\x61\x73\x73\x2c\x20\x74\x6f\x20\x61\x6c\x6c\x6f\x77\x20\x75\x73\x61\x67\x65\x20\x61\x73\x20\x61\x20\x63\x6c\x61\x73\x73\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x2e\x0a\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts_3_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_3_consts_0._ascii.ob_base,
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
toplevel_consts_12_consts_3_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_2._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_consts_3_varnames_1 = {
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
    ._data = "subclass",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts_3_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_12_consts_3_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_consts_3_name = {
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
        uint8_t _data[17];
    }
toplevel_consts_12_consts_3_qualname = {
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
    ._data = "ABCMeta.register",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_12_consts_3_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 4,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x05",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[13];
    }
toplevel_consts_12_consts_3_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x21\x22\x25\x27\x2f\x14\x30\x0d\x30",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[3];
    }
toplevel_consts_12_consts_3_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12_consts_3 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_3_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_3_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 110,
    .co_code = & toplevel_consts_12_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_3_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_3_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_3_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_3_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_3_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_12_consts_4_consts_0 = {
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
    ._data = "Override for isinstance(instance, cls).",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[1];
        }_object;
    }
toplevel_consts_12_consts_4_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_4_consts_0._ascii.ob_base,
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
toplevel_consts_12_consts_4_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_3._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[9];
    }
toplevel_consts_12_consts_4_varnames_1 = {
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
    ._data = "instance",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts_4_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_12_consts_4_varnames_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_12_consts_4_name = {
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
    ._data = "__instancecheck__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_12_consts_4_qualname = {
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
    ._data = "ABCMeta.__instancecheck__",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_12_consts_4_linetable = {
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
toplevel_consts_12_consts_4_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 12,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x14\x26\x27\x2a\x2c\x34\x14\x35\x0d\x35",
};
static struct PyCodeObject toplevel_consts_12_consts_4 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_4_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_4_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 117,
    .co_code = & toplevel_consts_12_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_4_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_4_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_4_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_4_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_12_consts_5_consts_0 = {
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
    ._data = "Override for issubclass(subclass, cls).",
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
            & toplevel_consts_12_consts_5_consts_0._ascii.ob_base,
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
toplevel_consts_12_consts_5_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_12_consts_5_name = {
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
    ._data = "__subclasscheck__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_12_consts_5_qualname = {
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
    ._data = "ABCMeta.__subclasscheck__",
};
static struct PyCodeObject toplevel_consts_12_consts_5 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_5_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_5_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_3_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 3,
    .co_firstlineno = 121,
    .co_code = & toplevel_consts_12_consts_3_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_3_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_3_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_5_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_5_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_4_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_4_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_4_columntable.ob_base.ob_base,
    .co_nlocalsplus = 2,
    .co_nlocals = 2,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_3_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_12_consts_7_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x64\x01\x7c\x00\x6a\x01\x9b\x00\x64\x02\x7c\x00\x6a\x02\x9b\x00\x9d\x04\x7c\x01\x64\x03\xaa\x02\x01\x00\x74\x00\x64\x04\x74\x03\xa9\x00\x9b\x00\x9d\x02\x7c\x01\x64\x03\xaa\x02\x01\x00\x74\x04\x7c\x00\xa9\x01\x5c\x04\x7d\x02\x7d\x03\x7d\x04\x7d\x05\x74\x00\x64\x05\x7c\x02\x9b\x02\x9d\x02\x7c\x01\x64\x03\xaa\x02\x01\x00\x74\x00\x64\x06\x7c\x03\x9b\x02\x9d\x02\x7c\x01\x64\x03\xaa\x02\x01\x00\x74\x00\x64\x07\x7c\x04\x9b\x02\x9d\x02\x7c\x01\x64\x03\xaa\x02\x01\x00\x74\x00\x64\x08\x7c\x05\x9b\x02\x9d\x02\x7c\x01\x64\x03\xaa\x02\x01\x00\x64\x09\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[40];
    }
toplevel_consts_12_consts_7_consts_0 = {
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
    ._data = "Debug helper to print the ABC registry.",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_12_consts_7_consts_1 = {
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
    ._data = "Class: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[2];
    }
toplevel_consts_12_consts_7_consts_2 = {
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
        uint8_t _data[5];
    }
toplevel_consts_12_consts_7_consts_3_0 = {
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
toplevel_consts_12_consts_7_consts_3 = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_7_consts_3_0._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_12_consts_7_consts_4 = {
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
    ._data = "Inv. counter: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[16];
    }
toplevel_consts_12_consts_7_consts_5 = {
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
    ._data = "_abc_registry: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_consts_12_consts_7_consts_6 = {
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
    ._data = "_abc_cache: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[22];
    }
toplevel_consts_12_consts_7_consts_7 = {
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
    ._data = "_abc_negative_cache: ",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[30];
    }
toplevel_consts_12_consts_7_consts_8 = {
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
    ._data = "_abc_negative_cache_version: ",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[10];
        }_object;
    }
toplevel_consts_12_consts_7_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 10,
        },
        .ob_item = {
            & toplevel_consts_12_consts_7_consts_0._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_1._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_2._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_3._object.ob_base.ob_base,
            & toplevel_consts_12_consts_7_consts_4._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_5._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_6._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_7._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_8._ascii.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_12_consts_7_names_0 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_12_consts_7_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_12_consts_7_names_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_9_0._ascii.ob_base,
            & toplevel_consts_9_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[14];
    }
toplevel_consts_12_consts_7_varnames_2 = {
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
    ._data = "_abc_registry",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[11];
    }
toplevel_consts_12_consts_7_varnames_3 = {
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
    ._data = "_abc_cache",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_12_consts_7_varnames_4 = {
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
    ._data = "_abc_negative_cache",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_12_consts_7_varnames_5 = {
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
    ._data = "_abc_negative_cache_version",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_12_consts_7_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_12_consts_7_consts_3_0._ascii.ob_base,
            & toplevel_consts_12_consts_7_varnames_2._ascii.ob_base,
            & toplevel_consts_12_consts_7_varnames_3._ascii.ob_base,
            & toplevel_consts_12_consts_7_varnames_4._ascii.ob_base,
            & toplevel_consts_12_consts_7_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[15];
    }
toplevel_consts_12_consts_7_name = {
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
    ._data = "_dump_registry",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_12_consts_7_qualname = {
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
    ._data = "ABCMeta._dump_registry",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[25];
    }
toplevel_consts_12_consts_7_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 24,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x1c\x02\x14\x01\x06\x02\x08\xff\x02\x01\x12\x01\x12\x01\x12\x01\x0a\x01\x02\x01\x0a\xff",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_12_consts_7_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x1c\x02\x14\x01\x08\x02\x06\xff\x02\x01\x12\x01\x12\x01\x12\x01\x0a\x01\x0c\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[143];
    }
toplevel_consts_12_consts_7_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 142,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x12\x13\x40\x1d\x20\x1d\x2b\x13\x40\x13\x40\x2e\x31\x2e\x3e\x13\x40\x13\x40\x47\x4b\x0d\x4c\x0d\x4c\x0d\x4c\x0d\x12\x13\x37\x24\x33\x24\x35\x13\x37\x13\x37\x3e\x42\x0d\x43\x0d\x43\x0d\x43\x2d\x36\x37\x3a\x2d\x3b\x0d\x2a\x0e\x1b\x1d\x27\x29\x3c\x0e\x29\x0d\x12\x13\x36\x25\x32\x13\x36\x13\x36\x3d\x41\x0d\x42\x0d\x42\x0d\x42\x0d\x12\x13\x30\x22\x2c\x13\x30\x13\x30\x37\x3b\x0d\x3c\x0d\x3c\x0d\x3c\x0d\x12\x13\x42\x2b\x3e\x13\x42\x13\x42\x49\x4d\x0d\x4e\x0d\x4e\x0d\x4e\x0d\x12\x13\x52\x33\x4e\x13\x52\x13\x52\x18\x1c\x0d\x1d\x0d\x1d\x0d\x1d\x0d\x1d\x0d\x1d",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_12_consts_7_localspluskinds = {
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
static struct PyCodeObject toplevel_consts_12_consts_7 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_7_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_7_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_7_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 2,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 5,
    .co_firstlineno = 125,
    .co_code = & toplevel_consts_12_consts_7_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_7_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_12_consts_7_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_7_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_7_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_7_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_7_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_7_columntable.ob_base.ob_base,
    .co_nlocalsplus = 6,
    .co_nlocals = 6,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_7_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_12_consts_8_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\xa9\x01\x01\x00\x64\x01\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[47];
    }
toplevel_consts_12_consts_8_consts_0 = {
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
    ._data = "Clear the registry (for debugging or testing).",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts_8_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_8_consts_0._ascii.ob_base,
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
toplevel_consts_12_consts_8_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_6._ascii.ob_base,
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
toplevel_consts_12_consts_8_varnames = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_12_consts_8_name = {
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
    ._data = "_abc_registry_clear",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[28];
    }
toplevel_consts_12_consts_8_qualname = {
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
    ._data = "ABCMeta._abc_registry_clear",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[5];
    }
toplevel_consts_12_consts_8_linetable = {
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
toplevel_consts_12_consts_8_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x1c\x1d\x20\x0d\x21\x0d\x21\x0d\x21\x0d\x21",
};
static struct PyCodeObject toplevel_consts_12_consts_8 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_8_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_8_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 137,
    .co_code = & toplevel_consts_12_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_8_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_8_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_8_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[45];
    }
toplevel_consts_12_consts_9_consts_0 = {
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
    ._data = "Clear the caches (for debugging or testing).",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[2];
        }_object;
    }
toplevel_consts_12_consts_9_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 2,
        },
        .ob_item = {
            & toplevel_consts_12_consts_9_consts_0._ascii.ob_base,
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
toplevel_consts_12_consts_9_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 1,
        },
        .ob_item = {
            & toplevel_consts_9_7._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[18];
    }
toplevel_consts_12_consts_9_name = {
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
    ._data = "_abc_caches_clear",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[26];
    }
toplevel_consts_12_consts_9_qualname = {
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
    ._data = "ABCMeta._abc_caches_clear",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[15];
    }
toplevel_consts_12_consts_9_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 14,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0d\x1a\x1b\x1e\x0d\x1f\x0d\x1f\x0d\x1f\x0d\x1f",
};
static struct PyCodeObject toplevel_consts_12_consts_9 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts_9_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_consts_9_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_consts_8_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 141,
    .co_code = & toplevel_consts_12_consts_8_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_12_consts_8_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_12_consts_9_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_12_consts_9_qualname._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_consts_8_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_consts_8_linetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_consts_9_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 1,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_12_consts_8_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[11];
        }_object;
    }
toplevel_consts_12_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 11,
        },
        .ob_item = {
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_12_consts_1._ascii.ob_base,
            & toplevel_consts_12_consts_2.ob_base,
            & toplevel_consts_12_consts_3.ob_base,
            & toplevel_consts_12_consts_4.ob_base,
            & toplevel_consts_12_consts_5.ob_base,
            Py_None,
            & toplevel_consts_12_consts_7.ob_base,
            & toplevel_consts_12_consts_8.ob_base,
            & toplevel_consts_12_consts_9.ob_base,
            & toplevel_consts_12_consts_2_consts._object.ob_base.ob_base,
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
toplevel_consts_12_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 12,
        },
        .ob_item = {
            & toplevel_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_12_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_12_consts_3_name._ascii.ob_base,
            & toplevel_consts_12_consts_4_name._ascii.ob_base,
            & toplevel_consts_12_consts_5_name._ascii.ob_base,
            & toplevel_consts_12_consts_7_name._ascii.ob_base,
            & toplevel_consts_12_consts_8_name._ascii.ob_base,
            & toplevel_consts_12_consts_9_name._ascii.ob_base,
            & toplevel_consts_2_names_6._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[21];
    }
toplevel_consts_12_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 20,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x01\x0a\x0c\x06\x05\x06\x07\x06\x04\x08\x04\x06\x0c\x0e\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_12_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 22,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x0a\x00\x04\x0c\x0a\x04\x06\x07\x06\x04\x06\x04\x02\x02\x06\x0a\x06\x04\x0e\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[73];
    }
toplevel_consts_12_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 72,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x09\x0c\x09\x0c\x09\x17\x09\x17\x09\x17\x09\x17\x09\x17\x09\x30\x09\x30\x09\x30\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x09\x35\x26\x2a\x09\x1d\x09\x1d\x09\x1d\x09\x21\x09\x21\x09\x21\x09\x1f\x09\x1f\x09\x1f\x09\x1f\x09\x1f\x09\x1f\x09\x1f",
};
static struct PyCodeObject toplevel_consts_12 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_12_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_12_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_12_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 2,
    .co_firstlineno = 92,
    .co_code = & toplevel_consts_12_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_2_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_10_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_10_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_12_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_12_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_12_columntable.ob_base.ob_base,
    .co_nlocalsplus = 1,
    .co_nlocals = 0,
    .co_nplaincellvars = 1,
    .co_ncellvars = 1,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_2_consts_3_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[149];
    }
toplevel_consts_14_code = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 148,
    },
    .ob_shash = -1,
    .ob_sval = "\x97\x00\x74\x00\x7c\x00\x64\x01\xa9\x02\x73\x08\x7c\x00\x53\x00\x74\x01\xa9\x00\x7d\x01\x7c\x00\x6a\x02\x44\x00\x5d\x1d\x7d\x02\x74\x03\x7c\x02\x64\x01\x64\x02\xa9\x03\x44\x00\x5d\x14\x7d\x03\x74\x03\x7c\x00\x7c\x03\x64\x03\xa9\x03\x7d\x04\x74\x03\x7c\x04\x64\x04\x64\x05\xa9\x03\x72\x2a\x7c\x01\xa0\x04\x7c\x03\xa8\x01\xa9\x01\x01\x00\x71\x16\x71\x0e\x7c\x00\x6a\x05\xa0\x06\xa8\x00\xa9\x00\x44\x00\x5d\x10\x5c\x02\x7d\x03\x7d\x04\x74\x03\x7c\x04\x64\x04\x64\x05\xa9\x03\x72\x42\x7c\x01\xa0\x04\x7c\x03\xa8\x01\xa9\x01\x01\x00\x71\x32\x74\x07\x7c\x01\xa9\x01\x7c\x00\x5f\x08\x7c\x00\x53\x00",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[668];
    }
toplevel_consts_14_consts_0 = {
    ._ascii = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyUnicode_Type,
        },
        .length = 667,
        .hash = -1,
        .state = {
            .kind = 1,
            .compact = 1,
            .ascii = 1,
            .ready = 1,
        },
    },
    ._data = "\x52\x65\x63\x61\x6c\x63\x75\x6c\x61\x74\x65\x20\x74\x68\x65\x20\x73\x65\x74\x20\x6f\x66\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x6f\x66\x20\x61\x6e\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x63\x6c\x61\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x61\x20\x63\x6c\x61\x73\x73\x20\x68\x61\x73\x20\x68\x61\x64\x20\x6f\x6e\x65\x20\x6f\x66\x20\x69\x74\x73\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x65\x64\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x77\x61\x73\x20\x63\x72\x65\x61\x74\x65\x64\x2c\x20\x74\x68\x65\x20\x6d\x65\x74\x68\x6f\x64\x20\x77\x69\x6c\x6c\x20\x6e\x6f\x74\x20\x62\x65\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x69\x6d\x70\x6c\x65\x6d\x65\x6e\x74\x65\x64\x20\x75\x6e\x74\x69\x6c\x0a\x20\x20\x20\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x63\x61\x6c\x6c\x65\x64\x2e\x20\x41\x6c\x74\x65\x72\x6e\x61\x74\x69\x76\x65\x6c\x79\x2c\x20\x69\x66\x20\x61\x20\x6e\x65\x77\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x20\x68\x61\x73\x20\x62\x65\x65\x6e\x0a\x20\x20\x20\x20\x61\x64\x64\x65\x64\x20\x74\x6f\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x2c\x20\x69\x74\x20\x77\x69\x6c\x6c\x20\x6f\x6e\x6c\x79\x20\x62\x65\x20\x63\x6f\x6e\x73\x69\x64\x65\x72\x65\x64\x20\x61\x6e\x20\x61\x62\x73\x74\x72\x61\x63\x74\x20\x6d\x65\x74\x68\x6f\x64\x20\x6f\x66\x20\x74\x68\x65\x0a\x20\x20\x20\x20\x63\x6c\x61\x73\x73\x20\x61\x66\x74\x65\x72\x20\x74\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x69\x73\x20\x63\x61\x6c\x6c\x65\x64\x2e\x0a\x0a\x20\x20\x20\x20\x54\x68\x69\x73\x20\x66\x75\x6e\x63\x74\x69\x6f\x6e\x20\x73\x68\x6f\x75\x6c\x64\x20\x62\x65\x20\x63\x61\x6c\x6c\x65\x64\x20\x62\x65\x66\x6f\x72\x65\x20\x61\x6e\x79\x20\x75\x73\x65\x20\x69\x73\x20\x6d\x61\x64\x65\x20\x6f\x66\x20\x74\x68\x65\x20\x63\x6c\x61\x73\x73\x2c\x0a\x20\x20\x20\x20\x75\x73\x75\x61\x6c\x6c\x79\x20\x69\x6e\x20\x63\x6c\x61\x73\x73\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x73\x20\x74\x68\x61\x74\x20\x61\x64\x64\x20\x6d\x65\x74\x68\x6f\x64\x73\x20\x74\x6f\x20\x74\x68\x65\x20\x73\x75\x62\x6a\x65\x63\x74\x20\x63\x6c\x61\x73\x73\x2e\x0a\x0a\x20\x20\x20\x20\x52\x65\x74\x75\x72\x6e\x73\x20\x63\x6c\x73\x2c\x20\x74\x6f\x20\x61\x6c\x6c\x6f\x77\x20\x75\x73\x61\x67\x65\x20\x61\x73\x20\x61\x20\x63\x6c\x61\x73\x73\x20\x64\x65\x63\x6f\x72\x61\x74\x6f\x72\x2e\x0a\x0a\x20\x20\x20\x20\x49\x66\x20\x63\x6c\x73\x20\x69\x73\x20\x6e\x6f\x74\x20\x61\x6e\x20\x69\x6e\x73\x74\x61\x6e\x63\x65\x20\x6f\x66\x20\x41\x42\x43\x4d\x65\x74\x61\x2c\x20\x64\x6f\x65\x73\x20\x6e\x6f\x74\x68\x69\x6e\x67\x2e\x0a\x20\x20\x20\x20",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[20];
    }
toplevel_consts_14_consts_1 = {
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
    ._data = "__abstractmethods__",
};
static
    struct {
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[6];
        }_object;
    }
toplevel_consts_14_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 6,
        },
        .ob_item = {
            & toplevel_consts_14_consts_0._ascii.ob_base,
            & toplevel_consts_14_consts_1._ascii.ob_base,
            & toplevel_consts_1_freevars._object.ob_base.ob_base,
            Py_None,
            & toplevel_consts_1_names_0._ascii.ob_base,
            Py_False,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_14_names_0 = {
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
        uint8_t _data[4];
    }
toplevel_consts_14_names_1 = {
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
        uint8_t _data[10];
    }
toplevel_consts_14_names_2 = {
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
    ._data = "__bases__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[8];
    }
toplevel_consts_14_names_3 = {
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
        uint8_t _data[4];
    }
toplevel_consts_14_names_4 = {
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
    ._data = "__dict__",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_14_names_6 = {
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
        uint8_t _data[10];
    }
toplevel_consts_14_names_7 = {
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
            & toplevel_consts_14_names_0._ascii.ob_base,
            & toplevel_consts_14_names_1._ascii.ob_base,
            & toplevel_consts_14_names_2._ascii.ob_base,
            & toplevel_consts_14_names_3._ascii.ob_base,
            & toplevel_consts_14_names_4._ascii.ob_base,
            & toplevel_consts_14_names_5._ascii.ob_base,
            & toplevel_consts_14_names_6._ascii.ob_base,
            & toplevel_consts_14_names_7._ascii.ob_base,
            & toplevel_consts_14_consts_1._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_14_varnames_1 = {
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
    ._data = "abstracts",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_consts_14_varnames_2 = {
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
    ._data = "scls",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[6];
    }
toplevel_consts_14_varnames_4 = {
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
            & toplevel_consts_12_consts_2_varnames_5._ascii.ob_base,
            & toplevel_consts_14_varnames_1._ascii.ob_base,
            & toplevel_consts_14_varnames_2._ascii.ob_base,
            & toplevel_consts_12_consts_2_varnames_1._ascii.ob_base,
            & toplevel_consts_14_varnames_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[23];
    }
toplevel_consts_14_name = {
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
    ._data = "update_abstractmethods",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[35];
    }
toplevel_consts_14_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x0a\x10\x04\x04\x06\x02\x0a\x03\x10\x01\x0c\x01\x0c\x01\x0c\x01\x02\x80\x02\xfd\x14\x05\x0c\x01\x0c\x01\x02\x80\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[47];
    }
toplevel_consts_14_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 46,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x00\x08\x10\x06\x04\x06\x02\x04\x03\x04\x04\x02\xfc\x0a\x01\x04\x03\x02\xfd\x0c\x01\x0a\x01\x0e\x01\x02\x80\x02\x00\x0a\x02\x04\x02\x06\xfe\x0a\x01\x0e\x01\x02\x80\x0a\x01\x04\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[149];
    }
toplevel_consts_14_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 148,
    },
    .ob_shash = -1,
    .ob_sval = "\x01\x01\x0c\x13\x14\x17\x19\x2e\x0c\x2f\x05\x13\x10\x13\x09\x13\x11\x14\x11\x16\x05\x0e\x11\x14\x11\x1e\x05\x24\x05\x24\x09\x0d\x15\x1c\x1d\x21\x23\x38\x3a\x3c\x15\x3d\x09\x24\x09\x24\x0d\x11\x15\x1c\x1d\x20\x22\x26\x28\x2c\x15\x2d\x0d\x12\x10\x17\x18\x1d\x1f\x35\x37\x3c\x10\x3d\x0d\x24\x11\x1a\x11\x24\x1f\x23\x11\x24\x11\x24\x11\x24\x00\x00\x09\x24\x18\x1b\x18\x24\x18\x2c\x18\x2c\x18\x2c\x05\x20\x05\x20\x09\x14\x09\x0d\x0f\x14\x0c\x13\x14\x19\x1b\x31\x33\x38\x0c\x39\x09\x20\x0d\x16\x0d\x20\x1b\x1f\x0d\x20\x0d\x20\x0d\x20\x00\x00\x1f\x28\x29\x32\x1f\x33\x05\x08\x05\x1c\x0c\x0f\x05\x0f",
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
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 3,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 1,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 6,
    .co_firstlineno = 146,
    .co_code = & toplevel_consts_14_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_14_localspluskinds.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_14_name._ascii.ob_base,
    .co_qualname = & toplevel_consts_14_name._ascii.ob_base,
    .co_linetable = & toplevel_consts_14_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_14_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_14_columntable.ob_base.ob_base,
    .co_nlocalsplus = 5,
    .co_nlocals = 5,
    .co_nplaincellvars = 0,
    .co_ncellvars = 0,
    .co_nfreevars = 0,
    .co_varnames = & toplevel_consts_14_varnames._object.ob_base.ob_base,
    .co_cellvars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_freevars = & toplevel_consts_1_freevars._object.ob_base.ob_base,
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[4];
    }
toplevel_consts_15_consts_0 = {
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
    ._data = "ABC",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[87];
    }
toplevel_consts_15_consts_1 = {
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
    ._data = "\x48\x65\x6c\x70\x65\x72\x20\x63\x6c\x61\x73\x73\x20\x74\x68\x61\x74\x20\x70\x72\x6f\x76\x69\x64\x65\x73\x20\x61\x20\x73\x74\x61\x6e\x64\x61\x72\x64\x20\x77\x61\x79\x20\x74\x6f\x20\x63\x72\x65\x61\x74\x65\x20\x61\x6e\x20\x41\x42\x43\x20\x75\x73\x69\x6e\x67\x0a\x20\x20\x20\x20\x69\x6e\x68\x65\x72\x69\x74\x61\x6e\x63\x65\x2e\x0a\x20\x20\x20\x20",
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
            & toplevel_consts_15_consts_1._ascii.ob_base,
            & toplevel_consts_1_freevars._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[10];
    }
toplevel_consts_15_names_4 = {
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[5];
        }_object;
    }
toplevel_consts_15_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 5,
        },
        .ob_item = {
            & toplevel_consts_2_names_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_consts_2_names_2._ascii.ob_base,
            & toplevel_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_15_names_4._ascii.ob_base,
        },
    },
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_15_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x01\x08\x03",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[7];
    }
toplevel_consts_15_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 6,
    },
    .ob_shash = -1,
    .ob_sval = "\x0a\x00\x04\x03\x08\x01",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[23];
    }
toplevel_consts_15_columntable = {
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
static struct PyCodeObject toplevel_consts_15 = {
    .ob_base = {
        .ob_refcnt = 999999999,
        .ob_type = &PyCode_Type,
    },
    .co_consts = & toplevel_consts_15_consts._object.ob_base.ob_base,
    .co_names = & toplevel_consts_15_names._object.ob_base.ob_base,
    .co_firstinstr = (_Py_CODEUNIT *) & toplevel_consts_6_code.ob_sval,
    .co_exceptiontable = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_flags = 0,
    .co_warmup = QUICKENING_INITIAL_WARMUP_VALUE,
    .co_argcount = 0,
    .co_posonlyargcount = 0,
    .co_kwonlyargcount = 0,
    .co_stacksize = 1,
    .co_firstlineno = 184,
    .co_code = & toplevel_consts_6_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
    .co_filename = & toplevel_consts_1_filename._ascii.ob_base,
    .co_name = & toplevel_consts_15_consts_0._ascii.ob_base,
    .co_qualname = & toplevel_consts_15_consts_0._ascii.ob_base,
    .co_linetable = & toplevel_consts_15_linetable.ob_base.ob_base,
    .co_endlinetable = & toplevel_consts_15_endlinetable.ob_base.ob_base,
    .co_columntable = & toplevel_consts_15_columntable.ob_base.ob_base,
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
        PyGC_Head _gc_head;
        struct {
            PyObject_VAR_HEAD
            PyObject *ob_item[19];
        }_object;
    }
toplevel_consts = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 19,
        },
        .ob_item = {
            & toplevel_consts_0._ascii.ob_base,
            & toplevel_consts_1.ob_base,
            & toplevel_consts_2.ob_base,
            & toplevel_consts_2_consts_0._ascii.ob_base,
            & toplevel_consts_4.ob_base,
            & toplevel_consts_4_consts_0._ascii.ob_base,
            & toplevel_consts_6.ob_base,
            & toplevel_consts_6_consts_0._ascii.ob_base,
            & toplevel_consts_8.ob_base.ob_base,
            & toplevel_consts_9._object.ob_base.ob_base,
            & toplevel_consts_10._object.ob_base.ob_base,
            & toplevel_consts_11._ascii.ob_base,
            & toplevel_consts_12.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_14.ob_base,
            & toplevel_consts_15.ob_base,
            & toplevel_consts_15_consts_0._ascii.ob_base,
            & toplevel_consts_17._object.ob_base.ob_base,
            Py_None,
        },
    },
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[12];
    }
toplevel_names_2 = {
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
        PyASCIIObject _ascii;
        uint8_t _data[13];
    }
toplevel_names_4 = {
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
        uint8_t _data[9];
    }
toplevel_names_6 = {
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
        uint8_t _data[5];
    }
toplevel_names_8 = {
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
        uint8_t _data[12];
    }
toplevel_names_17 = {
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
toplevel_names_18 = {
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
    ._data = "_py_abc",
};
static
    struct {
        PyASCIIObject _ascii;
        uint8_t _data[5];
    }
toplevel_names_21 = {
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
            PyObject *ob_item[24];
        }_object;
    }
toplevel_names = {
    ._object = {
        .ob_base = {
            .ob_base = {
                .ob_refcnt = 999999999,
                .ob_type = &PyTuple_Type,
            },
            .ob_size = 24,
        },
        .ob_item = {
            & toplevel_consts_2_names_3._ascii.ob_base,
            & toplevel_consts_1_name._ascii.ob_base,
            & toplevel_names_2._ascii.ob_base,
            & toplevel_consts_2_consts_0._ascii.ob_base,
            & toplevel_names_4._ascii.ob_base,
            & toplevel_consts_4_consts_0._ascii.ob_base,
            & toplevel_names_6._ascii.ob_base,
            & toplevel_consts_6_consts_0._ascii.ob_base,
            & toplevel_names_8._ascii.ob_base,
            & toplevel_consts_9_0._ascii.ob_base,
            & toplevel_consts_9_1._ascii.ob_base,
            & toplevel_consts_9_2._ascii.ob_base,
            & toplevel_consts_9_3._ascii.ob_base,
            & toplevel_consts_9_4._ascii.ob_base,
            & toplevel_consts_9_5._ascii.ob_base,
            & toplevel_consts_9_6._ascii.ob_base,
            & toplevel_consts_9_7._ascii.ob_base,
            & toplevel_names_17._ascii.ob_base,
            & toplevel_names_18._ascii.ob_base,
            & toplevel_consts_10_0._ascii.ob_base,
            & toplevel_consts_2_names_1._ascii.ob_base,
            & toplevel_names_21._ascii.ob_base,
            & toplevel_consts_14_name._ascii.ob_base,
            & toplevel_consts_15_consts_0._ascii.ob_base,
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
        char ob_sval[35];
    }
toplevel_linetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 34,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x03\x06\x03\x0e\x15\x0e\x14\x0e\x14\x02\x10\x2a\x01\x02\x80\x06\x03\x10\x01\x0a\x01\x02\xfe\x06\x80\x0e\x04\x06\x36\x14\x26",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[55];
    }
toplevel_endlinetable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 54,
    },
    .ob_shash = -1,
    .ob_sval = "\x02\x80\x04\x03\x06\x15\x08\x14\x02\xef\x04\x11\x08\x14\x02\xef\x04\x11\x08\x10\x02\xf3\x04\x0d\x02\x3e\x2a\xc8\x02\x80\x02\x01\x04\x02\x10\xff\x0c\x01\x06\x80\x08\x35\x02\xcd\x04\x33\x06\x26\x08\x07\x02\xfc\x0a\x04",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[181];
    }
toplevel_columntable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 180,
    },
    .ob_shash = -1,
    .ob_sval = "\x00\x00\x01\x3a\x01\x3a\x01\x13\x01\x13\x01\x13\x01\x23\x01\x23\x01\x23\x01\x23\x1b\x26\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x01\x23\x1c\x28\x01\x23\x01\x23\x01\x20\x01\x20\x01\x20\x01\x20\x18\x20\x01\x20\x01\x20\x01\x1f\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x05\x36\x00\x00\x08\x13\x01\x1f\x01\x1f\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x05\x31\x1a\x1f\x05\x0c\x05\x17\x05\x17\x05\x17\x01\x1f\x00\x00\x00\x00\x00\x00\x05\x1f\x05\x1f\x05\x1f\x05\x1f\x13\x17\x05\x1f\x05\x1f\x01\x0f\x01\x0f\x01\x0f\x01\x13\x01\x13\x01\x13\x01\x13\x15\x1c\x01\x13\x01\x13\x01\x13\x01\x13\x01\x13",
};
static
    struct {
        PyObject_VAR_HEAD
        Py_hash_t ob_shash;
        char ob_sval[16];
    }
toplevel_exceptiontable = {
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 999999999,
            .ob_type = &PyBytes_Type,
        },
        .ob_size = 15,
    },
    .ob_shash = -1,
    .ob_sval = "\x9c\x14\x31\x00\xb1\x0f\x41\x03\x03\xc1\x02\x01\x41\x03\x03",
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
    .co_stacksize = 5,
    .co_firstlineno = 1,
    .co_code = & toplevel_code.ob_base.ob_base,
    .co_localsplusnames = & toplevel_consts_1_freevars._object.ob_base.ob_base,
    .co_localspluskinds = & toplevel_consts_1_exceptiontable.ob_base.ob_base,
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
_Py_get_abc_toplevel(void)
{
    do_patchups();
    return (PyObject *) &toplevel;
}

