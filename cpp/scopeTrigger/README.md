# `scope_trigger`

The `scope_trigger` class is a simple way of setting actions that will be executed when the execution flow exits the scope where those actions are. A common application of this class is the release of allocated resources, such as dynamically allocated memory, opened files, loaded dynamically linked libraries (DLLs), and so on. (in the case of allocated memory, prefer to use smart pointers or arrays/vectors)

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger t1{ []{ std::cout << 1; } };

    {
        scope_trigger t2{ []{ std::cout << 2; } };

        {
            scope_trigger t3{ []{ std::cout << 3; } };
        }

        scope_trigger t4{ []{ std::cout << 4; } };
    }

    scope_trigger t5{ []{ std::cout << 5; } };

    return 0;
}
```

##### Output

```
34251
```

## 1) Constructors

### 1.1) `scope_trigger() noexcept`

Builds a `scope_trigger` object in an empty state (no action assigned). Thus no action will be executed when the program exits the scope.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{};

    std::cout << "Is foo in an empty state? " << std::boolalpha << !foo.enabled() << '\n';

    return 0;
}
```

##### Output

```
Is foo in an empty state? true
```

### 1.2) `scope_trigger(scope_trigger&& other) noexcept`

Builds a `scope_trigger` object from `other`, moving `other`'s action to this object and leaving `other` in an empty state.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{ []{ std::cout << "Triggered." << '\n'; } };
    scope_trigger bar{ std::move(foo) };

    std::cout << "Is foo enabled? " << std::boolalpha << foo.enabled() << '\n';
    std::cout << "Is bar enabled? " << std::boolalpha << bar.enabled() << '\n';

    return 0;
}
```

##### Output
```
Is foo enabled? false
Is bar enabled? true
Triggered.

```

### 1.3) `template<class TAction> scope_trigger(TAction&& action) noexcept`

Builds a `scope_trigger` object assigning `action` as this instance's triggered action.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

void foo()
{
    std::cout << "foo called." << '\n';
}

int main()
{
    auto&& named_lambda = []{ std::cout << "Named lambda called." << '\n'; };

    scope_trigger trigger_lambda{ []{ std::cout << "Lambda called." << '\n'; } };
    scope_trigger trigger_named_lambda{ named_lambda };
    scope_trigger trigger_foo{ foo };
    scope_trigger trigger_ptr_to_foo{ &foo };

    return 0;
}
```

##### Output

```
foo called.
foo called.
Named lambda called.
Lambda called.

```

## 2) Overloaded Operators

### 2.1) `scope_trigger& operator=(scope_trigger&& other) noexcept`

Assigns `other` to this object, moving `other`'s action to this object and leaving `other` in an empty state.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{ []{ std::cout << "Triggered." << '\n'; } };
    scope_trigger bar;

    bar = std::move(foo);

    std::cout << "Is foo enabled? " << std::boolalpha << foo.enabled() << '\n';
    std::cout << "Is bar enabled? " << std::boolalpha << bar.enabled() << '\n';

    return 0;
}
```

##### Output
```
Is foo enabled? false
Is bar enabled? true
Triggered.

```

## 3) Methods

### 3.1) `bool enabled() const`

Returns `true` if this `scope_trigger` object has an assigned action -- that is, if it is not in an empty state. Returns `false` otherwise.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{};
    scope_trigger bar{ []{ std::cout << "Lambda called." << '\n'; } };
    scope_trigger baz{ []{} };

    std::cout << "Is foo enabled? " << std::boolalpha << foo.enabled() << '\n';
    std::cout << "Is bar enabled? " << std::boolalpha << bar.enabled() << '\n';
    std::cout << "Is baz enabled? " << std::boolalpha << baz.enabled() << '\n';

    return 0;
}
```

##### Output

```
Is foo enabled? false
Is bar enabled? true
Is baz enabled? true
Lambda called.

```

### 3.2) `template<class TAction> void set_action(TAction&& action)`

Assigns `action` as the new triggered action of this `scope_trigger` object.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{};

    foo.set_action([]{ std::cout << "Lambda called." << '\n'; });

    return 0;
}
```

##### Output

```
Lambda called.

```

### 3.3) `void disable()`

Assigns no action to this `scope_trigger` object, leaving it in an empty state.

##### Example

```cpp
#include <iostream>
#include "scope_trigger.hpp"

int main()
{
    scope_trigger foo{ []{ std::cout << "foo triggered." << '\n'; } };
    scope_trigger bar{ []{ std::cout << "bar triggered." << '\n'; } };

    foo.disable();

    return 0;
}
```

##### Output

```
bar triggered.

```
