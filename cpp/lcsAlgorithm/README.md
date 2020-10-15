# Longest Common Subsequence (LCS)

I came across a challenge which required the developer to write a code that would print the [largest sequencial -- but not necessarily consecutive -- match](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem) between two strings. I didn't like the initial pre-written code for the challenge, as it was ridden with memory leaks (_"the horror!!!"_). And it was expected that you would also play around with `dinamyc_cast<>()`, which I'm already familiar with.

Long story short: I opted to code just the LCS algorithm since **that** was something I wasn't entirely familiar with -- the challenge's scenario was just a layer of flavor after all.

I upped the game just a little by choosing to code the algorithm as a _template<>_ function.

Right now, the function just returns the length of the LCS, not LCS per se. I'm thinking on how I can get the sequence in the best way I can come up with.