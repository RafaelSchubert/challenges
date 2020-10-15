# Circular Rotation

I was given this question, among others, during an interview. Given an array of integers `a`, a positive number `n`, and an array of queried indices of the first array, you are requested to return the numbers at each queried index of `a` after `n` circular rotations to the right.

## The Problem

The program will read three integers in a single line,

```csharp
"n k q"
```

where `n` is the number of elements in an array of integers, `k` is the number of circular rotations to be executed, and `q` is the number of indices to be queried. Then, it will read the array of `n` integers.

```csharp
"X0 X1 X2 ... Xn-1"
```

Finally, it will read each of the queried indices individually.

```csharp
"X0"
"X1"
"X2"
// ...
"Xq-1"
```

The `circularArrayRotation()` function is then given the array of integers `a[]` of size `n`, the number of circular rotations to be performed `k`, and the array of queried indices `q`. It should return the elements of `a[]` at each index in `q` after performing `k` circular rotations in an array.

A single circular rotation to the right is done by moving each element `a[n]` of an array `a[]` to `a[n + 1]`. So, performing `k` circular rotations to the right means that each element `a[n]` of `a[]` should be moved to `a[n + k]`. If `n + k >= a.Length`, then the element should be moved to `(n + k) % a.Length`.

## The Solution

What is interesting is that the number of circular rotations `k` could be really big, something up to the hundreds of thousands. So, performing the circular rotations, one rotation at a time, is actually impractical, and that is the catch.

What do you do, then? Well, if you think about it, the final positions of the elements of `a[]` are predictable. Rather, the **adjustment** of their positions is predictable.

There are four possible scenarios:

- `k == 0`;
- `k < a.Length`;
- `k == a.Length`;
- `k > a.Length`.

When `k == 0`, we don't to make any changes to `a[]`.

When `k < a.Length`, it is a simple matter of adding `k` to the each element's current index. If `(index + k) >= a.Length`, then we treat it as if `a[index]` was at `a[0]`, and we were performing `(index + k) - a.Length` rotations. If `(index + k) - a.Length` still is `>= a.Length`, then we subtract `a.Length` again, like `(index + k) - (2 * a.Length)`. Notice how that could be generalized as `(index + k) - (n * a.Length)`, with `n` being an integer `>= 0`. The result of that expression is actually `(index + k) % a.Length`, which works for both the cases where `k == 0` or `k < a.Length`.

When `k == a.Length`, we cycle each element through the whole array, and we end up with the original array. That is, `k == a.Length` has the same effect as `k == 0`. Notice how `(index + k) % a.Length == index` when `k == a.Length`, because `k % a.Length == 0`.

When `k > a.Length`, either `k` is a multiple of `a.Length`, or it isn't. If `k` is a multiple of `a.Length`, then it has the same effect as if `k == 0`, because `k == n * a.Length + 0`, with `n` being an integer `>= 0`. If `k` isn't a multiple of `a.Length`, then `k == n * a.Length + m`, with both `n` and `m` being integers `>= 0`, but `m < a.Length`. Which means that, when `k` isn't a multiple of `a.Length`, it has the same effect as `k % a.Length` rotations.
