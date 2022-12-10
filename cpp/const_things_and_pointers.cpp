int main() {
    /* -------------- */
    /* NON-CONSTEXPRS */
    /* -------------- */

    // Non-const pointers
    char* pointer_to_char = "pointer_to_char";
    const char* pointer_to_const_char = "pointer_to_const_char";

    // Const pointers
    char* const const_pointer_to_char = "const_pointer_to_char";
    const char* const const_pointer_to_const_char = "const_pointer_to_const_char";

    // [NO ERRORS]
    // Pointers are non-const
    pointer_to_char = "other literal for pointer_to_char";
    pointer_to_const_char = "other literal for pointer_to_const_char";

    // [COMPILE ERRORS]
    // Pointers are const
    // const_pointer_to_char = "other literal for const_pointer_to_char";
    // const_pointer_to_const_char = "other literal for const_pointer_to_const_char";

    // [RUNTIME ERRORS]
    // Pointers point to non-const char but it is read-only memory
    // pointer_to_char[0] = 'A';
    // const_pointer_to_char[0] = 'A';

    // [COMPILE ERRORS]
    // Pointers point to const char
    // pointer_to_const_char[0] = 'A';
    // const_pointer_to_const_char[0] = 'A';

    /* ---------- */
    /* CONSTEXPRS */
    /* ---------- */

    // Const pointers (constexpr on object declaration implies const)
    constexpr char* cexpr_pointer_to_char = "const_pointer_to_char";
    constexpr const char* cexpr_pointer_to_const_char = "const_pointer_to_const_char";

    // Const pointers (const before identifier is unnecessary, implied by constexpr)
    constexpr char* const cexpr_const_pointer_to_char = "const_pointer_to_char";
    constexpr const char* const cexpr_const_pointer_to_const_char = "const_pointer_to_const_char";

    // [COMPILE ERRORS]
    // Pointers are const
    // cexpr_pointer_to_char = "other literal for cexpr_pointer_to_char";
    // cexpr_pointer_to_const_char = "other literal for cexpr_pointer_to_const_char";

    // [COMPILE ERRORS]
    // Pointers are const
    // cexpr_const_pointer_to_char = "other literal for cexpr_const_pointer_to_char";
    // cexpr_const_pointer_to_const_char = "other literal for cexpr_const_pointer_to_const_char";

    // [RUNTIME ERRORS]
    // Pointers point to non-const char but it is read-only memory
    // cexpr_pointer_to_char[0] = 'A';
    // cexpr_const_pointer_to_char[0] = 'B';

    // [COMPILE ERRORS]
    // Pointers point to const char
    // cexpr_pointer_to_const_char[0] = 'A';
    // cexpr_const_pointer_to_const_char[0] = 'B';

    return 0;
}
