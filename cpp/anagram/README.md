# Anagrams of an Word

During a job interview I had there was this coding challenge -- among others -- which required me to compute the minimum number of changes needed in order to make a given word an anagram of another.

I thought it was an interesting question.

## The Problem

The idea is that the resulting program will read `q` entries, and for each one of them you have to split it and compare the right side to the left side. The comparison function (`anagram()`) has to return the minimum number of changes needed to turn the right side into an anagram of left side, once the characters are rearranged. If the left and the right sides have different lengths, then it should return `-1`.

For instance, if the program reads `abcdbadc`, then:

- you split it in the middle:

  - `"abcdbfdc"` becomes `"abcd"` and `"bfdc"`

- and compute the changes needed to make the right one an anagram of the left:

  1. `"bfdc"` could be reordered as `"fbcd"`
  1. `"f"` becomes an `"a"`
     1. so `"fbcd"` becomes `"abcd"`

- Total of `1` change (disregarding rearrangement).

If the program reads `"abcddabca"`, then:

- you return `-1` because you can't evenly split `"abcddabca"` in two (9 characters).

## The Solution

My take on it is that an anagram is just an arrangement of the same characters of a given word. Which means that that same word plus all of its anagrams are composed of the same set of characters (allowing repetitions, of course). For instance, both of the words `"dog"` and `"god"` are composed with the characters from the set `{ "d", "g", "o" }`.

Since we don't care about arrangement, we could just take the difference between the length of the left side and the length of the intersection between the sets of characters of each side.

That is:

```
length( left side ) - length( intersection( set( left side ) , set( right side ) ) )
```
