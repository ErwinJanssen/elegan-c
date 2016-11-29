#include <criterion/criterion.h>

#include "safe-c/safe_string.h"

#include "safe-c/safe_memory.h"

Test(copy_string, null_expect_exit, .exit_code = 1)
{
    cstring wont_allocate = copy_string(NULL);
    safe_free(wont_allocate);
}

Test(copy_string, empty_string_literal)
{
    cstring copy = copy_string("");
    cr_assert_str_empty(copy);
    safe_free(copy);
}

Test(copy_string, short_string_literal)
{
    cstring copy = copy_string("short");
    cr_assert_str_eq(copy, "short");
    safe_free(copy);
}

Test(copy_string, empty_string)
{
    cstring source = "";
    cstring copy = copy_string(source);
    cr_assert_str_eq(copy, source);
    safe_free(copy);
}

Test(copy_string, short_string)
{
    cstring source = "short";
    cstring copy = copy_string(source);
    cr_assert_str_eq(copy, source);
    safe_free(copy);
}

Test(copy_string, longer_string)
{
    cstring source = "This is a string that is much longer than the short "
            "string.\nIt contains newline characters, spaces and tabs\t.";
    cstring copy = copy_string(source);
    cr_assert_str_eq(copy, source);
    safe_free(copy);
}

Test(copy_string, string_with_null)
{
    cstring source = "This string contains \0 characters, the text after this "
            "character will not be copied.";
    cstring copy = copy_string(source);
    cr_assert_str_eq(copy, "This string contains ");
    safe_free(copy);
}
