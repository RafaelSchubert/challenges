# Time to Words

I faced this challenge during a test assigned to me as part of an interview. It's not really difficult but you also got to pay attention to its requirements.

## The Problem

The challenge requires you to parse a time input -- hours then minutes (each separately) -- into a text format. There's a few rules, however, that are better described by examples.

```
Constraints:
 1 <= hours   <= 12
 0 <= minutes <= 59

Examples:
 Input  | Output
--------+------------------------
 "2 0"  | "two o' clock"
 "2 5"  | "five past two"
 "2 15" | "quarter past two"
 "2 20" | "twenty past two"
 "2 30" | "half past two"
 "2 40" | "twenty to three"
 "2 45" | "quarter to three"
 "2 50" | "ten to three"
```

## The Solution

There's not much to say about the solution. I mean, look at the description, there doesn't seem to be any complex topics involved. It's a matter of being smart, I would say.

What I can say is this:

- Instead of a sequence of `if` or a `switch` for the number-to-text conversion, you can simply use an array and the numbers themselves as indices. There were no memory constraints in the test.

```c++
#include <iostream>
#include <array>
#include <string>

// Ah, yes! Make yourself a favor and use std::array<> instead of a raw array.
static std::array<std::string, 4> const s_numbers = { "", "one", "two", "three" };

int main()
{
    std::cout << s_numbers[1] << '\n';
    std::cout << s_numbers[2] << '\n';
    std::cout << s_numbers[3] << '\n';

    return 0;
}
```

- Notice that there's no `"fifteen"` nor `"thirty"`, but rather `"quarter"` and `"half"`. Since the hours are constrained to **[1, 12]**, I think it would be fine to put those terms in the same array as the others.

```c++
static std::array<std::string, ...> s_numbers =
{
    "", "one", "two", ... , "fourteen", "quarter", "sixteen", ...
};
```

- If you think about it, you don't really need to write the terms up to 59 -- nor 30. I would say you only need the terms from `1` to `20`, and then make a special case for `n > 20` and `n == 30`. Perhaps even to `n == 0`.

```c++
#include <array>
#include <string>

static std::array<std::string, 21> s_numbers = { ... };

std::string numberToText(int n)
{
    if (n == 30)
        return "half";

    if (n > 30)
        n = 60 - n;

    if (n > 20)
        return s_numbers[20] + " " + s_numbers[n - 20];

    return s_numbers[n];
}
```

- And something I didn't pay attention to at the time: if `(hours + 1) > 12`, then loop it back to `1`, not `13`.
