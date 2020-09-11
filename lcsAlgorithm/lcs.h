#ifndef LCS_H__
#define LCS_H__


#include <algorithm>
#include <vector>


template<class TLeft, class TRight>
std::size_t lcs(TLeft const& left, TRight const& right)
{
    std::vector<std::size_t> scores(size(right) + 1, 0);
    std::size_t              scoreIndex = 1;

    for (auto const& leftValue : left)
    {
        for (auto const& rightValue : right)
        {
            scores[scoreIndex] = std::max(scores[scoreIndex - 1], scores[scoreIndex]);

            if (leftValue == rightValue)
                ++scores[scoreIndex];

            ++scoreIndex;
        }

        scoreIndex = 1;
    }

    return scores.back();
}


#endif
