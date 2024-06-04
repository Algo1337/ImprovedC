#ifndef TYPES_H
#define TYPES_H

typedef enum DATA_T {
    NULL_VAR                                = 0x0000001, // NO VALUE

    /* C Types */
    VOID                                    = 0x00000002,
    VOID_PTR                                = 0x00000003,
    CHAR                                    = 0x00000004,
    CHAR_PTR                                = 0x00000005,
    CHAR_DPTR                               = 0x00000006,
    INT                                     = 0x00000007,

    /* IC TYPES */
    STRING                                  = 0x00000008,
    INTEGER                                 = 0x00000009,
    ARRAY                                   = 0x00000010,
    MAP                                     = 0x00000011,
    FLOAT                                   = 0x00000012,
    DOUBLE                                  = 0x00000013
} DATA_T;

typedef enum INCLUDE_ERR_T {
    INVALID_PATH_ERR                        = 0x10000020,
    INVALID_PATH_FILES_ERR                  = 0x10000021
} INCLUDE_ERR_T;

typedef enum FILE_ERR_T {
    INVALID_FILE_EXTENSION_ERR              = 0x20000030,
    INVALID_SRC_CODE_ERR                    = 0x20000031,
    MISSING_ENTRY_FNC_ERR                   = 0x20000032
} FILE_ERR_T;

typedef enum VAR_ERR_T {
    NO_VAR_ERR                              = 0x3000000,
    INVALID_DECLARATION                     = 0x3000001,

    INVALID_VAR_NAME_ERR                    = 0x3000002,
    MISSING_VAR_NAME_ERR                    = 0x3000003,

    EMPTY_STR_VALUE_ERR                     = 0x3000004,
    INVALID_VAR_VALUE_ERR                   = 0x3000005,
    MISSING_VAR_VALUE_ERR                   = 0x3000006,

    VAR_DECLARATION_ERR                     = 0x3000007,
    VAR_EXPRESSION_ERR                      = 0x3000008,
    VALUE_SET_ERR                           = 0x3000009,
    APPENDANCE_ERR                          = 0x3000010,
    MEMORY_ERR                              = 0x3000011
} VAR_ERR_T;

typedef enum STRUCT_ERR_T {
    NO_STRUCT_ERR                           = 0x4000000,
    MISSING_STRUCT_NAME_ERR                 = 0x4000001,
    INVALID_STRUCT_NAME_ERR                 = 0x4000002,

    MISSING_STRUCT_OPENING_BRACKET_ERR      = 0x4000003,
    MISSING_STRUCT_CLOSING_BREAKET_ERR      = 0x4000004,

    INVALID_DATA_T_ERR                      = 0x4000005,
    INVALID_FIELD_NAME_ERR                  = 0x4000006
} STRUCT_ERR_T;

typedef enum FNC_ERR_T {
    NO_FNC_ERR                              = 0x5000000,
    MISSING_FNC_NAME_ERR                    = 0x5000001,

    MISSING_ARG_OPENING_PARATHENSIS_ERR     = 0x5000002,
    MISSING_ARG_CLOSING_PARATHENSIS_ERR     = 0x5000003,

    INVALID_ARG_TYPE_ERR                    = 0x5000004,
    MISSING_ARG_TYPE_ERR                    = 0x5000005,

    INVALID_ARG_NAME_ERR                    = 0x5000006,
    MISSING_ARG_NAME_ERR                    = 0x5000007,

    MISSING_STACK_OPENING_BRACKET_ERR       = 0x5000008,
    MISSING_STACK_CLOSING_BRACKET_ERR       = 0x5000009,

    INVALID_STACK_ARGUMENT_ERR              = 0x5000010,
    MISSING_FNC_OPENING_BRACKET_ERR         = 0x5000011,
    MISSING_FNC_CLOSING_BREAKET_ERR         = 0x5000012,

    FNC_CREATION_ATTEMPT_ERR                = 0x5000013,
    STRUCT_CREATION_ATTEMPT_ERR             = 0x5000014
} FNC_ERR_T;

#endif